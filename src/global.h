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


#ifndef GLOBAL_H
#define GLOBAL_H

//*******************************
//* This class is used to store
//* global values across the
//* program.
//*******************************

#include <QString>
#include <QSettings>
#include <QObject>
#include <string>
#include <QSqlDatabase>
#include <QReadWriteLock>
#include <QShortcut>
#include <QAction>
#include "src/application.h"
#include "src/logger/qslog.h"
#include "src/logger/qslogdest.h"
#include "src/settings/filemanager.h"
#include "src/settings/startupconfig.h"
#include "src/filters/filtercriteria.h"
#include "src/models/notecache.h"
#include "src/gui/shortcutkeys.h"
#include "src/settings/accountsmanager.h"
#include "src/reminders/remindermanager.h"
#include "src/sql/databaseconnection.h"
#include "src/threads/indexrunner.h"
#include "src/utilities/crossmemorymapper.h"
#include "src/exits/exitpoint.h"
#include "src/exits/exitmanager.h"
#include "src/quentier/utility/StringUtils.h"



#define NOTE_TABLE_LID_POSITION 0
#define NOTE_TABLE_DATE_CREATED_POSITION 1
#define NOTE_TABLE_DATE_UPDATED_POSITION 2
#define NOTE_TABLE_TITLE_POSITION 3
#define NOTE_TABLE_NOTEBOOK_LID_POSITION 4
#define NOTE_TABLE_NOTEBOOK_POSITION 5
#define NOTE_TABLE_TAGS_POSITION 6
#define NOTE_TABLE_AUTHOR_POSITION 7
#define NOTE_TABLE_DATE_SUBJECT_POSITION 8
#define NOTE_TABLE_DATE_DELETED_POSITION 9
#define NOTE_TABLE_SOURCE_POSITION 10
#define NOTE_TABLE_SOURCE_URL_POSITION 11
#define NOTE_TABLE_SOURCE_APPLICATION_POSITION 12
#define NOTE_TABLE_LATITUDE_POSITION 13
#define NOTE_TABLE_LONGITUDE_POSITION 14
#define NOTE_TABLE_ALTITUDE_POSITION 15
#define NOTE_TABLE_HAS_ENCRYPTION_POSITION 16
#define NOTE_TABLE_HAS_TODO_POSITION 17
#define NOTE_TABLE_IS_DIRTY_POSITION 18
#define NOTE_TABLE_SIZE_POSITION 19
#define NOTE_TABLE_REMINDER_ORDER_POSITION 20
#define NOTE_TABLE_REMINDER_TIME_POSITION 21
#define NOTE_TABLE_REMINDER_TIME_DONE_POSITION 22
#define NOTE_TABLE_PINNED_POSITION 23
#define NOTE_TABLE_COLOR_POSITION 24

// generated thumbnail of the note
#define NOTE_TABLE_THUMBNAIL_POSITION 25

// internal column used for relevance search; value is generated during search
#define NOTE_TABLE_SEARCH_RELEVANCE_POSITION 26


// count of columns in the table (=> must be last column no. plus 1)
#define NOTE_TABLE_COLUMN_COUNT 27


#define MOUSE_MIDDLE_CLICK_NEW_TAB 0
#define MOUSE_MIDDLE_CLICK_NEW_WINDOW 1

using namespace std;


// Forward declare future classes
class DatabaseConnection;
class IndexRunner;

#define SET_MESSAGE_TIMEOUT_SHORT 1000
#define SET_MESSAGE_TIMEOUT_LONGER 15000
#define DEFAULT_THEME_NAME "Default"

// app binary name
#define NN_APP_NAME "nixnote21"

// app name for config paths
// WARNING DON'T CHANGE THIS TO ANYTHING else then "nixnote2" without knowing what it influence (e.g. existing paths of users)
#define NN_APP_NAME_CONFIG_PATHS "nixnote2"


// string to be displayed with program version (current version will be appended)
#define NN_APP_DISPLAY_NAME "NixNote"
// string to be displayed without program version
#define NN_APP_DISPLAY_NAME_GUI "NixNote2"
// user agent name
#define NN_APP_CLIENT_NAME "NixNote2/Linux"

// app name for NNEX format
#define APP_NNEX_APP_NAME "NixNote"

