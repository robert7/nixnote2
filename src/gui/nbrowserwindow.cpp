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

#include "nbrowserwindow.h"
#include "src/nixnote.h"
#include "src/sql/notetable.h"
#include "src/sql/notebooktable.h"
#include "src/gui/browserWidgets/urleditor.h"
#include "src/sql/tagtable.h"
#include "src/html/noteformatter.h"
#include "src/html/enmlformatter.h"
#include "src/sql/usertable.h"
#include "src/sql/resourcetable.h"
#include "src/sql/linkednotebooktable.h"
#include "src/email/smtpclient.h"
#include "src/email/mimehtml.h"
#include "src/email/mimemessage.h"
#include "src/email/mimeinlinefile.h"
#include "src/global.h"
#include "src/gui/browserWidgets/colormenu.h"
#include "src/gui/plugins/pluginfactory.h"
#include "src/dialog/insertlinkdialog.h"
#include "src/html/thumbnailer.h"
#include "src/dialog/tabledialog.h"
#include "src/dialog/insertlatexdialog.h"
#include "src/dialog/endecryptdialog.h"
#include "src/dialog/encryptdialog.h"
#include "src/dialog/emaildialog.h"
#include "src/sql/configstore.h"
#include "src/utilities/encrypt.h"
#include "src/utilities/mimereference.h"
#include "src/html/attachmenticonbuilder.h"
#include "src/dialog/remindersetdialog.h"
#include "src/dialog/spellcheckdialog.h"
#include "src/utilities/pixelconverter.h"
#include "src/gui/browserWidgets/table/tablepropertiesdialog.h"
#include "src/exits/exitmanager.h"
#include "browserWidgets/editorbuttonbar.h"
#include "src/dialog/spellcheckdialog.h"
#include "src/utilities/NixnoteStringUtils.h"
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QAction>
#include <QMenu>
#include <QFileIconProvider>
#include <QFontDatabase>
#include <QDesktopServices>
#include <QMessageBox>
#include <QFileDialog>
#include <QClipboard>
#include <QBuffer>
#include <QDateTime>
#include <QPrintDialog>
#include <QPrinterInfo>
#include <QPrintPreviewDialog>
#include <QPaintEngine>
#include <iostream>
#include <istream>
#include <qcalendarwidget.h>
#include <qplaintextedit.h>

#if QT_VERSION < 0x050000

#include <QtScript/QScriptEngine>

#else

#include <QJSEngine>

#endif


#include <QUndoStack>
#include <QVector>


extern Global
        global;

NBrowserWindow::NBrowserWindow(QWidget *parent) :
        QWidget(parent) {
    // Setup a unique identifier for this editor instance.
    QUuid uuid;
    this->uuid = uuid.createUuid().toString().replace("{", "").replace("}", "");
    QLOG_DEBUG() << "Creating NBrowserWindow uuid: " << this->uuid;

    browserThread = new QThread();
    connect(browserThread, SIGNAL(started()), this, SLOT(browserThreadStarted()));
    browserRunner = new BrowserRunner(0);
    connect(this, SIGNAL(requestNoteContentUpdate(qint32, QString, bool)), browserRunner,
            SLOT(updateNoteContent(qint32, QString, bool)));
    browserThread->start();


    //    this->setStyleSheet("margins:0px;");
    line1Layout = new QHBoxLayout();

    // Setup the alarm button & display
    alarmText.setStyleSheet("QPushButton {background-color: transparent; border-radius: 0px;}");
    connect(alarmButton.setAction, SIGNAL(triggered()), this, SLOT(alarmSet()));
    connect(alarmButton.clearAction, SIGNAL(triggered()), this, SLOT(alarmClear()));
    connect(alarmButton.doneAction, SIGNAL(triggered()), this, SLOT(alarmCompleted()));
    connect(&alarmButton.menu, SIGNAL(aboutToShow()), this, SLOT(alarmMenuActivated()));

    // Setup line #1 of the window.  The text & notebook
    connect(&alarmText, SIGNAL(clicked()), this, SLOT(alarmCompleted()));
    layout.addLayout(line1Layout);
    line1Layout->addWidget(&noteTitle, 20);
    line1Layout->addWidget(&alarmText);
    line1Layout->addWidget(&alarmButton);
    line1Layout->addWidget(&notebookMenu, 4);
    line1Layout->addWidget(&expandButton);


    // Add the second layout display
    layout.addLayout(&line2Layout);
    line2Layout.addWidget(&urlEditor, 1);
    line2Layout.addWidget(&tagEditor, 3);

    // Add the third layout display
    layout.addLayout(&line3Layout);
    line3Layout.addWidget(&dateEditor);


    editor = new NWebView(this);
    editor->setTitleEditor(&noteTitle);
    setupToolBar();
    layout.addWidget(buttonBar);

    sourceEdit = nullptr;
    hammer = nullptr;
    spellChecker = nullptr;
    printPreviewPage = nullptr;
    printPage = nullptr;

    // add the actual note editor & source view
    editorSplitter = new QSplitter(Qt::Vertical, this);
    editorSplitter->addWidget(editor);
    layout.addWidget(editorSplitter);
    setLayout(&layout);
    layout.setMargin(0);

    findReplace = new FindReplace();
    layout.addWidget(findReplace);
    findReplace->setVisible(false);

    connect(findReplace->nextButton, SIGNAL(clicked()), this, SLOT(findNextInNote()));
    connect(findReplace->findLine, SIGNAL(returnPressed()), this, SLOT(findNextInNote()));
    connect(findReplace->prevButton, SIGNAL(clicked()), this, SLOT(findPrevInNote()));
    connect(findReplace->replaceButton, SIGNAL(clicked()), this, SLOT(findReplaceInNotePressed()));
    connect(findReplace->replaceAllButton, SIGNAL(clicked()), this, SLOT(findReplaceAllInNotePressed()));
    connect(findReplace->closeButton, SIGNAL(clicked()), this, SLOT(findReplaceWindowHidden()));


    // Setup shortcuts
    focusNoteShortcut = new QShortcut(this);
    global.setupShortcut(focusNoteShortcut, "Focus_Note");
    connect(focusNoteShortcut, SIGNAL(activated()), this, SLOT(focusNote()));

    focusTitleShortcut = new QShortcut(this);
    global.setupShortcut(focusTitleShortcut, "Focus_Title");
    connect(focusTitleShortcut, SIGNAL(activated()), this, SLOT(focusTitle()));

    insertDatetimeShortcut = new QShortcut(this);
    global.setupShortcut(insertDatetimeShortcut, "Insert_DateTime");
    connect(insertDatetimeShortcut, SIGNAL(activated()), this, SLOT(insertDatetime()));

    insertDateShortcut = new QShortcut(this);
    global.setupShortcut(insertDateShortcut, "Insert_Date");
    connect(insertDateShortcut, SIGNAL(activated()), this, SLOT(insertDate()));

    insertTimeShortcut = new QShortcut(this);
    global.setupShortcut(insertTimeShortcut, "Insert_Time");
    connect(insertTimeShortcut, SIGNAL(activated()), this, SLOT(insertTime()));

    fontColorShortcut = new QShortcut(this);
    global.setupShortcut(fontColorShortcut, "Format_Font_Color");
    connect(fontColorShortcut, SIGNAL(activated()), this, SLOT(fontColorClicked()));

    fontHighlightShortcut = new QShortcut(this);
    global.setupShortcut(fontHighlightShortcut, "Format_Highlight");
    connect(fontHighlightShortcut, SIGNAL(activated()), this, SLOT(fontHighlightClicked()));

    copyNoteUrlShortcut = new QShortcut(this);
    global.setupShortcut(copyNoteUrlShortcut, "Edit_Copy_Note_Url");
    connect(copyNoteUrlShortcut, SIGNAL(activated()), this, SLOT(copyInAppNoteLink()));

    // Setup the signals
    connect(&expandButton, SIGNAL(stateChanged(int)), this, SLOT(changeExpandState(int)));
    connect(&notebookMenu, SIGNAL(notebookChanged()), this, SLOT(sendNotebookUpdateSignal()));
    connect(&urlEditor, SIGNAL(textUpdated()), this, SLOT(sendUrlUpdateSignal()));
    connect(&noteTitle, SIGNAL(titleChanged()), this, SLOT(sendTitleUpdateSignal()));
    connect(&dateEditor.authorEditor, SIGNAL(textUpdated()), this, SLOT(sendAuthorUpdateSignal()));
    connect(&dateEditor.locationEditor, SIGNAL(clicked()), this, SLOT(sendLocationUpdateSignal()));
    connect(&dateEditor.createdDate, SIGNAL(editingFinished()), this, SLOT(sendDateCreatedUpdateSignal()));
    connect(&dateEditor.subjectDate, SIGNAL(editingFinished()), this, SLOT(sendDateSubjectUpdateSignal()));
    connect(&dateEditor, SIGNAL(valueChanged()), this, SLOT(sendDateUpdateSignal()));
    connect(&tagEditor, SIGNAL(tagsUpdated()), this, SLOT(sendTagUpdateSignal()));
    connect(&tagEditor, SIGNAL(newTagCreated(qint32)), this, SLOT(newTagAdded(qint32)));
    connect(editor, SIGNAL(noteChanged()), this, SLOT(noteContentUpdated()));
    connect(editor, SIGNAL(htmlEditAlert()), this, SLOT(noteContentEdited()));
    connect(editor->page(), SIGNAL(linkClicked(QUrl)), this, SLOT(linkClicked(QUrl)));
    connect(editor->page(), SIGNAL(microFocusChanged()), this, SLOT(microFocusChanged()));
    connect(editor->page(), SIGNAL(contentsChanged()), this, SLOT(correctFontTagAttr()));

    editor->page()->setLinkDelegationPolicy(QWebEnginePage::DelegateAllLinks);
    connect(editor->page(), SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(exposeToJavascript()));
    connect(editor->page(), SIGNAL(javaScriptWindowObjectCleared()), editor, SLOT(exposeToJavascript()));

    editor->page()->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    factory = new PluginFactory(this);
    editor->page()->setPluginFactory(factory);

    buttonBar->getButtonbarState();

    printPreviewPage = nullptr;
    printPage = nullptr;

    if (!global.disableThumbnails) {
        hammer = new Thumbnailer(global.db);
    }
    lid = -1;

    //Setup shortcuts for context menu
    removeFormattingShortcut = new QShortcut(this);
    global.setupShortcut(removeFormattingShortcut, "Edit_Remove_Formatting");
    connect(removeFormattingShortcut, SIGNAL(activated()), this, SLOT(removeFormatButtonPressed()));
    //removeFormattingShortcut->setContext(Qt::WidgetWithChildrenShortcut);

    insertHtmlEntitiesShortcut = new QShortcut(this);
    global.setupShortcut(insertHtmlEntitiesShortcut, QString("Edit_Insert_Html_Entities"));
    connect(insertHtmlEntitiesShortcut, SIGNAL(activated()), this, SLOT(insertHtmlEntities()));
    //insertHtmlEntitiesShortcut->setContext(Qt::WidgetWithChildrenShortcut);

    encryptTextShortcut = new QShortcut(this);
    global.setupShortcut(encryptTextShortcut, QString("Edit_Encrypt_Text"));
    connect(encryptTextShortcut, SIGNAL(activated()), this, SLOT(encryptButtonPressed()));
    //encryptTextShortcut->setContext(Qt::WidgetWithChildrenShortcut);

    insertHyperlinkShortcut = new QShortcut(this);
    global.setupShortcut(insertHyperlinkShortcut, QString("Edit_Insert_Hyperlink"));
    connect(insertHyperlinkShortcut, SIGNAL(activated()), this, SLOT(insertLinkButtonPressed()));
    //insertHyperlinkShortcut->setContext(Qt::WidgetWithChildrenShortcut);

    insertQuicklinkShortcut = new QShortcut(this);
    global.setupShortcut(insertQuicklinkShortcut, QString("Edit_Insert_QuickLink"));
    connect(insertQuicklinkShortcut, SIGNAL(activated()), this, SLOT(insertQuickLinkButtonPressed()));
    //insertQuicklinkShortcut->setContext(Qt::WidgetWithChildrenShortcut);

    removeHyperlinkShortcut = new QShortcut(this);
    global.setupShortcut(removeHyperlinkShortcut, QString("Edit_Remove_Hyperlink"));
    connect(removeHyperlinkShortcut, SIGNAL(activated()), this, SLOT(removeLinkButtonPressed()));
    //removeHyperlinkShortcut->setContext(Qt::WidgetWithChildrenShortcut);

    attachFileShortcut = new QShortcut(this);
    global.setupShortcut(attachFileShortcut, QString("Edit_Attach_File"));
    connect(attachFileShortcut, SIGNAL(activated()), this, SLOT(attachFile()));
    //attachFileShortcut->setContext(Qt::WidgetWithChildrenShortcut);

    insertLatexShortcut = new QShortcut(this);
    global.setupShortcut(insertLatexShortcut, QString("Edit_Insert_Latex"));
    connect(insertLatexShortcut, SIGNAL(activated()), this, SLOT(insertLatexButtonPressed()));


    // Restore the expand/collapse state
    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    int expandButton = global.settings->value("ExpandButton", EXPANDBUTTON_1).toInt();
    global.settings->endGroup();
    this->expandButton.setState(expandButton);

    connect(&focusTimer, SIGNAL(timeout()), this, SLOT(focusCheck()));
    focusTimer.setInterval(100);
    focusTimer.start();

    connect(&saveTimer, SIGNAL(timeout()), this, SLOT(saveTimeCheck()));
    saveTimer.setInterval(global.autoSaveInterval);
    saveTimer.start();

    spellChecker = nullptr;

    QString css = global.getThemeCss("browserWindowCss");
    if (css != "") {
        this->setStyleSheet(css);
    }

    changeDisplayFontName(global.defaultFont);
    changeDisplayFontSize(QString::number(global.defaultFontSize) + "pt");
}


// Destructor
NBrowserWindow::~NBrowserWindow() {
    browserThread->quit();
    while (!browserRunner->isIdle);
    while (!browserThread->isFinished());

    delete browserThread;
    delete browserRunner;
    delete editor;

    delete editorSplitter;
    delete findReplace;
    delete factory;
    delete buttonBar;
    delete line1Layout;

    delete focusNoteShortcut;
    delete focusTitleShortcut;
    delete insertDatetimeShortcut;
    delete insertDateShortcut;
    delete insertTimeShortcut;
    delete fontColorShortcut;
    delete fontHighlightShortcut;
    delete copyNoteUrlShortcut;
    delete removeFormattingShortcut;
    delete insertHtmlEntitiesShortcut;
    delete encryptTextShortcut;
    delete insertHyperlinkShortcut;
    delete insertQuicklinkShortcut;
    delete removeHyperlinkShortcut;
    delete attachFileShortcut;
    delete insertLatexShortcut;

    if (hammer != nullptr) {
        delete hammer;
    }

    if (spellChecker != nullptr) {
        delete spellChecker;
    }
    if (printPreviewPage != nullptr) {
        delete printPreviewPage;
    }
    if (printPage != nullptr) {
        delete printPage;
    }
}


// Browser helper thread is ready
void NBrowserWindow::browserThreadStarted() {
    browserRunner->moveToThread(browserThread);
}


// Setup the toolbar window of the editor
void NBrowserWindow::setupToolBar() {
    buttonBar = new EditorButtonBar();

    // Toolbar action
    connect(buttonBar->undoButtonAction, SIGNAL(triggered()), this, SLOT(undoButtonPressed()));
    connect(buttonBar->undoButtonShortcut, SIGNAL(activated()), this, SLOT(undoButtonPressed()));

    connect(buttonBar->redoButtonAction, SIGNAL(triggered()), this, SLOT(redoButtonPressed()));
    connect(buttonBar->redoButtonShortcut, SIGNAL(activated()), this, SLOT(redoButtonPressed()));

    connect(buttonBar->cutButtonAction, SIGNAL(triggered()), this, SLOT(cutButtonPressed()));
    connect(buttonBar->cutButtonShortcut, SIGNAL(activated()), this, SLOT(cutButtonPressed()));

    connect(buttonBar->copyButtonAction, SIGNAL(triggered()), this, SLOT(copyButtonPressed()));
    connect(buttonBar->copyButtonShortcut, SIGNAL(activated()), this, SLOT(copyButtonPressed()));

    connect(buttonBar->pasteButtonAction, SIGNAL(triggered()), this, SLOT(pasteButtonPressed()));
    //connect(buttonBar->pasteButtonShortcut, SIGNAL(activated()), this, SLOT(pasteButtonPressed()));  // Handled via NWebView

    connect(buttonBar->removeFormatButtonAction, SIGNAL(triggered()), this, SLOT(removeFormatButtonPressed()));
    connect(buttonBar->removeFormatButtonShortcut, SIGNAL(activatedAmbiguously()), this,
            SLOT(removeFormatButtonPressed()));

    connect(buttonBar->boldButtonWidget, SIGNAL(clicked()), this, SLOT(boldButtonPressed()));
    connect(buttonBar->boldButtonShortcut, SIGNAL(activated()), this, SLOT(boldButtonPressed()));

    connect(buttonBar->italicButtonWidget, SIGNAL(clicked()), this, SLOT(italicsButtonPressed()));
    connect(buttonBar->italicButtonShortcut, SIGNAL(activated()), this, SLOT(italicsButtonPressed()));

    connect(buttonBar->underlineButtonWidget, SIGNAL(clicked()), this, SLOT(underlineButtonPressed()));
    connect(buttonBar->underlineButtonShortcut, SIGNAL(activated()), this, SLOT(underlineButtonPressed()));

    connect(buttonBar->leftJustifyButtonAction, SIGNAL(triggered()), this, SLOT(alignLeftButtonPressed()));
    connect(buttonBar->leftJustifyButtonShortcut, SIGNAL(activated()), this, SLOT(alignLeftButtonPressed()));

    connect(buttonBar->rightJustifyButtonAction, SIGNAL(triggered()), this, SLOT(alignRightButtonPressed()));
    connect(buttonBar->rightJustifyButtonShortcut, SIGNAL(activated()), this, SLOT(alignRightButtonPressed()));

    connect(buttonBar->centerJustifyButtonAction, SIGNAL(triggered()), this, SLOT(alignCenterButtonPressed()));
    connect(buttonBar->centerJustifyButtonShortcut, SIGNAL(activated()), this, SLOT(alignCenterButtonPressed()));

    connect(buttonBar->fullJustifyButtonAction, SIGNAL(triggered()), this, SLOT(alignFullButtonPressed()));
    connect(buttonBar->fullJustifyButtonShortcut, SIGNAL(activated()), this, SLOT(alignFullButtonPressed()));

    connect(buttonBar->strikethroughButtonAction, SIGNAL(triggered()), this, SLOT(strikethroughButtonPressed()));
    connect(buttonBar->strikethroughButtonShortcut, SIGNAL(activated()), this, SLOT(strikethroughButtonPressed()));

    connect(buttonBar->subscriptButtonAction, SIGNAL(triggered()), this, SLOT(subscriptButtonPressed()));
    connect(buttonBar->subscriptButtonShortcut, SIGNAL(activated()), this, SLOT(subscriptButtonPressed()));

    connect(buttonBar->superscriptButtonAction, SIGNAL(triggered()), this, SLOT(superscriptButtonPressed()));
    connect(buttonBar->superscriptButtonShortcut, SIGNAL(activated()), this, SLOT(superscriptButtonPressed()));

    connect(buttonBar->hlineButtonAction, SIGNAL(triggered()), this, SLOT(horizontalLineButtonPressed()));
    connect(buttonBar->hlineButtonShortcut, SIGNAL(activated()), this, SLOT(horizontalLineButtonPressed()));

    connect(buttonBar->shiftRightButtonAction, SIGNAL(triggered()), this, SLOT(shiftRightButtonPressed()));
    connect(buttonBar->shiftRightButtonShortcut, SIGNAL(activated()), this, SLOT(shiftRightButtonPressed()));

    connect(buttonBar->shiftLeftButtonAction, SIGNAL(triggered()), this, SLOT(shiftLeftButtonPressed()));
    connect(buttonBar->shiftLeftButtonShortcut, SIGNAL(activated()), this, SLOT(shiftLeftButtonPressed()));

    connect(buttonBar->bulletListButtonAction, SIGNAL(triggered()), this, SLOT(bulletListButtonPressed()));
    connect(buttonBar->bulletListButtonShortcut, SIGNAL(activated()), this, SLOT(bulletListButtonPressed()));

    connect(buttonBar->numberListButtonAction, SIGNAL(triggered()), this, SLOT(numberListButtonPressed()));
    connect(buttonBar->numberListButtonShortcut, SIGNAL(activated()), this, SLOT(numberListButtonPressed()));

    connect(buttonBar->todoButtonAction, SIGNAL(triggered()), this, SLOT(todoButtonPressed()));
    connect(buttonBar->todoButtonShortcut, SIGNAL(activated()), this, SLOT(todoButtonPressed()));

    connect(buttonBar->spellCheckButtonAction, SIGNAL(triggered()), this, SLOT(spellCheckPressed()));
    connect(buttonBar->spellCheckButtonShortcut, SIGNAL(activated()), this, SLOT(spellCheckPressed()));

    connect(buttonBar->fontSizes, SIGNAL(activated(int)), this, SLOT(fontSizeSelected(int)));
    connect(buttonBar->fontNames, SIGNAL(currentIndexChanged(int)), this, SLOT(fontNameSelected(int)));

    connect(buttonBar->fontColorButtonWidget, SIGNAL(clicked()), this, SLOT(fontColorClicked()));
    // pressed/long click
    connect(buttonBar->fontColorMenuWidget->getMenu(), SIGNAL(triggered(QAction * )), this, SLOT(fontColorClicked()));

    connect(buttonBar->highlightColorButtonWidget, SIGNAL(clicked()), this, SLOT(fontHighlightClicked()));
    // pressed/long click
    connect(buttonBar->highlightColorMenuWidget->getMenu(), SIGNAL(triggered(QAction * )), this,
            SLOT(fontHighlightClicked()));

    connect(buttonBar->insertTableButtonAction, SIGNAL(triggered()), this, SLOT(insertTableButtonPressed()));
    connect(buttonBar->insertTableButtonShortcut, SIGNAL(activated()), this, SLOT(insertTableButtonPressed()));

    connect(buttonBar->htmlEntitiesButtonAction, SIGNAL(triggered()), this, SLOT(insertHtmlEntities()));
    connect(buttonBar->htmlEntitiesButtonShortcut, SIGNAL(activated()), this, SLOT(insertHtmlEntities()));

    connect(buttonBar->insertDatetimeButtonAction, SIGNAL(triggered()), this, SLOT(insertDatetime()));
    connect(buttonBar->insertDatetimeButtonWidget, SIGNAL(clicked()), this, SLOT(insertDatetime()));

    connect(buttonBar->formatCodeButtonAction, SIGNAL(triggered()), this, SLOT(formatCodeButtonPressed()));
    connect(buttonBar->formatCodeButtonShortcut, SIGNAL(activated()), this, SLOT(formatCodeButtonPressed()));

    // this sync button doesn't need a shortcut; the main app window shortcut is global
    connect(buttonBar->syncButtonAction, SIGNAL(triggered()), this, SLOT(syncButtonPressed()));

    connect(buttonBar->emailButtonAction, SIGNAL(triggered()), this, SLOT(emailNote()));
    connect(buttonBar->emailButtonShortcut, SIGNAL(activated()), this, SLOT(emailNote()));
}

