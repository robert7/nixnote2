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

#include <QTimer>

#include "syncrunner.h"
#include "src/global.h"
#include "src/sql/databaseconnection.h"
#include "src/sql/usertable.h"
#include "src/sql/tagtable.h"
#include "src/sql/searchtable.h"
#include "src/sql/notebooktable.h"
#include "src/sql/notetable.h"
#include "src/sql/linkednotebooktable.h"
#include "src/sql/resourcetable.h"
#include "src/sql/sharednotebooktable.h"
#include "src/nixnote.h"
#include "src/communication/communicationmanager.h"
#include "src/communication/communicationerror.h"
#include "src/sql/nsqlquery.h"

extern Global global;

SyncRunner::SyncRunner() {
    initialized = false;
    finalSync = false;
    apiRateLimitExceeded = false;
    minutesToNextSync = 0;
    error = false;
    updateUserDataOnNextSync = false;
    connectionClosed = false;
}

SyncRunner::~SyncRunner() {
}


void SyncRunner::synchronize() {
    QLOG_DEBUG() << "synchronize";

    if (!initialized) {
        this->setObjectName("SyncRunnerThread");
        initialized = true;
        consumerKey = "";
        secret = "";
        apiRateLimitExceeded = false;
        connectionClosed = false;

        // Setup the user agent
        userAgent = NN_APP_CLIENT_NAME;

        userStoreUrl = QString("http://" + global.server + "/edam/user").toStdString();
        updateSequenceNumber = 0;

        defaultMsgTimeout = 150000;
        db = new DatabaseConnection("syncrunner");
        comm = new CommunicationManager(db);
        if (global.guiAvailable) {
            connect(global.application, SIGNAL(stdException(QString)), this, SLOT(applicationException(QString)));
        }
    }

    // If we are already connected, we are already synchronizing so there is nothing more to do
    if (global.connected) {
        QLOG_DEBUG() << "synchronize: sync seems to be already running (or stuck someway)";
        return;
    }

    error = false;
    comm->resetError();

    if (!comm->enConnect()) {
        QLOG_DEBUG() << "synchronize: connect failed";
        this->communicationErrorHandler();
        error = true;
        emit syncComplete();
        return;
    }
    QLOG_DEBUG() << "synchronize: connect OK";

    global.connected = true;
    keepRunning = true;
    evernoteSync();
    emit syncComplete();
    comm->enDisconnect();
    global.connected = false;
}

void SyncRunner::requestAndStoreUserData() {
    UserTable userTable(db);
    QLOG_INFO() << "Requesting user data UserStore.getInfo";
    User user;
    if (!comm->getUserInfo(user)) { // get user info BEFORE SYNC
        this->communicationErrorHandler();
        error = true;
        return;
    }
    QLOG_INFO() << "About to store user data";
    userTable.updateUser(user); // update user info in DB
    QLOG_INFO() << "User data updated";
}

void SyncRunner::evernoteSync() {
    QLOG_TRACE() << "Sync thread:" << QThread::currentThreadId();
    if (!global.connected) {
        QLOG_DEBUG() << "synchronize: not connected";
        return;
    }

    SyncState syncState;
    if (!comm->getSyncState("", syncState)) {
        this->communicationErrorHandler();
        error = true;
        return;
    }

    fullSync = false;

    UserTable userTable(db);
    qlonglong lastSyncDate = userTable.getLastSyncDate();
    updateSequenceNumber = userTable.getLastSyncNumber();

    if ((syncState.fullSyncBefore / 1000) > lastSyncDate) {
        QLOG_DEBUG() << "Full sequence date has expired";
        lastSyncDate = 0;
        fullSync = true;
    }

    if (updateSequenceNumber == 0) {
        fullSync = true;
    }

    // EXPERIMENTAL disable UserStore.getUser() for incremental sync
    if (fullSync || updateUserDataOnNextSync) {
        this->requestAndStoreUserData();
        updateUserDataOnNextSync = false;
    }



    emit setMessage(tr("Beginning sync"), defaultMsgTimeout);

    // If there are remote changes
    QLOG_DEBUG() << "--->>>  Current Chunk High Sequence Number: " << syncState.updateCount;
    QLOG_DEBUG() << "--->>>  Last User High Sequence Number: " << updateSequenceNumber;

    if (syncState.updateCount > updateSequenceNumber) {
        QLOG_DEBUG() << "Remote changes found. Downloading changes....";
        emit setMessage(tr("Downloading changes.."), 0);
        bool rc = syncRemoteToLocal(syncState.updateCount);
        if (!rc) {
            error = true;
        }
    }

    if (!global.disableUploads && !error) {
        qint32 searchUsn = uploadSavedSearches();
        if (searchUsn > updateSequenceNumber)
            updateSequenceNumber = searchUsn;
        qint32 tagUsn = uploadTags();
        if (tagUsn > updateSequenceNumber)
            updateSequenceNumber = tagUsn;
        qint32 notebookUsn = uploadNotebooks();
        if (notebookUsn > updateSequenceNumber)
            updateSequenceNumber = notebookUsn;
        qint32 personalNotesUsn = uploadPersonalNotes();
        if (personalNotesUsn > updateSequenceNumber)
            updateSequenceNumber = personalNotesUsn;
    }

    // Synchronize linked notebooks
    if (!error && !syncRemoteLinkedNotebooksActual())
        error = true;

    if (error || !comm->getSyncState("", syncState)) {
        error = true;
        this->communicationErrorHandler();
        return;
    }
    userTable.updateSyncState(syncState);

    // Cleanup any missing parent tags
    QList<qint32> lids;
    TagTable tagTable(db);
    tagTable.findMissingParents(lids);
    for (int i = 0; i < lids.size(); i++) {
        if (!finalSync)
            emit(tagExpunged(lids[i]));
    }
    tagTable.cleanupMissingParents();

    if (!error)
        emit setMessage(tr("Sync completed successfully"), defaultMsgTimeout);
    QLOG_TRACE() << "Leaving SyncRunner::evernoteSync()";
}


