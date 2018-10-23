/*********************************************************************************
NixNote - An open-source client for the Evernote service.
Copyright (C) 2014 Randy Baumgarte

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



#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <QObject>
#include <QStringList>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0) && !defined(_WIN32)
#include <QLibraryInfo>
#endif

// Windows Check
#ifndef _WIN32
class Hunspell;

class SpellChecker : public QObject
{
    Q_OBJECT
private:
    QStringList dictionaryPath;
    QString findDictionary(QString file);
    Hunspell *hunspell;
    QString customDictionaryPath;
    QString locale;
    QString getCustomDictionaryFileName();

public:
    explicit        SpellChecker(QObject *parent = 0);
    bool            setup(QString customDictionaryPath, QString language=QString());
    bool            spellCheck(QString word, QStringList &suggestions);
    void            addWord(QString word);
    QStringList     availableSpellLocales();

    static const QStringList dictionaryPaths()
    {
        QStringList dictPath;
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0) && !defined(_WIN32)
        dictPath.append(QLibraryInfo::location(QLibraryInfo::PrefixPath) + "/share/hunspell/");
#endif
        dictPath.append("/usr/share/hunspell/");
        dictPath.append("/usr/share/myspell/");
        dictPath.append("/usr/share/myspell/dicts/");
        dictPath.append("/Library/Spelling/");
        dictPath.append("/opt/openoffice.org/basis3.0/share/dict/ooo/");
        dictPath.append("/opt/openoffice.org2.4/share/dict/ooo/");
        dictPath.append("/usr/lib/openoffice.org2.4/share/dict/ooo");
        dictPath.append("/opt/openoffice.org2.3/share/dict/ooo/");
        dictPath.append("/usr/lib/openoffice.org2.3/share/dict/ooo/");
        dictPath.append("/opt/openoffice.org2.2/share/dict/ooo/");
        dictPath.append("/usr/lib/openoffice.org2.2/share/dict/ooo/");
        dictPath.append("/opt/openoffice.org2.1/share/dict/ooo/");
        dictPath.append("/usr/lib/openoffice.org2.1/share/dict/ooo");
        dictPath.append("/opt/openoffice.org2.0/share/dict/ooo/");
        dictPath.append("/usr/lib/openoffice.org2.0/share/dict/ooo/");
        return dictPath;
    }

    QString errorMsg;
signals:

public slots:

};

#endif // end of windows check

// just some name for logs
#define SPELLCHECKER_MODULE "Spellchecker"

#endif // SPELLCHECKER_H
