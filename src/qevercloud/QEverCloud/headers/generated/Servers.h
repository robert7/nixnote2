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

#ifndef QEVERCLOUD_GENERATED_SERVERS_H
#define QEVERCLOUD_GENERATED_SERVERS_H

#include "../Export.h"

#include "../Optional.h"
#include "../RequestContext.h"
#include "Constants.h"
#include "Types.h"
#include <QObject>
#include <functional>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief The NoteStoreServer class represents
 * customizable server for NoteStore requests.
 * It is primarily used for testing of QEverCloud
 */
class QEVERCLOUD_EXPORT NoteStoreServer: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(NoteStoreServer)
public:
    explicit NoteStoreServer(QObject * parent = nullptr);

Q_SIGNALS:
    // Signals notifying listeners about incoming requests
    void getSyncStateRequest(
        IRequestContextPtr ctx);

    void getFilteredSyncChunkRequest(
        qint32 afterUSN,
        qint32 maxEntries,
        SyncChunkFilter filter,
        IRequestContextPtr ctx);

    void getLinkedNotebookSyncStateRequest(
        LinkedNotebook linkedNotebook,
        IRequestContextPtr ctx);

    void getLinkedNotebookSyncChunkRequest(
        LinkedNotebook linkedNotebook,
        qint32 afterUSN,
        qint32 maxEntries,
        bool fullSyncOnly,
        IRequestContextPtr ctx);

    void listNotebooksRequest(
        IRequestContextPtr ctx);

    void listAccessibleBusinessNotebooksRequest(
        IRequestContextPtr ctx);

    void getNotebookRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getDefaultNotebookRequest(
        IRequestContextPtr ctx);

    void createNotebookRequest(
        Notebook notebook,
        IRequestContextPtr ctx);

    void updateNotebookRequest(
        Notebook notebook,
        IRequestContextPtr ctx);

    void expungeNotebookRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void listTagsRequest(
        IRequestContextPtr ctx);

    void listTagsByNotebookRequest(
        Guid notebookGuid,
        IRequestContextPtr ctx);

    void getTagRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void createTagRequest(
        Tag tag,
        IRequestContextPtr ctx);

    void updateTagRequest(
        Tag tag,
        IRequestContextPtr ctx);

    void untagAllRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void expungeTagRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void listSearchesRequest(
        IRequestContextPtr ctx);

    void getSearchRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void createSearchRequest(
        SavedSearch search,
        IRequestContextPtr ctx);

    void updateSearchRequest(
        SavedSearch search,
        IRequestContextPtr ctx);

    void expungeSearchRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void findNoteOffsetRequest(
        NoteFilter filter,
        Guid guid,
        IRequestContextPtr ctx);

    void findNotesMetadataRequest(
        NoteFilter filter,
        qint32 offset,
        qint32 maxNotes,
        NotesMetadataResultSpec resultSpec,
        IRequestContextPtr ctx);

    void findNoteCountsRequest(
        NoteFilter filter,
        bool withTrash,
        IRequestContextPtr ctx);

    void getNoteWithResultSpecRequest(
        Guid guid,
        NoteResultSpec resultSpec,
        IRequestContextPtr ctx);

    void getNoteRequest(
        Guid guid,
        bool withContent,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx);

    void getNoteApplicationDataRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getNoteApplicationDataEntryRequest(
        Guid guid,
        QString key,
        IRequestContextPtr ctx);

    void setNoteApplicationDataEntryRequest(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx);

    void unsetNoteApplicationDataEntryRequest(
        Guid guid,
        QString key,
        IRequestContextPtr ctx);

    void getNoteContentRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getNoteSearchTextRequest(
        Guid guid,
        bool noteOnly,
        bool tokenizeForIndexing,
        IRequestContextPtr ctx);

    void getResourceSearchTextRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getNoteTagNamesRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void createNoteRequest(
        Note note,
        IRequestContextPtr ctx);

    void updateNoteRequest(
        Note note,
        IRequestContextPtr ctx);

    void deleteNoteRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void expungeNoteRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void copyNoteRequest(
        Guid noteGuid,
        Guid toNotebookGuid,
        IRequestContextPtr ctx);

    void listNoteVersionsRequest(
        Guid noteGuid,
        IRequestContextPtr ctx);

    void getNoteVersionRequest(
        Guid noteGuid,
        qint32 updateSequenceNum,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx);

    void getResourceRequest(
        Guid guid,
        bool withData,
        bool withRecognition,
        bool withAttributes,
        bool withAlternateData,
        IRequestContextPtr ctx);

    void getResourceApplicationDataRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getResourceApplicationDataEntryRequest(
        Guid guid,
        QString key,
        IRequestContextPtr ctx);

    void setResourceApplicationDataEntryRequest(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx);

    void unsetResourceApplicationDataEntryRequest(
        Guid guid,
        QString key,
        IRequestContextPtr ctx);

    void updateResourceRequest(
        Resource resource,
        IRequestContextPtr ctx);

    void getResourceDataRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getResourceByHashRequest(
        Guid noteGuid,
        QByteArray contentHash,
        bool withData,
        bool withRecognition,
        bool withAlternateData,
        IRequestContextPtr ctx);

    void getResourceRecognitionRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getResourceAlternateDataRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getResourceAttributesRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void getPublicNotebookRequest(
        UserID userId,
        QString publicUri,
        IRequestContextPtr ctx);

    void shareNotebookRequest(
        SharedNotebook sharedNotebook,
        QString message,
        IRequestContextPtr ctx);

    void createOrUpdateNotebookSharesRequest(
        NotebookShareTemplate shareTemplate,
        IRequestContextPtr ctx);

    void updateSharedNotebookRequest(
        SharedNotebook sharedNotebook,
        IRequestContextPtr ctx);

    void setNotebookRecipientSettingsRequest(
        QString notebookGuid,
        NotebookRecipientSettings recipientSettings,
        IRequestContextPtr ctx);

    void listSharedNotebooksRequest(
        IRequestContextPtr ctx);

    void createLinkedNotebookRequest(
        LinkedNotebook linkedNotebook,
        IRequestContextPtr ctx);

    void updateLinkedNotebookRequest(
        LinkedNotebook linkedNotebook,
        IRequestContextPtr ctx);

    void listLinkedNotebooksRequest(
        IRequestContextPtr ctx);

    void expungeLinkedNotebookRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void authenticateToSharedNotebookRequest(
        QString shareKeyOrGlobalId,
        IRequestContextPtr ctx);

    void getSharedNotebookByAuthRequest(
        IRequestContextPtr ctx);

    void emailNoteRequest(
        NoteEmailParameters parameters,
        IRequestContextPtr ctx);

    void shareNoteRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void stopSharingNoteRequest(
        Guid guid,
        IRequestContextPtr ctx);

    void authenticateToSharedNoteRequest(
        QString guid,
        QString noteKey,
        IRequestContextPtr ctx);

    void findRelatedRequest(
        RelatedQuery query,
        RelatedResultSpec resultSpec,
        IRequestContextPtr ctx);

    void updateNoteIfUsnMatchesRequest(
        Note note,
        IRequestContextPtr ctx);

    void manageNotebookSharesRequest(
        ManageNotebookSharesParameters parameters,
        IRequestContextPtr ctx);

    void getNotebookSharesRequest(
        QString notebookGuid,
        IRequestContextPtr ctx);

    // Signals used to send encoded response data
    void getSyncStateRequestReady(
        QByteArray data);

    void getFilteredSyncChunkRequestReady(
        QByteArray data);

    void getLinkedNotebookSyncStateRequestReady(
        QByteArray data);

    void getLinkedNotebookSyncChunkRequestReady(
        QByteArray data);

    void listNotebooksRequestReady(
        QByteArray data);

    void listAccessibleBusinessNotebooksRequestReady(
        QByteArray data);

    void getNotebookRequestReady(
        QByteArray data);

    void getDefaultNotebookRequestReady(
        QByteArray data);

    void createNotebookRequestReady(
        QByteArray data);

    void updateNotebookRequestReady(
        QByteArray data);

    void expungeNotebookRequestReady(
        QByteArray data);

    void listTagsRequestReady(
        QByteArray data);

    void listTagsByNotebookRequestReady(
        QByteArray data);

    void getTagRequestReady(
        QByteArray data);

    void createTagRequestReady(
        QByteArray data);

    void updateTagRequestReady(
        QByteArray data);

    void untagAllRequestReady(
        QByteArray data);

    void expungeTagRequestReady(
        QByteArray data);

    void listSearchesRequestReady(
        QByteArray data);

    void getSearchRequestReady(
        QByteArray data);

    void createSearchRequestReady(
        QByteArray data);

    void updateSearchRequestReady(
        QByteArray data);

    void expungeSearchRequestReady(
        QByteArray data);

    void findNoteOffsetRequestReady(
        QByteArray data);

    void findNotesMetadataRequestReady(
        QByteArray data);

    void findNoteCountsRequestReady(
        QByteArray data);

    void getNoteWithResultSpecRequestReady(
        QByteArray data);

    void getNoteRequestReady(
        QByteArray data);

    void getNoteApplicationDataRequestReady(
        QByteArray data);

    void getNoteApplicationDataEntryRequestReady(
        QByteArray data);

    void setNoteApplicationDataEntryRequestReady(
        QByteArray data);

    void unsetNoteApplicationDataEntryRequestReady(
        QByteArray data);

    void getNoteContentRequestReady(
        QByteArray data);

    void getNoteSearchTextRequestReady(
        QByteArray data);

    void getResourceSearchTextRequestReady(
        QByteArray data);

    void getNoteTagNamesRequestReady(
        QByteArray data);

    void createNoteRequestReady(
        QByteArray data);

    void updateNoteRequestReady(
        QByteArray data);

    void deleteNoteRequestReady(
        QByteArray data);

    void expungeNoteRequestReady(
        QByteArray data);

    void copyNoteRequestReady(
        QByteArray data);

    void listNoteVersionsRequestReady(
        QByteArray data);

    void getNoteVersionRequestReady(
        QByteArray data);

    void getResourceRequestReady(
        QByteArray data);

    void getResourceApplicationDataRequestReady(
        QByteArray data);

    void getResourceApplicationDataEntryRequestReady(
        QByteArray data);

    void setResourceApplicationDataEntryRequestReady(
        QByteArray data);

    void unsetResourceApplicationDataEntryRequestReady(
        QByteArray data);

    void updateResourceRequestReady(
        QByteArray data);

    void getResourceDataRequestReady(
        QByteArray data);

    void getResourceByHashRequestReady(
        QByteArray data);

    void getResourceRecognitionRequestReady(
        QByteArray data);

    void getResourceAlternateDataRequestReady(
        QByteArray data);

    void getResourceAttributesRequestReady(
        QByteArray data);

    void getPublicNotebookRequestReady(
        QByteArray data);

    void shareNotebookRequestReady(
        QByteArray data);

    void createOrUpdateNotebookSharesRequestReady(
        QByteArray data);

    void updateSharedNotebookRequestReady(
        QByteArray data);

    void setNotebookRecipientSettingsRequestReady(
        QByteArray data);

    void listSharedNotebooksRequestReady(
        QByteArray data);

    void createLinkedNotebookRequestReady(
        QByteArray data);

    void updateLinkedNotebookRequestReady(
        QByteArray data);

    void listLinkedNotebooksRequestReady(
        QByteArray data);

    void expungeLinkedNotebookRequestReady(
        QByteArray data);

    void authenticateToSharedNotebookRequestReady(
        QByteArray data);

    void getSharedNotebookByAuthRequestReady(
        QByteArray data);

    void emailNoteRequestReady(
        QByteArray data);

    void shareNoteRequestReady(
        QByteArray data);

    void stopSharingNoteRequestReady(
        QByteArray data);

    void authenticateToSharedNoteRequestReady(
        QByteArray data);

    void findRelatedRequestReady(
        QByteArray data);

    void updateNoteIfUsnMatchesRequestReady(
        QByteArray data);

    void manageNotebookSharesRequestReady(
        QByteArray data);

    void getNotebookSharesRequestReady(
        QByteArray data);

