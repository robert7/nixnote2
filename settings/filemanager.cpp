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

#include "filemanager.h"
#include "global.h"
#include <iostream>
#include <cstdlib>

#ifdef USE_QSP
#include <QLibraryInfo>
#endif

//*******************************************
//* This class is used to find the location
//* of various files & directories
//*******************************************

using namespace std;

FileManager::FileManager() {
}

void FileManager::setup(QString startupConfigDirPath, QString startupProgramDirPath, int accountId) {
    if (!startupConfigDirPath.isEmpty()) {
        startupConfigDirPath = slashTerminatePath(startupConfigDirPath);
    }
    if (!startupProgramDirPath.isEmpty()) {
       startupProgramDirPath = slashTerminatePath(startupProgramDirPath);
    }
    QLOG_DEBUG() << "FileManager::setup startupConfigDirPath: " << startupConfigDirPath << ", startupProgramDirPath: " << startupProgramDirPath;

    this -> programDirPath = startupProgramDirPath;
    this -> configDirPath = startupConfigDirPath;

    if (this -> configDirPat.isEmpty()) {
        this -> configDirPath = slashTerminatePath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));

        // TODO
        // in order to not break things for existing user, check whenewer this -> configDirPath exists
        // if it doesn't exist & the OLD path exists - take old path
        // OLD: this -> configDirPath = slashTerminatePath(QDir().homePath() + QString("/.nixnote"));
    }
    createDirOrCheckWriteable(configDir);

    #ifdef Q_OS_MACOS
        QString appDirPath = QCoreApplication::applicationDirPath();
        if (appDirPath.endsWith(".app/Contents/MacOS")) {
            // get rid of the MacOS component
            appDirPath.chop(5);
            this -> programDirPath = appDirPath + "/Resources/";
        }
    #endif



#ifdef USE_QSP
#ifdef Q_OS_MACOS
    // get the resources from the app bundle
    dataDirPath = programDir;
#else
    dataDirPath = QLibraryInfo::location(QLibraryInfo::PrefixPath) + "/share/nixnote2/";
#endif
    const QString userDataDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)+"/");
    const QString configDir(QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) + "/");
#else
    // preserve the legacy behaviour
    dataDirPat = programDirPath;
    const QString userDataDir(configDirPath);
    const QString configDir(getHomeDirPath(""));
#endif

    dataDir.setPath(dataDirPath);

    // Read only files that everyone uses
    imagesDir.setPath(dataDirPath+"images");
    checkExistingReadableDir(imagesDir);
    imagesDirPath = slashTerminatePath(imagesDir.path());

    javaDir.setPath(dataDirPath+"java");
    checkExistingReadableDir(javaDir);
    javaDirPath = slashTerminatePath(javaDir.path());

//    spellDir.setPath(programDirPath+"spell");
//    checkExistingReadableDir(spellDir);
//    spellDirPath = slashTerminatePath(spellDir.path());

    spellDirUser.setPath(userDataDir+"spell");
    createDirOrCheckWriteable(spellDirUser);
    spellDirPathUser = slashTerminatePath(spellDirUser.path());

    //xmlDir.setPath(programDirPath+"xml");
    //checkExistingReadableDir(xmlDir);

    translateDir.setPath(dataDirPath+"translations");
    checkExistingReadableDir(translateDir);
    translateDirPath= slashTerminatePath(translateDir.path());

    qssDir.setPath(dataDirPath+"qss");
    checkExistingReadableDir(qssDir);
    qssDirPath = slashTerminatePath(qssDir.path());

    // Read/write directories that only we use

    QString settingsFile = configDir + "nixnote.conf";
    QSettings globalSettings(settingsFile, QSettings::IniFormat);

    if (accountId <=0) {
        globalSettings.beginGroup("SaveState");
        int accountIdFromSettings = globalSettings.value("lastAccessedAccount", 1).toInt();
        globalSettings.endGroup();
        accountId = accountIdFromSettings;
    }

    qssDirUser.setPath(userDataDir+"qss");
    createDirOrCheckWriteable(qssDirUser);
    qssDirPathUser = slashTerminatePath(qssDirUser.path());

    logsDir.setPath(userDataDir+"logs-" +QString::number(accountId));
    createDirOrCheckWriteable(logsDir);
    logsDirPath = slashTerminatePath(logsDir.path());

    tmpDir.setPath(userDataDir+"tmp-" +QString::number(accountId));
    createDirOrCheckWriteable(tmpDir);
    tmpDirPath = slashTerminatePath(tmpDir.path());

