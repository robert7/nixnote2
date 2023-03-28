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

#include <generated/Types.h>
#include "../Impl.h"
#include "../Impl.h"
#include "Types_io.h"
#include <Helpers.h>
#include <QDebug>
#include <QUuid>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

/** @cond HIDDEN_SYMBOLS  */

void readEnumEDAMErrorCode(
    ThriftBinaryBufferReader & reader,
    EDAMErrorCode & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(EDAMErrorCode::UNKNOWN): e = EDAMErrorCode::UNKNOWN; break;
    case static_cast<int>(EDAMErrorCode::BAD_DATA_FORMAT): e = EDAMErrorCode::BAD_DATA_FORMAT; break;
    case static_cast<int>(EDAMErrorCode::PERMISSION_DENIED): e = EDAMErrorCode::PERMISSION_DENIED; break;
    case static_cast<int>(EDAMErrorCode::INTERNAL_ERROR): e = EDAMErrorCode::INTERNAL_ERROR; break;
    case static_cast<int>(EDAMErrorCode::DATA_REQUIRED): e = EDAMErrorCode::DATA_REQUIRED; break;
    case static_cast<int>(EDAMErrorCode::LIMIT_REACHED): e = EDAMErrorCode::LIMIT_REACHED; break;
    case static_cast<int>(EDAMErrorCode::QUOTA_REACHED): e = EDAMErrorCode::QUOTA_REACHED; break;
    case static_cast<int>(EDAMErrorCode::INVALID_AUTH): e = EDAMErrorCode::INVALID_AUTH; break;
    case static_cast<int>(EDAMErrorCode::AUTH_EXPIRED): e = EDAMErrorCode::AUTH_EXPIRED; break;
    case static_cast<int>(EDAMErrorCode::DATA_CONFLICT): e = EDAMErrorCode::DATA_CONFLICT; break;
    case static_cast<int>(EDAMErrorCode::ENML_VALIDATION): e = EDAMErrorCode::ENML_VALIDATION; break;
    case static_cast<int>(EDAMErrorCode::SHARD_UNAVAILABLE): e = EDAMErrorCode::SHARD_UNAVAILABLE; break;
    case static_cast<int>(EDAMErrorCode::LEN_TOO_SHORT): e = EDAMErrorCode::LEN_TOO_SHORT; break;
    case static_cast<int>(EDAMErrorCode::LEN_TOO_LONG): e = EDAMErrorCode::LEN_TOO_LONG; break;
    case static_cast<int>(EDAMErrorCode::TOO_FEW): e = EDAMErrorCode::TOO_FEW; break;
    case static_cast<int>(EDAMErrorCode::TOO_MANY): e = EDAMErrorCode::TOO_MANY; break;
    case static_cast<int>(EDAMErrorCode::UNSUPPORTED_OPERATION): e = EDAMErrorCode::UNSUPPORTED_OPERATION; break;
    case static_cast<int>(EDAMErrorCode::TAKEN_DOWN): e = EDAMErrorCode::TAKEN_DOWN; break;
    case static_cast<int>(EDAMErrorCode::RATE_LIMIT_REACHED): e = EDAMErrorCode::RATE_LIMIT_REACHED; break;
    case static_cast<int>(EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED): e = EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED; break;
    case static_cast<int>(EDAMErrorCode::DEVICE_LIMIT_REACHED): e = EDAMErrorCode::DEVICE_LIMIT_REACHED; break;
    case static_cast<int>(EDAMErrorCode::OPENID_ALREADY_TAKEN): e = EDAMErrorCode::OPENID_ALREADY_TAKEN; break;
    case static_cast<int>(EDAMErrorCode::INVALID_OPENID_TOKEN): e = EDAMErrorCode::INVALID_OPENID_TOKEN; break;
    case static_cast<int>(EDAMErrorCode::USER_NOT_ASSOCIATED): e = EDAMErrorCode::USER_NOT_ASSOCIATED; break;
    case static_cast<int>(EDAMErrorCode::USER_NOT_REGISTERED): e = EDAMErrorCode::USER_NOT_REGISTERED; break;
    case static_cast<int>(EDAMErrorCode::USER_ALREADY_ASSOCIATED): e = EDAMErrorCode::USER_ALREADY_ASSOCIATED; break;
    case static_cast<int>(EDAMErrorCode::ACCOUNT_CLEAR): e = EDAMErrorCode::ACCOUNT_CLEAR; break;
    case static_cast<int>(EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED): e = EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum EDAMErrorCode"));
    }
}

void readEnumEDAMInvalidContactReason(
    ThriftBinaryBufferReader & reader,
    EDAMInvalidContactReason & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(EDAMInvalidContactReason::BAD_ADDRESS): e = EDAMInvalidContactReason::BAD_ADDRESS; break;
    case static_cast<int>(EDAMInvalidContactReason::DUPLICATE_CONTACT): e = EDAMInvalidContactReason::DUPLICATE_CONTACT; break;
    case static_cast<int>(EDAMInvalidContactReason::NO_CONNECTION): e = EDAMInvalidContactReason::NO_CONNECTION; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum EDAMInvalidContactReason"));
    }
}

void readEnumShareRelationshipPrivilegeLevel(
    ThriftBinaryBufferReader & reader,
    ShareRelationshipPrivilegeLevel & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK): e = ShareRelationshipPrivilegeLevel::READ_NOTEBOOK; break;
    case static_cast<int>(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY): e = ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY; break;
    case static_cast<int>(ShareRelationshipPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY): e = ShareRelationshipPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY; break;
    case static_cast<int>(ShareRelationshipPrivilegeLevel::FULL_ACCESS): e = ShareRelationshipPrivilegeLevel::FULL_ACCESS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum ShareRelationshipPrivilegeLevel"));
    }
}

void readEnumPrivilegeLevel(
    ThriftBinaryBufferReader & reader,
    PrivilegeLevel & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(PrivilegeLevel::NORMAL): e = PrivilegeLevel::NORMAL; break;
    case static_cast<int>(PrivilegeLevel::PREMIUM): e = PrivilegeLevel::PREMIUM; break;
    case static_cast<int>(PrivilegeLevel::VIP): e = PrivilegeLevel::VIP; break;
    case static_cast<int>(PrivilegeLevel::MANAGER): e = PrivilegeLevel::MANAGER; break;
    case static_cast<int>(PrivilegeLevel::SUPPORT): e = PrivilegeLevel::SUPPORT; break;
    case static_cast<int>(PrivilegeLevel::ADMIN): e = PrivilegeLevel::ADMIN; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum PrivilegeLevel"));
    }
}

void readEnumServiceLevel(
    ThriftBinaryBufferReader & reader,
    ServiceLevel & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(ServiceLevel::BASIC): e = ServiceLevel::BASIC; break;
    case static_cast<int>(ServiceLevel::PLUS): e = ServiceLevel::PLUS; break;
    case static_cast<int>(ServiceLevel::PREMIUM): e = ServiceLevel::PREMIUM; break;
    case static_cast<int>(ServiceLevel::BUSINESS): e = ServiceLevel::BUSINESS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum ServiceLevel"));
    }
}

void readEnumQueryFormat(
    ThriftBinaryBufferReader & reader,
    QueryFormat & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(QueryFormat::USER): e = QueryFormat::USER; break;
    case static_cast<int>(QueryFormat::SEXP): e = QueryFormat::SEXP; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum QueryFormat"));
    }
}

void readEnumNoteSortOrder(
    ThriftBinaryBufferReader & reader,
    NoteSortOrder & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(NoteSortOrder::CREATED): e = NoteSortOrder::CREATED; break;
    case static_cast<int>(NoteSortOrder::UPDATED): e = NoteSortOrder::UPDATED; break;
    case static_cast<int>(NoteSortOrder::RELEVANCE): e = NoteSortOrder::RELEVANCE; break;
    case static_cast<int>(NoteSortOrder::UPDATE_SEQUENCE_NUMBER): e = NoteSortOrder::UPDATE_SEQUENCE_NUMBER; break;
    case static_cast<int>(NoteSortOrder::TITLE): e = NoteSortOrder::TITLE; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum NoteSortOrder"));
    }
}

void readEnumPremiumOrderStatus(
    ThriftBinaryBufferReader & reader,
    PremiumOrderStatus & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(PremiumOrderStatus::NONE): e = PremiumOrderStatus::NONE; break;
    case static_cast<int>(PremiumOrderStatus::PENDING): e = PremiumOrderStatus::PENDING; break;
    case static_cast<int>(PremiumOrderStatus::ACTIVE): e = PremiumOrderStatus::ACTIVE; break;
    case static_cast<int>(PremiumOrderStatus::FAILED): e = PremiumOrderStatus::FAILED; break;
    case static_cast<int>(PremiumOrderStatus::CANCELLATION_PENDING): e = PremiumOrderStatus::CANCELLATION_PENDING; break;
    case static_cast<int>(PremiumOrderStatus::CANCELED): e = PremiumOrderStatus::CANCELED; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum PremiumOrderStatus"));
    }
}

void readEnumSharedNotebookPrivilegeLevel(
    ThriftBinaryBufferReader & reader,
    SharedNotebookPrivilegeLevel & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(SharedNotebookPrivilegeLevel::READ_NOTEBOOK): e = SharedNotebookPrivilegeLevel::READ_NOTEBOOK; break;
    case static_cast<int>(SharedNotebookPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY): e = SharedNotebookPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY; break;
    case static_cast<int>(SharedNotebookPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY): e = SharedNotebookPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY; break;
    case static_cast<int>(SharedNotebookPrivilegeLevel::GROUP): e = SharedNotebookPrivilegeLevel::GROUP; break;
    case static_cast<int>(SharedNotebookPrivilegeLevel::FULL_ACCESS): e = SharedNotebookPrivilegeLevel::FULL_ACCESS; break;
    case static_cast<int>(SharedNotebookPrivilegeLevel::BUSINESS_FULL_ACCESS): e = SharedNotebookPrivilegeLevel::BUSINESS_FULL_ACCESS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum SharedNotebookPrivilegeLevel"));
    }
}

void readEnumSharedNotePrivilegeLevel(
    ThriftBinaryBufferReader & reader,
    SharedNotePrivilegeLevel & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(SharedNotePrivilegeLevel::READ_NOTE): e = SharedNotePrivilegeLevel::READ_NOTE; break;
    case static_cast<int>(SharedNotePrivilegeLevel::MODIFY_NOTE): e = SharedNotePrivilegeLevel::MODIFY_NOTE; break;
    case static_cast<int>(SharedNotePrivilegeLevel::FULL_ACCESS): e = SharedNotePrivilegeLevel::FULL_ACCESS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum SharedNotePrivilegeLevel"));
    }
}

void readEnumSponsoredGroupRole(
    ThriftBinaryBufferReader & reader,
    SponsoredGroupRole & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(SponsoredGroupRole::GROUP_MEMBER): e = SponsoredGroupRole::GROUP_MEMBER; break;
    case static_cast<int>(SponsoredGroupRole::GROUP_ADMIN): e = SponsoredGroupRole::GROUP_ADMIN; break;
    case static_cast<int>(SponsoredGroupRole::GROUP_OWNER): e = SponsoredGroupRole::GROUP_OWNER; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum SponsoredGroupRole"));
    }
}

void readEnumBusinessUserRole(
    ThriftBinaryBufferReader & reader,
    BusinessUserRole & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(BusinessUserRole::ADMIN): e = BusinessUserRole::ADMIN; break;
    case static_cast<int>(BusinessUserRole::NORMAL): e = BusinessUserRole::NORMAL; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum BusinessUserRole"));
    }
}

void readEnumBusinessUserStatus(
    ThriftBinaryBufferReader & reader,
    BusinessUserStatus & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(BusinessUserStatus::ACTIVE): e = BusinessUserStatus::ACTIVE; break;
    case static_cast<int>(BusinessUserStatus::DEACTIVATED): e = BusinessUserStatus::DEACTIVATED; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum BusinessUserStatus"));
    }
}

void readEnumSharedNotebookInstanceRestrictions(
    ThriftBinaryBufferReader & reader,
    SharedNotebookInstanceRestrictions & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(SharedNotebookInstanceRestrictions::ASSIGNED): e = SharedNotebookInstanceRestrictions::ASSIGNED; break;
    case static_cast<int>(SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS): e = SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum SharedNotebookInstanceRestrictions"));
    }
}

void readEnumReminderEmailConfig(
    ThriftBinaryBufferReader & reader,
    ReminderEmailConfig & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(ReminderEmailConfig::DO_NOT_SEND): e = ReminderEmailConfig::DO_NOT_SEND; break;
    case static_cast<int>(ReminderEmailConfig::SEND_DAILY_EMAIL): e = ReminderEmailConfig::SEND_DAILY_EMAIL; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum ReminderEmailConfig"));
    }
}

void readEnumBusinessInvitationStatus(
    ThriftBinaryBufferReader & reader,
    BusinessInvitationStatus & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(BusinessInvitationStatus::APPROVED): e = BusinessInvitationStatus::APPROVED; break;
    case static_cast<int>(BusinessInvitationStatus::REQUESTED): e = BusinessInvitationStatus::REQUESTED; break;
    case static_cast<int>(BusinessInvitationStatus::REDEEMED): e = BusinessInvitationStatus::REDEEMED; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum BusinessInvitationStatus"));
    }
}

void readEnumContactType(
    ThriftBinaryBufferReader & reader,
    ContactType & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(ContactType::EVERNOTE): e = ContactType::EVERNOTE; break;
    case static_cast<int>(ContactType::SMS): e = ContactType::SMS; break;
    case static_cast<int>(ContactType::FACEBOOK): e = ContactType::FACEBOOK; break;
    case static_cast<int>(ContactType::EMAIL): e = ContactType::EMAIL; break;
    case static_cast<int>(ContactType::TWITTER): e = ContactType::TWITTER; break;
    case static_cast<int>(ContactType::LINKEDIN): e = ContactType::LINKEDIN; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum ContactType"));
    }
}

void readEnumEntityType(
    ThriftBinaryBufferReader & reader,
    EntityType & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(EntityType::NOTE): e = EntityType::NOTE; break;
    case static_cast<int>(EntityType::NOTEBOOK): e = EntityType::NOTEBOOK; break;
    case static_cast<int>(EntityType::WORKSPACE): e = EntityType::WORKSPACE; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum EntityType"));
    }
}

void readEnumRecipientStatus(
    ThriftBinaryBufferReader & reader,
    RecipientStatus & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(RecipientStatus::NOT_IN_MY_LIST): e = RecipientStatus::NOT_IN_MY_LIST; break;
    case static_cast<int>(RecipientStatus::IN_MY_LIST): e = RecipientStatus::IN_MY_LIST; break;
    case static_cast<int>(RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK): e = RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum RecipientStatus"));
    }
}

void readEnumCanMoveToContainerStatus(
    ThriftBinaryBufferReader & reader,
    CanMoveToContainerStatus & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(CanMoveToContainerStatus::CAN_BE_MOVED): e = CanMoveToContainerStatus::CAN_BE_MOVED; break;
    case static_cast<int>(CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE): e = CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE; break;
    case static_cast<int>(CanMoveToContainerStatus::INSUFFICIENT_CONTAINER_PRIVILEGE): e = CanMoveToContainerStatus::INSUFFICIENT_CONTAINER_PRIVILEGE; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum CanMoveToContainerStatus"));
    }
}

void readEnumRelatedContentType(
    ThriftBinaryBufferReader & reader,
    RelatedContentType & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(RelatedContentType::NEWS_ARTICLE): e = RelatedContentType::NEWS_ARTICLE; break;
    case static_cast<int>(RelatedContentType::PROFILE_PERSON): e = RelatedContentType::PROFILE_PERSON; break;
    case static_cast<int>(RelatedContentType::PROFILE_ORGANIZATION): e = RelatedContentType::PROFILE_ORGANIZATION; break;
    case static_cast<int>(RelatedContentType::REFERENCE_MATERIAL): e = RelatedContentType::REFERENCE_MATERIAL; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum RelatedContentType"));
    }
}

void readEnumRelatedContentAccess(
    ThriftBinaryBufferReader & reader,
    RelatedContentAccess & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(RelatedContentAccess::NOT_ACCESSIBLE): e = RelatedContentAccess::NOT_ACCESSIBLE; break;
    case static_cast<int>(RelatedContentAccess::DIRECT_LINK_ACCESS_OK): e = RelatedContentAccess::DIRECT_LINK_ACCESS_OK; break;
    case static_cast<int>(RelatedContentAccess::DIRECT_LINK_LOGIN_REQUIRED): e = RelatedContentAccess::DIRECT_LINK_LOGIN_REQUIRED; break;
    case static_cast<int>(RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW): e = RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum RelatedContentAccess"));
    }
}

void readEnumUserIdentityType(
    ThriftBinaryBufferReader & reader,
    UserIdentityType & e)
{
    qint32 i;
    reader.readI32(i);
    switch(i) {
    case static_cast<int>(UserIdentityType::EVERNOTE_USERID): e = UserIdentityType::EVERNOTE_USERID; break;
    case static_cast<int>(UserIdentityType::EMAIL): e = UserIdentityType::EMAIL; break;
    case static_cast<int>(UserIdentityType::IDENTITYID): e = UserIdentityType::IDENTITYID; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum UserIdentityType"));
    }
}

EverCloudLocalData::EverCloudLocalData()
{
    id = QUuid::createUuid().toString();
    // Remove curvy braces
    id.remove(id.size() - 1, 1);
    id.remove(0, 1);
}

EverCloudLocalData::~EverCloudLocalData() noexcept
{}

void EverCloudLocalData::print(QTextStream & strm) const
{
    strm << "    localData.id = " << id << "\n"
        << "    localData.dirty = " << (dirty ? "true" : "false") << "\n"
        << "    localData.local = " << (local ? "true" : "false") << "\n"
        << "    localData.favorited = " << (favorited ? "true" : "false") << "\n";

    if (!dict.isEmpty())
    {
        strm << "    localData.dict:" << "\n";
        QString valueStr;
        for(const auto & it: toRange(dict)) {
            strm << "        [" << it.key() << "] = ";
            valueStr.resize(0);
            QDebug dbg(&valueStr);
            dbg.noquote();
            dbg.nospace();
            dbg << it.value();
            strm << valueStr << "\n";
        }
    }
}

bool EverCloudLocalData::operator==(
    const EverCloudLocalData & other) const
{
    return id == other.id && dirty == other.dirty &&
        local == other.local && favorited == other.favorited &&
        dict == other.dict;
}

bool EverCloudLocalData::operator!=(
    const EverCloudLocalData & other) const
{
    return !operator==(other);
}

