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

#ifndef NIXNOTE_H
#define NIXNOTE_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSplitter>
#include <QScrollArea>
#include <QSystemTrayIcon>
#include <QToolBar>
#include <QSlider>
#include <QSplashScreen>

#include "src/filters/remotequery.h"
#include "src/watcher/filewatchermanager.h"
#include "src/gui/ntabwidget.h"
#include "src/gui/lineedit.h"
#include "src/sql/databaseconnection.h"
#include "src/gui/ntableview.h"
#include "src/gui/ntagview.h"
#include "src/gui/nsearchview.h"
#include "src/threads/syncrunner.h"
#include "src/threads/indexrunner.h"
#include "src/gui/widgetpanel.h"
#include "src/gui/nnotebookview.h"
#include "src/gui/favoritesview.h"
#include "src/gui/nmainmenubar.h"
#include "src/gui/traymenu.h"
#include "src/gui/nattributetree.h"
#include "src/gui/ntrashtree.h"
#include "src/dialog/accountdialog.h"
#include "src/threads/counterrunner.h"
//#include "src/oauth/oauthwindow.h"
#include "src/html/thumbnailer.h"
#include "src/reminders/remindermanager.h"
#include "src/plugins/hunspell/hunspellinterface.h"

//****************************************
//* This is the main NixNote class that
//* starts everything else.  It is called
//* by main()
//****************************************


// Forward declare classes used later
class DatabaseConnection;
class NMainMenuBar;
class NixNote;
class SyncRunner;
class IndexRunner;
class CounterRunner;
class NTabWidget;
class Thumbnailer;
class NTableView;
class SyncRunner;


// Define the actual class
class NixNote : public QMainWindow
{
    Q_OBJECT

private:
    static NixNote *singleton;  // static pointer to singleton instance of this class
    QTranslator *nixnoteTranslator;
    QWebView *pdfExportWindow;
    DatabaseConnection *db;  // The database connection
    NTableView *noteTableView;
    NSearchView *searchTreeView;
    NNotebookView *notebookTreeView;
    FavoritesView *favoritesTreeView;
    QLabel *leftSeparator1;
    QLabel *leftSeparator2;
    QLabel *leftSeparator3;
    QLabel *leftseparator4;
    QLabel *leftSeparator5;
    NTrashTree *trashTree;
    NTagView *tagTreeView;
    QSplitter *mainSplitter;
    QSplitter *leftPanelSplitter;
    WidgetPanel *leftPanel;
    QSplitter *rightPanelSplitter;
    QScrollArea *leftScroll;
    QWidget *topRightWidget;
    QVBoxLayout *topRightLayout;
    NAttributeTree *attributeTree;
    bool finalSync;
    QSystemTrayIcon *trayIcon;
    QString saveLastPath;   // Last path viewed in the restore dialog
    FileWatcherManager *importManager;
    Thumbnailer *hammer;
    QTimer indexTimer;

    // Tool & menu bar
    NMainMenuBar *menuBar;
    //TrayMenu   *trayIconContextMenu;
    QToolBar *toolBar;
    QAction *leftArrowButton;
    QAction *rightArrowButton;
    QAction *homeButton;
    QAction *syncButton;
    QAction *printNoteButton;
    QAction *deleteNoteButton;
    QAction *newNoteButton;
    //~temp removed//QAction *newExternalNoteButton;
    QAction *emailButton;
    QAction *toolsAccountAction;

    QAction *showAction;
    //QAction *minimizeToTrayAction;
    //QAction *closeToTrayAction;
    QAction *quitAction;
    bool minimizeToTray;
    bool closeToTray;
    bool unhidingWindow;

    // Sync Button rotate
    QTimer syncButtonTimer;
    QTimer syncTimer;
    QList<QPixmap> syncIcons;
    unsigned int synchronizeIconAngle;

    // Timer to check shared memory for other instance commands
    QTimer heartbeatTimer;
    QNetworkAccessManager *networkManager;
    QSplashScreen *splashScreen;
    QString clientId;

