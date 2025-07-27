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


#include "nwebview.h"
#include "nwebpage.h"
#include "src/global.h"
#include <QMessageBox>
#include <QtWebEngine>
#include <QFileDialog>
#include "src/settings/colorsettings.h"

//#include "./libencrypt/encrypt_global.h"
//#include "./libencrypt/encrypt.h"
#include "../dialog/endecryptdialog.h"
#include "src/sql/resourcetable.h"

extern Global global;


//****************************************************
//* This inherits everything from QWebEngineView.  It is
//* useful to allow us to setup things that are
//* needed to view & edit notes.
//****************************************************

// Override the constructor so we always use a NWebPage
// rather than a QWebEnginePage
NWebView::NWebView(NBrowserWindow *parent) :
    QWebEngineView(parent)
{
    this->parent = parent;
    editorPage = new NWebPage(this);
    setPage(editorPage);
    isDirty = false;
    this->setFont(global.getGuiFont(font()));

    contextMenu = new QMenu(this);

    openAction = new QAction(tr("Open"), this);
    contextMenu->addAction(openAction);
    contextMenu->addSeparator();
    contextMenu->setFont(global.getGuiFont(font()));

    cutAction = new QAction(tr("Cut"), this);
    global.setupShortcut(cutAction, "Edit_Cut");
    contextMenu->addAction(cutAction);
    connect(cutAction, SIGNAL(triggered()), parent, SLOT(cutButtonPressed()));

    copyAction = new QAction(tr("Copy"), this);
    global.setupShortcut(copyAction, "Edit_Copy");
    contextMenu->addAction(copyAction);
    connect(copyAction, SIGNAL(triggered()), parent, SLOT(copyButtonPressed()));

    pasteAction = new QAction(tr("Paste"), this);
    global.setupShortcut(pasteAction, "Edit_Paste");
    contextMenu->addAction(pasteAction);
    connect(pasteAction, SIGNAL(triggered()), parent, SLOT(pasteButtonPressed()));

    pasteWithoutFormatAction = new QAction(tr("Paste as Unformatted Text"), this);
    global.setupShortcut(pasteWithoutFormatAction, "Edit_Paste_Without_Formatting");
    contextMenu->addAction(pasteWithoutFormatAction);
    connect(pasteWithoutFormatAction, SIGNAL(triggered()), parent, SLOT(pasteWithoutFormatButtonPressed()));

    copyInAppNoteLinkAction = new QAction(tr("Copy In-App Note Link"), this);
    global.setupShortcut(copyInAppNoteLinkAction, "Edit_Copy_Note_Url");
    contextMenu->addAction(copyInAppNoteLinkAction);
    connect(copyInAppNoteLinkAction, SIGNAL(triggered()), parent, SLOT(copyInAppNoteLink()));

    contextMenu->addSeparator();

    htmlSimplifyAction = new QAction(tr("Simplify formatting"), this);
    global.setupShortcut(htmlSimplifyAction, "Edit_HTML_Simplify");
    contextMenu->addAction(htmlSimplifyAction);
    connect(htmlSimplifyAction, SIGNAL(triggered()), parent, SLOT(htmlSimplify()));

    contextMenu->addSeparator();

    // change background color of WHOLE note (this is different from changing font/text background color)
    colorMenu = new QMenu(tr("Note Background Color"), this);
    colorMenu->setFont(global.getGuiFont(font()));
    // Build the background color menu
    backgroundColorMapper = new QSignalMapper(this);
    QAction *action;
    ColorSettings colorSettings;
    QList< QPair<QString,QString> > colorList = colorSettings.colorList();
    for (int i=0; i<colorList.size(); i++) {
        action = colorMenu->addAction(colorList[i].first);
        backgroundColorMapper->setMapping(action, colorList[i].second);
        connect(action, SIGNAL(triggered()), backgroundColorMapper, SLOT(map()));
        connect(backgroundColorMapper, SIGNAL(mapped(QString)), this, SLOT(setBackgroundColor(QString)));
    }
    // QAction *action = setupColorMenuOption(tr("White"));

    fontColorAction = new QAction(tr("Set text color"), this);
    global.setupShortcut(fontColorAction, "Format_Font_Color");
    contextMenu->addAction(fontColorAction);
    connect(fontColorAction, SIGNAL(triggered()), parent, SLOT(fontColorClicked()));

    fontBackgroundColorAction = new QAction(tr("Set text background color"), this);
    global.setupShortcut(fontBackgroundColorAction, "Format_Highlight");
    contextMenu->addAction(fontBackgroundColorAction);
    connect(fontBackgroundColorAction, SIGNAL(triggered()), parent, SLOT(fontHighlightClicked()));

    contextMenu->addMenu(colorMenu);
    contextMenu->addSeparator();

    todoMenu = new QMenu(tr("To-do"), this);
    todoMenu->setFont(global.getGuiFont(font()));
    contextMenu->addMenu(todoMenu);
    todoAction = new QAction(tr("To-do"), this);
    global.setupShortcut(todoAction, "Edit_Insert_Todo");
    todoMenu->addAction(todoAction);
    connect(todoAction, SIGNAL(triggered()), parent, SLOT(todoButtonPressed()));
    todoMenu->addSeparator();

    todoSelectAllAction = new QAction(tr("Select All"), this);
    todoMenu->addAction(todoSelectAllAction);
    connect(todoSelectAllAction, SIGNAL(triggered()),
            parent, SLOT(todoSelectAll()));

    todoUnselectAllAction = new QAction(tr("Unselect All"), this);
    todoMenu->addAction(todoUnselectAllAction);
    connect(todoUnselectAllAction, SIGNAL(triggered()),
            parent, SLOT(todoUnselectAll()));

    contextMenu->addSeparator();

    insertHtmlEntitiesAction = new QAction(tr("HTML Entities"),this);
    contextMenu->addAction(insertHtmlEntitiesAction);
    global.setupShortcut(insertHtmlEntitiesAction, "Edit_Insert_Html_Entities");
    connect(insertHtmlEntitiesAction, SIGNAL(triggered()), parent, SLOT(insertHtmlEntities()));

    contextMenu->addSeparator();

    encryptAction = new QAction(tr("Encrypt Selected Text"), this);
    contextMenu->addAction(encryptAction);
    global.setupShortcut(encryptAction, "Edit_Encrypt_Text");
    connect(encryptAction, SIGNAL(triggered()), parent, SLOT(encryptButtonPressed()));

    insertDateTimeAction = new QAction(tr("Insert Date Time"), this);
    global.setupShortcut(insertDateTimeAction, "Insert_DateTime");
    contextMenu->addAction(insertDateTimeAction);
    connect(insertDateTimeAction, SIGNAL(triggered()), parent, SLOT(insertDatetime()));  // => nbrowserwindow.cpp

    insertLinkAction = new QAction(tr("Insert Hyperlink"), this);
    contextMenu->addAction(insertLinkAction);
    global.setupShortcut(insertLinkAction, "Edit_Insert_Hyperlink");
    connect(insertLinkAction, SIGNAL(triggered()),parent, SLOT(insertLinkButtonPressed()));

    insertQuickLinkAction = new QAction(tr("Quick Link"), this);
    contextMenu->addAction(insertQuickLinkAction);
    global.setupShortcut(insertQuickLinkAction, "Edit_Insert_QuickLink");
    connect(insertQuickLinkAction, SIGNAL(triggered()),parent, SLOT(insertQuickLinkButtonPressed()));

    removeLinkAction = new QAction(tr("Remove Hyperlink"), this);
    contextMenu->addAction(removeLinkAction);
    global.setupShortcut(removeLinkAction, "Edit_Remove_Hyperlink");
    connect(removeLinkAction, SIGNAL(triggered()),parent, SLOT(removeLinkButtonPressed()));

    attachFileAction = new QAction(tr("Attach File"), this);
    contextMenu->addAction(attachFileAction);
    global.setupShortcut(attachFileAction, "Edit_Attach_File");
    connect(attachFileAction, SIGNAL(triggered()),parent, SLOT(attachFile()));
    contextMenu->addSeparator();

    insertLatexAction = new QAction(tr("Insert LaTeX Formula"), this);
    contextMenu->addAction(insertLatexAction);
    global.setupShortcut(insertLatexAction, "Edit_Insert_Latex");
    connect(insertLatexAction, SIGNAL(triggered()),parent, SLOT(insertLatexButtonPressed()));
    contextMenu->addSeparator();

    tableMenu = new QMenu(tr("Table"), this);
    tableMenu->setFont(global.getGuiFont(font()));
    contextMenu->addMenu(tableMenu);
    insertTableAction = new QAction(tr("Insert Table"), this);
    global.setupShortcut(insertTableAction, "Edit_Insert_Table");
    tableMenu->addAction(insertTableAction);
    connect(insertTableAction, SIGNAL(triggered()), parent, SLOT(insertTableButtonPressed()));
    tableMenu->addSeparator();

    insertTableRowAction = new QAction(tr("Insert Row"), this);
    global.setupShortcut(insertTableRowAction, "Edit_Insert_Table_Row");
    tableMenu->addAction(insertTableRowAction);
    connect(insertTableRowAction, SIGNAL(triggered()), parent, SLOT(insertTableRowButtonPressed()));

    insertTableColumnAction = new QAction(tr("Insert Column"), this);
    global.setupShortcut(insertTableColumnAction, "Edit_Insert_Table_Column");
    tableMenu->addAction(insertTableColumnAction);
    connect(insertTableColumnAction, SIGNAL(triggered()), parent, SLOT(insertTableColumnButtonPressed()));

    tableMenu->addSeparator();

    deleteTableRowAction = new QAction(tr("Delete Row"), this);
    tableMenu->addAction(deleteTableRowAction);
    global.setupShortcut(deleteTableRowAction, "Edit_Delete_Table_Row");
    connect(deleteTableRowAction, SIGNAL(triggered()), parent, SLOT(deleteTableRowButtonPressed()));
    deleteTableColumnAction = new QAction(tr("Delete Column"), this);
    tableMenu->addAction(deleteTableColumnAction);
    global.setupShortcut(deleteTableColumnAction, "Edit_Delete_Table_Column");
    connect(deleteTableColumnAction, SIGNAL(triggered()), parent, SLOT(deleteTableColumnButtonPressed()));

    tableMenu->addSeparator();

    tablePropertiesAction = new QAction(tr("Table Properties"), this);
    global.setupShortcut(tablePropertiesAction, "Edit_Table_Properties");
    tableMenu->addAction(tablePropertiesAction);
    connect(tablePropertiesAction, SIGNAL(triggered()), parent, SLOT(tablePropertiesButtonPressed()));

    contextMenu->addSeparator();

    imageMenu = new QMenu(tr("Image"), this);
    imageMenu->setFont(global.getGuiFont(font()));
    contextMenu->addMenu(imageMenu);
    downloadImageAction()->setText(tr("Save Image"));
    imageMenu->addAction(downloadImageAction());
    // Don't connect this signal.  The download attachmen signal will handle it.  Otherwise
    // the signal fires twice.
    //connect(editorPage, SIGNAL(downloadRequested(QNetworkRequest)), this, SLOT(downloadRequested(QNetworkRequest)));

    imageMenu->addSeparator();

    rotateImageLeftAction = new QAction(tr("Rotate Left"), this);
    imageMenu->addAction(rotateImageLeftAction);
    global.setupShortcut(rotateImageLeftAction, "Edit_Image_Rotate_Left");
    connect(rotateImageLeftAction, SIGNAL(triggered()), parent, SLOT(rotateImageLeftButtonPressed()));
    rotateImageRightAction = new QAction(tr("Rotate Right"), this);
    global.setupShortcut(rotateImageRightAction, "Edit_Image_Rotate_Right");
    imageMenu->addAction(rotateImageRightAction);
    connect(rotateImageRightAction, SIGNAL(triggered()), parent, SLOT(rotateImageRightButtonPressed()));
    contextMenu->addSeparator();

    downloadAttachmentAction()->setText(tr("Save Attachment"));
    contextMenu->addAction(downloadAttachmentAction());
    connect(editorPage, SIGNAL(downloadRequested(QNetworkRequest)), this, SLOT(downloadRequested(QNetworkRequest)));

    connect(editorPage, SIGNAL(contentsChanged()), this, SLOT(editAlert()));
    editorPage->runJavaScript("document.documentElement.contentEditable = true");

    // Set some of the menus as disabled until a user selects an image or attachment
    downloadAttachmentAction()->setEnabled(false);
    rotateImageRightAction->setEnabled(false);
    rotateImageLeftAction->setEnabled(false);
    openAction->setEnabled(false);
    downloadImageAction()->setEnabled(false);

    connect(this->page(), SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(exposeToJavascript()));

    //    this->setStyleSheet("QWebEngineView,html,body { background-color : red; foreground-color : white; }");
    // ////////////////
    //    QString qss = global.fileManager.getQssDirPathUser("");
    //    if (qss == "")
    //        qss = global.fileManager.getQssDirPath("");
    //    this->settings()->setUserStyleSheetUrl(QUrl("file://"+qss+"editor.css"));

    // style apply: see Global::getEditorCss
    // then NBrowserWindow::setEditorStyle()

    this->pasteSequence = QKeySequence(this->pasteAction->shortcut()).toString().toLower();
    if (pasteSequence.trimmed() == "")
        pasteSequence = "ctrl+v";
    pasteUnformattedSequence = QKeySequence(pasteWithoutFormatAction->shortcut()).toString().toLower();
    if (pasteUnformattedSequence.trimmed() == "")
        pasteUnformattedSequence = "ctrl+shift+v";
    fileSaveSequence = "ctrl+s";

    QString css = global.getThemeCss("noteContentsCss");
    if (css!="")
        this->setStyleSheet(css);

    backgroundColor = nullptr;
}


