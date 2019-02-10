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

#include "src/global.h"

#include <string>
#include <limits.h>
#include <unistd.h>
#include <QWebSettings>
#include <QDesktopWidget>
#include <QApplication>

// The following include is needed for demangling names on a backtrace
// Windows Check
#ifndef _WIN32

#include <cxxabi.h>
#include <execinfo.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>

#endif  // End Windows Check

#include "src/sql/usertable.h"

//******************************************
//* Global settings used by the program
//******************************************
Global::Global() {

    dbLock = new QReadWriteLock(QReadWriteLock::Recursive);
    listView = ListViewWide;
    FilterCriteria *criteria = new FilterCriteria();
    filterCriteria.push_back(criteria);
    filterPosition = 0;

    this->argv = nullptr;
    this->argc = 0;
    criteria->resetNotebook = true;
    criteria->resetTags = true;
    criteria->resetSavedSearch = true;
    criteria->resetAttribute = true;
    criteria->resetFavorite = true;
    criteria->resetDeletedOnly = true;
    criteria->setDeletedOnly(false);
    criteria->resetLid = true;
    this->accountsManager = nullptr;
    criteria->resetSearchString = true;
    this->application = nullptr;
    this->showGoodSyncMessagesInTray = false;
    this->batchThumbnailCount = 4;
    username = "";
    this->defaultFontSize = 8;
    this->countBehavior = Global::CountAll;
    password = "";
    javaFound = false;
    reminderManager = nullptr;
    settings = nullptr;
    startupNewNote = false;
    this->sharedMemory = nullptr;
    this->forceSystemTrayAvailable = false;
    this->guiAvailable = true;
    forceUTF8 = false;
    startupNote = 0;
    db = nullptr;
    this->forceWebFonts = false;
    this->indexPDFLocally = true;
    this->indexRunner = nullptr;
    this->isFullscreen = false;
    this->indexNoteCountPause = -1;
    this->maxIndexInterval = 500;
    this->forceNoStartMimized = false;

    this->forceSearchLowerCase = false;
    this->forceSearchWithoutDiacritics = false;

    this->forceStartMinimized = false;
    this->globalSettings = nullptr;
    this->disableUploads = false;
    this->enableIndexing = false;
    this->disableThumbnails = false;
    this->defaultGuiFont = "";
    this->defaultGuiFontSize = 8;
    this->minIndexInterval = 500;
    this->minimumThumbnailInterval = 500;
    this->purgeTemporaryFilesOnShutdown = true;
    this->indexResourceCountPause = 500;
    this->maximumThumbnailInterval = 500;
    this->disableEditing = false;
    this->nonAsciiSortBug = false;
    this->startMinimized = false;
    this->pdfPreview = true;
    this->shortcutKeys = nullptr;
    this->cryptCounter = 0;
    this->connected = false;
}


// Initial global settings setup
void Global::setup(StartupConfig startupConfig, bool guiAvailable) {
    QLOG_ASSERT(globalSettings != nullptr);
    QLOG_ASSERT(!fileManager.getProgramDataDir().isEmpty());


    this->guiAvailable = guiAvailable;

    shortcutKeys = new ShortcutKeys();

    this->forceNoStartMimized = startupConfig.forceNoStartMinimized;
    this->forceSystemTrayAvailable = startupConfig.forceSystemTrayAvailable;
    this->startupNewNote = startupConfig.startupNewNote;
    //this->syncAndExit = startupConfig.syncAndExit;
    this->forceStartMinimized = startupConfig.forceStartMinimized;
    this->startupNote = startupConfig.startupNoteLid;
    accountsManager = new AccountsManager(getAccountId());
    if (startupConfig.enableIndexing || getBackgroundIndexing())
        enableIndexing = true;

    this->purgeTemporaryFilesOnShutdown = true;

    cryptCounter = 0;
    attachmentNameDelimeter = "------";
    username = "";
    password = "";
    connected = false;

    server = accountsManager->getServer();

    settings->beginGroup(INI_GROUP_DEBUGGING);
    disableUploads = settings->value("disableUploads", false).toBool();
    nonAsciiSortBug = settings->value("nonAsciiSortBug", false).toBool();
    settings->endGroup();

    setupDateTimeFormat();

    settings->beginGroup(INI_GROUP_APPEARANCE);
    int countbehavior = settings->value("countBehavior", CountAll).toInt();
    if (countbehavior == 1)
        countBehavior = CountAll;
    if (countbehavior == 2)
        countBehavior = CountNone;
    pdfPreview = settings->value("showPDFs", false).toBool();
    defaultFont = settings->value("defaultFont", "").toString();
    defaultFontSize = settings->value("defaultFontSize", 0).toInt();
    defaultGuiFontSize = settings->value("defaultGuiFontSize", 0).toInt();
    defaultGuiFont = settings->value("defaultGuiFont", "").toString();
    forceWebFonts = settings->value("forceWebFonts", false).toBool();
    disableEditing = false;
    if (settings->value("disableEditingOnStartup", false).toBool() || startupConfig.disableEditing)
        disableEditing = true;
    settings->endGroup();

    if (defaultFont != "" && defaultFontSize > 0 && this->guiAvailable) {
        QWebSettings *settings = QWebSettings::globalSettings();
        settings->setFontFamily(QWebSettings::StandardFont, defaultFont);
        // QWebkit DPI is hard coded to 96. Hence, we calculate the correct
        // font size based on desktop logical DPI.
        settings->setFontSize(QWebSettings::DefaultFontSize,
                              defaultFontSize * (QApplication::desktop()->logicalDpiX() / 96.0)
        );
    }
    if (defaultFont != "" && defaultFontSize <= 0 && this->guiAvailable) {
        QWebSettings *settings = QWebSettings::globalSettings();
        settings->setFontFamily(QWebSettings::StandardFont, defaultFont);
    }

    settings->beginGroup(INI_GROUP_APPEARANCE);
    QString theme = settings->value("themeName", "").toString();
    loadTheme(resourceList, colorList, theme);
    settings->endGroup();

    minIndexInterval = 5000;
    maxIndexInterval = 120000;
    indexResourceCountPause = 2;
    indexNoteCountPause = 100;
    isFullscreen = false;
    indexPDFLocally = getIndexPDFLocally();
    
    forceSearchLowerCase = readSettingForceSearchLowerCase();
    forceSearchWithoutDiacritics = readSettingForceSearchWithoutDiacritics();
    
    forceUTF8 = getForceUTF8();


    settings->beginGroup(INI_GROUP_THUMBNAIL);
    minimumThumbnailInterval = settings->value("minTime", 5).toInt();
    maximumThumbnailInterval = settings->value("maxTime", 60).toInt();
    batchThumbnailCount = settings->value("count", 1).toInt();
    disableThumbnails = settings->value("disabled", false).toBool();
    settings->endGroup();

    // reset username
    full_username = "";

    // Set auto-save interval
    autoSaveInterval = getAutoSaveInterval() * 1000;

    multiThreadSaveEnabled = this->getMultiThreadSave();
    exitManager = new ExitManager();
    exitManager->loadExits();
}

