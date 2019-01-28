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

#include "colormenu.h"
#include "src/global.h"

extern Global global;

ColorMenu::ColorMenu(QObject *parent) :
        QObject(parent) {
    this->parent = parent;
    setCurrentColorByEnglishName(DEFAULT_COLORMENU_COLOR);

    populateList();
    QString css = global.getThemeCss("colorMenuCss");
    if (css != "") {
        this->menu.setStyleSheet(css);
    }

}

QStringList ColorMenu::colorNames() {
    QStringList colors;
    const QString delim("|");
    colors << QString(tr("black")).append(delim).append(QString(DEFAULT_COLORMENU_COLOR));
    // for some reason the "dark grey" produces "grey" & "grey" produces "dark grey"
    // anyway this hacky way works enough well for our purpose
    colors << tr("darkGrey").append(delim).append(QString("gray"));
    colors << tr("gray").append(delim).append(QString("darkGrey"));

    colors << tr("red").append(delim).append(QString("red"));
    colors << tr("magenta").append(delim).append(QString("magenta"));
    colors << tr("darkMagenta").append(delim).append(QString("darkMagenta"));
    colors << tr("darkRed").append(delim).append(QString("darkRed"));

    colors << tr("green").append(delim).append(QString("green"));
    colors << tr("darkGreen").append(delim).append(QString("darkGreen"));

    colors << tr("blue").append(delim).append(QString("blue"));
    colors << tr("darkBlue").append(delim).append(QString("darkBlue"));
    colors << tr("cyan").append(delim).append(QString("cyan"));
    colors << tr("darkCyan").append(delim).append(QString("darkCyan"));

    colors << tr("yellow").append(delim).append(QString("yellow"));
    colors << tr("white").append(delim).append(QString("white"));
    return colors;
}


void ColorMenu::populateList() {
    // note: menu is created at beginning (not at runtime)
    QStringList list = colorNames();
    for (int i = 0; i < list.size(); i++) {
        QPixmap pix(QSize(22, 22));

        // (english) color name from the list
        QString colorTuple(list[i]);
        QStringList colorTupleL = colorTuple.split("|");
        if (colorTupleL.size() != 2) {
            continue;
        }

        QString colorNameLocal(colorTupleL[0].trimmed());
        QString colorNameEnglish(colorTupleL[1].trimmed());


        QColor color(colorNameEnglish);
        pix.fill(color);
        // get color code and save into local map
        //QString colorCode(color.name());
        mapLocal2EnglishName[colorNameLocal] = colorNameEnglish;

        QAction *newAction = new QAction(QIcon(pix), "", parent);
        newAction->setToolTip(colorNameLocal);
        newAction->setText(colorNameLocal);
        menu.addAction(newAction);

        connect(newAction, SIGNAL(hovered()), this, SLOT(itemHovered()));
    }
    //QLOG_DEBUG() << "Done: populating colormenu";
}


QString ColorMenu::getCurrentColorAsString() {
    return currentColorAsString;
}

QColor *ColorMenu::getCurrentColor() {
    return &currentColor;
}


QString ColorMenu::local2EnglishName(QString localName) {
    // get name from map created curring construction
    QString colorName(mapLocal2EnglishName[localName]);
    if (colorName.isEmpty()) {
        colorName = DEFAULT_COLORMENU_COLOR;
    }
    return colorName;
}

QString ColorMenu::getCurrentColorName() {
    return currentColorAsString;
}

QMenu *ColorMenu::getMenu() {
    return &menu;
}

void ColorMenu::setCurrentColorByEnglishName(QString color) {
    currentColorAsString = color;
    QColor tempColor(color);
    currentColor = tempColor;
    QLOG_DEBUG() << "Set color to name=" << color << ", code=" << currentColor.name();
}

void ColorMenu::setCurrentColorByLocalName(QString color) {
    setCurrentColorByEnglishName(local2EnglishName(color));
}

void ColorMenu::itemHovered() {
    if (menu.activeAction() != nullptr && menu.activeAction()->toolTip() != nullptr) {
        QString color = menu.activeAction()->toolTip();
        setCurrentColorByLocalName(color);
    }
}
