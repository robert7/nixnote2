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

#ifndef QEVERCLOUD_GENERATED_TYPES_IO_H
#define QEVERCLOUD_GENERATED_TYPES_IO_H

#include "../Impl.h"
#include <Optional.h>
#include <generated/Types.h>

namespace qevercloud {

/** @cond HIDDEN_SYMBOLS  */

void writeSyncState(ThriftBinaryBufferWriter & writer, const SyncState & s);
void readSyncState(ThriftBinaryBufferReader & reader, SyncState & s);
void writeSyncChunk(ThriftBinaryBufferWriter & writer, const SyncChunk & s);
void readSyncChunk(ThriftBinaryBufferReader & reader, SyncChunk & s);
void writeSyncChunkFilter(ThriftBinaryBufferWriter & writer, const SyncChunkFilter & s);
void readSyncChunkFilter(ThriftBinaryBufferReader & reader, SyncChunkFilter & s);
void writeNoteFilter(ThriftBinaryBufferWriter & writer, const NoteFilter & s);
void readNoteFilter(ThriftBinaryBufferReader & reader, NoteFilter & s);
void writeNoteList(ThriftBinaryBufferWriter & writer, const NoteList & s);
void readNoteList(ThriftBinaryBufferReader & reader, NoteList & s);
void writeNoteMetadata(ThriftBinaryBufferWriter & writer, const NoteMetadata & s);
void readNoteMetadata(ThriftBinaryBufferReader & reader, NoteMetadata & s);
void writeNotesMetadataList(ThriftBinaryBufferWriter & writer, const NotesMetadataList & s);
void readNotesMetadataList(ThriftBinaryBufferReader & reader, NotesMetadataList & s);
void writeNotesMetadataResultSpec(ThriftBinaryBufferWriter & writer, const NotesMetadataResultSpec & s);
void readNotesMetadataResultSpec(ThriftBinaryBufferReader & reader, NotesMetadataResultSpec & s);
void writeNoteCollectionCounts(ThriftBinaryBufferWriter & writer, const NoteCollectionCounts & s);
void readNoteCollectionCounts(ThriftBinaryBufferReader & reader, NoteCollectionCounts & s);
void writeNoteResultSpec(ThriftBinaryBufferWriter & writer, const NoteResultSpec & s);
void readNoteResultSpec(ThriftBinaryBufferReader & reader, NoteResultSpec & s);
void writeNoteEmailParameters(ThriftBinaryBufferWriter & writer, const NoteEmailParameters & s);
void readNoteEmailParameters(ThriftBinaryBufferReader & reader, NoteEmailParameters & s);
void writeNoteVersionId(ThriftBinaryBufferWriter & writer, const NoteVersionId & s);
void readNoteVersionId(ThriftBinaryBufferReader & reader, NoteVersionId & s);
void writeRelatedQuery(ThriftBinaryBufferWriter & writer, const RelatedQuery & s);
void readRelatedQuery(ThriftBinaryBufferReader & reader, RelatedQuery & s);
void writeRelatedResult(ThriftBinaryBufferWriter & writer, const RelatedResult & s);
void readRelatedResult(ThriftBinaryBufferReader & reader, RelatedResult & s);
void writeRelatedResultSpec(ThriftBinaryBufferWriter & writer, const RelatedResultSpec & s);
void readRelatedResultSpec(ThriftBinaryBufferReader & reader, RelatedResultSpec & s);
void writeUpdateNoteIfUsnMatchesResult(ThriftBinaryBufferWriter & writer, const UpdateNoteIfUsnMatchesResult & s);
void readUpdateNoteIfUsnMatchesResult(ThriftBinaryBufferReader & reader, UpdateNoteIfUsnMatchesResult & s);
void writeShareRelationshipRestrictions(ThriftBinaryBufferWriter & writer, const ShareRelationshipRestrictions & s);
void readShareRelationshipRestrictions(ThriftBinaryBufferReader & reader, ShareRelationshipRestrictions & s);
void writeInvitationShareRelationship(ThriftBinaryBufferWriter & writer, const InvitationShareRelationship & s);
void readInvitationShareRelationship(ThriftBinaryBufferReader & reader, InvitationShareRelationship & s);
void writeMemberShareRelationship(ThriftBinaryBufferWriter & writer, const MemberShareRelationship & s);
void readMemberShareRelationship(ThriftBinaryBufferReader & reader, MemberShareRelationship & s);
void writeShareRelationships(ThriftBinaryBufferWriter & writer, const ShareRelationships & s);
void readShareRelationships(ThriftBinaryBufferReader & reader, ShareRelationships & s);
void writeManageNotebookSharesParameters(ThriftBinaryBufferWriter & writer, const ManageNotebookSharesParameters & s);
void readManageNotebookSharesParameters(ThriftBinaryBufferReader & reader, ManageNotebookSharesParameters & s);
void writeManageNotebookSharesError(ThriftBinaryBufferWriter & writer, const ManageNotebookSharesError & s);
void readManageNotebookSharesError(ThriftBinaryBufferReader & reader, ManageNotebookSharesError & s);
void writeManageNotebookSharesResult(ThriftBinaryBufferWriter & writer, const ManageNotebookSharesResult & s);
void readManageNotebookSharesResult(ThriftBinaryBufferReader & reader, ManageNotebookSharesResult & s);
void writeSharedNoteTemplate(ThriftBinaryBufferWriter & writer, const SharedNoteTemplate & s);
void readSharedNoteTemplate(ThriftBinaryBufferReader & reader, SharedNoteTemplate & s);
void writeNotebookShareTemplate(ThriftBinaryBufferWriter & writer, const NotebookShareTemplate & s);
void readNotebookShareTemplate(ThriftBinaryBufferReader & reader, NotebookShareTemplate & s);
void writeCreateOrUpdateNotebookSharesResult(ThriftBinaryBufferWriter & writer, const CreateOrUpdateNotebookSharesResult & s);
void readCreateOrUpdateNotebookSharesResult(ThriftBinaryBufferReader & reader, CreateOrUpdateNotebookSharesResult & s);
void writeNoteShareRelationshipRestrictions(ThriftBinaryBufferWriter & writer, const NoteShareRelationshipRestrictions & s);
void readNoteShareRelationshipRestrictions(ThriftBinaryBufferReader & reader, NoteShareRelationshipRestrictions & s);
void writeNoteMemberShareRelationship(ThriftBinaryBufferWriter & writer, const NoteMemberShareRelationship & s);
void readNoteMemberShareRelationship(ThriftBinaryBufferReader & reader, NoteMemberShareRelationship & s);
void writeNoteInvitationShareRelationship(ThriftBinaryBufferWriter & writer, const NoteInvitationShareRelationship & s);
void readNoteInvitationShareRelationship(ThriftBinaryBufferReader & reader, NoteInvitationShareRelationship & s);
void writeNoteShareRelationships(ThriftBinaryBufferWriter & writer, const NoteShareRelationships & s);
void readNoteShareRelationships(ThriftBinaryBufferReader & reader, NoteShareRelationships & s);
void writeManageNoteSharesParameters(ThriftBinaryBufferWriter & writer, const ManageNoteSharesParameters & s);
void readManageNoteSharesParameters(ThriftBinaryBufferReader & reader, ManageNoteSharesParameters & s);
void writeManageNoteSharesError(ThriftBinaryBufferWriter & writer, const ManageNoteSharesError & s);
void readManageNoteSharesError(ThriftBinaryBufferReader & reader, ManageNoteSharesError & s);
void writeManageNoteSharesResult(ThriftBinaryBufferWriter & writer, const ManageNoteSharesResult & s);
void readManageNoteSharesResult(ThriftBinaryBufferReader & reader, ManageNoteSharesResult & s);
void writeData(ThriftBinaryBufferWriter & writer, const Data & s);
void readData(ThriftBinaryBufferReader & reader, Data & s);
void writeUserAttributes(ThriftBinaryBufferWriter & writer, const UserAttributes & s);
void readUserAttributes(ThriftBinaryBufferReader & reader, UserAttributes & s);
void writeBusinessUserAttributes(ThriftBinaryBufferWriter & writer, const BusinessUserAttributes & s);
void readBusinessUserAttributes(ThriftBinaryBufferReader & reader, BusinessUserAttributes & s);
void writeAccounting(ThriftBinaryBufferWriter & writer, const Accounting & s);
void readAccounting(ThriftBinaryBufferReader & reader, Accounting & s);
void writeBusinessUserInfo(ThriftBinaryBufferWriter & writer, const BusinessUserInfo & s);
void readBusinessUserInfo(ThriftBinaryBufferReader & reader, BusinessUserInfo & s);
void writeAccountLimits(ThriftBinaryBufferWriter & writer, const AccountLimits & s);
void readAccountLimits(ThriftBinaryBufferReader & reader, AccountLimits & s);
void writeUser(ThriftBinaryBufferWriter & writer, const User & s);
void readUser(ThriftBinaryBufferReader & reader, User & s);
void writeContact(ThriftBinaryBufferWriter & writer, const Contact & s);
void readContact(ThriftBinaryBufferReader & reader, Contact & s);
void writeIdentity(ThriftBinaryBufferWriter & writer, const Identity & s);
void readIdentity(ThriftBinaryBufferReader & reader, Identity & s);
void writeTag(ThriftBinaryBufferWriter & writer, const Tag & s);
void readTag(ThriftBinaryBufferReader & reader, Tag & s);
void writeLazyMap(ThriftBinaryBufferWriter & writer, const LazyMap & s);
void readLazyMap(ThriftBinaryBufferReader & reader, LazyMap & s);
void writeResourceAttributes(ThriftBinaryBufferWriter & writer, const ResourceAttributes & s);
void readResourceAttributes(ThriftBinaryBufferReader & reader, ResourceAttributes & s);
void writeResource(ThriftBinaryBufferWriter & writer, const Resource & s);
void readResource(ThriftBinaryBufferReader & reader, Resource & s);
void writeNoteAttributes(ThriftBinaryBufferWriter & writer, const NoteAttributes & s);
void readNoteAttributes(ThriftBinaryBufferReader & reader, NoteAttributes & s);
void writeSharedNote(ThriftBinaryBufferWriter & writer, const SharedNote & s);
void readSharedNote(ThriftBinaryBufferReader & reader, SharedNote & s);
void writeNoteRestrictions(ThriftBinaryBufferWriter & writer, const NoteRestrictions & s);
void readNoteRestrictions(ThriftBinaryBufferReader & reader, NoteRestrictions & s);
void writeNoteLimits(ThriftBinaryBufferWriter & writer, const NoteLimits & s);
void readNoteLimits(ThriftBinaryBufferReader & reader, NoteLimits & s);
void writeNote(ThriftBinaryBufferWriter & writer, const Note & s);
void readNote(ThriftBinaryBufferReader & reader, Note & s);
void writePublishing(ThriftBinaryBufferWriter & writer, const Publishing & s);
void readPublishing(ThriftBinaryBufferReader & reader, Publishing & s);
void writeBusinessNotebook(ThriftBinaryBufferWriter & writer, const BusinessNotebook & s);
void readBusinessNotebook(ThriftBinaryBufferReader & reader, BusinessNotebook & s);
void writeSavedSearchScope(ThriftBinaryBufferWriter & writer, const SavedSearchScope & s);
void readSavedSearchScope(ThriftBinaryBufferReader & reader, SavedSearchScope & s);
void writeSavedSearch(ThriftBinaryBufferWriter & writer, const SavedSearch & s);
void readSavedSearch(ThriftBinaryBufferReader & reader, SavedSearch & s);
void writeSharedNotebookRecipientSettings(ThriftBinaryBufferWriter & writer, const SharedNotebookRecipientSettings & s);
void readSharedNotebookRecipientSettings(ThriftBinaryBufferReader & reader, SharedNotebookRecipientSettings & s);
void writeNotebookRecipientSettings(ThriftBinaryBufferWriter & writer, const NotebookRecipientSettings & s);
void readNotebookRecipientSettings(ThriftBinaryBufferReader & reader, NotebookRecipientSettings & s);
void writeSharedNotebook(ThriftBinaryBufferWriter & writer, const SharedNotebook & s);
void readSharedNotebook(ThriftBinaryBufferReader & reader, SharedNotebook & s);
void writeCanMoveToContainerRestrictions(ThriftBinaryBufferWriter & writer, const CanMoveToContainerRestrictions & s);
void readCanMoveToContainerRestrictions(ThriftBinaryBufferReader & reader, CanMoveToContainerRestrictions & s);
void writeNotebookRestrictions(ThriftBinaryBufferWriter & writer, const NotebookRestrictions & s);
void readNotebookRestrictions(ThriftBinaryBufferReader & reader, NotebookRestrictions & s);
void writeNotebook(ThriftBinaryBufferWriter & writer, const Notebook & s);
void readNotebook(ThriftBinaryBufferReader & reader, Notebook & s);
void writeLinkedNotebook(ThriftBinaryBufferWriter & writer, const LinkedNotebook & s);
void readLinkedNotebook(ThriftBinaryBufferReader & reader, LinkedNotebook & s);
void writeNotebookDescriptor(ThriftBinaryBufferWriter & writer, const NotebookDescriptor & s);
void readNotebookDescriptor(ThriftBinaryBufferReader & reader, NotebookDescriptor & s);
void writeUserProfile(ThriftBinaryBufferWriter & writer, const UserProfile & s);
void readUserProfile(ThriftBinaryBufferReader & reader, UserProfile & s);
void writeRelatedContentImage(ThriftBinaryBufferWriter & writer, const RelatedContentImage & s);
void readRelatedContentImage(ThriftBinaryBufferReader & reader, RelatedContentImage & s);
void writeRelatedContent(ThriftBinaryBufferWriter & writer, const RelatedContent & s);
void readRelatedContent(ThriftBinaryBufferReader & reader, RelatedContent & s);
void writeBusinessInvitation(ThriftBinaryBufferWriter & writer, const BusinessInvitation & s);
void readBusinessInvitation(ThriftBinaryBufferReader & reader, BusinessInvitation & s);
void writeUserIdentity(ThriftBinaryBufferWriter & writer, const UserIdentity & s);
void readUserIdentity(ThriftBinaryBufferReader & reader, UserIdentity & s);
void writePublicUserInfo(ThriftBinaryBufferWriter & writer, const PublicUserInfo & s);
void readPublicUserInfo(ThriftBinaryBufferReader & reader, PublicUserInfo & s);
void writeUserUrls(ThriftBinaryBufferWriter & writer, const UserUrls & s);
void readUserUrls(ThriftBinaryBufferReader & reader, UserUrls & s);
void writeAuthenticationResult(ThriftBinaryBufferWriter & writer, const AuthenticationResult & s);
void readAuthenticationResult(ThriftBinaryBufferReader & reader, AuthenticationResult & s);
void writeBootstrapSettings(ThriftBinaryBufferWriter & writer, const BootstrapSettings & s);
void readBootstrapSettings(ThriftBinaryBufferReader & reader, BootstrapSettings & s);
void writeBootstrapProfile(ThriftBinaryBufferWriter & writer, const BootstrapProfile & s);
void readBootstrapProfile(ThriftBinaryBufferReader & reader, BootstrapProfile & s);
void writeBootstrapInfo(ThriftBinaryBufferWriter & writer, const BootstrapInfo & s);
void readBootstrapInfo(ThriftBinaryBufferReader & reader, BootstrapInfo & s);
void writeEDAMUserException(ThriftBinaryBufferWriter & writer, const EDAMUserException & s);
void readEDAMUserException(ThriftBinaryBufferReader & reader, EDAMUserException & s);
void writeEDAMSystemException(ThriftBinaryBufferWriter & writer, const EDAMSystemException & s);
void readEDAMSystemException(ThriftBinaryBufferReader & reader, EDAMSystemException & s);
void writeEDAMNotFoundException(ThriftBinaryBufferWriter & writer, const EDAMNotFoundException & s);
void readEDAMNotFoundException(ThriftBinaryBufferReader & reader, EDAMNotFoundException & s);
void writeEDAMInvalidContactsException(ThriftBinaryBufferWriter & writer, const EDAMInvalidContactsException & s);
void readEDAMInvalidContactsException(ThriftBinaryBufferReader & reader, EDAMInvalidContactsException & s);

void readEnumEDAMErrorCode(ThriftBinaryBufferReader & reader, EDAMErrorCode & e);
void readEnumEDAMInvalidContactReason(ThriftBinaryBufferReader & reader, EDAMInvalidContactReason & e);
void readEnumShareRelationshipPrivilegeLevel(ThriftBinaryBufferReader & reader, ShareRelationshipPrivilegeLevel & e);
void readEnumPrivilegeLevel(ThriftBinaryBufferReader & reader, PrivilegeLevel & e);
void readEnumServiceLevel(ThriftBinaryBufferReader & reader, ServiceLevel & e);
void readEnumQueryFormat(ThriftBinaryBufferReader & reader, QueryFormat & e);
void readEnumNoteSortOrder(ThriftBinaryBufferReader & reader, NoteSortOrder & e);
void readEnumPremiumOrderStatus(ThriftBinaryBufferReader & reader, PremiumOrderStatus & e);
void readEnumSharedNotebookPrivilegeLevel(ThriftBinaryBufferReader & reader, SharedNotebookPrivilegeLevel & e);
void readEnumSharedNotePrivilegeLevel(ThriftBinaryBufferReader & reader, SharedNotePrivilegeLevel & e);
void readEnumSponsoredGroupRole(ThriftBinaryBufferReader & reader, SponsoredGroupRole & e);
void readEnumBusinessUserRole(ThriftBinaryBufferReader & reader, BusinessUserRole & e);
void readEnumBusinessUserStatus(ThriftBinaryBufferReader & reader, BusinessUserStatus & e);
void readEnumSharedNotebookInstanceRestrictions(ThriftBinaryBufferReader & reader, SharedNotebookInstanceRestrictions & e);
void readEnumReminderEmailConfig(ThriftBinaryBufferReader & reader, ReminderEmailConfig & e);
void readEnumBusinessInvitationStatus(ThriftBinaryBufferReader & reader, BusinessInvitationStatus & e);
void readEnumContactType(ThriftBinaryBufferReader & reader, ContactType & e);
void readEnumEntityType(ThriftBinaryBufferReader & reader, EntityType & e);
void readEnumRecipientStatus(ThriftBinaryBufferReader & reader, RecipientStatus & e);
void readEnumCanMoveToContainerStatus(ThriftBinaryBufferReader & reader, CanMoveToContainerStatus & e);
void readEnumRelatedContentType(ThriftBinaryBufferReader & reader, RelatedContentType & e);
void readEnumRelatedContentAccess(ThriftBinaryBufferReader & reader, RelatedContentAccess & e);
void readEnumUserIdentityType(ThriftBinaryBufferReader & reader, UserIdentityType & e);

/** @endcond */
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_TYPES_IO_H
