/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_TYPES_H
#define QEVERCLOUD_GENERATED_TYPES_H

#include "../Export.h"

#include "../Optional.h"
#include "../Printable.h"
#include "EDAMErrorCode.h"
#include <QByteArray>
#include <QDateTime>
#include <QHash>
#include <QList>
#include <QMap>
#include <QMetaType>
#include <QMetaType>
#include <QSet>
#include <QStringList>
#include <QVariant>

namespace qevercloud {

/**
 * A monotonically incrementing number on each shard that identifies a cross shard
 * cache invalidation event.
 */
using InvalidationSequenceNumber = qint64;

/**
 * A type alias for the primary identifiers for Identity objects.
 */
using IdentityID = qint64;

/**
 * Every Evernote account is assigned a unique numeric identifier which
 * will not change for the life of the account.  This is independent of
 * the (string-based) "username" which is known by the user for login
 * purposes.  The user should have no reason to know their UserID.
 */
using UserID = qint32;

/**
 * Most data elements within a user's account (e.g. notebooks, notes, tags,
 * resources, etc.) are internally referred to using a globally unique
 * identifier that is written in a standard string format.  For example:
 *
 *    "8743428c-ef91-4d05-9e7c-4a2e856e813a"
 *
 * The internal components of the GUID are not given any particular meaning:
 * only the entire string is relevant as a unique identifier.
 */
using Guid = QString;

/**
 * An Evernote Timestamp is the date and time of an event in UTC time.
 * This is expressed as a specific number of milliseconds since the
 * standard base "epoch" of:
 *
 *    January 1, 1970, 00:00:00 GMT
 *
 * NOTE:  the time is expressed at the resolution of milliseconds, but
 * the value is only precise to the level of seconds.   This means that
 * the last three (decimal) digits of the timestamp will be '000'.
 *
 * The Thrift IDL specification does not include a native date/time type,
 * so this value is used instead.
 *
 * The service will accept timestamp values (e.g. for Note created and update
 * times) between 1000-01-01 and 9999-12-31
 */
using Timestamp = qint64;

/**
 * A sequence number for the MessageStore subsystem.
 */
using MessageEventID = qint64;

/**
 * A type alias for the primary identifiers for MessageThread objects.
 */
using MessageThreadID = qint64;


/**
 * @brief The EverCloudLocalData class contains several
 * data elements which are not synchronized with Evernote service
 * but which are nevertheless useful in applications using
 * QEverCloud to implement feature rich full sync Evernote clients.
 * Values of this class' types are contained within QEverCloud
 * types corresponding to actual Evernote API types
 */
class QEVERCLOUD_EXPORT EverCloudLocalData: public Printable
{
    Q_GADGET
public:
    EverCloudLocalData();
    virtual ~EverCloudLocalData() noexcept override;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const EverCloudLocalData & other) const;
    bool operator!=(const EverCloudLocalData & other) const;
    /**
     * @brief id property can be used as a local unique identifier
     * for any data item before it has been synchronized with
     * Evernote and thus before it can be identified using its guid.
     *
     * id property is generated automatically on EverCloudLocalData
     * construction for convenience but can be overridden manually
     */
    QString id;

    /**
     * @brief dirty property can be used to keep track which
     * objects have been modified locally and thus need to be synchronized
     * with Evernote service
     */
    bool dirty = false;

    /**
     * @brief local property can be used to keep track which
     * data items are meant to be local only and thus never be synchronized
     * with Evernote service
     */
    bool local = false;

    /**
     * @brief favorited property can be used to keep track which
     * data items were favorited in the client. Unfortunately,
     * Evernote has never provided a way to synchronize such
     * property between different clients
     */
    bool favorited = false;

    /**
     * @brief dict can be used for storage of any other auxiliary
     * values associated with objects of QEverCloud types
     */
    QHash<QString, QVariant> dict;

    // Properties declaration for meta-object system
    Q_PROPERTY(QString id MEMBER id USER true)
    Q_PROPERTY(bool dirty MEMBER dirty)
    Q_PROPERTY(bool local MEMBER local)
    Q_PROPERTY(bool favorited MEMBER favorited)

    using Dict = QHash<QString, QVariant>;
    Q_PROPERTY(Dict dict MEMBER dict)
};

/**
 * This structure encapsulates the information about the state of the
 * user's account for the purpose of "state based" synchronization.
 * */
struct QEVERCLOUD_EXPORT SyncState: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The server's current date and time.
    */
    Timestamp currentTime = 0;
    /**
    The cutoff date and time for client caches to be
       updated via incremental synchronization.  Any clients that were last
       synched with the server before this date/time must do a full resync of all
       objects.  This cutoff point will change over time as archival data is
       deleted or special circumstances on the service require resynchronization.
    */
    Timestamp fullSyncBefore = 0;
    /**
    Indicates the total number of transactions that have
       been committed within the account.  This reflects (for example) the
       number of discrete additions or modifications that have been made to
       the data in this account (tags, notes, resources, etc.).
       This number is the "high water mark" for Update Sequence Numbers (USN)
       within the account.
    */
    qint32 updateCount = 0;
    /**
    The total number of bytes that have been uploaded to
       this account in the current monthly period.  This can be compared against
       Accounting.uploadLimit (from the UserStore) to determine how close the user
       is to their monthly upload limit.
       This value may not be present if the SyncState has been retrieved by
       a caller that only has read access to the account.
    */
    Optional<qint64> uploaded;
    /**
    The last time when a user's account level information was changed. This value
       is the latest time when a modification was made to any of the following:
       accounting information (billing, quota, premium status, etc.), user attributes
       and business user information (business name, business user attributes, etc.) if
       the user is in a business.
       Clients who need to maintain account information about a User should watch this
       field for updates rather than polling UserStore.getUser for updates. Here is the
       basic flow that clients should follow:
       <ol>
         <li>Call NoteStore.getSyncState to retrieve the SyncState object</li>
         <li>Compare SyncState.userLastUpdated to previously stored value:
             if (SyncState.userLastUpdated > previousValue)
               call UserStore.getUser to get the latest User object;
             else
               do nothing;</li>
         <li>Update previousValue = SyncState.userLastUpdated</li>
       </ol>
    */
    Optional<Timestamp> userLastUpdated;
    /**
    The greatest MessageEventID for this user's account. Clients that do a full
       sync should store this value locally and compare their local copy to the
       value returned by getSyncState to determine if they need to sync with
       MessageStore. This value will be omitted if the user has never sent or
       received a message.
    */
    Optional<MessageEventID> userMaxMessageEventId;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const SyncState & other) const
    {
        return (currentTime == other.currentTime)
            && (fullSyncBefore == other.fullSyncBefore)
            && (updateCount == other.updateCount)
            && uploaded.isEqual(other.uploaded)
            && userLastUpdated.isEqual(other.userLastUpdated)
            && userMaxMessageEventId.isEqual(other.userMaxMessageEventId)
        ;
    }

    bool operator!=(const SyncState & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Timestamp currentTime MEMBER currentTime)
    Q_PROPERTY(Timestamp fullSyncBefore MEMBER fullSyncBefore)
    Q_PROPERTY(qint32 updateCount MEMBER updateCount)
    Q_PROPERTY(Optional<qint64> uploaded MEMBER uploaded)
    Q_PROPERTY(Optional<Timestamp> userLastUpdated MEMBER userLastUpdated)
    Q_PROPERTY(Optional<MessageEventID> userMaxMessageEventId MEMBER userMaxMessageEventId)
};

/**
 * This structure is used with the 'getFilteredSyncChunk' call to provide
 * fine-grained control over the data that's returned when a client needs
 * to synchronize with the service. Each flag in this structure specifies
 * whether to include one class of data in the results of that call.
 *
 **/
struct QEVERCLOUD_EXPORT SyncChunkFilter: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    If true, then the server will include the SyncChunks.notes field
    */
    Optional<bool> includeNotes;
    /**
    If true, then the server will include the 'resources' field on all of
       the Notes that are in SyncChunk.notes.
       If 'includeNotes' is false, then this will have no effect.
    */
    Optional<bool> includeNoteResources;
    /**
    If true, then the server will include the 'attributes' field on all of
       the Notes that are in SyncChunks.notes.
       If 'includeNotes' is false, then this will have no effect.
    */
    Optional<bool> includeNoteAttributes;
    /**
    If true, then the server will include the SyncChunks.notebooks field
    */
    Optional<bool> includeNotebooks;
    /**
    If true, then the server will include the SyncChunks.tags field
    */
    Optional<bool> includeTags;
    /**
    If true, then the server will include the SyncChunks.searches field
    */
    Optional<bool> includeSearches;
    /**
    If true, then the server will include the SyncChunks.resources field.
       Since the Resources are also provided with their Note
       (in the Notes.resources list), this is primarily useful for clients that
       want to watch for changes to individual Resources due to recognition data
       being added.
    */
    Optional<bool> includeResources;
    /**
    If true, then the server will include the SyncChunks.linkedNotebooks field.
    */
    Optional<bool> includeLinkedNotebooks;
    /**
    If true, then the server will include the 'expunged' data for any type
       of included data.  For example, if 'includeTags' and 'includeExpunged'
       are both true, then the SyncChunks.expungedTags field will be set with
       the GUIDs of tags that have been expunged from the server.
    */
    Optional<bool> includeExpunged;
    /**
    If true, then the values for the applicationData map will be filled
       in, assuming notes and note attributes are being returned.  Otherwise,
       only the keysOnly field will be filled in.
    */
    Optional<bool> includeNoteApplicationDataFullMap;
    /**
    If true, then the fullMap values for the applicationData map will be
       filled in, assuming resources and resource attributes are being returned
       (includeResources is true).  Otherwise, only the keysOnly field will be
       filled in.
    */
    Optional<bool> includeResourceApplicationDataFullMap;
    /**
    If true, then the fullMap values for the applicationData map will be
       filled in for resources found inside of notes, assuming resources are
       being returned in notes (includeNoteResources is true).  Otherwise,
       only the keysOnly field will be filled in.
    */
    Optional<bool> includeNoteResourceApplicationDataFullMap;
    /**
    If true, then the service will include the sharedNotes field on all
       notes that are in SyncChunk.notes. If 'includeNotes' is false, then
       this will have no effect.
    */
    Optional<bool> includeSharedNotes;
    /** NOT DOCUMENTED */
    Optional<bool> omitSharedNotebooks;
    /**
    If set, then only send notes whose content class matches this value.
       The value can be a literal match or, if the last character is an
       asterisk, a prefix match.
    */
    Optional<QString> requireNoteContentClass;
    /**
    If set, then restrict the returned notebooks, notes, and
       resources to those associated with one of the notebooks whose
       GUID is provided in this list.  If not set, then no filtering on
       notebook GUID will be performed.  If you set this field, you may
       not also set includeExpunged else an EDAMUserException with an
       error code of DATA_CONFLICT will be thrown.  You only need to set
       this field if you want to restrict the returned entities more
       than what your authentication token allows you to access.  For
       example, there is no need to set this field for single notebook
       tokens such as for shared notebooks.  You can use this field to
       synchronize a newly discovered business notebook while
       incrementally synchronizing a business account, in which case you
       will only need to consider setting includeNotes,
       includeNotebooks, includeNoteAttributes, includeNoteResources,
       and maybe some of the "FullMap" fields.
    */
    Optional<QSet<QString>> notebookGuids;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const SyncChunkFilter & other) const
    {
        return includeNotes.isEqual(other.includeNotes)
            && includeNoteResources.isEqual(other.includeNoteResources)
            && includeNoteAttributes.isEqual(other.includeNoteAttributes)
            && includeNotebooks.isEqual(other.includeNotebooks)
            && includeTags.isEqual(other.includeTags)
            && includeSearches.isEqual(other.includeSearches)
            && includeResources.isEqual(other.includeResources)
            && includeLinkedNotebooks.isEqual(other.includeLinkedNotebooks)
            && includeExpunged.isEqual(other.includeExpunged)
            && includeNoteApplicationDataFullMap.isEqual(other.includeNoteApplicationDataFullMap)
            && includeResourceApplicationDataFullMap.isEqual(other.includeResourceApplicationDataFullMap)
            && includeNoteResourceApplicationDataFullMap.isEqual(other.includeNoteResourceApplicationDataFullMap)
            && includeSharedNotes.isEqual(other.includeSharedNotes)
            && omitSharedNotebooks.isEqual(other.omitSharedNotebooks)
            && requireNoteContentClass.isEqual(other.requireNoteContentClass)
            && notebookGuids.isEqual(other.notebookGuids)
        ;
    }

    bool operator!=(const SyncChunkFilter & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<bool> includeNotes MEMBER includeNotes)
    Q_PROPERTY(Optional<bool> includeNoteResources MEMBER includeNoteResources)
    Q_PROPERTY(Optional<bool> includeNoteAttributes MEMBER includeNoteAttributes)
    Q_PROPERTY(Optional<bool> includeNotebooks MEMBER includeNotebooks)
    Q_PROPERTY(Optional<bool> includeTags MEMBER includeTags)
    Q_PROPERTY(Optional<bool> includeSearches MEMBER includeSearches)
    Q_PROPERTY(Optional<bool> includeResources MEMBER includeResources)
    Q_PROPERTY(Optional<bool> includeLinkedNotebooks MEMBER includeLinkedNotebooks)
    Q_PROPERTY(Optional<bool> includeExpunged MEMBER includeExpunged)
    Q_PROPERTY(Optional<bool> includeNoteApplicationDataFullMap MEMBER includeNoteApplicationDataFullMap)
    Q_PROPERTY(Optional<bool> includeResourceApplicationDataFullMap MEMBER includeResourceApplicationDataFullMap)
    Q_PROPERTY(Optional<bool> includeNoteResourceApplicationDataFullMap MEMBER includeNoteResourceApplicationDataFullMap)
    Q_PROPERTY(Optional<bool> includeSharedNotes MEMBER includeSharedNotes)
    Q_PROPERTY(Optional<bool> omitSharedNotebooks MEMBER omitSharedNotebooks)
    Q_PROPERTY(Optional<QString> requireNoteContentClass MEMBER requireNoteContentClass)
    Q_PROPERTY(Optional<QSet<QString>> notebookGuids MEMBER notebookGuids)
};

/**
 * A list of criteria that are used to indicate which notes are desired from
 * the account.  This is used in queries to the NoteStore to determine
 * which notes should be retrieved.
 *
 **/
struct QEVERCLOUD_EXPORT NoteFilter: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The NoteSortOrder value indicating what criterion should be
       used to sort the results of the filter.
    */
    Optional<qint32> order;
    /**
    If true, the results will be ascending in the requested
       sort order.  If false, the results will be descending.
    */
    Optional<bool> ascending;
    /**
    If present, a search query string that will filter the set of notes to be returned.
       Accepts the full search grammar documented in the Evernote API Overview.
    */
    Optional<QString> words;
    /**
    If present, the Guid of the notebook that must contain
       the notes.
    */
    Optional<Guid> notebookGuid;
    /**
    If present, the list of tags (by GUID) that must be present
       on the notes.
    */
    Optional<QList<Guid>> tagGuids;
    /**
    The zone ID for the user, which will be used to interpret
       any dates or times in the queries that do not include their desired zone
       information.
       For example, if a query requests notes created "yesterday", this
       will be evaluated from the provided time zone, if provided.
       The format must be encoded as a standard zone ID such as
       "America/Los_Angeles".
    */
    Optional<QString> timeZone;
    /**
    If true, then only notes that are not active (i.e. notes in
       the Trash) will be returned. Otherwise, only active notes will be returned.
       There is no way to find both active and inactive notes in a single query.
    */
    Optional<bool> inactive;
    /**
    If present, a search query string that may or may not influence the notes
       to be returned, both in terms of coverage as well as of order. Think of it
       as a wish list, not a requirement.
       Accepts the full search grammar documented in the Evernote API Overview.
    */
    Optional<QString> emphasized;
    /**
    If true, then the search will include all business notebooks that are readable
       by the user. A business authentication token must be supplied for
       this option to take effect when calling search APIs.
    */
    Optional<bool> includeAllReadableNotebooks;
    /**
    If true, then the search will include all workspaces that are readable
       by the user. A business authentication token must be supplied for
       this option to take effect when calling search APIs.
    */
    Optional<bool> includeAllReadableWorkspaces;
    /**
    Specifies the context to consider when determining result ranking.
       Clients must leave this value unset unless they wish to explicitly specify a known
       non-default context.
    */
    Optional<QString> context;
    /**
    If present, the raw user query input.
       Accepts the full search grammar documented in the Evernote API Overview.
    */
    Optional<QString> rawWords;
    /**
    Specifies the correlating information about the current search session, in byte array.
       If this request is not for the first page of search results, the client should populate
       this field with the value of searchContextBytes from the NotesMetadataList of the
       original search response.
    */
    Optional<QByteArray> searchContextBytes;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NoteFilter & other) const
    {
        return order.isEqual(other.order)
            && ascending.isEqual(other.ascending)
            && words.isEqual(other.words)
            && notebookGuid.isEqual(other.notebookGuid)
            && tagGuids.isEqual(other.tagGuids)
            && timeZone.isEqual(other.timeZone)
            && inactive.isEqual(other.inactive)
            && emphasized.isEqual(other.emphasized)
            && includeAllReadableNotebooks.isEqual(other.includeAllReadableNotebooks)
            && includeAllReadableWorkspaces.isEqual(other.includeAllReadableWorkspaces)
            && context.isEqual(other.context)
            && rawWords.isEqual(other.rawWords)
            && searchContextBytes.isEqual(other.searchContextBytes)
        ;
    }

    bool operator!=(const NoteFilter & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<qint32> order MEMBER order)
    Q_PROPERTY(Optional<bool> ascending MEMBER ascending)
    Q_PROPERTY(Optional<QString> words MEMBER words)
    Q_PROPERTY(Optional<Guid> notebookGuid MEMBER notebookGuid)
    Q_PROPERTY(Optional<QList<Guid>> tagGuids MEMBER tagGuids)
    Q_PROPERTY(Optional<QString> timeZone MEMBER timeZone)
    Q_PROPERTY(Optional<bool> inactive MEMBER inactive)
    Q_PROPERTY(Optional<QString> emphasized MEMBER emphasized)
    Q_PROPERTY(Optional<bool> includeAllReadableNotebooks MEMBER includeAllReadableNotebooks)
    Q_PROPERTY(Optional<bool> includeAllReadableWorkspaces MEMBER includeAllReadableWorkspaces)
    Q_PROPERTY(Optional<QString> context MEMBER context)
    Q_PROPERTY(Optional<QString> rawWords MEMBER rawWords)
    Q_PROPERTY(Optional<QByteArray> searchContextBytes MEMBER searchContextBytes)
};

/**
 * This structure is provided to the findNotesMetadata function to specify
 * the subset of fields that should be included in each NoteMetadata element
 * that is returned in the NotesMetadataList.
 * Each field on this structure is a boolean flag that indicates whether the
 * corresponding field should be included in the NoteMetadata structure when
 * it is returned.  For example, if the 'includeTitle' field is set on this
 * structure when calling findNotesMetadata, then each NoteMetadata in the
 * list should have its 'title' field set.
 * If one of the fields in this spec is not set, then it will be treated as
 * 'false' by the server, so the default behavior is to include nothing in
 * replies (but the mandatory GUID)
 */
struct QEVERCLOUD_EXPORT NotesMetadataResultSpec: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /** NOT DOCUMENTED */
    Optional<bool> includeTitle;
    /** NOT DOCUMENTED */
    Optional<bool> includeContentLength;
    /** NOT DOCUMENTED */
    Optional<bool> includeCreated;
    /** NOT DOCUMENTED */
    Optional<bool> includeUpdated;
    /** NOT DOCUMENTED */
    Optional<bool> includeDeleted;
    /** NOT DOCUMENTED */
    Optional<bool> includeUpdateSequenceNum;
    /** NOT DOCUMENTED */
    Optional<bool> includeNotebookGuid;
    /** NOT DOCUMENTED */
    Optional<bool> includeTagGuids;
    /** NOT DOCUMENTED */
    Optional<bool> includeAttributes;
    /** NOT DOCUMENTED */
    Optional<bool> includeLargestResourceMime;
    /** NOT DOCUMENTED */
    Optional<bool> includeLargestResourceSize;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NotesMetadataResultSpec & other) const
    {
        return includeTitle.isEqual(other.includeTitle)
            && includeContentLength.isEqual(other.includeContentLength)
            && includeCreated.isEqual(other.includeCreated)
            && includeUpdated.isEqual(other.includeUpdated)
            && includeDeleted.isEqual(other.includeDeleted)
            && includeUpdateSequenceNum.isEqual(other.includeUpdateSequenceNum)
            && includeNotebookGuid.isEqual(other.includeNotebookGuid)
            && includeTagGuids.isEqual(other.includeTagGuids)
            && includeAttributes.isEqual(other.includeAttributes)
            && includeLargestResourceMime.isEqual(other.includeLargestResourceMime)
            && includeLargestResourceSize.isEqual(other.includeLargestResourceSize)
        ;
    }

    bool operator!=(const NotesMetadataResultSpec & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<bool> includeTitle MEMBER includeTitle)
    Q_PROPERTY(Optional<bool> includeContentLength MEMBER includeContentLength)
    Q_PROPERTY(Optional<bool> includeCreated MEMBER includeCreated)
    Q_PROPERTY(Optional<bool> includeUpdated MEMBER includeUpdated)
    Q_PROPERTY(Optional<bool> includeDeleted MEMBER includeDeleted)
    Q_PROPERTY(Optional<bool> includeUpdateSequenceNum MEMBER includeUpdateSequenceNum)
    Q_PROPERTY(Optional<bool> includeNotebookGuid MEMBER includeNotebookGuid)
    Q_PROPERTY(Optional<bool> includeTagGuids MEMBER includeTagGuids)
    Q_PROPERTY(Optional<bool> includeAttributes MEMBER includeAttributes)
    Q_PROPERTY(Optional<bool> includeLargestResourceMime MEMBER includeLargestResourceMime)
    Q_PROPERTY(Optional<bool> includeLargestResourceSize MEMBER includeLargestResourceSize)
};

/**
 * A data structure representing the number of notes for each notebook
 * and tag with a non-zero set of applicable notes.
 *
 **/
struct QEVERCLOUD_EXPORT NoteCollectionCounts: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    A mapping from the Notebook GUID to the number of
       notes (from some selection) that are in the corresponding notebook.
    */
    Optional<QMap<Guid, qint32>> notebookCounts;
    /**
    A mapping from the Tag GUID to the number of notes (from some
       selection) that have the corresponding tag.
    */
    Optional<QMap<Guid, qint32>> tagCounts;
    /**
    If this is set, then this is the number of notes that are in the trash.
       If this is not set, then the number of notes in the trash hasn't been
       reported.  (I.e. if there are no notes in the trash, this will be set
       to 0.)
    */
    Optional<qint32> trashCount;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NoteCollectionCounts & other) const
    {
        return notebookCounts.isEqual(other.notebookCounts)
            && tagCounts.isEqual(other.tagCounts)
            && trashCount.isEqual(other.trashCount)
        ;
    }

    bool operator!=(const NoteCollectionCounts & other) const
    {
        return !(*this == other);
    }

    using TagCounts = QMap<Guid, qint32>;

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<TagCounts> notebookCounts MEMBER notebookCounts)
    Q_PROPERTY(Optional<TagCounts> tagCounts MEMBER tagCounts)
    Q_PROPERTY(Optional<qint32> trashCount MEMBER trashCount)
};

/**
 * This structure is provided to the getNoteWithResultSpec function to specify the subset of
 * fields that should be included in the Note that is returned. This allows clients to request
 * the minimum set of information that they require when retrieving a note, reducing the size
 * of the response and improving the response time.
 *
 * If one of the fields in this spec is not set, then it will be treated as 'false' by the service,
 * so that the default behavior is to include none of the fields below in the Note.
 *
 * */
struct QEVERCLOUD_EXPORT NoteResultSpec: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    If true, the Note.content field will be populated with the note's ENML contents.
    */
    Optional<bool> includeContent;
    /**
    If true, any Resource elements will include the binary contents of their 'data' field's
         body.
    */
    Optional<bool> includeResourcesData;
    /**
    If true, any Resource elements will include the binary contents of their 'recognition'
         field's body if recognition data is available.
    */
    Optional<bool> includeResourcesRecognition;
    /**
    If true, any Resource elements will include the binary contents of their 'alternateData'
         field's body, if an alternate form is available.
    */
    Optional<bool> includeResourcesAlternateData;
    /**
    If true, the Note.sharedNotes field will be populated with the note's shares.
    */
    Optional<bool> includeSharedNotes;
    /**
    If true, the Note.attributes.applicationData.fullMap field will be populated.
    */
    Optional<bool> includeNoteAppDataValues;
    /**
    If true, the Note.resource.attributes.applicationData.fullMap field will be populated.
    */
    Optional<bool> includeResourceAppDataValues;
    /**
    If true, the Note.limits field will be populated with the note owner's account limits.
    */
    Optional<bool> includeAccountLimits;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NoteResultSpec & other) const
    {
        return includeContent.isEqual(other.includeContent)
            && includeResourcesData.isEqual(other.includeResourcesData)
            && includeResourcesRecognition.isEqual(other.includeResourcesRecognition)
            && includeResourcesAlternateData.isEqual(other.includeResourcesAlternateData)
            && includeSharedNotes.isEqual(other.includeSharedNotes)
            && includeNoteAppDataValues.isEqual(other.includeNoteAppDataValues)
            && includeResourceAppDataValues.isEqual(other.includeResourceAppDataValues)
            && includeAccountLimits.isEqual(other.includeAccountLimits)
        ;
    }

    bool operator!=(const NoteResultSpec & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<bool> includeContent MEMBER includeContent)
    Q_PROPERTY(Optional<bool> includeResourcesData MEMBER includeResourcesData)
    Q_PROPERTY(Optional<bool> includeResourcesRecognition MEMBER includeResourcesRecognition)
    Q_PROPERTY(Optional<bool> includeResourcesAlternateData MEMBER includeResourcesAlternateData)
    Q_PROPERTY(Optional<bool> includeSharedNotes MEMBER includeSharedNotes)
    Q_PROPERTY(Optional<bool> includeNoteAppDataValues MEMBER includeNoteAppDataValues)
    Q_PROPERTY(Optional<bool> includeResourceAppDataValues MEMBER includeResourceAppDataValues)
    Q_PROPERTY(Optional<bool> includeAccountLimits MEMBER includeAccountLimits)
};

/**
 * Identifying information about previous versions of a note that are backed up
 * within Evernote's servers.  Used in the return value of the listNoteVersions
 * call.
 *
 * */
struct QEVERCLOUD_EXPORT NoteVersionId: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The update sequence number for the Note when it last had this content.
        This serves to uniquely identify each version of the note, since USN
        values are unique within an account for each update.
    */
    qint32 updateSequenceNum = 0;
    /**
    The 'updated' time that was set on the Note when it had this version
        of the content.  This is the user-modifiable modification time on the
        note, so it's not reliable for guaranteeing the order of various
        versions.  (E.g. if someone modifies the note, then changes this time
        manually into the past and then updates the note again.)
    */
    Timestamp updated = 0;
    /**
    A timestamp that holds the date and time when this version of the note
        was backed up by Evernote's servers.
    */
    Timestamp saved = 0;
    /**
    The title of the note when this particular version was saved.  (The
        current title of the note may differ from this value.)
    */
    QString title;
    /**
    The ID of the user who made the change to this version of the note. This will be
        unset if the note version was edited by the owner of the account.
    */
    Optional<UserID> lastEditorId;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NoteVersionId & other) const
    {
        return (updateSequenceNum == other.updateSequenceNum)
            && (updated == other.updated)
            && (saved == other.saved)
            && (title == other.title)
            && lastEditorId.isEqual(other.lastEditorId)
        ;
    }

    bool operator!=(const NoteVersionId & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(qint32 updateSequenceNum MEMBER updateSequenceNum)
    Q_PROPERTY(Timestamp updated MEMBER updated)
    Q_PROPERTY(Timestamp saved MEMBER saved)
    Q_PROPERTY(QString title MEMBER title)
    Q_PROPERTY(Optional<UserID> lastEditorId MEMBER lastEditorId)
};

/**
 * A description of the thing for which we are searching for related
 * entities.
 *
 * You must specify either <em>noteGuid</em> or <em>plainText</em>, but
 * not both. <em>filter</em> and <em>referenceUri</em> are optional.
 *
 * */
struct QEVERCLOUD_EXPORT RelatedQuery: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The GUID of an existing note in your account for which related
         entities will be found.
    */
    Optional<QString> noteGuid;
    /**
    A string of plain text for which to find related entities.
         You should provide a text block with a number of characters between
         EDAM_RELATED_PLAINTEXT_LEN_MIN and EDAM_RELATED_PLAINTEXT_LEN_MAX.
    */
    Optional<QString> plainText;
    /**
    The list of criteria that will constrain the notes being considered
         related.
         Please note that some of the parameters may be ignored, such as
         <em>order</em> and <em>ascending</em>.
    */
    Optional<NoteFilter> filter;
    /**
    A URI string specifying a reference entity, around which "relatedness"
         should be based. This can be an URL pointing to a web page, for example.
    */
    Optional<QString> referenceUri;
    /**
    Specifies the context to consider when determining related results.
         Clients must leave this value unset unless they wish to explicitly specify a known
         non-default context.
    */
    Optional<QString> context;
    /**
    If set and non-empty, this is an indicator for the server whether it is actually
         necessary to perform a new findRelated call at all. Cache Keys are opaque strings
         which are returned by the server as part of "RelatedResult" in response
         to a "NoteStore.findRelated" query. Cache Keys are inherently query specific.
    
         If set to an empty string, this indicates that the server should generate a cache
         key in the response as part of "RelatedResult".
    
         If not set, the server will not attempt to generate a cache key at all.
    */
    Optional<QString> cacheKey;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const RelatedQuery & other) const
    {
        return noteGuid.isEqual(other.noteGuid)
            && plainText.isEqual(other.plainText)
            && filter.isEqual(other.filter)
            && referenceUri.isEqual(other.referenceUri)
            && context.isEqual(other.context)
            && cacheKey.isEqual(other.cacheKey)
        ;
    }

    bool operator!=(const RelatedQuery & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> noteGuid MEMBER noteGuid)
    Q_PROPERTY(Optional<QString> plainText MEMBER plainText)
    Q_PROPERTY(Optional<NoteFilter> filter MEMBER filter)
    Q_PROPERTY(Optional<QString> referenceUri MEMBER referenceUri)
    Q_PROPERTY(Optional<QString> context MEMBER context)
    Q_PROPERTY(Optional<QString> cacheKey MEMBER cacheKey)
};

