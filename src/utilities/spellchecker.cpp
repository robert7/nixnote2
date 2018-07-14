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

SpellChecker::SpellChecker(QObject *parent) :
    QObject(parent)
{
    dictionaryPath = dictionaryPaths();

    error = false;
}




QString SpellChecker::findDictionary(QString file) {
    for (int i = 0; i < dictionaryPath.size(); ++i) {
        const QString dictFile = dictionaryPath[i] + file;
        QFile f(dictFile);
        if (f.exists())
            return dictFile;
    }
    return QString();
}



bool SpellChecker::setup(QString programDictionary, QString customDictionary, QString language) {
    QString locale = QLocale::system().name();
    if (!language.isEmpty())
        locale = language;
    dictionaryPath.prepend(programDictionary);
    dictionaryPath.prepend(customDictionary);

    QString aff = findDictionary(locale+".aff");
    QString dic = findDictionary(locale+".dic");
    if (dic.isEmpty() || aff.isEmpty()) {
        error = true;
        errorMsg = tr("Unable to find dictionaries for locale %1. Is a Hunspell dictionary installed for %2?")
            .arg(locale).arg(language);
        qWarning() << errorMsg << "path=" << dictionaryPath;
        // don't bail out, we now have a language selector in the spellcheck dialog
    }
    hunspell = new Hunspell(aff.toStdString().c_str(), dic.toStdString().c_str());

    //Start adding custom words
    QFile f(customDictionary+"user.lst");
    if (f.exists()) {
        f.open(QIODevice::ReadOnly);
        QTextStream in(&f);
        while ( !in.atEnd() ) {
            QString line = in.readLine();
            hunspell->add(line.toStdString().c_str());
        }
        f.close();
    }
    return true;
}


bool SpellChecker::spellCheck(QString word, QStringList &suggestions) {
    suggestions.clear();
    if (Q_UNLIKELY(error)) {
        return false;
    }
    int isValid = hunspell->spell(word.toStdString());
    if (isValid) {
        return true;
    }
    const auto suggested = hunspell->suggest(word.toStdString());
    for_each (suggested.begin(), suggested.end(), [&suggestions](const std::string &suggestion) {
            suggestions << QString::fromStdString(suggestion); });
    return false;
}


void SpellChecker::addWord(QString dictionary, QString word) {
    if (Q_UNLIKELY(error)) {
        return;
    }
    hunspell->add(word.toStdString().c_str());

    // Append to the end of the user dictionary
    //Start adding custom words
    QFile f(dictionary);
    f.open(QIODevice::Append);
    QTextStream out(&f);
    out << word;
    f.close();
}