bool SyncRunner::syncRemoteToLocal(qint32 updateCount) {
    QLOG_TRACE_IN();

    // The sync is run in several parts.
    // Part #1: Get all remote tags, notebooks, & saved searches for
    //          a user's account.  We do this first because we want
    //          the tag & notebook naems for filling out the note table.
    //          It is just easier this way.
    // Part #2: Get all changed notes & resources.  If it is a full sync
    //          then we get the resources & notes together as one entity
    //          (the resource chunk won't have anything).  We also do not
    //          get deleted notes on a full sync.  If it is a partial sync
    //          then we get resources & notes separately (i.e. the notes chunk
    //          may reference a resource guid, but it won't have the detail and
    //          the chunk resources will have valid data.  We get deleted notes
    //          on a partial sync.
    // Part #3: Upload anything local to the user's account.
    // Part #4: Do linked notebook stuff.  Basically the same as
    //          this except we do it across multiple accounts.

    int chunkSize = 5000;
    bool more = true;

    bool rc;
    int startingSequenceNumber = updateSequenceNumber;

    while (more && keepRunning) {
        SyncChunk chunk;
        rc = comm->getSyncChunk(chunk, updateSequenceNumber, chunkSize,
                                SYNC_CHUNK_LINKED_NOTEBOOKS | SYNC_CHUNK_NOTEBOOKS |
                                SYNC_CHUNK_TAGS | SYNC_CHUNK_SEARCHES | SYNC_CHUNK_EXPUNGED,
                                fullSync);
        if (!rc) {
            QLOG_ERROR() << "Error retrieving chunk";
            error = true;
            this->communicationErrorHandler();
            QLOG_TRACE_OUT();
            return false;
        }
        QLOG_DEBUG() << "-(Pass 1)->>>>  Old USN:" << updateSequenceNumber << " New USN:" << chunk.chunkHighUSN;
        int pct = (updateSequenceNumber - startingSequenceNumber) * 100 / (updateCount - startingSequenceNumber);
        emit setMessage(tr("Download ") + QString::number(pct) + tr("% complete for notebooks, tags, & searches."),
                        defaultMsgTimeout);

        processSyncChunk(chunk);

        updateSequenceNumber = chunk.chunkHighUSN;
        if (!chunk.chunkHighUSN.isSet() || chunk.chunkHighUSN >= chunk.updateCount)
            more = false;
    }

    emit setMessage(tr("Download complete for notebooks, tags, & searches.  Downloading notes."), defaultMsgTimeout);

    comm->loadTagGuidMap();
    more = true;
    chunkSize = 50;
    updateSequenceNumber = startingSequenceNumber;
    UserTable userTable(db);


    while (more && keepRunning) {
        SyncChunk chunk;
        rc = comm->getSyncChunk(chunk, updateSequenceNumber, chunkSize, SYNC_CHUNK_NOTES | SYNC_CHUNK_RESOURCES,
                                fullSync);
        if (!rc) {
            QLOG_ERROR() << "Error retrieving chunk";
            error = true;
            this->communicationErrorHandler();
            if (comm->getLastErrorType() == CommunicationError::StdException) {
                emit syncComplete();
            }
            QLOG_TRACE_OUT();
            return false;
        }
        QLOG_DEBUG() << "-(Pass 2) ->>>>  Old USN:" << updateSequenceNumber << " New USN:" << chunk.chunkHighUSN;
        int pct = (updateSequenceNumber - startingSequenceNumber) * 100 / (updateCount - startingSequenceNumber);
        emit setMessage(tr("Download ") + QString::number(pct) + tr("% complete."), defaultMsgTimeout);
        processSyncChunk(chunk);

        userTable.updateLastSyncNumber(chunk.chunkHighUSN);
        userTable.updateLastSyncDate(chunk.currentTime);

        updateSequenceNumber = chunk.chunkHighUSN;
        if (!chunk.chunkHighUSN.isSet() || chunk.chunkHighUSN >= chunk.updateCount) {
            more = false;
            userTable.updateLastSyncNumber(updateCount);
        }
    }

    emit setMessage(tr("Download complete."), defaultMsgTimeout);
    QLOG_TRACE_OUT();
    return true;
}