void Global::initializeSharedMemoryMapper(int accountId) {
    QLOG_ASSERT(globalSettings != nullptr);
    QString key = getOrCreateMemoryKey();

    key = key + QString::number(accountId);
    QLOG_ASSERT(sharedMemory == nullptr);

    sharedMemory = new CrossMemoryMapper(key);
}

QString Global::getOrCreateMemoryKey() const {
    globalSettings->beginGroup("MemoryKey");
    QString key = globalSettings->value("key", "").toString();
    if (key == "") {
        key = QUuid::createUuid().toString().replace("}", "").replace("{", "");
        globalSettings->setValue("key", key);
    }
    globalSettings->endGroup();
    return key;
}

/**
 * Configure global settings.
 */
void Global::initializeGlobalSettings() {
    QLOG_ASSERT(globalSettings == nullptr);
    QLOG_ASSERT(!fileManager.getProgramDataDir().isEmpty());
    const QString &configDir = fileManager.getConfigDir();
    QLOG_ASSERT(!configDir.isEmpty());

    QString settingsFile = configDir + NN_CONFIG_FILE_PREFIX + ".conf";
    QLOG_DEBUG() << "Configuring global config file " << settingsFile;
    globalSettings = new QSettings(settingsFile, QSettings::IniFormat);
}

/**
 * Configure user settings (accountId may come from command line
 * or its taken from global config.
 */
void Global::initializeUserSettings(int accountId) {
    QLOG_ASSERT(settings == nullptr);

    if (accountId <= 0) {
        globalSettings->beginGroup(INI_GROUP_SAVE_STATE);
        accountId = globalSettings->value("lastAccessedAccount", 1).toInt();
        QLOG_DEBUG() << "Last accessed accountId is " << accountId;
        globalSettings->endGroup();
    }
    QLOG_ASSERT(accountId > 0);
    setAccountId(accountId);
    const QString &configDir = fileManager.getConfigDir();

    QString settingsFile = configDir + NN_CONFIG_FILE_PREFIX + "-" + QString::number(accountId) + ".conf";
    QLOG_DEBUG() << "Configuring user config file " << settingsFile;
    settings = new QSettings(settingsFile, QSettings::IniFormat);
}

void Global::setDeleteConfirmation(bool value) {
    settings->beginGroup(INI_GROUP_APPEARANCE);
    settings->setValue("confirmDeletes", value);
    settings->endGroup();
}


// Should we confirm all deletes?
bool Global::confirmDeletes() {
    settings->beginGroup(INI_GROUP_APPEARANCE);
    bool confirmDeletes = settings->value("confirmDeletes", true).toBool();
    settings->endGroup();
    return confirmDeletes;
}


// Should we display tag counts?  This is really just a stub for future changes
QString Global::tagBehavior() {
    return "Count";
}


/**
 * Append the filter criteria to the filterCriteria queue and adjust filter position.
 */
void Global::appendFilter(FilterCriteria *criteria) {
    // First, find out if we're already viewing history.  If we are, we
    // chop off the end of the history & start a new one
    QLOG_ASSERT(filterPosition >= 0);

    while (filterPosition < filterCriteria.size() - 1) {
        // takeAt() - removes the item at index position i and returns it. i must be a valid index position
        // in the list (i.e., 0 <= i < size()).
        delete filterCriteria.takeAt(filterCriteria.size() - 1);
    }

    filterCriteria.append(criteria);
    filterPosition = filterCriteria.size() - 1;
}


// Should we show the tray icon?
bool Global::readSettingShowTrayIcon() {
    bool showTrayIcon;
    settings->beginGroup(INI_GROUP_APPEARANCE);
    showTrayIcon = settings->value("showTrayIcon", true).toBool();
    settings->endGroup();
    return showTrayIcon;
}


// Should we minimize to the tray
bool Global::readSettingMinimizeToTray() {
    bool minimizeToTray;
    settings->beginGroup(INI_GROUP_APPEARANCE);
    minimizeToTray = settings->value("minimizeToTray", true).toBool();
    settings->endGroup();
    return minimizeToTray;
}


// Should we close to the tray?
bool Global::readSettingCloseToTray() {
    bool showTrayIcon;
    settings->beginGroup(INI_GROUP_APPEARANCE);
    showTrayIcon = settings->value("closeToTray", true).toBool();
    settings->endGroup();
    return showTrayIcon;
}

QString Global::readSettingSortOrder() {
    QString value;
    settings->beginGroup(INI_GROUP_APPEARANCE);
    value = settings->value(INI_VALUE_SORTORDER, INI_VALUE_SORTORDER_DEFAULT).toString();
    settings->endGroup();
    return value;
}

