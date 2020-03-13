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
#include "src/global.h"
#include <iostream>
#include <cstdlib>
#include <QLibraryInfo>
#include "src/logger/qslog.h"
#include "src/logger/qslogdest.h"

//*******************************************
//* This class is used to find the location
//* of various files & directories
//*******************************************

using namespace std;

FileManager::FileManager() = default;

// Return the path the program data.
//
QString FileManager::getDefaultProgramDirPath() {
#ifdef Q_OS_MACOS
    QString appDirPath = QCoreApplication::applicationDirPath();
    if (appDirPath.endsWith(".app/Contents/MacOS")) {
        // get rid of the MacOS component
        appDirPath.chop(5);
        appDirPath.append("Resources/");
        QLOG_DEBUG() << "Default program dir path (adjusted for macOS): applicationDirPath=" << appDirPath;
        return appDirPath ;
    }
#endif

    QString path = QCoreApplication::applicationDirPath();
    QLOG_DEBUG() << "Default program dir path: applicationDirPath=" << path;
    // note: for AppImage this returns something like "/tmp/.mount_nixnotHzLe8g/usr/bin"

    if (path.endsWith("/bin")) {
        // runs in std location
        path.chop(3); // remove 3 chars from end of string
        return path + "share/" + NN_APP_NAME;
    } else {
        QLOG_ERROR() << "Binary needs to be started from application directory...";
        QLOG_ERROR() << "Expected runtime pathname is $SOMEDIR/bin/" NN_APP_NAME
                        ", then application data is expected in "
                        "$SOMEDIR/share/" NN_APP_NAME;
        QLOG_ERROR() << "E.g. use something like: cd $PROJECT_DIR/appdir; ./usr/bin/" NN_APP_NAME
                        ". Or you may use --programDataDir command line option for manual override.";
        exit(16);

        // unsupported - as this would add additional complexity
        // while debugging I recommend starting from $PROJECT_DIR using something like: ./appdir/usr/bin/nixnote2
        //return QDir(path + "/..").absolutePath();
    }
}


QString FileManager::getLibraryDirPath() {
    QString path = QCoreApplication::applicationDirPath();
    QLOG_DEBUG() << "Default program dir path: applicationDirPath=" << path;
    // note: for AppImage this returns something like "/tmp/.mount_nixnotHzLe8g/usr/bin"

    if (path.endsWith("/bin")) {
        // runs in std location
        path.chop(3); // remove 3 chars from end of string
        return path + "lib/" + NN_APP_NAME;
    } else {
        QLOG_ERROR() << "Binary needs to be started from application directory...";
        exit(16);
    }
}