// Deal with the sync chunk returned
void SyncRunner::processSyncChunk(SyncChunk &chunk, qint32 linkedNotebook) {

    // Now start processing the chunk
    if (chunk.expungedNotes.isSet())
        syncRemoteExpungedNotes(chunk.expungedNotes);

    if (chunk.expungedNotebooks.isSet())
        syncRemoteExpungedNotebooks(chunk.expungedNotebooks);

    if (chunk.expungedSearches.isSet())
        syncRemoteExpungedSavedSearches(chunk.expungedSearches);

    if (chunk.expungedTags.isSet())
        syncRemoteExpungedTags(chunk.expungedTags);

    if (chunk.expungedLinkedNotebooks.isSet())
        syncRemoteExpungedLinkedNotebooks(chunk.expungedLinkedNotebooks);


    if (chunk.notebooks.isSet())
        syncRemoteNotebooks(chunk.notebooks, linkedNotebook);

    if (chunk.tags.isSet())
        syncRemoteTags(chunk.tags, linkedNotebook);

    if (chunk.searches.isSet())
        syncRemoteSearches(chunk.searches);

    if (chunk.linkedNotebooks.isSet())
        syncRemoteLinkedNotebooksChunk(chunk.linkedNotebooks);

    if (chunk.notes.isSet())
        syncRemoteNotes(chunk.notes, linkedNotebook);

    if (chunk.resources.isSet())
        syncRemoteResources(chunk.resources);


    chunk.expungedLinkedNotebooks.clear();;
    chunk.expungedNotebooks.clear();
    chunk.expungedNotes.clear();
    chunk.expungedSearches.clear();
    chunk.expungedTags.clear();
    chunk.notebooks.clear();
    chunk.notes.clear();
    chunk.tags.clear();
    chunk.linkedNotebooks.clear();
    chunk.searches.clear();

    // Save any thumbnails notes
    while (comm->thumbnailList->size() > 0) {
        QPair<QString, QImage *> *pair = comm->thumbnailList->takeFirst();
        NoteTable nTable(db);
        qint32 lid = nTable.getLid(pair->first);
        if (lid > 0) {
            QString filename = global.fileManager.getThumbnailDirPath() + QString::number(lid) + QString(".png");
            pair->second->save(filename, "png");
            nTable.setThumbnail(lid, filename);
        }
        delete pair->second;
        delete pair;
    }

    // Save any ink notes
    while (comm->inkNoteList->size() > 0) {
        QPair<QString, QImage *> *pair = comm->inkNoteList->takeFirst();
        ResourceTable resTable(db);
        qint32 resLid = resTable.getLid(pair->first);
        if (resLid > 0) {
            QString filename = global.fileManager.getDbaDirPath() + QString::number(resLid) + QString(".png");
            pair->second->save(filename);
        }
        delete pair->second;
        delete pair;
    }
}


// Expunge deleted notes from the local database
void SyncRunner::syncRemoteExpungedNotes(QList<Guid> guids) {
    QLOG_TRACE() << "Entering SyncRunner::syncRemoteExpungedNotes";
    NoteTable noteTable(db);
    for (int i = 0; i < guids.size(); i++) {
        noteTable.expunge(guids[i]);
    }
    QLOG_TRACE() << "Leaving SyncRunner::syncRemoteExpungedNotes";
}


// Expunge deleted notebooks from the local database
void SyncRunner::syncRemoteExpungedNotebooks(QList<Guid> guids) {
    QLOG_TRACE() << "Entering SyncRunner::syncRemoteExpungedNotebooks";
    NotebookTable notebookTable(db);
    for (int i = 0; i < guids.size(); i++) {
        int lid = notebookTable.getLid(guids[i]);
        notebookTable.expunge(guids[i]);
        if (!finalSync)
            emit notebookExpunged(lid);
    }
    QLOG_TRACE() << "Leaving SyncRunner::syncRemoteExpungedNotebooks";
}


// Expunge deleted tags from the local database
void SyncRunner::syncRemoteExpungedTags(QList<Guid> guids) {
    QLOG_TRACE() << "Entering SyncRunner::syncRemoteExpungedTags";
    TagTable tagTable(db);
    for (int i = 0; i < guids.size(); i++) {
        int lid = tagTable.getLid(guids[i]);
        tagTable.expunge(guids[i]);
        if (!finalSync)
            emit tagExpunged(lid);
    }
    QLOG_TRACE() << "Leaving SyncRunner::syncRemoteExpungedTags";
}


// Expunge deleted tags from the local database
void SyncRunner::syncRemoteExpungedSavedSearches(QList<Guid> guids) {
    QLOG_TRACE() << "Entering SyncRunner::syncRemoteExpungedSavedSearches";
    SearchTable searchTable(db);
    for (int i = 0; i < guids.size(); i++) {
        int lid = searchTable.getLid(guids[i]);
        searchTable.expunge(guids[i]);
        if (!finalSync)
            emit searchExpunged(lid);
    }
    QLOG_TRACE() << "Leaving SyncRunner::syncRemoteExpungedSavedSearches";
}

