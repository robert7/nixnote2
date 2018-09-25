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

#include "nmainmenubar.h"
#include "src/global.h"
#include <QAbstractAnimation>
#include <QFileIconProvider>
#include <QDesktopServices>
#include <QShortcut>

extern Global global;

struct QPairFirstComparer {
    template<typename T1, typename T2>
    bool operator()(const QPair<T1, T2> &a, const QPair<T1, T2> &b) const {
        return a.first < b.first;
    }
};

NMainMenuBar::NMainMenuBar(QWidget *parent) :
    QMenuBar(parent) {
    this->parent = (NixNote *) parent;
    QFont f = global.getGuiFont(QFont());
    this->setFont(f);

    setupFileMenu();
    setupEditMenu();
    setupViewMenu();
    setupNoteMenu();
    setupToolsMenu();
    setupHelpMenu();
}


void NMainMenuBar::setupFileMenu() {
    QFont f = global.getGuiFont(QFont());
    this->setFont(f);

    fileMenu = this->addMenu(tr("&File"));
    fileMenu->setFont(f);


    emailAction = new QAction(tr("Email Note"), this);
    emailAction->setToolTip(tr("Email a copy of this note"));
    connect(emailAction, SIGNAL(triggered()), parent, SLOT(emailNote()));
    fileMenu->addAction(emailAction);


    printPreviewAction = new QAction(tr("Print Preview Note"), this);
    printPreviewAction->setToolTip(tr("Print preview of this note"));
    connect(printPreviewAction, SIGNAL(triggered()), parent, SLOT(printPreviewNote()));
    setupShortcut(printPreviewAction, QString("File_Print_Preview"));
    fileMenu->addAction(printPreviewAction);
    //printPreviewAction->setVisible(false);  // for some reason images don't show up in print preview, so this is useless.  Check again in Qt5

    printAction = new QAction(tr("&Print Note"), this);
    printAction->setToolTip(tr("Print this note"));
    connect(printAction, SIGNAL(triggered()), parent, SLOT(printNote()));
    setupShortcut(printAction, QString("File_Print"));
    fileMenu->addAction(printAction);
    fileMenu->addSeparator();


    backupDatabaseAction = new QAction(tr("&Backup Database"), this);
    backupDatabaseAction->setToolTip(tr("Backup database to a file"));
    connect(backupDatabaseAction, SIGNAL(triggered()), parent, SLOT(databaseBackup()));
    setupShortcut(backupDatabaseAction, QString("File_Backup_Database"));
    fileMenu->addAction(backupDatabaseAction);

    restoreDatabaseAction = new QAction(tr("&Restore Database"), this);
    restoreDatabaseAction->setToolTip(tr("Restore from a backup"));
    connect(restoreDatabaseAction, SIGNAL(triggered()), parent, SLOT(databaseRestore()));
    setupShortcut(restoreDatabaseAction, QString("File_Restore_Database"));
    fileMenu->addAction(restoreDatabaseAction);

    fileMenu->addSeparator();

    exportNoteAction = new QAction(tr("&Export to NixNote Export"), this);
    exportNoteAction->setToolTip(tr("Export selected notes to a NNEX file"));
    connect(exportNoteAction, SIGNAL(triggered()), parent, SLOT(noteExport()));
    setupShortcut(exportNoteAction, QString("File_Note_Export"));
    fileMenu->addAction(exportNoteAction);

    exportAsPdfAction = new QAction(tr("&Export notes as PDF"), this);
    exportAsPdfAction->setToolTip(tr("Export selected notes to a PDF file"));
    connect(exportAsPdfAction, SIGNAL(triggered()), parent, SLOT(onExportAsPdf()));
    setupShortcut(exportAsPdfAction, QString("File_Note_Export_Pdf"));
    fileMenu->addAction(exportAsPdfAction);

    importNoteAction = new QAction(tr("&Import notes"), this);
    importNoteAction->setToolTip(tr("Import notes from an export file"));
    connect(importNoteAction, SIGNAL(triggered()), parent, SLOT(noteImport()));
    setupShortcut(importNoteAction, QString("File_Note_Import"));
    fileMenu->addAction(importNoteAction);

    fileMenu->addSeparator();
    QList<QString> names = global.accountsManager->nameList();
    QList<int> ids = global.accountsManager->idList();
    QList<QPair<int, QString>> pairList;
    for (int i = 0; i < ids.size(); i++) {
        pairList.append(QPair<int, QString>(ids[i], names[i]));
    }
    qSort(pairList.begin(), pairList.end(), QPairFirstComparer());
    for (int i = 0; i < ids.size(); i++) {
        QAction *accountAction = new QAction(pairList[i].second + " - (" + QString::number(pairList[i].first) + ")",
                                             this);
        accountAction->setData(pairList[i].first);
        accountAction->setCheckable(true);
        if (global.accountsManager->currentId == pairList[i].first)
            accountAction->setChecked(true);
        else {
            accountAction->setText(
                tr("Switch to ") + pairList[i].second + " - (" + QString::number(pairList[i].first) + ")");
        }
        fileMenu->addAction(accountAction);
        connect(accountAction, SIGNAL(triggered()), parent, SLOT(switchUser()));
        userAccountActions.append(accountAction);
    }

    addUserAction = new QAction(tr("&Add Another User..."), this);
    fileMenu->addAction(addUserAction);
    connect(addUserAction, SIGNAL(triggered()), parent, SLOT(addAnotherUser()));

    userMaintenanceAction = new QAction(tr("&User Account Maintenance"), this);
    fileMenu->addAction(userMaintenanceAction);
    connect(userMaintenanceAction, SIGNAL(triggered()), parent, SLOT(userMaintenance()));

    fileMenu->addSeparator();

    openCloseAction = new QAction(tr("&Open/Close Notebooks"), this);
    openCloseAction->setToolTip(tr("Open/Close Notebooks"));
    connect(openCloseAction, SIGNAL(triggered()), parent, SLOT(openCloseNotebooks()));
    setupShortcut(quitAction, QString("File_Notebook_OpenClose"));
    fileMenu->addAction(openCloseAction);

    fileMenu->addSeparator();

    quitAction = new QAction(tr("Quit"), this);
    quitAction->setToolTip(tr("Quit the program"));
    connect(quitAction, SIGNAL(triggered()), parent, SLOT(quitNixNote()));

    quitAction->setShortcut(QKeySequence::Close);
    quitAction->setIcon(QIcon::fromTheme("exit"));
    setupShortcut(quitAction, QString("File_Exit"));
    fileMenu->addAction(quitAction);

    QString menuCss = global.getThemeCss("menuCss");
    if (menuCss != "")
        this->setStyleSheet(menuCss);
}


