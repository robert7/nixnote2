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

#include "notetable.h"
#include "resourcetable.h"
#include "configstore.h"
#include "notebooktable.h"
#include "linkednotebooktable.h"
#include "tagtable.h"
#include "src/global.h"
#include "src/utilities/noteindexer.h"
#include "src/utilities/NixnoteStringUtils.h"

#include <QSqlTableModel>
#include <QtXml>
#include "src/html/tagscanner.h"

extern Global global;

// Default constructor
NoteTable::NoteTable(DatabaseConnection *db)
{
    this->db = db;
}



// Given a note's lid, we give it a new guid.  This can happen
// the first time a record is synchronized
void NoteTable::updateGuid(qint32 lid, Guid &guid) {
    QLOG_TRACE() << "Entering NoteTable::updateNoteGuid()";

    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("Update DataStore set data=:data where key=:key and lid=:lid");
    query.bindValue(":data", guid);
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_GUID);
    query.exec();
    db->unlock();

    QLOG_TRACE() << "Leaving NoteTable::updateNoteGuid()";
}




// Synchronize a new note with what is in the database.  We basically
// just delete the old one & give it a new entry
void NoteTable::sync(Note &note, qint32 account) {
    sync(0, note, account);
}



// Synchronize a new note with what is in the database.  We basically
// just delete the old one & give it a new entry
void NoteTable::sync(qint32 lid, const Note &note, qint32 account) {
   // QLOG_TRACE() << "Entering NoteTable::sync()";

    if (lid > 0) {
        NSqlQuery query(db);

        // Delete the old record
        query.prepare("Delete from DataStore where lid=:lid");
        query.bindValue(":lid", lid);
        query.exec();
        query.finish();

        ResourceTable resTable(db);
        resTable.expungeByNote(lid);
    } else {
        ConfigStore cs(db);
        lid = cs.incrementLidCounter();
    }

    add(lid, note, false, account);
    setThumbnailNeeded(lid, true);

    //QLOG_TRACE() << "Leaving NoteTable::sync()";
}




// Given a note's GUID, we return the LID
qint32 NoteTable::getLid(QString guid) {

    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("Select lid from DataStore where key=:key and data=:data");
    query.bindValue(":key", NOTE_GUID);
    query.bindValue(":data", guid);
    query.exec();
    qint32 retval = 0;
    if (query.next())
        retval = query.value(0).toInt();
    query.finish();
    db->unlock();
    return retval;
}


// Given a note's lid, return the guid
QString NoteTable::getGuid(qint32 lid) {

    NSqlQuery query(db);
    QString retval = "";
    db->lockForRead();
    query.prepare("Select data from DataStore where key=:key and lid=:lid");
    query.bindValue(":key", NOTE_GUID);
    query.bindValue(":lid", lid);
    query.exec();
    if (query.next())
        retval = query.value(0).toString();
    query.finish();
    db->unlock();
    return retval;
}


// Given a note's GUID, we return the LID
qint32 NoteTable::getLid(string guid) {
    QString s(QString::fromStdString(guid));
    return getLid(s);
}


// Given a note's In-App or External URL, we return the LID
qint32 NoteTable::getLidFromUrl(QString noteUrl) {
    QString noteGuid = NixnoteStringUtils::extractNoteGuid(noteUrl);
    QLOG_DEBUG() << QString("getLidFromUrl: found note GUID=%1 from note url=%2").arg(noteGuid).arg(noteUrl);
    qint32 lid = getLid(noteGuid);
    QLOG_DEBUG() << QString("getLidFromUrl: found note lid: %1").arg(lid);
    return lid;
}


// Add a new note to the database
qint32 NoteTable::add(qint32 l, const Note &t, bool isDirty, qint32 account) {
    db->lockForWrite();

    ResourceTable resTable(db);
    ConfigStore cs(db);
    NSqlQuery query(db);
    qint32 lid = l;
    qint32 notebookLid = account;

    if (lid <= 0) {
        lid = cs.incrementLidCounter();
    }

    QString values = "";
    QList<qint32> lids;
    lids.clear();
    lids.append(lid);

    QList<QVariant> valueList;
    valueList.clear();

    QLOG_DEBUG() << "Adding note; lid=" << lid << ", title=" << (t.title.isSet() ? t.title : "title is empty");
    int lidSeqNum = 0;
    if (t.guid.isSet()) {
        QString guid = t.guid;
        QLOG_DEBUG() << "Adding note; guid=" << guid;
        values += joinValues(lids, NOTE_GUID, ":guid", lidSeqNum++) + ",";
        valueList.append(guid);
    }

    if (!global.disableThumbnails) {
        values += joinValues(lids, NOTE_THUMBNAIL_NEEDED, ":note_thumbnail_needed", lidSeqNum++) + ",";
        valueList.append(true);
    }

    if (t.title.isSet()) {
        QString title = t.title;
        values += joinValues(lids, NOTE_TITLE, ":title", lidSeqNum++) + ",";
        valueList.append(title);
    }

    if (t.content.isSet()) {
        QByteArray b;
        QString content = t.content;
#if QT_VERSION < 0x050000
        b.append(content.toAscii());
#else
        b.append(content);
#endif

        QLOG_DEBUG_FILE("incoming.enml", content);

        values += joinValues(lids, NOTE_CONTENT, ":note_content", lidSeqNum++) + ",";
        valueList.append(b);
    }

    if (t.contentHash.isSet()) {
        QByteArray contentHash = t.contentHash;
        values += joinValues(lids, NOTE_CONTENT_HASH, ":note_content_hash", lidSeqNum++) + ",";
        valueList.append(contentHash);
    }

    if (t.contentLength.isSet()) {
        qint32 len = t.contentLength;
        values += joinValues(lids, NOTE_CONTENT_LENGTH, ":note_content_length", lidSeqNum++) + ",";
        valueList.append(len);
    }

    if (t.updateSequenceNum.isSet()) {
        qint32 usn = t.updateSequenceNum;
        values += joinValues(lids, NOTE_UPDATE_SEQUENCE_NUMBER, ":note_update_sequence_number", lidSeqNum++) + ",";
        valueList.append(usn);
    }

    if (isDirty) {
        values += joinValues(lids, NOTE_ISDIRTY, ":is_dirty", lidSeqNum++) + ",";
        valueList.append(isDirty);
    }

    if (t.created.isSet()) {
        qlonglong date = t.created;
        values += joinValues(lids, NOTE_CREATED_DATE, ":created_date", lidSeqNum++) + ",";
        valueList.append(date);
    }

    if (t.updated.isSet()) {
        qlonglong date = t.updated;
        values += joinValues(lids, NOTE_UPDATED_DATE, ":updated_date", lidSeqNum++) + ",";
        valueList.append(date);
    }

    if (t.deleted.isSet()) {
        qlonglong date = t.deleted;
        values += joinValues(lids, NOTE_DELETED_DATE, ":deleted_date", lidSeqNum++) + ",";
        valueList.append(date);
    }

    if (t.active.isSet()) {
        bool active = t.active;
        values += joinValues(lids, NOTE_ACTIVE, ":note_ative", lidSeqNum++) + ",";
        valueList.append(active);
    }

    if (t.notebookGuid.isSet()) {
        NotebookTable notebookTable(db);
        LinkedNotebookTable linkedTable(db);
        if (account > 0)
            notebookLid = account;
        else
            notebookLid = 0;
        if (notebookLid <= 0)
            notebookLid = notebookTable.getLid(t.notebookGuid);
        if (notebookLid <= 0) {
            notebookLid = linkedTable.getLid(t.notebookGuid);
        }

        // If not found, we insert one to avoid problems.  We'll probably get the real data later
        if (notebookLid <= 0) {
            notebookLid = cs.incrementLidCounter();
            Notebook notebook;
            notebook.guid = t.notebookGuid;
            notebook.name = "<Missing Notebook>";
            notebookTable.add(notebookLid, notebook, false, false);
        }
        values += joinValues(lids, NOTE_NOTEBOOK_LID, ":note_notebook_lid", lidSeqNum++) + ",";
        valueList.append(notebookLid);
    }

    QList<QString> tagGuids;
    if (t.tagGuids.isSet())
        tagGuids = t.tagGuids;
    for (int i=0; i<tagGuids.size(); i++) {
        TagTable tagTable(db);
        qint32 tagLid = tagTable.getLid(tagGuids[i]);
        if (tagLid == 0) {
            // create a dummy tag to avoid later problems
            Tag newTag;
            newTag.guid = tagGuids[i];
            newTag.name = "";
            tagLid = cs.incrementLidCounter();
            tagTable.add(tagLid, newTag, false, 0);
        }

        values += joinValues(lids, NOTE_TAG_LID, ":note_tag_lid" + QString::number(i), lidSeqNum++) + ",";
        valueList.append(tagLid);
    }

    QList<Resource> resources;
    if (t.resources.isSet())
        resources = t.resources;

    QLOG_DEBUG() << "Adding resources count=" << resources.size();

    for (int i = 0; i < resources.size(); i++) {
        qint32 resLid;
        resLid = 0;
        Resource r;
        r = resources[i];
        QString noteGuid(t.guid);
        QString resourceGuid(resources[i].guid);
        resLid = resTable.getLid(noteGuid, resourceGuid);
        QLOG_DEBUG() << "Adding resource i=" << i << " noteGuid=" << noteGuid << ", resourceGuid=" << resourceGuid;


        if (resLid == 0)
            resLid = cs.incrementLidCounter();
        resTable.add(resLid, r, isDirty, lid);

        if (r.mime.isSet()) {
            QString mime = r.mime;
            if (!mime.startsWith("image/") && mime != "vnd.evernote.ink") {
                values += joinValues(lids, NOTE_HAS_ATTACHMENT, ":note_has_attachment", lidSeqNum++) + ",";
                valueList.append(true);
                break;
            }
        }
    }

    if (t.attributes.isSet()) {
        NoteAttributes na = t.attributes;
        if (na.subjectDate.isSet()) {
            qlonglong ts = na.subjectDate;
            values += joinValues(lids, NOTE_ATTRIBUTE_SUBJECT_DATE, ":subject_date", lidSeqNum++) + ",";
            valueList.append(ts);
        }
        if (na.latitude.isSet()) {
            double lat = na.latitude;
            values += joinValues(lids, NOTE_ATTRIBUTE_LATITUDE, ":lat", lidSeqNum++) + ",";
            valueList.append(lat);
        }
        if (na.longitude.isSet()) {
            double lon = na.longitude;
            values += joinValues(lids, NOTE_ATTRIBUTE_LONGITUDE, ":lon", lidSeqNum++) + ",";
            valueList.append(lon);
        }
        if (na.altitude.isSet()) {
            double alt = na.altitude;
            values += joinValues(lids, NOTE_ATTRIBUTE_ALTITUDE, ":alt", lidSeqNum++) + ",";
            valueList.append(alt);
        }
        if (na.author.isSet()) {
            QString author = na.author;
            values += joinValues(lids, NOTE_ATTRIBUTE_AUTHOR, ":author", lidSeqNum++) + ",";
            valueList.append(author);
        }
        if (na.source.isSet()) {
            QString source = na.source;
            values += joinValues(lids, NOTE_ATTRIBUTE_SOURCE, ":source", lidSeqNum++) + ",";
            valueList.append(source);
        }
        if (na.sourceURL.isSet()) {
            QString sourceURL = na.sourceURL;
            values += joinValues(lids, NOTE_ATTRIBUTE_SOURCE_URL, ":sourceURL", lidSeqNum++) + ",";
            valueList.append(sourceURL);
        }
        if (na.sourceApplication.isSet()) {
            QString sourceApplication = na.sourceApplication;
            values += joinValues(lids, NOTE_ATTRIBUTE_SOURCE_APPLICATION, ":sourceApplication", lidSeqNum++) + ",";
            valueList.append(sourceApplication);
        }
        if (na.shareDate.isSet()) {
            double date = na.shareDate;
            values += joinValues(lids, NOTE_ATTRIBUTE_SHARE_DATE, ":share_date", lidSeqNum++) + ",";
            valueList.append(date);
        }
        if (na.placeName.isSet()) {
            QString placename = na.placeName;
            values += joinValues(lids, NOTE_ATTRIBUTE_PLACE_NAME, ":placename", lidSeqNum++) + ",";
            valueList.append(placename);
        }
        if (na.contentClass.isSet()) {
            QString cc = na.contentClass;
            values += joinValues(lids, NOTE_ATTRIBUTE_CONTENT_CLASS, ":content_class", lidSeqNum++) + ",";
            valueList.append(cc);
        }
        if (na.reminderTime.isSet()) {
            double rt = na.reminderTime;
            values += joinValues(lids, NOTE_ATTRIBUTE_REMINDER_TIME, ":reminder_time", lidSeqNum++) + ",";
            valueList.append(rt);
        }
        if (na.reminderDoneTime.isSet()) {
            double rt = na.reminderDoneTime;
            values += joinValues(lids, NOTE_ATTRIBUTE_REMINDER_DONE_TIME, ":reminder_done_time", lidSeqNum++) + ",";
            valueList.append(rt);
        }
        if (na.reminderOrder.isSet()) {
            bool rt = na.reminderOrder;
            values += joinValues(lids, NOTE_ATTRIBUTE_REMINDER_ORDER, ":reminder_order", lidSeqNum++) + ",";
            valueList.append(rt);
        }
    }

    // No determine some attributes of the note based upon the content
    // This should probably happen every time a note changes? Or at least something simular:
    QString content;
    if (t.content.isSet())
        content = t.content;
    else
        content = "";

    if (content.contains("<en-crypt")) {
        values += joinValues(lids, NOTE_HAS_ENCRYPT, ":has_encrypt", lidSeqNum++) + ",";
        valueList.append(true);
    }

    if (content.contains("<en-todo")) {
        if (content.contains("<en-todo checked=\"true\"")) {
            values += joinValues(lids, NOTE_HAS_TODO_COMPLETED, ":note_has_todo_completed", lidSeqNum++) + ",";
            valueList.append(true);
        }
        if (content.contains("<en-todo checked=\"false\"") || content.contains("<en-todo/>")) {
            values += joinValues(lids, NOTE_HAS_TODO_UNCOMPLETED, ":note_has_todo_uncompleted", lidSeqNum++) + ",";
            valueList.append(true);
        }
    }

    updateNoteList(lid, t, isDirty, account);

    // Experimental index helper
    if (global.enableIndexing) {
        values += joinValues(lids, NOTE_INDEX_NEEDED, ":note_index_needed", lidSeqNum++) + ",";
        valueList.append(true);
    } else {
        NoteIndexer indexer(db);
        indexer.indexNote(lid);
    }
    if (values != "") {
        values.chop(1);
    }

    QString sql = "Insert into DataStore (lid, key, data) values " + values;
    query.prepare(sql);
    // Some versions of QSqlQuery don't allow binding all the keys with
    // one same name appearing in the query string with one same value
    // through one call of bindValue(), so for compatibilty, we have
    // to append a sequence number to the key name to differentiate
    // them. And correspondingly we have to append the same lid
    // muliple times, so that we can use bindLids() function to bind
    // them.
    for (int i = 0; i < lidSeqNum - 1; ++i) {
        lids.append(lid);
    }
    bindLids(query, lids);
    for (int i = 0; i < valueList.size(); ++i) {
        if (valueList[i].type() == QVariant::Bool ||
            valueList[i].type() == QVariant::Int) {
            query.bindValue(i*2 + 1, valueList[i].toInt());
        } else if (valueList[i].type() == QVariant::LongLong) {
            query.bindValue(i*2 + 1, valueList[i].toLongLong());
        } else {
            query.bindValue(i*2 + 1, valueList[i].toString());
        }
    }
    query.exec();
    query.finish();

    db->unlock();
    return lid;
}