// Synchronize remote tags with the current database
// If there is a conflict, the remote wins
void SyncRunner::syncRemoteTags(QList<Tag> tags, qint32 account) {
    QLOG_TRACE() << "Entering SyncRunner::syncRemoteTags";
    TagTable tagTable(db);

    for (int i = 0; i < tags.size() && keepRunning; i++) {
        Tag t = tags.at(i);

        // There are two ways to get the tag.  We can get
        // it by name or by guid.  We check both.  We'll find it by
        // name if a new tag was created locally with the same name
        // as an unsynced remote.  We then merge them.  We'll find it by guid
        // if a note was synchrozied with this tag before a chunk
        // with this tag was downloaded.

        qint32 lid = tagTable.findByName(t.name, account);
        if (lid == 0)
            lid = tagTable.getLid(t.guid);

        if (lid > 0) {
            Tag currentTag;
            tagTable.get(currentTag, lid);
            QString tagname = "";
            if (currentTag.name.isSet())
                tagname = currentTag.name;
            QString tname = "";
            if (t.name.isSet())
                tname = t.name;
            if (tagname != tname)
                changedTags.insert(t.guid, t.name);
            lid = tagTable.sync(lid, t, account);
        } else {
            tagTable.sync(t, account);
            lid = tagTable.getLid(t.guid);
            changedTags.insert(t.guid, t.name);
        }
        QString parentGuid = "";
        if (t.parentGuid.isSet())
            parentGuid = t.parentGuid;
        if (!finalSync) {
            if (t.name.isSet())
                emit tagUpdated(lid, t.name, parentGuid, account);
            else
                emit(tagUpdated(lid, "", parentGuid, account));
        }
    }

    QLOG_TRACE() << "Leaving SyncRunner::syncRemoteTags";
}


// Synchronize remote searches with the current database
// If there is a conflict, the remote wins
void SyncRunner::syncRemoteSearches(QList<SavedSearch> searches) {
    QLOG_TRACE() << "Entering SyncRunner::syncRemoteSearches";
    SearchTable searchTable(db);

    for (int i = 0; i < searches.size() && keepRunning; i++) {
        SavedSearch t = searches.at(i);
        qint32 lid = searchTable.getLid(t.guid);
        if (lid > 0) {
            searchTable.sync(lid, t);
        } else {
            searchTable.sync(t);
            lid = searchTable.getLid(t.guid);
        }
        if (!finalSync) {
            if (t.name.isSet())
                emit searchUpdated(lid, t.name);
            else
                emit searchUpdated(lid, "");
        }
    }

    QLOG_TRACE() << "Leaving SyncRunner::syncRemoteSearches";
}

// Synchronize remote notebooks with the current database
// If there is a conflict, the remote wins
void SyncRunner::syncRemoteNotebooks(QList<Notebook> books, qint32 account) {
    QLOG_TRACE() << "Entering SyncRunner::syncRemoteNotebooks";
    NotebookTable notebookTable(db);
    LinkedNotebookTable ltable(db);
    SharedNotebookTable stable(db);

    for (int i = 0; i < books.size() && keepRunning; i++) {
        Notebook t = books.at(i);

        // There are a few to get the notebook.
        // We can get it by the guid, the share key, the uri, or the name.
        qint32 lid = account;
        if (lid == 0)
            lid = notebookTable.getLid(t.guid);
        if (lid == 0)
            lid = ltable.getLid(t.guid);
        if (lid == 0 && t.sharedNotebooks.isSet()) {
            QList<SharedNotebook> sharedNotebooks = t.sharedNotebooks;
            for (int j = 0; j < sharedNotebooks.size() && lid == 0; j++) {
                lid = stable.findById(sharedNotebooks[j].id);
            }
        }
        Publishing publishing;
        if (t.publishing.isSet())
            publishing = t.publishing;
        if (lid == 0 && publishing.uri.isSet()) {
            lid = notebookTable.findByUri(publishing.uri);
        }
        if (lid == 0)
            lid = notebookTable.findByName(t.name);


        if (lid > 0) {
            notebookTable.sync(lid, t);
        } else {
            lid = notebookTable.sync(t);
        }
        changedNotebooks.insert(t.guid, t.name);
        QString stack = "";
        if (t.stack.isSet())
            stack = t.stack;
        bool shared = false;
        if (t.sharedNotebookIds.isSet() || t.sharedNotebooks.isSet())
            shared = true;
        if (account > 0) {
            LinkedNotebookTable ltb(db);
            LinkedNotebook lbook;
            ltb.get(lbook, account);
            if (lbook.username.isSet())
                stack = QString::fromStdString(username);
        }
        if (!finalSync) {
            if (t.name.isSet())
                emit notebookUpdated(lid, t.name, stack, false, shared);
            else
                emit notebookUpdated(lid, "", stack, false, shared);
        }
    }
    QLOG_TRACE() << "Leaving SyncRunner::syncRemoteNotebooks";
}


// Synchronize remote notes with the current database
void SyncRunner::syncRemoteNotes(QList<Note> notes, qint32 account) {
    QLOG_TRACE() << "Entering SyncRunner::syncRemoteNotes";
    NoteTable noteTable(db);
    NotebookTable bookTable(db);

    for (int i = 0; i < notes.size() && keepRunning; i++) {
        Note t = notes[i];
        qint32 lid = noteTable.getLid(t.guid);
        if (lid > 0) {
            // Find out if it is a conflicting change
            if (noteTable.isDirty(lid)) {
                qint32 newLid = noteTable.duplicateNote(lid);
                qint32 conflictNotebook = bookTable.getConflictNotebook();
                noteTable.updateNotebook(newLid, conflictNotebook, true);
                if (!finalSync)
                    emit noteUpdated(newLid);
            }
            noteTable.sync(lid, notes.at(i), account);
        } else {
            noteTable.sync(t, account);
            lid = noteTable.getLid(t.guid);
        }
        // Remove it from the cache (if it exists)
        if (global.cache.contains(lid)) {
            delete global.cache[lid];
            global.cache.remove(lid);
        }
        if (!finalSync)
            emit noteUpdated(lid);
    }

    QLOG_TRACE() << "Leaving SyncRunner::syncRemoteNotes";
}


