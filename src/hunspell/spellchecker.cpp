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



#include "spellchecker.h"
#include <QFile>
#include <QDir>
#include <QLocale>
#include <QTextStream>
#include <hunspell.hxx>
#include "src/logger/qslog.h"



SpellChecker::SpellChecker(QObject *parent) :
        QObject(parent) {
    dictionaryPath = dictionaryPaths();

    hunspell = nullptr;
}


QString SpellChecker::findDictionary(QString file) {
    for (int i = 0; i < dictionaryPath.size(); ++i) {
        const QString dictFile = dictionaryPath[i] + file;
        QFile f(dictFile);
        if (f.exists()) {
            return dictFile;
        }
    }
    return QString();
}


bool SpellChecker::setup(QString customDictionaryPath, QString locale) {
    if (locale.isEmpty()) {
        locale = QLocale::system().name();
    }

    dictionaryPath.prepend(customDictionaryPath);
    this->customDictionaryPath = customDictionaryPath;
    this->locale = locale;

    QString aff = findDictionary(locale + ".aff");
    QString dic = findDictionary(locale + ".dic");

    if (dic.isEmpty() || aff.isEmpty()) {
        qWarning().nospace() << (SPELLCHECKER_MODULE
        ": unable to find dictionaries for locale ") << locale
                << ", path=" << dictionaryPath;
        return false;
    }
    QLOG_INFO() << SPELLCHECKER_MODULE << ": using dictionaries: aff=" << aff << ", dic=" << dic;

    if (hunspell) {
        delete hunspell;
    }
    hunspell = new Hunspell(aff.toStdString().c_str(), dic.toStdString().c_str());

    // Start adding custom words
    QString customDictionaryFile(getCustomDictionaryFileName());
    QFile f(customDictionaryFile);
    QLOG_INFO() << SPELLCHECKER_MODULE << ": adding words from user dictionary=" << customDictionaryFile;

    int count = 0;
    if (f.exists()) {
        f.open(QIODevice::ReadOnly);
        QTextStream in(&f);
        while (!in.atEnd()) {
            QString word = in.readLine();
            hunspell->add(word.toStdString().c_str());
            QLOG_DEBUG() << SPELLCHECKER_MODULE ": adding word: " << word;
            count++;
        }
        f.close();
    }
    QLOG_DEBUG() << SPELLCHECKER_MODULE ": " << count << " words added";
    return true;
}

QString SpellChecker::getCustomDictionaryFileName() {
    return customDictionaryPath + "user-" + locale + ".lst";
}


bool SpellChecker::spellCheck(QString word, QStringList &suggestions) {
    suggestions.clear();
    if (!hunspell) {
        return false;
    }
    int isValid = hunspell->spell(word.toStdString().c_str());
    if (isValid) {
        return true;
    }

#ifdef HUNSPELL_16_PLUS
    // currently not used, as I don't know how to easily detect the version

    const auto suggested = hunspell->suggest(word.toStdString().c_str());
    for_each(suggested.begin(), suggested.end(), [&suggestions](const std::string &suggestion) {
        suggestions << QString::fromStdString(suggestion);
    });
#else
    // deprecated in 1.6 - but needed for 1.3
    char **wlst;
    int ns = hunspell->suggest(&wlst,word.toStdString().c_str());
    for (int i=0; i < ns; i++) {
        suggestions.append(QString::fromStdString(wlst[i]));
    }
#endif

    return false;
}


void SpellChecker::addWord(QString word) {
    if (!hunspell) {
        return;
    }
    QString customDictionaryFile(getCustomDictionaryFileName());
    hunspell->add(word.toStdString().c_str());

    QLOG_DEBUG() << "Adding word " << word << " to user dictionary " << customDictionaryFile;

    // Append to the end of the user dictionary
    // Start adding custom words
    QFile f(customDictionaryFile);
    f.open(QIODevice::Append);
    QTextStream out(&f);
    out << word << "\n";
    f.close();
}

QStringList SpellChecker::availableSpellLocales() {
    QStringList dictionaryPath = SpellChecker::dictionaryPaths();

    // locale regex
    QRegExp localeRx("^[a-z]{2}_[A-Z]{2}$");

    QStringList values;
    // Start loading available language dictionaries
    for (int i = 0; i < dictionaryPath.size(); i++) {
        QString spellDirName(dictionaryPath[i]);
        QDir spellDir(spellDirName);
        QStringList filter;
        filter.append("*.aff");
        filter.append("*.dic");

        QStringList entryList(spellDir.entryList(filter));
        for (const auto &fileName : entryList) {
            QLOG_DEBUG() << "Found dictionary file: " << fileName << " in " << spellDirName;

            QString lang = fileName;
            lang.chop(4);
            if (localeRx.indexIn(lang) != 0) {
                QLOG_DEBUG() << "Ignoring " << lang << " (as unexpected format)";
                continue;
            }
            QLOG_DEBUG() << "Adding locale: " << lang;

            if (!values.contains(lang)) {
                values.append(lang);
            }
        }
    }
    return values;
}