/**
 * A description of the thing for which the service will find related
 * entities, via findRelated(), together with a description of what
 * type of entities and how many you are seeking in the
 * RelatedResult.
 *
 * */
struct QEVERCLOUD_EXPORT RelatedResultSpec: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    Return notes that are related to the query, but no more than
         this many.  Any value greater than EDAM_RELATED_MAX_NOTES
         will be silently capped.  If you do not set this field, then
         no notes will be returned.
    */
    Optional<qint32> maxNotes;
    /**
    Return notebooks that are related to the query, but no more than
         this many.  Any value greater than EDAM_RELATED_MAX_NOTEBOOKS
         will be silently capped.  If you do not set this field, then
         no notebooks will be returned.
    */
    Optional<qint32> maxNotebooks;
    /**
    Return tags that are related to the query, but no more than
         this many.  Any value greater than EDAM_RELATED_MAX_TAGS
         will be silently capped.  If you do not set this field, then
         no tags will be returned.
    */
    Optional<qint32> maxTags;
    /**
    Require that all returned related notebooks are writable.
         The user will be able to create notes in all returned notebooks.
         However, individual notes returned may still belong to notebooks
         in which the user lacks the ability to create notes.
    */
    Optional<bool> writableNotebooksOnly;
    /**
    If set to <code>true</code>, return the containingNotebooks field
         in the RelatedResult, which will contain the list of notebooks to
         to which the returned related notes belong.
    */
    Optional<bool> includeContainingNotebooks;
    /**
    If set to <code>true</code>, indicate that debug information should
         be returned in the 'debugInfo' field of RelatedResult. Note that the call may
         be slower if this flag is set.
    */
    Optional<bool> includeDebugInfo;
    /**
    This can only be used when making a findRelated call against a business.
      Find users within your business who have knowledge about the specified query.
      No more than this many users will be returned. Any value greater than
      EDAM_RELATED_MAX_EXPERTS will be silently capped.
    */
    Optional<qint32> maxExperts;
    /**
    Return snippets of related content that is related to the query, but no more than
      this many. Any value greater than EDAM_RELATED_MAX_RELATED_CONTENT will be silently
      capped. If you do not set this field, then no related content will be returned.
    */
    Optional<qint32> maxRelatedContent;
    /**
    Specifies the types of Related Content that should be returned.
    */
    Optional<QSet<RelatedContentType>> relatedContentTypes;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const RelatedResultSpec & other) const
    {
        return maxNotes.isEqual(other.maxNotes)
            && maxNotebooks.isEqual(other.maxNotebooks)
            && maxTags.isEqual(other.maxTags)
            && writableNotebooksOnly.isEqual(other.writableNotebooksOnly)
            && includeContainingNotebooks.isEqual(other.includeContainingNotebooks)
            && includeDebugInfo.isEqual(other.includeDebugInfo)
            && maxExperts.isEqual(other.maxExperts)
            && maxRelatedContent.isEqual(other.maxRelatedContent)
            && relatedContentTypes.isEqual(other.relatedContentTypes)
        ;
    }

    bool operator!=(const RelatedResultSpec & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<qint32> maxNotes MEMBER maxNotes)
    Q_PROPERTY(Optional<qint32> maxNotebooks MEMBER maxNotebooks)
    Q_PROPERTY(Optional<qint32> maxTags MEMBER maxTags)
    Q_PROPERTY(Optional<bool> writableNotebooksOnly MEMBER writableNotebooksOnly)
    Q_PROPERTY(Optional<bool> includeContainingNotebooks MEMBER includeContainingNotebooks)
    Q_PROPERTY(Optional<bool> includeDebugInfo MEMBER includeDebugInfo)
    Q_PROPERTY(Optional<qint32> maxExperts MEMBER maxExperts)
    Q_PROPERTY(Optional<qint32> maxRelatedContent MEMBER maxRelatedContent)
    Q_PROPERTY(Optional<QSet<RelatedContentType>> relatedContentTypes MEMBER relatedContentTypes)
};

/** NO DOC COMMENT ID FOUND */
struct QEVERCLOUD_EXPORT ShareRelationshipRestrictions: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /** NOT DOCUMENTED */
    Optional<bool> noSetReadOnly;
    /** NOT DOCUMENTED */
    Optional<bool> noSetReadPlusActivity;
    /** NOT DOCUMENTED */
    Optional<bool> noSetModify;
    /** NOT DOCUMENTED */
    Optional<bool> noSetFullAccess;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const ShareRelationshipRestrictions & other) const
    {
        return noSetReadOnly.isEqual(other.noSetReadOnly)
            && noSetReadPlusActivity.isEqual(other.noSetReadPlusActivity)
            && noSetModify.isEqual(other.noSetModify)
            && noSetFullAccess.isEqual(other.noSetFullAccess)
        ;
    }

    bool operator!=(const ShareRelationshipRestrictions & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<bool> noSetReadOnly MEMBER noSetReadOnly)
    Q_PROPERTY(Optional<bool> noSetReadPlusActivity MEMBER noSetReadPlusActivity)
    Q_PROPERTY(Optional<bool> noSetModify MEMBER noSetModify)
    Q_PROPERTY(Optional<bool> noSetFullAccess MEMBER noSetFullAccess)
};

/**
 * Describes the association between a Notebook and an Evernote User who is
 * a member of that notebook.
 *
 * */
struct QEVERCLOUD_EXPORT MemberShareRelationship: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The string that clients should show to users to represent this
     member.
    */
    Optional<QString> displayName;
    /**
    The Evernote User ID of the recipient of this notebook share.
    */
    Optional<UserID> recipientUserId;
    /**
    The privilege at which the member can access the notebook,
     which is the best privilege granted either individually or to a
     group to which a member belongs, such as a business.  This field is
     used by the service to convey information to the user, so clients
     should treat it as read-only.
    */
    Optional<ShareRelationshipPrivilegeLevel> bestPrivilege;
    /**
    The individually granted privilege for the member, which does
     not take GROUP privileges into account.  This value may be unset if
     only a group-assigned privilege has been granted to the member.
     This value can be managed by others with sufficient rights using
     the manageNotebookShares method.  The valid values that clients
     should present to users for selection are given via the the
     'restrictions' field.
    */
    Optional<ShareRelationshipPrivilegeLevel> individualPrivilege;
    /**
    The restrictions on which privileges may be individually
     assigned to the recipient of this share relationship.
    */
    Optional<ShareRelationshipRestrictions> restrictions;
    /**
    The user id of the user who most recently shared the notebook
     to this user. This field is currently unset for a MemberShareRelationship
     created by joining a notebook that has been published to the business
     (MemberShareRelationships where the individual privilege is unset).
     This field is used by the service to convey information to the user, so
     clients should treat it as read-only.
    */
    Optional<UserID> sharerUserId;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const MemberShareRelationship & other) const
    {
        return displayName.isEqual(other.displayName)
            && recipientUserId.isEqual(other.recipientUserId)
            && bestPrivilege.isEqual(other.bestPrivilege)
            && individualPrivilege.isEqual(other.individualPrivilege)
            && restrictions.isEqual(other.restrictions)
            && sharerUserId.isEqual(other.sharerUserId)
        ;
    }

    bool operator!=(const MemberShareRelationship & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> displayName MEMBER displayName)
    Q_PROPERTY(Optional<UserID> recipientUserId MEMBER recipientUserId)
    Q_PROPERTY(Optional<ShareRelationshipPrivilegeLevel> bestPrivilege MEMBER bestPrivilege)
    Q_PROPERTY(Optional<ShareRelationshipPrivilegeLevel> individualPrivilege MEMBER individualPrivilege)
    Q_PROPERTY(Optional<ShareRelationshipRestrictions> restrictions MEMBER restrictions)
    Q_PROPERTY(Optional<UserID> sharerUserId MEMBER sharerUserId)
};

/**
 * This structure is used by the service to communicate to clients, via
 * getNoteShareRelationships, which privilege levels are assignable to the
 * target of a note share relationship.
 *
 * */
struct QEVERCLOUD_EXPORT NoteShareRelationshipRestrictions: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    This value is true if the user is not allowed to set the privilege
     level to SharedNotePrivilegeLevel.READ_NOTE.
    */
    Optional<bool> noSetReadNote;
    /**
    This value is true if the user is not allowed to set the privilege
     level to SharedNotePrivilegeLevel.MODIFY_NOTE.
    */
    Optional<bool> noSetModifyNote;
    /**
    This value is true if the user is not allowed to set the
     privilege level to SharedNotePrivilegeLevel.FULL_ACCESS.
    */
    Optional<bool> noSetFullAccess;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NoteShareRelationshipRestrictions & other) const
    {
        return noSetReadNote.isEqual(other.noSetReadNote)
            && noSetModifyNote.isEqual(other.noSetModifyNote)
            && noSetFullAccess.isEqual(other.noSetFullAccess)
        ;
    }

    bool operator!=(const NoteShareRelationshipRestrictions & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<bool> noSetReadNote MEMBER noSetReadNote)
    Q_PROPERTY(Optional<bool> noSetModifyNote MEMBER noSetModifyNote)
    Q_PROPERTY(Optional<bool> noSetFullAccess MEMBER noSetFullAccess)
};

/**
 * Describes the association between a Note and an Evernote User who is
 * a member of that note.
 *
 * */
struct QEVERCLOUD_EXPORT NoteMemberShareRelationship: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The string that clients should show to users to represent this
     member.
    */
    Optional<QString> displayName;
    /**
    The Evernote UserID of the user who is a member to the note.
    */
    Optional<UserID> recipientUserId;
    /**
    The privilege at which the member can access the note,
     which is the best privilege granted to the user across all of their
     individual shares for this note. This field is used by the service
     to convey information to the user, so clients should treat it as
     read-only.
    */
    Optional<SharedNotePrivilegeLevel> privilege;
    /**
    The restrictions on which privileges may be individually
     assigned to the recipient of this share relationship. This field
     is used by the service to convey information to the user, so
     clients should treat it as read-only.
    */
    Optional<NoteShareRelationshipRestrictions> restrictions;
    /**
    The user id of the user who most recently shared the note with
     this user. This field is used by the service to convey information
     to the user, so clients should treat it as read-only.
    */
    Optional<UserID> sharerUserId;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NoteMemberShareRelationship & other) const
    {
        return displayName.isEqual(other.displayName)
            && recipientUserId.isEqual(other.recipientUserId)
            && privilege.isEqual(other.privilege)
            && restrictions.isEqual(other.restrictions)
            && sharerUserId.isEqual(other.sharerUserId)
        ;
    }

    bool operator!=(const NoteMemberShareRelationship & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> displayName MEMBER displayName)
    Q_PROPERTY(Optional<UserID> recipientUserId MEMBER recipientUserId)
    Q_PROPERTY(Optional<SharedNotePrivilegeLevel> privilege MEMBER privilege)
    Q_PROPERTY(Optional<NoteShareRelationshipRestrictions> restrictions MEMBER restrictions)
    Q_PROPERTY(Optional<UserID> sharerUserId MEMBER sharerUserId)
};

/**
 * Describes an invitation to a person to use their Evernote credentials
 * to gain access to a note belonging to another user.
 *
 * */
struct QEVERCLOUD_EXPORT NoteInvitationShareRelationship: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The string that clients should show to users to represent this
     invitation.
    */
    Optional<QString> displayName;
    /**
    Identifies the identity of the invitation recipient. Once the
     identity has been claimed by an Evernote user and they have accessed
     the note at least once, the invitation will be used up and will no
     longer be returned by the service to clients. Instead, that recipient
     will be included in the list of NoteMemberShareRelationships.
    */
    Optional<IdentityID> recipientIdentityId;
    /**
    The privilege level that the recipient will be granted when they
     accept this invitation. If the user already has a higher privilege to
     access this note then this will not affect the recipient's privileges.
    */
    Optional<SharedNotePrivilegeLevel> privilege;
    /**
    The user id of the user who most recently shared this note to this
     recipient. This field is used by the service to convey information
     to the user, so clients should treat it as read-only.
    */
    Optional<UserID> sharerUserId;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NoteInvitationShareRelationship & other) const
    {
        return displayName.isEqual(other.displayName)
            && recipientIdentityId.isEqual(other.recipientIdentityId)
            && privilege.isEqual(other.privilege)
            && sharerUserId.isEqual(other.sharerUserId)
        ;
    }

    bool operator!=(const NoteInvitationShareRelationship & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> displayName MEMBER displayName)
    Q_PROPERTY(Optional<IdentityID> recipientIdentityId MEMBER recipientIdentityId)
    Q_PROPERTY(Optional<SharedNotePrivilegeLevel> privilege MEMBER privilege)
    Q_PROPERTY(Optional<UserID> sharerUserId MEMBER sharerUserId)
};

/**
 * Captures a collection of share relationships for a single note,
 * for example, as returned by the getNoteShares method. The share
 * relationships fall into two broad categories: members, and
 * invitations that can be used to become members.
 *
 * */
struct QEVERCLOUD_EXPORT NoteShareRelationships: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    A list of open invitations that can be redeemed into
     memberships to the note.
    */
    Optional<QList<NoteInvitationShareRelationship>> invitations;
    /**
    A list of memberships of the noteb. A member is identified
     by their Evernote UserID and has rights to access the
     note.
    */
    Optional<QList<NoteMemberShareRelationship>> memberships;
    /** NOT DOCUMENTED */
    Optional<NoteShareRelationshipRestrictions> invitationRestrictions;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NoteShareRelationships & other) const
    {
        return invitations.isEqual(other.invitations)
            && memberships.isEqual(other.memberships)
            && invitationRestrictions.isEqual(other.invitationRestrictions)
        ;
    }

    bool operator!=(const NoteShareRelationships & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QList<NoteInvitationShareRelationship>> invitations MEMBER invitations)
    Q_PROPERTY(Optional<QList<NoteMemberShareRelationship>> memberships MEMBER memberships)
    Q_PROPERTY(Optional<NoteShareRelationshipRestrictions> invitationRestrictions MEMBER invitationRestrictions)
};

/**
 * Captures parameters used by clients to manage the shares for a given
 * note via the manageNoteShares function. This is used only to manage
 * the existing memberships and invitations for a note. To invite a new
 * recipient, use NoteStore.createOrUpdateSharedNotes.
 *
 * The only field of an existing membership or invitation that can be
 * updated by this function is the share privilege.
 *
 * */
struct QEVERCLOUD_EXPORT ManageNoteSharesParameters: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The GUID of the note whose shares are being managed.
    */
    Optional<QString> noteGuid;
    /**
    A list of existing memberships to update. This field is not
         meant to be the full set of memberships for the note. Clients
         should only include those existing memberships that they wish
         to modify. To remove an existing membership, see the unshares
         field.
    */
    Optional<QList<NoteMemberShareRelationship>> membershipsToUpdate;
    /**
    The list of outstanding invitations to update, as matched by the
         identity field of the NoteInvitationShareRelatioship instances.
         This field is not meant to be the full set of invitations for the
         note. Clients should only include those existing invitations that
         they wish to modify.
    */
    Optional<QList<NoteInvitationShareRelationship>> invitationsToUpdate;
    /**
    A list of existing memberships to expunge from the service.
    */
    Optional<QList<UserID>> membershipsToUnshare;
    /**
    A list of outstanding invitations to expunge from the service.
    */
    Optional<QList<IdentityID>> invitationsToUnshare;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const ManageNoteSharesParameters & other) const
    {
        return noteGuid.isEqual(other.noteGuid)
            && membershipsToUpdate.isEqual(other.membershipsToUpdate)
            && invitationsToUpdate.isEqual(other.invitationsToUpdate)
            && membershipsToUnshare.isEqual(other.membershipsToUnshare)
            && invitationsToUnshare.isEqual(other.invitationsToUnshare)
        ;
    }

    bool operator!=(const ManageNoteSharesParameters & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> noteGuid MEMBER noteGuid)
    Q_PROPERTY(Optional<QList<NoteMemberShareRelationship>> membershipsToUpdate MEMBER membershipsToUpdate)
    Q_PROPERTY(Optional<QList<NoteInvitationShareRelationship>> invitationsToUpdate MEMBER invitationsToUpdate)
    Q_PROPERTY(Optional<QList<UserID>> membershipsToUnshare MEMBER membershipsToUnshare)
    Q_PROPERTY(Optional<QList<IdentityID>> invitationsToUnshare MEMBER invitationsToUnshare)
};

/**
 * In several places, EDAM exchanges blocks of bytes of data for a component
 * which may be relatively large.  For example:  the contents of a clipped
 * HTML note, the bytes of an embedded image, or the recognition XML for
 * a large image.  This structure is used in the protocol to represent
 * any of those large blocks of data when they are transmitted or when
 * they are only referenced their metadata.
 *
 **/
struct QEVERCLOUD_EXPORT Data: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    This field carries a one-way hash of the contents of the
       data body, in binary form.  The hash function is MD5<br/>
       Length:  EDAM_HASH_LEN (exactly)
    */
    Optional<QByteArray> bodyHash;
    /**
    The length, in bytes, of the data body.
    */
    Optional<qint32> size;
    /**
    This field is set to contain the binary contents of the data
       whenever the resource is being transferred.  If only metadata is
       being exchanged, this field will be empty.  For example, a client could
       notify the service about the change to an attribute for a resource
       without transmitting the binary resource contents.
    */
    Optional<QByteArray> body;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const Data & other) const
    {
        return bodyHash.isEqual(other.bodyHash)
            && size.isEqual(other.size)
            && body.isEqual(other.body)
        ;
    }

    bool operator!=(const Data & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QByteArray> bodyHash MEMBER bodyHash)
    Q_PROPERTY(Optional<qint32> size MEMBER size)
    Q_PROPERTY(Optional<QByteArray> body MEMBER body)
};

/**
 * A structure holding the optional attributes that can be stored
 * on a User.  These are generally less critical than the core User fields.
 *
 **/
struct QEVERCLOUD_EXPORT UserAttributes: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    the location string that should be associated
       with the user in order to determine where notes are taken if not otherwise
       specified.<br/>
       Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    Optional<QString> defaultLocationName;
    /**
    if set, this is the latitude that should be
       assigned to any notes that have no other latitude information.
    */
    Optional<double> defaultLatitude;
    /**
    if set, this is the longitude that should be
       assigned to any notes that have no other longitude information.
    */
    Optional<double> defaultLongitude;
    /**
    if set, the user account is not yet confirmed for
       login.  I.e. the account has been created, but we are still waiting for
       the user to complete the activation step.
    */
    Optional<bool> preactivation;
    /**
    a list of promotions the user has seen.
        This list may occasionally be modified by the system when promotions are
        no longer available.<br/>
        Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    Optional<QStringList> viewedPromotions;
    /**
    if set, this is the email address that the
        user may send email to in order to add an email note directly into the
        account via the SMTP email gateway.  This is the part of the email
        address before the '@' symbol ... our domain is not included.
        If this is not set, the user may not add notes via the gateway.<br/>
        Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    Optional<QString> incomingEmailAddress;
    /**
    if set, this will contain a list of email
        addresses that have recently been used as recipients
        of outbound emails by the user.  This can be used to pre-populate a
        list of possible destinations when a user wishes to send a note via
        email.<br/>
        Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX each<br/>
        Max:  EDAM_USER_RECENT_MAILED_ADDRESSES_MAX entries
    */
    Optional<QStringList> recentMailedAddresses;
    /**
    Free-form text field that may hold general support
        information, etc.<br/>
        Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    Optional<QString> comments;
    /**
    The date/time when the user agreed to
        the terms of service.  This can be used as the effective "start date"
        for the account.
    */
    Optional<Timestamp> dateAgreedToTermsOfService;
    /**
    The number of referrals that the user is permitted
        to make.
    */
    Optional<qint32> maxReferrals;
    /**
    The number of referrals sent from this account.
    */
    Optional<qint32> referralCount;
    /**
    A code indicating where the user was sent from. AKA
        promotion code
    */
    Optional<QString> refererCode;
    /**
    The most recent date when the user sent outbound
        emails from the service.  Used with sentEmailCount to limit the number
        of emails that can be sent per day.
    */
    Optional<Timestamp> sentEmailDate;
    /**
    The number of emails that were sent from the user
        via the service on sentEmailDate.  Used to enforce a limit on the number
        of emails per user per day to prevent spamming.
    */
    Optional<qint32> sentEmailCount;
    /**
    If set, this is the maximum number of emails that
        may be sent in a given day from this account.  If unset, the server will
        use the configured default limit.
    */
    Optional<qint32> dailyEmailLimit;
    /**
    If set, this is the date when the user asked
        to be excluded from offers and promotions sent by Evernote.  If not set,
        then the user currently agrees to receive these messages.
    */
    Optional<Timestamp> emailOptOutDate;
    /**
    If set, this is the date when the user asked
        to be included in offers and promotions sent by Evernote's partners.
        If not sent, then the user currently does not agree to receive these
        emails.
    */
    Optional<Timestamp> partnerEmailOptInDate;
    /**
    a 2 character language codes based on:
           http://ftp.ics.uci.edu/pub/ietf/http/related/iso639.txt used for
          localization purposes to determine what language to use for the web
          interface and for other direct communication (e.g. emails).
    */
    Optional<QString> preferredLanguage;
    /**
    Preferred country code based on ISO 3166-1-alpha-2 indicating the
       users preferred country
    */
    Optional<QString> preferredCountry;
    /**
    Boolean flag set to true if the user wants to clip full pages by
       default when they use the web clipper without a selection.
    */
    Optional<bool> clipFullPage;
    /**
    The username of the account of someone who has chosen to enable
       Twittering into Evernote.  This value is subject to change, since users
       may change their Twitter user name.
    */
    Optional<QString> twitterUserName;
    /**
    The unique identifier of the user's Twitter account if that user
       has chosen to enable Twittering into Evernote.
    */
    Optional<QString> twitterId;
    /**
    A name identifier used to identify a particular set of branding and
        light customization.
    */
    Optional<QString> groupName;
    /**
    a 2 character language codes based on:
           http://ftp.ics.uci.edu/pub/ietf/http/related/iso639.txt
           If set, this is used to determine the language that should be used
           when processing images and PDF files to find text.
           If not set, then the 'preferredLanguage' will be used.
    */
    Optional<QString> recognitionLanguage;
    /** NOT DOCUMENTED */
    Optional<QString> referralProof;
    /** NOT DOCUMENTED */
    Optional<bool> educationalDiscount;
    /**
    A string recording the business address of a Sponsored Account user who has requested invoicing.
    */
    Optional<QString> businessAddress;
    /**
    A flag indicating whether to hide the billing information on a sponsored
           account owner's settings page
    */
    Optional<bool> hideSponsorBilling;
    /**
    A flag indicating whether the user chooses to allow Evernote to automatically
           file and tag emailed notes
    */
    Optional<bool> useEmailAutoFiling;
    /**
    Configuration state for whether or not the user wishes to receive
           reminder e-mail.  This setting applies to both the reminder e-mail sent
           for personal reminder notes and for the reminder e-mail sent for reminder
           notes in the user's business notebooks that the user has configured for
           e-mail notifications.
    */
    Optional<ReminderEmailConfig> reminderEmailConfig;
    /**
    If set, this contains the time at which the user last confirmed that the
           configured email address for this account is correct and up-to-date. If this is
           unset that indicates that the user's email address is unverified.
    */
    Optional<Timestamp> emailAddressLastConfirmed;
    /**
    If set, this contains the time at which the user's password last changed. This
           will be unset for users created before the addition of this field who have not
           changed their passwords since the addition of this field.
    */
    Optional<Timestamp> passwordUpdated;
    /** NOT DOCUMENTED */
    Optional<bool> salesforcePushEnabled;
    /**
    If set to True, the server will record LogRequest send from clients of this
            user as ClientEventLog.
    */
    Optional<bool> shouldLogClientEvent;
    /**
    If set to True, no Machine Learning nor human review will be done to this
            user's note contents.
    */
    Optional<bool> optOutMachineLearning;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const UserAttributes & other) const
    {
        return defaultLocationName.isEqual(other.defaultLocationName)
            && defaultLatitude.isEqual(other.defaultLatitude)
            && defaultLongitude.isEqual(other.defaultLongitude)
            && preactivation.isEqual(other.preactivation)
            && viewedPromotions.isEqual(other.viewedPromotions)
            && incomingEmailAddress.isEqual(other.incomingEmailAddress)
            && recentMailedAddresses.isEqual(other.recentMailedAddresses)
            && comments.isEqual(other.comments)
            && dateAgreedToTermsOfService.isEqual(other.dateAgreedToTermsOfService)
            && maxReferrals.isEqual(other.maxReferrals)
            && referralCount.isEqual(other.referralCount)
            && refererCode.isEqual(other.refererCode)
            && sentEmailDate.isEqual(other.sentEmailDate)
            && sentEmailCount.isEqual(other.sentEmailCount)
            && dailyEmailLimit.isEqual(other.dailyEmailLimit)
            && emailOptOutDate.isEqual(other.emailOptOutDate)
            && partnerEmailOptInDate.isEqual(other.partnerEmailOptInDate)
            && preferredLanguage.isEqual(other.preferredLanguage)
            && preferredCountry.isEqual(other.preferredCountry)
            && clipFullPage.isEqual(other.clipFullPage)
            && twitterUserName.isEqual(other.twitterUserName)
            && twitterId.isEqual(other.twitterId)
            && groupName.isEqual(other.groupName)
            && recognitionLanguage.isEqual(other.recognitionLanguage)
            && referralProof.isEqual(other.referralProof)
            && educationalDiscount.isEqual(other.educationalDiscount)
            && businessAddress.isEqual(other.businessAddress)
            && hideSponsorBilling.isEqual(other.hideSponsorBilling)
            && useEmailAutoFiling.isEqual(other.useEmailAutoFiling)
            && reminderEmailConfig.isEqual(other.reminderEmailConfig)
            && emailAddressLastConfirmed.isEqual(other.emailAddressLastConfirmed)
            && passwordUpdated.isEqual(other.passwordUpdated)
            && salesforcePushEnabled.isEqual(other.salesforcePushEnabled)
            && shouldLogClientEvent.isEqual(other.shouldLogClientEvent)
            && optOutMachineLearning.isEqual(other.optOutMachineLearning)
        ;
    }

    bool operator!=(const UserAttributes & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> defaultLocationName MEMBER defaultLocationName)
    Q_PROPERTY(Optional<double> defaultLatitude MEMBER defaultLatitude)
    Q_PROPERTY(Optional<double> defaultLongitude MEMBER defaultLongitude)
    Q_PROPERTY(Optional<bool> preactivation MEMBER preactivation)
    Q_PROPERTY(Optional<QStringList> viewedPromotions MEMBER viewedPromotions)
    Q_PROPERTY(Optional<QString> incomingEmailAddress MEMBER incomingEmailAddress)
    Q_PROPERTY(Optional<QStringList> recentMailedAddresses MEMBER recentMailedAddresses)
    Q_PROPERTY(Optional<QString> comments MEMBER comments)
    Q_PROPERTY(Optional<Timestamp> dateAgreedToTermsOfService MEMBER dateAgreedToTermsOfService)
    Q_PROPERTY(Optional<qint32> maxReferrals MEMBER maxReferrals)
    Q_PROPERTY(Optional<qint32> referralCount MEMBER referralCount)
    Q_PROPERTY(Optional<QString> refererCode MEMBER refererCode)
    Q_PROPERTY(Optional<Timestamp> sentEmailDate MEMBER sentEmailDate)
    Q_PROPERTY(Optional<qint32> sentEmailCount MEMBER sentEmailCount)
    Q_PROPERTY(Optional<qint32> dailyEmailLimit MEMBER dailyEmailLimit)
    Q_PROPERTY(Optional<Timestamp> emailOptOutDate MEMBER emailOptOutDate)
    Q_PROPERTY(Optional<Timestamp> partnerEmailOptInDate MEMBER partnerEmailOptInDate)
    Q_PROPERTY(Optional<QString> preferredLanguage MEMBER preferredLanguage)
    Q_PROPERTY(Optional<QString> preferredCountry MEMBER preferredCountry)
    Q_PROPERTY(Optional<bool> clipFullPage MEMBER clipFullPage)
    Q_PROPERTY(Optional<QString> twitterUserName MEMBER twitterUserName)
    Q_PROPERTY(Optional<QString> twitterId MEMBER twitterId)
    Q_PROPERTY(Optional<QString> groupName MEMBER groupName)
    Q_PROPERTY(Optional<QString> recognitionLanguage MEMBER recognitionLanguage)
    Q_PROPERTY(Optional<QString> referralProof MEMBER referralProof)
    Q_PROPERTY(Optional<bool> educationalDiscount MEMBER educationalDiscount)
    Q_PROPERTY(Optional<QString> businessAddress MEMBER businessAddress)
    Q_PROPERTY(Optional<bool> hideSponsorBilling MEMBER hideSponsorBilling)
    Q_PROPERTY(Optional<bool> useEmailAutoFiling MEMBER useEmailAutoFiling)
    Q_PROPERTY(Optional<ReminderEmailConfig> reminderEmailConfig MEMBER reminderEmailConfig)
    Q_PROPERTY(Optional<Timestamp> emailAddressLastConfirmed MEMBER emailAddressLastConfirmed)
    Q_PROPERTY(Optional<Timestamp> passwordUpdated MEMBER passwordUpdated)
    Q_PROPERTY(Optional<bool> salesforcePushEnabled MEMBER salesforcePushEnabled)
    Q_PROPERTY(Optional<bool> shouldLogClientEvent MEMBER shouldLogClientEvent)
    Q_PROPERTY(Optional<bool> optOutMachineLearning MEMBER optOutMachineLearning)
};