// Synchronize remote resources with the current database
void SyncRunner::syncRemoteResources(QList<Resource> resources) {
    QLOG_TRACE() << "Entering SyncRunner::syncRemoteResources";
    ResourceTable resTable(db);

    for (int i = 0; i < resources.size(); i++) {
        Resource r = resources[i];
        qint32 lid = resTable.getLid(r.noteGuid, r.guid);
        if (lid > 0)
            resTable.sync(lid, r);
        else
            resTable.sync(r);
    }
    QLOG_TRACE() << "Leaving SyncRunner::syncRemoteResources";
}


// Synchronize remote linked notebooks
void SyncRunner::syncRemoteLinkedNotebooksChunk(QList<LinkedNotebook> books) {
    QLOG_TRACE_IN();
    LinkedNotebookTable ltable(db);
    for (int i = 0; i < books.size(); i++) {
        qint32 lid = ltable.sync(books[i]);
        LinkedNotebook lbk = books[i];
        QString sharename = "";
        QString username = "";
        if (lbk.shareName.isSet())
            sharename = lbk.shareName;
        if (lbk.username.isSet())
            username = lbk.username;
        if (!finalSync)
            emit notebookUpdated(lid, sharename, username, true, false);
    }
    QLOG_TRACE_OUT();
}


// Synchronize remote linked notebooks
bool SyncRunner::syncRemoteLinkedNotebooksActual() {
    QLOG_TRACE_IN();
    LinkedNotebookTable ltable(db);
    QList<qint32> lids;
    ltable.getAll(lids);
    bool fs;
    for (int i = 0; i < lids.size(); i++) {
        LinkedNotebook book;
        qint32 usn = ltable.getLastUpdateSequenceNumber(lids[i]);
        qint32 startingUSN = usn;
        ltable.get(book, lids[i]);
        int chunkSize = 5000;

        // If the share key is set, we need to authenticate
        if (!comm->authenticateToLinkedNotebookShard(book)) {

            // If we can't authenticate, we just gid of the notebook
            // because the user probably stopped sharing.
            qint32 linkedLid = 0;
            LinkedNotebookTable ntable(db);
            linkedLid = ntable.getLid(book.guid);
            ntable.expunge(book.guid);
            emit notebookExpunged(linkedLid);
            return true;

            //this->communicationErrorHandler();
            //error = true;
            //return false;
        }
        bool more = true;
        SyncState syncState;
        if (!comm->getLinkedNotebookSyncState(syncState, book)) {
            this->communicationErrorHandler();
            error = true;
            return false;
        }
        if (syncState.updateCount <= usn)
            more = false;
        qint32 startingSequenceNumber = usn;
        if (usn == 0)
            fs = true;
        else
            fs = false;


        // ***** STARTING PASS #1


        while (more && keepRunning) {
            SyncChunk chunk;
            if (!comm->getLinkedNotebookSyncChunk(chunk, book, usn, chunkSize, fs)) {
                more = false;
                if (comm->getLastErrorType() == CommunicationError::EDAMNotFoundException) {
                    ltable.expunge(lids[i]);
                    if (!finalSync)
                        emit(notebookExpunged(lids[i]));
                } else {
                    this->communicationErrorHandler();
                    error = true;
                    QLOG_TRACE_OUT();
                    return false;
                }
            } else {
                processSyncChunk(chunk, lids[i]);
                usn = chunk.chunkHighUSN;
                if (chunk.updateCount > 0 && chunk.updateCount > startingSequenceNumber) {
                    int pct = (usn - startingSequenceNumber) * 100 / (chunk.updateCount - startingSequenceNumber);
                    QString sharename = "";
                    if (book.shareName.isSet())
                        sharename = book.shareName;
                    emit setMessage(
                        tr("Downloading ") + QString::number(pct) + tr("% complete for tags in shared notebook ") +
                        sharename + tr("."), defaultMsgTimeout);
                }
                if (!chunk.chunkHighUSN.isSet() || chunk.chunkHighUSN >= chunk.updateCount)
                    more = false;
            }
        }

        //************* STARTING PASS 2

        usn = startingUSN;
        more = true;
        chunkSize = 50;
        if (error == true)
            more = false;

        QString sharename = "";
        if (book.shareName.isSet())
            sharename = book.shareName;
        emit setMessage(tr("Downloading notes for shared notebook ") + sharename + tr("."), defaultMsgTimeout);


        while (more && keepRunning) {
            SyncChunk chunk;
            if (!comm->getLinkedNotebookSyncChunk(chunk, book, usn, chunkSize, fs)) {
                more = false;
                if (comm->getLastErrorType()== CommunicationError::EDAMNotFoundException) {
                    ltable.expunge(lids[i]);
                    if (!finalSync)
                        emit(notebookExpunged(lids[i]));
                } else {
                    this->communicationErrorHandler();
                    error = true;
                    return false;
                }
            } else {
                processSyncChunk(chunk, lids[i]);
                usn = chunk.chunkHighUSN;
                if (chunk.updateCount > 0 && chunk.updateCount > startingSequenceNumber) {
                    int pct = (usn - startingSequenceNumber) * 100 / (chunk.updateCount - startingSequenceNumber);
                    QString sharename = "";
                    if (book.shareName.isSet())
                        sharename = book.shareName;
                    emit setMessage(
                        tr("Downloading ") + QString::number(pct) + tr("% complete for shared notebook ") + sharename +
                        tr("."), defaultMsgTimeout);
                }
                if (!chunk.chunkHighUSN.isSet() || chunk.chunkHighUSN >= chunk.updateCount) {
                    more = false;
                    ltable.setLastUpdateSequenceNumber(lids[i], syncState.updateCount);
                }
            }
        }

        qint32 noteUSN = uploadLinkedNotes(lids[i]);
        if (noteUSN > usn)
            ltable.setLastUpdateSequenceNumber(lids[i], noteUSN);
    }
    TagTable tagTable(db);
    tagTable.cleanupLinkedTags();
    QLOG_TRACE_OUT();
    return true;
}