// Save the user request to minimize to the tray
void Global::saveSettingMinimizeToTray(bool value) {
    settings->beginGroup(INI_GROUP_SAVE_STATE);
    settings->setValue("minimizeToTray", value);
    settings->endGroup();
}

void Global::saveSettingSortOrder(QString value) {
    settings->beginGroup(INI_GROUP_APPEARANCE);
    settings->setValue(INI_VALUE_SORTORDER, value);
    settings->endGroup();
}




// Save the user's request to close to the tray
void Global::setCloseToTray(bool value) {
    settings->beginGroup(INI_GROUP_SAVE_STATE);
    settings->setValue("closeToTray", value);
    settings->endGroup();
}

// Should we whow the note list grid?
bool Global::showNoteListGrid() {
    bool showNoteListGrid;
    settings->beginGroup(INI_GROUP_APPEARANCE);
    showNoteListGrid = settings->value("showNoteListGrid", false).toBool();
    settings->endGroup();
    return showNoteListGrid;
}

// Should we alternate the note list colors?
bool Global::alternateNoteListColors() {
    bool alternateNoteListColors;
    settings->beginGroup(INI_GROUP_APPEARANCE);
    alternateNoteListColors = settings->value("alternateNoteListColors", true).toBool();
    settings->endGroup();
    return alternateNoteListColors;
}

// Save the position of a column in the note list.
void Global::setColumnPosition(QString col, int position) {
    if (listView == ListViewWide)
        settings->beginGroup(INI_GROUP_COL_POS_WIDE);
    else
        settings->beginGroup(INI_GROUP_COL_POS_NARROW);
    settings->setValue(col, position);
    settings->endGroup();
}


// Save the with of a column in the note list
void Global::setColumnWidth(QString col, int width) {
    if (listView == ListViewWide)
        settings->beginGroup(INI_GROUP_COL_WIDTH_WIDE);
    else
        settings->beginGroup(INI_GROUP_COL_WIDTH_NARROW);
    settings->setValue(col, width);
    settings->endGroup();
}


// Get the desired width for a given column
int Global::getColumnWidth(QString col) {
    if (listView == ListViewWide)
        settings->beginGroup(INI_GROUP_COL_WIDTH_WIDE);
    else
        settings->beginGroup(INI_GROUP_COL_WIDTH_NARROW);
    int value = settings->value(col, -1).toInt();
    settings->endGroup();
    return value;
}


// Get the position of a given column in the note list
int Global::getColumnPosition(QString col) {
    if (listView == ListViewWide)
        settings->beginGroup(INI_GROUP_COL_POS_WIDE);
    else
        settings->beginGroup(INI_GROUP_COL_POS_NARROW);
    int value = settings->value(col, -1).toInt();
    settings->endGroup();
    return value;
}


// Get the minimum recognition confidence.  Anything below this minimum will not be
// included in search results.
int Global::getMinimumRecognitionWeight() {
    settings->beginGroup(INI_GROUP_SEARCH);
    int value = settings->value("minimumRecognitionWeight", 20).toInt();
    settings->endGroup();
    return value;
}

void Global::setClearNotebookOnSearch(bool value) {
    settings->beginGroup(INI_GROUP_SEARCH);
    settings->setValue("clearNotebookOnSearch", value);
    settings->endGroup();
}


void Global::setClearTagsOnSearch(bool value) {
    settings->beginGroup(INI_GROUP_SEARCH);
    settings->setValue("clearTagsOnSearch", value);
    settings->endGroup();
}

void Global::setClearSearchOnNotebook(bool value) {
    settings->beginGroup(INI_GROUP_SEARCH);
    settings->setValue("clearSearchOnNotebook", value);
    settings->endGroup();
}

void Global::setTagSelectionOr(bool value) {
    settings->beginGroup(INI_GROUP_SEARCH);
    settings->setValue("tagSelectionOr", value);
    settings->endGroup();
}

bool Global::getClearNotebookOnSearch() {
    settings->beginGroup(INI_GROUP_SEARCH);
    bool value = settings->value("clearNotebookOnSearch", false).toBool();
    settings->endGroup();
    return value;
}

bool Global::getClearSearchOnNotebook() {
    settings->beginGroup(INI_GROUP_SEARCH);
    bool value = settings->value("clearSearchOnNotebook", false).toBool();
    settings->endGroup();
    return value;
}


bool Global::getClearTagsOnSearch() {
    settings->beginGroup(INI_GROUP_SEARCH);
    bool value = settings->value("clearTagsOnSearch", false).toBool();
    settings->endGroup();
    return value;
}


bool Global::getBackgroundIndexing() {
    settings->beginGroup(INI_GROUP_SEARCH);
    bool value = settings->value("backgroundIndexing", false).toBool();
    settings->endGroup();
    return value;
}


void Global::setBackgroundIndexing(bool value) {
    settings->beginGroup(INI_GROUP_SEARCH);
    settings->setValue("backgroundIndexing", value);
    settings->endGroup();
}


bool Global::getTagSelectionOr() {
    settings->beginGroup(INI_GROUP_SEARCH);
    bool value = settings->value("tagSelectionOr", false).toBool();
    settings->endGroup();
    return value;
}


void Global::setIndexPDFLocally(bool value) {
    settings->beginGroup(INI_GROUP_SEARCH);
    settings->setValue("indexPDFLocally", value);
    settings->endGroup();
    indexPDFLocally = value;
}

bool Global::getIndexPDFLocally() {
    settings->beginGroup(INI_GROUP_SEARCH);
    bool value = settings->value("indexPDFLocally", true).toBool();
    settings->endGroup();
    indexPDFLocally = value;
    return value;
}


bool Global::readSettingForceSearchLowerCase() const {
    settings->beginGroup(INI_GROUP_SEARCH);
    const QVariant variant = settings->value("forceLowerCase");
    settings->endGroup();

    bool value = false;
    if (variant.isValid()) {
        value = variant.toBool();
    } else {
        saveSettingForceSearchLowerCase(value);
    }
    return value;
}

