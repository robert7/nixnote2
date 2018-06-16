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
#include <QLibraryInfo>

//*******************************************
//* This class is used to find the location
//* of various files & directories
//*******************************************

using namespace std;

FileManager::FileManager() {
}

// Return the path the program is executing under
// If we are in /usr/bin, then we need to return /usr/share/nixnote2.
// This is because we want to find other paths (like images).  This
// allows for users to run it out of a non-path location.
QString getDefaultProgramDirPath() {
#ifdef Q_OS_MACOS
    QString appDirPath = QCoreApplication::applicationDirPath();
    if (appDirPath.endsWith(".app/Contents/MacOS")) {
        // get rid of the MacOS component
        appDirPath.chop(5);
        return appDirPath + "/Resources/";
    }
#endif
    QString path = QCoreApplication::applicationDirPath();
    if (path.endsWith("/bin")) {
        path.chop(3); // remove 3 chars from end of string
        return path + "share/nixnote2";
    }
    return path;
}


void  FileManager::setup(QString startupConfigDir, QString startupUserDataDir, QString startupProgramDataDir, int accountId) {
    if (!startupConfigDir.isEmpty()) {
        startupConfigDir = slashTerminatePath(startupConfigDir);
    }
    if (!startupProgramDataDir.isEmpty()) {
        startupProgramDataDir = slashTerminatePath(startupProgramDataDir);
    }
    if (!startupUserDataDir.isEmpty()) {
        startupUserDataDir = slashTerminatePath(startupUserDataDir);
    }

    QLOG_DEBUG() << "FileManager::setup"
                 << " startupConfigDirPath: " << startupConfigDir
                 << ", startupUserDataDir: " << startupUserDataDir
                 << ", startupProgramDirPath: " << startupProgramDataDir;

    this->configDir = startupConfigDir;
    this->userDataDir = startupUserDataDir;
    this->programDataDir = startupProgramDataDir;

    if (this->configDir.isEmpty()) {
        // OK, there was NO command line override, now for backward compatibility, check, whenewer there
        // legacy config exists
        QDir legacyConfigDir;
        QString legacyConfigDirPath(QDir().homePath() + QString("/.nixnote"));
        legacyConfigDir.setPath(legacyConfigDirPath);
        QLOG_DEBUG() << "FileManager::setup checking whenever legacy config dir exists: " << legacyConfigDirPath;
        if (legacyConfigDir.exists()) {
            this->configDir = slashTerminatePath(legacyConfigDirPath);
            this->userDataDir = this->configDir;
            QLOG_DEBUG() << "FileManager::setup legacy config/data dir found. falling back to that: "
                         << this->configDir;
        }
    }

    if (this->configDir.isEmpty()) {
        // default config path
        this->configDir = slashTerminatePath(QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation));
        QLOG_DEBUG() << "FileManager::setup setting up standard config path: " << this->configDir;
    }
    createDirOrCheckWriteable(this->configDir);

    if (this->userDataDir.isEmpty()) {
        // default config path
        this->userDataDir = slashTerminatePath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
        QLOG_DEBUG() << "FileManager::setup setting up standard user data path: " << this->userDataDir;
    }
    createDirOrCheckWriteable(this->userDataDir);

    // in case nothing was given on command line, set to default
    if (this->programDataDir.isEmpty()) {
        // default program data path
        this->programDataDir = slashTerminatePath(getDefaultProgramDirPath());
    }

    QLOG_DEBUG() << "FileManager::setup "
                 << "configDir: " << this->configDir
                 << ", userDataDir: " << this->userDataDir
                 << ", programDataDir: " << this->programDataDir;

    // Read only files that everyone uses
    imagesDir.setPath(programDataDir + "images");
    checkExistingReadableDir(imagesDir);
    imagesDirPath = slashTerminatePath(imagesDir.path());

    javaDir.setPath(programDataDir + "java");
    checkExistingReadableDir(javaDir);
    javaDirPath = slashTerminatePath(javaDir.path());

    spellDirUser.setPath(programDataDir + "spell");
    checkExistingReadableDir(spellDirUser);
    spellDirPathUser = slashTerminatePath(spellDirUser.path());

    translateDir.setPath(programDataDir + "translations");
    checkExistingReadableDir(translateDir);
    translateDirPath = slashTerminatePath(translateDir.path());

    qssDir.setPath(programDataDir + "qss");
    checkExistingReadableDir(qssDir);
    qssDirPath = slashTerminatePath(qssDir.path());

    // Read/write directories that only we use
    QString globalSettingsFileName = configDir + "nixnote.conf";
    QLOG_DEBUG() << "FileManager::setup globalSettingsFileName: " << globalSettingsFileName;
    QSettings globalSettings(globalSettingsFileName, QSettings::IniFormat);

    if (accountId <= 0) {
        // not given on command line: get from conf file
        globalSettings.beginGroup("SaveState");
        int accountIdFromSettings = globalSettings.value("lastAccessedAccount", 1).toInt();
        globalSettings.endGroup();
        accountId = accountIdFromSettings;
    }

    qssDirUser.setPath(configDir + "qss");
    createDirOrCheckWriteable(qssDirUser);
    qssDirPathUser = slashTerminatePath(qssDirUser.path());

    logsDir.setPath(userDataDir + "logs-" + QString::number(accountId));
    createDirOrCheckWriteable(logsDir);
    logsDirPath = slashTerminatePath(logsDir.path());

    tmpDir.setPath(userDataDir + "tmp-" + QString::number(accountId));
    createDirOrCheckWriteable(tmpDir);
    tmpDirPath = slashTerminatePath(tmpDir.path());

    QString dbPath = userDataDir + "db-" + QString::number(accountId);
    dbDir.setPath(dbPath);

    createDirOrCheckWriteable(dbDir);
    dbDirPath = slashTerminatePath(dbDir.path());

    dbaDir.setPath(dbDirPath + "dba");
    createDirOrCheckWriteable(dbaDir);
    dbaDirPath = slashTerminatePath(dbaDir.path());

    dbiDir.setPath(dbDirPath + "dbi");
    createDirOrCheckWriteable(dbiDir);
    dbiDirPath = slashTerminatePath(dbiDir.path());

    thumbnailDir.setPath(dbDirPath + "tdba");
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