// Upload notes that belong to me
qint32 SyncRunner::uploadLinkedNotes(qint32 notebookLid) {
    QLOG_TRACE_IN();
    qint32 usn;
    qint32 maxUsn = 0;
    NoteTable noteTable(db);
    QList<qint32> lids, validLids, deletedLids;
    noteTable.getAllDirty(lids, notebookLid);

    // Split the list into deleted and updated notes
    for (int i = 0; i < lids.size(); i++) {
        if (noteTable.isDeleted(lids[i]))
            deletedLids.append(lids[i]);
        else
            validLids.append(lids[i]);
    }

    // Start deleting notes
    for (int i = 0; i < deletedLids.size(); i++) {
        QString guid = noteTable.getGuid(deletedLids[i]);
        noteTable.setDirty(lids[i], false);
        usn = comm->deleteLinkedNote(guid);
        if (usn > maxUsn) {
            maxUsn = usn;
            noteTable.setUpdateSequenceNumber(deletedLids[i], usn);
            noteTable.setDirty(deletedLids[i], false);
            if (!finalSync)
                emit(noteSynchronized(deletedLids[i], false));
        }
    }


    // Start deleting notes that were in the trash, but the trash was
    // emptied.
    NotebookTable bookTable(db);
    QString notebookGuid = "";
    bookTable.getGuid(notebookGuid, notebookLid);

    // Get all of the notes
    QStringList deleteQueueGuids;
    noteTable.getAllDeleteQueue(deleteQueueGuids, notebookGuid);


    // Do the actual deletes
    for (int i = 0; i < deleteQueueGuids.size(); i++) {
        QString guid = deleteQueueGuids[i];
        usn = comm->deleteLinkedNote(guid);
        if (usn > maxUsn) {
            maxUsn = usn;
        }
        noteTable.expungeFromDeleteQueue(guid);
    }


    // Start uploading notes
    for (int i = 0; i < validLids.size(); i++) {
        Note note;
        noteTable.get(note, validLids[i], true, true);
        qint32 oldUsn = note.updateSequenceNum;
        usn = comm->uploadLinkedNote(note);
        if (usn == 0) {
            this->communicationErrorHandler();
            error = true;
            QLOG_TRACE_OUT();
            return maxUsn;
        }
        if (usn > maxUsn) {
            maxUsn = usn;
            if (oldUsn == 0)
                noteTable.updateGuid(validLids[i], note.guid);
            noteTable.setUpdateSequenceNumber(validLids[i], usn);
            noteTable.setDirty(validLids[i], false);
            if (!finalSync)
                emit(noteSynchronized(validLids[i], false));
        } else {
            error = true;
        }
    }
    QLOG_TRACE_OUT();
    return maxUsn;
}


// Synchronize remote expunged linked notebooks
void SyncRunner::syncRemoteExpungedLinkedNotebooks(QList<Guid> guids) {
    LinkedNotebookTable btable(db);
    for (int i = 0; i < guids.size(); i++) {
        LinkedNotebookTable ntable(db);
        qint32 lid = ntable.getLid(guids[i]);
        btable.expunge(guids[i]);
        emit notebookExpunged(lid);
    }
}


void SyncRunner::applicationException(QString s) {
    QLOG_DEBUG() << "Application Exception!!! : " << s;
}


// Upload any saved searchs
qint32 SyncRunner::uploadSavedSearches() {
    QLOG_TRACE_IN();
    qint32 usn;
    qint32 maxUsn = 0;
    SearchTable stable(db);
    QList<qint32> lids;
    stable.getAllDirty(lids);
    if (lids.size() == 0) {
        QLOG_TRACE_OUT();
        return 0;
    }

    for (int i = 0; i < lids.size(); i++) {
        SavedSearch search;
        stable.get(search, lids[i]);
        if (!stable.isDeleted(lids[i])) {
            qint32 oldUsn = search.updateSequenceNum;
            usn = comm->uploadSavedSearch(search);
            if (usn == 0) {
                this->communicationErrorHandler();
                error = true;
                QLOG_TRACE_OUT();
                return maxUsn;
            }
            if (usn > maxUsn) {
                maxUsn = usn;
                if (oldUsn == 0)
                    stable.updateGuid(lids[i], search.guid);
                stable.setUpdateSequenceNumber(lids[i], usn);
            } else {
                error = true;
            }
        } else {
            QString guid = stable.getGuid(lids[i]);
            stable.expunge(lids[i]);
            if (search.updateSequenceNum > 0) {
                usn = comm->expungeSavedSearch(guid);
                if (usn > maxUsn)
                    maxUsn = usn;
            }
        }
    }
    QLOG_TRACE_OUT();
    return maxUsn;
}