// Add a stub for a note.  More information about the note will be added later.  This can
// happen during a sync if a resource appears before the note itself
qint32 NoteTable::addStub(QString noteGuid) {
    db->lockForWrite();
    ConfigStore cs(db);
    NSqlQuery query(db);

    qint32 lid = 0;
    lid = getLid(noteGuid);

    if (lid <= 0)
        lid = cs.incrementLidCounter();

    query.prepare("Insert into DataStore (lid, key, data) values (:lid, :key, :data)");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_GUID);
    query.bindValue(":data", noteGuid);
    query.exec();
    query.finish();
    db->unlock();
    return lid;
}



// Update the note listing table
bool NoteTable::updateNoteList(qint32 lid, const Note &t, bool isDirty, qint32 notebook) {

    if (lid <= 0)
        return false;

    db->lockForWrite();
    NotebookTable notebookTable(db);
    LinkedNotebookTable linkedNotebookTable(db);
    QString notebookName = "";

    qint32 notebookLid = notebook;
    qint32 account = 0;
    if (notebookLid <= 0)
        notebookLid = notebookTable.getLid(t.notebookGuid);
    if (notebookLid <=0) {
        notebookLid = linkedNotebookTable.getLid(t.notebookGuid);
        if (notebookLid > 0)
            account = notebookLid;
    }
    if (notebookLid <=0)
        notebookLid = notebookTable.addStub(t.notebookGuid);
    else {
        Notebook notebook;
        notebookTable.get(notebook, notebookLid);
        notebookName = notebook.name;
    }
    // Now let's update the user table
    NSqlQuery query(db);

    query.prepare("Delete from NoteTable where lid=:lid");
    query.bindValue(":lid", lid);
    query.exec();

    query.prepare(QString("Insert into NoteTable (lid, title, author, ") +
                  QString("dateCreated, dateUpdated, dateSubject, dateDeleted, source, sourceUrl, sourceApplication, ") +
                  QString("latitude, longitude, altitude, reminderOrder, reminderTime, reminderDoneTime, hasEncryption, hasTodo, isDirty, size, notebook, notebookLid, tags) ") +
                  QString("Values (:lid, :title, :author, ") +
                  QString(":dateCreated, :dateUpdated, :dateSubject, :dateDeleted, :source, :sourceUrl, :sourceApplication, ") +
                  QString(":latitude, :longitude, :altitude, :reminderOrder, :reminderTime, :reminderDoneTime, :hasEncryption, :hasTodo, :isDirty, :size, :notebook, :notebookLid, :tags) ")) ;

    query.bindValue(":lid", lid);

    QString title = "";
    if (t.title.isSet())
        title = t.title;
    query.bindValue(":title", title);

    NoteAttributes na;
    if (t.attributes.isSet())
        na = t.attributes;
    if (na.author.isSet()) {
        QString author = na.author;
        query.bindValue(":author",author);
    } else {
        query.bindValue(":author", "");
    }
    if (na.subjectDate.isSet()) {
        double sd = na.subjectDate;
        query.bindValue(":dateSubject", sd);
    } else {
        query.bindValue(":dateSubject", 0);
    }
    if (na.source.isSet()) {
        QString source = na.source;
        query.bindValue(":source", source);
    } else {
        query.bindValue(":source", "");
    }
    if (na.sourceURL.isSet()) {
        QString url = na.sourceURL;
        query.bindValue(":sourceUrl", url);
    } else {
        query.bindValue(":sourceUrl", "");
    }
    if (na.sourceApplication.isSet()) {
        QString sa = na.sourceApplication;
        query.bindValue(":sourceApplication", sa);
    } else {
        query.bindValue(":sourceApplication", "");
    }
    if (na.latitude.isSet()) {
        double lat = na.latitude;
        query.bindValue(":latitude", lat);
    } else {
        query.bindValue(":latitude", 0);
    }
    if (na.longitude.isSet()) {
        double lon = na.longitude;
        query.bindValue(":longitude",lon);
    } else {
        query.bindValue(":longitude", 0);
    }
    if (na.altitude.isSet()) {
        double alt = na.altitude;
        query.bindValue(":altitude", alt);
    } else {
        query.bindValue(":altitude", 0);
    }
    if (na.reminderOrder.isSet()) {
        qint64 order = na.reminderOrder;
        query.bindValue(":reminderOrder", order);
    } else {
        query.bindValue(":reminderOrder", 0);
    }
    if (na.reminderTime.isSet()) {
        qlonglong rt = na.reminderTime;
        query.bindValue(":reminderTime", rt);
    } else {
        query.bindValue(":reminderTime", 0);
    }
    if (na.reminderDoneTime.isSet()) {
        qlonglong rt = na.reminderDoneTime;
        query.bindValue(":reminderDoneTime", rt);
    } else {
        query.bindValue(":reminderDoneTime", 0);
    }

    qlonglong created = 0;
    if (t.created.isSet())
        created = t.created;
    query.bindValue(":dateCreated", created);

    qlonglong updated = created;
    if (t.updated.isSet())
        updated = t.updated;
    query.bindValue(":dateUpdated", updated);

    qlonglong deleted = 0;
    if (t.deleted.isSet())
        deleted = t.deleted;
    query.bindValue(":dateDeleted", deleted);

    bool hasEncryption;
    QString content;
    if (t.content.isSet())
        content = t.content;
    if (content.contains("<en-crypt"))
        hasEncryption = true;
    else
        hasEncryption = false;
    query.bindValue(":hasEncryption", hasEncryption);
    bool hasTodo;
    if (content.contains("<en-todo"))
        hasTodo = true;
    else
        hasTodo = false;
    query.bindValue(":hasTodo", hasTodo);
    query.bindValue(":isDirty", isDirty);
    qlonglong size = content.length();

    QList<Resource> reslist;
    if (t.resources.isSet())
        reslist = t.resources;
    for (int i=0; i<reslist.size(); i++) {
        if (reslist[i].data.isSet()) {
        Data d = reslist[i].data;
        if (d.size.isSet())
            size+=d.size;
        }
    }
    query.bindValue(":size", size);
    query.bindValue(":notebook", notebookName);
    query.bindValue(":notebookLid", notebookLid);

    QString tagName;
    QList<QString> tagNames;

    // Normal sort is below.  If user has problems with non-ASCII characters
    // they can choose to bypass the name sorting
    if (!global.nonAsciiSortBug) {
        QStringList sortedNames;
        if (t.tagNames.isSet())
            tagNames = t.tagNames;
        for (int i=0; i<tagNames.size(); i++) {
            sortedNames.append(tagNames[i].toLower());
        }
        sortedNames.sort();

        TagTable tagTable(db);

        // We search the table to get the name in the correct case.
        // We lowercased them above to sort properly without regards
        // to case.  Now, for the note list we need the correct case
        for (int i=0; i<sortedNames.size(); i++) {
            Tag currentTag;
            qint32 tagLid = tagTable.findByName(sortedNames[i], account);
            tagTable.get(currentTag, tagLid);
            if (currentTag.name.isSet()) {
                if (i>0) {
                    tagName = tagName+", ";
                }
                tagName = tagName + currentTag.name;
            }
        }
    } else {
        // Users have experienced bugs with the above because of non-ASCII characters.
        // This enables them to bypass the bug at the cost of not sorting tags.
        if (t.tagNames.isSet())
            tagNames = t.tagNames;
        for (int i=0; i<tagNames.size(); i++) {
            if (i>0)
                tagName = tagName+", ";
            tagName = tagName + tagNames[i];
        }
    }

    query.bindValue(":tags", tagName);

    if (!query.exec()) {
        QLOG_ERROR() << "Error inserting into NoteTable: " << query.lastError();
        QLOG_ERROR() << "Error inserting into NoteTable: " << query.lastQuery();
        query.finish();
        db->unlock();
        return false;
    }
    query.finish();
    db->unlock();
    return true;
}



