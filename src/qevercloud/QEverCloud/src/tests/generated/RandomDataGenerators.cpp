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

#include "RandomDataGenerators.h"
#include "../../Impl.h"
#include <QCryptographicHash>
#include <QDateTime>
#include <QEventLoop>
#include <QGlobalStatic>
#include <QObject>
#include <algorithm>
#include <cstdlib>
#include <limits>

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

Q_GLOBAL_STATIC_WITH_ARGS(
    QString,
    randomStringAvailableCharacters,
    (QString::fromUtf8(
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")))

template <typename T>
T generateRandomIntType()
{
    T min = std::numeric_limits<T>::min() / 4;
    T max = std::numeric_limits<T>::max() / 4;
    return min + (rand() % static_cast<T>(max - min + 1));
}

} // namespace

////////////////////////////////////////////////////////////////////////////////

QString generateRandomString(int len)
{
    if (len <= 0) {
        return {};
    }

    QString res;
    res.reserve(len);
    for(int i = 0; i < len; ++i) {
        int index = rand() % randomStringAvailableCharacters->length();
        res.append(randomStringAvailableCharacters->at(index));
    }

    return res;
}

qint8 generateRandomInt8()
{
    return generateRandomIntType<qint8>();
}

qint16 generateRandomInt16()
{
    return generateRandomIntType<qint16>();
}

qint32 generateRandomInt32()
{
    return generateRandomIntType<qint32>();
}

qint64 generateRandomInt64()
{
    return generateRandomIntType<qint64>();
}

quint8 generateRandomUint8()
{
    return generateRandomIntType<quint8>();
}

quint16 generateRandomUint16()
{
    return generateRandomIntType<quint16>();
}

quint32 generateRandomUint32()
{
    return generateRandomIntType<quint32>();
}

quint64 generateRandomUint64()
{
    return generateRandomIntType<quint64>();
}

double generateRandomDouble()
{
    double minval = std::numeric_limits<double>::min();
    double maxval = std::numeric_limits<double>::max();
    double f = (double)rand() / RAND_MAX;
    return minval + f * (maxval - minval);
}

bool generateRandomBool()
{
    return generateRandomInt8() >= 0;
}

////////////////////////////////////////////////////////////////////////////////

SyncState generateRandomSyncState()
{
    SyncState result;
    result.currentTime = generateRandomInt64();
    result.fullSyncBefore = generateRandomInt64();
    result.updateCount = generateRandomInt32();
    result.uploaded = generateRandomInt64();
    result.userLastUpdated = generateRandomInt64();
    result.userMaxMessageEventId = generateRandomInt64();
    return result;
}

SyncChunk generateRandomSyncChunk()
{
    SyncChunk result;
    result.currentTime = generateRandomInt64();
    result.chunkHighUSN = generateRandomInt32();
    result.updateCount = generateRandomInt32();
    result.notes = QList<Note>();
    result.notes.ref() << generateRandomNote();
    result.notes.ref() << generateRandomNote();
    result.notes.ref() << generateRandomNote();
    result.notebooks = QList<Notebook>();
    result.notebooks.ref() << generateRandomNotebook();
    result.notebooks.ref() << generateRandomNotebook();
    result.notebooks.ref() << generateRandomNotebook();
    result.tags = QList<Tag>();
    result.tags.ref() << generateRandomTag();
    result.tags.ref() << generateRandomTag();
    result.tags.ref() << generateRandomTag();
    result.searches = QList<SavedSearch>();
    result.searches.ref() << generateRandomSavedSearch();
    result.searches.ref() << generateRandomSavedSearch();
    result.searches.ref() << generateRandomSavedSearch();
    result.resources = QList<Resource>();
    result.resources.ref() << generateRandomResource();
    result.resources.ref() << generateRandomResource();
    result.resources.ref() << generateRandomResource();
    result.expungedNotes = QList<Guid>();
    result.expungedNotes.ref() << generateRandomString();
    result.expungedNotes.ref() << generateRandomString();
    result.expungedNotes.ref() << generateRandomString();
    result.expungedNotebooks = QList<Guid>();
    result.expungedNotebooks.ref() << generateRandomString();
    result.expungedNotebooks.ref() << generateRandomString();
    result.expungedNotebooks.ref() << generateRandomString();
    result.expungedTags = QList<Guid>();
    result.expungedTags.ref() << generateRandomString();
    result.expungedTags.ref() << generateRandomString();
    result.expungedTags.ref() << generateRandomString();
    result.expungedSearches = QList<Guid>();
    result.expungedSearches.ref() << generateRandomString();
    result.expungedSearches.ref() << generateRandomString();
    result.expungedSearches.ref() << generateRandomString();
    result.linkedNotebooks = QList<LinkedNotebook>();
    result.linkedNotebooks.ref() << generateRandomLinkedNotebook();
    result.linkedNotebooks.ref() << generateRandomLinkedNotebook();
    result.linkedNotebooks.ref() << generateRandomLinkedNotebook();
    result.expungedLinkedNotebooks = QList<Guid>();
    result.expungedLinkedNotebooks.ref() << generateRandomString();
    result.expungedLinkedNotebooks.ref() << generateRandomString();
    result.expungedLinkedNotebooks.ref() << generateRandomString();
    return result;
}

SyncChunkFilter generateRandomSyncChunkFilter()
{
    SyncChunkFilter result;
    result.includeNotes = generateRandomBool();
    result.includeNoteResources = generateRandomBool();
    result.includeNoteAttributes = generateRandomBool();
    result.includeNotebooks = generateRandomBool();
    result.includeTags = generateRandomBool();
    result.includeSearches = generateRandomBool();
    result.includeResources = generateRandomBool();
    result.includeLinkedNotebooks = generateRandomBool();
    result.includeExpunged = generateRandomBool();
    result.includeNoteApplicationDataFullMap = generateRandomBool();
    result.includeResourceApplicationDataFullMap = generateRandomBool();
    result.includeNoteResourceApplicationDataFullMap = generateRandomBool();
    result.includeSharedNotes = generateRandomBool();
    result.omitSharedNotebooks = generateRandomBool();
    result.requireNoteContentClass = generateRandomString();
    result.notebookGuids = QSet<QString>();
    result.notebookGuids->insert(generateRandomString());
    result.notebookGuids->insert(generateRandomString());
    result.notebookGuids->insert(generateRandomString());
    return result;
}

NoteFilter generateRandomNoteFilter()
{
    NoteFilter result;
    result.order = generateRandomInt32();
    result.ascending = generateRandomBool();
    result.words = generateRandomString();
    result.notebookGuid = generateRandomString();
    result.tagGuids = QList<Guid>();
    result.tagGuids.ref() << generateRandomString();
    result.tagGuids.ref() << generateRandomString();
    result.tagGuids.ref() << generateRandomString();
    result.timeZone = generateRandomString();
    result.inactive = generateRandomBool();
    result.emphasized = generateRandomString();
    result.includeAllReadableNotebooks = generateRandomBool();
    result.includeAllReadableWorkspaces = generateRandomBool();
    result.context = generateRandomString();
    result.rawWords = generateRandomString();
    result.searchContextBytes = generateRandomString().toUtf8();
    return result;
}

NoteList generateRandomNoteList()
{
    NoteList result;
    result.startIndex = generateRandomInt32();
    result.totalNotes = generateRandomInt32();
    result.notes << generateRandomNote();
    result.notes << generateRandomNote();
    result.notes << generateRandomNote();
    result.stoppedWords = QList<QString>();
    result.stoppedWords.ref() << generateRandomString();
    result.stoppedWords.ref() << generateRandomString();
    result.stoppedWords.ref() << generateRandomString();
    result.searchedWords = QList<QString>();
    result.searchedWords.ref() << generateRandomString();
    result.searchedWords.ref() << generateRandomString();
    result.searchedWords.ref() << generateRandomString();
    result.updateCount = generateRandomInt32();
    result.searchContextBytes = generateRandomString().toUtf8();
    result.debugInfo = generateRandomString();
    return result;
}

NoteMetadata generateRandomNoteMetadata()
{
    NoteMetadata result;
    result.guid = generateRandomString();
    result.title = generateRandomString();
    result.contentLength = generateRandomInt32();
    result.created = generateRandomInt64();
    result.updated = generateRandomInt64();
    result.deleted = generateRandomInt64();
    result.updateSequenceNum = generateRandomInt32();
    result.notebookGuid = generateRandomString();
    result.tagGuids = QList<Guid>();
    result.tagGuids.ref() << generateRandomString();
    result.tagGuids.ref() << generateRandomString();
    result.tagGuids.ref() << generateRandomString();
    result.attributes = generateRandomNoteAttributes();
    result.largestResourceMime = generateRandomString();
    result.largestResourceSize = generateRandomInt32();
    return result;
}

NotesMetadataList generateRandomNotesMetadataList()
{
    NotesMetadataList result;
    result.startIndex = generateRandomInt32();
    result.totalNotes = generateRandomInt32();
    result.notes << generateRandomNoteMetadata();
    result.notes << generateRandomNoteMetadata();
    result.notes << generateRandomNoteMetadata();
    result.stoppedWords = QList<QString>();
    result.stoppedWords.ref() << generateRandomString();
    result.stoppedWords.ref() << generateRandomString();
    result.stoppedWords.ref() << generateRandomString();
    result.searchedWords = QList<QString>();
    result.searchedWords.ref() << generateRandomString();
    result.searchedWords.ref() << generateRandomString();
    result.searchedWords.ref() << generateRandomString();
    result.updateCount = generateRandomInt32();
    result.searchContextBytes = generateRandomString().toUtf8();
    result.debugInfo = generateRandomString();
    return result;
}

NotesMetadataResultSpec generateRandomNotesMetadataResultSpec()
{
    NotesMetadataResultSpec result;
    result.includeTitle = generateRandomBool();
    result.includeContentLength = generateRandomBool();
    result.includeCreated = generateRandomBool();
    result.includeUpdated = generateRandomBool();
    result.includeDeleted = generateRandomBool();
    result.includeUpdateSequenceNum = generateRandomBool();
    result.includeNotebookGuid = generateRandomBool();
    result.includeTagGuids = generateRandomBool();
    result.includeAttributes = generateRandomBool();
    result.includeLargestResourceMime = generateRandomBool();
    result.includeLargestResourceSize = generateRandomBool();
    return result;
}

NoteCollectionCounts generateRandomNoteCollectionCounts()
{
    NoteCollectionCounts result;
    result.notebookCounts = QMap<Guid, qint32>();
    result.notebookCounts.ref()[generateRandomString()] = generateRandomInt32();
    result.notebookCounts.ref()[generateRandomString()] = generateRandomInt32();
    result.notebookCounts.ref()[generateRandomString()] = generateRandomInt32();
    result.tagCounts = QMap<Guid, qint32>();
    result.tagCounts.ref()[generateRandomString()] = generateRandomInt32();
    result.tagCounts.ref()[generateRandomString()] = generateRandomInt32();
    result.tagCounts.ref()[generateRandomString()] = generateRandomInt32();
    result.trashCount = generateRandomInt32();
    return result;
}

NoteResultSpec generateRandomNoteResultSpec()
{
    NoteResultSpec result;
    result.includeContent = generateRandomBool();
    result.includeResourcesData = generateRandomBool();
    result.includeResourcesRecognition = generateRandomBool();
    result.includeResourcesAlternateData = generateRandomBool();
    result.includeSharedNotes = generateRandomBool();
    result.includeNoteAppDataValues = generateRandomBool();
    result.includeResourceAppDataValues = generateRandomBool();
    result.includeAccountLimits = generateRandomBool();
    return result;
}

NoteEmailParameters generateRandomNoteEmailParameters()
{
    NoteEmailParameters result;
    result.guid = generateRandomString();
    result.note = generateRandomNote();
    result.toAddresses = QList<QString>();
    result.toAddresses.ref() << generateRandomString();
    result.toAddresses.ref() << generateRandomString();
    result.toAddresses.ref() << generateRandomString();
    result.ccAddresses = QList<QString>();
    result.ccAddresses.ref() << generateRandomString();
    result.ccAddresses.ref() << generateRandomString();
    result.ccAddresses.ref() << generateRandomString();
    result.subject = generateRandomString();
    result.message = generateRandomString();
    return result;
}

NoteVersionId generateRandomNoteVersionId()
{
    NoteVersionId result;
    result.updateSequenceNum = generateRandomInt32();
    result.updated = generateRandomInt64();
    result.saved = generateRandomInt64();
    result.title = generateRandomString();
    result.lastEditorId = generateRandomInt32();
    return result;
}

RelatedQuery generateRandomRelatedQuery()
{
    RelatedQuery result;
    result.noteGuid = generateRandomString();
    result.plainText = generateRandomString();
    result.filter = generateRandomNoteFilter();
    result.referenceUri = generateRandomString();
    result.context = generateRandomString();
    result.cacheKey = generateRandomString();
    return result;
}

RelatedResult generateRandomRelatedResult()
{
    RelatedResult result;
    result.notes = QList<Note>();
    result.notes.ref() << generateRandomNote();
    result.notes.ref() << generateRandomNote();
    result.notes.ref() << generateRandomNote();
    result.notebooks = QList<Notebook>();
    result.notebooks.ref() << generateRandomNotebook();
    result.notebooks.ref() << generateRandomNotebook();
    result.notebooks.ref() << generateRandomNotebook();
    result.tags = QList<Tag>();
    result.tags.ref() << generateRandomTag();
    result.tags.ref() << generateRandomTag();
    result.tags.ref() << generateRandomTag();
    result.containingNotebooks = QList<NotebookDescriptor>();
    result.containingNotebooks.ref() << generateRandomNotebookDescriptor();
    result.containingNotebooks.ref() << generateRandomNotebookDescriptor();
    result.containingNotebooks.ref() << generateRandomNotebookDescriptor();
    result.debugInfo = generateRandomString();
    result.experts = QList<UserProfile>();
    result.experts.ref() << generateRandomUserProfile();
    result.experts.ref() << generateRandomUserProfile();
    result.experts.ref() << generateRandomUserProfile();
    result.relatedContent = QList<RelatedContent>();
    result.relatedContent.ref() << generateRandomRelatedContent();
    result.relatedContent.ref() << generateRandomRelatedContent();
    result.relatedContent.ref() << generateRandomRelatedContent();
    result.cacheKey = generateRandomString();
    result.cacheExpires = generateRandomInt32();
    return result;
}

RelatedResultSpec generateRandomRelatedResultSpec()
{
    RelatedResultSpec result;
    result.maxNotes = generateRandomInt32();
    result.maxNotebooks = generateRandomInt32();
    result.maxTags = generateRandomInt32();
    result.writableNotebooksOnly = generateRandomBool();
    result.includeContainingNotebooks = generateRandomBool();
    result.includeDebugInfo = generateRandomBool();
    result.maxExperts = generateRandomInt32();
    result.maxRelatedContent = generateRandomInt32();
    result.relatedContentTypes = QSet<RelatedContentType>();
    result.relatedContentTypes->insert(RelatedContentType::NEWS_ARTICLE);
    result.relatedContentTypes->insert(RelatedContentType::NEWS_ARTICLE);
    result.relatedContentTypes->insert(RelatedContentType::PROFILE_PERSON);
    return result;
}

UpdateNoteIfUsnMatchesResult generateRandomUpdateNoteIfUsnMatchesResult()
{
    UpdateNoteIfUsnMatchesResult result;
    result.note = generateRandomNote();
    result.updated = generateRandomBool();
    return result;
}

ShareRelationshipRestrictions generateRandomShareRelationshipRestrictions()
{
    ShareRelationshipRestrictions result;
    result.noSetReadOnly = generateRandomBool();
    result.noSetReadPlusActivity = generateRandomBool();
    result.noSetModify = generateRandomBool();
    result.noSetFullAccess = generateRandomBool();
    return result;
}

InvitationShareRelationship generateRandomInvitationShareRelationship()
{
    InvitationShareRelationship result;
    result.displayName = generateRandomString();
    result.recipientUserIdentity = generateRandomUserIdentity();
    result.privilege = ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY;
    result.sharerUserId = generateRandomInt32();
    return result;
}

MemberShareRelationship generateRandomMemberShareRelationship()
{
    MemberShareRelationship result;
    result.displayName = generateRandomString();
    result.recipientUserId = generateRandomInt32();
    result.bestPrivilege = ShareRelationshipPrivilegeLevel::READ_NOTEBOOK;
    result.individualPrivilege = ShareRelationshipPrivilegeLevel::READ_NOTEBOOK;
    result.restrictions = generateRandomShareRelationshipRestrictions();
    result.sharerUserId = generateRandomInt32();
    return result;
}

ShareRelationships generateRandomShareRelationships()
{
    ShareRelationships result;
    result.invitations = QList<InvitationShareRelationship>();
    result.invitations.ref() << generateRandomInvitationShareRelationship();
    result.invitations.ref() << generateRandomInvitationShareRelationship();
    result.invitations.ref() << generateRandomInvitationShareRelationship();
    result.memberships = QList<MemberShareRelationship>();
    result.memberships.ref() << generateRandomMemberShareRelationship();
    result.memberships.ref() << generateRandomMemberShareRelationship();
    result.memberships.ref() << generateRandomMemberShareRelationship();
    result.invitationRestrictions = generateRandomShareRelationshipRestrictions();
    return result;
}

ManageNotebookSharesParameters generateRandomManageNotebookSharesParameters()
{
    ManageNotebookSharesParameters result;
    result.notebookGuid = generateRandomString();
    result.inviteMessage = generateRandomString();
    result.membershipsToUpdate = QList<MemberShareRelationship>();
    result.membershipsToUpdate.ref() << generateRandomMemberShareRelationship();
    result.membershipsToUpdate.ref() << generateRandomMemberShareRelationship();
    result.membershipsToUpdate.ref() << generateRandomMemberShareRelationship();
    result.invitationsToCreateOrUpdate = QList<InvitationShareRelationship>();
    result.invitationsToCreateOrUpdate.ref() << generateRandomInvitationShareRelationship();
    result.invitationsToCreateOrUpdate.ref() << generateRandomInvitationShareRelationship();
    result.invitationsToCreateOrUpdate.ref() << generateRandomInvitationShareRelationship();
    result.unshares = QList<UserIdentity>();
    result.unshares.ref() << generateRandomUserIdentity();
    result.unshares.ref() << generateRandomUserIdentity();
    result.unshares.ref() << generateRandomUserIdentity();
    return result;
}

ManageNotebookSharesError generateRandomManageNotebookSharesError()
{
    ManageNotebookSharesError result;
    result.userIdentity = generateRandomUserIdentity();
    result.userException = EDAMUserException();
    result.userException->errorCode = EDAMErrorCode::INVALID_OPENID_TOKEN;
    result.userException->parameter = generateRandomString();
    result.notFoundException = EDAMNotFoundException();
    result.notFoundException->identifier = generateRandomString();
    result.notFoundException->key = generateRandomString();
    return result;
}

ManageNotebookSharesResult generateRandomManageNotebookSharesResult()
{
    ManageNotebookSharesResult result;
    result.errors = QList<ManageNotebookSharesError>();
    result.errors.ref() << generateRandomManageNotebookSharesError();
    result.errors.ref() << generateRandomManageNotebookSharesError();
    result.errors.ref() << generateRandomManageNotebookSharesError();
    return result;
}

SharedNoteTemplate generateRandomSharedNoteTemplate()
{
    SharedNoteTemplate result;
    result.noteGuid = generateRandomString();
    result.recipientThreadId = generateRandomInt64();
    result.recipientContacts = QList<Contact>();
    result.recipientContacts.ref() << generateRandomContact();
    result.recipientContacts.ref() << generateRandomContact();
    result.recipientContacts.ref() << generateRandomContact();
    result.privilege = SharedNotePrivilegeLevel::READ_NOTE;
    return result;
}

NotebookShareTemplate generateRandomNotebookShareTemplate()
{
    NotebookShareTemplate result;
    result.notebookGuid = generateRandomString();
    result.recipientThreadId = generateRandomInt64();
    result.recipientContacts = QList<Contact>();
    result.recipientContacts.ref() << generateRandomContact();
    result.recipientContacts.ref() << generateRandomContact();
    result.recipientContacts.ref() << generateRandomContact();
    result.privilege = SharedNotebookPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY;
    return result;
}

CreateOrUpdateNotebookSharesResult generateRandomCreateOrUpdateNotebookSharesResult()
{
    CreateOrUpdateNotebookSharesResult result;
    result.updateSequenceNum = generateRandomInt32();
    result.matchingShares = QList<SharedNotebook>();
    result.matchingShares.ref() << generateRandomSharedNotebook();
    result.matchingShares.ref() << generateRandomSharedNotebook();
    result.matchingShares.ref() << generateRandomSharedNotebook();
    return result;
}

NoteShareRelationshipRestrictions generateRandomNoteShareRelationshipRestrictions()
{
    NoteShareRelationshipRestrictions result;
    result.noSetReadNote = generateRandomBool();
    result.noSetModifyNote = generateRandomBool();
    result.noSetFullAccess = generateRandomBool();
    return result;
}

NoteMemberShareRelationship generateRandomNoteMemberShareRelationship()
{
    NoteMemberShareRelationship result;
    result.displayName = generateRandomString();
    result.recipientUserId = generateRandomInt32();
    result.privilege = SharedNotePrivilegeLevel::FULL_ACCESS;
    result.restrictions = generateRandomNoteShareRelationshipRestrictions();
    result.sharerUserId = generateRandomInt32();
    return result;
}

NoteInvitationShareRelationship generateRandomNoteInvitationShareRelationship()
{
    NoteInvitationShareRelationship result;
    result.displayName = generateRandomString();
    result.recipientIdentityId = generateRandomInt64();
    result.privilege = SharedNotePrivilegeLevel::MODIFY_NOTE;
    result.sharerUserId = generateRandomInt32();
    return result;
}

NoteShareRelationships generateRandomNoteShareRelationships()
{
    NoteShareRelationships result;
    result.invitations = QList<NoteInvitationShareRelationship>();
    result.invitations.ref() << generateRandomNoteInvitationShareRelationship();
    result.invitations.ref() << generateRandomNoteInvitationShareRelationship();
    result.invitations.ref() << generateRandomNoteInvitationShareRelationship();
    result.memberships = QList<NoteMemberShareRelationship>();
    result.memberships.ref() << generateRandomNoteMemberShareRelationship();
    result.memberships.ref() << generateRandomNoteMemberShareRelationship();
    result.memberships.ref() << generateRandomNoteMemberShareRelationship();
    result.invitationRestrictions = generateRandomNoteShareRelationshipRestrictions();
    return result;
}

ManageNoteSharesParameters generateRandomManageNoteSharesParameters()
{
    ManageNoteSharesParameters result;
    result.noteGuid = generateRandomString();
    result.membershipsToUpdate = QList<NoteMemberShareRelationship>();
    result.membershipsToUpdate.ref() << generateRandomNoteMemberShareRelationship();
    result.membershipsToUpdate.ref() << generateRandomNoteMemberShareRelationship();
    result.membershipsToUpdate.ref() << generateRandomNoteMemberShareRelationship();
    result.invitationsToUpdate = QList<NoteInvitationShareRelationship>();
    result.invitationsToUpdate.ref() << generateRandomNoteInvitationShareRelationship();
    result.invitationsToUpdate.ref() << generateRandomNoteInvitationShareRelationship();
    result.invitationsToUpdate.ref() << generateRandomNoteInvitationShareRelationship();
    result.membershipsToUnshare = QList<UserID>();
    result.membershipsToUnshare.ref() << generateRandomInt32();
    result.membershipsToUnshare.ref() << generateRandomInt32();
    result.membershipsToUnshare.ref() << generateRandomInt32();
    result.invitationsToUnshare = QList<IdentityID>();
    result.invitationsToUnshare.ref() << generateRandomInt64();
    result.invitationsToUnshare.ref() << generateRandomInt64();
    result.invitationsToUnshare.ref() << generateRandomInt64();
    return result;
}

ManageNoteSharesError generateRandomManageNoteSharesError()
{
    ManageNoteSharesError result;
    result.identityID = generateRandomInt64();
    result.userID = generateRandomInt32();
    result.userException = EDAMUserException();
    result.userException->errorCode = EDAMErrorCode::OPENID_ALREADY_TAKEN;
    result.userException->parameter = generateRandomString();
    result.notFoundException = EDAMNotFoundException();
    result.notFoundException->identifier = generateRandomString();
    result.notFoundException->key = generateRandomString();
    return result;
}

ManageNoteSharesResult generateRandomManageNoteSharesResult()
{
    ManageNoteSharesResult result;
    result.errors = QList<ManageNoteSharesError>();
    result.errors.ref() << generateRandomManageNoteSharesError();
    result.errors.ref() << generateRandomManageNoteSharesError();
    result.errors.ref() << generateRandomManageNoteSharesError();
    return result;
}

Data generateRandomData()
{
    Data result;
    result.bodyHash = generateRandomString().toUtf8();
    result.size = generateRandomInt32();
    result.body = generateRandomString().toUtf8();
    return result;
}

UserAttributes generateRandomUserAttributes()
{
    UserAttributes result;
    result.defaultLocationName = generateRandomString();
    result.defaultLatitude = generateRandomDouble();
    result.defaultLongitude = generateRandomDouble();
    result.preactivation = generateRandomBool();
    result.viewedPromotions = QList<QString>();
    result.viewedPromotions.ref() << generateRandomString();
    result.viewedPromotions.ref() << generateRandomString();
    result.viewedPromotions.ref() << generateRandomString();
    result.incomingEmailAddress = generateRandomString();
    result.recentMailedAddresses = QList<QString>();
    result.recentMailedAddresses.ref() << generateRandomString();
    result.recentMailedAddresses.ref() << generateRandomString();
    result.recentMailedAddresses.ref() << generateRandomString();
    result.comments = generateRandomString();
    result.dateAgreedToTermsOfService = generateRandomInt64();
    result.maxReferrals = generateRandomInt32();
    result.referralCount = generateRandomInt32();
    result.refererCode = generateRandomString();
    result.sentEmailDate = generateRandomInt64();
    result.sentEmailCount = generateRandomInt32();
    result.dailyEmailLimit = generateRandomInt32();
    result.emailOptOutDate = generateRandomInt64();
    result.partnerEmailOptInDate = generateRandomInt64();
    result.preferredLanguage = generateRandomString();
    result.preferredCountry = generateRandomString();
    result.clipFullPage = generateRandomBool();
    result.twitterUserName = generateRandomString();
    result.twitterId = generateRandomString();
    result.groupName = generateRandomString();
    result.recognitionLanguage = generateRandomString();
    result.referralProof = generateRandomString();
    result.educationalDiscount = generateRandomBool();
    result.businessAddress = generateRandomString();
    result.hideSponsorBilling = generateRandomBool();
    result.useEmailAutoFiling = generateRandomBool();
    result.reminderEmailConfig = ReminderEmailConfig::DO_NOT_SEND;
    result.emailAddressLastConfirmed = generateRandomInt64();
    result.passwordUpdated = generateRandomInt64();
    result.salesforcePushEnabled = generateRandomBool();
    result.shouldLogClientEvent = generateRandomBool();
    result.optOutMachineLearning = generateRandomBool();
    return result;
}

BusinessUserAttributes generateRandomBusinessUserAttributes()
{
    BusinessUserAttributes result;
    result.title = generateRandomString();
    result.location = generateRandomString();
    result.department = generateRandomString();
    result.mobilePhone = generateRandomString();
    result.linkedInProfileUrl = generateRandomString();
    result.workPhone = generateRandomString();
    result.companyStartDate = generateRandomInt64();
    return result;
}

Accounting generateRandomAccounting()
{
    Accounting result;
    result.uploadLimitEnd = generateRandomInt64();
    result.uploadLimitNextMonth = generateRandomInt64();
    result.premiumServiceStatus = PremiumOrderStatus::PENDING;
    result.premiumOrderNumber = generateRandomString();
    result.premiumCommerceService = generateRandomString();
    result.premiumServiceStart = generateRandomInt64();
    result.premiumServiceSKU = generateRandomString();
    result.lastSuccessfulCharge = generateRandomInt64();
    result.lastFailedCharge = generateRandomInt64();
    result.lastFailedChargeReason = generateRandomString();
    result.nextPaymentDue = generateRandomInt64();
    result.premiumLockUntil = generateRandomInt64();
    result.updated = generateRandomInt64();
    result.premiumSubscriptionNumber = generateRandomString();
    result.lastRequestedCharge = generateRandomInt64();
    result.currency = generateRandomString();
    result.unitPrice = generateRandomInt32();
    result.businessId = generateRandomInt32();
    result.businessName = generateRandomString();
    result.businessRole = BusinessUserRole::NORMAL;
    result.unitDiscount = generateRandomInt32();
    result.nextChargeDate = generateRandomInt64();
    result.availablePoints = generateRandomInt32();
    return result;
}

BusinessUserInfo generateRandomBusinessUserInfo()
{
    BusinessUserInfo result;
    result.businessId = generateRandomInt32();
    result.businessName = generateRandomString();
    result.role = BusinessUserRole::ADMIN;
    result.email = generateRandomString();
    result.updated = generateRandomInt64();
    return result;
}

AccountLimits generateRandomAccountLimits()
{
    AccountLimits result;
    result.userMailLimitDaily = generateRandomInt32();
    result.noteSizeMax = generateRandomInt64();
    result.resourceSizeMax = generateRandomInt64();
    result.userLinkedNotebookMax = generateRandomInt32();
    result.uploadLimit = generateRandomInt64();
    result.userNoteCountMax = generateRandomInt32();
    result.userNotebookCountMax = generateRandomInt32();
    result.userTagCountMax = generateRandomInt32();
    result.noteTagCountMax = generateRandomInt32();
    result.userSavedSearchesMax = generateRandomInt32();
    result.noteResourceCountMax = generateRandomInt32();
    return result;
}

User generateRandomUser()
{
    User result;
    result.id = generateRandomInt32();
    result.username = generateRandomString();
    result.email = generateRandomString();
    result.name = generateRandomString();
    result.timezone = generateRandomString();
    result.privilege = PrivilegeLevel::MANAGER;
    result.serviceLevel = ServiceLevel::PLUS;
    result.created = generateRandomInt64();
    result.updated = generateRandomInt64();
    result.deleted = generateRandomInt64();
    result.active = generateRandomBool();
    result.shardId = generateRandomString();
    result.attributes = generateRandomUserAttributes();
    result.accounting = generateRandomAccounting();
    result.businessUserInfo = generateRandomBusinessUserInfo();
    result.photoUrl = generateRandomString();
    result.photoLastUpdated = generateRandomInt64();
    result.accountLimits = generateRandomAccountLimits();
    return result;
}

Contact generateRandomContact()
{
    Contact result;
    result.name = generateRandomString();
    result.id = generateRandomString();
    result.type = ContactType::EVERNOTE;
    result.photoUrl = generateRandomString();
    result.photoLastUpdated = generateRandomInt64();
    result.messagingPermit = generateRandomString().toUtf8();
    result.messagingPermitExpires = generateRandomInt64();
    return result;
}

Identity generateRandomIdentity()
{
    Identity result;
    result.id = generateRandomInt64();
    result.contact = generateRandomContact();
    result.userId = generateRandomInt32();
    result.deactivated = generateRandomBool();
    result.sameBusiness = generateRandomBool();
    result.blocked = generateRandomBool();
    result.userConnected = generateRandomBool();
    result.eventId = generateRandomInt64();
    return result;
}

Tag generateRandomTag()
{
    Tag result;
    result.guid = generateRandomString();
    result.name = generateRandomString();
    result.parentGuid = generateRandomString();
    result.updateSequenceNum = generateRandomInt32();
    return result;
}

LazyMap generateRandomLazyMap()
{
    LazyMap result;
    result.keysOnly = QSet<QString>();
    result.keysOnly->insert(generateRandomString());
    result.keysOnly->insert(generateRandomString());
    result.keysOnly->insert(generateRandomString());
    result.fullMap = QMap<QString, QString>();
    result.fullMap.ref()[generateRandomString()] = generateRandomString();
    result.fullMap.ref()[generateRandomString()] = generateRandomString();
    result.fullMap.ref()[generateRandomString()] = generateRandomString();
    return result;
}

ResourceAttributes generateRandomResourceAttributes()
{
    ResourceAttributes result;
    result.sourceURL = generateRandomString();
    result.timestamp = generateRandomInt64();
    result.latitude = generateRandomDouble();
    result.longitude = generateRandomDouble();
    result.altitude = generateRandomDouble();
    result.cameraMake = generateRandomString();
    result.cameraModel = generateRandomString();
    result.clientWillIndex = generateRandomBool();
    result.recoType = generateRandomString();
    result.fileName = generateRandomString();
    result.attachment = generateRandomBool();
    result.applicationData = generateRandomLazyMap();
    return result;
}

Resource generateRandomResource()
{
    Resource result;
    result.guid = generateRandomString();
    result.noteGuid = generateRandomString();
    result.data = generateRandomData();
    result.mime = generateRandomString();
    result.width = generateRandomInt16();
    result.height = generateRandomInt16();
    result.duration = generateRandomInt16();
    result.active = generateRandomBool();
    result.recognition = generateRandomData();
    result.attributes = generateRandomResourceAttributes();
    result.updateSequenceNum = generateRandomInt32();
    result.alternateData = generateRandomData();
    return result;
}

NoteAttributes generateRandomNoteAttributes()
{
    NoteAttributes result;
    result.subjectDate = generateRandomInt64();
    result.latitude = generateRandomDouble();
    result.longitude = generateRandomDouble();
    result.altitude = generateRandomDouble();
    result.author = generateRandomString();
    result.source = generateRandomString();
    result.sourceURL = generateRandomString();
    result.sourceApplication = generateRandomString();
    result.shareDate = generateRandomInt64();
    result.reminderOrder = generateRandomInt64();
    result.reminderDoneTime = generateRandomInt64();
    result.reminderTime = generateRandomInt64();
    result.placeName = generateRandomString();
    result.contentClass = generateRandomString();
    result.applicationData = generateRandomLazyMap();
    result.lastEditedBy = generateRandomString();
    result.classifications = QMap<QString, QString>();
    result.classifications.ref()[generateRandomString()] = generateRandomString();
    result.classifications.ref()[generateRandomString()] = generateRandomString();
    result.classifications.ref()[generateRandomString()] = generateRandomString();
    result.creatorId = generateRandomInt32();
    result.lastEditorId = generateRandomInt32();
    result.sharedWithBusiness = generateRandomBool();
    result.conflictSourceNoteGuid = generateRandomString();
    result.noteTitleQuality = generateRandomInt32();
    return result;
}

SharedNote generateRandomSharedNote()
{
    SharedNote result;
    result.sharerUserID = generateRandomInt32();
    result.recipientIdentity = generateRandomIdentity();
    result.privilege = SharedNotePrivilegeLevel::FULL_ACCESS;
    result.serviceCreated = generateRandomInt64();
    result.serviceUpdated = generateRandomInt64();
    result.serviceAssigned = generateRandomInt64();
    return result;
}

NoteRestrictions generateRandomNoteRestrictions()
{
    NoteRestrictions result;
    result.noUpdateTitle = generateRandomBool();
    result.noUpdateContent = generateRandomBool();
    result.noEmail = generateRandomBool();
    result.noShare = generateRandomBool();
    result.noSharePublicly = generateRandomBool();
    return result;
}

NoteLimits generateRandomNoteLimits()
{
    NoteLimits result;
    result.noteResourceCountMax = generateRandomInt32();
    result.uploadLimit = generateRandomInt64();
    result.resourceSizeMax = generateRandomInt64();
    result.noteSizeMax = generateRandomInt64();
    result.uploaded = generateRandomInt64();
    return result;
}

Note generateRandomNote()
{
    Note result;
    result.guid = generateRandomString();
    result.title = generateRandomString();
    result.content = generateRandomString();
    result.contentHash = generateRandomString().toUtf8();
    result.contentLength = generateRandomInt32();
    result.created = generateRandomInt64();
    result.updated = generateRandomInt64();
    result.deleted = generateRandomInt64();
    result.active = generateRandomBool();
    result.updateSequenceNum = generateRandomInt32();
    result.notebookGuid = generateRandomString();
    result.tagGuids = QList<Guid>();
    result.tagGuids.ref() << generateRandomString();
    result.tagGuids.ref() << generateRandomString();
    result.tagGuids.ref() << generateRandomString();
    result.resources = QList<Resource>();
    result.resources.ref() << generateRandomResource();
    result.resources.ref() << generateRandomResource();
    result.resources.ref() << generateRandomResource();
    result.attributes = generateRandomNoteAttributes();
    result.tagNames = QList<QString>();
    result.tagNames.ref() << generateRandomString();
    result.tagNames.ref() << generateRandomString();
    result.tagNames.ref() << generateRandomString();
    result.sharedNotes = QList<SharedNote>();
    result.sharedNotes.ref() << generateRandomSharedNote();
    result.sharedNotes.ref() << generateRandomSharedNote();
    result.sharedNotes.ref() << generateRandomSharedNote();
    result.restrictions = generateRandomNoteRestrictions();
    result.limits = generateRandomNoteLimits();
    return result;
}

Publishing generateRandomPublishing()
{
    Publishing result;
    result.uri = generateRandomString();
    result.order = NoteSortOrder::UPDATED;
    result.ascending = generateRandomBool();
    result.publicDescription = generateRandomString();
    return result;
}

BusinessNotebook generateRandomBusinessNotebook()
{
    BusinessNotebook result;
    result.notebookDescription = generateRandomString();
    result.privilege = SharedNotebookPrivilegeLevel::GROUP;
    result.recommended = generateRandomBool();
    return result;
}

SavedSearchScope generateRandomSavedSearchScope()
{
    SavedSearchScope result;
    result.includeAccount = generateRandomBool();
    result.includePersonalLinkedNotebooks = generateRandomBool();
    result.includeBusinessLinkedNotebooks = generateRandomBool();
    return result;
}

SavedSearch generateRandomSavedSearch()
{
    SavedSearch result;
    result.guid = generateRandomString();
    result.name = generateRandomString();
    result.query = generateRandomString();
    result.format = QueryFormat::USER;
    result.updateSequenceNum = generateRandomInt32();
    result.scope = generateRandomSavedSearchScope();
    return result;
}

SharedNotebookRecipientSettings generateRandomSharedNotebookRecipientSettings()
{
    SharedNotebookRecipientSettings result;
    result.reminderNotifyEmail = generateRandomBool();
    result.reminderNotifyInApp = generateRandomBool();
    return result;
}

NotebookRecipientSettings generateRandomNotebookRecipientSettings()
{
    NotebookRecipientSettings result;
    result.reminderNotifyEmail = generateRandomBool();
    result.reminderNotifyInApp = generateRandomBool();
    result.inMyList = generateRandomBool();
    result.stack = generateRandomString();
    result.recipientStatus = RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK;
    return result;
}

SharedNotebook generateRandomSharedNotebook()
{
    SharedNotebook result;
    result.id = generateRandomInt64();
    result.userId = generateRandomInt32();
    result.notebookGuid = generateRandomString();
    result.email = generateRandomString();
    result.recipientIdentityId = generateRandomInt64();
    result.notebookModifiable = generateRandomBool();
    result.serviceCreated = generateRandomInt64();
    result.serviceUpdated = generateRandomInt64();
    result.globalId = generateRandomString();
    result.username = generateRandomString();
    result.privilege = SharedNotebookPrivilegeLevel::GROUP;
    result.recipientSettings = generateRandomSharedNotebookRecipientSettings();
    result.sharerUserId = generateRandomInt32();
    result.recipientUsername = generateRandomString();
    result.recipientUserId = generateRandomInt32();
    result.serviceAssigned = generateRandomInt64();
    return result;
}

CanMoveToContainerRestrictions generateRandomCanMoveToContainerRestrictions()
{
    CanMoveToContainerRestrictions result;
    result.canMoveToContainer = CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE;
    return result;
}

NotebookRestrictions generateRandomNotebookRestrictions()
{
    NotebookRestrictions result;
    result.noReadNotes = generateRandomBool();
    result.noCreateNotes = generateRandomBool();
    result.noUpdateNotes = generateRandomBool();
    result.noExpungeNotes = generateRandomBool();
    result.noShareNotes = generateRandomBool();
    result.noEmailNotes = generateRandomBool();
    result.noSendMessageToRecipients = generateRandomBool();
    result.noUpdateNotebook = generateRandomBool();
    result.noExpungeNotebook = generateRandomBool();
    result.noSetDefaultNotebook = generateRandomBool();
    result.noSetNotebookStack = generateRandomBool();
    result.noPublishToPublic = generateRandomBool();
    result.noPublishToBusinessLibrary = generateRandomBool();
    result.noCreateTags = generateRandomBool();
    result.noUpdateTags = generateRandomBool();
    result.noExpungeTags = generateRandomBool();
    result.noSetParentTag = generateRandomBool();
    result.noCreateSharedNotebooks = generateRandomBool();
    result.updateWhichSharedNotebookRestrictions = SharedNotebookInstanceRestrictions::ASSIGNED;
    result.expungeWhichSharedNotebookRestrictions = SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS;
    result.noShareNotesWithBusiness = generateRandomBool();
    result.noRenameNotebook = generateRandomBool();
    result.noSetInMyList = generateRandomBool();
    result.noChangeContact = generateRandomBool();
    result.canMoveToContainerRestrictions = generateRandomCanMoveToContainerRestrictions();
    result.noSetReminderNotifyEmail = generateRandomBool();
    result.noSetReminderNotifyInApp = generateRandomBool();
    result.noSetRecipientSettingsStack = generateRandomBool();
    result.noCanMoveNote = generateRandomBool();
    return result;
}

Notebook generateRandomNotebook()
{
    Notebook result;
    result.guid = generateRandomString();
    result.name = generateRandomString();
    result.updateSequenceNum = generateRandomInt32();
    result.defaultNotebook = generateRandomBool();
    result.serviceCreated = generateRandomInt64();
    result.serviceUpdated = generateRandomInt64();
    result.publishing = generateRandomPublishing();
    result.published = generateRandomBool();
    result.stack = generateRandomString();
    result.sharedNotebookIds = QList<qint64>();
    result.sharedNotebookIds.ref() << generateRandomInt64();
    result.sharedNotebookIds.ref() << generateRandomInt64();
    result.sharedNotebookIds.ref() << generateRandomInt64();
    result.sharedNotebooks = QList<SharedNotebook>();
    result.sharedNotebooks.ref() << generateRandomSharedNotebook();
    result.sharedNotebooks.ref() << generateRandomSharedNotebook();
    result.sharedNotebooks.ref() << generateRandomSharedNotebook();
    result.businessNotebook = generateRandomBusinessNotebook();
    result.contact = generateRandomUser();
    result.restrictions = generateRandomNotebookRestrictions();
    result.recipientSettings = generateRandomNotebookRecipientSettings();
    return result;
}

LinkedNotebook generateRandomLinkedNotebook()
{
    LinkedNotebook result;
    result.shareName = generateRandomString();
    result.username = generateRandomString();
    result.shardId = generateRandomString();
    result.sharedNotebookGlobalId = generateRandomString();
    result.uri = generateRandomString();
    result.guid = generateRandomString();
    result.updateSequenceNum = generateRandomInt32();
    result.noteStoreUrl = generateRandomString();
    result.webApiUrlPrefix = generateRandomString();
    result.stack = generateRandomString();
    result.businessId = generateRandomInt32();
    return result;
}

NotebookDescriptor generateRandomNotebookDescriptor()
{
    NotebookDescriptor result;
    result.guid = generateRandomString();
    result.notebookDisplayName = generateRandomString();
    result.contactName = generateRandomString();
    result.hasSharedNotebook = generateRandomBool();
    result.joinedUserCount = generateRandomInt32();
    return result;
}

UserProfile generateRandomUserProfile()
{
    UserProfile result;
    result.id = generateRandomInt32();
    result.name = generateRandomString();
    result.email = generateRandomString();
    result.username = generateRandomString();
    result.attributes = generateRandomBusinessUserAttributes();
    result.joined = generateRandomInt64();
    result.photoLastUpdated = generateRandomInt64();
    result.photoUrl = generateRandomString();
    result.role = BusinessUserRole::NORMAL;
    result.status = BusinessUserStatus::ACTIVE;
    return result;
}

RelatedContentImage generateRandomRelatedContentImage()
{
    RelatedContentImage result;
    result.url = generateRandomString();
    result.width = generateRandomInt32();
    result.height = generateRandomInt32();
    result.pixelRatio = generateRandomDouble();
    result.fileSize = generateRandomInt32();
    return result;
}

RelatedContent generateRandomRelatedContent()
{
    RelatedContent result;
    result.contentId = generateRandomString();
    result.title = generateRandomString();
    result.url = generateRandomString();
    result.sourceId = generateRandomString();
    result.sourceUrl = generateRandomString();
    result.sourceFaviconUrl = generateRandomString();
    result.sourceName = generateRandomString();
    result.date = generateRandomInt64();
    result.teaser = generateRandomString();
    result.thumbnails = QList<RelatedContentImage>();
    result.thumbnails.ref() << generateRandomRelatedContentImage();
    result.thumbnails.ref() << generateRandomRelatedContentImage();
    result.thumbnails.ref() << generateRandomRelatedContentImage();
    result.contentType = RelatedContentType::NEWS_ARTICLE;
    result.accessType = RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW;
    result.visibleUrl = generateRandomString();
    result.clipUrl = generateRandomString();
    result.contact = generateRandomContact();
    result.authors = QList<QString>();
    result.authors.ref() << generateRandomString();
    result.authors.ref() << generateRandomString();
    result.authors.ref() << generateRandomString();
    return result;
}

BusinessInvitation generateRandomBusinessInvitation()
{
    BusinessInvitation result;
    result.businessId = generateRandomInt32();
    result.email = generateRandomString();
    result.role = BusinessUserRole::ADMIN;
    result.status = BusinessInvitationStatus::APPROVED;
    result.requesterId = generateRandomInt32();
    result.fromWorkChat = generateRandomBool();
    result.created = generateRandomInt64();
    result.mostRecentReminder = generateRandomInt64();
    return result;
}

UserIdentity generateRandomUserIdentity()
{
    UserIdentity result;
    result.type = UserIdentityType::IDENTITYID;
    result.stringIdentifier = generateRandomString();
    result.longIdentifier = generateRandomInt64();
    return result;
}

PublicUserInfo generateRandomPublicUserInfo()
{
    PublicUserInfo result;
    result.userId = generateRandomInt32();
    result.serviceLevel = ServiceLevel::PLUS;
    result.username = generateRandomString();
    result.noteStoreUrl = generateRandomString();
    result.webApiUrlPrefix = generateRandomString();
    return result;
}

UserUrls generateRandomUserUrls()
{
    UserUrls result;
    result.noteStoreUrl = generateRandomString();
    result.webApiUrlPrefix = generateRandomString();
    result.userStoreUrl = generateRandomString();
    result.utilityUrl = generateRandomString();
    result.messageStoreUrl = generateRandomString();
    result.userWebSocketUrl = generateRandomString();
    return result;
}

AuthenticationResult generateRandomAuthenticationResult()
{
    AuthenticationResult result;
    result.currentTime = generateRandomInt64();
    result.authenticationToken = generateRandomString();
    result.expiration = generateRandomInt64();
    result.user = generateRandomUser();
    result.publicUserInfo = generateRandomPublicUserInfo();
    result.noteStoreUrl = generateRandomString();
    result.webApiUrlPrefix = generateRandomString();
    result.secondFactorRequired = generateRandomBool();
    result.secondFactorDeliveryHint = generateRandomString();
    result.urls = generateRandomUserUrls();
    return result;
}

BootstrapSettings generateRandomBootstrapSettings()
{
    BootstrapSettings result;
    result.serviceHost = generateRandomString();
    result.marketingUrl = generateRandomString();
    result.supportUrl = generateRandomString();
    result.accountEmailDomain = generateRandomString();
    result.enableFacebookSharing = generateRandomBool();
    result.enableGiftSubscriptions = generateRandomBool();
    result.enableSupportTickets = generateRandomBool();
    result.enableSharedNotebooks = generateRandomBool();
    result.enableSingleNoteSharing = generateRandomBool();
    result.enableSponsoredAccounts = generateRandomBool();
    result.enableTwitterSharing = generateRandomBool();
    result.enableLinkedInSharing = generateRandomBool();
    result.enablePublicNotebooks = generateRandomBool();
    result.enableGoogle = generateRandomBool();
    return result;
}

BootstrapProfile generateRandomBootstrapProfile()
{
    BootstrapProfile result;
    result.name = generateRandomString();
    result.settings = generateRandomBootstrapSettings();
    return result;
}

BootstrapInfo generateRandomBootstrapInfo()
{
    BootstrapInfo result;
    result.profiles << generateRandomBootstrapProfile();
    result.profiles << generateRandomBootstrapProfile();
    result.profiles << generateRandomBootstrapProfile();
    return result;
}

} // namespace qevercloud
