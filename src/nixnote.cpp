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

#include "src/nixnote.h"
#include "src/threads/syncrunner.h"
#include "src/gui/nwebview.h"
#include "src/watcher/filewatcher.h"
#include "src/dialog/accountdialog.h"
#include "src/dialog/preferences/preferencesdialog.h"
#include "src/sql/resourcetable.h"
#include "src/sql/nsqlquery.h"
#include "src/filters/filtercriteria.h"
#include "src/filters/filterengine.h"
#include "src/dialog/faderdialog.h"
#include "src/dialog/shortcutdialog.h"
#include "src/utilities/noteindexer.h"

#include <QApplication>
#include <QThread>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include <QStringList>
#include <QDesktopServices>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QStatusBar>
#include <QSlider>
#include <QPrinter>
#include <QDesktopWidget>
#include <QFileIconProvider>
#include <QSplashScreen>
#include <unistd.h>

#include "src/sql/notetable.h"
#include "src/gui/ntabwidget.h"
#include "src/sql/notebooktable.h"
#include "src/sql/usertable.h"
#include "src/settings/startupconfig.h"
#include "src/dialog/logindialog.h"
#include "src/dialog/closenotebookdialog.h"
#include "src/gui/lineedit.h"
#include "src/gui/findreplace.h"
#include "src/gui/nattributetree.h"
#include "src/dialog/watchfolderdialog.h"
#include "src/dialog/notehistoryselect.h"
#include "src/gui/ntrashtree.h"
#include "src/html/attachmenticonbuilder.h"
#include "src/filters/filterengine.h"
#include "src/global.h"
#include "src/html/enmlformatter.h"
#include "src/html/noteformatter.h"
#include "src/dialog/databasestatus.h"
#include "src/dialog/adduseraccountdialog.h"
#include "src/dialog/accountmaintenancedialog.h"
#include "src/communication/communicationmanager.h"
#include "src/utilities/encrypt.h"

// Windows Check
#ifndef _WIN32

#include <boost/shared_ptr.hpp>

#endif

#include "src/cmdtools/cmdlinequery.h"
#include "src/cmdtools/alternote.h"


#include "src/gui/nmainmenubar.h"
#include "src/dialog/logindialog.h"
#include "src/xml/importdata.h"
#include "src/xml/importenex.h"
#include "src/xml/exportdata.h"
#include "src/dialog/aboutdialog.h"

#include "src/qevercloud/QEverCloud/headers/QEverCloud.h"
#include "src/qevercloud/QEverCloud/headers/QEverCloudOAuth.h"


using namespace qevercloud;

// Windows Check
#ifndef _WIN32
using namespace boost;
#endif

extern Global global;

class SyncRunner;

// Define/allocate the singleton instance pointer
NixNote *NixNote::singleton;

//*************************************************
//* This is the main class that is used to start
//* everything else.
//*************************************************
NixNote::NixNote(QWidget *parent) : QMainWindow(parent) {
    global.settings->beginGroup(INI_GROUP_APPEARANCE);
    if (global.settings->value("showSplashScreen", false).toBool()) {
        splashScreen = new QSplashScreen(this, global.getPixmapResource(":splashLogoImage"));
        splashScreen->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::SplashScreen | Qt::FramelessWindowHint);
        splashScreen->show();
        QTimer::singleShot(2500, this, SLOT(clearSplashScreen()));
    }
    global.settings->endGroup();
    QString css = global.getThemeCss("mainWindowCss");
    if (css != "")
        this->setStyleSheet(css);

    nixnoteTranslator = new QTranslator();
    QString translation;
    global.settings->beginGroup(INI_GROUP_LOCALE);
    translation = global.settings->value(INI_VALUE_TRANSLATION, QLocale::system().name()).toString();
    global.settings->endGroup();
    translation = global.fileManager.getTranslateFilePath(NN_APP_NAME "_" + translation + ".qm");
    QLOG_DEBUG() << "Looking for translations: " << translation;
    bool translationResult = nixnoteTranslator->load(translation);
    QLOG_DEBUG() << "Translation loaded: " << translationResult << ", installing translator";
    QApplication::instance()->installTranslator(nixnoteTranslator);
    QLOG_DEBUG() << "done";

    connect(&syncThread, SIGNAL(started()), this, SLOT(syncThreadStarted()));
    connect(&counterThread, SIGNAL(started()), this, SLOT(counterThreadStarted()));
    connect(&indexThread, SIGNAL(started()), this, SLOT(indexThreadStarted()));

    counterThread.start(QThread::LowestPriority);
    syncThread.start(QThread::LowPriority);
    indexThread.start(QThread::LowestPriority);
    this->thread()->setPriority(QThread::HighestPriority);

    if (global.getListenToCommands()) {
        heartbeatTimer.setInterval(1000);
        heartbeatTimer.setSingleShot(false);
        connect(&heartbeatTimer, SIGNAL(timeout()), this, SLOT(heartbeatTimerTriggered()));
        heartbeatTimer.start();
    }

    this->setFont(global.getGuiFont(this->font()));

    db = new DatabaseConnection(NN_DB_CONNECTION_NAME);  // Startup the database

    // Setup the sync thread
    QLOG_DEBUG() << "Setting up counter thread";
    connect(this, SIGNAL(updateCounts()), &counterRunner, SLOT(countAll()));


    // Setup the counter thread
    QLOG_DEBUG() << "Setting up sync thread";
    connect(this, SIGNAL(syncRequested()), &syncRunner, SLOT(synchronize()));
    connect(&syncRunner, SIGNAL(setMessage(QString, int)), this, SLOT(setMessage(QString, int)));

    QLOG_DEBUG() << "Setting up GUI";
    global.filterPosition = 0;
    this->setupGui();
    QLOG_DEBUG() << "GUI setup done";

    global.resourceWatcher = new QFileSystemWatcher(this);
    QLOG_DEBUG() << "Connecting signals";
    connect(favoritesTreeView, SIGNAL(updateSelectionRequested()), this, SLOT(updateSelectionCriteria()));
    connect(tagTreeView, SIGNAL(updateSelectionRequested()), this, SLOT(updateSelectionCriteria()));
    connect(notebookTreeView, SIGNAL(updateSelectionRequested()), this, SLOT(updateSelectionCriteria()));
    connect(searchTreeView, SIGNAL(updateSelectionRequested()), this, SLOT(updateSelectionCriteria()));
    connect(attributeTree, SIGNAL(updateSelectionRequested()), this, SLOT(updateSelectionCriteria()));
    connect(trashTree, SIGNAL(updateSelectionRequested()), this, SLOT(updateSelectionCriteria()));
    connect(searchText, SIGNAL(updateSelectionRequested()), this, SLOT(updateSelectionCriteria()));
    connect(global.resourceWatcher, SIGNAL(fileChanged(QString)), this, SLOT(resourceExternallyUpdated(QString)));

    finalSync = false;


    // Setup reminders
    global.reminderManager = new ReminderManager();
    connect(global.reminderManager, SIGNAL(showMessage(QString, QString, int)), this,
            SLOT(showMessage(QString, QString, int)));
    global.reminderManager->reloadTimers();

    global.settings->beginGroup(INI_GROUP_APPEARANCE);
    bool showMissed = global.settings->value("showMissedReminders", false).toBool();
    global.settings->endGroup();
    if (showMissed)
        QTimer::singleShot(5000, global.reminderManager, SLOT(timerPop()));
    else
        global.setLastReminderTime(QDateTime::currentMSecsSinceEpoch());


    // Check for Java and verify encryption works
    QLOG_DEBUG() << "encryption selftest";
    QString test = "Test Message";
    QString result;
    EnCrypt encrypt(global.fileManager.getCryptoJarPath());
    if (!encrypt.encrypt(result, test, test)) {
        if (!encrypt.decrypt(result, result, test)) {
            if (result == test) {
                global.javaFound = true;
                QLOG_DEBUG() << "encrypt available";
            } else {
                QLOG_WARN() << "encrypt.decrypt failed (different result)";
            }
        } else {
            QLOG_WARN() << "encrypt.decrypt failed";
        }
    } else {
        QLOG_WARN() << "encrypt.encrypt failed";
    }

    // Initialize pdfExportWindow to null. We don't fully set this up in case the person requests it.
    pdfExportWindow = nullptr;

    // Setup file watcher
    importManager = new FileWatcherManager(this);
    connect(importManager, SIGNAL(fileImported(qint32, qint32)), this, SLOT(updateSelectionCriteria()));
    connect(importManager, SIGNAL(fileImported()), this, SLOT(updateSelectionCriteria()));
    importManager->setup();
    this->updateSelectionCriteria(true);  // This is only needed in case we imported something at statup

    networkManager = new QNetworkAccessManager();
    connect(networkManager, SIGNAL(finished(QNetworkReply * )), this, SLOT(onNetworkManagerFinished(QNetworkReply * )));

    clientId = global.getOrCreateMemoryKey();
    // Set the static singleton instance pointer (q.v. get())
    singleton = this;
    QLOG_DEBUG() << "Exiting NixNote constructor";
}


// Destructor to call when all done
NixNote::~NixNote() {
    QLOG_DEBUG() << "~NixNote: Closing threads";
    syncThread.quit();
    indexThread.quit();
    counterThread.quit();
    while (!syncThread.isFinished());
    while (!indexThread.isFinished());
    while (!counterThread.isFinished());

    // Cleanup any temporary files
    if (global.purgeTemporaryFilesOnShutdown) {
        QDir myDir(global.fileManager.getTmpDirPath());
        QStringList list = myDir.entryList();
        for (int i = 0; i < list.size(); i++) {
            if (list[i] != "." && list[i] != "..") {
                QString file = global.fileManager.getTmpDirPath() + list[i];
                myDir.remove(file);
            }
        }
    }
    delete networkManager;

//    delete db;  // Free up memory used by the database connection
//    delete rightPanelSplitter;
//    delete leftPanelSplitter;
//    delete leftPanel;
}


void NixNote::clearSplashScreen() {
    splashScreen->close();
    delete splashScreen;
}


//****************************************************************
//* Public static method to get the singleton instance of NixNote
//****************************************************************
NixNote *NixNote::get() {
    return singleton;
}