void NMainMenuBar::addUserAccount(QAction *action) {
    fileMenu->insertAction(addUserAction, action);
    userAccountActions.append(action);
}


void NMainMenuBar::setupEditMenu() {
    editMenu = this->addMenu(tr("&Edit"));
    QFont f = global.getGuiFont(QFont());
    editMenu->setFont(f);

    undoAction = new QAction(tr("&Undo"), this);
    setupShortcut(undoAction, QString("Edit_Undo"));
    editMenu->addAction(undoAction);

    redoAction = new QAction(tr("&Redo"), this);
    setupShortcut(redoAction, QString("Edit_Redo"));
    editMenu->addAction(redoAction);

    editMenu->addSeparator();

    cutAction = new QAction(tr("&Cut"), this);
    setupShortcut(cutAction, QString("Edit_Cut"));
    editMenu->addAction(cutAction);

    copyAction = new QAction(tr("C&opy"), this);
    setupShortcut(copyAction, QString("Edit_Copy"));
    editMenu->addAction(copyAction);

    pasteAction = new QAction(tr("&Paste"), this);
    setupShortcut(pasteAction, QString("Edit_Paste"));
    editMenu->addAction(pasteAction);

    pasteAsTextAction = new QAction(tr("Pas&te as Unformatted Text"), this);
    setupShortcut(pasteAsTextAction, QString("Edit_Paste_Without_Formatting"));
    editMenu->addAction(pasteAsTextAction);

    removeFormattingAction = new QAction(tr("Remo&ve Formatting"), this);
    //setupShortcut(removeFormjattingAction, QString("Edit_Remove_Formatting")); // For some reason this one makes the editorButtonBar one ambiguous
    editMenu->addAction(removeFormattingAction);

    editMenu->addSeparator();

    selectAllAction = new QAction(tr("Select &All"), this);
    setupShortcut(selectAllAction, QString("Edit_Select_All"));
    editMenu->addAction(selectAllAction);

    editMenu->addSeparator();

    findReplaceMenu = editMenu->addMenu(tr("F&ind and Replace"));
    findReplaceMenu->setFont(f);

    searchNotesAction = new QAction(tr("&Search Notes"), this);
    setupShortcut(searchNotesAction, QString("Edit_Search_Notes"));
    findReplaceMenu->addAction(searchNotesAction);
    connect(searchNotesAction, SIGNAL(triggered()), parent->searchText, SLOT(setFocus()));

    resetSearchAction = new QAction(tr("&Reset Search"), this);
    setupShortcut(resetSearchAction, QString("Edit_Reset_Search"));
    findReplaceMenu->addAction(resetSearchAction);
    connect(resetSearchAction, SIGNAL(triggered()), parent, SLOT(resetView()));

    findReplaceMenu->addSeparator();

    searchFindAction = new QAction(tr("&Find in Note"), this);
    setupShortcut(searchFindAction, QString("Edit_Search_Find"));
    findReplaceMenu->addAction(searchFindAction);
    connect(searchFindAction, SIGNAL(triggered()), parent, SLOT(findInNote()));


    searchFindNextAction = new QAction(tr("Find &Next"), this);
    setupShortcut(searchFindNextAction, QString("Edit_Search_Find_Next"));
    findReplaceMenu->addAction(searchFindNextAction);
    connect(searchFindNextAction, SIGNAL(triggered()), parent, SLOT(findNextInNote()));

    searchFindPrevAction = new QAction(tr("Find &Previous"), this);
    setupShortcut(searchFindPrevAction, QString("Edit_Search_Find_Prev"));
    findReplaceMenu->addAction(searchFindPrevAction);
    connect(searchFindPrevAction, SIGNAL(triggered()), parent, SLOT(findPrevInNote()));

    findReplaceMenu->addSeparator();

    searchFindReplaceAction = new QAction(tr("Replace &Within Note..."), this);
    setupShortcut(searchFindReplaceAction, QString("Edit_Search_Find_Replace"));
    findReplaceMenu->addAction(searchFindReplaceAction);
    connect(searchFindReplaceAction, SIGNAL(triggered()), parent, SLOT(findReplaceInNote()));

    editMenu->addSeparator();

    createThemeMenu(editMenu);

    preferencesAction = new QAction(tr("Preferences"), this);
    preferencesAction->setMenuRole(QAction::PreferencesRole);
    setupShortcut(preferencesAction, QString("Edit_Preferences"));
    editMenu->addAction(preferencesAction);
    connect(preferencesAction, SIGNAL(triggered()), parent, SLOT(openPreferences()));

}

