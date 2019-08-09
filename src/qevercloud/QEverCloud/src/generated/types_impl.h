/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */


#ifndef QEVERCLOUD_GENERATED_TYPES_IMPL_H
#define QEVERCLOUD_GENERATED_TYPES_IMPL_H

#include <Optional.h>
#include <generated/types.h>
#include "../impl.h"
#include <QMap>
#include <QList>
#include <QSet>
#include <QString>
#include <QStringList>
#include <QByteArray>
#include <QDateTime>
#include <QMetaType>

namespace qevercloud {

/** @cond HIDDEN_SYMBOLS  */

void writeSyncState(ThriftBinaryBufferWriter & w, const SyncState & s);
void readSyncState(ThriftBinaryBufferReader & r, SyncState & s);
void writeSyncChunk(ThriftBinaryBufferWriter & w, const SyncChunk & s);
void readSyncChunk(ThriftBinaryBufferReader & r, SyncChunk & s);
void writeSyncChunkFilter(ThriftBinaryBufferWriter & w, const SyncChunkFilter & s);
void readSyncChunkFilter(ThriftBinaryBufferReader & r, SyncChunkFilter & s);
void writeNoteFilter(ThriftBinaryBufferWriter & w, const NoteFilter & s);
void readNoteFilter(ThriftBinaryBufferReader & r, NoteFilter & s);
void writeNoteList(ThriftBinaryBufferWriter & w, const NoteList & s);
void readNoteList(ThriftBinaryBufferReader & r, NoteList & s);
void writeNoteMetadata(ThriftBinaryBufferWriter & w, const NoteMetadata & s);
void readNoteMetadata(ThriftBinaryBufferReader & r, NoteMetadata & s);
void writeNotesMetadataList(ThriftBinaryBufferWriter & w, const NotesMetadataList & s);
void readNotesMetadataList(ThriftBinaryBufferReader & r, NotesMetadataList & s);
void writeNotesMetadataResultSpec(ThriftBinaryBufferWriter & w, const NotesMetadataResultSpec & s);
void readNotesMetadataResultSpec(ThriftBinaryBufferReader & r, NotesMetadataResultSpec & s);
void writeNoteCollectionCounts(ThriftBinaryBufferWriter & w, const NoteCollectionCounts & s);
void readNoteCollectionCounts(ThriftBinaryBufferReader & r, NoteCollectionCounts & s);
void writeNoteResultSpec(ThriftBinaryBufferWriter & w, const NoteResultSpec & s);
void readNoteResultSpec(ThriftBinaryBufferReader & r, NoteResultSpec & s);
void writeNoteEmailParameters(ThriftBinaryBufferWriter & w, const NoteEmailParameters & s);
void readNoteEmailParameters(ThriftBinaryBufferReader & r, NoteEmailParameters & s);
void writeNoteVersionId(ThriftBinaryBufferWriter & w, const NoteVersionId & s);
void readNoteVersionId(ThriftBinaryBufferReader & r, NoteVersionId & s);
void writeRelatedQuery(ThriftBinaryBufferWriter & w, const RelatedQuery & s);
void readRelatedQuery(ThriftBinaryBufferReader & r, RelatedQuery & s);
void writeRelatedResult(ThriftBinaryBufferWriter & w, const RelatedResult & s);
void readRelatedResult(ThriftBinaryBufferReader & r, RelatedResult & s);
void writeRelatedResultSpec(ThriftBinaryBufferWriter & w, const RelatedResultSpec & s);
void readRelatedResultSpec(ThriftBinaryBufferReader & r, RelatedResultSpec & s);
void writeUpdateNoteIfUsnMatchesResult(ThriftBinaryBufferWriter & w, const UpdateNoteIfUsnMatchesResult & s);
void readUpdateNoteIfUsnMatchesResult(ThriftBinaryBufferReader & r, UpdateNoteIfUsnMatchesResult & s);
void writeShareRelationshipRestrictions(ThriftBinaryBufferWriter & w, const ShareRelationshipRestrictions & s);
void readShareRelationshipRestrictions(ThriftBinaryBufferReader & r, ShareRelationshipRestrictions & s);
void writeInvitationShareRelationship(ThriftBinaryBufferWriter & w, const InvitationShareRelationship & s);
void readInvitationShareRelationship(ThriftBinaryBufferReader & r, InvitationShareRelationship & s);
void writeMemberShareRelationship(ThriftBinaryBufferWriter & w, const MemberShareRelationship & s);
void readMemberShareRelationship(ThriftBinaryBufferReader & r, MemberShareRelationship & s);
void writeShareRelationships(ThriftBinaryBufferWriter & w, const ShareRelationships & s);
void readShareRelationships(ThriftBinaryBufferReader & r, ShareRelationships & s);
void writeManageNotebookSharesParameters(ThriftBinaryBufferWriter & w, const ManageNotebookSharesParameters & s);
void readManageNotebookSharesParameters(ThriftBinaryBufferReader & r, ManageNotebookSharesParameters & s);
void writeManageNotebookSharesError(ThriftBinaryBufferWriter & w, const ManageNotebookSharesError & s);
void readManageNotebookSharesError(ThriftBinaryBufferReader & r, ManageNotebookSharesError & s);
void writeManageNotebookSharesResult(ThriftBinaryBufferWriter & w, const ManageNotebookSharesResult & s);
void readManageNotebookSharesResult(ThriftBinaryBufferReader & r, ManageNotebookSharesResult & s);
void writeSharedNoteTemplate(ThriftBinaryBufferWriter & w, const SharedNoteTemplate & s);
void readSharedNoteTemplate(ThriftBinaryBufferReader & r, SharedNoteTemplate & s);
void writeNotebookShareTemplate(ThriftBinaryBufferWriter & w, const NotebookShareTemplate & s);
void readNotebookShareTemplate(ThriftBinaryBufferReader & r, NotebookShareTemplate & s);
void writeCreateOrUpdateNotebookSharesResult(ThriftBinaryBufferWriter & w, const CreateOrUpdateNotebookSharesResult & s);
void readCreateOrUpdateNotebookSharesResult(ThriftBinaryBufferReader & r, CreateOrUpdateNotebookSharesResult & s);
void writeNoteShareRelationshipRestrictions(ThriftBinaryBufferWriter & w, const NoteShareRelationshipRestrictions & s);
void readNoteShareRelationshipRestrictions(ThriftBinaryBufferReader & r, NoteShareRelationshipRestrictions & s);
void writeNoteMemberShareRelationship(ThriftBinaryBufferWriter & w, const NoteMemberShareRelationship & s);
void readNoteMemberShareRelationship(ThriftBinaryBufferReader & r, NoteMemberShareRelationship & s);
void writeNoteInvitationShareRelationship(ThriftBinaryBufferWriter & w, const NoteInvitationShareRelationship & s);
void readNoteInvitationShareRelationship(ThriftBinaryBufferReader & r, NoteInvitationShareRelationship & s);
void writeNoteShareRelationships(ThriftBinaryBufferWriter & w, const NoteShareRelationships & s);
void readNoteShareRelationships(ThriftBinaryBufferReader & r, NoteShareRelationships & s);
void writeManageNoteSharesParameters(ThriftBinaryBufferWriter & w, const ManageNoteSharesParameters & s);
void readManageNoteSharesParameters(ThriftBinaryBufferReader & r, ManageNoteSharesParameters & s);
void writeManageNoteSharesError(ThriftBinaryBufferWriter & w, const ManageNoteSharesError & s);
void readManageNoteSharesError(ThriftBinaryBufferReader & r, ManageNoteSharesError & s);
void writeManageNoteSharesResult(ThriftBinaryBufferWriter & w, const ManageNoteSharesResult & s);
void readManageNoteSharesResult(ThriftBinaryBufferReader & r, ManageNoteSharesResult & s);
void writeData(ThriftBinaryBufferWriter & w, const Data & s);
void readData(ThriftBinaryBufferReader & r, Data & s);
void writeUserAttributes(ThriftBinaryBufferWriter & w, const UserAttributes & s);
void readUserAttributes(ThriftBinaryBufferReader & r, UserAttributes & s);
void writeBusinessUserAttributes(ThriftBinaryBufferWriter & w, const BusinessUserAttributes & s);
void readBusinessUserAttributes(ThriftBinaryBufferReader & r, BusinessUserAttributes & s);
void writeAccounting(ThriftBinaryBufferWriter & w, const Accounting & s);
void readAccounting(ThriftBinaryBufferReader & r, Accounting & s);
void writeBusinessUserInfo(ThriftBinaryBufferWriter & w, const BusinessUserInfo & s);
void readBusinessUserInfo(ThriftBinaryBufferReader & r, BusinessUserInfo & s);
void writeAccountLimits(ThriftBinaryBufferWriter & w, const AccountLimits & s);
void readAccountLimits(ThriftBinaryBufferReader & r, AccountLimits & s);
void writeUser(ThriftBinaryBufferWriter & w, const User & s);
void readUser(ThriftBinaryBufferReader & r, User & s);
void writeContact(ThriftBinaryBufferWriter & w, const Contact & s);
void readContact(ThriftBinaryBufferReader & r, Contact & s);
void writeIdentity(ThriftBinaryBufferWriter & w, const Identity & s);
void readIdentity(ThriftBinaryBufferReader & r, Identity & s);
void writeTag(ThriftBinaryBufferWriter & w, const Tag & s);
void readTag(ThriftBinaryBufferReader & r, Tag & s);
void writeLazyMap(ThriftBinaryBufferWriter & w, const LazyMap & s);
void readLazyMap(ThriftBinaryBufferReader & r, LazyMap & s);
void writeResourceAttributes(ThriftBinaryBufferWriter & w, const ResourceAttributes & s);
void readResourceAttributes(ThriftBinaryBufferReader & r, ResourceAttributes & s);
void writeResource(ThriftBinaryBufferWriter & w, const Resource & s);
void readResource(ThriftBinaryBufferReader & r, Resource & s);
void writeNoteAttributes(ThriftBinaryBufferWriter & w, const NoteAttributes & s);
void readNoteAttributes(ThriftBinaryBufferReader & r, NoteAttributes & s);
void writeSharedNote(ThriftBinaryBufferWriter & w, const SharedNote & s);
void readSharedNote(ThriftBinaryBufferReader & r, SharedNote & s);
void writeNoteRestrictions(ThriftBinaryBufferWriter & w, const NoteRestrictions & s);
void readNoteRestrictions(ThriftBinaryBufferReader & r, NoteRestrictions & s);
void writeNoteLimits(ThriftBinaryBufferWriter & w, const NoteLimits & s);
void readNoteLimits(ThriftBinaryBufferReader & r, NoteLimits & s);
void writeNote(ThriftBinaryBufferWriter & w, const Note & s);
void readNote(ThriftBinaryBufferReader & r, Note & s);
void writePublishing(ThriftBinaryBufferWriter & w, const Publishing & s);
void readPublishing(ThriftBinaryBufferReader & r, Publishing & s);
void writeBusinessNotebook(ThriftBinaryBufferWriter & w, const BusinessNotebook & s);
void readBusinessNotebook(ThriftBinaryBufferReader & r, BusinessNotebook & s);
void writeSavedSearchScope(ThriftBinaryBufferWriter & w, const SavedSearchScope & s);
void readSavedSearchScope(ThriftBinaryBufferReader & r, SavedSearchScope & s);
void writeSavedSearch(ThriftBinaryBufferWriter & w, const SavedSearch & s);
void readSavedSearch(ThriftBinaryBufferReader & r, SavedSearch & s);
void writeSharedNotebookRecipientSettings(ThriftBinaryBufferWriter & w, const SharedNotebookRecipientSettings & s);
void readSharedNotebookRecipientSettings(ThriftBinaryBufferReader & r, SharedNotebookRecipientSettings & s);
void writeNotebookRecipientSettings(ThriftBinaryBufferWriter & w, const NotebookRecipientSettings & s);
void readNotebookRecipientSettings(ThriftBinaryBufferReader & r, NotebookRecipientSettings & s);
void writeSharedNotebook(ThriftBinaryBufferWriter & w, const SharedNotebook & s);
void readSharedNotebook(ThriftBinaryBufferReader & r, SharedNotebook & s);
void writeCanMoveToContainerRestrictions(ThriftBinaryBufferWriter & w, const CanMoveToContainerRestrictions & s);
void readCanMoveToContainerRestrictions(ThriftBinaryBufferReader & r, CanMoveToContainerRestrictions & s);
void writeNotebookRestrictions(ThriftBinaryBufferWriter & w, const NotebookRestrictions & s);
void readNotebookRestrictions(ThriftBinaryBufferReader & r, NotebookRestrictions & s);
void writeNotebook(ThriftBinaryBufferWriter & w, const Notebook & s);
void readNotebook(ThriftBinaryBufferReader & r, Notebook & s);
void writeLinkedNotebook(ThriftBinaryBufferWriter & w, const LinkedNotebook & s);
void readLinkedNotebook(ThriftBinaryBufferReader & r, LinkedNotebook & s);
void writeNotebookDescriptor(ThriftBinaryBufferWriter & w, const NotebookDescriptor & s);
void readNotebookDescriptor(ThriftBinaryBufferReader & r, NotebookDescriptor & s);
void writeUserProfile(ThriftBinaryBufferWriter & w, const UserProfile & s);
void readUserProfile(ThriftBinaryBufferReader & r, UserProfile & s);
void writeRelatedContentImage(ThriftBinaryBufferWriter & w, const RelatedContentImage & s);
void readRelatedContentImage(ThriftBinaryBufferReader & r, RelatedContentImage & s);
void writeRelatedContent(ThriftBinaryBufferWriter & w, const RelatedContent & s);
void readRelatedContent(ThriftBinaryBufferReader & r, RelatedContent & s);
void writeBusinessInvitation(ThriftBinaryBufferWriter & w, const BusinessInvitation & s);
void readBusinessInvitation(ThriftBinaryBufferReader & r, BusinessInvitation & s);
void writeUserIdentity(ThriftBinaryBufferWriter & w, const UserIdentity & s);
void readUserIdentity(ThriftBinaryBufferReader & r, UserIdentity & s);
void writePublicUserInfo(ThriftBinaryBufferWriter & w, const PublicUserInfo & s);
void readPublicUserInfo(ThriftBinaryBufferReader & r, PublicUserInfo & s);
void writeUserUrls(ThriftBinaryBufferWriter & w, const UserUrls & s);
void readUserUrls(ThriftBinaryBufferReader & r, UserUrls & s);
void writeAuthenticationResult(ThriftBinaryBufferWriter & w, const AuthenticationResult & s);
void readAuthenticationResult(ThriftBinaryBufferReader & r, AuthenticationResult & s);
void writeBootstrapSettings(ThriftBinaryBufferWriter & w, const BootstrapSettings & s);
void readBootstrapSettings(ThriftBinaryBufferReader & r, BootstrapSettings & s);
void writeBootstrapProfile(ThriftBinaryBufferWriter & w, const BootstrapProfile & s);
void readBootstrapProfile(ThriftBinaryBufferReader & r, BootstrapProfile & s);
void writeBootstrapInfo(ThriftBinaryBufferWriter & w, const BootstrapInfo & s);
void readBootstrapInfo(ThriftBinaryBufferReader & r, BootstrapInfo & s);
void writeEDAMUserException(ThriftBinaryBufferWriter & w, const EDAMUserException & s);
void readEDAMUserException(ThriftBinaryBufferReader & r, EDAMUserException & s);
void writeEDAMSystemException(ThriftBinaryBufferWriter & w, const EDAMSystemException & s);
void readEDAMSystemException(ThriftBinaryBufferReader & r, EDAMSystemException & s);
void writeEDAMNotFoundException(ThriftBinaryBufferWriter & w, const EDAMNotFoundException & s);
void readEDAMNotFoundException(ThriftBinaryBufferReader & r, EDAMNotFoundException & s);
void writeEDAMInvalidContactsException(ThriftBinaryBufferWriter & w, const EDAMInvalidContactsException & s);
void readEDAMInvalidContactsException(ThriftBinaryBufferReader & r, EDAMInvalidContactsException & s);

void readEnumEDAMErrorCode(ThriftBinaryBufferReader & r, EDAMErrorCode::type & e);
void readEnumEDAMInvalidContactReason(ThriftBinaryBufferReader & r, EDAMInvalidContactReason::type & e);
void readEnumShareRelationshipPrivilegeLevel(ThriftBinaryBufferReader & r, ShareRelationshipPrivilegeLevel::type & e);
void readEnumPrivilegeLevel(ThriftBinaryBufferReader & r, PrivilegeLevel::type & e);
void readEnumServiceLevel(ThriftBinaryBufferReader & r, ServiceLevel::type & e);
void readEnumQueryFormat(ThriftBinaryBufferReader & r, QueryFormat::type & e);
void readEnumNoteSortOrder(ThriftBinaryBufferReader & r, NoteSortOrder::type & e);
void readEnumPremiumOrderStatus(ThriftBinaryBufferReader & r, PremiumOrderStatus::type & e);
void readEnumSharedNotebookPrivilegeLevel(ThriftBinaryBufferReader & r, SharedNotebookPrivilegeLevel::type & e);
void readEnumSharedNotePrivilegeLevel(ThriftBinaryBufferReader & r, SharedNotePrivilegeLevel::type & e);
void readEnumSponsoredGroupRole(ThriftBinaryBufferReader & r, SponsoredGroupRole::type & e);
void readEnumBusinessUserRole(ThriftBinaryBufferReader & r, BusinessUserRole::type & e);
void readEnumBusinessUserStatus(ThriftBinaryBufferReader & r, BusinessUserStatus::type & e);
void readEnumSharedNotebookInstanceRestrictions(ThriftBinaryBufferReader & r, SharedNotebookInstanceRestrictions::type & e);
void readEnumReminderEmailConfig(ThriftBinaryBufferReader & r, ReminderEmailConfig::type & e);
void readEnumBusinessInvitationStatus(ThriftBinaryBufferReader & r, BusinessInvitationStatus::type & e);
void readEnumContactType(ThriftBinaryBufferReader & r, ContactType::type & e);
void readEnumEntityType(ThriftBinaryBufferReader & r, EntityType::type & e);
void readEnumRecipientStatus(ThriftBinaryBufferReader & r, RecipientStatus::type & e);
void readEnumCanMoveToContainerStatus(ThriftBinaryBufferReader & r, CanMoveToContainerStatus::type & e);
void readEnumRelatedContentType(ThriftBinaryBufferReader & r, RelatedContentType::type & e);
void readEnumRelatedContentAccess(ThriftBinaryBufferReader & r, RelatedContentAccess::type & e);
void readEnumUserIdentityType(ThriftBinaryBufferReader & r, UserIdentityType::type & e);

/** @endcond */
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_TYPES_IMPL_H
