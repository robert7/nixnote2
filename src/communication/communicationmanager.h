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

#ifndef COMMUNICATIONMANAGER_H
#define COMMUNICATIONMANAGER_H


//***************************************************************************
//*  This class is used to manage communications between Evernote and
//*  NixNote.  A lot of this is done with QEvercloud.
//***************************************************************************

#include "src/qevercloud/QEverCloud/headers/QEverCloud.h"
#include "src/global.h"
#include <QString>
#include "communicationerror.h"
#include <inttypes.h>
#include <iostream>
// Windows Check
#ifndef _WIN32
#include <netinet/in.h>
#endif
#include <stdint.h>
#include <QObject>
#include <QNetworkAccessManager>
#include <QSqlDatabase>
#include <QMutex>

#include "src/qevercloud/QEverCloud/headers/QEverCloud.h"
using namespace qevercloud;

typedef unsigned int SOCKET;

using namespace std;

//* Userid/password key & secret


//* OAuth key & secret
#define EDAM_CONSUMER_KEY     "baumgarr-3523"
#define EDAM_CONSUMER_SECRET  "8d5ee175f8a5d3ec"

#define SYNC_CHUNK_NOTEBOOKS            0x0001
#define SYNC_CHUNK_TAGS                 0x0002
#define SYNC_CHUNK_LINKED_NOTEBOOKS     0x0004
#define SYNC_CHUNK_EXPUNGED            0x0008
#define SYNC_CHUNK_SEARCHES             0x0010
#define SYNC_CHUNK_NOTES                0x0020
#define SYNC_CHUNK_RESOURCES            0x0040

class CommunicationManager : public QObject
{
    Q_OBJECT

private:
    bool initComplete;                        // Has the class been properly initialized?
    DatabaseConnection *db;                   // Database connection
    bool initNoteStore();                     // Initialize the Notestore connection
    QUrl *postData;                           // URL used to communicate with Evernote

    QString noteStorePath;                    // Notestore URL path.
    QString evernoteHost;                     // Evernote server URL.

    AuthenticationResult linkedAuth;          // Linked notebook authorization key
    QString linkedAuthToken;                  // linked notebook authorization token

    qint32 minutesToNextSync;                    // After "API rate limit exceeded" how long should we wait to attempt sync notes (continue syncing large lists of notes - for example when user setup nixnote for first time)


    void downloadInkNoteImage(QString guid, Resource *r, QString shard, QString authToken);   // Function to download ink notes
    void checkForInkNotes(QList<Resource> &resources, QString shard, QString authToken);      // Check if a resource list has any ink notes

    QString authToken;                        // Authorization token.
    QString shardId;
    bool init();                              // Init function.  Run after the thread has started & after first call.
    QNetworkAccessManager *networkAccessManager;              // Network connection to download inknotes
    void handleEDAMSystemException(EDAMSystemException e, QString additionalInfo = "");
    void handleEDAMNotFoundException(EDAMNotFoundException e, QString additionalInfo = "");
    IUserStore *userStore;                                     // UserStore class
    INoteStore *noteStore;                                     // Notestore class
    INoteStore *linkedNoteStore;                               // Linked notestore class
    INoteStore *myNoteStore;                                   // local account notestore class
    void processSyncChunk(SyncChunk &chunk, QString token);   // Deal with a sync chunk.
    void dumpNote(const Note &note) const;
    void reportError(const CommunicationError::CommunicationErrorType errorType,
                     int code,
                     const QString &message,
                     const QString &internalMessage = QString());

    CommunicationError error;
    bool hasException;
    QMutex mutex;

public:

    CommunicationManager(DatabaseConnection *db);              // Constructor
    ~CommunicationManager();                                   // Destructor

    // both are used (just clion does not recognise it)
    bool getSharedNotebookByAuth(SharedNotebook &sharedNotebook);    // Get a shared notebook by authorization key
    bool authenticateToLinkedNotebook(AuthenticationResult &authResult, LinkedNotebook &book);   // Authenticate to linked notebook account

    bool enConnect();                                            // Connect to Evernote
    bool getSyncState(QString authToken, SyncState &syncState);    // Download the last sync state
    bool getSyncChunk(SyncChunk &chunk, int start, int chunkSize, int type, bool fullSync, QString token="");   // Download a sync chunk
    bool getLinkedNotebookSyncState(SyncState &syncState, LinkedNotebook &book);         // Get the sync state of a linked notebook
    bool getLinkedNotebookSyncChunk(SyncChunk &chunk, LinkedNotebook &book, int start, int chunkSize, bool fullSync);   // Get linked notebook sync chunk
    void enDisconnect();                                         // Disconnect from evernote
    bool authenticateToLinkedNotebookShard(LinkedNotebook &book);    // Authenticate to a linked notebook account owner shard
    bool getUserInfo(User &user);                              // Get user information
    bool getNote(Note &n, QString guid, bool wthResource, bool withRecognition, bool withResource);
    Note downloadNote(const Note &n);
    QList< QPair<QString, QImage*>* > *inkNoteList;            // List to store inknotes downloaded from account.
    QList< QPair<QString, QImage*>* > *thumbnailList;          // List to store thumbnails from account (not used)
    QHash<QString,QString> *tagGuidMap;                        // Temporary hashmap used to store tags.  Keeps from repetitive DB lookups filling in tag names

    qint32 uploadSavedSearch(SavedSearch &search);             // Upload a saved search to Evernote
    qint32 expungeSavedSearch(Guid guid);                      // Expunge/delete a saved search

    qint32 uploadTag(Tag &tag);                                // Upload a tag to Evernote
    qint32 expungeTag(Guid guid);                              // Expunge/delete a tag

    qint32 uploadNotebook(Notebook &notebook);                 // Upload a notebook to Evernote
    qint32 expungeNotebook(Guid guid);                         // Expunge/delete a notebook

    qint32 uploadNote(Note &note, QString token="");           // Upload a note to Evernote
    qint32 uploadLinkedNote(Note &note);                       // Upload a note to a linked account
    qint32 deleteNote(Guid guid, QString token="");            // Mark a note as deleted (we don't actually expunge)
    qint32 deleteLinkedNote(Guid guid);                        // Mark a note in a linked notebook as deleted

    bool getNotebookList(QList<Notebook> &list);               // Get a list of available notebooks
    bool getTagList(QList<Tag> &list);                         // Get a list of all tags

    bool listNoteVersions(QList<NoteVersionId> &list, QString guid);    // Get a list of note revisions
    bool getNoteVersion(Note &note, QString guid, qint32 usn, bool withResourceData=true, bool withResourceRecognition=true, bool withResourceAlternateData=true);  // Download a past version of a note from a linked account
    void loadTagGuidMap();                                     // Load the tag hashmap.

    qint32 getMinutesToNextSync();
    void resetError();
    int getLastErrorCode() const;
    CommunicationError::CommunicationErrorType getLastErrorType() const;

public slots:
    int inkNoteReady(QImage *newImage, QImage *replyImage, int position);   // An inknote has been downloaded.

};

#endif // COMMUNICATIONMANAGER_H