void NMainMenuBar::setupViewMenu() {
    viewMenu = this->addMenu(tr("&View"));
    QFont f = global.getGuiFont(QFont());
    viewMenu->setFont(f);

    viewNoteListWide = new QAction(tr("Wide Note List"), this);
    setupShortcut(viewNoteListWide, "View_Note_List_Wide");
    viewMenu->addAction(viewNoteListWide);
    viewNoteListWide->setCheckable(true);

    viewNoteListNarrow = new QAction(tr("Narrow Note List"), this);
    setupShortcut(viewNoteListNarrow, "View_Note_List_Narrow");
    viewNoteListNarrow->setCheckable(true);
    viewMenu->addAction(viewNoteListNarrow);
    connect(viewNoteListNarrow, SIGNAL(triggered()), parent, SLOT(viewNoteListNarrow()));
    connect(viewNoteListWide, SIGNAL(triggered()), parent, SLOT(viewNoteListWide()));

    viewSourceAction = new QAction(tr("&Show Source"), this);
    setupShortcut(viewSourceAction, "View_Source");
    viewMenu->addAction(viewSourceAction);

    viewHistoryAction = new QAction(tr("Note &History"), this);
    setupShortcut(viewHistoryAction, "View_Note_History");
    viewMenu->addAction(viewHistoryAction);

    viewMenu->addSeparator();

    viewPresentationModeAction = new QAction(tr("&Presentation Mode"), this);
    setupShortcut(viewPresentationModeAction, "View_Presentation_Mode");
    viewMenu->addAction(viewPresentationModeAction);

    viewLeftPanel = new QAction(tr("Show &Left Panel"), this);
    setupShortcut(viewLeftPanel, "View_Show_Left_Side");
    viewLeftPanel->setCheckable(true);
    viewLeftPanel->setChecked(true);
    viewMenu->addAction(viewLeftPanel);
    connect(viewLeftPanel, SIGNAL(triggered()), parent, SLOT(toggleLeftPanel()));

    viewFavoritesTree = new QAction(tr("Show &Favorites"), this);
    setupShortcut(viewFavoritesTree, "View_Show_Favorites_List");
    viewFavoritesTree->setCheckable(true);
    viewFavoritesTree->setChecked(true);
    viewMenu->addAction(viewFavoritesTree);
    connect(viewFavoritesTree, SIGNAL(triggered()), parent, SLOT(toggleFavoritesTree()));

    viewNotebookTree = new QAction(tr("Show &Notebooks"), this);
    setupShortcut(viewNotebookTree, "View_Show_Notebook_List");
    viewNotebookTree->setCheckable(true);
    viewNotebookTree->setChecked(true);
    viewMenu->addAction(viewNotebookTree);
    connect(viewNotebookTree, SIGNAL(triggered()), parent, SLOT(toggleNotebookTree()));

    viewTagTree = new QAction(tr("Show Ta&gs"), this);
    setupShortcut(viewTagTree, "View_Show_Tag_List");
    viewTagTree->setCheckable(true);
    viewTagTree->setChecked(true);
    viewMenu->addAction(viewTagTree);
    connect(viewTagTree, SIGNAL(triggered()), parent, SLOT(toggleTagTree()));

    viewSearchTree = new QAction(tr("Show Sa&ved Searches"), this);
    setupShortcut(viewSearchTree, "View_Show_Saved_Search_List");
    viewSearchTree->setCheckable(true);
    viewSearchTree->setChecked(true);
    viewMenu->addAction(viewSearchTree);
    connect(viewSearchTree, SIGNAL(triggered()), parent, SLOT(toggleSavedSearchTree()));

    viewAttributesTree = new QAction(tr("Show &Attribute Filter"), this);
    setupShortcut(viewAttributesTree, "View_Attributes_List");
    viewAttributesTree->setCheckable(true);
    viewAttributesTree->setChecked(true);
    viewMenu->addAction(viewAttributesTree);
    connect(viewAttributesTree, SIGNAL(triggered()), parent, SLOT(toggleAttributesTree()));

    viewTrashTree = new QAction(tr("Show T&rash"), this);
    setupShortcut(viewTrashTree, "View_Trash");
    viewTrashTree->setCheckable(true);
    viewTrashTree->setChecked(true);
    viewMenu->addAction(viewTrashTree);
    connect(viewTrashTree, SIGNAL(triggered()), parent, SLOT(toggleTrashTree()));

    viewNoteList = new QAction(tr("Show N&ote List"), this);
    setupShortcut(viewNoteList, "View_Show_Note_List");
    viewNoteList->setCheckable(true);
    viewNoteList->setChecked(true);
    viewMenu->addAction(viewNoteList);
    connect(viewNoteList, SIGNAL(triggered()), parent, SLOT(toggleNoteList()));

    viewNotePanel = new QAction(tr("Show Note &Panel"), this);
    setupShortcut(viewNotePanel, "View_Show_Note_Panel");
    viewNotePanel->setCheckable(true);
    viewNotePanel->setChecked(true);
    viewMenu->addAction(viewNotePanel);
    connect(viewNotePanel, SIGNAL(triggered()), parent, SLOT(toggleTabWindow()));

    viewMenu->addSeparator();

    viewExtendedInformation = new QAction(tr("View Note &Info"), this);
    setupShortcut(viewExtendedInformation, "View_Extended_Information");
    viewMenu->addAction(viewExtendedInformation);

    viewToolbar = new QAction(tr("View &Toolbar"), this);
    setupShortcut(viewToolbar, "View_Toolbar");
    viewMenu->addAction(viewToolbar);
    viewToolbar->setCheckable(true);
    viewToolbar->setChecked(true);
    connect(viewToolbar, SIGNAL(triggered()), parent, SLOT(toggleToolbar()));

    viewStatusbar = new QAction(tr("View Status&bar"), this);
    setupShortcut(viewStatusbar, "View_Statusbar");
    viewMenu->addAction(viewStatusbar);
    viewStatusbar->setCheckable(true);
    connect(viewStatusbar, SIGNAL(triggered()), parent, SLOT(toggleStatusbar()));

    createSortMenu(viewMenu);
}


