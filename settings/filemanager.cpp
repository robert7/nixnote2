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


void FileManager::setup(QString startupConfigDirPath, QString startupProgramDirPath, int accountId) {
    if (!startupConfigDirPath.isEmpty()) {
        startupConfigDirPath = slashTerminatePath(startupConfigDirPath);
    }
    if (!startupProgramDirPath.isEmpty()) {
        startupProgramDirPath = slashTerminatePath(startupProgramDirPath);
    }
    QLOG_DEBUG() << "FileManager::setup startupConfigDirPath: " << startupConfigDirPath << ", startupProgramDirPath: "
                 << startupProgramDirPath;

    this->programDataDir = startupProgramDirPath;
    this->configDir = startupConfigDirPath;

    if (this->configDir.isEmpty()) {
        // default config path
        this->configDir = slashTerminatePath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));

        // TODO
        // in order to not break things for existing user, check whenewer this -> configDir exists
        // if it doesn't exist & the OLD path exists - take old path
        // OLD: this -> configDir = slashTerminatePath(QDir().homePath() + QString("/.nixnote"));
    }
    createDirOrCheckWriteable(configDir);

    if (this->programDataDir.isEmpty()) {
        // default config path
        this->programDataDir = slashTerminatePath(getDefaultProgramDirPath());
    }

    QLOG_DEBUG() << "FileManager::setup "
                 << "configDir: " << this->configDirPath
                 << ", programDataDir: " << this->programDataDir;

#ifdef Q_OS_MACOS
        // get the resources from the app bundle
        this->dataDirPath = programDataDir;
    #else
        this->dataDirPath = QLibraryInfo::location(QLibraryInfo::PrefixPath) + "/share/nixnote2/";
    #endif

    const QString userDataDir(slashTerminatePath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)));
    QLOG_DEBUG() << "FileManager::setup dataDirPath: " << this->dataDirPath;

    // Read only files that everyone uses
    imagesDir.setPath(dataDirPath+"images");
    checkExistingReadableDir(imagesDir);
    imagesDirPath = slashTerminatePath(imagesDir.path());

    javaDir.setPath(dataDirPath+"java");
    checkExistingReadableDir(javaDir);
    javaDirPath = slashTerminatePath(javaDir.path());

    spellDirUser.setPath(userDataDir+"spell");
    createDirOrCheckWriteable(spellDirUser);
    spellDirPathUser = slashTerminatePath(spellDirUser.path());

    translateDir.setPath(dataDirPath+"translations");
    checkExistingReadableDir(translateDir);
    translateDirPath= slashTerminatePath(translateDir.path());

    qssDir.setPath(dataDirPath+"qss");
    checkExistingReadableDir(qssDir);
    qssDirPath = slashTerminatePath(qssDir.path());

    // Read/write directories that only we use

    QString settingsFile = configDirPath + "nixnote.conf";
    QLOG_DEBUG() << "FileManager::setup settingsFile: " << settingsFile;
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

    QString dbPath = userDataDir+"db-" +QString::number(accountId);
    dbDir.setPath(dbPath);

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
        QLOG_DEBUG() << "About to create directory " << dir;
         if (!dir.mkpath(dir.path())) {
             QLOG_FATAL() << "Failed to create directory '" << dir.path() << "'.  Aborting program.";
             exit(16);
         }
    } else {
        QLOG_DEBUG() << "Checking read access for directory " << dir;
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

QString FileManager::getProgramDataDir() {
    return programDataDir;
}
QString FileManager::getConfigDir() {
    return configDirPath;
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