/**
 * A structure holding the optional attributes associated with users
 * in a business.
 *
 * */
struct QEVERCLOUD_EXPORT BusinessUserAttributes: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    Free form text of this user's title in the business
    */
    Optional<QString> title;
    /**
    City, State (for US) or City / Province for other countries
    */
    Optional<QString> location;
    /**
    Free form text of the department this user belongs to.
    */
    Optional<QString> department;
    /**
    User's mobile phone number. Stored as plain text without any formatting.
    */
    Optional<QString> mobilePhone;
    /**
    URL to user's public LinkedIn profile page. This should only contain
      the portion relative to the base LinkedIn URL. For example: "/pub/john-smith/".
    */
    Optional<QString> linkedInProfileUrl;
    /**
    User's work phone number. Stored as plain text without any formatting.
    */
    Optional<QString> workPhone;
    /**
    The date on which the user started working at their company.
    */
    Optional<Timestamp> companyStartDate;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const BusinessUserAttributes & other) const
    {
        return title.isEqual(other.title)
            && location.isEqual(other.location)
            && department.isEqual(other.department)
            && mobilePhone.isEqual(other.mobilePhone)
            && linkedInProfileUrl.isEqual(other.linkedInProfileUrl)
            && workPhone.isEqual(other.workPhone)
            && companyStartDate.isEqual(other.companyStartDate)
        ;
    }

    bool operator!=(const BusinessUserAttributes & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> title MEMBER title)
    Q_PROPERTY(Optional<QString> location MEMBER location)
    Q_PROPERTY(Optional<QString> department MEMBER department)
    Q_PROPERTY(Optional<QString> mobilePhone MEMBER mobilePhone)
    Q_PROPERTY(Optional<QString> linkedInProfileUrl MEMBER linkedInProfileUrl)
    Q_PROPERTY(Optional<QString> workPhone MEMBER workPhone)
    Q_PROPERTY(Optional<Timestamp> companyStartDate MEMBER companyStartDate)
};

/**
 * This represents the bookkeeping information for the user's subscription.
 *
 **/
struct QEVERCLOUD_EXPORT Accounting: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The date and time when the current upload limit
       expires.  At this time, the monthly upload count reverts to 0 and a new
       limit is imposed.  This date and time is exclusive, so this is effectively
       the start of the new month.
    */
    Optional<Timestamp> uploadLimitEnd;
    /**
    When uploadLimitEnd is reached, the service
       will change uploadLimit to uploadLimitNextMonth. If a premium account is
       canceled, this mechanism will reset the quota appropriately.
    */
    Optional<qint64> uploadLimitNextMonth;
    /**
    Indicates the phases of a premium account
       during the billing process.
    */
    Optional<PremiumOrderStatus> premiumServiceStatus;
    /**
    The order number used by the commerce system to
       process recurring payments
    */
    Optional<QString> premiumOrderNumber;
    /**
    The commerce system used (paypal, Google
       checkout, etc)
    */
    Optional<QString> premiumCommerceService;
    /**
    The start date when this premium promotion
       began (this number will get overwritten if a premium service is canceled
       and then re-activated).
    */
    Optional<Timestamp> premiumServiceStart;
    /**
    The code associated with the purchase eg. monthly
       or annual purchase. Clients should interpret this value and localize it.
    */
    Optional<QString> premiumServiceSKU;
    /**
    Date the last time the user was charged.
       Null if never charged.
    */
    Optional<Timestamp> lastSuccessfulCharge;
    /**
    Date the last time a charge was attempted and
       failed.
    */
    Optional<Timestamp> lastFailedCharge;
    /**
    Reason provided for the charge failure
    */
    Optional<QString> lastFailedChargeReason;
    /**
    The end of the billing cycle. This could be in the
       past if there are failed charges.
    */
    Optional<Timestamp> nextPaymentDue;
    /**
    An internal variable to manage locking operations
       on the commerce variables.
    */
    Optional<Timestamp> premiumLockUntil;
    /**
    The date any modification where made to this record.
    */
    Optional<Timestamp> updated;
    /**
    The number number identifying the
       recurring subscription used to make the recurring charges.
    */
    Optional<QString> premiumSubscriptionNumber;
    /**
    Date charge last attempted
    */
    Optional<Timestamp> lastRequestedCharge;
    /**
    ISO 4217 currency code
    */
    Optional<QString> currency;
    /**
    charge in the smallest unit of the currency (e.g. cents for USD)
    */
    Optional<qint32> unitPrice;
    /**
    <i>DEPRECATED:</i>See BusinessUserInfo.
    */
    Optional<qint32> businessId;
    /**
    <i>DEPRECATED:</i>See BusinessUserInfo.
    */
    Optional<QString> businessName;
    /**
    <i>DEPRECATED:</i>See BusinessUserInfo.
    */
    Optional<BusinessUserRole> businessRole;
    /**
    discount per seat in negative amount and smallest unit of the currency (e.g.
           cents for USD)
    */
    Optional<qint32> unitDiscount;
    /**
    The next time the user will be charged, may or may not be the same as
           nextPaymentDue
    */
    Optional<Timestamp> nextChargeDate;
    /** NOT DOCUMENTED */
    Optional<qint32> availablePoints;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const Accounting & other) const
    {
        return uploadLimitEnd.isEqual(other.uploadLimitEnd)
            && uploadLimitNextMonth.isEqual(other.uploadLimitNextMonth)
            && premiumServiceStatus.isEqual(other.premiumServiceStatus)
            && premiumOrderNumber.isEqual(other.premiumOrderNumber)
            && premiumCommerceService.isEqual(other.premiumCommerceService)
            && premiumServiceStart.isEqual(other.premiumServiceStart)
            && premiumServiceSKU.isEqual(other.premiumServiceSKU)
            && lastSuccessfulCharge.isEqual(other.lastSuccessfulCharge)
            && lastFailedCharge.isEqual(other.lastFailedCharge)
            && lastFailedChargeReason.isEqual(other.lastFailedChargeReason)
            && nextPaymentDue.isEqual(other.nextPaymentDue)
            && premiumLockUntil.isEqual(other.premiumLockUntil)
            && updated.isEqual(other.updated)
            && premiumSubscriptionNumber.isEqual(other.premiumSubscriptionNumber)
            && lastRequestedCharge.isEqual(other.lastRequestedCharge)
            && currency.isEqual(other.currency)
            && unitPrice.isEqual(other.unitPrice)
            && businessId.isEqual(other.businessId)
            && businessName.isEqual(other.businessName)
            && businessRole.isEqual(other.businessRole)
            && unitDiscount.isEqual(other.unitDiscount)
            && nextChargeDate.isEqual(other.nextChargeDate)
            && availablePoints.isEqual(other.availablePoints)
        ;
    }

    bool operator!=(const Accounting & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<Timestamp> uploadLimitEnd MEMBER uploadLimitEnd)
    Q_PROPERTY(Optional<qint64> uploadLimitNextMonth MEMBER uploadLimitNextMonth)
    Q_PROPERTY(Optional<PremiumOrderStatus> premiumServiceStatus MEMBER premiumServiceStatus)
    Q_PROPERTY(Optional<QString> premiumOrderNumber MEMBER premiumOrderNumber)
    Q_PROPERTY(Optional<QString> premiumCommerceService MEMBER premiumCommerceService)
    Q_PROPERTY(Optional<Timestamp> premiumServiceStart MEMBER premiumServiceStart)
    Q_PROPERTY(Optional<QString> premiumServiceSKU MEMBER premiumServiceSKU)
    Q_PROPERTY(Optional<Timestamp> lastSuccessfulCharge MEMBER lastSuccessfulCharge)
    Q_PROPERTY(Optional<Timestamp> lastFailedCharge MEMBER lastFailedCharge)
    Q_PROPERTY(Optional<QString> lastFailedChargeReason MEMBER lastFailedChargeReason)
    Q_PROPERTY(Optional<Timestamp> nextPaymentDue MEMBER nextPaymentDue)
    Q_PROPERTY(Optional<Timestamp> premiumLockUntil MEMBER premiumLockUntil)
    Q_PROPERTY(Optional<Timestamp> updated MEMBER updated)
    Q_PROPERTY(Optional<QString> premiumSubscriptionNumber MEMBER premiumSubscriptionNumber)
    Q_PROPERTY(Optional<Timestamp> lastRequestedCharge MEMBER lastRequestedCharge)
    Q_PROPERTY(Optional<QString> currency MEMBER currency)
    Q_PROPERTY(Optional<qint32> unitPrice MEMBER unitPrice)
    Q_PROPERTY(Optional<qint32> businessId MEMBER businessId)
    Q_PROPERTY(Optional<QString> businessName MEMBER businessName)
    Q_PROPERTY(Optional<BusinessUserRole> businessRole MEMBER businessRole)
    Q_PROPERTY(Optional<qint32> unitDiscount MEMBER unitDiscount)
    Q_PROPERTY(Optional<Timestamp> nextChargeDate MEMBER nextChargeDate)
    Q_PROPERTY(Optional<qint32> availablePoints MEMBER availablePoints)
};

/**
 * This structure is used to provide information about an Evernote Business
 * membership, for members who are part of a business.
 *
 * */
struct QEVERCLOUD_EXPORT BusinessUserInfo: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The ID of the Evernote Business account that the user is a member of.
     <dt>businessName
       The human-readable name of the Evernote Business account that the user
           is a member of.
    */
    Optional<qint32> businessId;
    /** NOT DOCUMENTED */
    Optional<QString> businessName;
    /**
    The role of the user within the Evernote Business account that
           they are a member of.
    */
    Optional<BusinessUserRole> role;
    /**
    An e-mail address that will be used by the service in the context of your
           Evernote Business activities.  For example, this e-mail address will be used
           when you e-mail a business note, when you update notes in the account of
           your business, etc.  The business e-mail cannot be used for identification
           purposes such as for logging into the service.
    */
    Optional<QString> email;
    /**
    Last time the business user or business user attributes were updated.
    */
    Optional<Timestamp> updated;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const BusinessUserInfo & other) const
    {
        return businessId.isEqual(other.businessId)
            && businessName.isEqual(other.businessName)
            && role.isEqual(other.role)
            && email.isEqual(other.email)
            && updated.isEqual(other.updated)
        ;
    }

    bool operator!=(const BusinessUserInfo & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<qint32> businessId MEMBER businessId)
    Q_PROPERTY(Optional<QString> businessName MEMBER businessName)
    Q_PROPERTY(Optional<BusinessUserRole> role MEMBER role)
    Q_PROPERTY(Optional<QString> email MEMBER email)
    Q_PROPERTY(Optional<Timestamp> updated MEMBER updated)
};

/**
 * This structure is used to provide account limits that are in effect for this user.
 **/
struct QEVERCLOUD_EXPORT AccountLimits: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The number of emails of any type that can be sent by a user from the
           service per day.  If an email is sent to two different recipients, this
           counts as two emails.
    */
    Optional<qint32> userMailLimitDaily;
    /**
    Maximum total size of a Note that can be added.  The size of a note is
           calculated as:
           ENML content length (in Unicode characters) plus the sum of all resource
           sizes (in bytes).
    */
    Optional<qint64> noteSizeMax;
    /**
    Maximum size of a resource, in bytes
    */
    Optional<qint64> resourceSizeMax;
    /**
    Maximum number of linked notebooks per account.
    */
    Optional<qint32> userLinkedNotebookMax;
    /**
    The number of bytes that can be uploaded to the account
       in the current month.  For new notes that are created, this is the length
       of the note content (in Unicode characters) plus the size of each resource
       (in bytes).  For edited notes, this is the the difference between the old
       length and the new length (if this is greater than 0) plus the size of
       each new resource.
    */
    Optional<qint64> uploadLimit;
    /**
    Maximum number of Notes per user
    */
    Optional<qint32> userNoteCountMax;
    /**
    Maximum number of Notebooks per user
    */
    Optional<qint32> userNotebookCountMax;
    /**
    Maximum number of Tags per account
    */
    Optional<qint32> userTagCountMax;
    /**
    Maximum number of Tags per Note
    */
    Optional<qint32> noteTagCountMax;
    /**
    Maximum number of SavedSearches per account
    */
    Optional<qint32> userSavedSearchesMax;
    /**
    The maximum number of Resources per Note
    */
    Optional<qint32> noteResourceCountMax;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const AccountLimits & other) const
    {
        return userMailLimitDaily.isEqual(other.userMailLimitDaily)
            && noteSizeMax.isEqual(other.noteSizeMax)
            && resourceSizeMax.isEqual(other.resourceSizeMax)
            && userLinkedNotebookMax.isEqual(other.userLinkedNotebookMax)
            && uploadLimit.isEqual(other.uploadLimit)
            && userNoteCountMax.isEqual(other.userNoteCountMax)
            && userNotebookCountMax.isEqual(other.userNotebookCountMax)
            && userTagCountMax.isEqual(other.userTagCountMax)
            && noteTagCountMax.isEqual(other.noteTagCountMax)
            && userSavedSearchesMax.isEqual(other.userSavedSearchesMax)
            && noteResourceCountMax.isEqual(other.noteResourceCountMax)
        ;
    }

    bool operator!=(const AccountLimits & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<qint32> userMailLimitDaily MEMBER userMailLimitDaily)
    Q_PROPERTY(Optional<qint64> noteSizeMax MEMBER noteSizeMax)
    Q_PROPERTY(Optional<qint64> resourceSizeMax MEMBER resourceSizeMax)
    Q_PROPERTY(Optional<qint32> userLinkedNotebookMax MEMBER userLinkedNotebookMax)
    Q_PROPERTY(Optional<qint64> uploadLimit MEMBER uploadLimit)
    Q_PROPERTY(Optional<qint32> userNoteCountMax MEMBER userNoteCountMax)
    Q_PROPERTY(Optional<qint32> userNotebookCountMax MEMBER userNotebookCountMax)
    Q_PROPERTY(Optional<qint32> userTagCountMax MEMBER userTagCountMax)
    Q_PROPERTY(Optional<qint32> noteTagCountMax MEMBER noteTagCountMax)
    Q_PROPERTY(Optional<qint32> userSavedSearchesMax MEMBER userSavedSearchesMax)
    Q_PROPERTY(Optional<qint32> noteResourceCountMax MEMBER noteResourceCountMax)
};

/**
 * This represents the information about a single user account.
 **/
struct QEVERCLOUD_EXPORT User: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The unique numeric identifier for the account, which will not
       change for the lifetime of the account.
    */
    Optional<UserID> id;
    /**
    The name that uniquely identifies a single user account. This name
       may be presented by the user, along with their password, to log into
       their account.
       May only contain a-z, 0-9, or '-', and may not start or end with the '-'
       <br/>
       Length:  EDAM_USER_USERNAME_LEN_MIN - EDAM_USER_USERNAME_LEN_MAX
       <br/>
       Regex:  EDAM_USER_USERNAME_REGEX
    */
    Optional<QString> username;
    /**
    The email address registered for the user.  Must comply with
       RFC 2821 and RFC 2822.<br/>
       Third party applications that authenticate using OAuth do not have
       access to this field.
       Length:  EDAM_EMAIL_LEN_MIN - EDAM_EMAIL_LEN_MAX
       <br/>
       Regex:  EDAM_EMAIL_REGEX
    */
    Optional<QString> email;
    /**
    The printable name of the user, which may be a combination
       of given and family names.  This is used instead of separate "first"
       and "last" names due to variations in international name format/order.
       May not start or end with a whitespace character.  May contain any
       character but carriage return or newline (Unicode classes Zl and Zp).
       <br/>
       Length:  EDAM_USER_NAME_LEN_MIN - EDAM_USER_NAME_LEN_MAX
       <br/>
       Regex:  EDAM_USER_NAME_REGEX
    */
    Optional<QString> name;
    /**
    The zone ID for the user's default location.  If present,
       this may be used to localize the display of any timestamp for which no
       other timezone is available.
       The format must be encoded as a standard zone ID such as
       "America/Los_Angeles" or "GMT+08:00"
       <br/>
       Length:  EDAM_TIMEZONE_LEN_MIN - EDAM_TIMEZONE_LEN_MAX
       <br/>
       Regex:  EDAM_TIMEZONE_REGEX
    */
    Optional<QString> timezone;
    /** NOT DOCUMENTED */
    Optional<PrivilegeLevel> privilege;
    /**
    The level of service the user currently receives. This will always be populated
           for users retrieved from the Evernote service.
    */
    Optional<ServiceLevel> serviceLevel;
    /**
    The date and time when this user account was created in the
       service.
    */
    Optional<Timestamp> created;
    /**
    The date and time when this user account was last modified
       in the service.
    */
    Optional<Timestamp> updated;
    /**
    If the account has been deleted from the system (e.g. as
       the result of a legal request by the user), the date and time of the
       deletion will be represented here.  If not, this value will not be set.
    */
    Optional<Timestamp> deleted;
    /**
    If the user account is available for login and
       synchronization, this flag will be set to true.
    */
    Optional<bool> active;
    /**
    DEPRECATED - Client applications should have no need to use this field.
    */
    Optional<QString> shardId;
    /**
    If present, this will contain a list of the attributes
       for this user account.
    */
    Optional<UserAttributes> attributes;
    /**
    Bookkeeping information for the user's subscription.
    */
    Optional<Accounting> accounting;
    /**
    If present, this will contain a set of business information
       relating to the user's business membership.  If not present, the
       user is not currently part of a business.
    */
    Optional<BusinessUserInfo> businessUserInfo;
    /**
    The URL of the photo that represents this User. This field is filled in by the
       service and is read-only to clients. If <code>photoLastUpdated</code> is
       not set, this url will point to a placeholder user photo generated by the
       service.
    */
    Optional<QString> photoUrl;
    /**
    The time at which the photo at 'photoUrl' was last updated by this User. This
       field will be null if the User never set a profile photo. This field is filled in by
       the service and is read-only to clients.
    */
    Optional<Timestamp> photoLastUpdated;
    /**
    Account limits applicable for this user.
    */
    Optional<AccountLimits> accountLimits;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const User & other) const
    {
        return id.isEqual(other.id)
            && username.isEqual(other.username)
            && email.isEqual(other.email)
            && name.isEqual(other.name)
            && timezone.isEqual(other.timezone)
            && privilege.isEqual(other.privilege)
            && serviceLevel.isEqual(other.serviceLevel)
            && created.isEqual(other.created)
            && updated.isEqual(other.updated)
            && deleted.isEqual(other.deleted)
            && active.isEqual(other.active)
            && shardId.isEqual(other.shardId)
            && attributes.isEqual(other.attributes)
            && accounting.isEqual(other.accounting)
            && businessUserInfo.isEqual(other.businessUserInfo)
            && photoUrl.isEqual(other.photoUrl)
            && photoLastUpdated.isEqual(other.photoLastUpdated)
            && accountLimits.isEqual(other.accountLimits)
        ;
    }

    bool operator!=(const User & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<UserID> id MEMBER id)
    Q_PROPERTY(Optional<QString> username MEMBER username)
    Q_PROPERTY(Optional<QString> email MEMBER email)
    Q_PROPERTY(Optional<QString> name MEMBER name)
    Q_PROPERTY(Optional<QString> timezone MEMBER timezone)
    Q_PROPERTY(Optional<PrivilegeLevel> privilege MEMBER privilege)
    Q_PROPERTY(Optional<ServiceLevel> serviceLevel MEMBER serviceLevel)
    Q_PROPERTY(Optional<Timestamp> created MEMBER created)
    Q_PROPERTY(Optional<Timestamp> updated MEMBER updated)
    Q_PROPERTY(Optional<Timestamp> deleted MEMBER deleted)
    Q_PROPERTY(Optional<bool> active MEMBER active)
    Q_PROPERTY(Optional<QString> shardId MEMBER shardId)
    Q_PROPERTY(Optional<UserAttributes> attributes MEMBER attributes)
    Q_PROPERTY(Optional<Accounting> accounting MEMBER accounting)
    Q_PROPERTY(Optional<BusinessUserInfo> businessUserInfo MEMBER businessUserInfo)
    Q_PROPERTY(Optional<QString> photoUrl MEMBER photoUrl)
    Q_PROPERTY(Optional<Timestamp> photoLastUpdated MEMBER photoLastUpdated)
    Q_PROPERTY(Optional<AccountLimits> accountLimits MEMBER accountLimits)
};

/**
 * A structure that represents contact information. Note this does not necessarily correspond to
 * an Evernote user.
 *
 * */
struct QEVERCLOUD_EXPORT Contact: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The displayable name of this contact. This field is filled in by the service and
         is read-only to clients.
    */
    Optional<QString> name;
    /**
    A unique identifier for this ContactType.
    */
    Optional<QString> id;
    /**
    What service does this contact come from?
    */
    Optional<ContactType> type;
    /**
    A URL of a profile photo representing this Contact. This field is filled in by the
         service and is read-only to clients.
    */
    Optional<QString> photoUrl;
    /**
    timestamp when the profile photo at 'photoUrl' was last updated.
         This field will be null if the user has never set a profile photo.
         This field is filled in by the service and is read-only to clients.
    */
    Optional<Timestamp> photoLastUpdated;
    /**
    This field will only be filled by the service when it is giving a Contact record
         to a client, and that client does not normally have enough permission to send a
         new message to the person represented through this Contact. In that case, this
         whole Contact record could be used to send a new Message to the Contact, and the
         service will inspect this permit to confirm that operation was allowed.
    */
    Optional<QByteArray> messagingPermit;
    /**
    If this field is set, then this (whole) Contact record may be used in calls to
         sendMessage until this time. After that time, those calls may be rejected by the
         service if the caller does not have direct permission to initiate a message with
         the represented Evernote user.
    */
    Optional<Timestamp> messagingPermitExpires;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const Contact & other) const
    {
        return name.isEqual(other.name)
            && id.isEqual(other.id)
            && type.isEqual(other.type)
            && photoUrl.isEqual(other.photoUrl)
            && photoLastUpdated.isEqual(other.photoLastUpdated)
            && messagingPermit.isEqual(other.messagingPermit)
            && messagingPermitExpires.isEqual(other.messagingPermitExpires)
        ;
    }

    bool operator!=(const Contact & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> name MEMBER name)
    Q_PROPERTY(Optional<QString> id MEMBER id)
    Q_PROPERTY(Optional<ContactType> type MEMBER type)
    Q_PROPERTY(Optional<QString> photoUrl MEMBER photoUrl)
    Q_PROPERTY(Optional<Timestamp> photoLastUpdated MEMBER photoLastUpdated)
    Q_PROPERTY(Optional<QByteArray> messagingPermit MEMBER messagingPermit)
    Q_PROPERTY(Optional<Timestamp> messagingPermitExpires MEMBER messagingPermitExpires)
};

/**
 * An object that represents the relationship between a Contact that possibly
 * belongs to an Evernote User.
 *
 * */
struct QEVERCLOUD_EXPORT Identity: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The unique identifier for this mapping.
    */
    IdentityID id = 0;
    /** NOT DOCUMENTED */
    Optional<Contact> contact;
    /**
    The Evernote User id that is connected to the Contact. May be unset
          if this identity has not yet been claimed, or the caller is not
          connected to this identity.
    */
    Optional<UserID> userId;
    /**
    Indicates that the contact for this identity is no longer active and
      should not be used when creating new threads using Destination.recipients,
      unless you know of another Identity instance with the same contact information
      that is active.  If you are connected to the user (see userConnected), you
      can still create threads using their Evernote-type contact.
    */
    Optional<bool> deactivated;
    /**
    Does this Identity belong to someone who is in the same business as the
          caller?
    */
    Optional<bool> sameBusiness;
    /**
    Has the caller blocked the Evernote user this Identity represents?
    */
    Optional<bool> blocked;
    /**
    Indicates that the caller is "connected" to the user of this
      identity via this identity.  When you have a connection via an
      identity, you should always create new threads using the
      Evernote-type contact (see ContactType) using the userId field
      from a connected Identity.  On the Evernote service, the
      Evernote-type contact is the most durable. Phone numbers and
      e-mail addresses can get re-assigned but your Evernote account
      user ID will remain the same.  A connection exists when both of
      you are in the same business or the user has replied to a thread
      that you are on.  When connected, you will also get to see more
      information about the user who has claimed the identity.  Note
      that you are never connected to yourself since you won't be
      sending messages to yourself, but you will obviously see your own
      profile information.
    */
    Optional<bool> userConnected;
    /**
    A server-assigned sequence number for the events in the messages
      subsystem.
    */
    Optional<MessageEventID> eventId;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const Identity & other) const
    {
        return (id == other.id)
            && contact.isEqual(other.contact)
            && userId.isEqual(other.userId)
            && deactivated.isEqual(other.deactivated)
            && sameBusiness.isEqual(other.sameBusiness)
            && blocked.isEqual(other.blocked)
            && userConnected.isEqual(other.userConnected)
            && eventId.isEqual(other.eventId)
        ;
    }

    bool operator!=(const Identity & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(IdentityID id MEMBER id)
    Q_PROPERTY(Optional<Contact> contact MEMBER contact)
    Q_PROPERTY(Optional<UserID> userId MEMBER userId)
    Q_PROPERTY(Optional<bool> deactivated MEMBER deactivated)
    Q_PROPERTY(Optional<bool> sameBusiness MEMBER sameBusiness)
    Q_PROPERTY(Optional<bool> blocked MEMBER blocked)
    Q_PROPERTY(Optional<bool> userConnected MEMBER userConnected)
    Q_PROPERTY(Optional<MessageEventID> eventId MEMBER eventId)
};

/**
 * A tag within a user's account is a unique name which may be organized
 * a simple hierarchy.
 **/
struct QEVERCLOUD_EXPORT Tag: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The unique identifier of this tag. Will be set by the service,
       so may be omitted by the client when creating the Tag.
       <br/>
       Length:  EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
       <br/>
       Regex:  EDAM_GUID_REGEX
    */
    Optional<Guid> guid;
    /**
    A sequence of characters representing the tag's identifier.
       Case is preserved, but is ignored for comparisons.
       This means that an account may only have one tag with a given name, via
       case-insensitive comparison, so an account may not have both "food" and
       "Food" tags.
       May not contain a comma (','), and may not begin or end with a space.
       <br/>
       Length:  EDAM_TAG_NAME_LEN_MIN - EDAM_TAG_NAME_LEN_MAX
       <br/>
       Regex:  EDAM_TAG_NAME_REGEX
    */
    Optional<QString> name;
    /**
    If this is set, then this is the GUID of the tag that
       holds this tag within the tag organizational hierarchy.  If this is
       not set, then the tag has no parent and it is a "top level" tag.
       Cycles are not allowed (e.g. a->parent->parent == a) and will be
       rejected by the service.
       <br/>
       Length:  EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
       <br/>
       Regex:  EDAM_GUID_REGEX
    */
    Optional<Guid> parentGuid;
    /**
    A number identifying the last transaction to
       modify the state of this object.  The USN values are sequential within an
       account, and can be used to compare the order of modifications within the
       service.
    */
    Optional<qint32> updateSequenceNum;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const Tag & other) const
    {
        return guid.isEqual(other.guid)
            && name.isEqual(other.name)
            && parentGuid.isEqual(other.parentGuid)
            && updateSequenceNum.isEqual(other.updateSequenceNum)
        ;
    }

    bool operator!=(const Tag & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<Guid> guid MEMBER guid)
    Q_PROPERTY(Optional<QString> name MEMBER name)
    Q_PROPERTY(Optional<Guid> parentGuid MEMBER parentGuid)
    Q_PROPERTY(Optional<qint32> updateSequenceNum MEMBER updateSequenceNum)
};

/**
 * A structure that wraps a map of name/value pairs whose values are not
 * always present in the structure in order to reduce space when obtaining
 * batches of entities that contain the map.
 *
 * When the server provides the client with a LazyMap, it will fill in either
 * the keysOnly field or the fullMap field, but never both, based on the API
 * and parameters.
 *
 * When a client provides a LazyMap to the server as part of an update to
 * an object, the server will only update the LazyMap if the fullMap field is
 * set. If the fullMap field is not set, the server will not make any changes
 * to the map.
 *
 * Check the API documentation of the individual calls involving the LazyMap
 * for full details including the constraints of the names and values of the
 * map.
 *
 * */
struct QEVERCLOUD_EXPORT LazyMap: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The set of keys for the map.  This field is ignored by the
           server when set.
    */
    Optional<QSet<QString>> keysOnly;
    /**
    The complete map, including all keys and values.
    */
    Optional<QMap<QString, QString>> fullMap;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const LazyMap & other) const
    {
        return keysOnly.isEqual(other.keysOnly)
            && fullMap.isEqual(other.fullMap)
        ;
    }

    bool operator!=(const LazyMap & other) const
    {
        return !(*this == other);
    }

    using FullMap = QMap<QString, QString>;

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QSet<QString>> keysOnly MEMBER keysOnly)
    Q_PROPERTY(Optional<FullMap> fullMap MEMBER fullMap)
};

/**
 * Structure holding the optional attributes of a Resource
 * */