// Update the name of a notebook in the note list table
bool NoteTable::updateNotebookName(qint32 lid, QString name) {
    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("Update NoteTable set notebook=:name where notebooklid=:lid");
    query.bindValue(":name", name);
    query.bindValue(":lid", lid);
    bool retval = query.exec();
    query.finish();
    db->unlock();
    return retval;
}


// Return a note structure given the LID
bool NoteTable::get(Note &note, qint32 lid, bool loadResources, bool loadBinary) {

    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("Select key, data from DataStore where lid=:lid");
    query.bindValue(":lid", lid);
    NoteAttributes na;
    QList<QString> tagGuids;
    QList<QString> tagNames;
    if (note.attributes.isSet()) {
        na = note.attributes;
    }
    query.exec();
    while (query.next()) {
        qint32 key = query.value(0).toInt();
        switch (key) {
            case (NOTE_GUID):
                note.guid = query.value(1).toString();
                break;
            case (NOTE_UPDATE_SEQUENCE_NUMBER):
                note.updateSequenceNum = query.value(1).toInt();
                break;
            case (NOTE_ACTIVE):
                note.active = query.value(1).toBool();
                break;
            case (NOTE_DELETED_DATE):
                note.active = query.value(1).toLongLong();
                break;
            case (NOTE_ATTRIBUTE_SOURCE_URL):
                na.sourceURL = query.value(1).toString();
                note.attributes = na;
                break;
            case (NOTE_ATTRIBUTE_SOURCE_APPLICATION):
                na.sourceApplication = query.value(1).toString();
                note.attributes = na;
                break;
            case (NOTE_CONTENT_LENGTH):
                note.contentLength = query.value(1).toLongLong();
                break;
            case (NOTE_ATTRIBUTE_LONGITUDE):
                na.longitude = query.value(1).toFloat();
                note.attributes = na;
                break;
            case (NOTE_TITLE):
                note.title = query.value(1).toString();
                break;
            case (NOTE_ATTRIBUTE_SOURCE):
                na.source = query.value(1).toString();
                note.attributes = na;
                break;
            case (NOTE_ATTRIBUTE_ALTITUDE):
                na.altitude = query.value(1).toFloat();
                note.attributes = na;
                break;
            case (NOTE_NOTEBOOK_LID): {
                qint32 notebookLid = query.value(1).toInt();
                NotebookTable ntable(db);
                QString notebookGuid;
                ntable.getGuid(notebookGuid, notebookLid);
                note.notebookGuid = notebookGuid;
                break;
            }
            case (NOTE_UPDATED_DATE):
                note.updated = query.value(1).toLongLong();
                break;
            case (NOTE_CREATED_DATE):
                note.created = query.value(1).toLongLong();
                break;
            case (NOTE_ATTRIBUTE_SUBJECT_DATE):
                na.subjectDate = query.value(1).toLongLong();
                note.attributes = na;
                break;
            case (NOTE_ATTRIBUTE_LATITUDE):
                na.latitude = query.value(1).toFloat();
                note.attributes = na;
                break;
            case (NOTE_CONTENT):
                note.content = query.value(1).toByteArray().data();

                // Sometimes Evernote doesn't send the XML tag with UTF8 encoding. This forces it.
                if (global.forceUTF8 && !note.content->startsWith("<?xml"))
                    note.content = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" + note.content;
                break;
            case (NOTE_CONTENT_HASH):
                note.contentHash = query.value(1).toByteArray();
                break;
            case (NOTE_ATTRIBUTE_AUTHOR):
                na.author = query.value(1).toString();
                note.attributes = na;
                break;
            case (NOTE_ISDIRTY):
                break;
            case (NOTE_ATTRIBUTE_SHARE_DATE) :
                na.shareDate = query.value(1).toLongLong();
                note.attributes = na;
                break;
            case (NOTE_ATTRIBUTE_PLACE_NAME) :
                na.placeName = query.value(1).toString();
                note.attributes = na;
                break;
            case (NOTE_ATTRIBUTE_CONTENT_CLASS) :
                na.contentClass = query.value(1).toString();
                note.attributes = na;
                break;
            case (NOTE_ATTRIBUTE_REMINDER_ORDER) :
                na.reminderOrder = query.value(1).toLongLong();
                note.attributes = na;
                break;
            case (NOTE_ATTRIBUTE_REMINDER_DONE_TIME) :
                na.reminderDoneTime = query.value(1).toLongLong();
                note.attributes = na;
                break;
            case (NOTE_ATTRIBUTE_REMINDER_TIME) :
                na.reminderTime = query.value(1).toLongLong();
                note.attributes = na;
                break;
            case (NOTE_TAG_LID) :
                TagTable tagTable(db);
                qint32 tagLid = query.value(1).toInt();
                Tag tag;
                tagTable.get(tag, tagLid);
                if (tag.guid.isSet())
                    tagGuids.append(tag.guid);
                if (tag.name.isSet())
                    tagNames.append(tag.name);
                break;
        }
    }
    query.finish();

    // pass always - https://github.com/d1vanov/quentier/issues/266
    // if (tagGuids.size() > 0) {
    note.tagGuids = tagGuids;
    note.tagNames = tagNames;
    // }

    ResourceTable resTable(db);
    QLOG_TRACE() << "Fetching Resources? " << loadResources << " With binary? " << loadBinary;

    QList<Resource> resources;
    resTable.getAllResources(resources, lid, loadResources, loadBinary);
    note.resources = resources;
    QLOG_TRACE() << "Fetched resources";

    db->unlock();
    return note.guid.isSet();
}



// Return a note given the GUID
bool NoteTable::get(Note& note, QString guid,bool loadResources, bool loadBinary) {
    qint32 lid = getLid(guid);
    return get(note, lid, loadResources, loadBinary);
}



// Return a note given the GUID as a std::string
bool NoteTable::get(Note &note, string guid, bool loadResources, bool loadBinary) {
    qint32 lid = getLid(guid);
    return get(note, lid, loadResources, loadBinary);
}



// Return if a note is dirty given its lid
bool NoteTable::isIndexNeeded(qint32 lid) {
    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("Select data from DataStore where key=:key and lid=:lid");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_INDEX_NEEDED);
    query.exec();
    bool retval = false;
    if (query.next())
        retval = query.value(0).toBool();
    query.finish();
    db->unlock();
    return retval;
}



// Return if a note is dirty given its lid
bool NoteTable::isDirty(qint32 lid) {
    db->lockForRead();
    NSqlQuery query(db);
    bool retval = false;
    query.prepare("Select data from DataStore where key=:key and lid=:lid");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_ISDIRTY);
    query.exec();
    if (query.next())
        retval = query.value(0).toBool();
    query.finish();
    db->unlock();
    return retval;
}


// Determine if a note is dirty given a guid
bool NoteTable::isDirty(QString guid) {
    qint32 lid = getLid(guid);
    return isDirty(lid);
}


// Determine if a note is dirty given a guid
bool NoteTable::isDirty(string guid) {
    QString g(QString::fromStdString(guid));
    return isDirty(g);
}


// Does this note exist?
bool NoteTable::exists(qint32 lid) {
    NSqlQuery query(db);
    bool retval = false;
    db->lockForRead();
    query.prepare("Select lid from DataStore where key=:key and lid=:lid");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_GUID);
    query.exec();
    if (query.next())
        retval =  true;
    query.finish();
    db->unlock();
    return retval;
}


// Determine if a note is dirty given a guid
bool NoteTable::exists(QString guid) {
    qint32 lid = getLid(guid);
    return exists(lid);
}


// Determine if a note is dirty given a guid
bool NoteTable::exists(string guid) {
    qint32 lid = getLid(guid);
    return exists(lid);
}



// Find the note LIDs for a tag
qint32 NoteTable::findNotesByTag(QList<qint32> &values, qint32 tagLid) {
    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("Select lid from DataStore where key=:key and data=:tagLid");
    query.bindValue(":key", NOTE_TAG_LID);
    query.bindValue(":tagLid", tagLid);
    query.exec();
    while (query.next()) {
        values.append(query.value(0).toInt());
    }
    query.finish();
    db->unlock();
    return values.size();
}



