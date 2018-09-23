/*********************************************************************************
NixNote - An open-source client for the Evernote service.
Copyright (C) 2013 Randy Baumgarte

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
***********************************************************************************/


#include <QApplication>
#include "src/nixnote.h"
#include "src/global.h"
#include "src/settings/startupconfig.h"
#include "src/cmdtools/cmdlinetool.h"
//#include "src/cmdtools/cmdlineapp.h"

#include "src/logger/qslog.h"
#include <QDir>
#include <iostream>
#include <QMessageBox>
#include <QSharedMemory>

// Windows Check
#ifndef _WIN32

#include <execinfo.h>

#endif

#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <QNetworkProxy>


#include "src/application.h"

#include <tidy.h>
#include <tidybuffio.h>


NixNote *w;

using namespace std;

//*********************************************
//* This is the main entry point for NixNote.
//*********************************************
extern Global global;

//*********************************************************************
//* Segmentation fault.  This is triggered to print a stack trace.
//*********************************************************************
// Windows Check
#ifndef _WIN32

void fault_handler(int sig) {
    void *array[30];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, 30);

    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);
    backtrace_symbols_fd(array, size, 2);
    if (w != NULL) {
        fprintf(stderr, "Forcing save\n");
        w->saveState();
    }
    exit(1);
}


void sighup_handler(int sig) {
    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);
    if (w != NULL) {
        fprintf(stderr, "Forcing save\n");
        w->saveState();
    }
}


#endif // End Windows check