void NMainMenuBar::setupNoteMenu() {

    noteMenu = this->addMenu(tr("&Note"));
    QFont f = global.getGuiFont(QFont());
    noteMenu->setFont(f);

    newNoteAction = new QAction(tr("New &Note"), noteMenu);
    setupShortcut(newNoteAction, QString("File_Note_Add"));
    noteMenu->addAction(newNoteAction);
    connect(newNoteAction, SIGNAL(triggered()), parent, SLOT(newNote()));

    duplicateNoteAction = new QAction(tr("Dupl&icate Note"), noteMenu);
    setupShortcut(duplicateNoteAction, QString("File_Note_Duplicate"));
    noteMenu->addAction(duplicateNoteAction);
    connect(duplicateNoteAction, SIGNAL(triggered()), parent, SLOT(duplicateCurrentNote()));

    deleteNoteAction = new QAction(tr("&Delete"), noteMenu);
    setupShortcut(deleteNoteAction, QString("File_Note_Delete"));
    noteMenu->addAction(deleteNoteAction);
    connect(deleteNoteAction, SIGNAL(triggered()), parent, SLOT(deleteCurrentNote()));

    reindexNoteAction = new QAction(tr("Reindex Note"), noteMenu);
    setupShortcut(reindexNoteAction, QString("File_Note_Reindex"));
    noteMenu->addAction(reindexNoteAction);
    connect(reindexNoteAction, SIGNAL(triggered()), parent, SLOT(reindexCurrentNote()));

    if (parent->hunspellPluginAvailable) {
        noteMenu->addSeparator();
        spellCheckAction = new QAction(tr("&Spell Check"), noteMenu);
        // setupShortcut(spellCheckAction, QString("Tools_Spell_Check"));  This shortcut is done by the editor button bar
        noteMenu->addAction(spellCheckAction);
        connect(spellCheckAction, SIGNAL(triggered()), parent, SLOT(spellCheckCurrentNote()));
    }


    noteMenu->addSeparator();

    pinNoteAction = new QAction(tr("&Pin Note"), noteMenu);
    setupShortcut(pinNoteAction, QString("NOTE_PIN"));
    noteMenu->addAction(pinNoteAction);
    connect(pinNoteAction, SIGNAL(triggered()), parent, SLOT(pinCurrentNote()));

    unpinNoteAction = new QAction(tr("&UnPin Note"), noteMenu);
    setupShortcut(unpinNoteAction, QString("NOTE_UNPIN"));
    noteMenu->addAction(unpinNoteAction);
    connect(unpinNoteAction, SIGNAL(triggered()), parent, SLOT(unpinCurrentNote()));

}