// Find the note LIDs for a tag
qint32 NoteTable::findNotesByTag(QList<qint32> &values, QString data) {
    TagTable tagTable(db);
    qint32 tagLid = tagTable.getLid(data);
    return findNotesByTag(values, tagLid);
}



// Find the note LIDs for a tag
qint32 NoteTable::findNotesByTag(QList<qint32> &values, string data) {
    return findNotesByTag(values, QString::fromStdString(data));
}


// Update the user note list with the proper tag names
void NoteTable::updateNoteListTags(qint32 noteLid, QString tags) {
    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("Update NoteTable set tags=:tags where lid=:lid");
    query.bindValue(":lid", noteLid);
    query.bindValue(":tags", tags);
    query.exec();
    query.finish();
    db->unlock();
}



// Update the user's notebook name list
void NoteTable::updateNoteListNotebooks(QString guid, QString name) {
    db->lockForWrite();
    NotebookTable notebookTable(db);
    qint32 notebookLid;
    notebookLid = notebookTable.getLid(guid);
    NSqlQuery sql2(db);
    sql2.prepare("Update NoteTable set notebook=:note where lid=:lid");
    sql2.bindValue(":note", name);
    sql2.bindValue(":lid", notebookLid);
    sql2.exec();
    sql2.finish();
    db->unlock();
}



// Get a list of notes for a given tag
qint32 NoteTable::getNotesWithTag(QList<qint32> &retval, QString tag) {
    db->lockForRead();
    NSqlQuery query(db);
    TagTable tagTable(db);
    qint32 tagLid = tagTable.getLid(tag);
    query.prepare("Select lid data from DataStore where data=:tag and key=:key");
    query.bindValue(":tag", tagLid);
    query.bindValue(":key", NOTE_TAG_LID);
    query.exec();
    while(query.next()) {
        retval.append(query.value(0).toInt());
    }
    query.finish();
    db->unlock();
    return retval.size();
}


// Set if a note needs to be indexed
void NoteTable::setIndexNeeded(qint32 lid, bool indexNeeded) {
    QList<qint32> noteLids;
    noteLids.clear();
    noteLids.append(lid);
    setIndexNeeded(noteLids, indexNeeded);
}


// Set if notes need to be indexed
void NoteTable::setIndexNeeded(const QList<qint32> &indexNoteLids, bool indexNeeded) {
    QLOG_TRACE_IN();

    QList<qint32> noteLids;
    noteLids.clear();
    for (int i = 0; i < indexNoteLids.size(); ++i) {
        // If it is already set to this value, then we don't need to
        // do anything.
        if (this->isIndexNeeded(indexNoteLids[i]) != indexNeeded) {
            noteLids.append(indexNoteLids[i]);
        }
    }

    QString lids = joinLids(noteLids);
    if (lids == "") {
        QLOG_TRACE_OUT();
        return;
    }

    NSqlQuery query(db);
    db->lockForWrite();

    query.prepare("Delete from DataStore where lid in (" +
            lids + ") and key=:key");
    bindLids(query, noteLids);
    query.bindValue(":key", NOTE_INDEX_NEEDED);
    query.exec();

    // We don't really need to do anything after deleting the flag
    if (!indexNeeded) {
        query.finish();
        db->unlock();

        QLOG_TRACE_OUT();
        return;
    }

    QString values = joinValues(noteLids, NOTE_INDEX_NEEDED, indexNeeded);
    query.prepare("Insert into DataStore (lid, key, data) values " + values);
    bindLids(query, noteLids);
    query.exec();

    query.finish();
    db->unlock();

    // Experimental class to index at save
    if (!global.enableIndexing) {
        QLOG_TRACE() << "Calling indexNote";
        NoteIndexer indexer(db);
        indexer.indexNotes(noteLids);
    }
    QLOG_TRACE_OUT();
}


// Set if a note needs to be indexed
qint32 NoteTable::getIndexNeeded(QList<qint32> &lids) {
    NSqlQuery query(db);
    lids.clear();
    qlonglong delayTime = QDateTime::currentDateTime().currentMSecsSinceEpoch()-300000;
    db->lockForRead();
    query.prepare("Select lid, data from DataStore where key=:key and lid in (select lid from datastore where key=:key2 and data=1)");
    query.bindValue(":key", NOTE_UPDATED_DATE);
    query.bindValue(":key2", NOTE_INDEX_NEEDED);
    query.exec();
    while (query.next()) {
        qlonglong dt = query.value(1).toLongLong();
        if (delayTime > dt)
            lids.append(query.value(0).toInt());
    }
    query.finish();
    db->unlock();
    return lids.size();
}



// Update the notebook for a note
void NoteTable::updateNotebook(qint32 noteLid, qint32 notebookLid, bool setAsDirty) {
    QList<qint32> noteLids;
    noteLids.clear();
    noteLids.append(noteLid);
    updateNotebook(noteLids, notebookLid, setAsDirty);
}


// Update the notebook for multiple notes
void NoteTable::updateNotebook(const QList<qint32> &noteLids,
        qint32 notebookLid, bool setAsDirty) {
    Notebook book;
    NotebookTable notebookTable(db);
    notebookTable.get(book, notebookLid);

    if (!book.guid.isSet()) {
        return;
    }

    QString lids = joinLids(noteLids);

    NSqlQuery query(db);
    db->lockForWrite();

    query.prepare("Update DataStore set data=:notebookLid where lid in (" +
            lids + ") and key=:key;");
    bindLids(query, noteLids);
    query.bindValue(":notebookLid", notebookLid);
    query.bindValue(":key", NOTE_NOTEBOOK_LID);
    query.exec();

    if (setAsDirty) {
        setDirty(noteLids, setAsDirty, false);
    }

    QString bookName = book.name;
    query.prepare("Update NoteTable set notebook=:name where lid in (" +
            lids + ")");
    bindLids(query, noteLids);
    query.bindValue(":name", bookName);
    query.exec();

    query.prepare("Update NoteTable set notebookLid=:nlid where lid in (" +
            lids + ")");
    bindLids(query, noteLids);
    query.bindValue(":nlid", notebookLid);
    query.exec();

    query.finish();

    db->unlock();
}


// Update the URL for a note
void NoteTable::updateUrl(qint32 noteLid, QString url, bool setAsDirty=false) {
    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("delete from datastore where lid=:lid and key=:key");
    query.bindValue(":lid", noteLid);
    query.bindValue(":key", NOTE_ATTRIBUTE_SOURCE_URL);
    query.exec();

    if (url.trimmed() != "") {
        query.prepare("Insert into DataStore (lid, key, data) values (:lid, :key, :data)");
        query.bindValue(":lid", noteLid);
        query.bindValue(":key", NOTE_ATTRIBUTE_SOURCE_URL);
        query.bindValue(":data", url);
        query.exec();
    }

    if (setAsDirty) {
        setDirty(noteLid, setAsDirty);
    }

    query.prepare("Update NoteTable set SourceURl=:url where lid=:lid");
    query.bindValue(":url", url);
    query.bindValue(":lid", noteLid);
    query.exec();
    query.finish();
    db->unlock();
}




// Update the title for a note
void NoteTable::updateTitle(qint32 noteLid, QString title, bool setAsDirty=false) {
    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("Update DataStore set data=:url where lid=:lid and key=:key;");
    query.bindValue(":url", title);
    query.bindValue(":lid", noteLid);
    query.bindValue(":key", NOTE_TITLE);
    query.exec();

    if (setAsDirty) {
        setDirty(noteLid, setAsDirty);
    }

    query.prepare("Update NoteTable set Title=:url where lid=:lid");
    query.bindValue(":url", title);
    query.bindValue(":lid", noteLid);
    query.exec();
    query.finish();
    db->unlock();
}




// Update the author for a note
void NoteTable::updateAuthor(qint32 noteLid, QString author, bool setAsDirty=false) {
    if (noteLid <=0)
        return;
    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("Delete from Datastore where lid=:lid and key=:key");
    query.bindValue(":lid", noteLid);
    query.bindValue(":key", NOTE_ATTRIBUTE_AUTHOR);
    query.exec();

    query.prepare("Insert into Datastore(lid, key, data) values(:lid, :key, :author);");
    query.bindValue(":author", author);
    query.bindValue(":lid", noteLid);
    query.bindValue(":key", NOTE_ATTRIBUTE_AUTHOR);
    query.exec();

    if (setAsDirty) {
        setDirty(noteLid, setAsDirty);
    }

    query.prepare("Update NoteTable set Author=:author where lid=:lid");
    query.bindValue(":author", author);
    query.bindValue(":lid", noteLid);
    query.exec();
    query.finish();
    db->unlock();
}



// Update the subject/update/deleted/created date for a note
void NoteTable::updateDate(qint32 lid, Timestamp ts, qint32 key, bool isDirty = false) {
    if (lid <= 0)
        return;

    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("Update DataStore set data=:ts where lid=:lid and key=:key;");
    query.bindValue(":ts",ts);
    query.bindValue(":lid", lid);
    query.bindValue(":key",key);
    query.exec();

    if (isDirty) {
        setDirty(lid, isDirty);
    }

    if (key == NOTE_CREATED_DATE)
        query.prepare("Update NoteTable set dateCreated=:date where lid=:lid");
    if (key == NOTE_UPDATED_DATE)
        query.prepare("Update NoteTable set dateUpdated=:date where lid=:lid");
    if (key == NOTE_DELETED_DATE)
        query.prepare("Update NoteTable set dateDeleted=:date where lid=:lid");
    if (key == NOTE_ATTRIBUTE_SUBJECT_DATE)
        query.prepare("Update NoteTable set dateSubject=:date where lid=:lid");
    if (key == NOTE_ATTRIBUTE_REMINDER_TIME) {
        query.prepare("Delete from Datastore where lid=:lid and key=:key");
        query.bindValue(":lid", lid);
        query.bindValue(":key", NOTE_ATTRIBUTE_REMINDER_TIME);
        query.exec();

        query.prepare("Delete from Datastore where lid=:lid and key=:key");
        query.bindValue(":lid", lid);
        query.bindValue(":key", NOTE_ATTRIBUTE_REMINDER_ORDER);
        query.exec();

        query.prepare("Delete from Datastore where lid=:lid and key=:key");
        query.bindValue(":lid", lid);
        query.bindValue(":key", NOTE_ATTRIBUTE_REMINDER_DONE_TIME);
        query.exec();

        query.prepare("Insert into Datastore (lid, key, data) values (:lid, :key, :data)");
        query.bindValue(":lid", lid);
        query.bindValue(":key", NOTE_ATTRIBUTE_REMINDER_TIME);
        query.bindValue(":data", QVariant::fromValue(ts));
        query.exec();

        query.prepare("Insert into Datastore (lid, key, data) values (:lid, :key, datetime('now'))");
        query.bindValue(":lid", lid);
        query.bindValue(":key",NOTE_ATTRIBUTE_REMINDER_ORDER);
        query.exec();

        query.prepare("Update NoteTable set reminderTime=:date where lid=:lid");
    }

    query.bindValue(":date", QVariant::fromValue(ts));
    query.bindValue(":lid", lid);
    query.exec();
    query.finish();
    db->unlock();
}