void FileManager::setup(QString startupConfigDir, QString startupUserDataDir, QString startupProgramDataDir) {
    if (!startupConfigDir.isEmpty()) {
        startupConfigDir = slashTerminatePath(startupConfigDir);
    }
    if (!startupProgramDataDir.isEmpty()) {
        startupProgramDataDir = slashTerminatePath(startupProgramDataDir);
    }
    if (!startupUserDataDir.isEmpty()) {
        startupUserDataDir = slashTerminatePath(startupUserDataDir);
    }

    QLOG_DEBUG() << "Setting up file paths: "
                 << " startupConfigDirPath=" << startupConfigDir
                 << ", startupUserDataDir=" << startupUserDataDir
                 << ", startupProgramDirPath=" << startupProgramDataDir;

    this->configDir = startupConfigDir;
    this->userDataDir = startupUserDataDir;
    this->programDataDir = startupProgramDataDir;

    if (this->configDir.isEmpty()) {
        // OK, there was NO command line override, now for backward compatibility, check, whenewer there
        // legacy config exists
        QDir legacyConfigDir;
        QString legacyConfigDirPath(QDir().homePath() + QString("/.nixnote"));
        legacyConfigDir.setPath(legacyConfigDirPath);
        QLOG_DEBUG() << "Checking whenever legacy config dir exists: " << legacyConfigDirPath;
        if (legacyConfigDir.exists()) {
            this->configDir = slashTerminatePath(legacyConfigDirPath);
            this->userDataDir = this->configDir;
            QLOG_DEBUG() << "Legacy config/data dir found. falling back to that: "
                         << this->configDir;
        }
    }

    if (this->configDir.isEmpty()) {
        // default config path
        QString stdPath = slashTerminatePath(QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation));
        this->configDir = fixStandardPath(stdPath);
        QLOG_DEBUG() << "Setting up standard config path: " << this->configDir;
    }
    createDirOrCheckWriteable(this->configDir);

    if (this->userDataDir.isEmpty()) {
        // default config path
        QString stdPath = slashTerminatePath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
        this->userDataDir = fixStandardPath(stdPath);
        QLOG_DEBUG() << "Setting up standard user data path: " << this->userDataDir;
    }
    createDirOrCheckWriteable(this->userDataDir);

    // in case nothing was given on command line, set to default
    if (this->programDataDir.isEmpty()) {
        // default program data path
        this->programDataDir = slashTerminatePath(getDefaultProgramDirPath());
    }

    QLOG_DEBUG() << "Resulting file paths: "
                 << "configDir=" << this->configDir
                 << ", userDataDir=" << this->userDataDir
                 << ", programDataDir=" << this->programDataDir;

    // Read only files that everyone uses
    imagesDir.setPath(programDataDir + "images");
    checkExistingReadableDir(imagesDir);
    imagesDirPath = slashTerminatePath(imagesDir.path());

    javaDir.setPath(programDataDir + "java");
    checkExistingReadableDir(javaDir);
    javaDirPath = slashTerminatePath(javaDir.path());

    QDir spellDirUser;
    spellDirUser.setPath(this->configDir + "spell");
    this->spellDirPathUser = slashTerminatePath(spellDirUser.path());
    QLOG_DEBUG() << "Spell checker path: " << spellDirPathUser;
    createDirOrCheckWriteable(this->spellDirPathUser);

    translateDir.setPath(programDataDir + "translations");
    checkExistingReadableDir(translateDir);
    translateDirPath = slashTerminatePath(translateDir.path());

    //    qssDir.setPath(programDataDir + "qss");
    //    checkExistingReadableDir(qssDir);
    //    qssDirPath = slashTerminatePath(qssDir.path());
}


void FileManager::setupUserDirectories(int accountId) {
    QLOG_ASSERT(accountId > 0);

    logsDir.setPath(userDataDir + NN_LOGS_DIR_PREFIX + "-" + QString::number(accountId));
    createDirOrCheckWriteable(logsDir);
    logsDirPath = slashTerminatePath(logsDir.path());

    tmpDir.setPath(userDataDir + NN_TMP_DIR_PREFIX + "-" + QString::number(accountId));
    createDirOrCheckWriteable(tmpDir);
    tmpDirPath = slashTerminatePath(tmpDir.path());

    QString dbPath = userDataDir + NN_DB_DIR_PREFIX + "-" + QString::number(accountId);
    dbDir.setPath(dbPath);

    createDirOrCheckWriteable(dbDir);
    dbDirPath = slashTerminatePath(dbDir.path());

    dbaDir.setPath(dbDirPath + NN_DB_DIR_PREFIX + "a");
    createDirOrCheckWriteable(dbaDir);
    dbaDirPath = slashTerminatePath(dbaDir.path());

    dbiDir.setPath(dbDirPath + NN_DB_DIR_PREFIX + "i");
    createDirOrCheckWriteable(dbiDir);
    dbiDirPath = slashTerminatePath(dbiDir.path());

    thumbnailDir.setPath(dbDirPath + "t" + NN_DB_DIR_PREFIX + "a");
    createDirOrCheckWriteable(thumbnailDir);
    thumbnailDirPath = slashTerminatePath(thumbnailDir.path());
}