//using namespace cv;
//*********************************************************************
//* Main entry point to the program.
//*********************************************************************
int main(int argc, char *argv[]) {
    w = NULL;
    bool guiAvailable = true;

    // Setup the QLOG functions for debugging & messages
    // we need to do it at very beginning, else we lose the startup messages
    QsLogging::Logger &logger = QsLogging::Logger::instance();
    // at very beginning we starting with info level to get basic startup info
    // log level is later adjusted by settings

    // FOR ALFA VERSION TEMPORARY DEFAULT LOG LEVEL IS DEBUG
    logger.setLoggingLevel(QsLogging::DebugLevel);

    QsLogging::DestinationPtr debugDestination(
        QsLogging::DestinationFactory::MakeDebugOutputDestination());
    logger.addDestination(debugDestination.get());

// Windows Check
#ifndef _WIN32
    signal(SIGSEGV, fault_handler);   // install our handler
#endif

    // Begin setting up the environment
    StartupConfig startupConfig;
    global.argc = argc;
    global.argv = argv;

    // note guiAvailable is passed by reference and can be modified by cmd line arguments
    int retval = startupConfig.init(argc, argv, guiAvailable);
    QLOG_DEBUG() << "Startup config ret=" << retval << ", guiAvailable=" << guiAvailable;
    if (retval != 0) {
        return retval;
    }



    // Setup the application. If we have a GUI, then we use Application.
    // If we don't, then we just use a derivative of QCoreApplication
    QCoreApplication *a = nullptr;
    if (guiAvailable) {
        auto *app = new Application(argc, argv);
        a = app;
    } else {
        a = new QCoreApplication(argc, argv);
    }
    QCoreApplication::setApplicationName(NN_APP_NAME);
    global.application = a;


    global.fileManager.setup(startupConfig.getConfigDir(), startupConfig.getUserDataDir(),
                             startupConfig.getProgramDataDir());
    QString versionStr = global.fileManager.getProgramVersionPrintable();

    // first configure global settings file
    global.initializeGlobalSettings();
    // then we configure user config file - accountId may be set on command line (then it comes via startupConfig)
    // but if it is not, then we get it from main config (and set to global.accountId)
    global.initializeUserSettings(startupConfig.getAccountId());
    // now we can set up user data directories
    global.fileManager.setupUserDirectories(global.getAccountId());
    // and not instance sync memory mapper
    global.initializeSharedMemoryMapper(global.getAccountId());
    // now all other..
    global.setup(startupConfig, guiAvailable);

    // We were passed a SQL command
    if (startupConfig.sqlExec) {
        DatabaseConnection *db = new DatabaseConnection(NN_DB_CONNECTION_NAME);  // Startup the database
        QLOG_DEBUG() << "Starting DB";
        QSqlQuery query(db->conn);
        QLOG_DEBUG() << "After DB Start";
        if (!query.exec(startupConfig.sqlString)) {
            QLOG_FATAL() << query.lastError();
            delete db;
            exit(16);
        }
        while (query.next()) {
            QString result = "";
            for (int i = 0; i < query.record().count(); i++) {
                result = result + query.value(i).toString() + " | ";
            }
            QLOG_INFO() << result;
        }
        delete db;
        QLOG_INFO() << "Ok" << endl;
        exit(0);
    }


    // If we want something other than the GUI, try let the CmdLineTool deal with it.
    if (!startupConfig.gui()) {
        QLOG_INFO() << "About to handle command line arguments";
        global.purgeTemporaryFilesOnShutdown = startupConfig.purgeTemporaryFiles;
        CmdLineTool cmdline;
        startupConfig.purgeTemporaryFiles = false;
        int retval1 = cmdline.run(startupConfig);
        if (global.sharedMemory->isAttached()) {
            global.sharedMemory->detach();
        }
        if (retval1) {
            QLOG_ERROR() << "Exit FAILURE: retcode=" << retval1;

        } else {
            QLOG_INFO() << "Exit OK: retcode=" << retval1;
        }
        delete a;

        exit(retval1);
    }

    // Create a shared memory region.  We use this to communicate
    // with any other instance that may be running.  If another instance
    // is found we need to either show that one or kill this one.
    bool memInitNeeded = true;
    if (!global.sharedMemory->allocate(512 * 1024)) {
        // Attach to it and detach.  This is done in case it crashed.
        global.sharedMemory->attach();
        global.sharedMemory->detach();
        if (!global.sharedMemory->allocate(512 * 1024)) {
            QLOG_DEBUG() << "Shared memory segment created";
            if (startupConfig.startupNewNote) {
                QLOG_DEBUG() << "Sending request NEW_NOTE";
                global.sharedMemory->attach();
                global.sharedMemory->write(QString("NEW_NOTE"));
                global.sharedMemory->detach();
                delete a;
                exit(0);  // Exit this one
            }
            if (startupConfig.startupNoteLid > 0) {
                QString req("OPEN_NOTE" + QString::number(startupConfig.startupNoteLid) + " ");
                QLOG_DEBUG() << "Sending request " << req;
                global.sharedMemory->attach();
                global.sharedMemory->write(req);
                global.sharedMemory->detach();
                delete a;
                exit(0);  // Exit this one
            }

            // If we've gotten this far, we need to either stop this instance or stop the other
            // note: although this is configurable, there doesn't seem to be GUI preference for this
            global.settings->beginGroup(INI_GROUP_DEBUGGING);
            QString startup = global.settings->value("onMultipleInstances", "SHOW_OTHER").toString();
            QLOG_DEBUG() << "Another running instance with same account detected - configured action: " << startup;
            global.settings->endGroup();
            global.sharedMemory->attach();
            if (startup == "SHOW_OTHER") {
                QLOG_DEBUG() << "Trying to activate it..";
                global.sharedMemory->write(QString("SHOW_WINDOW"));
                global.sharedMemory->detach();
                delete a;
                return 0;  // Exit this one
            }
            if (startup == "STOP_OTHER") {
                QLOG_DEBUG() << "Trying to shutdown it..";
                global.sharedMemory->write(QString("IMMEDIATE_SHUTDOWN"));
                memInitNeeded = false;
            }
        }
    }

    if (memInitNeeded) {
        global.sharedMemory->clearMemory();
    }


    // activate logging in file
    QString logPath = global.fileManager.getMainLogFileName();
    QsLogging::DestinationPtr fileDestination(
            QsLogging::DestinationFactory::MakeFileDestination(logPath));
    logger.addDestination(fileDestination.get());

    // from now on logging goes also to log file (up to here only to terminal)

    QLOG_INFO().noquote() << NN_APP_DISPLAY_NAME " " << versionStr << ", build at " << __DATE__ << " at " << __TIME__
                          << ", with Qt" << QT_VERSION_STR << " running on " << qVersion();
    if (logger.loggingLevel() > 1) {
        QLOG_INFO() << "To get more detailed startup logging use --logLevel=1";
    }
    global.fileManager.setupFileAttachmentLogging();

#ifndef _WIN32
    if (global.getInterceptSigHup())
        signal(SIGHUP, sighup_handler);   // install our handler
#endif

    QLOG_DEBUG() << "Setting up";
    w = new NixNote();
    w->setAttribute(Qt::WA_QuitOnClose);

    // this is bit dirty, maybe improve later
    QObject::connect(&global, SIGNAL(setMessageSignal(QString, int)), w, SLOT(setMessage(QString, int)));

    bool show = true;
    if (global.readSettingMinimizeToTray() && global.startMinimized)
        show = false;
    if (show)
        w->show();
    else
        w->hide();
    if (global.startMinimized)
        w->showMinimized();

    // show message, if there is any configured
    w->showAnnouncementMessage();

    // Setup the proxy
    QNetworkProxy proxy;
    if (global.isProxyEnabled()) {
        if (global.isSocks5Enabled())
            proxy.setType(QNetworkProxy::Socks5Proxy);
        QString host = global.getProxyHost();
        int port = global.getProxyPort();
        QString user = global.getProxyUserid();
        QString password = global.getProxyPassword();

        if (host.trimmed() != "")
            proxy.setHostName(host.trimmed());
        if (port > 0)
            proxy.setPort(port);
        if (user.trimmed() != "")
            proxy.setUser(user.trimmed());
        if (password.trimmed() != "")
            proxy.setPassword(password.trimmed());

        QNetworkProxy::setApplicationProxy(proxy);
    } else {
        proxy.setType(QNetworkProxy::HttpProxy);
    }

    QLOG_DEBUG() << "Setting up exit signal";

    QObject::connect(a, SIGNAL(aboutToQuit()), w, SLOT(saveOnExit()));

    QLOG_DEBUG() << "Launching";
    int rc = a->exec();
    if (global.sharedMemory->isAttached())
        global.sharedMemory->detach();
    QLOG_DEBUG() << "Deleting NixNote instance";
    delete w;
    QLOG_DEBUG() << "Quitting application instance";
    a->exit(rc);
    QLOG_DEBUG() << "Deleting application instance";
    delete a;
    QLOG_INFO() << "Exit: retcode=" << rc;
    exit(rc);
    return rc;
}