NWebView::~NWebView() {
    delete editorPage;
    delete contextMenu;
    delete backgroundColorMapper;
    delete tableMenu;
    delete imageMenu;

    delete openAction;
    delete cutAction;
    delete copyAction;
    delete pasteAction;
    delete pasteWithoutFormatAction;
    delete copyInAppNoteLinkAction;
    delete htmlSimplifyAction;
    delete fontColorAction;

    delete fontBackgroundColorAction;
    delete todoAction;
    delete todoSelectAllAction;
    delete todoUnselectAllAction;
    delete insertHtmlEntitiesAction;
    delete encryptAction;
    delete insertDateTimeAction;
    delete insertLinkAction;

    delete insertQuickLinkAction;
    delete removeLinkAction;
    delete attachFileAction;
    delete insertLatexAction;
    delete insertTableAction;
    delete insertTableRowAction;
    delete insertTableColumnAction;
    delete deleteTableRowAction;
    delete deleteTableColumnAction;
    delete tablePropertiesAction;
    delete rotateImageLeftAction;
    delete rotateImageRightAction;
}


QAction *NWebView::downloadAttachmentAction() {
    return pageAction(QWebEnginePage::DownloadLinkToDisk);
}


QAction *NWebView::downloadImageAction() {
    return pageAction(QWebEnginePage::DownloadImageToDisk);
}