public Q_SLOTS:
    // Slot used to deliver requests to the server
    void onRequest(QByteArray data);

    // Slots for replies to requests
    void onGetSyncStateRequestReady(
        SyncState value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetFilteredSyncChunkRequestReady(
        SyncChunk value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetLinkedNotebookSyncStateRequestReady(
        SyncState value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetLinkedNotebookSyncChunkRequestReady(
        SyncChunk value,
        EverCloudExceptionDataPtr exceptionData);

    void onListNotebooksRequestReady(
        QList<Notebook> value,
        EverCloudExceptionDataPtr exceptionData);

    void onListAccessibleBusinessNotebooksRequestReady(
        QList<Notebook> value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetNotebookRequestReady(
        Notebook value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetDefaultNotebookRequestReady(
        Notebook value,
        EverCloudExceptionDataPtr exceptionData);

    void onCreateNotebookRequestReady(
        Notebook value,
        EverCloudExceptionDataPtr exceptionData);

    void onUpdateNotebookRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onExpungeNotebookRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onListTagsRequestReady(
        QList<Tag> value,
        EverCloudExceptionDataPtr exceptionData);

    void onListTagsByNotebookRequestReady(
        QList<Tag> value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetTagRequestReady(
        Tag value,
        EverCloudExceptionDataPtr exceptionData);

    void onCreateTagRequestReady(
        Tag value,
        EverCloudExceptionDataPtr exceptionData);

    void onUpdateTagRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onUntagAllRequestReady(
        EverCloudExceptionDataPtr exceptionData);

    void onExpungeTagRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onListSearchesRequestReady(
        QList<SavedSearch> value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetSearchRequestReady(
        SavedSearch value,
        EverCloudExceptionDataPtr exceptionData);

    void onCreateSearchRequestReady(
        SavedSearch value,
        EverCloudExceptionDataPtr exceptionData);

    void onUpdateSearchRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onExpungeSearchRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onFindNoteOffsetRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onFindNotesMetadataRequestReady(
        NotesMetadataList value,
        EverCloudExceptionDataPtr exceptionData);

    void onFindNoteCountsRequestReady(
        NoteCollectionCounts value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetNoteWithResultSpecRequestReady(
        Note value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetNoteRequestReady(
        Note value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetNoteApplicationDataRequestReady(
        LazyMap value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetNoteApplicationDataEntryRequestReady(
        QString value,
        EverCloudExceptionDataPtr exceptionData);

    void onSetNoteApplicationDataEntryRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onUnsetNoteApplicationDataEntryRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetNoteContentRequestReady(
        QString value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetNoteSearchTextRequestReady(
        QString value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetResourceSearchTextRequestReady(
        QString value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetNoteTagNamesRequestReady(
        QStringList value,
        EverCloudExceptionDataPtr exceptionData);

    void onCreateNoteRequestReady(
        Note value,
        EverCloudExceptionDataPtr exceptionData);

    void onUpdateNoteRequestReady(
        Note value,
        EverCloudExceptionDataPtr exceptionData);

    void onDeleteNoteRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onExpungeNoteRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onCopyNoteRequestReady(
        Note value,
        EverCloudExceptionDataPtr exceptionData);

    void onListNoteVersionsRequestReady(
        QList<NoteVersionId> value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetNoteVersionRequestReady(
        Note value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetResourceRequestReady(
        Resource value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetResourceApplicationDataRequestReady(
        LazyMap value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetResourceApplicationDataEntryRequestReady(
        QString value,
        EverCloudExceptionDataPtr exceptionData);

    void onSetResourceApplicationDataEntryRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onUnsetResourceApplicationDataEntryRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onUpdateResourceRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetResourceDataRequestReady(
        QByteArray value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetResourceByHashRequestReady(
        Resource value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetResourceRecognitionRequestReady(
        QByteArray value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetResourceAlternateDataRequestReady(
        QByteArray value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetResourceAttributesRequestReady(
        ResourceAttributes value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetPublicNotebookRequestReady(
        Notebook value,
        EverCloudExceptionDataPtr exceptionData);

    void onShareNotebookRequestReady(
        SharedNotebook value,
        EverCloudExceptionDataPtr exceptionData);

    void onCreateOrUpdateNotebookSharesRequestReady(
        CreateOrUpdateNotebookSharesResult value,
        EverCloudExceptionDataPtr exceptionData);

    void onUpdateSharedNotebookRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onSetNotebookRecipientSettingsRequestReady(
        Notebook value,
        EverCloudExceptionDataPtr exceptionData);

    void onListSharedNotebooksRequestReady(
        QList<SharedNotebook> value,
        EverCloudExceptionDataPtr exceptionData);

    void onCreateLinkedNotebookRequestReady(
        LinkedNotebook value,
        EverCloudExceptionDataPtr exceptionData);

    void onUpdateLinkedNotebookRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onListLinkedNotebooksRequestReady(
        QList<LinkedNotebook> value,
        EverCloudExceptionDataPtr exceptionData);

    void onExpungeLinkedNotebookRequestReady(
        qint32 value,
        EverCloudExceptionDataPtr exceptionData);

    void onAuthenticateToSharedNotebookRequestReady(
        AuthenticationResult value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetSharedNotebookByAuthRequestReady(
        SharedNotebook value,
        EverCloudExceptionDataPtr exceptionData);

    void onEmailNoteRequestReady(
        EverCloudExceptionDataPtr exceptionData);

    void onShareNoteRequestReady(
        QString value,
        EverCloudExceptionDataPtr exceptionData);

    void onStopSharingNoteRequestReady(
        EverCloudExceptionDataPtr exceptionData);

    void onAuthenticateToSharedNoteRequestReady(
        AuthenticationResult value,
        EverCloudExceptionDataPtr exceptionData);

    void onFindRelatedRequestReady(
        RelatedResult value,
        EverCloudExceptionDataPtr exceptionData);

    void onUpdateNoteIfUsnMatchesRequestReady(
        UpdateNoteIfUsnMatchesResult value,
        EverCloudExceptionDataPtr exceptionData);

    void onManageNotebookSharesRequestReady(
        ManageNotebookSharesResult value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetNotebookSharesRequestReady(
        ShareRelationships value,
        EverCloudExceptionDataPtr exceptionData);

};

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief The UserStoreServer class represents
 * customizable server for UserStore requests.
 * It is primarily used for testing of QEverCloud
 */
class QEVERCLOUD_EXPORT UserStoreServer: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(UserStoreServer)
public:
    explicit UserStoreServer(QObject * parent = nullptr);

Q_SIGNALS:
    // Signals notifying listeners about incoming requests
    void checkVersionRequest(
        QString clientName,
        qint16 edamVersionMajor,
        qint16 edamVersionMinor,
        IRequestContextPtr ctx);

    void getBootstrapInfoRequest(
        QString locale,
        IRequestContextPtr ctx);

    void authenticateLongSessionRequest(
        QString username,
        QString password,
        QString consumerKey,
        QString consumerSecret,
        QString deviceIdentifier,
        QString deviceDescription,
        bool supportsTwoFactor,
        IRequestContextPtr ctx);

    void completeTwoFactorAuthenticationRequest(
        QString oneTimeCode,
        QString deviceIdentifier,
        QString deviceDescription,
        IRequestContextPtr ctx);

    void revokeLongSessionRequest(
        IRequestContextPtr ctx);

    void authenticateToBusinessRequest(
        IRequestContextPtr ctx);

    void getUserRequest(
        IRequestContextPtr ctx);

    void getPublicUserInfoRequest(
        QString username,
        IRequestContextPtr ctx);

    void getUserUrlsRequest(
        IRequestContextPtr ctx);

    void inviteToBusinessRequest(
        QString emailAddress,
        IRequestContextPtr ctx);

    void removeFromBusinessRequest(
        QString emailAddress,
        IRequestContextPtr ctx);

    void updateBusinessUserIdentifierRequest(
        QString oldEmailAddress,
        QString newEmailAddress,
        IRequestContextPtr ctx);

    void listBusinessUsersRequest(
        IRequestContextPtr ctx);

    void listBusinessInvitationsRequest(
        bool includeRequestedInvitations,
        IRequestContextPtr ctx);

    void getAccountLimitsRequest(
        ServiceLevel serviceLevel,
        IRequestContextPtr ctx);

    // Signals used to send encoded response data
    void checkVersionRequestReady(
        QByteArray data);

    void getBootstrapInfoRequestReady(
        QByteArray data);

    void authenticateLongSessionRequestReady(
        QByteArray data);

    void completeTwoFactorAuthenticationRequestReady(
        QByteArray data);

    void revokeLongSessionRequestReady(
        QByteArray data);

    void authenticateToBusinessRequestReady(
        QByteArray data);

    void getUserRequestReady(
        QByteArray data);

    void getPublicUserInfoRequestReady(
        QByteArray data);

    void getUserUrlsRequestReady(
        QByteArray data);

    void inviteToBusinessRequestReady(
        QByteArray data);

    void removeFromBusinessRequestReady(
        QByteArray data);

    void updateBusinessUserIdentifierRequestReady(
        QByteArray data);

    void listBusinessUsersRequestReady(
        QByteArray data);

    void listBusinessInvitationsRequestReady(
        QByteArray data);

    void getAccountLimitsRequestReady(
        QByteArray data);

public Q_SLOTS:
    // Slot used to deliver requests to the server
    void onRequest(QByteArray data);

    // Slots for replies to requests
    void onCheckVersionRequestReady(
        bool value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetBootstrapInfoRequestReady(
        BootstrapInfo value,
        EverCloudExceptionDataPtr exceptionData);

    void onAuthenticateLongSessionRequestReady(
        AuthenticationResult value,
        EverCloudExceptionDataPtr exceptionData);

    void onCompleteTwoFactorAuthenticationRequestReady(
        AuthenticationResult value,
        EverCloudExceptionDataPtr exceptionData);

    void onRevokeLongSessionRequestReady(
        EverCloudExceptionDataPtr exceptionData);

    void onAuthenticateToBusinessRequestReady(
        AuthenticationResult value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetUserRequestReady(
        User value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetPublicUserInfoRequestReady(
        PublicUserInfo value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetUserUrlsRequestReady(
        UserUrls value,
        EverCloudExceptionDataPtr exceptionData);

    void onInviteToBusinessRequestReady(
        EverCloudExceptionDataPtr exceptionData);

    void onRemoveFromBusinessRequestReady(
        EverCloudExceptionDataPtr exceptionData);

    void onUpdateBusinessUserIdentifierRequestReady(
        EverCloudExceptionDataPtr exceptionData);

    void onListBusinessUsersRequestReady(
        QList<UserProfile> value,
        EverCloudExceptionDataPtr exceptionData);

    void onListBusinessInvitationsRequestReady(
        QList<BusinessInvitation> value,
        EverCloudExceptionDataPtr exceptionData);

    void onGetAccountLimitsRequestReady(
        AccountLimits value,
        EverCloudExceptionDataPtr exceptionData);

};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SERVERS_H