void Global::saveSettingForceSearchLowerCase(bool value) const {
    settings->beginGroup(INI_GROUP_SEARCH);
    settings->setValue("forceLowerCase", value);
    settings->endGroup();
}

bool Global::readSettingForceSearchWithoutDiacritics() const {
    settings->beginGroup(INI_GROUP_SEARCH);
    const QVariant variant = settings->value("forceSearchWithoutDiacritics");
    settings->endGroup();

    bool value = false;
    if (variant.isValid()) {
        value = variant.toBool();
    } else {
        saveSettingForceSearchWithoutDiacritics(value);
    }
    return value;
}

void Global::saveSettingForceSearchWithoutDiacritics(bool value) const {
    settings->beginGroup(INI_GROUP_SEARCH);
    settings->setValue("forceSearchWithoutDiacritics", value);
    settings->endGroup();
}

bool Global::getForceUTF8() {
    settings->beginGroup(INI_GROUP_DEBUGGING);
    bool value = settings->value("forceUTF8", true).toBool();
    settings->endGroup();
    forceUTF8 = value;
    return value;
}


void Global::setForceUTF8(bool value) {
    settings->beginGroup(INI_GROUP_DEBUGGING);
    settings->setValue("forceUTF8", value);
    settings->endGroup();
    forceUTF8 = value;
}


// Save the minimum recognition weight for an item to be included in a serch result
void Global::setMinimumRecognitionWeight(int weight) {
    settings->beginGroup(INI_GROUP_SEARCH);
    settings->setValue("minimumRecognitionWeight", weight);
    settings->endGroup();
}


// Should we synchronize attachments?  Not really useful except in debugging
bool Global::synchronizeAttachments() {
    settings->beginGroup(INI_GROUP_SEARCH);
    bool value = settings->value("synchronizeAttachments", true).toBool();
    settings->endGroup();
    return value;
}


// Should we synchronize attachments?  Not really useful except in debugging
void Global::setSynchronizeAttachments(bool value) {
    settings->beginGroup(INI_GROUP_SEARCH);
    settings->setValue("synchronizeAttachments", value);
    settings->endGroup();
}


// get the last time we issued a reminder
qlonglong Global::getLastReminderTime() {
    settings->beginGroup(INI_GROUP_REMINDERS);
    qlonglong value = settings->value("lastReminderTime", 0).toLongLong();
    settings->endGroup();
    return value;
}


// Save the last time we issued a reminder.
void Global::setLastReminderTime(qlonglong value) {
    settings->beginGroup(INI_GROUP_REMINDERS);
    settings->setValue("lastReminderTime", value);
    settings->endGroup();
}


// Setup the default date & time formatting
void Global::setupDateTimeFormat() {
    settings->beginGroup(INI_GROUP_LOCALE);
    int dateFmtNo = settings->value("dateFormat", 1).toInt();
    int timeFmtNo = settings->value("timeFormat", 1).toInt();
    settings->endGroup();

    this->setDateFormat(dateFmtNo);
    this->setTimeFormat(timeFmtNo);
}


// Get the username from the system
QString Global::getUsername() {

    if (!autosetUsername())
        return "";

    // First, see if the Evernote user record is available
    UserTable userTable(db);
    User user;
    userTable.getUser(user);
    if (user.name.isSet())
        return user.name;
// Windows Check
#ifndef _WIN32
    register struct passwd *pw;
    register uid_t uid;
    QString username = "";

    uid = geteuid();
    pw = getpwuid(uid);
    if (pw) {
        username = pw->pw_gecos;
        username.remove(QChar(','));
        if (username != "")
            return username.trimmed();
        username = pw->pw_name;
        return username.trimmed();
    }
#else
    return qgetenv("USERNAME");
#endif // End Windows Check

    return "";
}


// Determine if we should automatically set the username on new notes
bool Global::autosetUsername() {
    settings->beginGroup(INI_GROUP_APPEARANCE);
    bool value = settings->value("autosetUsername", true).toBool();
    settings->endGroup();
    return value;
}


// Set the preference of auto-setting the username
void Global::setAutosetUsername(bool value) {
    settings->beginGroup(INI_GROUP_APPEARANCE);
    settings->setValue("autosetUsername", value);
    settings->endGroup();
}


// Utility function for case insensitive sorting
bool caseInsensitiveLessThan(const QString &s1, const QString &s2) {
    return s1.toLower() < s2.toLower();
}


// Get a generic CSS theme setting from the themes.ini file.
QString Global::getThemeCss(QString key) {
    if (colorList.contains(key))
        return colorList[key];

    // read from file - currently unsupported - may be reintroduced later
    //    if (resourceList.contains(":" + key)) {
    //        QString value = resourceList[":" + key].trimmed();
    //        QFile f(value);
    //        if (f.exists()) {
    //            f.open(QIODevice::ReadOnly);
    //            QString css = f.readAll();
    //            return css;
    //        }
    //    }

    return "";
}


// Get the default GUI font
QFont Global::getGuiFont(QFont f) {
    if (defaultGuiFont != "") {
        f.setFamily(defaultGuiFont);
    }
    if (defaultGuiFontSize > 0) {
        f.setPointSize(defaultGuiFontSize);
    }
    return f;
}


// Get a QIcon of in an icon theme
QIcon Global::getIconResource(QHash<QString, QString> &resourceList, QString key) {
    if (resourceList.contains(key) && resourceList[key].trimmed() != "")
        return QIcon(resourceList[key]);
    return QIcon(key);
}


QString Global::getEditorStyle(bool colorOnly) {
    QString returnValue = "";
    if (!colorOnly) {
        returnValue = "document.body.style.background='" + this->getEditorBackgroundColor() + "'; ";
    }
    returnValue = returnValue + "document.body.style.color='" + this->getEditorFontColor() + "';";

    return "function setColor() { " + returnValue + " }; setColor();";
}