void NoteTable::removeTag(qint32 lid, qint32 tag, bool isDirty = false) {
    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("delete from DataStore where lid=:lid and key=:key and data=:tag");
    query.bindValue(":lid", lid);
    query.bindValue(":key",NOTE_TAG_LID);
    query.bindValue(":tag", tag);
    query.exec();;
    query.finish();
    db->unlock();
    if (isDirty) {
        setDirty(lid, isDirty, false);
    }
    rebuildNoteListTags(lid);
}


void NoteTable::addTag(qint32 lid, qint32 tag, bool isDirty = false) {
    if (lid <= 0)
        return;

    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("delete from DataStore where lid=:lid and key=:key and data=:tag");
    query.bindValue(":lid", lid);
    query.bindValue(":key",NOTE_TAG_LID);
    query.bindValue(":tag:", tag);
    query.exec();

    query.prepare("insert into DataStore (lid, key, data) values (:lid, :key, :data)");
    query.bindValue(":lid", lid);
    query.bindValue(":key",NOTE_TAG_LID);
    query.bindValue(":data", tag);
    query.exec();
    query.finish();
    db->unlock();

    if (isDirty) {
        setDirty(lid, isDirty, false);
    }
    rebuildNoteListTags(lid);
}


bool NoteTable::hasTag(qint32 noteLid, qint32 tagLid) {
    NSqlQuery query(db);
    db->lockForRead();
    bool retval = false;
    query.prepare("select lid from DataStore where lid=:lid and key=:key and data=:tag");
    query.bindValue(":lid", noteLid);
    query.bindValue(":key",NOTE_TAG_LID);
    query.bindValue(":tag:", tagLid);
    query.exec();
    if (query.next())
        retval =  true;
    query.finish();
    db->unlock();
    return retval;
}


void NoteTable::rebuildNoteListTags(qint32 lid) {
    // update the note list
    QStringList tagNames;
    TagTable tagTable(db);
    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("select data from DataStore where lid=:lid and key=:key");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_TAG_LID);
    query.exec();
    while (query.next()) {
        qint32 tagLid = query.value(0).toInt();
        Tag t;
        tagTable.get(t, tagLid);
        if (t.name.isSet())
            tagNames.append(t.name);
    }
    qSort(tagNames.begin(), tagNames.end(), caseInsensitiveLessThan);
    QString tagCol;
    for (qint32 i=0; i<tagNames.size(); i++) {
        tagCol = tagCol + tagNames[i];
        if (i<tagNames.size()-1)
            tagCol=tagCol+", ";
    }
    query.prepare("update NoteTable set tags=:tags where lid=:lid");
    query.bindValue(":tags", tagCol);
    query.bindValue(":lid", lid);
    query.exec();
    query.finish();
    db->unlock();
}



QString NoteTable::getNoteListTags(qint32 lid) {
    db->lockForRead();
    QString retval = "";
    NSqlQuery query(db);
    query.prepare("select tags from NoteTable where lid=:lid");
    query.bindValue(":lid", lid);
    query.exec();
    if (query.next()) {
        retval = query.value(0).toString();
    }
    query.finish();
    db->unlock();
    return retval;
}

// setDateUpdated: default true
void NoteTable::setDirty(qint32 lid, bool dirty, bool setDateUpdated) {
    QList<qint32> noteLids;
    noteLids.clear();
    noteLids.append(lid);
    setDirty(noteLids, dirty, setDateUpdated);
}


// Set multiple notes as dirty.
void NoteTable::setDirty(const QList<qint32> &noteLids, bool dirty,
        bool setDateUpdated) {
    QString lids = joinLids(noteLids);
    if (lids == "") {
        return;
    }

    NSqlQuery query(db);
    db->lockForWrite();

    // If it is setting it as dirty, we need to update the
    // update date &  time.
    if (dirty && setDateUpdated) {
        qint64 dt = QDateTime::currentMSecsSinceEpoch();

        query.prepare("Update DataStore set data=:value where lid in (" +
                lids + ") and key=:key");
        bindLids(query, noteLids);
        query.bindValue(":key", NOTE_UPDATED_DATE);
        query.bindValue(":value", dt);
        query.exec();

        query.prepare("Update NoteTable set dateUpdated=:value where lid in (" +
                lids + ")");
        bindLids(query, noteLids);
        query.bindValue(":value", dt);
        query.exec();
    }

    // If we got here, then the current dirty state doesn't match
    // what the caller wants.
    // If it is already set to the value, then we don't
    // need to do anything more.
    query.prepare("Update NoteTable set isDirty=:isDirty where lid in (" +
            lids + ") and isDirty!=:isDirty");
    bindLids(query, noteLids);
    query.bindValue(":isDirty", dirty);
    query.exec();

    query.prepare("Delete from DataStore where lid in (" +
            lids + ") and key=:key and data!=:data");
    bindLids(query, noteLids);
    query.bindValue(":key", NOTE_ISDIRTY);
    query.bindValue(":data", dirty);
    query.exec();

    if (dirty) {
        QString values = joinValues(noteLids, NOTE_ISDIRTY, dirty);
        query.prepare("Insert into DataStore (lid, key, data) values " + values);
        bindLids(query, noteLids);
        query.exec();
    }

    query.finish();
    db->unlock();

    if (dirty) {
        setIndexNeeded(noteLids, true);
    }
}


bool NoteTable::isDeleted(qint32 lid) {
    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("select data from DataStore where key=:key and lid=:lid");
    query.bindValue(":key", NOTE_ACTIVE);
    query.bindValue(":lid", lid);
    query.exec();
    if (query.next()) {
        db->unlock();
        bool active = query.value(0).toBool();
        query.finish();
        return !active;
    }
    query.finish();
    db->unlock();
    return false;
}



void NoteTable::deleteNote(qint32 lid, bool isDirty=true) {
    if (lid <=0)
        return;

    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("delete from DataStore where key=:key and lid=:lid");
    query.bindValue(":key", NOTE_ACTIVE);
    query.bindValue(":lid", lid);
    query.exec();

    query.prepare("delete from DataStore where key=:key and lid=:lid");
    query.bindValue(":key", NOTE_DELETED_DATE);
    query.bindValue(":lid", lid);
    query.exec();

    if (isDirty) {
        query.prepare("delete from DataStore where key=:key and lid=:lid");
        query.bindValue(":key", NOTE_ISDIRTY);
        query.bindValue(":lid", lid);
        query.exec();
    }

    query.prepare("Insert into DataStore (lid, key, data) values (:lid, :key, :data)");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_ACTIVE);
    query.bindValue(":data", false);
    query.exec();

    query.prepare("update notetable set dateDeleted=strftime('%s','now') where lid=:lid");
    query.bindValue(":lid", lid);
    query.exec();

    if (isDirty) {
        query.prepare("Insert into DataStore (lid, key, data) values (:lid, :key, :data)");
        query.bindValue(":lid", lid);
        query.bindValue(":key", NOTE_ISDIRTY);
        query.bindValue(":data", true);
        query.exec();

    }
    query.finish();
    db->unlock();
}


void NoteTable::deleteNotes(const QList<qint32> &noteLids, bool isDirty=true) {
    QString slids = joinLids(noteLids);
    if (slids == "") {
        return;
    }

    NSqlQuery query(db);
    db->lockForWrite();

    query.prepare("delete from DataStore where key=:key and lid in (" +
            slids + ")");
    bindLids(query, noteLids);
    query.bindValue(":key", NOTE_ACTIVE);
    query.exec();

    query.prepare("delete from DataStore where key=:key and lid in (" +
            slids + ")");
    bindLids(query, noteLids);
    query.bindValue(":key", NOTE_DELETED_DATE);
    query.exec();

    if (isDirty) {
        query.prepare("delete from DataStore where key=:key and lid in (" + slids + ")");
        bindLids(query, noteLids);
        query.bindValue(":key", NOTE_ISDIRTY);
        query.exec();
    }

    QString values = joinValues(noteLids, NOTE_ACTIVE, false);

    query.prepare("Insert into DataStore (lid, key, data) values " + values);
    bindLids(query, noteLids);
    query.exec();

    query.prepare("update notetable set dateDeleted=strftime('%s','now') where lid in (" + slids + ")");
    bindLids(query, noteLids);
    query.exec();

    if (isDirty) {
        values = joinValues(noteLids, NOTE_ISDIRTY, true);
        query.prepare("Insert into DataStore (lid, key, data) values " + values);
        bindLids(query, noteLids);
        query.exec();
    }

    query.finish();
    db->unlock();
}


void NoteTable::restoreNote(qint32 lid, bool isDirty=true) {
    QList<qint32> lids;
    lids.clear();
    lids.append(lid);
    restoreNotes(lids, isDirty);
}


void NoteTable::restoreNotes(const QList<qint32> &lids, bool isDirty=true) {
    QString slids = joinLids(lids);
    if (slids == "") {
        return;
    }

    NSqlQuery query(db);
    db->lockForWrite();

    query.prepare("Update DataStore set data=:data where key=:key and lid in (" + slids + ")");
    query.bindValue(":data", true);
    query.bindValue(":key", NOTE_ACTIVE);
    bindLids(query, lids);
    query.exec();

    query.prepare("delete from DataStore where key=:key and lid in (" +
            slids + ")");
    query.bindValue(":key", NOTE_DELETED_DATE);
    bindLids(query, lids);
    query.exec();

    if (isDirty) {
        query.prepare("Update DataStore set data=:data where key=:key and lid in (" + slids + ")");
        query.bindValue(":key", NOTE_ISDIRTY);
        query.bindValue(":data", true);
        bindLids(query, lids);
        query.exec();
    }

    query.prepare("Update notetable set dateDeleted=0 where lid in (" +
            slids + ")");
    bindLids(query, lids);
    query.exec();

    query.prepare("Delete from filter where lid in (" + slids + ")");
    bindLids(query, lids);
    query.exec();

    query.finish();
    db->unlock();
}