struct QEVERCLOUD_EXPORT ResourceAttributes: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    the original location where the resource was hosted
       <br/>
        Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    Optional<QString> sourceURL;
    /**
    the date and time that is associated with this resource
       (e.g. the time embedded in an image from a digital camera with a clock)
    */
    Optional<Timestamp> timestamp;
    /**
    the latitude where the resource was captured
    */
    Optional<double> latitude;
    /**
    the longitude where the resource was captured
    */
    Optional<double> longitude;
    /**
    the altitude where the resource was captured
    */
    Optional<double> altitude;
    /**
    information about an image's camera, e.g. as embedded in
       the image's EXIF data
       <br/>
       Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    Optional<QString> cameraMake;
    /**
    information about an image's camera, e.g. as embedded
       in the image's EXIF data
       <br/>
       Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    Optional<QString> cameraModel;
    /**
    if true, then the original client that submitted
       the resource plans to submit the recognition index for this resource at a
       later time.
    */
    Optional<bool> clientWillIndex;
    /**
    DEPRECATED - this field is no longer set by the service, so should
         be ignored.
    */
    Optional<QString> recoType;
    /**
    if the resource came from a source that provided an
       explicit file name, the original name will be stored here.  Many resources
       come from unnamed sources, so this will not always be set.
    */
    Optional<QString> fileName;
    /**
    this will be true if the resource should be displayed as an attachment,
       or false if the resource should be displayed inline (if possible).
    */
    Optional<bool> attachment;
    /**
    Provides a location for applications to store a relatively small
     (4kb) blob of data associated with a Resource that is not visible to the user
     and that is opaque to the Evernote service. A single application may use at most
     one entry in this map, using its API consumer key as the map key. See the
     documentation for LazyMap for a description of when the actual map values
     are returned by the service.
     <p>To safely add or modify your application's entry in the map, use
     NoteStore.setResourceApplicationDataEntry. To safely remove your application's
     entry from the map, use NoteStore.unsetResourceApplicationDataEntry.</p>
     Minimum length of a name (key): EDAM_APPLICATIONDATA_NAME_LEN_MIN
     <br/>
     Sum max size of key and value: EDAM_APPLICATIONDATA_ENTRY_LEN_MAX
     <br/>
     Syntax regex for name (key): EDAM_APPLICATIONDATA_NAME_REGEX
    */
    Optional<LazyMap> applicationData;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const ResourceAttributes & other) const
    {
        return sourceURL.isEqual(other.sourceURL)
            && timestamp.isEqual(other.timestamp)
            && latitude.isEqual(other.latitude)
            && longitude.isEqual(other.longitude)
            && altitude.isEqual(other.altitude)
            && cameraMake.isEqual(other.cameraMake)
            && cameraModel.isEqual(other.cameraModel)
            && clientWillIndex.isEqual(other.clientWillIndex)
            && recoType.isEqual(other.recoType)
            && fileName.isEqual(other.fileName)
            && attachment.isEqual(other.attachment)
            && applicationData.isEqual(other.applicationData)
        ;
    }

    bool operator!=(const ResourceAttributes & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> sourceURL MEMBER sourceURL)
    Q_PROPERTY(Optional<Timestamp> timestamp MEMBER timestamp)
    Q_PROPERTY(Optional<double> latitude MEMBER latitude)
    Q_PROPERTY(Optional<double> longitude MEMBER longitude)
    Q_PROPERTY(Optional<double> altitude MEMBER altitude)
    Q_PROPERTY(Optional<QString> cameraMake MEMBER cameraMake)
    Q_PROPERTY(Optional<QString> cameraModel MEMBER cameraModel)
    Q_PROPERTY(Optional<bool> clientWillIndex MEMBER clientWillIndex)
    Q_PROPERTY(Optional<QString> recoType MEMBER recoType)
    Q_PROPERTY(Optional<QString> fileName MEMBER fileName)
    Q_PROPERTY(Optional<bool> attachment MEMBER attachment)
    Q_PROPERTY(Optional<LazyMap> applicationData MEMBER applicationData)
};

/**
 * Every media file that is embedded or attached to a note is represented
 * through a Resource entry.
 * */
struct QEVERCLOUD_EXPORT Resource: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The unique identifier of this resource.  Will be set whenever
       a resource is retrieved from the service, but may be null when a client
       is creating a resource.
       <br/>
       Length:  EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
       <br/>
       Regex:  EDAM_GUID_REGEX
    */
    Optional<Guid> guid;
    /**
    The unique identifier of the Note that holds this
       Resource. Will be set whenever the resource is retrieved from the service,
       but may be null when a client is creating a resource.
       <br/>
       Length:  EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
       <br/>
       Regex:  EDAM_GUID_REGEX
    */
    Optional<Guid> noteGuid;
    /**
    The contents of the resource.
       Maximum length:  The data.body is limited to EDAM_RESOURCE_SIZE_MAX_FREE
       for free accounts and EDAM_RESOURCE_SIZE_MAX_PREMIUM for premium accounts.
    */
    Optional<Data> data;
    /**
    The MIME type for the embedded resource.  E.g. "image/gif"
       <br/>
       Length:  EDAM_MIME_LEN_MIN - EDAM_MIME_LEN_MAX
       <br/>
       Regex:  EDAM_MIME_REGEX
    */
    Optional<QString> mime;
    /**
    If set, this contains the display width of this resource, in
       pixels.
    */
    Optional<qint16> width;
    /**
    If set, this contains the display height of this resource,
       in pixels.
    */
    Optional<qint16> height;
    /**
    DEPRECATED: ignored.
    */
    Optional<qint16> duration;
    /**
    If the resource is active or not.
    */
    Optional<bool> active;
    /**
    If set, this will hold the encoded data that provides
       information on search and recognition within this resource.
    */
    Optional<Data> recognition;
    /**
    A list of the attributes for this resource.
    */
    Optional<ResourceAttributes> attributes;
    /**
    A number identifying the last transaction to
       modify the state of this object. The USN values are sequential within an
       account, and can be used to compare the order of modifications within the
       service.
    */
    Optional<qint32> updateSequenceNum;
    /**
    Some Resources may be assigned an alternate data format by the service
       which may be more appropriate for indexing or rendering than the original
       data provided by the user.  In these cases, the alternate data form will
       be available via this Data element.  If a Resource has no alternate form,
       this field will be unset.
    */
    Optional<Data> alternateData;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const Resource & other) const
    {
        return guid.isEqual(other.guid)
            && noteGuid.isEqual(other.noteGuid)
            && data.isEqual(other.data)
            && mime.isEqual(other.mime)
            && width.isEqual(other.width)
            && height.isEqual(other.height)
            && duration.isEqual(other.duration)
            && active.isEqual(other.active)
            && recognition.isEqual(other.recognition)
            && attributes.isEqual(other.attributes)
            && updateSequenceNum.isEqual(other.updateSequenceNum)
            && alternateData.isEqual(other.alternateData)
        ;
    }

    bool operator!=(const Resource & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<Guid> guid MEMBER guid)
    Q_PROPERTY(Optional<Guid> noteGuid MEMBER noteGuid)
    Q_PROPERTY(Optional<Data> data MEMBER data)
    Q_PROPERTY(Optional<QString> mime MEMBER mime)
    Q_PROPERTY(Optional<qint16> width MEMBER width)
    Q_PROPERTY(Optional<qint16> height MEMBER height)
    Q_PROPERTY(Optional<qint16> duration MEMBER duration)
    Q_PROPERTY(Optional<bool> active MEMBER active)
    Q_PROPERTY(Optional<Data> recognition MEMBER recognition)
    Q_PROPERTY(Optional<ResourceAttributes> attributes MEMBER attributes)
    Q_PROPERTY(Optional<qint32> updateSequenceNum MEMBER updateSequenceNum)
    Q_PROPERTY(Optional<Data> alternateData MEMBER alternateData)
};

/**
 * The list of optional attributes that can be stored on a note.
 * */
struct QEVERCLOUD_EXPORT NoteAttributes: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    time that the note refers to
    */
    Optional<Timestamp> subjectDate;
    /**
    the latitude where the note was taken
    */
    Optional<double> latitude;
    /**
    the longitude where the note was taken
    */
    Optional<double> longitude;
    /**
    the altitude where the note was taken
    */
    Optional<double> altitude;
    /**
    the author of the content of the note
       <br/>
       Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    Optional<QString> author;
    /**
    the method that the note was added to the account, if the
       note wasn't directly authored in an Evernote desktop client.
       <br/>
       Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    Optional<QString> source;
    /**
    the original location where the resource was hosted. For web clips,
       this will be the URL of the page that was clipped.
       <br/>
       Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    Optional<QString> sourceURL;
    /**
    an identifying string for the application that
       created this note.  This string does not have a guaranteed syntax or
       structure -- it is intended for human inspection and tracking.
       <br/>
       Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    Optional<QString> sourceApplication;
    /**
    The date and time when this note was directly shared via its own URL.
      This is only set on notes that were individually shared - it is independent
      of any notebook-level sharing of the containing notebook. This field
      is treated as "read-only" for clients; the server will ignore changes
      to this field from an external client.
    */
    Optional<Timestamp> shareDate;
    /**
    The set of notes with this parameter set are considered
     "reminders" and are to be treated specially by clients to give them
     higher UI prominence within a notebook.  The value is used to sort
     the reminder notes within the notebook with higher values
     representing greater prominence.  Outside of the context of a
     notebook, the value of this parameter is undefined.  The value is
     not intended to be compared to the values of reminder notes in
     other notebooks.  In order to allow clients to place a note at a
     higher precedence than other notes, you should never set a value
     greater than the current time (as defined for a Timetstamp). To
     place a note at higher precedence than existing notes, set the
     value to the current time as defined for a timestamp (milliseconds
     since the epoch).  Synchronizing clients must remember the time when
     the update was performed, using the local clock on the client,
     and use that value when they later upload the note to the service.
     Clients must not set the reminderOrder to the reminderTime as the
     reminderTime could be in the future.  Those two fields are never
     intended to be related.  The correct value for reminderOrder field
     for new notes is the "current" time when the user indicated that
     the note is a reminder.  Clients may implement a separate
     "sort by date" feature to show notes ordered by reminderTime.
     Whenever a reminderDoneTime or reminderTime is set but a
     reminderOrder is not set, the server will fill in the current
     server time for the reminderOrder field.
    */
    Optional<qint64> reminderOrder;
    /**
    The date and time when a user dismissed/"marked done" the reminder
     on the note.  Users typically do not manually set this value directly
     as it is set to the time when the user dismissed/"marked done" the
     reminder.
    */
    Optional<Timestamp> reminderDoneTime;
    /**
    The date and time a user has selected to be reminded of the note.
     A note with this value set is known as a "reminder" and the user can
     be reminded, via e-mail or client-specific notifications, of the note
     when the time is reached or about to be reached.  When a user sets
     a reminder time on a note that has a reminder done time, and that
     reminder time is in the future, then the reminder done time should be
     cleared.  This should happen regardless of any existing reminder time
     that may have previously existed on the note.
    */
    Optional<Timestamp> reminderTime;
    /**
    Allows the user to assign a human-readable location name associated
     with a note. Users may assign values like 'Home' and 'Work'. Place
     names may also be populated with values from geonames database
     (e.g., a restaurant name). Applications are encouraged to normalize values
     so that grouping values by place name provides a useful result. Applications
     MUST NOT automatically add place name values based on geolocation without
     confirmation from the user; that is, the value in this field should be
     more useful than a simple automated lookup based on the note's latitude
     and longitude.
    */
    Optional<QString> placeName;
    /**
    The class (or type) of note. This field is used to indicate to
     clients that special structured information is represented within
     the note such that special rules apply when making
     modifications. If contentClass is set and the client
     application does not specifically support the specified class,
     the client MUST treat the note as read-only. In this case, the
     client MAY modify the note's notebook and tags via the
     Note.notebookGuid and Note.tagGuids fields.  The client MAY also
     modify the reminderOrder field as well as the reminderTime and
     reminderDoneTime fields.
     <p>Applications should set contentClass only when they are creating notes
     that contain structured information that needs to be maintained in order
     for the user to be able to use the note within that application.
     Setting contentClass makes a note read-only in other applications, so
     there is a trade-off when an application chooses to use contentClass.
     Applications that set contentClass when creating notes must use a contentClass
     string of the form <i>CompanyName.ApplicationName</i> to ensure uniqueness.</p>
     Length restrictions: EDAM_NOTE_CONTENT_CLASS_LEN_MIN, EDAM_NOTE_CONTENT_CLASS_LEN_MAX
     <br/>
     Regex: EDAM_NOTE_CONTENT_CLASS_REGEX
    */
    Optional<QString> contentClass;
    /**
    Provides a location for applications to store a relatively small
     (4kb) blob of data that is not meant to be visible to the user and
     that is opaque to the Evernote service. A single application may use at most
     one entry in this map, using its API consumer key as the map key. See the
     documentation for LazyMap for a description of when the actual map values
     are returned by the service.
     <p>To safely add or modify your application's entry in the map, use
     NoteStore.setNoteApplicationDataEntry. To safely remove your application's
     entry from the map, use NoteStore.unsetNoteApplicationDataEntry.</p>
     Minimum length of a name (key): EDAM_APPLICATIONDATA_NAME_LEN_MIN
     <br/>
     Sum max size of key and value: EDAM_APPLICATIONDATA_ENTRY_LEN_MAX
     <br/>
     Syntax regex for name (key): EDAM_APPLICATIONDATA_NAME_REGEX
    */
    Optional<LazyMap> applicationData;
    /**
    An indication of who made the last change to the note.  If you are
     accessing the note via a shared notebook to which you have modification
     rights, or if you are the owner of the notebook to which the note belongs,
     then you have access to the value.  In this case, the value will be
     unset if the owner of the notebook containing the note was the last to
     make the modification, else it will be a string describing the
     guest who made the last edit.  If you do not have access to this value,
     it will be left unset.  This field is read-only by clients.  The server
     will ignore all values set by clients into this field.
    */
    Optional<QString> lastEditedBy;
    /**
    A map of classifications applied to the note by clients or by the
     Evernote service. The key is the string name of the classification type,
     and the value is a constant that begins with CLASSIFICATION_.
    */
    Optional<QMap<QString, QString>> classifications;
    /**
    The numeric user ID of the user who originally created the note.
    */
    Optional<UserID> creatorId;
    /**
    The numeric user ID of the user described in lastEditedBy.
    */
    Optional<UserID> lastEditorId;
    /**
    When this flag is set on a business note, any user in that business
     may view the note if they request it by GUID. This field is read-only by
     clients. The server will ignore all values set by clients into this field.
    
     To share a note with the business, use NoteStore.shareNoteWithBusiness and
     to stop sharing a note with the business, use NoteStore.stopSharingNoteWithBusiness.
    */
    Optional<bool> sharedWithBusiness;
    /**
    If set, this specifies the GUID of a note that caused a sync conflict
     resulting in the creation of a duplicate note. The duplicated note contains
     the user's changes that could not be applied as a result of the sync conflict,
     and uses the conflictSourceNoteGuid field to specify the note that caused the
     conflict. This allows clients to provide a customized user experience for note
     conflicts.
    */
    Optional<Guid> conflictSourceNoteGuid;
    /**
    If set, this specifies that the note's title was automatically generated
     and indicates the likelihood that the generated title is useful for display to
     the user. If not set, the note's title was manually entered by the user.
    
     Clients MUST set this attribute to one of the following values when the
     corresponding note's title was not manually entered by the user:
     EDAM_NOTE_TITLE_QUALITY_UNTITLED, EDAM_NOTE_TITLE_QUALITY_LOW,
     EDAM_NOTE_TITLE_QUALITY_MEDIUM or EDAM_NOTE_TITLE_QUALITY_HIGH.
    
     When a user edits a note's title, clients MUST unset this value.
    */
    Optional<qint32> noteTitleQuality;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NoteAttributes & other) const
    {
        return subjectDate.isEqual(other.subjectDate)
            && latitude.isEqual(other.latitude)
            && longitude.isEqual(other.longitude)
            && altitude.isEqual(other.altitude)
            && author.isEqual(other.author)
            && source.isEqual(other.source)
            && sourceURL.isEqual(other.sourceURL)
            && sourceApplication.isEqual(other.sourceApplication)
            && shareDate.isEqual(other.shareDate)
            && reminderOrder.isEqual(other.reminderOrder)
            && reminderDoneTime.isEqual(other.reminderDoneTime)
            && reminderTime.isEqual(other.reminderTime)
            && placeName.isEqual(other.placeName)
            && contentClass.isEqual(other.contentClass)
            && applicationData.isEqual(other.applicationData)
            && lastEditedBy.isEqual(other.lastEditedBy)
            && classifications.isEqual(other.classifications)
            && creatorId.isEqual(other.creatorId)
            && lastEditorId.isEqual(other.lastEditorId)
            && sharedWithBusiness.isEqual(other.sharedWithBusiness)
            && conflictSourceNoteGuid.isEqual(other.conflictSourceNoteGuid)
            && noteTitleQuality.isEqual(other.noteTitleQuality)
        ;
    }

    bool operator!=(const NoteAttributes & other) const
    {
        return !(*this == other);
    }

    using Classifications = QMap<QString, QString>;

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<Timestamp> subjectDate MEMBER subjectDate)
    Q_PROPERTY(Optional<double> latitude MEMBER latitude)
    Q_PROPERTY(Optional<double> longitude MEMBER longitude)
    Q_PROPERTY(Optional<double> altitude MEMBER altitude)
    Q_PROPERTY(Optional<QString> author MEMBER author)
    Q_PROPERTY(Optional<QString> source MEMBER source)
    Q_PROPERTY(Optional<QString> sourceURL MEMBER sourceURL)
    Q_PROPERTY(Optional<QString> sourceApplication MEMBER sourceApplication)
    Q_PROPERTY(Optional<Timestamp> shareDate MEMBER shareDate)
    Q_PROPERTY(Optional<qint64> reminderOrder MEMBER reminderOrder)
    Q_PROPERTY(Optional<Timestamp> reminderDoneTime MEMBER reminderDoneTime)
    Q_PROPERTY(Optional<Timestamp> reminderTime MEMBER reminderTime)
    Q_PROPERTY(Optional<QString> placeName MEMBER placeName)
    Q_PROPERTY(Optional<QString> contentClass MEMBER contentClass)
    Q_PROPERTY(Optional<LazyMap> applicationData MEMBER applicationData)
    Q_PROPERTY(Optional<QString> lastEditedBy MEMBER lastEditedBy)
    Q_PROPERTY(Optional<Classifications> classifications MEMBER classifications)
    Q_PROPERTY(Optional<UserID> creatorId MEMBER creatorId)
    Q_PROPERTY(Optional<UserID> lastEditorId MEMBER lastEditorId)
    Q_PROPERTY(Optional<bool> sharedWithBusiness MEMBER sharedWithBusiness)
    Q_PROPERTY(Optional<Guid> conflictSourceNoteGuid MEMBER conflictSourceNoteGuid)
    Q_PROPERTY(Optional<qint32> noteTitleQuality MEMBER noteTitleQuality)
};

/**
 * Represents a relationship between a note and a single share invitation recipient. The recipient
 * is identified via an Identity, and has a given privilege that specifies what actions they may
 * take on the note.
 *
 * */
struct QEVERCLOUD_EXPORT SharedNote: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The user ID of the user who shared the note with the recipient.
    */
    Optional<UserID> sharerUserID;
    /**
    The identity of the recipient of the share. For a given note, there may be only one
         SharedNote per recipient identity. Only recipientIdentity.id is guaranteed to be set.
         Other fields on the Identity may or my not be set based on the requesting user's
         relationship with the recipient.
    */
    Optional<Identity> recipientIdentity;
    /**
    The privilege level that the share grants to the recipient.
    */
    Optional<SharedNotePrivilegeLevel> privilege;
    /**
    The time at which the share was created.
    */
    Optional<Timestamp> serviceCreated;
    /**
    The time at which the share was last updated.
    */
    Optional<Timestamp> serviceUpdated;
    /**
    The time at which the share was assigned to a specific recipient user ID.
    */
    Optional<Timestamp> serviceAssigned;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const SharedNote & other) const
    {
        return sharerUserID.isEqual(other.sharerUserID)
            && recipientIdentity.isEqual(other.recipientIdentity)
            && privilege.isEqual(other.privilege)
            && serviceCreated.isEqual(other.serviceCreated)
            && serviceUpdated.isEqual(other.serviceUpdated)
            && serviceAssigned.isEqual(other.serviceAssigned)
        ;
    }

    bool operator!=(const SharedNote & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<UserID> sharerUserID MEMBER sharerUserID)
    Q_PROPERTY(Optional<Identity> recipientIdentity MEMBER recipientIdentity)
    Q_PROPERTY(Optional<SharedNotePrivilegeLevel> privilege MEMBER privilege)
    Q_PROPERTY(Optional<Timestamp> serviceCreated MEMBER serviceCreated)
    Q_PROPERTY(Optional<Timestamp> serviceUpdated MEMBER serviceUpdated)
    Q_PROPERTY(Optional<Timestamp> serviceAssigned MEMBER serviceAssigned)
};

/**
 * This structure captures information about the operations that cannot be performed on a given
 * note that has been shared with a recipient via a SharedNote. The following operations are
 * <b>never</b> allowed based on SharedNotes, and as such are left out of the NoteRestrictions
 * structure for brevity:
 *
 * <ul>
 *   <li>Expunging a note (NoteStore.expungeNote)</li>
 *   <li>Moving a note to the trash (Note.active)</li>
 *   <li>Updating a note's notebook (Note.notebookGuid)</li>
 *   <li>Updating a note's tags (Note.tagGuids, Note.tagNames)</li>
 *   <li>Updating a note's attributes (Note.attributes)</li>
 *   <li>Sharing a note with the business (NoteStore.shareNoteWithBusiness</li>
 *   <li>Getting a note's version history (NoteStore.listNoteVersions,
 *     NoteStore.getNoteVersion)</li>
 * </ul>
 *
 * When a client has permission to update a note's title or content, it may also update the
 * Note.updated timestamp.
 *
 * <b>This structure reflects only the privileges / restrictions conveyed by the SharedNote.</b>
 * It does not incorporate privileges conveyed by a potential SharedNotebook to the same
 * recipient. As such, the actual permissions that the recipient has on the note may differ from
 * the permissions expressed in this structure.
 *
 * For example, consider a user with read-only access to a shared notebook, and a read-write share
 * of a specific note in the notebook. The note restrictions would contain noUpdateTitle = false,
 * while the notebook restrictions would contain noUpdateNotes = true. In this case, the user is
 * allowed to update the note title based on the note restrictions.
 *
 * Alternatively, consider a user with read-write access to a shared notebook, and a read-only
 * share of a specific note in that notebook. The note restrictions would contain
 * noUpdateTitle = true, while the notebook restrictions would contain noUpdateNotes = false. In
 * this case, the user would have full edit permissions on the note based on the notebook
 * restrictions.
 *
 * */
struct QEVERCLOUD_EXPORT NoteRestrictions: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The client may not update the note's title (Note.title).
    */
    Optional<bool> noUpdateTitle;
    /** NOT DOCUMENTED */
    Optional<bool> noUpdateContent;
    /**
    The client may not email the note (NoteStore.emailNote).
    */
    Optional<bool> noEmail;
    /**
    The client may not share the note with specific recipients
         (NoteStore.createOrUpdateSharedNotes).
    */
    Optional<bool> noShare;
    /**
    The client may not make the note public (NoteStore.shareNote).
    */
    Optional<bool> noSharePublicly;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NoteRestrictions & other) const
    {
        return noUpdateTitle.isEqual(other.noUpdateTitle)
            && noUpdateContent.isEqual(other.noUpdateContent)
            && noEmail.isEqual(other.noEmail)
            && noShare.isEqual(other.noShare)
            && noSharePublicly.isEqual(other.noSharePublicly)
        ;
    }

    bool operator!=(const NoteRestrictions & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<bool> noUpdateTitle MEMBER noUpdateTitle)
    Q_PROPERTY(Optional<bool> noUpdateContent MEMBER noUpdateContent)
    Q_PROPERTY(Optional<bool> noEmail MEMBER noEmail)
    Q_PROPERTY(Optional<bool> noShare MEMBER noShare)
    Q_PROPERTY(Optional<bool> noSharePublicly MEMBER noSharePublicly)
};

/**
 * Represents the owner's account related limits on a Note.
 * The field uploaded represents the total number of bytes that have been uploaded
 * to this account and is taken from the SyncState struct. All other fields
 * represent account related limits and are taken from the AccountLimits struct.
 * <p />
 * See SyncState and AccountLimits struct field definitions for more details.
 */
struct QEVERCLOUD_EXPORT NoteLimits: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /** NOT DOCUMENTED */
    Optional<qint32> noteResourceCountMax;
    /** NOT DOCUMENTED */
    Optional<qint64> uploadLimit;
    /** NOT DOCUMENTED */
    Optional<qint64> resourceSizeMax;
    /** NOT DOCUMENTED */
    Optional<qint64> noteSizeMax;
    /** NOT DOCUMENTED */
    Optional<qint64> uploaded;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NoteLimits & other) const
    {
        return noteResourceCountMax.isEqual(other.noteResourceCountMax)
            && uploadLimit.isEqual(other.uploadLimit)
            && resourceSizeMax.isEqual(other.resourceSizeMax)
            && noteSizeMax.isEqual(other.noteSizeMax)
            && uploaded.isEqual(other.uploaded)
        ;
    }

    bool operator!=(const NoteLimits & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<qint32> noteResourceCountMax MEMBER noteResourceCountMax)
    Q_PROPERTY(Optional<qint64> uploadLimit MEMBER uploadLimit)
    Q_PROPERTY(Optional<qint64> resourceSizeMax MEMBER resourceSizeMax)
    Q_PROPERTY(Optional<qint64> noteSizeMax MEMBER noteSizeMax)
    Q_PROPERTY(Optional<qint64> uploaded MEMBER uploaded)
};

/**
 * Represents a single note in the user's account.
 *
 * */
struct QEVERCLOUD_EXPORT Note: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The unique identifier of this note.  Will be set by the
       server, but will be omitted by clients calling NoteStore.createNote()
       <br/>
       Length:  EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
       <br/>
       Regex:  EDAM_GUID_REGEX
    */
    Optional<Guid> guid;
    /**
    The subject of the note.  Can't begin or end with a space.
       <br/>
       Length:  EDAM_NOTE_TITLE_LEN_MIN - EDAM_NOTE_TITLE_LEN_MAX
       <br/>
       Regex:  EDAM_NOTE_TITLE_REGEX
    */
    Optional<QString> title;
    /**
    The XHTML block that makes up the note.  This is
       the canonical form of the note's contents, so will include abstract
       Evernote tags for internal resource references.  A client may create
       a separate transformed version of this content for internal presentation,
       but the same canonical bytes should be used for transmission and
       comparison unless the user chooses to modify their content.
       <br/>
       Length:  EDAM_NOTE_CONTENT_LEN_MIN - EDAM_NOTE_CONTENT_LEN_MAX
    */
    Optional<QString> content;
    /**
    The binary MD5 checksum of the UTF-8 encoded content
       body. This will always be set by the server, but clients may choose to omit
       this when they submit a note with content.
       <br/>
       Length:  EDAM_HASH_LEN (exactly)
    */
    Optional<QByteArray> contentHash;
    /**
    The number of Unicode characters in the content of
       the note.  This will always be set by the service, but clients may choose
       to omit this value when they submit a Note.
    */
    Optional<qint32> contentLength;
    /**
    The date and time when the note was created in one of the
       clients.  In most cases, this will match the user's sense of when
       the note was created, and ordering between notes will be based on
       ordering of this field.  However, this is not a "reliable" timestamp
       if a client has an incorrect clock, so it cannot provide a true absolute
       ordering between notes.  Notes created directly through the service
       (e.g. via the web GUI) will have an absolutely ordered "created" value.
    */
    Optional<Timestamp> created;
    /**
    The date and time when the note was last modified in one of
       the clients.  In most cases, this will match the user's sense of when
       the note was modified, but this field may not be absolutely reliable
       due to the possibility of client clock errors.
    */
    Optional<Timestamp> updated;
    /**
    If present, the note is considered "deleted", and this
       stores the date and time when the note was deleted by one of the clients.
       In most cases, this will match the user's sense of when the note was
       deleted, but this field may be unreliable due to the possibility of
       client clock errors.
    */
    Optional<Timestamp> deleted;
    /**
    If the note is available for normal actions and viewing,
       this flag will be set to true.
    */
    Optional<bool> active;
    /**
    A number identifying the last transaction to
       modify the state of this note (including changes to the note's attributes
       or resources).  The USN values are sequential within an account,
       and can be used to compare the order of modifications within the service.
    */
    Optional<qint32> updateSequenceNum;
    /**
    The unique identifier of the notebook that contains
       this note.  If no notebookGuid is provided on a call to createNote(), the
       default notebook will be used instead.
       <br/>
       Length:  EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
       <br/>
       Regex:  EDAM_GUID_REGEX
    */
    Optional<QString> notebookGuid;
    /**
    A list of the GUID identifiers for tags that are applied to this note.
       This may be provided in a call to createNote() to unambiguously declare
       the tags that should be assigned to the new note.  Alternately, clients
       may pass the names of desired tags via the 'tagNames' field during
       note creation.
       If the list of tags are omitted on a call to createNote(), then
       the server will assume that no changes have been made to the resources.
       Maximum:  EDAM_NOTE_TAGS_MAX tags per note
    */
    Optional<QList<Guid>> tagGuids;
    /**
    The list of resources that are embedded within this note.
       If the list of resources are omitted on a call to updateNote(), then
       the server will assume that no changes have been made to the resources.
       The binary contents of the resources must be provided when the resource
       is first sent to the service, but it will be omitted by the service when
       the Note is returned in the future.
       Maximum:  EDAM_NOTE_RESOURCES_MAX resources per note
    */
    Optional<QList<Resource>> resources;
    /**
    A list of the attributes for this note.
       If the list of attributes are omitted on a call to updateNote(), then
       the server will assume that no changes have been made to the resources.
    */
    Optional<NoteAttributes> attributes;
    /**
    May be provided by clients during calls to createNote() as an
       alternative to providing the tagGuids of existing tags.  If any tagNames
       are provided during createNote(), these will be found, or created if they
       don't already exist.  Created tags will have no parent (they will be at
       the top level of the tag panel).
    */
    Optional<QStringList> tagNames;
    /**
    The list of recipients with whom this note has been shared. This field will be unset if
         the caller has access to the note via the containing notebook, but does not have activity
         feed permission for that notebook. This field is read-only. Clients may not make changes to
         a note's sharing state via this field.
    */
    Optional<QList<SharedNote>> sharedNotes;
    /**
    If this field is set, the user has note-level permissions that may differ from their
         notebook-level permissions. In this case, the restrictions structure specifies
         a set of restrictions limiting the actions that a user may take on the note based
         on their note-level permissions. If this field is unset, then there are no
         note-specific restrictions. However, a client may still be limited based on the user's
         notebook permissions.
    */
    Optional<NoteRestrictions> restrictions;
    /** NOT DOCUMENTED */
    Optional<NoteLimits> limits;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const Note & other) const
    {
        return guid.isEqual(other.guid)
            && title.isEqual(other.title)
            && content.isEqual(other.content)
            && contentHash.isEqual(other.contentHash)
            && contentLength.isEqual(other.contentLength)
            && created.isEqual(other.created)
            && updated.isEqual(other.updated)
            && deleted.isEqual(other.deleted)
            && active.isEqual(other.active)
            && updateSequenceNum.isEqual(other.updateSequenceNum)
            && notebookGuid.isEqual(other.notebookGuid)
            && tagGuids.isEqual(other.tagGuids)
            && resources.isEqual(other.resources)
            && attributes.isEqual(other.attributes)
            && tagNames.isEqual(other.tagNames)
            && sharedNotes.isEqual(other.sharedNotes)
            && restrictions.isEqual(other.restrictions)
            && limits.isEqual(other.limits)
        ;
    }

    bool operator!=(const Note & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<Guid> guid MEMBER guid)
    Q_PROPERTY(Optional<QString> title MEMBER title)
    Q_PROPERTY(Optional<QString> content MEMBER content)
    Q_PROPERTY(Optional<QByteArray> contentHash MEMBER contentHash)
    Q_PROPERTY(Optional<qint32> contentLength MEMBER contentLength)
    Q_PROPERTY(Optional<Timestamp> created MEMBER created)
    Q_PROPERTY(Optional<Timestamp> updated MEMBER updated)
    Q_PROPERTY(Optional<Timestamp> deleted MEMBER deleted)
    Q_PROPERTY(Optional<bool> active MEMBER active)
    Q_PROPERTY(Optional<qint32> updateSequenceNum MEMBER updateSequenceNum)
    Q_PROPERTY(Optional<QString> notebookGuid MEMBER notebookGuid)
    Q_PROPERTY(Optional<QList<Guid>> tagGuids MEMBER tagGuids)
    Q_PROPERTY(Optional<QList<Resource>> resources MEMBER resources)
    Q_PROPERTY(Optional<NoteAttributes> attributes MEMBER attributes)
    Q_PROPERTY(Optional<QStringList> tagNames MEMBER tagNames)
    Q_PROPERTY(Optional<QList<SharedNote>> sharedNotes MEMBER sharedNotes)
    Q_PROPERTY(Optional<NoteRestrictions> restrictions MEMBER restrictions)
    Q_PROPERTY(Optional<NoteLimits> limits MEMBER limits)
};