// Load the note content into the window
void NBrowserWindow::setContent(qint32 lid) {
    QLOG_DEBUG() << "Setting note contents to lid=" << lid;

    // First, make sure we have a valid lid
    if (lid == -1) {
        blockSignals(true);
        setReadOnly(true);
        clear();
        blockSignals(false);
        return;
    }

    // If we are already updating this note, we don't do anything
    QLOG_DEBUG() << "Current editor lid=" << this->lid << ", changing to lid=" << lid;
    if (lid == this->lid) {
        QLOG_DEBUG() << "no change => exit";
        return;
    }

    bool hasFocus = false;
    if (this->editor->hasFocus())
        hasFocus = true;

    if (this->editor->isDirty) {
        QLOG_DEBUG() << "editor is dirty - content save";
        this->saveNoteContent();
    }

    QLOG_DEBUG() << "===== Loading note contents, lid=" << lid;
    // let's load the new note
    this->lid = lid;
    this->editor->isDirty = false;

    NoteTable noteTable(global.db);
    Note n;

    QLOG_DEBUG() << "Getting note, lid=" << this->lid;
    bool rc = noteTable.get(n, this->lid, false, false);
    if (!rc) {
        QLOG_DEBUG() << "Failed to load note (guid not set), lid=" << this->lid;
        return;
    }

    QByteArray content;
    bool inkNote = false;
    bool readOnly = false;

    // If we are searching, we never pull from the cache since the search string may
    // have changed since the last time.
    FilterCriteria *criteria = global.getCurrentCriteria();
    if (criteria->isSearchStringSet() && criteria->getSearchString().trimmed() != "") {
        global.cache.remove(lid);
    }

    QLOG_DEBUG() << "Checking if note is in cache, lid=" << this->lid;
    if (global.cache.contains(lid)) {
        QLOG_DEBUG() << "Fetching from cache, lid=" << this->lid;
        NoteCache *c = global.cache[lid];
        if (c == nullptr || c->noteContent == (char *) nullptr) {
            QLOG_DEBUG() << "Invalid note found in cache.  Removing it.";
            global.cache.remove(lid);
        } else {
            QLOG_DEBUG() << "Setting content from cache, lid=" << this->lid;
            content = c->noteContent;
            readOnly = c->isReadOnly;
            inkNote = c->isInkNote;
        }
    }

    if (!global.cache.contains(lid)) {
        QLOG_DEBUG() << "Note not in cache, lid=" << this->lid;
        NoteFormatter formatter;
        if (criteria->isSearchStringSet())
            formatter.setHighlightText(criteria->getSearchString());

        formatter.setNote(n, global.pdfPreview);
        //formatter.setHighlight();

        QLOG_DEBUG() << "Rebuilding note HTML, lid=" << this->lid;
        content = formatter.rebuildNoteHTML();
        if (!criteria->isSearchStringSet()) {
            QLOG_DEBUG() << "Criteria search string set";
            NoteCache *newCache = new NoteCache();
            newCache->isReadOnly = formatter.readOnly;
            newCache->isInkNote = formatter.inkNote;
            newCache->noteContent = content;
            QLOG_DEBUG() << "Adding to cache";
            global.cache.insert(lid, newCache);
        }
        readOnly = formatter.readOnly;
        inkNote = formatter.inkNote;
    }

    setReadOnly(readOnly);

    QLOG_DEBUG() << "Setting note title";
    noteTitle.setTitle(lid, n.title, n.title);
    dateEditor.setNote(lid, n);
    QWebSettings::setMaximumPagesInCache(0);
    QWebSettings::setObjectCacheCapacities(0, 0, 0);

    QLOG_DEBUG() << "Setting editor contents";

    //**** BEGINNING CALL TO PRE-LOAD EXIT
    QHash<QString, ExitPoint *> *points;
    points = global.exitManager->exitPoints;

    if (points->contains("ExitPoint_LoadNote") &&
        points->value("ExitPoint_LoadNote") != nullptr &&
        points->value("ExitPoint_LoadNote")->getEnabled()) {
        exitPoint(points->value("ExitPoint_LoadNote"));
    }
    //**** END OF CALL TO PRE-LOAD EXIT

    editor->setContent(content);

    // is this an ink note?
    if (inkNote)
        editor->page()->runJavaScript("document.documentElement.contentEditable = false");

    // Setup the alarm
    NoteAttributes attributes;
    QLOG_DEBUG() << "Setting attributes, lid=" << this->lid;
    if (n.attributes.isSet())
        attributes = n.attributes;
    if (attributes.reminderTime.isSet()) {
        Timestamp t;
        if (attributes.reminderTime.isSet())
            t = attributes.reminderTime;
        QFont f = alarmText.font();
        if (attributes.reminderDoneTime.isSet()) {
            f.setStrikeOut(true);
        } else {
            f.setStrikeOut(false);
        }
        alarmText.setFont(f);
        alarmText.setVisible(true);
        QDateTime atime;
        atime.setMSecsSinceEpoch(t);
        if (atime.date() == QDate::currentDate())
            alarmText.setText(tr("Today"));
        else if (atime.date() == QDate::currentDate().addDays(+1))
            alarmText.setText(tr("Tomorrow"));
        else if (atime.date() == QDate::currentDate().addDays(-1))
            alarmText.setText(tr("Yesterday"));
        else
            alarmText.setText(atime.date().toString(global.getDateFormat()));
    } else {
        alarmText.setText("");
        alarmText.setVisible(false);
    }


    // Set the tag names
    QLOG_DEBUG() << "Setting tags, lid=" << this->lid;
    tagEditor.clear();
    QStringList names;
    QList<QString> tagNames;
    if (n.tagNames.isSet())
        tagNames = n.tagNames;
    for (int i = 0; i < tagNames.size(); i++) {
        names << tagNames[i];
    }
    tagEditor.setTags(names);
    tagEditor.setCurrentLid(lid);
    NotebookTable notebookTable(global.db);
    qint32 notebookLid = notebookTable.getLid(n.notebookGuid);
    LinkedNotebookTable linkedTable(global.db);
    if (linkedTable.exists(notebookLid))
        tagEditor.setAccount(notebookLid);
    else
        tagEditor.setAccount(0);

    QLOG_DEBUG() << "Setting notebook, lid=" << this->lid;
    //this->lid = lid;
    notebookMenu.setCurrentNotebook(lid, n);
    QLOG_DEBUG() << "Setting URL";
    urlEditor.setUrl(lid, "");
    NoteAttributes na;
    QLOG_DEBUG() << "Setting note attributes, lid=" << this->lid;
    if (n.attributes.isSet()) {
        na = n.attributes;
        if (na.sourceURL.isSet()) {
            QLOG_DEBUG() << "Setting sourceUrl";
            urlEditor.setUrl(lid, na.sourceURL);
        }
    }

    QLOG_DEBUG() << "Calling set source, lid=" << this->lid;
    setSource();

    if (criteria->isSearchStringSet()) {
        QStringList list = criteria->getSearchString().split(" ");
        for (int i = 0; i < list.size(); i++) {
            editor->page()->findText(list[i], QWebEnginePage::HighlightAllOccurrences);
        }
    }

    QLOG_DEBUG() << "Checking thumbnail, lid=" << this->lid;
    if (!global.disableThumbnails && !noteTable.thumbnailExists(this->lid)) {
        hammer->capturePage(this->lid, this->editor->page());
    }
    this->setEditorStyle();

    if (hasFocus)
        this->editor->setFocus();
    QLOG_DEBUG() << "===== Finished loading note contents, lid=" << lid;
}


void NBrowserWindow::setReadOnly(bool readOnly) {
    QLOG_DEBUG() << "Setting read only flag to=" << readOnly << ", lid=" << this->lid;

    isReadOnly = readOnly;
    if (readOnly || global.disableEditing) {
        noteTitle.setFocusPolicy(Qt::NoFocus);
        tagEditor.setEnabled(false);
        buttonBar->setVisible(false);
        tagEditor.setFocusPolicy(Qt::NoFocus);
        //authorEditor.setFocusPolicy(Qt::NoFocus);
        //locationEditor.setFocusPolicy(Qt::NoFocus);
        urlEditor.setFocusPolicy(Qt::NoFocus);
        notebookMenu.setEnabled(false);
        dateEditor.setEnabled(false);
        editor->page()->runJavaScript("document.documentElement.contentEditable = false");
        alarmButton.setEnabled(false);
        return;
    }

    noteTitle.setFocusPolicy(Qt::StrongFocus);
    tagEditor.setEnabled(true);
    tagEditor.setFocusPolicy(Qt::StrongFocus);
    urlEditor.setFocusPolicy(Qt::StrongFocus);
    notebookMenu.setEnabled(true);
    dateEditor.setEnabled(true);
    editor->page()->runJavaScript("document.documentElement.contentEditable = true");
    alarmButton.setEnabled(true);
}


// Show / hide various note attributes depending upon what the user
// has clicked
void NBrowserWindow::changeExpandState(int value) {
    switch (value) {
        case EXPANDBUTTON_1:
            urlEditor.hide();
            tagEditor.hide();
            dateEditor.hide();
            break;
        case EXPANDBUTTON_2:
            urlEditor.show();
            tagEditor.show();
            break;
        case EXPANDBUTTON_3:
            urlEditor.show();
            tagEditor.show();
            dateEditor.show();
            break;
    }
    global.settings->beginGroup(INI_GROUP_SAVE_STATE);
    global.settings->setValue("ExpandButton", value);
    global.settings->endGroup();
}

// Send a signal that a tag has been added to a note
void NBrowserWindow::newTagAdded(qint32 lid) {
    emit(tagAdded(lid));
}

// Add a tag to a note
void NBrowserWindow::addTagName(qint32 lid) {
    TagTable table(global.db);
    Tag t;
    table.get(t, lid);
    tagEditor.addTag(t.name);
}


// Rename a tag in a note.
void NBrowserWindow::tagRenamed(qint32 lid, QString oldName, QString newName) {
    tagEditor.tagRenamed(lid, oldName, newName);
}


// Remove a tag in a note
void NBrowserWindow::tagDeleted(qint32 lid, QString name) {
    Q_UNUSED(lid);  /* suppress unused */
    tagEditor.removeTag(name);
}


// A notebook was renamed
void NBrowserWindow::notebookRenamed(qint32 lid, QString oldName, QString newName) {
    Q_UNUSED(lid);  /* suppress unused */
    Q_UNUSED(oldName);  /* suppress unused */
    Q_UNUSED(newName)  /* suppress unused */
    notebookMenu.reloadData();
}


// A notebook was deleted
void NBrowserWindow::notebookDeleted(qint32 lid, QString name) {
    Q_UNUSED(lid);  /* suppress unused */
    Q_UNUSED(name); /* suppress unused */
    notebookMenu.reloadData();
}


// A stack was renamed
void NBrowserWindow::stackRenamed(QString oldName, QString newName) {
    Q_UNUSED(oldName);  /* suppress unused */
    Q_UNUSED(newName);  /* suppress unused */
    notebookMenu.reloadData();
}


// A stack was deleted
void NBrowserWindow::stackDeleted(QString name) {
    Q_UNUSED(name);  /* suppress unused */
    notebookMenu.reloadData();
}


// A stack was added
void NBrowserWindow::stackAdded(QString name) {
    Q_UNUSED(name);  /* suppress unused */
    notebookMenu.reloadData();
}


// A notebook was added
void NBrowserWindow::notebookAdded(qint32 lid) {
    Q_UNUSED(lid);  /* suppress unused */
    notebookMenu.reloadData();
}


// A note was synchronized with Evernote's servers
void NBrowserWindow::noteSyncUpdate(qint32 lid) {
    if (lid != this->lid || editor->isDirty)
        return;
    setContent(lid);
}

// mark note currently open in editor as dirty (or as NOT dirty depending on param)
// default setDateUpdated=true
void NBrowserWindow::setDirty(qint32 lid, bool dirty, bool setDateUpdated) {
    QLOG_DEBUG() << "setDirty: lid=" << lid << ", dirty=" << dirty << ", setDateUpdated=" << setDateUpdated;
    NoteTable noteTable(global.db);
    noteTable.setDirty(lid, dirty, setDateUpdated);
    if (setDateUpdated) {
        qint64 dt = QDateTime::currentMSecsSinceEpoch();
        emit(updateNoteList(lid, NOTE_TABLE_DATE_UPDATED_POSITION, dt));
    }

    emit(updateNoteList(lid, NOTE_TABLE_IS_DIRTY_POSITION, QVariant(dirty)));
    // signal to redraw title compound column (with unchanged data)
    emit(updateNoteList(lid, NOTE_TABLE_TITLE_POSITION, QVariant()));
}


// A note's content was updated
void NBrowserWindow::noteContentUpdated() {
    if (editor->isDirty) {
        QLOG_DEBUG() << "noteContentUpdated: setting dirty flag for lid=" << this->lid;
        setDirty(this->lid, true);
        editor->isDirty = false;
        emit(noteUpdated(this->lid));
    } else {
        QLOG_DEBUG() << "noteContentUpdated: - content not really modified";
    }
}


// Save the note's content
void NBrowserWindow::saveNoteContent() {
    //microFocusChanged();

    if (this->editor->isDirty) {
        QLOG_DEBUG() << "saveNoteContent() dirty=true";
        // BEGIN EXIT POINT
        QHash<QString, ExitPoint *> *points;
        points = global.exitManager->exitPoints;
        if (points->contains("ExitPoint_SaveNote") &&
            points->value("ExitPoint_SaveNote") != nullptr &&
            points->value("ExitPoint_SaveNote")->getEnabled())
            exitPoint(points->value("ExitPoint_SaveNote"));
        // END EXIT POINT

        QString contents = editor->editorPage->documentElement().toOuterXml();

        EnmlFormatter formatter(contents, global.guiAvailable, global.passwordSafe,
                                global.fileManager.getCryptoJarPath());
        formatter.rebuildNoteEnml();
        if (formatter.isFormattingError()) {
            QMessageBox::information(
                    this,
                    tr("Unable to reformat"),
                    QString(
                            tr(NN_APP_DISPLAY_NAME_GUI " was unable to reformat the note in ENML. Note could not be saved."))
            );
            return;
        }


        // get a list of lids found in the note.
        // Purge anything that is no longer needed.
        QList<qint32> validLids = formatter.getResources();
        QList<qint32> oldLids;
        ResourceTable resTable(global.db);
        resTable.getResourceList(oldLids, lid);

        for (int i = 0; i < validLids.size(); i++) {
            QLOG_DEBUG() << "valid [" << i << "] " << validLids[i];
        }
        for (int i = 0; i < oldLids.size(); i++) {
            QLOG_DEBUG() << "old [" << i << "] " << oldLids[i];
        }

        for (int i = 0; i < oldLids.size(); i++) {
            if (!validLids.contains(oldLids[i])) {
                QLOG_DEBUG() << "expunging old lid " << oldLids[i];
                resTable.expunge(oldLids[i]);
            }
        }

        QLOG_DEBUG() << "Updating note content";
        if (!global.multiThreadSaveEnabled) {
            NoteTable table(global.db);
            table.updateNoteContent(lid, formatter.getContent());
        } else
                emit requestNoteContentUpdate(lid, formatter.getContent(), true);
        editor->isDirty = false;

        if (!global.disableThumbnails) {
            QLOG_DEBUG() << "Beginning thumbnail";
            hammer->capturePage(this->lid, this->editor->page());
            QLOG_DEBUG() << "Thumbnail completed";
        }

        NoteCache *cache = global.cache[lid];
        if (cache != nullptr) {
            QLOG_DEBUG() << "Updating cache";
            QByteArray b;
            b.append(contents);
            cache->noteContent = b;
            global.cache.remove(lid);
        }
        QLOG_DEBUG() << "Leaving saveNoteContent()";
    } else {
        QLOG_DEBUG() << "saveNoteContent() not dirty";
    }
}


// The undo edit button was pressed
void NBrowserWindow::undoButtonPressed() {
    this->editor->triggerPageAction(QWebEnginePage::Undo);
    this->editor->setFocus();
    microFocusChanged();
}


// The redo edit button was pressed
void NBrowserWindow::redoButtonPressed() {
    this->editor->triggerPageAction(QWebEnginePage::Redo);
    this->editor->setFocus();
    microFocusChanged();
}


// The cut button was pressed
void NBrowserWindow::cutButtonPressed() {
    this->editor->triggerPageAction(QWebEnginePage::Cut);
    this->editor->setFocus();
    microFocusChanged();
}


// The copy button was pressed
void NBrowserWindow::copyButtonPressed() {
    //    editor->downloadImageAction()->setEnabled(true);
    //    selectedFileName = f;
    //    selectedFileLid = l.toInt();

    // If we have text selected
    if (this->editor->selectedText().trimmed() != "") {
        this->editor->triggerPageAction(QWebEnginePage::Copy);
        this->editor->setFocus();
    } else {
        // If we have an image selected, we copy it to the clipboard.
        if (editor->downloadImageAction()->isEnabled()) {
            QString fileName = global.fileManager.getDbaDirPath() + selectedFileName;
            QApplication::clipboard()->setPixmap(QPixmap(fileName));
        }
    }

    microFocusChanged();
}


// Build URL from pasted text
QString NBrowserWindow::buildPasteUrl(QString url) {
    // Setup regular expression to test http urls
    // regex from https://stackoverflow.com/questions/3809401/what-is-a-good-regular-expression-to-match-a-url
    // TODO add tests...
    QRegExp urlREGEX(R"R(^https?:\/\/(www\.)?[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b([-a-zA-Z0-9()@:%_\+.~#?&//=]*)$)R");
    urlREGEX.setCaseSensitivity(Qt::CaseInsensitive);
    urlREGEX.setPatternSyntax(QRegExp::RegExp);

    bool valid = urlREGEX.exactMatch(url);
    if (!valid) {
        QLOG_DEBUG() << "buildPasteUrl: not a valid url detected";
        return url;
    }
    QString newUrl = QString("<a href=\"") + url + QString("\">") + url + QString("</a>");
    QLOG_DEBUG() << "buildPasteUrl: valid url; adjusted to HTML: newUrl=" << newUrl;
    return newUrl;
}