//****************************************************************
//* Setup the user interface
//****************************************************************
void NixNote::setupGui() {
    // Setup the GUI
    //this->setStyleSheet("background-color: white;");
    //statusBar();    setWindowTitle(tr(NN_APP_DISPLAY_NAME_GUI));
    QLOG_DEBUG() << "setupGui: Setting up window icon";
    const auto wIcon = global.getIconResource(":windowIcon");
    if (!wIcon.isNull()) {
        setWindowIcon(wIcon);
    }
    QLOG_DEBUG() << "Font setup";
    QFont guiFont(global.getGuiFont(font()));

    global.setSortOrder(global.readSettingSortOrder());

    searchText = new LineEdit();
    searchText->setFont(guiFont);

    QLOG_DEBUG() << "Setting up menu bar";
    menuBar = new NMainMenuBar(this);
    setMenuBar(menuBar);

    QLOG_DEBUG() << "Setting up tool bar";
    toolBar = addToolBar(tr("ToolBar"));
    QString css = global.getThemeCss("mainToolbarCss");
    if (css != "")
        toolBar->setStyleSheet(css);
    connect(toolBar, SIGNAL(visibilityChanged(bool)), this, SLOT(toolbarVisibilityChanged()));
    //menuBar = new NMainMenuBar(this);
    toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toolBar->setObjectName("toolBar");
    //toolBar->addWidget(menuBar);
    menuBar->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    toolBar->setFloatable(true);
    toolBar->setMovable(true);
    toolBar->setFont(guiFont);
    toolBar->setAllowedAreas(Qt::BottomToolBarArea | Qt::TopToolBarArea);
    //toolBar->addSeparator();

    leftArrowButtonShortcut = new QShortcut(this);
    leftArrowButton = toolBar->addAction(
            global.getIconResource(":leftArrowIcon"),
            tr("Back") + global.setupShortcut(leftArrowButtonShortcut, "File_History_Previous")
    );
    leftArrowButton->setEnabled(false);
    leftArrowButton->setPriority(QAction::LowPriority);
    connect(leftArrowButton, SIGNAL(triggered(bool)), this, SLOT(leftButtonTriggered()));
    connect(leftArrowButtonShortcut, SIGNAL(activated()), this, SLOT(leftButtonTriggered()));

    rightArrowButtonShortcut = new QShortcut(this);
    rightArrowButton = toolBar->addAction(
            global.getIconResource(":rightArrowIcon"),
            tr("Next") + global.setupShortcut(rightArrowButtonShortcut, "File_History_Next")
    );
    rightArrowButton->setEnabled(false);
    rightArrowButton->setPriority(QAction::LowPriority);
    connect(rightArrowButton, SIGNAL(triggered(bool)), this, SLOT(rightButtonTriggered()));
    connect(rightArrowButtonShortcut, SIGNAL(activated()), this, SLOT(rightButtonTriggered()));

    toolBar->addSeparator();

    // Sync shortcut moved from the menu, to this toolbar button
    // This enables it to apply globally in all app windows
    syncButtonShortcut = new QShortcut(this);
    syncButton = toolBar->addAction(global.getIconResource(":synchronizeIcon"), tr("Sync"));
    syncButton->setToolTip(tr("Sync") + global.setupShortcut(syncButtonShortcut, "Tools_Synchronize"));
    syncButton->setPriority(QAction::LowPriority);   // Hide the text by the icon
    syncButtonShortcut->setContext(Qt::ApplicationShortcut); // Make sync key work in all app windows

    homeButtonShortcut = new QShortcut(this);
    homeButton = toolBar->addAction(global.getIconResource(":homeIcon"), tr("All Notes"));
    homeButton->setToolTip(tr("All Notes") + global.setupShortcut(homeButtonShortcut, "View_All_Notes"));

    newNoteButton = toolBar->addAction(global.getIconResource(":newNoteIcon"), tr("New Note"));
    newNoteButton->setToolTip(global.appendShortcutInfo(tr("New Note"), "File_Note_Add"));

    toolBar->addSeparator();

    deleteNoteButton = toolBar->addAction(
            global.getIconResource(":deleteIcon"),
            global.appendShortcutInfo(tr("Delete"), "File_Note_Delete")
    );
    deleteNoteButton->setPriority(QAction::LowPriority);

    toolBar->addSeparator();

    printNoteButton = toolBar->addAction(
            global.getIconResource(":printerIcon"),
            global.appendShortcutInfo(tr("Print the current note"), "File_Print")
    );
    printNoteButton->setPriority(QAction::LowPriority);   // Hide the text by the icon

    emailButton = toolBar->addAction(global.getIconResource(":emailIcon"),
                                     global.appendShortcutInfo(tr("Email the current note"), "File_Email"));
    emailButton->setPriority(QAction::LowPriority);   // Hide the text by the icon

    toolBar->addSeparator();


    connect(syncButton, SIGNAL(triggered()), this, SLOT(synchronize()));
    connect(syncButtonShortcut, SIGNAL(activated()), this, SLOT(synchronize()));

    connect(homeButton, SIGNAL(triggered()), this, SLOT(resetView()));
    connect(homeButtonShortcut, SIGNAL(activated()), this, SLOT(resetView()));

    connect(printNoteButton, SIGNAL(triggered()), this, SLOT(fastPrintNote()));
    connect(deleteNoteButton, SIGNAL(triggered()), this, SLOT(deleteCurrentNote()));
    connect(newNoteButton, SIGNAL(triggered()), this, SLOT(newNote()));
    connect(emailButton, SIGNAL(triggered()), this, SLOT(emailNote()));

    QLOG_DEBUG() << "Adding main splitter";
    mainSplitter = new QSplitter(Qt::Horizontal);
    setCentralWidget(mainSplitter);

    rightPanelSplitter = new QSplitter(Qt::Vertical);
    leftPanelSplitter = new QSplitter(Qt::Vertical);
    leftPanel = new WidgetPanel();

    this->setupNoteList();
    this->setupFavoritesTree();
    this->setupSynchronizedNotebookTree();
    this->setupTagTree();
    this->setupSearchTree();
    this->setupAttributeTree();
    this->setupTrashTree();
    this->setupTabWindow();
    leftPanel->vboxLayout->addStretch();

    connect(tagTreeView, SIGNAL(tagDeleted(qint32, QString)), favoritesTreeView, SLOT(itemExpunged(qint32, QString)));
    connect(searchTreeView, SIGNAL(searchDeleted(qint32)), favoritesTreeView, SLOT(itemExpunged(qint32)));
    connect(notebookTreeView, SIGNAL(notebookDeleted(qint32, QString)), favoritesTreeView,
            SLOT(itemExpunged(qint32, QString)));
    connect(tagTreeView, SIGNAL(tagRenamed(qint32, QString, QString)), favoritesTreeView,
            SLOT(itemRenamed(qint32, QString, QString)));
    connect(searchTreeView, SIGNAL(searchDeleted(qint32)), favoritesTreeView, SLOT(itemExpunged(qint32)));
    connect(notebookTreeView, SIGNAL(notebookRenamed(qint32, QString, QString)), favoritesTreeView,
            SLOT(itemRenamed(qint32, QString, QString)));
    connect(notebookTreeView, SIGNAL(stackDeleted(QString)), favoritesTreeView, SLOT(stackExpunged(QString)));
    connect(notebookTreeView, SIGNAL(stackRenamed(QString, QString)), favoritesTreeView,
            SLOT(stackRenamed(QString, QString)));
    connect(tabWindow, SIGNAL(updateNoteTitle(QString, qint32, QString)), favoritesTreeView,
            SLOT(updateShortcutName(QString, qint32, QString)));

    QLOG_DEBUG() << "Setting up left panel";
    leftPanel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    leftScroll = new QScrollArea();
    leftScroll->setWidgetResizable(true);
    leftScroll->setWidget(leftPanel);
    leftScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    leftScroll->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    mainSplitter->insertWidget(0, leftScroll);
    mainSplitter->addWidget(rightPanelSplitter);
    mainSplitter->setStretchFactor(0, 1);
    mainSplitter->setStretchFactor(1, 3);

    QLOG_DEBUG() << "Resetting left side widgets";
    tagTreeView->resetSize();
    searchTreeView->resetSize();
    attributeTree->resetSize();
    trashTree->resetSize();

    // Restore the window state
    global.startMinimized = false;
    QLOG_DEBUG() << "Restoring window state";
    global.settings->beginGroup(INI_GROUP_APPEARANCE);
    int selectionBehavior = global.settings->value("startupNotebook",
                                                   AppearancePreferences::UseLastViewedNotebook).toInt();
    global.startMinimized = global.settings->value("startMinimized", false).toBool();
    global.settings->endGroup();

    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    bool showStatusbar = global.settings->value("statusBar", true).toBool();
    if (showStatusbar) {
        menuBar->viewStatusbar->setChecked(showStatusbar);
        statusBar()->setVisible(true);
    } else {
        menuBar->viewStatusbar->setChecked(false);
        statusBar()->setVisible(false);
    }
    restoreState(global.settings->value("WindowState").toByteArray());
    restoreGeometry(global.settings->value("WindowGeometry").toByteArray());
    mainSplitter->restoreState(global.settings->value("mainSplitter", 0).toByteArray());
    rightPanelSplitter->restoreState(global.settings->value("rightSplitter", 0).toByteArray());
    if (global.settings->value("isMaximized", false).toBool())
        this->setWindowState(Qt::WindowMaximized);
    QString lidListString = global.settings->value("openTabs", "").toString().trimmed();
    bool value = global.settings->value("leftPanelVisible", true).toBool();
    if (!value) {
        menuBar->viewLeftPanel->setChecked(false);
        leftScroll->setVisible(false);
    }
    value = global.settings->value("noteListVisible", true).toBool();
    if (!value) {
        menuBar->viewNoteList->setChecked(false);
        topRightWidget->setVisible(false);
    }
    value = global.settings->value("tabWindowVisible", true).toBool();
    if (!value) {
        menuBar->viewNotePanel->setChecked(false);
        tabWindow->setVisible(false);
    }
    value = global.settings->value("favoritesTreeVisible", true).toBool();
    if (!value) {
        menuBar->viewFavoritesTree->setChecked(false);
        favoritesTreeView->setVisible(false);
    }
    value = global.settings->value("notebookTreeVisible", true).toBool();
    if (!value) {
        menuBar->viewNotebookTree->setChecked(false);
        notebookTreeView->setVisible(false);
    }
    value = global.settings->value("tagTreeVisible", true).toBool();
    if (!value) {
        menuBar->viewTagTree->setChecked(false);
        tagTreeView->setVisible(false);
    }
    value = global.settings->value("savedSearchTreeVisible", true).toBool();
    if (!value) {
        menuBar->viewSearchTree->setChecked(false);
        searchTreeView->setVisible(false);
    }
    value = global.settings->value("attributeTreeVisible", true).toBool();
    if (!value) {
        menuBar->viewAttributesTree->setChecked(false);
        attributeTree->setVisible(false);
    }
    value = global.settings->value("trashTreeVisible", true).toBool();
    if (!value) {
        menuBar->viewTrashTree->setChecked(false);
        trashTree->setVisible(false);
    }
    global.settings->endGroup();
    checkLeftPanelSeparators();

    if (rightPanelSplitter->orientation() == Qt::Vertical)
        viewNoteListWide();
    else
        viewNoteListNarrow();

    QStringList lidList = lidListString.split(' ');
    // If we have old notes we were viewing the last time
    if (lidList.size() > 0) {
        FilterCriteria *filter = global.getCurrentCriteria();

        for (int i = 0; i < lidList.size(); i++) {
            // if we are doing multiple notes, they each need
            // to be added to the selection criteria.
            if (i > 0)
                filter = new FilterCriteria();
            int lid = lidList[i].toInt();
            QList<qint32> selectedLids;
            selectedLids.append(lid);
            filter->setSelectedNotes(selectedLids);
            filter->setLid(lid);
            if (i > 0)
                global.filterCriteria.append(filter);
        }

        for (int i = 0; i < lidList.size(); i++) {
            global.filterPosition = i;
            if (i == 0)
                openNote(false);
            else
                openNote(true);
        }
    }

    NoteTable noteTable(global.db);
    if (global.startupNote > 0 && noteTable.exists(global.startupNote)) {
        openExternalNote(global.startupNote);
    }


    // Setup the tray icon
    minimizeToTray = global.readSettingMinimizeToTray();
    closeToTray = global.readSettingCloseToTray();
    bool forceSystemTrayAvailable = global.forceSystemTrayAvailable;
    bool isSystemTrayAvailable = QSystemTrayIcon::isSystemTrayAvailable();
    bool showTrayIcon = global.readSettingShowTrayIcon();
    bool forceNoStartMimized = global.forceNoStartMimized;

    QLOG_DEBUG() << "Tray status #1: isSystemTrayAvailable=" << isSystemTrayAvailable
                 << ", minimizeToTray=" << minimizeToTray
                 << ", closeToTray=" << closeToTray
                 << ", forceSystemTrayAvailable=" << forceSystemTrayAvailable
                 << ", showTrayIcon=" << showTrayIcon
                 << ", forceNoStartMimized=" << forceNoStartMimized;

    if (!isSystemTrayAvailable && forceSystemTrayAvailable) {
        QLOG_INFO() << "Overriding QSystemTrayIcon::isSystemTrayAvailable() per command line option.";
    }
    if (!showTrayIcon || forceNoStartMimized || (!isSystemTrayAvailable && !forceSystemTrayAvailable)) {
        QLOG_DEBUG() << "Overriding close & minimize to tray because of command line or isSystemTrayAvailable";
        closeToTray = false;
        minimizeToTray = false;
    }

    trayIcon = new QSystemTrayIcon(global.getIconResource(":trayIcon"), this);
    TrayMenu *trayIconContextMenu = createTrayContexMenu();
    trayIcon->setContextMenu(trayIconContextMenu);
    QLOG_DEBUG() << "Tray status #2: showTrayIcon=" << showTrayIcon
                 << ", closeToTray=" << closeToTray
                 << ", minimizeToTray=" << minimizeToTray;

    if (showTrayIcon) {
        trayIcon->show();
    }
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
            SLOT(onTrayActivated(QSystemTrayIcon::ActivationReason)));

    // Setup timers
    QLOG_DEBUG() << "Setting up timers";
    setSyncTimer();
    connect(&syncTimer, SIGNAL(timeout()), this, SLOT(syncTimerExpired()));
    connect(&syncButtonTimer, SIGNAL(timeout()), this, SLOT(updateSyncButton()));
    connect(&syncRunner, SIGNAL(syncComplete()), this, SLOT(syncButtonReset()));

    QLOG_DEBUG() << "Setting up more connections for tab windows & threads";
    connect(&syncRunner, SIGNAL(syncComplete()), this, SLOT(notifySyncComplete()));

    // connect so we refresh the note list and counts whenever a note has changed
    connect(tabWindow, SIGNAL(noteUpdated(qint32)), noteTableView, SLOT(refreshData()));
    connect(tabWindow, SIGNAL(noteUpdated(qint32)), &counterRunner, SLOT(countNotebooks()));
    connect(tabWindow, SIGNAL(noteUpdated(qint32)), &counterRunner, SLOT(countTags()));
    connect(tabWindow, SIGNAL(noteTagsUpdated(QString, qint32, QStringList)), noteTableView,
            SLOT(noteTagsUpdated(QString, qint32, QStringList)));
    connect(tabWindow, SIGNAL(noteNotebookUpdated(QString, qint32, QString)), noteTableView,
            SLOT(noteNotebookUpdated(QString, qint32, QString)));
    connect(tabWindow, SIGNAL(updateNoteList(qint32, int, QVariant)), noteTableView,
            SLOT(refreshCell(qint32, int, QVariant)));
    connect(noteTableView, SIGNAL(refreshNoteContent(qint32)), tabWindow, SLOT(refreshNoteContent(qint32)));
    connect(noteTableView, SIGNAL(saveAllNotes()), tabWindow, SLOT(saveAllNotes()));

    // connect so we refresh the tag tree when a new tag is added
    connect(tabWindow, SIGNAL(tagCreated(qint32)), tagTreeView, SLOT(addNewTag(qint32)));
    connect(tabWindow, SIGNAL(tagCreated(qint32)), &counterRunner, SLOT(countTags()));

    connect(tabWindow, SIGNAL(updateSelectionRequested()), this, SLOT(updateSelectionCriteria()));
    connect(tabWindow->tabBar, SIGNAL(currentChanged(int)), this, SLOT(checkReadOnlyNotebook()));

    // Finish by filtering & displaying the data
    //updateSelectionCriteria();

    // connect signal on a tag rename
    connect(tagTreeView, SIGNAL(tagRenamed(qint32, QString, QString)), this, SLOT(updateSelectionCriteria()));
    connect(notebookTreeView, SIGNAL(notebookRenamed(qint32, QString, QString)), this, SLOT(updateSelectionCriteria()));

    // Reload saved selection criteria
    if (selectionBehavior != AppearancePreferences::UseAllNotebooks) {
        bool criteriaFound = false;
        FilterCriteria *criteria = new FilterCriteria();

        // Restore whatever they were looking at in the past
        if (selectionBehavior == AppearancePreferences::UseLastViewedNotebook) {

            global.settings->beginGroup(INI_GROUP_SAVE_STATE);
            qint32 notebookLid = global.settings->value("selectedNotebook", 0).toInt();
            if (notebookLid > 0 && notebookTreeView->dataStore[notebookLid] != nullptr) {
                criteria->setNotebook(*notebookTreeView->dataStore[notebookLid]);
                criteriaFound = true;
            } else {
                QString selectedStack = global.settings->value("selectedStack", "").toString();
                if (selectedStack != "" && notebookTreeView->stackStore[selectedStack] != nullptr) {
                    criteria->setNotebook(*notebookTreeView->stackStore[selectedStack]);
                    criteriaFound = true;
                }
            }

            QString prevSearch = global.settings->value("searchString", "").toString();
            if (prevSearch != "") {
                searchText->setText(prevSearch);
                criteria->setSearchString(prevSearch);
                criteriaFound = true;
            }

            qint32 searchLid = global.settings->value("selectedSearch", 0).toInt();
            if (searchLid > 0 && searchTreeView->dataStore[searchLid] != nullptr) {
                criteria->setSavedSearch(*searchTreeView->dataStore[searchLid]);
                criteriaFound = true;
            }

            QString selectedTags = global.settings->value("selectedTags", "").toString();
            if (selectedTags != "") {
                QStringList tags = selectedTags.split(" ");
                QList<QTreeWidgetItem *> items;
                for (int i = 0; i < tags.size(); i++) {
                    if (tagTreeView->dataStore[tags[i].toInt()] != nullptr)
                        items.append(tagTreeView->dataStore[tags[i].toInt()]);
                }
                criteriaFound = true;
                criteria->setTags(items);
            }

            global.settings->endGroup();
        }

        // Select the default notebook
        if (selectionBehavior == AppearancePreferences::UseDefaultNotebook) {
            NotebookTable ntable(global.db);
            qint32 lid = ntable.getDefaultNotebookLid();
            if (notebookTreeView->dataStore[lid] != nullptr) {
                criteria->setNotebook(*notebookTreeView->dataStore[lid]);
                criteriaFound = true;
            }
        }



        // If we have some filter criteria, save it.  Otherwise delete
        // the unused memory.
        if (criteriaFound) {
            global.appendFilter(criteria);
        } else
            delete criteria;
    }

    this->updateSelectionCriteria();
    // Set default focus to the editor window
    tabWindow->currentBrowser()->editor->setFocus();

    QStringList accountNames = global.accountsManager->nameList();
    QList<int> ids = global.accountsManager->idList();
    for (int i = 0; i < ids.size(); i++) {
        if (ids[i] == global.accountsManager->currentId) {
            setWindowTitle(NN_APP_DISPLAY_NAME_GUI " - " + accountNames[i]);
            i = ids.size();
        }
    }

    // Determine if we should start minimized
    QLOG_DEBUG() << "isSystemTrayAvailable:" << isSystemTrayAvailable;
    if (global.startMinimized && !forceNoStartMimized &&
        (isSystemTrayAvailable || forceSystemTrayAvailable)) {
        // TODO refactor
        QLOG_DEBUG() << "About to start minimized in system tray";
        this->setWindowState(Qt::WindowMinimized);
        if (minimizeToTray) {
            QTimer::singleShot(100, this, SLOT(hide()));
        }
    }
    if (global.forceStartMinimized) {
        QLOG_DEBUG() << "About to start minimized in system tray (2)";
        this->setWindowState(Qt::WindowMinimized);
        if (minimizeToTray)
            QTimer::singleShot(100, this, SLOT(hide()));
    }

    // Restore expanded tags & stacks
    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    QString expandedTags = global.settings->value("expandedTags", "").toString();
    if (expandedTags != "") {
        QStringList tags = expandedTags.split(" ");
        for (int i = 0; i < tags.size(); i++) {
            NTagViewItem *item;
            item = tagTreeView->dataStore[tags[i].toInt()];
            if (item != nullptr)
                item->setExpanded(true);
        }
    }
    QString expandedNotebooks = global.settings->value("expandedStacks", "").toString();
    if (expandedNotebooks != "") {
        QStringList books = expandedNotebooks.split(" ");
        for (int i = 0; i < books.size(); i++) {
            NNotebookViewItem *item;
            item = notebookTreeView->dataStore[books[i].toInt()];
            if (item != nullptr && item->stack != "" && item->parent() != nullptr) {
                item->parent()->setExpanded(true);
                //QLOG_DEBUG() << "Parent of " << books[i] << " expanded.";
            }
        }
    }

    searchTreeView->root->setExpanded(true);
    QString collapsedTrees = global.settings->value("collapsedTrees", "").toString();
    if (collapsedTrees != "") {
        QStringList trees = collapsedTrees.split(" ");
        for (int i = 0; i < trees.size(); i++) {
            QString item = trees[i].toLower();
            if (item == "favorites")
                this->favoritesTreeView->root->setExpanded(false);
            if (item == "notebooks")
                this->notebookTreeView->root->setExpanded(false);
            if (item == "tags")
                this->tagTreeView->root->setExpanded(false);
            if (item == "attributes")
                this->attributeTree->root->setExpanded(false);
            if (item == "savedsearches")
                this->searchTreeView->root->setExpanded(false);
        }
    }
    global.settings->endGroup();


    // Setup application-wide shortcuts
    focusSearchShortcut = new QShortcut(this);
    focusSearchShortcut->setContext(Qt::WidgetWithChildrenShortcut);
    global.setupShortcut(focusSearchShortcut, "Focus_Search");
    connect(focusSearchShortcut, SIGNAL(activated()), searchText, SLOT(setFocus()));

    fileSaveShortcut = new QShortcut(this);
    fileSaveShortcut->setContext(Qt::WidgetWithChildrenShortcut);
    global.setupShortcut(fileSaveShortcut, "File_Save_Content");
    connect(fileSaveShortcut, SIGNAL(activated()), tabWindow, SLOT(saveAllNotes()));

    focusTitleShortcut = new QShortcut(this);
    focusTitleShortcut->setContext(Qt::WidgetShortcut);
    global.setupShortcut(focusTitleShortcut, "Focus_Title");
    connect(focusTitleShortcut, SIGNAL(activated()), &tabWindow->currentBrowser()->noteTitle, SLOT(setFocus()));

    focusNoteShortcut = new QShortcut(this);
    focusNoteShortcut->setContext(Qt::WidgetShortcut);
    global.setupShortcut(focusNoteShortcut, "Focus_Note");
    connect(focusNoteShortcut, SIGNAL(activated()), tabWindow->currentBrowser()->editor, SLOT(setFocus()));

    copyNoteUrlShortcut = new QShortcut(this);
    copyNoteUrlShortcut->setContext(Qt::WidgetShortcut);
    global.setupShortcut(copyNoteUrlShortcut, "Edit_Copy_Note_Url");
    connect(copyNoteUrlShortcut, SIGNAL(activated()), tabWindow->currentBrowser(), SLOT(copyInAppNoteLink()));

    focusTagShortcut = new QShortcut(this);
    focusTagShortcut->setContext(Qt::WidgetWithChildrenShortcut);
    global.setupShortcut(focusTagShortcut, "Focus_Tag");
    connect(focusTagShortcut, SIGNAL(activated()), tabWindow->currentBrowser(), SLOT(newTagFocusShortcut()));

    focusUrlShortcut = new QShortcut(this);
    focusUrlShortcut->setContext(Qt::WidgetWithChildrenShortcut);
    global.setupShortcut(focusUrlShortcut, "Focus_Url");
    connect(focusUrlShortcut, SIGNAL(activated()), tabWindow->currentBrowser(), SLOT(urlFocusShortcut()));

    focusAuthorShortcut = new QShortcut(this);
    focusAuthorShortcut->setContext(Qt::WidgetWithChildrenShortcut);
    global.setupShortcut(focusAuthorShortcut, "Focus_Author");
    connect(focusAuthorShortcut, SIGNAL(activated()), tabWindow->currentBrowser(), SLOT(authorFocusShortcut()));

    focusNotebookShortcut = new QShortcut(this);
    focusNotebookShortcut->setContext(Qt::WidgetWithChildrenShortcut);
    global.setupShortcut(focusNotebookShortcut, "Focus_Notebook");
    connect(focusNotebookShortcut, SIGNAL(activated()), tabWindow->currentBrowser(), SLOT(notebookFocusShortcut()));

    focusFontShortcut = new QShortcut(this);
    focusFontShortcut->setContext(Qt::WidgetWithChildrenShortcut);
    global.setupShortcut(focusFontShortcut, "Focus_Font");
    connect(focusFontShortcut, SIGNAL(activated()), tabWindow->currentBrowser(), SLOT(fontFocusShortcut()));

    focusFontSizeShortcut = new QShortcut(this);
    focusFontSizeShortcut->setContext(Qt::WidgetWithChildrenShortcut);
    global.setupShortcut(focusFontSizeShortcut, "Focus_Font_Size");
    connect(focusFontSizeShortcut, SIGNAL(activated()), tabWindow->currentBrowser(), SLOT(fontSizeFocusShortcut()));

    nextTabShortcut = new QShortcut(this);
    nextTabShortcut->setContext(Qt::WidgetWithChildrenShortcut);
    global.setupShortcut(nextTabShortcut, "Next_Tab");
    connect(nextTabShortcut, SIGNAL(activated()), tabWindow, SLOT(nextTab()));

    prevTabShortcut = new QShortcut(this);
    prevTabShortcut->setContext(Qt::WidgetWithChildrenShortcut);
    global.setupShortcut(prevTabShortcut, "Prev_Tab");
    connect(prevTabShortcut, SIGNAL(activated()), tabWindow, SLOT(prevTab()));

    closeTabShortcut = new QShortcut(this);
    closeTabShortcut->setContext(Qt::WidgetWithChildrenShortcut);
    global.setupShortcut(closeTabShortcut, "Close_Tab");
    connect(closeTabShortcut, SIGNAL(activated()), tabWindow, SLOT(closeTab()));

    downNoteShortcut = new QShortcut(this);
    downNoteShortcut->setContext(Qt::WidgetWithChildrenShortcut);
    global.setupShortcut(downNoteShortcut, "Down_Note");
    connect(downNoteShortcut, SIGNAL(activated()), noteTableView, SLOT(downNote()));

    upNoteShortcut = new QShortcut(this);
    upNoteShortcut->setContext(Qt::WidgetWithChildrenShortcut);
    global.setupShortcut(upNoteShortcut, "Up_Note");
    connect(upNoteShortcut, SIGNAL(activated()), noteTableView, SLOT(upNote()));

    // startup the index timer (if needed)
    if (global.enableIndexing) {
        indexTimer.setInterval(global.minimumThumbnailInterval);
        connect(&indexTimer, SIGNAL(timeout()), &indexRunner, SLOT(index()));
        connect(&indexRunner, SIGNAL(indexDone(bool)), this, SLOT(indexFinished(bool)));
        indexTimer.start();
    }
}

