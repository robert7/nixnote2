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
    QObject(parent)
{
    this->parent = parent;
    setCurrentColor(Qt::black);

    populateList();
    QString css = global.getThemeCss("colorMenuCss");
    if (css!="")
        this->menu.setStyleSheet(css);

}

QStringList ColorMenu::colorNames() {
    QStringList colors;
    const QString &delim = QStringLiteral("|");
    colors << QString(tr("black")).append(delim).append(QString("black"));
    colors << tr("gray").append(delim).append(QString("gray"));
    colors << tr("darkGrey").append(delim).append(QString("darkGrey"));

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
        QString colorname(list[i]);
        QColor color(colorname);
        pix.fill(color);
        // get color code and save into local map
        QString colorCode(color.name());
        colorMap[colorCode] = colorname;

        QAction *newAction = new QAction(QIcon(pix), "", parent);
        newAction->setToolTip(colorname);
        newAction->setText(colorname);
        menu.addAction(newAction);

        connect(newAction, SIGNAL(hovered()), this, SLOT(itemHovered()));
    }
    //QLOG_DEBUG() << "Done: populating colormenu";
}


QColor *ColorMenu::getCurrentColor() {
    //QLOG_DEBUG() << "ColorMenu::getCurrentColor; currentColor=" << currentColor.name();
    return &currentColor;
}

QString ColorMenu::getCurrentColorName() {
    QString colorCode(currentColor.name());
    // get name from map created curring construction
    QString colorName(colorMap[colorCode]);
    if (colorName.isEmpty()) {
        colorName = colorCode;
    }
    //QLOG_DEBUG() << "ColorMenu::getCurrentColorName; currentColorName=" << colorName;
    return colorName;
}

QMenu *ColorMenu::getMenu() {
    return &menu;
}

void ColorMenu::setCurrentColor(QColor color) {
    currentColor = color;
}

void ColorMenu::setCurrentColor(QString color) {
    currentColor.setNamedColor(color);
}

void ColorMenu::itemHovered() {
    if (menu.activeAction() != nullptr && menu.activeAction()->toolTip() != nullptr) {
        QString color = menu.activeAction()->toolTip();
        setCurrentColor(color);
    }
}
