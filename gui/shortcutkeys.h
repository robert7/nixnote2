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

#ifndef SHORTCUTKEYS_H
#define SHORTCUTKEYS_H

#include <QObject>
#include <QHash>
#include <string>

using namespace std;


class ShortcutKeys : public QObject
{
    Q_OBJECT
private:
    void loadCustomKeys(QString fileName);

public:
    explicit ShortcutKeys(QObject *parent = 0);

    QHash<QString, QString> *actionMap;
    QHash<QString, QString> *shortcutMap;

    void loadkey(QString action, QString *shortcut);
    void removeByShortcut(QString shortcut);
    void removeByAction(QString action);
    bool containsShortcut(QString *shortcut);
    bool containsAction(QString *action);
    QString getShortcut(QString *action);
    QString getAction(QString *shortcut);
};

#endif // SHORTCUTKEYS_H