qint32 NoteTable::getAllDeleted(QList<qint32> &lids) {
    db->lockForRead();
    lids.clear();
    NSqlQuery query(db);
    query.prepare("select lid from DataStore where key=:key and data=0");
    query.bindValue(":key", NOTE_ACTIVE);
    query.exec();

    while (query.next()) {
        lids.append(query.value(0).toInt());
    }
    query.finish();
    db->unlock();
    return lids.size();
}



void NoteTable::expunge(qint32 lid) {
    QList<qint32> lids;
    lids.clear();
    lids.append(lid);
    expunge(lids);
}


void NoteTable::expunge(string guid) {
    int lid = this->getLid(guid);
    this->expunge(lid);
}


void NoteTable::expunge(QString guid) {
    int lid = this->getLid(guid);
    this->expunge(lid);
}


void NoteTable::expunge(const QList<qint32> &lids) {
    QString slids = joinLids(lids);
    if (slids == "") {
        return;
    }

    for (int i = 0; i < lids.size(); ++i) {
        // Expunge the thumbnail
        QString thumbnail = global.fileManager.getThumbnailDirPath() +
            QString::number(lids[i]) + ".png";
        QFile f(thumbnail);
        if (f.exists()) {
            QDir d;
            d.remove(thumbnail);
        }

        Note note;
        this->get(note, lids[i], true, false);
        ResourceTable resTable(db);
        QList<Resource> resources;
        if (note.resources.isSet())
            resources = note.resources;

        QList<qint32> resourceGuids;
        resourceGuids.clear();
        for (int i=0; i<resources.size(); i++) {
            resourceGuids.append(resources[i].guid.ref().toInt());
        }
        resTable.expunge(resourceGuids);
    }

    NSqlQuery query(db);
    db->lockForWrite();

    query.prepare("delete from DataStore where lid in (" + slids + ")");
    bindLids(query, lids);
    query.exec();

    query.prepare("delete from NoteTable where lid in (" + slids + ")");
    bindLids(query, lids);
    query.exec();

    query.finish();
    db->unlock();
}


// Add to the deletion queue
void NoteTable::addToDeleteQueue(qint32 lid, Note n) {
    get(n,lid,true,true);
    NSqlQuery query(db);
    db->lockForWrite();

    query.prepare("insert into datastore (lid,key,data) values (:lid, :key, :data)");

    QString guid = n.guid;
    QString notebookGuid = n.notebookGuid;

    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_DELETE_PENDING_GUID);
    query.bindValue(":data" , guid);
    query.exec();

    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_DELETE_PENDING_NOTEBOOK);
    query.bindValue(":data" , notebookGuid);
    query.exec();

    db->unlock();
}



// Get every pending delete
void NoteTable::getAllDeleteQueue(QStringList &guids, QString notebookGuid) {
    NSqlQuery query(db);

    guids.clear();
    db->lockForRead();
    if (notebookGuid == "") {
        query.prepare("Select data from datastore where key=:key");
        query.bindValue(":key", NOTE_DELETE_PENDING_GUID);
    } else {
        query.prepare("Select data from datastore where key=:key and data=:notebookGuid");
        query.bindValue(":key", NOTE_DELETE_PENDING_GUID);
        query.bindValue(":data", notebookGuid);
    }
    query.exec();
    while(query.next()) {
        guids.append(query.value(0).toString());
    }
    db->unlock();
}



// Expunge from the deletion queue
void NoteTable::expungeFromDeleteQueue(qint32 lid) {
    NSqlQuery query(db);

    db->lockForWrite();
    query.prepare("delete from datastore where lid=:lid");
    query.bindValue(":lid", lid);
    query.exec();
    db->unlock();
}


// Expunge from the deletion queue
void NoteTable::expungeFromDeleteQueue(QString guid) {
    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("Select lid from datastore where key=:key and data=:data");
    query.bindValue(":key", NOTE_DELETE_PENDING_GUID);
    query.bindValue(":data", guid);
    query.exec();
    db->unlock();
    while(query.next()) {
        expungeFromDeleteQueue(query.value(0).toInt());
    }
}




// Find all notes belonging to a particular notebook.
qint32 NoteTable::findNotesByNotebook(QList<qint32> &notes, QString guid) {
    NSqlQuery query(db);
    qint32 notebookLid;
    NotebookTable notebookTable(db);
    notebookLid = notebookTable.getLid(guid);
    return findNotesByNotebook(notes, notebookLid);
}




// Find all notes belonging to a particular notebook.
qint32 NoteTable::findNotesByNotebook(QList<qint32> &notes, qint32 lid) {
    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("Select lid from DataStore where key=:key and data=:notebookLid");
    query.bindValue(":notebookLid", lid);
    query.bindValue(":key", NOTE_NOTEBOOK_LID);
    query.exec();
    while (query.next()) {
        notes.append(query.value(0).toInt());
    }
    query.finish();
    db->unlock();
    return notes.size();
}


qint32 NoteTable::findNotesByNotebook(QList<qint32> &notes, string guid) {
    return findNotesByNotebook(notes, QString::fromStdString(guid));
}


void NoteTable::updateNoteContent(qint32 lid, QString content, bool isDirty) {
    db->lockForWrite();

    NSqlQuery query(db);

    query.prepare("update datastore set data=:content where lid=:lid and key=:key");
    query.bindValue(":content", content);
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_CONTENT);
    query.exec();

    // Delete values from the table of datastore, to prepare to insert later.
    query.prepare("Delete from datastore where lid=:lid and \
            (key=:content_length or key=:has_todo_completed or \
            key=:has_todo_uncompleted or key=:has_encrypt or \
            key=:note_index_needed)");
    query.bindValue(":lid", lid);
    query.bindValue(":content_length", NOTE_CONTENT_LENGTH);
    query.bindValue(":has_todo_completed", NOTE_HAS_TODO_COMPLETED);
    query.bindValue(":has_todo_uncompleted", NOTE_HAS_TODO_UNCOMPLETED);
    query.bindValue(":has_encrypt", NOTE_HAS_ENCRYPT);
    query.bindValue(":note_index_needed", NOTE_INDEX_NEEDED);
    query.exec();

    // Insert values into the table of datastore.
    QString sql = "Insert into datastore (lid, key, data) values ";
    // 'values' is the value part in string in the sql statement.
    QString values = "(:lid, :key_content_length, :value_content_length),";

    // 'valueList' contains all the real parameters of
    // the sql statement, including the keys used in
    // DataStore and values correspoding to them.
    QList<QVariant> valueList;
    valueList.clear();

    if (content.contains("<en-todo")) {
        QLOG_DEBUG() << content;
        // If we have a todo that is checked, then it is completed.
        if (content.contains("<en-todo checked=\"true\"")) {
            values += "(:lid, :key_has_todo_completed, :value_has_todo_completed),";
            valueList.append(NOTE_HAS_TODO_COMPLETED);
            valueList.append(true);
        }

        // If we have a todo that is not checked, but still have a todo, then it must be uncoompleted.
        if (content.contains("<en-todo checked=\"false\"") || content.contains("<en-todo/>")) {
            values += "(:lid, :key_has_todo_uncompleted, :value_has_todo_uncompleted),";
            valueList.append(NOTE_HAS_TODO_UNCOMPLETED);
            valueList.append(true);
        }
    }

    if (content.contains("<en-crypt")) {
        values += "(:lid, :key_has_encrypt, :value_has_encrypt),";
        valueList.append(NOTE_HAS_ENCRYPT);
        valueList.append(true);
    }

    if (global.enableIndexing) {
        values += "(:lid, :key_note_index_needed, :value_note_index_needed),";
        valueList.append(NOTE_INDEX_NEEDED);
        valueList.append(true);
    } else {
        NoteIndexer indexer(db);
        indexer.indexNote(lid);
    }

    values.chop(1);
    sql += values;
    query.prepare(sql);
    query.bindValue(":lid", lid);
    query.bindValue(":key_content_length", NOTE_CONTENT_LENGTH);
    query.bindValue(":value_content_length", content.length());
    for (int i = 0, j = 0; i < valueList.size(); i += 2, j += 1) {
        // Bind the DataStore key with a real parameter.
        query.bindValue(3 + j*3 + 1, valueList[i]);
        // Bind the DataStore value with a real parameter.
        query.bindValue(3 + j*3 + 2, valueList[i+1]);
    }
    query.exec();

    // Update the table of NoteTable.
    sql = QString("Update NoteTable set hasTodo=:has_todo, ") +
        QString("hasEncryption=:has_encryption, ") +
        QString("size=:size where lid=:lid;");
    query.prepare(sql);
    query.bindValue(":lid", lid);
    query.bindValue(":has_todo", content.contains("<en-todo"));
    query.bindValue(":has_encryption", content.contains("<en-crypt"));
    qlonglong totalsize = this->getSize(lid);
    query.bindValue(":size", totalsize);
    query.exec();

    query.finish();
    db->unlock();

    setDirty(lid, isDirty);
}



qint32 NoteTable::findNotesByTitle(QList<qint32> &lids, QString title) {
    NSqlQuery query(db);
    lids.clear();

    db->lockForRead();
    query.prepare("select lid from notetable where title like :title order by datecreated;");
    query.bindValue(":title", title);
    query.exec();

    while (query.next()) {
        lids.append(query.value(0).toInt());
    }
    query.finish();
    db->unlock();
    return lids.size();
}


qint32 NoteTable::getCount() {
    qint32 retval = 0;
    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("Select count(lid) from DataStore where key=:key and lid not in (select lid from datastore where key=:key2 and data = 1)");
    query.bindValue(":key", NOTE_GUID);
    query.bindValue(":key2", NOTE_EXPUNGED_FROM_TRASH);
    query.exec();
    if (query.next())
        retval =  query.value(0).toInt();
    query.finish();
    db->unlock();
    return retval;

}



qint32 NoteTable::getUnindexedCount() {
    qint32 retval = 0;
    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("Select count(lid) from DataStore where key=:key and data=1 and lid not in (select lid from datastore where key=:key2 and data = 1)");
    query.bindValue(":key", NOTE_INDEX_NEEDED);
    query.bindValue(":key2", NOTE_EXPUNGED_FROM_TRASH);
    query.exec();
    if (query.next())
        retval = query.value(0).toInt();
    query.finish();
    db->unlock();
    return retval;
}



