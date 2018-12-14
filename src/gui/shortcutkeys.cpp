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

#include "shortcutkeys.h"
#include "src/global.h"

#include <QFile>

extern Global global;

ShortcutKeys::ShortcutKeys(QObject *parent) :
    QObject(parent)
{
    // Setup value Array
    shortcutMap = new QHash<QString, QString>();
    actionMap = new QHash<QString, QString>();

    QString userFileName = global.fileManager.getConfigDir() + QString("shortcuts.txt"); // user shortcuts
    QString systemFileName = global.fileManager.getProgramDataDir() + QString("shortcuts.txt"); // system shortcuts

    QLOG_DEBUG() << "About to load system shortcuts from " << systemFileName;
    loadCustomKeys(systemFileName);
    QLOG_DEBUG() << "About to load user shortcuts from " << userFileName;
    loadCustomKeys(userFileName);
}

// Read in the custom keys (if they exist)
void ShortcutKeys::loadCustomKeys(QString fileName) {
    QFile file(fileName);
    file.open(QFile::ReadOnly);
    if (file.isOpen()) {
        QLOG_DEBUG() << "Loading " << fileName;
        while (!file.atEnd()) {
            QString line = file.readLine().simplified();
            QStringList list = line.split(" ");
            QStringList keyvalue;

            for (int i = 0; i < list.size(); i++) {
                QString str = list[i].trimmed();

                if (str.startsWith("//")) {
                    break;
                }
                if (str != "") {
                    keyvalue.append(str.toLower());
                }
            }

            if (keyvalue.size() >= 1) {
                QString keyStr = keyvalue[0];
                removeByAction(keyStr);

                if (keyvalue.size() >= 2) {
                    loadkey(keyStr, &keyvalue[1]);
                }
            }
        }
        file.close();
    } else {
        QLOG_TRACE() << "Unable to open" << fileName << "for reading or file does not exist.";
    }
}


// Load a key value into the map for later use
void ShortcutKeys::loadkey(QString action, QString *shortcut) {
    action = action.toLower().trimmed();
    QString sc = shortcut->toLower().trimmed();

    // If we have an existing one, remove it.
    if (actionMap->contains(action)) {
        removeByAction(action);
    }
    if (shortcutMap->contains(sc)) {
        removeByShortcut(sc);
    }

    if (sc == "") {
        removeByShortcut(sc);
        return;
    }

    // Add the new value
    QLOG_TRACE() << "Setting " << action << " to " << sc;
    actionMap->insert(action, sc);
    shortcutMap->insert(sc, action);
}

// Remove a shortcut by the Shortcut key
void ShortcutKeys::removeByShortcut(QString shortcut) {
    QLOG_TRACE() << "Removing by shortcut " << shortcut;
    QString action = shortcutMap->key(shortcut.toLower(), "");
    shortcutMap->remove(shortcut.toLower());
    if (action != "")
        actionMap->remove(action.toLower());
}

// Remove a shortcut by the action itself
void ShortcutKeys::removeByAction(QString action) {
    QLOG_TRACE() << "Removing by action " << action;
    QString shortcut = actionMap->key(action.toLower(),"");
    actionMap->remove(action.toLower());
    if (shortcut != "")
        shortcutMap->remove(shortcut.toLower());
}

// Check if a shortcut key exists
bool ShortcutKeys::containsShortcut(QString *shortcut) {
    QString sk(shortcut->toLower());
    QString key = shortcutMap->value(sk, "");
    if (key.trimmed() == "")
        return false;
    else
        return true;
}

// Check if an action exists
bool ShortcutKeys::containsAction(QString *action) {
    QString key = actionMap->value(action->toLower(), "");
    if (key.trimmed() == "")
        return false;
    else
        return true;
}

// Get a key based upon the action
QString ShortcutKeys::getShortcut(QString *action) {
    if (!actionMap->contains(action->toLower()))
        return "";
    QString retval(actionMap->value(action->toLower()));
    return retval;
}

// Get an action based upon the key
QString ShortcutKeys::getAction(QString *shortcut) {
    if (!shortcutMap->contains(shortcut->toLower()))
        return "";
    return shortcutMap->value(shortcut->toLower());
}