// Upload any tags
qint32 SyncRunner::uploadTags() {
    QLOG_TRACE_IN();
    qint32 usn;
    qint32 maxUsn = 0;
    TagTable table(db);
    QList<qint32> lids, deletedLids, updatedLids;
    table.resetLinkedTagsDirty();
    table.getAllDirty(lids);
    if (lids.size() == 0) {
        QLOG_TRACE_OUT();
        return 0;
    }

    // Split the lids into lids to be updated, and lids to be deleted
    for (int i = 0; i < lids.size(); i++) {
        if (table.isDeleted(lids[i]))
            deletedLids.append(lids[i]);
        else
            updatedLids.append(lids[i]);
    }

    // Get existing tags in case there is a duplicate name
    QList<Tag> existingTags;
    comm->getTagList(existingTags);

    // Update any lids
    QLOG_DEBUG() << "Beginning to upload new & altered tags";
    int i = 0;
    while (updatedLids.size() > 0) {

        Tag tag;
        table.get(tag, updatedLids[i]);
        if (tag.name.isSet()) {
            QLOG_DEBUG() << "Found changed tag " << tag.name;
        }
        qint32 parentLid = 0;
        QString parentGuid = "";
        if (tag.parentGuid.isSet())
            parentGuid = tag.parentGuid;
        if (parentGuid != "")
            parentLid = table.getLid(tag.parentGuid);

        // If the parent is either not dirty, or there is no parent we can update this lid.
        if (parentLid <= 0 || !table.isDirty(parentLid)) {
            QLOG_DEBUG() << "Tag has no parent or parent is unaltered";
            // Check if a tag with this name already exists.
            // In reality this should never happen, but there was a bug
            // where a tag was uploaded but the USN & GUID wasn't
            // updated.  This is a workaround for people who
            // have that bug.
            Tag foundTag;
            bool matchFound = false;
            for (int j = 0; j < existingTags.size(); j++) {
                QString tempTagName = existingTags[j].name;
                if (tempTagName == tag.name) {
                    matchFound = true;
                    foundTag = existingTags[j];
                    j = existingTags.size();
                }
            }

            if (!matchFound) {
                qint32 oldUsn = 0;
                if (tag.updateSequenceNum.isSet())
                    oldUsn = tag.updateSequenceNum;
                QLOG_DEBUG() << "Uploaing tag " << tag.name;
                usn = comm->uploadTag(tag);
                if (usn == 0) {
                    this->communicationErrorHandler();
                    error = true;
                    QLOG_TRACE_OUT();
                    return maxUsn;
                }
                if (usn > 0) {
                    maxUsn = usn;
                    QLOG_DEBUG() << "Tag USN: " << usn;
                    if (oldUsn == 0) {
                        QLOG_DEBUG() << "New USN: " << tag.guid;
                        table.updateGuid(updatedLids[i], tag.guid);
                    }
                    table.setUpdateSequenceNumber(updatedLids[i], usn);
                    table.setDirty(tag.guid, false);
                    updatedLids.removeAt(i);
                    i = -1;  // Reset for the next time through the loop
                } else {
                    error = true;
                    updatedLids.clear();
                }
            } else {
                QLOG_DEBUG() << "Tag with this name exists.";
                table.updateGuid(updatedLids[i], foundTag.guid);
                table.setUpdateSequenceNumber(updatedLids[i], foundTag.updateSequenceNum);
                updatedLids.removeAt(i);
                i = -1;  // Reset for the next time through the loop
            }
        }
        i++;
    }

    QLOG_DEBUG() << "Deleting LIDS";
    // delete any lids
    for (int i = 0; i < deletedLids.size(); i++) {
        Tag tag;
        table.get(tag, deletedLids[i]);
        table.expunge(lids[i]);
        if (tag.updateSequenceNum > 0) {
            usn = comm->expungeTag(tag.guid);
            if (usn > maxUsn)
                maxUsn = usn;
        }
    }
    QLOG_TRACE_OUT();
    return maxUsn;
}


// Upload any saved searchs
qint32 SyncRunner::uploadNotebooks() {
    QLOG_TRACE_IN();
    qint32 usn;
    qint32 maxUsn = 0;
    NotebookTable table(db);
    QList<qint32> lids;
    table.resetDirtyLocalNotebooks();
    table.resetLinkedNotebooksDirty();
    table.getAllDirty(lids);
    for (int i = 0; i < lids.size(); i++) {
        Notebook notebook;
        table.get(notebook, lids[i]);
        if (!table.isDeleted(lids[i])) {
            qint32 oldUsn = notebook.updateSequenceNum;
            usn = comm->uploadNotebook(notebook);
            if (usn == 0) {
                this->communicationErrorHandler();
                error = true;
                QLOG_TRACE_OUT();
                return maxUsn;
            }
            if (usn > maxUsn) {
                maxUsn = usn;
                if (oldUsn == 0)
                    table.updateGuid(lids[i], notebook.guid);
                table.setUpdateSequenceNumber(lids[i], usn);
            } else {
                error = true;
            }
        } else {
            QString guid;
            table.getGuid(guid, lids[i]);
            table.expunge(lids[i]);
            if (notebook.updateSequenceNum > 0) {
                usn = comm->expungeNotebook(guid);
                if (usn > maxUsn)
                    maxUsn = usn;
            }
        }
    }
    QLOG_TRACE_OUT();
    return maxUsn;
}