/**
 * If a Notebook has been opened to the public, the Notebook will have a
 * reference to one of these structures, which gives the location and optional
 * description of the externally-visible public Notebook.
 * */
struct QEVERCLOUD_EXPORT Publishing: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    If this field is present, then the notebook is published for
       mass consumption on the Internet under the provided URI, which is
       relative to a defined base publishing URI defined by the service.
       This field can only be modified via the web service GUI ... publishing
       cannot be modified via an offline client.
       <br/>
       Length:  EDAM_PUBLISHING_URI_LEN_MIN - EDAM_PUBLISHING_URI_LEN_MAX
       <br/>
       Regex:  EDAM_PUBLISHING_URI_REGEX
    */
    Optional<QString> uri;
    /**
    When the notes are publicly displayed, they will be sorted
       based on the requested criteria.
    */
    Optional<NoteSortOrder> order;
    /**
    If this is set to true, then the public notes will be
       displayed in ascending order (e.g. from oldest to newest).  Otherwise,
       the notes will be displayed in descending order (e.g. newest to oldest).
    */
    Optional<bool> ascending;
    /**
    This field may be used to provide a short
       description of the notebook, which may be displayed when (e.g.) the
       notebook is shown in a public view.  Can't begin or end with a space.
       <br/>
       Length:  EDAM_PUBLISHING_DESCRIPTION_LEN_MIN -
                EDAM_PUBLISHING_DESCRIPTION_LEN_MAX
       <br/>
       Regex:  EDAM_PUBLISHING_DESCRIPTION_REGEX
    */
    Optional<QString> publicDescription;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const Publishing & other) const
    {
        return uri.isEqual(other.uri)
            && order.isEqual(other.order)
            && ascending.isEqual(other.ascending)
            && publicDescription.isEqual(other.publicDescription)
        ;
    }

    bool operator!=(const Publishing & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> uri MEMBER uri)
    Q_PROPERTY(Optional<NoteSortOrder> order MEMBER order)
    Q_PROPERTY(Optional<bool> ascending MEMBER ascending)
    Q_PROPERTY(Optional<QString> publicDescription MEMBER publicDescription)
};

/**
 * If a Notebook contained in an Evernote Business account has been published
 * the to business library, the Notebook will have a reference to one of these
 * structures, which specifies how the Notebook will be represented in the
 * library.
 *
 * */
struct QEVERCLOUD_EXPORT BusinessNotebook: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    A short description of the notebook's content that will be displayed
           in the business library user interface. The description may not begin
           or end with whitespace.
       <br/>
       Length: EDAM_BUSINESS_NOTEBOOK_DESCRIPTION_LEN_MIN -
               EDAM_BUSINESS_NOTEBOOK_DESCRIPTION_LEN_MAX
       <br/>
       Regex:  EDAM_BUSINESS_NOTEBOOK_DESCRIPTION_REGEX
    */
    Optional<QString> notebookDescription;
    /**
    The privileges that will be granted to users who join the notebook through
           the business library.
    */
    Optional<SharedNotebookPrivilegeLevel> privilege;
    /**
    Whether the notebook should be "recommended" when displayed in the business
           library user interface.
    */
    Optional<bool> recommended;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const BusinessNotebook & other) const
    {
        return notebookDescription.isEqual(other.notebookDescription)
            && privilege.isEqual(other.privilege)
            && recommended.isEqual(other.recommended)
        ;
    }

    bool operator!=(const BusinessNotebook & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> notebookDescription MEMBER notebookDescription)
    Q_PROPERTY(Optional<SharedNotebookPrivilegeLevel> privilege MEMBER privilege)
    Q_PROPERTY(Optional<bool> recommended MEMBER recommended)
};

/**
 * A structure defining the scope of a SavedSearch.
 *
 * */
struct QEVERCLOUD_EXPORT SavedSearchScope: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The search should include notes from the account that contains the SavedSearch.
    */
    Optional<bool> includeAccount;
    /**
    The search should include notes within those shared notebooks
       that the user has joined that are NOT business notebooks.
    */
    Optional<bool> includePersonalLinkedNotebooks;
    /**
    The search should include notes within those shared notebooks
       that the user has joined that are business notebooks in the business that
       the user is currently a member of.
    */
    Optional<bool> includeBusinessLinkedNotebooks;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const SavedSearchScope & other) const
    {
        return includeAccount.isEqual(other.includeAccount)
            && includePersonalLinkedNotebooks.isEqual(other.includePersonalLinkedNotebooks)
            && includeBusinessLinkedNotebooks.isEqual(other.includeBusinessLinkedNotebooks)
        ;
    }

    bool operator!=(const SavedSearchScope & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<bool> includeAccount MEMBER includeAccount)
    Q_PROPERTY(Optional<bool> includePersonalLinkedNotebooks MEMBER includePersonalLinkedNotebooks)
    Q_PROPERTY(Optional<bool> includeBusinessLinkedNotebooks MEMBER includeBusinessLinkedNotebooks)
};

/**
 * A named search associated with the account that can be quickly re-used.
 * */
struct QEVERCLOUD_EXPORT SavedSearch: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The unique identifier of this search.  Will be set by the
       service, so may be omitted by the client when creating.
       <br/>
       Length:  EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
       <br/>
       Regex:  EDAM_GUID_REGEX
    */
    Optional<Guid> guid;
    /**
    The name of the saved search to display in the GUI.  The
       account may only contain one search with a given name (case-insensitive
       compare). Can't begin or end with a space.
       <br/>
       Length:  EDAM_SAVED_SEARCH_NAME_LEN_MIN - EDAM_SAVED_SEARCH_NAME_LEN_MAX
       <br/>
       Regex:  EDAM_SAVED_SEARCH_NAME_REGEX
    */
    Optional<QString> name;
    /**
    A string expressing the search to be performed.
       <br/>
       Length:  EDAM_SAVED_SEARCH_QUERY_LEN_MIN - EDAM_SAVED_SEARCH_QUERY_LEN_MAX
    */
    Optional<QString> query;
    /**
    The format of the query string, to determine how to parse
       and process it.
    */
    Optional<QueryFormat> format;
    /**
    A number identifying the last transaction to
       modify the state of this object.  The USN values are sequential within an
       account, and can be used to compare the order of modifications within the
       service.
    */
    Optional<qint32> updateSequenceNum;
    /**
    <p>Specifies the set of notes that should be included in the search, if
        possible.</p>
        <p>Clients are expected to search as much of the desired scope as possible,
        with the understanding that a given client may not be able to cover the full
        specified scope. For example, when executing a search that includes notes in both
        the owner's account and business notebooks, a mobile client may choose to only
        search within the user's account because it is not capable of searching both
        scopes simultaneously. When a search across multiple scopes is not possible,
        a client may choose which scope to search based on the current application
        context. If a client cannot search any of the desired scopes, it should refuse
        to execute the search.</p>
    */
    Optional<SavedSearchScope> scope;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const SavedSearch & other) const
    {
        return guid.isEqual(other.guid)
            && name.isEqual(other.name)
            && query.isEqual(other.query)
            && format.isEqual(other.format)
            && updateSequenceNum.isEqual(other.updateSequenceNum)
            && scope.isEqual(other.scope)
        ;
    }

    bool operator!=(const SavedSearch & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<Guid> guid MEMBER guid)
    Q_PROPERTY(Optional<QString> name MEMBER name)
    Q_PROPERTY(Optional<QString> query MEMBER query)
    Q_PROPERTY(Optional<QueryFormat> format MEMBER format)
    Q_PROPERTY(Optional<qint32> updateSequenceNum MEMBER updateSequenceNum)
    Q_PROPERTY(Optional<SavedSearchScope> scope MEMBER scope)
};

/**
 * Settings meant for the recipient of a shared notebook, such as
 * for indicating which types of notifications the recipient wishes
 * for reminders, etc.
 *
 * The reminderNotifyEmail and reminderNotifyInApp fields have a
 * 3-state read value but a 2-state write value.  On read, it is
 * possible to observe "unset", true, or false.  The initial state is
 * "unset".  When you choose to set a value, you may set it to either
 * true or false, but you cannot unset the value.  Once one of these
 * members has a true/false value, it will always have a true/false
 * value.
 *
 * */
struct QEVERCLOUD_EXPORT SharedNotebookRecipientSettings: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    Indicates that the user wishes to receive daily e-mail notifications
         for reminders associated with the notebook. This may be true only for
         business notebooks that belong to the business of which the user is a
         member. You may only set this value on a notebook in your business.
    */
    Optional<bool> reminderNotifyEmail;
    /**
    Indicates that the user wishes to receive notifications for
         reminders by applications that support providing such
         notifications.  The exact nature of the notification is defined
         by the individual applications.
    */
    Optional<bool> reminderNotifyInApp;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const SharedNotebookRecipientSettings & other) const
    {
        return reminderNotifyEmail.isEqual(other.reminderNotifyEmail)
            && reminderNotifyInApp.isEqual(other.reminderNotifyInApp)
        ;
    }

    bool operator!=(const SharedNotebookRecipientSettings & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<bool> reminderNotifyEmail MEMBER reminderNotifyEmail)
    Q_PROPERTY(Optional<bool> reminderNotifyInApp MEMBER reminderNotifyInApp)
};

/**
 * Settings meant for the recipient of a notebook share.
 *
 * Some of these fields have a 3-state read value but a 2-state write value.
 * On read, it is possible to observe "unset", true, or false. The initial
 * state is "unset". When you choose to set a value, you may set it to either
 * true or false, but you cannot unset the value. Once one of these members
 * has a true/false value, it will always have a true/false value.
 *
 * */
struct QEVERCLOUD_EXPORT NotebookRecipientSettings: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    Indicates that the user wishes to receive daily e-mail notifications
         for reminders associated with the notebook. This may be
         true only for business notebooks that belong to the business of
         which the user is a member. You may only set this value on a
         notebook in your business. This value will initially be unset.
    */
    Optional<bool> reminderNotifyEmail;
    /**
    Indicates that the user wishes to receive notifications for
         reminders by applications that support providing such
         notifications.  The exact nature of the notification is defined
         by the individual applications. This value will initially be unset.
    */
    Optional<bool> reminderNotifyInApp;
    /**
    DEPRECATED: Use recipientStatus instead.
         The notebook is on the recipient's notebook list (formerly, we would say
         that the recipient has "joined" the notebook)
    */
    Optional<bool> inMyList;
    /**
    The stack the recipient has put this notebook into. See Notebook.stack
     for a definition. Every recipient can have their own stack value for the same
     notebook.
    */
    Optional<QString> stack;
    /**
    The notebook is on/off the recipient's notebook list (formerly, we would say
         that the recipient has "joined" the notebook) and perhaps also their
         default notebook
    */
    Optional<RecipientStatus> recipientStatus;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NotebookRecipientSettings & other) const
    {
        return reminderNotifyEmail.isEqual(other.reminderNotifyEmail)
            && reminderNotifyInApp.isEqual(other.reminderNotifyInApp)
            && inMyList.isEqual(other.inMyList)
            && stack.isEqual(other.stack)
            && recipientStatus.isEqual(other.recipientStatus)
        ;
    }

    bool operator!=(const NotebookRecipientSettings & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<bool> reminderNotifyEmail MEMBER reminderNotifyEmail)
    Q_PROPERTY(Optional<bool> reminderNotifyInApp MEMBER reminderNotifyInApp)
    Q_PROPERTY(Optional<bool> inMyList MEMBER inMyList)
    Q_PROPERTY(Optional<QString> stack MEMBER stack)
    Q_PROPERTY(Optional<RecipientStatus> recipientStatus MEMBER recipientStatus)
};

/**
 * Shared notebooks represent a relationship between a notebook and a single
 * share invitation recipient.
 * */
struct QEVERCLOUD_EXPORT SharedNotebook: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The primary identifier of the share, which is not globally unique.
    */
    Optional<qint64> id;
    /**
    The user id of the owner of the notebook.
    */
    Optional<UserID> userId;
    /**
    The GUID of the notebook that has been shared.
    */
    Optional<Guid> notebookGuid;
    /**
    A string containing a display name for the recipient of the share. This may
         be an email address, a phone number, a full name, or some other descriptive
         string This field is read-only to clients. It will be filled in by the service
         when returning shared notebooks.
    */
    Optional<QString> email;
    /**
    The IdentityID of the share recipient. If present, only the user who has
         claimed that identity may access this share.
    */
    Optional<IdentityID> recipientIdentityId;
    /**
    DEPRECATED
    */
    Optional<bool> notebookModifiable;
    /**
    The date that the owner first created the share with the specific email
       address.
    */
    Optional<Timestamp> serviceCreated;
    /**
    The date the shared notebook was last updated on the service.  This
         will be updated when authenticateToSharedNotebook is called the first
         time with a shared notebook (i.e. when the username is bound to that
         shared notebook), and also when the SharedNotebook privilege is updated
         as part of a shareNotebook(...) call, as well as on any calls to
         updateSharedNotebook(...).
    */
    Optional<Timestamp> serviceUpdated;
    /**
    An immutable, opaque string that acts as a globally unique
         identifier for this shared notebook record.  You can use this field to
         match linked notebook and shared notebook records as well as to
         create new LinkedNotebook records.  This field replaces the deprecated
         shareKey field.
    */
    Optional<QString> globalId;
    /**
    DEPRECATED. The username of the user who can access this share. This
         value is read-only to clients. It will be filled in by the service when
         returning shared notebooks.
    */
    Optional<QString> username;
    /**
    The privilege level granted to the notebook, activity stream, and
         invitations.  See the corresponding enumeration for details.
    */
    Optional<SharedNotebookPrivilegeLevel> privilege;
    /**
    Settings intended for use only by the recipient of this shared
         notebook.  You should skip setting this value unless you want
         to change the value contained inside the structure, and only if
         you are the recipient.
    */
    Optional<SharedNotebookRecipientSettings> recipientSettings;
    /**
    The user id of the user who shared a notebook via this shared notebook
         instance. This may not be the same as userId, since a user with full
         access to a notebook may have created a new share for that notebook. For
         Business, this represents the user who shared the business notebook. This
         field is currently unset for a SharedNotebook created by joining a
         notebook that has been published to the business.
    */
    Optional<UserID> sharerUserId;
    /**
    The username of the user who can access this share. This is the username
         for the user with the id in recipientUserId. This value can be set
         by clients when calling shareNotebook(...), and that will result in the
         created SharedNotebook being assigned to a user. This value is always set
         if serviceAssigned is set.
    */
    Optional<QString> recipientUsername;
    /**
    The id of the user who can access this share. This is the id for the user
         with the username in recipientUsername. This value is read-only and set
         by the service. Value set by clients will be ignored. This field may be unset
         for unjoined notebooks and is always set if serviceAssigned is set. Clients should
         prefer this field over recipientUsername unless they need to use usernames
         directly.
    */
    Optional<UserID> recipientUserId;
    /**
    The date this SharedNotebook was assigned (i.e. has been associated with an
         Evernote user whose user ID is set in recipientUserId). Unset if the SharedNotebook
         is not assigned. This field is a read-only value that is set by the service.
    */
    Optional<Timestamp> serviceAssigned;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const SharedNotebook & other) const
    {
        return id.isEqual(other.id)
            && userId.isEqual(other.userId)
            && notebookGuid.isEqual(other.notebookGuid)
            && email.isEqual(other.email)
            && recipientIdentityId.isEqual(other.recipientIdentityId)
            && notebookModifiable.isEqual(other.notebookModifiable)
            && serviceCreated.isEqual(other.serviceCreated)
            && serviceUpdated.isEqual(other.serviceUpdated)
            && globalId.isEqual(other.globalId)
            && username.isEqual(other.username)
            && privilege.isEqual(other.privilege)
            && recipientSettings.isEqual(other.recipientSettings)
            && sharerUserId.isEqual(other.sharerUserId)
            && recipientUsername.isEqual(other.recipientUsername)
            && recipientUserId.isEqual(other.recipientUserId)
            && serviceAssigned.isEqual(other.serviceAssigned)
        ;
    }

    bool operator!=(const SharedNotebook & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<qint64> id MEMBER id)
    Q_PROPERTY(Optional<UserID> userId MEMBER userId)
    Q_PROPERTY(Optional<Guid> notebookGuid MEMBER notebookGuid)
    Q_PROPERTY(Optional<QString> email MEMBER email)
    Q_PROPERTY(Optional<IdentityID> recipientIdentityId MEMBER recipientIdentityId)
    Q_PROPERTY(Optional<bool> notebookModifiable MEMBER notebookModifiable)
    Q_PROPERTY(Optional<Timestamp> serviceCreated MEMBER serviceCreated)
    Q_PROPERTY(Optional<Timestamp> serviceUpdated MEMBER serviceUpdated)
    Q_PROPERTY(Optional<QString> globalId MEMBER globalId)
    Q_PROPERTY(Optional<QString> username MEMBER username)
    Q_PROPERTY(Optional<SharedNotebookPrivilegeLevel> privilege MEMBER privilege)
    Q_PROPERTY(Optional<SharedNotebookRecipientSettings> recipientSettings MEMBER recipientSettings)
    Q_PROPERTY(Optional<UserID> sharerUserId MEMBER sharerUserId)
    Q_PROPERTY(Optional<QString> recipientUsername MEMBER recipientUsername)
    Q_PROPERTY(Optional<UserID> recipientUserId MEMBER recipientUserId)
    Q_PROPERTY(Optional<Timestamp> serviceAssigned MEMBER serviceAssigned)
};

/**
 * Specifies if the client can move a Notebook to a Workspace.
 */
struct QEVERCLOUD_EXPORT CanMoveToContainerRestrictions: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /** NOT DOCUMENTED */
    Optional<CanMoveToContainerStatus> canMoveToContainer;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const CanMoveToContainerRestrictions & other) const
    {
        return canMoveToContainer.isEqual(other.canMoveToContainer)
        ;
    }

    bool operator!=(const CanMoveToContainerRestrictions & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<CanMoveToContainerStatus> canMoveToContainer MEMBER canMoveToContainer)
};

/**
 * This structure captures information about the types of operations
 * that cannot be performed on a given notebook with a type of
 * authenticated access and credentials.  The values filled into this
 * structure are based on then-current values in the server database
 * for shared notebooks and notebook publishing records, as well as
 * information related to the authentication token.  Information from
 * the authentication token includes the application that is accessing
 * the server, as defined by the permissions granted by consumer (api)
 * key, and the method used to obtain the token, for example via
 * authenticateToSharedNotebook, authenticateToBusiness, etc.  Note
 * that changes to values in this structure that are the result of
 * shared notebook or publishing record changes are communicated to
 * the client via a change in the notebook USN during sync.  It is
 * important to use the same access method, parameters, and consumer
 * key in order obtain correct results from the sync engine.
 *
 * The server has the final say on what is allowed as values may
 * change between calls to obtain NotebookRestrictions instances
 * and to operate on data on the service.
 *
 * If the following are set and true, then the given restriction is
 * in effect, as accessed by the same authentication token from which
 * the values were obtained.
 *
 * */
struct QEVERCLOUD_EXPORT NotebookRestrictions: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The client is not able to read notes from the service and
       the notebook is write-only.
    */
    Optional<bool> noReadNotes;
    /**
    The client may not create new notes in the notebook.
    */
    Optional<bool> noCreateNotes;
    /**
    The client may not update notes currently in the notebook.
    */
    Optional<bool> noUpdateNotes;
    /**
    The client may not expunge notes currently in the notebook.
    */
    Optional<bool> noExpungeNotes;
    /**
    The client may not share notes in the notebook via the
       shareNote or createOrUpdateSharedNotes methods.
    */
    Optional<bool> noShareNotes;
    /**
    The client may not e-mail notes by guid via the Evernote
       service by using the emailNote method.  Email notes by value
       by populating the note parameter instead.
    */
    Optional<bool> noEmailNotes;
    /**
    The client may not send messages to the share recipients of
       the notebook.
    */
    Optional<bool> noSendMessageToRecipients;
    /**
    The client may not update the Notebook object itself, for
       example, via the updateNotebook method.
    */
    Optional<bool> noUpdateNotebook;
    /**
    The client may not expunge the Notebook object itself, for
       example, via the expungeNotebook method.
    */
    Optional<bool> noExpungeNotebook;
    /**
    The client may not set this notebook to be the default notebook.
       The caller should leave Notebook.defaultNotebook unset.
    */
    Optional<bool> noSetDefaultNotebook;
    /**
    If the client is able to update the Notebook, the Notebook.stack
       value may not be set.
    */
    Optional<bool> noSetNotebookStack;
    /**
    The client may not publish the notebook to the public.
       For example, business notebooks may not be shared publicly.
    */
    Optional<bool> noPublishToPublic;
    /**
    The client may not publish the notebook to the business library.
    */
    Optional<bool> noPublishToBusinessLibrary;
    /**
    The client may not complete an operation that results in a new tag
       being created in the owner's account.
    */
    Optional<bool> noCreateTags;
    /**
    The client may not update tags in the owner's account.
    */
    Optional<bool> noUpdateTags;
    /**
    The client may not expunge tags in the owner's account.
    */
    Optional<bool> noExpungeTags;
    /**
    If the client is able to create or update tags in the owner's account,
       then they will not be able to set the parent tag.  Leave the value unset.
    */
    Optional<bool> noSetParentTag;
    /**
    The client is unable to create shared notebooks for the notebook.
    */
    Optional<bool> noCreateSharedNotebooks;
    /**
    Restrictions on which shared notebook instances can be updated.  If the
       value is not set or null, then the client can update any of the shared notebooks
       associated with the notebook on which the NotebookRestrictions are defined.
       See the enumeration for further details.
    */
    Optional<SharedNotebookInstanceRestrictions> updateWhichSharedNotebookRestrictions;
    /**
    Restrictions on which shared notebook instances can be expunged.  If the
       value is not set or null, then the client can expunge any of the shared notebooks
       associated with the notebook on which the NotebookRestrictions are defined.
       See the enumeration for further details.
    */
    Optional<SharedNotebookInstanceRestrictions> expungeWhichSharedNotebookRestrictions;
    /**
    The client may not share notes in the notebook via the shareNoteWithBusiness
       method.
    */
    Optional<bool> noShareNotesWithBusiness;
    /**
    The client may not rename this notebook.
    */
    Optional<bool> noRenameNotebook;
    /**
    clients may not change the NotebookRecipientSettings.inMyList settings for
       this notebook.
    */
    Optional<bool> noSetInMyList;
    /** NOT DOCUMENTED */
    Optional<bool> noChangeContact;
    /**
    Specifies if the client can move this notebook to a container and if not,
       the reason why.
    */
    Optional<CanMoveToContainerRestrictions> canMoveToContainerRestrictions;
    /** NOT DOCUMENTED */
    Optional<bool> noSetReminderNotifyEmail;
    /** NOT DOCUMENTED */
    Optional<bool> noSetReminderNotifyInApp;
    /** NOT DOCUMENTED */
    Optional<bool> noSetRecipientSettingsStack;
    /**
    If set, the client cannot move a Note into or out of the Notebook.
    */
    Optional<bool> noCanMoveNote;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NotebookRestrictions & other) const
    {
        return noReadNotes.isEqual(other.noReadNotes)
            && noCreateNotes.isEqual(other.noCreateNotes)
            && noUpdateNotes.isEqual(other.noUpdateNotes)
            && noExpungeNotes.isEqual(other.noExpungeNotes)
            && noShareNotes.isEqual(other.noShareNotes)
            && noEmailNotes.isEqual(other.noEmailNotes)
            && noSendMessageToRecipients.isEqual(other.noSendMessageToRecipients)
            && noUpdateNotebook.isEqual(other.noUpdateNotebook)
            && noExpungeNotebook.isEqual(other.noExpungeNotebook)
            && noSetDefaultNotebook.isEqual(other.noSetDefaultNotebook)
            && noSetNotebookStack.isEqual(other.noSetNotebookStack)
            && noPublishToPublic.isEqual(other.noPublishToPublic)
            && noPublishToBusinessLibrary.isEqual(other.noPublishToBusinessLibrary)
            && noCreateTags.isEqual(other.noCreateTags)
            && noUpdateTags.isEqual(other.noUpdateTags)
            && noExpungeTags.isEqual(other.noExpungeTags)
            && noSetParentTag.isEqual(other.noSetParentTag)
            && noCreateSharedNotebooks.isEqual(other.noCreateSharedNotebooks)
            && updateWhichSharedNotebookRestrictions.isEqual(other.updateWhichSharedNotebookRestrictions)
            && expungeWhichSharedNotebookRestrictions.isEqual(other.expungeWhichSharedNotebookRestrictions)
            && noShareNotesWithBusiness.isEqual(other.noShareNotesWithBusiness)
            && noRenameNotebook.isEqual(other.noRenameNotebook)
            && noSetInMyList.isEqual(other.noSetInMyList)
            && noChangeContact.isEqual(other.noChangeContact)
            && canMoveToContainerRestrictions.isEqual(other.canMoveToContainerRestrictions)
            && noSetReminderNotifyEmail.isEqual(other.noSetReminderNotifyEmail)
            && noSetReminderNotifyInApp.isEqual(other.noSetReminderNotifyInApp)
            && noSetRecipientSettingsStack.isEqual(other.noSetRecipientSettingsStack)
            && noCanMoveNote.isEqual(other.noCanMoveNote)
        ;
    }

    bool operator!=(const NotebookRestrictions & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<bool> noReadNotes MEMBER noReadNotes)
    Q_PROPERTY(Optional<bool> noCreateNotes MEMBER noCreateNotes)
    Q_PROPERTY(Optional<bool> noUpdateNotes MEMBER noUpdateNotes)
    Q_PROPERTY(Optional<bool> noExpungeNotes MEMBER noExpungeNotes)
    Q_PROPERTY(Optional<bool> noShareNotes MEMBER noShareNotes)
    Q_PROPERTY(Optional<bool> noEmailNotes MEMBER noEmailNotes)
    Q_PROPERTY(Optional<bool> noSendMessageToRecipients MEMBER noSendMessageToRecipients)
    Q_PROPERTY(Optional<bool> noUpdateNotebook MEMBER noUpdateNotebook)
    Q_PROPERTY(Optional<bool> noExpungeNotebook MEMBER noExpungeNotebook)
    Q_PROPERTY(Optional<bool> noSetDefaultNotebook MEMBER noSetDefaultNotebook)
    Q_PROPERTY(Optional<bool> noSetNotebookStack MEMBER noSetNotebookStack)
    Q_PROPERTY(Optional<bool> noPublishToPublic MEMBER noPublishToPublic)
    Q_PROPERTY(Optional<bool> noPublishToBusinessLibrary MEMBER noPublishToBusinessLibrary)
    Q_PROPERTY(Optional<bool> noCreateTags MEMBER noCreateTags)
    Q_PROPERTY(Optional<bool> noUpdateTags MEMBER noUpdateTags)
    Q_PROPERTY(Optional<bool> noExpungeTags MEMBER noExpungeTags)
    Q_PROPERTY(Optional<bool> noSetParentTag MEMBER noSetParentTag)
    Q_PROPERTY(Optional<bool> noCreateSharedNotebooks MEMBER noCreateSharedNotebooks)
    Q_PROPERTY(Optional<SharedNotebookInstanceRestrictions> updateWhichSharedNotebookRestrictions MEMBER updateWhichSharedNotebookRestrictions)
    Q_PROPERTY(Optional<SharedNotebookInstanceRestrictions> expungeWhichSharedNotebookRestrictions MEMBER expungeWhichSharedNotebookRestrictions)
    Q_PROPERTY(Optional<bool> noShareNotesWithBusiness MEMBER noShareNotesWithBusiness)
    Q_PROPERTY(Optional<bool> noRenameNotebook MEMBER noRenameNotebook)
    Q_PROPERTY(Optional<bool> noSetInMyList MEMBER noSetInMyList)
    Q_PROPERTY(Optional<bool> noChangeContact MEMBER noChangeContact)
    Q_PROPERTY(Optional<CanMoveToContainerRestrictions> canMoveToContainerRestrictions MEMBER canMoveToContainerRestrictions)
    Q_PROPERTY(Optional<bool> noSetReminderNotifyEmail MEMBER noSetReminderNotifyEmail)
    Q_PROPERTY(Optional<bool> noSetReminderNotifyInApp MEMBER noSetReminderNotifyInApp)
    Q_PROPERTY(Optional<bool> noSetRecipientSettingsStack MEMBER noSetRecipientSettingsStack)
    Q_PROPERTY(Optional<bool> noCanMoveNote MEMBER noCanMoveNote)
};

