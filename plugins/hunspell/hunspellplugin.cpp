/*********************************************************************************
NixNote - An open-source client for the Evernote service.
Copyright (C) 2016 Randy Baumgarte

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


#include <iostream>
#include <QDebug>

#include "hunspellplugin.h"
HunspellPlugin::HunspellPlugin() {

}

// Initialize for use. I don't do it in the constructor because I don't 
// want to take the time unless the user REALLY wants to use the spell checker.
bool HunspellPlugin::initialize(QString programDictionary, QString userDictionary, QString &errMsg, QString language)  {
    checker = new SpellChecker();
    qDebug() << "**** Setting up SpellChecker:" << checker << "with" << programDictionary
        << "and" << userDictionary << "for language" << language;
    bool result = checker->setup(programDictionary, userDictionary, language);
    if (!result) {
        errMsg = tr("Error setting up spellchecker with programDictionary %1 and userDictionary %2 for language %3")
            .arg(programDictionary).arg(userDictionary).arg(checker->errorMsg);
    }
    return result;
}

bool HunspellPlugin::spellCheck(QString word, QStringList &suggestions) {
    return checker->spellCheck(word, suggestions);
}


void HunspellPlugin::addWord(QString dictionary, QString word) {
    return checker->addWord(dictionary, word);
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(hunspellplugin, HunspellPlugin)
#endif