// Upload notes that belong to me
qint32 SyncRunner::uploadPersonalNotes() {
    QLOG_TRACE_IN();
    qint32 usn;
    qint32 maxUsn = 0;
    NotebookTable notebookTable(db);
    LinkedNotebookTable linkedNotebookTable(db);
    NoteTable noteTable(db);
    QList<qint32> lids, validLids, deletedLids, movedLids;
    QStringList deleteQueueGuids;
    noteTable.getAllDirty(lids);

    // Get all of the notes that were deleted, and then removed from the trash
    noteTable.getAllDeleteQueue(deleteQueueGuids);


    // Get a list of all notes that are both dirty and in an account we own and isn't deleted
    for (int i = 0; i < lids.size(); i++) {
        qint32 notebookLid = noteTable.getNotebookLid(lids[i]);
        if (!linkedNotebookTable.exists(notebookLid)) {
            if (!notebookTable.isLocal(notebookLid)) {
                if (noteTable.isDeleted(lids[i]))
                    deletedLids.append(lids[i]);
                else
                    validLids.append(lids[i]);
            } else {
                // We have a note that is local.  Check if it was once
                // synchronized.  If so, it was moved to a local notebook
                // and now needs to be deleted on the remote end
                Note n;
                noteTable.get(n, lids[i], false, false);
                if (n.updateSequenceNum.isSet() && n.updateSequenceNum > 0) {
                    movedLids.append(lids[i]);
                }
            }
        }
    }

    // Start deleting notes
    for (int i = 0; i < deletedLids.size(); i++) {
        QString guid = noteTable.getGuid(deletedLids[i]);
        noteTable.setDirty(lids[i], false);
        usn = comm->deleteNote(guid);
        if (usn > maxUsn) {
            maxUsn = usn;
            noteTable.setUpdateSequenceNumber(deletedLids[i], usn);
            noteTable.setDirty(deletedLids[i], false);
            if (!finalSync)
                emit(noteSynchronized(deletedLids[i], false));
        }
    }

    // Start handling notes moved to a local notebook.  What
    // we do is to delete the note on Evernote, then give the
    // note in the local notebook a new GUID & set the
    // update sequence number to 0.
    for (int i = 0; i < movedLids.size(); i++) {
        QUuid uuid;
        Guid newGuid = uuid.createUuid().toString().replace("{", "").replace("}", "");
        QString guid = noteTable.getGuid(movedLids[i]);
        noteTable.setDirty(movedLids[i], false);
        noteTable.updateGuid(movedLids[i], newGuid);
        noteTable.setUpdateSequenceNumber(movedLids[0], 0);
        usn = comm->deleteNote(guid);
        if (usn > maxUsn) {
            maxUsn = usn;
        }
        if (!finalSync)
            emit(noteSynchronized(movedLids[i], false));
    }


    // Delete any notes that were deleted, but emptied from the trash
    for (int i = 0; i < deleteQueueGuids.size(); i++) {
        QString guid = deleteQueueGuids[i];
        usn = comm->deleteNote(guid);
        if (usn > maxUsn) {
            maxUsn = usn;
        }
        noteTable.expungeFromDeleteQueue(guid);
    }


    // Start uploading notes
    for (int i = 0; i < validLids.size(); i++) {
        Note note;
        noteTable.get(note, validLids[i], true, true);

        qint32 oldUsn = 0;
        if (note.updateSequenceNum.isSet())
            oldUsn = note.updateSequenceNum;
        usn = comm->uploadNote(note);
        if (usn == 0) {
            this->communicationErrorHandler();
            if (note.title.isSet()) {
                QLOG_ERROR() << tr("Error uploading note:") + note.title;
            } else {
                QLOG_ERROR() << tr("Error uploading note with a missing title!");
            }
            error = true;
            //return maxUsn;
        }
        if (usn > maxUsn) {
            maxUsn = usn;
            if (oldUsn == 0)
                noteTable.updateGuid(validLids[i], note.guid);
            noteTable.setUpdateSequenceNumber(validLids[i], usn);
            noteTable.setDirty(validLids[i], false);
            if (!finalSync)
                emit(noteSynchronized(validLids[i], false));
        } else {
            error = true;
        }
    }
    QLOG_TRACE_OUT();
    return maxUsn;
}


// If a communication error happened, try to determine what the error is and
// notify the user
void SyncRunner::communicationErrorHandler() {
    CommunicationError::CommunicationErrorType type = comm->getLastErrorType();

    if (type == CommunicationError::None ||
            type == CommunicationError::StdException) {
        connectionClosed = true;
        return;
    }

    if (type == CommunicationError::RateLimitExceeded) {
        minutesToNextSync = comm->getMinutesToNextSync();
        apiRateLimitExceeded = true;
    }
    if (type == CommunicationError::EDAMUserException) {
        if (comm->getLastErrorCode() == static_cast<int>(EDAMErrorCode::AUTH_EXPIRED)) {
            global.accountsManager->setOAuthToken("");
        }
    }
    // should be already displayed by "error" itself
    //emit(setMessage(comm->error.getMessage(), 0));
}

void SyncRunner::setUpdateUserDataOnNextSync(bool updateUserDataOnNextSync) {
    QLOG_INFO() << "Setting updateUserDataOnNextSync to " << updateUserDataOnNextSync;
    SyncRunner::updateUserDataOnNextSync = updateUserDataOnNextSync;
}