/**
 * A unique container for a set of notes.
 * */
struct QEVERCLOUD_EXPORT Notebook: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The unique identifier of this notebook.
       <br/>
       Length:  EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
       <br/>
       Regex:  EDAM_GUID_REGEX
    */
    Optional<Guid> guid;
    /**
    A sequence of characters representing the name of the
       notebook.  May be changed by clients, but the account may not contain two
       notebooks with names that are equal via a case-insensitive comparison.
       Can't begin or end with a space.
       <br/>
       Length:  EDAM_NOTEBOOK_NAME_LEN_MIN - EDAM_NOTEBOOK_NAME_LEN_MAX
       <br/>
       Regex:  EDAM_NOTEBOOK_NAME_REGEX
    */
    Optional<QString> name;
    /**
    A number identifying the last transaction to
       modify the state of this object.  The USN values are sequential within an
       account, and can be used to compare the order of modifications within the
       service.
    */
    Optional<qint32> updateSequenceNum;
    /**
    If true, this notebook should be used for new notes
       whenever the user has not (or cannot) specify a desired target notebook.
       For example, if a note is submitted via SMTP email.
       The service will maintain at most one defaultNotebook per account.
       If a second notebook is created or updated with defaultNotebook set to
       true, the service will automatically update the prior notebook's
       defaultNotebook field to false.  If the default notebook is deleted
       (i.e. "active" set to false), the "defaultNotebook" field will be
       set to false by the service.  If the account has no default notebook
       set, the service will use the most recent notebook as the default.
    */
    Optional<bool> defaultNotebook;
    /**
    The time when this notebook was created on the
       service. This will be set on the service during creation, and the service
       will provide this value when it returns a Notebook to a client.
       The service will ignore this value if it is sent by clients.
    */
    Optional<Timestamp> serviceCreated;
    /**
    The time when this notebook was last modified on the
       service.  This will be set on the service during creation, and the service
       will provide this value when it returns a Notebook to a client.
       The service will ignore this value if it is sent by clients.
    */
    Optional<Timestamp> serviceUpdated;
    /**
    If the Notebook has been opened for public access, then this will point to the set of
       publishing information for the Notebook (URI, description, etc.). A Notebook cannot be
       published without providing this information, but it will persist for later use if publishing
       is ever disabled on the Notebook. Clients that do not wish to change the publishing behavior
       of a Notebook should not set this value when calling NoteStore.updateNotebook().
       Note that this structure is never populated for business notebooks, see the businessNotebook
       field.
    */
    Optional<Publishing> publishing;
    /**
    If this is set to true, then the Notebook will be
       accessible either to the public, or for business users to their business,
       via the 'publishing' or 'businessNotebook' specifications, which must also be set. If this is
       set to false, the Notebook will not be available to the public (or business).
       Clients that do not wish to change the publishing behavior of a Notebook
       should not set this value when calling NoteStore.updateNotebook().
    */
    Optional<bool> published;
    /**
    If this is set, then the notebook is visually contained within a stack
       of notebooks with this name.  All notebooks in the same account with the
       same 'stack' field are considered to be in the same stack.
       Notebooks with no stack set are "top level" and not contained within a
       stack.
    */
    Optional<QString> stack;
    /**
    <i>DEPRECATED</i> - replaced by sharedNotebooks.
    */
    Optional<QList<qint64>> sharedNotebookIds;
    /**
    The list of recipients to whom this notebook has been shared
       (one SharedNotebook object per recipient email address). This field will
       be unset if you do not have permission to access this data. If you are
       accessing the notebook as the owner or via a shared notebook that is
       modifiable, then you have access to this data and the value will be set.
       This field is read-only. Clients may not make changes to shared notebooks
       via this field.
    */
    Optional<QList<SharedNotebook>> sharedNotebooks;
    /**
    If the notebook is part of a business account and has been shared with the entire
       business, this will contain sharing information. The presence or absence of this field
       is not a reliable test of whether a given notebook is in fact a business notebook - the
       field is only used when a notebook is or has been shared with the entire business.
    */
    Optional<BusinessNotebook> businessNotebook;
    /**
    Intended for use with Business accounts, this field identifies the user who
       has been designated as the "contact".  For notebooks created in business
       accounts, the server will automatically set this value to the user who created
       the notebook unless Notebook.contact.username has been set, in which that value
       will be used.  When updating a notebook, it is common to leave Notebook.contact
       field unset, indicating that no change to the value is being requested and that
       the existing value, if any, should be preserved.
    */
    Optional<User> contact;
    /** NOT DOCUMENTED */
    Optional<NotebookRestrictions> restrictions;
    /**
    This represents the preferences/settings that a recipient has set for this
       notebook. These are intended to be changed only by the recipient, and each
       recipient has their own recipient settings.
    */
    Optional<NotebookRecipientSettings> recipientSettings;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const Notebook & other) const
    {
        return guid.isEqual(other.guid)
            && name.isEqual(other.name)
            && updateSequenceNum.isEqual(other.updateSequenceNum)
            && defaultNotebook.isEqual(other.defaultNotebook)
            && serviceCreated.isEqual(other.serviceCreated)
            && serviceUpdated.isEqual(other.serviceUpdated)
            && publishing.isEqual(other.publishing)
            && published.isEqual(other.published)
            && stack.isEqual(other.stack)
            && sharedNotebookIds.isEqual(other.sharedNotebookIds)
            && sharedNotebooks.isEqual(other.sharedNotebooks)
            && businessNotebook.isEqual(other.businessNotebook)
            && contact.isEqual(other.contact)
            && restrictions.isEqual(other.restrictions)
            && recipientSettings.isEqual(other.recipientSettings)
        ;
    }

    bool operator!=(const Notebook & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<Guid> guid MEMBER guid)
    Q_PROPERTY(Optional<QString> name MEMBER name)
    Q_PROPERTY(Optional<qint32> updateSequenceNum MEMBER updateSequenceNum)
    Q_PROPERTY(Optional<bool> defaultNotebook MEMBER defaultNotebook)
    Q_PROPERTY(Optional<Timestamp> serviceCreated MEMBER serviceCreated)
    Q_PROPERTY(Optional<Timestamp> serviceUpdated MEMBER serviceUpdated)
    Q_PROPERTY(Optional<Publishing> publishing MEMBER publishing)
    Q_PROPERTY(Optional<bool> published MEMBER published)
    Q_PROPERTY(Optional<QString> stack MEMBER stack)
    Q_PROPERTY(Optional<QList<qint64>> sharedNotebookIds MEMBER sharedNotebookIds)
    Q_PROPERTY(Optional<QList<SharedNotebook>> sharedNotebooks MEMBER sharedNotebooks)
    Q_PROPERTY(Optional<BusinessNotebook> businessNotebook MEMBER businessNotebook)
    Q_PROPERTY(Optional<User> contact MEMBER contact)
    Q_PROPERTY(Optional<NotebookRestrictions> restrictions MEMBER restrictions)
    Q_PROPERTY(Optional<NotebookRecipientSettings> recipientSettings MEMBER recipientSettings)
};

/**
 * A link in a user's account that refers them to a public or
 * individual shared notebook in another user's account.
 *
 * */
struct QEVERCLOUD_EXPORT LinkedNotebook: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The display name of the shared notebook. The link owner can change this.
    */
    Optional<QString> shareName;
    /**
    The username of the user who owns the shared or public notebook.
    */
    Optional<QString> username;
    /**
    The shard ID of the notebook if the notebook is not public.
    
     <dt>uri
     The identifier of the public notebook.
    */
    Optional<QString> shardId;
    /**
    The globally unique identifier (globalId) of the shared notebook that
       corresponds to the share key, or the GUID of the Notebook that the linked notebook
       refers to. This field must be filled in with the SharedNotebook.globalId or
       Notebook.GUID value when creating new LinkedNotebooks. This field replaces the
       deprecated "shareKey" field.
    */
    Optional<QString> sharedNotebookGlobalId;
    /** NOT DOCUMENTED */
    Optional<QString> uri;
    /**
    The unique identifier of this linked notebook.  Will be set whenever
       a linked notebook is retrieved from the service, but may be null when a client
       is creating a linked notebook.
       <br/>
       Length:  EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
       <br/>
       Regex:  EDAM_GUID_REGEX
    */
    Optional<Guid> guid;
    /**
    A number identifying the last transaction to
       modify the state of this object.  The USN values are sequential within an
       account, and can be used to compare the order of modifications within the
       service.
    */
    Optional<qint32> updateSequenceNum;
    /**
    This field will contain the full URL that clients should use to make
       NoteStore requests to the server shard that contains that notebook's data.
       I.e. this is the URL that should be used to create the Thrift HTTP client
       transport to send messages to the NoteStore service for the account.
    */
    Optional<QString> noteStoreUrl;
    /**
    This field will contain the initial part of the URLs that should be used
       to make requests to Evernote's thin client "web API", which provide
       optimized operations for clients that aren't capable of manipulating
       the full contents of accounts via the full Thrift data model. Clients
       should concatenate the relative path for the various servlets onto the
       end of this string to construct the full URL, as documented on our
       developer web site.
    */
    Optional<QString> webApiUrlPrefix;
    /**
    If this is set, then the notebook is visually contained within a stack
       of notebooks with this name.  All notebooks in the same account with the
       same 'stack' field are considered to be in the same stack.
       Notebooks with no stack set are "top level" and not contained within a
       stack.  The link owner can change this and this field is for the benefit
       of the link owner.
    */
    Optional<QString> stack;
    /**
    If set, this will be the unique identifier for the business that owns
       the notebook to which the linked notebook refers.
    */
    Optional<qint32> businessId;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const LinkedNotebook & other) const
    {
        return shareName.isEqual(other.shareName)
            && username.isEqual(other.username)
            && shardId.isEqual(other.shardId)
            && sharedNotebookGlobalId.isEqual(other.sharedNotebookGlobalId)
            && uri.isEqual(other.uri)
            && guid.isEqual(other.guid)
            && updateSequenceNum.isEqual(other.updateSequenceNum)
            && noteStoreUrl.isEqual(other.noteStoreUrl)
            && webApiUrlPrefix.isEqual(other.webApiUrlPrefix)
            && stack.isEqual(other.stack)
            && businessId.isEqual(other.businessId)
        ;
    }

    bool operator!=(const LinkedNotebook & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> shareName MEMBER shareName)
    Q_PROPERTY(Optional<QString> username MEMBER username)
    Q_PROPERTY(Optional<QString> shardId MEMBER shardId)
    Q_PROPERTY(Optional<QString> sharedNotebookGlobalId MEMBER sharedNotebookGlobalId)
    Q_PROPERTY(Optional<QString> uri MEMBER uri)
    Q_PROPERTY(Optional<Guid> guid MEMBER guid)
    Q_PROPERTY(Optional<qint32> updateSequenceNum MEMBER updateSequenceNum)
    Q_PROPERTY(Optional<QString> noteStoreUrl MEMBER noteStoreUrl)
    Q_PROPERTY(Optional<QString> webApiUrlPrefix MEMBER webApiUrlPrefix)
    Q_PROPERTY(Optional<QString> stack MEMBER stack)
    Q_PROPERTY(Optional<qint32> businessId MEMBER businessId)
};

/**
 * A structure that describes a notebook or a user's relationship with
 * a notebook. NotebookDescriptor is expected to remain a lighter-weight
 * structure when compared to Notebook.
 * */
struct QEVERCLOUD_EXPORT NotebookDescriptor: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The unique identifier of the notebook.
    */
    Optional<Guid> guid;
    /**
    A sequence of characters representing the name of the
       notebook.
    */
    Optional<QString> notebookDisplayName;
    /**
    The User.name value of the notebook's "contact".
    */
    Optional<QString> contactName;
    /**
    Whether a SharedNotebook record exists between the calling user and this
       notebook.
    */
    Optional<bool> hasSharedNotebook;
    /**
    The number of users who have joined this notebook.
    */
    Optional<qint32> joinedUserCount;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NotebookDescriptor & other) const
    {
        return guid.isEqual(other.guid)
            && notebookDisplayName.isEqual(other.notebookDisplayName)
            && contactName.isEqual(other.contactName)
            && hasSharedNotebook.isEqual(other.hasSharedNotebook)
            && joinedUserCount.isEqual(other.joinedUserCount)
        ;
    }

    bool operator!=(const NotebookDescriptor & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<Guid> guid MEMBER guid)
    Q_PROPERTY(Optional<QString> notebookDisplayName MEMBER notebookDisplayName)
    Q_PROPERTY(Optional<QString> contactName MEMBER contactName)
    Q_PROPERTY(Optional<bool> hasSharedNotebook MEMBER hasSharedNotebook)
    Q_PROPERTY(Optional<qint32> joinedUserCount MEMBER joinedUserCount)
};

/**
 * This structure represents profile information for a user in a business.
 *
 * */
struct QEVERCLOUD_EXPORT UserProfile: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The numeric identifier that uniquely identifies a user.
    */
    Optional<UserID> id;
    /**
    The full name of the user.
    */
    Optional<QString> name;
    /**
    The user's business email address. If the user has not registered their business
       email address, this field will be empty.
    */
    Optional<QString> email;
    /**
    The user's Evernote username.
    */
    Optional<QString> username;
    /**
    The user's business specific attributes.
    */
    Optional<BusinessUserAttributes> attributes;
    /**
    The time when the user joined the business
    */
    Optional<Timestamp> joined;
    /**
    The time when the user's profile photo was most recently updated
    */
    Optional<Timestamp> photoLastUpdated;
    /**
    A URL identifying a copy of the user's current profile photo
    */
    Optional<QString> photoUrl;
    /**
    The BusinessUserRole for the user
    */
    Optional<BusinessUserRole> role;
    /**
    The BusinessUserStatus for the user
    */
    Optional<BusinessUserStatus> status;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const UserProfile & other) const
    {
        return id.isEqual(other.id)
            && name.isEqual(other.name)
            && email.isEqual(other.email)
            && username.isEqual(other.username)
            && attributes.isEqual(other.attributes)
            && joined.isEqual(other.joined)
            && photoLastUpdated.isEqual(other.photoLastUpdated)
            && photoUrl.isEqual(other.photoUrl)
            && role.isEqual(other.role)
            && status.isEqual(other.status)
        ;
    }

    bool operator!=(const UserProfile & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<UserID> id MEMBER id)
    Q_PROPERTY(Optional<QString> name MEMBER name)
    Q_PROPERTY(Optional<QString> email MEMBER email)
    Q_PROPERTY(Optional<QString> username MEMBER username)
    Q_PROPERTY(Optional<BusinessUserAttributes> attributes MEMBER attributes)
    Q_PROPERTY(Optional<Timestamp> joined MEMBER joined)
    Q_PROPERTY(Optional<Timestamp> photoLastUpdated MEMBER photoLastUpdated)
    Q_PROPERTY(Optional<QString> photoUrl MEMBER photoUrl)
    Q_PROPERTY(Optional<BusinessUserRole> role MEMBER role)
    Q_PROPERTY(Optional<BusinessUserStatus> status MEMBER status)
};

/**
 * An external image that can be shown with a related content snippet,
 * usually either a JPEG or PNG image. It is up to the client which image(s) are shown,
 * depending on available screen real estate, resolution and aspect ratio.
 *
 * */
struct QEVERCLOUD_EXPORT RelatedContentImage: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The external URL of the image
    */
    Optional<QString> url;
    /**
    The width of the image, in pixels.
    */
    Optional<qint32> width;
    /**
    The height of the image, in pixels.
    */
    Optional<qint32> height;
    /**
    the pixel ratio (usually either 1.0, 1.5 or 2.0)
    */
    Optional<double> pixelRatio;
    /**
    the size of the image file, in bytes
    */
    Optional<qint32> fileSize;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const RelatedContentImage & other) const
    {
        return url.isEqual(other.url)
            && width.isEqual(other.width)
            && height.isEqual(other.height)
            && pixelRatio.isEqual(other.pixelRatio)
            && fileSize.isEqual(other.fileSize)
        ;
    }

    bool operator!=(const RelatedContentImage & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> url MEMBER url)
    Q_PROPERTY(Optional<qint32> width MEMBER width)
    Q_PROPERTY(Optional<qint32> height MEMBER height)
    Q_PROPERTY(Optional<double> pixelRatio MEMBER pixelRatio)
    Q_PROPERTY(Optional<qint32> fileSize MEMBER fileSize)
};

/**
 * A structure identifying one snippet of related content (some information that is not
 * part of an Evernote account but might still be relevant to the user).
 *
 * */
struct QEVERCLOUD_EXPORT RelatedContent: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    An identifier that uniquely identifies the content.
    */
    Optional<QString> contentId;
    /**
    The main title to show.
    */
    Optional<QString> title;
    /**
    The URL the client can use to retrieve the content.
    */
    Optional<QString> url;
    /**
    An identifier that uniquely identifies the source.
    */
    Optional<QString> sourceId;
    /**
    A URL the client can access to know more about the source.
    */
    Optional<QString> sourceUrl;
    /**
    The favicon URL of the source which the content belongs to.
    */
    Optional<QString> sourceFaviconUrl;
    /**
    A human-readable name of the source that provided this content.
    */
    Optional<QString> sourceName;
    /**
    A timestamp telling the user about the recency of the content.
    */
    Optional<Timestamp> date;
    /**
    A teaser text to show to the user; usually the first few sentences of the content,
         excluding the title.
    */
    Optional<QString> teaser;
    /**
    A list of thumbnails the client can show in the snippet.
    */
    Optional<QList<RelatedContentImage>> thumbnails;
    /**
    The type of this related content.
    */
    Optional<RelatedContentType> contentType;
    /**
    An indication of how this content can be accessed. This type influences the
         semantics of the <code>url</code> parameter.
    */
    Optional<RelatedContentAccess> accessType;
    /**
    If set, the client should show this URL to the user, instead of the URL that was
         used to retrieve the content. This URL should be used when opening the content
         in an external browser window, or when sharing with another person.
    */
    Optional<QString> visibleUrl;
    /**
    If set, the client should use this URL for clipping purposes, instead of the URL
         that was used to retrieve the content. The clipUrl may directly point to an .enex
         file, for example.
    */
    Optional<QString> clipUrl;
    /**
    If set, the client may use this Contact for messaging purposes. This will typically
         only be set for user profiles.
    */
    Optional<Contact> contact;
    /**
    For News articles only. A list of names of the article authors, if available.
    */
    Optional<QStringList> authors;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const RelatedContent & other) const
    {
        return contentId.isEqual(other.contentId)
            && title.isEqual(other.title)
            && url.isEqual(other.url)
            && sourceId.isEqual(other.sourceId)
            && sourceUrl.isEqual(other.sourceUrl)
            && sourceFaviconUrl.isEqual(other.sourceFaviconUrl)
            && sourceName.isEqual(other.sourceName)
            && date.isEqual(other.date)
            && teaser.isEqual(other.teaser)
            && thumbnails.isEqual(other.thumbnails)
            && contentType.isEqual(other.contentType)
            && accessType.isEqual(other.accessType)
            && visibleUrl.isEqual(other.visibleUrl)
            && clipUrl.isEqual(other.clipUrl)
            && contact.isEqual(other.contact)
            && authors.isEqual(other.authors)
        ;
    }

    bool operator!=(const RelatedContent & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> contentId MEMBER contentId)
    Q_PROPERTY(Optional<QString> title MEMBER title)
    Q_PROPERTY(Optional<QString> url MEMBER url)
    Q_PROPERTY(Optional<QString> sourceId MEMBER sourceId)
    Q_PROPERTY(Optional<QString> sourceUrl MEMBER sourceUrl)
    Q_PROPERTY(Optional<QString> sourceFaviconUrl MEMBER sourceFaviconUrl)
    Q_PROPERTY(Optional<QString> sourceName MEMBER sourceName)
    Q_PROPERTY(Optional<Timestamp> date MEMBER date)
    Q_PROPERTY(Optional<QString> teaser MEMBER teaser)
    Q_PROPERTY(Optional<QList<RelatedContentImage>> thumbnails MEMBER thumbnails)
    Q_PROPERTY(Optional<RelatedContentType> contentType MEMBER contentType)
    Q_PROPERTY(Optional<RelatedContentAccess> accessType MEMBER accessType)
    Q_PROPERTY(Optional<QString> visibleUrl MEMBER visibleUrl)
    Q_PROPERTY(Optional<QString> clipUrl MEMBER clipUrl)
    Q_PROPERTY(Optional<Contact> contact MEMBER contact)
    Q_PROPERTY(Optional<QStringList> authors MEMBER authors)
};

/**
 * A structure describing an invitation to join a business account.
 *
 * */
struct QEVERCLOUD_EXPORT BusinessInvitation: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The ID of the business to which the invitation grants access.
    */
    Optional<qint32> businessId;
    /**
    The email address that was invited to join the business.
    */
    Optional<QString> email;
    /**
    The role to grant the user after the invitation is accepted.
    */
    Optional<BusinessUserRole> role;
    /**
    The status of the invitation.
    */
    Optional<BusinessInvitationStatus> status;
    /**
    For invitations that were initially requested by a non-admin member of the business,
           this field specifies the user ID of the requestor. For all other invitations, this field
           will be unset.
    */
    Optional<UserID> requesterId;
    /**
    If this invitation was created implicitly via a WorkChat, this field
           will be true.
    */
    Optional<bool> fromWorkChat;
    /**
    The timestamp at which this invitation was created.
    */
    Optional<Timestamp> created;
    /**
    The timestamp at which the most recent reminder was sent.
    */
    Optional<Timestamp> mostRecentReminder;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const BusinessInvitation & other) const
    {
        return businessId.isEqual(other.businessId)
            && email.isEqual(other.email)
            && role.isEqual(other.role)
            && status.isEqual(other.status)
            && requesterId.isEqual(other.requesterId)
            && fromWorkChat.isEqual(other.fromWorkChat)
            && created.isEqual(other.created)
            && mostRecentReminder.isEqual(other.mostRecentReminder)
        ;
    }

    bool operator!=(const BusinessInvitation & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<qint32> businessId MEMBER businessId)
    Q_PROPERTY(Optional<QString> email MEMBER email)
    Q_PROPERTY(Optional<BusinessUserRole> role MEMBER role)
    Q_PROPERTY(Optional<BusinessInvitationStatus> status MEMBER status)
    Q_PROPERTY(Optional<UserID> requesterId MEMBER requesterId)
    Q_PROPERTY(Optional<bool> fromWorkChat MEMBER fromWorkChat)
    Q_PROPERTY(Optional<Timestamp> created MEMBER created)
    Q_PROPERTY(Optional<Timestamp> mostRecentReminder MEMBER mostRecentReminder)
};

/**
 * A structure that holds user identifying information such as an
 * email address, Evernote user ID, or an identifier from a 3rd party
 * service.  An instance consists of a type and a value, where the
 * value will be stored in one of the value fields depending upon the
 * data type required for the identity type.
 *
 * When used with shared notebook invitations, a UserIdentity
 * identifies a particular person who may not (yet) have an Evernote
 * UserID UserIdentity but who has (almost) unique access to the
 * service endpoint described by the UserIdentity.  For example, an
 * e-mail UserIdentity can identify the person who receives e-mail at
 * the given address, and who can therefore read the share key that
 * has a cryptographic signature from the Evernote service. With the
 * share key, this person can supply their Evernote UserID via an
 * authentication token to join the notebook
 * (authenticateToSharedNotebook), at which time we have associated
 * the e-mail UserIdentity with an Evernote UserID UserIdentity. Note
 * that using shared notebook records, the relationship between
 * Evernote UserIDs and e-mail addresses is many to many.
 *
 * Note that the identifier may not directly identify a
 * particular Evernote UserID UserIdentity without further
 * verification.  For example, an e-mail UserIdentity may be
 * associated with an invitation to join a notebook (via a shared
 * notebook record), but until a user uses a share key, that was sent
 * to that e-mail address, to join the notebook, we do not know an
 * Evernote UserID UserIdentity ID to match the e-mail address.
 */
struct QEVERCLOUD_EXPORT UserIdentity: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /** NOT DOCUMENTED */
    Optional<UserIdentityType> type;
    /** NOT DOCUMENTED */
    Optional<QString> stringIdentifier;
    /** NOT DOCUMENTED */
    Optional<qint64> longIdentifier;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const UserIdentity & other) const
    {
        return type.isEqual(other.type)
            && stringIdentifier.isEqual(other.stringIdentifier)
            && longIdentifier.isEqual(other.longIdentifier)
        ;
    }

    bool operator!=(const UserIdentity & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<UserIdentityType> type MEMBER type)
    Q_PROPERTY(Optional<QString> stringIdentifier MEMBER stringIdentifier)
    Q_PROPERTY(Optional<qint64> longIdentifier MEMBER longIdentifier)
};

/**
 * This structure is used to provide publicly-available user information
 * about a particular account.
 **/
struct QEVERCLOUD_EXPORT PublicUserInfo: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The unique numeric user identifier for the user account.
    */
    UserID userId = 0;
    /**
    The service level of the account.
    */
    Optional<ServiceLevel> serviceLevel;
    /** NOT DOCUMENTED */
    Optional<QString> username;
    /**
    This field will contain the full URL that clients should use to make
       NoteStore requests to the server shard that contains that user's data.
       I.e. this is the URL that should be used to create the Thrift HTTP client
       transport to send messages to the NoteStore service for the account.
    */
    Optional<QString> noteStoreUrl;
    /**
    This field will contain the initial part of the URLs that should be used
       to make requests to Evernote's thin client "web API", which provide
       optimized operations for clients that aren't capable of manipulating
       the full contents of accounts via the full Thrift data model. Clients
       should concatenate the relative path for the various servlets onto the
       end of this string to construct the full URL, as documented on our
       developer web site.
    */
    Optional<QString> webApiUrlPrefix;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const PublicUserInfo & other) const
    {
        return (userId == other.userId)
            && serviceLevel.isEqual(other.serviceLevel)
            && username.isEqual(other.username)
            && noteStoreUrl.isEqual(other.noteStoreUrl)
            && webApiUrlPrefix.isEqual(other.webApiUrlPrefix)
        ;
    }

    bool operator!=(const PublicUserInfo & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(UserID userId MEMBER userId)
    Q_PROPERTY(Optional<ServiceLevel> serviceLevel MEMBER serviceLevel)
    Q_PROPERTY(Optional<QString> username MEMBER username)
    Q_PROPERTY(Optional<QString> noteStoreUrl MEMBER noteStoreUrl)
    Q_PROPERTY(Optional<QString> webApiUrlPrefix MEMBER webApiUrlPrefix)
};

/**
 * */
struct QEVERCLOUD_EXPORT UserUrls: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    This field will contain the full URL that clients should use to make
       NoteStore requests to the server shard that contains that user's data.
       I.e. this is the URL that should be used to create the Thrift HTTP client
       transport to send messages to the NoteStore service for the account.
    */
    Optional<QString> noteStoreUrl;
    /**
    This field will contain the initial part of the URLs that should be used
       to make requests to Evernote's thin client "web API", which provide
       optimized operations for clients that aren't capable of manipulating
       the full contents of accounts via the full Thrift data model. Clients
       should concatenate the relative path for the various servlets onto the
       end of this string to construct the full URL, as documented on our
       developer web site.
    */
    Optional<QString> webApiUrlPrefix;
    /**
    This field will contain the full URL that clients should use to make UserStore
       requests after successfully authenticating. I.e. this is the URL that should be used
       to create the Thrift HTTP client transport to send messages to the UserStore service
       for this account.
    */
    Optional<QString> userStoreUrl;
    /**
    This field will contain the full URL that clients should use to make Utility requests
       to the server shard that contains that user's data. I.e. this is the URL that should
       be used to create the Thrift HTTP client transport to send messages to the Utility
       service for the account.
    */
    Optional<QString> utilityUrl;
    /**
    This field will contain the full URL that clients should use to make MessageStore
       requests to the server. I.e. this is the URL that should be used to create the
       Thrift HTTP client transport to send messages to the MessageStore service for the
       account.
    */
    Optional<QString> messageStoreUrl;
    /**
    This field will contain the full URL that clients should use when opening a
       persistent web socket to receive notification of events for the authenticated user.
    */
    Optional<QString> userWebSocketUrl;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const UserUrls & other) const
    {
        return noteStoreUrl.isEqual(other.noteStoreUrl)
            && webApiUrlPrefix.isEqual(other.webApiUrlPrefix)
            && userStoreUrl.isEqual(other.userStoreUrl)
            && utilityUrl.isEqual(other.utilityUrl)
            && messageStoreUrl.isEqual(other.messageStoreUrl)
            && userWebSocketUrl.isEqual(other.userWebSocketUrl)
        ;
    }

    bool operator!=(const UserUrls & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> noteStoreUrl MEMBER noteStoreUrl)
    Q_PROPERTY(Optional<QString> webApiUrlPrefix MEMBER webApiUrlPrefix)
    Q_PROPERTY(Optional<QString> userStoreUrl MEMBER userStoreUrl)
    Q_PROPERTY(Optional<QString> utilityUrl MEMBER utilityUrl)
    Q_PROPERTY(Optional<QString> messageStoreUrl MEMBER messageStoreUrl)
    Q_PROPERTY(Optional<QString> userWebSocketUrl MEMBER userWebSocketUrl)
};