QString Global::getEditorFontColor() {
    if (colorList.contains("editorFontColor"))
        return colorList["editorFontColor"];
    else
        return "black";
}


QString Global::getEditorBackgroundColor() {
    if (colorList.contains("editorBackgroundColor"))
        return colorList["editorBackgroundColor"];
    else
        return "white";
}

QString Global::getNoteTitleColor() {
    if (colorList.contains("noteTitleColor"))
        return colorList["noteTitleColor"];
    else
        return "#0e1cd1";
}

QString Global::getNoteTitleActiveStyle() {
    QString result = this->getThemeCss("titleActiveCss");

    if (result.length() == 0) {
        result = "QLineEdit {border: 1px solid #808080; background-color: white; border-radius: 4px;} ";
    }

    return result;
}

QString Global::getNoteTitleInactiveStyle() {
    QString result = this->getThemeCss("titleInactiveCss");

    if (result.length() == 0) {
        result = "QLineEdit {background-color: transparent; border-radius: 0px;} QLineEdit:hover {border: 1px solid #808080; background-color: white; border-radius: 4px;} ";
    }

    return result;
}

QString Global::getDateTimeEditorColor() {
    if (colorList.contains("dateTimeEditorColor"))
        return colorList["dateTimeEditorColor"];
    else
        return "#0e1cd1";
}

QString Global::getTagViewerInactiveStyle() {
    QString result = this->getThemeCss("tagViewerInactiveCss");

    if (result.length() == 0) {
        result = "QLineEdit {color: black; font:normal;} ";
    }

    return result;
}


QString Global::getTagViewerActiveStyle() {
    QString result = this->getThemeCss("tagViewerActiveCss");

    if (result.length() == 0) {
        result = "QLineEdit {color: black; font:normal;} ";
    }

    return result;
}


QString Global::getTagEditorInactiveStyle() {
    QString result = this->getThemeCss("tagEditorInactiveCss");

    if (result.length() == 0) {
        result = "QLineEdit {background-color: transparent; border-radius: 0px;} ";
    }

    return result;
}


QString Global::getTagEditorActiveStyle() {
    QString result = this->getThemeCss("tagEditorActiveCss");

    if (result.length() == 0) {
        result = "QLineEdit {border: 1px solid #808080; background-color: white; border-radius: 4px;}";
    }

    return result;
}


QString Global::getUrlEditorActiveStyle() {
    QString result = this->getThemeCss("urlEditorActiveCss");

    if (result.length() == 0) {
        result = "QLineEdit {border: 1px solid #808080; background-color: white; border-radius: 4px;}";
    }

    return result;
}

QString Global::getUrlEditorInactiveStyle() {
    QString result = this->getThemeCss("urlEditorInactiveCss");

    if (result.length() == 0) {
        result = "QLineEdit {background-color: transparent; border-radius: 0px;}";
    }

    return result;
}


QString Global::getDateTimeEditorActiveStyle() {
    QString result = this->getThemeCss("dateTimeEditorActiveCss");

    if (result.length() == 0) {
        result = "QDateTimeEdit {border: 1px solid #808080; background-color: white; border-radius: 4px;}  QDateTimeEdit::up-button {width: 14px;} QDateTimeEdit::down-button{width: 14px;}";
    }

    return result;
}

QString Global::getDateTimeEditorInactiveStyle() {
    QString result = this->getThemeCss("dateTimeEditorInactiveCss");

    if (result.length() == 0) {
        result = "QDateTimeEdit {background-color: transparent; border-radius: 1px;} QDateTimeEdit:hover {border: 1px solid #808080; background-color: white; border-radius: 4px;} QDateTimeEdit::up-button {width: 0px; image:none;} QDateTimeEdit::down-button{width: 0px; image: none;}";
    }

    return result;
}


QString Global::getEditorCss() {
    return this->getThemeCss("editorCss");
}

// Get a QIcon in an icon theme
QIcon Global::getIconResource(QString key) {
    return this->getIconResource(resourceList, key);
}


// Get a QPixmap from an icon theme
QPixmap Global::getPixmapResource(QString key) {
    return this->getPixmapResource(resourceList, key);
}


// Get a QPixmap from an icon theme
QPixmap Global::getPixmapResource(QHash<QString, QString> &resourceList, QString key) {
    if (resourceList.contains(key) && resourceList[key] != "")
        return QPixmap(resourceList[key]);
    return QPixmap(key);
}

// renamed on 20.6.2018 because of structure changes prevent loading of legacy user themes (they need minor fixes)
#define THEME_FILE "themes.ini"


// Load a theme into a resourceList.
void Global::loadTheme(QHash<QString, QString> &resourceList, QHash<QString, QString> &colorList, QString theme) {
    QLOG_DEBUG() << "Loading theme " << theme;

    resourceList.clear();
    colorList.clear();
    if (theme.trimmed() == "") {
        return;
    }

    QFile systemThemeFn(fileManager.getProgramDataDir() + THEME_FILE);
    this->loadThemeFile(resourceList, colorList, systemThemeFn, theme);

    QFile userThemeFn(fileManager.getConfigDir() + THEME_FILE); // user theme
    this->loadThemeFile(resourceList, colorList, userThemeFn, theme);
}


// Load a theme from a given file
void Global::loadThemeFile(QFile &file, QString themeName) {
    this->loadThemeFile(resourceList, colorList, file, themeName);
}