// name of the config file (main config and user configs)
#define NN_CONFIG_FILE_PREFIX "nixnote"
#define NN_NIXNOTE_DATABASE_NAME "nixnote.db"
#define NN_ACCOUNTS_CONFIG_FILE_PREFIX "accounts"
#define NN_DB_DIR_PREFIX "db"
#define NN_LOGS_DIR_PREFIX "logs"
#define NN_TMP_DIR_PREFIX "tmp"
// subdirectory in log directory for file attachments
#define LOG_DIR_FILES "files"

#define NN_DB_CONNECTION_NAME "nixnote"

// as the upstream is currently defunct main page is the fork
#define NN_MAIN_REPO_USER "robert7"
#define NN_MAIN_REPO_NAME "nixnote2"
#define NN_GITHUB_URL_WITH_USER "https://github.com/" NN_MAIN_REPO_USER

// project repository with source
#define NN_GITHUB_REPO_URL NN_GITHUB_URL_WITH_USER "/" NN_MAIN_REPO_NAME
// project wiki
#define NN_GITHUB_WIKI_URL NN_GITHUB_REPO_URL "/wiki"

#define INI_GROUP_APPEARANCE "Appearance"
#define INI_VALUE_SORTORDER "sortOrder"
#define INI_VALUE_SORTORDER_DEFAULT "relevance desc, dateUpdated desc"


#define INI_GROUP_COL_HIDDEN_WIDE "ColumnHidden-Wide"
#define INI_GROUP_COL_POS_WIDE "ColumnPosition-Wide"
#define INI_GROUP_COL_WIDTH_WIDE "ColumnWidth-Wide"
#define INI_GROUP_COL_HIDDEN_NARROW "ColumnHidden-Narrow"
#define INI_GROUP_COL_POS_NARROW "ColumnPosition-Narrow"
#define INI_GROUP_COL_WIDTH_NARROW "ColumnWidth-Narrow"
#define INI_GROUP_SAVE_STATE "SaveState"

#define INI_GROUP_DEBUGGING "Debugging"
#define INI_GROUP_SYNC "Sync"
#define INI_GROUP_LOCALE "Locale"
#define INI_GROUP_SEARCH "Search"
#define INI_GROUP_THUMBNAIL "Thumbnail"

#define INI_GROUP_REMINDERS "Reminders"
#define INI_GROUP_PROXY "Proxy"
#define INI_GROUP_EMAIL "Email"
#define INI_GROUP_PRINTER "Printer"
#define QLOG_ASSERT(expr) if (expr) {} else { QLOG_FATAL() << "Assertion failed: " #expr; exit(16);}

class Global : public QObject {
    Q_OBJECT

private:
    void getThemeNamesFromFile(QString fileName, QStringList &values);
    int accountId;

    // Force notes search text to be lower case.  Useful for some non-ASCII languages.
    bool forceSearchLowerCase;
    bool forceSearchWithoutDiacritics;
    quentier::StringUtils stringUtils;

    // Desired display date format
    QString dateFormat;

    // Desired display time format
    QString timeFormat;

    QString sortOrder;

public:
    const QString &getDateFormat() const;
    const QString &getTimeFormat() const;
    QString getDateTimeFormat() const;
    QString getTimeFormatByNo(int time) const;
    QString getDateFormatByNo(int fmtNo) const;
    QStringList getDateFormats() const;
    QStringList getTimeFormats() const;

    void setDateFormat(int fmtNo);
    void setTimeFormat(int time);

    Global();           // Generic constructor
    virtual ~Global() {};          // destructor

    // Possible ways tags & notebook counts may be displayed to the user
    enum CountBehavior {
        CountAll = 1,
        CountNone = 2
    };
    CountBehavior countBehavior;   // How does the user want tags/notebooks to be counted.

    bool disableUploads;           // Should we disable all uploads to Evernote?  Useful for testing.

    // Valid values for the note list appearance.  Should it be a narrow or wide list
    enum ListViewSetup {
        ListViewWide = 1,
        listViewNarrow = 2
    };

    ListViewSetup listView;    // Current desired note list value