TrayMenu *NixNote::createTrayContexMenu() {
    TrayMenu *trayIconContextMenu = new TrayMenu(this);

    // ~temporary removal
    //newExternalNoteButton = trayIconContextMenu->addAction(tr("Quick Note"));
    //connect(newExternalNoteButton, SIGNAL(triggered()), this, SLOT(newExternalNote()));

    showAction = trayIconContextMenu->addAction(tr("Show"));
    connect(showAction, SIGNAL(triggered()), this, SLOT(showMainWindow()));

    QAction *newNoteButton2 = trayIconContextMenu->addAction(tr("New note"));
    connect(newNoteButton2, SIGNAL(triggered()), this, SLOT(restoreAndNewNote()));

    QMenu *favoritesMenu = trayIconContextMenu->addMenu(tr("Shortcut notes"));
    trayIconContextMenu->setActionMenu(TrayMenu::FavoriteNotesMenu, favoritesMenu);

    // ~temporary removal
    // QMenu *pinnedMenu = trayIconContextMenu->addMenu(tr("Pinned Notes"));
    // trayIconContextMenu->setActionMenu(TrayMenu::PinnedMenu, pinnedMenu);

    QMenu *recentMenu = trayIconContextMenu->addMenu(tr("Recently updated"));
    trayIconContextMenu->setActionMenu(TrayMenu::RecentMenu, recentMenu);
    connect(trayIconContextMenu, SIGNAL(openNote(qint32)), this, SLOT(openExternalNote(qint32)));

    trayIconContextMenu->addSeparator();
    quitAction = trayIconContextMenu->addAction(tr("Quit"));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(quitNixNote()));
    return trayIconContextMenu;
}


void NixNote::indexFinished(bool finished) {
    indexTimer.stop();
    if (!finished)
        indexTimer.setInterval(global.minIndexInterval);
    else
        indexTimer.setInterval(global.maxIndexInterval);
    indexTimer.start();
}


//**************************************************************
//* Move sync, couter, & index objects to their appropriate
//* thread.
//**************************************************************
void NixNote::counterThreadStarted() {
    counterRunner.moveToThread(&counterThread);
}


//***************************************************************
//* Signal received when the syncRunner thread has started
//***************************************************************
void NixNote::syncThreadStarted() {
    syncRunner.moveToThread(&syncThread);
    global.settings->beginGroup(INI_GROUP_SYNC);
    bool syncOnStartup = global.settings->value("syncOnStartup", false).toBool();
    global.showGoodSyncMessagesInTray = global.settings->value("showGoodSyncMessagesInTray", true).toBool();
    global.settings->endGroup();
    if (syncOnStartup)
        synchronize();
}

void NixNote::indexThreadStarted() {
    indexRunner.moveToThread(&indexThread);
    indexRunner.initialize();
    global.indexRunner = &indexRunner;
}


//******************************************************************************
//* This function sets up the note list window.  This is what the users select
//* view a specific note
//******************************************************************************
void NixNote::setupNoteList() {
    QLOG_DEBUG() << "Starting NixNote.setupNoteList()";

    // Setup a generic widget to hold the search & note table
    topRightWidget = new QWidget(this);
    topRightLayout = new QVBoxLayout();
    topRightLayout->addWidget(searchText);
    topRightWidget->setLayout(topRightLayout);
    noteTableView = new NTableView(this);
    topRightLayout->addWidget(noteTableView);
    topRightLayout->setContentsMargins(QMargins(0, 0, 0, 0));

    // Add the generic widget
    if (global.listView == Global::ListViewWide)
        rightPanelSplitter->addWidget(topRightWidget);
    else
        mainSplitter->addWidget(topRightWidget);

    connect(noteTableView, SIGNAL(newNote()), this, SLOT(newNote()));
    connect(noteTableView, SIGNAL(notesDeleted(QList<qint32>, bool)), this, SLOT(notesDeleted(QList<qint32>)));
    connect(noteTableView, SIGNAL(notesRestored(QList<qint32>)), this, SLOT(notesRestored(QList<qint32>)));
    connect(&syncRunner, SIGNAL(syncComplete()), noteTableView, SLOT(refreshData()));
    connect(&syncRunner, SIGNAL(noteSynchronized(qint32, bool)), this, SLOT(noteSynchronized(qint32, bool)));

    QLOG_TRACE() << "Leaving NixNote.setupNoteList()";
}


// Signal received when a note has been synchronized
void NixNote::noteSynchronized(qint32 lid, bool value) {
    noteTableView->refreshCell(lid, NOTE_TABLE_IS_DIRTY_POSITION, value);
}


//*****************************************************************************
//* This function sets up the user's search tree
//*****************************************************************************
void NixNote::setupSearchTree() {
    QLOG_DEBUG() << "Starting NixNote.setupSearchTree()";

    leftSeparator3 = new QLabel();
    leftSeparator3->setTextFormat(Qt::RichText);
    leftSeparator3->setText("<hr>");
    leftPanel->addSeparator(leftSeparator3);

    searchTreeView = new NSearchView(leftPanel);
    leftPanel->addSearchView(searchTreeView);
    connect(&syncRunner, SIGNAL(searchUpdated(qint32, QString)), searchTreeView, SLOT(searchUpdated(qint32, QString)));
    connect(&syncRunner, SIGNAL(searchExpunged(qint32)), searchTreeView, SLOT(searchExpunged(qint32)));
    //connect(&syncRunner, SIGNAL(syncComplete()),searchTreeView, SLOT(re);
    QLOG_TRACE() << "Exiting NixNote.setupSearchTree()";
}


//*****************************************************************************
//* This function sets up the user's tag tree
//*****************************************************************************
void NixNote::setupTagTree() {
    QLOG_DEBUG() << "Starting NixNote.setupTagTree()";

    leftSeparator2 = new QLabel();
    leftSeparator2->setTextFormat(Qt::RichText);
    leftSeparator2->setText("<hr>");
    leftPanel->addSeparator(leftSeparator2);

    tagTreeView = new NTagView(leftPanel);
    leftPanel->addTagView(tagTreeView);
    connect(&syncRunner, SIGNAL(tagUpdated(qint32, QString, QString, qint32)), tagTreeView,
            SLOT(tagUpdated(qint32, QString, QString, qint32)));
    connect(&syncRunner, SIGNAL(tagExpunged(qint32)), tagTreeView, SLOT(tagExpunged(qint32)));
    connect(&syncRunner, SIGNAL(syncComplete()), tagTreeView, SLOT(rebuildTree()));
    connect(&counterRunner, SIGNAL(tagTotals(qint32, qint32, qint32)), tagTreeView,
            SLOT(updateTotals(qint32, qint32, qint32)));
    connect(&counterRunner, SIGNAL(tagCountComplete()), tagTreeView, SLOT(hideUnassignedTags()));
    connect(notebookTreeView, SIGNAL(notebookSelectionChanged(qint32)), tagTreeView,
            SLOT(notebookSelectionChanged(qint32)));
    connect(tagTreeView, SIGNAL(updateNoteList(qint32, int, QVariant)), noteTableView,
            SLOT(refreshCell(qint32, int, QVariant)));
    connect(tagTreeView, SIGNAL(updateCounts()), &counterRunner, SLOT(countAll()));
    QLOG_TRACE() << "Exiting NixNote.setupTagTree()";
}


//*****************************************************************************
//* This function sets up the attribute search tree
//*****************************************************************************
void NixNote::setupAttributeTree() {
    QLOG_DEBUG() << "Starting NixNote.setupAttributeTree()";

    leftseparator4 = new QLabel();
    leftseparator4->setTextFormat(Qt::RichText);
    leftseparator4->setText("<hr>");
    leftPanel->addSeparator(leftseparator4);

    attributeTree = new NAttributeTree(leftPanel);
    leftPanel->addAttributeTree(attributeTree);
    QLOG_TRACE() << "Exiting NixNote.setupAttributeTree()";
}


//*****************************************************************************
//* This function sets up the trash
//*****************************************************************************
void NixNote::setupTrashTree() {
    QLOG_DEBUG() << "Starting NixNote.setupTrashTree()";

    leftSeparator5 = new QLabel();
    leftSeparator5->setTextFormat(Qt::RichText);
    leftSeparator5->setText("<hr>");
    leftPanel->addSeparator(leftSeparator5);

    trashTree = new NTrashTree(leftPanel);
    leftPanel->addTrashTree(trashTree);
    QLOG_TRACE() << "Exiting NixNote.setupTrashTree()";
    connect(&counterRunner, SIGNAL(trashTotals(qint32)), trashTree, SLOT(updateTotals(qint32)));
}


//*****************************************************************************
//* This function sets up the user's synchronized notebook tree
//*****************************************************************************
void NixNote::setupFavoritesTree() {
    QLOG_DEBUG() << "Starting NixNote.setupFavoritesdNotebookTree()";
    favoritesTreeView = new FavoritesView(leftPanel);
    leftPanel->addFavoritesView(favoritesTreeView);

//    connect(&syncRunner, SIGNAL(notebookUpdated(qint32, QString,QString, bool, bool)),notebookTreeView, SLOT(notebookUpdated(qint32, QString, QString, bool, bool)));
    connect(&syncRunner, SIGNAL(notebookExpunged(qint32)), favoritesTreeView, SLOT(itemExpunged(qint32)));
    connect(&syncRunner, SIGNAL(tagExpunged(qint32)), favoritesTreeView, SLOT(itemExpunged(qint32)));
//    connect(&syncRunner, SIGNAL(noteUpdated(qint32)), notebookTreeView, SLOT(itemExpunged(qint32)));
    connect(&counterRunner, SIGNAL(notebookTotals(qint32, qint32, qint32)), favoritesTreeView,
            SLOT(updateTotals(qint32, qint32, qint32)));
    connect(&counterRunner, SIGNAL(tagTotals(qint32, qint32, qint32)), favoritesTreeView,
            SLOT(updateTotals(qint32, qint32, qint32)));
    connect(favoritesTreeView, SIGNAL(updateCounts()), &counterRunner, SLOT(countAll()));

    leftSeparator1 = new QLabel();
    leftSeparator1->setTextFormat(Qt::RichText);
    leftSeparator1->setText("<hr>");
    leftPanel->addSeparator(leftSeparator1);

    QLOG_TRACE() << "Exiting NixNote.setupFavoritesTree()";
}


//*****************************************************************************
//* This function sets up the user's synchronized notebook tree
//*****************************************************************************
void NixNote::setupSynchronizedNotebookTree() {
    QLOG_DEBUG() << "Starting NixNote.setupSynchronizedNotebookTree()";
    notebookTreeView = new NNotebookView(leftPanel);
    leftPanel->addNotebookView(notebookTreeView);
    connect(&syncRunner, SIGNAL(notebookUpdated(qint32, QString, QString, bool, bool)), notebookTreeView,
            SLOT(notebookUpdated(qint32, QString, QString, bool, bool)));
    connect(&syncRunner, SIGNAL(syncComplete()), notebookTreeView, SLOT(rebuildTree()));
    connect(&syncRunner, SIGNAL(notebookExpunged(qint32)), notebookTreeView, SLOT(notebookExpunged(qint32)));
    connect(&counterRunner, SIGNAL(notebookTotals(qint32, qint32, qint32)), notebookTreeView,
            SLOT(updateTotals(qint32, qint32, qint32)));
    connect(notebookTreeView, SIGNAL(updateNoteList(qint32, int, QVariant)), noteTableView,
            SLOT(refreshCell(qint32, int, QVariant)));
    connect(notebookTreeView, SIGNAL(updateCounts()), &counterRunner, SLOT(countAll()));
    QLOG_TRACE() << "Exiting NixNote.setupSynchronizedNotebookTree()";
}


//*****************************************************************************
//* This function sets up the tab window that is used by the browser
//*****************************************************************************
void NixNote::setupTabWindow() {
    QLOG_DEBUG() << "Starting NixNote.setupTabWindow()";
    tabWindow = new NTabWidget(this, &syncRunner, notebookTreeView, tagTreeView);
    QWidget *tabPanel = new QWidget(this);
    tabPanel->setLayout(new QVBoxLayout());
    tabPanel->layout()->addWidget(tabWindow);
    rightPanelSplitter->addWidget(tabPanel);

    NBrowserWindow *newBrowser = new NBrowserWindow(this);
    connect(&syncRunner, SIGNAL(syncComplete()), &newBrowser->notebookMenu, SLOT(reloadData()));
    connect(&syncRunner, SIGNAL(syncComplete()), &newBrowser->tagEditor, SLOT(reloadTags()));
    connect(&syncRunner, SIGNAL(noteUpdated(qint32)), newBrowser, SLOT(noteSyncUpdate(qint32)));
    tabWindow->addBrowser(newBrowser, "");
    rightPanelSplitter->setStretchFactor(1, 10);

    connect(noteTableView, SIGNAL(openNote(bool)), this, SLOT(openNote(bool)));
    connect(noteTableView, SIGNAL(openNoteExternalWindow(qint32)), this, SLOT(openExternalNote(qint32)));
    connect(menuBar->viewSourceAction, SIGNAL(triggered()), tabWindow, SLOT(toggleSource()));
    connect(menuBar->viewHistoryAction, SIGNAL(triggered()), this, SLOT(viewNoteHistory()));
    connect(menuBar->viewPresentationModeAction, SIGNAL(triggered()), this, SLOT(presentationModeOn()));
    connect(tabWindow, SIGNAL(escapeKeyPressed()), this, SLOT(presentationModeOff()));

    connect(menuBar->undoAction, SIGNAL(triggered()), tabWindow, SLOT(undoButtonPressed()));
    connect(menuBar->redoAction, SIGNAL(triggered()), tabWindow, SLOT(redoButtonPressed()));
    connect(menuBar->cutAction, SIGNAL(triggered()), tabWindow, SLOT(cutButtonPressed()));
    connect(menuBar->copyAction, SIGNAL(triggered()), tabWindow, SLOT(copyButtonPressed()));
    connect(menuBar->pasteAction, SIGNAL(triggered()), tabWindow, SLOT(pasteButtonPressed()));
    connect(menuBar->pasteAsTextAction, SIGNAL(triggered()), tabWindow, SLOT(pasteAsTextButtonPressed()));
    connect(menuBar->selectAllAction, SIGNAL(triggered()), tabWindow, SLOT(selectAllButtonPressed()));
    connect(menuBar->viewExtendedInformation, SIGNAL(triggered()), tabWindow, SLOT(viewExtendedInformation()));

    QLOG_TRACE() << "Exiting NixNote.setupTabWindow()";
}