// The paste button was pressed
void NBrowserWindow::pasteButtonPressed() {
    if (forceTextPaste) {
        pasteWithoutFormatButtonPressed();
        return;
    }
    QLOG_DEBUG() << "pasteButtonPressed";

    const QMimeData *mime = QApplication::clipboard()->mimeData();
    if (mime->hasImage()) {
        editor->setFocus();
        insertImage(mime);
        editor->setFocus();
        return;
    }

    if (mime->hasUrls()) {
        QList<QUrl> urls = mime->urls();
        for (int i=0; i<urls.size(); i++) {
            QLOG_DEBUG() << urls[i].toString();
            if (urls[i].toString().startsWith("file://")) {
// Windows Check
#ifndef _WIN32
                QString fileName = urls[i].toString().mid(7);
#else
                QString fileName = urls[i].toString().mid(8);
#endif  // End windows check
                attachFileSelected(fileName);
                this->editor->triggerPageAction(QWebEnginePage::InsertParagraphSeparator);
            }
        }

        this->editor->setFocus();
        microFocusChanged();
        return;
    }

    if (!mime->hasText()) {
        QLOG_DEBUG() << "pasteButtonPressed: no text; nothing to do";
        return;
    }

    // note: pasted text - is text only version without html tags
    bool hasHtml = mime->hasHtml();
    const QString mimeContentAsText = mime->text();
    bool isEvernoteInAppLink = mimeContentAsText.startsWith("evernote:///view/");
    bool processAsHtml = hasHtml && (!isEvernoteInAppLink);
    QString textToPaste = processAsHtml ? mime->html() : mimeContentAsText;

    QLOG_DEBUG() << "pasteButtonPressed: hasHtml=" << hasHtml
                 << ", isEvernoteInAppLink=" << isEvernoteInAppLink
                 << ", original textToPaste=" << textToPaste;
    bool hasWhitespace = textToPaste.contains(QRegExp("\\s"));
    if (hasWhitespace) {
        // hacky workaround to skip any postprocessing
        QLOG_DEBUG() << "1:1 insert (no preprocessing)";
        this->editor->triggerPageAction(QWebEnginePage::Paste);
    } else {
        if ((!hasHtml) && (!isEvernoteInAppLink)) {
            // this to add markup if it is a single url
            textToPaste = this->buildPasteUrl(textToPaste);
        }

        // TODO refactor this hacky code
        if (isEvernoteInAppLink) {
            // very hacky way to process evernote urls
            QLOG_DEBUG() << "pasteButtonPressed: its evernote link";
            QStringList urlList = textToPaste.split(" ");
            QString url = "";
            for (int i = 0; i < urlList.size(); i++) {
                //QLOG_DEBUG() << urlList[i];
                textToPaste = urlList[i];
                textToPaste = textToPaste.mid(17);
                int pos = textToPaste.indexOf("/");
                textToPaste = textToPaste.mid(pos + 1);
                pos = textToPaste.indexOf("/");
                textToPaste = textToPaste.mid(pos + 1);
                pos = textToPaste.indexOf("/");
                textToPaste = textToPaste.mid(pos + 1);
                pos = textToPaste.indexOf("/");
                QString guid = textToPaste.mid(0, pos);
                textToPaste = textToPaste.mid(pos);
                pos = textToPaste.indexOf("/");
                QString locguid = textToPaste.mid(pos);

                Note n;
                bool goodrc = false;
                NoteTable ntable(global.db);
                goodrc = ntable.get(n, guid, false, false);
                if (!goodrc) {
                    goodrc = ntable.get(n, locguid, false, false);
                }

                // If we have a good return, then we can paste the link, otherwise we fall out
                // to a normal paste.
                if (goodrc) {
                    url = url + QString("<a href=\"%1\" title=\"%2\">%3</a>").arg(
                            urlList[i],
                            n.title.ref().toHtmlEscaped().replace("'", "&apos;"),
                            n.title.ref().toHtmlEscaped().replace("'", "&apos;"));
                    QLOG_DEBUG() << "HTML to insert:" << url;
                    if (i + 1 < urlList.size()) {
                        url = url + " <br> ";
                    }
                    textToPaste = url;
                    // TODO maybe add code to handle more than one url
                    break;
                }
            }
        }

        // https://developer.mozilla.org/en-US/docs/Web/API/Document/execCommand
        // 2nd param: A Boolean, specifies if the UI should be shown or not
        QLOG_DEBUG() << "pasteButtonPressed: final textToPaste=" << textToPaste;
        QString script = QString("document.execCommand('insertHtml', false, '%1');").arg(textToPaste);
        editor->page()->runJavaScript(script);
    }

    this->editor->setFocus();
    microFocusChanged();
}


// The paste button was pressed
void NBrowserWindow::selectAllButtonPressed() {
    this->editor->triggerPageAction(QWebEnginePage::SelectAll);
    this->editor->setFocus();
    microFocusChanged();
}


// The paste without mime format was pressed
void NBrowserWindow::pasteWithoutFormatButtonPressed() {
    QLOG_DEBUG() << "pasteWithoutFormatButtonPressed";

    const QMimeData *mime = QApplication::clipboard()->mimeData();
    if (!mime->hasText())
        return;
    QString text = mime->text();
    QApplication::clipboard()->clear();
    QApplication::clipboard()->setText(text, QClipboard::Clipboard);
    this->editor->triggerPageAction(QWebEnginePage::Paste);

    // This is done because pasting into an encryption block
    // can cause multiple cells (which can't happen).  It
    // just goes through the table, extracts the data, &
    // puts it back as one table cell.
    if (insideEncryption) {
        QString js = QString("function fixEncryption() { ")
                     + QString("   var selObj = window.getSelection();")
                     + QString("   var selRange = selObj.getRangeAt(0);")
                     + QString("   var workingNode = window.getSelection().anchorNode;")
                     + QString("   while(workingNode != null && workingNode.nodeName.toLowerCase() != 'table') { ")
                     + QString("           workingNode = workingNode.parentNode;")
                     + QString("   } ")
                     + QString(
                "   workingNode.innerHTML = window.browserWindow.fixEncryptionPaste(workingNode.innerHTML);")
                     + QString("} fixEncryption();");
        editor->page()->runJavaScript(js);
    }

    this->editor->setFocus();
    microFocusChanged();
}

// This basically removes all the table tags and returns just the contents.
// This is called by JavaScript to fix encryption pastes.
QString NBrowserWindow::fixEncryptionPaste(QString data) {
    data = data.replace("<tbody>", "");
    data = data.replace("</tbody>", "");
    data = data.replace("<tr>", "");
    data = data.replace("</tr>", "");
    data = data.replace("<td>", "");
    data = data.replace("</td>", "<br>");
    data = data.replace("<br><br>", "<br>");
    return QString("<tbody><tr><td>") + data + QString("</td></tr></tbody>");
}


// The bold button was pressed / toggled
void NBrowserWindow::boldButtonPressed() {
    QAction *action = editor->page()->action(QWebEnginePage::ToggleBold);
    action->activate(QAction::Trigger);
    this->editor->setFocus();
    microFocusChanged();
}


// The toggled button was pressed/toggled
void NBrowserWindow::italicsButtonPressed() {
    QAction *action = editor->page()->action(QWebEnginePage::ToggleItalic);
    action->activate(QAction::Trigger);
    this->editor->setFocus();
    microFocusChanged();
}


// The underline button was toggled
void NBrowserWindow::underlineButtonPressed() {
    this->editor->triggerPageAction(QWebEnginePage::ToggleUnderline);
    this->editor->setFocus();
    microFocusChanged();
}


void NBrowserWindow::removeFormatButtonPressed() {
    // for some reason first call doesn't remove background color, but the second does...
    this->editor->triggerPageAction(QWebEnginePage::RemoveFormat);
    this->editor->triggerPageAction(QWebEnginePage::RemoveFormat);

    this->editor->setFocus();
    microFocusChanged();
}


void NBrowserWindow::htmlCleanup(HtmlCleanupMode mode) {
    QLOG_DEBUG() << "html cleanup, mode " << mode;
    QWebElement rootElement = editor->editorPage->documentElement();
    QString contents = rootElement.toOuterXml();
    bool isSimplify = mode == HtmlCleanupMode::Simplify;

    EnmlFormatter formatter(contents, global.guiAvailable, global.passwordSafe, global.fileManager.getCryptoJarPath());

    if (isSimplify) {
        formatter.tidyHtml(HtmlCleanupMode::Tidy);
        bool isOK = !formatter.isFormattingError();
        if (isOK) {
            contents = formatter.getContent();

            // hardcore hack :(

            // http://doc.qt.io/qt-5/qstring.html#replace-12
            QRegularExpression reImg("(<img [^>]*>)");
            QRegularExpression reA("(<a [^>]*>)");
            QRegularExpression reObject("(<object [^>]*>)");

            contents.replace(reA, HTML_COMMENT_START "\\1" HTML_COMMENT_END);
            contents.replace("</a>", HTML_COMMENT_START "</a>" HTML_COMMENT_END);

            contents.replace(reObject, HTML_COMMENT_START "\\1" HTML_COMMENT_END);
            contents.replace("</object>", HTML_COMMENT_START "</object>" HTML_COMMENT_END);

            contents.replace(reImg, HTML_COMMENT_START "\\1" HTML_COMMENT_END);
            formatter.setContent(contents);
            QLOG_DEBUG_FILE("simplify1.html", formatter.getContent());

            formatter.tidyHtml(HtmlCleanupMode::Simplify);
            QLOG_DEBUG_FILE("simplify2.html", formatter.getContent());
            isOK = !formatter.isFormattingError();
        }
        if (isOK) {
            contents = formatter.getContent();
            contents.replace(HTML_COMMENT_START, "");
            contents.replace(HTML_COMMENT_END, "");
        }
    } else {
        formatter.tidyHtml(mode);
        contents = formatter.getContent();
    };


    if (formatter.isFormattingError()) {
        QMessageBox::information(
                this,
                tr("Unable to reformat"),
                QString(tr("HTML cleanup failed."))
        );
        return;
    }
    // equals to setContent(html, "text/html", baseUrl).
    QLOG_DEBUG_FILE("htmlCleanup.html", contents);
    editor->setHtml(contents);


    editor->setFocus();
    // this will set editor to dirty, signal "noteChanged" which will call noteContentUpdated()
    editor->editAlert();
    microFocusChanged();

    noteContentEdited();
}


/**
 * Simplify html.
 */
void NBrowserWindow::htmlSimplify() {
    // this also may help a bit (but only if the text is selected I suppose)
    // a bit hack; maybe improve later
    removeFormatButtonPressed();

    htmlCleanup(HtmlCleanupMode::Simplify);
}


// The strikethrough button was pressed
void NBrowserWindow::strikethroughButtonPressed() {
    this->editor->triggerPageAction(QWebEnginePage::ToggleStrikethrough);
    this->editor->setFocus();
    microFocusChanged();
}


// The horizontal line button was pressed
void NBrowserWindow::horizontalLineButtonPressed() {
    this->editor->page()->runJavaScript(
            "document.execCommand('insertHorizontalRule', false, '');");
    editor->setFocus();
    microFocusChanged();
}


// The center align button was pressed
void NBrowserWindow::alignCenterButtonPressed() {
    this->editor->page()->runJavaScript(
            "document.execCommand('JustifyCenter', false, '');");
    editor->setFocus();
    microFocusChanged();
}


// The format code button was pressed
void NBrowserWindow::formatCodeButtonPressed() {

    QString text = editor->selectedText();
    // default (now removed)
    // if (text.trimmed() == "")
    //     text = ""tr("Insert your code here.")"";
    QString buffer;
    //    buffer.append("<pre style=\"font-family: Monaco, Menlo, Consolas, 'Courier New', monospace; font-size: 0.9em; border-radius: 4px; letter-spacing: 0.015em; padding: 1em; border: 1px solid #cccccc; background-color: #f8f8f8; overflow-x: auto;\">");
    buffer.append(
            "<br/><pre style=\"font-family: Monaco, Menlo, Consolas, Courier New, monospace; font-size: 0.9em; border-radius: 4px; letter-spacing: 0.015em; padding: 1em; border: 1px solid #cccccc; background-color: #f8f8f8; overflow-x: auto;\">");
    buffer.append(text);
    buffer.append("</pre><br/>");
    QString script = QString("document.execCommand('insertHtml', false, '%1');").arg(buffer);
    editor->page()->runJavaScript(script).toString();

    QKeyEvent *left = new QKeyEvent(QEvent::KeyPress, Qt::Key_Left, Qt::NoModifier);
    QCoreApplication::postEvent(editor->editorPage, left);
}

// The sync button was pressed
void NBrowserWindow::syncButtonPressed() {
    NixNote::get()->synchronize();
}

// The full align button was pressed
void NBrowserWindow::alignFullButtonPressed() {
    this->editor->page()->runJavaScript(
            "document.execCommand('JustifyFull', false, '');");
    editor->setFocus();
    microFocusChanged();
}


// The left align button was pressed
void NBrowserWindow::alignLeftButtonPressed() {
    this->editor->page()->runJavaScript(
            "document.execCommand('JustifyLeft', false, '');");
    editor->setFocus();
    microFocusChanged();
}


// The align right button was pressed
void NBrowserWindow::alignRightButtonPressed() {
    this->editor->page()->runJavaScript(
            "document.execCommand('JustifyRight', false, '');");
    editor->setFocus();
    microFocusChanged();
}


// The shift right button was pressed
void NBrowserWindow::shiftRightButtonPressed() {
    this->editor->page()->runJavaScript(
            "document.execCommand('indent', false, '');");
    editor->setFocus();
    microFocusChanged();
}


// The shift left button was pressed
void NBrowserWindow::shiftLeftButtonPressed() {
    this->editor->page()->runJavaScript(
            "document.execCommand('outdent', false, '');");
    editor->setFocus();
    microFocusChanged();
}


// The number list button was pressed
void NBrowserWindow::numberListButtonPressed() {
    this->editor->page()->runJavaScript(
            "document.execCommand('InsertOrderedList', false, '');");
    editor->setFocus();
    microFocusChanged();
}


// The bullet list button was pressed
void NBrowserWindow::bulletListButtonPressed() {
    this->editor->page()->runJavaScript(
            "document.execCommand('InsertUnorderedList', false, '');");
    editor->setFocus();
    microFocusChanged();
}

// called from many places (mainly here inside) after some action changed content of editor
// also called 1x from outside
void NBrowserWindow::contentChanged() {
    QLOG_DEBUG() << "contentChanged()";
    this->editor->isDirty = true;
    saveNoteContent();
    this->sendDateUpdateSignal();
}

// The todo button was pressed
void NBrowserWindow::todoButtonPressed() {
    QString script_start = "document.execCommand('insertHtml', false, '";
    QString script_end = "');";

    QString selectedHtml = editor->selectedHtml();
    int length = selectedHtml.length();
    selectedHtml.replace(global.getCheckboxElement(true, false), "");
    selectedHtml.replace(global.getCheckboxElement(false, false), "");
    if (selectedHtml.length() < length) {
        editor->page()->runJavaScript(script_start +
                selectedHtml + script_end);
        return;
    }

    QString selectedText = editor->selectedText().trimmed();
    QRegExp regex("\\r?\\n");
    QStringList items = selectedText.split(regex);

    QString html = "";
    for (int i = 0; i < items.size(); i++) {
        html += "<div>" + global.getCheckboxElement(false, true) + items[i] +
            "</div>";
    }

    editor->page()->runJavaScript(script_start + html + script_end);
    editor->setFocus();
    microFocusChanged();
}

void NBrowserWindow::todoSelectAll() {
    this->todoSetAllChecked(true);
}

void NBrowserWindow::todoUnselectAll() {
    this->todoSetAllChecked(false);
}

void NBrowserWindow::todoSetAllChecked(bool allSelected) {
    QString script_start = "document.execCommand('insertHtml', false, '";
    QString script_end = "');";

    QString html = editor->selectedHtml();
    if (allSelected) {
        html.replace(global.getCheckboxElement(false, false),
                global.getCheckboxElement(true, true));
        html.replace(global.getCheckboxElement(true, false),
                global.getCheckboxElement(true, true));
    } else {
        html.replace(global.getCheckboxElement(true, false),
                global.getCheckboxElement(false, true));
        html.replace(global.getCheckboxElement(false, false),
                global.getCheckboxElement(false, true));
    }

    editor->page()->runJavaScript(script_start + html + script_end);
}


// The font size button was pressed
void NBrowserWindow::fontSizeSelected(int index) {
    int size = buttonBar->fontSizes->itemData(index).toInt();
    if (size <= 0)
        return;

    if (this->editor->selectedText() == "" &&
            buttonBar->fontSizes->currentText() == QString(size)) {
        return;
    }

    // Start building a new font span.
    int idx = buttonBar->fontNames->currentIndex();
    QString font = buttonBar->fontNames->itemText(idx);

    QString text = editor->selectedHtml();
    if (text.trimmed() == "") {
        QUndoStack *stack = this->editor->page()->undoStack();

        // Simulate a backspace press down event to delete
        // the invisible charactor inserted above.
        QKeyEvent *backspacePressed = new QKeyEvent(QKeyEvent::KeyPress,
                Qt::Key_Backspace, Qt::NoModifier, "");

        stack->beginMacro("SetFontSize");

        // Add an invisible charactor in order to focus on the innerhtml
        // part of the <span> tags added below. If not, the text typed
        // in after font size changed will be added beyond the <span>
        // tags scope.
        text = "&zwnj;";
        QString newText = "<span style=\"font-size:" + QString::number(size) + "pt;font-family:" + font + ";\">" + text + "</span>";
        QString script2 = QString("document.execCommand('insertHtml', false, '" + newText + "');");
        editor->page()->runJavaScript(script2);

        QApplication::sendEvent(editor, backspacePressed);

        stack->endMacro();

        delete backspacePressed;
    } else {
        QString script = QString("document.execCommand('fontSize', false, 5);");
        editor->page()->runJavaScript(script);

        // document.execCommand fontSize will generate font tag with 'size'
        // attribute set, which now and then makes the following font size
        // setting in trouble. So replace it with 'font-size' here.
        modifyFontTagAttr(size);
    }

    editor->setFocus();
    microFocusChanged();
    buttonBar->fontSizes->setCurrentText(QString::number(size));
}


void NBrowserWindow::insertHtml(QString html) {
    QString script = QString("document.execCommand('insertHtml', false, '%1');").arg(html);
    editor->page()->runJavaScript(script);
    microFocusChanged();
}


// The font name list was selected
void NBrowserWindow::fontNameSelected(int index) {
    QString font = buttonBar->fontNames->itemData(index).toString();
    buttonBar->fontSizes->blockSignals(true);
    buttonBar->loadFontSizeComboBox(font);
    buttonBar->fontSizes->blockSignals(false);
    this->editor->page()->runJavaScript(
            "document.execCommand('fontName', false, '" + font + "');");
    editor->setFocus();
    microFocusChanged();
}

// The font color was pressed
void NBrowserWindow::fontColorClicked() {
    QLOG_DEBUG() << "fontColorClicked";
    QColor *color = buttonBar->fontColorMenuWidget->getCurrentColor();
    QLOG_DEBUG() << "Setting text color to: " << buttonBar->fontColorMenuWidget->getCurrentColorName();
    if (color->isValid()) {
        this->editor->page()->runJavaScript(
                "document.execCommand('foreColor', false, '" + color->name() + "');");
        editor->setFocus();
        microFocusChanged();
        buttonBar->saveButtonbarState();
    }
}


// The font highlight color was pressed
void NBrowserWindow::fontHighlightClicked() {
    QLOG_DEBUG() << "fontHighlightClicked";
    QColor *color = buttonBar->highlightColorMenuWidget->getCurrentColor();
    QLOG_DEBUG() << "Setting text background color to: " << buttonBar->highlightColorMenuWidget->getCurrentColorName();
    if (color->isValid()) {
        this->editor->page()->runJavaScript(
                "document.execCommand('backColor', false, '" + color->name() + "');");
        editor->setFocus();
        microFocusChanged();
        buttonBar->saveButtonbarState();
    }
}