    int argc;                  // Initial argument count from the program start
    char** argv;               // List of arguments from the program start
    FileManager fileManager;   // Manage file paths
    AccountsManager *accountsManager;      // Manage user account
    QCoreApplication *application;              // pointer to this current application
    unsigned int cryptCounter;             // Count of crytpographic entries.  This is incremented each time we encrypt some text.
    QString attachmentNameDelimeter;       // Delimeter between attachment ID & name
    string username;                       // This is probably obsolete
    string password;                       // This is probably obsolete
    bool connected;                        // Are we currently connected to Evernote?
    bool enableIndexing;                   // background indexing
    bool pdfPreview;                       // Should we view PDFs inline?
    bool showGoodSyncMessagesInTray;       // Should we show good sync messages in the tray, or just errors?
    CrossMemoryMapper *sharedMemory;       // Shared memory key.  Useful to prevent multiple instances and for cross memory communication
    bool confirmDeletes();                 // Should we confirm deletes?
    bool purgeTemporaryFilesOnShutdown;    // Should we purge temporary files on shutdown?
    void setDeleteConfirmation(bool value);  // Set delete confirmation
    QString tagBehavior();                 // Should inactive tags be shown?
    bool newNoteFocusToTitle();            // Should we focus on the note title when a new note has been created?
    void setNewNoteFocusToTitle(bool focus); // Set if we should focus on the title when a new note is created
    QString server;                        // Evernote server to sync with
    QSettings *settings;                   // Pointer to the nixnote config file.  There is a different one for each account.
    QSettings *globalSettings;             // Pointer to all the config file that is common to all accounts.
    ShortcutKeys *shortcutKeys;            // Keyboard shortcuts defined by the user
    QList<qint32> expungedResources;       // List of expunged resource LIDs
    QFileSystemWatcher *resourceWatcher;    // Watcher for file system directories.  New files here will create anote

    bool readSettingShowTrayIcon();                   // Should we show the tray icon?
    bool readSettingCloseToTray();                    // Close it to the tray.  We really just hide it.
    bool readSettingMinimizeToTray();                 // Minimize it to tray rather than the task list.  We really just hide it.
    QString readSettingSortOrder();

    void saveSettingMinimizeToTray(bool value);    // Set if we should minimize it to the tray
    void saveSettingSortOrder(QString value);

    void setCloseToTray(bool value);       // Set if we should close it to the tray
    bool showNoteListGrid();               // Should we whow the table grid?
    bool alternateNoteListColors();        // Should we alternate the table colors?
    bool getForceUTF8();                    // force UTF8 encoding if not given by Evernote
    void setForceUTF8(bool value);         // force UTF8 encoding if not given by Evernote
    void setColumnPosition(QString col, int position);    // Save the order of a  note list's column.
    void setColumnWidth(QString col, int width);          // Save the width of a note list column
    int getColumnPosition(QString col);                   // Get the desired position of a note column
    int getColumnWidth(QString col);                      // Get the desired width o a note column.
    int getMinimumRecognitionWeight();                    // Minimum OCR recognition confidence before including it in search results.
    void setSynchronizeAttachments(bool value);           // Should at
    bool synchronizeAttachments();                        // This is probabably obsolete
    qlonglong getLastReminderTime();                      // Get the last time we actually showed a user note reminders.
    void setLastReminderTime(qlonglong value);            // Save the date/time we last showed a user note reminders.
    void setMinimumRecognitionWeight(int weight);         // Set the minimum OCR recgnition confidence before including it in search results.
    bool popupOnSyncError();                 // Should we do a popup on every sync error?
    void setPopupOnSyncError(bool value);    // Set if we should do a popup on sync errors.
    void setBackgroundIndexing(bool value);                         // Should we do indexing in a separate thread?
    bool getBackgroundIndexing();                         // Should we do indexing in a separate thread?
    DatabaseConnection *db;                               // "default" DB connection for the main thread.
    bool javaFound;                                       // Have we found Java?
    bool forceUTF8;                                       // force UTF8 encoding
    QString defaultFont;                                  // Default editor font name
    int defaultFontSize;                                  // Default editor font size
    int defaultGuiFontSize;                               // Default GUI font size
    QString defaultGuiFont;                               // Default GUI font name
    bool startupNewNote;                                  // Were we started with the command to begin a new note?
    bool forceNoStartMimized;                             // Force the system to not start minimized, despite the user's settings
    bool forceSystemTrayAvailable;                        // Override QSystemTrayIcon::isSystemTrayAvailable()
    bool forceStartMinimized;                             // Force it to start minimized, despiet the user's settings
    bool startMinimized;                                  // Do user prefernces say to start minimized?
    bool forceWebFonts;
    qint32 startupNote;                                   // Initial note to startup with.

