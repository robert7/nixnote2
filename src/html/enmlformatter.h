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


#ifndef ENMLFORMATTER_H
#define ENMLFORMATTER_H

#include <QObject>
#include <QtWebKit>
#include <QObject>
#include <QTemporaryFile>
#include <QThread>
#include <QString>
#include <QMap>
#include <QHash>
#include <QVector>
#include <QtXml>

using namespace std;

enum HtmlCleanupMode {
    Tidy = 0,
    Simplify = 1
};

#define DEFAULT_HTML_HEAD "<head>" \
                          "<meta http-equiv=\"content-type\" content=\"text-html; charset=utf-8\">" \
                          "<style>img { height:auto; width:auto; max-height:auto; max-width:100%; }</style>" \
                          "</head>"
#define DEFAULT_HTML_TYPE "<!DOCTYPE html><html xmlns=\"http://www.w3.org/1999/xhtml\">"


#define HTML_COMMENT_START "<!-- "
#define HTML_COMMENT_END " -->"
#define HTML_TEMP_TABLE_CLASS "en-crypt-temp"


class EnmlFormatter : public QObject
{
    Q_OBJECT
private:
    QByteArray content;

    bool isAttributeValid(QString attribute);
    bool checkAndFixElement(QWebElement &e);
    void fixImgNode(QWebElement &element);
    void fixTableNode(QWebElement &e);
    void fixInputNode(QWebElement &e);
    void removeInvalidAttributes(QWebElement &e);
    void fixANode(QWebElement &e);
    void fixObjectNode(QWebElement &e);
    void removeInvalidUnicode();
    //QByteArray fixEncryptionTags(QByteArray newContent);

    QStringList coreattrs;
    QStringList i18n;
    QStringList focus;
    QStringList attrs;
    QStringList textAlign;
    QStringList cellHalign;
    QStringList cellValign;
    QStringList a;
    QStringList area;
    QStringList bdo;
    QStringList blockQuote;
    QStringList br;
    QStringList caption;
    QStringList col;
    QStringList colGroup;
    QStringList del;
    QStringList dl;
    QStringList font;
    QStringList hr;
    QStringList img;
    QStringList ins;
    QStringList input;
    QStringList li;
    QStringList map;
    QStringList object;
    QStringList ol;
    QStringList pre;
    QStringList q;
    QStringList table;
    QStringList td;
    QStringList th;
    QStringList tr_;
    QStringList ul;
    bool formattingError;
    void checkAttributes(QWebElement &element, QStringList valid);
    QList<qint32> resources;
    bool guiAvailable;
    QHash< QString, QPair <QString, QString> > passwordSafe;
    QString cryptoJarPath;
    void recursiveTreeCleanup(QWebElement &elementRoot, int level);

public:
    explicit EnmlFormatter(QString html, bool guiAvailable, QHash< QString, QPair <QString, QString> > passwordSafe, QString cryptoJarPath);

    QList<qint32> getResources() const { return resources; }
    QString getContent() const;
    QByteArray getContentBytes() const;

    void removeHtmlHeader();
    void rebuildNoteEnml();
    void tidyHtml(HtmlCleanupMode mode);
    bool isFormattingError() const;
    void setContent(QString &content);
    void removeHtmlCommentsInclContent();
};


#endif // ENMLFORMATTER_H