// Load a theme from a given file
void Global::loadThemeFile(QHash<QString, QString> &resourceList, QHash<QString, QString> &colorList, QFile &file,
                           QString themeName) {
    if (!file.exists())
        return;
    if (!file.open(QIODevice::ReadOnly))
        return;

    QTextStream in(&file);
    QString colon(":");
    QString openingBracket(":");

    bool themeFound = false;
    QString wantedThemeHeader = "[" + themeName.trimmed() + "]";
    while (!in.atEnd()) {
        QString line = in.readLine().simplified();
        bool isComment = line.startsWith("#");
        if (isComment) {
            continue;
        }
        bool isThemeHeader = line.startsWith("[");

        if (isThemeHeader && wantedThemeHeader != line) {
            themeFound = false;
            continue;
        }
        if (isThemeHeader && wantedThemeHeader == line) {
            themeFound = true;
            // we don't clear the existing values, as we want user theme be able to add to system theme but doesn't need to replace all
        }


        if (themeFound) {
            QStringList fields = line.split("=");
            if (fields.size() >= 2) {
                QString key = line.section('=', 0, 0).simplified();
                QString value = line.section('=', 1, 999).split("##").at(0).simplified();
                if (key.isEmpty() || value.isEmpty()) {
                    // empty keys and values are ignores
                    // if user theme wants to reset existing style to blank, then it needs to put at least something
                    continue;
                }

                QLOG_TRACE() << "Theme " << wantedThemeHeader << ": key=" << key << "value=" << value;

                // this is a guess, but inline CSS always needs to contain ":", file path should never
                // or at least "{"
                bool isInlineCss = value.contains(colon) || value.contains(openingBracket);
                if (isInlineCss) {
                    colorList.insert(key, value);
                    QLOG_TRACE() << "Theme " << wantedThemeHeader << ": added CSS key=" << key << "value=" << value;
                } else {
                    // image
                    // css in external file unsupported now
                    QString filePath = fileManager.getImageDirPath("").append(value);
                    QFile f(filePath);
                    if (f.exists()) {
                        QLOG_TRACE() << "Theme " << wantedThemeHeader << ": added image key=" << key << "path="
                                     << filePath;
                        resourceList.insert(":" + key, filePath);
                    } else {
                        QLOG_WARN() << "Theme image file for key=" << key << "not found: " + filePath;
                    }
                }
            }
        }

    }

    file.close();
}

// Get all available themes
QStringList Global::getThemeNames() {
    QStringList values;
    values.empty();
    this->getThemeNamesFromFile(fileManager.getProgramDataDir() + THEME_FILE, values);
    this->getThemeNamesFromFile(fileManager.getConfigDir() + THEME_FILE, values);

    // leave in order how they were defined in the file (this makes sure DEFAULT theme will be first)
    //if (!nonAsciiSortBug)
    //    qSort(values.begin(), values.end(), caseInsensitiveLessThan);
    if (values.size() == 0) {
        QLOG_FATAL() << "No themes found";
        exit(16);
    }

    return values;
}

// Get all themes available in a given file
void Global::getThemeNamesFromFile(QString fileName, QStringList &values) {
    QLOG_DEBUG() << "About to load themes from " << fileName;
    QFile file(fileName);

    if (!file.exists()) {
        return;
    }
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }
    QLOG_DEBUG() << "Loading themes from " << fileName;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().simplified();
        if (line.startsWith("[")) {
            QString name = line.mid(1);
            name.chop(1);
            if (name.simplified() != "") {
                if (!values.contains(name, Qt::CaseInsensitive)) {
                    values.append(name);
                }
            }
        }
    }

    file.close();
}


// Get the full path of a resource in a theme file
QString Global::getResourceFileName(QHash<QString, QString> &resourceList, QString key) {
    if (resourceList.contains(key) && resourceList[key].trimmed() != "")
        return resourceList[key];

    // If we have a default resource
    QString fileName = key.remove(":");
    return fileManager.getImageDirPath("") + fileName;
}


// save the proxy address
void Global::setProxyHost(QString proxy) {
    settings->beginGroup(INI_GROUP_PROXY);
    settings->setValue("hostName", proxy);
    settings->endGroup();
}


// save the port for the proxy server
void Global::setProxyPort(int port) {
    settings->beginGroup(INI_GROUP_PROXY);
    settings->setValue("port", port);
    settings->endGroup();
}

// Save the proxy password
void Global::setProxyPassword(QString password) {
    settings->beginGroup(INI_GROUP_PROXY);
    settings->setValue("password", password);
    settings->endGroup();
}


// Save the proxy userid
void Global::setProxyUserid(QString userid) {
    settings->beginGroup(INI_GROUP_PROXY);
    settings->setValue("userid", userid);
    settings->endGroup();
}

// get the proxy  hostname
QString Global::getProxyHost() {
    settings->beginGroup(INI_GROUP_PROXY);
    QString value = settings->value("hostName", "").toString();
    settings->endGroup();
    return value;
}

// Get the proxy port number
int Global::getProxyPort() {
    settings->beginGroup(INI_GROUP_PROXY);
    int value = settings->value("port", 0).toInt();
    settings->endGroup();
    return value;
}

// Get the proxy password
QString Global::getProxyPassword() {
    settings->beginGroup(INI_GROUP_PROXY);
    QString value = settings->value("password", "").toString();
    settings->endGroup();
    return value;
}

// Get the proxy userid
QString Global::getProxyUserid() {
    settings->beginGroup(INI_GROUP_PROXY);
    QString value = settings->value("userid", "").toString();
    settings->endGroup();
    return value;
}

// Get the proxy userid
void Global::setProxyEnabled(bool value) {
    settings->beginGroup(INI_GROUP_PROXY);
    settings->setValue("enabled", value);
    settings->endGroup();
}

// Get the proxy userid
bool Global::isProxyEnabled() {
    settings->beginGroup(INI_GROUP_PROXY);
    bool value = settings->value("enabled", false).toBool();
    settings->endGroup();
    return value;
}

// Set the Sock5 proxy
void Global::setSocks5Enabled(bool value) {
    settings->beginGroup(INI_GROUP_PROXY);
    settings->setValue("socks5", value);
    settings->endGroup();
}

