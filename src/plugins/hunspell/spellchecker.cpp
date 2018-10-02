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
#include <QLocale>
#include <QTextStream>
#include <QDebug>
#include <hunspell.hxx>
#include <hunspellplugin.h>

#define P_QLOG_DEBUG qDebug().nospace
#define P_QLOG_INFO qInfo().nospace
#define P_QLOG_WARN qWarn().nospace


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
        qWarning().nospace() << (SPELLCHECKER_PLUGIN
        ": unable to find dictionaries for locale ") << locale
                << ", path=" << dictionaryPath;
        return false;
    }
    P_QLOG_INFO() << SPELLCHECKER_PLUGIN << ": using dictionaries: aff=" << aff << ", dic=" << dic;

    if (hunspell) {
        delete hunspell;
    }
    hunspell = new Hunspell(aff.toStdString().c_str(), dic.toStdString().c_str());

    // Start adding custom words
    QString customDictionaryFile(getCustomDictionaryFileName());
    QFile f(customDictionaryFile);
    P_QLOG_INFO() << SPELLCHECKER_PLUGIN << ": adding words from user dictionary=" << customDictionaryFile;

    int count = 0;
    if (f.exists()) {
        f.open(QIODevice::ReadOnly);
        QTextStream in(&f);
        while (!in.atEnd()) {
            QString line = in.readLine();
            hunspell->add(line.toStdString().c_str());
            count++;
        }
        f.close();
    }
    P_QLOG_DEBUG() << SPELLCHECKER_PLUGIN ": " << count << " words added";
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
    int isValid = hunspell->spell(word.toStdString());
    if (isValid) {
        return true;
    }

    const auto suggested = hunspell->suggest(word.toStdString());
    for_each(suggested.begin(), suggested.end(), [&suggestions](const std::string &suggestion) {
        suggestions << QString::fromStdString(suggestion);
    });
    return false;
}


void SpellChecker::addWord(QString word) {
    if (!hunspell) {
        return;
    }
    QString customDictionaryFile(getCustomDictionaryFileName());
    hunspell->add(word.toStdString().c_str());

    P_QLOG_DEBUG() << "Adding word " << word << " to user dictionary " << customDictionaryFile;

    // Append to the end of the user dictionary
    // Start adding custom words
    QFile f(customDictionaryFile);
    f.open(QIODevice::Append);
    QTextStream out(&f);
    out << word;
    f.close();
}