void NBrowserWindow::insertLinkButtonPressed() {
    QLOG_DEBUG() << "insertLinkButtonPressed";
    QString text = editor->selectedText().trimmed();
    if (text == "" && currentHyperlink == "") {
        QLOG_DEBUG()
            << "insertLinkButtonPressed. you need to select some text or position cursor inside existing link, "
               "before calling the function (abort)";
        return;
    }
    InsertLinkDialog dialog(insertHyperlink);

    // If we have a link already highlighted, set it to the dialog.
    if (text.startsWith("http://", Qt::CaseInsensitive) ||
        text.startsWith("https://", Qt::CaseInsensitive) ||
        text.startsWith("ftp://", Qt::CaseInsensitive) ||
        text.startsWith("mailto:", Qt::CaseInsensitive)) {
        dialog.setUrl(text);
    }

    if (currentHyperlink != nullptr && currentHyperlink != "") {
        dialog.setUrl(currentHyperlink);
    }
    dialog.exec();
    if (!dialog.okButtonPressed()) {
        return;
    }

    // Take care of inserting new links
    if (insertHyperlink) {
        QString selectedText = editor->selectedText().replace("'", "\\'");
        if (dialog.getUrl().trimmed() == "")
            return;
        QString durl = dialog.getUrl().trimmed().replace("'", "\\'");
        QString url = QString("<a href=\"%1\" title=\"%2\">%3</a>").arg(durl, durl, selectedText);
        QString script = QString("document.execCommand('insertHtml', false, '%1')").arg(url);
        editor->page()->runJavaScript(script);
        return;
    }

    QString x = dialog.getUrl();
    // Edit existing links
    QString js = "function getCursorPos() {"
                 "var cursorPos;"
                 "if (window.getSelection) {"
                 "   var selObj = window.getSelection();"
                 "   var selRange = selObj.getRangeAt(0);"
                 "   var workingNode = window.getSelection().anchorNode.parentNode;"
                 "   while(workingNode != null) { "
                 "      if (workingNode.nodeName.toLowerCase()=='a') workingNode.setAttribute('href','";
    js = js + dialog.getUrl() + QString("');")
         + QString("      workingNode = workingNode.parentNode;")
         + QString("   }")
         + QString("}")
         + QString("} getCursorPos();");
    editor->page()->runJavaScript(js);

    if (dialog.getUrl().trimmed() != "") {
        contentChanged();
        return;
    }

    // Remove URL
    js = QString("function getCursorPos() {")
         + QString("var cursorPos;")
         + QString("if (window.getSelection) {")
         + QString("   var selObj = window.getSelection();")
         + QString("   var selRange = selObj.getRangeAt(0);")
         + QString("   var workingNode = window.getSelection().anchorNode.parentNode;")
         + QString("   while(workingNode != null) { ")
         + QString("      if (workingNode.nodeName.toLowerCase()=='a') { ")
         + QString("         workingNode.removeAttribute('href');")
         + QString("         workingNode.removeAttribute('title');")
         + QString("         var text = document.createTextNode(workingNode.innerText);")
         + QString("         workingNode.parentNode.insertBefore(text, workingNode);")
         + QString("         workingNode.parentNode.removeChild(workingNode);")
         + QString("      }")
         + QString("      workingNode = workingNode.parentNode;")
         + QString("   }")
         + QString("}")
         + QString("} getCursorPos();");
    editor->page()->runJavaScript(js);

    contentChanged();
}


void NBrowserWindow::removeLinkButtonPressed() {
    // Remove URL
    QString js = QString("function getCursorPos() {")
                 + QString("var cursorPos;")
                 + QString("if (window.getSelection) {")
                 + QString("   var selObj = window.getSelection();")
                 + QString("   var selRange = selObj.getRangeAt(0);")
                 + QString("   var workingNode = window.getSelection().anchorNode.parentNode;")
                 + QString("   while(workingNode != null) { ")
                 + QString("      if (workingNode.nodeName.toLowerCase()=='a') { ")
                 + QString("         workingNode.removeAttribute('href');")
                 + QString("         workingNode.removeAttribute('title');")
                 + QString("         var text = document.createTextNode(workingNode.innerText);")
                 + QString("         workingNode.parentNode.insertBefore(text, workingNode);")
                 + QString("         workingNode.parentNode.removeChild(workingNode);")
                 + QString("      }")
                 + QString("      workingNode = workingNode.parentNode;")
                 + QString("   }")
                 + QString("}")
                 + QString("} getCursorPos();");
    editor->page()->runJavaScript(js);
    contentChanged();
}


void NBrowserWindow::insertQuickLinkButtonPressed() {
    QString text = editor->selectedText();
    if (text.trimmed() == "")
        return;

    NoteTable ntable(global.db);
    QList<qint32> lids;
    if (!ntable.findNotesByTitle(lids, text))
        if (!ntable.findNotesByTitle(lids, text.trimmed() + "%"))
            if (!ntable.findNotesByNotebook(lids, "%" + text.trimmed() + "%"))
                return;
    Note n;

    // If we have a good return, then we can paste the link, otherwise we fall out
    // to a normal paste.
    if (ntable.get(n, lids[0], false, false)) {
        UserTable utable(global.db);
        User user;
        utable.getUser(user);

        QString href = "evernote:///view/" + QString::number(user.id) + QString("/") +
                       user.shardId + QString("/") +
                       n.guid + QString("/") +
                       n.guid + QString("/");

        QString url = QString("<a href=\"") + href
                      + QString("\" title=\"") + text
                      + QString("\">") + text + QString("</a>");
        QString script = QString("document.execCommand('insertHtml', false, '") + url + QString("');");
        editor->page()->runJavaScript(script);
        return;
    }
}


void NBrowserWindow::insertLatexButtonPressed() {
    this->editLatex("");
}


void NBrowserWindow::insertTableButtonPressed() {
    TableDialog dialog(this);
    dialog.exec();
    if (!dialog.isOkPressed()) {
        return;
    }

    int cols = dialog.getCols();
    int rows = dialog.getRows();
    int width = dialog.getWidth();
    bool percent = dialog.isPercent();
    QString tableStyle = "style=\"-evernote-table:true;border-collapse:collapse;width:%1;table-layout:fixed;margin-left:0px;\"";
    QString cellStyle = "style=\"border-style:solid;border-width:1px;border-color:rgb(211,211,211);padding:10px;margin:0px;width:33.33%;\"";


    QString widthString = QString::number(width);
    if (percent) {
        widthString = widthString + "%";
    }
    QString newHTML = "<table " + tableStyle.arg(widthString) + "><tbody>";

    for (int i = 0; i < rows; i++) {
        newHTML = newHTML + "<tr>";
        for (int j = 0; j < cols; j++) {
            newHTML = newHTML + "<td " + cellStyle + ">&nbsp;</td>";
        }
        newHTML = newHTML + "</tr>";
    }
    newHTML = newHTML + "</tbody></table>";

    QString script = "document.execCommand('insertHtml', false, '" + newHTML + "');";
    editor->page()->runJavaScript(script);
    contentChanged();
}


void NBrowserWindow::insertTableRowButtonPressed() {
    QString js = "function insertTableRow() {"
                 "   var selObj = window.getSelection();"
                 "   var selRange = selObj.getRangeAt(0);"
                 "   var workingNode = window.getSelection().anchorNode.parentNode;"
                 "   var cellCount = 0;"
                 "   while(workingNode != null) { "
                 "      if (workingNode.nodeName.toLowerCase()=='tr') {"
                 "           row = document.createElement('TR');"
                 "           var nodes = workingNode.getElementsByTagName('td');"
                 "           var style = '';"
                 "           for (j=0; j<nodes.length; j=j+1) {"
                 "             if (style == '' && nodes[0].hasAttribute('style')) style = nodes[0].attributes['style'].value;"
                 "             window.browserWindow.printNodeName(style);"
                 "             cell = document.createElement('TD');"
                 "             if (style != '') cell.setAttribute('style',style);"
                 "             cell.innerHTML='&nbsp;';"
                 "             row.appendChild(cell);"
                 "           }"
                 "           workingNode.parentNode.insertBefore(row,workingNode.nextSibling);"
                 "           return;"
                 "      }"
                 "      workingNode = workingNode.parentNode;"
                 "   }"
                 "} insertTableRow();";
    editor->page()->runJavaScript(js);
    contentChanged();
}


void NBrowserWindow::insertTableColumnButtonPressed() {
    if (!editor->insertTableColumnAction->isEnabled())
        return;
    QString js = "function insertTableColumn() {"
                 "   var selObj = window.getSelection();"
                 "   var selRange = selObj.getRangeAt(0);"
                 "   var workingNode = window.getSelection().anchorNode.parentNode;"
                 "   var current = 0;"
                 "   var style = '';"
                 "   while (workingNode.nodeName.toLowerCase() != 'table' && workingNode != null) {"
                 "       if (workingNode.nodeName.toLowerCase() == 'td') {"
                 "          var td = workingNode;"
                 "          if (style == '' && td.hasAttribute('style')) style = td.attributes['style'].value;"
                 "          while (td.previousSibling != null) { "
                 "             current = current+1; td = td.previousSibling;"
                 "          }"
                 "       }"
                 "       workingNode = workingNode.parentNode; "
                 "   }"
                 "   if (workingNode == null) return;"
                 "   for (var i=0; i<workingNode.rows.length; i++) { "
                 "      var cell = workingNode.rows[i].insertCell(current+1); "
                 "      cell.setAttribute('style',style);"
                 //            "          window.browserWindow.printNodeName(cell.style);"
                 "      cell.innerHTML = '&nbsp'; "
                 "   }"
                 "} insertTableColumn();";
    editor->page()->runJavaScript(js);
    contentChanged();
}


void NBrowserWindow::tablePropertiesButtonPressed() {
    if (!editor->tablePropertiesAction->isEnabled())
        return;
    tableCellStyle = "";
    tableStyle = "";

    // First go through the table & find the existing cell & table attributes
    QString js = "function tableProperties() {"
                 "   var selObj = window.getSelection();"
                 "   var selRange = selObj.getRangeAt(0);"
                 "   var workingNode = window.getSelection().anchorNode.parentNode;"
                 "   var current = 0;"
                 "   var style = '';"
                 "   while (workingNode.nodeName.toLowerCase() != 'table' && workingNode != null) {"
                 "       if (workingNode.nodeName.toLowerCase() == 'td') {"
                 "          var td = workingNode;"
                 "          if (style == '' && td.hasAttribute('style')) style = td.attributes['style'].value;"
                 "          while (td.previousSibling != null) { "
                 "             current = current+1; td = td.previousSibling;"
                 "          }"
                 "       }"
                 "       workingNode = workingNode.parentNode; "
                 "   }"
                 "   if (workingNode == null) return;"
                 "   window.browserWindow.setTableCellStyle(style);"
                 "   window.browserWindow.printNodeName(style);"
                 "   if (workingNode.hasAttribute('style')) {"
                 "       var td = workingNode;"
                 "       style = td.attributes['style'].value;"
                 "       window.browserWindow.setTableStyle(style);"
                 "   }"
                 "} tableProperties();";
    editor->page()->runJavaScript(js);
    QLOG_DEBUG() << this->tableStyle;
    QLOG_DEBUG() << this->tableCellStyle;

    TablePropertiesDialog dialog(tableStyle, tableCellStyle);
    dialog.exec();

    if (!dialog.okButtonPressed)
        return;

    QString newTableStyle = dialog.getTableCss();
    QString newCellStyle = dialog.getCellCss();

    // Go through the table & change the styles attributes.
    js = "function setTableProperties() {"
         "   var selObj = window.getSelection();"
         "   var selRange = selObj.getRangeAt(0);"
         "   var workingNode = window.getSelection().anchorNode.parentNode;"
         "   var style = '';"
         "   while (workingNode.nodeName.toLowerCase() != 'table' && workingNode != null) {"
         "       if (workingNode.nodeName.toLowerCase() == 'td') {"
         "          var td = workingNode;"
         "          while (td.previousSibling != null) { "
         "             td = td.previousSibling;"
         "          }"
         "       }"
         "       workingNode = workingNode.parentNode; "
         "   }"
         "   if (workingNode == null) return;"
         "   workingNode.attributes['style'].value = '%1';"
         "   window.browserWindow.setTableCellStyle(style);"
         "   var rowCount = workingNode.rows.length;"
         "   for (var i=0; i<rowCount; i++) {"
         "      var colCount = workingNode.rows[i].cells.length;"
         "      for (var j=0; j<colCount; j++) {"
         "         workingNode.rows[i].cells[j].attributes['style'].value = '%2';"
         "      }"
         "   }"
         "} setTableProperties();";
    js = js.arg(newTableStyle).arg(newCellStyle);
    editor->page()->runJavaScript(js);
    this->editor->isDirty = true;
    microFocusChanged();
}


void NBrowserWindow::deleteTableRowButtonPressed() {
    if (!editor->deleteTableRowAction->isEnabled())
        return;

    QString js = "function deleteTableRow() {"
                 "   var selObj = window.getSelection();"
                 "   var selRange = selObj.getRangeAt(0);"
                 "   var workingNode = window.getSelection().anchorNode.parentNode;"
                 "   var cellCount = 0;"
                 "   while(workingNode != null) { "
                 "      if (workingNode.nodeName.toLowerCase()=='tr') {"
                 "           workingNode.parentNode.removeChild(workingNode);"
                 "           return;"
                 "      }"
                 "      workingNode = workingNode.parentNode;"
                 "   }"
                 "} deleteTableRow();";
    editor->page()->runJavaScript(js);
    contentChanged();
}


void NBrowserWindow::deleteTableColumnButtonPressed() {
    if (!editor->deleteTableColumnAction->isEnabled())
        return;

    QString js = "function deleteTableColumn() {"
                 "   var selObj = window.getSelection();"
                 "   var selRange = selObj.getRangeAt(0);"
                 "   var workingNode = window.getSelection().anchorNode.parentNode;"
                 "   var current = 0;"
                 "   while (workingNode.nodeName.toLowerCase() != 'table' && workingNode != null) {"
                 "       if (workingNode.nodeName.toLowerCase() == 'td') {"
                 "          var td = workingNode;"
                 "          while (td.previousSibling != null) { "
                 "             current = current+1; td = td.previousSibling;"
                 "          }"
                 "       }"
                 "       workingNode = workingNode.parentNode; "
                 "   }"
                 "   if (workingNode == null) return;"
                 "   for (var i=0; i<workingNode.rows.length; i++) { "
                 "      workingNode.rows[i].deleteCell(current); "
                 "   }"
                 "} deleteTableColumn();";
    editor->page()->runJavaScript(js);
    contentChanged();
}


void NBrowserWindow::rotateImageLeftButtonPressed() {
    rotateImage(-90.0);
}


void NBrowserWindow::rotateImageRightButtonPressed() {
    rotateImage(90.0);
}


void NBrowserWindow::rotateImage(qreal
                                 degrees) {

// rotate the image
    QWebSettings::setMaximumPagesInCache(0);
    QWebSettings::setObjectCacheCapacities(0, 0, 0);
    QImage image(global.fileManager.getDbaDirPath() + selectedFileName);
    QMatrix matrix;
    matrix.
            rotate(degrees);
    image = image.transformed(matrix);
    image.
            save(global
                         .fileManager.

            getDbaDirPath()

                 + selectedFileName);
    editor->
            setHtml(editor
                            ->page()->

            toHtml()

    );

// Now, we need to update the note's MD5
    QFile f(global.fileManager.getDbaDirPath() + selectedFileName);
    f.
            open(QIODevice::ReadOnly);
    QByteArray filedata = f.readAll();
    QCryptographicHash hash(QCryptographicHash::Md5);
    QByteArray b = hash.hash(filedata, QCryptographicHash::Md5);
    updateImageHash(b);

// Reload the web page
    editor->
            triggerPageAction(QWebEnginePage::ReloadAndBypassCache);

    contentChanged();

}


void NBrowserWindow::updateImageHash(QByteArray newhash) {
    QString content = editor->page()->toHtml();
    int pos = content.indexOf("<img ");
    for (; pos != -1; pos = content.indexOf("<img ", pos + 1)) {
        int endPos = content.indexOf(">", pos);
        QString section = content.mid(pos, endPos - pos);
        if (section.contains("lid=\"" + QString::number(selectedFileLid) + "\"")) {
            ResourceTable rtable(global.db);
            QString oldhash = section.mid(section.indexOf("hash=\"") + 6);
            oldhash = oldhash.mid(0, oldhash.indexOf("\""));
            section.replace(oldhash, newhash.toHex());
            QString newcontent = content.mid(0, pos) + section + content.mid(endPos);
            QByteArray c;
            c.append(newcontent);
            editor->page()->setContent(c);
            rtable.updateResourceHash(selectedFileLid, newhash);
            return;
        }
    }
}

void NBrowserWindow::imageContextMenu(QString l, QString f) {
    editor->downloadAttachmentAction()->setEnabled(true);
    editor->rotateImageRightAction->setEnabled(true);
    editor->rotateImageLeftAction->setEnabled(true);
    editor->openAction->setEnabled(true);
    editor->downloadImageAction()->setEnabled(true);
    selectedFileName = f;
    selectedFileLid = l.toInt();
}


void NBrowserWindow::attachFile() {
    QFileDialog fileDialog;
    if (attachFilePath != "")
        fileDialog.setDirectory(attachFilePath);
    else
        fileDialog.setDirectory(QDir::homePath());
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    //connect(&fileDialog, SIGNAL(fileSelected(QString)), this, SLOT(attachFileSelected(QString)));
    //fileDialog.exec();
    QStringList list = fileDialog.getOpenFileNames();
    for (int i = 0; i < list.size(); i++) {
        attachFileSelected(list[i]);
    }
}


//****************************************************************
//* MicroFocus changed
//****************************************************************
void NBrowserWindow::microFocusChanged() {
    saveTimer.stop();
    buttonBar->boldButtonWidget->setDown(false);
    buttonBar->italicButtonWidget->setDown(false);
    buttonBar->underlineButtonWidget->setDown(false);
    editor->openAction->setEnabled(false);
    editor->downloadAttachmentAction()->setEnabled(false);
    editor->rotateImageLeftAction->setEnabled(false);
    editor->rotateImageRightAction->setEnabled(false);
    editor->insertTableAction->setEnabled(true);
    editor->insertTableColumnAction->setEnabled(false);
    editor->insertTableRowAction->setEnabled(false);
    editor->tablePropertiesAction->setEnabled(false);
    editor->deleteTableRowAction->setEnabled(false);
    editor->deleteTableColumnAction->setEnabled(false);
    editor->insertLinkAction->setText(tr("Insert Link"));
    editor->removeLinkAction->setEnabled(false);
    editor->insertQuickLinkAction->setEnabled(true);
    editor->rotateImageRightAction->setEnabled(false);
    editor->rotateImageLeftAction->setEnabled(false);

//     QLOG_DEBUG() << editor->page()->inputMethodQuery(Qt::ImCursorPosition).toInt();
//     QLOG_DEBUG() << editor->page()->inputMethodQuery(Qt::ImSurroundingText).toString();

    insertHyperlink = true;
    currentHyperlink = "";
    insideList = false;
    insideTable = false;
    insideEncryption = false;
    forceTextPaste = false;
    insidePre = false;

    if (editor->selectedText().trimmed().length() > 0 && global.javaFound)
        editor->encryptAction->setEnabled(true);
    else
        editor->encryptAction->setEnabled(false);

    //     +QString("            window.browserWindow.printNodeName(workingNode.firstChild.nodeValue);")
    QString js = QString("function getCursorPos() {")
               + QString("    var cursorPos;")
               + QString("    var insideUrl=false;")
               + QString("    if (window.getSelection) {")
               + QString("        var selObj = window.getSelection();")
               + QString("        var selRange = selObj.getRangeAt(0);")
               + QString("        var workingNode = window.getSelection().anchorNode.parentNode;")
               //+QString("    window.browserWindow.printNodeName(workingNode.nodeName);")
               + QString("        while(workingNode != null) { ")
               //+QString("      window.browserWindow.printNodeName(workingNode.nodeName);")
               + QString("            if (workingNode.nodeName=='TABLE') {")
               + QString("                if (workingNode.getAttribute('class').toLowerCase() == 'en-crypt-temp') window.browserWindow.insideEncryptionArea();")
               + QString("            }")
               + QString("            if (workingNode.nodeName=='PRE') window.browserWindow.setInsidePre();")
               + QString("            if (workingNode.nodeName=='B') window.browserWindow.boldActive();")
               + QString("            if (workingNode.nodeName=='I') window.browserWindow.italicsActive();")
               + QString("            if (workingNode.nodeName=='U') window.browserWindow.underlineActive();")
               + QString("            if (workingNode.nodeName=='UL') window.browserWindow.setInsideList();")
               + QString("            if (workingNode.nodeName=='OL') window.browserWindow.setInsideList();")
               + QString("            if (workingNode.nodeName=='LI') window.browserWindow.setInsideList();")
               + QString("            if (workingNode.nodeName=='TBODY') window.browserWindow.setInsideTable();")
               + QString("            if (workingNode.nodeName=='A') {")
               + QString("                 insideUrl = true;")
               + QString("                 for(var x = 0; x < workingNode.attributes.length; x++ ) {")
               + QString("                    if (workingNode.attributes[x].nodeName.toLowerCase() == 'href')")
               + QString("                        window.browserWindow.setInsideLink(workingNode.attributes[x].nodeValue);")
               + QString("                 }")
               + QString("            }")
               + QString("            if (workingNode.nodeName=='SPAN') {")
               + QString("                if (workingNode.getAttribute('style') == 'text-decoration: underline;') window.browserWindow.underlineActive();")
               + QString("            }")
               + QString("            workingNode = workingNode.parentNode;")
               + QString("        }")
               + QString("    }")
               + QString("}  getCursorPos();");

    editor->page()->runJavaScript(js);

    QString js2 = QString("function getFontSize() {") +
                  QString("    var node = document.getSelection().anchorNode;") +
                  QString("    var anchor = (node.nodeType == 3 ? node.parentNode : node);") +
                  QString("      var size = window.getComputedStyle(anchor,null)[\"fontSize\"];") +
                  QString("      var font = window.getComputedStyle(anchor,null)[\"fontFamily\"];") +
                  QString("      window.browserWindow.changeDisplayFontSize(size);") +
                  QString("      window.browserWindow.changeDisplayFontName(font);") +
                  QString("} getFontSize();");
    editor->page()->runJavaScript(js2);

    saveTimer.setInterval(global.autoSaveInterval);
    saveTimer.start();
}