/**
 * Quit NixNote.   This will force a app close even if "close to tray" is set.
 */
void NixNote::quitNixNote() {
    QLOG_DEBUG() << "quitNixNote";

    closeToTray = false;
    close();
}


/**
 * Close nixnote via the shortcut. If we have it set to close to the tray,
 */
void NixNote::closeShortcut() {
    QLOG_DEBUG() << "closeShortcut()";

    if (closeToTray && isVisible())
        showMainWindow(); // wtf?
    else
        quitNixNote();
}


//*****************************************************************************
//* Save program contents on exit
//******************************************************************************
void NixNote::saveOnExit() {
    QLOG_DEBUG() << "saveOnExit()";

    QLOG_DEBUG() << "saveOnExit: Saving contents";
    saveContents();

    QLOG_DEBUG() << "saveOnExit: Shutting down threads";
    indexRunner.keepRunning = false;
    counterRunner.keepRunning = false;

    if (!global.getSaveUiState()) {
        return;
    }

    QCoreApplication::processEvents();

    QLOG_DEBUG() << "Saving window states";
    ConfigStore config(global.db);
    config.saveSetting(CONFIG_STORE_WINDOW_STATE, saveState());
    config.saveSetting(CONFIG_STORE_WINDOW_GEOMETRY, saveGeometry());

    QString lidList;
    QList<NBrowserWindow *> *browsers = tabWindow->browserList;
    for (int i = 0; i < browsers->size(); i++) {
        lidList = lidList + QString::number(browsers->at(i)->lid) + QString(" ");
    }

    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    global.settings->setValue("WindowState", saveState());
    global.settings->setValue("WindowGeometry", saveGeometry());
    global.settings->setValue("isMaximized", isMaximized());
    global.settings->setValue("openTabs", lidList);
    global.settings->setValue("lastViewed", tabWindow->currentBrowser()->lid);
    global.settings->setValue("noteListWidth", noteTableView->width());
    global.settings->setValue("noteListHeight", noteTableView->height());
    global.settings->setValue("mainSplitter", mainSplitter->saveState());
    global.settings->setValue("rightSplitter", rightPanelSplitter->saveState());
    global.settings->setValue("listView", global.listView);

    global.settings->remove("selectedStack");
    global.settings->remove("selectedNotebook");
    global.settings->remove("expandedStacks");
    global.settings->remove("selectedTags");
    global.settings->remove("expandedTags");
    global.settings->remove("selectedSearch");
    global.settings->remove("searchString");

    // Save the current notebook/stack selection
    if (notebookTreeView->selectedItems().size() > 0) {
        NNotebookViewItem *item = (NNotebookViewItem *) notebookTreeView->selectedItems().at(0);
        qint32 saveLid = item->lid;
        if (saveLid > 0) {
            global.settings->setValue("selectedNotebook", saveLid);
        } else {
            QString saveStack = item->text(0);
            global.settings->setValue("selectedStack", saveStack);
        }
    }

    if (searchText->isSet()) {
        global.settings->setValue("searchString", searchText->text().trimmed());
    }

    if (searchTreeView->selectedItems().size() > 0) {
        NSearchViewItem *item = (NSearchViewItem *) searchTreeView->selectedItems().at(0);
        qint32 saveLid = item->data(0, Qt::UserRole).toInt();
        if (saveLid > 0) {
            global.settings->setValue("selectedSearch", saveLid);
        }
    }

    // Save any selected tags
    QString savedLids = "";
    if (tagTreeView->selectedItems().size() > 0) {
        for (int i = 0; i < tagTreeView->selectedItems().size(); i++) {
            NTagViewItem *item = (NTagViewItem *) tagTreeView->selectedItems().at(i);
            qint32 saveLid = item->data(0, Qt::UserRole).toInt();
            savedLids = savedLids + QString::number(saveLid) + " ";
        }
        global.settings->setValue("selectedTags", savedLids.trimmed());
    }

    QHash<qint32, NTagViewItem *>::iterator iterator;
    savedLids = "";
    for (iterator = tagTreeView->dataStore.begin(); iterator != tagTreeView->dataStore.end(); ++iterator) {
        if (iterator.value() != nullptr) {
            qint32 saveLid = iterator.value()->data(0, Qt::UserRole).toInt();
            if (iterator.value()->isExpanded()) {
                savedLids = savedLids + QString::number(saveLid) + " ";
            }
        }
    }
    global.settings->setValue("expandedTags", savedLids.trimmed());

    QString collapsedTrees = "";
    global.settings->remove("collapsedTrees");
    if (!favoritesTreeView->root->isExpanded())
        collapsedTrees = "favorites ";
    if (!notebookTreeView->root->isExpanded())
        collapsedTrees = collapsedTrees + "notebooks ";
    if (!tagTreeView->root->isExpanded())
        collapsedTrees = collapsedTrees + "tags ";
    if (!attributeTree->root->isExpanded())
        collapsedTrees = collapsedTrees + "attributes ";
    if (!searchTreeView->root->isExpanded())
        collapsedTrees = collapsedTrees + "savedsearches ";
    global.settings->setValue("collapsedTrees", collapsedTrees.trimmed());

    QHash<qint32, NNotebookViewItem *>::iterator books;
    savedLids = "";
    for (books = notebookTreeView->dataStore.begin(); books != notebookTreeView->dataStore.end(); ++books) {
        if (books.value() != nullptr) {
            qint32 saveLid = books.value()->data(0, Qt::UserRole).toInt();
            if (books.value()->stack != "" && books.value()->parent()->isExpanded()) {
                savedLids = savedLids + QString::number(saveLid) + " ";
            }
        }
    }
    global.settings->setValue("expandedStacks", savedLids.trimmed());

    global.settings->endGroup();

    saveNoteColumnWidths();
    saveNoteColumnPositions();
    noteTableView->saveColumnsVisible();

    QLOG_DEBUG() << "Exiting saveOnExit()";
}

//*****************************************************************************
//* Close the program
//*****************************************************************************
void NixNote::closeEvent(QCloseEvent *event) {
    QLOG_DEBUG() << "closeEvent";

    //    if (closeToTray && !closeFlag) {
    //        event->ignore();
    //        hide();
    //        return;
    //    }

    saveOnExit();

    global.settings->beginGroup(INI_GROUP_SYNC);
    bool syncOnShutdown = global.settings->value("syncOnShutdown", false).toBool();
    global.settings->endGroup();
    if (syncOnShutdown && !finalSync && global.accountsManager->oauthTokenFound()) {
        finalSync = true;
        syncRunner.finalSync = true;
        hide();
        connect(&syncRunner, SIGNAL(syncComplete()), this, SLOT(close()));
        synchronize();
        event->ignore();
        QLOG_DEBUG() << "closeEvent: ignore";

        return;
    }

    syncRunner.keepRunning = false;
    syncThread.quit();

    if (trayIcon != nullptr) {
        if (trayIcon->isVisible()) {
            trayIcon->hide();
        }
        delete trayIcon;
        trayIcon = nullptr;
    }

    QMainWindow::closeEvent(event);
    QLOG_DEBUG() << "closeEvent: quitting";
}


