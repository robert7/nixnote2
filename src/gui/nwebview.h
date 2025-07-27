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

#ifndef NWEBVIEW_H
#define NWEBVIEW_H

#include <QWebEngineView>
#include "src/gui/nwebpage.h"
#include <QShortcut>
#include <QMenu>
#include <QNetworkRequest>
#include <QAction>
#include <QSignalMapper>

#include "src/gui/nbrowserwindow.h"
#include "src/gui/browserWidgets/ntitleeditor.h"

class NBrowserWindow;

//****************************************************
//* This inherits everything from QWebView.  It is
//* useful to allow us to setup things that are
//* needed to view & edit notes.
//****************************************************
class NWebView : public QWebEngineView
{
    Q_OBJECT
private:
    QAction *setupColorMenuOption(QString color);
    QSignalMapper *backgroundColorMapper;
    QMenu *todoMenu;
    QMenu *colorMenu;
    QAction *backgroundColor;

public:
    explicit NWebView(NBrowserWindow *parent = 0);
    ~NWebView();
    NBrowserWindow *parent;
    NTitleEditor *titleEditor;
    QString pasteSequence;
    QString pasteUnformattedSequence;
    QString fileSaveSequence;
    QMenu *contextMenu;
    QMenu *tableMenu;
    QMenu *imageMenu;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    //QAction *removeFormattingAction;
    QAction *htmlTidyAction;
    QAction *htmlSimplifyAction;
    QAction *insertDateTimeAction;
    QAction *pasteWithoutFormatAction;
    QAction *todoAction;
    QAction *todoSelectAllAction;
    QAction *todoUnselectAllAction;
    QAction *encryptAction;
    QAction *downloadAttachmentAction();
    QAction *downloadImageAction();
    QAction *rotateImageRightAction;
    QAction *rotateImageLeftAction;
    QAction *insertLinkAction;
    QAction *removeLinkAction;
    QAction *insertLatexAction;
    QAction *attachFileAction;
    QAction *insertTableAction;
    QAction *insertTableRowAction;
    QAction *tablePropertiesAction;
    QAction *insertTableColumnAction;
    QAction *deleteTableColumnAction;
    QAction *deleteTableRowAction;
    QAction *openAction;
    QAction *insertQuickLinkAction;
    QAction *insertHtmlEntitiesAction;
    QAction *copyInAppNoteLinkAction;

    QAction *fontColorAction;
    QAction *fontBackgroundColorAction;


    QShortcut *attachFileShortcut;

    bool isDirty;
    NWebPage *editorPage;
    bool event(QEvent *event);
    void keyPressEvent(QKeyEvent *);
    void downloadAttachment(QNetworkRequest *req);
    void focusLostNotify(QString text);
    void setContent(const QByteArray &data);

signals:
    void noteChanged();
    void downloadAttachmentRequested(QNetworkRequest*);
    void htmlEditAlert();
    void escapeKeyPressed();

public slots:
    void editAlert();
    void decryptText(QString id, QString text, QString hint);
    void contextMenuEvent(QContextMenuEvent *event);
    void setBackgroundColor(QString color);
    void printNodeName(QString s);
    void setTitleEditor(NTitleEditor *editor);
    void focusOutEvent(QFocusEvent *e);

private slots:
    void exposeToJavascript();
    void setDefaultTitle();
    void downloadRequested(QNetworkRequest);
    void dropEvent(QDropEvent *e);


};

#endif // NWEBVIEW_H