// Get the Socks5 proxy
bool Global::isSocks5Enabled() {
    settings->beginGroup(INI_GROUP_PROXY);
    bool value = settings->value("socks5", false).toBool();
    settings->endGroup();
    return value;
}


// Mouse middle click actions
void Global::setMiddleClickAction(int value) {
    settings->beginGroup(INI_GROUP_APPEARANCE);
    settings->setValue("mouseMiddleClickOpen", value);
    settings->endGroup();
}

int Global::getMiddleClickAction() {
    settings->beginGroup(INI_GROUP_APPEARANCE);
    int value = settings->value("mouseMiddleClickOpen", 0).toInt();
    settings->endGroup();
    return value;
}


bool Global::newNoteFocusToTitle() {
    settings->beginGroup(INI_GROUP_APPEARANCE);
    bool returnValue = settings->value("newNoteFocusOnTitle", false).toBool();
    settings->endGroup();
    return returnValue;
}

void Global::setNewNoteFocusToTitle(bool focus) {
    settings->beginGroup(INI_GROUP_APPEARANCE);
    settings->setValue("newNoteFocusOnTitle", focus);
    settings->endGroup();
}


bool Global::disableImageHighlight() {
    settings->beginGroup(INI_GROUP_DEBUGGING);
    bool value = settings->value("disableImageHighlight", false).toBool();
    settings->endGroup();
    return value;
}


// What version of the database are we using?
int Global::getDatabaseVersion() {
    settings->beginGroup(INI_GROUP_SAVE_STATE);
    int value = settings->value("databaseVersion", 1).toInt();
    settings->endGroup();
    return value;
}


// What version of the database are we using?
void Global::setDatabaseVersion(int value) {
    settings->beginGroup(INI_GROUP_SAVE_STATE);
    settings->setValue("databaseVersion", value);
    settings->endGroup();
    return;
}


// What is doing the system notification?
QString Global::systemNotifier() {
    settings->beginGroup(INI_GROUP_APPEARANCE);
    QString value = settings->value("systemNotifier", "qt").toString();
    settings->endGroup();
    return value;
}


void Global::stackDump(int max) {
// Windows Check
#ifndef _WIN32

    void *array[30];
    size_t size;
    QLOG_ERROR() << "***** Dumping stack *****";

    // get void*'s for all entries on the stack
    size = backtrace(array, 30);
    char **messages = backtrace_symbols(array, size);

    if (max > 0)
        size = max + 1;  // We add one here because we always skip the first thing on the stack (this function).
    for (size_t i = 1; i < size && messages != nullptr; ++i) {
        char *mangled_name = 0, *offset_begin = 0, *offset_end = 0;

        // find parantheses and +address offset surrounding mangled name
        for (char *p = messages[i]; *p; ++p) {
            if (*p == '(') {
                mangled_name = p;
            } else if (*p == '+') {
                offset_begin = p;
            } else if (*p == ')') {
                offset_end = p;
                break;
            }
        }

        // if the line could be processed, attempt to demangle the symbol
        if (mangled_name && offset_begin && offset_end &&
            mangled_name < offset_begin) {
            *mangled_name++ = '\0';
            *offset_begin++ = '\0';
            *offset_end++ = '\0';

            int status;
            char *real_name = abi::__cxa_demangle(mangled_name, 0, 0, &status);

            // if demangling is successful, output the demangled function name
            if (status == 0) {
                QLOG_ERROR() << "[bt]: (" << i << ") " << messages[i] << " : "
                             << real_name << "+" << offset_begin << offset_end;

            }
                // otherwise, output the mangled function name
            else {
                QLOG_ERROR() << "[bt]: (" << i << ") " << messages[i] << " : "
                             << mangled_name << "+" << offset_begin << offset_end;
            }
            free(real_name);
        }
            // otherwise, print the whole line
        else {
            QLOG_ERROR() << "[bt]: (" << i << ") " << messages[i];
        }
    }

    free(messages);
    QLOG_ERROR() << "**** Stack dump complete *****";
#else
    Q_UNUSED(max)
#endif // End windows check
}

Global global;


// Should we preview fonts in the editor window?
bool Global::previewFontsInDialog() {
    settings->beginGroup(INI_GROUP_APPEARANCE);
    bool value = settings->value("previewFonts", false).toBool();
    settings->endGroup();
    return value;
}


// Set the previewing of fonts in the editor window.
void Global::setPreviewFontsInDialog(bool value) {
    settings->beginGroup(INI_GROUP_APPEARANCE);
    settings->setValue("previewFonts", value);
    settings->endGroup();
}


// Should we show a popup on sync errors?
void Global::setPopupOnSyncError(bool value) {
    global.settings->beginGroup(INI_GROUP_SYNC);
    global.settings->setValue("popupOnSyncError", value);
    global.settings->endGroup();
}

bool Global::popupOnSyncError() {
    global.settings->beginGroup(INI_GROUP_SYNC);
    bool value = global.settings->value("popupOnSyncError", true).toBool();
    global.settings->endGroup();
    return value;
}


// save the user-specified auto-save interval
int Global::getAutoSaveInterval() {
    global.settings->beginGroup(INI_GROUP_APPEARANCE);
    int value = global.settings->value("autoSaveInterval", 500).toInt();
    global.settings->endGroup();
    return value;
}

// Save the user specified auto-save interval
void Global::setAutoSaveInterval(int value) {
    global.settings->beginGroup(INI_GROUP_APPEARANCE);
    global.settings->setValue("autoSaveInterval", value);
    global.settings->endGroup();
    global.autoSaveInterval = value * 1000;
}


// Should we intercept SIGHUP on Unix platforms
bool Global::getInterceptSigHup() {
    global.settings->beginGroup(INI_GROUP_APPEARANCE);
    bool value = global.settings->value("interceptSigHup", true).toBool();
    global.settings->endGroup();
    return value;
}