void writeSyncState(
    ThriftBinaryBufferWriter & writer,
    const SyncState & s)
{
    writer.writeStructBegin(QStringLiteral("SyncState"));
    writer.writeFieldBegin(
        QStringLiteral("currentTime"),
        ThriftFieldType::T_I64,
        1);

    writer.writeI64(s.currentTime);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("fullSyncBefore"),
        ThriftFieldType::T_I64,
        2);

    writer.writeI64(s.fullSyncBefore);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("updateCount"),
        ThriftFieldType::T_I32,
        3);

    writer.writeI32(s.updateCount);
    writer.writeFieldEnd();

    if (s.uploaded.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("uploaded"),
            ThriftFieldType::T_I64,
            4);

        writer.writeI64(s.uploaded.ref());
        writer.writeFieldEnd();
    }

    if (s.userLastUpdated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userLastUpdated"),
            ThriftFieldType::T_I64,
            5);

        writer.writeI64(s.userLastUpdated.ref());
        writer.writeFieldEnd();
    }

    if (s.userMaxMessageEventId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userMaxMessageEventId"),
            ThriftFieldType::T_I64,
            6);

        writer.writeI64(s.userMaxMessageEventId.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSyncState(
    ThriftBinaryBufferReader & reader,
    SyncState & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool currentTime_isset = false;
    bool fullSyncBefore_isset = false;
    bool updateCount_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                currentTime_isset = true;
                qint64 v;
                reader.readI64(v);
                s.currentTime = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                fullSyncBefore_isset = true;
                qint64 v;
                reader.readI64(v);
                s.fullSyncBefore = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                updateCount_isset = true;
                qint32 v;
                reader.readI32(v);
                s.updateCount = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.uploaded = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.userLastUpdated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageEventID v;
                reader.readI64(v);
                s.userMaxMessageEventId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!currentTime_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncState.currentTime has no value"));
    if (!fullSyncBefore_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncState.fullSyncBefore has no value"));
    if (!updateCount_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncState.updateCount has no value"));
}

void SyncState::print(QTextStream & strm) const
{
    strm << "SyncState: {\n";
    localData.print(strm);
    strm << "    currentTime = "
        << currentTime << "\n";
    strm << "    fullSyncBefore = "
        << fullSyncBefore << "\n";
    strm << "    updateCount = "
        << updateCount << "\n";

    if (uploaded.isSet()) {
        strm << "    uploaded = "
            << uploaded.ref() << "\n";
    }
    else {
        strm << "    uploaded is not set\n";
    }

    if (userLastUpdated.isSet()) {
        strm << "    userLastUpdated = "
            << userLastUpdated.ref() << "\n";
    }
    else {
        strm << "    userLastUpdated is not set\n";
    }

    if (userMaxMessageEventId.isSet()) {
        strm << "    userMaxMessageEventId = "
            << userMaxMessageEventId.ref() << "\n";
    }
    else {
        strm << "    userMaxMessageEventId is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeSyncChunk(
    ThriftBinaryBufferWriter & writer,
    const SyncChunk & s)
{
    writer.writeStructBegin(QStringLiteral("SyncChunk"));
    writer.writeFieldBegin(
        QStringLiteral("currentTime"),
        ThriftFieldType::T_I64,
        1);

    writer.writeI64(s.currentTime);
    writer.writeFieldEnd();

    if (s.chunkHighUSN.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("chunkHighUSN"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(s.chunkHighUSN.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldBegin(
        QStringLiteral("updateCount"),
        ThriftFieldType::T_I32,
        3);

    writer.writeI32(s.updateCount);
    writer.writeFieldEnd();

    if (s.notes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notes"),
            ThriftFieldType::T_LIST,
            4);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.notes.ref().length());
        for(const auto & value: qAsConst(s.notes.ref())) {
            writeNote(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.notebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notebooks"),
            ThriftFieldType::T_LIST,
            5);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.notebooks.ref().length());
        for(const auto & value: qAsConst(s.notebooks.ref())) {
            writeNotebook(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.tags.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("tags"),
            ThriftFieldType::T_LIST,
            6);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.tags.ref().length());
        for(const auto & value: qAsConst(s.tags.ref())) {
            writeTag(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.searches.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("searches"),
            ThriftFieldType::T_LIST,
            7);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.searches.ref().length());
        for(const auto & value: qAsConst(s.searches.ref())) {
            writeSavedSearch(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.resources.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("resources"),
            ThriftFieldType::T_LIST,
            8);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.resources.ref().length());
        for(const auto & value: qAsConst(s.resources.ref())) {
            writeResource(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.expungedNotes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("expungedNotes"),
            ThriftFieldType::T_LIST,
            9);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.expungedNotes.ref().length());
        for(const auto & value: qAsConst(s.expungedNotes.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.expungedNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("expungedNotebooks"),
            ThriftFieldType::T_LIST,
            10);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.expungedNotebooks.ref().length());
        for(const auto & value: qAsConst(s.expungedNotebooks.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.expungedTags.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("expungedTags"),
            ThriftFieldType::T_LIST,
            11);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.expungedTags.ref().length());
        for(const auto & value: qAsConst(s.expungedTags.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.expungedSearches.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("expungedSearches"),
            ThriftFieldType::T_LIST,
            12);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.expungedSearches.ref().length());
        for(const auto & value: qAsConst(s.expungedSearches.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.linkedNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("linkedNotebooks"),
            ThriftFieldType::T_LIST,
            13);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.linkedNotebooks.ref().length());
        for(const auto & value: qAsConst(s.linkedNotebooks.ref())) {
            writeLinkedNotebook(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.expungedLinkedNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("expungedLinkedNotebooks"),
            ThriftFieldType::T_LIST,
            14);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.expungedLinkedNotebooks.ref().length());
        for(const auto & value: qAsConst(s.expungedLinkedNotebooks.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSyncChunk(
    ThriftBinaryBufferReader & reader,
    SyncChunk & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool currentTime_isset = false;
    bool updateCount_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                currentTime_isset = true;
                qint64 v;
                reader.readI64(v);
                s.currentTime = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.chunkHighUSN = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                updateCount_isset = true;
                qint32 v;
                reader.readI32(v);
                s.updateCount = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Note> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.notes)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Note elem;
                    readNote(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.notes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Notebook> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.notebooks)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Notebook elem;
                    readNotebook(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.notebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Tag> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.tags)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Tag elem;
                    readTag(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.tags = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<SavedSearch> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.searches)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    SavedSearch elem;
                    readSavedSearch(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.searches = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Resource> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.resources)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Resource elem;
                    readResource(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.resources = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.expungedNotes)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.expungedNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.expungedNotebooks)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.expungedNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.expungedTags)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.expungedTags = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.expungedSearches)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.expungedSearches = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<LinkedNotebook> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.linkedNotebooks)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    LinkedNotebook elem;
                    readLinkedNotebook(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.linkedNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SyncChunk.expungedLinkedNotebooks)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.expungedLinkedNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!currentTime_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncChunk.currentTime has no value"));
    if (!updateCount_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncChunk.updateCount has no value"));
}

void SyncChunk::print(QTextStream & strm) const
{
    strm << "SyncChunk: {\n";
    localData.print(strm);
    strm << "    currentTime = "
        << currentTime << "\n";

    if (chunkHighUSN.isSet()) {
        strm << "    chunkHighUSN = "
            << chunkHighUSN.ref() << "\n";
    }
    else {
        strm << "    chunkHighUSN is not set\n";
    }

    strm << "    updateCount = "
        << updateCount << "\n";

    if (notes.isSet()) {
        strm << "    notes = "
            << "QList<Note> {";
        for(const auto & v: notes.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    notes is not set\n";
    }

    if (notebooks.isSet()) {
        strm << "    notebooks = "
            << "QList<Notebook> {";
        for(const auto & v: notebooks.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    notebooks is not set\n";
    }

    if (tags.isSet()) {
        strm << "    tags = "
            << "QList<Tag> {";
        for(const auto & v: tags.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    tags is not set\n";
    }

    if (searches.isSet()) {
        strm << "    searches = "
            << "QList<SavedSearch> {";
        for(const auto & v: searches.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    searches is not set\n";
    }

    if (resources.isSet()) {
        strm << "    resources = "
            << "QList<Resource> {";
        for(const auto & v: resources.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    resources is not set\n";
    }

    if (expungedNotes.isSet()) {
        strm << "    expungedNotes = "
            << "QList<Guid> {";
        for(const auto & v: expungedNotes.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    expungedNotes is not set\n";
    }

    if (expungedNotebooks.isSet()) {
        strm << "    expungedNotebooks = "
            << "QList<Guid> {";
        for(const auto & v: expungedNotebooks.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    expungedNotebooks is not set\n";
    }

    if (expungedTags.isSet()) {
        strm << "    expungedTags = "
            << "QList<Guid> {";
        for(const auto & v: expungedTags.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    expungedTags is not set\n";
    }

    if (expungedSearches.isSet()) {
        strm << "    expungedSearches = "
            << "QList<Guid> {";
        for(const auto & v: expungedSearches.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    expungedSearches is not set\n";
    }

    if (linkedNotebooks.isSet()) {
        strm << "    linkedNotebooks = "
            << "QList<LinkedNotebook> {";
        for(const auto & v: linkedNotebooks.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    linkedNotebooks is not set\n";
    }

    if (expungedLinkedNotebooks.isSet()) {
        strm << "    expungedLinkedNotebooks = "
            << "QList<Guid> {";
        for(const auto & v: expungedLinkedNotebooks.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    expungedLinkedNotebooks is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeSyncChunkFilter(
    ThriftBinaryBufferWriter & writer,
    const SyncChunkFilter & s)
{
    writer.writeStructBegin(QStringLiteral("SyncChunkFilter"));
    if (s.includeNotes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNotes"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(s.includeNotes.ref());
        writer.writeFieldEnd();
    }

    if (s.includeNoteResources.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNoteResources"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(s.includeNoteResources.ref());
        writer.writeFieldEnd();
    }

    if (s.includeNoteAttributes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNoteAttributes"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(s.includeNoteAttributes.ref());
        writer.writeFieldEnd();
    }

    if (s.includeNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNotebooks"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(s.includeNotebooks.ref());
        writer.writeFieldEnd();
    }

    if (s.includeTags.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeTags"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(s.includeTags.ref());
        writer.writeFieldEnd();
    }

    if (s.includeSearches.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeSearches"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(s.includeSearches.ref());
        writer.writeFieldEnd();
    }

    if (s.includeResources.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeResources"),
            ThriftFieldType::T_BOOL,
            7);

        writer.writeBool(s.includeResources.ref());
        writer.writeFieldEnd();
    }

    if (s.includeLinkedNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeLinkedNotebooks"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(s.includeLinkedNotebooks.ref());
        writer.writeFieldEnd();
    }

    if (s.includeExpunged.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeExpunged"),
            ThriftFieldType::T_BOOL,
            9);

        writer.writeBool(s.includeExpunged.ref());
        writer.writeFieldEnd();
    }

    if (s.includeNoteApplicationDataFullMap.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNoteApplicationDataFullMap"),
            ThriftFieldType::T_BOOL,
            10);

        writer.writeBool(s.includeNoteApplicationDataFullMap.ref());
        writer.writeFieldEnd();
    }

    if (s.includeResourceApplicationDataFullMap.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeResourceApplicationDataFullMap"),
            ThriftFieldType::T_BOOL,
            12);

        writer.writeBool(s.includeResourceApplicationDataFullMap.ref());
        writer.writeFieldEnd();
    }

    if (s.includeNoteResourceApplicationDataFullMap.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNoteResourceApplicationDataFullMap"),
            ThriftFieldType::T_BOOL,
            13);

        writer.writeBool(s.includeNoteResourceApplicationDataFullMap.ref());
        writer.writeFieldEnd();
    }

    if (s.includeSharedNotes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeSharedNotes"),
            ThriftFieldType::T_BOOL,
            17);

        writer.writeBool(s.includeSharedNotes.ref());
        writer.writeFieldEnd();
    }

    if (s.omitSharedNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("omitSharedNotebooks"),
            ThriftFieldType::T_BOOL,
            16);

        writer.writeBool(s.omitSharedNotebooks.ref());
        writer.writeFieldEnd();
    }

    if (s.requireNoteContentClass.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("requireNoteContentClass"),
            ThriftFieldType::T_STRING,
            11);

        writer.writeString(s.requireNoteContentClass.ref());
        writer.writeFieldEnd();
    }

    if (s.notebookGuids.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookGuids"),
            ThriftFieldType::T_SET,
            15);

        writer.writeSetBegin(ThriftFieldType::T_STRING, s.notebookGuids.ref().count());
        for(const auto & value: qAsConst(s.notebookGuids.ref())) {
            writer.writeString(value);
        }
        writer.writeSetEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSyncChunkFilter(
    ThriftBinaryBufferReader & reader,
    SyncChunkFilter & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeNoteResources = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeNoteAttributes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeTags = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeSearches = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeResources = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeLinkedNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeExpunged = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeNoteApplicationDataFullMap = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeResourceApplicationDataFullMap = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeNoteResourceApplicationDataFullMap = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeSharedNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.omitSharedNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.requireNoteContentClass = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_SET) {
                QSet<QString> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readSetBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect set type (SyncChunkFilter.notebookGuids)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.insert(elem);
                }
                reader.readSetEnd();
                s.notebookGuids = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void SyncChunkFilter::print(QTextStream & strm) const
{
    strm << "SyncChunkFilter: {\n";
    localData.print(strm);

    if (includeNotes.isSet()) {
        strm << "    includeNotes = "
            << includeNotes.ref() << "\n";
    }
    else {
        strm << "    includeNotes is not set\n";
    }

    if (includeNoteResources.isSet()) {
        strm << "    includeNoteResources = "
            << includeNoteResources.ref() << "\n";
    }
    else {
        strm << "    includeNoteResources is not set\n";
    }

    if (includeNoteAttributes.isSet()) {
        strm << "    includeNoteAttributes = "
            << includeNoteAttributes.ref() << "\n";
    }
    else {
        strm << "    includeNoteAttributes is not set\n";
    }

    if (includeNotebooks.isSet()) {
        strm << "    includeNotebooks = "
            << includeNotebooks.ref() << "\n";
    }
    else {
        strm << "    includeNotebooks is not set\n";
    }

    if (includeTags.isSet()) {
        strm << "    includeTags = "
            << includeTags.ref() << "\n";
    }
    else {
        strm << "    includeTags is not set\n";
    }

    if (includeSearches.isSet()) {
        strm << "    includeSearches = "
            << includeSearches.ref() << "\n";
    }
    else {
        strm << "    includeSearches is not set\n";
    }

    if (includeResources.isSet()) {
        strm << "    includeResources = "
            << includeResources.ref() << "\n";
    }
    else {
        strm << "    includeResources is not set\n";
    }

    if (includeLinkedNotebooks.isSet()) {
        strm << "    includeLinkedNotebooks = "
            << includeLinkedNotebooks.ref() << "\n";
    }
    else {
        strm << "    includeLinkedNotebooks is not set\n";
    }

    if (includeExpunged.isSet()) {
        strm << "    includeExpunged = "
            << includeExpunged.ref() << "\n";
    }
    else {
        strm << "    includeExpunged is not set\n";
    }

    if (includeNoteApplicationDataFullMap.isSet()) {
        strm << "    includeNoteApplicationDataFullMap = "
            << includeNoteApplicationDataFullMap.ref() << "\n";
    }
    else {
        strm << "    includeNoteApplicationDataFullMap is not set\n";
    }

    if (includeResourceApplicationDataFullMap.isSet()) {
        strm << "    includeResourceApplicationDataFullMap = "
            << includeResourceApplicationDataFullMap.ref() << "\n";
    }
    else {
        strm << "    includeResourceApplicationDataFullMap is not set\n";
    }

    if (includeNoteResourceApplicationDataFullMap.isSet()) {
        strm << "    includeNoteResourceApplicationDataFullMap = "
            << includeNoteResourceApplicationDataFullMap.ref() << "\n";
    }
    else {
        strm << "    includeNoteResourceApplicationDataFullMap is not set\n";
    }

    if (includeSharedNotes.isSet()) {
        strm << "    includeSharedNotes = "
            << includeSharedNotes.ref() << "\n";
    }
    else {
        strm << "    includeSharedNotes is not set\n";
    }

    if (omitSharedNotebooks.isSet()) {
        strm << "    omitSharedNotebooks = "
            << omitSharedNotebooks.ref() << "\n";
    }
    else {
        strm << "    omitSharedNotebooks is not set\n";
    }

    if (requireNoteContentClass.isSet()) {
        strm << "    requireNoteContentClass = "
            << requireNoteContentClass.ref() << "\n";
    }
    else {
        strm << "    requireNoteContentClass is not set\n";
    }

    if (notebookGuids.isSet()) {
        strm << "    notebookGuids = "
            << "QSet<QString> {";
        for(const auto & v: notebookGuids.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    notebookGuids is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteFilter(
    ThriftBinaryBufferWriter & writer,
    const NoteFilter & s)
{
    writer.writeStructBegin(QStringLiteral("NoteFilter"));
    if (s.order.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("order"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(s.order.ref());
        writer.writeFieldEnd();
    }

    if (s.ascending.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("ascending"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(s.ascending.ref());
        writer.writeFieldEnd();
    }

    if (s.words.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("words"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(s.words.ref());
        writer.writeFieldEnd();
    }

    if (s.notebookGuid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.notebookGuid.ref());
        writer.writeFieldEnd();
    }

    if (s.tagGuids.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("tagGuids"),
            ThriftFieldType::T_LIST,
            5);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.tagGuids.ref().length());
        for(const auto & value: qAsConst(s.tagGuids.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.timeZone.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("timeZone"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(s.timeZone.ref());
        writer.writeFieldEnd();
    }

    if (s.inactive.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("inactive"),
            ThriftFieldType::T_BOOL,
            7);

        writer.writeBool(s.inactive.ref());
        writer.writeFieldEnd();
    }

    if (s.emphasized.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("emphasized"),
            ThriftFieldType::T_STRING,
            8);

        writer.writeString(s.emphasized.ref());
        writer.writeFieldEnd();
    }

    if (s.includeAllReadableNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeAllReadableNotebooks"),
            ThriftFieldType::T_BOOL,
            9);

        writer.writeBool(s.includeAllReadableNotebooks.ref());
        writer.writeFieldEnd();
    }

    if (s.includeAllReadableWorkspaces.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeAllReadableWorkspaces"),
            ThriftFieldType::T_BOOL,
            15);

        writer.writeBool(s.includeAllReadableWorkspaces.ref());
        writer.writeFieldEnd();
    }

    if (s.context.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("context"),
            ThriftFieldType::T_STRING,
            10);

        writer.writeString(s.context.ref());
        writer.writeFieldEnd();
    }

    if (s.rawWords.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("rawWords"),
            ThriftFieldType::T_STRING,
            11);

        writer.writeString(s.rawWords.ref());
        writer.writeFieldEnd();
    }

    if (s.searchContextBytes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("searchContextBytes"),
            ThriftFieldType::T_STRING,
            12);

        writer.writeBinary(s.searchContextBytes.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteFilter(
    ThriftBinaryBufferReader & reader,
    NoteFilter & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.order = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.ascending = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.words = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.notebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteFilter.tagGuids)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.tagGuids = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.timeZone = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.inactive = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.emphasized = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeAllReadableNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeAllReadableWorkspaces = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.context = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.rawWords = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                s.searchContextBytes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NoteFilter::print(QTextStream & strm) const
{
    strm << "NoteFilter: {\n";
    localData.print(strm);

    if (order.isSet()) {
        strm << "    order = "
            << order.ref() << "\n";
    }
    else {
        strm << "    order is not set\n";
    }

    if (ascending.isSet()) {
        strm << "    ascending = "
            << ascending.ref() << "\n";
    }
    else {
        strm << "    ascending is not set\n";
    }

    if (words.isSet()) {
        strm << "    words = "
            << words.ref() << "\n";
    }
    else {
        strm << "    words is not set\n";
    }

    if (notebookGuid.isSet()) {
        strm << "    notebookGuid = "
            << notebookGuid.ref() << "\n";
    }
    else {
        strm << "    notebookGuid is not set\n";
    }

    if (tagGuids.isSet()) {
        strm << "    tagGuids = "
            << "QList<Guid> {";
        for(const auto & v: tagGuids.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    tagGuids is not set\n";
    }

    if (timeZone.isSet()) {
        strm << "    timeZone = "
            << timeZone.ref() << "\n";
    }
    else {
        strm << "    timeZone is not set\n";
    }

    if (inactive.isSet()) {
        strm << "    inactive = "
            << inactive.ref() << "\n";
    }
    else {
        strm << "    inactive is not set\n";
    }

    if (emphasized.isSet()) {
        strm << "    emphasized = "
            << emphasized.ref() << "\n";
    }
    else {
        strm << "    emphasized is not set\n";
    }

    if (includeAllReadableNotebooks.isSet()) {
        strm << "    includeAllReadableNotebooks = "
            << includeAllReadableNotebooks.ref() << "\n";
    }
    else {
        strm << "    includeAllReadableNotebooks is not set\n";
    }

    if (includeAllReadableWorkspaces.isSet()) {
        strm << "    includeAllReadableWorkspaces = "
            << includeAllReadableWorkspaces.ref() << "\n";
    }
    else {
        strm << "    includeAllReadableWorkspaces is not set\n";
    }

    if (context.isSet()) {
        strm << "    context = "
            << context.ref() << "\n";
    }
    else {
        strm << "    context is not set\n";
    }

    if (rawWords.isSet()) {
        strm << "    rawWords = "
            << rawWords.ref() << "\n";
    }
    else {
        strm << "    rawWords is not set\n";
    }

    if (searchContextBytes.isSet()) {
        strm << "    searchContextBytes = "
            << searchContextBytes.ref() << "\n";
    }
    else {
        strm << "    searchContextBytes is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteList(
    ThriftBinaryBufferWriter & writer,
    const NoteList & s)
{
    writer.writeStructBegin(QStringLiteral("NoteList"));
    writer.writeFieldBegin(
        QStringLiteral("startIndex"),
        ThriftFieldType::T_I32,
        1);

    writer.writeI32(s.startIndex);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("totalNotes"),
        ThriftFieldType::T_I32,
        2);

    writer.writeI32(s.totalNotes);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("notes"),
        ThriftFieldType::T_LIST,
        3);

    writer.writeListBegin(ThriftFieldType::T_STRUCT, s.notes.length());
    for(const auto & value: qAsConst(s.notes)) {
        writeNote(writer, value);
    }
    writer.writeListEnd();

    writer.writeFieldEnd();

    if (s.stoppedWords.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("stoppedWords"),
            ThriftFieldType::T_LIST,
            4);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.stoppedWords.ref().length());
        for(const auto & value: qAsConst(s.stoppedWords.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.searchedWords.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("searchedWords"),
            ThriftFieldType::T_LIST,
            5);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.searchedWords.ref().length());
        for(const auto & value: qAsConst(s.searchedWords.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.updateCount.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updateCount"),
            ThriftFieldType::T_I32,
            6);

        writer.writeI32(s.updateCount.ref());
        writer.writeFieldEnd();
    }

    if (s.searchContextBytes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("searchContextBytes"),
            ThriftFieldType::T_STRING,
            7);

        writer.writeBinary(s.searchContextBytes.ref());
        writer.writeFieldEnd();
    }

    if (s.debugInfo.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("debugInfo"),
            ThriftFieldType::T_STRING,
            8);

        writer.writeString(s.debugInfo.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteList(
    ThriftBinaryBufferReader & reader,
    NoteList & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool startIndex_isset = false;
    bool totalNotes_isset = false;
    bool notes_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                startIndex_isset = true;
                qint32 v;
                reader.readI32(v);
                s.startIndex = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                totalNotes_isset = true;
                qint32 v;
                reader.readI32(v);
                s.totalNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                notes_isset = true;
                QList<Note> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteList.notes)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Note elem;
                    readNote(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.notes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteList.stoppedWords)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.stoppedWords = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteList.searchedWords)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.searchedWords = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.updateCount = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                s.searchContextBytes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.debugInfo = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!startIndex_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteList.startIndex has no value"));
    if (!totalNotes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteList.totalNotes has no value"));
    if (!notes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteList.notes has no value"));
}

void NoteList::print(QTextStream & strm) const
{
    strm << "NoteList: {\n";
    localData.print(strm);
    strm << "    startIndex = "
        << startIndex << "\n";
    strm << "    totalNotes = "
        << totalNotes << "\n";
    strm << "    notes = "
        << "QList<Note> {";
    for(const auto & v: notes) {
        strm << "    " << v << "\n";
    }
    strm << "}\n";

    if (stoppedWords.isSet()) {
        strm << "    stoppedWords = "
            << "QList<QString> {";
        for(const auto & v: stoppedWords.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    stoppedWords is not set\n";
    }

    if (searchedWords.isSet()) {
        strm << "    searchedWords = "
            << "QList<QString> {";
        for(const auto & v: searchedWords.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    searchedWords is not set\n";
    }

    if (updateCount.isSet()) {
        strm << "    updateCount = "
            << updateCount.ref() << "\n";
    }
    else {
        strm << "    updateCount is not set\n";
    }

    if (searchContextBytes.isSet()) {
        strm << "    searchContextBytes = "
            << searchContextBytes.ref() << "\n";
    }
    else {
        strm << "    searchContextBytes is not set\n";
    }

    if (debugInfo.isSet()) {
        strm << "    debugInfo = "
            << debugInfo.ref() << "\n";
    }
    else {
        strm << "    debugInfo is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteMetadata(
    ThriftBinaryBufferWriter & writer,
    const NoteMetadata & s)
{
    writer.writeStructBegin(QStringLiteral("NoteMetadata"));
    writer.writeFieldBegin(
        QStringLiteral("guid"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(s.guid);
    writer.writeFieldEnd();

    if (s.title.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("title"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.title.ref());
        writer.writeFieldEnd();
    }

    if (s.contentLength.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("contentLength"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(s.contentLength.ref());
        writer.writeFieldEnd();
    }

    if (s.created.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("created"),
            ThriftFieldType::T_I64,
            6);

        writer.writeI64(s.created.ref());
        writer.writeFieldEnd();
    }

    if (s.updated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(s.updated.ref());
        writer.writeFieldEnd();
    }

    if (s.deleted.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("deleted"),
            ThriftFieldType::T_I64,
            8);

        writer.writeI64(s.deleted.ref());
        writer.writeFieldEnd();
    }

    if (s.updateSequenceNum.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            10);

        writer.writeI32(s.updateSequenceNum.ref());
        writer.writeFieldEnd();
    }

    if (s.notebookGuid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            11);

        writer.writeString(s.notebookGuid.ref());
        writer.writeFieldEnd();
    }

    if (s.tagGuids.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("tagGuids"),
            ThriftFieldType::T_LIST,
            12);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.tagGuids.ref().length());
        for(const auto & value: qAsConst(s.tagGuids.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.attributes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            14);

        writeNoteAttributes(writer, s.attributes.ref());
        writer.writeFieldEnd();
    }

    if (s.largestResourceMime.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("largestResourceMime"),
            ThriftFieldType::T_STRING,
            20);

        writer.writeString(s.largestResourceMime.ref());
        writer.writeFieldEnd();
    }

    if (s.largestResourceSize.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("largestResourceSize"),
            ThriftFieldType::T_I32,
            21);

        writer.writeI32(s.largestResourceSize.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteMetadata(
    ThriftBinaryBufferReader & reader,
    NoteMetadata & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool guid_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                guid_isset = true;
                Guid v;
                reader.readString(v);
                s.guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.title = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.contentLength = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.created = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.updated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.deleted = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.updateSequenceNum = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.notebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteMetadata.tagGuids)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.tagGuids = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteAttributes v;
                readNoteAttributes(reader, v);
                s.attributes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.largestResourceMime = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.largestResourceSize = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!guid_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteMetadata.guid has no value"));
}

void NoteMetadata::print(QTextStream & strm) const
{
    strm << "NoteMetadata: {\n";
    localData.print(strm);
    strm << "    guid = "
        << guid << "\n";

    if (title.isSet()) {
        strm << "    title = "
            << title.ref() << "\n";
    }
    else {
        strm << "    title is not set\n";
    }

    if (contentLength.isSet()) {
        strm << "    contentLength = "
            << contentLength.ref() << "\n";
    }
    else {
        strm << "    contentLength is not set\n";
    }

    if (created.isSet()) {
        strm << "    created = "
            << created.ref() << "\n";
    }
    else {
        strm << "    created is not set\n";
    }

    if (updated.isSet()) {
        strm << "    updated = "
            << updated.ref() << "\n";
    }
    else {
        strm << "    updated is not set\n";
    }

    if (deleted.isSet()) {
        strm << "    deleted = "
            << deleted.ref() << "\n";
    }
    else {
        strm << "    deleted is not set\n";
    }

    if (updateSequenceNum.isSet()) {
        strm << "    updateSequenceNum = "
            << updateSequenceNum.ref() << "\n";
    }
    else {
        strm << "    updateSequenceNum is not set\n";
    }

    if (notebookGuid.isSet()) {
        strm << "    notebookGuid = "
            << notebookGuid.ref() << "\n";
    }
    else {
        strm << "    notebookGuid is not set\n";
    }

    if (tagGuids.isSet()) {
        strm << "    tagGuids = "
            << "QList<Guid> {";
        for(const auto & v: tagGuids.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    tagGuids is not set\n";
    }

    if (attributes.isSet()) {
        strm << "    attributes = "
            << attributes.ref() << "\n";
    }
    else {
        strm << "    attributes is not set\n";
    }

    if (largestResourceMime.isSet()) {
        strm << "    largestResourceMime = "
            << largestResourceMime.ref() << "\n";
    }
    else {
        strm << "    largestResourceMime is not set\n";
    }

    if (largestResourceSize.isSet()) {
        strm << "    largestResourceSize = "
            << largestResourceSize.ref() << "\n";
    }
    else {
        strm << "    largestResourceSize is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNotesMetadataList(
    ThriftBinaryBufferWriter & writer,
    const NotesMetadataList & s)
{
    writer.writeStructBegin(QStringLiteral("NotesMetadataList"));
    writer.writeFieldBegin(
        QStringLiteral("startIndex"),
        ThriftFieldType::T_I32,
        1);

    writer.writeI32(s.startIndex);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("totalNotes"),
        ThriftFieldType::T_I32,
        2);

    writer.writeI32(s.totalNotes);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("notes"),
        ThriftFieldType::T_LIST,
        3);

    writer.writeListBegin(ThriftFieldType::T_STRUCT, s.notes.length());
    for(const auto & value: qAsConst(s.notes)) {
        writeNoteMetadata(writer, value);
    }
    writer.writeListEnd();

    writer.writeFieldEnd();

    if (s.stoppedWords.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("stoppedWords"),
            ThriftFieldType::T_LIST,
            4);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.stoppedWords.ref().length());
        for(const auto & value: qAsConst(s.stoppedWords.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.searchedWords.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("searchedWords"),
            ThriftFieldType::T_LIST,
            5);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.searchedWords.ref().length());
        for(const auto & value: qAsConst(s.searchedWords.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.updateCount.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updateCount"),
            ThriftFieldType::T_I32,
            6);

        writer.writeI32(s.updateCount.ref());
        writer.writeFieldEnd();
    }

    if (s.searchContextBytes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("searchContextBytes"),
            ThriftFieldType::T_STRING,
            7);

        writer.writeBinary(s.searchContextBytes.ref());
        writer.writeFieldEnd();
    }

    if (s.debugInfo.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("debugInfo"),
            ThriftFieldType::T_STRING,
            9);

        writer.writeString(s.debugInfo.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNotesMetadataList(
    ThriftBinaryBufferReader & reader,
    NotesMetadataList & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool startIndex_isset = false;
    bool totalNotes_isset = false;
    bool notes_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                startIndex_isset = true;
                qint32 v;
                reader.readI32(v);
                s.startIndex = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                totalNotes_isset = true;
                qint32 v;
                reader.readI32(v);
                s.totalNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                notes_isset = true;
                QList<NoteMetadata> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NotesMetadataList.notes)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    NoteMetadata elem;
                    readNoteMetadata(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.notes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NotesMetadataList.stoppedWords)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.stoppedWords = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NotesMetadataList.searchedWords)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.searchedWords = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.updateCount = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                s.searchContextBytes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.debugInfo = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!startIndex_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NotesMetadataList.startIndex has no value"));
    if (!totalNotes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NotesMetadataList.totalNotes has no value"));
    if (!notes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NotesMetadataList.notes has no value"));
}

void NotesMetadataList::print(QTextStream & strm) const
{
    strm << "NotesMetadataList: {\n";
    localData.print(strm);
    strm << "    startIndex = "
        << startIndex << "\n";
    strm << "    totalNotes = "
        << totalNotes << "\n";
    strm << "    notes = "
        << "QList<NoteMetadata> {";
    for(const auto & v: notes) {
        strm << "    " << v << "\n";
    }
    strm << "}\n";

    if (stoppedWords.isSet()) {
        strm << "    stoppedWords = "
            << "QList<QString> {";
        for(const auto & v: stoppedWords.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    stoppedWords is not set\n";
    }

    if (searchedWords.isSet()) {
        strm << "    searchedWords = "
            << "QList<QString> {";
        for(const auto & v: searchedWords.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    searchedWords is not set\n";
    }

    if (updateCount.isSet()) {
        strm << "    updateCount = "
            << updateCount.ref() << "\n";
    }
    else {
        strm << "    updateCount is not set\n";
    }

    if (searchContextBytes.isSet()) {
        strm << "    searchContextBytes = "
            << searchContextBytes.ref() << "\n";
    }
    else {
        strm << "    searchContextBytes is not set\n";
    }

    if (debugInfo.isSet()) {
        strm << "    debugInfo = "
            << debugInfo.ref() << "\n";
    }
    else {
        strm << "    debugInfo is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNotesMetadataResultSpec(
    ThriftBinaryBufferWriter & writer,
    const NotesMetadataResultSpec & s)
{
    writer.writeStructBegin(QStringLiteral("NotesMetadataResultSpec"));
    if (s.includeTitle.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeTitle"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(s.includeTitle.ref());
        writer.writeFieldEnd();
    }

    if (s.includeContentLength.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeContentLength"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(s.includeContentLength.ref());
        writer.writeFieldEnd();
    }

    if (s.includeCreated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeCreated"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(s.includeCreated.ref());
        writer.writeFieldEnd();
    }

    if (s.includeUpdated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeUpdated"),
            ThriftFieldType::T_BOOL,
            7);

        writer.writeBool(s.includeUpdated.ref());
        writer.writeFieldEnd();
    }

    if (s.includeDeleted.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeDeleted"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(s.includeDeleted.ref());
        writer.writeFieldEnd();
    }

    if (s.includeUpdateSequenceNum.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeUpdateSequenceNum"),
            ThriftFieldType::T_BOOL,
            10);

        writer.writeBool(s.includeUpdateSequenceNum.ref());
        writer.writeFieldEnd();
    }

    if (s.includeNotebookGuid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNotebookGuid"),
            ThriftFieldType::T_BOOL,
            11);

        writer.writeBool(s.includeNotebookGuid.ref());
        writer.writeFieldEnd();
    }

    if (s.includeTagGuids.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeTagGuids"),
            ThriftFieldType::T_BOOL,
            12);

        writer.writeBool(s.includeTagGuids.ref());
        writer.writeFieldEnd();
    }

    if (s.includeAttributes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeAttributes"),
            ThriftFieldType::T_BOOL,
            14);

        writer.writeBool(s.includeAttributes.ref());
        writer.writeFieldEnd();
    }

    if (s.includeLargestResourceMime.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeLargestResourceMime"),
            ThriftFieldType::T_BOOL,
            20);

        writer.writeBool(s.includeLargestResourceMime.ref());
        writer.writeFieldEnd();
    }

    if (s.includeLargestResourceSize.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeLargestResourceSize"),
            ThriftFieldType::T_BOOL,
            21);

        writer.writeBool(s.includeLargestResourceSize.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNotesMetadataResultSpec(
    ThriftBinaryBufferReader & reader,
    NotesMetadataResultSpec & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeTitle = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeContentLength = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeCreated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeUpdated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeDeleted = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeUpdateSequenceNum = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeNotebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeTagGuids = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeAttributes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeLargestResourceMime = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeLargestResourceSize = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NotesMetadataResultSpec::print(QTextStream & strm) const
{
    strm << "NotesMetadataResultSpec: {\n";
    localData.print(strm);

    if (includeTitle.isSet()) {
        strm << "    includeTitle = "
            << includeTitle.ref() << "\n";
    }
    else {
        strm << "    includeTitle is not set\n";
    }

    if (includeContentLength.isSet()) {
        strm << "    includeContentLength = "
            << includeContentLength.ref() << "\n";
    }
    else {
        strm << "    includeContentLength is not set\n";
    }

    if (includeCreated.isSet()) {
        strm << "    includeCreated = "
            << includeCreated.ref() << "\n";
    }
    else {
        strm << "    includeCreated is not set\n";
    }

    if (includeUpdated.isSet()) {
        strm << "    includeUpdated = "
            << includeUpdated.ref() << "\n";
    }
    else {
        strm << "    includeUpdated is not set\n";
    }

    if (includeDeleted.isSet()) {
        strm << "    includeDeleted = "
            << includeDeleted.ref() << "\n";
    }
    else {
        strm << "    includeDeleted is not set\n";
    }

    if (includeUpdateSequenceNum.isSet()) {
        strm << "    includeUpdateSequenceNum = "
            << includeUpdateSequenceNum.ref() << "\n";
    }
    else {
        strm << "    includeUpdateSequenceNum is not set\n";
    }

    if (includeNotebookGuid.isSet()) {
        strm << "    includeNotebookGuid = "
            << includeNotebookGuid.ref() << "\n";
    }
    else {
        strm << "    includeNotebookGuid is not set\n";
    }

    if (includeTagGuids.isSet()) {
        strm << "    includeTagGuids = "
            << includeTagGuids.ref() << "\n";
    }
    else {
        strm << "    includeTagGuids is not set\n";
    }

    if (includeAttributes.isSet()) {
        strm << "    includeAttributes = "
            << includeAttributes.ref() << "\n";
    }
    else {
        strm << "    includeAttributes is not set\n";
    }

    if (includeLargestResourceMime.isSet()) {
        strm << "    includeLargestResourceMime = "
            << includeLargestResourceMime.ref() << "\n";
    }
    else {
        strm << "    includeLargestResourceMime is not set\n";
    }

    if (includeLargestResourceSize.isSet()) {
        strm << "    includeLargestResourceSize = "
            << includeLargestResourceSize.ref() << "\n";
    }
    else {
        strm << "    includeLargestResourceSize is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteCollectionCounts(
    ThriftBinaryBufferWriter & writer,
    const NoteCollectionCounts & s)
{
    writer.writeStructBegin(QStringLiteral("NoteCollectionCounts"));
    if (s.notebookCounts.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookCounts"),
            ThriftFieldType::T_MAP,
            1);

        writer.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_I32, s.notebookCounts.ref().size());
        for(const auto & it: toRange(s.notebookCounts.ref())) {
            writer.writeString(it.key());
            writer.writeI32(it.value());
        }
        writer.writeMapEnd();

        writer.writeFieldEnd();
    }

    if (s.tagCounts.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("tagCounts"),
            ThriftFieldType::T_MAP,
            2);

        writer.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_I32, s.tagCounts.ref().size());
        for(const auto & it: toRange(s.tagCounts.ref())) {
            writer.writeString(it.key());
            writer.writeI32(it.value());
        }
        writer.writeMapEnd();

        writer.writeFieldEnd();
    }

    if (s.trashCount.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("trashCount"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(s.trashCount.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteCollectionCounts(
    ThriftBinaryBufferReader & reader,
    NoteCollectionCounts & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap<Guid, qint32> v;
                qint32 size;
                ThriftFieldType keyType;
                ThriftFieldType elemType;
                reader.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (NoteCollectionCounts.notebookCounts)"));
                if (elemType != ThriftFieldType::T_I32) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (NoteCollectionCounts.notebookCounts)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid key;
                    reader.readString(key);
                    qint32 value;
                    reader.readI32(value);
                    v[key] = value;
                }
                reader.readMapEnd();
                s.notebookCounts = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap<Guid, qint32> v;
                qint32 size;
                ThriftFieldType keyType;
                ThriftFieldType elemType;
                reader.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (NoteCollectionCounts.tagCounts)"));
                if (elemType != ThriftFieldType::T_I32) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (NoteCollectionCounts.tagCounts)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid key;
                    reader.readString(key);
                    qint32 value;
                    reader.readI32(value);
                    v[key] = value;
                }
                reader.readMapEnd();
                s.tagCounts = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.trashCount = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NoteCollectionCounts::print(QTextStream & strm) const
{
    strm << "NoteCollectionCounts: {\n";
    localData.print(strm);

    if (notebookCounts.isSet()) {
        strm << "    notebookCounts = "
            << "QMap<Guid, qint32> {";
        for(const auto & it: toRange(notebookCounts.ref())) {
            strm << "        [" << it.key() << "] = " << it.value() << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    notebookCounts is not set\n";
    }

    if (tagCounts.isSet()) {
        strm << "    tagCounts = "
            << "QMap<Guid, qint32> {";
        for(const auto & it: toRange(tagCounts.ref())) {
            strm << "        [" << it.key() << "] = " << it.value() << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    tagCounts is not set\n";
    }

    if (trashCount.isSet()) {
        strm << "    trashCount = "
            << trashCount.ref() << "\n";
    }
    else {
        strm << "    trashCount is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteResultSpec(
    ThriftBinaryBufferWriter & writer,
    const NoteResultSpec & s)
{
    writer.writeStructBegin(QStringLiteral("NoteResultSpec"));
    if (s.includeContent.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeContent"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(s.includeContent.ref());
        writer.writeFieldEnd();
    }

    if (s.includeResourcesData.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeResourcesData"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(s.includeResourcesData.ref());
        writer.writeFieldEnd();
    }

    if (s.includeResourcesRecognition.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeResourcesRecognition"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(s.includeResourcesRecognition.ref());
        writer.writeFieldEnd();
    }

    if (s.includeResourcesAlternateData.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeResourcesAlternateData"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(s.includeResourcesAlternateData.ref());
        writer.writeFieldEnd();
    }

    if (s.includeSharedNotes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeSharedNotes"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(s.includeSharedNotes.ref());
        writer.writeFieldEnd();
    }

    if (s.includeNoteAppDataValues.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeNoteAppDataValues"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(s.includeNoteAppDataValues.ref());
        writer.writeFieldEnd();
    }

    if (s.includeResourceAppDataValues.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeResourceAppDataValues"),
            ThriftFieldType::T_BOOL,
            7);

        writer.writeBool(s.includeResourceAppDataValues.ref());
        writer.writeFieldEnd();
    }

    if (s.includeAccountLimits.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeAccountLimits"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(s.includeAccountLimits.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteResultSpec(
    ThriftBinaryBufferReader & reader,
    NoteResultSpec & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeContent = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeResourcesData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeResourcesRecognition = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeResourcesAlternateData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeSharedNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeNoteAppDataValues = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeResourceAppDataValues = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeAccountLimits = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NoteResultSpec::print(QTextStream & strm) const
{
    strm << "NoteResultSpec: {\n";
    localData.print(strm);

    if (includeContent.isSet()) {
        strm << "    includeContent = "
            << includeContent.ref() << "\n";
    }
    else {
        strm << "    includeContent is not set\n";
    }

    if (includeResourcesData.isSet()) {
        strm << "    includeResourcesData = "
            << includeResourcesData.ref() << "\n";
    }
    else {
        strm << "    includeResourcesData is not set\n";
    }

    if (includeResourcesRecognition.isSet()) {
        strm << "    includeResourcesRecognition = "
            << includeResourcesRecognition.ref() << "\n";
    }
    else {
        strm << "    includeResourcesRecognition is not set\n";
    }

    if (includeResourcesAlternateData.isSet()) {
        strm << "    includeResourcesAlternateData = "
            << includeResourcesAlternateData.ref() << "\n";
    }
    else {
        strm << "    includeResourcesAlternateData is not set\n";
    }

    if (includeSharedNotes.isSet()) {
        strm << "    includeSharedNotes = "
            << includeSharedNotes.ref() << "\n";
    }
    else {
        strm << "    includeSharedNotes is not set\n";
    }

    if (includeNoteAppDataValues.isSet()) {
        strm << "    includeNoteAppDataValues = "
            << includeNoteAppDataValues.ref() << "\n";
    }
    else {
        strm << "    includeNoteAppDataValues is not set\n";
    }

    if (includeResourceAppDataValues.isSet()) {
        strm << "    includeResourceAppDataValues = "
            << includeResourceAppDataValues.ref() << "\n";
    }
    else {
        strm << "    includeResourceAppDataValues is not set\n";
    }

    if (includeAccountLimits.isSet()) {
        strm << "    includeAccountLimits = "
            << includeAccountLimits.ref() << "\n";
    }
    else {
        strm << "    includeAccountLimits is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteEmailParameters(
    ThriftBinaryBufferWriter & writer,
    const NoteEmailParameters & s)
{
    writer.writeStructBegin(QStringLiteral("NoteEmailParameters"));
    if (s.guid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.guid.ref());
        writer.writeFieldEnd();
    }

    if (s.note.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("note"),
            ThriftFieldType::T_STRUCT,
            2);

        writeNote(writer, s.note.ref());
        writer.writeFieldEnd();
    }

    if (s.toAddresses.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("toAddresses"),
            ThriftFieldType::T_LIST,
            3);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.toAddresses.ref().length());
        for(const auto & value: qAsConst(s.toAddresses.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.ccAddresses.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("ccAddresses"),
            ThriftFieldType::T_LIST,
            4);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.ccAddresses.ref().length());
        for(const auto & value: qAsConst(s.ccAddresses.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.subject.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("subject"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(s.subject.ref());
        writer.writeFieldEnd();
    }

    if (s.message.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("message"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(s.message.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteEmailParameters(
    ThriftBinaryBufferReader & reader,
    NoteEmailParameters & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Note v;
                readNote(reader, v);
                s.note = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteEmailParameters.toAddresses)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.toAddresses = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteEmailParameters.ccAddresses)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.ccAddresses = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.subject = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.message = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NoteEmailParameters::print(QTextStream & strm) const
{
    strm << "NoteEmailParameters: {\n";
    localData.print(strm);

    if (guid.isSet()) {
        strm << "    guid = "
            << guid.ref() << "\n";
    }
    else {
        strm << "    guid is not set\n";
    }

    if (note.isSet()) {
        strm << "    note = "
            << note.ref() << "\n";
    }
    else {
        strm << "    note is not set\n";
    }

    if (toAddresses.isSet()) {
        strm << "    toAddresses = "
            << "QList<QString> {";
        for(const auto & v: toAddresses.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    toAddresses is not set\n";
    }

    if (ccAddresses.isSet()) {
        strm << "    ccAddresses = "
            << "QList<QString> {";
        for(const auto & v: ccAddresses.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    ccAddresses is not set\n";
    }

    if (subject.isSet()) {
        strm << "    subject = "
            << subject.ref() << "\n";
    }
    else {
        strm << "    subject is not set\n";
    }

    if (message.isSet()) {
        strm << "    message = "
            << message.ref() << "\n";
    }
    else {
        strm << "    message is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteVersionId(
    ThriftBinaryBufferWriter & writer,
    const NoteVersionId & s)
{
    writer.writeStructBegin(QStringLiteral("NoteVersionId"));
    writer.writeFieldBegin(
        QStringLiteral("updateSequenceNum"),
        ThriftFieldType::T_I32,
        1);

    writer.writeI32(s.updateSequenceNum);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("updated"),
        ThriftFieldType::T_I64,
        2);

    writer.writeI64(s.updated);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("saved"),
        ThriftFieldType::T_I64,
        3);

    writer.writeI64(s.saved);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("title"),
        ThriftFieldType::T_STRING,
        4);

    writer.writeString(s.title);
    writer.writeFieldEnd();

    if (s.lastEditorId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("lastEditorId"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(s.lastEditorId.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteVersionId(
    ThriftBinaryBufferReader & reader,
    NoteVersionId & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool updateSequenceNum_isset = false;
    bool updated_isset = false;
    bool saved_isset = false;
    bool title_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                updateSequenceNum_isset = true;
                qint32 v;
                reader.readI32(v);
                s.updateSequenceNum = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                updated_isset = true;
                qint64 v;
                reader.readI64(v);
                s.updated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                saved_isset = true;
                qint64 v;
                reader.readI64(v);
                s.saved = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                title_isset = true;
                QString v;
                reader.readString(v);
                s.title = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.lastEditorId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!updateSequenceNum_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.updateSequenceNum has no value"));
    if (!updated_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.updated has no value"));
    if (!saved_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.saved has no value"));
    if (!title_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.title has no value"));
}

void NoteVersionId::print(QTextStream & strm) const
{
    strm << "NoteVersionId: {\n";
    localData.print(strm);
    strm << "    updateSequenceNum = "
        << updateSequenceNum << "\n";
    strm << "    updated = "
        << updated << "\n";
    strm << "    saved = "
        << saved << "\n";
    strm << "    title = "
        << title << "\n";

    if (lastEditorId.isSet()) {
        strm << "    lastEditorId = "
            << lastEditorId.ref() << "\n";
    }
    else {
        strm << "    lastEditorId is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeRelatedQuery(
    ThriftBinaryBufferWriter & writer,
    const RelatedQuery & s)
{
    writer.writeStructBegin(QStringLiteral("RelatedQuery"));
    if (s.noteGuid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noteGuid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.noteGuid.ref());
        writer.writeFieldEnd();
    }

    if (s.plainText.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("plainText"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.plainText.ref());
        writer.writeFieldEnd();
    }

    if (s.filter.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("filter"),
            ThriftFieldType::T_STRUCT,
            3);

        writeNoteFilter(writer, s.filter.ref());
        writer.writeFieldEnd();
    }

    if (s.referenceUri.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("referenceUri"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.referenceUri.ref());
        writer.writeFieldEnd();
    }

    if (s.context.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("context"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(s.context.ref());
        writer.writeFieldEnd();
    }

    if (s.cacheKey.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("cacheKey"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(s.cacheKey.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readRelatedQuery(
    ThriftBinaryBufferReader & reader,
    RelatedQuery & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.noteGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.plainText = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteFilter v;
                readNoteFilter(reader, v);
                s.filter = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.referenceUri = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.context = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.cacheKey = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void RelatedQuery::print(QTextStream & strm) const
{
    strm << "RelatedQuery: {\n";
    localData.print(strm);

    if (noteGuid.isSet()) {
        strm << "    noteGuid = "
            << noteGuid.ref() << "\n";
    }
    else {
        strm << "    noteGuid is not set\n";
    }

    if (plainText.isSet()) {
        strm << "    plainText = "
            << plainText.ref() << "\n";
    }
    else {
        strm << "    plainText is not set\n";
    }

    if (filter.isSet()) {
        strm << "    filter = "
            << filter.ref() << "\n";
    }
    else {
        strm << "    filter is not set\n";
    }

    if (referenceUri.isSet()) {
        strm << "    referenceUri = "
            << referenceUri.ref() << "\n";
    }
    else {
        strm << "    referenceUri is not set\n";
    }

    if (context.isSet()) {
        strm << "    context = "
            << context.ref() << "\n";
    }
    else {
        strm << "    context is not set\n";
    }

    if (cacheKey.isSet()) {
        strm << "    cacheKey = "
            << cacheKey.ref() << "\n";
    }
    else {
        strm << "    cacheKey is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeRelatedResult(
    ThriftBinaryBufferWriter & writer,
    const RelatedResult & s)
{
    writer.writeStructBegin(QStringLiteral("RelatedResult"));
    if (s.notes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notes"),
            ThriftFieldType::T_LIST,
            1);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.notes.ref().length());
        for(const auto & value: qAsConst(s.notes.ref())) {
            writeNote(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.notebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notebooks"),
            ThriftFieldType::T_LIST,
            2);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.notebooks.ref().length());
        for(const auto & value: qAsConst(s.notebooks.ref())) {
            writeNotebook(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.tags.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("tags"),
            ThriftFieldType::T_LIST,
            3);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.tags.ref().length());
        for(const auto & value: qAsConst(s.tags.ref())) {
            writeTag(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.containingNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("containingNotebooks"),
            ThriftFieldType::T_LIST,
            4);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.containingNotebooks.ref().length());
        for(const auto & value: qAsConst(s.containingNotebooks.ref())) {
            writeNotebookDescriptor(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.debugInfo.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("debugInfo"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(s.debugInfo.ref());
        writer.writeFieldEnd();
    }

    if (s.experts.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("experts"),
            ThriftFieldType::T_LIST,
            6);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.experts.ref().length());
        for(const auto & value: qAsConst(s.experts.ref())) {
            writeUserProfile(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.relatedContent.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("relatedContent"),
            ThriftFieldType::T_LIST,
            7);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.relatedContent.ref().length());
        for(const auto & value: qAsConst(s.relatedContent.ref())) {
            writeRelatedContent(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.cacheKey.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("cacheKey"),
            ThriftFieldType::T_STRING,
            8);

        writer.writeString(s.cacheKey.ref());
        writer.writeFieldEnd();
    }

    if (s.cacheExpires.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("cacheExpires"),
            ThriftFieldType::T_I32,
            9);

        writer.writeI32(s.cacheExpires.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readRelatedResult(
    ThriftBinaryBufferReader & reader,
    RelatedResult & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Note> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedResult.notes)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Note elem;
                    readNote(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.notes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Notebook> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedResult.notebooks)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Notebook elem;
                    readNotebook(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.notebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Tag> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedResult.tags)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Tag elem;
                    readTag(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.tags = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NotebookDescriptor> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedResult.containingNotebooks)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    NotebookDescriptor elem;
                    readNotebookDescriptor(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.containingNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.debugInfo = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<UserProfile> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedResult.experts)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    UserProfile elem;
                    readUserProfile(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.experts = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<RelatedContent> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedResult.relatedContent)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    RelatedContent elem;
                    readRelatedContent(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.relatedContent = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.cacheKey = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.cacheExpires = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void RelatedResult::print(QTextStream & strm) const
{
    strm << "RelatedResult: {\n";
    localData.print(strm);

    if (notes.isSet()) {
        strm << "    notes = "
            << "QList<Note> {";
        for(const auto & v: notes.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    notes is not set\n";
    }

    if (notebooks.isSet()) {
        strm << "    notebooks = "
            << "QList<Notebook> {";
        for(const auto & v: notebooks.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    notebooks is not set\n";
    }

    if (tags.isSet()) {
        strm << "    tags = "
            << "QList<Tag> {";
        for(const auto & v: tags.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    tags is not set\n";
    }

    if (containingNotebooks.isSet()) {
        strm << "    containingNotebooks = "
            << "QList<NotebookDescriptor> {";
        for(const auto & v: containingNotebooks.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    containingNotebooks is not set\n";
    }

    if (debugInfo.isSet()) {
        strm << "    debugInfo = "
            << debugInfo.ref() << "\n";
    }
    else {
        strm << "    debugInfo is not set\n";
    }

    if (experts.isSet()) {
        strm << "    experts = "
            << "QList<UserProfile> {";
        for(const auto & v: experts.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    experts is not set\n";
    }

    if (relatedContent.isSet()) {
        strm << "    relatedContent = "
            << "QList<RelatedContent> {";
        for(const auto & v: relatedContent.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    relatedContent is not set\n";
    }

    if (cacheKey.isSet()) {
        strm << "    cacheKey = "
            << cacheKey.ref() << "\n";
    }
    else {
        strm << "    cacheKey is not set\n";
    }

    if (cacheExpires.isSet()) {
        strm << "    cacheExpires = "
            << cacheExpires.ref() << "\n";
    }
    else {
        strm << "    cacheExpires is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeRelatedResultSpec(
    ThriftBinaryBufferWriter & writer,
    const RelatedResultSpec & s)
{
    writer.writeStructBegin(QStringLiteral("RelatedResultSpec"));
    if (s.maxNotes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("maxNotes"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(s.maxNotes.ref());
        writer.writeFieldEnd();
    }

    if (s.maxNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("maxNotebooks"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(s.maxNotebooks.ref());
        writer.writeFieldEnd();
    }

    if (s.maxTags.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("maxTags"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(s.maxTags.ref());
        writer.writeFieldEnd();
    }

    if (s.writableNotebooksOnly.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("writableNotebooksOnly"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(s.writableNotebooksOnly.ref());
        writer.writeFieldEnd();
    }

    if (s.includeContainingNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeContainingNotebooks"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(s.includeContainingNotebooks.ref());
        writer.writeFieldEnd();
    }

    if (s.includeDebugInfo.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeDebugInfo"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(s.includeDebugInfo.ref());
        writer.writeFieldEnd();
    }

    if (s.maxExperts.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("maxExperts"),
            ThriftFieldType::T_I32,
            7);

        writer.writeI32(s.maxExperts.ref());
        writer.writeFieldEnd();
    }

    if (s.maxRelatedContent.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("maxRelatedContent"),
            ThriftFieldType::T_I32,
            8);

        writer.writeI32(s.maxRelatedContent.ref());
        writer.writeFieldEnd();
    }

    if (s.relatedContentTypes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("relatedContentTypes"),
            ThriftFieldType::T_SET,
            9);

        writer.writeSetBegin(ThriftFieldType::T_I32, s.relatedContentTypes.ref().count());
        for(const auto & value: qAsConst(s.relatedContentTypes.ref())) {
            writer.writeI32(static_cast<qint32>(value));
        }
        writer.writeSetEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readRelatedResultSpec(
    ThriftBinaryBufferReader & reader,
    RelatedResultSpec & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.maxNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.maxNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.maxTags = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.writableNotebooksOnly = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeContainingNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeDebugInfo = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.maxExperts = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.maxRelatedContent = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_SET) {
                QSet<RelatedContentType> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readSetBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_I32) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect set type (RelatedResultSpec.relatedContentTypes)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    RelatedContentType elem;
                    readEnumRelatedContentType(reader, elem);
                    v.insert(elem);
                }
                reader.readSetEnd();
                s.relatedContentTypes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void RelatedResultSpec::print(QTextStream & strm) const
{
    strm << "RelatedResultSpec: {\n";
    localData.print(strm);

    if (maxNotes.isSet()) {
        strm << "    maxNotes = "
            << maxNotes.ref() << "\n";
    }
    else {
        strm << "    maxNotes is not set\n";
    }

    if (maxNotebooks.isSet()) {
        strm << "    maxNotebooks = "
            << maxNotebooks.ref() << "\n";
    }
    else {
        strm << "    maxNotebooks is not set\n";
    }

    if (maxTags.isSet()) {
        strm << "    maxTags = "
            << maxTags.ref() << "\n";
    }
    else {
        strm << "    maxTags is not set\n";
    }

    if (writableNotebooksOnly.isSet()) {
        strm << "    writableNotebooksOnly = "
            << writableNotebooksOnly.ref() << "\n";
    }
    else {
        strm << "    writableNotebooksOnly is not set\n";
    }

    if (includeContainingNotebooks.isSet()) {
        strm << "    includeContainingNotebooks = "
            << includeContainingNotebooks.ref() << "\n";
    }
    else {
        strm << "    includeContainingNotebooks is not set\n";
    }

    if (includeDebugInfo.isSet()) {
        strm << "    includeDebugInfo = "
            << includeDebugInfo.ref() << "\n";
    }
    else {
        strm << "    includeDebugInfo is not set\n";
    }

    if (maxExperts.isSet()) {
        strm << "    maxExperts = "
            << maxExperts.ref() << "\n";
    }
    else {
        strm << "    maxExperts is not set\n";
    }

    if (maxRelatedContent.isSet()) {
        strm << "    maxRelatedContent = "
            << maxRelatedContent.ref() << "\n";
    }
    else {
        strm << "    maxRelatedContent is not set\n";
    }

    if (relatedContentTypes.isSet()) {
        strm << "    relatedContentTypes = "
            << "QSet<RelatedContentType> {";
        for(const auto & v: relatedContentTypes.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    relatedContentTypes is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeUpdateNoteIfUsnMatchesResult(
    ThriftBinaryBufferWriter & writer,
    const UpdateNoteIfUsnMatchesResult & s)
{
    writer.writeStructBegin(QStringLiteral("UpdateNoteIfUsnMatchesResult"));
    if (s.note.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("note"),
            ThriftFieldType::T_STRUCT,
            1);

        writeNote(writer, s.note.ref());
        writer.writeFieldEnd();
    }

    if (s.updated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(s.updated.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readUpdateNoteIfUsnMatchesResult(
    ThriftBinaryBufferReader & reader,
    UpdateNoteIfUsnMatchesResult & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Note v;
                readNote(reader, v);
                s.note = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.updated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void UpdateNoteIfUsnMatchesResult::print(QTextStream & strm) const
{
    strm << "UpdateNoteIfUsnMatchesResult: {\n";
    localData.print(strm);

    if (note.isSet()) {
        strm << "    note = "
            << note.ref() << "\n";
    }
    else {
        strm << "    note is not set\n";
    }

    if (updated.isSet()) {
        strm << "    updated = "
            << updated.ref() << "\n";
    }
    else {
        strm << "    updated is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeShareRelationshipRestrictions(
    ThriftBinaryBufferWriter & writer,
    const ShareRelationshipRestrictions & s)
{
    writer.writeStructBegin(QStringLiteral("ShareRelationshipRestrictions"));
    if (s.noSetReadOnly.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetReadOnly"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(s.noSetReadOnly.ref());
        writer.writeFieldEnd();
    }

    if (s.noSetReadPlusActivity.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetReadPlusActivity"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(s.noSetReadPlusActivity.ref());
        writer.writeFieldEnd();
    }

    if (s.noSetModify.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetModify"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(s.noSetModify.ref());
        writer.writeFieldEnd();
    }

    if (s.noSetFullAccess.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetFullAccess"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(s.noSetFullAccess.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readShareRelationshipRestrictions(
    ThriftBinaryBufferReader & reader,
    ShareRelationshipRestrictions & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSetReadOnly = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSetReadPlusActivity = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSetModify = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSetFullAccess = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void ShareRelationshipRestrictions::print(QTextStream & strm) const
{
    strm << "ShareRelationshipRestrictions: {\n";
    localData.print(strm);

    if (noSetReadOnly.isSet()) {
        strm << "    noSetReadOnly = "
            << noSetReadOnly.ref() << "\n";
    }
    else {
        strm << "    noSetReadOnly is not set\n";
    }

    if (noSetReadPlusActivity.isSet()) {
        strm << "    noSetReadPlusActivity = "
            << noSetReadPlusActivity.ref() << "\n";
    }
    else {
        strm << "    noSetReadPlusActivity is not set\n";
    }

    if (noSetModify.isSet()) {
        strm << "    noSetModify = "
            << noSetModify.ref() << "\n";
    }
    else {
        strm << "    noSetModify is not set\n";
    }

    if (noSetFullAccess.isSet()) {
        strm << "    noSetFullAccess = "
            << noSetFullAccess.ref() << "\n";
    }
    else {
        strm << "    noSetFullAccess is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeInvitationShareRelationship(
    ThriftBinaryBufferWriter & writer,
    const InvitationShareRelationship & s)
{
    writer.writeStructBegin(QStringLiteral("InvitationShareRelationship"));
    if (s.displayName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("displayName"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.displayName.ref());
        writer.writeFieldEnd();
    }

    if (s.recipientUserIdentity.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientUserIdentity"),
            ThriftFieldType::T_STRUCT,
            2);

        writeUserIdentity(writer, s.recipientUserIdentity.ref());
        writer.writeFieldEnd();
    }

    if (s.privilege.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(s.privilege.ref()));
        writer.writeFieldEnd();
    }

    if (s.sharerUserId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(s.sharerUserId.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readInvitationShareRelationship(
    ThriftBinaryBufferReader & reader,
    InvitationShareRelationship & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.displayName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserIdentity v;
                readUserIdentity(reader, v);
                s.recipientUserIdentity = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                ShareRelationshipPrivilegeLevel v;
                readEnumShareRelationshipPrivilegeLevel(reader, v);
                s.privilege = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.sharerUserId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void InvitationShareRelationship::print(QTextStream & strm) const
{
    strm << "InvitationShareRelationship: {\n";
    localData.print(strm);

    if (displayName.isSet()) {
        strm << "    displayName = "
            << displayName.ref() << "\n";
    }
    else {
        strm << "    displayName is not set\n";
    }

    if (recipientUserIdentity.isSet()) {
        strm << "    recipientUserIdentity = "
            << recipientUserIdentity.ref() << "\n";
    }
    else {
        strm << "    recipientUserIdentity is not set\n";
    }

    if (privilege.isSet()) {
        strm << "    privilege = "
            << privilege.ref() << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    if (sharerUserId.isSet()) {
        strm << "    sharerUserId = "
            << sharerUserId.ref() << "\n";
    }
    else {
        strm << "    sharerUserId is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeMemberShareRelationship(
    ThriftBinaryBufferWriter & writer,
    const MemberShareRelationship & s)
{
    writer.writeStructBegin(QStringLiteral("MemberShareRelationship"));
    if (s.displayName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("displayName"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.displayName.ref());
        writer.writeFieldEnd();
    }

    if (s.recipientUserId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientUserId"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(s.recipientUserId.ref());
        writer.writeFieldEnd();
    }

    if (s.bestPrivilege.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("bestPrivilege"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(s.bestPrivilege.ref()));
        writer.writeFieldEnd();
    }

    if (s.individualPrivilege.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("individualPrivilege"),
            ThriftFieldType::T_I32,
            4);

        writer.writeI32(static_cast<qint32>(s.individualPrivilege.ref()));
        writer.writeFieldEnd();
    }

    if (s.restrictions.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("restrictions"),
            ThriftFieldType::T_STRUCT,
            5);

        writeShareRelationshipRestrictions(writer, s.restrictions.ref());
        writer.writeFieldEnd();
    }

    if (s.sharerUserId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            6);

        writer.writeI32(s.sharerUserId.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readMemberShareRelationship(
    ThriftBinaryBufferReader & reader,
    MemberShareRelationship & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.displayName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.recipientUserId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                ShareRelationshipPrivilegeLevel v;
                readEnumShareRelationshipPrivilegeLevel(reader, v);
                s.bestPrivilege = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                ShareRelationshipPrivilegeLevel v;
                readEnumShareRelationshipPrivilegeLevel(reader, v);
                s.individualPrivilege = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                ShareRelationshipRestrictions v;
                readShareRelationshipRestrictions(reader, v);
                s.restrictions = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.sharerUserId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void MemberShareRelationship::print(QTextStream & strm) const
{
    strm << "MemberShareRelationship: {\n";
    localData.print(strm);

    if (displayName.isSet()) {
        strm << "    displayName = "
            << displayName.ref() << "\n";
    }
    else {
        strm << "    displayName is not set\n";
    }

    if (recipientUserId.isSet()) {
        strm << "    recipientUserId = "
            << recipientUserId.ref() << "\n";
    }
    else {
        strm << "    recipientUserId is not set\n";
    }

    if (bestPrivilege.isSet()) {
        strm << "    bestPrivilege = "
            << bestPrivilege.ref() << "\n";
    }
    else {
        strm << "    bestPrivilege is not set\n";
    }

    if (individualPrivilege.isSet()) {
        strm << "    individualPrivilege = "
            << individualPrivilege.ref() << "\n";
    }
    else {
        strm << "    individualPrivilege is not set\n";
    }

    if (restrictions.isSet()) {
        strm << "    restrictions = "
            << restrictions.ref() << "\n";
    }
    else {
        strm << "    restrictions is not set\n";
    }

    if (sharerUserId.isSet()) {
        strm << "    sharerUserId = "
            << sharerUserId.ref() << "\n";
    }
    else {
        strm << "    sharerUserId is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeShareRelationships(
    ThriftBinaryBufferWriter & writer,
    const ShareRelationships & s)
{
    writer.writeStructBegin(QStringLiteral("ShareRelationships"));
    if (s.invitations.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("invitations"),
            ThriftFieldType::T_LIST,
            1);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.invitations.ref().length());
        for(const auto & value: qAsConst(s.invitations.ref())) {
            writeInvitationShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.memberships.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("memberships"),
            ThriftFieldType::T_LIST,
            2);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.memberships.ref().length());
        for(const auto & value: qAsConst(s.memberships.ref())) {
            writeMemberShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.invitationRestrictions.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("invitationRestrictions"),
            ThriftFieldType::T_STRUCT,
            3);

        writeShareRelationshipRestrictions(writer, s.invitationRestrictions.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readShareRelationships(
    ThriftBinaryBufferReader & reader,
    ShareRelationships & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<InvitationShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ShareRelationships.invitations)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    InvitationShareRelationship elem;
                    readInvitationShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.invitations = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<MemberShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ShareRelationships.memberships)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    MemberShareRelationship elem;
                    readMemberShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.memberships = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                ShareRelationshipRestrictions v;
                readShareRelationshipRestrictions(reader, v);
                s.invitationRestrictions = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void ShareRelationships::print(QTextStream & strm) const
{
    strm << "ShareRelationships: {\n";
    localData.print(strm);

    if (invitations.isSet()) {
        strm << "    invitations = "
            << "QList<InvitationShareRelationship> {";
        for(const auto & v: invitations.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    invitations is not set\n";
    }

    if (memberships.isSet()) {
        strm << "    memberships = "
            << "QList<MemberShareRelationship> {";
        for(const auto & v: memberships.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    memberships is not set\n";
    }

    if (invitationRestrictions.isSet()) {
        strm << "    invitationRestrictions = "
            << invitationRestrictions.ref() << "\n";
    }
    else {
        strm << "    invitationRestrictions is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeManageNotebookSharesParameters(
    ThriftBinaryBufferWriter & writer,
    const ManageNotebookSharesParameters & s)
{
    writer.writeStructBegin(QStringLiteral("ManageNotebookSharesParameters"));
    if (s.notebookGuid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.notebookGuid.ref());
        writer.writeFieldEnd();
    }

    if (s.inviteMessage.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("inviteMessage"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.inviteMessage.ref());
        writer.writeFieldEnd();
    }

    if (s.membershipsToUpdate.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("membershipsToUpdate"),
            ThriftFieldType::T_LIST,
            3);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.membershipsToUpdate.ref().length());
        for(const auto & value: qAsConst(s.membershipsToUpdate.ref())) {
            writeMemberShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.invitationsToCreateOrUpdate.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("invitationsToCreateOrUpdate"),
            ThriftFieldType::T_LIST,
            4);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.invitationsToCreateOrUpdate.ref().length());
        for(const auto & value: qAsConst(s.invitationsToCreateOrUpdate.ref())) {
            writeInvitationShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.unshares.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("unshares"),
            ThriftFieldType::T_LIST,
            5);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.unshares.ref().length());
        for(const auto & value: qAsConst(s.unshares.ref())) {
            writeUserIdentity(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readManageNotebookSharesParameters(
    ThriftBinaryBufferReader & reader,
    ManageNotebookSharesParameters & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.notebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.inviteMessage = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<MemberShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNotebookSharesParameters.membershipsToUpdate)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    MemberShareRelationship elem;
                    readMemberShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.membershipsToUpdate = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<InvitationShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNotebookSharesParameters.invitationsToCreateOrUpdate)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    InvitationShareRelationship elem;
                    readInvitationShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.invitationsToCreateOrUpdate = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<UserIdentity> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNotebookSharesParameters.unshares)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    UserIdentity elem;
                    readUserIdentity(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.unshares = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void ManageNotebookSharesParameters::print(QTextStream & strm) const
{
    strm << "ManageNotebookSharesParameters: {\n";
    localData.print(strm);

    if (notebookGuid.isSet()) {
        strm << "    notebookGuid = "
            << notebookGuid.ref() << "\n";
    }
    else {
        strm << "    notebookGuid is not set\n";
    }

    if (inviteMessage.isSet()) {
        strm << "    inviteMessage = "
            << inviteMessage.ref() << "\n";
    }
    else {
        strm << "    inviteMessage is not set\n";
    }

    if (membershipsToUpdate.isSet()) {
        strm << "    membershipsToUpdate = "
            << "QList<MemberShareRelationship> {";
        for(const auto & v: membershipsToUpdate.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    membershipsToUpdate is not set\n";
    }

    if (invitationsToCreateOrUpdate.isSet()) {
        strm << "    invitationsToCreateOrUpdate = "
            << "QList<InvitationShareRelationship> {";
        for(const auto & v: invitationsToCreateOrUpdate.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    invitationsToCreateOrUpdate is not set\n";
    }

    if (unshares.isSet()) {
        strm << "    unshares = "
            << "QList<UserIdentity> {";
        for(const auto & v: unshares.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    unshares is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeManageNotebookSharesError(
    ThriftBinaryBufferWriter & writer,
    const ManageNotebookSharesError & s)
{
    writer.writeStructBegin(QStringLiteral("ManageNotebookSharesError"));
    if (s.userIdentity.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userIdentity"),
            ThriftFieldType::T_STRUCT,
            1);

        writeUserIdentity(writer, s.userIdentity.ref());
        writer.writeFieldEnd();
    }

    if (s.userException.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMUserException(writer, s.userException.ref());
        writer.writeFieldEnd();
    }

    if (s.notFoundException.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notFoundException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMNotFoundException(writer, s.notFoundException.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readManageNotebookSharesError(
    ThriftBinaryBufferReader & reader,
    ManageNotebookSharesError & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserIdentity v;
                readUserIdentity(reader, v);
                s.userIdentity = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException v;
                readEDAMUserException(reader, v);
                s.userException = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException v;
                readEDAMNotFoundException(reader, v);
                s.notFoundException = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void ManageNotebookSharesError::print(QTextStream & strm) const
{
    strm << "ManageNotebookSharesError: {\n";
    localData.print(strm);

    if (userIdentity.isSet()) {
        strm << "    userIdentity = "
            << userIdentity.ref() << "\n";
    }
    else {
        strm << "    userIdentity is not set\n";
    }

    if (userException.isSet()) {
        strm << "    userException = "
            << userException.ref() << "\n";
    }
    else {
        strm << "    userException is not set\n";
    }

    if (notFoundException.isSet()) {
        strm << "    notFoundException = "
            << notFoundException.ref() << "\n";
    }
    else {
        strm << "    notFoundException is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeManageNotebookSharesResult(
    ThriftBinaryBufferWriter & writer,
    const ManageNotebookSharesResult & s)
{
    writer.writeStructBegin(QStringLiteral("ManageNotebookSharesResult"));
    if (s.errors.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("errors"),
            ThriftFieldType::T_LIST,
            1);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.errors.ref().length());
        for(const auto & value: qAsConst(s.errors.ref())) {
            writeManageNotebookSharesError(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readManageNotebookSharesResult(
    ThriftBinaryBufferReader & reader,
    ManageNotebookSharesResult & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<ManageNotebookSharesError> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNotebookSharesResult.errors)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    ManageNotebookSharesError elem;
                    readManageNotebookSharesError(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.errors = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void ManageNotebookSharesResult::print(QTextStream & strm) const
{
    strm << "ManageNotebookSharesResult: {\n";
    localData.print(strm);

    if (errors.isSet()) {
        strm << "    errors = "
            << "QList<ManageNotebookSharesError> {";
        for(const auto & v: errors.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    errors is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeSharedNoteTemplate(
    ThriftBinaryBufferWriter & writer,
    const SharedNoteTemplate & s)
{
    writer.writeStructBegin(QStringLiteral("SharedNoteTemplate"));
    if (s.noteGuid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noteGuid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.noteGuid.ref());
        writer.writeFieldEnd();
    }

    if (s.recipientThreadId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientThreadId"),
            ThriftFieldType::T_I64,
            4);

        writer.writeI64(s.recipientThreadId.ref());
        writer.writeFieldEnd();
    }

    if (s.recipientContacts.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientContacts"),
            ThriftFieldType::T_LIST,
            2);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.recipientContacts.ref().length());
        for(const auto & value: qAsConst(s.recipientContacts.ref())) {
            writeContact(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.privilege.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(s.privilege.ref()));
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSharedNoteTemplate(
    ThriftBinaryBufferReader & reader,
    SharedNoteTemplate & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.noteGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageThreadID v;
                reader.readI64(v);
                s.recipientThreadId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Contact> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (SharedNoteTemplate.recipientContacts)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Contact elem;
                    readContact(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.recipientContacts = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel v;
                readEnumSharedNotePrivilegeLevel(reader, v);
                s.privilege = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void SharedNoteTemplate::print(QTextStream & strm) const
{
    strm << "SharedNoteTemplate: {\n";
    localData.print(strm);

    if (noteGuid.isSet()) {
        strm << "    noteGuid = "
            << noteGuid.ref() << "\n";
    }
    else {
        strm << "    noteGuid is not set\n";
    }

    if (recipientThreadId.isSet()) {
        strm << "    recipientThreadId = "
            << recipientThreadId.ref() << "\n";
    }
    else {
        strm << "    recipientThreadId is not set\n";
    }

    if (recipientContacts.isSet()) {
        strm << "    recipientContacts = "
            << "QList<Contact> {";
        for(const auto & v: recipientContacts.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    recipientContacts is not set\n";
    }

    if (privilege.isSet()) {
        strm << "    privilege = "
            << privilege.ref() << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNotebookShareTemplate(
    ThriftBinaryBufferWriter & writer,
    const NotebookShareTemplate & s)
{
    writer.writeStructBegin(QStringLiteral("NotebookShareTemplate"));
    if (s.notebookGuid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.notebookGuid.ref());
        writer.writeFieldEnd();
    }

    if (s.recipientThreadId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientThreadId"),
            ThriftFieldType::T_I64,
            4);

        writer.writeI64(s.recipientThreadId.ref());
        writer.writeFieldEnd();
    }

    if (s.recipientContacts.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientContacts"),
            ThriftFieldType::T_LIST,
            2);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.recipientContacts.ref().length());
        for(const auto & value: qAsConst(s.recipientContacts.ref())) {
            writeContact(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.privilege.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(s.privilege.ref()));
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNotebookShareTemplate(
    ThriftBinaryBufferReader & reader,
    NotebookShareTemplate & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.notebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageThreadID v;
                reader.readI64(v);
                s.recipientThreadId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Contact> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NotebookShareTemplate.recipientContacts)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Contact elem;
                    readContact(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.recipientContacts = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookPrivilegeLevel v;
                readEnumSharedNotebookPrivilegeLevel(reader, v);
                s.privilege = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NotebookShareTemplate::print(QTextStream & strm) const
{
    strm << "NotebookShareTemplate: {\n";
    localData.print(strm);

    if (notebookGuid.isSet()) {
        strm << "    notebookGuid = "
            << notebookGuid.ref() << "\n";
    }
    else {
        strm << "    notebookGuid is not set\n";
    }

    if (recipientThreadId.isSet()) {
        strm << "    recipientThreadId = "
            << recipientThreadId.ref() << "\n";
    }
    else {
        strm << "    recipientThreadId is not set\n";
    }

    if (recipientContacts.isSet()) {
        strm << "    recipientContacts = "
            << "QList<Contact> {";
        for(const auto & v: recipientContacts.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    recipientContacts is not set\n";
    }

    if (privilege.isSet()) {
        strm << "    privilege = "
            << privilege.ref() << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeCreateOrUpdateNotebookSharesResult(
    ThriftBinaryBufferWriter & writer,
    const CreateOrUpdateNotebookSharesResult & s)
{
    writer.writeStructBegin(QStringLiteral("CreateOrUpdateNotebookSharesResult"));
    if (s.updateSequenceNum.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(s.updateSequenceNum.ref());
        writer.writeFieldEnd();
    }

    if (s.matchingShares.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("matchingShares"),
            ThriftFieldType::T_LIST,
            2);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.matchingShares.ref().length());
        for(const auto & value: qAsConst(s.matchingShares.ref())) {
            writeSharedNotebook(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readCreateOrUpdateNotebookSharesResult(
    ThriftBinaryBufferReader & reader,
    CreateOrUpdateNotebookSharesResult & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.updateSequenceNum = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<SharedNotebook> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (CreateOrUpdateNotebookSharesResult.matchingShares)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    SharedNotebook elem;
                    readSharedNotebook(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.matchingShares = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void CreateOrUpdateNotebookSharesResult::print(QTextStream & strm) const
{
    strm << "CreateOrUpdateNotebookSharesResult: {\n";
    localData.print(strm);

    if (updateSequenceNum.isSet()) {
        strm << "    updateSequenceNum = "
            << updateSequenceNum.ref() << "\n";
    }
    else {
        strm << "    updateSequenceNum is not set\n";
    }

    if (matchingShares.isSet()) {
        strm << "    matchingShares = "
            << "QList<SharedNotebook> {";
        for(const auto & v: matchingShares.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    matchingShares is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteShareRelationshipRestrictions(
    ThriftBinaryBufferWriter & writer,
    const NoteShareRelationshipRestrictions & s)
{
    writer.writeStructBegin(QStringLiteral("NoteShareRelationshipRestrictions"));
    if (s.noSetReadNote.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetReadNote"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(s.noSetReadNote.ref());
        writer.writeFieldEnd();
    }

    if (s.noSetModifyNote.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetModifyNote"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(s.noSetModifyNote.ref());
        writer.writeFieldEnd();
    }

    if (s.noSetFullAccess.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetFullAccess"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(s.noSetFullAccess.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteShareRelationshipRestrictions(
    ThriftBinaryBufferReader & reader,
    NoteShareRelationshipRestrictions & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSetReadNote = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSetModifyNote = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSetFullAccess = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NoteShareRelationshipRestrictions::print(QTextStream & strm) const
{
    strm << "NoteShareRelationshipRestrictions: {\n";
    localData.print(strm);

    if (noSetReadNote.isSet()) {
        strm << "    noSetReadNote = "
            << noSetReadNote.ref() << "\n";
    }
    else {
        strm << "    noSetReadNote is not set\n";
    }

    if (noSetModifyNote.isSet()) {
        strm << "    noSetModifyNote = "
            << noSetModifyNote.ref() << "\n";
    }
    else {
        strm << "    noSetModifyNote is not set\n";
    }

    if (noSetFullAccess.isSet()) {
        strm << "    noSetFullAccess = "
            << noSetFullAccess.ref() << "\n";
    }
    else {
        strm << "    noSetFullAccess is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteMemberShareRelationship(
    ThriftBinaryBufferWriter & writer,
    const NoteMemberShareRelationship & s)
{
    writer.writeStructBegin(QStringLiteral("NoteMemberShareRelationship"));
    if (s.displayName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("displayName"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.displayName.ref());
        writer.writeFieldEnd();
    }

    if (s.recipientUserId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientUserId"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(s.recipientUserId.ref());
        writer.writeFieldEnd();
    }

    if (s.privilege.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(s.privilege.ref()));
        writer.writeFieldEnd();
    }

    if (s.restrictions.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("restrictions"),
            ThriftFieldType::T_STRUCT,
            4);

        writeNoteShareRelationshipRestrictions(writer, s.restrictions.ref());
        writer.writeFieldEnd();
    }

    if (s.sharerUserId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(s.sharerUserId.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteMemberShareRelationship(
    ThriftBinaryBufferReader & reader,
    NoteMemberShareRelationship & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.displayName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.recipientUserId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel v;
                readEnumSharedNotePrivilegeLevel(reader, v);
                s.privilege = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteShareRelationshipRestrictions v;
                readNoteShareRelationshipRestrictions(reader, v);
                s.restrictions = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.sharerUserId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NoteMemberShareRelationship::print(QTextStream & strm) const
{
    strm << "NoteMemberShareRelationship: {\n";
    localData.print(strm);

    if (displayName.isSet()) {
        strm << "    displayName = "
            << displayName.ref() << "\n";
    }
    else {
        strm << "    displayName is not set\n";
    }

    if (recipientUserId.isSet()) {
        strm << "    recipientUserId = "
            << recipientUserId.ref() << "\n";
    }
    else {
        strm << "    recipientUserId is not set\n";
    }

    if (privilege.isSet()) {
        strm << "    privilege = "
            << privilege.ref() << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    if (restrictions.isSet()) {
        strm << "    restrictions = "
            << restrictions.ref() << "\n";
    }
    else {
        strm << "    restrictions is not set\n";
    }

    if (sharerUserId.isSet()) {
        strm << "    sharerUserId = "
            << sharerUserId.ref() << "\n";
    }
    else {
        strm << "    sharerUserId is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteInvitationShareRelationship(
    ThriftBinaryBufferWriter & writer,
    const NoteInvitationShareRelationship & s)
{
    writer.writeStructBegin(QStringLiteral("NoteInvitationShareRelationship"));
    if (s.displayName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("displayName"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.displayName.ref());
        writer.writeFieldEnd();
    }

    if (s.recipientIdentityId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientIdentityId"),
            ThriftFieldType::T_I64,
            2);

        writer.writeI64(s.recipientIdentityId.ref());
        writer.writeFieldEnd();
    }

    if (s.privilege.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(s.privilege.ref()));
        writer.writeFieldEnd();
    }

    if (s.sharerUserId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(s.sharerUserId.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteInvitationShareRelationship(
    ThriftBinaryBufferReader & reader,
    NoteInvitationShareRelationship & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.displayName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                IdentityID v;
                reader.readI64(v);
                s.recipientIdentityId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel v;
                readEnumSharedNotePrivilegeLevel(reader, v);
                s.privilege = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.sharerUserId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NoteInvitationShareRelationship::print(QTextStream & strm) const
{
    strm << "NoteInvitationShareRelationship: {\n";
    localData.print(strm);

    if (displayName.isSet()) {
        strm << "    displayName = "
            << displayName.ref() << "\n";
    }
    else {
        strm << "    displayName is not set\n";
    }

    if (recipientIdentityId.isSet()) {
        strm << "    recipientIdentityId = "
            << recipientIdentityId.ref() << "\n";
    }
    else {
        strm << "    recipientIdentityId is not set\n";
    }

    if (privilege.isSet()) {
        strm << "    privilege = "
            << privilege.ref() << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    if (sharerUserId.isSet()) {
        strm << "    sharerUserId = "
            << sharerUserId.ref() << "\n";
    }
    else {
        strm << "    sharerUserId is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteShareRelationships(
    ThriftBinaryBufferWriter & writer,
    const NoteShareRelationships & s)
{
    writer.writeStructBegin(QStringLiteral("NoteShareRelationships"));
    if (s.invitations.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("invitations"),
            ThriftFieldType::T_LIST,
            1);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.invitations.ref().length());
        for(const auto & value: qAsConst(s.invitations.ref())) {
            writeNoteInvitationShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.memberships.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("memberships"),
            ThriftFieldType::T_LIST,
            2);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.memberships.ref().length());
        for(const auto & value: qAsConst(s.memberships.ref())) {
            writeNoteMemberShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.invitationRestrictions.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("invitationRestrictions"),
            ThriftFieldType::T_STRUCT,
            3);

        writeNoteShareRelationshipRestrictions(writer, s.invitationRestrictions.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteShareRelationships(
    ThriftBinaryBufferReader & reader,
    NoteShareRelationships & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NoteInvitationShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteShareRelationships.invitations)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    NoteInvitationShareRelationship elem;
                    readNoteInvitationShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.invitations = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NoteMemberShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (NoteShareRelationships.memberships)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    NoteMemberShareRelationship elem;
                    readNoteMemberShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.memberships = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteShareRelationshipRestrictions v;
                readNoteShareRelationshipRestrictions(reader, v);
                s.invitationRestrictions = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NoteShareRelationships::print(QTextStream & strm) const
{
    strm << "NoteShareRelationships: {\n";
    localData.print(strm);

    if (invitations.isSet()) {
        strm << "    invitations = "
            << "QList<NoteInvitationShareRelationship> {";
        for(const auto & v: invitations.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    invitations is not set\n";
    }

    if (memberships.isSet()) {
        strm << "    memberships = "
            << "QList<NoteMemberShareRelationship> {";
        for(const auto & v: memberships.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    memberships is not set\n";
    }

    if (invitationRestrictions.isSet()) {
        strm << "    invitationRestrictions = "
            << invitationRestrictions.ref() << "\n";
    }
    else {
        strm << "    invitationRestrictions is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeManageNoteSharesParameters(
    ThriftBinaryBufferWriter & writer,
    const ManageNoteSharesParameters & s)
{
    writer.writeStructBegin(QStringLiteral("ManageNoteSharesParameters"));
    if (s.noteGuid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noteGuid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.noteGuid.ref());
        writer.writeFieldEnd();
    }

    if (s.membershipsToUpdate.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("membershipsToUpdate"),
            ThriftFieldType::T_LIST,
            2);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.membershipsToUpdate.ref().length());
        for(const auto & value: qAsConst(s.membershipsToUpdate.ref())) {
            writeNoteMemberShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.invitationsToUpdate.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("invitationsToUpdate"),
            ThriftFieldType::T_LIST,
            3);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.invitationsToUpdate.ref().length());
        for(const auto & value: qAsConst(s.invitationsToUpdate.ref())) {
            writeNoteInvitationShareRelationship(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.membershipsToUnshare.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("membershipsToUnshare"),
            ThriftFieldType::T_LIST,
            4);

        writer.writeListBegin(ThriftFieldType::T_I32, s.membershipsToUnshare.ref().length());
        for(const auto & value: qAsConst(s.membershipsToUnshare.ref())) {
            writer.writeI32(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.invitationsToUnshare.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("invitationsToUnshare"),
            ThriftFieldType::T_LIST,
            5);

        writer.writeListBegin(ThriftFieldType::T_I64, s.invitationsToUnshare.ref().length());
        for(const auto & value: qAsConst(s.invitationsToUnshare.ref())) {
            writer.writeI64(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readManageNoteSharesParameters(
    ThriftBinaryBufferReader & reader,
    ManageNoteSharesParameters & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.noteGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NoteMemberShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNoteSharesParameters.membershipsToUpdate)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    NoteMemberShareRelationship elem;
                    readNoteMemberShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.membershipsToUpdate = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<NoteInvitationShareRelationship> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNoteSharesParameters.invitationsToUpdate)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    NoteInvitationShareRelationship elem;
                    readNoteInvitationShareRelationship(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.invitationsToUpdate = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<UserID> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_I32) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNoteSharesParameters.membershipsToUnshare)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    UserID elem;
                    reader.readI32(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.membershipsToUnshare = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<IdentityID> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_I64) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNoteSharesParameters.invitationsToUnshare)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    IdentityID elem;
                    reader.readI64(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.invitationsToUnshare = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void ManageNoteSharesParameters::print(QTextStream & strm) const
{
    strm << "ManageNoteSharesParameters: {\n";
    localData.print(strm);

    if (noteGuid.isSet()) {
        strm << "    noteGuid = "
            << noteGuid.ref() << "\n";
    }
    else {
        strm << "    noteGuid is not set\n";
    }

    if (membershipsToUpdate.isSet()) {
        strm << "    membershipsToUpdate = "
            << "QList<NoteMemberShareRelationship> {";
        for(const auto & v: membershipsToUpdate.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    membershipsToUpdate is not set\n";
    }

    if (invitationsToUpdate.isSet()) {
        strm << "    invitationsToUpdate = "
            << "QList<NoteInvitationShareRelationship> {";
        for(const auto & v: invitationsToUpdate.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    invitationsToUpdate is not set\n";
    }

    if (membershipsToUnshare.isSet()) {
        strm << "    membershipsToUnshare = "
            << "QList<UserID> {";
        for(const auto & v: membershipsToUnshare.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    membershipsToUnshare is not set\n";
    }

    if (invitationsToUnshare.isSet()) {
        strm << "    invitationsToUnshare = "
            << "QList<IdentityID> {";
        for(const auto & v: invitationsToUnshare.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    invitationsToUnshare is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeManageNoteSharesError(
    ThriftBinaryBufferWriter & writer,
    const ManageNoteSharesError & s)
{
    writer.writeStructBegin(QStringLiteral("ManageNoteSharesError"));
    if (s.identityID.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("identityID"),
            ThriftFieldType::T_I64,
            1);

        writer.writeI64(s.identityID.ref());
        writer.writeFieldEnd();
    }

    if (s.userID.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userID"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(s.userID.ref());
        writer.writeFieldEnd();
    }

    if (s.userException.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMUserException(writer, s.userException.ref());
        writer.writeFieldEnd();
    }

    if (s.notFoundException.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notFoundException"),
            ThriftFieldType::T_STRUCT,
            4);

        writeEDAMNotFoundException(writer, s.notFoundException.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readManageNoteSharesError(
    ThriftBinaryBufferReader & reader,
    ManageNoteSharesError & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                IdentityID v;
                reader.readI64(v);
                s.identityID = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.userID = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException v;
                readEDAMUserException(reader, v);
                s.userException = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException v;
                readEDAMNotFoundException(reader, v);
                s.notFoundException = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void ManageNoteSharesError::print(QTextStream & strm) const
{
    strm << "ManageNoteSharesError: {\n";
    localData.print(strm);

    if (identityID.isSet()) {
        strm << "    identityID = "
            << identityID.ref() << "\n";
    }
    else {
        strm << "    identityID is not set\n";
    }

    if (userID.isSet()) {
        strm << "    userID = "
            << userID.ref() << "\n";
    }
    else {
        strm << "    userID is not set\n";
    }

    if (userException.isSet()) {
        strm << "    userException = "
            << userException.ref() << "\n";
    }
    else {
        strm << "    userException is not set\n";
    }

    if (notFoundException.isSet()) {
        strm << "    notFoundException = "
            << notFoundException.ref() << "\n";
    }
    else {
        strm << "    notFoundException is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeManageNoteSharesResult(
    ThriftBinaryBufferWriter & writer,
    const ManageNoteSharesResult & s)
{
    writer.writeStructBegin(QStringLiteral("ManageNoteSharesResult"));
    if (s.errors.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("errors"),
            ThriftFieldType::T_LIST,
            1);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.errors.ref().length());
        for(const auto & value: qAsConst(s.errors.ref())) {
            writeManageNoteSharesError(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readManageNoteSharesResult(
    ThriftBinaryBufferReader & reader,
    ManageNoteSharesResult & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<ManageNoteSharesError> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (ManageNoteSharesResult.errors)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    ManageNoteSharesError elem;
                    readManageNoteSharesError(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.errors = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void ManageNoteSharesResult::print(QTextStream & strm) const
{
    strm << "ManageNoteSharesResult: {\n";
    localData.print(strm);

    if (errors.isSet()) {
        strm << "    errors = "
            << "QList<ManageNoteSharesError> {";
        for(const auto & v: errors.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    errors is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeData(
    ThriftBinaryBufferWriter & writer,
    const Data & s)
{
    writer.writeStructBegin(QStringLiteral("Data"));
    if (s.bodyHash.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("bodyHash"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeBinary(s.bodyHash.ref());
        writer.writeFieldEnd();
    }

    if (s.size.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("size"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(s.size.ref());
        writer.writeFieldEnd();
    }

    if (s.body.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("body"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeBinary(s.body.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readData(
    ThriftBinaryBufferReader & reader,
    Data & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                s.bodyHash = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.size = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                s.body = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void Data::print(QTextStream & strm) const
{
    strm << "Data: {\n";
    localData.print(strm);

    if (bodyHash.isSet()) {
        strm << "    bodyHash = "
            << bodyHash.ref() << "\n";
    }
    else {
        strm << "    bodyHash is not set\n";
    }

    if (size.isSet()) {
        strm << "    size = "
            << size.ref() << "\n";
    }
    else {
        strm << "    size is not set\n";
    }

    if (body.isSet()) {
        strm << "    body = "
            << body.ref() << "\n";
    }
    else {
        strm << "    body is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeUserAttributes(
    ThriftBinaryBufferWriter & writer,
    const UserAttributes & s)
{
    writer.writeStructBegin(QStringLiteral("UserAttributes"));
    if (s.defaultLocationName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("defaultLocationName"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.defaultLocationName.ref());
        writer.writeFieldEnd();
    }

    if (s.defaultLatitude.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("defaultLatitude"),
            ThriftFieldType::T_DOUBLE,
            2);

        writer.writeDouble(s.defaultLatitude.ref());
        writer.writeFieldEnd();
    }

    if (s.defaultLongitude.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("defaultLongitude"),
            ThriftFieldType::T_DOUBLE,
            3);

        writer.writeDouble(s.defaultLongitude.ref());
        writer.writeFieldEnd();
    }

    if (s.preactivation.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("preactivation"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(s.preactivation.ref());
        writer.writeFieldEnd();
    }

    if (s.viewedPromotions.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("viewedPromotions"),
            ThriftFieldType::T_LIST,
            5);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.viewedPromotions.ref().length());
        for(const auto & value: qAsConst(s.viewedPromotions.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.incomingEmailAddress.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("incomingEmailAddress"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(s.incomingEmailAddress.ref());
        writer.writeFieldEnd();
    }

    if (s.recentMailedAddresses.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recentMailedAddresses"),
            ThriftFieldType::T_LIST,
            7);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.recentMailedAddresses.ref().length());
        for(const auto & value: qAsConst(s.recentMailedAddresses.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.comments.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("comments"),
            ThriftFieldType::T_STRING,
            9);

        writer.writeString(s.comments.ref());
        writer.writeFieldEnd();
    }

    if (s.dateAgreedToTermsOfService.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("dateAgreedToTermsOfService"),
            ThriftFieldType::T_I64,
            11);

        writer.writeI64(s.dateAgreedToTermsOfService.ref());
        writer.writeFieldEnd();
    }

    if (s.maxReferrals.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("maxReferrals"),
            ThriftFieldType::T_I32,
            12);

        writer.writeI32(s.maxReferrals.ref());
        writer.writeFieldEnd();
    }

    if (s.referralCount.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("referralCount"),
            ThriftFieldType::T_I32,
            13);

        writer.writeI32(s.referralCount.ref());
        writer.writeFieldEnd();
    }

    if (s.refererCode.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("refererCode"),
            ThriftFieldType::T_STRING,
            14);

        writer.writeString(s.refererCode.ref());
        writer.writeFieldEnd();
    }

    if (s.sentEmailDate.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sentEmailDate"),
            ThriftFieldType::T_I64,
            15);

        writer.writeI64(s.sentEmailDate.ref());
        writer.writeFieldEnd();
    }

    if (s.sentEmailCount.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sentEmailCount"),
            ThriftFieldType::T_I32,
            16);

        writer.writeI32(s.sentEmailCount.ref());
        writer.writeFieldEnd();
    }

    if (s.dailyEmailLimit.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("dailyEmailLimit"),
            ThriftFieldType::T_I32,
            17);

        writer.writeI32(s.dailyEmailLimit.ref());
        writer.writeFieldEnd();
    }

    if (s.emailOptOutDate.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("emailOptOutDate"),
            ThriftFieldType::T_I64,
            18);

        writer.writeI64(s.emailOptOutDate.ref());
        writer.writeFieldEnd();
    }

    if (s.partnerEmailOptInDate.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("partnerEmailOptInDate"),
            ThriftFieldType::T_I64,
            19);

        writer.writeI64(s.partnerEmailOptInDate.ref());
        writer.writeFieldEnd();
    }

    if (s.preferredLanguage.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("preferredLanguage"),
            ThriftFieldType::T_STRING,
            20);

        writer.writeString(s.preferredLanguage.ref());
        writer.writeFieldEnd();
    }

    if (s.preferredCountry.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("preferredCountry"),
            ThriftFieldType::T_STRING,
            21);

        writer.writeString(s.preferredCountry.ref());
        writer.writeFieldEnd();
    }

    if (s.clipFullPage.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("clipFullPage"),
            ThriftFieldType::T_BOOL,
            22);

        writer.writeBool(s.clipFullPage.ref());
        writer.writeFieldEnd();
    }

    if (s.twitterUserName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("twitterUserName"),
            ThriftFieldType::T_STRING,
            23);

        writer.writeString(s.twitterUserName.ref());
        writer.writeFieldEnd();
    }

    if (s.twitterId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("twitterId"),
            ThriftFieldType::T_STRING,
            24);

        writer.writeString(s.twitterId.ref());
        writer.writeFieldEnd();
    }

    if (s.groupName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("groupName"),
            ThriftFieldType::T_STRING,
            25);

        writer.writeString(s.groupName.ref());
        writer.writeFieldEnd();
    }

    if (s.recognitionLanguage.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recognitionLanguage"),
            ThriftFieldType::T_STRING,
            26);

        writer.writeString(s.recognitionLanguage.ref());
        writer.writeFieldEnd();
    }

    if (s.referralProof.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("referralProof"),
            ThriftFieldType::T_STRING,
            28);

        writer.writeString(s.referralProof.ref());
        writer.writeFieldEnd();
    }

    if (s.educationalDiscount.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("educationalDiscount"),
            ThriftFieldType::T_BOOL,
            29);

        writer.writeBool(s.educationalDiscount.ref());
        writer.writeFieldEnd();
    }

    if (s.businessAddress.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("businessAddress"),
            ThriftFieldType::T_STRING,
            30);

        writer.writeString(s.businessAddress.ref());
        writer.writeFieldEnd();
    }

    if (s.hideSponsorBilling.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("hideSponsorBilling"),
            ThriftFieldType::T_BOOL,
            31);

        writer.writeBool(s.hideSponsorBilling.ref());
        writer.writeFieldEnd();
    }

    if (s.useEmailAutoFiling.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("useEmailAutoFiling"),
            ThriftFieldType::T_BOOL,
            33);

        writer.writeBool(s.useEmailAutoFiling.ref());
        writer.writeFieldEnd();
    }

    if (s.reminderEmailConfig.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderEmailConfig"),
            ThriftFieldType::T_I32,
            34);

        writer.writeI32(static_cast<qint32>(s.reminderEmailConfig.ref()));
        writer.writeFieldEnd();
    }

    if (s.emailAddressLastConfirmed.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("emailAddressLastConfirmed"),
            ThriftFieldType::T_I64,
            35);

        writer.writeI64(s.emailAddressLastConfirmed.ref());
        writer.writeFieldEnd();
    }

    if (s.passwordUpdated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("passwordUpdated"),
            ThriftFieldType::T_I64,
            36);

        writer.writeI64(s.passwordUpdated.ref());
        writer.writeFieldEnd();
    }

    if (s.salesforcePushEnabled.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("salesforcePushEnabled"),
            ThriftFieldType::T_BOOL,
            37);

        writer.writeBool(s.salesforcePushEnabled.ref());
        writer.writeFieldEnd();
    }

    if (s.shouldLogClientEvent.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("shouldLogClientEvent"),
            ThriftFieldType::T_BOOL,
            38);

        writer.writeBool(s.shouldLogClientEvent.ref());
        writer.writeFieldEnd();
    }

    if (s.optOutMachineLearning.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("optOutMachineLearning"),
            ThriftFieldType::T_BOOL,
            39);

        writer.writeBool(s.optOutMachineLearning.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readUserAttributes(
    ThriftBinaryBufferReader & reader,
    UserAttributes & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.defaultLocationName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.defaultLatitude = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.defaultLongitude = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.preactivation = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (UserAttributes.viewedPromotions)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.viewedPromotions = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.incomingEmailAddress = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (UserAttributes.recentMailedAddresses)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.recentMailedAddresses = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.comments = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.dateAgreedToTermsOfService = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.maxReferrals = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.referralCount = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.refererCode = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.sentEmailDate = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.sentEmailCount = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.dailyEmailLimit = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.emailOptOutDate = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.partnerEmailOptInDate = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.preferredLanguage = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.preferredCountry = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.clipFullPage = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.twitterUserName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.twitterId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 25) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.groupName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 26) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.recognitionLanguage = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 28) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.referralProof = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 29) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.educationalDiscount = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 30) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.businessAddress = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 31) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.hideSponsorBilling = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 33) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.useEmailAutoFiling = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 34) {
            if (fieldType == ThriftFieldType::T_I32) {
                ReminderEmailConfig v;
                readEnumReminderEmailConfig(reader, v);
                s.reminderEmailConfig = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 35) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.emailAddressLastConfirmed = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 36) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.passwordUpdated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 37) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.salesforcePushEnabled = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 38) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.shouldLogClientEvent = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 39) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.optOutMachineLearning = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void UserAttributes::print(QTextStream & strm) const
{
    strm << "UserAttributes: {\n";
    localData.print(strm);

    if (defaultLocationName.isSet()) {
        strm << "    defaultLocationName = "
            << defaultLocationName.ref() << "\n";
    }
    else {
        strm << "    defaultLocationName is not set\n";
    }

    if (defaultLatitude.isSet()) {
        strm << "    defaultLatitude = "
            << defaultLatitude.ref() << "\n";
    }
    else {
        strm << "    defaultLatitude is not set\n";
    }

    if (defaultLongitude.isSet()) {
        strm << "    defaultLongitude = "
            << defaultLongitude.ref() << "\n";
    }
    else {
        strm << "    defaultLongitude is not set\n";
    }

    if (preactivation.isSet()) {
        strm << "    preactivation = "
            << preactivation.ref() << "\n";
    }
    else {
        strm << "    preactivation is not set\n";
    }

    if (viewedPromotions.isSet()) {
        strm << "    viewedPromotions = "
            << "QList<QString> {";
        for(const auto & v: viewedPromotions.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    viewedPromotions is not set\n";
    }

    if (incomingEmailAddress.isSet()) {
        strm << "    incomingEmailAddress = "
            << incomingEmailAddress.ref() << "\n";
    }
    else {
        strm << "    incomingEmailAddress is not set\n";
    }

    if (recentMailedAddresses.isSet()) {
        strm << "    recentMailedAddresses = "
            << "QList<QString> {";
        for(const auto & v: recentMailedAddresses.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    recentMailedAddresses is not set\n";
    }

    if (comments.isSet()) {
        strm << "    comments = "
            << comments.ref() << "\n";
    }
    else {
        strm << "    comments is not set\n";
    }

    if (dateAgreedToTermsOfService.isSet()) {
        strm << "    dateAgreedToTermsOfService = "
            << dateAgreedToTermsOfService.ref() << "\n";
    }
    else {
        strm << "    dateAgreedToTermsOfService is not set\n";
    }

    if (maxReferrals.isSet()) {
        strm << "    maxReferrals = "
            << maxReferrals.ref() << "\n";
    }
    else {
        strm << "    maxReferrals is not set\n";
    }

    if (referralCount.isSet()) {
        strm << "    referralCount = "
            << referralCount.ref() << "\n";
    }
    else {
        strm << "    referralCount is not set\n";
    }

    if (refererCode.isSet()) {
        strm << "    refererCode = "
            << refererCode.ref() << "\n";
    }
    else {
        strm << "    refererCode is not set\n";
    }

    if (sentEmailDate.isSet()) {
        strm << "    sentEmailDate = "
            << sentEmailDate.ref() << "\n";
    }
    else {
        strm << "    sentEmailDate is not set\n";
    }

    if (sentEmailCount.isSet()) {
        strm << "    sentEmailCount = "
            << sentEmailCount.ref() << "\n";
    }
    else {
        strm << "    sentEmailCount is not set\n";
    }

    if (dailyEmailLimit.isSet()) {
        strm << "    dailyEmailLimit = "
            << dailyEmailLimit.ref() << "\n";
    }
    else {
        strm << "    dailyEmailLimit is not set\n";
    }

    if (emailOptOutDate.isSet()) {
        strm << "    emailOptOutDate = "
            << emailOptOutDate.ref() << "\n";
    }
    else {
        strm << "    emailOptOutDate is not set\n";
    }

    if (partnerEmailOptInDate.isSet()) {
        strm << "    partnerEmailOptInDate = "
            << partnerEmailOptInDate.ref() << "\n";
    }
    else {
        strm << "    partnerEmailOptInDate is not set\n";
    }

    if (preferredLanguage.isSet()) {
        strm << "    preferredLanguage = "
            << preferredLanguage.ref() << "\n";
    }
    else {
        strm << "    preferredLanguage is not set\n";
    }

    if (preferredCountry.isSet()) {
        strm << "    preferredCountry = "
            << preferredCountry.ref() << "\n";
    }
    else {
        strm << "    preferredCountry is not set\n";
    }

    if (clipFullPage.isSet()) {
        strm << "    clipFullPage = "
            << clipFullPage.ref() << "\n";
    }
    else {
        strm << "    clipFullPage is not set\n";
    }

    if (twitterUserName.isSet()) {
        strm << "    twitterUserName = "
            << twitterUserName.ref() << "\n";
    }
    else {
        strm << "    twitterUserName is not set\n";
    }

    if (twitterId.isSet()) {
        strm << "    twitterId = "
            << twitterId.ref() << "\n";
    }
    else {
        strm << "    twitterId is not set\n";
    }

    if (groupName.isSet()) {
        strm << "    groupName = "
            << groupName.ref() << "\n";
    }
    else {
        strm << "    groupName is not set\n";
    }

    if (recognitionLanguage.isSet()) {
        strm << "    recognitionLanguage = "
            << recognitionLanguage.ref() << "\n";
    }
    else {
        strm << "    recognitionLanguage is not set\n";
    }

    if (referralProof.isSet()) {
        strm << "    referralProof = "
            << referralProof.ref() << "\n";
    }
    else {
        strm << "    referralProof is not set\n";
    }

    if (educationalDiscount.isSet()) {
        strm << "    educationalDiscount = "
            << educationalDiscount.ref() << "\n";
    }
    else {
        strm << "    educationalDiscount is not set\n";
    }

    if (businessAddress.isSet()) {
        strm << "    businessAddress = "
            << businessAddress.ref() << "\n";
    }
    else {
        strm << "    businessAddress is not set\n";
    }

    if (hideSponsorBilling.isSet()) {
        strm << "    hideSponsorBilling = "
            << hideSponsorBilling.ref() << "\n";
    }
    else {
        strm << "    hideSponsorBilling is not set\n";
    }

    if (useEmailAutoFiling.isSet()) {
        strm << "    useEmailAutoFiling = "
            << useEmailAutoFiling.ref() << "\n";
    }
    else {
        strm << "    useEmailAutoFiling is not set\n";
    }

    if (reminderEmailConfig.isSet()) {
        strm << "    reminderEmailConfig = "
            << reminderEmailConfig.ref() << "\n";
    }
    else {
        strm << "    reminderEmailConfig is not set\n";
    }

    if (emailAddressLastConfirmed.isSet()) {
        strm << "    emailAddressLastConfirmed = "
            << emailAddressLastConfirmed.ref() << "\n";
    }
    else {
        strm << "    emailAddressLastConfirmed is not set\n";
    }

    if (passwordUpdated.isSet()) {
        strm << "    passwordUpdated = "
            << passwordUpdated.ref() << "\n";
    }
    else {
        strm << "    passwordUpdated is not set\n";
    }

    if (salesforcePushEnabled.isSet()) {
        strm << "    salesforcePushEnabled = "
            << salesforcePushEnabled.ref() << "\n";
    }
    else {
        strm << "    salesforcePushEnabled is not set\n";
    }

    if (shouldLogClientEvent.isSet()) {
        strm << "    shouldLogClientEvent = "
            << shouldLogClientEvent.ref() << "\n";
    }
    else {
        strm << "    shouldLogClientEvent is not set\n";
    }

    if (optOutMachineLearning.isSet()) {
        strm << "    optOutMachineLearning = "
            << optOutMachineLearning.ref() << "\n";
    }
    else {
        strm << "    optOutMachineLearning is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeBusinessUserAttributes(
    ThriftBinaryBufferWriter & writer,
    const BusinessUserAttributes & s)
{
    writer.writeStructBegin(QStringLiteral("BusinessUserAttributes"));
    if (s.title.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("title"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.title.ref());
        writer.writeFieldEnd();
    }

    if (s.location.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("location"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.location.ref());
        writer.writeFieldEnd();
    }

    if (s.department.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("department"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(s.department.ref());
        writer.writeFieldEnd();
    }

    if (s.mobilePhone.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("mobilePhone"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.mobilePhone.ref());
        writer.writeFieldEnd();
    }

    if (s.linkedInProfileUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("linkedInProfileUrl"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(s.linkedInProfileUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.workPhone.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("workPhone"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(s.workPhone.ref());
        writer.writeFieldEnd();
    }

    if (s.companyStartDate.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("companyStartDate"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(s.companyStartDate.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readBusinessUserAttributes(
    ThriftBinaryBufferReader & reader,
    BusinessUserAttributes & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.title = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.location = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.department = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.mobilePhone = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.linkedInProfileUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.workPhone = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.companyStartDate = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void BusinessUserAttributes::print(QTextStream & strm) const
{
    strm << "BusinessUserAttributes: {\n";
    localData.print(strm);

    if (title.isSet()) {
        strm << "    title = "
            << title.ref() << "\n";
    }
    else {
        strm << "    title is not set\n";
    }

    if (location.isSet()) {
        strm << "    location = "
            << location.ref() << "\n";
    }
    else {
        strm << "    location is not set\n";
    }

    if (department.isSet()) {
        strm << "    department = "
            << department.ref() << "\n";
    }
    else {
        strm << "    department is not set\n";
    }

    if (mobilePhone.isSet()) {
        strm << "    mobilePhone = "
            << mobilePhone.ref() << "\n";
    }
    else {
        strm << "    mobilePhone is not set\n";
    }

    if (linkedInProfileUrl.isSet()) {
        strm << "    linkedInProfileUrl = "
            << linkedInProfileUrl.ref() << "\n";
    }
    else {
        strm << "    linkedInProfileUrl is not set\n";
    }

    if (workPhone.isSet()) {
        strm << "    workPhone = "
            << workPhone.ref() << "\n";
    }
    else {
        strm << "    workPhone is not set\n";
    }

    if (companyStartDate.isSet()) {
        strm << "    companyStartDate = "
            << companyStartDate.ref() << "\n";
    }
    else {
        strm << "    companyStartDate is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeAccounting(
    ThriftBinaryBufferWriter & writer,
    const Accounting & s)
{
    writer.writeStructBegin(QStringLiteral("Accounting"));
    if (s.uploadLimitEnd.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("uploadLimitEnd"),
            ThriftFieldType::T_I64,
            2);

        writer.writeI64(s.uploadLimitEnd.ref());
        writer.writeFieldEnd();
    }

    if (s.uploadLimitNextMonth.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("uploadLimitNextMonth"),
            ThriftFieldType::T_I64,
            3);

        writer.writeI64(s.uploadLimitNextMonth.ref());
        writer.writeFieldEnd();
    }

    if (s.premiumServiceStatus.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("premiumServiceStatus"),
            ThriftFieldType::T_I32,
            4);

        writer.writeI32(static_cast<qint32>(s.premiumServiceStatus.ref()));
        writer.writeFieldEnd();
    }

    if (s.premiumOrderNumber.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("premiumOrderNumber"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(s.premiumOrderNumber.ref());
        writer.writeFieldEnd();
    }

    if (s.premiumCommerceService.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("premiumCommerceService"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(s.premiumCommerceService.ref());
        writer.writeFieldEnd();
    }

    if (s.premiumServiceStart.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("premiumServiceStart"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(s.premiumServiceStart.ref());
        writer.writeFieldEnd();
    }

    if (s.premiumServiceSKU.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("premiumServiceSKU"),
            ThriftFieldType::T_STRING,
            8);

        writer.writeString(s.premiumServiceSKU.ref());
        writer.writeFieldEnd();
    }

    if (s.lastSuccessfulCharge.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("lastSuccessfulCharge"),
            ThriftFieldType::T_I64,
            9);

        writer.writeI64(s.lastSuccessfulCharge.ref());
        writer.writeFieldEnd();
    }

    if (s.lastFailedCharge.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("lastFailedCharge"),
            ThriftFieldType::T_I64,
            10);

        writer.writeI64(s.lastFailedCharge.ref());
        writer.writeFieldEnd();
    }

    if (s.lastFailedChargeReason.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("lastFailedChargeReason"),
            ThriftFieldType::T_STRING,
            11);

        writer.writeString(s.lastFailedChargeReason.ref());
        writer.writeFieldEnd();
    }

    if (s.nextPaymentDue.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("nextPaymentDue"),
            ThriftFieldType::T_I64,
            12);

        writer.writeI64(s.nextPaymentDue.ref());
        writer.writeFieldEnd();
    }

    if (s.premiumLockUntil.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("premiumLockUntil"),
            ThriftFieldType::T_I64,
            13);

        writer.writeI64(s.premiumLockUntil.ref());
        writer.writeFieldEnd();
    }

    if (s.updated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            14);

        writer.writeI64(s.updated.ref());
        writer.writeFieldEnd();
    }

    if (s.premiumSubscriptionNumber.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("premiumSubscriptionNumber"),
            ThriftFieldType::T_STRING,
            16);

        writer.writeString(s.premiumSubscriptionNumber.ref());
        writer.writeFieldEnd();
    }

    if (s.lastRequestedCharge.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("lastRequestedCharge"),
            ThriftFieldType::T_I64,
            17);

        writer.writeI64(s.lastRequestedCharge.ref());
        writer.writeFieldEnd();
    }

    if (s.currency.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("currency"),
            ThriftFieldType::T_STRING,
            18);

        writer.writeString(s.currency.ref());
        writer.writeFieldEnd();
    }

    if (s.unitPrice.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("unitPrice"),
            ThriftFieldType::T_I32,
            19);

        writer.writeI32(s.unitPrice.ref());
        writer.writeFieldEnd();
    }

    if (s.businessId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("businessId"),
            ThriftFieldType::T_I32,
            20);

        writer.writeI32(s.businessId.ref());
        writer.writeFieldEnd();
    }

    if (s.businessName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("businessName"),
            ThriftFieldType::T_STRING,
            21);

        writer.writeString(s.businessName.ref());
        writer.writeFieldEnd();
    }

    if (s.businessRole.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("businessRole"),
            ThriftFieldType::T_I32,
            22);

        writer.writeI32(static_cast<qint32>(s.businessRole.ref()));
        writer.writeFieldEnd();
    }

    if (s.unitDiscount.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("unitDiscount"),
            ThriftFieldType::T_I32,
            23);

        writer.writeI32(s.unitDiscount.ref());
        writer.writeFieldEnd();
    }

    if (s.nextChargeDate.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("nextChargeDate"),
            ThriftFieldType::T_I64,
            24);

        writer.writeI64(s.nextChargeDate.ref());
        writer.writeFieldEnd();
    }

    if (s.availablePoints.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("availablePoints"),
            ThriftFieldType::T_I32,
            25);

        writer.writeI32(s.availablePoints.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readAccounting(
    ThriftBinaryBufferReader & reader,
    Accounting & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.uploadLimitEnd = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.uploadLimitNextMonth = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                PremiumOrderStatus v;
                readEnumPremiumOrderStatus(reader, v);
                s.premiumServiceStatus = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.premiumOrderNumber = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.premiumCommerceService = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.premiumServiceStart = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.premiumServiceSKU = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.lastSuccessfulCharge = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.lastFailedCharge = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.lastFailedChargeReason = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.nextPaymentDue = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.premiumLockUntil = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.updated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.premiumSubscriptionNumber = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.lastRequestedCharge = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.currency = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.unitPrice = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.businessId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.businessName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole v;
                readEnumBusinessUserRole(reader, v);
                s.businessRole = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.unitDiscount = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.nextChargeDate = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 25) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.availablePoints = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void Accounting::print(QTextStream & strm) const
{
    strm << "Accounting: {\n";
    localData.print(strm);

    if (uploadLimitEnd.isSet()) {
        strm << "    uploadLimitEnd = "
            << uploadLimitEnd.ref() << "\n";
    }
    else {
        strm << "    uploadLimitEnd is not set\n";
    }

    if (uploadLimitNextMonth.isSet()) {
        strm << "    uploadLimitNextMonth = "
            << uploadLimitNextMonth.ref() << "\n";
    }
    else {
        strm << "    uploadLimitNextMonth is not set\n";
    }

    if (premiumServiceStatus.isSet()) {
        strm << "    premiumServiceStatus = "
            << premiumServiceStatus.ref() << "\n";
    }
    else {
        strm << "    premiumServiceStatus is not set\n";
    }

    if (premiumOrderNumber.isSet()) {
        strm << "    premiumOrderNumber = "
            << premiumOrderNumber.ref() << "\n";
    }
    else {
        strm << "    premiumOrderNumber is not set\n";
    }

    if (premiumCommerceService.isSet()) {
        strm << "    premiumCommerceService = "
            << premiumCommerceService.ref() << "\n";
    }
    else {
        strm << "    premiumCommerceService is not set\n";
    }

    if (premiumServiceStart.isSet()) {
        strm << "    premiumServiceStart = "
            << premiumServiceStart.ref() << "\n";
    }
    else {
        strm << "    premiumServiceStart is not set\n";
    }

    if (premiumServiceSKU.isSet()) {
        strm << "    premiumServiceSKU = "
            << premiumServiceSKU.ref() << "\n";
    }
    else {
        strm << "    premiumServiceSKU is not set\n";
    }

    if (lastSuccessfulCharge.isSet()) {
        strm << "    lastSuccessfulCharge = "
            << lastSuccessfulCharge.ref() << "\n";
    }
    else {
        strm << "    lastSuccessfulCharge is not set\n";
    }

    if (lastFailedCharge.isSet()) {
        strm << "    lastFailedCharge = "
            << lastFailedCharge.ref() << "\n";
    }
    else {
        strm << "    lastFailedCharge is not set\n";
    }

    if (lastFailedChargeReason.isSet()) {
        strm << "    lastFailedChargeReason = "
            << lastFailedChargeReason.ref() << "\n";
    }
    else {
        strm << "    lastFailedChargeReason is not set\n";
    }

    if (nextPaymentDue.isSet()) {
        strm << "    nextPaymentDue = "
            << nextPaymentDue.ref() << "\n";
    }
    else {
        strm << "    nextPaymentDue is not set\n";
    }

    if (premiumLockUntil.isSet()) {
        strm << "    premiumLockUntil = "
            << premiumLockUntil.ref() << "\n";
    }
    else {
        strm << "    premiumLockUntil is not set\n";
    }

    if (updated.isSet()) {
        strm << "    updated = "
            << updated.ref() << "\n";
    }
    else {
        strm << "    updated is not set\n";
    }

    if (premiumSubscriptionNumber.isSet()) {
        strm << "    premiumSubscriptionNumber = "
            << premiumSubscriptionNumber.ref() << "\n";
    }
    else {
        strm << "    premiumSubscriptionNumber is not set\n";
    }

    if (lastRequestedCharge.isSet()) {
        strm << "    lastRequestedCharge = "
            << lastRequestedCharge.ref() << "\n";
    }
    else {
        strm << "    lastRequestedCharge is not set\n";
    }

    if (currency.isSet()) {
        strm << "    currency = "
            << currency.ref() << "\n";
    }
    else {
        strm << "    currency is not set\n";
    }

    if (unitPrice.isSet()) {
        strm << "    unitPrice = "
            << unitPrice.ref() << "\n";
    }
    else {
        strm << "    unitPrice is not set\n";
    }

    if (businessId.isSet()) {
        strm << "    businessId = "
            << businessId.ref() << "\n";
    }
    else {
        strm << "    businessId is not set\n";
    }

    if (businessName.isSet()) {
        strm << "    businessName = "
            << businessName.ref() << "\n";
    }
    else {
        strm << "    businessName is not set\n";
    }

    if (businessRole.isSet()) {
        strm << "    businessRole = "
            << businessRole.ref() << "\n";
    }
    else {
        strm << "    businessRole is not set\n";
    }

    if (unitDiscount.isSet()) {
        strm << "    unitDiscount = "
            << unitDiscount.ref() << "\n";
    }
    else {
        strm << "    unitDiscount is not set\n";
    }

    if (nextChargeDate.isSet()) {
        strm << "    nextChargeDate = "
            << nextChargeDate.ref() << "\n";
    }
    else {
        strm << "    nextChargeDate is not set\n";
    }

    if (availablePoints.isSet()) {
        strm << "    availablePoints = "
            << availablePoints.ref() << "\n";
    }
    else {
        strm << "    availablePoints is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeBusinessUserInfo(
    ThriftBinaryBufferWriter & writer,
    const BusinessUserInfo & s)
{
    writer.writeStructBegin(QStringLiteral("BusinessUserInfo"));
    if (s.businessId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("businessId"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(s.businessId.ref());
        writer.writeFieldEnd();
    }

    if (s.businessName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("businessName"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.businessName.ref());
        writer.writeFieldEnd();
    }

    if (s.role.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("role"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(s.role.ref()));
        writer.writeFieldEnd();
    }

    if (s.email.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.email.ref());
        writer.writeFieldEnd();
    }

    if (s.updated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            5);

        writer.writeI64(s.updated.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readBusinessUserInfo(
    ThriftBinaryBufferReader & reader,
    BusinessUserInfo & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.businessId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.businessName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole v;
                readEnumBusinessUserRole(reader, v);
                s.role = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.email = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.updated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void BusinessUserInfo::print(QTextStream & strm) const
{
    strm << "BusinessUserInfo: {\n";
    localData.print(strm);

    if (businessId.isSet()) {
        strm << "    businessId = "
            << businessId.ref() << "\n";
    }
    else {
        strm << "    businessId is not set\n";
    }

    if (businessName.isSet()) {
        strm << "    businessName = "
            << businessName.ref() << "\n";
    }
    else {
        strm << "    businessName is not set\n";
    }

    if (role.isSet()) {
        strm << "    role = "
            << role.ref() << "\n";
    }
    else {
        strm << "    role is not set\n";
    }

    if (email.isSet()) {
        strm << "    email = "
            << email.ref() << "\n";
    }
    else {
        strm << "    email is not set\n";
    }

    if (updated.isSet()) {
        strm << "    updated = "
            << updated.ref() << "\n";
    }
    else {
        strm << "    updated is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeAccountLimits(
    ThriftBinaryBufferWriter & writer,
    const AccountLimits & s)
{
    writer.writeStructBegin(QStringLiteral("AccountLimits"));
    if (s.userMailLimitDaily.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userMailLimitDaily"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(s.userMailLimitDaily.ref());
        writer.writeFieldEnd();
    }

    if (s.noteSizeMax.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noteSizeMax"),
            ThriftFieldType::T_I64,
            2);

        writer.writeI64(s.noteSizeMax.ref());
        writer.writeFieldEnd();
    }

    if (s.resourceSizeMax.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("resourceSizeMax"),
            ThriftFieldType::T_I64,
            3);

        writer.writeI64(s.resourceSizeMax.ref());
        writer.writeFieldEnd();
    }

    if (s.userLinkedNotebookMax.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userLinkedNotebookMax"),
            ThriftFieldType::T_I32,
            4);

        writer.writeI32(s.userLinkedNotebookMax.ref());
        writer.writeFieldEnd();
    }

    if (s.uploadLimit.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("uploadLimit"),
            ThriftFieldType::T_I64,
            5);

        writer.writeI64(s.uploadLimit.ref());
        writer.writeFieldEnd();
    }

    if (s.userNoteCountMax.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userNoteCountMax"),
            ThriftFieldType::T_I32,
            6);

        writer.writeI32(s.userNoteCountMax.ref());
        writer.writeFieldEnd();
    }

    if (s.userNotebookCountMax.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userNotebookCountMax"),
            ThriftFieldType::T_I32,
            7);

        writer.writeI32(s.userNotebookCountMax.ref());
        writer.writeFieldEnd();
    }

    if (s.userTagCountMax.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userTagCountMax"),
            ThriftFieldType::T_I32,
            8);

        writer.writeI32(s.userTagCountMax.ref());
        writer.writeFieldEnd();
    }

    if (s.noteTagCountMax.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noteTagCountMax"),
            ThriftFieldType::T_I32,
            9);

        writer.writeI32(s.noteTagCountMax.ref());
        writer.writeFieldEnd();
    }

    if (s.userSavedSearchesMax.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userSavedSearchesMax"),
            ThriftFieldType::T_I32,
            10);

        writer.writeI32(s.userSavedSearchesMax.ref());
        writer.writeFieldEnd();
    }

    if (s.noteResourceCountMax.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noteResourceCountMax"),
            ThriftFieldType::T_I32,
            11);

        writer.writeI32(s.noteResourceCountMax.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readAccountLimits(
    ThriftBinaryBufferReader & reader,
    AccountLimits & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.userMailLimitDaily = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.noteSizeMax = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.resourceSizeMax = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.userLinkedNotebookMax = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.uploadLimit = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.userNoteCountMax = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.userNotebookCountMax = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.userTagCountMax = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.noteTagCountMax = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.userSavedSearchesMax = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.noteResourceCountMax = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void AccountLimits::print(QTextStream & strm) const
{
    strm << "AccountLimits: {\n";
    localData.print(strm);

    if (userMailLimitDaily.isSet()) {
        strm << "    userMailLimitDaily = "
            << userMailLimitDaily.ref() << "\n";
    }
    else {
        strm << "    userMailLimitDaily is not set\n";
    }

    if (noteSizeMax.isSet()) {
        strm << "    noteSizeMax = "
            << noteSizeMax.ref() << "\n";
    }
    else {
        strm << "    noteSizeMax is not set\n";
    }

    if (resourceSizeMax.isSet()) {
        strm << "    resourceSizeMax = "
            << resourceSizeMax.ref() << "\n";
    }
    else {
        strm << "    resourceSizeMax is not set\n";
    }

    if (userLinkedNotebookMax.isSet()) {
        strm << "    userLinkedNotebookMax = "
            << userLinkedNotebookMax.ref() << "\n";
    }
    else {
        strm << "    userLinkedNotebookMax is not set\n";
    }

    if (uploadLimit.isSet()) {
        strm << "    uploadLimit = "
            << uploadLimit.ref() << "\n";
    }
    else {
        strm << "    uploadLimit is not set\n";
    }

    if (userNoteCountMax.isSet()) {
        strm << "    userNoteCountMax = "
            << userNoteCountMax.ref() << "\n";
    }
    else {
        strm << "    userNoteCountMax is not set\n";
    }

    if (userNotebookCountMax.isSet()) {
        strm << "    userNotebookCountMax = "
            << userNotebookCountMax.ref() << "\n";
    }
    else {
        strm << "    userNotebookCountMax is not set\n";
    }

    if (userTagCountMax.isSet()) {
        strm << "    userTagCountMax = "
            << userTagCountMax.ref() << "\n";
    }
    else {
        strm << "    userTagCountMax is not set\n";
    }

    if (noteTagCountMax.isSet()) {
        strm << "    noteTagCountMax = "
            << noteTagCountMax.ref() << "\n";
    }
    else {
        strm << "    noteTagCountMax is not set\n";
    }

    if (userSavedSearchesMax.isSet()) {
        strm << "    userSavedSearchesMax = "
            << userSavedSearchesMax.ref() << "\n";
    }
    else {
        strm << "    userSavedSearchesMax is not set\n";
    }

    if (noteResourceCountMax.isSet()) {
        strm << "    noteResourceCountMax = "
            << noteResourceCountMax.ref() << "\n";
    }
    else {
        strm << "    noteResourceCountMax is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeUser(
    ThriftBinaryBufferWriter & writer,
    const User & s)
{
    writer.writeStructBegin(QStringLiteral("User"));
    if (s.id.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("id"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(s.id.ref());
        writer.writeFieldEnd();
    }

    if (s.username.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.username.ref());
        writer.writeFieldEnd();
    }

    if (s.email.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(s.email.ref());
        writer.writeFieldEnd();
    }

    if (s.name.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.name.ref());
        writer.writeFieldEnd();
    }

    if (s.timezone.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("timezone"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(s.timezone.ref());
        writer.writeFieldEnd();
    }

    if (s.privilege.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            7);

        writer.writeI32(static_cast<qint32>(s.privilege.ref()));
        writer.writeFieldEnd();
    }

    if (s.serviceLevel.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceLevel"),
            ThriftFieldType::T_I32,
            21);

        writer.writeI32(static_cast<qint32>(s.serviceLevel.ref()));
        writer.writeFieldEnd();
    }

    if (s.created.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("created"),
            ThriftFieldType::T_I64,
            9);

        writer.writeI64(s.created.ref());
        writer.writeFieldEnd();
    }

    if (s.updated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            10);

        writer.writeI64(s.updated.ref());
        writer.writeFieldEnd();
    }

    if (s.deleted.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("deleted"),
            ThriftFieldType::T_I64,
            11);

        writer.writeI64(s.deleted.ref());
        writer.writeFieldEnd();
    }

    if (s.active.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("active"),
            ThriftFieldType::T_BOOL,
            13);

        writer.writeBool(s.active.ref());
        writer.writeFieldEnd();
    }

    if (s.shardId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("shardId"),
            ThriftFieldType::T_STRING,
            14);

        writer.writeString(s.shardId.ref());
        writer.writeFieldEnd();
    }

    if (s.attributes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            15);

        writeUserAttributes(writer, s.attributes.ref());
        writer.writeFieldEnd();
    }

    if (s.accounting.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("accounting"),
            ThriftFieldType::T_STRUCT,
            16);

        writeAccounting(writer, s.accounting.ref());
        writer.writeFieldEnd();
    }

    if (s.businessUserInfo.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("businessUserInfo"),
            ThriftFieldType::T_STRUCT,
            18);

        writeBusinessUserInfo(writer, s.businessUserInfo.ref());
        writer.writeFieldEnd();
    }

    if (s.photoUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("photoUrl"),
            ThriftFieldType::T_STRING,
            19);

        writer.writeString(s.photoUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.photoLastUpdated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("photoLastUpdated"),
            ThriftFieldType::T_I64,
            20);

        writer.writeI64(s.photoLastUpdated.ref());
        writer.writeFieldEnd();
    }

    if (s.accountLimits.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("accountLimits"),
            ThriftFieldType::T_STRUCT,
            22);

        writeAccountLimits(writer, s.accountLimits.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readUser(
    ThriftBinaryBufferReader & reader,
    User & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.id = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.username = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.email = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.name = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.timezone = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                PrivilegeLevel v;
                readEnumPrivilegeLevel(reader, v);
                s.privilege = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_I32) {
                ServiceLevel v;
                readEnumServiceLevel(reader, v);
                s.serviceLevel = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.created = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.updated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.deleted = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.active = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.shardId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserAttributes v;
                readUserAttributes(reader, v);
                s.attributes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Accounting v;
                readAccounting(reader, v);
                s.accounting = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                BusinessUserInfo v;
                readBusinessUserInfo(reader, v);
                s.businessUserInfo = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.photoUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.photoLastUpdated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                AccountLimits v;
                readAccountLimits(reader, v);
                s.accountLimits = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void User::print(QTextStream & strm) const
{
    strm << "User: {\n";
    localData.print(strm);

    if (id.isSet()) {
        strm << "    id = "
            << id.ref() << "\n";
    }
    else {
        strm << "    id is not set\n";
    }

    if (username.isSet()) {
        strm << "    username = "
            << username.ref() << "\n";
    }
    else {
        strm << "    username is not set\n";
    }

    if (email.isSet()) {
        strm << "    email = "
            << email.ref() << "\n";
    }
    else {
        strm << "    email is not set\n";
    }

    if (name.isSet()) {
        strm << "    name = "
            << name.ref() << "\n";
    }
    else {
        strm << "    name is not set\n";
    }

    if (timezone.isSet()) {
        strm << "    timezone = "
            << timezone.ref() << "\n";
    }
    else {
        strm << "    timezone is not set\n";
    }

    if (privilege.isSet()) {
        strm << "    privilege = "
            << privilege.ref() << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    if (serviceLevel.isSet()) {
        strm << "    serviceLevel = "
            << serviceLevel.ref() << "\n";
    }
    else {
        strm << "    serviceLevel is not set\n";
    }

    if (created.isSet()) {
        strm << "    created = "
            << created.ref() << "\n";
    }
    else {
        strm << "    created is not set\n";
    }

    if (updated.isSet()) {
        strm << "    updated = "
            << updated.ref() << "\n";
    }
    else {
        strm << "    updated is not set\n";
    }

    if (deleted.isSet()) {
        strm << "    deleted = "
            << deleted.ref() << "\n";
    }
    else {
        strm << "    deleted is not set\n";
    }

    if (active.isSet()) {
        strm << "    active = "
            << active.ref() << "\n";
    }
    else {
        strm << "    active is not set\n";
    }

    if (shardId.isSet()) {
        strm << "    shardId = "
            << shardId.ref() << "\n";
    }
    else {
        strm << "    shardId is not set\n";
    }

    if (attributes.isSet()) {
        strm << "    attributes = "
            << attributes.ref() << "\n";
    }
    else {
        strm << "    attributes is not set\n";
    }

    if (accounting.isSet()) {
        strm << "    accounting = "
            << accounting.ref() << "\n";
    }
    else {
        strm << "    accounting is not set\n";
    }

    if (businessUserInfo.isSet()) {
        strm << "    businessUserInfo = "
            << businessUserInfo.ref() << "\n";
    }
    else {
        strm << "    businessUserInfo is not set\n";
    }

    if (photoUrl.isSet()) {
        strm << "    photoUrl = "
            << photoUrl.ref() << "\n";
    }
    else {
        strm << "    photoUrl is not set\n";
    }

    if (photoLastUpdated.isSet()) {
        strm << "    photoLastUpdated = "
            << photoLastUpdated.ref() << "\n";
    }
    else {
        strm << "    photoLastUpdated is not set\n";
    }

    if (accountLimits.isSet()) {
        strm << "    accountLimits = "
            << accountLimits.ref() << "\n";
    }
    else {
        strm << "    accountLimits is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeContact(
    ThriftBinaryBufferWriter & writer,
    const Contact & s)
{
    writer.writeStructBegin(QStringLiteral("Contact"));
    if (s.name.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.name.ref());
        writer.writeFieldEnd();
    }

    if (s.id.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("id"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.id.ref());
        writer.writeFieldEnd();
    }

    if (s.type.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("type"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(s.type.ref()));
        writer.writeFieldEnd();
    }

    if (s.photoUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("photoUrl"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.photoUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.photoLastUpdated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("photoLastUpdated"),
            ThriftFieldType::T_I64,
            5);

        writer.writeI64(s.photoLastUpdated.ref());
        writer.writeFieldEnd();
    }

    if (s.messagingPermit.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("messagingPermit"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeBinary(s.messagingPermit.ref());
        writer.writeFieldEnd();
    }

    if (s.messagingPermitExpires.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("messagingPermitExpires"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(s.messagingPermitExpires.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readContact(
    ThriftBinaryBufferReader & reader,
    Contact & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.name = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.id = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                ContactType v;
                readEnumContactType(reader, v);
                s.type = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.photoUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.photoLastUpdated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                s.messagingPermit = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.messagingPermitExpires = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void Contact::print(QTextStream & strm) const
{
    strm << "Contact: {\n";
    localData.print(strm);

    if (name.isSet()) {
        strm << "    name = "
            << name.ref() << "\n";
    }
    else {
        strm << "    name is not set\n";
    }

    if (id.isSet()) {
        strm << "    id = "
            << id.ref() << "\n";
    }
    else {
        strm << "    id is not set\n";
    }

    if (type.isSet()) {
        strm << "    type = "
            << type.ref() << "\n";
    }
    else {
        strm << "    type is not set\n";
    }

    if (photoUrl.isSet()) {
        strm << "    photoUrl = "
            << photoUrl.ref() << "\n";
    }
    else {
        strm << "    photoUrl is not set\n";
    }

    if (photoLastUpdated.isSet()) {
        strm << "    photoLastUpdated = "
            << photoLastUpdated.ref() << "\n";
    }
    else {
        strm << "    photoLastUpdated is not set\n";
    }

    if (messagingPermit.isSet()) {
        strm << "    messagingPermit = "
            << messagingPermit.ref() << "\n";
    }
    else {
        strm << "    messagingPermit is not set\n";
    }

    if (messagingPermitExpires.isSet()) {
        strm << "    messagingPermitExpires = "
            << messagingPermitExpires.ref() << "\n";
    }
    else {
        strm << "    messagingPermitExpires is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeIdentity(
    ThriftBinaryBufferWriter & writer,
    const Identity & s)
{
    writer.writeStructBegin(QStringLiteral("Identity"));
    writer.writeFieldBegin(
        QStringLiteral("id"),
        ThriftFieldType::T_I64,
        1);

    writer.writeI64(s.id);
    writer.writeFieldEnd();

    if (s.contact.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("contact"),
            ThriftFieldType::T_STRUCT,
            2);

        writeContact(writer, s.contact.ref());
        writer.writeFieldEnd();
    }

    if (s.userId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userId"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(s.userId.ref());
        writer.writeFieldEnd();
    }

    if (s.deactivated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("deactivated"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(s.deactivated.ref());
        writer.writeFieldEnd();
    }

    if (s.sameBusiness.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sameBusiness"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(s.sameBusiness.ref());
        writer.writeFieldEnd();
    }

    if (s.blocked.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("blocked"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(s.blocked.ref());
        writer.writeFieldEnd();
    }

    if (s.userConnected.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userConnected"),
            ThriftFieldType::T_BOOL,
            7);

        writer.writeBool(s.userConnected.ref());
        writer.writeFieldEnd();
    }

    if (s.eventId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("eventId"),
            ThriftFieldType::T_I64,
            8);

        writer.writeI64(s.eventId.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readIdentity(
    ThriftBinaryBufferReader & reader,
    Identity & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool id_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                id_isset = true;
                IdentityID v;
                reader.readI64(v);
                s.id = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Contact v;
                readContact(reader, v);
                s.contact = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.userId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.deactivated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.sameBusiness = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.blocked = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.userConnected = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageEventID v;
                reader.readI64(v);
                s.eventId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!id_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Identity.id has no value"));
}

void Identity::print(QTextStream & strm) const
{
    strm << "Identity: {\n";
    localData.print(strm);
    strm << "    id = "
        << id << "\n";

    if (contact.isSet()) {
        strm << "    contact = "
            << contact.ref() << "\n";
    }
    else {
        strm << "    contact is not set\n";
    }

    if (userId.isSet()) {
        strm << "    userId = "
            << userId.ref() << "\n";
    }
    else {
        strm << "    userId is not set\n";
    }

    if (deactivated.isSet()) {
        strm << "    deactivated = "
            << deactivated.ref() << "\n";
    }
    else {
        strm << "    deactivated is not set\n";
    }

    if (sameBusiness.isSet()) {
        strm << "    sameBusiness = "
            << sameBusiness.ref() << "\n";
    }
    else {
        strm << "    sameBusiness is not set\n";
    }

    if (blocked.isSet()) {
        strm << "    blocked = "
            << blocked.ref() << "\n";
    }
    else {
        strm << "    blocked is not set\n";
    }

    if (userConnected.isSet()) {
        strm << "    userConnected = "
            << userConnected.ref() << "\n";
    }
    else {
        strm << "    userConnected is not set\n";
    }

    if (eventId.isSet()) {
        strm << "    eventId = "
            << eventId.ref() << "\n";
    }
    else {
        strm << "    eventId is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeTag(
    ThriftBinaryBufferWriter & writer,
    const Tag & s)
{
    writer.writeStructBegin(QStringLiteral("Tag"));
    if (s.guid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.guid.ref());
        writer.writeFieldEnd();
    }

    if (s.name.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.name.ref());
        writer.writeFieldEnd();
    }

    if (s.parentGuid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("parentGuid"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(s.parentGuid.ref());
        writer.writeFieldEnd();
    }

    if (s.updateSequenceNum.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            4);

        writer.writeI32(s.updateSequenceNum.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readTag(
    ThriftBinaryBufferReader & reader,
    Tag & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.name = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.parentGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.updateSequenceNum = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void Tag::print(QTextStream & strm) const
{
    strm << "Tag: {\n";
    localData.print(strm);

    if (guid.isSet()) {
        strm << "    guid = "
            << guid.ref() << "\n";
    }
    else {
        strm << "    guid is not set\n";
    }

    if (name.isSet()) {
        strm << "    name = "
            << name.ref() << "\n";
    }
    else {
        strm << "    name is not set\n";
    }

    if (parentGuid.isSet()) {
        strm << "    parentGuid = "
            << parentGuid.ref() << "\n";
    }
    else {
        strm << "    parentGuid is not set\n";
    }

    if (updateSequenceNum.isSet()) {
        strm << "    updateSequenceNum = "
            << updateSequenceNum.ref() << "\n";
    }
    else {
        strm << "    updateSequenceNum is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeLazyMap(
    ThriftBinaryBufferWriter & writer,
    const LazyMap & s)
{
    writer.writeStructBegin(QStringLiteral("LazyMap"));
    if (s.keysOnly.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("keysOnly"),
            ThriftFieldType::T_SET,
            1);

        writer.writeSetBegin(ThriftFieldType::T_STRING, s.keysOnly.ref().count());
        for(const auto & value: qAsConst(s.keysOnly.ref())) {
            writer.writeString(value);
        }
        writer.writeSetEnd();

        writer.writeFieldEnd();
    }

    if (s.fullMap.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("fullMap"),
            ThriftFieldType::T_MAP,
            2);

        writer.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_STRING, s.fullMap.ref().size());
        for(const auto & it: toRange(s.fullMap.ref())) {
            writer.writeString(it.key());
            writer.writeString(it.value());
        }
        writer.writeMapEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readLazyMap(
    ThriftBinaryBufferReader & reader,
    LazyMap & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_SET) {
                QSet<QString> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readSetBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect set type (LazyMap.keysOnly)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.insert(elem);
                }
                reader.readSetEnd();
                s.keysOnly = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap<QString, QString> v;
                qint32 size;
                ThriftFieldType keyType;
                ThriftFieldType elemType;
                reader.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (LazyMap.fullMap)"));
                if (elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (LazyMap.fullMap)"));
                for(qint32 i = 0; i < size; i++) {
                    QString key;
                    reader.readString(key);
                    QString value;
                    reader.readString(value);
                    v[key] = value;
                }
                reader.readMapEnd();
                s.fullMap = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void LazyMap::print(QTextStream & strm) const
{
    strm << "LazyMap: {\n";
    localData.print(strm);

    if (keysOnly.isSet()) {
        strm << "    keysOnly = "
            << "QSet<QString> {";
        for(const auto & v: keysOnly.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    keysOnly is not set\n";
    }

    if (fullMap.isSet()) {
        strm << "    fullMap = "
            << "QMap<QString, QString> {";
        for(const auto & it: toRange(fullMap.ref())) {
            strm << "        [" << it.key() << "] = " << it.value() << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    fullMap is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeResourceAttributes(
    ThriftBinaryBufferWriter & writer,
    const ResourceAttributes & s)
{
    writer.writeStructBegin(QStringLiteral("ResourceAttributes"));
    if (s.sourceURL.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sourceURL"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.sourceURL.ref());
        writer.writeFieldEnd();
    }

    if (s.timestamp.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("timestamp"),
            ThriftFieldType::T_I64,
            2);

        writer.writeI64(s.timestamp.ref());
        writer.writeFieldEnd();
    }

    if (s.latitude.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("latitude"),
            ThriftFieldType::T_DOUBLE,
            3);

        writer.writeDouble(s.latitude.ref());
        writer.writeFieldEnd();
    }

    if (s.longitude.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("longitude"),
            ThriftFieldType::T_DOUBLE,
            4);

        writer.writeDouble(s.longitude.ref());
        writer.writeFieldEnd();
    }

    if (s.altitude.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("altitude"),
            ThriftFieldType::T_DOUBLE,
            5);

        writer.writeDouble(s.altitude.ref());
        writer.writeFieldEnd();
    }

    if (s.cameraMake.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("cameraMake"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(s.cameraMake.ref());
        writer.writeFieldEnd();
    }

    if (s.cameraModel.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("cameraModel"),
            ThriftFieldType::T_STRING,
            7);

        writer.writeString(s.cameraModel.ref());
        writer.writeFieldEnd();
    }

    if (s.clientWillIndex.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("clientWillIndex"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(s.clientWillIndex.ref());
        writer.writeFieldEnd();
    }

    if (s.recoType.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recoType"),
            ThriftFieldType::T_STRING,
            9);

        writer.writeString(s.recoType.ref());
        writer.writeFieldEnd();
    }

    if (s.fileName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("fileName"),
            ThriftFieldType::T_STRING,
            10);

        writer.writeString(s.fileName.ref());
        writer.writeFieldEnd();
    }

    if (s.attachment.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("attachment"),
            ThriftFieldType::T_BOOL,
            11);

        writer.writeBool(s.attachment.ref());
        writer.writeFieldEnd();
    }

    if (s.applicationData.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("applicationData"),
            ThriftFieldType::T_STRUCT,
            12);

        writeLazyMap(writer, s.applicationData.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readResourceAttributes(
    ThriftBinaryBufferReader & reader,
    ResourceAttributes & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.sourceURL = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.timestamp = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.latitude = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.longitude = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.altitude = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.cameraMake = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.cameraModel = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.clientWillIndex = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.recoType = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.fileName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.attachment = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LazyMap v;
                readLazyMap(reader, v);
                s.applicationData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void ResourceAttributes::print(QTextStream & strm) const
{
    strm << "ResourceAttributes: {\n";
    localData.print(strm);

    if (sourceURL.isSet()) {
        strm << "    sourceURL = "
            << sourceURL.ref() << "\n";
    }
    else {
        strm << "    sourceURL is not set\n";
    }

    if (timestamp.isSet()) {
        strm << "    timestamp = "
            << timestamp.ref() << "\n";
    }
    else {
        strm << "    timestamp is not set\n";
    }

    if (latitude.isSet()) {
        strm << "    latitude = "
            << latitude.ref() << "\n";
    }
    else {
        strm << "    latitude is not set\n";
    }

    if (longitude.isSet()) {
        strm << "    longitude = "
            << longitude.ref() << "\n";
    }
    else {
        strm << "    longitude is not set\n";
    }

    if (altitude.isSet()) {
        strm << "    altitude = "
            << altitude.ref() << "\n";
    }
    else {
        strm << "    altitude is not set\n";
    }

    if (cameraMake.isSet()) {
        strm << "    cameraMake = "
            << cameraMake.ref() << "\n";
    }
    else {
        strm << "    cameraMake is not set\n";
    }

    if (cameraModel.isSet()) {
        strm << "    cameraModel = "
            << cameraModel.ref() << "\n";
    }
    else {
        strm << "    cameraModel is not set\n";
    }

    if (clientWillIndex.isSet()) {
        strm << "    clientWillIndex = "
            << clientWillIndex.ref() << "\n";
    }
    else {
        strm << "    clientWillIndex is not set\n";
    }

    if (recoType.isSet()) {
        strm << "    recoType = "
            << recoType.ref() << "\n";
    }
    else {
        strm << "    recoType is not set\n";
    }

    if (fileName.isSet()) {
        strm << "    fileName = "
            << fileName.ref() << "\n";
    }
    else {
        strm << "    fileName is not set\n";
    }

    if (attachment.isSet()) {
        strm << "    attachment = "
            << attachment.ref() << "\n";
    }
    else {
        strm << "    attachment is not set\n";
    }

    if (applicationData.isSet()) {
        strm << "    applicationData = "
            << applicationData.ref() << "\n";
    }
    else {
        strm << "    applicationData is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeResource(
    ThriftBinaryBufferWriter & writer,
    const Resource & s)
{
    writer.writeStructBegin(QStringLiteral("Resource"));
    if (s.guid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.guid.ref());
        writer.writeFieldEnd();
    }

    if (s.noteGuid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noteGuid"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.noteGuid.ref());
        writer.writeFieldEnd();
    }

    if (s.data.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("data"),
            ThriftFieldType::T_STRUCT,
            3);

        writeData(writer, s.data.ref());
        writer.writeFieldEnd();
    }

    if (s.mime.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("mime"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.mime.ref());
        writer.writeFieldEnd();
    }

    if (s.width.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("width"),
            ThriftFieldType::T_I16,
            5);

        writer.writeI16(s.width.ref());
        writer.writeFieldEnd();
    }

    if (s.height.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("height"),
            ThriftFieldType::T_I16,
            6);

        writer.writeI16(s.height.ref());
        writer.writeFieldEnd();
    }

    if (s.duration.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("duration"),
            ThriftFieldType::T_I16,
            7);

        writer.writeI16(s.duration.ref());
        writer.writeFieldEnd();
    }

    if (s.active.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("active"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(s.active.ref());
        writer.writeFieldEnd();
    }

    if (s.recognition.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recognition"),
            ThriftFieldType::T_STRUCT,
            9);

        writeData(writer, s.recognition.ref());
        writer.writeFieldEnd();
    }

    if (s.attributes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            11);

        writeResourceAttributes(writer, s.attributes.ref());
        writer.writeFieldEnd();
    }

    if (s.updateSequenceNum.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            12);

        writer.writeI32(s.updateSequenceNum.ref());
        writer.writeFieldEnd();
    }

    if (s.alternateData.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("alternateData"),
            ThriftFieldType::T_STRUCT,
            13);

        writeData(writer, s.alternateData.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readResource(
    ThriftBinaryBufferReader & reader,
    Resource & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.noteGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Data v;
                readData(reader, v);
                s.data = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.mime = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                reader.readI16(v);
                s.width = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                reader.readI16(v);
                s.height = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                reader.readI16(v);
                s.duration = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.active = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Data v;
                readData(reader, v);
                s.recognition = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                ResourceAttributes v;
                readResourceAttributes(reader, v);
                s.attributes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.updateSequenceNum = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Data v;
                readData(reader, v);
                s.alternateData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void Resource::print(QTextStream & strm) const
{
    strm << "Resource: {\n";
    localData.print(strm);

    if (guid.isSet()) {
        strm << "    guid = "
            << guid.ref() << "\n";
    }
    else {
        strm << "    guid is not set\n";
    }

    if (noteGuid.isSet()) {
        strm << "    noteGuid = "
            << noteGuid.ref() << "\n";
    }
    else {
        strm << "    noteGuid is not set\n";
    }

    if (data.isSet()) {
        strm << "    data = "
            << data.ref() << "\n";
    }
    else {
        strm << "    data is not set\n";
    }

    if (mime.isSet()) {
        strm << "    mime = "
            << mime.ref() << "\n";
    }
    else {
        strm << "    mime is not set\n";
    }

    if (width.isSet()) {
        strm << "    width = "
            << width.ref() << "\n";
    }
    else {
        strm << "    width is not set\n";
    }

    if (height.isSet()) {
        strm << "    height = "
            << height.ref() << "\n";
    }
    else {
        strm << "    height is not set\n";
    }

    if (duration.isSet()) {
        strm << "    duration = "
            << duration.ref() << "\n";
    }
    else {
        strm << "    duration is not set\n";
    }

    if (active.isSet()) {
        strm << "    active = "
            << active.ref() << "\n";
    }
    else {
        strm << "    active is not set\n";
    }

    if (recognition.isSet()) {
        strm << "    recognition = "
            << recognition.ref() << "\n";
    }
    else {
        strm << "    recognition is not set\n";
    }

    if (attributes.isSet()) {
        strm << "    attributes = "
            << attributes.ref() << "\n";
    }
    else {
        strm << "    attributes is not set\n";
    }

    if (updateSequenceNum.isSet()) {
        strm << "    updateSequenceNum = "
            << updateSequenceNum.ref() << "\n";
    }
    else {
        strm << "    updateSequenceNum is not set\n";
    }

    if (alternateData.isSet()) {
        strm << "    alternateData = "
            << alternateData.ref() << "\n";
    }
    else {
        strm << "    alternateData is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteAttributes(
    ThriftBinaryBufferWriter & writer,
    const NoteAttributes & s)
{
    writer.writeStructBegin(QStringLiteral("NoteAttributes"));
    if (s.subjectDate.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("subjectDate"),
            ThriftFieldType::T_I64,
            1);

        writer.writeI64(s.subjectDate.ref());
        writer.writeFieldEnd();
    }

    if (s.latitude.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("latitude"),
            ThriftFieldType::T_DOUBLE,
            10);

        writer.writeDouble(s.latitude.ref());
        writer.writeFieldEnd();
    }

    if (s.longitude.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("longitude"),
            ThriftFieldType::T_DOUBLE,
            11);

        writer.writeDouble(s.longitude.ref());
        writer.writeFieldEnd();
    }

    if (s.altitude.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("altitude"),
            ThriftFieldType::T_DOUBLE,
            12);

        writer.writeDouble(s.altitude.ref());
        writer.writeFieldEnd();
    }

    if (s.author.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("author"),
            ThriftFieldType::T_STRING,
            13);

        writer.writeString(s.author.ref());
        writer.writeFieldEnd();
    }

    if (s.source.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("source"),
            ThriftFieldType::T_STRING,
            14);

        writer.writeString(s.source.ref());
        writer.writeFieldEnd();
    }

    if (s.sourceURL.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sourceURL"),
            ThriftFieldType::T_STRING,
            15);

        writer.writeString(s.sourceURL.ref());
        writer.writeFieldEnd();
    }

    if (s.sourceApplication.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sourceApplication"),
            ThriftFieldType::T_STRING,
            16);

        writer.writeString(s.sourceApplication.ref());
        writer.writeFieldEnd();
    }

    if (s.shareDate.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("shareDate"),
            ThriftFieldType::T_I64,
            17);

        writer.writeI64(s.shareDate.ref());
        writer.writeFieldEnd();
    }

    if (s.reminderOrder.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderOrder"),
            ThriftFieldType::T_I64,
            18);

        writer.writeI64(s.reminderOrder.ref());
        writer.writeFieldEnd();
    }

    if (s.reminderDoneTime.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderDoneTime"),
            ThriftFieldType::T_I64,
            19);

        writer.writeI64(s.reminderDoneTime.ref());
        writer.writeFieldEnd();
    }

    if (s.reminderTime.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderTime"),
            ThriftFieldType::T_I64,
            20);

        writer.writeI64(s.reminderTime.ref());
        writer.writeFieldEnd();
    }

    if (s.placeName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("placeName"),
            ThriftFieldType::T_STRING,
            21);

        writer.writeString(s.placeName.ref());
        writer.writeFieldEnd();
    }

    if (s.contentClass.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("contentClass"),
            ThriftFieldType::T_STRING,
            22);

        writer.writeString(s.contentClass.ref());
        writer.writeFieldEnd();
    }

    if (s.applicationData.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("applicationData"),
            ThriftFieldType::T_STRUCT,
            23);

        writeLazyMap(writer, s.applicationData.ref());
        writer.writeFieldEnd();
    }

    if (s.lastEditedBy.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("lastEditedBy"),
            ThriftFieldType::T_STRING,
            24);

        writer.writeString(s.lastEditedBy.ref());
        writer.writeFieldEnd();
    }

    if (s.classifications.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("classifications"),
            ThriftFieldType::T_MAP,
            26);

        writer.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_STRING, s.classifications.ref().size());
        for(const auto & it: toRange(s.classifications.ref())) {
            writer.writeString(it.key());
            writer.writeString(it.value());
        }
        writer.writeMapEnd();

        writer.writeFieldEnd();
    }

    if (s.creatorId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("creatorId"),
            ThriftFieldType::T_I32,
            27);

        writer.writeI32(s.creatorId.ref());
        writer.writeFieldEnd();
    }

    if (s.lastEditorId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("lastEditorId"),
            ThriftFieldType::T_I32,
            28);

        writer.writeI32(s.lastEditorId.ref());
        writer.writeFieldEnd();
    }

    if (s.sharedWithBusiness.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sharedWithBusiness"),
            ThriftFieldType::T_BOOL,
            29);

        writer.writeBool(s.sharedWithBusiness.ref());
        writer.writeFieldEnd();
    }

    if (s.conflictSourceNoteGuid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("conflictSourceNoteGuid"),
            ThriftFieldType::T_STRING,
            30);

        writer.writeString(s.conflictSourceNoteGuid.ref());
        writer.writeFieldEnd();
    }

    if (s.noteTitleQuality.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noteTitleQuality"),
            ThriftFieldType::T_I32,
            31);

        writer.writeI32(s.noteTitleQuality.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteAttributes(
    ThriftBinaryBufferReader & reader,
    NoteAttributes & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.subjectDate = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.latitude = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.longitude = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.altitude = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.author = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.source = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.sourceURL = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.sourceApplication = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.shareDate = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.reminderOrder = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.reminderDoneTime = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.reminderTime = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.placeName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.contentClass = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LazyMap v;
                readLazyMap(reader, v);
                s.applicationData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.lastEditedBy = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 26) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap<QString, QString> v;
                qint32 size;
                ThriftFieldType keyType;
                ThriftFieldType elemType;
                reader.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (NoteAttributes.classifications)"));
                if (elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (NoteAttributes.classifications)"));
                for(qint32 i = 0; i < size; i++) {
                    QString key;
                    reader.readString(key);
                    QString value;
                    reader.readString(value);
                    v[key] = value;
                }
                reader.readMapEnd();
                s.classifications = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 27) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.creatorId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 28) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.lastEditorId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 29) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.sharedWithBusiness = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 30) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.conflictSourceNoteGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 31) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.noteTitleQuality = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NoteAttributes::print(QTextStream & strm) const
{
    strm << "NoteAttributes: {\n";
    localData.print(strm);

    if (subjectDate.isSet()) {
        strm << "    subjectDate = "
            << subjectDate.ref() << "\n";
    }
    else {
        strm << "    subjectDate is not set\n";
    }

    if (latitude.isSet()) {
        strm << "    latitude = "
            << latitude.ref() << "\n";
    }
    else {
        strm << "    latitude is not set\n";
    }

    if (longitude.isSet()) {
        strm << "    longitude = "
            << longitude.ref() << "\n";
    }
    else {
        strm << "    longitude is not set\n";
    }

    if (altitude.isSet()) {
        strm << "    altitude = "
            << altitude.ref() << "\n";
    }
    else {
        strm << "    altitude is not set\n";
    }

    if (author.isSet()) {
        strm << "    author = "
            << author.ref() << "\n";
    }
    else {
        strm << "    author is not set\n";
    }

    if (source.isSet()) {
        strm << "    source = "
            << source.ref() << "\n";
    }
    else {
        strm << "    source is not set\n";
    }

    if (sourceURL.isSet()) {
        strm << "    sourceURL = "
            << sourceURL.ref() << "\n";
    }
    else {
        strm << "    sourceURL is not set\n";
    }

    if (sourceApplication.isSet()) {
        strm << "    sourceApplication = "
            << sourceApplication.ref() << "\n";
    }
    else {
        strm << "    sourceApplication is not set\n";
    }

    if (shareDate.isSet()) {
        strm << "    shareDate = "
            << shareDate.ref() << "\n";
    }
    else {
        strm << "    shareDate is not set\n";
    }

    if (reminderOrder.isSet()) {
        strm << "    reminderOrder = "
            << reminderOrder.ref() << "\n";
    }
    else {
        strm << "    reminderOrder is not set\n";
    }

    if (reminderDoneTime.isSet()) {
        strm << "    reminderDoneTime = "
            << reminderDoneTime.ref() << "\n";
    }
    else {
        strm << "    reminderDoneTime is not set\n";
    }

    if (reminderTime.isSet()) {
        strm << "    reminderTime = "
            << reminderTime.ref() << "\n";
    }
    else {
        strm << "    reminderTime is not set\n";
    }

    if (placeName.isSet()) {
        strm << "    placeName = "
            << placeName.ref() << "\n";
    }
    else {
        strm << "    placeName is not set\n";
    }

    if (contentClass.isSet()) {
        strm << "    contentClass = "
            << contentClass.ref() << "\n";
    }
    else {
        strm << "    contentClass is not set\n";
    }

    if (applicationData.isSet()) {
        strm << "    applicationData = "
            << applicationData.ref() << "\n";
    }
    else {
        strm << "    applicationData is not set\n";
    }

    if (lastEditedBy.isSet()) {
        strm << "    lastEditedBy = "
            << lastEditedBy.ref() << "\n";
    }
    else {
        strm << "    lastEditedBy is not set\n";
    }

    if (classifications.isSet()) {
        strm << "    classifications = "
            << "QMap<QString, QString> {";
        for(const auto & it: toRange(classifications.ref())) {
            strm << "        [" << it.key() << "] = " << it.value() << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    classifications is not set\n";
    }

    if (creatorId.isSet()) {
        strm << "    creatorId = "
            << creatorId.ref() << "\n";
    }
    else {
        strm << "    creatorId is not set\n";
    }

    if (lastEditorId.isSet()) {
        strm << "    lastEditorId = "
            << lastEditorId.ref() << "\n";
    }
    else {
        strm << "    lastEditorId is not set\n";
    }

    if (sharedWithBusiness.isSet()) {
        strm << "    sharedWithBusiness = "
            << sharedWithBusiness.ref() << "\n";
    }
    else {
        strm << "    sharedWithBusiness is not set\n";
    }

    if (conflictSourceNoteGuid.isSet()) {
        strm << "    conflictSourceNoteGuid = "
            << conflictSourceNoteGuid.ref() << "\n";
    }
    else {
        strm << "    conflictSourceNoteGuid is not set\n";
    }

    if (noteTitleQuality.isSet()) {
        strm << "    noteTitleQuality = "
            << noteTitleQuality.ref() << "\n";
    }
    else {
        strm << "    noteTitleQuality is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeSharedNote(
    ThriftBinaryBufferWriter & writer,
    const SharedNote & s)
{
    writer.writeStructBegin(QStringLiteral("SharedNote"));
    if (s.sharerUserID.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sharerUserID"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(s.sharerUserID.ref());
        writer.writeFieldEnd();
    }

    if (s.recipientIdentity.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientIdentity"),
            ThriftFieldType::T_STRUCT,
            2);

        writeIdentity(writer, s.recipientIdentity.ref());
        writer.writeFieldEnd();
    }

    if (s.privilege.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(s.privilege.ref()));
        writer.writeFieldEnd();
    }

    if (s.serviceCreated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceCreated"),
            ThriftFieldType::T_I64,
            4);

        writer.writeI64(s.serviceCreated.ref());
        writer.writeFieldEnd();
    }

    if (s.serviceUpdated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceUpdated"),
            ThriftFieldType::T_I64,
            5);

        writer.writeI64(s.serviceUpdated.ref());
        writer.writeFieldEnd();
    }

    if (s.serviceAssigned.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceAssigned"),
            ThriftFieldType::T_I64,
            6);

        writer.writeI64(s.serviceAssigned.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSharedNote(
    ThriftBinaryBufferReader & reader,
    SharedNote & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.sharerUserID = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Identity v;
                readIdentity(reader, v);
                s.recipientIdentity = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel v;
                readEnumSharedNotePrivilegeLevel(reader, v);
                s.privilege = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.serviceCreated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.serviceUpdated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.serviceAssigned = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void SharedNote::print(QTextStream & strm) const
{
    strm << "SharedNote: {\n";
    localData.print(strm);

    if (sharerUserID.isSet()) {
        strm << "    sharerUserID = "
            << sharerUserID.ref() << "\n";
    }
    else {
        strm << "    sharerUserID is not set\n";
    }

    if (recipientIdentity.isSet()) {
        strm << "    recipientIdentity = "
            << recipientIdentity.ref() << "\n";
    }
    else {
        strm << "    recipientIdentity is not set\n";
    }

    if (privilege.isSet()) {
        strm << "    privilege = "
            << privilege.ref() << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    if (serviceCreated.isSet()) {
        strm << "    serviceCreated = "
            << serviceCreated.ref() << "\n";
    }
    else {
        strm << "    serviceCreated is not set\n";
    }

    if (serviceUpdated.isSet()) {
        strm << "    serviceUpdated = "
            << serviceUpdated.ref() << "\n";
    }
    else {
        strm << "    serviceUpdated is not set\n";
    }

    if (serviceAssigned.isSet()) {
        strm << "    serviceAssigned = "
            << serviceAssigned.ref() << "\n";
    }
    else {
        strm << "    serviceAssigned is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteRestrictions(
    ThriftBinaryBufferWriter & writer,
    const NoteRestrictions & s)
{
    writer.writeStructBegin(QStringLiteral("NoteRestrictions"));
    if (s.noUpdateTitle.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noUpdateTitle"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(s.noUpdateTitle.ref());
        writer.writeFieldEnd();
    }

    if (s.noUpdateContent.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noUpdateContent"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(s.noUpdateContent.ref());
        writer.writeFieldEnd();
    }

    if (s.noEmail.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noEmail"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(s.noEmail.ref());
        writer.writeFieldEnd();
    }

    if (s.noShare.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noShare"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(s.noShare.ref());
        writer.writeFieldEnd();
    }

    if (s.noSharePublicly.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSharePublicly"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(s.noSharePublicly.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteRestrictions(
    ThriftBinaryBufferReader & reader,
    NoteRestrictions & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noUpdateTitle = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noUpdateContent = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noEmail = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noShare = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSharePublicly = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NoteRestrictions::print(QTextStream & strm) const
{
    strm << "NoteRestrictions: {\n";
    localData.print(strm);

    if (noUpdateTitle.isSet()) {
        strm << "    noUpdateTitle = "
            << noUpdateTitle.ref() << "\n";
    }
    else {
        strm << "    noUpdateTitle is not set\n";
    }

    if (noUpdateContent.isSet()) {
        strm << "    noUpdateContent = "
            << noUpdateContent.ref() << "\n";
    }
    else {
        strm << "    noUpdateContent is not set\n";
    }

    if (noEmail.isSet()) {
        strm << "    noEmail = "
            << noEmail.ref() << "\n";
    }
    else {
        strm << "    noEmail is not set\n";
    }

    if (noShare.isSet()) {
        strm << "    noShare = "
            << noShare.ref() << "\n";
    }
    else {
        strm << "    noShare is not set\n";
    }

    if (noSharePublicly.isSet()) {
        strm << "    noSharePublicly = "
            << noSharePublicly.ref() << "\n";
    }
    else {
        strm << "    noSharePublicly is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNoteLimits(
    ThriftBinaryBufferWriter & writer,
    const NoteLimits & s)
{
    writer.writeStructBegin(QStringLiteral("NoteLimits"));
    if (s.noteResourceCountMax.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noteResourceCountMax"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(s.noteResourceCountMax.ref());
        writer.writeFieldEnd();
    }

    if (s.uploadLimit.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("uploadLimit"),
            ThriftFieldType::T_I64,
            2);

        writer.writeI64(s.uploadLimit.ref());
        writer.writeFieldEnd();
    }

    if (s.resourceSizeMax.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("resourceSizeMax"),
            ThriftFieldType::T_I64,
            3);

        writer.writeI64(s.resourceSizeMax.ref());
        writer.writeFieldEnd();
    }

    if (s.noteSizeMax.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noteSizeMax"),
            ThriftFieldType::T_I64,
            4);

        writer.writeI64(s.noteSizeMax.ref());
        writer.writeFieldEnd();
    }

    if (s.uploaded.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("uploaded"),
            ThriftFieldType::T_I64,
            5);

        writer.writeI64(s.uploaded.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNoteLimits(
    ThriftBinaryBufferReader & reader,
    NoteLimits & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.noteResourceCountMax = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.uploadLimit = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.resourceSizeMax = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.noteSizeMax = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.uploaded = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NoteLimits::print(QTextStream & strm) const
{
    strm << "NoteLimits: {\n";
    localData.print(strm);

    if (noteResourceCountMax.isSet()) {
        strm << "    noteResourceCountMax = "
            << noteResourceCountMax.ref() << "\n";
    }
    else {
        strm << "    noteResourceCountMax is not set\n";
    }

    if (uploadLimit.isSet()) {
        strm << "    uploadLimit = "
            << uploadLimit.ref() << "\n";
    }
    else {
        strm << "    uploadLimit is not set\n";
    }

    if (resourceSizeMax.isSet()) {
        strm << "    resourceSizeMax = "
            << resourceSizeMax.ref() << "\n";
    }
    else {
        strm << "    resourceSizeMax is not set\n";
    }

    if (noteSizeMax.isSet()) {
        strm << "    noteSizeMax = "
            << noteSizeMax.ref() << "\n";
    }
    else {
        strm << "    noteSizeMax is not set\n";
    }

    if (uploaded.isSet()) {
        strm << "    uploaded = "
            << uploaded.ref() << "\n";
    }
    else {
        strm << "    uploaded is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNote(
    ThriftBinaryBufferWriter & writer,
    const Note & s)
{
    writer.writeStructBegin(QStringLiteral("Note"));
    if (s.guid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.guid.ref());
        writer.writeFieldEnd();
    }

    if (s.title.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("title"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.title.ref());
        writer.writeFieldEnd();
    }

    if (s.content.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("content"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(s.content.ref());
        writer.writeFieldEnd();
    }

    if (s.contentHash.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("contentHash"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeBinary(s.contentHash.ref());
        writer.writeFieldEnd();
    }

    if (s.contentLength.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("contentLength"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(s.contentLength.ref());
        writer.writeFieldEnd();
    }

    if (s.created.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("created"),
            ThriftFieldType::T_I64,
            6);

        writer.writeI64(s.created.ref());
        writer.writeFieldEnd();
    }

    if (s.updated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updated"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(s.updated.ref());
        writer.writeFieldEnd();
    }

    if (s.deleted.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("deleted"),
            ThriftFieldType::T_I64,
            8);

        writer.writeI64(s.deleted.ref());
        writer.writeFieldEnd();
    }

    if (s.active.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("active"),
            ThriftFieldType::T_BOOL,
            9);

        writer.writeBool(s.active.ref());
        writer.writeFieldEnd();
    }

    if (s.updateSequenceNum.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            10);

        writer.writeI32(s.updateSequenceNum.ref());
        writer.writeFieldEnd();
    }

    if (s.notebookGuid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            11);

        writer.writeString(s.notebookGuid.ref());
        writer.writeFieldEnd();
    }

    if (s.tagGuids.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("tagGuids"),
            ThriftFieldType::T_LIST,
            12);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.tagGuids.ref().length());
        for(const auto & value: qAsConst(s.tagGuids.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.resources.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("resources"),
            ThriftFieldType::T_LIST,
            13);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.resources.ref().length());
        for(const auto & value: qAsConst(s.resources.ref())) {
            writeResource(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.attributes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            14);

        writeNoteAttributes(writer, s.attributes.ref());
        writer.writeFieldEnd();
    }

    if (s.tagNames.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("tagNames"),
            ThriftFieldType::T_LIST,
            15);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.tagNames.ref().length());
        for(const auto & value: qAsConst(s.tagNames.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.sharedNotes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sharedNotes"),
            ThriftFieldType::T_LIST,
            16);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.sharedNotes.ref().length());
        for(const auto & value: qAsConst(s.sharedNotes.ref())) {
            writeSharedNote(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.restrictions.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("restrictions"),
            ThriftFieldType::T_STRUCT,
            17);

        writeNoteRestrictions(writer, s.restrictions.ref());
        writer.writeFieldEnd();
    }

    if (s.limits.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("limits"),
            ThriftFieldType::T_STRUCT,
            18);

        writeNoteLimits(writer, s.limits.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNote(
    ThriftBinaryBufferReader & reader,
    Note & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.title = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.content = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                s.contentHash = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.contentLength = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.created = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.updated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.deleted = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.active = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.updateSequenceNum = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.notebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Guid> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (Note.tagGuids)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.tagGuids = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<Resource> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (Note.resources)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Resource elem;
                    readResource(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.resources = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteAttributes v;
                readNoteAttributes(reader, v);
                s.attributes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (Note.tagNames)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.tagNames = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<SharedNote> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (Note.sharedNotes)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    SharedNote elem;
                    readSharedNote(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.sharedNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteRestrictions v;
                readNoteRestrictions(reader, v);
                s.restrictions = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteLimits v;
                readNoteLimits(reader, v);
                s.limits = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void Note::print(QTextStream & strm) const
{
    strm << "Note: {\n";
    localData.print(strm);

    if (guid.isSet()) {
        strm << "    guid = "
            << guid.ref() << "\n";
    }
    else {
        strm << "    guid is not set\n";
    }

    if (title.isSet()) {
        strm << "    title = "
            << title.ref() << "\n";
    }
    else {
        strm << "    title is not set\n";
    }

    if (content.isSet()) {
        strm << "    content = "
            << content.ref() << "\n";
    }
    else {
        strm << "    content is not set\n";
    }

    if (contentHash.isSet()) {
        strm << "    contentHash = "
            << contentHash.ref() << "\n";
    }
    else {
        strm << "    contentHash is not set\n";
    }

    if (contentLength.isSet()) {
        strm << "    contentLength = "
            << contentLength.ref() << "\n";
    }
    else {
        strm << "    contentLength is not set\n";
    }

    if (created.isSet()) {
        strm << "    created = "
            << created.ref() << "\n";
    }
    else {
        strm << "    created is not set\n";
    }

    if (updated.isSet()) {
        strm << "    updated = "
            << updated.ref() << "\n";
    }
    else {
        strm << "    updated is not set\n";
    }

    if (deleted.isSet()) {
        strm << "    deleted = "
            << deleted.ref() << "\n";
    }
    else {
        strm << "    deleted is not set\n";
    }

    if (active.isSet()) {
        strm << "    active = "
            << active.ref() << "\n";
    }
    else {
        strm << "    active is not set\n";
    }

    if (updateSequenceNum.isSet()) {
        strm << "    updateSequenceNum = "
            << updateSequenceNum.ref() << "\n";
    }
    else {
        strm << "    updateSequenceNum is not set\n";
    }

    if (notebookGuid.isSet()) {
        strm << "    notebookGuid = "
            << notebookGuid.ref() << "\n";
    }
    else {
        strm << "    notebookGuid is not set\n";
    }

    if (tagGuids.isSet()) {
        strm << "    tagGuids = "
            << "QList<Guid> {";
        for(const auto & v: tagGuids.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    tagGuids is not set\n";
    }

    if (resources.isSet()) {
        strm << "    resources = "
            << "QList<Resource> {";
        for(const auto & v: resources.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    resources is not set\n";
    }

    if (attributes.isSet()) {
        strm << "    attributes = "
            << attributes.ref() << "\n";
    }
    else {
        strm << "    attributes is not set\n";
    }

    if (tagNames.isSet()) {
        strm << "    tagNames = "
            << "QList<QString> {";
        for(const auto & v: tagNames.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    tagNames is not set\n";
    }

    if (sharedNotes.isSet()) {
        strm << "    sharedNotes = "
            << "QList<SharedNote> {";
        for(const auto & v: sharedNotes.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    sharedNotes is not set\n";
    }

    if (restrictions.isSet()) {
        strm << "    restrictions = "
            << restrictions.ref() << "\n";
    }
    else {
        strm << "    restrictions is not set\n";
    }

    if (limits.isSet()) {
        strm << "    limits = "
            << limits.ref() << "\n";
    }
    else {
        strm << "    limits is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writePublishing(
    ThriftBinaryBufferWriter & writer,
    const Publishing & s)
{
    writer.writeStructBegin(QStringLiteral("Publishing"));
    if (s.uri.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("uri"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.uri.ref());
        writer.writeFieldEnd();
    }

    if (s.order.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("order"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(static_cast<qint32>(s.order.ref()));
        writer.writeFieldEnd();
    }

    if (s.ascending.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("ascending"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(s.ascending.ref());
        writer.writeFieldEnd();
    }

    if (s.publicDescription.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("publicDescription"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.publicDescription.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readPublishing(
    ThriftBinaryBufferReader & reader,
    Publishing & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.uri = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                NoteSortOrder v;
                readEnumNoteSortOrder(reader, v);
                s.order = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.ascending = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.publicDescription = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void Publishing::print(QTextStream & strm) const
{
    strm << "Publishing: {\n";
    localData.print(strm);

    if (uri.isSet()) {
        strm << "    uri = "
            << uri.ref() << "\n";
    }
    else {
        strm << "    uri is not set\n";
    }

    if (order.isSet()) {
        strm << "    order = "
            << order.ref() << "\n";
    }
    else {
        strm << "    order is not set\n";
    }

    if (ascending.isSet()) {
        strm << "    ascending = "
            << ascending.ref() << "\n";
    }
    else {
        strm << "    ascending is not set\n";
    }

    if (publicDescription.isSet()) {
        strm << "    publicDescription = "
            << publicDescription.ref() << "\n";
    }
    else {
        strm << "    publicDescription is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeBusinessNotebook(
    ThriftBinaryBufferWriter & writer,
    const BusinessNotebook & s)
{
    writer.writeStructBegin(QStringLiteral("BusinessNotebook"));
    if (s.notebookDescription.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookDescription"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.notebookDescription.ref());
        writer.writeFieldEnd();
    }

    if (s.privilege.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(static_cast<qint32>(s.privilege.ref()));
        writer.writeFieldEnd();
    }

    if (s.recommended.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recommended"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(s.recommended.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readBusinessNotebook(
    ThriftBinaryBufferReader & reader,
    BusinessNotebook & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.notebookDescription = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookPrivilegeLevel v;
                readEnumSharedNotebookPrivilegeLevel(reader, v);
                s.privilege = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.recommended = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void BusinessNotebook::print(QTextStream & strm) const
{
    strm << "BusinessNotebook: {\n";
    localData.print(strm);

    if (notebookDescription.isSet()) {
        strm << "    notebookDescription = "
            << notebookDescription.ref() << "\n";
    }
    else {
        strm << "    notebookDescription is not set\n";
    }

    if (privilege.isSet()) {
        strm << "    privilege = "
            << privilege.ref() << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    if (recommended.isSet()) {
        strm << "    recommended = "
            << recommended.ref() << "\n";
    }
    else {
        strm << "    recommended is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeSavedSearchScope(
    ThriftBinaryBufferWriter & writer,
    const SavedSearchScope & s)
{
    writer.writeStructBegin(QStringLiteral("SavedSearchScope"));
    if (s.includeAccount.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeAccount"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(s.includeAccount.ref());
        writer.writeFieldEnd();
    }

    if (s.includePersonalLinkedNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includePersonalLinkedNotebooks"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(s.includePersonalLinkedNotebooks.ref());
        writer.writeFieldEnd();
    }

    if (s.includeBusinessLinkedNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("includeBusinessLinkedNotebooks"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(s.includeBusinessLinkedNotebooks.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSavedSearchScope(
    ThriftBinaryBufferReader & reader,
    SavedSearchScope & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeAccount = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includePersonalLinkedNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.includeBusinessLinkedNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void SavedSearchScope::print(QTextStream & strm) const
{
    strm << "SavedSearchScope: {\n";
    localData.print(strm);

    if (includeAccount.isSet()) {
        strm << "    includeAccount = "
            << includeAccount.ref() << "\n";
    }
    else {
        strm << "    includeAccount is not set\n";
    }

    if (includePersonalLinkedNotebooks.isSet()) {
        strm << "    includePersonalLinkedNotebooks = "
            << includePersonalLinkedNotebooks.ref() << "\n";
    }
    else {
        strm << "    includePersonalLinkedNotebooks is not set\n";
    }

    if (includeBusinessLinkedNotebooks.isSet()) {
        strm << "    includeBusinessLinkedNotebooks = "
            << includeBusinessLinkedNotebooks.ref() << "\n";
    }
    else {
        strm << "    includeBusinessLinkedNotebooks is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeSavedSearch(
    ThriftBinaryBufferWriter & writer,
    const SavedSearch & s)
{
    writer.writeStructBegin(QStringLiteral("SavedSearch"));
    if (s.guid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.guid.ref());
        writer.writeFieldEnd();
    }

    if (s.name.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.name.ref());
        writer.writeFieldEnd();
    }

    if (s.query.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("query"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(s.query.ref());
        writer.writeFieldEnd();
    }

    if (s.format.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("format"),
            ThriftFieldType::T_I32,
            4);

        writer.writeI32(static_cast<qint32>(s.format.ref()));
        writer.writeFieldEnd();
    }

    if (s.updateSequenceNum.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(s.updateSequenceNum.ref());
        writer.writeFieldEnd();
    }

    if (s.scope.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("scope"),
            ThriftFieldType::T_STRUCT,
            6);

        writeSavedSearchScope(writer, s.scope.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSavedSearch(
    ThriftBinaryBufferReader & reader,
    SavedSearch & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.name = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.query = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                QueryFormat v;
                readEnumQueryFormat(reader, v);
                s.format = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.updateSequenceNum = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SavedSearchScope v;
                readSavedSearchScope(reader, v);
                s.scope = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void SavedSearch::print(QTextStream & strm) const
{
    strm << "SavedSearch: {\n";
    localData.print(strm);

    if (guid.isSet()) {
        strm << "    guid = "
            << guid.ref() << "\n";
    }
    else {
        strm << "    guid is not set\n";
    }

    if (name.isSet()) {
        strm << "    name = "
            << name.ref() << "\n";
    }
    else {
        strm << "    name is not set\n";
    }

    if (query.isSet()) {
        strm << "    query = "
            << query.ref() << "\n";
    }
    else {
        strm << "    query is not set\n";
    }

    if (format.isSet()) {
        strm << "    format = "
            << format.ref() << "\n";
    }
    else {
        strm << "    format is not set\n";
    }

    if (updateSequenceNum.isSet()) {
        strm << "    updateSequenceNum = "
            << updateSequenceNum.ref() << "\n";
    }
    else {
        strm << "    updateSequenceNum is not set\n";
    }

    if (scope.isSet()) {
        strm << "    scope = "
            << scope.ref() << "\n";
    }
    else {
        strm << "    scope is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeSharedNotebookRecipientSettings(
    ThriftBinaryBufferWriter & writer,
    const SharedNotebookRecipientSettings & s)
{
    writer.writeStructBegin(QStringLiteral("SharedNotebookRecipientSettings"));
    if (s.reminderNotifyEmail.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderNotifyEmail"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(s.reminderNotifyEmail.ref());
        writer.writeFieldEnd();
    }

    if (s.reminderNotifyInApp.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderNotifyInApp"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(s.reminderNotifyInApp.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSharedNotebookRecipientSettings(
    ThriftBinaryBufferReader & reader,
    SharedNotebookRecipientSettings & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.reminderNotifyEmail = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.reminderNotifyInApp = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void SharedNotebookRecipientSettings::print(QTextStream & strm) const
{
    strm << "SharedNotebookRecipientSettings: {\n";
    localData.print(strm);

    if (reminderNotifyEmail.isSet()) {
        strm << "    reminderNotifyEmail = "
            << reminderNotifyEmail.ref() << "\n";
    }
    else {
        strm << "    reminderNotifyEmail is not set\n";
    }

    if (reminderNotifyInApp.isSet()) {
        strm << "    reminderNotifyInApp = "
            << reminderNotifyInApp.ref() << "\n";
    }
    else {
        strm << "    reminderNotifyInApp is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNotebookRecipientSettings(
    ThriftBinaryBufferWriter & writer,
    const NotebookRecipientSettings & s)
{
    writer.writeStructBegin(QStringLiteral("NotebookRecipientSettings"));
    if (s.reminderNotifyEmail.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderNotifyEmail"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(s.reminderNotifyEmail.ref());
        writer.writeFieldEnd();
    }

    if (s.reminderNotifyInApp.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("reminderNotifyInApp"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(s.reminderNotifyInApp.ref());
        writer.writeFieldEnd();
    }

    if (s.inMyList.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("inMyList"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(s.inMyList.ref());
        writer.writeFieldEnd();
    }

    if (s.stack.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("stack"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.stack.ref());
        writer.writeFieldEnd();
    }

    if (s.recipientStatus.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientStatus"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(static_cast<qint32>(s.recipientStatus.ref()));
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNotebookRecipientSettings(
    ThriftBinaryBufferReader & reader,
    NotebookRecipientSettings & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.reminderNotifyEmail = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.reminderNotifyInApp = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.inMyList = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.stack = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                RecipientStatus v;
                readEnumRecipientStatus(reader, v);
                s.recipientStatus = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NotebookRecipientSettings::print(QTextStream & strm) const
{
    strm << "NotebookRecipientSettings: {\n";
    localData.print(strm);

    if (reminderNotifyEmail.isSet()) {
        strm << "    reminderNotifyEmail = "
            << reminderNotifyEmail.ref() << "\n";
    }
    else {
        strm << "    reminderNotifyEmail is not set\n";
    }

    if (reminderNotifyInApp.isSet()) {
        strm << "    reminderNotifyInApp = "
            << reminderNotifyInApp.ref() << "\n";
    }
    else {
        strm << "    reminderNotifyInApp is not set\n";
    }

    if (inMyList.isSet()) {
        strm << "    inMyList = "
            << inMyList.ref() << "\n";
    }
    else {
        strm << "    inMyList is not set\n";
    }

    if (stack.isSet()) {
        strm << "    stack = "
            << stack.ref() << "\n";
    }
    else {
        strm << "    stack is not set\n";
    }

    if (recipientStatus.isSet()) {
        strm << "    recipientStatus = "
            << recipientStatus.ref() << "\n";
    }
    else {
        strm << "    recipientStatus is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeSharedNotebook(
    ThriftBinaryBufferWriter & writer,
    const SharedNotebook & s)
{
    writer.writeStructBegin(QStringLiteral("SharedNotebook"));
    if (s.id.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("id"),
            ThriftFieldType::T_I64,
            1);

        writer.writeI64(s.id.ref());
        writer.writeFieldEnd();
    }

    if (s.userId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userId"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(s.userId.ref());
        writer.writeFieldEnd();
    }

    if (s.notebookGuid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookGuid"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(s.notebookGuid.ref());
        writer.writeFieldEnd();
    }

    if (s.email.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.email.ref());
        writer.writeFieldEnd();
    }

    if (s.recipientIdentityId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientIdentityId"),
            ThriftFieldType::T_I64,
            18);

        writer.writeI64(s.recipientIdentityId.ref());
        writer.writeFieldEnd();
    }

    if (s.notebookModifiable.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookModifiable"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(s.notebookModifiable.ref());
        writer.writeFieldEnd();
    }

    if (s.serviceCreated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceCreated"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(s.serviceCreated.ref());
        writer.writeFieldEnd();
    }

    if (s.serviceUpdated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceUpdated"),
            ThriftFieldType::T_I64,
            10);

        writer.writeI64(s.serviceUpdated.ref());
        writer.writeFieldEnd();
    }

    if (s.globalId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("globalId"),
            ThriftFieldType::T_STRING,
            8);

        writer.writeString(s.globalId.ref());
        writer.writeFieldEnd();
    }

    if (s.username.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            9);

        writer.writeString(s.username.ref());
        writer.writeFieldEnd();
    }

    if (s.privilege.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("privilege"),
            ThriftFieldType::T_I32,
            11);

        writer.writeI32(static_cast<qint32>(s.privilege.ref()));
        writer.writeFieldEnd();
    }

    if (s.recipientSettings.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientSettings"),
            ThriftFieldType::T_STRUCT,
            13);

        writeSharedNotebookRecipientSettings(writer, s.recipientSettings.ref());
        writer.writeFieldEnd();
    }

    if (s.sharerUserId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sharerUserId"),
            ThriftFieldType::T_I32,
            14);

        writer.writeI32(s.sharerUserId.ref());
        writer.writeFieldEnd();
    }

    if (s.recipientUsername.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientUsername"),
            ThriftFieldType::T_STRING,
            15);

        writer.writeString(s.recipientUsername.ref());
        writer.writeFieldEnd();
    }

    if (s.recipientUserId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientUserId"),
            ThriftFieldType::T_I32,
            17);

        writer.writeI32(s.recipientUserId.ref());
        writer.writeFieldEnd();
    }

    if (s.serviceAssigned.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceAssigned"),
            ThriftFieldType::T_I64,
            16);

        writer.writeI64(s.serviceAssigned.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readSharedNotebook(
    ThriftBinaryBufferReader & reader,
    SharedNotebook & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.id = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.userId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.notebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.email = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_I64) {
                IdentityID v;
                reader.readI64(v);
                s.recipientIdentityId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.notebookModifiable = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.serviceCreated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.serviceUpdated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.globalId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.username = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookPrivilegeLevel v;
                readEnumSharedNotebookPrivilegeLevel(reader, v);
                s.privilege = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SharedNotebookRecipientSettings v;
                readSharedNotebookRecipientSettings(reader, v);
                s.recipientSettings = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.sharerUserId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.recipientUsername = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.recipientUserId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.serviceAssigned = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void SharedNotebook::print(QTextStream & strm) const
{
    strm << "SharedNotebook: {\n";
    localData.print(strm);

    if (id.isSet()) {
        strm << "    id = "
            << id.ref() << "\n";
    }
    else {
        strm << "    id is not set\n";
    }

    if (userId.isSet()) {
        strm << "    userId = "
            << userId.ref() << "\n";
    }
    else {
        strm << "    userId is not set\n";
    }

    if (notebookGuid.isSet()) {
        strm << "    notebookGuid = "
            << notebookGuid.ref() << "\n";
    }
    else {
        strm << "    notebookGuid is not set\n";
    }

    if (email.isSet()) {
        strm << "    email = "
            << email.ref() << "\n";
    }
    else {
        strm << "    email is not set\n";
    }

    if (recipientIdentityId.isSet()) {
        strm << "    recipientIdentityId = "
            << recipientIdentityId.ref() << "\n";
    }
    else {
        strm << "    recipientIdentityId is not set\n";
    }

    if (notebookModifiable.isSet()) {
        strm << "    notebookModifiable = "
            << notebookModifiable.ref() << "\n";
    }
    else {
        strm << "    notebookModifiable is not set\n";
    }

    if (serviceCreated.isSet()) {
        strm << "    serviceCreated = "
            << serviceCreated.ref() << "\n";
    }
    else {
        strm << "    serviceCreated is not set\n";
    }

    if (serviceUpdated.isSet()) {
        strm << "    serviceUpdated = "
            << serviceUpdated.ref() << "\n";
    }
    else {
        strm << "    serviceUpdated is not set\n";
    }

    if (globalId.isSet()) {
        strm << "    globalId = "
            << globalId.ref() << "\n";
    }
    else {
        strm << "    globalId is not set\n";
    }

    if (username.isSet()) {
        strm << "    username = "
            << username.ref() << "\n";
    }
    else {
        strm << "    username is not set\n";
    }

    if (privilege.isSet()) {
        strm << "    privilege = "
            << privilege.ref() << "\n";
    }
    else {
        strm << "    privilege is not set\n";
    }

    if (recipientSettings.isSet()) {
        strm << "    recipientSettings = "
            << recipientSettings.ref() << "\n";
    }
    else {
        strm << "    recipientSettings is not set\n";
    }

    if (sharerUserId.isSet()) {
        strm << "    sharerUserId = "
            << sharerUserId.ref() << "\n";
    }
    else {
        strm << "    sharerUserId is not set\n";
    }

    if (recipientUsername.isSet()) {
        strm << "    recipientUsername = "
            << recipientUsername.ref() << "\n";
    }
    else {
        strm << "    recipientUsername is not set\n";
    }

    if (recipientUserId.isSet()) {
        strm << "    recipientUserId = "
            << recipientUserId.ref() << "\n";
    }
    else {
        strm << "    recipientUserId is not set\n";
    }

    if (serviceAssigned.isSet()) {
        strm << "    serviceAssigned = "
            << serviceAssigned.ref() << "\n";
    }
    else {
        strm << "    serviceAssigned is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeCanMoveToContainerRestrictions(
    ThriftBinaryBufferWriter & writer,
    const CanMoveToContainerRestrictions & s)
{
    writer.writeStructBegin(QStringLiteral("CanMoveToContainerRestrictions"));
    if (s.canMoveToContainer.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("canMoveToContainer"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(static_cast<qint32>(s.canMoveToContainer.ref()));
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readCanMoveToContainerRestrictions(
    ThriftBinaryBufferReader & reader,
    CanMoveToContainerRestrictions & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                CanMoveToContainerStatus v;
                readEnumCanMoveToContainerStatus(reader, v);
                s.canMoveToContainer = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void CanMoveToContainerRestrictions::print(QTextStream & strm) const
{
    strm << "CanMoveToContainerRestrictions: {\n";
    localData.print(strm);

    if (canMoveToContainer.isSet()) {
        strm << "    canMoveToContainer = "
            << canMoveToContainer.ref() << "\n";
    }
    else {
        strm << "    canMoveToContainer is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNotebookRestrictions(
    ThriftBinaryBufferWriter & writer,
    const NotebookRestrictions & s)
{
    writer.writeStructBegin(QStringLiteral("NotebookRestrictions"));
    if (s.noReadNotes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noReadNotes"),
            ThriftFieldType::T_BOOL,
            1);

        writer.writeBool(s.noReadNotes.ref());
        writer.writeFieldEnd();
    }

    if (s.noCreateNotes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noCreateNotes"),
            ThriftFieldType::T_BOOL,
            2);

        writer.writeBool(s.noCreateNotes.ref());
        writer.writeFieldEnd();
    }

    if (s.noUpdateNotes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noUpdateNotes"),
            ThriftFieldType::T_BOOL,
            3);

        writer.writeBool(s.noUpdateNotes.ref());
        writer.writeFieldEnd();
    }

    if (s.noExpungeNotes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noExpungeNotes"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(s.noExpungeNotes.ref());
        writer.writeFieldEnd();
    }

    if (s.noShareNotes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noShareNotes"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(s.noShareNotes.ref());
        writer.writeFieldEnd();
    }

    if (s.noEmailNotes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noEmailNotes"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(s.noEmailNotes.ref());
        writer.writeFieldEnd();
    }

    if (s.noSendMessageToRecipients.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSendMessageToRecipients"),
            ThriftFieldType::T_BOOL,
            7);

        writer.writeBool(s.noSendMessageToRecipients.ref());
        writer.writeFieldEnd();
    }

    if (s.noUpdateNotebook.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noUpdateNotebook"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(s.noUpdateNotebook.ref());
        writer.writeFieldEnd();
    }

    if (s.noExpungeNotebook.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noExpungeNotebook"),
            ThriftFieldType::T_BOOL,
            9);

        writer.writeBool(s.noExpungeNotebook.ref());
        writer.writeFieldEnd();
    }

    if (s.noSetDefaultNotebook.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetDefaultNotebook"),
            ThriftFieldType::T_BOOL,
            10);

        writer.writeBool(s.noSetDefaultNotebook.ref());
        writer.writeFieldEnd();
    }

    if (s.noSetNotebookStack.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetNotebookStack"),
            ThriftFieldType::T_BOOL,
            11);

        writer.writeBool(s.noSetNotebookStack.ref());
        writer.writeFieldEnd();
    }

    if (s.noPublishToPublic.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noPublishToPublic"),
            ThriftFieldType::T_BOOL,
            12);

        writer.writeBool(s.noPublishToPublic.ref());
        writer.writeFieldEnd();
    }

    if (s.noPublishToBusinessLibrary.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noPublishToBusinessLibrary"),
            ThriftFieldType::T_BOOL,
            13);

        writer.writeBool(s.noPublishToBusinessLibrary.ref());
        writer.writeFieldEnd();
    }

    if (s.noCreateTags.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noCreateTags"),
            ThriftFieldType::T_BOOL,
            14);

        writer.writeBool(s.noCreateTags.ref());
        writer.writeFieldEnd();
    }

    if (s.noUpdateTags.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noUpdateTags"),
            ThriftFieldType::T_BOOL,
            15);

        writer.writeBool(s.noUpdateTags.ref());
        writer.writeFieldEnd();
    }

    if (s.noExpungeTags.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noExpungeTags"),
            ThriftFieldType::T_BOOL,
            16);

        writer.writeBool(s.noExpungeTags.ref());
        writer.writeFieldEnd();
    }

    if (s.noSetParentTag.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetParentTag"),
            ThriftFieldType::T_BOOL,
            17);

        writer.writeBool(s.noSetParentTag.ref());
        writer.writeFieldEnd();
    }

    if (s.noCreateSharedNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noCreateSharedNotebooks"),
            ThriftFieldType::T_BOOL,
            18);

        writer.writeBool(s.noCreateSharedNotebooks.ref());
        writer.writeFieldEnd();
    }

    if (s.updateWhichSharedNotebookRestrictions.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updateWhichSharedNotebookRestrictions"),
            ThriftFieldType::T_I32,
            19);

        writer.writeI32(static_cast<qint32>(s.updateWhichSharedNotebookRestrictions.ref()));
        writer.writeFieldEnd();
    }

    if (s.expungeWhichSharedNotebookRestrictions.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("expungeWhichSharedNotebookRestrictions"),
            ThriftFieldType::T_I32,
            20);

        writer.writeI32(static_cast<qint32>(s.expungeWhichSharedNotebookRestrictions.ref()));
        writer.writeFieldEnd();
    }

    if (s.noShareNotesWithBusiness.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noShareNotesWithBusiness"),
            ThriftFieldType::T_BOOL,
            21);

        writer.writeBool(s.noShareNotesWithBusiness.ref());
        writer.writeFieldEnd();
    }

    if (s.noRenameNotebook.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noRenameNotebook"),
            ThriftFieldType::T_BOOL,
            22);

        writer.writeBool(s.noRenameNotebook.ref());
        writer.writeFieldEnd();
    }

    if (s.noSetInMyList.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetInMyList"),
            ThriftFieldType::T_BOOL,
            23);

        writer.writeBool(s.noSetInMyList.ref());
        writer.writeFieldEnd();
    }

    if (s.noChangeContact.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noChangeContact"),
            ThriftFieldType::T_BOOL,
            24);

        writer.writeBool(s.noChangeContact.ref());
        writer.writeFieldEnd();
    }

    if (s.canMoveToContainerRestrictions.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("canMoveToContainerRestrictions"),
            ThriftFieldType::T_STRUCT,
            26);

        writeCanMoveToContainerRestrictions(writer, s.canMoveToContainerRestrictions.ref());
        writer.writeFieldEnd();
    }

    if (s.noSetReminderNotifyEmail.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetReminderNotifyEmail"),
            ThriftFieldType::T_BOOL,
            27);

        writer.writeBool(s.noSetReminderNotifyEmail.ref());
        writer.writeFieldEnd();
    }

    if (s.noSetReminderNotifyInApp.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetReminderNotifyInApp"),
            ThriftFieldType::T_BOOL,
            28);

        writer.writeBool(s.noSetReminderNotifyInApp.ref());
        writer.writeFieldEnd();
    }

    if (s.noSetRecipientSettingsStack.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noSetRecipientSettingsStack"),
            ThriftFieldType::T_BOOL,
            29);

        writer.writeBool(s.noSetRecipientSettingsStack.ref());
        writer.writeFieldEnd();
    }

    if (s.noCanMoveNote.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noCanMoveNote"),
            ThriftFieldType::T_BOOL,
            30);

        writer.writeBool(s.noCanMoveNote.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNotebookRestrictions(
    ThriftBinaryBufferReader & reader,
    NotebookRestrictions & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noReadNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noCreateNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noUpdateNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noExpungeNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noShareNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noEmailNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSendMessageToRecipients = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noUpdateNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noExpungeNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSetDefaultNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSetNotebookStack = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noPublishToPublic = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noPublishToBusinessLibrary = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noCreateTags = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noUpdateTags = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noExpungeTags = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSetParentTag = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noCreateSharedNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookInstanceRestrictions v;
                readEnumSharedNotebookInstanceRestrictions(reader, v);
                s.updateWhichSharedNotebookRestrictions = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookInstanceRestrictions v;
                readEnumSharedNotebookInstanceRestrictions(reader, v);
                s.expungeWhichSharedNotebookRestrictions = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noShareNotesWithBusiness = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noRenameNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSetInMyList = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noChangeContact = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 26) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                CanMoveToContainerRestrictions v;
                readCanMoveToContainerRestrictions(reader, v);
                s.canMoveToContainerRestrictions = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 27) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSetReminderNotifyEmail = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 28) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSetReminderNotifyInApp = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 29) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noSetRecipientSettingsStack = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 30) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.noCanMoveNote = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NotebookRestrictions::print(QTextStream & strm) const
{
    strm << "NotebookRestrictions: {\n";
    localData.print(strm);

    if (noReadNotes.isSet()) {
        strm << "    noReadNotes = "
            << noReadNotes.ref() << "\n";
    }
    else {
        strm << "    noReadNotes is not set\n";
    }

    if (noCreateNotes.isSet()) {
        strm << "    noCreateNotes = "
            << noCreateNotes.ref() << "\n";
    }
    else {
        strm << "    noCreateNotes is not set\n";
    }

    if (noUpdateNotes.isSet()) {
        strm << "    noUpdateNotes = "
            << noUpdateNotes.ref() << "\n";
    }
    else {
        strm << "    noUpdateNotes is not set\n";
    }

    if (noExpungeNotes.isSet()) {
        strm << "    noExpungeNotes = "
            << noExpungeNotes.ref() << "\n";
    }
    else {
        strm << "    noExpungeNotes is not set\n";
    }

    if (noShareNotes.isSet()) {
        strm << "    noShareNotes = "
            << noShareNotes.ref() << "\n";
    }
    else {
        strm << "    noShareNotes is not set\n";
    }

    if (noEmailNotes.isSet()) {
        strm << "    noEmailNotes = "
            << noEmailNotes.ref() << "\n";
    }
    else {
        strm << "    noEmailNotes is not set\n";
    }

    if (noSendMessageToRecipients.isSet()) {
        strm << "    noSendMessageToRecipients = "
            << noSendMessageToRecipients.ref() << "\n";
    }
    else {
        strm << "    noSendMessageToRecipients is not set\n";
    }

    if (noUpdateNotebook.isSet()) {
        strm << "    noUpdateNotebook = "
            << noUpdateNotebook.ref() << "\n";
    }
    else {
        strm << "    noUpdateNotebook is not set\n";
    }

    if (noExpungeNotebook.isSet()) {
        strm << "    noExpungeNotebook = "
            << noExpungeNotebook.ref() << "\n";
    }
    else {
        strm << "    noExpungeNotebook is not set\n";
    }

    if (noSetDefaultNotebook.isSet()) {
        strm << "    noSetDefaultNotebook = "
            << noSetDefaultNotebook.ref() << "\n";
    }
    else {
        strm << "    noSetDefaultNotebook is not set\n";
    }

    if (noSetNotebookStack.isSet()) {
        strm << "    noSetNotebookStack = "
            << noSetNotebookStack.ref() << "\n";
    }
    else {
        strm << "    noSetNotebookStack is not set\n";
    }

    if (noPublishToPublic.isSet()) {
        strm << "    noPublishToPublic = "
            << noPublishToPublic.ref() << "\n";
    }
    else {
        strm << "    noPublishToPublic is not set\n";
    }

    if (noPublishToBusinessLibrary.isSet()) {
        strm << "    noPublishToBusinessLibrary = "
            << noPublishToBusinessLibrary.ref() << "\n";
    }
    else {
        strm << "    noPublishToBusinessLibrary is not set\n";
    }

    if (noCreateTags.isSet()) {
        strm << "    noCreateTags = "
            << noCreateTags.ref() << "\n";
    }
    else {
        strm << "    noCreateTags is not set\n";
    }

    if (noUpdateTags.isSet()) {
        strm << "    noUpdateTags = "
            << noUpdateTags.ref() << "\n";
    }
    else {
        strm << "    noUpdateTags is not set\n";
    }

    if (noExpungeTags.isSet()) {
        strm << "    noExpungeTags = "
            << noExpungeTags.ref() << "\n";
    }
    else {
        strm << "    noExpungeTags is not set\n";
    }

    if (noSetParentTag.isSet()) {
        strm << "    noSetParentTag = "
            << noSetParentTag.ref() << "\n";
    }
    else {
        strm << "    noSetParentTag is not set\n";
    }

    if (noCreateSharedNotebooks.isSet()) {
        strm << "    noCreateSharedNotebooks = "
            << noCreateSharedNotebooks.ref() << "\n";
    }
    else {
        strm << "    noCreateSharedNotebooks is not set\n";
    }

    if (updateWhichSharedNotebookRestrictions.isSet()) {
        strm << "    updateWhichSharedNotebookRestrictions = "
            << updateWhichSharedNotebookRestrictions.ref() << "\n";
    }
    else {
        strm << "    updateWhichSharedNotebookRestrictions is not set\n";
    }

    if (expungeWhichSharedNotebookRestrictions.isSet()) {
        strm << "    expungeWhichSharedNotebookRestrictions = "
            << expungeWhichSharedNotebookRestrictions.ref() << "\n";
    }
    else {
        strm << "    expungeWhichSharedNotebookRestrictions is not set\n";
    }

    if (noShareNotesWithBusiness.isSet()) {
        strm << "    noShareNotesWithBusiness = "
            << noShareNotesWithBusiness.ref() << "\n";
    }
    else {
        strm << "    noShareNotesWithBusiness is not set\n";
    }

    if (noRenameNotebook.isSet()) {
        strm << "    noRenameNotebook = "
            << noRenameNotebook.ref() << "\n";
    }
    else {
        strm << "    noRenameNotebook is not set\n";
    }

    if (noSetInMyList.isSet()) {
        strm << "    noSetInMyList = "
            << noSetInMyList.ref() << "\n";
    }
    else {
        strm << "    noSetInMyList is not set\n";
    }

    if (noChangeContact.isSet()) {
        strm << "    noChangeContact = "
            << noChangeContact.ref() << "\n";
    }
    else {
        strm << "    noChangeContact is not set\n";
    }

    if (canMoveToContainerRestrictions.isSet()) {
        strm << "    canMoveToContainerRestrictions = "
            << canMoveToContainerRestrictions.ref() << "\n";
    }
    else {
        strm << "    canMoveToContainerRestrictions is not set\n";
    }

    if (noSetReminderNotifyEmail.isSet()) {
        strm << "    noSetReminderNotifyEmail = "
            << noSetReminderNotifyEmail.ref() << "\n";
    }
    else {
        strm << "    noSetReminderNotifyEmail is not set\n";
    }

    if (noSetReminderNotifyInApp.isSet()) {
        strm << "    noSetReminderNotifyInApp = "
            << noSetReminderNotifyInApp.ref() << "\n";
    }
    else {
        strm << "    noSetReminderNotifyInApp is not set\n";
    }

    if (noSetRecipientSettingsStack.isSet()) {
        strm << "    noSetRecipientSettingsStack = "
            << noSetRecipientSettingsStack.ref() << "\n";
    }
    else {
        strm << "    noSetRecipientSettingsStack is not set\n";
    }

    if (noCanMoveNote.isSet()) {
        strm << "    noCanMoveNote = "
            << noCanMoveNote.ref() << "\n";
    }
    else {
        strm << "    noCanMoveNote is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNotebook(
    ThriftBinaryBufferWriter & writer,
    const Notebook & s)
{
    writer.writeStructBegin(QStringLiteral("Notebook"));
    if (s.guid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.guid.ref());
        writer.writeFieldEnd();
    }

    if (s.name.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.name.ref());
        writer.writeFieldEnd();
    }

    if (s.updateSequenceNum.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(s.updateSequenceNum.ref());
        writer.writeFieldEnd();
    }

    if (s.defaultNotebook.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("defaultNotebook"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(s.defaultNotebook.ref());
        writer.writeFieldEnd();
    }

    if (s.serviceCreated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceCreated"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(s.serviceCreated.ref());
        writer.writeFieldEnd();
    }

    if (s.serviceUpdated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceUpdated"),
            ThriftFieldType::T_I64,
            8);

        writer.writeI64(s.serviceUpdated.ref());
        writer.writeFieldEnd();
    }

    if (s.publishing.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("publishing"),
            ThriftFieldType::T_STRUCT,
            10);

        writePublishing(writer, s.publishing.ref());
        writer.writeFieldEnd();
    }

    if (s.published.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("published"),
            ThriftFieldType::T_BOOL,
            11);

        writer.writeBool(s.published.ref());
        writer.writeFieldEnd();
    }

    if (s.stack.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("stack"),
            ThriftFieldType::T_STRING,
            12);

        writer.writeString(s.stack.ref());
        writer.writeFieldEnd();
    }

    if (s.sharedNotebookIds.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sharedNotebookIds"),
            ThriftFieldType::T_LIST,
            13);

        writer.writeListBegin(ThriftFieldType::T_I64, s.sharedNotebookIds.ref().length());
        for(const auto & value: qAsConst(s.sharedNotebookIds.ref())) {
            writer.writeI64(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.sharedNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sharedNotebooks"),
            ThriftFieldType::T_LIST,
            14);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.sharedNotebooks.ref().length());
        for(const auto & value: qAsConst(s.sharedNotebooks.ref())) {
            writeSharedNotebook(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.businessNotebook.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("businessNotebook"),
            ThriftFieldType::T_STRUCT,
            15);

        writeBusinessNotebook(writer, s.businessNotebook.ref());
        writer.writeFieldEnd();
    }

    if (s.contact.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("contact"),
            ThriftFieldType::T_STRUCT,
            16);

        writeUser(writer, s.contact.ref());
        writer.writeFieldEnd();
    }

    if (s.restrictions.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("restrictions"),
            ThriftFieldType::T_STRUCT,
            17);

        writeNotebookRestrictions(writer, s.restrictions.ref());
        writer.writeFieldEnd();
    }

    if (s.recipientSettings.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("recipientSettings"),
            ThriftFieldType::T_STRUCT,
            18);

        writeNotebookRecipientSettings(writer, s.recipientSettings.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNotebook(
    ThriftBinaryBufferReader & reader,
    Notebook & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.name = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.updateSequenceNum = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.defaultNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.serviceCreated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.serviceUpdated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Publishing v;
                readPublishing(reader, v);
                s.publishing = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.published = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.stack = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<qint64> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_I64) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (Notebook.sharedNotebookIds)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    qint64 elem;
                    reader.readI64(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.sharedNotebookIds = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<SharedNotebook> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (Notebook.sharedNotebooks)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    SharedNotebook elem;
                    readSharedNotebook(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.sharedNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                BusinessNotebook v;
                readBusinessNotebook(reader, v);
                s.businessNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                User v;
                readUser(reader, v);
                s.contact = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NotebookRestrictions v;
                readNotebookRestrictions(reader, v);
                s.restrictions = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NotebookRecipientSettings v;
                readNotebookRecipientSettings(reader, v);
                s.recipientSettings = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void Notebook::print(QTextStream & strm) const
{
    strm << "Notebook: {\n";
    localData.print(strm);

    if (guid.isSet()) {
        strm << "    guid = "
            << guid.ref() << "\n";
    }
    else {
        strm << "    guid is not set\n";
    }

    if (name.isSet()) {
        strm << "    name = "
            << name.ref() << "\n";
    }
    else {
        strm << "    name is not set\n";
    }

    if (updateSequenceNum.isSet()) {
        strm << "    updateSequenceNum = "
            << updateSequenceNum.ref() << "\n";
    }
    else {
        strm << "    updateSequenceNum is not set\n";
    }

    if (defaultNotebook.isSet()) {
        strm << "    defaultNotebook = "
            << defaultNotebook.ref() << "\n";
    }
    else {
        strm << "    defaultNotebook is not set\n";
    }

    if (serviceCreated.isSet()) {
        strm << "    serviceCreated = "
            << serviceCreated.ref() << "\n";
    }
    else {
        strm << "    serviceCreated is not set\n";
    }

    if (serviceUpdated.isSet()) {
        strm << "    serviceUpdated = "
            << serviceUpdated.ref() << "\n";
    }
    else {
        strm << "    serviceUpdated is not set\n";
    }

    if (publishing.isSet()) {
        strm << "    publishing = "
            << publishing.ref() << "\n";
    }
    else {
        strm << "    publishing is not set\n";
    }

    if (published.isSet()) {
        strm << "    published = "
            << published.ref() << "\n";
    }
    else {
        strm << "    published is not set\n";
    }

    if (stack.isSet()) {
        strm << "    stack = "
            << stack.ref() << "\n";
    }
    else {
        strm << "    stack is not set\n";
    }

    if (sharedNotebookIds.isSet()) {
        strm << "    sharedNotebookIds = "
            << "QList<qint64> {";
        for(const auto & v: sharedNotebookIds.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    sharedNotebookIds is not set\n";
    }

    if (sharedNotebooks.isSet()) {
        strm << "    sharedNotebooks = "
            << "QList<SharedNotebook> {";
        for(const auto & v: sharedNotebooks.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    sharedNotebooks is not set\n";
    }

    if (businessNotebook.isSet()) {
        strm << "    businessNotebook = "
            << businessNotebook.ref() << "\n";
    }
    else {
        strm << "    businessNotebook is not set\n";
    }

    if (contact.isSet()) {
        strm << "    contact = "
            << contact.ref() << "\n";
    }
    else {
        strm << "    contact is not set\n";
    }

    if (restrictions.isSet()) {
        strm << "    restrictions = "
            << restrictions.ref() << "\n";
    }
    else {
        strm << "    restrictions is not set\n";
    }

    if (recipientSettings.isSet()) {
        strm << "    recipientSettings = "
            << recipientSettings.ref() << "\n";
    }
    else {
        strm << "    recipientSettings is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeLinkedNotebook(
    ThriftBinaryBufferWriter & writer,
    const LinkedNotebook & s)
{
    writer.writeStructBegin(QStringLiteral("LinkedNotebook"));
    if (s.shareName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("shareName"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.shareName.ref());
        writer.writeFieldEnd();
    }

    if (s.username.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(s.username.ref());
        writer.writeFieldEnd();
    }

    if (s.shardId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("shardId"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.shardId.ref());
        writer.writeFieldEnd();
    }

    if (s.sharedNotebookGlobalId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sharedNotebookGlobalId"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(s.sharedNotebookGlobalId.ref());
        writer.writeFieldEnd();
    }

    if (s.uri.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("uri"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(s.uri.ref());
        writer.writeFieldEnd();
    }

    if (s.guid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            7);

        writer.writeString(s.guid.ref());
        writer.writeFieldEnd();
    }

    if (s.updateSequenceNum.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("updateSequenceNum"),
            ThriftFieldType::T_I32,
            8);

        writer.writeI32(s.updateSequenceNum.ref());
        writer.writeFieldEnd();
    }

    if (s.noteStoreUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noteStoreUrl"),
            ThriftFieldType::T_STRING,
            9);

        writer.writeString(s.noteStoreUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.webApiUrlPrefix.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("webApiUrlPrefix"),
            ThriftFieldType::T_STRING,
            10);

        writer.writeString(s.webApiUrlPrefix.ref());
        writer.writeFieldEnd();
    }

    if (s.stack.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("stack"),
            ThriftFieldType::T_STRING,
            11);

        writer.writeString(s.stack.ref());
        writer.writeFieldEnd();
    }

    if (s.businessId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("businessId"),
            ThriftFieldType::T_I32,
            12);

        writer.writeI32(s.businessId.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readLinkedNotebook(
    ThriftBinaryBufferReader & reader,
    LinkedNotebook & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.shareName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.username = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.shardId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.sharedNotebookGlobalId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.uri = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.updateSequenceNum = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.noteStoreUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.webApiUrlPrefix = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.stack = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.businessId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void LinkedNotebook::print(QTextStream & strm) const
{
    strm << "LinkedNotebook: {\n";
    localData.print(strm);

    if (shareName.isSet()) {
        strm << "    shareName = "
            << shareName.ref() << "\n";
    }
    else {
        strm << "    shareName is not set\n";
    }

    if (username.isSet()) {
        strm << "    username = "
            << username.ref() << "\n";
    }
    else {
        strm << "    username is not set\n";
    }

    if (shardId.isSet()) {
        strm << "    shardId = "
            << shardId.ref() << "\n";
    }
    else {
        strm << "    shardId is not set\n";
    }

    if (sharedNotebookGlobalId.isSet()) {
        strm << "    sharedNotebookGlobalId = "
            << sharedNotebookGlobalId.ref() << "\n";
    }
    else {
        strm << "    sharedNotebookGlobalId is not set\n";
    }

    if (uri.isSet()) {
        strm << "    uri = "
            << uri.ref() << "\n";
    }
    else {
        strm << "    uri is not set\n";
    }

    if (guid.isSet()) {
        strm << "    guid = "
            << guid.ref() << "\n";
    }
    else {
        strm << "    guid is not set\n";
    }

    if (updateSequenceNum.isSet()) {
        strm << "    updateSequenceNum = "
            << updateSequenceNum.ref() << "\n";
    }
    else {
        strm << "    updateSequenceNum is not set\n";
    }

    if (noteStoreUrl.isSet()) {
        strm << "    noteStoreUrl = "
            << noteStoreUrl.ref() << "\n";
    }
    else {
        strm << "    noteStoreUrl is not set\n";
    }

    if (webApiUrlPrefix.isSet()) {
        strm << "    webApiUrlPrefix = "
            << webApiUrlPrefix.ref() << "\n";
    }
    else {
        strm << "    webApiUrlPrefix is not set\n";
    }

    if (stack.isSet()) {
        strm << "    stack = "
            << stack.ref() << "\n";
    }
    else {
        strm << "    stack is not set\n";
    }

    if (businessId.isSet()) {
        strm << "    businessId = "
            << businessId.ref() << "\n";
    }
    else {
        strm << "    businessId is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeNotebookDescriptor(
    ThriftBinaryBufferWriter & writer,
    const NotebookDescriptor & s)
{
    writer.writeStructBegin(QStringLiteral("NotebookDescriptor"));
    if (s.guid.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("guid"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.guid.ref());
        writer.writeFieldEnd();
    }

    if (s.notebookDisplayName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("notebookDisplayName"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.notebookDisplayName.ref());
        writer.writeFieldEnd();
    }

    if (s.contactName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("contactName"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(s.contactName.ref());
        writer.writeFieldEnd();
    }

    if (s.hasSharedNotebook.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("hasSharedNotebook"),
            ThriftFieldType::T_BOOL,
            4);

        writer.writeBool(s.hasSharedNotebook.ref());
        writer.writeFieldEnd();
    }

    if (s.joinedUserCount.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("joinedUserCount"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(s.joinedUserCount.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readNotebookDescriptor(
    ThriftBinaryBufferReader & reader,
    NotebookDescriptor & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                s.guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.notebookDisplayName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.contactName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.hasSharedNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.joinedUserCount = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void NotebookDescriptor::print(QTextStream & strm) const
{
    strm << "NotebookDescriptor: {\n";
    localData.print(strm);

    if (guid.isSet()) {
        strm << "    guid = "
            << guid.ref() << "\n";
    }
    else {
        strm << "    guid is not set\n";
    }

    if (notebookDisplayName.isSet()) {
        strm << "    notebookDisplayName = "
            << notebookDisplayName.ref() << "\n";
    }
    else {
        strm << "    notebookDisplayName is not set\n";
    }

    if (contactName.isSet()) {
        strm << "    contactName = "
            << contactName.ref() << "\n";
    }
    else {
        strm << "    contactName is not set\n";
    }

    if (hasSharedNotebook.isSet()) {
        strm << "    hasSharedNotebook = "
            << hasSharedNotebook.ref() << "\n";
    }
    else {
        strm << "    hasSharedNotebook is not set\n";
    }

    if (joinedUserCount.isSet()) {
        strm << "    joinedUserCount = "
            << joinedUserCount.ref() << "\n";
    }
    else {
        strm << "    joinedUserCount is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeUserProfile(
    ThriftBinaryBufferWriter & writer,
    const UserProfile & s)
{
    writer.writeStructBegin(QStringLiteral("UserProfile"));
    if (s.id.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("id"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(s.id.ref());
        writer.writeFieldEnd();
    }

    if (s.name.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("name"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.name.ref());
        writer.writeFieldEnd();
    }

    if (s.email.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(s.email.ref());
        writer.writeFieldEnd();
    }

    if (s.username.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.username.ref());
        writer.writeFieldEnd();
    }

    if (s.attributes.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("attributes"),
            ThriftFieldType::T_STRUCT,
            5);

        writeBusinessUserAttributes(writer, s.attributes.ref());
        writer.writeFieldEnd();
    }

    if (s.joined.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("joined"),
            ThriftFieldType::T_I64,
            6);

        writer.writeI64(s.joined.ref());
        writer.writeFieldEnd();
    }

    if (s.photoLastUpdated.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("photoLastUpdated"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(s.photoLastUpdated.ref());
        writer.writeFieldEnd();
    }

    if (s.photoUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("photoUrl"),
            ThriftFieldType::T_STRING,
            8);

        writer.writeString(s.photoUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.role.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("role"),
            ThriftFieldType::T_I32,
            9);

        writer.writeI32(static_cast<qint32>(s.role.ref()));
        writer.writeFieldEnd();
    }

    if (s.status.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("status"),
            ThriftFieldType::T_I32,
            10);

        writer.writeI32(static_cast<qint32>(s.status.ref()));
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readUserProfile(
    ThriftBinaryBufferReader & reader,
    UserProfile & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.id = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.name = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.email = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.username = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                BusinessUserAttributes v;
                readBusinessUserAttributes(reader, v);
                s.attributes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.joined = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.photoLastUpdated = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.photoUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole v;
                readEnumBusinessUserRole(reader, v);
                s.role = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserStatus v;
                readEnumBusinessUserStatus(reader, v);
                s.status = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void UserProfile::print(QTextStream & strm) const
{
    strm << "UserProfile: {\n";
    localData.print(strm);

    if (id.isSet()) {
        strm << "    id = "
            << id.ref() << "\n";
    }
    else {
        strm << "    id is not set\n";
    }

    if (name.isSet()) {
        strm << "    name = "
            << name.ref() << "\n";
    }
    else {
        strm << "    name is not set\n";
    }

    if (email.isSet()) {
        strm << "    email = "
            << email.ref() << "\n";
    }
    else {
        strm << "    email is not set\n";
    }

    if (username.isSet()) {
        strm << "    username = "
            << username.ref() << "\n";
    }
    else {
        strm << "    username is not set\n";
    }

    if (attributes.isSet()) {
        strm << "    attributes = "
            << attributes.ref() << "\n";
    }
    else {
        strm << "    attributes is not set\n";
    }

    if (joined.isSet()) {
        strm << "    joined = "
            << joined.ref() << "\n";
    }
    else {
        strm << "    joined is not set\n";
    }

    if (photoLastUpdated.isSet()) {
        strm << "    photoLastUpdated = "
            << photoLastUpdated.ref() << "\n";
    }
    else {
        strm << "    photoLastUpdated is not set\n";
    }

    if (photoUrl.isSet()) {
        strm << "    photoUrl = "
            << photoUrl.ref() << "\n";
    }
    else {
        strm << "    photoUrl is not set\n";
    }

    if (role.isSet()) {
        strm << "    role = "
            << role.ref() << "\n";
    }
    else {
        strm << "    role is not set\n";
    }

    if (status.isSet()) {
        strm << "    status = "
            << status.ref() << "\n";
    }
    else {
        strm << "    status is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeRelatedContentImage(
    ThriftBinaryBufferWriter & writer,
    const RelatedContentImage & s)
{
    writer.writeStructBegin(QStringLiteral("RelatedContentImage"));
    if (s.url.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("url"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.url.ref());
        writer.writeFieldEnd();
    }

    if (s.width.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("width"),
            ThriftFieldType::T_I32,
            2);

        writer.writeI32(s.width.ref());
        writer.writeFieldEnd();
    }

    if (s.height.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("height"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(s.height.ref());
        writer.writeFieldEnd();
    }

    if (s.pixelRatio.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("pixelRatio"),
            ThriftFieldType::T_DOUBLE,
            4);

        writer.writeDouble(s.pixelRatio.ref());
        writer.writeFieldEnd();
    }

    if (s.fileSize.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("fileSize"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(s.fileSize.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readRelatedContentImage(
    ThriftBinaryBufferReader & reader,
    RelatedContentImage & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.url = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.width = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.height = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                reader.readDouble(v);
                s.pixelRatio = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.fileSize = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void RelatedContentImage::print(QTextStream & strm) const
{
    strm << "RelatedContentImage: {\n";
    localData.print(strm);

    if (url.isSet()) {
        strm << "    url = "
            << url.ref() << "\n";
    }
    else {
        strm << "    url is not set\n";
    }

    if (width.isSet()) {
        strm << "    width = "
            << width.ref() << "\n";
    }
    else {
        strm << "    width is not set\n";
    }

    if (height.isSet()) {
        strm << "    height = "
            << height.ref() << "\n";
    }
    else {
        strm << "    height is not set\n";
    }

    if (pixelRatio.isSet()) {
        strm << "    pixelRatio = "
            << pixelRatio.ref() << "\n";
    }
    else {
        strm << "    pixelRatio is not set\n";
    }

    if (fileSize.isSet()) {
        strm << "    fileSize = "
            << fileSize.ref() << "\n";
    }
    else {
        strm << "    fileSize is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeRelatedContent(
    ThriftBinaryBufferWriter & writer,
    const RelatedContent & s)
{
    writer.writeStructBegin(QStringLiteral("RelatedContent"));
    if (s.contentId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("contentId"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.contentId.ref());
        writer.writeFieldEnd();
    }

    if (s.title.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("title"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.title.ref());
        writer.writeFieldEnd();
    }

    if (s.url.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("url"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(s.url.ref());
        writer.writeFieldEnd();
    }

    if (s.sourceId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sourceId"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.sourceId.ref());
        writer.writeFieldEnd();
    }

    if (s.sourceUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sourceUrl"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(s.sourceUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.sourceFaviconUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sourceFaviconUrl"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(s.sourceFaviconUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.sourceName.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("sourceName"),
            ThriftFieldType::T_STRING,
            7);

        writer.writeString(s.sourceName.ref());
        writer.writeFieldEnd();
    }

    if (s.date.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("date"),
            ThriftFieldType::T_I64,
            8);

        writer.writeI64(s.date.ref());
        writer.writeFieldEnd();
    }

    if (s.teaser.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("teaser"),
            ThriftFieldType::T_STRING,
            9);

        writer.writeString(s.teaser.ref());
        writer.writeFieldEnd();
    }

    if (s.thumbnails.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("thumbnails"),
            ThriftFieldType::T_LIST,
            10);

        writer.writeListBegin(ThriftFieldType::T_STRUCT, s.thumbnails.ref().length());
        for(const auto & value: qAsConst(s.thumbnails.ref())) {
            writeRelatedContentImage(writer, value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    if (s.contentType.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("contentType"),
            ThriftFieldType::T_I32,
            11);

        writer.writeI32(static_cast<qint32>(s.contentType.ref()));
        writer.writeFieldEnd();
    }

    if (s.accessType.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("accessType"),
            ThriftFieldType::T_I32,
            12);

        writer.writeI32(static_cast<qint32>(s.accessType.ref()));
        writer.writeFieldEnd();
    }

    if (s.visibleUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("visibleUrl"),
            ThriftFieldType::T_STRING,
            13);

        writer.writeString(s.visibleUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.clipUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("clipUrl"),
            ThriftFieldType::T_STRING,
            14);

        writer.writeString(s.clipUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.contact.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("contact"),
            ThriftFieldType::T_STRUCT,
            15);

        writeContact(writer, s.contact.ref());
        writer.writeFieldEnd();
    }

    if (s.authors.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("authors"),
            ThriftFieldType::T_LIST,
            16);

        writer.writeListBegin(ThriftFieldType::T_STRING, s.authors.ref().length());
        for(const auto & value: qAsConst(s.authors.ref())) {
            writer.writeString(value);
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readRelatedContent(
    ThriftBinaryBufferReader & reader,
    RelatedContent & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.contentId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.title = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.url = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.sourceId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.sourceUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.sourceFaviconUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.sourceName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.date = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.teaser = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<RelatedContentImage> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedContent.thumbnails)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    RelatedContentImage elem;
                    readRelatedContentImage(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.thumbnails = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I32) {
                RelatedContentType v;
                readEnumRelatedContentType(reader, v);
                s.contentType = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                RelatedContentAccess v;
                readEnumRelatedContentAccess(reader, v);
                s.accessType = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.visibleUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.clipUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Contact v;
                readContact(reader, v);
                s.contact = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (RelatedContent.authors)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    reader.readString(elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.authors = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void RelatedContent::print(QTextStream & strm) const
{
    strm << "RelatedContent: {\n";
    localData.print(strm);

    if (contentId.isSet()) {
        strm << "    contentId = "
            << contentId.ref() << "\n";
    }
    else {
        strm << "    contentId is not set\n";
    }

    if (title.isSet()) {
        strm << "    title = "
            << title.ref() << "\n";
    }
    else {
        strm << "    title is not set\n";
    }

    if (url.isSet()) {
        strm << "    url = "
            << url.ref() << "\n";
    }
    else {
        strm << "    url is not set\n";
    }

    if (sourceId.isSet()) {
        strm << "    sourceId = "
            << sourceId.ref() << "\n";
    }
    else {
        strm << "    sourceId is not set\n";
    }

    if (sourceUrl.isSet()) {
        strm << "    sourceUrl = "
            << sourceUrl.ref() << "\n";
    }
    else {
        strm << "    sourceUrl is not set\n";
    }

    if (sourceFaviconUrl.isSet()) {
        strm << "    sourceFaviconUrl = "
            << sourceFaviconUrl.ref() << "\n";
    }
    else {
        strm << "    sourceFaviconUrl is not set\n";
    }

    if (sourceName.isSet()) {
        strm << "    sourceName = "
            << sourceName.ref() << "\n";
    }
    else {
        strm << "    sourceName is not set\n";
    }

    if (date.isSet()) {
        strm << "    date = "
            << date.ref() << "\n";
    }
    else {
        strm << "    date is not set\n";
    }

    if (teaser.isSet()) {
        strm << "    teaser = "
            << teaser.ref() << "\n";
    }
    else {
        strm << "    teaser is not set\n";
    }

    if (thumbnails.isSet()) {
        strm << "    thumbnails = "
            << "QList<RelatedContentImage> {";
        for(const auto & v: thumbnails.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    thumbnails is not set\n";
    }

    if (contentType.isSet()) {
        strm << "    contentType = "
            << contentType.ref() << "\n";
    }
    else {
        strm << "    contentType is not set\n";
    }

    if (accessType.isSet()) {
        strm << "    accessType = "
            << accessType.ref() << "\n";
    }
    else {
        strm << "    accessType is not set\n";
    }

    if (visibleUrl.isSet()) {
        strm << "    visibleUrl = "
            << visibleUrl.ref() << "\n";
    }
    else {
        strm << "    visibleUrl is not set\n";
    }

    if (clipUrl.isSet()) {
        strm << "    clipUrl = "
            << clipUrl.ref() << "\n";
    }
    else {
        strm << "    clipUrl is not set\n";
    }

    if (contact.isSet()) {
        strm << "    contact = "
            << contact.ref() << "\n";
    }
    else {
        strm << "    contact is not set\n";
    }

    if (authors.isSet()) {
        strm << "    authors = "
            << "QList<QString> {";
        for(const auto & v: authors.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    authors is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeBusinessInvitation(
    ThriftBinaryBufferWriter & writer,
    const BusinessInvitation & s)
{
    writer.writeStructBegin(QStringLiteral("BusinessInvitation"));
    if (s.businessId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("businessId"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(s.businessId.ref());
        writer.writeFieldEnd();
    }

    if (s.email.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("email"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.email.ref());
        writer.writeFieldEnd();
    }

    if (s.role.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("role"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(static_cast<qint32>(s.role.ref()));
        writer.writeFieldEnd();
    }

    if (s.status.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("status"),
            ThriftFieldType::T_I32,
            4);

        writer.writeI32(static_cast<qint32>(s.status.ref()));
        writer.writeFieldEnd();
    }

    if (s.requesterId.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("requesterId"),
            ThriftFieldType::T_I32,
            5);

        writer.writeI32(s.requesterId.ref());
        writer.writeFieldEnd();
    }

    if (s.fromWorkChat.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("fromWorkChat"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(s.fromWorkChat.ref());
        writer.writeFieldEnd();
    }

    if (s.created.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("created"),
            ThriftFieldType::T_I64,
            7);

        writer.writeI64(s.created.ref());
        writer.writeFieldEnd();
    }

    if (s.mostRecentReminder.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("mostRecentReminder"),
            ThriftFieldType::T_I64,
            8);

        writer.writeI64(s.mostRecentReminder.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readBusinessInvitation(
    ThriftBinaryBufferReader & reader,
    BusinessInvitation & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.businessId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.email = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole v;
                readEnumBusinessUserRole(reader, v);
                s.role = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessInvitationStatus v;
                readEnumBusinessInvitationStatus(reader, v);
                s.status = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                s.requesterId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.fromWorkChat = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.created = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.mostRecentReminder = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void BusinessInvitation::print(QTextStream & strm) const
{
    strm << "BusinessInvitation: {\n";
    localData.print(strm);

    if (businessId.isSet()) {
        strm << "    businessId = "
            << businessId.ref() << "\n";
    }
    else {
        strm << "    businessId is not set\n";
    }

    if (email.isSet()) {
        strm << "    email = "
            << email.ref() << "\n";
    }
    else {
        strm << "    email is not set\n";
    }

    if (role.isSet()) {
        strm << "    role = "
            << role.ref() << "\n";
    }
    else {
        strm << "    role is not set\n";
    }

    if (status.isSet()) {
        strm << "    status = "
            << status.ref() << "\n";
    }
    else {
        strm << "    status is not set\n";
    }

    if (requesterId.isSet()) {
        strm << "    requesterId = "
            << requesterId.ref() << "\n";
    }
    else {
        strm << "    requesterId is not set\n";
    }

    if (fromWorkChat.isSet()) {
        strm << "    fromWorkChat = "
            << fromWorkChat.ref() << "\n";
    }
    else {
        strm << "    fromWorkChat is not set\n";
    }

    if (created.isSet()) {
        strm << "    created = "
            << created.ref() << "\n";
    }
    else {
        strm << "    created is not set\n";
    }

    if (mostRecentReminder.isSet()) {
        strm << "    mostRecentReminder = "
            << mostRecentReminder.ref() << "\n";
    }
    else {
        strm << "    mostRecentReminder is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeUserIdentity(
    ThriftBinaryBufferWriter & writer,
    const UserIdentity & s)
{
    writer.writeStructBegin(QStringLiteral("UserIdentity"));
    if (s.type.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("type"),
            ThriftFieldType::T_I32,
            1);

        writer.writeI32(static_cast<qint32>(s.type.ref()));
        writer.writeFieldEnd();
    }

    if (s.stringIdentifier.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("stringIdentifier"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.stringIdentifier.ref());
        writer.writeFieldEnd();
    }

    if (s.longIdentifier.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("longIdentifier"),
            ThriftFieldType::T_I64,
            3);

        writer.writeI64(s.longIdentifier.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readUserIdentity(
    ThriftBinaryBufferReader & reader,
    UserIdentity & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserIdentityType v;
                readEnumUserIdentityType(reader, v);
                s.type = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.stringIdentifier = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                reader.readI64(v);
                s.longIdentifier = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void UserIdentity::print(QTextStream & strm) const
{
    strm << "UserIdentity: {\n";
    localData.print(strm);

    if (type.isSet()) {
        strm << "    type = "
            << type.ref() << "\n";
    }
    else {
        strm << "    type is not set\n";
    }

    if (stringIdentifier.isSet()) {
        strm << "    stringIdentifier = "
            << stringIdentifier.ref() << "\n";
    }
    else {
        strm << "    stringIdentifier is not set\n";
    }

    if (longIdentifier.isSet()) {
        strm << "    longIdentifier = "
            << longIdentifier.ref() << "\n";
    }
    else {
        strm << "    longIdentifier is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writePublicUserInfo(
    ThriftBinaryBufferWriter & writer,
    const PublicUserInfo & s)
{
    writer.writeStructBegin(QStringLiteral("PublicUserInfo"));
    writer.writeFieldBegin(
        QStringLiteral("userId"),
        ThriftFieldType::T_I32,
        1);

    writer.writeI32(s.userId);
    writer.writeFieldEnd();

    if (s.serviceLevel.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("serviceLevel"),
            ThriftFieldType::T_I32,
            7);

        writer.writeI32(static_cast<qint32>(s.serviceLevel.ref()));
        writer.writeFieldEnd();
    }

    if (s.username.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("username"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.username.ref());
        writer.writeFieldEnd();
    }

    if (s.noteStoreUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noteStoreUrl"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(s.noteStoreUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.webApiUrlPrefix.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("webApiUrlPrefix"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(s.webApiUrlPrefix.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readPublicUserInfo(
    ThriftBinaryBufferReader & reader,
    PublicUserInfo & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool userId_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                userId_isset = true;
                UserID v;
                reader.readI32(v);
                s.userId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                ServiceLevel v;
                readEnumServiceLevel(reader, v);
                s.serviceLevel = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.username = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.noteStoreUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.webApiUrlPrefix = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!userId_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("PublicUserInfo.userId has no value"));
}

void PublicUserInfo::print(QTextStream & strm) const
{
    strm << "PublicUserInfo: {\n";
    localData.print(strm);
    strm << "    userId = "
        << userId << "\n";

    if (serviceLevel.isSet()) {
        strm << "    serviceLevel = "
            << serviceLevel.ref() << "\n";
    }
    else {
        strm << "    serviceLevel is not set\n";
    }

    if (username.isSet()) {
        strm << "    username = "
            << username.ref() << "\n";
    }
    else {
        strm << "    username is not set\n";
    }

    if (noteStoreUrl.isSet()) {
        strm << "    noteStoreUrl = "
            << noteStoreUrl.ref() << "\n";
    }
    else {
        strm << "    noteStoreUrl is not set\n";
    }

    if (webApiUrlPrefix.isSet()) {
        strm << "    webApiUrlPrefix = "
            << webApiUrlPrefix.ref() << "\n";
    }
    else {
        strm << "    webApiUrlPrefix is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeUserUrls(
    ThriftBinaryBufferWriter & writer,
    const UserUrls & s)
{
    writer.writeStructBegin(QStringLiteral("UserUrls"));
    if (s.noteStoreUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noteStoreUrl"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.noteStoreUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.webApiUrlPrefix.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("webApiUrlPrefix"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.webApiUrlPrefix.ref());
        writer.writeFieldEnd();
    }

    if (s.userStoreUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userStoreUrl"),
            ThriftFieldType::T_STRING,
            3);

        writer.writeString(s.userStoreUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.utilityUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("utilityUrl"),
            ThriftFieldType::T_STRING,
            4);

        writer.writeString(s.utilityUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.messageStoreUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("messageStoreUrl"),
            ThriftFieldType::T_STRING,
            5);

        writer.writeString(s.messageStoreUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.userWebSocketUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("userWebSocketUrl"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(s.userWebSocketUrl.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readUserUrls(
    ThriftBinaryBufferReader & reader,
    UserUrls & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.noteStoreUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.webApiUrlPrefix = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.userStoreUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.utilityUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.messageStoreUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.userWebSocketUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void UserUrls::print(QTextStream & strm) const
{
    strm << "UserUrls: {\n";
    localData.print(strm);

    if (noteStoreUrl.isSet()) {
        strm << "    noteStoreUrl = "
            << noteStoreUrl.ref() << "\n";
    }
    else {
        strm << "    noteStoreUrl is not set\n";
    }

    if (webApiUrlPrefix.isSet()) {
        strm << "    webApiUrlPrefix = "
            << webApiUrlPrefix.ref() << "\n";
    }
    else {
        strm << "    webApiUrlPrefix is not set\n";
    }

    if (userStoreUrl.isSet()) {
        strm << "    userStoreUrl = "
            << userStoreUrl.ref() << "\n";
    }
    else {
        strm << "    userStoreUrl is not set\n";
    }

    if (utilityUrl.isSet()) {
        strm << "    utilityUrl = "
            << utilityUrl.ref() << "\n";
    }
    else {
        strm << "    utilityUrl is not set\n";
    }

    if (messageStoreUrl.isSet()) {
        strm << "    messageStoreUrl = "
            << messageStoreUrl.ref() << "\n";
    }
    else {
        strm << "    messageStoreUrl is not set\n";
    }

    if (userWebSocketUrl.isSet()) {
        strm << "    userWebSocketUrl = "
            << userWebSocketUrl.ref() << "\n";
    }
    else {
        strm << "    userWebSocketUrl is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeAuthenticationResult(
    ThriftBinaryBufferWriter & writer,
    const AuthenticationResult & s)
{
    writer.writeStructBegin(QStringLiteral("AuthenticationResult"));
    writer.writeFieldBegin(
        QStringLiteral("currentTime"),
        ThriftFieldType::T_I64,
        1);

    writer.writeI64(s.currentTime);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("authenticationToken"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(s.authenticationToken);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("expiration"),
        ThriftFieldType::T_I64,
        3);

    writer.writeI64(s.expiration);
    writer.writeFieldEnd();

    if (s.user.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("user"),
            ThriftFieldType::T_STRUCT,
            4);

        writeUser(writer, s.user.ref());
        writer.writeFieldEnd();
    }

    if (s.publicUserInfo.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("publicUserInfo"),
            ThriftFieldType::T_STRUCT,
            5);

        writePublicUserInfo(writer, s.publicUserInfo.ref());
        writer.writeFieldEnd();
    }

    if (s.noteStoreUrl.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("noteStoreUrl"),
            ThriftFieldType::T_STRING,
            6);

        writer.writeString(s.noteStoreUrl.ref());
        writer.writeFieldEnd();
    }

    if (s.webApiUrlPrefix.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("webApiUrlPrefix"),
            ThriftFieldType::T_STRING,
            7);

        writer.writeString(s.webApiUrlPrefix.ref());
        writer.writeFieldEnd();
    }

    if (s.secondFactorRequired.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("secondFactorRequired"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(s.secondFactorRequired.ref());
        writer.writeFieldEnd();
    }

    if (s.secondFactorDeliveryHint.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("secondFactorDeliveryHint"),
            ThriftFieldType::T_STRING,
            9);

        writer.writeString(s.secondFactorDeliveryHint.ref());
        writer.writeFieldEnd();
    }

    if (s.urls.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("urls"),
            ThriftFieldType::T_STRUCT,
            10);

        writeUserUrls(writer, s.urls.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readAuthenticationResult(
    ThriftBinaryBufferReader & reader,
    AuthenticationResult & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool currentTime_isset = false;
    bool authenticationToken_isset = false;
    bool expiration_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                currentTime_isset = true;
                qint64 v;
                reader.readI64(v);
                s.currentTime = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                authenticationToken_isset = true;
                QString v;
                reader.readString(v);
                s.authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                expiration_isset = true;
                qint64 v;
                reader.readI64(v);
                s.expiration = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                User v;
                readUser(reader, v);
                s.user = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                PublicUserInfo v;
                readPublicUserInfo(reader, v);
                s.publicUserInfo = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.noteStoreUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.webApiUrlPrefix = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.secondFactorRequired = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.secondFactorDeliveryHint = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserUrls v;
                readUserUrls(reader, v);
                s.urls = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!currentTime_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("AuthenticationResult.currentTime has no value"));
    if (!authenticationToken_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("AuthenticationResult.authenticationToken has no value"));
    if (!expiration_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("AuthenticationResult.expiration has no value"));
}

void AuthenticationResult::print(QTextStream & strm) const
{
    strm << "AuthenticationResult: {\n";
    localData.print(strm);
    strm << "    currentTime = "
        << currentTime << "\n";
    strm << "    authenticationToken = "
        << authenticationToken << "\n";
    strm << "    expiration = "
        << expiration << "\n";

    if (user.isSet()) {
        strm << "    user = "
            << user.ref() << "\n";
    }
    else {
        strm << "    user is not set\n";
    }

    if (publicUserInfo.isSet()) {
        strm << "    publicUserInfo = "
            << publicUserInfo.ref() << "\n";
    }
    else {
        strm << "    publicUserInfo is not set\n";
    }

    if (noteStoreUrl.isSet()) {
        strm << "    noteStoreUrl = "
            << noteStoreUrl.ref() << "\n";
    }
    else {
        strm << "    noteStoreUrl is not set\n";
    }

    if (webApiUrlPrefix.isSet()) {
        strm << "    webApiUrlPrefix = "
            << webApiUrlPrefix.ref() << "\n";
    }
    else {
        strm << "    webApiUrlPrefix is not set\n";
    }

    if (secondFactorRequired.isSet()) {
        strm << "    secondFactorRequired = "
            << secondFactorRequired.ref() << "\n";
    }
    else {
        strm << "    secondFactorRequired is not set\n";
    }

    if (secondFactorDeliveryHint.isSet()) {
        strm << "    secondFactorDeliveryHint = "
            << secondFactorDeliveryHint.ref() << "\n";
    }
    else {
        strm << "    secondFactorDeliveryHint is not set\n";
    }

    if (urls.isSet()) {
        strm << "    urls = "
            << urls.ref() << "\n";
    }
    else {
        strm << "    urls is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeBootstrapSettings(
    ThriftBinaryBufferWriter & writer,
    const BootstrapSettings & s)
{
    writer.writeStructBegin(QStringLiteral("BootstrapSettings"));
    writer.writeFieldBegin(
        QStringLiteral("serviceHost"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(s.serviceHost);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("marketingUrl"),
        ThriftFieldType::T_STRING,
        2);

    writer.writeString(s.marketingUrl);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("supportUrl"),
        ThriftFieldType::T_STRING,
        3);

    writer.writeString(s.supportUrl);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("accountEmailDomain"),
        ThriftFieldType::T_STRING,
        4);

    writer.writeString(s.accountEmailDomain);
    writer.writeFieldEnd();

    if (s.enableFacebookSharing.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("enableFacebookSharing"),
            ThriftFieldType::T_BOOL,
            5);

        writer.writeBool(s.enableFacebookSharing.ref());
        writer.writeFieldEnd();
    }

    if (s.enableGiftSubscriptions.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("enableGiftSubscriptions"),
            ThriftFieldType::T_BOOL,
            6);

        writer.writeBool(s.enableGiftSubscriptions.ref());
        writer.writeFieldEnd();
    }

    if (s.enableSupportTickets.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("enableSupportTickets"),
            ThriftFieldType::T_BOOL,
            7);

        writer.writeBool(s.enableSupportTickets.ref());
        writer.writeFieldEnd();
    }

    if (s.enableSharedNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("enableSharedNotebooks"),
            ThriftFieldType::T_BOOL,
            8);

        writer.writeBool(s.enableSharedNotebooks.ref());
        writer.writeFieldEnd();
    }

    if (s.enableSingleNoteSharing.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("enableSingleNoteSharing"),
            ThriftFieldType::T_BOOL,
            9);

        writer.writeBool(s.enableSingleNoteSharing.ref());
        writer.writeFieldEnd();
    }

    if (s.enableSponsoredAccounts.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("enableSponsoredAccounts"),
            ThriftFieldType::T_BOOL,
            10);

        writer.writeBool(s.enableSponsoredAccounts.ref());
        writer.writeFieldEnd();
    }

    if (s.enableTwitterSharing.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("enableTwitterSharing"),
            ThriftFieldType::T_BOOL,
            11);

        writer.writeBool(s.enableTwitterSharing.ref());
        writer.writeFieldEnd();
    }

    if (s.enableLinkedInSharing.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("enableLinkedInSharing"),
            ThriftFieldType::T_BOOL,
            12);

        writer.writeBool(s.enableLinkedInSharing.ref());
        writer.writeFieldEnd();
    }

    if (s.enablePublicNotebooks.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("enablePublicNotebooks"),
            ThriftFieldType::T_BOOL,
            13);

        writer.writeBool(s.enablePublicNotebooks.ref());
        writer.writeFieldEnd();
    }

    if (s.enableGoogle.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("enableGoogle"),
            ThriftFieldType::T_BOOL,
            16);

        writer.writeBool(s.enableGoogle.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readBootstrapSettings(
    ThriftBinaryBufferReader & reader,
    BootstrapSettings & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool serviceHost_isset = false;
    bool marketingUrl_isset = false;
    bool supportUrl_isset = false;
    bool accountEmailDomain_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                serviceHost_isset = true;
                QString v;
                reader.readString(v);
                s.serviceHost = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                marketingUrl_isset = true;
                QString v;
                reader.readString(v);
                s.marketingUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                supportUrl_isset = true;
                QString v;
                reader.readString(v);
                s.supportUrl = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                accountEmailDomain_isset = true;
                QString v;
                reader.readString(v);
                s.accountEmailDomain = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.enableFacebookSharing = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.enableGiftSubscriptions = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.enableSupportTickets = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.enableSharedNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.enableSingleNoteSharing = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.enableSponsoredAccounts = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.enableTwitterSharing = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.enableLinkedInSharing = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.enablePublicNotebooks = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                s.enableGoogle = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!serviceHost_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.serviceHost has no value"));
    if (!marketingUrl_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.marketingUrl has no value"));
    if (!supportUrl_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.supportUrl has no value"));
    if (!accountEmailDomain_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.accountEmailDomain has no value"));
}

void BootstrapSettings::print(QTextStream & strm) const
{
    strm << "BootstrapSettings: {\n";
    localData.print(strm);
    strm << "    serviceHost = "
        << serviceHost << "\n";
    strm << "    marketingUrl = "
        << marketingUrl << "\n";
    strm << "    supportUrl = "
        << supportUrl << "\n";
    strm << "    accountEmailDomain = "
        << accountEmailDomain << "\n";

    if (enableFacebookSharing.isSet()) {
        strm << "    enableFacebookSharing = "
            << enableFacebookSharing.ref() << "\n";
    }
    else {
        strm << "    enableFacebookSharing is not set\n";
    }

    if (enableGiftSubscriptions.isSet()) {
        strm << "    enableGiftSubscriptions = "
            << enableGiftSubscriptions.ref() << "\n";
    }
    else {
        strm << "    enableGiftSubscriptions is not set\n";
    }

    if (enableSupportTickets.isSet()) {
        strm << "    enableSupportTickets = "
            << enableSupportTickets.ref() << "\n";
    }
    else {
        strm << "    enableSupportTickets is not set\n";
    }

    if (enableSharedNotebooks.isSet()) {
        strm << "    enableSharedNotebooks = "
            << enableSharedNotebooks.ref() << "\n";
    }
    else {
        strm << "    enableSharedNotebooks is not set\n";
    }

    if (enableSingleNoteSharing.isSet()) {
        strm << "    enableSingleNoteSharing = "
            << enableSingleNoteSharing.ref() << "\n";
    }
    else {
        strm << "    enableSingleNoteSharing is not set\n";
    }

    if (enableSponsoredAccounts.isSet()) {
        strm << "    enableSponsoredAccounts = "
            << enableSponsoredAccounts.ref() << "\n";
    }
    else {
        strm << "    enableSponsoredAccounts is not set\n";
    }

    if (enableTwitterSharing.isSet()) {
        strm << "    enableTwitterSharing = "
            << enableTwitterSharing.ref() << "\n";
    }
    else {
        strm << "    enableTwitterSharing is not set\n";
    }

    if (enableLinkedInSharing.isSet()) {
        strm << "    enableLinkedInSharing = "
            << enableLinkedInSharing.ref() << "\n";
    }
    else {
        strm << "    enableLinkedInSharing is not set\n";
    }

    if (enablePublicNotebooks.isSet()) {
        strm << "    enablePublicNotebooks = "
            << enablePublicNotebooks.ref() << "\n";
    }
    else {
        strm << "    enablePublicNotebooks is not set\n";
    }

    if (enableGoogle.isSet()) {
        strm << "    enableGoogle = "
            << enableGoogle.ref() << "\n";
    }
    else {
        strm << "    enableGoogle is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeBootstrapProfile(
    ThriftBinaryBufferWriter & writer,
    const BootstrapProfile & s)
{
    writer.writeStructBegin(QStringLiteral("BootstrapProfile"));
    writer.writeFieldBegin(
        QStringLiteral("name"),
        ThriftFieldType::T_STRING,
        1);

    writer.writeString(s.name);
    writer.writeFieldEnd();

    writer.writeFieldBegin(
        QStringLiteral("settings"),
        ThriftFieldType::T_STRUCT,
        2);

    writeBootstrapSettings(writer, s.settings);
    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readBootstrapProfile(
    ThriftBinaryBufferReader & reader,
    BootstrapProfile & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool name_isset = false;
    bool settings_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                name_isset = true;
                QString v;
                reader.readString(v);
                s.name = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                settings_isset = true;
                BootstrapSettings v;
                readBootstrapSettings(reader, v);
                s.settings = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!name_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapProfile.name has no value"));
    if (!settings_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapProfile.settings has no value"));
}

void BootstrapProfile::print(QTextStream & strm) const
{
    strm << "BootstrapProfile: {\n";
    localData.print(strm);
    strm << "    name = "
        << name << "\n";
    strm << "    settings = "
        << settings << "\n";
    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

void writeBootstrapInfo(
    ThriftBinaryBufferWriter & writer,
    const BootstrapInfo & s)
{
    writer.writeStructBegin(QStringLiteral("BootstrapInfo"));
    writer.writeFieldBegin(
        QStringLiteral("profiles"),
        ThriftFieldType::T_LIST,
        1);

    writer.writeListBegin(ThriftFieldType::T_STRUCT, s.profiles.length());
    for(const auto & value: qAsConst(s.profiles)) {
        writeBootstrapProfile(writer, value);
    }
    writer.writeListEnd();

    writer.writeFieldEnd();

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readBootstrapInfo(
    ThriftBinaryBufferReader & reader,
    BootstrapInfo & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool profiles_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                profiles_isset = true;
                QList<BootstrapProfile> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (BootstrapInfo.profiles)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    BootstrapProfile elem;
                    readBootstrapProfile(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.profiles = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!profiles_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapInfo.profiles has no value"));
}

void BootstrapInfo::print(QTextStream & strm) const
{
    strm << "BootstrapInfo: {\n";
    localData.print(strm);
    strm << "    profiles = "
        << "QList<BootstrapProfile> {";
    for(const auto & v: profiles) {
        strm << "    " << v << "\n";
    }
    strm << "}\n";
    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

EDAMUserException::EDAMUserException() {}
EDAMUserException::~EDAMUserException() noexcept {}
EDAMUserException::EDAMUserException(const EDAMUserException& other) : EvernoteException(other)
{
   errorCode = other.errorCode;
   parameter = other.parameter;
}
void writeEDAMUserException(
    ThriftBinaryBufferWriter & writer,
    const EDAMUserException & s)
{
    writer.writeStructBegin(QStringLiteral("EDAMUserException"));
    writer.writeFieldBegin(
        QStringLiteral("errorCode"),
        ThriftFieldType::T_I32,
        1);

    writer.writeI32(static_cast<qint32>(s.errorCode));
    writer.writeFieldEnd();

    if (s.parameter.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("parameter"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.parameter.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readEDAMUserException(
    ThriftBinaryBufferReader & reader,
    EDAMUserException & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool errorCode_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                errorCode_isset = true;
                EDAMErrorCode v;
                readEnumEDAMErrorCode(reader, v);
                s.errorCode = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.parameter = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!errorCode_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("EDAMUserException.errorCode has no value"));
}

void EDAMUserException::print(QTextStream & strm) const
{
    strm << "EDAMUserException: {\n";
    strm << "    errorCode = "
        << errorCode << "\n";

    if (parameter.isSet()) {
        strm << "    parameter = "
            << parameter.ref() << "\n";
    }
    else {
        strm << "    parameter is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

EDAMSystemException::EDAMSystemException() {}
EDAMSystemException::~EDAMSystemException() noexcept {}
EDAMSystemException::EDAMSystemException(const EDAMSystemException& other) : EvernoteException(other)
{
   errorCode = other.errorCode;
   message = other.message;
   rateLimitDuration = other.rateLimitDuration;
}
void writeEDAMSystemException(
    ThriftBinaryBufferWriter & writer,
    const EDAMSystemException & s)
{
    writer.writeStructBegin(QStringLiteral("EDAMSystemException"));
    writer.writeFieldBegin(
        QStringLiteral("errorCode"),
        ThriftFieldType::T_I32,
        1);

    writer.writeI32(static_cast<qint32>(s.errorCode));
    writer.writeFieldEnd();

    if (s.message.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("message"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.message.ref());
        writer.writeFieldEnd();
    }

    if (s.rateLimitDuration.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("rateLimitDuration"),
            ThriftFieldType::T_I32,
            3);

        writer.writeI32(s.rateLimitDuration.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readEDAMSystemException(
    ThriftBinaryBufferReader & reader,
    EDAMSystemException & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool errorCode_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                errorCode_isset = true;
                EDAMErrorCode v;
                readEnumEDAMErrorCode(reader, v);
                s.errorCode = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.message = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                s.rateLimitDuration = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!errorCode_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("EDAMSystemException.errorCode has no value"));
}

void EDAMSystemException::print(QTextStream & strm) const
{
    strm << "EDAMSystemException: {\n";
    strm << "    errorCode = "
        << errorCode << "\n";

    if (message.isSet()) {
        strm << "    message = "
            << message.ref() << "\n";
    }
    else {
        strm << "    message is not set\n";
    }

    if (rateLimitDuration.isSet()) {
        strm << "    rateLimitDuration = "
            << rateLimitDuration.ref() << "\n";
    }
    else {
        strm << "    rateLimitDuration is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

EDAMNotFoundException::EDAMNotFoundException() {}
EDAMNotFoundException::~EDAMNotFoundException() noexcept {}
EDAMNotFoundException::EDAMNotFoundException(const EDAMNotFoundException& other) : EvernoteException(other)
{
   identifier = other.identifier;
   key = other.key;
}
void writeEDAMNotFoundException(
    ThriftBinaryBufferWriter & writer,
    const EDAMNotFoundException & s)
{
    writer.writeStructBegin(QStringLiteral("EDAMNotFoundException"));
    if (s.identifier.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("identifier"),
            ThriftFieldType::T_STRING,
            1);

        writer.writeString(s.identifier.ref());
        writer.writeFieldEnd();
    }

    if (s.key.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("key"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.key.ref());
        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readEDAMNotFoundException(
    ThriftBinaryBufferReader & reader,
    EDAMNotFoundException & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.identifier = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.key = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
}

void EDAMNotFoundException::print(QTextStream & strm) const
{
    strm << "EDAMNotFoundException: {\n";

    if (identifier.isSet()) {
        strm << "    identifier = "
            << identifier.ref() << "\n";
    }
    else {
        strm << "    identifier is not set\n";
    }

    if (key.isSet()) {
        strm << "    key = "
            << key.ref() << "\n";
    }
    else {
        strm << "    key is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

EDAMInvalidContactsException::EDAMInvalidContactsException() {}
EDAMInvalidContactsException::~EDAMInvalidContactsException() noexcept {}
EDAMInvalidContactsException::EDAMInvalidContactsException(const EDAMInvalidContactsException& other) : EvernoteException(other)
{
   contacts = other.contacts;
   parameter = other.parameter;
   reasons = other.reasons;
}
void writeEDAMInvalidContactsException(
    ThriftBinaryBufferWriter & writer,
    const EDAMInvalidContactsException & s)
{
    writer.writeStructBegin(QStringLiteral("EDAMInvalidContactsException"));
    writer.writeFieldBegin(
        QStringLiteral("contacts"),
        ThriftFieldType::T_LIST,
        1);

    writer.writeListBegin(ThriftFieldType::T_STRUCT, s.contacts.length());
    for(const auto & value: qAsConst(s.contacts)) {
        writeContact(writer, value);
    }
    writer.writeListEnd();

    writer.writeFieldEnd();

    if (s.parameter.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("parameter"),
            ThriftFieldType::T_STRING,
            2);

        writer.writeString(s.parameter.ref());
        writer.writeFieldEnd();
    }

    if (s.reasons.isSet()) {
        writer.writeFieldBegin(
            QStringLiteral("reasons"),
            ThriftFieldType::T_LIST,
            3);

        writer.writeListBegin(ThriftFieldType::T_I32, s.reasons.ref().length());
        for(const auto & value: qAsConst(s.reasons.ref())) {
            writer.writeI32(static_cast<qint32>(value));
        }
        writer.writeListEnd();

        writer.writeFieldEnd();
    }

    writer.writeFieldStop();
    writer.writeStructEnd();
}

void readEDAMInvalidContactsException(
    ThriftBinaryBufferReader & reader,
    EDAMInvalidContactsException & s)
{
    QString fname;
    ThriftFieldType fieldType;
    qint16 fieldId;
    bool contacts_isset = false;
    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                contacts_isset = true;
                QList<Contact> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRUCT) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (EDAMInvalidContactsException.contacts)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    Contact elem;
                    readContact(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.contacts = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                s.parameter = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList<EDAMInvalidContactReason> v;
                qint32 size;
                ThriftFieldType elemType;
                reader.readListBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_I32) {
                    throw ThriftException(
                        ThriftException::Type::INVALID_DATA,
                        QStringLiteral("Incorrect list type (EDAMInvalidContactsException.reasons)"));
                }
                for(qint32 i = 0; i < size; i++) {
                    EDAMInvalidContactReason elem;
                    readEnumEDAMInvalidContactReason(reader, elem);
                    v.append(elem);
                }
                reader.readListEnd();
                s.reasons = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }
        reader.readFieldEnd();
    }
    reader.readStructEnd();
    if (!contacts_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("EDAMInvalidContactsException.contacts has no value"));
}

void EDAMInvalidContactsException::print(QTextStream & strm) const
{
    strm << "EDAMInvalidContactsException: {\n";
    strm << "    contacts = "
        << "QList<Contact> {";
    for(const auto & v: contacts) {
        strm << "    " << v << "\n";
    }
    strm << "}\n";

    if (parameter.isSet()) {
        strm << "    parameter = "
            << parameter.ref() << "\n";
    }
    else {
        strm << "    parameter is not set\n";
    }

    if (reasons.isSet()) {
        strm << "    reasons = "
            << "QList<EDAMInvalidContactReason> {";
        for(const auto & v: reasons.ref()) {
            strm << "        " << v << "\n";
        }
        strm << "    }\n";
    }
    else {
        strm << "    reasons is not set\n";
    }

    strm << "}\n";
}

////////////////////////////////////////////////////////////////////////////////

/** @endcond */

} // namespace qevercloud