void NMainMenuBar::setupToolsMenu() {
    toolsMenu = this->addMenu(tr("&Tools"));
    QFont f = global.getGuiFont(QFont());
    toolsMenu->setFont(f);

    synchronizeAction = new QAction(tr("&Synchronize"), this);
    synchronizeAction->setToolTip(tr("Synchronize with Evernote"));
    connect(synchronizeAction, SIGNAL(triggered()), parent, SLOT(synchronize()));
    toolsMenu->addAction(synchronizeAction);

    disconnectAction = new QAction(tr("&Disconnect"), this);
    disconnectAction->setToolTip(tr("Disconnect from Evernote"));
    connect(disconnectAction, SIGNAL(triggered()), parent, SLOT(disconnect()));
    setupShortcut(disconnectAction, QString(""));
    toolsMenu->addAction(disconnectAction);
    disconnectAction->setEnabled(false);
    disconnectAction->setVisible(false);  /// We can probably delete this whole menu option

    pauseIndexingAction = new QAction(tr("Pause &indexing"), this);
    pauseIndexingAction->setToolTip(tr("Temporarily pause indexing"));
    setupShortcut(pauseIndexingAction, QString("Tools_Pause_Indexing"));
    connect(pauseIndexingAction, SIGNAL(triggered()), parent, SLOT(pauseIndexing()));
    pauseIndexingAction->setCheckable(true);
    toolsMenu->addAction(pauseIndexingAction);
    pauseIndexingAction->setVisible(global.enableIndexing);

    disableEditingAction = new QAction(tr("Disable &editing"), this);
    disableEditingAction->setToolTip(tr("Temporarily disable note editing"));
    setupShortcut(disableEditingAction, QString("Tools_Disable_Editing"));
    disableEditingAction->setCheckable(true);
    disableEditingAction->setChecked(global.disableEditing);
    connect(disableEditingAction, SIGNAL(triggered()), parent, SLOT(disableEditing()));
    toolsMenu->addAction(disableEditingAction);

    toolsMenu->addSeparator();

    reindexDatabaseAction = new QAction(tr("&Reindex database"), this);
    reindexDatabaseAction->setToolTip(tr("Reindex all notes"));
    setupShortcut(reindexDatabaseAction, QString("Tools_Database_Reindex"));
    connect(reindexDatabaseAction, SIGNAL(triggered()), parent, SLOT(reindexDatabase()));
    toolsMenu->addAction(reindexDatabaseAction);
    reindexDatabaseAction->setVisible(global.enableIndexing);

    databaseStatusDialogAction = new QAction(tr("&Database status"), this);
    databaseStatusDialogAction->setToolTip(tr("Database Status"));
    setupShortcut(databaseStatusDialogAction, QString("Tools_Database_Status"));
    connect(databaseStatusDialogAction, SIGNAL(triggered()), parent, SLOT(openDatabaseStatus()));
    toolsMenu->addAction(databaseStatusDialogAction);

    toolsMenu->addSeparator();

    accountDialogAction = new QAction(tr("A&ccount / usage"), this);
    accountDialogAction->setToolTip(tr("Account and usage information"));
    connect(accountDialogAction, SIGNAL(triggered()), parent, SLOT(openAccount()));
    setupShortcut(accountDialogAction, QString("Tools_Account_Information"));
    toolsMenu->addAction(accountDialogAction);

    toolsMenu->addSeparator();

    importFoldersDialogAction = new QAction(tr("&Import folders"), this);
    importFoldersDialogAction->setToolTip(tr("Import Folders"));
    setupShortcut(importFoldersDialogAction, QString("Tools_Import_Folders"));
    connect(importFoldersDialogAction, SIGNAL(triggered()), parent, SLOT(openImportFolders()));
    toolsMenu->addAction(importFoldersDialogAction);
}