void Global::setInterceptSigHup(bool value) {
    global.settings->beginGroup(INI_GROUP_APPEARANCE);
    global.settings->setValue("interceptSigHup", value);
    global.settings->endGroup();

}


// Should we use multiple theads to do note saving
bool Global::getMultiThreadSave() {
    global.settings->beginGroup(INI_GROUP_APPEARANCE);
    bool value = global.settings->value("multiThreadSave", false).toBool();
    global.settings->endGroup();
    return value;
}

void Global::setMultiThreadSave(bool value) {
    global.settings->beginGroup(INI_GROUP_APPEARANCE);
    global.settings->setValue("multiThreadSave", value);
    global.settings->endGroup();
    this->multiThreadSaveEnabled = value;
}


QString Global::formatShortcutKeyString(QString shortcutKeyString) {
    return shortcutKeyString.toUpper()
        .replace("SPACE", "Space")
        .replace("CTRL", "Ctrl")
        .replace("ALT", "Alt")
        .replace("SHIFT", "Shift")
        .replace("LEFT", "Left")
        .replace("RIGHT", "Right")
        .replace("PGUP", "PgUp")
        .replace("PGDOWN", "PgDown");
}

QString Global::appendShortcutInfo(QString tooltip, QString shortCutCode) {
    QString shortcutStr = getShortcutStr(shortCutCode, false);
    if (shortcutStr.isEmpty()) {
        return tooltip;
    }
    return tooltip.append(" - ").append(shortcutStr);
}

QString Global::getShortcutStr(QString shortCutCode, bool lowerCased) {
    ShortcutKeys *shortcutKeys = this->shortcutKeys;

    if (!shortcutKeys->containsAction(&shortCutCode)) {
        // none defined
        return QString();
    }
    QString code = shortcutKeys->getShortcut(&shortCutCode);
    if (!lowerCased) {
        // pretty print
        code = formatShortcutKeyString(code);
    }
    return code;
}

QString Global::setupShortcut(QShortcut *action, QString shortCutCode) {
    QString shortcutStr = this->getShortcutStr(shortCutCode, true);
    if (shortcutStr.isEmpty()) {
        return QString();
    }
    QKeySequence key(shortcutStr);
    //QLOG_DEBUG() << "Setting up shortcut key " << shortcutStr;
    action->setKey(key);
    return appendShortcutInfo(QString(), shortCutCode);
}

QString Global::setupShortcut(QAction *action, QString shortCutCode) {
    QString shortcutStr = this->getShortcutStr(shortCutCode, true);
    if (shortcutStr.isEmpty()) {
        return QString();
    }
    QKeySequence key(shortcutStr);
    //QLOG_DEBUG() << "Setting up shortcut key " << shortcutStr;
    action->setShortcut(key);
    return appendShortcutInfo(QString(), shortCutCode);
}

void Global::setMessage(QString msg, int timeout) {
    // sent "setMessage" signal
    emit setMessageSignal(msg, timeout);
}

/**
 * @return Current filter criteria.
 */
FilterCriteria *Global::getCurrentCriteria() const {
    qint32 pos = global.filterPosition;
    QLOG_TRACE() << "Requesting filter [" << pos << "], filter count=" << global.filterCriteria.size();
    return global.filterCriteria[pos];
}

bool Global::isForceSearchLowerCase() const
{
    return forceSearchLowerCase;
}

bool Global::isForceSearchWithoutDiacritics() const
{
    return forceSearchWithoutDiacritics;
}

/**
 * Normalize term before search or index process,
 * @param s String to process.
 * @return Normalized representation.
 */
QString Global::normalizeTermForSearchAndIndex(QString s) const
{
    if (forceSearchLowerCase) {
        s = s.toLower();
    }
    if (forceSearchWithoutDiacritics) {
        stringUtils.removeDiacritics(s);
    }

    return s;
}

const QString &Global::getDateFormat() const {
    return dateFormat;
}


void Global::setDateFormat(int fmtNo) {
    Global::dateFormat = getDateFormatByNo(fmtNo);
}

QString Global::getDateFormatByNo(int fmtNo) const {
    QStringList l = getDateFormats();
    //QLOG_DEBUG() << l << "size=" << l.size();
    if (fmtNo < 1 || (fmtNo > l.size())) {
        fmtNo = 1;
    }
    return l.at(fmtNo - 1);
}

QStringList Global::getDateFormats() const {
    return (QStringList() << "MM/dd/yy" << "MM/dd/yyyy" << "M/dd/yyyy" << "M/d/yyyy" << "dd/MM/yy"
                          << "d/M/yy" << "dd/MM/yyyy" << "d/M/yyyy" << "yyyy-MM-dd" << "yy-MM-dd"
                          << "yyMMdd" << "dd.MM.yy" << "dd.MM.yyyy" << "d.M.yy" << "d.M.yyyy");
}

QStringList Global::getTimeFormats() const {
    return (QStringList() << "HH:mm:ss" << "HH:MM:SS a" << "HH:mm" << "HH:mm a" << "hh:mm:ss"
                          << "hh:mm:ss a" << "h:mm:ss a" << "hh:mm" << "hh:mm a" << "h:mm a");
}

const QString &Global::getTimeFormat() const {
    return timeFormat;
}

void Global::setTimeFormat(int time) {
    Global::timeFormat = getTimeFormatByNo(time);
}

QString Global::getTimeFormatByNo(int fmtNo) const {
    QStringList l = getTimeFormats();
    if (fmtNo < 1 || (fmtNo > l.size())) {
        fmtNo = 1;
    }
    return l.at(fmtNo - 1);
}

QString Global::getDateTimeFormat() const {
    return getDateFormat() + QStringLiteral(" ") + getTimeFormat();
}

const QString Global::getSortOrder() const {
    return Global::sortOrder;
}

void Global::setSortOrder(const QString &sortOrder) {
    Global::sortOrder = sortOrder;
    saveSettingSortOrder(sortOrder);
}