qint32 NoteTable::duplicateNote(qint32 oldLid, bool keepCreatedDate) {
    if (oldLid <=0)
        return -1;

    ConfigStore cs(db);
    qint32 newLid = cs.incrementLidCounter();
    db->lockForWrite();

    NSqlQuery query(db);
    query.prepare("insert into datastore (lid, key, data) select :newLid, key, data from datastore where lid=:oldLid");
    query.bindValue(":newLid", newLid);
    query.bindValue(":oldLid", oldLid);
    query.exec();

    query.prepare("update datastore set data=:data where lid=:lid and key=:key");
    query.bindValue(":data", QString::number(newLid));
    query.bindValue(":lid", newLid);
    query.bindValue(":key", NOTE_GUID);
    query.exec();

    // experimental: mark copy as "- copy" in title
    query.prepare("update datastore set data=data || ' - copy' where lid=:lid and key=:key");
    query.bindValue(":lid", newLid);
    query.bindValue(":key", NOTE_TITLE);
    query.exec();

    query.prepare("update datastore set data=:data where lid=:lid and key=:key");
    query.bindValue(":data", 0);
    query.bindValue(":lid", newLid);
    query.bindValue(":key", NOTE_UPDATE_SEQUENCE_NUMBER);
    query.exec();

    Note n;
    get(n, newLid, false, false);
    NotebookTable notebookTable(db);
    qint32 notebookLid = notebookTable.getLid(n.notebookGuid);
    updateNoteList(newLid, n, true, notebookLid);

    setDirty(newLid, true);
    setIndexNeeded(newLid, true);

    if (!keepCreatedDate) {
        qint64 dt = QDateTime::currentMSecsSinceEpoch();
        this->updateDate(newLid, dt, NOTE_CREATED_DATE, true);
    }

    // Update all the resources
    ResourceTable resTable(db);
    QList<qint32> lids;
    resTable.getResourceList(lids, oldLid);
    for (int i=0; i<lids.size(); i++) {
        qint32 newResLid = cs.incrementLidCounter();

        query.prepare("insert into datastore (lid, key,data) select :newLid, key, data from datastore where lid=:oldLid");
        query.bindValue(":newLid", newResLid);
        query.bindValue(":oldLid", lids[i]);
        query.exec();

        query.prepare("update datastore set data=:data where lid=:lid and key=:key");
        query.bindValue(":data", QString::number(newResLid));
        query.bindValue(":lid", newResLid);
        query.bindValue(":key", RESOURCE_GUID);
        query.exec();

        query.prepare("update datastore set data=:data where lid=:lid and key=:key");
        query.bindValue(":data", 0);
        query.bindValue(":lid", newResLid);
        query.bindValue(":key", RESOURCE_UPDATE_SEQUENCE_NUMBER);
        query.exec();

        query.prepare("update datastore set data=:data where lid=:lid and key=:key");
        query.bindValue(":data", newLid);
        query.bindValue(":lid", newResLid);
        query.bindValue(":key", RESOURCE_NOTE_LID);
        query.exec();

        QStringList filter;
        QDir resDir(global.fileManager.getDbaDirPath());
        filter << QString::number(lids[i])+".*";
        QStringList files = resDir.entryList(filter);
        for (int j=0; j<files.size(); j++) {
            QFile file(global.fileManager.getDbaDirPath()+files[j]);
            int pos = files[j].indexOf(".");
            QString type = files[j].mid(pos);
            file.open(QIODevice::ReadOnly);
            file.copy(global.fileManager.getDbaDirPath()+
                      QString::number(newResLid) +type);
            file.close();
        }
    }
    query.finish();
    db->unlock();
    return newLid;
}






// Get all dirty lids
qint32 NoteTable::getAllDirty(QList<qint32> &lids) {
    NSqlQuery query(db);
    db->lockForRead();
    lids.clear();
    query.prepare("Select lid from DataStore where key=:key and data = 1");
    query.bindValue(":key", NOTE_ISDIRTY);
    query.exec();
    while(query.next()) {
        lids.append(query.value(0).toInt());
    }
    query.finish();
    db->unlock();
    return lids.size();
}



// Get all dirty lids
qint32 NoteTable::getAllDirty(QList<qint32> &lids, qint32 linkedNotebookLid) {
    NSqlQuery query(db);
    lids.clear();
    db->lockForRead();
    query.prepare("Select lid from DataStore where key=:key and data = 1 and lid in (select lid from datastore where key=:notebookKey and data=:notebookLid)");
    query.bindValue(":key", NOTE_ISDIRTY);
    query.bindValue(":notebookKey", NOTE_NOTEBOOK_LID);
    query.bindValue(":notebookLid", linkedNotebookLid);
    query.exec();
    while(query.next()) {
        lids.append(query.value(0).toInt());
    }
    query.finish();
    db->unlock();
    return lids.size();
}







// Get the notebook lid for a note
qint32 NoteTable::getNotebookLid(qint32 noteLid) {
    qint32 retval = 0;
    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("Select data from DataStore where key=:key and lid=:lid");
    query.bindValue(":key", NOTE_NOTEBOOK_LID);
    query.bindValue(":lid", noteLid);
    query.exec();
    if (query.next()) {
        retval = query.value(0).toInt();
    }
    query.finish();
    db->unlock();
    return retval;
}




// Update the USN
void NoteTable::setUpdateSequenceNumber(qint32 lid, qint32 usn) {
    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("Update DataStore set data=:data where key=:key and lid=:lid");
    query.bindValue(":data", usn);
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_UPDATE_SEQUENCE_NUMBER);
    query.exec();
    query.finish();
    db->unlock();
}



void NoteTable::updateEnmediaHash(qint32 lid, QByteArray oldHash, QByteArray newHash, bool isDirty) {
    QString content;
    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("Select data from datastore where lid=:lid and key=:key");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_CONTENT);
    query.exec();
    if (query.next()) {
        content = query.value(0).toString();

        // Start going through & looking for the old hash
        int pos = content.indexOf("<en-note");
        int endPos;
        int hashPos = -1;
        QString hashString = "hash=\"" +oldHash.toHex() +"\"";
        while (pos != -1) {
            endPos = content.indexOf(">", pos);  // Find the matching end of the tag
            hashPos = content.indexOf(hashString, pos);
            if (hashPos < endPos && hashPos != -1) {  // If we found the hash, begin the update
                QString startString = content.mid(0, hashPos);
                QString endString = content.mid(hashPos+hashString.length());
                QString newContent = startString + "hash=\"" +newHash.toHex() +"\"" +endString;
                updateNoteContent(lid, newContent, isDirty);
                pos = -1;
            } else {
                pos = content.indexOf("<", pos+1);
            }
        }
    }
    query.finish();
    db->unlock();
}



void NoteTable::setThumbnail(qint32 lid, QString filename) {
    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("Update notetable set thumbnail=:thumbnail where lid=:lid");
    query.bindValue(":thumbnail", filename);
    query.bindValue(":lid", lid);
    query.exec();
    query.prepare("Delete from datastore where lid=:lid and key=:key");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_THUMBNAIL_NEEDED);
    query.exec();
    query.finish();
    db->unlock();
}


void NoteTable::reindexAllNotes() {
    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("delete from datastore where key=:indexKey");
    query.bindValue(":indexKey", NOTE_INDEX_NEEDED);
    query.exec();

    query.prepare("insert into datastore (lid, key, data) select lid, :indexKey, 1 from datastore where key=:key;");
    query.bindValue(":indexKey", NOTE_INDEX_NEEDED);
    query.bindValue(":key", NOTE_GUID);
    query.exec();
    query.finish();
    db->unlock();
}


void NoteTable::resetGeography(qint32 lid, bool isDirty) {
    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("delete from datastore where lid=:lid and key=:key");

    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_ATTRIBUTE_LONGITUDE);
    query.exec();

    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_ATTRIBUTE_LATITUDE);
    query.exec();

    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_ATTRIBUTE_ALTITUDE);
    query.exec();
    query.finish();
    db->unlock();

    if (isDirty)
        this->setDirty(lid, isDirty);
}




void NoteTable::setGeography(qint32 lid, double longitude, double latitude, double altitude, bool isDirty) {
    this->resetGeography(lid, isDirty);

    db->lockForWrite();
    NSqlQuery query(db);
    query.prepare("insert into datastore (lid,key,data) values(:lid, :key, :data)");

    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_ATTRIBUTE_LONGITUDE);
    query.bindValue(":data", longitude);
    query.exec();

    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_ATTRIBUTE_LATITUDE);
    query.bindValue(":data", latitude);
    query.exec();

    if (altitude>0.0) {
        query.bindValue(":lid", lid);
        query.bindValue(":key", NOTE_ATTRIBUTE_ALTITUDE);
        query.bindValue(":data", altitude);
        query.exec();
    }
    query.finish();
    db->unlock();

    if (isDirty)
        this->setDirty(lid, isDirty);
}



void NoteTable::setThumbnailNeeded(qint32 lid, bool value) {
    if (lid >=0)
        return;

    // If it is already set to this value, then we don't need to
    // do anything.
    if (isThumbnailNeeded(lid) == value)
        return;

    db->lockForWrite();
    NSqlQuery query(db);
    query.prepare("Delete from DataStore where lid=:lid and key=:key");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_THUMBNAIL_NEEDED);
    query.exec();

    if (value) {
        query.prepare("Insert into DataStore (lid, key, data) values (:lid, :key, :data)");
        query.bindValue(":lid", lid);
        query.bindValue(":key", NOTE_THUMBNAIL_NEEDED);
        query.bindValue(":data", value);
        query.exec();
    }
    query.finish();
    db->unlock();
}



void NoteTable::setThumbnailNeeded(QString guid, bool value) {
    qint32 lid = getLid(guid);
    setThumbnailNeeded(lid, value);
}

void NoteTable::setThumbnailNeeded(string guid, bool value) {
    qint32 lid = getLid(guid);
    setThumbnailNeeded(lid, value);
}

bool NoteTable::isThumbnailNeeded(qint32 lid) {
    bool retval = false;
    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("select data from DataStore where lid=:lid and key=:key");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_THUMBNAIL_NEEDED);
    query.exec();
    if (query.next()) {
        retval = query.value(0).toBool();
    }
    query.finish();
    db->unlock();
    return retval;
}

bool NoteTable::isThumbnailNeeded(QString guid) {
    qint32 lid = getLid(guid);
    return isThumbnailNeeded(lid);
}

bool NoteTable::isThumbnailNeeded(string guid) {
    qint32 lid = getLid(guid);
    return isThumbnailNeeded(lid);
}