QAction* NWebView::setupColorMenuOption(QString color) {
    if (backgroundColor != nullptr) {
        backgroundColor = new QAction(color, this);
    }
    color = color.replace(" ", "");
    //connect(backgroundColor, SIGNAL(triggered()), this, SLOT()
    return backgroundColor;
}


void NWebView::focusOutEvent(QFocusEvent *e) {
    QWebEngineView::focusOutEvent(e);
    titleEditor->checkNoteTitleChange();
}

void NWebView::editAlert() {

    // If this is the first time the note is dirty, set the dirty
    // flag (this is checked elsewhere) and signal the change
    if (!isDirty) {
        isDirty = true;
        emit(noteChanged());
    }
    emit (htmlEditAlert());

    // This should already be set, but just in case...
    isDirty = true;
}


void NWebView::exposeToJavascript() {
    page()->addToJavaScriptWindowObject("editorWindow", this);
}



void NWebView::decryptText(QString id, QString text, QString hint) {
    /* Suppress unused */
    Q_UNUSED(id);
    Q_UNUSED(text);
    Q_UNUSED(hint);


//    EnCrypt crypt;
//    QString plainText;
/*
//    // First, try to decrypt with any keys we already have
    for (int i=0; i<global.passwordRemember.size(); i++) {
        QString key = global.passwordRemember[i].second;
        bool retVal = crypt.decrypt(text, plainText, key);
        if (retVal && plainText != "") {
            //slot = new String(Long.toString(l));
            //Global.passwordSafe.put(slot, Global.passwordRemember.get(i));
            //removeEncryption(id, plainText, false, slot);
            return;
        }
    }


    EnDecryptDialog dialog;
    dialog.hint.setText(hint);
    bool goodReturn = true;
    while (goodReturn && (plainText == "" || !dialog.okPressed)) {
        dialog.exec();
        if (!dialog.okPressed) {
            return;
        }
        QString pswd = dialog.password.text().trimmed();
        crypt.decrypt(text, plainText, pswd);
        if (plainText == "") {
            QMessageBox mb;
            mb.warning(this, tr("Incorrect Password"), tr("The password entered is not correct"));
        }
    }
//    Pair<String,String> passwordPair = new Pair<String,String>();
//    passwordPair.setFirst(dialog.getPassword());
//    passwordPair.setSecond(dialog.getHint());
//    Global.passwordSafe.put(slot, passwordPair);
//    removeEncryption(id, plainText, dialog.permanentlyDecrypt(), slot);
//    if (dialog.rememberPassword()) {
//        Pair<String, String> pair = new Pair<String,String>();
//        pair.setFirst(dialog.getPassword());
//        pair.setSecond(dialog.getHint());
//        Global.passwordRemember.add(pair);
//    }
*/
}