    qint32 minIndexInterval;                              // Minimum interval to check for any unindexed notes.
    qint32 maxIndexInterval;                              // Maximum interval to check for any unindexed notes.
    qint32 indexResourceCountPause;                       // After indexing this many resources we pause to avoid overloading the CPU
    qint32 indexNoteCountPause;                           // After indexing this many notes we pause to avoid overloading the CPU

    // Filter criteria.  Used for things like the back & forward buttons
    QList<FilterCriteria*> filterCriteria;
    qint32 filterPosition;

    QReadWriteLock  *dbLock;                               // Database read/write lock mutex

    QHash<qint32, NoteCache*> cache;                         // Note cache  used to keep from needing to re-format the same note for a display

    void setup(StartupConfig config, bool guiAvailable);                         // Setup the global variables
    bool guiAvailable;                                        // Is there a GUI available?
    QString full_username;                                    // current username
    bool autosetUsername();                                   // Should the username be set automatically?
    void setAutosetUsername(bool value);
    QString getUsername();                                    // pull username from the system.
    QList< QPair<QString, QString> > passwordRemember;        // Cache of passwords
    QHash< QString, QPair <QString, QString> > passwordSafe;  // Saved passwords
    void appendFilter(FilterCriteria *criteria);
    void setupDateTimeFormat();                               // Setup the user's desired date & time format
    QFont getGuiFont(QFont f);                                // Get the user's desired GUI font
    int getDatabaseVersion();                                 // What DB version are we using?
    void setDatabaseVersion(int value);                       // Save the current database version
    bool nonAsciiSortBug;                                     // Workaround for non-ASCII characters in tag name sorting
    ReminderManager *reminderManager;                         // Used to alert the user when a reminder time has expired

    // These functions deal with proxy settings
    void setProxyHost(QString proxy);
    void setProxyPort(int port);
    void setProxyPassword(QString password);
    void setProxyUserid(QString userid);
    QString getProxyHost();
    int getProxyPort();
    QString getProxyPassword();
    QString getProxyUserid();
    bool isProxyEnabled();
    bool isSocks5Enabled();
    void setProxyEnabled(bool value);
    void setSocks5Enabled(bool value);
    QString systemNotifier();
    bool previewFontsInDialog();
    void setPreviewFontsInDialog(bool value);

    // Search Behavior
    void setClearNotebookOnSearch(bool value);
    void setClearSearchOnNotebook(bool value);
    void setClearTagsOnSearch(bool value);
    void setTagSelectionOr(bool value);
    bool getClearNotebookOnSearch();
    bool getClearSearchOnNotebook();
    bool getClearTagsOnSearch();
    bool getTagSelectionOr();
    bool disableImageHighlight();


    // Middle click settings
    int getMiddleClickAction();
    void setMiddleClickAction(int value);

    bool disableEditing;                                    // Disable all editing of notes
    bool isFullscreen;                                      // Are we in fullscreen mode?
    // These functions deal with the icon themes
    QHash<QString,QString> resourceList;                    // Hashmap of icons used in the current theme
    QHash<QString,QString> colorList;                       // List of colors used in the current theme
    bool indexPDFLocally;                                   // Should we index PDFs locally?


    bool getIndexPDFLocally();                              // Should we index PDFs locally (read from settings)
    void setIndexPDFLocally(bool value);                    // save local index of PDFs option
    QString getEditorStyle(bool colorOnly);                 // Get note editor style overrides
    QString getEditorFontColor();                           // Get the editor font color from the theme
    QString getEditorBackgroundColor();                     // Get the editor background color from the theme

    // Generic inline theme css
    QString getThemeCss(QString key);

    // QString getGenricCss(QString key); //obsolete - remove
    // QString getGenricStyle(QString key); //obsolete - remove

    QString getNoteTitleColor();
    QString getNoteTitleActiveStyle();
    QString getNoteTitleInactiveStyle();

    QString getTagViewerActiveStyle();
    QString getTagViewerInactiveStyle();

    QString getTagEditorActiveStyle();
    QString getTagEditorInactiveStyle();

    QString getUrlEditorActiveStyle();
    QString getUrlEditorInactiveStyle();

    // QString getLineEditSearchActiveStyle();
    // QString getLineEditSearchInactiveStyle();

    QString getDateTimeEditorColor();
    QString getDateTimeEditorActiveStyle();
    QString getDateTimeEditorInactiveStyle();