void NBrowserWindow::modifyFontTagAttr(int size) {
    QString js = QString("var nodes = document.getElementsByTagName(\"font\");") +
                 QString("for (var i = 0; i < nodes.length; i++) {") +
             QString("    if (nodes[i].attributes[\"size\"] != null) {") +
             QString("        nodes[i].removeAttribute(\"size\");") +
             QString("        nodes[i].setAttribute(\"style\", \"font-size:" + QString::number(size) + "pt;\");") +
             QString("    }") +
             QString("}");

    editor->page()->runJavaScript(js);
}

// When a font size is selected, and the page content is empty, any keyboard input
// will make font tag generated with size attribute set, which may make the following
// font size setting out of order. So have to replace it with css style. Called only when the content is null.
void NBrowserWindow::correctFontTagAttr() {
    // Only modify the attribute when no content selected, so that the note content is null belongs to this case.
    if (this->editor->selectedHtml() != "") {
        return;
    }

    int size = buttonBar->fontSizes->currentText().toInt();
    if (size <= 0)
        return;

    modifyFontTagAttr(size);
}


void NBrowserWindow::printNodeName(QString v) {
    QLOG_DEBUG() << v;
}


// Tab button pressed
void NBrowserWindow::tabPressed() {
    if (insideEncryption)
        return;
    if (!insideList && !insideTable) {
        QString script_start = "document.execCommand('insertHtml', false, ' &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;');";
        editor->page()->runJavaScript(script_start);
        return;
    }
    if (insideList) {
        shiftRightButtonPressed();
    }
    if (insideTable) {
        QString js = "function getCursorPosition() { "
                     "   var selObj = window.getSelection();"
                     "   var selRange = selObj.getRangeAt(0);"
                     "   var workingNode = window.getSelection().anchorNode;"
                     "   var rowCount = 0;"
                     "   var colCount = 0;"
                     "   while(workingNode != null && workingNode.nodeName.toLowerCase() != 'table') { "
                     "      if (workingNode.nodeName.toLowerCase()=='tr') {"
                     "         rowCount = rowCount+1;"
                     "      }"
                     "      if (workingNode.nodeName.toLowerCase() == 'td') {"
                     "         colCount = colCount+1;"
                     "      }"
                     "      if (workingNode.previousSibling != null)"
                     "          workingNode = workingNode.previousSibling;"
                     "      else "
                     "           workingNode = workingNode.parentNode;"
                     "   }"
                     "   var nodes = workingNode.getElementsByTagName('tr');"
                     "   var tableRows = nodes.length;"
                     "   nodes = nodes[0].getElementsByTagName('td');"
                     "   var tableColumns = nodes.length;"
                     "   window.browserWindow.setTableCursorPositionTab(rowCount, colCount, tableRows, tableColumns);"
                     "} getCursorPosition();";
        editor->page()->runJavaScript(js);
    }

}


// Backtab pressed.
void NBrowserWindow::backtabPressed() {
    if (insideEncryption)
        return;
    if (insideList)
        shiftLeftButtonPressed();
    if (insideTable) {
        QString js = "function getCursorPosition() { "
                     "   var selObj = window.getSelection();"
                     "   var selRange = selObj.getRangeAt(0);"
                     "   var workingNode = window.getSelection().anchorNode;"
                     "   var rowCount = 0;"
                     "   var colCount = 0;"
                     "   while(workingNode != null && workingNode.nodeName.toLowerCase() != 'table') { "
                     "      if (workingNode.nodeName.toLowerCase()=='tr') {"
                     "         rowCount = rowCount+1;"
                     "      }"
                     "      if (workingNode.nodeName.toLowerCase() == 'td') {"
                     "         colCount = colCount+1;"
                     "      }"
                     "      if (workingNode.previousSibling != null)"
                     "          workingNode = workingNode.previousSibling;"
                     "      else "
                     "           workingNode = workingNode.parentNode;"
                     "   }"
                     "   var nodes = workingNode.getElementsByTagName('tr');"
                     "   var tableRows = nodes.length;"
                     "   nodes = nodes[0].getElementsByTagName('td');"
                     "   var tableColumns = nodes.length;"
                     "   window.browserWindow.setTableCursorPositionBackTab(rowCount, colCount, tableRows, tableColumns);"
                     "} getCursorPosition();";
        editor->page()->runJavaScript(js);
    }
}


// Backtab pressed.
bool NBrowserWindow::enterPressed() {
    if (!insidePre)
        return false;

    QString script = "document.execCommand('insertHTML', false, '&#10;&#13;');";

    editor->page()->runJavaScript(script);
    return true;

//     QKeyEvent *down = new QKeyEvent(QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);
//     QCoreApplication::postEvent(editor->editorPage, down);

}


