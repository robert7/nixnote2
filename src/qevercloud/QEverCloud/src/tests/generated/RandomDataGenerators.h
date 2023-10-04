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

#ifndef QEVERCLOUD_GENERATED_RANDOMDATAGENERATORS_H
#define QEVERCLOUD_GENERATED_RANDOMDATAGENERATORS_H

#include <generated/Types.h>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

QString generateRandomString(int len = 10);

qint8 generateRandomInt8();

qint16 generateRandomInt16();

qint32 generateRandomInt32();

qint64 generateRandomInt64();

quint8 generateRandomUint8();

quint16 generateRandomUint16();

quint32 generateRandomUint32();

quint64 generateRandomUint64();

double generateRandomDouble();

bool generateRandomBool();

////////////////////////////////////////////////////////////////////////////////

SyncState generateRandomSyncState();

SyncChunk generateRandomSyncChunk();

SyncChunkFilter generateRandomSyncChunkFilter();

NoteFilter generateRandomNoteFilter();

NoteList generateRandomNoteList();

NoteMetadata generateRandomNoteMetadata();

NotesMetadataList generateRandomNotesMetadataList();

NotesMetadataResultSpec generateRandomNotesMetadataResultSpec();

NoteCollectionCounts generateRandomNoteCollectionCounts();

NoteResultSpec generateRandomNoteResultSpec();

NoteEmailParameters generateRandomNoteEmailParameters();

NoteVersionId generateRandomNoteVersionId();

RelatedQuery generateRandomRelatedQuery();

RelatedResult generateRandomRelatedResult();

RelatedResultSpec generateRandomRelatedResultSpec();

UpdateNoteIfUsnMatchesResult generateRandomUpdateNoteIfUsnMatchesResult();

ShareRelationshipRestrictions generateRandomShareRelationshipRestrictions();

InvitationShareRelationship generateRandomInvitationShareRelationship();

MemberShareRelationship generateRandomMemberShareRelationship();

ShareRelationships generateRandomShareRelationships();

ManageNotebookSharesParameters generateRandomManageNotebookSharesParameters();

ManageNotebookSharesError generateRandomManageNotebookSharesError();

ManageNotebookSharesResult generateRandomManageNotebookSharesResult();

SharedNoteTemplate generateRandomSharedNoteTemplate();

NotebookShareTemplate generateRandomNotebookShareTemplate();

CreateOrUpdateNotebookSharesResult generateRandomCreateOrUpdateNotebookSharesResult();

NoteShareRelationshipRestrictions generateRandomNoteShareRelationshipRestrictions();

NoteMemberShareRelationship generateRandomNoteMemberShareRelationship();

NoteInvitationShareRelationship generateRandomNoteInvitationShareRelationship();

NoteShareRelationships generateRandomNoteShareRelationships();

ManageNoteSharesParameters generateRandomManageNoteSharesParameters();

ManageNoteSharesError generateRandomManageNoteSharesError();

ManageNoteSharesResult generateRandomManageNoteSharesResult();

Data generateRandomData();

UserAttributes generateRandomUserAttributes();

BusinessUserAttributes generateRandomBusinessUserAttributes();

Accounting generateRandomAccounting();

BusinessUserInfo generateRandomBusinessUserInfo();

AccountLimits generateRandomAccountLimits();

User generateRandomUser();

Contact generateRandomContact();

Identity generateRandomIdentity();

Tag generateRandomTag();

LazyMap generateRandomLazyMap();

ResourceAttributes generateRandomResourceAttributes();

Resource generateRandomResource();

NoteAttributes generateRandomNoteAttributes();

SharedNote generateRandomSharedNote();

NoteRestrictions generateRandomNoteRestrictions();

NoteLimits generateRandomNoteLimits();

Note generateRandomNote();

Publishing generateRandomPublishing();

BusinessNotebook generateRandomBusinessNotebook();

SavedSearchScope generateRandomSavedSearchScope();

SavedSearch generateRandomSavedSearch();

SharedNotebookRecipientSettings generateRandomSharedNotebookRecipientSettings();

NotebookRecipientSettings generateRandomNotebookRecipientSettings();

SharedNotebook generateRandomSharedNotebook();

CanMoveToContainerRestrictions generateRandomCanMoveToContainerRestrictions();

NotebookRestrictions generateRandomNotebookRestrictions();

Notebook generateRandomNotebook();

LinkedNotebook generateRandomLinkedNotebook();

NotebookDescriptor generateRandomNotebookDescriptor();

UserProfile generateRandomUserProfile();

RelatedContentImage generateRandomRelatedContentImage();

RelatedContent generateRandomRelatedContent();

BusinessInvitation generateRandomBusinessInvitation();

UserIdentity generateRandomUserIdentity();

PublicUserInfo generateRandomPublicUserInfo();

UserUrls generateRandomUserUrls();

AuthenticationResult generateRandomAuthenticationResult();

BootstrapSettings generateRandomBootstrapSettings();

BootstrapProfile generateRandomBootstrapProfile();

BootstrapInfo generateRandomBootstrapInfo();

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RANDOMDATAGENERATORS_H
