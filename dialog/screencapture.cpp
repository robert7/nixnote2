/***************************************************************************
 *   Copyright (C) 2009 - 2011 by Artem 'DOOMer' Galichkin                        *
 *   doomer3d@gmail.com                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/



#include "screencapture.h"

#include <QDesktopWidget>
#include <QApplication>
#include <QMainWindow>
#include <QPoint>
#include <QEvent>
#include <QKeyEvent>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QScreen>
#include <QWindow>
#endif

ScreenCapture::ScreenCapture(QMainWindow *appWindow, QWidget *parent) :
    QDialog(parent)
{

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    // fetch the QScreen on which NixNote2 is currently running:
    const auto desktopWidget = QApplication::desktop();
    int ourScreenNr = desktopWidget->screenNumber(appWindow);
    QScreen *ourScreen = qApp->screens().at(ourScreenNr);

    // move our fullscreen window to the top-left of our current screen
    scOrigin = ourScreen->geometry().topLeft();
    move(scOrigin);
    // also be certain the fullscreen window is on that screen.
    if (auto window = windowHandle()) {
        window->setScreen(ourScreen);
    }
#endif

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint );
    setWindowState(Qt::WindowFullScreen);
#ifdef __APPLE__
    setWindowOpacity(0.25);
#endif
    setCursor(Qt::CrossCursor);

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    // get the geometry of the entire desktop spanning all screens
    const auto desktopGeo = ourScreen->virtualGeometry();
    sizeDesktop = desktopGeo.size();
    desktopOrigin = desktopGeo.topLeft();
    // size our fullscreen window to the virtual desktop size. In theory we
    // should move the top-left to desktopOrigin, but in practice we seem to
    // be limited to the size of the screen we're on anyway (on Mac at least).
    resize(sizeDesktop);

    // QPixmap::grabWindow is deprecated in Qt5 so we use QScreen::grabWindow()
    // and we grab the entire (virtual) desktop.
    desktopPixmapBkg = ourScreen->grabWindow(desktopWidget->winId(),
        desktopGeo.x(), desktopGeo.y(), desktopGeo.width(), desktopGeo.height());
#else
    sizeDesktop = QApplication::desktop()->size();
    resize(sizeDesktop);

    desktopPixmapBkg = QPixmap::grabWindow(QApplication::desktop()->winId());
    move(0, 0);
    desktopOrigin = scOrigin = QPoint(0,0);
#endif
    desktopPixmapClr = desktopPixmapBkg;

    drawBackGround();
}





ScreenCapture::~ScreenCapture()
{
    setWindowState(Qt::WindowMinimized);
}

bool ScreenCapture::event(QEvent *event)
{
    switch (event->type()) {
        case QEvent::MouseButtonRelease:
            accept();
            break;
        case QEvent::KeyPress: {
            QKeyEvent *qke = static_cast<QKeyEvent*>(event);
            if (qke->key() == Qt::Key_Escape) {
                // escape key cancels the grab
                reject();
            } else {
                // any other key terminates the grab
                // if this happens before a selection was made,
                // the grab will be of the entire (virtual) desktop
                accept();
            }
            break;
        }
        case QEvent::MouseButtonPress: {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*> (event);

            if (mouseEvent->button() != Qt::LeftButton)
                reject();

            selStartPoint = mouseEvent->pos();
            selectRect = QRect(selStartPoint, QSize());
            break;
        }
        default:
            break;
    }

    return QDialog::event(event);
}

void ScreenCapture::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);  // suppress unused variable warning
    QPainter painter(this);

    if (!palBackground)
      painter.drawPixmap(QPoint(0, 0), desktopPixmapBkg);

    drawRectSelection(painter);
}

void ScreenCapture::mouseMoveEvent(QMouseEvent *event)
{
    QMouseEvent *mouseEvent = static_cast<QMouseEvent*> (event);
    selectRect = QRect(selStartPoint, mouseEvent->pos()).normalized();
    selEndPoint  = mouseEvent->pos();
    update();
}



void ScreenCapture::drawBackGround()
{
    // create painter on  pixelmap of desktop
    QPainter painter(&desktopPixmapBkg);

    // set painter brush on 85% transparency
    painter.setBrush(QBrush(QColor(0, 0, 0, 85), Qt::SolidPattern));

    // draw rect of desktop size in painter
    painter.drawRect(QApplication::desktop()->rect());

    QRect txtRect = QApplication::desktop()->screenGeometry(QApplication::desktop()->primaryScreen());
    QString txtTip = QApplication::tr("Use your mouse to draw a rectangle to screenshot or exit pressing\nany key or using the right or middle mouse buttons.");

    txtRect.setHeight(qRound(txtRect.height() / 10.f)); // rounded val of text rect height

    painter.setPen(QPen(Qt::red)); // ste message rect border color
    painter.setBrush(QBrush(QColor(255, 255, 255, 180), Qt::SolidPattern));
    QRect txtBgRect = painter.boundingRect(txtRect, Qt::AlignCenter, txtTip);

    // set height & width of bkg rect
    txtBgRect.setX(txtBgRect.x() - 6);
    txtBgRect.setY(txtBgRect.y() - 4);
    txtBgRect.setWidth(txtBgRect.width() + 12);
    txtBgRect.setHeight(txtBgRect.height() + 8);

    painter.drawRect(txtBgRect);

      // Draw the text
    painter.setPen(QPen(Qt::black)); // black color pen
    painter.drawText(txtBgRect, Qt::AlignCenter, txtTip);

    palBackground = (qApp->desktop()->numScreens() > 1);

    // set bkg to pallette widget
    if (palBackground)
    {
        QPalette newPalette = palette();
        newPalette.setBrush(QPalette::Window, QBrush(desktopPixmapBkg));
        setPalette(newPalette);
    }
}

void ScreenCapture::drawRectSelection(QPainter &painter)
{
    painter.drawPixmap(selectRect, desktopPixmapClr, selectRect);
    painter.setPen(QPen(QBrush(QColor(0, 0, 0, 255)), 2));
    painter.drawRect(selectRect);

    QString txtSize = QApplication::tr("%1 x %2 pixels ").arg(selectRect.width()).arg(selectRect.height());
    painter.drawText(selectRect, Qt::AlignBottom | Qt::AlignRight, txtSize);

    /* This does a zoom box around the selection.
    if (!selEndPoint.isNull() ) // && conf->getZoomAroundMouse() == true)
    {
        const quint8 zoomSide = 200;

        // create magnifer coords
        QPoint zoomStart = selEndPoint;
        zoomStart -= QPoint(zoomSide/5, zoomSide/5); // 40, 40

        QPoint zoomEnd = selEndPoint;
        zoomEnd += QPoint(zoomSide/5, zoomSide/5);

        // creating rect area for magnifer
        QRect zoomRect = QRect(zoomStart, zoomEnd);

        QPixmap zoomPixmap = desktopPixmapClr.copy(zoomRect).scaled(QSize(zoomSide, zoomSide), Qt::KeepAspectRatio);

        QPainter zoomPainer(&zoomPixmap); // create painter from pixmap maignifer
        zoomPainer.setPen(QPen(QBrush(QColor(255, 0, 0, 180)), 2));
        zoomPainer.drawRect(zoomPixmap.rect()); // draw
        zoomPainer.drawText(zoomPixmap.rect().center() - QPoint(4, -4), "+");

        // position for drawing preview
        QPoint zoomCenter = selectRect.bottomRight();

        if (zoomCenter.x() + zoomSide > desktopPixmapClr.rect().width() || zoomCenter.y() + zoomSide > desktopPixmapClr.rect().height())
        {
            zoomCenter -= QPoint(zoomSide, zoomSide);
        }
        painter.drawPixmap(zoomCenter, zoomPixmap);
    }
    */
}

QPixmap ScreenCapture::getSelection()
{
    QPixmap sel;
    QRect selected = selectRect;
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    // make sure we take the respective origins of the (virtual) desktop "window"
    // and the fullscreen (ScreenCapture) window into account:
    QPoint offset = desktopOrigin;
    offset -= scOrigin;
    offset *= -1;
    selected.translate(offset);
#endif
    sel = desktopPixmapClr.copy(selected);
    return sel;
}