void NWebView::contextMenuEvent(QContextMenuEvent *event) {
    if (event != nullptr)
        contextMenu->exec(event->globalPos());
    downloadAttachmentAction()->setEnabled(false);
    rotateImageRightAction->setEnabled(false);
    rotateImageLeftAction->setEnabled(false);
    openAction->setEnabled(false);
    downloadImageAction()->setEnabled(false);}


bool NWebView::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *ke = (QKeyEvent*)event;
        if (ke->key() == Qt::Key_Tab) {
            parent->tabPressed();
            ke->accept();
            return true;
        }
        if (ke->key() == Qt::Key_Backtab) {
            parent->backtabPressed();
            ke->accept();
            return true;
        }
        if (ke->key() == Qt::Key_Enter || ke->key() == Qt::Key_Return) {
            bool retval = parent->enterPressed();
            if (retval) {
                ke->accept();
                return true;
            }
        }

    }
    if (event->type() == QEvent::MouseButtonDblClick) {
        QLOG_DEBUG() << "NWebView::event: DOUBLE CLICK!!!";
    }
    return QWebEngineView::event(event);
}



void NWebView::keyPressEvent(QKeyEvent *e) {
    // This is done because if we set the content as editable, the scroll keys are
    // ignored by wbkit.
    if (e->key() == Qt::Key_PageUp || e->key() == Qt::Key_PageDown) {
        int bottom = this->page()->geometry().bottom();
        int top = this->page()->geometry().top();
        int scrollValue = top-bottom;
        if (e->key() == Qt::Key_PageDown)
            scrollValue = -1*scrollValue;
        page()->scroll(0,scrollValue);
    }

    // Exit presentation mode
    if (e->key() == Qt::Key_Escape) {
        emit escapeKeyPressed();

        // Return without going forward or the current selected text is removed
        return;
    }

    // Hard override of paste because I can't seem to get it any other way.
//    if (e->key() == Qt::Key_V && e->modifiers().testFlag(Qt::ControlModifier)) {
    QKeySequence ks(e->modifiers()|e->key());
    if (ks.toString().toLower() == pasteSequence) {
        parent->pasteButtonPressed();
        e->accept();
        return;
    }
    if (ks.toString().toLower() == pasteUnformattedSequence) {
        parent->pasteWithoutFormatButtonPressed();
        e->accept();
        return;
    }
    if (ks.toString().toLower() == fileSaveSequence) {
        parent->saveNoteContent();
        e->accept();
        return;
    }

    QWebEngineView::keyPressEvent(e);
}




