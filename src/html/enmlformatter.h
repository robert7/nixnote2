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




class EnmlFormatter : public QObject
{
    Q_OBJECT
private:
    QByteArray content;
    bool isAttributeValid(QString attribute);
    bool isElementValid(QWebElement e);
    // void scanTags(QWebElement &element);
    void fixImgNode(QWebElement &element);
    //void fixEnCryptNode(QWebElement &element);
    void fixInputNode(QWebElement &element);
    QStringList findAllTags(QWebElement &element);
    void removeInvalidAttributes(QWebElement &node);
    void fixANode(QWebElement e);
    void fixObjectNode(QWebElement &e);
    void fixSpanNode(QWebElement &e);
    void fixDivNode(QWebElement &e);
    void fixPreNode(QWebElement &e);
    void removeInvalidUnicode();
    QByteArray fixEncryptionTags(QByteArray newContent);

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
    QStringList li;
    QStringList map;
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

public:
    QList<qint32> resources;

    explicit EnmlFormatter(QString html);
    QString getContent() const;
    QByteArray getContentBytes() const;

    void removeHtmlHeader();
    void rebuildNoteEnml();
    void tidyHtml(HtmlCleanupMode mode);
    bool isFormattingError() const;
    void setContent(QString &content);
};


#endif // ENMLFORMATTER_H