    QShortcut *focusSearchShortcut;
    QShortcut *fileSaveShortcut;
    QShortcut *focusNotebookShortcut;
    QShortcut *focusFontShortcut;
    QShortcut *focusFontSizeShortcut;
    QShortcut *focusTitleShortcut;
    QShortcut *focusTagShortcut;
    QShortcut *focusNoteShortcut;
    QShortcut *focusUrlShortcut;
    QShortcut *focusAuthorShortcut;
    QShortcut *copyNoteUrlShortcut;
    QShortcut *nextTabShortcut;
    QShortcut *prevTabShortcut;
    QShortcut *closeTabShortcut;
    QShortcut *downNoteShortcut;
    QShortcut *upNoteShortcut;
    QShortcut *homeButtonShortcut;
    QShortcut *syncButtonShortcut;
    QShortcut *leftArrowButtonShortcut;
    QShortcut *rightArrowButtonShortcut;

private:
    void loadPlugins();
    void setupGui();
    void setupNoteList();
    void setupSearchTree();
    void setupTagTree();
    void setupAttributeTree();
    void setupFavoritesTree();
    void setupTrashTree();
    void setupSynchronizedNotebookTree();
    void setupTabWindow();
    void waitCursor(bool value);
    void saveContents();
    void saveNoteColumnPositions();
    void saveNoteColumnWidths();
    void checkLeftPanelSeparators();
    QString selectExportPDFFileName();
    void trayActivatedAction(int value);
    TrayMenu *createTrayContexMenu();
    void restoreAndShowMainWindow();

public:
    NixNote(QWidget *parent = 0);  // Constructor
    ~NixNote();   //Destructor
    static NixNote *get();      // Public Singleton getter
    SyncRunner syncRunner;
    QThread syncThread;
    QThread indexThread;
    QThread counterThread;
    IndexRunner indexRunner;
    CounterRunner counterRunner;
    void closeEvent(QCloseEvent *event);
    //bool notify(QObject* receiver, QEvent* event);
    bool event(QEvent *event);
    LineEdit *searchText;
    NTabWidget *tabWindow;
    bool hunspellPluginAvailable;
    void showAnnouncementMessage();

private slots:
    void onNetworkManagerFinished(QNetworkReply *reply);
    void onExportAsPdfReady(bool);

public slots:
    void quitNixNote();
    void closeShortcut();
    void synchronize();
    void syncTimerExpired();
    void disconnect();
    void updateSyncButton();
    void syncButtonReset();
    void updateSelectionCriteria(bool afterSync=false);
    void leftButtonTriggered();
    void rightButtonTriggered();
    void openNote(bool newWindow);
    void noteImport();
    void noteExport();
    void databaseRestore(bool fullRestore=true);
    void databaseBackup(bool backup=true);
    void resetView();
    void newNote();
    void newExternalNote();
    void disableEditing();
    void setSyncTimer();
    void notesDeleted(QList<qint32> lid);
    void reindexCurrentNote();
    void openAccount();
    void openDatabaseStatus();
    void openAbout();
    void openShortcutsDialog();
    void openImportFolders();
    void openQtAbout();
    void setMessage(QString msg, int timeout=15000);
    void toggleLeftPanel();
    void toggleFavoritesTree();
    void toggleNotebookTree();
    void toggleTagTree();
    void toggleSavedSearchTree();
    void toggleAttributesTree();
    void toggleTrashTree();
    void toggleNoteList();
    void toggleTabWindow();
    void toggleToolbar();
    void toggleStatusbar();
    void findReplaceInNote();
    void findReplaceAllInNotePressed();
    void findReplaceInNotePressed();
    void findInNote();
    void findNextInNote();
    void findPrevInNote();
    void viewNoteHistory();
    void findReplaceWindowHidden();
    void checkReadOnlyNotebook();
    void heartbeatTimerTriggered();
    void notesRestored(QList<qint32>);
    void emailNote();
    void printNote();
    void printPreviewNote();
    void fastPrintNote();
    void showMainWindow();
    void openPreferences();
    void notifySyncComplete();
    void addAnotherUser();
    void switchUser();
    void userMaintenance();
    void viewNoteListWide();
    void viewNoteListNarrow();
    void resourceExternallyUpdated(QString resource);
    void reindexDatabase();
    void noteSynchronized(qint32 lid, bool value);
    void indexThreadStarted();
    void syncThreadStarted();
    void counterThreadStarted();
    void openCloseNotebooks();
    void deleteCurrentNote();
    void duplicateCurrentNote();
    void pinCurrentNote();
    void unpinCurrentNote();
    void spellCheckCurrentNote();
    void openExternalNote(qint32 lid);
    void pauseIndexing(bool value=true);
    void openEvernoteSupport();
    void openMessageLogInfo();
    void showDesktopUrl(const QUrl &url);
    void reloadIcons();
    void showMessage(QString title, QString msg, int timeout=10000);
    void toolbarVisibilityChanged();
    void presentationModeOn();
    void presentationModeOff();
    void indexFinished(bool finished);
    void onExportAsPdf();
    void saveOnExit();
    void onTrayActivated(QSystemTrayIcon::ActivationReason reason);

signals:
    void syncRequested();
    void updateCounts();

};

#endif // NIXNOTE_H