void NWebView::downloadAttachment(QNetworkRequest *req) {
    QLOG_DEBUG() << req->url().toString();
    emit(downloadAttachmentRequested(req));
}



void NWebView::setBackgroundColor(QString color) { parent->setBackgroundColor(color); }

void NWebView::printNodeName(QString s) {
    QLOG_DEBUG() << s;
}


void NWebView::setTitleEditor(NTitleEditor *editor) {
    titleEditor = editor;
    if (editor == nullptr)
        return;
    connect(page(), SIGNAL(contentsChanged()), this, SLOT(setDefaultTitle()));
}


void NWebView::setDefaultTitle() {
    QString body = this->page()->toPlainText();
    titleEditor->setTitleFromContent(body);
}

void NWebView::downloadRequested(QNetworkRequest req) {
    QString urlString = req.url().toString();

    if (urlString == "")  {
        return;
    }

    if (urlString.startsWith("nnres:")) {
        int pos = urlString.indexOf(global.attachmentNameDelimeter);
        QString extension = "";
        if (pos != -1) {
            extension = urlString.mid(pos+global.attachmentNameDelimeter.length());
            urlString = urlString.mid(0,pos);
        }
        urlString = urlString.mid(6);
        if (urlString.lastIndexOf("/") > 0)
        	urlString = urlString.mid(urlString.lastIndexOf("/")+1);
        if (urlString.indexOf(".")>0)
        	urlString = urlString.mid(0,urlString.indexOf("."));

        qint32 lid = urlString.toInt();
        ResourceTable resTable(global.db);
        Resource r;
        resTable.get(r, lid, true);
        QString filename;
        ResourceAttributes attributes;
        if (r.attributes.isSet())
            attributes = r.attributes;
        if (attributes.fileName.isSet())
            filename = attributes.fileName;
        else
            filename = urlString + QString(".") + extension;

        QFileDialog fd;
        fd.setFileMode(QFileDialog::AnyFile);
        fd.setWindowTitle(tr("Save File"));
        fd.setAcceptMode(QFileDialog::AcceptSave);
        fd.selectFile(filename);
        fd.setConfirmOverwrite(true);
        if (fd.exec()) {
            if (fd.selectedFiles().size() == 0)
                return;
            filename = fd.selectedFiles()[0];
            QFile newFile(filename);
            newFile.open(QIODevice::WriteOnly);
            Data d;
            if (r.data.isSet())
                d = r.data;
            QByteArray body;
            if (d.body.isSet())
                body = d.body;
            int size = 0;
            if (d.size.isSet())
                size = d.size;
            newFile.write(body, size);
            newFile.close();
            return;
        }
    }
    if (urlString.startsWith("file:///")) {
        if (!req.url().isValid())
            return;
        urlString = urlString.mid(8);
        QFileDialog fd;
        fd.setFileMode(QFileDialog::AnyFile);
        fd.setWindowTitle(tr("Save File"));
        fd.setAcceptMode(QFileDialog::AcceptSave);
        QString oldname = urlString;
        fd.selectFile(urlString.replace(global.fileManager.getDbaDirPath(), ""));
        fd.setConfirmOverwrite(true);
        if (fd.exec()) {
            if (fd.selectedFiles().size() == 0)
                return;
            QString newname = fd.selectedFiles()[0];
            QFile::remove(urlString);
            QFile::copy(oldname, newname);
            return;
        }

    }
}



void NWebView::dropEvent(QDropEvent *e) {
        setFocus();
        const QMimeData *mime = e->mimeData();
        parent->handleUrls(mime);
        parent->contentChanged();
}


void NWebView::setContent(const QByteArray &data) {
    // Qt Webview memory leaks solution:
    // https://forum.qt.io/topic/10832/memory-size-increases-per-page-load/4
    QByteArray content = data;
    content.replace("<body", "<body onunload=_function() {} ");
    QWebEngineView::setContent(content);

    QWebSettings::clearMemoryCaches();
    this->history()->clear();
}