// If a user presses backtab from within a table
void NBrowserWindow::setTableCursorPositionBackTab(int currentRow, int currentCol, int tableRows, int tableColumns) {
    // suppress unused warninsg
    Q_UNUSED(tableRows);
    Q_UNUSED(tableColumns);

    // Determine what key to emulate.
    if (currentRow == 1 && currentCol == 1) {
        return;
    }
    QKeyEvent *up = new QKeyEvent(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
    QCoreApplication::postEvent(editor->editorPage, up);
}


// If a user presses backtab from within a table
void NBrowserWindow::setTableCursorPositionTab(int currentRow, int currentCol, int tableRows, int tableColumns) {
    if (currentRow == tableRows && currentCol == tableColumns) {
        this->insertTableRowButtonPressed();
    }
    QKeyEvent *down = new QKeyEvent(QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);
    QCoreApplication::postEvent(editor->editorPage, down);
}


// Set the background color of a note
void NBrowserWindow::setBackgroundColor(QString value) {
    QString js = QString("function changeBackground(color) {")
                 + QString("document.body.style.background = color;")
                 + QString("}")
                 + QString("changeBackground('" + value + "');");
    editor->page()->runJavaScript(js);

    setDirty(this->lid, true);
    this->editor->isDirty = true;
    editor->setFocus();
    microFocusChanged();
}


// The user clicked a link in the note
void NBrowserWindow::linkClicked(const QUrl url) {

    QLOG_DEBUG() << "linkClicked: " << url;


    if (url.toString().startsWith("latex:///", Qt::CaseInsensitive)) {
        editLatex(url.toString().mid(9));
        return;
    }
    if (url.toString().startsWith("evernote:/view/", Qt::CaseInsensitive) ||
        url.toString().startsWith("evernote:///view/", Qt::CaseInsensitive)) {

        QStringList tokens;
        if (url.toString().startsWith("evernote:/view/", Qt::CaseInsensitive))
            tokens = url.toString().replace("evernote:/view/", "").split("/", QString::SkipEmptyParts);
        else
            tokens = url.toString().replace("evernote:///view/", "").split("/", QString::SkipEmptyParts);
        QString oguid = tokens[2];
        QString eguid = tokens[3];
        NoteTable ntable(global.db);
        qint32 newlid = ntable.getLid(eguid);
        if (newlid <= 0)
            newlid = ntable.getLid(oguid);
        if (newlid <= 0)
            return;

        bool newExternalWindow = false;
        bool newTab = false;
        if (QApplication::keyboardModifiers() & Qt::ShiftModifier) {
            //if (global.getMiddleClickAction() == MOUSE_MIDDLE_CLICK_NEW_WINDOW)
            newExternalWindow = true;
            //else
            //    newTab = true;
        } else {
            // Setup a new filter
            FilterCriteria *criteria = new FilterCriteria();
            global.getCurrentCriteria()->duplicate(*criteria);
            criteria->unsetSelectedNotes();
            criteria->unsetLid();
            criteria->setLid(newlid);
            global.appendFilter(criteria);
        }
        emit(evernoteLinkClicked(newlid, newTab, newExternalWindow));

        return;
    }
    if (url.toString().startsWith("nnres:", Qt::CaseInsensitive)) {
        if (url.toString().endsWith("/vnd.evernote.ink")) {
            QMessageBox::information(this, tr("Unable Open"), QString(
                    tr("This is an ink note.\nInk notes are not supported since Evernote has not\n published any specifications on them\nand I'm too lazy to figure them out by myself.")));
            return;
        }
        QString filepath = global.fileManager.getDbaDirPath();
// Windows check
#ifdef _WIN32
        filepath = filepath.replace("\\", "/");
#endif // End windows check
        QString fullName = url.toString().mid(6).replace(filepath, "");
        filepath = filepath.replace("\\", "/");
        QLOG_DEBUG() << "linkClicked: dba path=" << global.fileManager.getDbaDirPath();

        int index = fullName.lastIndexOf(".");
        QString guid = "";
        if (index != -1) {
            guid = fullName.mid(0, index);
        } else
            guid = fullName;
        QDirIterator dirIt(global.fileManager.getDbaDirPath());
        QString fileUrl = "";
        while (dirIt.hasNext()) {
            if (QFileInfo(dirIt.filePath()).isFile() && QFileInfo(dirIt.filePath()).baseName() == guid) {
                fileUrl = dirIt.fileName();
            }
            dirIt.next();
        }
        if (fileUrl == "")
            return;
        fileUrl = global.fileManager.getDbaDirPath() + fileUrl;

// Windows check
#ifdef _WIN32
        fileUrl = fileUrl.replace("\\", "/");
#endif // End windows check
        global.resourceWatcher->addPath(fileUrl);
        QLOG_DEBUG() << "Opening attachment file (QDesktopServices::openUrl) url=" << fileUrl;
        QDesktopServices::openUrl(fileUrl);
        return;
    }

    QLOG_DEBUG() << "Opening attachment (QDesktopServices::openUrl) url=" << url;
    QDesktopServices::openUrl(url);
}


// show/hide view source window
void NBrowserWindow::showSource(bool value) {
    if (value) {
        setSource();
    }
    sourceEdit->setVisible(value);
}


// Toggle the show source button
void NBrowserWindow::toggleSource() {
    if (sourceEdit == nullptr) {
        // setup the source editor
        sourceEdit = new QTextEdit(this);
        sourceEdit->setVisible(false);
        sourceEdit->setTabChangesFocus(true);

        QFont font;
        font.setFamily("Courier");
        font.setFixedPitch(true);
        global.getGuiFont(font);
        sourceEdit->setFont(global.getGuiFont(font));

        editorSplitter->addWidget(sourceEdit);

        connect(sourceEdit, SIGNAL(textChanged()), this, SLOT(noteSourceUpdated()));
        connect(editor->page(), SIGNAL(contentsChanged()), this, SLOT(setSource()));
    }

    if (sourceEdit->isVisible())
        showSource(false);
    else
        showSource(true);
}


// Clear out the window's contents
void NBrowserWindow::clear() {
    if (sourceEdit != nullptr) {
        sourceEdit->blockSignals(true);
        sourceEdit->setPlainText("");
        sourceEdit->setReadOnly(true);
        sourceEdit->blockSignals(false);
    }
    editor->blockSignals(true);
    editor->setContent("<html><body></body></html>");
    editor->page()->runJavaScript("document.documentElement.contentEditable = false");
    lid = -1;
    editor->blockSignals(false);

    noteTitle.blockSignals(true);
    noteTitle.setTitle(-1, "", "");
    noteTitle.blockSignals(false);

    tagEditor.blockSignals(true);
    tagEditor.clear();
    tagEditor.blockSignals(false);

//    authorEditor.blockSignals(true);
//    authorEditor.setText("");
//    authorEditor.blockSignals(false);

    urlEditor.blockSignals(true);
    urlEditor.setUrl(-1, "");
    urlEditor.blockSignals(false);

//    dateEditor.setEnabled(false);
//    editor->page()->runJavaScript("document.documentElement.contentEditable = false");

    dateEditor.clear();
}


// Set the source for the "show source" button
void NBrowserWindow::setSource() {
    if (sourceEdit == nullptr || sourceEdit->hasFocus())
        return;

    QString text = editor->editorPage->toHtml();
    sourceEdit->blockSignals(true);
    int body = text.indexOf("<body", Qt::CaseInsensitive);
    if (body != -1) {
        body = text.indexOf(">", body);
        if (body != -1) {
            sourceEditHeader = text.mid(0, body + 1);
            text = text.mid(body + 1);
        }
    }
    text = text.replace("</body></html>", "");
    sourceEdit->setPlainText(text);
    //   sourceEdit->setReadOnly(true);
    sourceEdit->setReadOnly(!editor->page()->isContentEditable());
    sourceEdit->blockSignals(false);
}


// Expose the programs to the javascript process
void NBrowserWindow::exposeToJavascript() {
    editor->page()->addToJavaScriptWindowObject("browserWindow", this);
}


// If we are within bold text, set the bold button active
void NBrowserWindow::boldActive() {
    buttonBar->boldButtonWidget->setDown(true);
}


// If we are within italics text, make the text button active
void NBrowserWindow::italicsActive() {
    buttonBar->italicButtonWidget->setDown(true);
}


// If we are within encrypted text, make sure we force a paste text
void NBrowserWindow::insideEncryptionArea() {
    insideEncryption = true;
    forceTextPaste = true;
}


// If we are within underlined text, make the button active
void NBrowserWindow::underlineActive() {
    buttonBar->underlineButtonWidget->setDown(true);
}


// Set true if we are within some type of list
void NBrowserWindow::setInsideList() {
    insideList = true;
}


// If we are inside a pre-formatted tag <pre>
void NBrowserWindow::setInsidePre() {
    this->insidePre = true;
}


// If we are within a table, set the menu options active
void NBrowserWindow::setInsideTable() {
    editor->insertTableAction->setEnabled(false);
    editor->insertTableRowAction->setEnabled(true);
    editor->tablePropertiesAction->setEnabled(true);
    editor->insertTableColumnAction->setEnabled(true);
    editor->deleteTableRowAction->setEnabled(true);
    editor->deleteTableColumnAction->setEnabled(true);
    editor->encryptAction->setEnabled(false);
    insideTable = true;
}


// Set if we are within a link
void NBrowserWindow::setInsideLink(QString link) {
    currentHyperlink = link;
    editor->insertLinkAction->setText(tr("Edit Link"));
    editor->removeLinkAction->setEnabled(true);
    currentHyperlink = link;
    insertHyperlink = false;
}


// Edit a LaTeX formula
void NBrowserWindow::editLatex(QString incomingLid) {

    QString formula = editor->selectedText();
    QLOG_DEBUG() << "edit latex incomingLid=" << incomingLid << ", formula=" << formula;

    QString oldFormula = "";
    if (formula.trimmed() == "\n" || formula.trimmed() == "") {
        InsertLatexDialog dialog;
        if (incomingLid.trimmed() != "") {
            Resource r;
            ResourceTable resTable(global.db);
            resTable.get(r, incomingLid.toInt(), false);

            if (r.attributes.isSet()) {
                ResourceAttributes attributes;
                attributes = r.attributes;
                if (attributes.sourceURL.isSet()) {
                    QString origFormula = NixnoteStringUtils::extractLatexFormulaFromResourceUrl(attributes.sourceURL);
                    QLOG_DEBUG() << "edit latex origFormula=" << origFormula;
                    oldFormula = origFormula;
                    dialog.setFormula(origFormula);
                }
            }
        }
        dialog.exec();
        if (!dialog.okPressed()) {
            QLOG_DEBUG() << "latex dialog cancelled";
            return;
        }
        formula = dialog.getFormula().trimmed();
    }
    QLOG_DEBUG() << "latex dialog finished, formula=" << formula;

    ConfigStore cs(global.db);
    qint32 newlid = cs.incrementLidCounter();
    Resource r;
    NoteTable ntable(global.db);
    ResourceTable rtable(global.db);
    QString outfile = global.fileManager.getDbaDirPath() + QString::number(newlid) + QString(".gif");

    // Run it through "mimetex" to create the gif
    QProcess latexProcess;
    QStringList args;
    args.append("-e");
    args.append(outfile);
    args.append(formula);
    QLOG_INFO() << "About to start: " << "mimetex" << args;
    latexProcess.start("mimetex", args, QIODevice::ReadWrite | QIODevice::Unbuffered);
    latexProcess.waitForStarted();
    latexProcess.waitForFinished();
    QLOG_INFO() << " Result: " << latexProcess.state();
    QLOG_DEBUG() << "mimetex Errors:" << latexProcess.readAllStandardError();
    QLOG_DEBUG() << "mimetex Output:" << latexProcess.readAllStandardOutput();

    // Now, check if the file exists.  If it does, we continue to create the resource
    QFile f(outfile);
    if (!f.exists()) {
        QMessageBox msgBox;
        msgBox.setText(tr("Unable to create LaTeX image"));
        msgBox.setInformativeText(tr("Unable to create LaTeX image.  Are you sure mimetex is installed?"));
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        return;
    }
    f.open(QIODevice::ReadOnly);
    QByteArray data = f.readAll();
    f.close();
    f.open(QIODevice::ReadOnly);
    QCryptographicHash md5hash(QCryptographicHash::Md5);
    QByteArray hash = md5hash.hash(data, QCryptographicHash::Md5);

    Data d;
    if (r.data.isSet())
        d = r.data;
    d.body = f.read(data.size());
    r.data = d;
    f.close();
    d.bodyHash = hash;
    d.size = data.size();
    r.data = d;

    r.guid = QString::number(newlid);
    r.noteGuid = ntable.getGuid(lid);

    r.mime = "image/gif";
    r.active = true;
    r.updateSequenceNum = 0;
    r.width = 0;
    r.height = 0;
    r.duration = 0;

    ResourceAttributes a;
    a.attachment = false;
    a.sourceURL = NixnoteStringUtils::createLatexResourceUrl(formula);
    r.attributes = a;

    rtable.add(newlid, r, true, lid);

    // do the actual insert into the note
    QString buffer;
    buffer.append("<a onmouseover=\"cursor:&apos;hand&apos;\" title=\"");
    buffer.append(NixnoteStringUtils::urlencode(formula));
    buffer.append("\" href=\"latex:///");
    buffer.append(QString::number(newlid));
    buffer.append("\">");
    buffer.append("<img src=\"file://");
    buffer.append(outfile);
    buffer.append("\" type=\"image/gif\" hash=\"");
    buffer.append(hash.toHex());
    buffer.append("\" onContextMenu=\"window.browser.imageContextMenu(&apos;");
    buffer.append(QString::number(newlid));
    buffer.append("&apos;, &apos;");
    buffer.append(outfile);
    buffer.append("&apos;);\" ");
    buffer.append(" en-tag=\"en-latex\" lid=\"");
    buffer.append(QString::number(newlid));
    buffer.append("\"></a>");

    QLOG_DEBUG() << "latex, final html=" << buffer;

    // If this is a new formula, we insert it, otherwise we replace the old one.
    if (oldFormula == "") {
        QLOG_DEBUG() << "latex: insert";
        QString script_start = "document.execCommand('insertHTML', false, '";
        QString script_end = "');";

        editor->page()->runJavaScript(script_start + buffer + script_end);
    } else {
        QLOG_DEBUG() << "latex: replace";
        QString oldHtml = editor->page()->toHtml();
        int startPos = oldHtml.indexOf("<a");

        bool found = false;
        QString sliceId("latex:///" + incomingLid);

        while (startPos != -1) {
            int endPos = oldHtml.indexOf("</a>", startPos);
            if (endPos != -1) {
                QString slice = oldHtml.mid(startPos, endPos - startPos + 4);
                QLOG_DEBUG() << "latex: slice=" << slice;
                if (slice.contains(sliceId)) {
                    QLOG_DEBUG() << "latex: replace - insertion point found slice=" << slice;
                    oldHtml.replace(slice, buffer);
                    found = true;
                    break;
                }
                startPos = oldHtml.indexOf("<a", endPos);
            }
        }

        if (found) {
            editor->page()->setHtml(oldHtml);
            editor->reload();
            contentChanged();
        } else {
            QLOG_ERROR() << "latex: insertion point not found!";
        }
    }
}


// Set the focus to the note title
void NBrowserWindow::focusTitle() {
    this->noteTitle.setFocus();
}


// Set the focus to the note
void NBrowserWindow::focusNote() {
    this->editor->setFocus();
}


// Insert the date/time into a note
void NBrowserWindow::insertDatetime() {
    const QString format = global.getDateTimeFormat();
    insertDateTimeUsingFormat(format);
}

void NBrowserWindow::insertDate() {
    const QString format = global.getDateFormat();
    insertDateTimeUsingFormat(format);
}

void NBrowserWindow::insertTime() {
    const QString format = global.getTimeFormat();
    insertDateTimeUsingFormat(format);
}

void NBrowserWindow::insertDateTimeUsingFormat(const QString &format) const {
    QDateTime dt = QDateTime::currentDateTime();
    QString dts = dt.toString(format);
    editor->page()->runJavaScript("document.execCommand('insertHtml', false, '" + dts + "');");
    editor->setFocus();
}


// Insert an image into the editor
void NBrowserWindow::insertImage(const QMimeData *mime) {
    QLOG_DEBUG() << "insertImage";

    // Get the image from the clipboard and save it into a QByteArray
    // that can be saved
    QImage img = qvariant_cast<QImage>(mime->imageData());
//    QClipboard *clipboard = global.clipboard;
//    QImage img = clipboard->pixmap().toImage();
    QByteArray imageBa;
    QBuffer b(&imageBa);
    b.open(QIODevice::WriteOnly);
    img.save(&b, "PNG");

    QString script_start = "document.execCommand('insertHTML', false, '";
    QString script_end = "');";

    Resource newRes;
    qint32 rlid = createResource(newRes, 0, imageBa, "image/png", false, "");
    if (rlid <= 0)
        return;

    // The resource is done, now we need to add it to the
    // note body
    QString g = QString::number(rlid) + QString(".png");
    QString path = global.fileManager.getDbaDirPath() + g;

    // do the actual insert into the note
    QString buffer;
    Data d;
    if (newRes.data.isSet())
        d = newRes.data;
    QByteArray hash;
    if (d.bodyHash.isSet())
        hash = d.bodyHash;
    buffer.append("<img src=\"file://");
#ifdef _WIN32
    buffer.append("/");
#endif
    buffer.append(path);
    buffer.append("\" type=\"image/png\" hash=\"");
    buffer.append(hash.toHex());
    buffer.append("\" onContextMenu=\"window.browser.imageContextMenu(&apos;");
    buffer.append(QString::number(rlid));
    buffer.append("&apos;, &apos;");
    buffer.append(g);
    buffer.append("&apos;);\" ");
    buffer.append(" en-tag=\"en-media\" style=\"cursor: default;\" lid=\"");
    buffer.append(QString::number(rlid));
    buffer.append("\">");

    // Insert the actual note
    editor->page()->runJavaScript(
            script_start + buffer + script_end);

    return;
}


// Create  a new resource and add it to the database
qint32 NBrowserWindow::createResource(Resource &r, int sequence, QByteArray data, QString mime, bool attachment,
                                      QString filename) {
    ConfigStore cs(global.db);
    qint32 rlid = cs.incrementLidCounter();

    QByteArray hash = QCryptographicHash::hash(data, QCryptographicHash::Md5);

    QString guid = QString::number(rlid);
    NoteTable noteTable(global.db);
    r.guid = guid;
    r.noteGuid = noteTable.getGuid(lid);
    QString noteguid = r.noteGuid;
    if (noteguid == "")
        return 0;
    r.mime = mime;
    r.active = true;
    r.updateSequenceNum = sequence;
    r.width = 0;
    r.height = 0;
    r.duration = 0;
    ResourceAttributes a;
    if (r.attributes.isSet())
        a = r.attributes;
    a.attachment = attachment;
    if (filename != "") {
        a.fileName = filename;
    }

    Data d;
    d.body = data;
    d.bodyHash = hash;
    d.size = data.size();

    r.data = d;
    r.attributes = a;
    ResourceTable resourceTable(global.db);
    resourceTable.add(rlid, r, true, lid);

    return rlid;
}


// Prepare the email for sending.  This function scans through
// the email for images & attachments.  The resulting
// MimeMessage has all of the email contents.
void NBrowserWindow::prepareEmailMessage(MimeMessage *message, QString note) {
    MimeHtml *text = new MimeHtml();

    // Prepare the massage the same as if we were printing it.
    QString contents = this->stripContentsForPrint();
    QString textContents = editor->page()->currentFrame()->toPlainText();
    QStringList images;
    QStringList attachments;

    // Now, go thgough & reformat all the img tags.
    int cidCount = 0;
    int pos = contents.indexOf("src=\"file:");
    while (pos >= 0) {
        QString localFile = contents.mid(pos + 13);
        int endPos = localFile.indexOf("\"");
        localFile = localFile.mid(0, endPos);
        images.append(localFile);
        endPos = pos + endPos;
        QString part1 = contents.mid(0, pos);
        QString part2 = contents.mid(endPos + 14);
        cidCount++;
        contents = part1 + "src='cid:file" + QString::number(cidCount) + "'" + part2;

        pos = contents.indexOf("src=\"file:", pos + 5);
    }

    // next, look for all the attachments
    pos = contents.indexOf("href=\"nnres:");
    while (pos != -1) {
        QString localFile = contents.mid(pos + 12);
        int endPos = localFile.indexOf("\"");
        localFile = localFile.mid(0, endPos);
        attachments.append(localFile);
        cidCount++;
        pos = contents.indexOf("href=\"nnres:", pos + 5);
    }

    // If the user adds a note, then prepend it to the beginning.
    if (note.trimmed() != "") {
        int pos = contents.indexOf("<body");
        int endPos = contents.indexOf(">", pos);
        contents.insert(endPos + 1, Qt::escape(note) + "<p><p><hr><p>");
    }
    text->setHtml(contents);
    message->addPart(text);


    // Add all the images
    for (int i = 0; i < images.size(); i++) {
        MimeReference mimeRef;
        QString localFile = images[i];
        QString mime = mimeRef.getMimeFromFileName(localFile);
        MimeInlineFile *file = new MimeInlineFile(new QFile(localFile));
        QString lidFile = localFile.mid(localFile.lastIndexOf(QDir::separator()) + 1);
        qint32 lid = lidFile.mid(0, lidFile.lastIndexOf(".")).toInt();
        ResourceTable rtable(global.db);
        Resource r;
        ResourceAttributes ra;
        if (rtable.get(r, lid, false) && r.attributes.isSet()) {
            ra = r.attributes;
            if (ra.fileName.isSet())
                file->setContentName(ra.fileName);
        }
        file->setContentId("file" + QString::number(i + 1));
        file->setContentType(mime);
        message->addPart(file);
    }

    // Add all the attachments
    for (int i = 0; i < attachments.size(); i++) {
        MimeReference mimeRef;
        QString localFile = attachments[i];
        QString mime = mimeRef.getMimeFromFileName(localFile);
        MimeInlineFile *file = new MimeInlineFile(new QFile(localFile));
        QString lidFile = localFile.mid(localFile.lastIndexOf(QDir::separator()) + 1);
        qint32 lid = lidFile.mid(0, lidFile.lastIndexOf(".")).toInt();
        ResourceTable rtable(global.db);
        Resource r;
        ResourceAttributes ra;
        if (rtable.get(r, lid, false) && r.attributes.isSet()) {
            ra = r.attributes;
            if (ra.fileName.isSet())
                file->setContentName(ra.fileName);
        }
        file->setContentType(mime);
        message->addPart(file);
    }
    return;

}


// Email current note.
void NBrowserWindow::emailNote() {
    global.settings->beginGroup(INI_GROUP_EMAIL);
    QString server = global.settings->value("smtpServer", "").toString();
    int port = global.settings->value("smtpPort", 25).toInt();
    QString smtpConnectionType = global.settings->value("smtpConnectionType", "TcpConnection").toString();
    QString userid = global.settings->value("userid", "").toString();
    QString password = global.settings->value("password", "").toString();
    QString senderEmail = global.settings->value("senderEmail", "").toString();
    QString senderName = global.settings->value("senderName", "").toString();
    global.settings->endGroup();

    if (senderEmail.trimmed() == "" || server.trimmed() == "") {
        QMessageBox::critical(this, tr("Setup Error"),
                              tr("SMTP Server has not been setup.\n\nPlease specify server settings\nin the Preferences menu."),
                              QMessageBox::Ok);
        return;
    }

    EmailDialog emailDialog;
    emailDialog.subject->setText(noteTitle.text());
    emailDialog.exec();
    if (emailDialog.cancelPressed)
        return;
    emit(setMessage(tr("Sending Email. Please be patient.")));

    QStringList toAddresses = emailDialog.getToAddresses();
    QStringList ccAddresses = emailDialog.getCcAddresses();
    QStringList bccAddresses = emailDialog.getBccAddresses();

    if (senderName.trimmed() == "")
        senderName = senderEmail;

    SmtpClient::ConnectionType type = SmtpClient::TcpConnection;
    if (smtpConnectionType == "SslConnection")
        type = SmtpClient::SslConnection;
    if (smtpConnectionType == "TlsConnection")
        type = SmtpClient::TlsConnection;

    SmtpClient smtp(server, port, type);
    smtp.setResponseTimeout(-1);

    // We need to set the username (your email address) and password
    // for smtp authentication.
    smtp.setUser(userid);
    smtp.setPassword(password);

    // Now we create a MimeMessage object. This is the email.
    MimeMessage message;

    EmailAddress sender(senderEmail, senderName);
    message.setSender(&sender);

    for (int i = 0; i < toAddresses.size(); i++) {
        EmailAddress *to = new EmailAddress(toAddresses[i], toAddresses[i]);
        message.addRecipient(to);
    }

    for (int i = 0; i < ccAddresses.size(); i++) {
        EmailAddress *cc = new EmailAddress(ccAddresses[i], ccAddresses[i]);
        message.addRecipient(cc);
    }


    if (emailDialog.ccSelf->isChecked()) {
        EmailAddress *cc = new EmailAddress(senderEmail, senderName);
        message.addRecipient(cc);
    }

    for (int i = 0; i < bccAddresses.size(); i++) {
        EmailAddress *bcc = new EmailAddress(bccAddresses[i], bccAddresses[i]);
        message.addRecipient(bcc);
    }

    // Set the subject
    message.setSubject(emailDialog.subject->text().trimmed());

    // Build the note content
    QString text = emailDialog.note->toPlainText();
    prepareEmailMessage(&message, text);

    // Send the actual message.
    if (!smtp.connectToHost()) {
        QLOG_ERROR() << "Failed to connect to host!";
        QMessageBox::critical(this, tr("Connection Error"), tr("Unable to connect to host."), QMessageBox::Ok);
        return;
    }

    if (!smtp.login()) {
        QLOG_ERROR() << "Failed to login!";
        QMessageBox::critical(this, tr("Login Error"), tr("Unable to login."), QMessageBox::Ok);
        return;
    }

    if (!smtp.sendMail(message)) {
        QMessageBox::critical(this, tr("Send Error"), tr("Unable to send email."), QMessageBox::Ok);
        QLOG_ERROR() << "Failed to send mail!";
        return;
    }

    smtp.quit();
    emit(setMessage("Message Sent"));
    //    QMessageBox::information(this, tr("Message Sent"), tr("Message sent."), QMessageBox::Ok);
}


// Strip the contents from the current webview in preparation for printing.
QString NBrowserWindow::stripContentsForPrint() {
    // Start removing object tags
    QString contents = this->editor->selectedHtml().trimmed();
    if (contents == "")
        contents = editor->editorPage->toHtml();
    int pos = contents.indexOf("<object");
    while (pos != -1) {
        int endPos = contents.indexOf(">", pos);
        QString lidString = contents.mid(contents.indexOf("lid=", pos) + 5);
        lidString = lidString.mid(0, lidString.indexOf("\" "));
#ifndef _WIN32
        contents = contents.mid(0, pos) + "<img src=\"file://" +
                   global.fileManager.getTmpDirPath() + lidString +
                   QString("-print.png\" width=\"10%\" height=\"10%\"></img>") + contents.mid(endPos + 1);
#else
        contents = contents.mid(0,pos) + "<img src=\"file:///" +
                global.fileManager.getTmpDirPath() + lidString +
                QString("-print.png\" width=\"10%\" height=\"10%\"></img>")+contents.mid(endPos+1);
#endif
        pos = contents.indexOf("<object", endPos);
    }
    return contents.replace("src=\"file:////", "src=\"/");
}


// Do a print preview of this note.  This works
// in much the same way as printNote().  It removes all the
// <object> tags & replaces them with <img>.
void NBrowserWindow::printPreviewNote() {
    if (printPreviewPage == nullptr) {
        printPreviewPage = new QTextEdit();
        printPreviewPage->setVisible(false);
    }
    QString contents = stripContentsForPrint();

    // Load the print page.  When it is ready the printReady() slot will
    // do the actual print
    printPreviewPage->setHtml(contents.toUtf8());
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer, this);
    preview.setWindowFlags(Qt::Window);
    connect(&preview, SIGNAL(paintRequested(QPrinter * )), this, SLOT(printPreviewReady(QPrinter * )));
    preview.exec();
}


// Slot for when the printPreview is ready.
void NBrowserWindow::printPreviewReady(QPrinter *printer) {
    printPreviewPage->print(printer);
}


// Print the contents of a note.  Basically it loops through the
// note and replaces the <object> tags with <img> tags.  The plugin
// object should be creating temporary images for the print.
void NBrowserWindow::printNote() {
    if (printPage == nullptr) {
        printPage = new QTextEdit();
        printPage->setVisible(false);
    }
    QString contents = stripContentsForPrint();

    // Load the print page.  When it is ready the printReady() slot will
    // do the actual print
    printPage->setDocumentTitle(editor->title());
    printPage->setHtml(contents.toUtf8());

    QPrinter *printer;

    global.settings->beginGroup(INI_GROUP_PRINTER);
    QPrinter::Orientation orientation = static_cast<QPrinter::Orientation>(global.settings->value(
            "orientation").toUInt());
    QString name = global.settings->value("printerName", "").toString();
    QPrinter::OutputFormat format = static_cast<QPrinter::OutputFormat>(global.settings->value("outputFormat",
                                                                                               0).toUInt());
    QPrinter::PaperSize pageSize = static_cast<QPrinter::PageSize>(global.settings->value("pageSize", 2).toUInt());
    QPrinter::ColorMode colorMode = static_cast<QPrinter::ColorMode>(global.settings->value("colorMode", 1).toUInt());
    QString fileName = global.settings->value("outputFileName", "").toString();
    global.settings->endGroup();

    bool error = false;
    printer = new QPrinter();
    printer->setPageSize(pageSize);
    printer->setOutputFormat(format);
    printer->setOrientation(orientation);
    printer->setColorMode(colorMode);


    if (fastPrint) {
        if (format == QPrinter::PdfFormat) {
            if (fileName == "")
                error = true;
            else
                printer->setOutputFileName(fileName);
        } else {
            if (name == "")
                error = true;
            else
                printer->setPrinterName(name);
        }
        if (error) {
            fastPrint = false;

            // Re-initialize printer object so we don't have any bogus
            // values from settings.
            delete printer;
            printer = new QPrinter();
        }
    }

    if (!fastPrint) {
        if (format == QPrinter::PdfFormat && fileName.trimmed() != "")
            printer->setOutputFileName(fileName);
        if (name.trimmed() != "")
            printer->setPrinterName(name);

        QPrintDialog dialog(printer);
        if (dialog.exec() == QDialog::Accepted) {
            printer = dialog.printer();
            global.settings->beginGroup(INI_GROUP_PRINTER);
            global.settings->setValue("orientation", printer->orientation());
            global.settings->setValue("printerName", printer->printerName());
            global.settings->setValue("outputFormat", printer->outputFormat());
            global.settings->setValue("outputFileName", printer->outputFileName());
            global.settings->setValue("pageSize", printer->pageSize());
            global.settings->setValue("colorMode", printer->colorMode());
            global.settings->endGroup();
            printPage->print(printer);
        }
    } else {
        printPage->print(printer);
//        QTextDocument td;
//        td.setHtml(printPage->toHtml());
//        td.setPageSize(printer->pageRect().size());
//            QRect innerRect = printer->pageRect();
//            innerRect.setTop(innerRect.top() + 20);
//            innerRect.setBottom(innerRect.bottom() - 30);
//            QRect contentRect = QRect(QPoint(0,0), td.size().toSize());
//            QRect currentRect = QRect(QPoint(0,0), innerRect.size());
//            QPainter painter(printer);
//            int count = 0;
//            painter.save();
//            painter.translate(0, 30);
//            while (currentRect.intersects(contentRect) && count < td.pageCount()) {
//                td.drawContents(&painter, currentRect);
//                count++;
//                currentRect.translate(0, currentRect.height());
//                painter.restore();
//                painter.drawText(10, 10, editor->title());
//                painter.drawText(10, printer->pageRect().bottom() - 10, QString("Page %1 of %2").arg(count).arg(td.pageCount()));
//                painter.save();
//                painter.translate(0, -currentRect.height() * count + 30);
//                if (currentRect.intersects(contentRect) && count < td.pageCount())
//                    printer->newPage();
//            }
//            painter.restore();
//            painter.end();
    }

    this->fastPrint = false;
}


void NBrowserWindow::noteSourceUpdated() {
    scrollPoint = editor->page()->scrollPosition();
    connect(editor, SIGNAL(loadFinished(bool)), this, SLOT(repositionAfterSourceEdit(bool)));
    QByteArray ba;
    QString source = sourceEdit->toPlainText();
    //source = Qt::escape(source);
    ba.append(sourceEditHeader);
    ba.append(source);
    ba.append("</body></html>");
    editor->setContent(ba);
    this->editor->isDirty = true;
    noteContentEdited();
}


// Called after the source is edited and a reposition is needed to keep the page from being positioned at the top
void NBrowserWindow::repositionAfterSourceEdit(bool) {
    editor->page()->setScrollPosition(scrollPoint);
    disconnect(editor, SIGNAL(loadFinished(bool)), this, SLOT(repositionAfterSourceEdit(bool)));
}


// Update a resource's hash if it was edited somewhere else
void NBrowserWindow::updateResourceHash(qint32 noteLid, QByteArray oldHash, QByteArray newHash) {
    if (noteLid != lid)
        return;

    QString content = editor->editorPage->documentElement().toOuterXml();

    // Start going through & looking for the old hash
    int pos = content.indexOf("<body");
    int endPos;
    int hashPos = -1;
    QString hashString = "hash=\"" + oldHash.toHex() + "\"";
    while (pos != -1) {
        endPos = content.indexOf(">", pos);  // Find the matching end of the tag
        hashPos = content.indexOf(hashString, pos);
        if (hashPos < endPos && hashPos != -1) {  // If we found the hash, begin the update
            QString startString = content.mid(0, hashPos);
            QString endString = content.mid(hashPos + hashString.length());
            QString newContent = startString + "hash=\"" + newHash.toHex() + "\"" + endString;
            QByteArray byteArray;
            byteArray.append(newContent);
            editor->setContent(byteArray);
            noteUpdated(lid);
            return;
        } else {
            pos = content.indexOf("<", pos + 1);
        }
    }


}