#ifdef USE_QSP
    dbDir.setPath(userDataDir+"db-" +QString::number(accountId));
#else
    dbDir.setPath(configDirPath+"db-" +QString::number(accountId));
#endif
    createDirOrCheckWriteable(dbDir);
    dbDirPath = slashTerminatePath(dbDir.path());

    dbaDir.setPath(dbDirPath+"dba");
    createDirOrCheckWriteable(dbaDir);
    dbaDirPath = slashTerminatePath(dbaDir.path());

    dbiDir.setPath(dbDirPath+"dbi");
    createDirOrCheckWriteable(dbiDir);
    dbiDirPath = slashTerminatePath(dbiDir.path());

    thumbnailDir.setPath(dbDirPath+"tdba");
    createDirOrCheckWriteable(thumbnailDir);
    thumbnailDirPath = slashTerminatePath(thumbnailDir.path());
}



QString FileManager::toPlatformPathSeparator(QString relativePath) {
    return relativePath;
}



/*************************************************/
/* Given a path, append either a / or a \ to     */
/* form a fully qualified path                   */
/*************************************************/
QString FileManager::slashTerminatePath(QString path) {
    if (!path.endsWith(QDir::separator())) {
        return path + QDir::separator();
    }
    return path;
}


/*************************************************/
/* Delete files in a directory.  This is used    */
/* to cleanup temporary files.                   */
/*************************************************/
void FileManager::deleteTopLevelFiles(QDir dir, bool exitOnFail) {
    dir.setFilter(QDir::Files);
    QStringList list = dir.entryList();
    for (qint32 i=0; i<list.size(); i++) {
        QFile f(list.at(i));
        if (!f.remove() && exitOnFail) {
            cout << "Error deleting file '" +f.fileName().toStdString() <<
                    "'. Aborting program";
            exit(16);
        }
    }
}


/*************************************************/
/* Create a directory if it doesn't exist.       */
/*************************************************/
void FileManager::createDirOrCheckWriteable(QDir dir) {
    if (!dir.exists()) {
         if (!dir.mkpath(dir.path())) {
             QLOG_FATAL() << "Failed to create directory '" << dir.path() << "'.  Aborting program.";
             exit(16);
         }
    } else {
        if (!dir.isReadable()) {
            QLOG_FATAL() << "Directory '" + dir.path() + "' does not have read permission.  Aborting program.";
            exit(16);
        }
    }
}


/**************************************************/
/* Check that an existing directory is readable.  */
/**************************************************/
void FileManager::checkExistingReadableDir(QDir dir) {
// Windows Check
#ifndef _WIN32
    if (!dir.isReadable()) {
            QLOG_FATAL() << "Directory '" + dir.path() + "' does not have read permission.  Aborting program.";
            exit(16);
    }
#endif  // end windows check
    if (!dir.exists()) {
         QLOG_FATAL() << "Directory '" + dir.path() + "' does not exist.  Aborting program";
         exit(16);
    }
}



/**************************************************/
/* Check that an existing directory is writable.  */
/**************************************************/
void FileManager::checkExistingWriteableDir(QDir dir) {
    this->checkExistingReadableDir(dir);
}

