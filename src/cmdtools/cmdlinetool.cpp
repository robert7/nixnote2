/*********************************************************************************
NixNote - An open-source client for the Evernote service.
Copyright (C) 2015 Randy Baumgarte

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



#include "cmdlinetool.h"
#include "src/global.h"
#include <iostream>
#include <unistd.h>
#include "src/html/enmlformatter.h"
#include "src/utilities/crossmemorymapper.h"
#include "src/filters/filtercriteria.h"
#include "src/filters/filterengine.h"
#include "src/sql/notebooktable.h"
#include "src/sql/tagtable.h"
#include "src/sql/notetable.h"
#include "src/utilities/nuuid.h"
#include "src/email/smtpclient.h"
#include "src/utilities/mimereference.h"
#include "src/threads/syncrunner.h"


extern Global global;

CmdLineTool::CmdLineTool(QObject *parent) :
    QObject(parent)
{
}

// Run the command line request.
int CmdLineTool::run(StartupConfig &config) {
#if QT_VERSION < 0x050000
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
#endif
    QString errmsg(tr("Unable to attach to shared memory segment.  Is the other NixNote running?\n"));
    if (config.sync()) {
        QLOG_DEBUG() << "Command: sync";
        // If the shared memory segment doesn't exist, we just do a sync & exit
        if (!global.sharedMemory->attach()) {
            QLOG_DEBUG() << "Command: sync - attach failed => we'll handle the sync";
            return this->sync();
        }
        global.sharedMemory->write(QString("SYNCHRONIZE"));
        global.sharedMemory->detach();
        return 0;
    }
    if (config.shutdown()) {
        QLOG_DEBUG() << "Command: shutdown";
        if (!global.sharedMemory->attach()) {
            QLOG_DEBUG() << "Command: shutdown - attach failed";
            std::cout << errmsg.toStdString();
            return 16;
        }
        global.sharedMemory->write(QString("IMMEDIATE_SHUTDOWN"));
        global.sharedMemory->detach();
        return 1;
    }
    if (config.show()) {
        QLOG_DEBUG() << "Command: show";
        if (!global.sharedMemory->attach()) {
            std::cout << errmsg.toStdString();
            return 16;
        }
        global.sharedMemory->write(QString("SHOW_WINDOW"));
        global.sharedMemory->detach();
        return 1;
    }


    if (config.addNote()) {
        QLOG_DEBUG() << "Command: addNote";
        return addNote(config);
    }

    if (config.appendNote()) {
        QLOG_DEBUG() << "Command: appendNote";
        return appendNote(config);
    }

    if (config.query()) {
        QLOG_DEBUG() << "Command: query";
        return queryNotes(config);
    }
    if (config.deleteNote()) {
        QLOG_DEBUG() << "Command: deleteNote";
        return deleteNote(config);
    }
    if (config.emailNote()) {
        QLOG_DEBUG() << "Command: emailNote";
        return emailNote(config);
    }
    if (config.readNote()) {
        QLOG_DEBUG() << "Command: readNote";
        return readNote(config);
    }
    if (config.exports() || config.backup()) {
        QLOG_DEBUG() << "Command: backup";
        return exportNotes(config);
    }
    if (config.import()) {
        QLOG_DEBUG() << "Command: importNotes";
        return importNotes(config);
    }
    if (config.alterNote()) {
        QLOG_DEBUG() << "Command: alterNote";
        return alterNote(config);
    }
    if (config.openNotebook()) {
        QLOG_DEBUG() << "Command: openNotebook";
        return openNotebook(config);
    }
    if (config.closeNotebook()) {
        QLOG_DEBUG() << "Command: closeNotebook";
        return closeNotebook(config);
    }
    if (config.signalOtherGui()) {
        QLOG_DEBUG() << "Command: signalOtherGui";
        return signalGui(config);
    }
    return 0;
}


// Email a note via the command line.
int CmdLineTool::emailNote(StartupConfig config) {
    global.db = new DatabaseConnection(NN_DB_CONNECTION_NAME);  // Startup the database
    return config.email->sendEmail();
}


// Delete a note via the command line
int CmdLineTool::deleteNote(StartupConfig config) {
    if (config.delNote->verifyDelete) {
        std::string verify;
        std::cout << QString(tr("Type DELETE to verify: ")).toStdString();
        std::cin >> verify;
        QString qVerify = QString::fromStdString(verify);
        if (qVerify.toLower() != "delete")
            return 16;
    }

    global.db = new DatabaseConnection(NN_DB_CONNECTION_NAME);  // Startup the database
    NoteTable noteTable(global.db);
    noteTable.deleteNote(config.delNote->lid,true);
    return 0;
}


// Query notes via the command line
int CmdLineTool::queryNotes(StartupConfig config) {
    // The other NixNote isn't found, so we do the query ourself
    global.db = new DatabaseConnection(NN_DB_CONNECTION_NAME);  // Startup the database
    FilterCriteria *filter = new FilterCriteria();
    global.filterCriteria.append(filter);
    global.filterPosition = 0;
    FilterEngine engine;
    filter->setSearchString(config.queryNotes->query);
    QList<qint32> lids;
    engine.filter(filter, &lids);
    config.queryNotes->write(lids, "");
    return 0;
}


// Add a note via the command line.  if Nixnote is running,
// the new note is copied into the dbi directory and
// auto-imported.  If it is not running it is created directly.
int CmdLineTool::addNote(StartupConfig config) {

// Windows Check
#ifndef _WIN32
#ifdef Q_OS_WIN32
    _setmode(_fileno(stdin), _O_BINARY);
#endif
#endif // End windows check

    // If we are reding stdin
    if (config.newNote->content == "")  {
        QByteArray content;

        while(!std::cin.eof()) {
            char arr[1024];
            std::cin.read(arr,sizeof(arr));
            int s = std::cin.gcount();
            content.append(arr,s);
            content.append("<br>");
            content.replace("\n","<br>");
        }
        config.newNote->content = QString::fromAscii(content);
    }

    if (!config.newNote->content.contains("<body")) {
        config.newNote->content.prepend("<body>");
    }
    if (!config.newNote->content.contains("</body")) {
        config.newNote->content.append("</body>");
    }


    EnmlFormatter formatter(config.newNote->content, global.guiAvailable, global.passwordSafe, global.fileManager.getCryptoJarPath());
    formatter.rebuildNoteEnml();
    config.newNote->content = formatter.getContent();

   // Another NN isn't found, so we do this ourself
    global.db = new DatabaseConnection(NN_DB_CONNECTION_NAME);  // Startup the database
    NUuid uuid;
    Note newNote;
    newNote.content = config.newNote->content;
    newNote.active = true;
    newNote.created = QDateTime::currentMSecsSinceEpoch();
    newNote.guid = uuid.create();
    if (config.newNote->title != "")
        newNote.title = config.newNote->title;
    else
        newNote.title = tr("Untitled Note");

    // Process tags
    newNote.tagGuids = QList<Guid>();
    newNote.tagNames=QStringList();
    for (int i=0; i<config.newNote->tags.size(); i++) {
        QString tagName = config.newNote->tags[i];
        TagTable tagTable(global.db);
        qint32 tagLid = tagTable.findByName(tagName, 0);
        QString tagGuid;

        // Do we need to add the tag?
        if (tagLid == 0) {
            Tag tag;
            tag.name = tagName;
            NUuid uuid;
            tagGuid = uuid.create();
            tag.guid = tagGuid;
            tagTable.add(0, tag, true, 0);
        } else {
            tagTable.getGuid(tagGuid, tagLid);
        }
        newNote.tagNames->append(tagName);
        newNote.tagGuids->append(tagGuid);
    }

    // Process the notebook
    if (config.newNote->notebook != "") {
        QString notebookName = config.newNote->notebook;
        NotebookTable notebookTable(global.db);
        qint32 lid = notebookTable.findByName(notebookName);
        QString notebookGuid;

        // Do we need to add the notebook?
        if (lid == 0) {
            Notebook book;
            book.name = notebookName;
            NUuid uuid;
            QString newGuid = uuid.create();
            book.guid = newGuid;
            notebookGuid = newGuid;
            lid = notebookTable.add(0, book, true, false);
        } else {
            notebookTable.getGuid(notebookGuid, lid);
        }
        newNote.notebookGuid = notebookGuid;
    } else {
        NotebookTable notebookTable(global.db);
        newNote.notebookGuid = notebookTable.getDefaultNotebookGuid();
    }

    // Do the dates
    if (config.newNote->created != "") {
        QString dateString = config.newNote->created;
        QDateTime date = QDateTime::fromString(dateString.trimmed(), "yyyy-MM-ddTHH:mm:ss.zzzZ");
        newNote.created = date.toMSecsSinceEpoch();
    }
    if (config.newNote->updated != "") {
        QString dateString = config.newNote->updated;
        QDateTime date = QDateTime::fromString(dateString, "yyyy-MM-ddTHH:mm:ss.zzzZ");
        newNote.updated = date.toMSecsSinceEpoch();
    }
    if (config.newNote->reminder != "") {
        QString dateString = config.newNote->reminder;
        QDateTime date = QDateTime::fromString(dateString, "yyyy-MM-ddTHH:mm:ss.zzzZ");
        if (date > QDateTime::currentDateTime()) {
            if (!newNote.attributes.isSet()) {
                NoteAttributes na;
                newNote.attributes = na;
            }
            newNote.attributes->reminderTime = date.toMSecsSinceEpoch();
        }
    }


    NoteTable noteTable(global.db);
    qint32 newLid = noteTable.addStub(newNote.guid);
    // Do the attachments
    for (int i=0; i<config.newNote->attachments.size(); i++) {
        QString filename = config.newNote->attachments[i];
        QFile file(filename);
        if (file.exists()) {

            file.open(QIODevice::ReadOnly);
            QByteArray ba = file.readAll();
            file.close();

            MimeReference mimeRef;
            QString extension = filename;
            int endPos = filename.lastIndexOf(".");
            if (endPos != -1)
                extension = extension.mid(endPos);
            QString mime =  mimeRef.getMimeFromExtension(extension);
            Resource newRes;
            bool attachment = true;
            if (mime == "application/pdf" || mime.startsWith("image/"))
                attachment = false;
            config.newNote->createResource(newRes, 0, ba, mime, attachment, QFileInfo(filename).fileName(), newLid);
            QByteArray hash;
            if (newRes.data.isSet()) {
                Data d = newRes.data;
                if (d.bodyHash.isSet())
                    hash = d.bodyHash;
            }
            if (!newNote.resources.isSet()) {
                newNote.resources = QList<Resource>();
            }
            QString mediaString = "<en-media hash=\""+hash.toHex()+"\" type=\""+mime+"\"/>";
            if (newNote.content->contains(config.newNote->attachmentDelimiter)) {
                 //newNote.content = newNote.content->replace(config.newNote->attachmentDelimiter,mediaString);
                 newNote.content = newNote.content->replace(newNote.content->indexOf(config.newNote->attachmentDelimiter),
                                                     config.newNote->attachmentDelimiter.size(), mediaString);
            } else {
                newNote.content = newNote.content->replace("</en-note>","<br>"+mediaString+"</en-note>");
            }
            newNote.resources->append(newRes);
        }
    }
    noteTable.expunge(newLid);
    noteTable.add(newLid,newNote,true);
    std::cout << newLid << QString(tr(" has been created.\n")).toStdString();
    return newLid;
}



// Append text to a note via the command line.
int CmdLineTool::appendNote(StartupConfig config) {

// Windows Check
#ifndef _WIN32
#ifdef Q_OS_WIN32
    _setmode(_fileno(stdin), _O_BINARY);
#endif
#endif // end windows check

    // If we are reding stdin
    if (config.newNote->content == "")  {
        QByteArray content;

        while(!std::cin.eof()) {
            char arr[1024];
            std::cin.read(arr,sizeof(arr));
            int s = std::cin.gcount();
            content.append(arr,s);
            content.append("<br>");
            content.replace("\n","<br>");
        }
        config.newNote->content = QString::fromAscii(content);
    }

    if (!config.newNote->content.contains("<body")) {
        config.newNote->content.prepend("<body>");
    }
    if (!config.newNote->content.contains("</body")) {
        config.newNote->content.append("</body>");
    }


    EnmlFormatter formatter(config.newNote->content, global.guiAvailable, global.passwordSafe, global.fileManager.getCryptoJarPath());
    formatter.rebuildNoteEnml();
    config.newNote->content = formatter.getContent();

    // Another NN isn't found, so we do this ourself
    global.db = new DatabaseConnection(NN_DB_CONNECTION_NAME);  // Startup the database
    Note newNote;

    // Fetch the existing note
    NoteTable noteTable(global.db);
    if (!noteTable.get(newNote, config.newNote->lid, true, true)) {
        std::cerr << config.newNote->lid << QString(tr(" was not found.\n")).toStdString();
        return -1;
    }

    // Append the text to the existing note
    newNote.content->replace("</en-note>", "<br/>");

    // Chop off the beginning of the new text to remove the <en-note stuff
    int startOfNote = config.newNote->content.indexOf("<en-note");
    config.newNote->content = config.newNote->content.mid(startOfNote+9);

    // Append the two notes
    newNote.content = newNote.content + config.newNote->content;

    // Do the attachments
    for (int i=0; i<config.newNote->attachments.size(); i++) {
        QString filename = config.newNote->attachments[i];
        QFile file(filename);
        if (file.exists()) {

            file.open(QIODevice::ReadOnly);
            QByteArray ba = file.readAll();
            file.close();

            MimeReference mimeRef;
            QString extension = filename;
            int endPos = filename.lastIndexOf(".");
            if (endPos != -1)
                extension = extension.mid(endPos);
            QString mime =  mimeRef.getMimeFromExtension(extension);
            Resource newRes;
            bool attachment = true;
            if (mime == "application/pdf" || mime.startsWith("image/"))
                attachment = false;
            config.newNote->createResource(newRes, 0, ba, mime, attachment, QFileInfo(filename).fileName(), config.newNote->lid);
            QByteArray hash;
            if (newRes.data.isSet()) {
                Data d = newRes.data;
                if (d.bodyHash.isSet())
                    hash = d.bodyHash;
            }
            if (!newNote.resources.isSet()) {
                newNote.resources = QList<Resource>();
            }
            QString mediaString = "<en-media hash=\""+hash.toHex()+"\" type=\""+mime+"\"/>";
            if (newNote.content->contains(config.newNote->attachmentDelimiter)) {
                 //newNote.content = newNote.content->replace(config.newNote->attachmentDelimiter,mediaString);
                 newNote.content = newNote.content->replace(newNote.content->indexOf(config.newNote->attachmentDelimiter),
                                                     config.newNote->attachmentDelimiter.size(), mediaString);
            } else {
                newNote.content = newNote.content->replace("</en-note>","<br>"+mediaString+"</en-note>");
            }
            newNote.resources->append(newRes);
        }
    }
    noteTable.expunge(config.newNote->lid);
    noteTable.add(config.newNote->lid,newNote,true);
    std::cout << config.newNote->lid << QString(tr(" has been appended.\n")).toStdString();
    return config.newNote->lid;
}



// Read a note via the command line and extract the text
// contents.
int CmdLineTool::readNote(StartupConfig config) {
    global.db = new DatabaseConnection(NN_DB_CONNECTION_NAME);  // Startup the database
    NoteTable noteTable(global.db);
    Note n;
    QString text;
    if (noteTable.get(n,config.extractText->lid,false,false)) {
        text = config.extractText->stripTags(n.content);
    } else {
        text = tr("Note not found.");
    }
    std::cout << text.toStdString() << endl;
    return 0;
}



// Export notes or do a backup via the command line
int CmdLineTool::exportNotes(StartupConfig config) {
    if (global.sharedMemory->attach()) {
        std::cout << tr("This cannot be done with NixNote running.").toStdString() << endl;
        return 16;
    }
    global.db = new DatabaseConnection(NN_DB_CONNECTION_NAME);  // Startup the database
    if (config.exportNotes->backup)
        config.exportNotes->backupDB();
    else
        config.exportNotes->extract();
    return 0;
}



// Import notes from a nnex file.
int CmdLineTool::importNotes(StartupConfig config) {
    if (global.sharedMemory->attach()) {
        std::cout << tr("This cannot be done with NixNote running.").toStdString() << endl;
        return 16;
    }
    global.db = new DatabaseConnection(NN_DB_CONNECTION_NAME);  // Startup the database
    config.importNotes->import();
    return 0;
}


// Alter a note's notebook or add/remove tags for a note.
int CmdLineTool::alterNote(StartupConfig config) {
    global.db = new DatabaseConnection(NN_DB_CONNECTION_NAME);  // Startup the database
    return config.alter->alterNote();
}


// Open a notebook
int CmdLineTool::openNotebook(StartupConfig config) {
    if (global.sharedMemory->attach()) {
        std::cout << tr("This cannot be done with NixNote running.").toStdString() << endl;
        return 16;
    }
    global.db = new DatabaseConnection(NN_DB_CONNECTION_NAME);  // Startup the database
    NotebookTable bookTable(global.db);
    for (int i=0; i<config.notebookList.size(); i++) {
        qint32 lid = bookTable.findByName(config.notebookList[i]);
        if (lid >0) {
            bookTable.openNotebook(lid);
        } else {
            std::cout << tr("Notebook not found: ").toStdString() << config.notebookList[i].toStdString() << endl;
        }
    }
    return 0;
}


// Close a notebook
int CmdLineTool::closeNotebook(StartupConfig config) {
    if (global.sharedMemory->attach()) {
        std::cout << tr("This cannot be done with NixNote running.").toStdString() << endl;
        return 16;
    }
    global.db = new DatabaseConnection(NN_DB_CONNECTION_NAME);  // Startup the database
    NotebookTable bookTable(global.db);
    for (int i=0; i<config.notebookList.size(); i++) {
        qint32 lid = bookTable.findByName(config.notebookList[i]);
        if (lid >0) {
            bookTable.closeNotebook(lid);
        } else {
            std::cout << tr("Notebook not found: ").toStdString() << config.notebookList[i].toStdString() << endl;
        }
    }
    return 0;
}


#include "src/models/notemodel.h"
#include "src/sql/nsqlquery.h"

// Do a sync
int CmdLineTool::sync() {
    if (!global.accountsManager->oauthTokenFound()) {
        std::cout << tr("OAuth token not found.").toStdString() << endl;
        return 16;
    }

    global.db = new DatabaseConnection(NN_DB_CONNECTION_NAME);  // Startup the database

    // Check if the table exists.  If not, create it.
    NSqlQuery sql(global.db);
    sql.exec("Select *  from sqlite_master where type='table' and name='NoteTable';");
    if (!sql.next()) {
        NoteModel model(this);
        model.createNoteTable();
    }
    sql.finish();

    SyncRunner runner;
    runner.synchronize();
    if (runner.error) {
        std::cout << tr("Error synchronizing with Evernote.").toStdString() << std::endl;
        return 16;
    }
    std::cout << tr("Sync completed.").toStdString() << std::endl;
    return 0;
}


int CmdLineTool::signalGui(StartupConfig config) {

    // Make sure another one is actually running. If not, we exit out.
    if (!global.sharedMemory->attach()) {
        QLOG_DEBUG() << "Failed to attach to other instance";
        return 16;
    }
    if (config.signalGui->show)
        global.sharedMemory->write(QString("SIGNAL_GUI: SHOW"));
    if (config.signalGui->takeScreenshot)
        global.sharedMemory->write(QString("SIGNAL_GUI: SCREENSHOT"));
    if (config.signalGui->shutdown)
        global.sharedMemory->write(QString("SIGNAL_GUI: SHUTDOWN"));
    if (config.signalGui->newNote)
        global.sharedMemory->write(QString("SIGNAL_GUI: NEW_NOTE"));
    if (config.signalGui->newExternalNote)
        global.sharedMemory->write(QString("SIGNAL_GUI: NEW_EXTERNAL_NOTE"));
    if (config.signalGui->openNote)
        global.sharedMemory->write("SIGNAL_GUI: OPEN_NOTE " + QVariant(config.signalGui->lid).toString());
    if (config.signalGui->openNoteUrl)
        global.sharedMemory->write("SIGNAL_GUI: OPEN_NOTE_URL " + QVariant(config.signalGui->url).toString());
    if (config.signalGui->openExternalNote)
        global.sharedMemory->write("SIGNAL_GUI: OPEN_EXTERNAL_NOTE " + QVariant(config.signalGui->lid).toString());
    if (config.signalGui->openExternalNoteUrl)
        global.sharedMemory->write("SIGNAL_GUI: OPEN_EXTERNAL_NOTE_URL " + QVariant(config.signalGui->url).toString());
    if (config.signalGui->openNoteNewTab)
        global.sharedMemory->write("SIGNAL_GUI: OPEN_NOTE_NEW_TAB " + QVariant(config.signalGui->lid).toString());
    if (config.signalGui->openNoteNewTabUrl)
        global.sharedMemory->write("SIGNAL_GUI: OPEN_NOTE_NEW_TAB_URL " + QVariant(config.signalGui->url).toString());
    if (config.signalGui->synchronize)
        global.sharedMemory->write(QString("SIGNAL_GUI: SYNCHRONIZE"));

    return 0;
}