void NMainMenuBar::setupHelpMenu() {
    helpMenu = this->addMenu(tr("&Help"));
    QFont f = global.getGuiFont(QFont());
    helpMenu->setFont(f);

    openProjectWebPageAction = new QAction(tr("&Project wiki"), this);
    openProjectWebPageAction->setToolTip(tr("Open NixNote wiki page with help/documentation/contact"));
    connect(openProjectWebPageAction, SIGNAL(triggered()), this, SLOT(onOpenProjectWebPage()));
    helpMenu->addAction(openProjectWebPageAction);

    QAction *openGettingStartedWebPageAction = new QAction(tr("&Getting started"), this);
    openGettingStartedWebPageAction->setToolTip(tr("Open Getting started wiki page"));
    connect(openGettingStartedWebPageAction, SIGNAL(triggered()), this, SLOT(onOpenGettingStartedWebPage()));
    helpMenu->addAction(openGettingStartedWebPageAction);

    helpMenu->addSeparator();

    themeInformationAction = new QAction(tr("Theme &Information"), this);
    // themeInformationAction->setToolTip(tr("View information about the current theme."));
    // connect(themeInformationAction, SIGNAL(triggered()), this, SLOT(openThemeInformation()));
    // helpMenu->addAction(themeInformationAction);
    // QString url = global.getResourceFileName(global.resourceList, ":themeInformation");
    // themeInformationAction->setVisible(false);
    // if (url.startsWith("http://", Qt::CaseInsensitive) || url.startsWith("https://", Qt::CaseInsensitive))
    //     themeInformationAction->setVisible(true);
    // QFile file(url);
    // if (file.exists())
    //     themeInformationAction->setVisible(true);
    // global.settings->beginGroup(INI_GROUP_APPEARANCE);
    // QString themeName = global.settings->value("themeName", "").toString();
    // global.settings->endGroup();
    // if (themeName == "")

    // temporarily off - as the themes are currently un-ripe/unfinished
    themeInformationAction->setVisible(false);

    openMessageLogAction = new QAction(tr("Data and &log location info"), this);
    openMessageLogAction->setToolTip(tr("View location of program data and log file"));
    connect(openMessageLogAction, SIGNAL(triggered()), parent, SLOT(openMessageLogInfo()));
    helpMenu->addAction(openMessageLogAction);

    openShortcutsDialogAction = new QAction(tr("Active shortcuts"), this);
    openShortcutsDialogAction->setToolTip(tr("View current shortcuts"));
    connect(openShortcutsDialogAction, SIGNAL(triggered(bool)), parent, SLOT(openShortcutsDialog()));
    helpMenu->addAction(openShortcutsDialogAction);

    helpMenu->addSeparator();

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setMenuRole(QAction::AboutQtRole);
    aboutQtAction->setToolTip(tr("About Qt"));
    connect(aboutQtAction, SIGNAL(triggered()), parent, SLOT(openQtAbout()));
    helpMenu->addAction(aboutQtAction);

    helpMenu->addSeparator();

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setToolTip(tr("About"));
    aboutAction->setMenuRole(QAction::AboutRole);
    connect(aboutAction, SIGNAL(triggered()), parent, SLOT(openAbout()));
    helpMenu->addAction(aboutAction);
}

