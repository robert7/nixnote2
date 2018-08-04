/*********************************************************************************
NixNote - An open-source client for the Evernote service.
Copyright (C) 2015 Randy Baumgarte

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

#include "traymenu.h"
#include "src/sql/notetable.h"
#include "src/sql/favoritestable.h"
#include "src/global.h"

extern Global global;

TrayMenu::TrayMenu(QWidget *parent) :
        QMenu(parent) {
    signalMapper = new QSignalMapper();
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(noteChosen(int)));

    // QMenu: this signal is emitted just before the menu is shown to the user.
    connect(this, SIGNAL(aboutToShow()), this, SLOT(buildActionMenu()));
    connect(this, SIGNAL(show()), this, SLOT(buildActionMenu()));

    QString css = global.getThemeCss("trayMenuCss");
    if (css != "") {
        this->setStyleSheet(css);
    }
    
    pinnedMenu = nullptr;
    recentlyUpdatedMenu = nullptr;
    favoriteNotesMenu = nullptr;
}

void TrayMenu::setActionMenu(ActionMenuType type, QMenu *menu) {
    if (type == PinnedMenu) {
        pinnedMenu = menu;
    } else if (type == RecentMenu) {
        recentlyUpdatedMenu = menu;
    } else if (type == FavoriteNotesMenu) {
        favoriteNotesMenu = menu;
    }
}

void TrayMenu::buildActionMenu() {
    QLOG_DEBUG() << "buildActionMenu";

    for (int i = actions.size() - 1; i >= 0; i--) {
        QAction *action = actions[i];
        signalMapper->removeMappings(action);
        if (pinnedMenu) {
            pinnedMenu->removeAction(action);
        }
        if (recentlyUpdatedMenu) {
            recentlyUpdatedMenu->removeAction(action);
        }
        if (favoriteNotesMenu) {
            favoriteNotesMenu->removeAction(action);
        }
    }
    actions.clear();

    QList<QPair<qint32, QString> > records;
    NoteTable noteTable(global.db);
    if (pinnedMenu) {
        noteTable.getAllPinned(records);
        buildMenu("pinnedMenu", pinnedMenu, records);
    }

    if (recentlyUpdatedMenu) {
        records.clear();;
        noteTable.getRecentlyUpdated(records);
        buildMenu("recentlyUpdatedMenu", recentlyUpdatedMenu, records);
    }

    if (favoriteNotesMenu) {
        records.clear();
        FavoritesTable ftable(global.db);
        QList<qint32> lids;
        ftable.getAll(lids);
        for (int i = 0; i < lids.size(); i++) {
            FavoritesRecord record;
            ftable.get(record, lids[i]);
            if (record.type == FavoritesRecord::Note) {
                QPair<qint32, QString> pair;
                pair.first = record.target.toInt();
                pair.second = record.displayName;
                records.prepend(pair);
            }
        }
        favoriteNotesMenu->clear();
        buildMenu("favoriteNotesMenu", favoriteNotesMenu, records);
    }
}


void TrayMenu::buildMenu(QString debugInfo, QMenu *actionMenu, QList<QPair<qint32, QString> > records) {
    QLOG_DEBUG() << "buildMenu: " << debugInfo;
    if (!actionMenu) {
        return;
    }

    for (int i = 0; i < records.size(); i++) {
        QAction *newAction = actionMenu->addAction(records[i].second);
        signalMapper->setMapping(newAction, records[i].first);
        connect(newAction, SIGNAL(triggered()), signalMapper, SLOT(map()));
        actions.append(newAction);
    }

}

void TrayMenu::noteChosen(int note) {
    emit (openNote(note));
}