/**
 * When an authentication (or re-authentication) is performed, this structure
 * provides the result to the client.
 **/
struct QEVERCLOUD_EXPORT AuthenticationResult: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The server-side date and time when this result was
       generated.
    */
    Timestamp currentTime = 0;
    /**
    Holds an opaque, ASCII-encoded token that can be
       used by the client to perform actions on a NoteStore.
    */
    QString authenticationToken;
    /**
    Holds the server-side date and time when the
       authentication token will expire.
       This time can be compared to "currentTime" to produce an expiration
       time that can be reconciled with the client's local clock.
    */
    Timestamp expiration = 0;
    /**
    Holds the information about the account which was
       authenticated if this was a full authentication.  May be absent if this
       particular authentication did not require user information.
    */
    Optional<User> user;
    /**
    If this authentication result was achieved without full permissions to
       access the full User structure, this field may be set to give back
       a more limited public set of data.
    */
    Optional<PublicUserInfo> publicUserInfo;
    /**
    DEPRECATED - Client applications should use urls.noteStoreUrl.
    */
    Optional<QString> noteStoreUrl;
    /**
    DEPRECATED - Client applications should use urls.webApiUrlPrefix.
    */
    Optional<QString> webApiUrlPrefix;
    /**
    If set to true, this field indicates that the user has enabled two-factor
       authentication and must enter their second factor in order to complete
       authentication. In this case the value of authenticationResult will be
       a short-lived authentication token that may only be used to make a
       subsequent call to completeTwoFactorAuthentication.
    */
    Optional<bool> secondFactorRequired;
    /**
    When secondFactorRequired is set to true, this field may contain a string
       describing the second factor delivery method that the user has configured.
       This will typically be an obfuscated mobile device number, such as
       "(xxx) xxx-x095". This string can be displayed to the user to remind them
       how to obtain the required second factor.
    */
    Optional<QString> secondFactorDeliveryHint;
    /**
    This structure will contain all of the URLs that clients need to make requests to the
       Evernote service on behalf of the authenticated User.
    */
    Optional<UserUrls> urls;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const AuthenticationResult & other) const
    {
        return (currentTime == other.currentTime)
            && (authenticationToken == other.authenticationToken)
            && (expiration == other.expiration)
            && user.isEqual(other.user)
            && publicUserInfo.isEqual(other.publicUserInfo)
            && noteStoreUrl.isEqual(other.noteStoreUrl)
            && webApiUrlPrefix.isEqual(other.webApiUrlPrefix)
            && secondFactorRequired.isEqual(other.secondFactorRequired)
            && secondFactorDeliveryHint.isEqual(other.secondFactorDeliveryHint)
            && urls.isEqual(other.urls)
        ;
    }

    bool operator!=(const AuthenticationResult & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Timestamp currentTime MEMBER currentTime)
    Q_PROPERTY(QString authenticationToken MEMBER authenticationToken)
    Q_PROPERTY(Timestamp expiration MEMBER expiration)
    Q_PROPERTY(Optional<User> user MEMBER user)
    Q_PROPERTY(Optional<PublicUserInfo> publicUserInfo MEMBER publicUserInfo)
    Q_PROPERTY(Optional<QString> noteStoreUrl MEMBER noteStoreUrl)
    Q_PROPERTY(Optional<QString> webApiUrlPrefix MEMBER webApiUrlPrefix)
    Q_PROPERTY(Optional<bool> secondFactorRequired MEMBER secondFactorRequired)
    Q_PROPERTY(Optional<QString> secondFactorDeliveryHint MEMBER secondFactorDeliveryHint)
    Q_PROPERTY(Optional<UserUrls> urls MEMBER urls)
};

/**
 * This structure describes a collection of bootstrap settings.
 **/
struct QEVERCLOUD_EXPORT BootstrapSettings: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The hostname and optional port for composing Evernote web service URLs.
       This URL can be used to access the UserStore and related services,
       but must not be used to compose the NoteStore URL. Client applications
       must handle serviceHost values that include only the hostname
       (e.g. www.evernote.com) or both the hostname and port (e.g. www.evernote.com:8080).
       If no port is specified, or if port 443 is specified, client applications must
       use the scheme "https" when composing URLs. Otherwise, a client must use the
       scheme "http".
    */
    QString serviceHost;
    /**
    The URL stem for the Evernote corporate marketing website, e.g. http://www.evernote.com.
       This stem can be used to compose website URLs. For example, the URL of the Evernote
       Trunk is composed by appending "/about/trunk/" to the value of marketingUrl.
    */
    QString marketingUrl;
    /**
    The full URL for the Evernote customer support website, e.g. https://support.evernote.com.
    */
    QString supportUrl;
    /**
    The domain used for an Evernote user's incoming email address, which allows notes to
       be emailed into an account. E.g. m.evernote.com.
    */
    QString accountEmailDomain;
    /**
    Whether the client application should enable sharing of notes on Facebook.
    */
    Optional<bool> enableFacebookSharing;
    /**
    Whether the client application should enable gift subscriptions.
    */
    Optional<bool> enableGiftSubscriptions;
    /**
    Whether the client application should enable in-client creation of support tickets.
    */
    Optional<bool> enableSupportTickets;
    /**
    Whether the client application should enable shared notebooks.
    */
    Optional<bool> enableSharedNotebooks;
    /**
    Whether the client application should enable single note sharing.
    */
    Optional<bool> enableSingleNoteSharing;
    /**
    Whether the client application should enable sponsored accounts.
    */
    Optional<bool> enableSponsoredAccounts;
    /**
    Whether the client application should enable sharing of notes on Twitter.
    */
    Optional<bool> enableTwitterSharing;
    /** NOT DOCUMENTED */
    Optional<bool> enableLinkedInSharing;
    /** NOT DOCUMENTED */
    Optional<bool> enablePublicNotebooks;
    /**
    Whether the client application should enable authentication with Google,
       for example to allow integration with a user's Gmail contacts.
    */
    Optional<bool> enableGoogle;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const BootstrapSettings & other) const
    {
        return (serviceHost == other.serviceHost)
            && (marketingUrl == other.marketingUrl)
            && (supportUrl == other.supportUrl)
            && (accountEmailDomain == other.accountEmailDomain)
            && enableFacebookSharing.isEqual(other.enableFacebookSharing)
            && enableGiftSubscriptions.isEqual(other.enableGiftSubscriptions)
            && enableSupportTickets.isEqual(other.enableSupportTickets)
            && enableSharedNotebooks.isEqual(other.enableSharedNotebooks)
            && enableSingleNoteSharing.isEqual(other.enableSingleNoteSharing)
            && enableSponsoredAccounts.isEqual(other.enableSponsoredAccounts)
            && enableTwitterSharing.isEqual(other.enableTwitterSharing)
            && enableLinkedInSharing.isEqual(other.enableLinkedInSharing)
            && enablePublicNotebooks.isEqual(other.enablePublicNotebooks)
            && enableGoogle.isEqual(other.enableGoogle)
        ;
    }

    bool operator!=(const BootstrapSettings & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(QString serviceHost MEMBER serviceHost)
    Q_PROPERTY(QString marketingUrl MEMBER marketingUrl)
    Q_PROPERTY(QString supportUrl MEMBER supportUrl)
    Q_PROPERTY(QString accountEmailDomain MEMBER accountEmailDomain)
    Q_PROPERTY(Optional<bool> enableFacebookSharing MEMBER enableFacebookSharing)
    Q_PROPERTY(Optional<bool> enableGiftSubscriptions MEMBER enableGiftSubscriptions)
    Q_PROPERTY(Optional<bool> enableSupportTickets MEMBER enableSupportTickets)
    Q_PROPERTY(Optional<bool> enableSharedNotebooks MEMBER enableSharedNotebooks)
    Q_PROPERTY(Optional<bool> enableSingleNoteSharing MEMBER enableSingleNoteSharing)
    Q_PROPERTY(Optional<bool> enableSponsoredAccounts MEMBER enableSponsoredAccounts)
    Q_PROPERTY(Optional<bool> enableTwitterSharing MEMBER enableTwitterSharing)
    Q_PROPERTY(Optional<bool> enableLinkedInSharing MEMBER enableLinkedInSharing)
    Q_PROPERTY(Optional<bool> enablePublicNotebooks MEMBER enablePublicNotebooks)
    Q_PROPERTY(Optional<bool> enableGoogle MEMBER enableGoogle)
};

/**
 * This structure describes a collection of bootstrap settings.
 **/
struct QEVERCLOUD_EXPORT BootstrapProfile: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The unique name of the profile, which is guaranteed to remain consistent across
       calls to getBootstrapInfo.
    */
    QString name;
    /**
    The settings for this profile.
    */
    BootstrapSettings settings;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const BootstrapProfile & other) const
    {
        return (name == other.name)
            && (settings == other.settings)
        ;
    }

    bool operator!=(const BootstrapProfile & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(QString name MEMBER name)
    Q_PROPERTY(BootstrapSettings settings MEMBER settings)
};

/**
 * This structure describes a collection of bootstrap profiles.
 **/
struct QEVERCLOUD_EXPORT BootstrapInfo: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    List of one or more bootstrap profiles, in descending
       preference order.
    */
    QList<BootstrapProfile> profiles;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const BootstrapInfo & other) const
    {
        return (profiles == other.profiles)
        ;
    }

    bool operator!=(const BootstrapInfo & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(QList<BootstrapProfile> profiles MEMBER profiles)
};

/**
 * This exception is thrown by EDAM procedures when a call fails as a result of 
 * a problem that a caller may be able to resolve.  For example, if the user
 * attempts to add a note to their account which would exceed their storage
 * quota, this type of exception may be thrown to indicate the source of the
 * error so that they can choose an alternate action.
 *
 * This exception would not be used for internal system errors that do not
 * reflect user actions, but rather reflect a problem within the service that
 * the user cannot resolve.
 *
 * errorCode:  The numeric code indicating the type of error that occurred.
 *   must be one of the values of EDAMErrorCode.
 *
 * parameter:  If the error applied to a particular input parameter, this will
 *   indicate which parameter. For some errors (USER_NOT_ASSOCIATED, USER_NOT_REGISTERED,
 *   SSO_AUTHENTICATION_REQUIRED), this is the user's email.
 */
class QEVERCLOUD_EXPORT EDAMUserException: public EvernoteException, public Printable
{
    Q_GADGET
public:
    EDAMErrorCode errorCode;
    Optional<QString> parameter;

    EDAMUserException();
    virtual ~EDAMUserException() noexcept override;

    EDAMUserException(const EDAMUserException & other);
    const char * what() const noexcept override;
    virtual EverCloudExceptionDataPtr exceptionData() const override;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const EDAMUserException & other) const
    {
        return (errorCode == other.errorCode)
            && parameter.isEqual(other.parameter)
        ;
    }

    bool operator!=(const EDAMUserException & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EDAMErrorCode errorCode MEMBER errorCode)
    Q_PROPERTY(Optional<QString> parameter MEMBER parameter)
};

/**
 * This exception is thrown by EDAM procedures when a call fails as a result of
 * a problem in the service that could not be changed through caller action.
 *
 * errorCode:  The numeric code indicating the type of error that occurred.
 *   must be one of the values of EDAMErrorCode.
 *
 * message:  This may contain additional information about the error
 *
 * rateLimitDuration:  Indicates the minimum number of seconds that an application should
 *   expect subsequent API calls for this user to fail. The application should not retry
 *   API requests for the user until at least this many seconds have passed. Present only
 *   when errorCode is RATE_LIMIT_REACHED,
 */
class QEVERCLOUD_EXPORT EDAMSystemException: public EvernoteException, public Printable
{
    Q_GADGET
public:
    EDAMErrorCode errorCode;
    Optional<QString> message;
    Optional<qint32> rateLimitDuration;

    EDAMSystemException();
    virtual ~EDAMSystemException() noexcept override;

    EDAMSystemException(const EDAMSystemException & other);
    const char * what() const noexcept override;
    virtual EverCloudExceptionDataPtr exceptionData() const override;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const EDAMSystemException & other) const
    {
        return (errorCode == other.errorCode)
            && message.isEqual(other.message)
            && rateLimitDuration.isEqual(other.rateLimitDuration)
        ;
    }

    bool operator!=(const EDAMSystemException & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EDAMErrorCode errorCode MEMBER errorCode)
    Q_PROPERTY(Optional<QString> message MEMBER message)
    Q_PROPERTY(Optional<qint32> rateLimitDuration MEMBER rateLimitDuration)
};

/**
 * This exception is thrown by EDAM procedures when a caller asks to perform
 * an operation on an object that does not exist.  This may be thrown based on an invalid
 * primary identifier (e.g. a bad GUID), or when the caller refers to an object
 * by another unique identifier (e.g. a User's email address).
 *
 * identifier:  A description of the object that was not found on the server.
 *   For example, "Note.notebookGuid" when a caller attempts to create a note in a
 *   notebook that does not exist in the user's account.
 *
 * key:  The value passed from the client in the identifier, which was not
 *   found. For example, the GUID that was not found.
 */
class QEVERCLOUD_EXPORT EDAMNotFoundException: public EvernoteException, public Printable
{
    Q_GADGET
public:
    Optional<QString> identifier;
    Optional<QString> key;

    EDAMNotFoundException();
    virtual ~EDAMNotFoundException() noexcept override;

    EDAMNotFoundException(const EDAMNotFoundException & other);
    const char * what() const noexcept override;
    virtual EverCloudExceptionDataPtr exceptionData() const override;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const EDAMNotFoundException & other) const
    {
        return identifier.isEqual(other.identifier)
            && key.isEqual(other.key)
        ;
    }

    bool operator!=(const EDAMNotFoundException & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(Optional<QString> identifier MEMBER identifier)
    Q_PROPERTY(Optional<QString> key MEMBER key)
};

/**
 * An exception thrown when the provided Contacts fail validation. For instance,
 * email domains could be invalid, phone numbers might not be valid for SMS,
 * etc.
 *
 * We will not provide individual reasons for each Contact's validation failure.
 * The presence of the Contact in this exception means that the user must figure
 * out how to take appropriate action to fix this Contact.
 *
 * <dl>
 *   <dt>contacts</dt>
 *   <dd>The list of Contacts that are considered invalid by the service</dd>
 *
 *   <dt>parameter</dt>
 *   <dd>If the error applied to a particular input parameter, this will
 *   indicate which parameter.</dd>
 *
 *   <dt>reasons</dt>
 *   <dd>If supplied, the list of reasons why the server considered a contact invalid,
 *   matching, in order, the list returned in the contacts field.</dd>
 * </dl>
 */
class QEVERCLOUD_EXPORT EDAMInvalidContactsException: public EvernoteException, public Printable
{
    Q_GADGET
public:
    QList<Contact> contacts;
    Optional<QString> parameter;
    Optional<QList<EDAMInvalidContactReason>> reasons;

    EDAMInvalidContactsException();
    virtual ~EDAMInvalidContactsException() noexcept override;

    EDAMInvalidContactsException(const EDAMInvalidContactsException & other);
    const char * what() const noexcept override;
    virtual EverCloudExceptionDataPtr exceptionData() const override;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const EDAMInvalidContactsException & other) const
    {
        return (contacts == other.contacts)
            && parameter.isEqual(other.parameter)
            && reasons.isEqual(other.reasons)
        ;
    }

    bool operator!=(const EDAMInvalidContactsException & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(QList<Contact> contacts MEMBER contacts)
    Q_PROPERTY(Optional<QString> parameter MEMBER parameter)
    Q_PROPERTY(Optional<QList<EDAMInvalidContactReason>> reasons MEMBER reasons)
};

/**
 * This structure is given out by the NoteStore when a client asks to
 * receive the current state of an account.  The client asks for the server's
 * state one chunk at a time in order to allow clients to retrieve the state
 * of a large account without needing to transfer the entire account in
 * a single message.
 *
 * The server always gives SyncChunks using an ascending series of Update
 * Sequence Numbers (USNs).
 *
 **/
struct QEVERCLOUD_EXPORT SyncChunk: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The server's current date and time.
    */
    Timestamp currentTime = 0;
    /**
    The highest USN for any of the data objects represented
       in this sync chunk.  If there are no objects in the chunk, this will not be
       set.
    */
    Optional<qint32> chunkHighUSN;
    /**
    The total number of updates that have been performed in
       the service for this account.  This is equal to the highest USN within the
       account at the point that this SyncChunk was generated.  If updateCount
       and chunkHighUSN are identical, that means that this is the last chunk
       in the account ... there is no more recent information.
    */
    qint32 updateCount = 0;
    /**
    If present, this is a list of non-expunged notes that
       have a USN in this chunk.  This will include notes that are "deleted"
       but not expunged (i.e. in the trash).  The notes will include their list
       of tags and resources, but the note content, resource content, resource
       recognition data and resource alternate data will not be supplied.
    */
    Optional<QList<Note>> notes;
    /**
    If present, this is a list of non-expunged notebooks that
       have a USN in this chunk.
    */
    Optional<QList<Notebook>> notebooks;
    /**
    If present, this is a list of the non-expunged tags that have a
       USN in this chunk.
    */
    Optional<QList<Tag>> tags;
    /**
    If present, this is a list of non-expunged searches that
       have a USN in this chunk.
    */
    Optional<QList<SavedSearch>> searches;
    /**
    If present, this is a list of the non-expunged resources
       that have a USN in this chunk.  This will include the metadata for each
       resource, but not its binary contents or recognition data, which must be
       retrieved separately.
    */
    Optional<QList<Resource>> resources;
    /**
    If present, the GUIDs of all of the notes that were
       permanently expunged in this chunk.
    */
    Optional<QList<Guid>> expungedNotes;
    /**
    If present, the GUIDs of all of the notebooks that
       were permanently expunged in this chunk.  When a notebook is expunged,
       this implies that all of its child notes (and their resources) were
       also expunged.
    */
    Optional<QList<Guid>> expungedNotebooks;
    /**
    If present, the GUIDs of all of the tags that were
       permanently expunged in this chunk.
    */
    Optional<QList<Guid>> expungedTags;
    /**
    If present, the GUIDs of all of the saved searches
       that were permanently expunged in this chunk.
    */
    Optional<QList<Guid>> expungedSearches;
    /**
    If present, this is a list of non-expunged LinkedNotebooks that
       have a USN in this chunk.
    */
    Optional<QList<LinkedNotebook>> linkedNotebooks;
    /**
    If present, the GUIDs of all of the LinkedNotebooks
       that were permanently expunged in this chunk.
    */
    Optional<QList<Guid>> expungedLinkedNotebooks;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const SyncChunk & other) const
    {
        return (currentTime == other.currentTime)
            && chunkHighUSN.isEqual(other.chunkHighUSN)
            && (updateCount == other.updateCount)
            && notes.isEqual(other.notes)
            && notebooks.isEqual(other.notebooks)
            && tags.isEqual(other.tags)
            && searches.isEqual(other.searches)
            && resources.isEqual(other.resources)
            && expungedNotes.isEqual(other.expungedNotes)
            && expungedNotebooks.isEqual(other.expungedNotebooks)
            && expungedTags.isEqual(other.expungedTags)
            && expungedSearches.isEqual(other.expungedSearches)
            && linkedNotebooks.isEqual(other.linkedNotebooks)
            && expungedLinkedNotebooks.isEqual(other.expungedLinkedNotebooks)
        ;
    }

    bool operator!=(const SyncChunk & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Timestamp currentTime MEMBER currentTime)
    Q_PROPERTY(Optional<qint32> chunkHighUSN MEMBER chunkHighUSN)
    Q_PROPERTY(qint32 updateCount MEMBER updateCount)
    Q_PROPERTY(Optional<QList<Note>> notes MEMBER notes)
    Q_PROPERTY(Optional<QList<Notebook>> notebooks MEMBER notebooks)
    Q_PROPERTY(Optional<QList<Tag>> tags MEMBER tags)
    Q_PROPERTY(Optional<QList<SavedSearch>> searches MEMBER searches)
    Q_PROPERTY(Optional<QList<Resource>> resources MEMBER resources)
    Q_PROPERTY(Optional<QList<Guid>> expungedNotes MEMBER expungedNotes)
    Q_PROPERTY(Optional<QList<Guid>> expungedNotebooks MEMBER expungedNotebooks)
    Q_PROPERTY(Optional<QList<Guid>> expungedTags MEMBER expungedTags)
    Q_PROPERTY(Optional<QList<Guid>> expungedSearches MEMBER expungedSearches)
    Q_PROPERTY(Optional<QList<LinkedNotebook>> linkedNotebooks MEMBER linkedNotebooks)
    Q_PROPERTY(Optional<QList<Guid>> expungedLinkedNotebooks MEMBER expungedLinkedNotebooks)
};

/**
 * A small structure for returning a list of notes out of a larger set.
 *
 **/
struct QEVERCLOUD_EXPORT NoteList: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The starting index within the overall set of notes.  This
       is also the number of notes that are "before" this list in the set.
    */
    qint32 startIndex = 0;
    /**
    The number of notes in the larger set.  This can be used
       to calculate how many notes are "after" this note in the set.
       (I.e.  remaining = totalNotes - (startIndex + notes.length)  )
    */
    qint32 totalNotes = 0;
    /**
    The list of notes from this range.  The Notes will include all
       metadata (attributes, resources, etc.), but will not include the ENML
       content of the note or the binary contents of any resources.
    */
    QList<Note> notes;
    /**
    If the NoteList was produced using a text based search
       query that included words that are not indexed or searched by the service,
       this will include a list of those ignored words.
    */
    Optional<QStringList> stoppedWords;
    /**
    If the NoteList was produced using a text based search
       query that included viable search words or quoted expressions, this will
       include a list of those words.  Any stopped words will not be included
       in this list.
    */
    Optional<QStringList> searchedWords;
    /**
    Indicates the total number of transactions that have
       been committed within the account.  This reflects (for example) the
       number of discrete additions or modifications that have been made to
       the data in this account (tags, notes, resources, etc.).
       This number is the "high water mark" for Update Sequence Numbers (USN)
       within the account.
    */
    Optional<qint32> updateCount;
    /**
    Specifies the correlating information about the current search session, in byte array.
    */
    Optional<QByteArray> searchContextBytes;
    /**
    Depends on the value of <code>context</code> in NoteFilter, this field
       may contain debug information if the service decides to do so.
    */
    Optional<QString> debugInfo;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NoteList & other) const
    {
        return (startIndex == other.startIndex)
            && (totalNotes == other.totalNotes)
            && (notes == other.notes)
            && stoppedWords.isEqual(other.stoppedWords)
            && searchedWords.isEqual(other.searchedWords)
            && updateCount.isEqual(other.updateCount)
            && searchContextBytes.isEqual(other.searchContextBytes)
            && debugInfo.isEqual(other.debugInfo)
        ;
    }

    bool operator!=(const NoteList & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(qint32 startIndex MEMBER startIndex)
    Q_PROPERTY(qint32 totalNotes MEMBER totalNotes)
    Q_PROPERTY(QList<Note> notes MEMBER notes)
    Q_PROPERTY(Optional<QStringList> stoppedWords MEMBER stoppedWords)
    Q_PROPERTY(Optional<QStringList> searchedWords MEMBER searchedWords)
    Q_PROPERTY(Optional<qint32> updateCount MEMBER updateCount)
    Q_PROPERTY(Optional<QByteArray> searchContextBytes MEMBER searchContextBytes)
    Q_PROPERTY(Optional<QString> debugInfo MEMBER debugInfo)
};

/**
 * This structure is used in the set of results returned by the
 * findNotesMetadata function.  It represents the high-level information about
 * a single Note, without some of the larger deep structure.  This allows
 * for the information about a list of Notes to be returned relatively quickly
 * with less marshalling and data transfer to remote clients.
 * Most fields in this structure are identical to the corresponding field in
 * the Note structure, with the exception of:
 *
 * */
struct QEVERCLOUD_EXPORT NoteMetadata: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /** NOT DOCUMENTED */
    Guid guid;
    /** NOT DOCUMENTED */
    Optional<QString> title;
    /** NOT DOCUMENTED */
    Optional<qint32> contentLength;
    /** NOT DOCUMENTED */
    Optional<Timestamp> created;
    /** NOT DOCUMENTED */
    Optional<Timestamp> updated;
    /** NOT DOCUMENTED */
    Optional<Timestamp> deleted;
    /** NOT DOCUMENTED */
    Optional<qint32> updateSequenceNum;
    /** NOT DOCUMENTED */
    Optional<QString> notebookGuid;
    /** NOT DOCUMENTED */
    Optional<QList<Guid>> tagGuids;
    /** NOT DOCUMENTED */
    Optional<NoteAttributes> attributes;
    /**
    If set, then this will contain the MIME type of the largest Resource
       (in bytes) within the Note.  This may be useful, for example, to choose
       an appropriate icon or thumbnail to represent the Note.
    */
    Optional<QString> largestResourceMime;
    /**
    If set, this will contain the size of the largest Resource file, in
      bytes, within the Note.  This may be useful, for example, to decide whether
      to ask the server for a thumbnail to represent the Note.
    */
    Optional<qint32> largestResourceSize;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NoteMetadata & other) const
    {
        return (guid == other.guid)
            && title.isEqual(other.title)
            && contentLength.isEqual(other.contentLength)
            && created.isEqual(other.created)
            && updated.isEqual(other.updated)
            && deleted.isEqual(other.deleted)
            && updateSequenceNum.isEqual(other.updateSequenceNum)
            && notebookGuid.isEqual(other.notebookGuid)
            && tagGuids.isEqual(other.tagGuids)
            && attributes.isEqual(other.attributes)
            && largestResourceMime.isEqual(other.largestResourceMime)
            && largestResourceSize.isEqual(other.largestResourceSize)
        ;
    }

    bool operator!=(const NoteMetadata & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Guid guid MEMBER guid)
    Q_PROPERTY(Optional<QString> title MEMBER title)
    Q_PROPERTY(Optional<qint32> contentLength MEMBER contentLength)
    Q_PROPERTY(Optional<Timestamp> created MEMBER created)
    Q_PROPERTY(Optional<Timestamp> updated MEMBER updated)
    Q_PROPERTY(Optional<Timestamp> deleted MEMBER deleted)
    Q_PROPERTY(Optional<qint32> updateSequenceNum MEMBER updateSequenceNum)
    Q_PROPERTY(Optional<QString> notebookGuid MEMBER notebookGuid)
    Q_PROPERTY(Optional<QList<Guid>> tagGuids MEMBER tagGuids)
    Q_PROPERTY(Optional<NoteAttributes> attributes MEMBER attributes)
    Q_PROPERTY(Optional<QString> largestResourceMime MEMBER largestResourceMime)
    Q_PROPERTY(Optional<qint32> largestResourceSize MEMBER largestResourceSize)
};

/**
 * This structure is returned from calls to the findNotesMetadata function to
 * give the high-level metadata about a subset of Notes that are found to
 * match a specified NoteFilter in a search.
 *
 **/
struct QEVERCLOUD_EXPORT NotesMetadataList: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The starting index within the overall set of notes.  This
       is also the number of notes that are "before" this list in the set.
    */
    qint32 startIndex = 0;
    /**
    The number of notes in the larger set.  This can be used
       to calculate how many notes are "after" this note in the set.
       (I.e.  remaining = totalNotes - (startIndex + notes.length)  )
    */
    qint32 totalNotes = 0;
    /**
    The list of metadata for Notes in this range.  The set of optional fields
       that are set in each metadata structure will depend on the
       NotesMetadataResultSpec provided by the caller when the search was
       performed.  Only the 'guid' field will be guaranteed to be set in each
       Note.
    */
    QList<NoteMetadata> notes;
    /**
    If the NoteList was produced using a text based search
       query that included words that are not indexed or searched by the service,
       this will include a list of those ignored words.
    */
    Optional<QStringList> stoppedWords;
    /**
    If the NoteList was produced using a text based search
       query that included viable search words or quoted expressions, this will
       include a list of those words.  Any stopped words will not be included
       in this list.
    */
    Optional<QStringList> searchedWords;
    /**
    Indicates the total number of transactions that have
       been committed within the account.  This reflects (for example) the
       number of discrete additions or modifications that have been made to
       the data in this account (tags, notes, resources, etc.).
       This number is the "high water mark" for Update Sequence Numbers (USN)
       within the account.
    */
    Optional<qint32> updateCount;
    /**
    Specifies the correlating information about the current search session, in byte array.
    */
    Optional<QByteArray> searchContextBytes;
    /**
    Depends on the value of <code>context</code> in NoteFilter, this field
       may contain debug information if the service decides to do so.
    */
    Optional<QString> debugInfo;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NotesMetadataList & other) const
    {
        return (startIndex == other.startIndex)
            && (totalNotes == other.totalNotes)
            && (notes == other.notes)
            && stoppedWords.isEqual(other.stoppedWords)
            && searchedWords.isEqual(other.searchedWords)
            && updateCount.isEqual(other.updateCount)
            && searchContextBytes.isEqual(other.searchContextBytes)
            && debugInfo.isEqual(other.debugInfo)
        ;
    }

    bool operator!=(const NotesMetadataList & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(qint32 startIndex MEMBER startIndex)
    Q_PROPERTY(qint32 totalNotes MEMBER totalNotes)
    Q_PROPERTY(QList<NoteMetadata> notes MEMBER notes)
    Q_PROPERTY(Optional<QStringList> stoppedWords MEMBER stoppedWords)
    Q_PROPERTY(Optional<QStringList> searchedWords MEMBER searchedWords)
    Q_PROPERTY(Optional<qint32> updateCount MEMBER updateCount)
    Q_PROPERTY(Optional<QByteArray> searchContextBytes MEMBER searchContextBytes)
    Q_PROPERTY(Optional<QString> debugInfo MEMBER debugInfo)
};