void NMainMenuBar::setupShortcut(QAction *action, QString text) {
    if (!global.shortcutKeys->containsAction(&text))
        return;
    QKeySequence key(global.shortcutKeys->getShortcut(&text));
    action->setShortcut(key);
}

void NMainMenuBar::onOpenProjectWebPage() {
    QDesktopServices::openUrl(QUrl(NN_GITHUB_WIKI_URL));
}

void NMainMenuBar::onOpenGettingStartedWebPage() {
    QDesktopServices::openUrl(QUrl(NN_GITHUB_WIKI_URL "/Getting-started"));
}

void NMainMenuBar::createSortMenu(QMenu *parentMenu) {
    sortMenu = parentMenu->addMenu(tr("Sort notes by"));

    QFont f = global.getGuiFont(QFont());
    QActionGroup *menuActionGroup = new QActionGroup(this);
    menuActionGroup->setExclusive(true);

    addSortAction(sortMenu, menuActionGroup, f, tr("Relevance, Date updated [desc]"), INI_VALUE_SORTORDER_DEFAULT);
    addSortAction(sortMenu, menuActionGroup, f, tr("Relevance, Date updated [asc]"), "relevance desc, dateUpdated asc");

    addSortAction(sortMenu, menuActionGroup, f, tr("Relevance, Date created [desc]"), "relevance desc, dateCreated desc");
    addSortAction(sortMenu, menuActionGroup, f, tr("Relevance, Date created [asc]"), "relevance desc, dateCreated asc");

    addSortAction(sortMenu, menuActionGroup, f, tr("Relevance, Title [desc]"), "relevance desc, title desc");
    addSortAction(sortMenu, menuActionGroup, f, tr("Relevance, Title [asc]"), "relevance desc, title asc");
    sortMenu->addSeparator();

    addSortAction(sortMenu, menuActionGroup, f, tr("Date updated [desc]"), "dateUpdated desc");
    addSortAction(sortMenu, menuActionGroup, f, tr("Date updated [asc]"), "dateUpdated asc");

    addSortAction(sortMenu, menuActionGroup, f, tr("Date created [desc]"), "dateCreated desc");
    addSortAction(sortMenu, menuActionGroup, f, tr("Date created [asc]"), "dateCreated asc");

    addSortAction(sortMenu, menuActionGroup, f, tr("Title [desc]"), "title desc");
    addSortAction(sortMenu, menuActionGroup, f, tr("Title [asc]"), "title asc");

    addSortAction(sortMenu, menuActionGroup, f, tr("Size [desc]"), "size desc, dateUpdated desc");
    addSortAction(sortMenu, menuActionGroup, f, tr("Has todo [desc]"), "hasTodo desc, dateUpdated desc");
    addSortAction(sortMenu, menuActionGroup, f, tr("Unsynced first"), "isDirty desc, dateUpdated desc");

    sortMenu->setFont(f);
}