void NBrowserWindow::attachFileSelected(QString filename) {
    QLOG_INFO() << "attachFileSelected: attaching file: " << filename;

    // Read in the file
    QFile file(filename);

    // Save prior path for future use
    QFileInfo fileInfo(file);
    attachFilePath = fileInfo.path();

    file.open(QIODevice::ReadOnly);
    QByteArray ba = file.readAll();
    file.close();

    QString script_start = "document.execCommand('insertHTML', false, '";
    QString script_end = "');";

    MimeReference mimeRef;
    QString extension = filename;
    int endPos = filename.lastIndexOf(".");
    if (endPos != -1)
        extension = extension.mid(endPos);
    QString mime = mimeRef.getMimeFromExtension(extension);
    Resource newRes;
    bool attachment = true;
    if (mime == "application/pdf" || mime.startsWith("image/"))
        attachment = false;

    qint32 rlid = createResource(newRes, 0, ba, mime, attachment, QFileInfo(filename).fileName());
    QByteArray hash;
    if (newRes.data.isSet()) {
        Data d = newRes.data;
        if (d.bodyHash.isSet())
            hash = d.bodyHash;
    }
    QLOG_INFO() << "attachFileSelected: attaching file rlid=" << rlid;
    if (rlid <= 0) {
        QLOG_INFO() << "attachFileSelected: FAIL";
        return;
    }

    // If we have an image, then insert it.
    if (mime.startsWith("image", Qt::CaseInsensitive)) {
        QLOG_INFO() << "attachFileSelected: image insert";

        // The resource is done, now we need to add it to the
        // note body
        QString g = QString::number(rlid) + extension;
        QString path = global.fileManager.getDbaDirPath() + g;

        // do the actual insert into the note
        QString buffer;
        QByteArray hash = "";
        if (newRes.data.isSet()) {
            Data d = newRes.data;
            if (d.bodyHash.isSet())
                hash = d.bodyHash;
        }
        buffer.append("<img src=\"file://");
#ifdef _WIN32
        buffer.append("/");
#endif
        buffer.append(path);
        buffer.append("\" type=\"");
        buffer.append(mime);
        buffer.append("\" hash=\"");
        buffer.append(hash.toHex());
        buffer.append("\" onContextMenu=\"window.browser.imageContextMenu(&apos;");
        buffer.append(QString::number(rlid));
        buffer.append("&apos;, &apos;");
        buffer.append(g);
        buffer.append("&apos;);\" ");
        buffer.append(" en-tag=\"en-media\" style=\"cursor: default;\" lid=\"");
        buffer.append(QString::number(rlid));
        buffer.append("\">");

        // Insert the actual image
        editor->page()->runJavaScript(script_start + buffer + script_end);
        return;
    }

    bool isPdfWithInlineDisplay = mime == "application/pdf" && global.pdfPreview;
    if (isPdfWithInlineDisplay) {
        QLOG_INFO() << "attachFileSelected: isPdfWithInlineDisplay";
        // The resource is done, now we need to add it to the note body
        QString g = QString::number(rlid) + extension;

        // do the actual insert into the note
        QString buffer;
        QByteArray hash;
        if (newRes.data.isSet()) {
            Data data = newRes.data;
            if (data.bodyHash.isSet()) {
                hash = data.bodyHash;
            }
        }
        // PDF iniline preview object
        buffer.append("<object style=\"width:100%; height: 600px\" lid=\"" + QString::number(rlid) + "\" hash=\"");
        buffer.append(hash.toHex());
        buffer.append("\" type=\"application/pdf\" />");

        // Insert the actual image
        editor->page()->runJavaScript(script_start + buffer + script_end);
    } else {
        QLOG_INFO() << "attachFileSelected: other object";

        // if we already inserted the "object", then skip "img" tag, as this would duplicate the PDF

        // If we have something other than an image or PDF
        // First get the icon for this type of file
        AttachmentIconBuilder builder;
        QString g = global.fileManager.getDbaDirPath() + QString::number(rlid) + extension;
        QString tmpFile = builder.buildIcon(rlid, filename);


        // do the actual insert into the note
        QString buffer;
        buffer.append("<a en-tag=\"en-media\" ");
        buffer.append("lid=\"" + QString::number(rlid) + QString("\" "));
        buffer.append("type=\"" + mime + "\" ");
        buffer.append("hash=\"" + hash.toHex() + "\" ");
        buffer.append("href=\"nnres:" + g + "\" ");
        buffer.append("oncontextmenu=\"window.browserWindow.resourceContextMenu(&apos");
        buffer.append(g + QString("&apos);\" "));
        buffer.append(">");

        buffer.append("<img en-tag=\"temporary\" title=\"" + QFileInfo(filename).fileName() + "\" ");
        buffer.append("src=\"file://");
#ifdef _WIN32
        buffer.append("/");
#endif
        buffer.append(tmpFile);
        buffer.append("\" />");
        buffer.append("</a>");
        buffer.replace("\'", "&quot;");

        const QString &html = script_start + buffer + script_end;
        QLOG_INFO() << "attachFileSelected: inserting HTML " << html;

        editor->page()->runJavaScript(html);
    }
}


// Alarm has been completed
void NBrowserWindow::alarmCompleted() {
    QFont f = alarmText.font();
    f.setStrikeOut(!f.strikeOut());
    alarmText.setFont(f);

    setDirty(this->lid, true);
    NoteTable noteTable(global.db);
    noteTable.setReminderCompleted(this->lid, f.strikeOut());

    global.reminderManager->remove(this->lid);
    emit(noteUpdated(this->lid));
    emit noteAlarmEditedSignal(uuid, lid, f.strikeOut(), alarmText.text());
}


void NBrowserWindow::alarmSet() {
    ReminderSetDialog dialog;
    Note n;
    NoteTable ntable(global.db);
    ntable.get(n, lid, false, false);
    NoteAttributes attributes;
    if (n.attributes.isSet())
        attributes = n.attributes;
    if (attributes.reminderTime.isSet()) {
        QDateTime dt;
        dt.setMSecsSinceEpoch(attributes.reminderTime);
        dialog.time->setTime(dt.time());
        dialog.calendar->setSelectedDate(dt.date());
    } else {
        QTime t = QTime::currentTime();
        dialog.time->setTime(t.addSecs(60 * 60));
    }
    dialog.exec();
    if (!dialog.okPressed)
        return;

    QDateTime dt;
    dt.setTime(dialog.time->time());
    QTime t = dialog.time->time();
    t.setHMS(t.hour(), t.minute(), 0, 0);
    dt.setTime(t);
    dt.setDate(dialog.calendar->selectedDate());

    ntable.updateDate(this->lid, dt.toMSecsSinceEpoch(), NOTE_ATTRIBUTE_REMINDER_TIME, true);
    //alarmText.setText(dt.date().toString(Qt::SystemLocaleShortDate));
    if (dt.date() == QDate::currentDate())
        alarmText.setText(tr("Today"));
    else if (dt.date() == QDate::currentDate().addDays(+1))
        alarmText.setText(tr("Tomorrow"));
    else if (dt.date() == QDate::currentDate().addDays(-1))
        alarmText.setText(tr("Yesterday"));
    else
        alarmText.setText(dt.date().toString(global.getDateFormat()));

    alarmText.setVisible(true);
    QFont f = alarmText.font();
    f.setStrikeOut(false);
    alarmText.setFont(f);

    // Update the reminders
    global.reminderManager->updateReminder(this->lid, dt);
    this->noteUpdated(this->lid);
    this->editor->isDirty = true;
    emit noteAlarmEditedSignal(uuid, lid, false, alarmText.text());
}

void NBrowserWindow::alarmClear() {
    alarmText.setText("");
    alarmText.setVisible(false);

    setDirty(this->lid, true);

    NoteTable noteTable(global.db);
    noteTable.removeReminder(this->lid);
    emit(noteUpdated(this->lid));
    emit noteAlarmEditedSignal(uuid, lid, false, "");
}

void NBrowserWindow::alarmMenuActivated() {
    QFont f = alarmText.font();
    f.setStrikeOut(false);
    emit noteAlarmEditedSignal(uuid, lid, false, alarmText.text());
    alarmText.setFont(f);

    setDirty(this->lid, true);

    NoteTable noteTable(global.db);
    noteTable.setReminderCompleted(this->lid, false);
    emit(noteUpdated(this->lid));
}


void NBrowserWindow::decryptText(QString id, QString text, QString hint, QString cipher, int len) {
    if (cipher != "RC2") {
        QMessageBox::critical(this, tr("Decryption Error"),
                              tr("Unknown encryption method.\n"
                                 "Unable to decrypt.")
                              + "\n" + cipher
        );
        return;
    }

    EnCrypt crypt(global.fileManager.getCryptoJarPath());
    QString plainText = "";
    QUuid uuid;
    QString slot = uuid.createUuid().toString().replace("{", "").replace("}", "");

    // First, try to decrypt with any keys we already have
    for (int i = 0; i < global.passwordRemember.size(); i++) {
        QString password = global.passwordRemember.at(i).first;
        int rc = crypt.decrypt(plainText, text, password, cipher, len);
        if (rc == 0) {
            QLOG_DEBUG() << "Successful decrypt with session password #" << (i + 1);

            QPair<QString, QString> newEntry;
            newEntry.first = id;
            newEntry.second = global.passwordRemember.at(i).second;
            global.passwordRemember.append(newEntry);
            removeEncryption(id, plainText, false, slot);
            return;
        }
    }

    QLOG_DEBUG() << "About to show decrypt dialog";

    EnDecryptDialog dialog;
    if (hint.trimmed() != "") {
        dialog.hint->setText(hint);
    }

    QString pwd;
    while (plainText == "" || !dialog.okPressed) {
        dialog.exec();
        if (!dialog.okPressed) {
            QLOG_DEBUG() << "Failed to decrypt (dialog cancel)";
            return;
        }
        pwd = dialog.password->text().trimmed();

        int rc = crypt.decrypt(plainText, text, pwd);
        if (rc == EnCrypt::Invalid_Key) {
            //QMessageBox.warning(this, tr("Incorrect Password"), tr("The password entered is not correct"));
        }
    }

    //const QString hint = dialog.hint->text().trimmed();

    QPair<QString, QString> passwordPair;
    passwordPair.first = pwd;
    passwordPair.second = hint;
    global.passwordSafe.insert(slot, passwordPair);

    bool isPernamentDecrypt = dialog.permanentlyDecrypt->isChecked();
    bool permanentlyDecrypt = isPernamentDecrypt;
    removeEncryption(id, plainText, permanentlyDecrypt, slot);

    bool rememberPassword = dialog.rememberPassword->isChecked();

    if (rememberPassword) {
        QPair<QString, QString> pair;
        pair.first = pwd;
        pair.second = hint;
        QLOG_DEBUG() << "Appending password to session store";
        global.passwordRemember.append(pair);
    }
}


void NBrowserWindow::removeEncryption(QString id, QString plainText, bool permanent, QString slot) {
    // TODO fix the editable version
    if (!permanent) {
        plainText = " <table class=\"" HTML_TEMP_TABLE_CLASS "\" slot=\""
                    + slot
                    + "\""
                    + "border=1 width=100%><tbody><tr><td>"
                    + plainText + "</td></tr></tbody></table>";

        QMimeData *mimeData = new QMimeData;
        mimeData->setData("text/html", plainText.toUtf8());

        QApplication::clipboard()->setMimeData(mimeData, QClipboard::Clipboard);
        this->editor->triggerPageAction(QWebEnginePage::Paste);

        // currently readonly - as edit encrypted is unstable
        editor->page()->runJavaScript("document.documentElement.contentEditable = false");

        return;
    }

    QString html = editor->page()->toHtml();
    QString text = html;
    int imagePos = html.indexOf("<img");
    int endPos;
    for (; imagePos != -1;) {
        // Find the end tag
        endPos = text.indexOf(">", imagePos);
        QString tag = text.mid(imagePos - 1, endPos);
        if (tag.indexOf("id=\"" + id + "\"") > -1) {
            text = text.mid(0, imagePos) + plainText + text.mid(endPos + 1);
            editor->page()->setHtml(text);
            editor->reload();
            if (permanent) {
                contentChanged();
            }
        }
        imagePos = text.indexOf("<img", imagePos + 1);
    }
}


void NBrowserWindow::encryptButtonPressed() {
    //EnCrypt encrypt(global.fileManager.getCryptoJarPath());

    QString text = editor->selectedText();
    if (text.trimmed() == "") {
        return;
    }
    text = text.replace("\n", "<br/>");

    EnCryptDialog dialog;
    dialog.exec();
    if (!dialog.okPressed()) {
        return;
    }

    EnCrypt crypt(global.fileManager.getCryptoJarPath());
    QString encrypted;
    int rc = crypt.encrypt(encrypted, text, dialog.getPassword().trimmed());

    if (rc != 0) {
        QMessageBox::information(this, tr("Error"),
                                 tr("Error Encrypting String.  Please verify you have Java installed."));
        return;
    }
    QString buffer;
    buffer.append("<img en-tag=\"en-crypt\" cipher=\"RC2\" hint=\""
                  + dialog.getHint().replace("'", "\\'") + "\" length=\"64\" ");
    buffer.append("contentEditable=\"false\" alt=\"");
    buffer.append(encrypted);

#ifndef _WIN32
    buffer.append("\" src=\"file://").append(global.fileManager.getImageDirPath("encrypt.png") + "\"");
#else
    buffer.append("\" src=\"file:///").append(global.fileManager.getImageDirPath("encrypt.png") +"\"");
#endif

    global.cryptCounter++;
    buffer.append(" id=\"crypt" + QString::number(global.cryptCounter) + "\"");
    buffer.append(" onMouseOver=\"style.cursor=\\'hand\\'\"");
    buffer.append(" onClick=\"window.browserWindow.decryptText(\\'crypt" + QString::number(global.cryptCounter)
                  + "\\', \\'" + encrypted + "\\', \\'" + dialog.getHint().replace("'", "\\&amp;apos;") +
                  "\\', \\'RC2\\', 64);\"");
    buffer.append("style=\"display:block\" />");


    QString script_start = "document.execCommand('insertHtml', false, '";
    QString script_end = "');";
    editor->page()->runJavaScript(script_start + buffer + script_end);
}


void NBrowserWindow::sendAuthorUpdateSignal() {
    emit noteAuthorEditedSignal(uuid, lid, dateEditor.authorEditor.getText());
}


void NBrowserWindow::sendLocationUpdateSignal() {
    double longitude, latitude, altitude;
    QString name;
    dateEditor.locationEditor.getGeography(longitude, latitude, altitude, name);
    emit noteLocationEditedSignal(uuid, lid, longitude, latitude, altitude, name);
}


void NBrowserWindow::sendDateCreatedUpdateSignal() {
    emit noteDateEditedSignal(uuid, lid, NOTE_CREATED_DATE, dateEditor.createdDate.dateTime());
}


void NBrowserWindow::sendDateSubjectUpdateSignal() {
    emit noteDateEditedSignal(uuid, lid, NOTE_ATTRIBUTE_SUBJECT_DATE, dateEditor.subjectDate.dateTime());
}


QString NBrowserWindow::getCurrentNoteTitle() {
    return this->noteTitle.text().replace("\n", " ").simplified();
}


void NBrowserWindow::sendTitleUpdateSignal() {
    NoteTable ntable(global.db);
    QString text = getCurrentNoteTitle();
    ntable.updateTitle(this->lid, text, true);
    emit noteTitleEditedSignal(uuid, lid, text);

    emit(this->noteUpdated(lid));
    emit(this->updateNoteList(lid, NOTE_TABLE_TITLE_POSITION, text));
    sendDateUpdateSignal();
}


// Send a signal that the note has been updated
void NBrowserWindow::sendNotebookUpdateSignal() {
    //    QString notebook = notebookMenu.d
    //    ntable.updateNotebook(this->lid, this->noteTitle.text().trimmed(), true);
    //    this->editor->isDirty = true;

    setDirty(this->lid, true, false);

    emit(this->noteUpdated(lid));
    qint32 lid = notebookMenu.notebookLid;
    QString name = notebookMenu.notebookName;
    emit(this->updateNoteList(lid, NOTE_TABLE_NOTEBOOK_POSITION, name));
    emit(this->updateNoteList(lid, NOTE_TABLE_NOTEBOOK_LID_POSITION, lid));
    emit noteNotebookEditedSignal(uuid, this->lid, lid, name);

    //sendDateUpdateSignal();
}


// Send a signal that the note has been updated
void NBrowserWindow::sendDateUpdateSignal(qint64
                                          dt) {
    setDirty(this->lid, true);

    if (dt == 0) {
        dt = QDateTime::currentMSecsSinceEpoch();
        this->dateEditor.
                setUpdateDate(dt);
    }
    emit(this->
            noteUpdated(lid)
    );
    emit(this->
            updateNoteList(lid,
                           NOTE_TABLE_DATE_UPDATED_POSITION, dt));
}


// Send a signal that the note tag has been updated
void NBrowserWindow::sendTagUpdateSignal() {
    // let update data also on tag change
    setDirty(this->lid, true);

    emit(this->noteUpdated(lid));
    //sendDateUpdateSignal();
    QStringList names;
    tagEditor.getTags(names);
    emit noteTagsEditedSignal(uuid, lid, names);
}


// Send a signal that the note has been updated
void NBrowserWindow::sendUrlUpdateSignal() {
    setDirty(this->lid, true);

    emit(this->noteUpdated(lid));
    sendDateUpdateSignal();
    emit(this->updateNoteList(lid, NOTE_TABLE_SOURCE_URL_POSITION, urlEditor.getText()));
    emit noteUrlEditedSignal(uuid, lid, urlEditor.getText());

}


void NBrowserWindow::spellCheckPressed() {
    QLOG_DEBUG() << SPELLCHECKER_DLG ": Starting spellcheck";

    // Check if we have a plugin for Hunspell loaded. This could have been done at startup, but if this is
    // an external window we could need to load it again.
    if (!spellChecker) {
        QLOG_DEBUG() << SPELLCHECKER_DLG ": About to create spell checker";
        this->createSpellChecker();
    }

    // If we STILL don't have a plugin then it can't be loaded. Quit out
    QString currentSpellLocale = initializeSpellCheckerInitial();
    if (currentSpellLocale.isEmpty()) {
        QLOG_DEBUG() << SPELLCHECKER_DLG ": Spell checker init was not successful - exit spell check";
        QMessageBox::critical(this, tr("Plugin Error"),
                              tr("Hunspell not available or no dictionary for current locale"), QMessageBox::Ok);
        return;
    }

    QLOG_DEBUG() << SPELLCHECKER_DLG ":Preparing page for spell check";
    QWebEnginePage *page = editor->page();
    page->action(QWebEnginePage::MoveToStartOfDocument);
    page->setFocus();

    Qt::KeyboardModifier ctrl(Qt::ControlModifier);
    QKeyEvent key(QEvent::KeyPress, Qt::Key_Home, ctrl);
    editor->keyPressEvent(&key);
    page->setFocus();

    QString plainText(page->toPlainText());
    QLOG_DEBUG_FILE("spell-1.txt", plainText);
    //QLOG_INFO() << "spell plain before: " << plainText;
    plainText = plainText
            .replace(QRegularExpression("\\s|\\xa0"), " ") // \xa0 is &nbsp;
            .replace(QRegularExpression("\\s-"), " ")
            .replace(QRegularExpression("-\\s"), " ")
            .replace(QRegularExpression(
                    "[" + QRegularExpression::escape("/*\\;:()[]{}~#`§^′_$%&=\",.!?+") + "]"
            ), " ")
            .replace(QRegularExpression("\\s+"), " "
            );
    QLOG_DEBUG_FILE("spell-2.txt", plainText);

    QStringList words = plainText.split(" ");
    QStringList ignoreWords;
    QStringList suggestions;

    QLOG_DEBUG() << SPELLCHECKER_DLG ": creating dialog for locale=" << currentSpellLocale;
    QStringList availableLocales = spellChecker->availableSpellLocales();
    SpellCheckDialog dialog(currentSpellLocale, availableLocales, this);

    QLOG_DEBUG() << SPELLCHECKER_DLG ": Starting spell check loop";
    for (int i = 0; i < words.size(); i++) {
        QString currentWord = words[i].trimmed();
        bool shouldBeIgnored = (currentWord.length() <= 1) || ignoreWords.contains(currentWord);
        if (shouldBeIgnored) {
            continue;
        }

        // this could be too verbose, eventually switch to trace
        QLOG_DEBUG() << SPELLCHECKER_DLG ": checking word: " << currentWord;

        if (!page->findText(currentWord)) {
            QLOG_DEBUG() << SPELLCHECKER_DLG ": skip word: " << currentWord << " (as find failed)";
        };
        suggestions.clear();

        if (!spellChecker->spellCheck(currentWord, suggestions)) {
            dialog.setState(currentWord, suggestions);

            //dialog.move(0, 0);
            int result = dialog.exec();
            QLOG_DEBUG() << SPELLCHECKER_DLG ": dialog result: " << result;

            if (result == DONE_IGNORE) {
                continue;
            } else if (result == DONE_CANCEL) {
                QLOG_DEBUG() << SPELLCHECKER_DLG ": got cancel";
                break;
            } else if (result == DONE_IGNOREALL) {
                QLOG_DEBUG() << SPELLCHECKER_DLG ": ignore all: " << currentWord;
                ignoreWords.append(currentWord);
            } else if (result == DONE_REPLACE) {
                QString replacement(dialog.getReplacement());
                QLOG_DEBUG() << SPELLCHECKER_DLG ": replacing by: " << replacement;
                QApplication::clipboard()->setText(replacement);
                //1: pasteButtonPressed();
                //2: this->editor->triggerPageAction(QWebEnginePage::Paste);
                page->triggerAction(QWebEnginePage::Paste);

            } else if (result == DONE_CHANGELANGUAGE) {
                // let restart the loop
                i = 0;

                int idx = dialog.language->currentIndex();
                QString newLocale = dialog.language->itemText(idx);
                QLOG_DEBUG() << SPELLCHECKER_DLG ": switching language to " << newLocale;

                if (initializeSpellCheckerWithLocale(newLocale)) {
                    QLOG_DEBUG() << SPELLCHECKER_DLG ": switch OK";
                }
            } else if (result == DONE_ADDTODICTIONARY) {
                QLOG_DEBUG() << SPELLCHECKER_DLG ": adding word to dictionary: " << currentWord;

                spellCheckAddWordToUserDictionary(currentWord);
            } else {
                QLOG_DEBUG() << SPELLCHECKER_DLG ": unrecognised result code: " << result;
            }
        }
    }
    QLOG_DEBUG() << SPELLCHECKER_DLG ": finished spell check";

    // Go to the end of the document & finish up
    QKeyEvent key2(QEvent::KeyPress, Qt::Key_End, ctrl);
    editor->keyPressEvent(&key2);

    global.setMessage(tr("Spell check completed"));
}