//*************************************************************
//* Function called on shutdown to save all of the note
//* table column positions.  These values are restored the
//* next time NixNote starts.
//**************************************************************
void NixNote::saveNoteColumnPositions() {
    int position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_ALTITUDE_POSITION);
    global.setColumnPosition("noteTableAltitudePosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_AUTHOR_POSITION);
    global.setColumnPosition("noteTableAuthorPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_DATE_CREATED_POSITION);
    global.setColumnPosition("noteTableDateCreatedPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_DATE_DELETED_POSITION);
    global.setColumnPosition("noteTableDateDeletedPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_DATE_SUBJECT_POSITION);
    global.setColumnPosition("noteTableDateSubjectPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_DATE_UPDATED_POSITION);
    global.setColumnPosition("noteTableDateUpdatedosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_HAS_ENCRYPTION_POSITION);
    global.setColumnPosition("noteTableHasEncryptionPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_HAS_TODO_POSITION);
    global.setColumnPosition("noteTableHasTodoPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_IS_DIRTY_POSITION);
    global.setColumnPosition("noteTableIsDirtyPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_LATITUDE_POSITION);
    global.setColumnPosition("noteTableLatitudePosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_LONGITUDE_POSITION);
    global.setColumnPosition("noteTableLongitudePosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_NOTEBOOK_LID_POSITION);
    global.setColumnPosition("noteTableNotebookLidPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_LID_POSITION);
    global.setColumnPosition("noteTableLidPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_NOTEBOOK_POSITION);
    global.setColumnPosition("noteTableNotebookPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_SIZE_POSITION);
    global.setColumnPosition("noteTableSizePosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_SOURCE_APPLICATION_POSITION);
    global.setColumnPosition("noteTableSourceApplicationPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_SOURCE_POSITION);
    global.setColumnPosition("noteTableSourcePosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_SOURCE_URL_POSITION);
    global.setColumnPosition("noteTableSourceUrlPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_TAGS_POSITION);
    global.setColumnPosition("noteTableTagsPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_TITLE_POSITION);
    global.setColumnPosition("noteTableTitlePosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_REMINDER_TIME_POSITION);
    global.setColumnPosition("noteTableReminderTimePosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_REMINDER_TIME_DONE_POSITION);
    global.setColumnPosition("noteTableReminderTimeDonePosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_REMINDER_ORDER_POSITION);
    global.setColumnPosition("noteTableReminderOrderPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_THUMBNAIL_POSITION);
    global.setColumnPosition("noteTableThumbnailPosition", position);
    position = noteTableView->horizontalHeader()->visualIndex(NOTE_TABLE_SEARCH_RELEVANCE_POSITION);
    global.setColumnPosition("noteTableRelevancePosition", position);
}


//*************************************************************
//* Function called on shutdown to save all of the note
//* table column widths.  These values are restored the
//* next time NixNote starts.
//**************************************************************
void NixNote::saveNoteColumnWidths() {
    int width;
    width = noteTableView->columnWidth(NOTE_TABLE_ALTITUDE_POSITION);
    global.setColumnWidth("noteTableAltitudePosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_AUTHOR_POSITION);
    global.setColumnWidth("noteTableAuthorPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_DATE_CREATED_POSITION);
    global.setColumnWidth("noteTableDateCreatedPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_DATE_DELETED_POSITION);
    global.setColumnWidth("noteTableDateDeletedPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_DATE_SUBJECT_POSITION);
    global.setColumnWidth("noteTableDateSubjectPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_DATE_UPDATED_POSITION);
    global.setColumnWidth("noteTableDateUpdatedPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_HAS_ENCRYPTION_POSITION);
    global.setColumnWidth("noteTableHasEncryptionPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_HAS_TODO_POSITION);
    global.setColumnWidth("noteTableHasTodoPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_IS_DIRTY_POSITION);
    global.setColumnWidth("noteTableIsDirtyPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_LATITUDE_POSITION);
    global.setColumnWidth("noteTableLatitudePosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_LID_POSITION);
    global.setColumnWidth("noteTableLidPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_LONGITUDE_POSITION);
    global.setColumnWidth("noteTableLongitudePosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_NOTEBOOK_LID_POSITION);
    global.setColumnWidth("noteTableNotebookLidPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_NOTEBOOK_POSITION);
    global.setColumnWidth("noteTableNotebookPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_SIZE_POSITION);
    global.setColumnWidth("noteTableSizePosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_SOURCE_APPLICATION_POSITION);
    global.setColumnWidth("noteTableSourceApplicationPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_TAGS_POSITION);
    global.setColumnWidth("noteTableTagsPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_TITLE_POSITION);
    global.setColumnWidth("noteTableTitlePosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_REMINDER_TIME_POSITION);
    global.setColumnWidth("noteTableReminderTimePosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_REMINDER_TIME_DONE_POSITION);
    global.setColumnWidth("noteTableReminderTimeDonePosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_REMINDER_ORDER_POSITION);
    global.setColumnWidth("noteTableReminderOrderPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_THUMBNAIL_POSITION);
    global.setColumnWidth("noteTableThumbnailPosition", width);
    width = noteTableView->columnWidth(NOTE_TABLE_SEARCH_RELEVANCE_POSITION);
    global.setColumnWidth("noteTableRelevancePosition", width);
}


//*****************************************************************************
//* The sync timer has expired
//*****************************************************************************
void NixNote::syncTimerExpired() {
    pauseIndexing(true);
    // If we are already connected, we are already synchronizing so there is nothing more to do
    if (global.connected == true)
        return;
    if (!global.accountsManager->oauthTokenFound())
        return;
    tabWindow->saveAllNotes();
    emit(syncRequested());
}

void NixNote::onNetworkManagerFinished(QNetworkReply *reply) {
    //QLOG_DEBUG() << "onNetworkManagerFinished";
    if (reply->error()) {
        //QLOG_DEBUG() << "onNetworkManagerFinished err " << reply->errorString();
        return;
    }

    QString answer = reply->readAll();
    QLOG_DEBUG() << "onNetworkManagerFinished OK"; // << answer;
}

#define GA_SITE "www.google-analytics.com"
#define GA_ID   "UA-123318717-1"
#define GA_EC   "app"
#define GA_EA   "sync"

//******************************************************************************
//* User synchronize was requested
//******************************************************************************
void NixNote::synchronize() {
    // If we are already connected, we are already synchronizing so there is nothing more to do
    if (global.connected) {
        return;
    }

    this->pauseIndexing(true);

    if (tabWindow->currentBrowser()->noteTitle.hasFocus()) {
        tabWindow->currentBrowser()->noteTitle.checkNoteTitleChange();
    }

    if (!this->checkAuthAndReauthorize()) {
        return;
    }

    QLOG_DEBUG() << "Preparing sync";

    QNetworkRequest request;
    const QString version = global.fileManager.getProgramVersion();
    QString url("https://" GA_SITE "/collect?v=1&tid=" GA_ID "&cid=");
    url.append(clientId).append("&t=event&ec=" GA_EC "&ea=" GA_EA "&el=").append(version);
    request.setUrl(QUrl(url));
    // QLOG_DEBUG() << "Req.url " << url;
    networkManager->get(request);

    this->saveContents();
    tabWindow->saveAllNotes();
    syncButtonTimer.start(36);
    emit syncRequested();
}

/**
 * Check if token is available & reauthorize if not.
 * Save new token.
 */
bool NixNote::checkAuthAndReauthorize() {
    if (!global.accountsManager->oauthTokenFound()) {
        QLOG_INFO() << "Authorization token not found => reauthorize";

        QString consumerKey = EDAM_CONSUMER_KEY;
        QString consumerSecret = EDAM_CONSUMER_SECRET;
        EvernoteOAuthDialog d(consumerKey, consumerSecret, global.server);
        d.setWindowTitle(tr("Log in to Evernote") + " (" + global.server + ")");
        if (d.exec() != QDialog::Accepted) {
            QLOG_INFO() << "Reauthorization failed";
            QMessageBox::critical(0, tr(NN_APP_DISPLAY_NAME_GUI), "Login failed.\n" + d.oauthError());
            return false;
        }
        const QString &oauthToken = d.oauthResult().authenticationToken;
        QString token = QString("oauth_token=") + oauthToken +
                        QString("&oauth_token_secret=&edam_shard=") + d.oauthResult().shardId +
                        QString("&edam_userId=") + QString::number(d.oauthResult().userId) +
                        QString("&edam_expires=") + QString::number(d.oauthResult().expires) +
                        QString("&edam_noteStoreUrl=") + d.oauthResult().noteStoreUrl +
                        QString("&edam_webApiUrlPrefix=") + d.oauthResult().webApiUrlPrefix;

        QLOG_INFO() << "Reauthorization OK";
        global.accountsManager->setOAuthToken(token);
        syncRunner.setUpdateUserDataOnNextSync(true);
    }
    return true;
}


//********************************************************************************
//* Disconnect from Evernote
//********************************************************************************
void NixNote::disconnect() {
    global.connected = false;
    menuBar->disconnectAction->setEnabled(false);
    syncButtonTimer.stop();
    pauseIndexing(false);
}


//********************************************************
//* Function called when a sync has completed.  It stops
//* the spinning sync icon and resets it to the default
//* value.
//*********************************************************
void NixNote::syncButtonReset() {
    pauseIndexing(false);
    if (syncIcons.size() == 0)
        return;
    syncButtonTimer.stop();
    syncButton->setIcon(syncIcons[0]);

    global.settings->beginGroup(INI_GROUP_SYNC);
    bool apiRateLimitAutoRestart =
        global.settings->value("apiRateLimitAutoRestart", false).toBool();
    bool connectionClosedAutoRestart =
        global.settings->value("connectionClosedAutoRestart", false).toBool();
    global.settings->endGroup();

    // If we had an API rate limit exceeded, restart at the top of the hour.
    if (apiRateLimitAutoRestart && syncRunner.apiRateLimitExceeded) {
        QTimer::singleShot(60 * 1000 * (syncRunner.minutesToNextSync + 1),
                this, SLOT(synchronize()));
        return;
    }

    if (connectionClosedAutoRestart && syncRunner.connectionClosed) {
        synchronize();
    }

//// If we had an API rate limit exceeded, restart at the top of the hour.
//    if (syncRunner.apiRateLimitExceeded) {
//        global.settings->beginGroup(INI_GROUP_SYNC);
//        bool restart = global.settings->value("apiRateLimitAutoRestart", false).toBool();
//        global.settings->endGroup();
//        if (restart) {
//            QTimer::singleShot(60 * 1000 * (syncRunner.minutesToNextSync + 1), this, SLOT(synchronize()));
//        }
//    }
}


//*****************************************************
//* Rotate the sync icon when we are connected to
//* Evernote and are transmitting & receiving info
//*****************************************************
void NixNote::updateSyncButton() {
    const int N_ICONS = 30;
    if (syncIcons.size() == 0) {
        double angle = 0.0;
        synchronizeIconIndex = 0;
        QPixmap pix(":synchronizeIcon");
        syncIcons.push_back(pix);

        QPainter p;
        p.setBackgroundMode(Qt::OpaqueMode);
        QSize size = pix.size();

        for (qint32 i = 1; i < N_ICONS; ++i) {
            QPixmap rotatedPix(pix.size());
            rotatedPix.fill(toolBar->palette().color(QPalette::Background));

            p.begin(&rotatedPix);
            p.translate(size.width() / 2, size.height() / 2);
            angle = angle + 360.0f/N_ICONS;
            p.rotate(angle);
            p.translate(-size.width() / 2, -size.height() / 2);

            p.drawPixmap(0, 0, pix);
            p.end();

            syncIcons.push_back(rotatedPix);
        }
    }
    synchronizeIconIndex++;
    if (synchronizeIconIndex == N_ICONS)
        synchronizeIconIndex = 0;
    syncButton->setIcon(syncIcons[synchronizeIconIndex]);
}


/**
 * Open note by current selection criteria.
 * If newWindow is true it is an external note request.
 *
 * @param newWindow Whenever open in new window.
 */
void NixNote::openNote(bool newWindow) {
    saveContents();
    FilterCriteria *criteria = global.getCurrentCriteria();
    qint32 lid;
    bool isLidSet = criteria->isLidSet();
    QLOG_DEBUG() << "Opening note lid=" << (isLidSet ? criteria->getLid() : -1);
    if (isLidSet) {
        lid = criteria->getLid();
        if (newWindow)
            tabWindow->openNote(lid, NTabWidget::NewTab);
        else
            tabWindow->openNote(lid, NTabWidget::CurrentTab);
    } else {
        tabWindow->openNote(-1, NTabWidget::CurrentTab);
    }
    rightArrowButton->setEnabled(false);
    leftArrowButton->setEnabled(false);

    int maxFilterPosition = global.filterCriteria.size() - 1;
    if (global.filterPosition < maxFilterPosition) {
        rightArrowButton->setEnabled(true);
    }
    if (global.filterPosition > 0) {
        leftArrowButton->setEnabled(true);
    }
    checkReadOnlyNotebook();
}


//**************************************************************
//* Open a note in an external window.
//**************************************************************
void NixNote::openExternalNote(qint32 lid) {
    tabWindow->openNote(lid, NTabWidget::ExternalWindow);
}


//*****************************************************
//* Called when a user changes the selection criteria
//* (i.e. they select a notebook, tag, saved search...
//*****************************************************
void NixNote::updateSelectionCriteria(bool afterSync) {
    QLOG_DEBUG() << "Updating selection criteria filtercnt="
                 << global.filterCriteria.size()
                 << ", pos=" << global.filterPosition
                 << ", afterSync=" << afterSync;

    tabWindow->currentBrowser()->saveNoteContent();

    // Invalidate the cache
    QDir dir(global.fileManager.getTmpDirPath());
    QFileInfoList files = dir.entryInfoList();

    for (int i = 0; i < files.size(); i++) {
        if (files[i].fileName().endsWith("_icon.png")) {
            QFile file(files[i].absoluteFilePath());
            file.remove();
        }
    }
    QList<qint32> keys = global.cache.keys();
    for (int i = 0; i < keys.size(); i++) {
        global.cache.remove(keys[i]);
    }

    // The filter() function can work without being passed parameters, but
    // it is best to allocate a QList<qint32> object for filter() here
    // in case that filter() returns result via it in the future.
    FilterEngine filterEngine;
    QList<qint32> *results = new QList<qint32>();
    filterEngine.filter(NULL, results);
    delete results;

    QLOG_DEBUG() << "Refreshing data";
    noteTableView->refreshData();
    noteTableView->scrollToTop();            // vertical scroll
    noteTableView->reset();                  // reset selection (to none)

    // yet missing:horizontal reset
    // focus search text after updating search criteria
    if (!afterSync) {
        searchText->setFocus(Qt::OtherFocusReason);
    }

    int maxFilterPosition = global.filterCriteria.size() - 1;
    if (global.filterPosition > maxFilterPosition) {
        // kind of emergency fix; we should handle it at more central point
        global.filterPosition = maxFilterPosition;
    }

    favoritesTreeView->updateSelection();
    tagTreeView->updateSelection();
    notebookTreeView->updateSelection();
    searchTreeView->updateSelection();
    attributeTree->updateSelection();
    trashTree->updateSelection();
    searchText->updateSelection();

    rightArrowButton->setEnabled(false);
    leftArrowButton->setEnabled(false);
    if (global.filterPosition < maxFilterPosition)
        rightArrowButton->setEnabled(true);
    if (global.filterPosition > 0)
        leftArrowButton->setEnabled(true);

    QList<qint32> selectedNotes;
    global.getCurrentCriteria()->getSelectedNotes(selectedNotes);
    if (selectedNotes.size() == 0) {
        tabWindow->currentBrowser()->clear();
        tabWindow->currentBrowser()->setReadOnly(true);
    }
    if (selectedNotes.size() > 0 && !afterSync) {
        //tabWindow->currentBrowser()->setContent(selectedNotes.at(0));  // <<<<<< This causes problems with multiple tabs after sync
        NBrowserWindow *window = nullptr;
        tabWindow->findBrowser(window, selectedNotes.at(0));
        if (window != nullptr) {
            window->setContent(selectedNotes.at(0));
        }
        if (!afterSync) {
            openNote(false);
        }
    }

    if (global.getCurrentCriteria()->isDeletedOnlySet() &&
        global.getCurrentCriteria()->getDeletedOnly())
        newNoteButton->setEnabled(false);
    else
        newNoteButton->setEnabled(true);

    emit updateCounts();
}


//******************************************************************
//* Check if the notebook selected is read-only.  With
//* read-only notes the editor and a lot of actions are disabled.
//******************************************************************
void NixNote::checkReadOnlyNotebook() {
    qint32 lid = tabWindow->currentBrowser()->lid;
    Note n;
    NoteTable ntable(global.db);
    NotebookTable btable(global.db);
    ntable.get(n, lid, false, false);
    qint32 notebookLid = 0;
    if (n.notebookGuid.isSet())
        notebookLid = btable.getLid(n.notebookGuid);
    if (btable.isReadOnly(notebookLid)) {
        newNoteButton->setEnabled(false);
        menuBar->deleteNoteAction->setEnabled(false);
    } else {
        newNoteButton->setEnabled(true);
        menuBar->deleteNoteAction->setEnabled(true);
    }
}


//*********************************************
//* User clicked the -> "forward" button
//* to go to the next history position.
//*********************************************
void NixNote::rightButtonTriggered() {
    int maxFilterPosition = global.filterCriteria.size() - 1;
    if (global.filterPosition >= maxFilterPosition) {
        return;
    }

    global.filterPosition++;
    updateSelectionCriteria();
}


//*********************************************
//* User clicked the <- "back" button
//* to go to the previous history position.
//*********************************************
void NixNote::leftButtonTriggered() {
    if (global.filterPosition <= 0) {
        return;
    }
    global.filterPosition--;
    updateSelectionCriteria();
}


void NixNote::exportSelectedNotes() {
    exportNotes(false);
}

//**************************************************
//* Backup (or export) notes
//**************************************************
void NixNote::exportNotes(bool exportAllNotes) {
    QLOG_TRACE() << "Entering databaseBackup()";
    ExportData noteReader(exportAllNotes);

    if (!exportAllNotes) {
        noteTableView->getSelectedLids(noteReader.lids);
        if (noteReader.lids.size() == 0) {
            QMessageBox::critical(this, tr("Error"), tr("No notes selected."));
            return;
        }
    }

    QString caption, directory;
    if (exportAllNotes)
        caption = tr("Export All Notes");
    else
        caption = tr("Export Notes");

    if (saveLastPath == "")
        directory = QDir::homePath();
    else
        directory = saveLastPath;

    QFileDialog fd(0, caption, directory, tr(APP_NNEX_APP_NAME " Export (*.nnex);;All Files (*.*)"));
    fd.setFileMode(QFileDialog::AnyFile);
    fd.setConfirmOverwrite(true);
    fd.setAcceptMode(QFileDialog::AcceptSave);

    if (fd.exec() == 0 || fd.selectedFiles().size() == 0) {
        QLOG_DEBUG() << "Export canceled in file dialog.";
        return;
    }

    waitCursor(true);
    QStringList fileNames;
    fileNames = fd.selectedFiles();
    saveLastPath = fileNames[0];
    int pos = saveLastPath.lastIndexOf("/");
    if (pos != -1)
        saveLastPath.truncate(pos);

    setMessage(tr("Performing export"));

    if (!fileNames[0].endsWith(".nnex")) {
        fileNames[0].append(".nnex");
    }
    noteReader.backupData(fileNames[0]);

    if (noteReader.lastError != 0) {
        setMessage(noteReader.errorMessage);
        QLOG_ERROR() << "Export problem: " << noteReader.errorMessage;
        QMessageBox::critical(this, tr("Error"), noteReader.errorMessage);
        waitCursor(false);
        return;
    }
    setMessage(tr("Note export complete."));
    waitCursor(false);
}


// partial import
void NixNote::noteImport() {
    importNotes(false);
}


// full or partial import
// basically same, just full import additionally displays warning
void NixNote::importNotes(bool fullRestore) {
    QLOG_TRACE() << "Entering importNotes()";

    if (fullRestore) {
        QMessageBox msgBox;
        msgBox.setText(
                tr("This is used to restore a database from backups.\nIt is HIGHLY recommended that this only be used to populate\nan empty database.  Restoring into a database that\n already has data can cause problems.\n\nAre you sure you want to continue?"));

        QPushButton *okButton = new QPushButton(tr("Ok"), &msgBox);
        msgBox.addButton(okButton, QMessageBox::AcceptRole);
        msgBox.addButton(new QPushButton(tr("Cancel"), &msgBox), QMessageBox::RejectRole);

        msgBox.setDefaultButton(okButton);
        msgBox.setWindowTitle(tr("Confirm Restore"));
        int retval = msgBox.exec();
        QLOG_DEBUG() << "Dialog answer: " << retval;
        if (retval != 0) {
            QLOG_INFO() << "Import of all notes has been canceled";
            return;
        }
    }

    QString caption, directory, filter;

    if (fullRestore) {
        caption = tr("Import all notes");
        filter = tr(APP_NNEX_APP_NAME " Export (*.nnex);;All Files (*.*)");
    } else {
        caption = tr("Import notes");
        filter = tr(APP_NNEX_APP_NAME " Export (*.nnex);;Evernote Export (*.enex);;All Files (*.*)");
    }

    if (saveLastPath == "")
        directory = QDir::homePath();
    else
        directory = saveLastPath;

    QFileDialog fd(0, caption, directory, filter);
    fd.setFileMode(QFileDialog::ExistingFile);
    fd.setConfirmOverwrite(true);
    fd.setAcceptMode(QFileDialog::AcceptOpen);

    if (fd.exec() == 0 || fd.selectedFiles().size() == 0) {
        QLOG_INFO() << "Note import canceled in file dialog";
        return;
    }

    waitCursor(true);
    QStringList fileNames;
    fileNames = fd.selectedFiles();
    saveLastPath = fileNames[0];
    int pos = saveLastPath.lastIndexOf("/");
    if (pos != -1)
        saveLastPath.truncate(pos);

    setMessage(tr("Importing notes"));

    if (fileNames[0].endsWith(".nnex") || fullRestore) {
        ImportData noteReader(fullRestore);
        noteReader.import(fileNames[0]);

        if (noteReader.lastError != 0) {
            setMessage(noteReader.getErrorMessage());
            QLOG_ERROR() << "Import problem: " << noteReader.errorMessage;
            QMessageBox::critical(this, tr("Error"), noteReader.errorMessage);
            waitCursor(false);
            return;
        }
    } else {
        ImportEnex enexReader;
        fullRestore = false;
        enexReader.import(fileNames[0]);
        QLOG_DEBUG() << "Back from import";
    }

    // Finish by filtering & displaying the data
    updateSelectionCriteria();

    tagTreeView->rebuildTagTreeNeeded = true;
    tagTreeView->loadData();
    searchTreeView->loadData();

    notebookTreeView->rebuildNotebookTreeNeeded = true;
    notebookTreeView->loadData();

    setMessage(tr("Notes have been imported."));
    waitCursor(false);
}


//*********************************************************
//* Set wait cursor
//*********************************************************
void NixNote::waitCursor(bool value) {
    Q_UNUSED(value); /* suppress warning of unused */
}


// Show a message in the status bar
// If timeout is 0 (default), the message remains displayed until the clearMessage() slot is called
// or until the showMessage() slot is called again to change the message.
void NixNote::setMessage(QString text, int timeout) {
    QLOG_TRACE_IN();
    statusBar()->showMessage(text, timeout);
    //QLOG_DEBUG() << "setMessage: " << text;
    QLOG_TRACE_OUT();
}


// Notification slot that the sync has completed.
void NixNote::notifySyncComplete() {
    updateSelectionCriteria(true);

    global.settings->beginGroup(INI_GROUP_SYNC);
    bool apiRateLimitAutoRestart = global.settings->value("apiRateLimitAutoRestart", false).toBool();
    global.settings->endGroup();
    global.settings->beginGroup(INI_GROUP_SYNC);
    bool syncNotifications = global.settings->value("enableNotification", false).toBool();
    global.settings->endGroup();

    bool popupOnSyncError = global.popupOnSyncError();
    bool haveSyncError = syncRunner.error;

    QLOG_DEBUG() << "notifySyncComplete: haveSyncError=" << haveSyncError
                 << ", apiRateLimitAutoRestart=" << apiRateLimitAutoRestart
                 << ", popupOnSyncError=" << popupOnSyncError
                 << ", syncNotifications=" << syncNotifications;

    if (haveSyncError && popupOnSyncError && !this->isHidden()) {
        QMessageBox::critical(this, tr("Sync Error"), tr("Sync error. See message log for details"));
        return;
    }

    if (!syncNotifications) {
        return;
    }
    if (haveSyncError) {
        showMessage(tr("Sync Error"), tr("Sync completed with errors."));
    } else if (global.showGoodSyncMessagesInTray) {
        showMessage(tr("Sync Complete"), tr("Sync completed successfully."));
    }

    QLOG_DEBUG() << "notifySyncComplete: done";
}


void NixNote::showMessage(QString title, QString msg, int timeout) {
    if (global.systemNotifier() == "notify-send") {
        QProcess notifyProcess;
        QStringList arguments;
        arguments << title << msg << "-t" << QString::number(timeout);
        notifyProcess.start(QString("notify-send"), arguments, QIODevice::ReadWrite | QIODevice::Unbuffered);
        notifyProcess.waitForFinished();
        QLOG_DEBUG() << "notify-send completed: " << notifyProcess.waitForFinished()
                     << " Return Code: " << notifyProcess.state();
    } else {
        trayIcon->showMessage(title, msg);
    }
}


//*******************************************************
//* Check for dirty notes and save the contents
//*******************************************************
void NixNote::saveContents() {
    for (int i = 0; i < tabWindow->browserList->size(); i++) {
        qint32 lid = tabWindow->browserList->at(i)->lid;
        // Check if the note is dirty
        if (tabWindow->browserList->at(i)->editor->isDirty) {
            tabWindow->browserList->at(i)->saveNoteContent();
            noteTableView->refreshCell(lid, NOTE_TABLE_IS_DIRTY_POSITION, true);
            // also redraw title column
            QVariant noData;
            noteTableView->refreshCell(lid, NOTE_TABLE_TITLE_POSITION, noData);
        }

    }
}


//********************************************
//* Reset values back to the unset values
//********************************************
void NixNote::resetView() {
    FilterCriteria *criteria = new FilterCriteria();
    global.getCurrentCriteria()->duplicate(*criteria);
    criteria->resetAttribute = true;
    criteria->resetDeletedOnly = true;
    criteria->resetFavorite = true;
    criteria->resetNotebook = true;
    criteria->resetSavedSearch = true;
    criteria->resetSearchString = true;
    criteria->resetTags = true;
    criteria->unsetFavorite();
    criteria->unsetNotebook();
    criteria->unsetDeletedOnly();
    criteria->unsetTags();
    criteria->unsetAttribute();
    criteria->unsetSavedSearch();
    criteria->unsetSearchString();
    global.filterCriteria.append(criteria);
    global.filterPosition++;
    // clear search text, after we clicked "All Notes"
    searchText->setText("");
    updateSelectionCriteria();
}

/**
 * Restore & create a new note - this is called from systray.
 */
void NixNote::restoreAndNewNote() {
    restoreAndShowMainWindow();
    newNote();
}


#define NEW_NOTE_ENML "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" \
                      "<!DOCTYPE en-note SYSTEM \"http://xml.evernote.com/pub/enml2.dtd\">" \
                      "<en-note style=\"word-wrap: break-word; -webkit-nbsp-mode: space; -webkit-line-break: after-white-space;\"></en-note>"

/**
 * Create a new note
 */
void NixNote::newNote() {
    QString newNoteBody = QString(NEW_NOTE_ENML);

    Note n;
    NotebookTable notebookTable(global.db);
    n.content = newNoteBody;
    n.title = tr("Untitled note");
    QString uuid = QUuid::createUuid().toString();
    uuid = uuid.mid(1);
    uuid.chop(1);
    n.guid = uuid;
    n.active = true;
    //QDateTime now;
    n.created = QDateTime::currentMSecsSinceEpoch();
    n.updated = n.created;
    n.updateSequenceNum = 0;
    if (notebookTreeView->selectedItems().size() > 0) {
        NNotebookViewItem *item = (NNotebookViewItem *) notebookTreeView->selectedItems().at(0);
        qint32 lid = item->lid;

        // If we have a stack, we find the first notebook (in alphabetical order) for the new note.
        if (lid == 0) {
            QString stackName = notebookTreeView->selectedItems().at(0)->data(0, Qt::DisplayRole).toString();
            QList<qint32> notebooks;
            notebookTable.getStack(notebooks, stackName);
            QString priorName;
            Notebook book;
            if (notebooks.size() > 0) {
                for (int i = 0; i < notebooks.size(); i++) {
                    qint32 priorLid = notebooks[i];
                    notebookTable.get(book, priorLid);
                    QString currentName = "";
                    if (book.name.isSet())
                        currentName = book.name;
                    if (currentName.toUpper() < priorName.toUpper() || priorName == "") {
                        lid = notebooks[i];
                    }
                    priorLid = notebooks[i];
                    priorName = currentName;
                }
            }
        }
        QString notebookGuid;
        notebookTable.getGuid(notebookGuid, lid);
        n.notebookGuid = notebookGuid;
    } else {
        QList<QTreeWidgetItem *> items = favoritesTreeView->selectedItems();
        QString notebookGuid = notebookTable.getDefaultNotebookGuid();
        for (int i = 0; i < items.size(); i++) {
            FavoritesViewItem *item = (FavoritesViewItem *) items[i];
            if (item->record.type == FavoritesRecord::LocalNotebook ||
                item->record.type == FavoritesRecord::SynchronizedNotebook) {
                QString guid;
                notebookTable.getGuid(guid, item->record.target.toInt());
                if (guid != "") {
                    notebookGuid = guid;
                    i = items.size();
                }
            }
        }
        n.notebookGuid = notebookGuid;
    }
    if (global.full_username != "") {
        NoteAttributes na;
        if (n.attributes.isSet())
            na = n.attributes;
        na.author = global.full_username;
        n.attributes = na;
    }
    NoteTable table(global.db);
    QLOG_DEBUG() << "Adding new note";
    qint32 lid = table.add(0, n, true);

    QLOG_DEBUG() << "New note added; lid=" << lid;
    FilterCriteria *criteria = new FilterCriteria();
    global.getCurrentCriteria()->duplicate(*criteria);
    criteria->unsetTags();
    criteria->unsetSearchString();
    criteria->setLid(lid);

    global.filterCriteria.append(criteria);
    // set last criteria as active
    global.filterPosition = global.filterCriteria.size() - 1;
    updateSelectionCriteria();
    openNote(false); // newWindow=false

    bool newNoteFocusToTitle = global.newNoteFocusToTitle();
    NBrowserWindow *browser = tabWindow->currentBrowser();
    QLOG_DEBUG() << "About to set focus to browser; newNoteFocusToTitle=" << newNoteFocusToTitle;
    if (newNoteFocusToTitle) {
        browser->noteTitle.setFocus();
        browser->noteTitle.selectAll();
    } else
        browser->editor->setFocus();
}


//**********************************************
//* Create a new note in an external window.
//**********************************************
void NixNote::newExternalNote() {
    QString newNoteBody = QString(NEW_NOTE_ENML);

    Note n;
    NotebookTable notebookTable(global.db);
    n.content = newNoteBody;
    n.title = tr("Untitled note");
    QString uuid = QUuid::createUuid().toString();
    uuid = uuid.mid(1);
    uuid.chop(1);
    n.guid = uuid;
    n.active = true;
    //QDateTime now;
    n.created = QDateTime::currentMSecsSinceEpoch();
    n.updated = n.created;
    n.updateSequenceNum = 0;
    if (notebookTreeView->selectedItems().size() == 0) {
        n.notebookGuid = notebookTable.getDefaultNotebookGuid();
    } else {
        NNotebookViewItem *item = (NNotebookViewItem *) notebookTreeView->selectedItems().at(0);
        qint32 lid = item->lid;

        // If we have a stack, we find the first notebook (in alphabetical order) for the new note.
        if (lid == 0) {
            QString stackName = notebookTreeView->selectedItems().at(0)->data(0, Qt::DisplayRole).toString();
            QList<qint32> notebooks;
            notebookTable.getStack(notebooks, stackName);
            QString priorName;
            Notebook book;
            if (notebooks.size() > 0) {
                for (int i = 0; i < notebooks.size(); i++) {
                    qint32 priorLid = notebooks[i];
                    notebookTable.get(book, priorLid);
                    QString currentName = "";
                    if (book.name.isSet())
                        currentName = book.name;
                    if (currentName.toUpper() < priorName.toUpper() || priorName == "") {
                        lid = notebooks[i];
                    }
                    priorLid = notebooks[i];
                    priorName = currentName;
                }
            }
        }
        QString notebookGuid;
        notebookTable.getGuid(notebookGuid, lid);
        n.notebookGuid = notebookGuid;
    }
    NoteTable table(global.db);
    qint32 lid = table.add(0, n, true);
    tabWindow->openNote(lid, NTabWidget::ExternalWindow);
    updateSelectionCriteria();

    // Find the position in the external window array & set the focus.
    int pos = -1;
    for (int i = 0; i < tabWindow->externalList->size(); i++) {
        if (tabWindow->externalList->at(i)->browser->lid == lid) {
            pos = i;
            i = tabWindow->externalList->size();
        }
    }

    // This shouldn't happen, but just in case...
    if (pos < 0)
        return;

    // Set the focus
    if (global.newNoteFocusToTitle()) {
        tabWindow->externalList->at(pos)->browser->noteTitle.setFocus();
        tabWindow->externalList->at(pos)->browser->noteTitle.selectAll();
    } else
        tabWindow->externalList->at(pos)->browser->editor->setFocus();

}


// Slot for when notes have been deleted from the notes list.
void NixNote::notesDeleted(QList<qint32>) {
    updateSelectionCriteria();
}


// Slot for when notes have been deleted from the notes list.
void NixNote::notesRestored(QList<qint32>) {
    updateSelectionCriteria();
}


// Open Evernote support
void NixNote::openEvernoteSupport() {
    QString server = "http://www.evernote.com/about/contact/support/";
    if (global.accountsManager->getServer() == "app.yinxiang.com")
        server = "https://support.yinxiang.com";
    QDesktopServices::openUrl(QUrl(server));
}


//*****************************************
//* Open the user account dialog box.
//*****************************************
void NixNote::openAccount() {
    AccountDialog dialog;
    dialog.exec();
}


//*******************************
//* Open Help/About dialog box.
//*******************************
void NixNote::openAbout() {
    AboutDialog about;
    about.exec();
}


//*******************************
//* Open About Qt dialog box.
//*******************************
void NixNote::openQtAbout() {
    QApplication::aboutQt();
}


//*********************************
//* Open Shortcut Keys Dialog
//*********************************
void NixNote::openShortcutsDialog() {
    ShortcutDialog *dialog = new ShortcutDialog();
    dialog->exec();
    delete dialog;
}


//**********************************************
//* Show/Hide the left display panel.
//**********************************************
void NixNote::toggleLeftPanel() {
    bool visible;
    if (leftPanel->isVisible()) {
        leftScroll->hide();
        visible = false;
    } else {
        visible = true;
        leftScroll->show();
    }
    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    global.settings->setValue("leftPanelVisible", visible);
    global.settings->endGroup();
}


//************************************************
//* Show/Hide the note table.
//************************************************
void NixNote::toggleNoteList() {
    bool value;
    if (topRightWidget->isVisible()) {
        topRightWidget->hide();
        value = false;
    } else {
        value = true;
        topRightWidget->show();
    }
    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    global.settings->setValue("noteListVisible", value);
    global.settings->endGroup();
}


//****************************************************
//* Show/hide the note editor/tab window.
//****************************************************
void NixNote::toggleTabWindow() {
    bool value;
    if (tabWindow->isVisible()) {
        tabWindow->hide();
        value = false;
    } else {
        tabWindow->show();
        value = true;
    }
    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    global.settings->setValue("tabWindowVisible", value);
    global.settings->endGroup();

}


//**************************************
//* Toggle the main window toolbar.
//**************************************
void NixNote::toggleToolbar() {
    if (toolBar->isVisible())
        toolBar->hide();
    else
        toolBar->show();
}


//*****************************************
//* Show/hide the window statusbar.
//*****************************************
void NixNote::toggleStatusbar() {
    if (statusBar()->isVisible())
        statusBar()->hide();
    else
        statusBar()->show();
    global.settings->beginGroup("saveState");
    global.settings->setValue("statusBar", statusBar()->isVisible());
    global.settings->endGroup();
}


//**********************************************
//* View the current note's history.
//**********************************************
void NixNote::viewNoteHistory() {
    this->saveContents();
    statusBar()->clearMessage();

    qint32 lid = this->tabWindow->currentBrowser()->lid;
    NoteTable ntable(global.db);
    Note n;
    ntable.get(n, lid, false, false);
    if (n.updateSequenceNum.isSet() && n.updateSequenceNum == 0) {
        QMessageBox::information(0, tr("Unsynchronized Note"),
                                 tr("This note has never been synchronized with Evernote"));
        return;
    }

    if (!this->checkAuthAndReauthorize()) {
        return;
    }

    UserTable userTable(global.db);
    User user;
    userTable.getUser(user);
    bool normalUser = false;
    if (user.privilege == PrivilegeLevel::NORMAL)
        normalUser = true;

    NoteHistorySelect dialog;
    QString guid = ntable.getGuid(tabWindow->currentBrowser()->lid);
    QList<NoteVersionId> versions;

    CommunicationManager comm(global.db);
    if (comm.enConnect()) {
        QList<NoteVersionId> versions;
        NoteTable ntable(global.db);
        QString guid = ntable.getGuid(tabWindow->currentBrowser()->lid);
        if (!normalUser)
            comm.listNoteVersions(versions, guid);
    }

    dialog.loadData(versions);
    dialog.exec();
    if (!dialog.importPressed)
        return;
    Note note;
    if (dialog.usn > 0 && !comm.getNoteVersion(note, guid, dialog.usn)) {
        QMessageBox mbox;
        mbox.setText(tr("Error retrieving note."));
        mbox.setWindowTitle(tr("Error retrieving note"));
        mbox.exec();
        return;
    }
    if (dialog.usn <= 0 && !comm.getNote(note, guid, true, true, true)) {
        QMessageBox mbox;
        mbox.setText(tr("Error retrieving note."));
        mbox.setWindowTitle(tr("Error retrieving note"));
        mbox.exec();
        return;
    }
    if (!dialog.replaceCurrentNote()) {
        note.updateSequenceNum = 0;
        note.active = true;
        QUuid uuid;
        QString newGuid = uuid.createUuid().toString().replace("{", "").replace("}", "");
        note.guid = newGuid;
        QList<Resource> resources;
        if (note.resources.isSet())
            resources = note.resources;
        for (int i = 0; i < resources.size(); i++) {
            Resource r = resources[i];
            r.updateSequenceNum = 0;
            newGuid = uuid.createUuid().toString().replace("{", "").replace("}", "");
            r.guid = newGuid;
            resources[i] = r;
        }
        note.resources = resources;
        qint32 newLid = ntable.add(0, note, true);
        tabWindow->currentBrowser()->setContent(newLid);
        QMessageBox::information(0, tr("Note Restored"), tr("A new copy has been restored."));
    } else {
        ntable.expunge(lid);
        bool dirty = true;
        if (dialog.usn <= 0)
            dirty = false;
        ntable.add(lid, note, dirty);
        tabWindow->currentBrowser()->setContent(0);
        tabWindow->currentBrowser()->setContent(lid);
        QMessageBox::information(0, tr("Note Restored"), tr("Note successfully restored."));
    }
    updateSelectionCriteria();
    setMessage(tr("Note restored"));
}


//****************************************
//* Search for text within a note
//****************************************
void NixNote::findInNote() {
    tabWindow->currentBrowser()->findShortcut();
//    if (!findReplaceWindow->isVisible()) {
//        findReplaceWindow->showFind();
//    } else {
//        if (findReplaceWindow->findLine->hasFocus())
//            findReplaceWindow->hide();
//        else {
//            findReplaceWindow->showFind();
//            findReplaceWindow->findLine->setFocus();
//            findReplaceWindow->findLine->selectAll();
//        }
//    }
}


//*******************************************
//* Search for the next occurrence of text
//* in a note.
//*******************************************
void NixNote::findNextInNote() {
    tabWindow->currentBrowser()->findNextInNote();
}


//*******************************************
//* Search for the previous occurrence of
//* text in a note.
//*******************************************
void NixNote::findPrevInNote() {
    tabWindow->currentBrowser()->findPrevInNote();
}


//*******************************************
//* This just does a null find to reset the
//* text in a note so nothing is highlighted.
//* This is triggered when the find dialog
//* box is hidden.
//*******************************************
void NixNote::findReplaceWindowHidden() {
    tabWindow->currentBrowser()->findReplaceWindowHidden();
}


//**************************************
//* Show find & replace dialog box.
//**************************************
void NixNote::findReplaceInNote() {
    tabWindow->currentBrowser()->findReplaceShortcut();
}


//***************************************
//* Find/replace button pressed, so we
//* need to highlight all the occurrences
//* in a note.
//***************************************
void NixNote::findReplaceInNotePressed() {
    tabWindow->currentBrowser()->findReplaceInNotePressed();
}


//**************************************************
//* Temporarily disable all note editing
//**************************************************
void NixNote::disableEditing() {
    global.disableEditing = !global.disableEditing;
    for (int i = 0; i < tabWindow->browserList->size(); i++) {
        NBrowserWindow *browser = tabWindow->browserList->at(i);
        browser->setReadOnly(global.disableEditing && browser->isReadOnly);
    }
    for (int i = 0; i < tabWindow->externalList->size(); i++) {
        NBrowserWindow *browser = tabWindow->externalList->at(i)->browser;
        browser->setReadOnly(global.disableEditing && browser->isReadOnly);
    }
}


//*************************************************
//* Replace All button pressed.
//*************************************************
void NixNote::findReplaceAllInNotePressed() {
    tabWindow->currentBrowser()->findReplaceAllInNotePressed();
}


//**************************************************************
//* This queries the shared memory segment at occasional
//* intervals.  This is useful for cross-program communication.
//**************************************************************
void NixNote::heartbeatTimerTriggered() {
    QByteArray data = global.sharedMemory->read();

    if (data.startsWith("SYNCHRONIZE")) {
        QLOG_INFO() << "SYNCHRONIZE requested by shared memory segment.";
        this->synchronize();
        return;
    } else if (data.startsWith("IMMEDIATE_SHUTDOWN")) {
        QLOG_INFO() << "IMMEDIATE_SHUTDOWN requested by shared memory segment (quitNixNote).";
        this->quitNixNote();
        return;
    } else if (data.startsWith("SHOW_WINDOW")) {
        QLOG_INFO() << "SHOW_WINDOW requested by shared memory segment.";
        this->raise();
        this->showMaximized();
        return;
    } else if (data.startsWith("QUERY:")) {
        QLOG_INFO() << "QUERY requested by shared memory segment.";
        QList<qint32> results;
        QString query = data.mid(6);
        QLOG_DEBUG() << query;
        FilterCriteria filter;
        filter.setSearchString(query);
        FilterEngine engine;
        engine.filter(&filter, &results);
        QString xmlString;
        QXmlStreamWriter dom(&xmlString);
        dom.setAutoFormatting(true);
        dom.writeStartDocument();
        dom.writeStartElement("response");
        NoteTable ntable(global.db);
        for (int i = 0; i < results.size(); i++) {
            dom.writeStartElement("note");
            dom.writeStartElement("lid");
            dom.writeCharacters(QString::number(results[i]));
            dom.writeEndElement();
            Note n;
            ntable.get(n, results[i], false, false);
            if (n.title.isSet()) {
                dom.writeStartElement("title");
                dom.writeCharacters(n.title);
                dom.writeEndElement();
            }
            QString filename = global.fileManager.getThumbnailDirPath("") + QString::number(results[i]) + ".png";
            QFile file(filename);
            if (file.exists()) {
                dom.writeStartElement("preview");
                dom.writeCharacters(filename);
                dom.writeEndElement();
            }
            dom.writeEndElement();
        }
        dom.writeEndElement();
        dom.writeEndDocument();

        global.sharedMemory->write(xmlString);
    } else if (data.startsWith("OPEN_NOTE:")) {
        QLOG_INFO() << "OPEN_NOTE requested by shared memory segment.";
        QString number = data.mid(10);
        qint32 note = number.toInt();
        NoteTable noteTable(global.db);
        if (noteTable.exists(note))
            this->openExternalNote(note);
    } else if (data.startsWith("NEW_NOTE")) {
        QLOG_INFO() << "NEW_NOTE requested by shared memory segment.";
        this->newExternalNote();
    } else if (data.startsWith("CMDLINE_QUERY:")) {
        QLOG_INFO() << "CMDLINE_QUERY requested by shared memory segment.";
        QString xml = data.mid(14);
        CmdLineQuery query;
        query.unwrap(xml.trimmed());
        QString tmpFile = global.fileManager.getTmpDirPath() + query.returnUuid + ".txt";
        FilterCriteria *filter = new FilterCriteria();
        FilterEngine engine;
        filter->setSearchString(query.query);
        QList<qint32> lids;
        engine.filter(filter, &lids);
        query.write(lids, tmpFile);
    } else if (data.startsWith("DELETE_NOTE:")) {
        QLOG_INFO() << "DELETE_NOTE requested by shared memory segment.";
        qint32 lid = data.mid(12).toInt();
        NoteTable noteTable(global.db);
        noteTable.deleteNote(lid, true);
        updateSelectionCriteria();
    } else if (data.startsWith("EMAIL_NOTE:")) {
        QLOG_INFO() << "EMAIL_NOTE requested by shared memory segment.";
        QString xml = data.mid(11);
        EmailNote email;
        email.unwrap(xml);
        email.sendEmail();
    } else if (data.startsWith("ALTER_NOTE:")) {
        QLOG_INFO() << "ALTER_NOTE requested by shared memory segment.";
        QString xml = data.mid(11);
        AlterNote alter;
        alter.unwrap(xml);
        alter.alterNote();
        updateSelectionCriteria();
    } else if (data.startsWith("READ_NOTE:")) {
        QLOG_INFO() << "READ_NOTE requested by shared memory segment.";
        QString xml = data.mid(10);
        ExtractNoteText data;
        data.unwrap(xml);
        NoteTable ntable(global.db);
        Note n;
        if (ntable.get(n, data.lid, false, false))
            data.text = data.stripTags(n.content);
        else
            data.text = tr("Note not found.");
        QString reply = data.wrap();
        CrossMemoryMapper responseMapper(data.returnUuid);
        if (!responseMapper.attach())
            return;
        responseMapper.write(reply);
        responseMapper.detach();
    } else if (data.startsWith("SIGNAL_GUI:")) {
        QLOG_INFO() << "SIGNAL_GUI requested by shared memory segment.";
        QString cmd = data.mid(12);
        QLOG_DEBUG() << "COMMAND REQUESTED: " << cmd;
        if (cmd.startsWith("SYNCHRONIZE")) {
            this->synchronize();
        } else if (cmd.startsWith("SHUTDOWN")) {
            QLOG_INFO() << "calling quitNixNote";
            this->quitNixNote();
        } else if (cmd.startsWith("SHOW")) {
            this->restoreAndShowMainWindow();
        } else if (cmd.startsWith("NEW_NOTE")) {
            this->restoreAndNewNote();
        } else if (cmd.startsWith("NEW_EXTERNAL_NOTE")) {
            this->newExternalNote();
            this->raise();
            this->activateWindow();
            if (tabWindow->lastExternal != nullptr) {
                tabWindow->lastExternal->activateWindow();
                tabWindow->lastExternal->showNormal();
                tabWindow->lastExternal->browser->editor->setFocus();
            }
        } else if (cmd.startsWith("OPEN_EXTERNAL_NOTE")) {
            cmd = cmd.mid(18);
            qint32 lid;
            if (cmd.startsWith("_URL")) {
                QString noteUrl = cmd.mid(4);
                NoteTable ntable(global.db);
                lid = ntable.getLidFromUrl(noteUrl);
            } else {
                lid = cmd.toInt();
            }
            this->openExternalNote(lid);
            if (tabWindow->lastExternal != nullptr) {
                tabWindow->lastExternal->activateWindow();
                tabWindow->lastExternal->showNormal();
                tabWindow->lastExternal->browser->editor->setFocus();
            }
            return;
        } else if (cmd.startsWith("OPEN_NOTE")) {
            bool newTab = false;
            this->restoreAndShowMainWindow();
            if (cmd.startsWith("OPEN_NOTE_NEW_TAB")) {
                newTab = true;
                cmd = cmd.mid(17);
            } else {
                cmd = cmd.mid(9);
            }
            qint32 lid;
            if (cmd.startsWith("_URL")) {
                QString noteUrl = cmd.mid(4);
                NoteTable ntable(global.db);
                lid = ntable.getLidFromUrl(noteUrl);
            } else {
                lid = cmd.toInt();
            }
            QList<qint32> lids;
            lids.append(lid);

            // First, find out if we're already viewing history.  If we are we
            // chop off the end of the history & start a new one
            if (global.filterPosition + 1 < global.filterCriteria.size()) {
                while (global.filterPosition + 1 < global.filterCriteria.size())
                    delete global.filterCriteria.takeAt(global.filterCriteria.size() - 1);
            }

            auto *newFilter = new FilterCriteria();
            global.filterCriteria.at(global.filterPosition)->duplicate(*newFilter);

            newFilter->setSelectedNotes(lids);
            newFilter->setLid(lid);
            global.filterCriteria.push_back(newFilter);
            global.filterPosition++;
            this->openNote(newTab);

            this->restoreAndShowMainWindow();
        } else {
            QLOG_DEBUG() << "unhandled command";
        }
    } else {
        // not sure what all can mean "no command" (maybe later improve)
        //QLOG_DEBUG() << "heartbeatTimerTriggered: unhandled command";
    }
}


// Open the dialog status dialog box.
void NixNote::openDatabaseStatus() {
    DatabaseStatus dbstatus;
    dbstatus.exec();
}


// Open the dialog status dialog box.
void NixNote::openImportFolders() {
    WatchFolderDialog dialog;
    dialog.exec();
    if (dialog.okClicked) {
        importManager->reset();
        importManager->setup();
    }
}


// Print the current note
void NixNote::printNote() {
    tabWindow->currentBrowser()->fastPrint = false;
    tabWindow->currentBrowser()->printNote();
}


// Print the current note
void NixNote::emailNote() {
    tabWindow->currentBrowser()->emailNote();
}


// Print the current note
void NixNote::printPreviewNote() {
    tabWindow->currentBrowser()->printPreviewNote();
}


// Print the current note
void NixNote::fastPrintNote() {
    tabWindow->currentBrowser()->fastPrint = true;
    tabWindow->currentBrowser()->printNote();
}


/**
 * Toggle the window visibility.  Used when closing to
 * the tray.
 */
void NixNote::showMainWindow() {
    QLOG_DEBUG() << "showMainWindow";
    this->setWindowState(Qt::WindowActive);

    this->showNormal();            // Restores the widget after it has been maximized or minimized
    this->show();                  // Shows the widget and its child widgets
    this->raise();                 // Raises this widget to the top of the parent widget's stack
    this->activateWindow();        // Sets the top-level widget containing this widget to be the active window
    // Gives the keyboard input focus to this widget (or its focus proxy) if this widget or one of its parents is the active window
    this->setFocus();
    this->show();                  // Shows the widget and its child widgets
}

/**
 * This is more strong version which should also recover window, if open but not minimized.
 * May have side effects.
 */
void NixNote::restoreAndShowMainWindow() {
    QLOG_DEBUG() << "restoreAndShowMainWindow";
    setWindowFlags(Qt::WindowStaysOnTopHint); // recovery from "behind other window" - may have side effects

    // normal "show"
    showMainWindow();

    this->setWindowFlags(Qt::Window);
    this->show();                  // Shows the widget and its child widgets
}


void NixNote::trayActivatedAction(int value) {
    QLOG_DEBUG() << "trayActivatedAction action=" << value;

    if (value == TRAY_ACTION_SHOW) {
        restoreAndShowMainWindow();
    } else if (value == TRAY_ACTION_NEWNOTE) {
        restoreAndNewNote();
    }
}

/**
 * The tray icon was activated.  E.g. if it was double clicked we restore the gui.
 */
void NixNote::onTrayActivated(QSystemTrayIcon::ActivationReason reason) {

    if (reason == QSystemTrayIcon::DoubleClick || reason == QSystemTrayIcon::Trigger) {
        QLOG_DEBUG() << "onTrayActivated reason=DoubleClick (" << reason << ")";
        global.settings->beginGroup(INI_GROUP_APPEARANCE);
        int value = global.settings->value("trayDoubleClickAction", -1).toInt();
        global.settings->endGroup();
        trayActivatedAction(value);
    } else if (reason == QSystemTrayIcon::MiddleClick) {
        QLOG_DEBUG() << "onTrayActivated reason=MiddleClick (" << reason << ")";
        global.settings->beginGroup(INI_GROUP_APPEARANCE);
        int value = global.settings->value("trayMiddleClickAction", -1).toInt();
        global.settings->endGroup();
        trayActivatedAction(value);
    } else {
        QLOG_DEBUG() << "onTrayActivated unknowm reason=" << reason;
    }
}



//*******************************************************
//* Event triggered when the window state is changing.
//* Useful when hiding & restoring from the tray.
//*******************************************************
//void NixNote::changeEvent(QEvent *e) {
//    return QMainWindow::changeEvent(e);
//}

bool NixNote::event(QEvent *event) {
    if (event->type() == QEvent::WindowStateChange && isMinimized()) {
        if (minimizeToTray) {
            hide();
            return false;
        }
    }

    if (event->type() == QEvent::Close) {
        if (closeToTray && isVisible()) {
            QLOG_DEBUG() << "overriding close event => minimize";

            hide();
            this->setHidden(true);

            event->ignore();
            return false;
        }
    }
    return QMainWindow::event(event);
}


//*****************************************************
//* Open the Edit/Preferences dialog box.
//*****************************************************
void NixNote::openPreferences() {
    PreferencesDialog prefs;
    prefs.exec();
    if (prefs.okButtonPressed) {
        setSyncTimer();
        bool showTrayIcon = global.readSettingShowTrayIcon();
        const auto wIcon = QIcon(global.getIconResource(":windowIcon"));
        if (!wIcon.isNull()) {
            setWindowIcon(wIcon);
        }
        trayIcon->setIcon(global.getIconResource(":trayIcon"));
        trayIcon->setVisible(showTrayIcon);
        if (!showTrayIcon) {
            if (!this->isVisible())
                this->show();

        } else {
            minimizeToTray = global.readSettingMinimizeToTray();
            closeToTray = global.readSettingCloseToTray();
        }

        indexRunner.officeFound = global.synchronizeAttachments();
    }
}


//**************************************************************
//* Set the automatic sync timer interval.
//**************************************************************
void NixNote::setSyncTimer() {
    global.settings->beginGroup(INI_GROUP_SYNC);
    bool automaticSync = global.settings->value("syncAutomatically", false).toBool();
    int interval = global.settings->value("syncInterval", 15).toInt();
    if (interval < 15)
        interval = 15;
    global.settings->endGroup();
    syncTimer.blockSignals(true);
    syncTimer.stop();
    syncTimer.blockSignals(false);
    if (!automaticSync) {
        return;
    }
    syncTimer.setInterval(60 * 1000 * interval);
    syncTimer.blockSignals(true);
    syncTimer.start();
    syncTimer.blockSignals(false);
}


//*********************************************************************
//* Switch user account.
//*********************************************************************
void NixNote::switchUser() {
    QAction *userSwitch;
    QList<int> checkedEntries;
    int currentAcctPos = 0;
    int newAcctPos = 0;
    for (int i = 0; i < menuBar->userAccountActions.size(); i++) {
        userSwitch = menuBar->userAccountActions[i];
        int actionID = userSwitch->data().toInt();
        if (actionID == global.accountsManager->currentId)
            currentAcctPos = i;
        else if (userSwitch->isChecked())
            newAcctPos = i;
        if (userSwitch->isChecked()) {
            checkedEntries.append(i);
        }
    }

    // If nothing is checked, we recheck the old one or
    // if more than one is checked, we uncheck the old guy
    if (checkedEntries.size() == 0) {
        menuBar->blockSignals(true);
        menuBar->userAccountActions[currentAcctPos]->setChecked(true);
        menuBar->blockSignals(false);
        return;
    }
    if (checkedEntries.size() > 1) {
        menuBar->blockSignals(true);
        menuBar->userAccountActions[currentAcctPos]->setChecked(false);
        menuBar->blockSignals(false);
        global.accountsManager->currentId = menuBar->userAccountActions[newAcctPos]->data().toInt();
        global.globalSettings->beginGroup(INI_GROUP_SAVE_STATE);
        global.globalSettings->setValue("lastAccessedAccount", global.accountsManager->currentId);
        global.globalSettings->endGroup();
        quitAction->trigger();
        global.sharedMemory->detach();
        QProcess::startDetached(QCoreApplication::applicationFilePath());
        return;
    }
}


//*********************************************************************
//* Add another user account.
//*********************************************************************
void NixNote::addAnotherUser() {
    AddUserAccountDialog dialog;
    dialog.exec();
    if (!dialog.okPushed)
        return;
    QString name = dialog.newAccountName->text().trimmed();
    int six = dialog.newAccountServer->currentIndex();
    QString server = dialog.newAccountServer->itemData(six, Qt::UserRole).toString();
    int newid = global.accountsManager->addId(-1, name, "", server);
    QAction *newAction = new QAction(menuBar);
    newAction->setText(tr("Switch to ") + name);
    newAction->setCheckable(true);
    newAction->setData(newid);
    menuBar->addUserAccount(newAction);
    connect(newAction, SIGNAL(triggered()), this, SLOT(switchUser()));
}


//*********************************************************************
//* Edit a user account
//*********************************************************************
void NixNote::userMaintenance() {
    AccountMaintenanceDialog dialog(menuBar, this);
    dialog.exec();
}


//*********************************************************************
//* Show the note list in a wide view above the editor.
//*********************************************************************
void NixNote::viewNoteListWide() {
    menuBar->blockSignals(true);
    menuBar->viewNoteListNarrow->setChecked(false);
    menuBar->viewNoteListWide->setChecked(true);
    menuBar->blockSignals(false);

    saveNoteColumnPositions();
    saveNoteColumnWidths();
    noteTableView->saveColumnsVisible();

    rightPanelSplitter->setOrientation(Qt::Vertical);
    global.listView = Global::ListViewWide;
    noteTableView->setColumnsVisible();
    noteTableView->repositionColumns();
    noteTableView->resizeColumns();

    // a bit hack again - displaying all notes will reset font size which wasn't ok before
    resetView();
}


//*********************************************************************
//* Show the note list in a narrow view between the editor & left panel.
//*********************************************************************
void NixNote::viewNoteListNarrow() {

    menuBar->blockSignals(true);
    menuBar->viewNoteListWide->setChecked(false);
    menuBar->viewNoteListNarrow->setChecked(true);
    menuBar->blockSignals(false);

    saveNoteColumnPositions();
    saveNoteColumnWidths();
    noteTableView->saveColumnsVisible();

    rightPanelSplitter->setOrientation(Qt::Horizontal);
    global.listView = Global::listViewNarrow;
    noteTableView->setColumnsVisible();
    noteTableView->repositionColumns();
    noteTableView->resizeColumns();

    // a bit hack again - displaying all notes will reset font size which wasn't ok before
    resetView();
}


// This is called via global.resourceWatcher when a resource
// has been updated by an external program.  The file name is the
// resource file which starts with the lid.
void NixNote::resourceExternallyUpdated(QString resourceFile) {
    // We do a remove of the watcher at the beginning and a
    // re-add at the end, because some applications don't actually
    // update an existing file, but delete & re-add it. The delete
    // causes NN to stop watching and any later saves are lost.
    // This re-add at the end hopefully fixes it.
    global.resourceWatcher->removePath(resourceFile);
    QString shortName = resourceFile;
    QString dba = global.fileManager.getDbaDirPath();
    shortName.replace(dba, "");
    int pos = shortName.indexOf(".");
    if (pos != -1) {
        shortName = shortName.mid(0, pos);
    }

    qint32 lid = shortName.toInt();
    QFile file(resourceFile);
    file.open(QIODevice::ReadOnly);
    QByteArray ba = file.readAll();
    file.close();
    QByteArray newHash = QCryptographicHash::hash(ba, QCryptographicHash::Md5);
    ResourceTable resTable(global.db);
    QByteArray oldHash = resTable.getDataHash(lid);
    if (oldHash != newHash) {
        QLOG_DEBUG() << "Detected change of " << resourceFile << " old hash " << oldHash << " new hash " << newHash;

        qint32 noteLid = resTable.getNoteLid(lid);
        resTable.updateResourceHash(lid, newHash);
        NoteTable noteTable(global.db);
        noteTable.updateEnmediaHash(noteLid, oldHash, newHash, true);
        tabWindow->updateResourceHash(noteLid, oldHash, newHash);
    }

    AttachmentIconBuilder icon;
    icon.buildIcon(lid, resourceFile);
    global.resourceWatcher->addPath(resourceFile);
}


// Reindex all notes & resources
void NixNote::reindexDatabase() {

    int response = QMessageBox::question(this, tr("Reindex Database"), tr("Reindex the entire database?"),
                                         QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (response != QMessageBox::Yes)
        return;

    NoteTable ntable(global.db);
    ResourceTable rtable(global.db);
    rtable.reindexAllResources();
    ntable.reindexAllNotes();

    setMessage(tr("Notes will be reindexed."));
}


// Open/Close selected notebooks
void NixNote::openCloseNotebooks() {
    CloseNotebookDialog dialog;
    dialog.exec();
    if (dialog.okPressed) {
        notebookTreeView->rebuildNotebookTreeNeeded = true;
        this->updateSelectionCriteria();
        notebookTreeView->rebuildTree();
    }
}

// Reindex the current note
void NixNote::reindexCurrentNote() {
    tabWindow->currentBrowser()->saveNoteContent();

    NoteIndexer indexer(global.db);
    indexer.indexNote(tabWindow->currentBrowser()->lid);

    ResourceTable rtable(global.db);
    QList<qint32> rlids;
    rtable.getResourceList(rlids, tabWindow->currentBrowser()->lid);
    for (int i = 0; i < rlids.size(); i++) {
        indexer.indexResource(rlids[i]);
    }
    QMessageBox::information(0, tr("Note Reindexed"), "Reindex Complete");
}


bool NixNote::isOkToDeleteNote(QString msg) {
    if (!global.confirmDeletes()) {
        return true;
    }


    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Verify Delete"));
    msgBox.setText(msg);
    QPushButton *yesButton = new QPushButton(tr("Yes"), &msgBox);
    msgBox.addButton(yesButton, QMessageBox::YesRole);
    msgBox.addButton(new QPushButton(tr("No"), &msgBox), QMessageBox::NoRole);

    msgBox.setIcon(QMessageBox::Question);
    msgBox.setDefaultButton(yesButton);
    int rc = msgBox.exec();
    QLOG_DEBUG() << "Delete dialog reply: " << rc;
    return rc == 0;
}


// Delete the note we are currently viewing
void NixNote::deleteCurrentNote() {
    qint32 lid = tabWindow->currentBrowser()->lid;

    QString typeDelete;
    QString msg;
    FilterCriteria *f = global.getCurrentCriteria();
    bool expunged = false;
    typeDelete = tr("Delete ");

    if (f->isDeletedOnlySet() && f->getDeletedOnly()) {
        typeDelete = tr("Permanently delete ");
        expunged = true;
    }

    msg = typeDelete + tr("this note?");
    if (!isOkToDeleteNote(msg)) {
        return;
    }

    NoteTable ntable(global.db);
    NSqlQuery sql(global.db);
    sql.prepare("Delete from filter where lid=:lid");
    ntable.deleteNote(lid, true);
    if (expunged)
        ntable.expunge(lid);
    sql.bindValue(":lid", lid);
    sql.exec();
    sql.finish();
    delete global.cache[lid];
    global.cache.remove(lid);
    QList<qint32> lids;
    lids.append(lid);
    emit(notesDeleted(lids));
}


// Duplicate the current note
void NixNote::duplicateCurrentNote() {
    tabWindow->currentBrowser()->saveNoteContent();
    qint32 oldLid = tabWindow->currentBrowser()->lid;
    qint32 newLid;
    NoteTable ntable(global.db);
    newLid = ntable.duplicateNote(oldLid);

    FilterCriteria *criteria = new FilterCriteria();
    global.getCurrentCriteria()->duplicate(*criteria);
    criteria->setLid(newLid);
    global.filterCriteria.append(criteria);
    global.filterPosition++;
    openNote(false);
    updateSelectionCriteria();
    tabWindow->currentBrowser()->editor->setFocus();
}


// "Pin" the current note.  This makes sure it appears in all searches
void NixNote::pinCurrentNote() {
    qint32 lid = tabWindow->currentBrowser()->lid;
    NoteTable ntable(global.db);
    ntable.pinNote(lid, true);
    updateSelectionCriteria();
}


// "Unpin" the current note so it doesn't appear in every search
void NixNote::unpinCurrentNote() {
    qint32 lid = tabWindow->currentBrowser()->lid;
    NoteTable ntable(global.db);
    ntable.pinNote(lid, false);
    updateSelectionCriteria();
}


// Run the spell checker
void NixNote::spellCheckCurrentNote() {
    tabWindow->currentBrowser()->spellCheckPressed();
}


// Pause/unpause indexing.
void NixNote::pauseIndexing(bool value) {
    if (menuBar->pauseIndexingAction->isChecked()) {
        indexRunner.pauseIndexing = true;
        return;
    }
    indexRunner.pauseIndexing = value;
}


// View the message log info
void NixNote::openMessageLogInfo() {
    QMessageBox mb;
    mb.information(this, tr("Application file(s) info"),
                   tr("Config files are located at:") + "\n"
                   + global.fileManager.getConfigDir() + "\n"
                   + tr("Note database files are located at:") + "\n"
                   + global.fileManager.getUserDataDir() + "\n\n"
                   + tr("Main app log file is located at:") + "\n"
                   + global.fileManager.getMainLogFileName() + "\n"
                   + "\n"
                   + tr("See project wiki section FAQ (Menu Help/Project wiki) for more info how to:") + "\n"
                   + tr("* change log level") + "\n"
                   + tr("* look at log") + "\n"
                   + tr("* how to add content of log file to github issue") + "\n"
                   + tr("* how to change data location")
    );
}


// Show a url to the debugging log
void NixNote::showDesktopUrl(const QUrl &url) {
    QLOG_DEBUG() << url.toString();
}


// Reload the icons after a theme switch
void NixNote::reloadIcons() {
    QString newThemeName = "";
    global.settings->beginGroup(INI_GROUP_APPEARANCE);
    QString currentTheme = global.settings->value("themeName", "").toString();
    global.settings->endGroup();

    QAction *themeSwitch;
    QList<int> checkedEntries;
    int currentThemePos = 0;
    int newThemePos = 0;
    for (int i = 0; i < menuBar->themeActions.size(); i++) {
        themeSwitch = menuBar->themeActions[i];
        QString checkedTheme = themeSwitch->data().toString();
        if (checkedTheme == currentTheme)
            currentThemePos = i;
        else {
            if (themeSwitch->isChecked())
                newThemePos = i;
        }
        if (themeSwitch->isChecked()) {
            checkedEntries.append(i);
        }
    }

    // If nothing is checked, we recheck the old one or
    // if more than one is checked, we uncheck the old guy
    if (checkedEntries.size() == 0) {
        menuBar->blockSignals(true);
        menuBar->themeActions[currentThemePos]->setChecked(true);
        menuBar->blockSignals(false);
    }
    if (checkedEntries.size() > 0) {
        menuBar->blockSignals(true);
        menuBar->themeActions[currentThemePos]->setChecked(false);
        menuBar->blockSignals(false);
        global.settings->beginGroup(INI_GROUP_APPEARANCE);
        newThemeName = menuBar->themeActions[newThemePos]->data().toString();
        if (newThemeName != "")
            global.settings->setValue("themeName", newThemeName);
        else
            global.settings->remove("themeName");
        global.settings->endGroup();
        global.loadTheme(global.resourceList, global.colorList, newThemeName);
    }

    const auto wIcon = QIcon(global.getIconResource(":windowIcon"));
    if (!wIcon.isNull()) {
        setWindowIcon(wIcon);
    }
    leftArrowButton->setIcon(global.getIconResource(":leftArrowIcon"));
    rightArrowButton->setIcon(global.getIconResource(":rightArrowIcon"));
    homeButton->setIcon(global.getIconResource(":homeIcon"));
    syncButton->setIcon(global.getIconResource(":synchronizeIcon"));
    printNoteButton->setIcon(global.getIconResource(":printerIcon"));
    newNoteButton->setIcon(global.getIconResource(":newNoteIcon"));
    deleteNoteButton->setIcon(global.getIconResource(":deleteIcon"));

    trayIcon->setIcon(global.getIconResource(":trayIcon"));
    emailButton->setIcon(global.getIconResource(":emailIcon"));
    notebookTreeView->reloadIcons();
    tagTreeView->reloadIcons();
    attributeTree->reloadIcons();
    trashTree->reloadIcons();
    searchTreeView->reloadIcons();
    favoritesTreeView->reloadIcons();
    tabWindow->reloadIcons();

    global.clearResourceList();

    tabWindow->changeEditorStyle();

    QString themeInformation = global.getResourceFileName(global.resourceList, ":themeInformation");
    menuBar->themeInformationAction->setVisible(true);
    if (themeInformation.startsWith("http://", Qt::CaseInsensitive))
        return;
    if (themeInformation.startsWith("https://", Qt::CaseInsensitive))
        return;

    QFile f(themeInformation);
    if (!f.exists() && newThemeName != "")
        menuBar->themeInformationAction->setVisible(false);
}


// Show/Hide the favorites tree on the left side
void NixNote::toggleFavoritesTree() {
    bool visible = true;
    if (favoritesTreeView->isVisible())
        visible = false;
    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    global.settings->setValue("favoritesTreeVisible", visible);
    global.settings->endGroup();
    favoritesTreeView->setVisible(visible);
    checkLeftPanelSeparators();
}


// Show/Hide the notebook tree on the left side
void NixNote::toggleNotebookTree() {
    bool visible = true;
    if (notebookTreeView->isVisible())
        visible = false;
    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    global.settings->setValue("notebookTreeVisible", visible);
    global.settings->endGroup();
    notebookTreeView->setVisible(visible);
    checkLeftPanelSeparators();
}


// Show/Hide the tag tree on the left side
void NixNote::toggleTagTree() {
    bool visible = true;
    if (tagTreeView->isVisible())
        visible = false;
    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    global.settings->setValue("tagTreeVisible", visible);
    global.settings->endGroup();
    tagTreeView->setVisible(visible);
    checkLeftPanelSeparators();
}


// Show/Hide the saved search tree on the left side
void NixNote::toggleSavedSearchTree() {
    bool visible = true;
    if (searchTreeView->isVisible())
        visible = false;
    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    global.settings->setValue("savedSearchTreeVisible", visible);
    global.settings->endGroup();
    searchTreeView->setVisible(visible);
    checkLeftPanelSeparators();
}


// Show/Hide the attributes tree on the left side
void NixNote::toggleAttributesTree() {
    bool visible = true;
    if (attributeTree->isVisible())
        visible = false;
    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    global.settings->setValue("attributeTreeVisible", visible);
    global.settings->endGroup();
    attributeTree->setVisible(visible);
    checkLeftPanelSeparators();
}

// Show/Hide the trash tree on the left side
void NixNote::toggleTrashTree() {
    bool visible = true;
    if (trashTree->isVisible())
        visible = false;
    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    global.settings->setValue("trashTreeVisible", visible);
    global.settings->endGroup();
    trashTree->setVisible(visible);
    checkLeftPanelSeparators();
}


// This function will show/hide all of the separators between the trees on the left side
// of the gui.
void NixNote::checkLeftPanelSeparators() {
    bool s1 = false;
    bool s2 = false;
    bool s3 = false;
    bool s4 = false;
    bool s5 = false;

    bool tags;
    bool notebooks;
    bool favorites;
    bool searches;
    bool attributes;
    bool trash;

    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    favorites = global.settings->value("favoritesTreeVisible", true).toBool();
    notebooks = global.settings->value("notebookTreeVisible", true).toBool();
    tags = global.settings->value("tagTreeVisible", true).toBool();
    searches = global.settings->value("savedSearchTreeVisible", true).toBool();
    attributes = global.settings->value("attributeTreeVisible", true).toBool();
    trash = global.settings->value("trashTreeVisible", true).toBool();
    global.settings->endGroup();

    if (favorites && (notebooks || tags || searches || attributes || trash)) {
        s1 = true;
    }
    if (notebooks && (tags || searches || attributes || trash)) {
        s2 = true;
    }
    if (tags && (searches || attributes || trash)) {
        s3 = true;
    }
    if (searches && (attributes || trash)) {
        s4 = true;
    }
    if (attributes && trash) {
        s5 = true;
    }

    leftSeparator1->setVisible(s1);
    leftSeparator2->setVisible(s2);
    leftSeparator3->setVisible(s3);
    leftseparator4->setVisible(s4);
    leftSeparator5->setVisible(s5);
}

// Make sure the toolbar checkbox & the menu match.
void NixNote::toolbarVisibilityChanged() {
    menuBar->viewToolbar->blockSignals(true);
    menuBar->viewToolbar->setChecked(toolBar->isVisible());
    menuBar->viewToolbar->blockSignals(false);
}


//Turn on presentation mode
void NixNote::presentationModeOn() {
    this->leftScroll->hide();
    //    this->toggleLeftPanel();
    //    this->toggleLeftPanel();
    this->menuBar->setVisible(false);
    this->topRightWidget->setVisible(false);
    this->toolBar->setVisible(false);

    this->statusBar()->setVisible(false);
    this->showFullScreen();
    global.isFullscreen = true;
    tabWindow->currentBrowser()->buttonBar->hide();

    FaderDialog *d = new FaderDialog();
    d->setText(tr("Press ESC to exit."));
    d->show();
}

//Turn off presentation mode
void NixNote::presentationModeOff() {
    if (!this->isFullScreen())
        return;
    if (menuBar->viewLeftPanel->isChecked())
        leftScroll->show();
    if (menuBar->viewNoteList->isChecked())
        topRightWidget->show();
    if (menuBar->viewStatusbar->isChecked())
        statusBar()->show();
    menuBar->show();
    toolBar->show();
    global.isFullscreen = false;
    tabWindow->currentBrowser()->buttonBar->show();
    this->showMaximized();
}

// Export selected notes as PDF files.
void NixNote::onExportAsPdf() {
    QList<qint32> lids;
    noteTableView->getSelectedLids(lids);

    if (pdfExportWindow == nullptr) {
        pdfExportWindow = new QWebView();
        connect(pdfExportWindow, SIGNAL(loadFinished(bool)), this, SLOT(onExportAsPdfReady(bool)));
    }

    if (lids.size() <= 0) {
        QList<qint32> lids;
        noteTableView->getSelectedLids(lids);

        QString file = selectExportPDFFileName();
        if (file.isEmpty()) {
            return;
        }


        QPrinter printer;
        configurePdfPrinter(printer, file);

        // TODO use this as base for filename
        const QString noteTitle = tabWindow->currentBrowser()->noteTitle.text();
        printer.setDocName(noteTitle);
        tabWindow->currentBrowser()->editor->print(&printer);
        return;
    }

    NoteTable noteTable(global.db);
    QByteArray content;
    content.clear();
    NoteFormatter formatter;

    QProgressDialog *progress = new QProgressDialog(0);
    progress->setMinimum(0);
    progress->setWindowTitle(tr("Exporting notes as PDF"));
    progress->setLabelText(tr("Exporting notes as PDF"));
    progress->setMaximum(lids.size());
    progress->setVisible(true);
    progress->setWindowModality(Qt::ApplicationModal);
    progress->setCancelButton(0);
    progress->show();

    // TODO pass first note as default for PDF title
    for (int i = 0; i < lids.size(); i++) {
        Note n;
        noteTable.get(n, lids[i], true, false);
        formatter.setNote(n, false);
        if (n.title.isSet())
            content.append("<h2>" + n.title + "</h2>");
        content.append(formatter.rebuildNoteHTML());
        if (i < lids.size() - 1)
            content.append("<p style=\"page-break-after:always;\"></p>");
        progress->setValue(i);
    }

    progress->hide();
    delete progress;
    pdfExportWindow->setHtml(content);
}

void NixNote::configurePdfPrinter(QPrinter &printer, QString &file) const {
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setResolution(QPrinter::HighResolution);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(file);
#define TOP_MARGIN 10
#define SIDE_MARGIN 15
    printer.setPageMargins(SIDE_MARGIN, TOP_MARGIN, SIDE_MARGIN, TOP_MARGIN, QPrinter::Millimeter);
}

QString NixNote::selectExportPDFFileName() {
    QString file = QFileDialog::getSaveFileName(this, tr("PDF Export"), "", "*.pdf");

    if (!file.isEmpty()) {
        // add file suffix
        if (!file.endsWith(".pdf")) {
            file = file.append(".pdf");
        }
    }
    return file;
}


// Slot called when notes that were exported as PDF files are ready to be printed
// TODO bool param not needed
void NixNote::onExportAsPdfReady(bool) {
    QString file = selectExportPDFFileName();
    if (file.isEmpty()) {
        return;
    }

    QPrinter printer;
    configurePdfPrinter(printer, file);
    pdfExportWindow->print(&printer);
}


void NixNote::showAnnouncementMessage() {
    // this can be used to some "critical" infos to users - normaly there should be no message
    // QMessageBox::critical(
    //         this, tr("Announcement"),
    //         "msg text"
    //         "\n\n"
    //         "Sorry for additional inconvenience..");
}


void NixNote::unsortNoteTable() {
    // Sort the notetableview by a non-existing column
    int sortColumn = noteTableView->horizontalHeader()->count();
    noteTableView->sortByColumn(sortColumn);
}