void NMainMenuBar::addSortAction(QMenu *menu, QActionGroup *menuActionGroup, const QFont &f, QString name,
                                 QString code) {
    QString currentSortOrder = global.getSortOrder();

    QAction *action = new QAction(name, this);
    action->setData(code);
    action->setCheckable(true);
    if (QString::compare(code, currentSortOrder) == 0) {
        action->setChecked(true);
    }

    action->setFont(f);
    menuActionGroup->addAction(action);
    connect(action, SIGNAL(triggered()), this, SLOT(onSortMenuTriggered()));
    menu->addAction(action);
}

void NMainMenuBar::onSortMenuTriggered() {
    QAction *pAction = qobject_cast<QAction *>(sender());
    if (!pAction) {
        return;
    }
    QString data = pAction->data().toString();
    QLOG_DEBUG() << "sort action data= " << data;
    global.setSortOrder(data);

    // refresh result set
    parent->updateSelectionCriteria(false);
}


void NMainMenuBar::createThemeMenu(QMenu *parentMenu) {
    QMenu *menu = parentMenu->addMenu(tr("Theme"));
    QStringList list = global.getThemeNames();
    QFont f = global.getGuiFont(QFont());

    global.settings->beginGroup(INI_GROUP_APPEARANCE);
    QString userTheme = global.settings->value("themeName", DEFAULT_THEME_NAME).toString();
    global.settings->endGroup();


    // Setup themes (we expect to find the DEFAULT_THEME_NAME theme as first one)
    for (int i = 0; i < list.size(); i++) {
        QString themeName(list[i]);
        if ((i == 0) && (QString::compare(themeName, DEFAULT_THEME_NAME, Qt::CaseInsensitive) != 0)) {
            QLOG_ERROR() << "First theme is expected to be " << DEFAULT_THEME_NAME;
        }


        QAction *themeAction = new QAction(themeName, this);
        themeAction->setData(themeName);
        themeAction->setCheckable(true);
        themeAction->setFont(f);
        connect(themeAction, SIGNAL(triggered()), parent, SLOT(reloadIcons()));
        if (themeName == userTheme) {
            themeAction->setChecked(true);
        }
        themeActions.append(themeAction);
    }
    menu->addActions(themeActions);
    menu->setFont(f);
}


void NMainMenuBar::openThemeInformation() {
    global.settings->beginGroup(INI_GROUP_APPEARANCE);
    QString themeName = global.settings->value("themeName", "").toString();
    global.settings->endGroup();
    if (themeName == "") {
        QDesktopServices::openUrl(QUrl(global.fileManager.getImageDirPath("") + "themeInfo.html"));
        return;
    }
    QString url = global.getResourceFileName(global.resourceList, ":themeInformation");
    QDesktopServices::openUrl(QUrl(url));
}