QString FileManager::getProgramDirPath(QString relativePath) {
#ifdef USE_QSP
    return dataDirPath + toPlatformPathSeparator(relativePath);
#else
    return programDirPath + toPlatformPathSeparator(relativePath);
#endif
}
QString FileManager::getHomeDirPath(QString relativePath) {
    return configDirPath + toPlatformPathSeparator(relativePath);
}
QDir FileManager::getSpellDirFileUser(QString relativePath) {
    return spellDirPathUser + toPlatformPathSeparator(relativePath);
}
QString FileManager::getSpellDirPathUser() {
    return spellDirPathUser;
}
QString FileManager::getDbDirPath(QString relativePath) {
    return dbDirPath + toPlatformPathSeparator(relativePath);
}
QDir FileManager::getImageDirFile(QString relativePath) {
    return QDir(imagesDir.dirName()+ toPlatformPathSeparator(relativePath));
}
QString FileManager::getImageDirPath(QString relativePath) {
    return imagesDirPath + toPlatformPathSeparator(relativePath);
}
QDir FileManager::getJavaDirFile(QString relativePath) {
    return QDir(javaDir.dirName()+ toPlatformPathSeparator(relativePath));
}
QString FileManager::getJavaDirPath(QString relativePath) {
    return javaDirPath + toPlatformPathSeparator(relativePath);
}
QDir FileManager::getLogsDirFile(QString relativePath) {
    return QDir(logsDir.dirName() + toPlatformPathSeparator(relativePath));
}
QString FileManager::getLogsDirPath(QString relativePath) {
    return logsDirPath + toPlatformPathSeparator(relativePath);
}


QString FileManager::getQssDirPath(QString relativePath) {
    return qssDirPath + toPlatformPathSeparator(relativePath);
}
QString FileManager::getQssDirPathUser(QString relativePath) {
    return qssDirPathUser + toPlatformPathSeparator(relativePath);
}

QString FileManager::getTmpDirPath() {
    return tmpDirPath;
}
QString FileManager::getTmpDirPath(QString relativePath) {
    return tmpDirPath + toPlatformPathSeparator(relativePath);
}
QString FileManager::getTmpDirPathSpecialChar(QString relativePath) {
    return tmpDirPath + toPlatformPathSeparator(relativePath).replace("#", "%23");
}
QString FileManager::getDbaDirPath() {
    return dbaDirPath.replace("\\", "/");
}
QString FileManager::getDbaDirPath(QString relativePath) {
    return dbaDirPath + toPlatformPathSeparator(relativePath);
}
QString FileManager::getDbaDirPathSpecialChar(QString relativePath) {
    return dbaDirPath + toPlatformPathSeparator(relativePath).replace("#", "%23");
}
QString FileManager::getDbiDirPath() {
    return dbiDirPath;
}
QString FileManager::getDbiDirPath(QString relativePath) {
    return dbiDirPath + toPlatformPathSeparator(relativePath);
}
QString FileManager::getDbiDirPathSpecialChar(QString relativePath) {
    return dbiDirPath + toPlatformPathSeparator(relativePath).replace("#", "%23");
}
QString FileManager::getThumbnailDirPath() {
    return thumbnailDirPath;
}
QString FileManager::getThumbnailDirPath(QString relativePath) {
    return thumbnailDirPath + toPlatformPathSeparator(relativePath);
}
QString FileManager::getThumbnailDirPathSpecialChar(QString relativePath) {
    return thumbnailDirPath + toPlatformPathSeparator(relativePath).replace("#", "%23");
}
/*
QDir FileManager::getXMLDirFile(QString relativePath) {
    return QDir(xmlDir.dirName() + toPlatformPathSeparator(relativePath));
}
*/
QString FileManager::getTranslateFilePath(QString relativePath) {
    return translateDirPath + toPlatformPathSeparator(relativePath);
}
void FileManager::purgeResDirectory(bool exitOnFail) {
    this->deleteTopLevelFiles(tmpDir.dirName(), exitOnFail);
}