qint32 NoteTable::getNextThumbnailNeeded() {
    qint32 retval = -1;
    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("select lid from datastore where data=1 and key=:key limit 1;");
    query.bindValue(":key", NOTE_THUMBNAIL_NEEDED);
    query.exec();
    if (query.next()) {
        retval = query.value(0).toInt();
    }
    query.finish();
    db->unlock();
    return retval;
}



qint32 NoteTable::getThumbnailsNeededCount() {
    //qint32 retval = 0;
    //NSqlQuery query(db);
    //db->lockForRead();
    //query.prepare("select count(lid)from datastore where data=1 and key=:key;");
    //query.bindValue(":key", NOTE_THUMBNAIL_NEEDED);
    //query.exec();
    //if (query.next()) {
    //    retval = query.value(0).toInt();
    //}
    //query.finish();
    //db->unlock();
    //return retval;

    QDir pwd = QDir::current();
    pwd.cd(QDir::toNativeSeparators(global.fileManager.getThumbnailDirPath()));
    qint32 count =  getCount() - pwd.entryList(QDir::Files).count();

    return count;
}



bool NoteTable::thumbnailExists(qint32 lid) {
    QFile f;
    f.setFileName(
            QDir::toNativeSeparators(global.fileManager.getThumbnailDirPath()) +
            QString::number(lid) + ".png");
    return f.exists();
}

void NoteTable::setReminderCompleted(qint32 lid, bool completed) {
    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("Delete from DataStore where lid=:lid and key=:key");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_ATTRIBUTE_REMINDER_DONE_TIME);
    query.exec();

    if (completed) {
        QDateTime dt = QDateTime::currentDateTime();
        query.prepare("Insert into DataStore (lid, key, data) values (:lid, :key, :dt)");
        query.bindValue(":lid", lid);
        query.bindValue(":key", NOTE_ATTRIBUTE_REMINDER_DONE_TIME);
        query.bindValue(":dt", dt.toMSecsSinceEpoch());
        query.exec();

        query.prepare("Update NoteTable set reminderDoneTime=:dt where lid=:lid");
        query.bindValue(":dt", dt.toMSecsSinceEpoch());
        query.bindValue(":lid", lid);
        query.exec();
    }
    query.finish();
    db->unlock();
}



void NoteTable::removeReminder(qint32 lid) {
    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("Delete from DataStore where lid=:lid and key=:key");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_ATTRIBUTE_REMINDER_DONE_TIME);
    query.exec();

    query.prepare("Delete from DataStore where lid=:lid and key=:key");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_ATTRIBUTE_REMINDER_ORDER);
    query.exec();


    query.prepare("Delete from DataStore where lid=:lid and key=:key");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_ATTRIBUTE_REMINDER_TIME);
    query.exec();

    query.prepare("Update NoteTable set reminderTime=0 where lid=:lid");
    query.bindValue(":lid", lid);
    query.exec();
    query.finish();

    query.prepare("Update NoteTable set reminderDoneTime=0 where lid=:lid");
    query.bindValue(":lid", lid);
    query.exec();
    query.finish();

    db->unlock();
}


void NoteTable::getAllReminders(QList< QPair<qint32,qlonglong>* > *reminders) {
    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("select lid,data from datastore where  key=:key1 and lid not in (select lid from datastore where key=:key2)");
    query.bindValue(":key1", NOTE_ATTRIBUTE_REMINDER_TIME);
    query.bindValue(":key2", NOTE_ATTRIBUTE_REMINDER_DONE_TIME);
    query.exec();
    while (query.next()) {
        qint32 lid = query.value(0).toInt();
        qlonglong dt = query.value(1).toLongLong();
        QPair<qint32, qlonglong> *p = new QPair<qint32, qlonglong>();
        p->first = lid;
        p->second = dt;
        reminders->append(p);
    }
    query.finish();
    db->unlock();
}


// Return if a note is dirty given its lid
bool NoteTable::isPinned(qint32 lid) {
    bool retval = false;
    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("Select data from DataStore where key=:key and lid=:lid");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_ISPINNED);
    query.exec();
    if (query.next())
        retval =  query.value(0).toBool();
    query.finish();
    db->unlock();
    return retval;
}


// Determine if a note is pinned given a guid
bool NoteTable::isPinned(QString guid) {
    qint32 lid = getLid(guid);
    return isPinned(lid);
}


// Determine if a note is pinned a guid
bool NoteTable::isPinned(string guid) {
    QString g(QString::fromStdString(guid));
    return isPinned(g);
}


// Return if a note is dirty given its lid
void NoteTable::pinNote(qint32 lid, bool value) {
    if (value && isPinned(lid))
        return;

    NSqlQuery query(db);
    db->lockForWrite();
    query.prepare("Delete from DataStore where key=:key and lid=:lid");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_ISPINNED);
    query.exec();

    if (!value) {
        query.prepare("Update NoteTable set isPinned=0 where lid=:lid");
        query.bindValue(":lid", lid);
        query.exec();
        QLOG_DEBUG() << query.lastError();
        query.finish();
        return;
    }

    query.prepare("Insert into DataStore (lid, key, data) values (:lid, :key, 1)");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_ISPINNED);
    query.exec();

    query.prepare("Update NoteTable set isPinned=1 where lid=:lid");
    query.bindValue(":lid", lid);
    query.exec();
    query.lastError();
    query.finish();
    db->unlock();

    //setDirty(lid, true, false);
}


// Determine if a note is pinned given a guid
void NoteTable::pinNote(QString guid, bool value) {
    qint32 lid = getLid(guid);
    pinNote(lid, value);
}


// Determine if a note is pinned a guid
void NoteTable::pinNote(string guid, bool value) {
    QString g(QString::fromStdString(guid));
    pinNote(g, value);
}


void NoteTable::getAllPinned(QList< QPair< qint32, QString > > &lids) {
    NSqlQuery query(db);
    lids.clear();
    db->lockForRead();
    query.prepare("Select lid, data from DataStore where key=:titlekey and lid in (select lid from datastore where key=:key and data=1) order by data");
    query.bindValue(":titlekey", NOTE_TITLE);
    query.bindValue(":key", NOTE_ISPINNED);
    query.exec();
    while (query.next()) {
        QPair<qint32, QString> pair;
        pair.first = query.value(0).toInt();
        pair.second = query.value(1).toString();
        lids.append(pair);
    }
    query.finish();
    db->unlock();
    return;
}


void NoteTable::getRecentlyUpdated(QList< QPair< qint32, QString > > &lids) {
    NSqlQuery query(db);
    lids.clear();
    db->lockForRead();
    query.prepare("select lid, title from notetable order by dateupdated desc limit 10");
    query.exec();
    while (query.next()) {
        QPair<qint32, QString> pair;
        pair.first = query.value(0).toInt();
        pair.second = query.value(1).toString();
        lids.append(pair);
    }
    query.finish();
    db->unlock();
    return;
}





// Get all lids
void NoteTable::getAll(QList<qint32> &lids) {
    NSqlQuery query(db);
    lids.empty();
    db->lockForRead();
    query.prepare("Select lid from DataStore where key=:guid");
    query.bindValue(":guid", NOTE_GUID);
    query.exec();
    while(query.next()) {
        lids.append(query.value(0).toInt());

    }
    query.finish();
    db->unlock();
}



// Get all lids
void NoteTable::setTitleColor(qint32 lid, QString color) {
    NSqlQuery query(db);
    QString c = color;
    if (c == "white")
        c = "";
    db->lockForWrite();
    query.prepare("Update NoteTable set titleColor=:color where lid=:lid");
    query.bindValue(":color", c);
    query.bindValue(":lid", lid);
    query.exec();

    query.prepare("Delete from DataStore where key=:key and lid=:lid");
    query.bindValue(":key", NOTE_TITLE_COLOR);
    query.bindValue(":lid", lid);
    query.exec();

    if (c == "")
        return;
    query.prepare("Insert into DataStore (lid, key, data) values (:lid, :key, :value)");
    query.bindValue(":lid", lid);
    query.bindValue(":key", NOTE_TITLE_COLOR);
    query.bindValue(":value", c);
    query.exec();
    query.finish();
    db->unlock();
}


qlonglong NoteTable::getSize(qint32 lid) {
    NSqlQuery query(db);
    db->lockForRead();
    query.prepare("select data from datastore where key=:key and lid=:lid");
    query.bindValue(":key", NOTE_CONTENT_LENGTH);
    query.bindValue(":lid", lid);
    query.exec();
    qlonglong returnValue = 0;
    if (query.next()) {
        returnValue = query.value(0).toLongLong();
    }
    query.prepare("Select sum(data) from DataStore where key=:key and lid in (select lid from datastore where key=:key2 and data=:lid)");
    query.bindValue(":key", RESOURCE_DATA_SIZE);
    query.bindValue(":key2", RESOURCE_NOTE_LID);
    query.bindValue(":data", lid);
    query.exec();
    while (query.next()) {
        returnValue = returnValue+query.value(0).toLongLong();
    }
    return returnValue;
}


QString NoteTable::joinLids(const QList<qint32> &noteLids) {
    QString lids = "";

    for (int i = 0; i < noteLids.size(); ++i) {
        if (noteLids[i] > 0) {
            lids += ":lid" + QString::number(i) + ",";
        }
    }
    if (lids != "") {
        lids.chop(1); // chop the trailing ','
    }

    return lids;
}



QString NoteTable::joinValues(const QList<qint32> &noteLids,
        int key, const QVariant &value, int lidSeqNum/* =-1 */) {
    QString values = "";
    for (int i = 0; i < noteLids.size(); ++i) {
        if (noteLids[i] <= 0) {
            continue;
        }
        if (lidSeqNum == -1) {
            values += "(:lid" + QString::number(i) + "," +
                QString::number(key) + ",";
        } else {
            values += "(:lid" + QString::number(lidSeqNum) + "," +
                QString::number(key) + ",";
        }

        if (value.type() == QVariant::Bool ||
                value.type() == QVariant::Int) {
            values += QString::number(value.toInt()) + "),";
        } else if (value.type() == QVariant::LongLong) {
            values += QString::number(value.toLongLong()) + "),";
        } else {
            values += value.toString() + "),";
        }
    }

    if (values != "") {
        values.chop(1); // chop the trailing ','
    }

    return values;
}



void NoteTable::bindLids(NSqlQuery &sql, const QList<qint32> &noteLids) {
    for (int i = 0; i < noteLids.size(); ++i) {
        if (noteLids[i] > 0) {
            sql.bindValue(":lid" + QString::number(i),
                    noteLids[i]);
        }
    }
}