void NBrowserWindow::insertHtmlEntities() {
    emit showHtmlEntities();
}


void NBrowserWindow::hideHtmlEntities() {
    buttonBar->htmlEntitiesButtonVisible->setVisible(false);
    buttonBar->htmlEntitiesButtonAction->setVisible(false);
    editor->insertHtmlEntitiesAction->setVisible(false);
}


void NBrowserWindow::handleUrls(const QMimeData *mime) {
    QList<QUrl> urlList = mime->urls();
    bool ctrlModifier = QApplication::keyboardModifiers() & Qt::ControlModifier;
    QLOG_DEBUG() << "handleUrls: urlList=" << urlList << ", ctrlModifier=" << ctrlModifier;

    for (int i = 0; i < urlList.size(); i++) {
        QString file = urlList[i].toString();
        QLOG_DEBUG() << "handleUrls: file=" << file;

        bool isFileProtocol = file.toLower().startsWith("file://");
        bool isLastItem = i >= urlList.size() - 1;

        if (isFileProtocol && !ctrlModifier) {
            attachFileSelected(file.mid(7));

            if (!isLastItem) {
                insertHtml("<div><br/></div>");
            }
        } else if (isFileProtocol && ctrlModifier) {
            QString urlMarkup = QString("<a href=\"%1\" title=\"%2\">%3</a>").arg(file).arg(file).arg(file);
            QLOG_DEBUG() << "handleUrls: converted urlMarkup=" << file;
            insertHtml(urlMarkup);
            if (!isLastItem) {
                insertHtml("<div><br/></div>");
            }
        } else {
            QLOG_DEBUG() << "handleUrls: plain clipboard insert";
            editor->setFocus();
            QApplication::clipboard()->clear();
            QApplication::clipboard()->setText(file, QClipboard::Clipboard);
            this->editor->triggerPageAction(QWebEnginePage::Paste);
        }
    }
}


/** This is used to notify the tab window that the contents of a
  * note have changed.  It avoids some of the overhead that happens
  * when a note is first edited, but it is signaled on every change.
  * The tab window uses it to update any duplicate windows (i.e. a note
  * was edited in an external editor and is still being viewed internally
  * so we need to keep the contents in sync.
  * */
void NBrowserWindow::noteContentEdited() {
    emit noteContentEditedSignal(uuid, lid, editor->editorPage->documentElement().toOuterXml());
}


void NBrowserWindow::changeDisplayFontSize(QString size) {
    bool convert = false;
    if (size.endsWith("px", Qt::CaseInsensitive))
        convert = true;
    size.chop(2);  // Remove px from the end
    float converted = size.toFloat();
    if (convert) {
        PixelConverter c;
        converted = c.getPoints(converted);
        size = QString::number(int(converted));
    }
    int idx = buttonBar->fontSizes->findData(size, Qt::UserRole);
    if (idx >= 0) {
        buttonBar->fontSizes->blockSignals(true);
        buttonBar->fontSizes->setCurrentIndex(idx);
        buttonBar->fontSizes->blockSignals(false);
    }
}


// This function is called when the cursor position within the document changes.  It should
// change the combo box to the current font name.
void NBrowserWindow::changeDisplayFontName(QString name) {
    //QLOG_DEBUG() << "Font Name:" << name;
    if (name.startsWith("'")) {
        name = name.mid(1);
        int idx = name.indexOf("'");
        if (idx != -1)
            name = name.mid(0, idx);
    }
    name = name.toLower();
    buttonBar->fontNames->blockSignals(true);
    int idx = buttonBar->fontNames->findData(name, Qt::UserRole);
    if (idx != -1)
        buttonBar->fontNames->setCurrentIndex(idx);
    buttonBar->fontNames->blockSignals(false);
}


void NBrowserWindow::focusCheck() {
    bool buttonBarVisible = true;

    //    if (editor->hasFocus())
    //        buttonBarVisible = true;
    //    if (editor->contextMenu->hasFocus())
    //        buttonBarVisible = true;
    //    if (buttonBar->hasFocus())
    //        buttonBarVisible = true;
    //    if (buttonBar->fontNames->isExpanded())
    //        buttonBarVisible = true;
    //    if (buttonBar->fontNames->lineEdit()->hasFocus())
    //        buttonBarVisible = true;
    //    if (buttonBar->fontSizes->lineEdit()->hasFocus())
    //        buttonBarVisible = true;
    //    if (buttonBar->fontSizes->isExpanded())
    //        buttonBarVisible = true;

    if (global.isFullscreen)
        buttonBarVisible = false;
    if (!editor->page()->isContentEditable())
        buttonBarVisible = false;

    buttonBar->setVisible(buttonBarVisible);
}


void NBrowserWindow::saveTimeCheck() {
    if (editor->isDirty) {
        QLOG_DEBUG() << "saveTimeCheck()";
        this->saveNoteContent();
    }
}


void NBrowserWindow::notebookFocusShortcut() {
    this->notebookMenu.setFocus();
    this->notebookMenu.click();
}


void NBrowserWindow::fontFocusShortcut() {
    if (this->buttonBar->fontNames->isVisible()) {
        this->buttonBar->fontNames->setFocus();
        this->buttonBar->fontNames->showPopup();
    }
}


void NBrowserWindow::fontSizeFocusShortcut() {
    if (this->buttonBar->fontSizes->isVisible()) {
        this->buttonBar->fontSizes->setFocus();
        this->buttonBar->fontSizes->showPopup();
    }
}


void NBrowserWindow::authorFocusShortcut() {
    if (!this->dateEditor.authorEditor.isVisible()) {
        this->changeExpandState(EXPANDBUTTON_3);
        this->expandButton.setState(EXPANDBUTTON_3);
    }
    dateEditor.authorEditor.setFocus();
}

void NBrowserWindow::urlFocusShortcut() {
    if (!this->urlEditor.isVisible()) {
        this->changeExpandState(EXPANDBUTTON_2);
        this->expandButton.setState(EXPANDBUTTON_2);
    }
    this->urlEditor.setFocus();
}


void NBrowserWindow::copyInAppNoteLink() {
    Note n;
    NoteTable ntable(global.db);
    ntable.get(n, this->lid, false, false);
    UserTable utable(global.db);
    User user;
    utable.getUser(user);

    QString href = NixnoteStringUtils::createNoteLink(true, global.server, QString::number(user.id), user.shardId,
                                                      n.guid);
    QApplication::clipboard()->setText(href, QClipboard::Clipboard);
}


void NBrowserWindow::newTagFocusShortcut() {
    if (!this->tagEditor.newTag.isVisible()) {
        this->changeExpandState(EXPANDBUTTON_2);
        this->expandButton.setState(EXPANDBUTTON_2);
    }
    tagEditor.newTag.setFocus();
}


// User pressed the superscript editor button
void NBrowserWindow::superscriptButtonPressed() {
    editor->page()->runJavaScript("document.execCommand('superscript')");
}


// User pressed the subscript editor button
void NBrowserWindow::subscriptButtonPressed() {
    editor->page()->runJavaScript("document.execCommand('subscript');");
}

QString base64_encode(QString string) {
    QByteArray ba;
    ba.append(string);
    return ba.toBase64();
}

// Set the editor background & font color
void NBrowserWindow::setEditorStyle() {
    QString css = global.getEditorCss();

    QString checkbox =
        QString("img.todo-icon {") +
        QString("    vertical-align: baseline !important;") +
        QString("    cursor: pointer;") +
        QString("    padding-right: 5px;") +
        QString("\n") +
        QString("    user-drag: none;") +
        QString("    -webkit-user-drag: none;") +
        QString("}");

    css += checkbox;

    QString url = QString("data:text/css;charset=utf-8;base64,").append(base64_encode(css));
    // http://doc.qt.io/archives/qt-5.5/qwebsettings.html#setUserStyleSheetUrl
    // hack to pass inline css to avoid putting it in file
    // The location must be either a path on the local filesystem, or a data URL with UTF-8 and Base64 encoded data, such as:
    // "data:text/css;charset=utf-8;base64,cCB7IGJhY2tncm91bmQtY29sb3I6IHJlZCB9Ow=="
    //QLOG_DEBUG() << "applied css " << css << " as " << url;

    editor->settings()->setUserStyleSheetUrl(url);
}


void NBrowserWindow::createSpellChecker() {
    QLOG_DEBUG() << SPELLCHECKER_MODULE
                    ": about to create spell checker";
    // if interface doesn't exist, create it
    if (!spellChecker) {
        spellChecker = new SpellChecker();
    }
}

/**
 * First time init from settings with retry fallback.
 * @return current locale if OK
 */
QString NBrowserWindow::initializeSpellCheckerInitial() {
    // if interface exists, then try to init with "current" locale
    if (spellChecker) {
        QString locale = getSpellCheckerLocaleFromSettings();
        bool ok = initializeSpellCheckerWithLocale(locale);

        if (!ok) {
            QLOG_WARN() << SPELLCHECKER_MODULE
                           ": failed init with locale=" << locale;

            // get list of all available locales
            QStringList availableLocales = spellChecker->availableSpellLocales();
            if (!availableLocales.isEmpty()) {
                // first locale from list
                QString availableLocales1 = availableLocales.first();
                QLOG_INFO() << SPELLCHECKER_MODULE
                               ": first availablelocale: " << availableLocales1;
                if (QString::compare(locale, availableLocales1, Qt::CaseInsensitive) != 0) {
                    QLOG_INFO() << SPELLCHECKER_MODULE
                                   ": will retry init with: " << availableLocales1;
                    ok = initializeSpellCheckerWithLocale(availableLocales1);
                    if (ok) {
                        QLOG_INFO() << SPELLCHECKER_MODULE
                                       ": OK init with fallback locale=" << locale;
                        locale = availableLocales1;
                    }
                }
            }
        }
        if (ok) {
            // on success set current locale
            QLOG_DEBUG() << SPELLCHECKER_MODULE
                            ": OK setting current locale=" << locale;
            saveSpellCheckerLocaleToSettings(locale);
            return locale;
        }
    }
    QLOG_ERROR() << SPELLCHECKER_MODULE
                    ": failed init";
    return QString();
}

bool NBrowserWindow::initializeSpellCheckerWithLocale(QString locale) {
    QString userDictionaryPath(global.fileManager.getSpellDirPathUser());

    QLOG_INFO() << SPELLCHECKER_MODULE
                   ": trying initialization for locale: " << locale
                << ", userDictionaryPath=" << userDictionaryPath;


    bool result = spellChecker->setup(userDictionaryPath, locale);
    if (result) {
        QLOG_INFO() << SPELLCHECKER_MODULE
                       ": initialization OK";
        saveSpellCheckerLocaleToSettings(locale);
    } else {
        global.setMessage(tr("Failed to initialize spell checker for ") + locale);
        QLOG_ERROR() << SPELLCHECKER_MODULE
                        ": initialization FAILED for locale: " << locale;
    }
    return result;
}

QString NBrowserWindow::getSpellCheckerLocaleFromSettings() {
    global.settings->beginGroup(INI_GROUP_LOCALE);
    QString locale = global.settings->value(INI_VALUE_SPELLCHECK_LOCALE).toString();
    if (locale.isEmpty()) {
        // fallback to translation
        locale = global.settings->value(INI_VALUE_TRANSLATION).toString();
    }
    global.settings->endGroup();

    if (locale.isEmpty()) {
        // fallback if even translation isn't present
        locale = QLocale::system().name();
    }

    QLOG_DEBUG() << SPELLCHECKER_MODULE
                    ": got settings spell check locale=" << locale;
    return locale;
}

void NBrowserWindow::saveSpellCheckerLocaleToSettings(QString locale) {
    QLOG_DEBUG() << SPELLCHECKER_MODULE
                    ": save settings spell check locale=" << locale;
    global.settings->beginGroup(INI_GROUP_LOCALE);
    global.settings->setValue(INI_VALUE_SPELLCHECK_LOCALE, locale);
    global.settings->endGroup();
}


void NBrowserWindow::spellCheckAddWordToUserDictionary(QString currentWord) {
    if (!spellChecker) {
        // invalid state
        return;
    }
    spellChecker->addWord(currentWord);
}


// Find shortcut activated
void NBrowserWindow::findShortcut() {
    if (!findReplace->isVisible()) {
        findReplace->showFind();
    } else {
        if (findReplace->findLine->hasFocus())
            findReplace->hide();
        else {
            findReplace->showFind();
            findReplace->findLine->setFocus();
            findReplace->findLine->selectAll();
        }
    }

}


//*******************************************
//* Search for the next occurrence of text
//* in a note.
//*******************************************
void NBrowserWindow::findNextShortcut() {
    this->findNextInNote();
}


//*******************************************
//* Search for the previous occurrence of
//* text in a note.
//*******************************************
void NBrowserWindow::findPrevShortcut() {
    this->findPrevInNote();
}


// Find shortcut activated
void NBrowserWindow::findReplaceShortcut() {
    this->findReplace->showFindReplace();
}


//***************************************
//* Find/replace button pressed, so we
//* need to highlight all the occurrences
//* in a note.
//***************************************
void NBrowserWindow::findReplaceInNotePressed() {
    QString find = findReplace->findLine->text();
    QString replace = findReplace->replaceLine->text();
    if (find == "")
        return;
    bool found = false;
    found = editor->page()->findText(find,
                                     findReplace->getCaseSensitive() | QWebEnginePage::FindWrapsAroundDocument);
    if (!found)
        return;

    QApplication::clipboard()->setText(replace);
    editor->pasteAction->trigger();
}


//*************************************************
//* Replace All button pressed.
//*************************************************
void NBrowserWindow::findReplaceAllInNotePressed() {
    QString find = findReplace->findLine->text();
    QString replace = findReplace->replaceLine->text();
    if (find == "")
        return;
    bool found = false;
    while (true) {
        found = editor->page()->findText(find,
                                         findReplace->getCaseSensitive() | QWebEnginePage::FindWrapsAroundDocument);
        if (!found)
            return;
        QApplication::clipboard()->setText(replace);
        editor->pasteAction->trigger();
    }
}


//*******************************************
//* Search for the next occurrence of text
//* in a note.
//*******************************************
void NBrowserWindow::findNextInNote() {
    findReplace->showFind();
    QString find = findReplace->findLine->text();
    if (find != "")
        editor->page()->findText(find,
                                 findReplace->getCaseSensitive() | QWebEnginePage::FindWrapsAroundDocument);
    // The background color of the occurances
    // when finding text under Windows is
    // light gray, not recognizable enough,
    // for better experience, add a background
    // color for them here.
#ifdef _WIN32
    editor->page()->findText(find, QWebEnginePage::HighlightAllOccurrences);
#endif
}


//*******************************************
//* Search for the previous occurrence of
//* text in a note.
//*******************************************
void NBrowserWindow::findPrevInNote() {
    findReplace->showFind();
    QString find = findReplace->findLine->text();
    if (find != "")
        editor->page()->findText(find,
                                 findReplace->getCaseSensitive() | QWebEnginePage::FindBackward |
                                 QWebEnginePage::FindWrapsAroundDocument);

#ifdef _WIN32
    editor->page()->findText(find, QWebEnginePage::HighlightAllOccurrences);
#endif
}


//*******************************************
//* This just does a null find to reset the
//* text in a note so nothing is highlighted.
//* This is triggered when the find dialog
//* box is hidden.
//*******************************************
void NBrowserWindow::findReplaceWindowHidden() {
    editor->page()->findText("");
}


//************************************************
//* Set the current edited cell style in a table
//* This is called from a javascript function to
//* get the current cell style the cursor is in.
//*************************************************
void NBrowserWindow::setTableCellStyle(QString value) {
    this->tableCellStyle = value;
}


//************************************************
//* Set the current table style
//* This is called from a javascript function to
//* get the currenttablel style the cursor is in.
//*************************************************
void NBrowserWindow::setTableStyle(QString value) {
    this->tableStyle = value;
}



//**************************************************
//* This is called when a note's content is saved.
//* It is used to call user exits.
//**************************************************

void NBrowserWindow::exitPoint(ExitPoint *exit) {
    QLOG_TRACE_IN();
    ExitPoint_NoteEdit *saveExit = new ExitPoint_NoteEdit();

    QJSEngine engine;
    QJSValue exit_s = engine.newQObject(saveExit);
    engine.globalObject().setProperty("note", exit_s);

    // Start loading values
    QLOG_INFO() << "Calling exit " << exit->getExitName();
    saveExit->setExitName(exit->getExitName());
    saveExit->setTitle(this->noteTitle.text());
    saveExit->setNotebook(notebookMenu.notebookName);
    saveExit->setCreationDate(dateEditor.createdDate.dateTime().toMSecsSinceEpoch());
    saveExit->setUpdatedDate(dateEditor.updatedDate.dateTime().toMSecsSinceEpoch());
    saveExit->setSubjectDate(dateEditor.subjectDate.dateTime().toMSecsSinceEpoch());

    QStringList tags;
    tagEditor.getTags(tags);
    saveExit->setTags(tags);
    saveExit->setContents(editor->page()->toHtml());

    // Set exit ready & call it.
    saveExit->setExitReady();
    QJSValue retval = engine.evaluate(exit->getScript());
    QLOG_INFO() << "Return value from exit: " << retval.toString();

    // Check for any changes.
    if (saveExit->isTitleModified()) {
        this->noteTitle.setText(saveExit->getTitle());
    }
    if (saveExit->isTagsModified()) {
        QStringList newTags = saveExit->getTags();
        QStringList oldTags;
        tagEditor.getTags(oldTags);
        for (int i = 0; i < oldTags.size(); i++) {
            tagEditor.removeTag(oldTags[i]);
        }
        for (int i = 0; i < newTags.size(); i++) {
            tagEditor.addTag(newTags[i]);
        }
    }
    if (saveExit->isNotebookModified()) {
        NotebookTable ntable(global.db);
        QString notebookName = saveExit->getNotebook();
        qint32 notebookLid = ntable.findByName(notebookName);
        if (notebookLid > 0) {
            this->notebookMenu.updateCurrentNotebook(notebookLid, notebookName);
            NoteTable noteTable(global.db);
            noteTable.updateNotebook(this->lid, notebookLid, true);
            emit(noteNotebookEditedSignal(uuid, lid, notebookLid, notebookName));
        } else QLOG_ERROR() << tr("Notebook was not found:") << notebookName;
    }
    if (saveExit->isContentsModified()) {
        QByteArray data = saveExit->getContents().toUtf8();
        this->editor->setContent(data);
    }
    editor->isDirty = saveExit->isContentsDirty();
    setDirty(this->lid, editor->isDirty, false);

    QLOG_TRACE_OUT();
}