/**
 * Check directory is writeable, if it doesn't exist, create it first.
 **/
void FileManager::createDirOrCheckWriteable(QDir dir) {
    if (!dir.exists()) {
        QLOG_DEBUG() << "About to create directory " << dir;
        if (!dir.mkpath(dir.path())) {
            QLOG_FATAL() << "Failed to create directory '" << dir.path() << "'.  Aborting program.";
            exit(16);
        }
    }
    checkExistingWriteableDir(dir);
}


/**************************************************/
/* Check that an existing directory is readable.  */
/**************************************************/
void FileManager::checkExistingReadableDir(QDir dir) {
    QString path = dir.path();
    // Windows Check
    #ifndef _WIN32
    QLOG_DEBUG() << "Checking read access for directory " << path;
    if (!dir.isReadable()) {
            QLOG_FATAL() << "Directory '" + path + "' does not have read permission.  Aborting program.";
            exit(16);
    }
    #endif  // end windows check

    if (!dir.exists()) {
         QLOG_FATAL() << "Directory '" + path + "' does not exist.  Aborting program";
         exit(16);
    }
}

bool isWriteable(QDir dir) {
#ifndef _WIN32
    // non windows
    QString path(dir.path());
    QFileInfo fi(path);
    return (fi.isDir() && fi.isWritable());
#else
    // TODO recheck of windows, if this works and whenewer there is better way
    return dir.exists();
#endif
}


/**************************************************/
/* Check that an existing directory is writable.  */
/**************************************************/
void FileManager::checkExistingWriteableDir(QDir dir) {
    QString path(dir.path());
    QLOG_DEBUG() << "Checking write access for directory " << path;
    if (!isWriteable(dir)) {
        QLOG_FATAL() << "Directory '" + path + "' does not have read permission.  Aborting program.";
        exit(16);
    }
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
QString FileManager::getTranslateFilePath(QString relativePath) {
    return translateDirPath + toPlatformPathSeparator(relativePath);
}
void FileManager::purgeResDirectory(bool exitOnFail) {
    this->deleteTopLevelFiles(tmpDir.dirName(), exitOnFail);
}