    QString getEditorCss();
    QPixmap getPixmapResource(QHash<QString, QString> &resourceList, QString key);   // Get a pixmap from the user's (or default) theme
    QPixmap getPixmapResource(QString key);                   // Get a pixmap from the user's (or default) theme
    QIcon getIconResource(QHash<QString, QString> &resourceList, QString key);       // Get an icon from the user's (or default) theme
    QIcon getIconResource(QString key);                       // Get an icon from the user's (or default) theme
    void loadTheme(QHash<QString, QString> &resourceList, QHash<QString, QString> &colorList, QString themeName);   // Load an icon theme into the resourceList
    void loadThemeFile(QFile &file, QString themeName);       // Load a given theme's values from a a file.
    void loadThemeFile(QHash<QString, QString> &resourceList, QHash<QString, QString> &colorList, QFile &file, QString themeName);    // Load a given theme's values from a file
    QStringList getThemeNames();                               // Get a list of all available theme names
    QString getResourceFileName(QHash<QString, QString> &resourceList, QString key);    // Get the actual file path for a given icon theme
    QString getResourcefileName(QString key);                  // Get the actual file path for a given icon theme
    void stackDump(int max=0);                                 // Utility to dump the running stack

    bool readSettingForceSearchLowerCase() const;
    bool readSettingForceSearchWithoutDiacritics() const;

    void saveSettingForceSearchWithoutDiacritics(bool value) const;
    void saveSettingForceSearchLowerCase(bool value) const;

    IndexRunner *indexRunner;                                    // Pointer to index thread

    int minimumThumbnailInterval;                               // Minimum time to scan for thumbnails
    int maximumThumbnailInterval;                               // Maximum time to scan for thumbnails
    bool disableThumbnails;                                     // Disable thumbnail generation
    int batchThumbnailCount;                                    // Maximum number of thumbails to generate per batch

    int getAutoSaveInterval();                                  // Time (in seconds) between auto-saving of notes.
    void setAutoSaveInterval(int value);                                 // Save auto save interval
    int autoSaveInterval;                                       // current auto save interval

    bool getInterceptSigHup();                                  // Intercept SIGHUP on Unix platforms.
    void setInterceptSigHup(bool value);                        // Intercept SIGHUP on Unix platforms

    void setMultiThreadSave(bool value);                        // Should we use multiple theads in the browser window to save
    bool getMultiThreadSave();
    bool multiThreadSaveEnabled;

    ExitManager *exitManager;                                  // Utility to manage exit points.
    QString getProgramDataDir() { return fileManager.getProgramDataDir(); }

    // kind of "pretty print"
    // format from lower cased to "display version"
    QString formatShortcutKeyString(QString shortcutKeyString);

    // get short cut string for given shortcut code (by shortcuts.txt)
    // lowerCased=true => return lower cased string (as it is stored internally and shoudl be used to setup shortcuts)
    // lowerCased=false => will try "pretty print"
    QString getShortcutStr(QString shortCutCode, bool lowerCased = false);

    // setup shortcut key
    // in case match was found, return info to be appended to tooltip
    QString setupShortcut(QShortcut *action, QString shortCutCode);
    // setup shortcut key
    // in case match was found, return info to be appended to tooltip
    QString setupShortcut(QAction *action, QString shortCutCode);

    // used to append active short info to tolltip strings
    QString appendShortcutInfo(QString tooltip, QString shortCutCode);

    // update status bar with given string
    void setMessage(QString msg, int timeout=SET_MESSAGE_TIMEOUT_LONGER);

    void initializeGlobalSettings();
    void initializeUserSettings(int accountId);
    void initializeSharedMemoryMapper(int accountId);

    int getAccountId() { return accountId; };
    void setAccountId(int accountId)  {this->accountId = accountId; };

    FilterCriteria* getCurrentCriteria() const;

    bool isForceSearchLowerCase() const;
    bool isForceSearchWithoutDiacritics() const;

    QString normalizeTermForSearchAndIndex(QString s) const;
    QString getOrCreateMemoryKey() const;

    const QString getSortOrder() const;
    void setSortOrder(const QString &sortOrder);

signals:
    // global can send signal about updating status bar
    void setMessageSignal(QString msg, int timeout);

};

bool caseInsensitiveLessThan(const QString &s1, const QString &s2);         // Helper function to sort values case-insensitive.

#endif // GLOBAL_H
