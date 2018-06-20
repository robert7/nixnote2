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

#ifndef FILEMANAGER_H
#define FILEMANAGER_H


#include <QObject>
#include <QRegExp>
#include <QFile>
#include <QDir>
#include <exception>
#include <QStandardPaths>

//************************************************
//* This class is used to retrieve the
//* location of certain directories.
//************************************************
class FileManager : public QObject
{
    Q_OBJECT
private:
    // see: getter method for description
    QString configDir;
    QString programDataDir;
    QString userDataDir;

    QString dbDirPath;
    QDir dbDir;

    QDir logsDir;
    QString logsDirPath;

    QString imagesDirPath;
    QDir imagesDir;

    QString javaDirPath;
    QDir javaDir;

    QString spellDirPathUser;
    QDir spellDirUser;

    //    QString qssDirPath;
    //    QDir qssDir;
    //    QString qssDirPathUser;
    //    QDir qssDirUser;

    QString tmpDirPath;
    QDir tmpDir;

    QString dbaDirPath;
    QDir dbaDir;

    QString dbiDirPath;
    QDir dbiDir;

    QString thumbnailDirPath;
    QDir thumbnailDir;

    QString translateDirPath;
    QDir translateDir;

    QString toPlatformPathSeparator(QString relativePath);
    QString slashTerminatePath(QString path);
    void deleteTopLevelFiles(QDir dir, bool exitOnFail);
    void createDirOrCheckWriteable(QDir dir);
    void checkExistingReadableDir(QDir dir);
    void checkExistingWriteableDir(QDir dir);

public:
    FileManager();
    void setup(QString startupConfigDir, QString startupUserDataDir, QString startupProgramDataDir, int accountId);

    // new global file path interface ------- -----------------------------------------------------------
    // where "nixnote.conf" is stored (but NOT database, logs etc.)
    QString getConfigDir() { return configDir; };

    // where additional resources are stored e.g. "help/*", "images/*" etc.
    QString getProgramDataDir() { return programDataDir; };

    // where user data dir is stored (e.g. database, logs etc.)
    QString getUserDataDir() { return userDataDir; };
    // new global file path interface ------- -----------------------------------------------------------


    QString getSpellDirPath();
    QDir getSpellDirFileUser(QString relativePath);
    QString getSpellDirPathUser();
    QString getDbDirPath(QString relativePath);
    QString getDbaDirPath();
    QString getDbaDirPath(QString relativePath);
    QString getDbaDirPathSpecialChar(QString relativePath);
    QString getDbiDirPath();
    QString getDbiDirPath(QString relativePath);
    QString getDbiDirPathSpecialChar(QString relativePath);
    QString getThumbnailDirPath();
    QString getThumbnailDirPath(QString relativePath);
    QString getThumbnailDirPathSpecialChar(QString relativePath);
    QDir getImageDirFile(QString relativePath);
    QString getImageDirPath(QString relativePath);
    QDir getJavaDirFile(QString relativePath);
    QString getJavaDirPath(QString relativePath);
    QDir getLogsDirFile(QString relativePath);
    QString getLogsDirPath(QString relativePath);
    //    QString getQssDirPath(QString relativePath);
    //    QString getQssDirPathUser(QString relativePath);
    QString getTmpDirPath();
    QString getTmpDirPath(QString relativePath);
    QString getTmpDirPathSpecialChar(QString relativePath);
    QString getTranslateFilePath(QString relativePath);
    void purgeResDirectory(bool exitOnFail);
};

#endif // FILEMANAGER_H


