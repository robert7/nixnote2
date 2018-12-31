/*********************************************************************************
  NixNote - An open-source client for the Evernote service.
  Copyright (C) 2018 Robert Spiegel

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

#ifndef NOTEFORMATTERBASE_H
#define NOTEFORMATTERBASE_H

#include <QtWebKit>
#include <QWebPage>
#include <QWebFrame>
#include <QObject>
#include <QTemporaryFile>
#include <QThread>
#include <QString>
#include <QMap>
#include <QHash>
#include <QVector>
#include <QtXml>

using namespace std;

class NoteFormatterBase : public QObject {
Q_OBJECT
private:
public:
    explicit NoteFormatterBase(QObject *parent = 0);

};

#endif // NOTEFORMATTERBASE_H