/**
 * Parameters that must be given to the NoteStore emailNote call. These allow
 * the caller to specify the note to send, the recipient addresses, etc.
 *
 * */
struct QEVERCLOUD_EXPORT NoteEmailParameters: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    If set, this must be the GUID of a note within the user's account that
          should be retrieved from the service and sent as email.  If not set,
          the 'note' field must be provided instead.
    */
    Optional<QString> guid;
    /**
    If the 'guid' field is not set, this field must be provided, including
          the full contents of the note note (and all of its Resources) to send.
          This can be used for a Note that as not been created in the service,
          for example by a local client with local notes.
    */
    Optional<Note> note;
    /**
    If provided, this should contain a list of the SMTP email addresses
          that should be included in the "To:" line of the email.
          Callers must specify at least one "to" or "cc" email address.
    */
    Optional<QStringList> toAddresses;
    /**
    If provided, this should contain a list of the SMTP email addresses
          that should be included in the "Cc:" line of the email.
          Callers must specify at least one "to" or "cc" email address.
    */
    Optional<QStringList> ccAddresses;
    /**
    If provided, this should contain the subject line of the email that
          will be sent.  If not provided, the title of the note will be used
          as the subject of the email.
    */
    Optional<QString> subject;
    /**
    If provided, this is additional personal text that should be included
          into the email as a message from the owner to the recipient(s).
    */
    Optional<QString> message;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NoteEmailParameters & other) const
    {
        return guid.isEqual(other.guid)
            && note.isEqual(other.note)
            && toAddresses.isEqual(other.toAddresses)
            && ccAddresses.isEqual(other.ccAddresses)
            && subject.isEqual(other.subject)
            && message.isEqual(other.message)
        ;
    }

    bool operator!=(const NoteEmailParameters & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> guid MEMBER guid)
    Q_PROPERTY(Optional<Note> note MEMBER note)
    Q_PROPERTY(Optional<QStringList> toAddresses MEMBER toAddresses)
    Q_PROPERTY(Optional<QStringList> ccAddresses MEMBER ccAddresses)
    Q_PROPERTY(Optional<QString> subject MEMBER subject)
    Q_PROPERTY(Optional<QString> message MEMBER message)
};

/**
 * The result of calling findRelated().  The contents of the notes,
 * notebooks, and tags fields will be in decreasing order of expected
 * relevance.  It is possible that fewer results than requested will be
 * returned even if there are enough distinct entities in the account
 * in cases where the relevance is estimated to be low.
 *
 * */
struct QEVERCLOUD_EXPORT RelatedResult: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    If notes have been requested to be included, this will be the
         list of notes.
    */
    Optional<QList<Note>> notes;
    /**
    If notebooks have been requested to be included, this will be the
         list of notebooks.
    */
    Optional<QList<Notebook>> notebooks;
    /**
    If tags have been requested to be included, this will be the list
         of tags.
    */
    Optional<QList<Tag>> tags;
    /**
    If <code>includeContainingNotebooks</code> is set to <code>true</code>
         in the RelatedResultSpec, return the list of notebooks to
         to which the returned related notes belong. The notebooks in this
         list will occur once per notebook GUID and are represented as
         NotebookDescriptor objects.
    */
    Optional<QList<NotebookDescriptor>> containingNotebooks;
    /** NOT DOCUMENTED */
    Optional<QString> debugInfo;
    /**
    If experts have been requested to be included, this will return
      a list of users within your business who have knowledge about the specified query.
    */
    Optional<QList<UserProfile>> experts;
    /**
    If related content has been requested to be included, this will be the list of
      related content snippets.
    */
    Optional<QList<RelatedContent>> relatedContent;
    /**
    If set and non-empty, this cache key may be used in subsequent
         "NoteStore.findRelated" calls (via "RelatedQuery") to re-use previous
         responses that were cached on the client-side, instead of actually performing
         another search.
    
         If set to an empty string, this indicates that the server could not determine
         a specific key for this response, but the client should nevertheless remove
         any previously cached result for this request.
    
         If unset/null, it is up to the client whether to re-use cached results or to
         use the server's response.
    
         If set to the exact non-empty cache key that was specified in
         "RelatedQuery.cacheKey", this indicates that the server decided that cached results
         could be reused.
    
         Depending on the cache key specified in the query, the "RelatedResult" may only be
         partially filled. For each set field, the client should replace the corresponding
         part in the previously cached result with the new partial result.
    
         For example, for a specific query that has both "RelatedResultSpec.maxNotes" and
         "RelatedResultSpec.maxRelatedContent" set to positive values, the server may decide
         that the previously requested and cached <em>Related Content</em> are unchanged,
         but new results for <em>Related Notes</em> are available. The
         response will have a new cache key and have "RelatedResult.notes" set, but have
         "RelatedResult.relatedContent" unset (not just empty, but really unset).
    
         In this situation, the client should replace any cached notes with the newly
         returned "RelatedResult.notes", but it can re-use the previously cached entries for
         "RelatedResult.relatedContent". List fields that are set, but empty indicate that
         no results could be found; the cache should be updated correspondingly.
    */
    Optional<QString> cacheKey;
    /**
    If set, clients should reuse this response for any situations where the same input
          parameters are applicable for up to this many seconds after receiving this result.
    
          After this time has passed, the client may request a new result from the service,
          but it should supply the stored cacheKey to the service when checking for an
          update.
    */
    Optional<qint32> cacheExpires;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const RelatedResult & other) const
    {
        return notes.isEqual(other.notes)
            && notebooks.isEqual(other.notebooks)
            && tags.isEqual(other.tags)
            && containingNotebooks.isEqual(other.containingNotebooks)
            && debugInfo.isEqual(other.debugInfo)
            && experts.isEqual(other.experts)
            && relatedContent.isEqual(other.relatedContent)
            && cacheKey.isEqual(other.cacheKey)
            && cacheExpires.isEqual(other.cacheExpires)
        ;
    }

    bool operator!=(const RelatedResult & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QList<Note>> notes MEMBER notes)
    Q_PROPERTY(Optional<QList<Notebook>> notebooks MEMBER notebooks)
    Q_PROPERTY(Optional<QList<Tag>> tags MEMBER tags)
    Q_PROPERTY(Optional<QList<NotebookDescriptor>> containingNotebooks MEMBER containingNotebooks)
    Q_PROPERTY(Optional<QString> debugInfo MEMBER debugInfo)
    Q_PROPERTY(Optional<QList<UserProfile>> experts MEMBER experts)
    Q_PROPERTY(Optional<QList<RelatedContent>> relatedContent MEMBER relatedContent)
    Q_PROPERTY(Optional<QString> cacheKey MEMBER cacheKey)
    Q_PROPERTY(Optional<qint32> cacheExpires MEMBER cacheExpires)
};

/**
 * The result of a call to updateNoteIfUsnMatches, which optionally updates a note
 * based on the current value of the note's update sequence number on the service.
 *
 * */
struct QEVERCLOUD_EXPORT UpdateNoteIfUsnMatchesResult: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    Either the current state of the note if <tt>updated</tt> is false or the
     result of updating the note as would be done via the <tt>updateNote</tt> method.
     If the note was not updated, you will receive a Note that does not include note
     content, resources data, resources recognition data, or resources alternate data.
     You can check for updates to these large objects by checking the Data.bodyHash
     values and downloading accordingly.
    */
    Optional<Note> note;
    /**
    Whether or not the note was updated by the operation.
    */
    Optional<bool> updated;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const UpdateNoteIfUsnMatchesResult & other) const
    {
        return note.isEqual(other.note)
            && updated.isEqual(other.updated)
        ;
    }

    bool operator!=(const UpdateNoteIfUsnMatchesResult & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<Note> note MEMBER note)
    Q_PROPERTY(Optional<bool> updated MEMBER updated)
};

/**
 * Describes an invitation to a person to use their Evernote
 * credentials to become a member of a notebook.
 *
 * */
struct QEVERCLOUD_EXPORT InvitationShareRelationship: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The string that clients should show to users to represent this
     invitation.
    */
    Optional<QString> displayName;
    /**
    Identifies the recipient of the invitation. The user identity
     type can be either EMAIL, EVERNOTE or IDENTITYID. If the
     invitation was created using the classic notebook sharing APIs it will be EMAIL. If it
     was created using the new identity-based notebook sharing APIs it will either be
     EVERNOTE or IDENTITYID, depending on whether we can map the identity to an Evernote
     user at the time of creation.
    */
    Optional<UserIdentity> recipientUserIdentity;
    /**
    The privilege level at which the member will be joined, if it
     turns out that the member is not already joined at a higher level.
     Note that the <tt>identity</tt> field may not uniquely identify an
     Evernote User ID, and so we won't know until the invitation is
     redeemed whether or not the recipient already has privilege.
    */
    Optional<ShareRelationshipPrivilegeLevel> privilege;
    /**
    The user id of the user who most recently shared this notebook
     to this identity. This field is used by the service to convey information
     to the user, so clients should treat it as read-only.
    */
    Optional<UserID> sharerUserId;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const InvitationShareRelationship & other) const
    {
        return displayName.isEqual(other.displayName)
            && recipientUserIdentity.isEqual(other.recipientUserIdentity)
            && privilege.isEqual(other.privilege)
            && sharerUserId.isEqual(other.sharerUserId)
        ;
    }

    bool operator!=(const InvitationShareRelationship & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> displayName MEMBER displayName)
    Q_PROPERTY(Optional<UserIdentity> recipientUserIdentity MEMBER recipientUserIdentity)
    Q_PROPERTY(Optional<ShareRelationshipPrivilegeLevel> privilege MEMBER privilege)
    Q_PROPERTY(Optional<UserID> sharerUserId MEMBER sharerUserId)
};

/**
 * Captures a collection of share relationships for a notebook, for
 * example, as returned by the getNotebookShares method.  The share
 * relationships fall into two broad categories: members, and
 * invitations that can be used to become members.
 *
 * */
struct QEVERCLOUD_EXPORT ShareRelationships: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    A list of open invitations that can be redeemed into
     memberships to the notebook.
    */
    Optional<QList<InvitationShareRelationship>> invitations;
    /**
    A list of memberships of the notebook.  A member is identified
     by their Evernote UserID and has rights to access the
     notebook.
    */
    Optional<QList<MemberShareRelationship>> memberships;
    /**
    The restrictions on what privileges may be granted to invitees
     to this notebook. These restrictions may be specific to the calling
     user or to the notebook itself. They represent the
     union of all possible invite cases, so it is possible that once the
     recipient of the invitation has been identified by the service, such
     as by a business auto-join, the actual assigned privilege may change.
    */
    Optional<ShareRelationshipRestrictions> invitationRestrictions;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const ShareRelationships & other) const
    {
        return invitations.isEqual(other.invitations)
            && memberships.isEqual(other.memberships)
            && invitationRestrictions.isEqual(other.invitationRestrictions)
        ;
    }

    bool operator!=(const ShareRelationships & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QList<InvitationShareRelationship>> invitations MEMBER invitations)
    Q_PROPERTY(Optional<QList<MemberShareRelationship>> memberships MEMBER memberships)
    Q_PROPERTY(Optional<ShareRelationshipRestrictions> invitationRestrictions MEMBER invitationRestrictions)
};

/**
 * A structure that captures parameters used by clients to manage the
 * shares for a given notebook via the manageNotebookShares method.
 *
 * */
struct QEVERCLOUD_EXPORT ManageNotebookSharesParameters: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The GUID of the notebook whose shares are being managed.
    */
    Optional<QString> notebookGuid;
    /**
    If the service sends a message to invitees, this parameter will
     be used to form the actual message that is sent.
    */
    Optional<QString> inviteMessage;
    /**
    The list of existing memberships to update.  This field is not
     intended to be the full set of memberships for the notebook and
     should only include those already-existing memberships that you
     actually want to change.  If you want to remove shares, see the
     unshares fields.  If you want to create a membership,
     i.e. auto-join a business user, you can do this via the
     invitationsToCreateOrUpdate field using an Evernote UserID of a
     fellow business member (the created invitation is automatically
     joined by the service, so the client is creating an
     invitation, not a membership).
    */
    Optional<QList<MemberShareRelationship>> membershipsToUpdate;
    /**
    The list of invitations to update, as matched by the identity
     field of the InvitationShareRelationship instances, or to create if
     an existing invitation does not exist.  This field is not intended
     to be the full set of invitations on the notebook and should only
     include those invitations that you wish to create or update.  Note
     that your invitation could convert into a membership via a
     service-supported auto-join operation.  This happens, for example,
     when you use an invitation with an Evernote UserID type for a
     recipient who is a member of the business to which the notebook
     belongs.  Note that to discover the user IDs for business members,
     the sharer must also be part of the business.
    */
    Optional<QList<InvitationShareRelationship>> invitationsToCreateOrUpdate;
    /**
    The list of share relationships to expunge from the service.
     If the user identity is for an Evernote UserID, then matching invitations or
     memberships will be removed. If it's an e-mail, then e-mail based shared notebook
     invitations will be removed. If it's for an Identity ID, then any invitations that
     match the identity (by identity ID or user ID or e-mail for legacy invitations) will be
     removed.
    */
    Optional<QList<UserIdentity>> unshares;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const ManageNotebookSharesParameters & other) const
    {
        return notebookGuid.isEqual(other.notebookGuid)
            && inviteMessage.isEqual(other.inviteMessage)
            && membershipsToUpdate.isEqual(other.membershipsToUpdate)
            && invitationsToCreateOrUpdate.isEqual(other.invitationsToCreateOrUpdate)
            && unshares.isEqual(other.unshares)
        ;
    }

    bool operator!=(const ManageNotebookSharesParameters & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QString> notebookGuid MEMBER notebookGuid)
    Q_PROPERTY(Optional<QString> inviteMessage MEMBER inviteMessage)
    Q_PROPERTY(Optional<QList<MemberShareRelationship>> membershipsToUpdate MEMBER membershipsToUpdate)
    Q_PROPERTY(Optional<QList<InvitationShareRelationship>> invitationsToCreateOrUpdate MEMBER invitationsToCreateOrUpdate)
    Q_PROPERTY(Optional<QList<UserIdentity>> unshares MEMBER unshares)
};

/**
 * A structure to capture certain errors that occurred during a call
 * to manageNotebookShares.  That method can be run best-effort,
 * meaning that some change requests can be applied while others fail.
 * Note that some errors such as system errors will still fail the
 * entire transaction regardless of running best effort.  When some
 * change requests do not succeed, the error conditions are captured
 * in instances of this class, captured by the identity of the share
 * relationship and one of the exception fields.
 *
 * */
struct QEVERCLOUD_EXPORT ManageNotebookSharesError: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The identity of the share relationship whose update encountered
     an error.
    */
    Optional<UserIdentity> userIdentity;
    /**
    If the error is represented as an EDAMUserException that would
     have otherwise been thrown without best-effort execution.  Only one
     exception field will be set.
    */
    Optional<EDAMUserException> userException;
    /**
    If the error is represented as an EDAMNotFoundException that would
     have otherwise been thrown without best-effort execution.  Only one
     exception field will be set.
    */
    Optional<EDAMNotFoundException> notFoundException;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const ManageNotebookSharesError & other) const
    {
        return userIdentity.isEqual(other.userIdentity)
            && userException.isEqual(other.userException)
            && notFoundException.isEqual(other.notFoundException)
        ;
    }

    bool operator!=(const ManageNotebookSharesError & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<UserIdentity> userIdentity MEMBER userIdentity)
    Q_PROPERTY(Optional<EDAMUserException> userException MEMBER userException)
    Q_PROPERTY(Optional<EDAMNotFoundException> notFoundException MEMBER notFoundException)
};

/**
 * The return value of a call to the manageNotebookShares method.
 *
 * */
struct QEVERCLOUD_EXPORT ManageNotebookSharesResult: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    If the method completed without throwing exceptions, some errors
     might still have occurred, and in that case, this field will contain
     the list of those errors the occurred.
    */
    Optional<QList<ManageNotebookSharesError>> errors;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const ManageNotebookSharesResult & other) const
    {
        return errors.isEqual(other.errors)
        ;
    }

    bool operator!=(const ManageNotebookSharesResult & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QList<ManageNotebookSharesError>> errors MEMBER errors)
};

/**
 * A structure used to share a note with one or more recipients at a given privilege.
 *
 * */
struct QEVERCLOUD_EXPORT SharedNoteTemplate: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The GUID of the note.
    */
    Optional<Guid> noteGuid;
    /**
    The recipients of the note share specified as a messaging thread ID. If you
           have an existing messaging thread to share the note with, specify its ID
           here instead of recipientContacts in order to properly support defunct
           identities. The sharer must be a participant of the thread. Either this
           field or recipientContacts must be set.
    */
    Optional<MessageThreadID> recipientThreadId;
    /**
    The recipients of the note share specified as a list of contacts. This should
           only be set if the sharing takes place before the thread is created. Use
           recipientThreadId instead when sharing with an existing thread. Either this
           field or recipientThreadId must be set.
    */
    Optional<QList<Contact>> recipientContacts;
    /**
    The privilege level to be granted.
    */
    Optional<SharedNotePrivilegeLevel> privilege;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const SharedNoteTemplate & other) const
    {
        return noteGuid.isEqual(other.noteGuid)
            && recipientThreadId.isEqual(other.recipientThreadId)
            && recipientContacts.isEqual(other.recipientContacts)
            && privilege.isEqual(other.privilege)
        ;
    }

    bool operator!=(const SharedNoteTemplate & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<Guid> noteGuid MEMBER noteGuid)
    Q_PROPERTY(Optional<MessageThreadID> recipientThreadId MEMBER recipientThreadId)
    Q_PROPERTY(Optional<QList<Contact>> recipientContacts MEMBER recipientContacts)
    Q_PROPERTY(Optional<SharedNotePrivilegeLevel> privilege MEMBER privilege)
};

/**
 * A structure used to share a notebook with one or more recipients at a given privilege.
 *
 * */
struct QEVERCLOUD_EXPORT NotebookShareTemplate: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The GUID of the notebook.
    */
    Optional<Guid> notebookGuid;
    /**
    The recipients of the notebook share specified as a messaging thread ID. If you
           have an existing messaging thread to share the note with, specify its ID
           here instead of recipientContacts in order to properly support defunct
           identities. The sharer must be a participant of the thread. Either this field
           or recipientContacts must be set.
    */
    Optional<MessageThreadID> recipientThreadId;
    /**
    The recipients of the notebook share specified as a list of contacts. This should
           only be set if the sharing takes place before the thread is created. Use
           recipientThreadId instead when sharing with an existing thread. Either this
           field or recipientThreadId must be set.
    */
    Optional<QList<Contact>> recipientContacts;
    /**
    The privilege level to be granted.
    */
    Optional<SharedNotebookPrivilegeLevel> privilege;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const NotebookShareTemplate & other) const
    {
        return notebookGuid.isEqual(other.notebookGuid)
            && recipientThreadId.isEqual(other.recipientThreadId)
            && recipientContacts.isEqual(other.recipientContacts)
            && privilege.isEqual(other.privilege)
        ;
    }

    bool operator!=(const NotebookShareTemplate & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<Guid> notebookGuid MEMBER notebookGuid)
    Q_PROPERTY(Optional<MessageThreadID> recipientThreadId MEMBER recipientThreadId)
    Q_PROPERTY(Optional<QList<Contact>> recipientContacts MEMBER recipientContacts)
    Q_PROPERTY(Optional<SharedNotebookPrivilegeLevel> privilege MEMBER privilege)
};

/**
 * A structure containing the results of a call to createOrUpdateNotebookShares.
 *
 * */
struct QEVERCLOUD_EXPORT CreateOrUpdateNotebookSharesResult: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The USN of the notebook after the call.
    */
    Optional<qint32> updateSequenceNum;
    /**
    A list of SharedNotebook records that match the desired recipients. These
           records may have been either created or updated by the call to
           createOrUpdateNotebookShares, or they may have been at the desired privilege
           privilege level prior to the call.
    */
    Optional<QList<SharedNotebook>> matchingShares;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const CreateOrUpdateNotebookSharesResult & other) const
    {
        return updateSequenceNum.isEqual(other.updateSequenceNum)
            && matchingShares.isEqual(other.matchingShares)
        ;
    }

    bool operator!=(const CreateOrUpdateNotebookSharesResult & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<qint32> updateSequenceNum MEMBER updateSequenceNum)
    Q_PROPERTY(Optional<QList<SharedNotebook>> matchingShares MEMBER matchingShares)
};

/**
 * Captures errors that occur during a call to manageNoteShares. That
 * function can be run best-effort, meaning that some change requests can
 * be applied while others fail. Note that some errors such as system
 * exceptions may still cause the entire call to fail.
 *
 * Only one of the two ID fields will be set on a given error.
 *
 * Only one of the two exception fields will be set on a given error.
 *
 * */
struct QEVERCLOUD_EXPORT ManageNoteSharesError: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    The identity ID of an outstanding invitation that was not updated
         due to the error.
    */
    Optional<IdentityID> identityID;
    /**
    The user ID of an existing membership that was not updated due
         to the error.
    */
    Optional<UserID> userID;
    /**
    If the error is represented as an EDAMUserException that would
         have otherwise been thrown without best-effort execution.
    */
    Optional<EDAMUserException> userException;
    /**
    If the error is represented as an EDAMNotFoundException that
         would have otherwise been thrown without best-effort execution.
         The identifier field of the exception will be either "Identity.id"
         or "User.id", indicating that no existing share could be found for
         the specified recipient.
    */
    Optional<EDAMNotFoundException> notFoundException;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const ManageNoteSharesError & other) const
    {
        return identityID.isEqual(other.identityID)
            && userID.isEqual(other.userID)
            && userException.isEqual(other.userException)
            && notFoundException.isEqual(other.notFoundException)
        ;
    }

    bool operator!=(const ManageNoteSharesError & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<IdentityID> identityID MEMBER identityID)
    Q_PROPERTY(Optional<UserID> userID MEMBER userID)
    Q_PROPERTY(Optional<EDAMUserException> userException MEMBER userException)
    Q_PROPERTY(Optional<EDAMNotFoundException> notFoundException MEMBER notFoundException)
};

/**
 * The return value of a call to the manageNoteShares function.
 *
 * */
struct QEVERCLOUD_EXPORT ManageNoteSharesResult: public Printable
{
private:
    Q_GADGET
public:
    /**
     * See the declaration of EverCloudLocalData for details
     */
    EverCloudLocalData localData;

    /**
    If the call succeeded without throwing an exception, some errors
         might still have occurred. In that case, this field will contain the
         list of errors.
    */
    Optional<QList<ManageNoteSharesError>> errors;

    virtual void print(QTextStream & strm) const override;

    bool operator==(const ManageNoteSharesResult & other) const
    {
        return errors.isEqual(other.errors)
        ;
    }

    bool operator!=(const ManageNoteSharesResult & other) const
    {
        return !(*this == other);
    }

    Q_PROPERTY(EverCloudLocalData localData MEMBER localData)
    Q_PROPERTY(Optional<QList<ManageNoteSharesError>> errors MEMBER errors)
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::EverCloudLocalData)
Q_DECLARE_METATYPE(qevercloud::SyncState)
Q_DECLARE_METATYPE(qevercloud::SyncChunkFilter)
Q_DECLARE_METATYPE(qevercloud::NoteFilter)
Q_DECLARE_METATYPE(qevercloud::NotesMetadataResultSpec)
Q_DECLARE_METATYPE(qevercloud::NoteCollectionCounts)
Q_DECLARE_METATYPE(qevercloud::NoteResultSpec)
Q_DECLARE_METATYPE(qevercloud::NoteVersionId)
Q_DECLARE_METATYPE(qevercloud::RelatedQuery)
Q_DECLARE_METATYPE(qevercloud::RelatedResultSpec)
Q_DECLARE_METATYPE(qevercloud::ShareRelationshipRestrictions)
Q_DECLARE_METATYPE(qevercloud::MemberShareRelationship)
Q_DECLARE_METATYPE(qevercloud::NoteShareRelationshipRestrictions)
Q_DECLARE_METATYPE(qevercloud::NoteMemberShareRelationship)
Q_DECLARE_METATYPE(qevercloud::NoteInvitationShareRelationship)
Q_DECLARE_METATYPE(qevercloud::NoteShareRelationships)
Q_DECLARE_METATYPE(qevercloud::ManageNoteSharesParameters)
Q_DECLARE_METATYPE(qevercloud::Data)
Q_DECLARE_METATYPE(qevercloud::UserAttributes)
Q_DECLARE_METATYPE(qevercloud::BusinessUserAttributes)
Q_DECLARE_METATYPE(qevercloud::Accounting)
Q_DECLARE_METATYPE(qevercloud::BusinessUserInfo)
Q_DECLARE_METATYPE(qevercloud::AccountLimits)
Q_DECLARE_METATYPE(qevercloud::User)
Q_DECLARE_METATYPE(qevercloud::Contact)
Q_DECLARE_METATYPE(qevercloud::Identity)
Q_DECLARE_METATYPE(qevercloud::Tag)
Q_DECLARE_METATYPE(qevercloud::LazyMap)
Q_DECLARE_METATYPE(qevercloud::ResourceAttributes)
Q_DECLARE_METATYPE(qevercloud::Resource)
Q_DECLARE_METATYPE(qevercloud::NoteAttributes)
Q_DECLARE_METATYPE(qevercloud::SharedNote)
Q_DECLARE_METATYPE(qevercloud::NoteRestrictions)
Q_DECLARE_METATYPE(qevercloud::NoteLimits)
Q_DECLARE_METATYPE(qevercloud::Note)
Q_DECLARE_METATYPE(qevercloud::Publishing)
Q_DECLARE_METATYPE(qevercloud::BusinessNotebook)
Q_DECLARE_METATYPE(qevercloud::SavedSearchScope)
Q_DECLARE_METATYPE(qevercloud::SavedSearch)
Q_DECLARE_METATYPE(qevercloud::SharedNotebookRecipientSettings)
Q_DECLARE_METATYPE(qevercloud::NotebookRecipientSettings)
Q_DECLARE_METATYPE(qevercloud::SharedNotebook)
Q_DECLARE_METATYPE(qevercloud::CanMoveToContainerRestrictions)
Q_DECLARE_METATYPE(qevercloud::NotebookRestrictions)
Q_DECLARE_METATYPE(qevercloud::Notebook)
Q_DECLARE_METATYPE(qevercloud::LinkedNotebook)
Q_DECLARE_METATYPE(qevercloud::NotebookDescriptor)
Q_DECLARE_METATYPE(qevercloud::UserProfile)
Q_DECLARE_METATYPE(qevercloud::RelatedContentImage)
Q_DECLARE_METATYPE(qevercloud::RelatedContent)
Q_DECLARE_METATYPE(qevercloud::BusinessInvitation)
Q_DECLARE_METATYPE(qevercloud::UserIdentity)
Q_DECLARE_METATYPE(qevercloud::PublicUserInfo)
Q_DECLARE_METATYPE(qevercloud::UserUrls)
Q_DECLARE_METATYPE(qevercloud::AuthenticationResult)
Q_DECLARE_METATYPE(qevercloud::BootstrapSettings)
Q_DECLARE_METATYPE(qevercloud::BootstrapProfile)
Q_DECLARE_METATYPE(qevercloud::BootstrapInfo)
Q_DECLARE_METATYPE(qevercloud::EDAMUserException)
Q_DECLARE_METATYPE(qevercloud::EDAMSystemException)
Q_DECLARE_METATYPE(qevercloud::EDAMNotFoundException)
Q_DECLARE_METATYPE(qevercloud::EDAMInvalidContactsException)
Q_DECLARE_METATYPE(qevercloud::SyncChunk)
Q_DECLARE_METATYPE(qevercloud::NoteList)
Q_DECLARE_METATYPE(qevercloud::NoteMetadata)
Q_DECLARE_METATYPE(qevercloud::NotesMetadataList)
Q_DECLARE_METATYPE(qevercloud::NoteEmailParameters)
Q_DECLARE_METATYPE(qevercloud::RelatedResult)
Q_DECLARE_METATYPE(qevercloud::UpdateNoteIfUsnMatchesResult)
Q_DECLARE_METATYPE(qevercloud::InvitationShareRelationship)
Q_DECLARE_METATYPE(qevercloud::ShareRelationships)
Q_DECLARE_METATYPE(qevercloud::ManageNotebookSharesParameters)
Q_DECLARE_METATYPE(qevercloud::ManageNotebookSharesError)
Q_DECLARE_METATYPE(qevercloud::ManageNotebookSharesResult)
Q_DECLARE_METATYPE(qevercloud::SharedNoteTemplate)
Q_DECLARE_METATYPE(qevercloud::NotebookShareTemplate)
Q_DECLARE_METATYPE(qevercloud::CreateOrUpdateNotebookSharesResult)
Q_DECLARE_METATYPE(qevercloud::ManageNoteSharesError)
Q_DECLARE_METATYPE(qevercloud::ManageNoteSharesResult)


#endif // QEVERCLOUD_GENERATED_TYPES_H
