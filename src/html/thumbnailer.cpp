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

#include "thumbnailer.h"
#include <QtWebKit>
#include <QWebPage>
#include <QWebFrame>
#include <QtSql>
#include <QTextDocument>
#include <QPainter>
#include "src/global.h"
#include "src/sql/notetable.h"

extern Global global;

/* Generic constructor. */
Thumbnailer::Thumbnailer(DatabaseConnection *db)
{
    this->db = db;
}

Thumbnailer::~Thumbnailer() {
}


void Thumbnailer::capturePage(qint32 lid, QWebPage *page) {
    qreal zoomFactor = page->mainFrame()->zoomFactor();
    QSize viewportSize = page->viewportSize();

    page->mainFrame()->setZoomFactor(3);
    page->setViewportSize(QSize(300,300));

    QImage pix(QSize(300,300), QImage::Format_ARGB32);
    QPainter painter;
    painter.begin(&pix);
    QRegion region = QRegion(0, 0, 300, 300);
    page->mainFrame()->render(&painter, region);
    painter.end();
    QString filename = global.fileManager.getThumbnailDirPath() + QString::number(lid) +".png";
    pix.save(filename);

    page->mainFrame()->setZoomFactor(zoomFactor);
    page->setViewportSize(viewportSize);

    NoteTable ntable(db);
    ntable.setThumbnail(lid, filename);
}