QString FileManager::toPlatformPathSeparator(QString relativePath) const {
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

/**
 * This should change the used app name in the app name which we want to have for config paths.
 * As we for some time used "nixnote2" (and we may return to it eventually)
 * let don't change the path, even if we changed the app name.
 *
 * @param path
 * @return fixed path
 */
QString FileManager::fixStandardPath(QString &path) const {
    // not needed anymore
    //path = path.replace("/" NN_APP_NAME "/", "/" NN_APP_NAME_CONFIG_PATHS "/") ;
    return path;
}


/*************************************************/
/* Delete files in a directory.  This is used    */
/* to cleanup temporary files.                   */
/*************************************************/
void FileManager::deleteTopLevelFiles(QDir dir, bool exitOnFail) {
    QLOG_DEBUG() << "About to delete all files in directory: " << dir.absolutePath();
    dir.setFilter(QDir::Files);
    QStringList list = dir.entryList();
    for (qint32 i = 0; i < list.size(); i++) {
        const QString &fileName = list.at(i);
        const QString &fileNameWithPath = dir.filePath(fileName);

        QLOG_DEBUG() << "About to delete file: " << fileNameWithPath;
        QFile f(fileNameWithPath);

        if (!f.remove() && exitOnFail) {
            QLOG_FATAL() << "Error deleting file '" << fileNameWithPath
                         << "'. Aborting program";
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


QString FileManager::getSpellDirPathUser() {
    return spellDirPathUser;
}

QString FileManager::getDbDirPath(QString relativePath) {
    return dbDirPath + toPlatformPathSeparator(relativePath);
}

QDir FileManager::getImageDirFile(QString relativePath) {
    return QDir(imagesDir.dirName() + toPlatformPathSeparator(relativePath));
}

QString FileManager::getImageDirPath(QString relativePath) {
    return imagesDirPath + toPlatformPathSeparator(relativePath);
}

QDir FileManager::getJavaDirFile(QString relativePath) {
    return QDir(javaDir.dirName() + toPlatformPathSeparator(relativePath));
}

QString FileManager::getJavaDirPath(QString relativePath) {
    return javaDirPath + toPlatformPathSeparator(relativePath);
}

QDir FileManager::getLogsDirFile(QString relativePath) {
    return QDir(logsDir.dirName() + toPlatformPathSeparator(relativePath));
}

QString FileManager::getLogsDirPath(QString relativePath) const {
    return logsDirPath + toPlatformPathSeparator(relativePath);
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
    return dbaDirPath;
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

/**
 * Read contents of the file in string
 */
QString FileManager::readFile(QString file) {
    QFile f(file);
    if (!f.open(QFile::ReadOnly)) {
        QLOG_DEBUG() << "Error opening file " << file;
        return QString();
    }
    QTextStream is(&f);
    return is.readAll();
}

QString FileManager::getProgramVersion() {
    const QString programDataDir = getProgramDataDir();
    QString versionFile = programDataDir + "build-version.txt";
    return readFile(versionFile).replace("\n", "");
}

/**
 * Bit more print friendly version.
 * @return
 */
QString FileManager::getProgramVersionPrintable() {
    // cuurently no difference
    return getProgramVersion();
}

/**
 * Setup logging with QLOG_DEBUG_FILE.
 */
void FileManager::setupFileAttachmentLogging() {
    QsLogging::Logger &logger = QsLogging::Logger::instance();

    // 4 configure file logging (until now logging was only to terminal)
    const QString loggingPath = getLogsDirPath("");

    QString loggingAttachmentsPath = loggingPath + LOG_DIR_FILES;
    QDir loggingAttachmentsPathQD(loggingAttachmentsPath);
    createDirOrCheckWriteable(loggingAttachmentsPathQD);
    deleteTopLevelFiles(loggingAttachmentsPathQD, true);

    logger.setFileLoggingPath(loggingAttachmentsPath);
}


