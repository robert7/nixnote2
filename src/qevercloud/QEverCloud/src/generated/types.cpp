/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */


#include <generated/types.h>
#include "../impl.h"
#include "../impl.h"
#include "types_impl.h"
#include <qt4helpers.h>

namespace qevercloud {
/** @cond HIDDEN_SYMBOLS  */

void readEnumEDAMErrorCode(ThriftBinaryBufferReader & r, EDAMErrorCode::type & e) {
    qint32 i;
    r.readI32(i);
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

void readEnumEDAMInvalidContactReason(ThriftBinaryBufferReader & r, EDAMInvalidContactReason::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(EDAMInvalidContactReason::BAD_ADDRESS): e = EDAMInvalidContactReason::BAD_ADDRESS; break;
    case static_cast<int>(EDAMInvalidContactReason::DUPLICATE_CONTACT): e = EDAMInvalidContactReason::DUPLICATE_CONTACT; break;
    case static_cast<int>(EDAMInvalidContactReason::NO_CONNECTION): e = EDAMInvalidContactReason::NO_CONNECTION; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum EDAMInvalidContactReason"));
    }
}

void readEnumShareRelationshipPrivilegeLevel(ThriftBinaryBufferReader & r, ShareRelationshipPrivilegeLevel::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK): e = ShareRelationshipPrivilegeLevel::READ_NOTEBOOK; break;
    case static_cast<int>(ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY): e = ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY; break;
    case static_cast<int>(ShareRelationshipPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY): e = ShareRelationshipPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY; break;
    case static_cast<int>(ShareRelationshipPrivilegeLevel::FULL_ACCESS): e = ShareRelationshipPrivilegeLevel::FULL_ACCESS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum ShareRelationshipPrivilegeLevel"));
    }
}

void readEnumPrivilegeLevel(ThriftBinaryBufferReader & r, PrivilegeLevel::type & e) {
    qint32 i;
    r.readI32(i);
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

void readEnumServiceLevel(ThriftBinaryBufferReader & r, ServiceLevel::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(ServiceLevel::BASIC): e = ServiceLevel::BASIC; break;
    case static_cast<int>(ServiceLevel::PLUS): e = ServiceLevel::PLUS; break;
    case static_cast<int>(ServiceLevel::PREMIUM): e = ServiceLevel::PREMIUM; break;
    case static_cast<int>(ServiceLevel::BUSINESS): e = ServiceLevel::BUSINESS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum ServiceLevel"));
    }
}

void readEnumQueryFormat(ThriftBinaryBufferReader & r, QueryFormat::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(QueryFormat::USER): e = QueryFormat::USER; break;
    case static_cast<int>(QueryFormat::SEXP): e = QueryFormat::SEXP; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum QueryFormat"));
    }
}

void readEnumNoteSortOrder(ThriftBinaryBufferReader & r, NoteSortOrder::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(NoteSortOrder::CREATED): e = NoteSortOrder::CREATED; break;
    case static_cast<int>(NoteSortOrder::UPDATED): e = NoteSortOrder::UPDATED; break;
    case static_cast<int>(NoteSortOrder::RELEVANCE): e = NoteSortOrder::RELEVANCE; break;
    case static_cast<int>(NoteSortOrder::UPDATE_SEQUENCE_NUMBER): e = NoteSortOrder::UPDATE_SEQUENCE_NUMBER; break;
    case static_cast<int>(NoteSortOrder::TITLE): e = NoteSortOrder::TITLE; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum NoteSortOrder"));
    }
}

void readEnumPremiumOrderStatus(ThriftBinaryBufferReader & r, PremiumOrderStatus::type & e) {
    qint32 i;
    r.readI32(i);
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

void readEnumSharedNotebookPrivilegeLevel(ThriftBinaryBufferReader & r, SharedNotebookPrivilegeLevel::type & e) {
    qint32 i;
    r.readI32(i);
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

void readEnumSharedNotePrivilegeLevel(ThriftBinaryBufferReader & r, SharedNotePrivilegeLevel::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(SharedNotePrivilegeLevel::READ_NOTE): e = SharedNotePrivilegeLevel::READ_NOTE; break;
    case static_cast<int>(SharedNotePrivilegeLevel::MODIFY_NOTE): e = SharedNotePrivilegeLevel::MODIFY_NOTE; break;
    case static_cast<int>(SharedNotePrivilegeLevel::FULL_ACCESS): e = SharedNotePrivilegeLevel::FULL_ACCESS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum SharedNotePrivilegeLevel"));
    }
}

void readEnumSponsoredGroupRole(ThriftBinaryBufferReader & r, SponsoredGroupRole::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(SponsoredGroupRole::GROUP_MEMBER): e = SponsoredGroupRole::GROUP_MEMBER; break;
    case static_cast<int>(SponsoredGroupRole::GROUP_ADMIN): e = SponsoredGroupRole::GROUP_ADMIN; break;
    case static_cast<int>(SponsoredGroupRole::GROUP_OWNER): e = SponsoredGroupRole::GROUP_OWNER; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum SponsoredGroupRole"));
    }
}

void readEnumBusinessUserRole(ThriftBinaryBufferReader & r, BusinessUserRole::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(BusinessUserRole::ADMIN): e = BusinessUserRole::ADMIN; break;
    case static_cast<int>(BusinessUserRole::NORMAL): e = BusinessUserRole::NORMAL; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum BusinessUserRole"));
    }
}

void readEnumBusinessUserStatus(ThriftBinaryBufferReader & r, BusinessUserStatus::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(BusinessUserStatus::ACTIVE): e = BusinessUserStatus::ACTIVE; break;
    case static_cast<int>(BusinessUserStatus::DEACTIVATED): e = BusinessUserStatus::DEACTIVATED; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum BusinessUserStatus"));
    }
}

void readEnumSharedNotebookInstanceRestrictions(ThriftBinaryBufferReader & r, SharedNotebookInstanceRestrictions::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(SharedNotebookInstanceRestrictions::ASSIGNED): e = SharedNotebookInstanceRestrictions::ASSIGNED; break;
    case static_cast<int>(SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS): e = SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum SharedNotebookInstanceRestrictions"));
    }
}

void readEnumReminderEmailConfig(ThriftBinaryBufferReader & r, ReminderEmailConfig::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(ReminderEmailConfig::DO_NOT_SEND): e = ReminderEmailConfig::DO_NOT_SEND; break;
    case static_cast<int>(ReminderEmailConfig::SEND_DAILY_EMAIL): e = ReminderEmailConfig::SEND_DAILY_EMAIL; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum ReminderEmailConfig"));
    }
}

void readEnumBusinessInvitationStatus(ThriftBinaryBufferReader & r, BusinessInvitationStatus::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(BusinessInvitationStatus::APPROVED): e = BusinessInvitationStatus::APPROVED; break;
    case static_cast<int>(BusinessInvitationStatus::REQUESTED): e = BusinessInvitationStatus::REQUESTED; break;
    case static_cast<int>(BusinessInvitationStatus::REDEEMED): e = BusinessInvitationStatus::REDEEMED; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum BusinessInvitationStatus"));
    }
}

void readEnumContactType(ThriftBinaryBufferReader & r, ContactType::type & e) {
    qint32 i;
    r.readI32(i);
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

void readEnumEntityType(ThriftBinaryBufferReader & r, EntityType::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(EntityType::NOTE): e = EntityType::NOTE; break;
    case static_cast<int>(EntityType::NOTEBOOK): e = EntityType::NOTEBOOK; break;
    case static_cast<int>(EntityType::WORKSPACE): e = EntityType::WORKSPACE; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum EntityType"));
    }
}

void readEnumRecipientStatus(ThriftBinaryBufferReader & r, RecipientStatus::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(RecipientStatus::NOT_IN_MY_LIST): e = RecipientStatus::NOT_IN_MY_LIST; break;
    case static_cast<int>(RecipientStatus::IN_MY_LIST): e = RecipientStatus::IN_MY_LIST; break;
    case static_cast<int>(RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK): e = RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum RecipientStatus"));
    }
}

void readEnumCanMoveToContainerStatus(ThriftBinaryBufferReader & r, CanMoveToContainerStatus::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(CanMoveToContainerStatus::CAN_BE_MOVED): e = CanMoveToContainerStatus::CAN_BE_MOVED; break;
    case static_cast<int>(CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE): e = CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE; break;
    case static_cast<int>(CanMoveToContainerStatus::INSUFFICIENT_CONTAINER_PRIVILEGE): e = CanMoveToContainerStatus::INSUFFICIENT_CONTAINER_PRIVILEGE; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum CanMoveToContainerStatus"));
    }
}

void readEnumRelatedContentType(ThriftBinaryBufferReader & r, RelatedContentType::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(RelatedContentType::NEWS_ARTICLE): e = RelatedContentType::NEWS_ARTICLE; break;
    case static_cast<int>(RelatedContentType::PROFILE_PERSON): e = RelatedContentType::PROFILE_PERSON; break;
    case static_cast<int>(RelatedContentType::PROFILE_ORGANIZATION): e = RelatedContentType::PROFILE_ORGANIZATION; break;
    case static_cast<int>(RelatedContentType::REFERENCE_MATERIAL): e = RelatedContentType::REFERENCE_MATERIAL; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum RelatedContentType"));
    }
}

void readEnumRelatedContentAccess(ThriftBinaryBufferReader & r, RelatedContentAccess::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(RelatedContentAccess::NOT_ACCESSIBLE): e = RelatedContentAccess::NOT_ACCESSIBLE; break;
    case static_cast<int>(RelatedContentAccess::DIRECT_LINK_ACCESS_OK): e = RelatedContentAccess::DIRECT_LINK_ACCESS_OK; break;
    case static_cast<int>(RelatedContentAccess::DIRECT_LINK_LOGIN_REQUIRED): e = RelatedContentAccess::DIRECT_LINK_LOGIN_REQUIRED; break;
    case static_cast<int>(RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW): e = RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum RelatedContentAccess"));
    }
}

void readEnumUserIdentityType(ThriftBinaryBufferReader & r, UserIdentityType::type & e) {
    qint32 i;
    r.readI32(i);
    switch(i) {
    case static_cast<int>(UserIdentityType::EVERNOTE_USERID): e = UserIdentityType::EVERNOTE_USERID; break;
    case static_cast<int>(UserIdentityType::EMAIL): e = UserIdentityType::EMAIL; break;
    case static_cast<int>(UserIdentityType::IDENTITYID): e = UserIdentityType::IDENTITYID; break;
    default: throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect value for enum UserIdentityType"));
    }
}

void writeSyncState(ThriftBinaryBufferWriter & w, const SyncState & s) {
    w.writeStructBegin(QStringLiteral("SyncState"));
    w.writeFieldBegin(QStringLiteral("currentTime"), ThriftFieldType::T_I64, 1);
    w.writeI64(s.currentTime);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("fullSyncBefore"), ThriftFieldType::T_I64, 2);
    w.writeI64(s.fullSyncBefore);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("updateCount"), ThriftFieldType::T_I32, 3);
    w.writeI32(s.updateCount);
    w.writeFieldEnd();
    if(s.uploaded.isSet()) {
        w.writeFieldBegin(QStringLiteral("uploaded"), ThriftFieldType::T_I64, 4);
        w.writeI64(s.uploaded.ref());
        w.writeFieldEnd();
    }
    if(s.userLastUpdated.isSet()) {
        w.writeFieldBegin(QStringLiteral("userLastUpdated"), ThriftFieldType::T_I64, 5);
        w.writeI64(s.userLastUpdated.ref());
        w.writeFieldEnd();
    }
    if(s.userMaxMessageEventId.isSet()) {
        w.writeFieldBegin(QStringLiteral("userMaxMessageEventId"), ThriftFieldType::T_I64, 6);
        w.writeI64(s.userMaxMessageEventId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSyncState(ThriftBinaryBufferReader & r, SyncState & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool currentTime_isset = false;
    bool fullSyncBefore_isset = false;
    bool updateCount_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                currentTime_isset = true;
                qint64 v;
                r.readI64(v);
                s.currentTime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                fullSyncBefore_isset = true;
                qint64 v;
                r.readI64(v);
                s.fullSyncBefore = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                updateCount_isset = true;
                qint32 v;
                r.readI32(v);
                s.updateCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.uploaded = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.userLastUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageEventID v;
                r.readI64(v);
                s.userMaxMessageEventId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!currentTime_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncState.currentTime has no value"));
    if(!fullSyncBefore_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncState.fullSyncBefore has no value"));
    if(!updateCount_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncState.updateCount has no value"));
}

void writeSyncChunk(ThriftBinaryBufferWriter & w, const SyncChunk & s) {
    w.writeStructBegin(QStringLiteral("SyncChunk"));
    w.writeFieldBegin(QStringLiteral("currentTime"), ThriftFieldType::T_I64, 1);
    w.writeI64(s.currentTime);
    w.writeFieldEnd();
    if(s.chunkHighUSN.isSet()) {
        w.writeFieldBegin(QStringLiteral("chunkHighUSN"), ThriftFieldType::T_I32, 2);
        w.writeI32(s.chunkHighUSN.ref());
        w.writeFieldEnd();
    }
    w.writeFieldBegin(QStringLiteral("updateCount"), ThriftFieldType::T_I32, 3);
    w.writeI32(s.updateCount);
    w.writeFieldEnd();
    if(s.notes.isSet()) {
        w.writeFieldBegin(QStringLiteral("notes"), ThriftFieldType::T_LIST, 4);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.notes.ref().length());
        for(QList< Note >::const_iterator it = s.notes.ref().constBegin(), end = s.notes.ref().constEnd(); it != end; ++it) {
            writeNote(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.notebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("notebooks"), ThriftFieldType::T_LIST, 5);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.notebooks.ref().length());
        for(QList< Notebook >::const_iterator it = s.notebooks.ref().constBegin(), end = s.notebooks.ref().constEnd(); it != end; ++it) {
            writeNotebook(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.tags.isSet()) {
        w.writeFieldBegin(QStringLiteral("tags"), ThriftFieldType::T_LIST, 6);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.tags.ref().length());
        for(QList< Tag >::const_iterator it = s.tags.ref().constBegin(), end = s.tags.ref().constEnd(); it != end; ++it) {
            writeTag(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.searches.isSet()) {
        w.writeFieldBegin(QStringLiteral("searches"), ThriftFieldType::T_LIST, 7);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.searches.ref().length());
        for(QList< SavedSearch >::const_iterator it = s.searches.ref().constBegin(), end = s.searches.ref().constEnd(); it != end; ++it) {
            writeSavedSearch(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.resources.isSet()) {
        w.writeFieldBegin(QStringLiteral("resources"), ThriftFieldType::T_LIST, 8);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.resources.ref().length());
        for(QList< Resource >::const_iterator it = s.resources.ref().constBegin(), end = s.resources.ref().constEnd(); it != end; ++it) {
            writeResource(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.expungedNotes.isSet()) {
        w.writeFieldBegin(QStringLiteral("expungedNotes"), ThriftFieldType::T_LIST, 9);
        w.writeListBegin(ThriftFieldType::T_STRING, s.expungedNotes.ref().length());
        for(QList< Guid >::const_iterator it = s.expungedNotes.ref().constBegin(), end = s.expungedNotes.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.expungedNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("expungedNotebooks"), ThriftFieldType::T_LIST, 10);
        w.writeListBegin(ThriftFieldType::T_STRING, s.expungedNotebooks.ref().length());
        for(QList< Guid >::const_iterator it = s.expungedNotebooks.ref().constBegin(), end = s.expungedNotebooks.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.expungedTags.isSet()) {
        w.writeFieldBegin(QStringLiteral("expungedTags"), ThriftFieldType::T_LIST, 11);
        w.writeListBegin(ThriftFieldType::T_STRING, s.expungedTags.ref().length());
        for(QList< Guid >::const_iterator it = s.expungedTags.ref().constBegin(), end = s.expungedTags.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.expungedSearches.isSet()) {
        w.writeFieldBegin(QStringLiteral("expungedSearches"), ThriftFieldType::T_LIST, 12);
        w.writeListBegin(ThriftFieldType::T_STRING, s.expungedSearches.ref().length());
        for(QList< Guid >::const_iterator it = s.expungedSearches.ref().constBegin(), end = s.expungedSearches.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.linkedNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("linkedNotebooks"), ThriftFieldType::T_LIST, 13);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.linkedNotebooks.ref().length());
        for(QList< LinkedNotebook >::const_iterator it = s.linkedNotebooks.ref().constBegin(), end = s.linkedNotebooks.ref().constEnd(); it != end; ++it) {
            writeLinkedNotebook(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.expungedLinkedNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("expungedLinkedNotebooks"), ThriftFieldType::T_LIST, 14);
        w.writeListBegin(ThriftFieldType::T_STRING, s.expungedLinkedNotebooks.ref().length());
        for(QList< Guid >::const_iterator it = s.expungedLinkedNotebooks.ref().constBegin(), end = s.expungedLinkedNotebooks.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSyncChunk(ThriftBinaryBufferReader & r, SyncChunk & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool currentTime_isset = false;
    bool updateCount_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                currentTime_isset = true;
                qint64 v;
                r.readI64(v);
                s.currentTime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.chunkHighUSN = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                updateCount_isset = true;
                qint32 v;
                r.readI32(v);
                s.updateCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Note > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.notes)"));
                for(qint32 i = 0; i < size; i++) {
                    Note elem;
                    readNote(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.notes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Notebook > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.notebooks)"));
                for(qint32 i = 0; i < size; i++) {
                    Notebook elem;
                    readNotebook(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.notebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Tag > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.tags)"));
                for(qint32 i = 0; i < size; i++) {
                    Tag elem;
                    readTag(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.tags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< SavedSearch > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.searches)"));
                for(qint32 i = 0; i < size; i++) {
                    SavedSearch elem;
                    readSavedSearch(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.searches = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Resource > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.resources)"));
                for(qint32 i = 0; i < size; i++) {
                    Resource elem;
                    readResource(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.resources = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Guid > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.expungedNotes)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.expungedNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Guid > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.expungedNotebooks)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.expungedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Guid > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.expungedTags)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.expungedTags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Guid > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.expungedSearches)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.expungedSearches = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< LinkedNotebook > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.linkedNotebooks)"));
                for(qint32 i = 0; i < size; i++) {
                    LinkedNotebook elem;
                    readLinkedNotebook(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.linkedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Guid > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SyncChunk.expungedLinkedNotebooks)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.expungedLinkedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!currentTime_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncChunk.currentTime has no value"));
    if(!updateCount_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("SyncChunk.updateCount has no value"));
}

void writeSyncChunkFilter(ThriftBinaryBufferWriter & w, const SyncChunkFilter & s) {
    w.writeStructBegin(QStringLiteral("SyncChunkFilter"));
    if(s.includeNotes.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeNotes"), ThriftFieldType::T_BOOL, 1);
        w.writeBool(s.includeNotes.ref());
        w.writeFieldEnd();
    }
    if(s.includeNoteResources.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeNoteResources"), ThriftFieldType::T_BOOL, 2);
        w.writeBool(s.includeNoteResources.ref());
        w.writeFieldEnd();
    }
    if(s.includeNoteAttributes.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeNoteAttributes"), ThriftFieldType::T_BOOL, 3);
        w.writeBool(s.includeNoteAttributes.ref());
        w.writeFieldEnd();
    }
    if(s.includeNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeNotebooks"), ThriftFieldType::T_BOOL, 4);
        w.writeBool(s.includeNotebooks.ref());
        w.writeFieldEnd();
    }
    if(s.includeTags.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeTags"), ThriftFieldType::T_BOOL, 5);
        w.writeBool(s.includeTags.ref());
        w.writeFieldEnd();
    }
    if(s.includeSearches.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeSearches"), ThriftFieldType::T_BOOL, 6);
        w.writeBool(s.includeSearches.ref());
        w.writeFieldEnd();
    }
    if(s.includeResources.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeResources"), ThriftFieldType::T_BOOL, 7);
        w.writeBool(s.includeResources.ref());
        w.writeFieldEnd();
    }
    if(s.includeLinkedNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeLinkedNotebooks"), ThriftFieldType::T_BOOL, 8);
        w.writeBool(s.includeLinkedNotebooks.ref());
        w.writeFieldEnd();
    }
    if(s.includeExpunged.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeExpunged"), ThriftFieldType::T_BOOL, 9);
        w.writeBool(s.includeExpunged.ref());
        w.writeFieldEnd();
    }
    if(s.includeNoteApplicationDataFullMap.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeNoteApplicationDataFullMap"), ThriftFieldType::T_BOOL, 10);
        w.writeBool(s.includeNoteApplicationDataFullMap.ref());
        w.writeFieldEnd();
    }
    if(s.includeResourceApplicationDataFullMap.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeResourceApplicationDataFullMap"), ThriftFieldType::T_BOOL, 12);
        w.writeBool(s.includeResourceApplicationDataFullMap.ref());
        w.writeFieldEnd();
    }
    if(s.includeNoteResourceApplicationDataFullMap.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeNoteResourceApplicationDataFullMap"), ThriftFieldType::T_BOOL, 13);
        w.writeBool(s.includeNoteResourceApplicationDataFullMap.ref());
        w.writeFieldEnd();
    }
    if(s.includeSharedNotes.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeSharedNotes"), ThriftFieldType::T_BOOL, 17);
        w.writeBool(s.includeSharedNotes.ref());
        w.writeFieldEnd();
    }
    if(s.omitSharedNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("omitSharedNotebooks"), ThriftFieldType::T_BOOL, 16);
        w.writeBool(s.omitSharedNotebooks.ref());
        w.writeFieldEnd();
    }
    if(s.requireNoteContentClass.isSet()) {
        w.writeFieldBegin(QStringLiteral("requireNoteContentClass"), ThriftFieldType::T_STRING, 11);
        w.writeString(s.requireNoteContentClass.ref());
        w.writeFieldEnd();
    }
    if(s.notebookGuids.isSet()) {
        w.writeFieldBegin(QStringLiteral("notebookGuids"), ThriftFieldType::T_SET, 15);
        w.writeSetBegin(ThriftFieldType::T_STRING, s.notebookGuids.ref().count());
        for(QSet< QString >::const_iterator it = s.notebookGuids.ref().constBegin(), end = s.notebookGuids.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeSetEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSyncChunkFilter(ThriftBinaryBufferReader & r, SyncChunkFilter & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNoteResources = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNoteAttributes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeTags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeSearches = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeResources = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeLinkedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeExpunged = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNoteApplicationDataFullMap = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeResourceApplicationDataFullMap = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNoteResourceApplicationDataFullMap = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeSharedNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.omitSharedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.requireNoteContentClass = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_SET) {
                QSet< QString > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readSetBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect set type (SyncChunkFilter.notebookGuids)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.insert(elem);
                }
                r.readSetEnd();
                s.notebookGuids = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNoteFilter(ThriftBinaryBufferWriter & w, const NoteFilter & s) {
    w.writeStructBegin(QStringLiteral("NoteFilter"));
    if(s.order.isSet()) {
        w.writeFieldBegin(QStringLiteral("order"), ThriftFieldType::T_I32, 1);
        w.writeI32(s.order.ref());
        w.writeFieldEnd();
    }
    if(s.ascending.isSet()) {
        w.writeFieldBegin(QStringLiteral("ascending"), ThriftFieldType::T_BOOL, 2);
        w.writeBool(s.ascending.ref());
        w.writeFieldEnd();
    }
    if(s.words.isSet()) {
        w.writeFieldBegin(QStringLiteral("words"), ThriftFieldType::T_STRING, 3);
        w.writeString(s.words.ref());
        w.writeFieldEnd();
    }
    if(s.notebookGuid.isSet()) {
        w.writeFieldBegin(QStringLiteral("notebookGuid"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.notebookGuid.ref());
        w.writeFieldEnd();
    }
    if(s.tagGuids.isSet()) {
        w.writeFieldBegin(QStringLiteral("tagGuids"), ThriftFieldType::T_LIST, 5);
        w.writeListBegin(ThriftFieldType::T_STRING, s.tagGuids.ref().length());
        for(QList< Guid >::const_iterator it = s.tagGuids.ref().constBegin(), end = s.tagGuids.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.timeZone.isSet()) {
        w.writeFieldBegin(QStringLiteral("timeZone"), ThriftFieldType::T_STRING, 6);
        w.writeString(s.timeZone.ref());
        w.writeFieldEnd();
    }
    if(s.inactive.isSet()) {
        w.writeFieldBegin(QStringLiteral("inactive"), ThriftFieldType::T_BOOL, 7);
        w.writeBool(s.inactive.ref());
        w.writeFieldEnd();
    }
    if(s.emphasized.isSet()) {
        w.writeFieldBegin(QStringLiteral("emphasized"), ThriftFieldType::T_STRING, 8);
        w.writeString(s.emphasized.ref());
        w.writeFieldEnd();
    }
    if(s.includeAllReadableNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeAllReadableNotebooks"), ThriftFieldType::T_BOOL, 9);
        w.writeBool(s.includeAllReadableNotebooks.ref());
        w.writeFieldEnd();
    }
    if(s.includeAllReadableWorkspaces.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeAllReadableWorkspaces"), ThriftFieldType::T_BOOL, 15);
        w.writeBool(s.includeAllReadableWorkspaces.ref());
        w.writeFieldEnd();
    }
    if(s.context.isSet()) {
        w.writeFieldBegin(QStringLiteral("context"), ThriftFieldType::T_STRING, 10);
        w.writeString(s.context.ref());
        w.writeFieldEnd();
    }
    if(s.rawWords.isSet()) {
        w.writeFieldBegin(QStringLiteral("rawWords"), ThriftFieldType::T_STRING, 11);
        w.writeString(s.rawWords.ref());
        w.writeFieldEnd();
    }
    if(s.searchContextBytes.isSet()) {
        w.writeFieldBegin(QStringLiteral("searchContextBytes"), ThriftFieldType::T_STRING, 12);
        w.writeBinary(s.searchContextBytes.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteFilter(ThriftBinaryBufferReader & r, NoteFilter & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.order = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.ascending = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.words = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.notebookGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Guid > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteFilter.tagGuids)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.tagGuids = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.timeZone = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.inactive = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.emphasized = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeAllReadableNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeAllReadableWorkspaces = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.context = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.rawWords = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                r.readBinary(v);
                s.searchContextBytes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNoteList(ThriftBinaryBufferWriter & w, const NoteList & s) {
    w.writeStructBegin(QStringLiteral("NoteList"));
    w.writeFieldBegin(QStringLiteral("startIndex"), ThriftFieldType::T_I32, 1);
    w.writeI32(s.startIndex);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("totalNotes"), ThriftFieldType::T_I32, 2);
    w.writeI32(s.totalNotes);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("notes"), ThriftFieldType::T_LIST, 3);
    w.writeListBegin(ThriftFieldType::T_STRUCT, s.notes.length());
    for(QList< Note >::const_iterator it = s.notes.constBegin(), end = s.notes.constEnd(); it != end; ++it) {
        writeNote(w, *it);
    }
    w.writeListEnd();
    w.writeFieldEnd();
    if(s.stoppedWords.isSet()) {
        w.writeFieldBegin(QStringLiteral("stoppedWords"), ThriftFieldType::T_LIST, 4);
        w.writeListBegin(ThriftFieldType::T_STRING, s.stoppedWords.ref().length());
        for(QStringList::const_iterator it = s.stoppedWords.ref().constBegin(), end = s.stoppedWords.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.searchedWords.isSet()) {
        w.writeFieldBegin(QStringLiteral("searchedWords"), ThriftFieldType::T_LIST, 5);
        w.writeListBegin(ThriftFieldType::T_STRING, s.searchedWords.ref().length());
        for(QStringList::const_iterator it = s.searchedWords.ref().constBegin(), end = s.searchedWords.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.updateCount.isSet()) {
        w.writeFieldBegin(QStringLiteral("updateCount"), ThriftFieldType::T_I32, 6);
        w.writeI32(s.updateCount.ref());
        w.writeFieldEnd();
    }
    if(s.searchContextBytes.isSet()) {
        w.writeFieldBegin(QStringLiteral("searchContextBytes"), ThriftFieldType::T_STRING, 7);
        w.writeBinary(s.searchContextBytes.ref());
        w.writeFieldEnd();
    }
    if(s.debugInfo.isSet()) {
        w.writeFieldBegin(QStringLiteral("debugInfo"), ThriftFieldType::T_STRING, 8);
        w.writeString(s.debugInfo.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteList(ThriftBinaryBufferReader & r, NoteList & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool startIndex_isset = false;
    bool totalNotes_isset = false;
    bool notes_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                startIndex_isset = true;
                qint32 v;
                r.readI32(v);
                s.startIndex = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                totalNotes_isset = true;
                qint32 v;
                r.readI32(v);
                s.totalNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                notes_isset = true;
                QList< Note > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteList.notes)"));
                for(qint32 i = 0; i < size; i++) {
                    Note elem;
                    readNote(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.notes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteList.stoppedWords)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.stoppedWords = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteList.searchedWords)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.searchedWords = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                r.readBinary(v);
                s.searchContextBytes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.debugInfo = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!startIndex_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteList.startIndex has no value"));
    if(!totalNotes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteList.totalNotes has no value"));
    if(!notes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteList.notes has no value"));
}

void writeNoteMetadata(ThriftBinaryBufferWriter & w, const NoteMetadata & s) {
    w.writeStructBegin(QStringLiteral("NoteMetadata"));
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 1);
    w.writeString(s.guid);
    w.writeFieldEnd();
    if(s.title.isSet()) {
        w.writeFieldBegin(QStringLiteral("title"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.title.ref());
        w.writeFieldEnd();
    }
    if(s.contentLength.isSet()) {
        w.writeFieldBegin(QStringLiteral("contentLength"), ThriftFieldType::T_I32, 5);
        w.writeI32(s.contentLength.ref());
        w.writeFieldEnd();
    }
    if(s.created.isSet()) {
        w.writeFieldBegin(QStringLiteral("created"), ThriftFieldType::T_I64, 6);
        w.writeI64(s.created.ref());
        w.writeFieldEnd();
    }
    if(s.updated.isSet()) {
        w.writeFieldBegin(QStringLiteral("updated"), ThriftFieldType::T_I64, 7);
        w.writeI64(s.updated.ref());
        w.writeFieldEnd();
    }
    if(s.deleted.isSet()) {
        w.writeFieldBegin(QStringLiteral("deleted"), ThriftFieldType::T_I64, 8);
        w.writeI64(s.deleted.ref());
        w.writeFieldEnd();
    }
    if(s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(QStringLiteral("updateSequenceNum"), ThriftFieldType::T_I32, 10);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if(s.notebookGuid.isSet()) {
        w.writeFieldBegin(QStringLiteral("notebookGuid"), ThriftFieldType::T_STRING, 11);
        w.writeString(s.notebookGuid.ref());
        w.writeFieldEnd();
    }
    if(s.tagGuids.isSet()) {
        w.writeFieldBegin(QStringLiteral("tagGuids"), ThriftFieldType::T_LIST, 12);
        w.writeListBegin(ThriftFieldType::T_STRING, s.tagGuids.ref().length());
        for(QList< Guid >::const_iterator it = s.tagGuids.ref().constBegin(), end = s.tagGuids.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.attributes.isSet()) {
        w.writeFieldBegin(QStringLiteral("attributes"), ThriftFieldType::T_STRUCT, 14);
        writeNoteAttributes(w, s.attributes.ref());
        w.writeFieldEnd();
    }
    if(s.largestResourceMime.isSet()) {
        w.writeFieldBegin(QStringLiteral("largestResourceMime"), ThriftFieldType::T_STRING, 20);
        w.writeString(s.largestResourceMime.ref());
        w.writeFieldEnd();
    }
    if(s.largestResourceSize.isSet()) {
        w.writeFieldBegin(QStringLiteral("largestResourceSize"), ThriftFieldType::T_I32, 21);
        w.writeI32(s.largestResourceSize.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteMetadata(ThriftBinaryBufferReader & r, NoteMetadata & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool guid_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                guid_isset = true;
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.title = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.contentLength = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.created = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.updated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.deleted = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.notebookGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Guid > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteMetadata.tagGuids)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.tagGuids = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteAttributes v;
                readNoteAttributes(r, v);
                s.attributes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.largestResourceMime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.largestResourceSize = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!guid_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteMetadata.guid has no value"));
}

void writeNotesMetadataList(ThriftBinaryBufferWriter & w, const NotesMetadataList & s) {
    w.writeStructBegin(QStringLiteral("NotesMetadataList"));
    w.writeFieldBegin(QStringLiteral("startIndex"), ThriftFieldType::T_I32, 1);
    w.writeI32(s.startIndex);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("totalNotes"), ThriftFieldType::T_I32, 2);
    w.writeI32(s.totalNotes);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("notes"), ThriftFieldType::T_LIST, 3);
    w.writeListBegin(ThriftFieldType::T_STRUCT, s.notes.length());
    for(QList< NoteMetadata >::const_iterator it = s.notes.constBegin(), end = s.notes.constEnd(); it != end; ++it) {
        writeNoteMetadata(w, *it);
    }
    w.writeListEnd();
    w.writeFieldEnd();
    if(s.stoppedWords.isSet()) {
        w.writeFieldBegin(QStringLiteral("stoppedWords"), ThriftFieldType::T_LIST, 4);
        w.writeListBegin(ThriftFieldType::T_STRING, s.stoppedWords.ref().length());
        for(QStringList::const_iterator it = s.stoppedWords.ref().constBegin(), end = s.stoppedWords.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.searchedWords.isSet()) {
        w.writeFieldBegin(QStringLiteral("searchedWords"), ThriftFieldType::T_LIST, 5);
        w.writeListBegin(ThriftFieldType::T_STRING, s.searchedWords.ref().length());
        for(QStringList::const_iterator it = s.searchedWords.ref().constBegin(), end = s.searchedWords.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.updateCount.isSet()) {
        w.writeFieldBegin(QStringLiteral("updateCount"), ThriftFieldType::T_I32, 6);
        w.writeI32(s.updateCount.ref());
        w.writeFieldEnd();
    }
    if(s.searchContextBytes.isSet()) {
        w.writeFieldBegin(QStringLiteral("searchContextBytes"), ThriftFieldType::T_STRING, 7);
        w.writeBinary(s.searchContextBytes.ref());
        w.writeFieldEnd();
    }
    if(s.debugInfo.isSet()) {
        w.writeFieldBegin(QStringLiteral("debugInfo"), ThriftFieldType::T_STRING, 9);
        w.writeString(s.debugInfo.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNotesMetadataList(ThriftBinaryBufferReader & r, NotesMetadataList & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool startIndex_isset = false;
    bool totalNotes_isset = false;
    bool notes_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                startIndex_isset = true;
                qint32 v;
                r.readI32(v);
                s.startIndex = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                totalNotes_isset = true;
                qint32 v;
                r.readI32(v);
                s.totalNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                notes_isset = true;
                QList< NoteMetadata > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NotesMetadataList.notes)"));
                for(qint32 i = 0; i < size; i++) {
                    NoteMetadata elem;
                    readNoteMetadata(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.notes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NotesMetadataList.stoppedWords)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.stoppedWords = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NotesMetadataList.searchedWords)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.searchedWords = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                r.readBinary(v);
                s.searchContextBytes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.debugInfo = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!startIndex_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NotesMetadataList.startIndex has no value"));
    if(!totalNotes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NotesMetadataList.totalNotes has no value"));
    if(!notes_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NotesMetadataList.notes has no value"));
}

void writeNotesMetadataResultSpec(ThriftBinaryBufferWriter & w, const NotesMetadataResultSpec & s) {
    w.writeStructBegin(QStringLiteral("NotesMetadataResultSpec"));
    if(s.includeTitle.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeTitle"), ThriftFieldType::T_BOOL, 2);
        w.writeBool(s.includeTitle.ref());
        w.writeFieldEnd();
    }
    if(s.includeContentLength.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeContentLength"), ThriftFieldType::T_BOOL, 5);
        w.writeBool(s.includeContentLength.ref());
        w.writeFieldEnd();
    }
    if(s.includeCreated.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeCreated"), ThriftFieldType::T_BOOL, 6);
        w.writeBool(s.includeCreated.ref());
        w.writeFieldEnd();
    }
    if(s.includeUpdated.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeUpdated"), ThriftFieldType::T_BOOL, 7);
        w.writeBool(s.includeUpdated.ref());
        w.writeFieldEnd();
    }
    if(s.includeDeleted.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeDeleted"), ThriftFieldType::T_BOOL, 8);
        w.writeBool(s.includeDeleted.ref());
        w.writeFieldEnd();
    }
    if(s.includeUpdateSequenceNum.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeUpdateSequenceNum"), ThriftFieldType::T_BOOL, 10);
        w.writeBool(s.includeUpdateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if(s.includeNotebookGuid.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeNotebookGuid"), ThriftFieldType::T_BOOL, 11);
        w.writeBool(s.includeNotebookGuid.ref());
        w.writeFieldEnd();
    }
    if(s.includeTagGuids.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeTagGuids"), ThriftFieldType::T_BOOL, 12);
        w.writeBool(s.includeTagGuids.ref());
        w.writeFieldEnd();
    }
    if(s.includeAttributes.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeAttributes"), ThriftFieldType::T_BOOL, 14);
        w.writeBool(s.includeAttributes.ref());
        w.writeFieldEnd();
    }
    if(s.includeLargestResourceMime.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeLargestResourceMime"), ThriftFieldType::T_BOOL, 20);
        w.writeBool(s.includeLargestResourceMime.ref());
        w.writeFieldEnd();
    }
    if(s.includeLargestResourceSize.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeLargestResourceSize"), ThriftFieldType::T_BOOL, 21);
        w.writeBool(s.includeLargestResourceSize.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNotesMetadataResultSpec(ThriftBinaryBufferReader & r, NotesMetadataResultSpec & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeTitle = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeContentLength = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeCreated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeDeleted = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeUpdateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNotebookGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeTagGuids = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeAttributes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeLargestResourceMime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeLargestResourceSize = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNoteCollectionCounts(ThriftBinaryBufferWriter & w, const NoteCollectionCounts & s) {
    w.writeStructBegin(QStringLiteral("NoteCollectionCounts"));
    if(s.notebookCounts.isSet()) {
        w.writeFieldBegin(QStringLiteral("notebookCounts"), ThriftFieldType::T_MAP, 1);
        w.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_I32, s.notebookCounts.ref().size());
        for(QMap< Guid, qint32 >::const_iterator it = s.notebookCounts.ref().constBegin(), end = s.notebookCounts.ref().constEnd(); it != end; ++it) {
            w.writeString(it.key());
            w.writeI32(it.value());
        }
        w.writeMapEnd();
        w.writeFieldEnd();
    }
    if(s.tagCounts.isSet()) {
        w.writeFieldBegin(QStringLiteral("tagCounts"), ThriftFieldType::T_MAP, 2);
        w.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_I32, s.tagCounts.ref().size());
        for(QMap< Guid, qint32 >::const_iterator it = s.tagCounts.ref().constBegin(), end = s.tagCounts.ref().constEnd(); it != end; ++it) {
            w.writeString(it.key());
            w.writeI32(it.value());
        }
        w.writeMapEnd();
        w.writeFieldEnd();
    }
    if(s.trashCount.isSet()) {
        w.writeFieldBegin(QStringLiteral("trashCount"), ThriftFieldType::T_I32, 3);
        w.writeI32(s.trashCount.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteCollectionCounts(ThriftBinaryBufferReader & r, NoteCollectionCounts & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap< Guid, qint32 > v;
                qint32 size;
                ThriftFieldType::type keyType;
                ThriftFieldType::type elemType;
                r.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (NoteCollectionCounts.notebookCounts)"));
                if (elemType != ThriftFieldType::T_I32) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (NoteCollectionCounts.notebookCounts)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid key;
                    r.readString(key);
                    qint32 value;
                    r.readI32(value);
                    v[key] = value;
                }
                r.readMapEnd();
                s.notebookCounts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap< Guid, qint32 > v;
                qint32 size;
                ThriftFieldType::type keyType;
                ThriftFieldType::type elemType;
                r.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (NoteCollectionCounts.tagCounts)"));
                if (elemType != ThriftFieldType::T_I32) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (NoteCollectionCounts.tagCounts)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid key;
                    r.readString(key);
                    qint32 value;
                    r.readI32(value);
                    v[key] = value;
                }
                r.readMapEnd();
                s.tagCounts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.trashCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNoteResultSpec(ThriftBinaryBufferWriter & w, const NoteResultSpec & s) {
    w.writeStructBegin(QStringLiteral("NoteResultSpec"));
    if(s.includeContent.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeContent"), ThriftFieldType::T_BOOL, 1);
        w.writeBool(s.includeContent.ref());
        w.writeFieldEnd();
    }
    if(s.includeResourcesData.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeResourcesData"), ThriftFieldType::T_BOOL, 2);
        w.writeBool(s.includeResourcesData.ref());
        w.writeFieldEnd();
    }
    if(s.includeResourcesRecognition.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeResourcesRecognition"), ThriftFieldType::T_BOOL, 3);
        w.writeBool(s.includeResourcesRecognition.ref());
        w.writeFieldEnd();
    }
    if(s.includeResourcesAlternateData.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeResourcesAlternateData"), ThriftFieldType::T_BOOL, 4);
        w.writeBool(s.includeResourcesAlternateData.ref());
        w.writeFieldEnd();
    }
    if(s.includeSharedNotes.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeSharedNotes"), ThriftFieldType::T_BOOL, 5);
        w.writeBool(s.includeSharedNotes.ref());
        w.writeFieldEnd();
    }
    if(s.includeNoteAppDataValues.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeNoteAppDataValues"), ThriftFieldType::T_BOOL, 6);
        w.writeBool(s.includeNoteAppDataValues.ref());
        w.writeFieldEnd();
    }
    if(s.includeResourceAppDataValues.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeResourceAppDataValues"), ThriftFieldType::T_BOOL, 7);
        w.writeBool(s.includeResourceAppDataValues.ref());
        w.writeFieldEnd();
    }
    if(s.includeAccountLimits.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeAccountLimits"), ThriftFieldType::T_BOOL, 8);
        w.writeBool(s.includeAccountLimits.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteResultSpec(ThriftBinaryBufferReader & r, NoteResultSpec & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeContent = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeResourcesData = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeResourcesRecognition = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeResourcesAlternateData = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeSharedNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeNoteAppDataValues = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeResourceAppDataValues = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeAccountLimits = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNoteEmailParameters(ThriftBinaryBufferWriter & w, const NoteEmailParameters & s) {
    w.writeStructBegin(QStringLiteral("NoteEmailParameters"));
    if(s.guid.isSet()) {
        w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if(s.note.isSet()) {
        w.writeFieldBegin(QStringLiteral("note"), ThriftFieldType::T_STRUCT, 2);
        writeNote(w, s.note.ref());
        w.writeFieldEnd();
    }
    if(s.toAddresses.isSet()) {
        w.writeFieldBegin(QStringLiteral("toAddresses"), ThriftFieldType::T_LIST, 3);
        w.writeListBegin(ThriftFieldType::T_STRING, s.toAddresses.ref().length());
        for(QStringList::const_iterator it = s.toAddresses.ref().constBegin(), end = s.toAddresses.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.ccAddresses.isSet()) {
        w.writeFieldBegin(QStringLiteral("ccAddresses"), ThriftFieldType::T_LIST, 4);
        w.writeListBegin(ThriftFieldType::T_STRING, s.ccAddresses.ref().length());
        for(QStringList::const_iterator it = s.ccAddresses.ref().constBegin(), end = s.ccAddresses.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.subject.isSet()) {
        w.writeFieldBegin(QStringLiteral("subject"), ThriftFieldType::T_STRING, 5);
        w.writeString(s.subject.ref());
        w.writeFieldEnd();
    }
    if(s.message.isSet()) {
        w.writeFieldBegin(QStringLiteral("message"), ThriftFieldType::T_STRING, 6);
        w.writeString(s.message.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteEmailParameters(ThriftBinaryBufferReader & r, NoteEmailParameters & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Note v;
                readNote(r, v);
                s.note = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteEmailParameters.toAddresses)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.toAddresses = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteEmailParameters.ccAddresses)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.ccAddresses = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.subject = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.message = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNoteVersionId(ThriftBinaryBufferWriter & w, const NoteVersionId & s) {
    w.writeStructBegin(QStringLiteral("NoteVersionId"));
    w.writeFieldBegin(QStringLiteral("updateSequenceNum"), ThriftFieldType::T_I32, 1);
    w.writeI32(s.updateSequenceNum);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("updated"), ThriftFieldType::T_I64, 2);
    w.writeI64(s.updated);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("saved"), ThriftFieldType::T_I64, 3);
    w.writeI64(s.saved);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("title"), ThriftFieldType::T_STRING, 4);
    w.writeString(s.title);
    w.writeFieldEnd();
    if(s.lastEditorId.isSet()) {
        w.writeFieldBegin(QStringLiteral("lastEditorId"), ThriftFieldType::T_I32, 5);
        w.writeI32(s.lastEditorId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteVersionId(ThriftBinaryBufferReader & r, NoteVersionId & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool updateSequenceNum_isset = false;
    bool updated_isset = false;
    bool saved_isset = false;
    bool title_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                updateSequenceNum_isset = true;
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                updated_isset = true;
                qint64 v;
                r.readI64(v);
                s.updated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                saved_isset = true;
                qint64 v;
                r.readI64(v);
                s.saved = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                title_isset = true;
                QString v;
                r.readString(v);
                s.title = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.lastEditorId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!updateSequenceNum_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.updateSequenceNum has no value"));
    if(!updated_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.updated has no value"));
    if(!saved_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.saved has no value"));
    if(!title_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("NoteVersionId.title has no value"));
}

void writeRelatedQuery(ThriftBinaryBufferWriter & w, const RelatedQuery & s) {
    w.writeStructBegin(QStringLiteral("RelatedQuery"));
    if(s.noteGuid.isSet()) {
        w.writeFieldBegin(QStringLiteral("noteGuid"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.noteGuid.ref());
        w.writeFieldEnd();
    }
    if(s.plainText.isSet()) {
        w.writeFieldBegin(QStringLiteral("plainText"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.plainText.ref());
        w.writeFieldEnd();
    }
    if(s.filter.isSet()) {
        w.writeFieldBegin(QStringLiteral("filter"), ThriftFieldType::T_STRUCT, 3);
        writeNoteFilter(w, s.filter.ref());
        w.writeFieldEnd();
    }
    if(s.referenceUri.isSet()) {
        w.writeFieldBegin(QStringLiteral("referenceUri"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.referenceUri.ref());
        w.writeFieldEnd();
    }
    if(s.context.isSet()) {
        w.writeFieldBegin(QStringLiteral("context"), ThriftFieldType::T_STRING, 5);
        w.writeString(s.context.ref());
        w.writeFieldEnd();
    }
    if(s.cacheKey.isSet()) {
        w.writeFieldBegin(QStringLiteral("cacheKey"), ThriftFieldType::T_STRING, 6);
        w.writeString(s.cacheKey.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readRelatedQuery(ThriftBinaryBufferReader & r, RelatedQuery & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.noteGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.plainText = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteFilter v;
                readNoteFilter(r, v);
                s.filter = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.referenceUri = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.context = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.cacheKey = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeRelatedResult(ThriftBinaryBufferWriter & w, const RelatedResult & s) {
    w.writeStructBegin(QStringLiteral("RelatedResult"));
    if(s.notes.isSet()) {
        w.writeFieldBegin(QStringLiteral("notes"), ThriftFieldType::T_LIST, 1);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.notes.ref().length());
        for(QList< Note >::const_iterator it = s.notes.ref().constBegin(), end = s.notes.ref().constEnd(); it != end; ++it) {
            writeNote(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.notebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("notebooks"), ThriftFieldType::T_LIST, 2);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.notebooks.ref().length());
        for(QList< Notebook >::const_iterator it = s.notebooks.ref().constBegin(), end = s.notebooks.ref().constEnd(); it != end; ++it) {
            writeNotebook(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.tags.isSet()) {
        w.writeFieldBegin(QStringLiteral("tags"), ThriftFieldType::T_LIST, 3);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.tags.ref().length());
        for(QList< Tag >::const_iterator it = s.tags.ref().constBegin(), end = s.tags.ref().constEnd(); it != end; ++it) {
            writeTag(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.containingNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("containingNotebooks"), ThriftFieldType::T_LIST, 4);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.containingNotebooks.ref().length());
        for(QList< NotebookDescriptor >::const_iterator it = s.containingNotebooks.ref().constBegin(), end = s.containingNotebooks.ref().constEnd(); it != end; ++it) {
            writeNotebookDescriptor(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.debugInfo.isSet()) {
        w.writeFieldBegin(QStringLiteral("debugInfo"), ThriftFieldType::T_STRING, 5);
        w.writeString(s.debugInfo.ref());
        w.writeFieldEnd();
    }
    if(s.experts.isSet()) {
        w.writeFieldBegin(QStringLiteral("experts"), ThriftFieldType::T_LIST, 6);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.experts.ref().length());
        for(QList< UserProfile >::const_iterator it = s.experts.ref().constBegin(), end = s.experts.ref().constEnd(); it != end; ++it) {
            writeUserProfile(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.relatedContent.isSet()) {
        w.writeFieldBegin(QStringLiteral("relatedContent"), ThriftFieldType::T_LIST, 7);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.relatedContent.ref().length());
        for(QList< RelatedContent >::const_iterator it = s.relatedContent.ref().constBegin(), end = s.relatedContent.ref().constEnd(); it != end; ++it) {
            writeRelatedContent(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.cacheKey.isSet()) {
        w.writeFieldBegin(QStringLiteral("cacheKey"), ThriftFieldType::T_STRING, 8);
        w.writeString(s.cacheKey.ref());
        w.writeFieldEnd();
    }
    if(s.cacheExpires.isSet()) {
        w.writeFieldBegin(QStringLiteral("cacheExpires"), ThriftFieldType::T_I32, 9);
        w.writeI32(s.cacheExpires.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readRelatedResult(ThriftBinaryBufferReader & r, RelatedResult & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Note > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedResult.notes)"));
                for(qint32 i = 0; i < size; i++) {
                    Note elem;
                    readNote(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.notes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Notebook > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedResult.notebooks)"));
                for(qint32 i = 0; i < size; i++) {
                    Notebook elem;
                    readNotebook(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.notebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Tag > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedResult.tags)"));
                for(qint32 i = 0; i < size; i++) {
                    Tag elem;
                    readTag(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.tags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< NotebookDescriptor > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedResult.containingNotebooks)"));
                for(qint32 i = 0; i < size; i++) {
                    NotebookDescriptor elem;
                    readNotebookDescriptor(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.containingNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.debugInfo = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< UserProfile > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedResult.experts)"));
                for(qint32 i = 0; i < size; i++) {
                    UserProfile elem;
                    readUserProfile(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.experts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< RelatedContent > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedResult.relatedContent)"));
                for(qint32 i = 0; i < size; i++) {
                    RelatedContent elem;
                    readRelatedContent(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.relatedContent = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.cacheKey = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.cacheExpires = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeRelatedResultSpec(ThriftBinaryBufferWriter & w, const RelatedResultSpec & s) {
    w.writeStructBegin(QStringLiteral("RelatedResultSpec"));
    if(s.maxNotes.isSet()) {
        w.writeFieldBegin(QStringLiteral("maxNotes"), ThriftFieldType::T_I32, 1);
        w.writeI32(s.maxNotes.ref());
        w.writeFieldEnd();
    }
    if(s.maxNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("maxNotebooks"), ThriftFieldType::T_I32, 2);
        w.writeI32(s.maxNotebooks.ref());
        w.writeFieldEnd();
    }
    if(s.maxTags.isSet()) {
        w.writeFieldBegin(QStringLiteral("maxTags"), ThriftFieldType::T_I32, 3);
        w.writeI32(s.maxTags.ref());
        w.writeFieldEnd();
    }
    if(s.writableNotebooksOnly.isSet()) {
        w.writeFieldBegin(QStringLiteral("writableNotebooksOnly"), ThriftFieldType::T_BOOL, 4);
        w.writeBool(s.writableNotebooksOnly.ref());
        w.writeFieldEnd();
    }
    if(s.includeContainingNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeContainingNotebooks"), ThriftFieldType::T_BOOL, 5);
        w.writeBool(s.includeContainingNotebooks.ref());
        w.writeFieldEnd();
    }
    if(s.includeDebugInfo.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeDebugInfo"), ThriftFieldType::T_BOOL, 6);
        w.writeBool(s.includeDebugInfo.ref());
        w.writeFieldEnd();
    }
    if(s.maxExperts.isSet()) {
        w.writeFieldBegin(QStringLiteral("maxExperts"), ThriftFieldType::T_I32, 7);
        w.writeI32(s.maxExperts.ref());
        w.writeFieldEnd();
    }
    if(s.maxRelatedContent.isSet()) {
        w.writeFieldBegin(QStringLiteral("maxRelatedContent"), ThriftFieldType::T_I32, 8);
        w.writeI32(s.maxRelatedContent.ref());
        w.writeFieldEnd();
    }
    if(s.relatedContentTypes.isSet()) {
        w.writeFieldBegin(QStringLiteral("relatedContentTypes"), ThriftFieldType::T_SET, 9);
        w.writeSetBegin(ThriftFieldType::T_I32, s.relatedContentTypes.ref().count());
        for(QSet< RelatedContentType::type >::const_iterator it = s.relatedContentTypes.ref().constBegin(), end = s.relatedContentTypes.ref().constEnd(); it != end; ++it) {
            w.writeI32(static_cast<qint32>(*it));
        }
        w.writeSetEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readRelatedResultSpec(ThriftBinaryBufferReader & r, RelatedResultSpec & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.maxNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.maxNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.maxTags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.writableNotebooksOnly = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeContainingNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeDebugInfo = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.maxExperts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.maxRelatedContent = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_SET) {
                QSet< RelatedContentType::type > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readSetBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_I32) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect set type (RelatedResultSpec.relatedContentTypes)"));
                for(qint32 i = 0; i < size; i++) {
                    RelatedContentType::type elem;
                    readEnumRelatedContentType(r, elem);
                    v.insert(elem);
                }
                r.readSetEnd();
                s.relatedContentTypes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeUpdateNoteIfUsnMatchesResult(ThriftBinaryBufferWriter & w, const UpdateNoteIfUsnMatchesResult & s) {
    w.writeStructBegin(QStringLiteral("UpdateNoteIfUsnMatchesResult"));
    if(s.note.isSet()) {
        w.writeFieldBegin(QStringLiteral("note"), ThriftFieldType::T_STRUCT, 1);
        writeNote(w, s.note.ref());
        w.writeFieldEnd();
    }
    if(s.updated.isSet()) {
        w.writeFieldBegin(QStringLiteral("updated"), ThriftFieldType::T_BOOL, 2);
        w.writeBool(s.updated.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readUpdateNoteIfUsnMatchesResult(ThriftBinaryBufferReader & r, UpdateNoteIfUsnMatchesResult & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Note v;
                readNote(r, v);
                s.note = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.updated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeShareRelationshipRestrictions(ThriftBinaryBufferWriter & w, const ShareRelationshipRestrictions & s) {
    w.writeStructBegin(QStringLiteral("ShareRelationshipRestrictions"));
    if(s.noSetReadOnly.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSetReadOnly"), ThriftFieldType::T_BOOL, 1);
        w.writeBool(s.noSetReadOnly.ref());
        w.writeFieldEnd();
    }
    if(s.noSetReadPlusActivity.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSetReadPlusActivity"), ThriftFieldType::T_BOOL, 2);
        w.writeBool(s.noSetReadPlusActivity.ref());
        w.writeFieldEnd();
    }
    if(s.noSetModify.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSetModify"), ThriftFieldType::T_BOOL, 3);
        w.writeBool(s.noSetModify.ref());
        w.writeFieldEnd();
    }
    if(s.noSetFullAccess.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSetFullAccess"), ThriftFieldType::T_BOOL, 4);
        w.writeBool(s.noSetFullAccess.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readShareRelationshipRestrictions(ThriftBinaryBufferReader & r, ShareRelationshipRestrictions & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetReadOnly = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetReadPlusActivity = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetModify = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetFullAccess = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeInvitationShareRelationship(ThriftBinaryBufferWriter & w, const InvitationShareRelationship & s) {
    w.writeStructBegin(QStringLiteral("InvitationShareRelationship"));
    if(s.displayName.isSet()) {
        w.writeFieldBegin(QStringLiteral("displayName"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.displayName.ref());
        w.writeFieldEnd();
    }
    if(s.recipientUserIdentity.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientUserIdentity"), ThriftFieldType::T_STRUCT, 2);
        writeUserIdentity(w, s.recipientUserIdentity.ref());
        w.writeFieldEnd();
    }
    if(s.privilege.isSet()) {
        w.writeFieldBegin(QStringLiteral("privilege"), ThriftFieldType::T_I32, 3);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    if(s.sharerUserId.isSet()) {
        w.writeFieldBegin(QStringLiteral("sharerUserId"), ThriftFieldType::T_I32, 5);
        w.writeI32(s.sharerUserId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readInvitationShareRelationship(ThriftBinaryBufferReader & r, InvitationShareRelationship & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.displayName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserIdentity v;
                readUserIdentity(r, v);
                s.recipientUserIdentity = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                ShareRelationshipPrivilegeLevel::type v;
                readEnumShareRelationshipPrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.sharerUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeMemberShareRelationship(ThriftBinaryBufferWriter & w, const MemberShareRelationship & s) {
    w.writeStructBegin(QStringLiteral("MemberShareRelationship"));
    if(s.displayName.isSet()) {
        w.writeFieldBegin(QStringLiteral("displayName"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.displayName.ref());
        w.writeFieldEnd();
    }
    if(s.recipientUserId.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientUserId"), ThriftFieldType::T_I32, 2);
        w.writeI32(s.recipientUserId.ref());
        w.writeFieldEnd();
    }
    if(s.bestPrivilege.isSet()) {
        w.writeFieldBegin(QStringLiteral("bestPrivilege"), ThriftFieldType::T_I32, 3);
        w.writeI32(static_cast<qint32>(s.bestPrivilege.ref()));
        w.writeFieldEnd();
    }
    if(s.individualPrivilege.isSet()) {
        w.writeFieldBegin(QStringLiteral("individualPrivilege"), ThriftFieldType::T_I32, 4);
        w.writeI32(static_cast<qint32>(s.individualPrivilege.ref()));
        w.writeFieldEnd();
    }
    if(s.restrictions.isSet()) {
        w.writeFieldBegin(QStringLiteral("restrictions"), ThriftFieldType::T_STRUCT, 5);
        writeShareRelationshipRestrictions(w, s.restrictions.ref());
        w.writeFieldEnd();
    }
    if(s.sharerUserId.isSet()) {
        w.writeFieldBegin(QStringLiteral("sharerUserId"), ThriftFieldType::T_I32, 6);
        w.writeI32(s.sharerUserId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readMemberShareRelationship(ThriftBinaryBufferReader & r, MemberShareRelationship & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.displayName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.recipientUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                ShareRelationshipPrivilegeLevel::type v;
                readEnumShareRelationshipPrivilegeLevel(r, v);
                s.bestPrivilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                ShareRelationshipPrivilegeLevel::type v;
                readEnumShareRelationshipPrivilegeLevel(r, v);
                s.individualPrivilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                ShareRelationshipRestrictions v;
                readShareRelationshipRestrictions(r, v);
                s.restrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.sharerUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeShareRelationships(ThriftBinaryBufferWriter & w, const ShareRelationships & s) {
    w.writeStructBegin(QStringLiteral("ShareRelationships"));
    if(s.invitations.isSet()) {
        w.writeFieldBegin(QStringLiteral("invitations"), ThriftFieldType::T_LIST, 1);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.invitations.ref().length());
        for(QList< InvitationShareRelationship >::const_iterator it = s.invitations.ref().constBegin(), end = s.invitations.ref().constEnd(); it != end; ++it) {
            writeInvitationShareRelationship(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.memberships.isSet()) {
        w.writeFieldBegin(QStringLiteral("memberships"), ThriftFieldType::T_LIST, 2);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.memberships.ref().length());
        for(QList< MemberShareRelationship >::const_iterator it = s.memberships.ref().constBegin(), end = s.memberships.ref().constEnd(); it != end; ++it) {
            writeMemberShareRelationship(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.invitationRestrictions.isSet()) {
        w.writeFieldBegin(QStringLiteral("invitationRestrictions"), ThriftFieldType::T_STRUCT, 3);
        writeShareRelationshipRestrictions(w, s.invitationRestrictions.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readShareRelationships(ThriftBinaryBufferReader & r, ShareRelationships & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< InvitationShareRelationship > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ShareRelationships.invitations)"));
                for(qint32 i = 0; i < size; i++) {
                    InvitationShareRelationship elem;
                    readInvitationShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.invitations = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< MemberShareRelationship > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ShareRelationships.memberships)"));
                for(qint32 i = 0; i < size; i++) {
                    MemberShareRelationship elem;
                    readMemberShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.memberships = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                ShareRelationshipRestrictions v;
                readShareRelationshipRestrictions(r, v);
                s.invitationRestrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeManageNotebookSharesParameters(ThriftBinaryBufferWriter & w, const ManageNotebookSharesParameters & s) {
    w.writeStructBegin(QStringLiteral("ManageNotebookSharesParameters"));
    if(s.notebookGuid.isSet()) {
        w.writeFieldBegin(QStringLiteral("notebookGuid"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.notebookGuid.ref());
        w.writeFieldEnd();
    }
    if(s.inviteMessage.isSet()) {
        w.writeFieldBegin(QStringLiteral("inviteMessage"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.inviteMessage.ref());
        w.writeFieldEnd();
    }
    if(s.membershipsToUpdate.isSet()) {
        w.writeFieldBegin(QStringLiteral("membershipsToUpdate"), ThriftFieldType::T_LIST, 3);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.membershipsToUpdate.ref().length());
        for(QList< MemberShareRelationship >::const_iterator it = s.membershipsToUpdate.ref().constBegin(), end = s.membershipsToUpdate.ref().constEnd(); it != end; ++it) {
            writeMemberShareRelationship(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.invitationsToCreateOrUpdate.isSet()) {
        w.writeFieldBegin(QStringLiteral("invitationsToCreateOrUpdate"), ThriftFieldType::T_LIST, 4);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.invitationsToCreateOrUpdate.ref().length());
        for(QList< InvitationShareRelationship >::const_iterator it = s.invitationsToCreateOrUpdate.ref().constBegin(), end = s.invitationsToCreateOrUpdate.ref().constEnd(); it != end; ++it) {
            writeInvitationShareRelationship(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.unshares.isSet()) {
        w.writeFieldBegin(QStringLiteral("unshares"), ThriftFieldType::T_LIST, 5);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.unshares.ref().length());
        for(QList< UserIdentity >::const_iterator it = s.unshares.ref().constBegin(), end = s.unshares.ref().constEnd(); it != end; ++it) {
            writeUserIdentity(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readManageNotebookSharesParameters(ThriftBinaryBufferReader & r, ManageNotebookSharesParameters & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.notebookGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.inviteMessage = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< MemberShareRelationship > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNotebookSharesParameters.membershipsToUpdate)"));
                for(qint32 i = 0; i < size; i++) {
                    MemberShareRelationship elem;
                    readMemberShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.membershipsToUpdate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< InvitationShareRelationship > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNotebookSharesParameters.invitationsToCreateOrUpdate)"));
                for(qint32 i = 0; i < size; i++) {
                    InvitationShareRelationship elem;
                    readInvitationShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.invitationsToCreateOrUpdate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< UserIdentity > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNotebookSharesParameters.unshares)"));
                for(qint32 i = 0; i < size; i++) {
                    UserIdentity elem;
                    readUserIdentity(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.unshares = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeManageNotebookSharesError(ThriftBinaryBufferWriter & w, const ManageNotebookSharesError & s) {
    w.writeStructBegin(QStringLiteral("ManageNotebookSharesError"));
    if(s.userIdentity.isSet()) {
        w.writeFieldBegin(QStringLiteral("userIdentity"), ThriftFieldType::T_STRUCT, 1);
        writeUserIdentity(w, s.userIdentity.ref());
        w.writeFieldEnd();
    }
    if(s.userException.isSet()) {
        w.writeFieldBegin(QStringLiteral("userException"), ThriftFieldType::T_STRUCT, 2);
        writeEDAMUserException(w, s.userException.ref());
        w.writeFieldEnd();
    }
    if(s.notFoundException.isSet()) {
        w.writeFieldBegin(QStringLiteral("notFoundException"), ThriftFieldType::T_STRUCT, 3);
        writeEDAMNotFoundException(w, s.notFoundException.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readManageNotebookSharesError(ThriftBinaryBufferReader & r, ManageNotebookSharesError & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserIdentity v;
                readUserIdentity(r, v);
                s.userIdentity = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException v;
                readEDAMUserException(r, v);
                s.userException = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException v;
                readEDAMNotFoundException(r, v);
                s.notFoundException = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeManageNotebookSharesResult(ThriftBinaryBufferWriter & w, const ManageNotebookSharesResult & s) {
    w.writeStructBegin(QStringLiteral("ManageNotebookSharesResult"));
    if(s.errors.isSet()) {
        w.writeFieldBegin(QStringLiteral("errors"), ThriftFieldType::T_LIST, 1);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.errors.ref().length());
        for(QList< ManageNotebookSharesError >::const_iterator it = s.errors.ref().constBegin(), end = s.errors.ref().constEnd(); it != end; ++it) {
            writeManageNotebookSharesError(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readManageNotebookSharesResult(ThriftBinaryBufferReader & r, ManageNotebookSharesResult & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< ManageNotebookSharesError > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNotebookSharesResult.errors)"));
                for(qint32 i = 0; i < size; i++) {
                    ManageNotebookSharesError elem;
                    readManageNotebookSharesError(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.errors = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeSharedNoteTemplate(ThriftBinaryBufferWriter & w, const SharedNoteTemplate & s) {
    w.writeStructBegin(QStringLiteral("SharedNoteTemplate"));
    if(s.noteGuid.isSet()) {
        w.writeFieldBegin(QStringLiteral("noteGuid"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.noteGuid.ref());
        w.writeFieldEnd();
    }
    if(s.recipientThreadId.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientThreadId"), ThriftFieldType::T_I64, 4);
        w.writeI64(s.recipientThreadId.ref());
        w.writeFieldEnd();
    }
    if(s.recipientContacts.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientContacts"), ThriftFieldType::T_LIST, 2);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.recipientContacts.ref().length());
        for(QList< Contact >::const_iterator it = s.recipientContacts.ref().constBegin(), end = s.recipientContacts.ref().constEnd(); it != end; ++it) {
            writeContact(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.privilege.isSet()) {
        w.writeFieldBegin(QStringLiteral("privilege"), ThriftFieldType::T_I32, 3);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSharedNoteTemplate(ThriftBinaryBufferReader & r, SharedNoteTemplate & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.noteGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageThreadID v;
                r.readI64(v);
                s.recipientThreadId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Contact > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (SharedNoteTemplate.recipientContacts)"));
                for(qint32 i = 0; i < size; i++) {
                    Contact elem;
                    readContact(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.recipientContacts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel::type v;
                readEnumSharedNotePrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNotebookShareTemplate(ThriftBinaryBufferWriter & w, const NotebookShareTemplate & s) {
    w.writeStructBegin(QStringLiteral("NotebookShareTemplate"));
    if(s.notebookGuid.isSet()) {
        w.writeFieldBegin(QStringLiteral("notebookGuid"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.notebookGuid.ref());
        w.writeFieldEnd();
    }
    if(s.recipientThreadId.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientThreadId"), ThriftFieldType::T_I64, 4);
        w.writeI64(s.recipientThreadId.ref());
        w.writeFieldEnd();
    }
    if(s.recipientContacts.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientContacts"), ThriftFieldType::T_LIST, 2);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.recipientContacts.ref().length());
        for(QList< Contact >::const_iterator it = s.recipientContacts.ref().constBegin(), end = s.recipientContacts.ref().constEnd(); it != end; ++it) {
            writeContact(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.privilege.isSet()) {
        w.writeFieldBegin(QStringLiteral("privilege"), ThriftFieldType::T_I32, 3);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNotebookShareTemplate(ThriftBinaryBufferReader & r, NotebookShareTemplate & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.notebookGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageThreadID v;
                r.readI64(v);
                s.recipientThreadId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Contact > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NotebookShareTemplate.recipientContacts)"));
                for(qint32 i = 0; i < size; i++) {
                    Contact elem;
                    readContact(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.recipientContacts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookPrivilegeLevel::type v;
                readEnumSharedNotebookPrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeCreateOrUpdateNotebookSharesResult(ThriftBinaryBufferWriter & w, const CreateOrUpdateNotebookSharesResult & s) {
    w.writeStructBegin(QStringLiteral("CreateOrUpdateNotebookSharesResult"));
    if(s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(QStringLiteral("updateSequenceNum"), ThriftFieldType::T_I32, 1);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if(s.matchingShares.isSet()) {
        w.writeFieldBegin(QStringLiteral("matchingShares"), ThriftFieldType::T_LIST, 2);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.matchingShares.ref().length());
        for(QList< SharedNotebook >::const_iterator it = s.matchingShares.ref().constBegin(), end = s.matchingShares.ref().constEnd(); it != end; ++it) {
            writeSharedNotebook(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readCreateOrUpdateNotebookSharesResult(ThriftBinaryBufferReader & r, CreateOrUpdateNotebookSharesResult & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< SharedNotebook > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (CreateOrUpdateNotebookSharesResult.matchingShares)"));
                for(qint32 i = 0; i < size; i++) {
                    SharedNotebook elem;
                    readSharedNotebook(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.matchingShares = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNoteShareRelationshipRestrictions(ThriftBinaryBufferWriter & w, const NoteShareRelationshipRestrictions & s) {
    w.writeStructBegin(QStringLiteral("NoteShareRelationshipRestrictions"));
    if(s.noSetReadNote.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSetReadNote"), ThriftFieldType::T_BOOL, 1);
        w.writeBool(s.noSetReadNote.ref());
        w.writeFieldEnd();
    }
    if(s.noSetModifyNote.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSetModifyNote"), ThriftFieldType::T_BOOL, 2);
        w.writeBool(s.noSetModifyNote.ref());
        w.writeFieldEnd();
    }
    if(s.noSetFullAccess.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSetFullAccess"), ThriftFieldType::T_BOOL, 3);
        w.writeBool(s.noSetFullAccess.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteShareRelationshipRestrictions(ThriftBinaryBufferReader & r, NoteShareRelationshipRestrictions & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetReadNote = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetModifyNote = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetFullAccess = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNoteMemberShareRelationship(ThriftBinaryBufferWriter & w, const NoteMemberShareRelationship & s) {
    w.writeStructBegin(QStringLiteral("NoteMemberShareRelationship"));
    if(s.displayName.isSet()) {
        w.writeFieldBegin(QStringLiteral("displayName"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.displayName.ref());
        w.writeFieldEnd();
    }
    if(s.recipientUserId.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientUserId"), ThriftFieldType::T_I32, 2);
        w.writeI32(s.recipientUserId.ref());
        w.writeFieldEnd();
    }
    if(s.privilege.isSet()) {
        w.writeFieldBegin(QStringLiteral("privilege"), ThriftFieldType::T_I32, 3);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    if(s.restrictions.isSet()) {
        w.writeFieldBegin(QStringLiteral("restrictions"), ThriftFieldType::T_STRUCT, 4);
        writeNoteShareRelationshipRestrictions(w, s.restrictions.ref());
        w.writeFieldEnd();
    }
    if(s.sharerUserId.isSet()) {
        w.writeFieldBegin(QStringLiteral("sharerUserId"), ThriftFieldType::T_I32, 5);
        w.writeI32(s.sharerUserId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteMemberShareRelationship(ThriftBinaryBufferReader & r, NoteMemberShareRelationship & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.displayName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.recipientUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel::type v;
                readEnumSharedNotePrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteShareRelationshipRestrictions v;
                readNoteShareRelationshipRestrictions(r, v);
                s.restrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.sharerUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNoteInvitationShareRelationship(ThriftBinaryBufferWriter & w, const NoteInvitationShareRelationship & s) {
    w.writeStructBegin(QStringLiteral("NoteInvitationShareRelationship"));
    if(s.displayName.isSet()) {
        w.writeFieldBegin(QStringLiteral("displayName"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.displayName.ref());
        w.writeFieldEnd();
    }
    if(s.recipientIdentityId.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientIdentityId"), ThriftFieldType::T_I64, 2);
        w.writeI64(s.recipientIdentityId.ref());
        w.writeFieldEnd();
    }
    if(s.privilege.isSet()) {
        w.writeFieldBegin(QStringLiteral("privilege"), ThriftFieldType::T_I32, 3);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    if(s.sharerUserId.isSet()) {
        w.writeFieldBegin(QStringLiteral("sharerUserId"), ThriftFieldType::T_I32, 5);
        w.writeI32(s.sharerUserId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteInvitationShareRelationship(ThriftBinaryBufferReader & r, NoteInvitationShareRelationship & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.displayName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                IdentityID v;
                r.readI64(v);
                s.recipientIdentityId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel::type v;
                readEnumSharedNotePrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.sharerUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNoteShareRelationships(ThriftBinaryBufferWriter & w, const NoteShareRelationships & s) {
    w.writeStructBegin(QStringLiteral("NoteShareRelationships"));
    if(s.invitations.isSet()) {
        w.writeFieldBegin(QStringLiteral("invitations"), ThriftFieldType::T_LIST, 1);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.invitations.ref().length());
        for(QList< NoteInvitationShareRelationship >::const_iterator it = s.invitations.ref().constBegin(), end = s.invitations.ref().constEnd(); it != end; ++it) {
            writeNoteInvitationShareRelationship(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.memberships.isSet()) {
        w.writeFieldBegin(QStringLiteral("memberships"), ThriftFieldType::T_LIST, 2);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.memberships.ref().length());
        for(QList< NoteMemberShareRelationship >::const_iterator it = s.memberships.ref().constBegin(), end = s.memberships.ref().constEnd(); it != end; ++it) {
            writeNoteMemberShareRelationship(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.invitationRestrictions.isSet()) {
        w.writeFieldBegin(QStringLiteral("invitationRestrictions"), ThriftFieldType::T_STRUCT, 3);
        writeNoteShareRelationshipRestrictions(w, s.invitationRestrictions.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteShareRelationships(ThriftBinaryBufferReader & r, NoteShareRelationships & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< NoteInvitationShareRelationship > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteShareRelationships.invitations)"));
                for(qint32 i = 0; i < size; i++) {
                    NoteInvitationShareRelationship elem;
                    readNoteInvitationShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.invitations = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< NoteMemberShareRelationship > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (NoteShareRelationships.memberships)"));
                for(qint32 i = 0; i < size; i++) {
                    NoteMemberShareRelationship elem;
                    readNoteMemberShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.memberships = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteShareRelationshipRestrictions v;
                readNoteShareRelationshipRestrictions(r, v);
                s.invitationRestrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeManageNoteSharesParameters(ThriftBinaryBufferWriter & w, const ManageNoteSharesParameters & s) {
    w.writeStructBegin(QStringLiteral("ManageNoteSharesParameters"));
    if(s.noteGuid.isSet()) {
        w.writeFieldBegin(QStringLiteral("noteGuid"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.noteGuid.ref());
        w.writeFieldEnd();
    }
    if(s.membershipsToUpdate.isSet()) {
        w.writeFieldBegin(QStringLiteral("membershipsToUpdate"), ThriftFieldType::T_LIST, 2);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.membershipsToUpdate.ref().length());
        for(QList< NoteMemberShareRelationship >::const_iterator it = s.membershipsToUpdate.ref().constBegin(), end = s.membershipsToUpdate.ref().constEnd(); it != end; ++it) {
            writeNoteMemberShareRelationship(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.invitationsToUpdate.isSet()) {
        w.writeFieldBegin(QStringLiteral("invitationsToUpdate"), ThriftFieldType::T_LIST, 3);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.invitationsToUpdate.ref().length());
        for(QList< NoteInvitationShareRelationship >::const_iterator it = s.invitationsToUpdate.ref().constBegin(), end = s.invitationsToUpdate.ref().constEnd(); it != end; ++it) {
            writeNoteInvitationShareRelationship(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.membershipsToUnshare.isSet()) {
        w.writeFieldBegin(QStringLiteral("membershipsToUnshare"), ThriftFieldType::T_LIST, 4);
        w.writeListBegin(ThriftFieldType::T_I32, s.membershipsToUnshare.ref().length());
        for(QList< UserID >::const_iterator it = s.membershipsToUnshare.ref().constBegin(), end = s.membershipsToUnshare.ref().constEnd(); it != end; ++it) {
            w.writeI32(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.invitationsToUnshare.isSet()) {
        w.writeFieldBegin(QStringLiteral("invitationsToUnshare"), ThriftFieldType::T_LIST, 5);
        w.writeListBegin(ThriftFieldType::T_I64, s.invitationsToUnshare.ref().length());
        for(QList< IdentityID >::const_iterator it = s.invitationsToUnshare.ref().constBegin(), end = s.invitationsToUnshare.ref().constEnd(); it != end; ++it) {
            w.writeI64(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readManageNoteSharesParameters(ThriftBinaryBufferReader & r, ManageNoteSharesParameters & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.noteGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< NoteMemberShareRelationship > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNoteSharesParameters.membershipsToUpdate)"));
                for(qint32 i = 0; i < size; i++) {
                    NoteMemberShareRelationship elem;
                    readNoteMemberShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.membershipsToUpdate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< NoteInvitationShareRelationship > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNoteSharesParameters.invitationsToUpdate)"));
                for(qint32 i = 0; i < size; i++) {
                    NoteInvitationShareRelationship elem;
                    readNoteInvitationShareRelationship(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.invitationsToUpdate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< UserID > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_I32) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNoteSharesParameters.membershipsToUnshare)"));
                for(qint32 i = 0; i < size; i++) {
                    UserID elem;
                    r.readI32(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.membershipsToUnshare = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< IdentityID > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_I64) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNoteSharesParameters.invitationsToUnshare)"));
                for(qint32 i = 0; i < size; i++) {
                    IdentityID elem;
                    r.readI64(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.invitationsToUnshare = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeManageNoteSharesError(ThriftBinaryBufferWriter & w, const ManageNoteSharesError & s) {
    w.writeStructBegin(QStringLiteral("ManageNoteSharesError"));
    if(s.identityID.isSet()) {
        w.writeFieldBegin(QStringLiteral("identityID"), ThriftFieldType::T_I64, 1);
        w.writeI64(s.identityID.ref());
        w.writeFieldEnd();
    }
    if(s.userID.isSet()) {
        w.writeFieldBegin(QStringLiteral("userID"), ThriftFieldType::T_I32, 2);
        w.writeI32(s.userID.ref());
        w.writeFieldEnd();
    }
    if(s.userException.isSet()) {
        w.writeFieldBegin(QStringLiteral("userException"), ThriftFieldType::T_STRUCT, 3);
        writeEDAMUserException(w, s.userException.ref());
        w.writeFieldEnd();
    }
    if(s.notFoundException.isSet()) {
        w.writeFieldBegin(QStringLiteral("notFoundException"), ThriftFieldType::T_STRUCT, 4);
        writeEDAMNotFoundException(w, s.notFoundException.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readManageNoteSharesError(ThriftBinaryBufferReader & r, ManageNoteSharesError & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                IdentityID v;
                r.readI64(v);
                s.identityID = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.userID = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException v;
                readEDAMUserException(r, v);
                s.userException = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException v;
                readEDAMNotFoundException(r, v);
                s.notFoundException = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeManageNoteSharesResult(ThriftBinaryBufferWriter & w, const ManageNoteSharesResult & s) {
    w.writeStructBegin(QStringLiteral("ManageNoteSharesResult"));
    if(s.errors.isSet()) {
        w.writeFieldBegin(QStringLiteral("errors"), ThriftFieldType::T_LIST, 1);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.errors.ref().length());
        for(QList< ManageNoteSharesError >::const_iterator it = s.errors.ref().constBegin(), end = s.errors.ref().constEnd(); it != end; ++it) {
            writeManageNoteSharesError(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readManageNoteSharesResult(ThriftBinaryBufferReader & r, ManageNoteSharesResult & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< ManageNoteSharesError > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (ManageNoteSharesResult.errors)"));
                for(qint32 i = 0; i < size; i++) {
                    ManageNoteSharesError elem;
                    readManageNoteSharesError(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.errors = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeData(ThriftBinaryBufferWriter & w, const Data & s) {
    w.writeStructBegin(QStringLiteral("Data"));
    if(s.bodyHash.isSet()) {
        w.writeFieldBegin(QStringLiteral("bodyHash"), ThriftFieldType::T_STRING, 1);
        w.writeBinary(s.bodyHash.ref());
        w.writeFieldEnd();
    }
    if(s.size.isSet()) {
        w.writeFieldBegin(QStringLiteral("size"), ThriftFieldType::T_I32, 2);
        w.writeI32(s.size.ref());
        w.writeFieldEnd();
    }
    if(s.body.isSet()) {
        w.writeFieldBegin(QStringLiteral("body"), ThriftFieldType::T_STRING, 3);
        w.writeBinary(s.body.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readData(ThriftBinaryBufferReader & r, Data & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                r.readBinary(v);
                s.bodyHash = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.size = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                r.readBinary(v);
                s.body = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeUserAttributes(ThriftBinaryBufferWriter & w, const UserAttributes & s) {
    w.writeStructBegin(QStringLiteral("UserAttributes"));
    if(s.defaultLocationName.isSet()) {
        w.writeFieldBegin(QStringLiteral("defaultLocationName"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.defaultLocationName.ref());
        w.writeFieldEnd();
    }
    if(s.defaultLatitude.isSet()) {
        w.writeFieldBegin(QStringLiteral("defaultLatitude"), ThriftFieldType::T_DOUBLE, 2);
        w.writeDouble(s.defaultLatitude.ref());
        w.writeFieldEnd();
    }
    if(s.defaultLongitude.isSet()) {
        w.writeFieldBegin(QStringLiteral("defaultLongitude"), ThriftFieldType::T_DOUBLE, 3);
        w.writeDouble(s.defaultLongitude.ref());
        w.writeFieldEnd();
    }
    if(s.preactivation.isSet()) {
        w.writeFieldBegin(QStringLiteral("preactivation"), ThriftFieldType::T_BOOL, 4);
        w.writeBool(s.preactivation.ref());
        w.writeFieldEnd();
    }
    if(s.viewedPromotions.isSet()) {
        w.writeFieldBegin(QStringLiteral("viewedPromotions"), ThriftFieldType::T_LIST, 5);
        w.writeListBegin(ThriftFieldType::T_STRING, s.viewedPromotions.ref().length());
        for(QStringList::const_iterator it = s.viewedPromotions.ref().constBegin(), end = s.viewedPromotions.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.incomingEmailAddress.isSet()) {
        w.writeFieldBegin(QStringLiteral("incomingEmailAddress"), ThriftFieldType::T_STRING, 6);
        w.writeString(s.incomingEmailAddress.ref());
        w.writeFieldEnd();
    }
    if(s.recentMailedAddresses.isSet()) {
        w.writeFieldBegin(QStringLiteral("recentMailedAddresses"), ThriftFieldType::T_LIST, 7);
        w.writeListBegin(ThriftFieldType::T_STRING, s.recentMailedAddresses.ref().length());
        for(QStringList::const_iterator it = s.recentMailedAddresses.ref().constBegin(), end = s.recentMailedAddresses.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.comments.isSet()) {
        w.writeFieldBegin(QStringLiteral("comments"), ThriftFieldType::T_STRING, 9);
        w.writeString(s.comments.ref());
        w.writeFieldEnd();
    }
    if(s.dateAgreedToTermsOfService.isSet()) {
        w.writeFieldBegin(QStringLiteral("dateAgreedToTermsOfService"), ThriftFieldType::T_I64, 11);
        w.writeI64(s.dateAgreedToTermsOfService.ref());
        w.writeFieldEnd();
    }
    if(s.maxReferrals.isSet()) {
        w.writeFieldBegin(QStringLiteral("maxReferrals"), ThriftFieldType::T_I32, 12);
        w.writeI32(s.maxReferrals.ref());
        w.writeFieldEnd();
    }
    if(s.referralCount.isSet()) {
        w.writeFieldBegin(QStringLiteral("referralCount"), ThriftFieldType::T_I32, 13);
        w.writeI32(s.referralCount.ref());
        w.writeFieldEnd();
    }
    if(s.refererCode.isSet()) {
        w.writeFieldBegin(QStringLiteral("refererCode"), ThriftFieldType::T_STRING, 14);
        w.writeString(s.refererCode.ref());
        w.writeFieldEnd();
    }
    if(s.sentEmailDate.isSet()) {
        w.writeFieldBegin(QStringLiteral("sentEmailDate"), ThriftFieldType::T_I64, 15);
        w.writeI64(s.sentEmailDate.ref());
        w.writeFieldEnd();
    }
    if(s.sentEmailCount.isSet()) {
        w.writeFieldBegin(QStringLiteral("sentEmailCount"), ThriftFieldType::T_I32, 16);
        w.writeI32(s.sentEmailCount.ref());
        w.writeFieldEnd();
    }
    if(s.dailyEmailLimit.isSet()) {
        w.writeFieldBegin(QStringLiteral("dailyEmailLimit"), ThriftFieldType::T_I32, 17);
        w.writeI32(s.dailyEmailLimit.ref());
        w.writeFieldEnd();
    }
    if(s.emailOptOutDate.isSet()) {
        w.writeFieldBegin(QStringLiteral("emailOptOutDate"), ThriftFieldType::T_I64, 18);
        w.writeI64(s.emailOptOutDate.ref());
        w.writeFieldEnd();
    }
    if(s.partnerEmailOptInDate.isSet()) {
        w.writeFieldBegin(QStringLiteral("partnerEmailOptInDate"), ThriftFieldType::T_I64, 19);
        w.writeI64(s.partnerEmailOptInDate.ref());
        w.writeFieldEnd();
    }
    if(s.preferredLanguage.isSet()) {
        w.writeFieldBegin(QStringLiteral("preferredLanguage"), ThriftFieldType::T_STRING, 20);
        w.writeString(s.preferredLanguage.ref());
        w.writeFieldEnd();
    }
    if(s.preferredCountry.isSet()) {
        w.writeFieldBegin(QStringLiteral("preferredCountry"), ThriftFieldType::T_STRING, 21);
        w.writeString(s.preferredCountry.ref());
        w.writeFieldEnd();
    }
    if(s.clipFullPage.isSet()) {
        w.writeFieldBegin(QStringLiteral("clipFullPage"), ThriftFieldType::T_BOOL, 22);
        w.writeBool(s.clipFullPage.ref());
        w.writeFieldEnd();
    }
    if(s.twitterUserName.isSet()) {
        w.writeFieldBegin(QStringLiteral("twitterUserName"), ThriftFieldType::T_STRING, 23);
        w.writeString(s.twitterUserName.ref());
        w.writeFieldEnd();
    }
    if(s.twitterId.isSet()) {
        w.writeFieldBegin(QStringLiteral("twitterId"), ThriftFieldType::T_STRING, 24);
        w.writeString(s.twitterId.ref());
        w.writeFieldEnd();
    }
    if(s.groupName.isSet()) {
        w.writeFieldBegin(QStringLiteral("groupName"), ThriftFieldType::T_STRING, 25);
        w.writeString(s.groupName.ref());
        w.writeFieldEnd();
    }
    if(s.recognitionLanguage.isSet()) {
        w.writeFieldBegin(QStringLiteral("recognitionLanguage"), ThriftFieldType::T_STRING, 26);
        w.writeString(s.recognitionLanguage.ref());
        w.writeFieldEnd();
    }
    if(s.referralProof.isSet()) {
        w.writeFieldBegin(QStringLiteral("referralProof"), ThriftFieldType::T_STRING, 28);
        w.writeString(s.referralProof.ref());
        w.writeFieldEnd();
    }
    if(s.educationalDiscount.isSet()) {
        w.writeFieldBegin(QStringLiteral("educationalDiscount"), ThriftFieldType::T_BOOL, 29);
        w.writeBool(s.educationalDiscount.ref());
        w.writeFieldEnd();
    }
    if(s.businessAddress.isSet()) {
        w.writeFieldBegin(QStringLiteral("businessAddress"), ThriftFieldType::T_STRING, 30);
        w.writeString(s.businessAddress.ref());
        w.writeFieldEnd();
    }
    if(s.hideSponsorBilling.isSet()) {
        w.writeFieldBegin(QStringLiteral("hideSponsorBilling"), ThriftFieldType::T_BOOL, 31);
        w.writeBool(s.hideSponsorBilling.ref());
        w.writeFieldEnd();
    }
    if(s.useEmailAutoFiling.isSet()) {
        w.writeFieldBegin(QStringLiteral("useEmailAutoFiling"), ThriftFieldType::T_BOOL, 33);
        w.writeBool(s.useEmailAutoFiling.ref());
        w.writeFieldEnd();
    }
    if(s.reminderEmailConfig.isSet()) {
        w.writeFieldBegin(QStringLiteral("reminderEmailConfig"), ThriftFieldType::T_I32, 34);
        w.writeI32(static_cast<qint32>(s.reminderEmailConfig.ref()));
        w.writeFieldEnd();
    }
    if(s.emailAddressLastConfirmed.isSet()) {
        w.writeFieldBegin(QStringLiteral("emailAddressLastConfirmed"), ThriftFieldType::T_I64, 35);
        w.writeI64(s.emailAddressLastConfirmed.ref());
        w.writeFieldEnd();
    }
    if(s.passwordUpdated.isSet()) {
        w.writeFieldBegin(QStringLiteral("passwordUpdated"), ThriftFieldType::T_I64, 36);
        w.writeI64(s.passwordUpdated.ref());
        w.writeFieldEnd();
    }
    if(s.salesforcePushEnabled.isSet()) {
        w.writeFieldBegin(QStringLiteral("salesforcePushEnabled"), ThriftFieldType::T_BOOL, 37);
        w.writeBool(s.salesforcePushEnabled.ref());
        w.writeFieldEnd();
    }
    if(s.shouldLogClientEvent.isSet()) {
        w.writeFieldBegin(QStringLiteral("shouldLogClientEvent"), ThriftFieldType::T_BOOL, 38);
        w.writeBool(s.shouldLogClientEvent.ref());
        w.writeFieldEnd();
    }
    if(s.optOutMachineLearning.isSet()) {
        w.writeFieldBegin(QStringLiteral("optOutMachineLearning"), ThriftFieldType::T_BOOL, 39);
        w.writeBool(s.optOutMachineLearning.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readUserAttributes(ThriftBinaryBufferReader & r, UserAttributes & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.defaultLocationName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.defaultLatitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.defaultLongitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.preactivation = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (UserAttributes.viewedPromotions)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.viewedPromotions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.incomingEmailAddress = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (UserAttributes.recentMailedAddresses)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.recentMailedAddresses = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.comments = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.dateAgreedToTermsOfService = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.maxReferrals = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.referralCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.refererCode = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.sentEmailDate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.sentEmailCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.dailyEmailLimit = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.emailOptOutDate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.partnerEmailOptInDate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.preferredLanguage = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.preferredCountry = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.clipFullPage = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.twitterUserName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.twitterId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 25) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.groupName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 26) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.recognitionLanguage = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 28) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.referralProof = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 29) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.educationalDiscount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 30) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.businessAddress = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 31) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.hideSponsorBilling = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 33) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.useEmailAutoFiling = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 34) {
            if (fieldType == ThriftFieldType::T_I32) {
                ReminderEmailConfig::type v;
                readEnumReminderEmailConfig(r, v);
                s.reminderEmailConfig = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 35) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.emailAddressLastConfirmed = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 36) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.passwordUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 37) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.salesforcePushEnabled = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 38) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.shouldLogClientEvent = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 39) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.optOutMachineLearning = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeBusinessUserAttributes(ThriftBinaryBufferWriter & w, const BusinessUserAttributes & s) {
    w.writeStructBegin(QStringLiteral("BusinessUserAttributes"));
    if(s.title.isSet()) {
        w.writeFieldBegin(QStringLiteral("title"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.title.ref());
        w.writeFieldEnd();
    }
    if(s.location.isSet()) {
        w.writeFieldBegin(QStringLiteral("location"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.location.ref());
        w.writeFieldEnd();
    }
    if(s.department.isSet()) {
        w.writeFieldBegin(QStringLiteral("department"), ThriftFieldType::T_STRING, 3);
        w.writeString(s.department.ref());
        w.writeFieldEnd();
    }
    if(s.mobilePhone.isSet()) {
        w.writeFieldBegin(QStringLiteral("mobilePhone"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.mobilePhone.ref());
        w.writeFieldEnd();
    }
    if(s.linkedInProfileUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("linkedInProfileUrl"), ThriftFieldType::T_STRING, 5);
        w.writeString(s.linkedInProfileUrl.ref());
        w.writeFieldEnd();
    }
    if(s.workPhone.isSet()) {
        w.writeFieldBegin(QStringLiteral("workPhone"), ThriftFieldType::T_STRING, 6);
        w.writeString(s.workPhone.ref());
        w.writeFieldEnd();
    }
    if(s.companyStartDate.isSet()) {
        w.writeFieldBegin(QStringLiteral("companyStartDate"), ThriftFieldType::T_I64, 7);
        w.writeI64(s.companyStartDate.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readBusinessUserAttributes(ThriftBinaryBufferReader & r, BusinessUserAttributes & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.title = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.location = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.department = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.mobilePhone = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.linkedInProfileUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.workPhone = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.companyStartDate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeAccounting(ThriftBinaryBufferWriter & w, const Accounting & s) {
    w.writeStructBegin(QStringLiteral("Accounting"));
    if(s.uploadLimitEnd.isSet()) {
        w.writeFieldBegin(QStringLiteral("uploadLimitEnd"), ThriftFieldType::T_I64, 2);
        w.writeI64(s.uploadLimitEnd.ref());
        w.writeFieldEnd();
    }
    if(s.uploadLimitNextMonth.isSet()) {
        w.writeFieldBegin(QStringLiteral("uploadLimitNextMonth"), ThriftFieldType::T_I64, 3);
        w.writeI64(s.uploadLimitNextMonth.ref());
        w.writeFieldEnd();
    }
    if(s.premiumServiceStatus.isSet()) {
        w.writeFieldBegin(QStringLiteral("premiumServiceStatus"), ThriftFieldType::T_I32, 4);
        w.writeI32(static_cast<qint32>(s.premiumServiceStatus.ref()));
        w.writeFieldEnd();
    }
    if(s.premiumOrderNumber.isSet()) {
        w.writeFieldBegin(QStringLiteral("premiumOrderNumber"), ThriftFieldType::T_STRING, 5);
        w.writeString(s.premiumOrderNumber.ref());
        w.writeFieldEnd();
    }
    if(s.premiumCommerceService.isSet()) {
        w.writeFieldBegin(QStringLiteral("premiumCommerceService"), ThriftFieldType::T_STRING, 6);
        w.writeString(s.premiumCommerceService.ref());
        w.writeFieldEnd();
    }
    if(s.premiumServiceStart.isSet()) {
        w.writeFieldBegin(QStringLiteral("premiumServiceStart"), ThriftFieldType::T_I64, 7);
        w.writeI64(s.premiumServiceStart.ref());
        w.writeFieldEnd();
    }
    if(s.premiumServiceSKU.isSet()) {
        w.writeFieldBegin(QStringLiteral("premiumServiceSKU"), ThriftFieldType::T_STRING, 8);
        w.writeString(s.premiumServiceSKU.ref());
        w.writeFieldEnd();
    }
    if(s.lastSuccessfulCharge.isSet()) {
        w.writeFieldBegin(QStringLiteral("lastSuccessfulCharge"), ThriftFieldType::T_I64, 9);
        w.writeI64(s.lastSuccessfulCharge.ref());
        w.writeFieldEnd();
    }
    if(s.lastFailedCharge.isSet()) {
        w.writeFieldBegin(QStringLiteral("lastFailedCharge"), ThriftFieldType::T_I64, 10);
        w.writeI64(s.lastFailedCharge.ref());
        w.writeFieldEnd();
    }
    if(s.lastFailedChargeReason.isSet()) {
        w.writeFieldBegin(QStringLiteral("lastFailedChargeReason"), ThriftFieldType::T_STRING, 11);
        w.writeString(s.lastFailedChargeReason.ref());
        w.writeFieldEnd();
    }
    if(s.nextPaymentDue.isSet()) {
        w.writeFieldBegin(QStringLiteral("nextPaymentDue"), ThriftFieldType::T_I64, 12);
        w.writeI64(s.nextPaymentDue.ref());
        w.writeFieldEnd();
    }
    if(s.premiumLockUntil.isSet()) {
        w.writeFieldBegin(QStringLiteral("premiumLockUntil"), ThriftFieldType::T_I64, 13);
        w.writeI64(s.premiumLockUntil.ref());
        w.writeFieldEnd();
    }
    if(s.updated.isSet()) {
        w.writeFieldBegin(QStringLiteral("updated"), ThriftFieldType::T_I64, 14);
        w.writeI64(s.updated.ref());
        w.writeFieldEnd();
    }
    if(s.premiumSubscriptionNumber.isSet()) {
        w.writeFieldBegin(QStringLiteral("premiumSubscriptionNumber"), ThriftFieldType::T_STRING, 16);
        w.writeString(s.premiumSubscriptionNumber.ref());
        w.writeFieldEnd();
    }
    if(s.lastRequestedCharge.isSet()) {
        w.writeFieldBegin(QStringLiteral("lastRequestedCharge"), ThriftFieldType::T_I64, 17);
        w.writeI64(s.lastRequestedCharge.ref());
        w.writeFieldEnd();
    }
    if(s.currency.isSet()) {
        w.writeFieldBegin(QStringLiteral("currency"), ThriftFieldType::T_STRING, 18);
        w.writeString(s.currency.ref());
        w.writeFieldEnd();
    }
    if(s.unitPrice.isSet()) {
        w.writeFieldBegin(QStringLiteral("unitPrice"), ThriftFieldType::T_I32, 19);
        w.writeI32(s.unitPrice.ref());
        w.writeFieldEnd();
    }
    if(s.businessId.isSet()) {
        w.writeFieldBegin(QStringLiteral("businessId"), ThriftFieldType::T_I32, 20);
        w.writeI32(s.businessId.ref());
        w.writeFieldEnd();
    }
    if(s.businessName.isSet()) {
        w.writeFieldBegin(QStringLiteral("businessName"), ThriftFieldType::T_STRING, 21);
        w.writeString(s.businessName.ref());
        w.writeFieldEnd();
    }
    if(s.businessRole.isSet()) {
        w.writeFieldBegin(QStringLiteral("businessRole"), ThriftFieldType::T_I32, 22);
        w.writeI32(static_cast<qint32>(s.businessRole.ref()));
        w.writeFieldEnd();
    }
    if(s.unitDiscount.isSet()) {
        w.writeFieldBegin(QStringLiteral("unitDiscount"), ThriftFieldType::T_I32, 23);
        w.writeI32(s.unitDiscount.ref());
        w.writeFieldEnd();
    }
    if(s.nextChargeDate.isSet()) {
        w.writeFieldBegin(QStringLiteral("nextChargeDate"), ThriftFieldType::T_I64, 24);
        w.writeI64(s.nextChargeDate.ref());
        w.writeFieldEnd();
    }
    if(s.availablePoints.isSet()) {
        w.writeFieldBegin(QStringLiteral("availablePoints"), ThriftFieldType::T_I32, 25);
        w.writeI32(s.availablePoints.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readAccounting(ThriftBinaryBufferReader & r, Accounting & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.uploadLimitEnd = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.uploadLimitNextMonth = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                PremiumOrderStatus::type v;
                readEnumPremiumOrderStatus(r, v);
                s.premiumServiceStatus = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.premiumOrderNumber = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.premiumCommerceService = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.premiumServiceStart = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.premiumServiceSKU = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.lastSuccessfulCharge = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.lastFailedCharge = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.lastFailedChargeReason = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.nextPaymentDue = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.premiumLockUntil = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.updated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.premiumSubscriptionNumber = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.lastRequestedCharge = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.currency = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.unitPrice = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.businessId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.businessName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole::type v;
                readEnumBusinessUserRole(r, v);
                s.businessRole = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.unitDiscount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.nextChargeDate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 25) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.availablePoints = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeBusinessUserInfo(ThriftBinaryBufferWriter & w, const BusinessUserInfo & s) {
    w.writeStructBegin(QStringLiteral("BusinessUserInfo"));
    if(s.businessId.isSet()) {
        w.writeFieldBegin(QStringLiteral("businessId"), ThriftFieldType::T_I32, 1);
        w.writeI32(s.businessId.ref());
        w.writeFieldEnd();
    }
    if(s.businessName.isSet()) {
        w.writeFieldBegin(QStringLiteral("businessName"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.businessName.ref());
        w.writeFieldEnd();
    }
    if(s.role.isSet()) {
        w.writeFieldBegin(QStringLiteral("role"), ThriftFieldType::T_I32, 3);
        w.writeI32(static_cast<qint32>(s.role.ref()));
        w.writeFieldEnd();
    }
    if(s.email.isSet()) {
        w.writeFieldBegin(QStringLiteral("email"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.email.ref());
        w.writeFieldEnd();
    }
    if(s.updated.isSet()) {
        w.writeFieldBegin(QStringLiteral("updated"), ThriftFieldType::T_I64, 5);
        w.writeI64(s.updated.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readBusinessUserInfo(ThriftBinaryBufferReader & r, BusinessUserInfo & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.businessId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.businessName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole::type v;
                readEnumBusinessUserRole(r, v);
                s.role = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.email = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.updated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeAccountLimits(ThriftBinaryBufferWriter & w, const AccountLimits & s) {
    w.writeStructBegin(QStringLiteral("AccountLimits"));
    if(s.userMailLimitDaily.isSet()) {
        w.writeFieldBegin(QStringLiteral("userMailLimitDaily"), ThriftFieldType::T_I32, 1);
        w.writeI32(s.userMailLimitDaily.ref());
        w.writeFieldEnd();
    }
    if(s.noteSizeMax.isSet()) {
        w.writeFieldBegin(QStringLiteral("noteSizeMax"), ThriftFieldType::T_I64, 2);
        w.writeI64(s.noteSizeMax.ref());
        w.writeFieldEnd();
    }
    if(s.resourceSizeMax.isSet()) {
        w.writeFieldBegin(QStringLiteral("resourceSizeMax"), ThriftFieldType::T_I64, 3);
        w.writeI64(s.resourceSizeMax.ref());
        w.writeFieldEnd();
    }
    if(s.userLinkedNotebookMax.isSet()) {
        w.writeFieldBegin(QStringLiteral("userLinkedNotebookMax"), ThriftFieldType::T_I32, 4);
        w.writeI32(s.userLinkedNotebookMax.ref());
        w.writeFieldEnd();
    }
    if(s.uploadLimit.isSet()) {
        w.writeFieldBegin(QStringLiteral("uploadLimit"), ThriftFieldType::T_I64, 5);
        w.writeI64(s.uploadLimit.ref());
        w.writeFieldEnd();
    }
    if(s.userNoteCountMax.isSet()) {
        w.writeFieldBegin(QStringLiteral("userNoteCountMax"), ThriftFieldType::T_I32, 6);
        w.writeI32(s.userNoteCountMax.ref());
        w.writeFieldEnd();
    }
    if(s.userNotebookCountMax.isSet()) {
        w.writeFieldBegin(QStringLiteral("userNotebookCountMax"), ThriftFieldType::T_I32, 7);
        w.writeI32(s.userNotebookCountMax.ref());
        w.writeFieldEnd();
    }
    if(s.userTagCountMax.isSet()) {
        w.writeFieldBegin(QStringLiteral("userTagCountMax"), ThriftFieldType::T_I32, 8);
        w.writeI32(s.userTagCountMax.ref());
        w.writeFieldEnd();
    }
    if(s.noteTagCountMax.isSet()) {
        w.writeFieldBegin(QStringLiteral("noteTagCountMax"), ThriftFieldType::T_I32, 9);
        w.writeI32(s.noteTagCountMax.ref());
        w.writeFieldEnd();
    }
    if(s.userSavedSearchesMax.isSet()) {
        w.writeFieldBegin(QStringLiteral("userSavedSearchesMax"), ThriftFieldType::T_I32, 10);
        w.writeI32(s.userSavedSearchesMax.ref());
        w.writeFieldEnd();
    }
    if(s.noteResourceCountMax.isSet()) {
        w.writeFieldBegin(QStringLiteral("noteResourceCountMax"), ThriftFieldType::T_I32, 11);
        w.writeI32(s.noteResourceCountMax.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readAccountLimits(ThriftBinaryBufferReader & r, AccountLimits & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.userMailLimitDaily = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.noteSizeMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.resourceSizeMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.userLinkedNotebookMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.uploadLimit = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.userNoteCountMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.userNotebookCountMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.userTagCountMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.noteTagCountMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.userSavedSearchesMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.noteResourceCountMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeUser(ThriftBinaryBufferWriter & w, const User & s) {
    w.writeStructBegin(QStringLiteral("User"));
    if(s.id.isSet()) {
        w.writeFieldBegin(QStringLiteral("id"), ThriftFieldType::T_I32, 1);
        w.writeI32(s.id.ref());
        w.writeFieldEnd();
    }
    if(s.username.isSet()) {
        w.writeFieldBegin(QStringLiteral("username"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.username.ref());
        w.writeFieldEnd();
    }
    if(s.email.isSet()) {
        w.writeFieldBegin(QStringLiteral("email"), ThriftFieldType::T_STRING, 3);
        w.writeString(s.email.ref());
        w.writeFieldEnd();
    }
    if(s.name.isSet()) {
        w.writeFieldBegin(QStringLiteral("name"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.name.ref());
        w.writeFieldEnd();
    }
    if(s.timezone.isSet()) {
        w.writeFieldBegin(QStringLiteral("timezone"), ThriftFieldType::T_STRING, 6);
        w.writeString(s.timezone.ref());
        w.writeFieldEnd();
    }
    if(s.privilege.isSet()) {
        w.writeFieldBegin(QStringLiteral("privilege"), ThriftFieldType::T_I32, 7);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    if(s.serviceLevel.isSet()) {
        w.writeFieldBegin(QStringLiteral("serviceLevel"), ThriftFieldType::T_I32, 21);
        w.writeI32(static_cast<qint32>(s.serviceLevel.ref()));
        w.writeFieldEnd();
    }
    if(s.created.isSet()) {
        w.writeFieldBegin(QStringLiteral("created"), ThriftFieldType::T_I64, 9);
        w.writeI64(s.created.ref());
        w.writeFieldEnd();
    }
    if(s.updated.isSet()) {
        w.writeFieldBegin(QStringLiteral("updated"), ThriftFieldType::T_I64, 10);
        w.writeI64(s.updated.ref());
        w.writeFieldEnd();
    }
    if(s.deleted.isSet()) {
        w.writeFieldBegin(QStringLiteral("deleted"), ThriftFieldType::T_I64, 11);
        w.writeI64(s.deleted.ref());
        w.writeFieldEnd();
    }
    if(s.active.isSet()) {
        w.writeFieldBegin(QStringLiteral("active"), ThriftFieldType::T_BOOL, 13);
        w.writeBool(s.active.ref());
        w.writeFieldEnd();
    }
    if(s.shardId.isSet()) {
        w.writeFieldBegin(QStringLiteral("shardId"), ThriftFieldType::T_STRING, 14);
        w.writeString(s.shardId.ref());
        w.writeFieldEnd();
    }
    if(s.attributes.isSet()) {
        w.writeFieldBegin(QStringLiteral("attributes"), ThriftFieldType::T_STRUCT, 15);
        writeUserAttributes(w, s.attributes.ref());
        w.writeFieldEnd();
    }
    if(s.accounting.isSet()) {
        w.writeFieldBegin(QStringLiteral("accounting"), ThriftFieldType::T_STRUCT, 16);
        writeAccounting(w, s.accounting.ref());
        w.writeFieldEnd();
    }
    if(s.businessUserInfo.isSet()) {
        w.writeFieldBegin(QStringLiteral("businessUserInfo"), ThriftFieldType::T_STRUCT, 18);
        writeBusinessUserInfo(w, s.businessUserInfo.ref());
        w.writeFieldEnd();
    }
    if(s.photoUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("photoUrl"), ThriftFieldType::T_STRING, 19);
        w.writeString(s.photoUrl.ref());
        w.writeFieldEnd();
    }
    if(s.photoLastUpdated.isSet()) {
        w.writeFieldBegin(QStringLiteral("photoLastUpdated"), ThriftFieldType::T_I64, 20);
        w.writeI64(s.photoLastUpdated.ref());
        w.writeFieldEnd();
    }
    if(s.accountLimits.isSet()) {
        w.writeFieldBegin(QStringLiteral("accountLimits"), ThriftFieldType::T_STRUCT, 22);
        writeAccountLimits(w, s.accountLimits.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readUser(ThriftBinaryBufferReader & r, User & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.id = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.username = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.email = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.name = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.timezone = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                PrivilegeLevel::type v;
                readEnumPrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_I32) {
                ServiceLevel::type v;
                readEnumServiceLevel(r, v);
                s.serviceLevel = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.created = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.updated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.deleted = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.active = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.shardId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserAttributes v;
                readUserAttributes(r, v);
                s.attributes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Accounting v;
                readAccounting(r, v);
                s.accounting = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                BusinessUserInfo v;
                readBusinessUserInfo(r, v);
                s.businessUserInfo = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.photoUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.photoLastUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                AccountLimits v;
                readAccountLimits(r, v);
                s.accountLimits = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeContact(ThriftBinaryBufferWriter & w, const Contact & s) {
    w.writeStructBegin(QStringLiteral("Contact"));
    if(s.name.isSet()) {
        w.writeFieldBegin(QStringLiteral("name"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.name.ref());
        w.writeFieldEnd();
    }
    if(s.id.isSet()) {
        w.writeFieldBegin(QStringLiteral("id"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.id.ref());
        w.writeFieldEnd();
    }
    if(s.type.isSet()) {
        w.writeFieldBegin(QStringLiteral("type"), ThriftFieldType::T_I32, 3);
        w.writeI32(static_cast<qint32>(s.type.ref()));
        w.writeFieldEnd();
    }
    if(s.photoUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("photoUrl"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.photoUrl.ref());
        w.writeFieldEnd();
    }
    if(s.photoLastUpdated.isSet()) {
        w.writeFieldBegin(QStringLiteral("photoLastUpdated"), ThriftFieldType::T_I64, 5);
        w.writeI64(s.photoLastUpdated.ref());
        w.writeFieldEnd();
    }
    if(s.messagingPermit.isSet()) {
        w.writeFieldBegin(QStringLiteral("messagingPermit"), ThriftFieldType::T_STRING, 6);
        w.writeBinary(s.messagingPermit.ref());
        w.writeFieldEnd();
    }
    if(s.messagingPermitExpires.isSet()) {
        w.writeFieldBegin(QStringLiteral("messagingPermitExpires"), ThriftFieldType::T_I64, 7);
        w.writeI64(s.messagingPermitExpires.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readContact(ThriftBinaryBufferReader & r, Contact & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.name = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.id = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                ContactType::type v;
                readEnumContactType(r, v);
                s.type = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.photoUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.photoLastUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                r.readBinary(v);
                s.messagingPermit = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.messagingPermitExpires = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeIdentity(ThriftBinaryBufferWriter & w, const Identity & s) {
    w.writeStructBegin(QStringLiteral("Identity"));
    w.writeFieldBegin(QStringLiteral("id"), ThriftFieldType::T_I64, 1);
    w.writeI64(s.id);
    w.writeFieldEnd();
    if(s.contact.isSet()) {
        w.writeFieldBegin(QStringLiteral("contact"), ThriftFieldType::T_STRUCT, 2);
        writeContact(w, s.contact.ref());
        w.writeFieldEnd();
    }
    if(s.userId.isSet()) {
        w.writeFieldBegin(QStringLiteral("userId"), ThriftFieldType::T_I32, 3);
        w.writeI32(s.userId.ref());
        w.writeFieldEnd();
    }
    if(s.deactivated.isSet()) {
        w.writeFieldBegin(QStringLiteral("deactivated"), ThriftFieldType::T_BOOL, 4);
        w.writeBool(s.deactivated.ref());
        w.writeFieldEnd();
    }
    if(s.sameBusiness.isSet()) {
        w.writeFieldBegin(QStringLiteral("sameBusiness"), ThriftFieldType::T_BOOL, 5);
        w.writeBool(s.sameBusiness.ref());
        w.writeFieldEnd();
    }
    if(s.blocked.isSet()) {
        w.writeFieldBegin(QStringLiteral("blocked"), ThriftFieldType::T_BOOL, 6);
        w.writeBool(s.blocked.ref());
        w.writeFieldEnd();
    }
    if(s.userConnected.isSet()) {
        w.writeFieldBegin(QStringLiteral("userConnected"), ThriftFieldType::T_BOOL, 7);
        w.writeBool(s.userConnected.ref());
        w.writeFieldEnd();
    }
    if(s.eventId.isSet()) {
        w.writeFieldBegin(QStringLiteral("eventId"), ThriftFieldType::T_I64, 8);
        w.writeI64(s.eventId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readIdentity(ThriftBinaryBufferReader & r, Identity & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool id_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                id_isset = true;
                IdentityID v;
                r.readI64(v);
                s.id = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Contact v;
                readContact(r, v);
                s.contact = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.userId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.deactivated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.sameBusiness = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.blocked = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.userConnected = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                MessageEventID v;
                r.readI64(v);
                s.eventId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!id_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Identity.id has no value"));
}

void writeTag(ThriftBinaryBufferWriter & w, const Tag & s) {
    w.writeStructBegin(QStringLiteral("Tag"));
    if(s.guid.isSet()) {
        w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if(s.name.isSet()) {
        w.writeFieldBegin(QStringLiteral("name"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.name.ref());
        w.writeFieldEnd();
    }
    if(s.parentGuid.isSet()) {
        w.writeFieldBegin(QStringLiteral("parentGuid"), ThriftFieldType::T_STRING, 3);
        w.writeString(s.parentGuid.ref());
        w.writeFieldEnd();
    }
    if(s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(QStringLiteral("updateSequenceNum"), ThriftFieldType::T_I32, 4);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readTag(ThriftBinaryBufferReader & r, Tag & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.name = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.parentGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeLazyMap(ThriftBinaryBufferWriter & w, const LazyMap & s) {
    w.writeStructBegin(QStringLiteral("LazyMap"));
    if(s.keysOnly.isSet()) {
        w.writeFieldBegin(QStringLiteral("keysOnly"), ThriftFieldType::T_SET, 1);
        w.writeSetBegin(ThriftFieldType::T_STRING, s.keysOnly.ref().count());
        for(QSet< QString >::const_iterator it = s.keysOnly.ref().constBegin(), end = s.keysOnly.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeSetEnd();
        w.writeFieldEnd();
    }
    if(s.fullMap.isSet()) {
        w.writeFieldBegin(QStringLiteral("fullMap"), ThriftFieldType::T_MAP, 2);
        w.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_STRING, s.fullMap.ref().size());
        for(QMap< QString, QString >::const_iterator it = s.fullMap.ref().constBegin(), end = s.fullMap.ref().constEnd(); it != end; ++it) {
            w.writeString(it.key());
            w.writeString(it.value());
        }
        w.writeMapEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readLazyMap(ThriftBinaryBufferReader & r, LazyMap & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_SET) {
                QSet< QString > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readSetBegin(elemType, size);
                v.reserve(size);
                if (elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect set type (LazyMap.keysOnly)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.insert(elem);
                }
                r.readSetEnd();
                s.keysOnly = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap< QString, QString > v;
                qint32 size;
                ThriftFieldType::type keyType;
                ThriftFieldType::type elemType;
                r.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (LazyMap.fullMap)"));
                if (elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (LazyMap.fullMap)"));
                for(qint32 i = 0; i < size; i++) {
                    QString key;
                    r.readString(key);
                    QString value;
                    r.readString(value);
                    v[key] = value;
                }
                r.readMapEnd();
                s.fullMap = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeResourceAttributes(ThriftBinaryBufferWriter & w, const ResourceAttributes & s) {
    w.writeStructBegin(QStringLiteral("ResourceAttributes"));
    if(s.sourceURL.isSet()) {
        w.writeFieldBegin(QStringLiteral("sourceURL"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.sourceURL.ref());
        w.writeFieldEnd();
    }
    if(s.timestamp.isSet()) {
        w.writeFieldBegin(QStringLiteral("timestamp"), ThriftFieldType::T_I64, 2);
        w.writeI64(s.timestamp.ref());
        w.writeFieldEnd();
    }
    if(s.latitude.isSet()) {
        w.writeFieldBegin(QStringLiteral("latitude"), ThriftFieldType::T_DOUBLE, 3);
        w.writeDouble(s.latitude.ref());
        w.writeFieldEnd();
    }
    if(s.longitude.isSet()) {
        w.writeFieldBegin(QStringLiteral("longitude"), ThriftFieldType::T_DOUBLE, 4);
        w.writeDouble(s.longitude.ref());
        w.writeFieldEnd();
    }
    if(s.altitude.isSet()) {
        w.writeFieldBegin(QStringLiteral("altitude"), ThriftFieldType::T_DOUBLE, 5);
        w.writeDouble(s.altitude.ref());
        w.writeFieldEnd();
    }
    if(s.cameraMake.isSet()) {
        w.writeFieldBegin(QStringLiteral("cameraMake"), ThriftFieldType::T_STRING, 6);
        w.writeString(s.cameraMake.ref());
        w.writeFieldEnd();
    }
    if(s.cameraModel.isSet()) {
        w.writeFieldBegin(QStringLiteral("cameraModel"), ThriftFieldType::T_STRING, 7);
        w.writeString(s.cameraModel.ref());
        w.writeFieldEnd();
    }
    if(s.clientWillIndex.isSet()) {
        w.writeFieldBegin(QStringLiteral("clientWillIndex"), ThriftFieldType::T_BOOL, 8);
        w.writeBool(s.clientWillIndex.ref());
        w.writeFieldEnd();
    }
    if(s.recoType.isSet()) {
        w.writeFieldBegin(QStringLiteral("recoType"), ThriftFieldType::T_STRING, 9);
        w.writeString(s.recoType.ref());
        w.writeFieldEnd();
    }
    if(s.fileName.isSet()) {
        w.writeFieldBegin(QStringLiteral("fileName"), ThriftFieldType::T_STRING, 10);
        w.writeString(s.fileName.ref());
        w.writeFieldEnd();
    }
    if(s.attachment.isSet()) {
        w.writeFieldBegin(QStringLiteral("attachment"), ThriftFieldType::T_BOOL, 11);
        w.writeBool(s.attachment.ref());
        w.writeFieldEnd();
    }
    if(s.applicationData.isSet()) {
        w.writeFieldBegin(QStringLiteral("applicationData"), ThriftFieldType::T_STRUCT, 12);
        writeLazyMap(w, s.applicationData.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readResourceAttributes(ThriftBinaryBufferReader & r, ResourceAttributes & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sourceURL = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.timestamp = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.latitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.longitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.altitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.cameraMake = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.cameraModel = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.clientWillIndex = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.recoType = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.fileName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.attachment = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LazyMap v;
                readLazyMap(r, v);
                s.applicationData = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeResource(ThriftBinaryBufferWriter & w, const Resource & s) {
    w.writeStructBegin(QStringLiteral("Resource"));
    if(s.guid.isSet()) {
        w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if(s.noteGuid.isSet()) {
        w.writeFieldBegin(QStringLiteral("noteGuid"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.noteGuid.ref());
        w.writeFieldEnd();
    }
    if(s.data.isSet()) {
        w.writeFieldBegin(QStringLiteral("data"), ThriftFieldType::T_STRUCT, 3);
        writeData(w, s.data.ref());
        w.writeFieldEnd();
    }
    if(s.mime.isSet()) {
        w.writeFieldBegin(QStringLiteral("mime"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.mime.ref());
        w.writeFieldEnd();
    }
    if(s.width.isSet()) {
        w.writeFieldBegin(QStringLiteral("width"), ThriftFieldType::T_I16, 5);
        w.writeI16(s.width.ref());
        w.writeFieldEnd();
    }
    if(s.height.isSet()) {
        w.writeFieldBegin(QStringLiteral("height"), ThriftFieldType::T_I16, 6);
        w.writeI16(s.height.ref());
        w.writeFieldEnd();
    }
    if(s.duration.isSet()) {
        w.writeFieldBegin(QStringLiteral("duration"), ThriftFieldType::T_I16, 7);
        w.writeI16(s.duration.ref());
        w.writeFieldEnd();
    }
    if(s.active.isSet()) {
        w.writeFieldBegin(QStringLiteral("active"), ThriftFieldType::T_BOOL, 8);
        w.writeBool(s.active.ref());
        w.writeFieldEnd();
    }
    if(s.recognition.isSet()) {
        w.writeFieldBegin(QStringLiteral("recognition"), ThriftFieldType::T_STRUCT, 9);
        writeData(w, s.recognition.ref());
        w.writeFieldEnd();
    }
    if(s.attributes.isSet()) {
        w.writeFieldBegin(QStringLiteral("attributes"), ThriftFieldType::T_STRUCT, 11);
        writeResourceAttributes(w, s.attributes.ref());
        w.writeFieldEnd();
    }
    if(s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(QStringLiteral("updateSequenceNum"), ThriftFieldType::T_I32, 12);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if(s.alternateData.isSet()) {
        w.writeFieldBegin(QStringLiteral("alternateData"), ThriftFieldType::T_STRUCT, 13);
        writeData(w, s.alternateData.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readResource(ThriftBinaryBufferReader & r, Resource & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.noteGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Data v;
                readData(r, v);
                s.data = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.mime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                r.readI16(v);
                s.width = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                r.readI16(v);
                s.height = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                r.readI16(v);
                s.duration = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.active = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Data v;
                readData(r, v);
                s.recognition = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                ResourceAttributes v;
                readResourceAttributes(r, v);
                s.attributes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Data v;
                readData(r, v);
                s.alternateData = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNoteAttributes(ThriftBinaryBufferWriter & w, const NoteAttributes & s) {
    w.writeStructBegin(QStringLiteral("NoteAttributes"));
    if(s.subjectDate.isSet()) {
        w.writeFieldBegin(QStringLiteral("subjectDate"), ThriftFieldType::T_I64, 1);
        w.writeI64(s.subjectDate.ref());
        w.writeFieldEnd();
    }
    if(s.latitude.isSet()) {
        w.writeFieldBegin(QStringLiteral("latitude"), ThriftFieldType::T_DOUBLE, 10);
        w.writeDouble(s.latitude.ref());
        w.writeFieldEnd();
    }
    if(s.longitude.isSet()) {
        w.writeFieldBegin(QStringLiteral("longitude"), ThriftFieldType::T_DOUBLE, 11);
        w.writeDouble(s.longitude.ref());
        w.writeFieldEnd();
    }
    if(s.altitude.isSet()) {
        w.writeFieldBegin(QStringLiteral("altitude"), ThriftFieldType::T_DOUBLE, 12);
        w.writeDouble(s.altitude.ref());
        w.writeFieldEnd();
    }
    if(s.author.isSet()) {
        w.writeFieldBegin(QStringLiteral("author"), ThriftFieldType::T_STRING, 13);
        w.writeString(s.author.ref());
        w.writeFieldEnd();
    }
    if(s.source.isSet()) {
        w.writeFieldBegin(QStringLiteral("source"), ThriftFieldType::T_STRING, 14);
        w.writeString(s.source.ref());
        w.writeFieldEnd();
    }
    if(s.sourceURL.isSet()) {
        w.writeFieldBegin(QStringLiteral("sourceURL"), ThriftFieldType::T_STRING, 15);
        w.writeString(s.sourceURL.ref());
        w.writeFieldEnd();
    }
    if(s.sourceApplication.isSet()) {
        w.writeFieldBegin(QStringLiteral("sourceApplication"), ThriftFieldType::T_STRING, 16);
        w.writeString(s.sourceApplication.ref());
        w.writeFieldEnd();
    }
    if(s.shareDate.isSet()) {
        w.writeFieldBegin(QStringLiteral("shareDate"), ThriftFieldType::T_I64, 17);
        w.writeI64(s.shareDate.ref());
        w.writeFieldEnd();
    }
    if(s.reminderOrder.isSet()) {
        w.writeFieldBegin(QStringLiteral("reminderOrder"), ThriftFieldType::T_I64, 18);
        w.writeI64(s.reminderOrder.ref());
        w.writeFieldEnd();
    }
    if(s.reminderDoneTime.isSet()) {
        w.writeFieldBegin(QStringLiteral("reminderDoneTime"), ThriftFieldType::T_I64, 19);
        w.writeI64(s.reminderDoneTime.ref());
        w.writeFieldEnd();
    }
    if(s.reminderTime.isSet()) {
        w.writeFieldBegin(QStringLiteral("reminderTime"), ThriftFieldType::T_I64, 20);
        w.writeI64(s.reminderTime.ref());
        w.writeFieldEnd();
    }
    if(s.placeName.isSet()) {
        w.writeFieldBegin(QStringLiteral("placeName"), ThriftFieldType::T_STRING, 21);
        w.writeString(s.placeName.ref());
        w.writeFieldEnd();
    }
    if(s.contentClass.isSet()) {
        w.writeFieldBegin(QStringLiteral("contentClass"), ThriftFieldType::T_STRING, 22);
        w.writeString(s.contentClass.ref());
        w.writeFieldEnd();
    }
    if(s.applicationData.isSet()) {
        w.writeFieldBegin(QStringLiteral("applicationData"), ThriftFieldType::T_STRUCT, 23);
        writeLazyMap(w, s.applicationData.ref());
        w.writeFieldEnd();
    }
    if(s.lastEditedBy.isSet()) {
        w.writeFieldBegin(QStringLiteral("lastEditedBy"), ThriftFieldType::T_STRING, 24);
        w.writeString(s.lastEditedBy.ref());
        w.writeFieldEnd();
    }
    if(s.classifications.isSet()) {
        w.writeFieldBegin(QStringLiteral("classifications"), ThriftFieldType::T_MAP, 26);
        w.writeMapBegin(ThriftFieldType::T_STRING, ThriftFieldType::T_STRING, s.classifications.ref().size());
        for(QMap< QString, QString >::const_iterator it = s.classifications.ref().constBegin(), end = s.classifications.ref().constEnd(); it != end; ++it) {
            w.writeString(it.key());
            w.writeString(it.value());
        }
        w.writeMapEnd();
        w.writeFieldEnd();
    }
    if(s.creatorId.isSet()) {
        w.writeFieldBegin(QStringLiteral("creatorId"), ThriftFieldType::T_I32, 27);
        w.writeI32(s.creatorId.ref());
        w.writeFieldEnd();
    }
    if(s.lastEditorId.isSet()) {
        w.writeFieldBegin(QStringLiteral("lastEditorId"), ThriftFieldType::T_I32, 28);
        w.writeI32(s.lastEditorId.ref());
        w.writeFieldEnd();
    }
    if(s.sharedWithBusiness.isSet()) {
        w.writeFieldBegin(QStringLiteral("sharedWithBusiness"), ThriftFieldType::T_BOOL, 29);
        w.writeBool(s.sharedWithBusiness.ref());
        w.writeFieldEnd();
    }
    if(s.conflictSourceNoteGuid.isSet()) {
        w.writeFieldBegin(QStringLiteral("conflictSourceNoteGuid"), ThriftFieldType::T_STRING, 30);
        w.writeString(s.conflictSourceNoteGuid.ref());
        w.writeFieldEnd();
    }
    if(s.noteTitleQuality.isSet()) {
        w.writeFieldBegin(QStringLiteral("noteTitleQuality"), ThriftFieldType::T_I32, 31);
        w.writeI32(s.noteTitleQuality.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteAttributes(ThriftBinaryBufferReader & r, NoteAttributes & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.subjectDate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.latitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.longitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.altitude = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.author = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.source = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sourceURL = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sourceApplication = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.shareDate = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.reminderOrder = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.reminderDoneTime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.reminderTime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.placeName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.contentClass = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LazyMap v;
                readLazyMap(r, v);
                s.applicationData = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.lastEditedBy = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 26) {
            if (fieldType == ThriftFieldType::T_MAP) {
                QMap< QString, QString > v;
                qint32 size;
                ThriftFieldType::type keyType;
                ThriftFieldType::type elemType;
                r.readMapBegin(keyType, elemType, size);
                if (keyType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map key type (NoteAttributes.classifications)"));
                if (elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect map value type (NoteAttributes.classifications)"));
                for(qint32 i = 0; i < size; i++) {
                    QString key;
                    r.readString(key);
                    QString value;
                    r.readString(value);
                    v[key] = value;
                }
                r.readMapEnd();
                s.classifications = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 27) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.creatorId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 28) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.lastEditorId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 29) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.sharedWithBusiness = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 30) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.conflictSourceNoteGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 31) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.noteTitleQuality = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeSharedNote(ThriftBinaryBufferWriter & w, const SharedNote & s) {
    w.writeStructBegin(QStringLiteral("SharedNote"));
    if(s.sharerUserID.isSet()) {
        w.writeFieldBegin(QStringLiteral("sharerUserID"), ThriftFieldType::T_I32, 1);
        w.writeI32(s.sharerUserID.ref());
        w.writeFieldEnd();
    }
    if(s.recipientIdentity.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientIdentity"), ThriftFieldType::T_STRUCT, 2);
        writeIdentity(w, s.recipientIdentity.ref());
        w.writeFieldEnd();
    }
    if(s.privilege.isSet()) {
        w.writeFieldBegin(QStringLiteral("privilege"), ThriftFieldType::T_I32, 3);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    if(s.serviceCreated.isSet()) {
        w.writeFieldBegin(QStringLiteral("serviceCreated"), ThriftFieldType::T_I64, 4);
        w.writeI64(s.serviceCreated.ref());
        w.writeFieldEnd();
    }
    if(s.serviceUpdated.isSet()) {
        w.writeFieldBegin(QStringLiteral("serviceUpdated"), ThriftFieldType::T_I64, 5);
        w.writeI64(s.serviceUpdated.ref());
        w.writeFieldEnd();
    }
    if(s.serviceAssigned.isSet()) {
        w.writeFieldBegin(QStringLiteral("serviceAssigned"), ThriftFieldType::T_I64, 6);
        w.writeI64(s.serviceAssigned.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSharedNote(ThriftBinaryBufferReader & r, SharedNote & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.sharerUserID = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Identity v;
                readIdentity(r, v);
                s.recipientIdentity = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotePrivilegeLevel::type v;
                readEnumSharedNotePrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceCreated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceAssigned = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNoteRestrictions(ThriftBinaryBufferWriter & w, const NoteRestrictions & s) {
    w.writeStructBegin(QStringLiteral("NoteRestrictions"));
    if(s.noUpdateTitle.isSet()) {
        w.writeFieldBegin(QStringLiteral("noUpdateTitle"), ThriftFieldType::T_BOOL, 1);
        w.writeBool(s.noUpdateTitle.ref());
        w.writeFieldEnd();
    }
    if(s.noUpdateContent.isSet()) {
        w.writeFieldBegin(QStringLiteral("noUpdateContent"), ThriftFieldType::T_BOOL, 2);
        w.writeBool(s.noUpdateContent.ref());
        w.writeFieldEnd();
    }
    if(s.noEmail.isSet()) {
        w.writeFieldBegin(QStringLiteral("noEmail"), ThriftFieldType::T_BOOL, 3);
        w.writeBool(s.noEmail.ref());
        w.writeFieldEnd();
    }
    if(s.noShare.isSet()) {
        w.writeFieldBegin(QStringLiteral("noShare"), ThriftFieldType::T_BOOL, 4);
        w.writeBool(s.noShare.ref());
        w.writeFieldEnd();
    }
    if(s.noSharePublicly.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSharePublicly"), ThriftFieldType::T_BOOL, 5);
        w.writeBool(s.noSharePublicly.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteRestrictions(ThriftBinaryBufferReader & r, NoteRestrictions & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noUpdateTitle = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noUpdateContent = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noEmail = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noShare = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSharePublicly = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNoteLimits(ThriftBinaryBufferWriter & w, const NoteLimits & s) {
    w.writeStructBegin(QStringLiteral("NoteLimits"));
    if(s.noteResourceCountMax.isSet()) {
        w.writeFieldBegin(QStringLiteral("noteResourceCountMax"), ThriftFieldType::T_I32, 1);
        w.writeI32(s.noteResourceCountMax.ref());
        w.writeFieldEnd();
    }
    if(s.uploadLimit.isSet()) {
        w.writeFieldBegin(QStringLiteral("uploadLimit"), ThriftFieldType::T_I64, 2);
        w.writeI64(s.uploadLimit.ref());
        w.writeFieldEnd();
    }
    if(s.resourceSizeMax.isSet()) {
        w.writeFieldBegin(QStringLiteral("resourceSizeMax"), ThriftFieldType::T_I64, 3);
        w.writeI64(s.resourceSizeMax.ref());
        w.writeFieldEnd();
    }
    if(s.noteSizeMax.isSet()) {
        w.writeFieldBegin(QStringLiteral("noteSizeMax"), ThriftFieldType::T_I64, 4);
        w.writeI64(s.noteSizeMax.ref());
        w.writeFieldEnd();
    }
    if(s.uploaded.isSet()) {
        w.writeFieldBegin(QStringLiteral("uploaded"), ThriftFieldType::T_I64, 5);
        w.writeI64(s.uploaded.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNoteLimits(ThriftBinaryBufferReader & r, NoteLimits & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.noteResourceCountMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.uploadLimit = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.resourceSizeMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.noteSizeMax = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.uploaded = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNote(ThriftBinaryBufferWriter & w, const Note & s) {
    w.writeStructBegin(QStringLiteral("Note"));
    if(s.guid.isSet()) {
        w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if(s.title.isSet()) {
        w.writeFieldBegin(QStringLiteral("title"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.title.ref());
        w.writeFieldEnd();
    }
    if(s.content.isSet()) {
        w.writeFieldBegin(QStringLiteral("content"), ThriftFieldType::T_STRING, 3);
        w.writeString(s.content.ref());
        w.writeFieldEnd();
    }
    if(s.contentHash.isSet()) {
        w.writeFieldBegin(QStringLiteral("contentHash"), ThriftFieldType::T_STRING, 4);
        w.writeBinary(s.contentHash.ref());
        w.writeFieldEnd();
    }
    if(s.contentLength.isSet()) {
        w.writeFieldBegin(QStringLiteral("contentLength"), ThriftFieldType::T_I32, 5);
        w.writeI32(s.contentLength.ref());
        w.writeFieldEnd();
    }
    if(s.created.isSet()) {
        w.writeFieldBegin(QStringLiteral("created"), ThriftFieldType::T_I64, 6);
        w.writeI64(s.created.ref());
        w.writeFieldEnd();
    }
    if(s.updated.isSet()) {
        w.writeFieldBegin(QStringLiteral("updated"), ThriftFieldType::T_I64, 7);
        w.writeI64(s.updated.ref());
        w.writeFieldEnd();
    }
    if(s.deleted.isSet()) {
        w.writeFieldBegin(QStringLiteral("deleted"), ThriftFieldType::T_I64, 8);
        w.writeI64(s.deleted.ref());
        w.writeFieldEnd();
    }
    if(s.active.isSet()) {
        w.writeFieldBegin(QStringLiteral("active"), ThriftFieldType::T_BOOL, 9);
        w.writeBool(s.active.ref());
        w.writeFieldEnd();
    }
    if(s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(QStringLiteral("updateSequenceNum"), ThriftFieldType::T_I32, 10);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if(s.notebookGuid.isSet()) {
        w.writeFieldBegin(QStringLiteral("notebookGuid"), ThriftFieldType::T_STRING, 11);
        w.writeString(s.notebookGuid.ref());
        w.writeFieldEnd();
    }
    if(s.tagGuids.isSet()) {
        w.writeFieldBegin(QStringLiteral("tagGuids"), ThriftFieldType::T_LIST, 12);
        w.writeListBegin(ThriftFieldType::T_STRING, s.tagGuids.ref().length());
        for(QList< Guid >::const_iterator it = s.tagGuids.ref().constBegin(), end = s.tagGuids.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.resources.isSet()) {
        w.writeFieldBegin(QStringLiteral("resources"), ThriftFieldType::T_LIST, 13);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.resources.ref().length());
        for(QList< Resource >::const_iterator it = s.resources.ref().constBegin(), end = s.resources.ref().constEnd(); it != end; ++it) {
            writeResource(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.attributes.isSet()) {
        w.writeFieldBegin(QStringLiteral("attributes"), ThriftFieldType::T_STRUCT, 14);
        writeNoteAttributes(w, s.attributes.ref());
        w.writeFieldEnd();
    }
    if(s.tagNames.isSet()) {
        w.writeFieldBegin(QStringLiteral("tagNames"), ThriftFieldType::T_LIST, 15);
        w.writeListBegin(ThriftFieldType::T_STRING, s.tagNames.ref().length());
        for(QStringList::const_iterator it = s.tagNames.ref().constBegin(), end = s.tagNames.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.sharedNotes.isSet()) {
        w.writeFieldBegin(QStringLiteral("sharedNotes"), ThriftFieldType::T_LIST, 16);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.sharedNotes.ref().length());
        for(QList< SharedNote >::const_iterator it = s.sharedNotes.ref().constBegin(), end = s.sharedNotes.ref().constEnd(); it != end; ++it) {
            writeSharedNote(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.restrictions.isSet()) {
        w.writeFieldBegin(QStringLiteral("restrictions"), ThriftFieldType::T_STRUCT, 17);
        writeNoteRestrictions(w, s.restrictions.ref());
        w.writeFieldEnd();
    }
    if(s.limits.isSet()) {
        w.writeFieldBegin(QStringLiteral("limits"), ThriftFieldType::T_STRUCT, 18);
        writeNoteLimits(w, s.limits.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNote(ThriftBinaryBufferReader & r, Note & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.title = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.content = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                r.readBinary(v);
                s.contentHash = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.contentLength = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.created = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.updated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.deleted = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.active = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.notebookGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Guid > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (Note.tagGuids)"));
                for(qint32 i = 0; i < size; i++) {
                    Guid elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.tagGuids = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< Resource > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (Note.resources)"));
                for(qint32 i = 0; i < size; i++) {
                    Resource elem;
                    readResource(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.resources = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteAttributes v;
                readNoteAttributes(r, v);
                s.attributes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (Note.tagNames)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.tagNames = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< SharedNote > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (Note.sharedNotes)"));
                for(qint32 i = 0; i < size; i++) {
                    SharedNote elem;
                    readSharedNote(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.sharedNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteRestrictions v;
                readNoteRestrictions(r, v);
                s.restrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteLimits v;
                readNoteLimits(r, v);
                s.limits = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writePublishing(ThriftBinaryBufferWriter & w, const Publishing & s) {
    w.writeStructBegin(QStringLiteral("Publishing"));
    if(s.uri.isSet()) {
        w.writeFieldBegin(QStringLiteral("uri"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.uri.ref());
        w.writeFieldEnd();
    }
    if(s.order.isSet()) {
        w.writeFieldBegin(QStringLiteral("order"), ThriftFieldType::T_I32, 2);
        w.writeI32(static_cast<qint32>(s.order.ref()));
        w.writeFieldEnd();
    }
    if(s.ascending.isSet()) {
        w.writeFieldBegin(QStringLiteral("ascending"), ThriftFieldType::T_BOOL, 3);
        w.writeBool(s.ascending.ref());
        w.writeFieldEnd();
    }
    if(s.publicDescription.isSet()) {
        w.writeFieldBegin(QStringLiteral("publicDescription"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.publicDescription.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readPublishing(ThriftBinaryBufferReader & r, Publishing & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.uri = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                NoteSortOrder::type v;
                readEnumNoteSortOrder(r, v);
                s.order = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.ascending = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.publicDescription = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeBusinessNotebook(ThriftBinaryBufferWriter & w, const BusinessNotebook & s) {
    w.writeStructBegin(QStringLiteral("BusinessNotebook"));
    if(s.notebookDescription.isSet()) {
        w.writeFieldBegin(QStringLiteral("notebookDescription"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.notebookDescription.ref());
        w.writeFieldEnd();
    }
    if(s.privilege.isSet()) {
        w.writeFieldBegin(QStringLiteral("privilege"), ThriftFieldType::T_I32, 2);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    if(s.recommended.isSet()) {
        w.writeFieldBegin(QStringLiteral("recommended"), ThriftFieldType::T_BOOL, 3);
        w.writeBool(s.recommended.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readBusinessNotebook(ThriftBinaryBufferReader & r, BusinessNotebook & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.notebookDescription = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookPrivilegeLevel::type v;
                readEnumSharedNotebookPrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.recommended = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeSavedSearchScope(ThriftBinaryBufferWriter & w, const SavedSearchScope & s) {
    w.writeStructBegin(QStringLiteral("SavedSearchScope"));
    if(s.includeAccount.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeAccount"), ThriftFieldType::T_BOOL, 1);
        w.writeBool(s.includeAccount.ref());
        w.writeFieldEnd();
    }
    if(s.includePersonalLinkedNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("includePersonalLinkedNotebooks"), ThriftFieldType::T_BOOL, 2);
        w.writeBool(s.includePersonalLinkedNotebooks.ref());
        w.writeFieldEnd();
    }
    if(s.includeBusinessLinkedNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("includeBusinessLinkedNotebooks"), ThriftFieldType::T_BOOL, 3);
        w.writeBool(s.includeBusinessLinkedNotebooks.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSavedSearchScope(ThriftBinaryBufferReader & r, SavedSearchScope & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeAccount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includePersonalLinkedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.includeBusinessLinkedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeSavedSearch(ThriftBinaryBufferWriter & w, const SavedSearch & s) {
    w.writeStructBegin(QStringLiteral("SavedSearch"));
    if(s.guid.isSet()) {
        w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if(s.name.isSet()) {
        w.writeFieldBegin(QStringLiteral("name"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.name.ref());
        w.writeFieldEnd();
    }
    if(s.query.isSet()) {
        w.writeFieldBegin(QStringLiteral("query"), ThriftFieldType::T_STRING, 3);
        w.writeString(s.query.ref());
        w.writeFieldEnd();
    }
    if(s.format.isSet()) {
        w.writeFieldBegin(QStringLiteral("format"), ThriftFieldType::T_I32, 4);
        w.writeI32(static_cast<qint32>(s.format.ref()));
        w.writeFieldEnd();
    }
    if(s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(QStringLiteral("updateSequenceNum"), ThriftFieldType::T_I32, 5);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if(s.scope.isSet()) {
        w.writeFieldBegin(QStringLiteral("scope"), ThriftFieldType::T_STRUCT, 6);
        writeSavedSearchScope(w, s.scope.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSavedSearch(ThriftBinaryBufferReader & r, SavedSearch & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.name = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.query = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                QueryFormat::type v;
                readEnumQueryFormat(r, v);
                s.format = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SavedSearchScope v;
                readSavedSearchScope(r, v);
                s.scope = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeSharedNotebookRecipientSettings(ThriftBinaryBufferWriter & w, const SharedNotebookRecipientSettings & s) {
    w.writeStructBegin(QStringLiteral("SharedNotebookRecipientSettings"));
    if(s.reminderNotifyEmail.isSet()) {
        w.writeFieldBegin(QStringLiteral("reminderNotifyEmail"), ThriftFieldType::T_BOOL, 1);
        w.writeBool(s.reminderNotifyEmail.ref());
        w.writeFieldEnd();
    }
    if(s.reminderNotifyInApp.isSet()) {
        w.writeFieldBegin(QStringLiteral("reminderNotifyInApp"), ThriftFieldType::T_BOOL, 2);
        w.writeBool(s.reminderNotifyInApp.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSharedNotebookRecipientSettings(ThriftBinaryBufferReader & r, SharedNotebookRecipientSettings & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.reminderNotifyEmail = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.reminderNotifyInApp = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNotebookRecipientSettings(ThriftBinaryBufferWriter & w, const NotebookRecipientSettings & s) {
    w.writeStructBegin(QStringLiteral("NotebookRecipientSettings"));
    if(s.reminderNotifyEmail.isSet()) {
        w.writeFieldBegin(QStringLiteral("reminderNotifyEmail"), ThriftFieldType::T_BOOL, 1);
        w.writeBool(s.reminderNotifyEmail.ref());
        w.writeFieldEnd();
    }
    if(s.reminderNotifyInApp.isSet()) {
        w.writeFieldBegin(QStringLiteral("reminderNotifyInApp"), ThriftFieldType::T_BOOL, 2);
        w.writeBool(s.reminderNotifyInApp.ref());
        w.writeFieldEnd();
    }
    if(s.inMyList.isSet()) {
        w.writeFieldBegin(QStringLiteral("inMyList"), ThriftFieldType::T_BOOL, 3);
        w.writeBool(s.inMyList.ref());
        w.writeFieldEnd();
    }
    if(s.stack.isSet()) {
        w.writeFieldBegin(QStringLiteral("stack"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.stack.ref());
        w.writeFieldEnd();
    }
    if(s.recipientStatus.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientStatus"), ThriftFieldType::T_I32, 5);
        w.writeI32(static_cast<qint32>(s.recipientStatus.ref()));
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNotebookRecipientSettings(ThriftBinaryBufferReader & r, NotebookRecipientSettings & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.reminderNotifyEmail = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.reminderNotifyInApp = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.inMyList = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.stack = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                RecipientStatus::type v;
                readEnumRecipientStatus(r, v);
                s.recipientStatus = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeSharedNotebook(ThriftBinaryBufferWriter & w, const SharedNotebook & s) {
    w.writeStructBegin(QStringLiteral("SharedNotebook"));
    if(s.id.isSet()) {
        w.writeFieldBegin(QStringLiteral("id"), ThriftFieldType::T_I64, 1);
        w.writeI64(s.id.ref());
        w.writeFieldEnd();
    }
    if(s.userId.isSet()) {
        w.writeFieldBegin(QStringLiteral("userId"), ThriftFieldType::T_I32, 2);
        w.writeI32(s.userId.ref());
        w.writeFieldEnd();
    }
    if(s.notebookGuid.isSet()) {
        w.writeFieldBegin(QStringLiteral("notebookGuid"), ThriftFieldType::T_STRING, 3);
        w.writeString(s.notebookGuid.ref());
        w.writeFieldEnd();
    }
    if(s.email.isSet()) {
        w.writeFieldBegin(QStringLiteral("email"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.email.ref());
        w.writeFieldEnd();
    }
    if(s.recipientIdentityId.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientIdentityId"), ThriftFieldType::T_I64, 18);
        w.writeI64(s.recipientIdentityId.ref());
        w.writeFieldEnd();
    }
    if(s.notebookModifiable.isSet()) {
        w.writeFieldBegin(QStringLiteral("notebookModifiable"), ThriftFieldType::T_BOOL, 5);
        w.writeBool(s.notebookModifiable.ref());
        w.writeFieldEnd();
    }
    if(s.serviceCreated.isSet()) {
        w.writeFieldBegin(QStringLiteral("serviceCreated"), ThriftFieldType::T_I64, 7);
        w.writeI64(s.serviceCreated.ref());
        w.writeFieldEnd();
    }
    if(s.serviceUpdated.isSet()) {
        w.writeFieldBegin(QStringLiteral("serviceUpdated"), ThriftFieldType::T_I64, 10);
        w.writeI64(s.serviceUpdated.ref());
        w.writeFieldEnd();
    }
    if(s.globalId.isSet()) {
        w.writeFieldBegin(QStringLiteral("globalId"), ThriftFieldType::T_STRING, 8);
        w.writeString(s.globalId.ref());
        w.writeFieldEnd();
    }
    if(s.username.isSet()) {
        w.writeFieldBegin(QStringLiteral("username"), ThriftFieldType::T_STRING, 9);
        w.writeString(s.username.ref());
        w.writeFieldEnd();
    }
    if(s.privilege.isSet()) {
        w.writeFieldBegin(QStringLiteral("privilege"), ThriftFieldType::T_I32, 11);
        w.writeI32(static_cast<qint32>(s.privilege.ref()));
        w.writeFieldEnd();
    }
    if(s.recipientSettings.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientSettings"), ThriftFieldType::T_STRUCT, 13);
        writeSharedNotebookRecipientSettings(w, s.recipientSettings.ref());
        w.writeFieldEnd();
    }
    if(s.sharerUserId.isSet()) {
        w.writeFieldBegin(QStringLiteral("sharerUserId"), ThriftFieldType::T_I32, 14);
        w.writeI32(s.sharerUserId.ref());
        w.writeFieldEnd();
    }
    if(s.recipientUsername.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientUsername"), ThriftFieldType::T_STRING, 15);
        w.writeString(s.recipientUsername.ref());
        w.writeFieldEnd();
    }
    if(s.recipientUserId.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientUserId"), ThriftFieldType::T_I32, 17);
        w.writeI32(s.recipientUserId.ref());
        w.writeFieldEnd();
    }
    if(s.serviceAssigned.isSet()) {
        w.writeFieldBegin(QStringLiteral("serviceAssigned"), ThriftFieldType::T_I64, 16);
        w.writeI64(s.serviceAssigned.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readSharedNotebook(ThriftBinaryBufferReader & r, SharedNotebook & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.id = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.userId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.notebookGuid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.email = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_I64) {
                IdentityID v;
                r.readI64(v);
                s.recipientIdentityId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.notebookModifiable = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceCreated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.globalId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.username = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookPrivilegeLevel::type v;
                readEnumSharedNotebookPrivilegeLevel(r, v);
                s.privilege = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SharedNotebookRecipientSettings v;
                readSharedNotebookRecipientSettings(r, v);
                s.recipientSettings = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.sharerUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.recipientUsername = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.recipientUserId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceAssigned = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeCanMoveToContainerRestrictions(ThriftBinaryBufferWriter & w, const CanMoveToContainerRestrictions & s) {
    w.writeStructBegin(QStringLiteral("CanMoveToContainerRestrictions"));
    if(s.canMoveToContainer.isSet()) {
        w.writeFieldBegin(QStringLiteral("canMoveToContainer"), ThriftFieldType::T_I32, 1);
        w.writeI32(static_cast<qint32>(s.canMoveToContainer.ref()));
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readCanMoveToContainerRestrictions(ThriftBinaryBufferReader & r, CanMoveToContainerRestrictions & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                CanMoveToContainerStatus::type v;
                readEnumCanMoveToContainerStatus(r, v);
                s.canMoveToContainer = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNotebookRestrictions(ThriftBinaryBufferWriter & w, const NotebookRestrictions & s) {
    w.writeStructBegin(QStringLiteral("NotebookRestrictions"));
    if(s.noReadNotes.isSet()) {
        w.writeFieldBegin(QStringLiteral("noReadNotes"), ThriftFieldType::T_BOOL, 1);
        w.writeBool(s.noReadNotes.ref());
        w.writeFieldEnd();
    }
    if(s.noCreateNotes.isSet()) {
        w.writeFieldBegin(QStringLiteral("noCreateNotes"), ThriftFieldType::T_BOOL, 2);
        w.writeBool(s.noCreateNotes.ref());
        w.writeFieldEnd();
    }
    if(s.noUpdateNotes.isSet()) {
        w.writeFieldBegin(QStringLiteral("noUpdateNotes"), ThriftFieldType::T_BOOL, 3);
        w.writeBool(s.noUpdateNotes.ref());
        w.writeFieldEnd();
    }
    if(s.noExpungeNotes.isSet()) {
        w.writeFieldBegin(QStringLiteral("noExpungeNotes"), ThriftFieldType::T_BOOL, 4);
        w.writeBool(s.noExpungeNotes.ref());
        w.writeFieldEnd();
    }
    if(s.noShareNotes.isSet()) {
        w.writeFieldBegin(QStringLiteral("noShareNotes"), ThriftFieldType::T_BOOL, 5);
        w.writeBool(s.noShareNotes.ref());
        w.writeFieldEnd();
    }
    if(s.noEmailNotes.isSet()) {
        w.writeFieldBegin(QStringLiteral("noEmailNotes"), ThriftFieldType::T_BOOL, 6);
        w.writeBool(s.noEmailNotes.ref());
        w.writeFieldEnd();
    }
    if(s.noSendMessageToRecipients.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSendMessageToRecipients"), ThriftFieldType::T_BOOL, 7);
        w.writeBool(s.noSendMessageToRecipients.ref());
        w.writeFieldEnd();
    }
    if(s.noUpdateNotebook.isSet()) {
        w.writeFieldBegin(QStringLiteral("noUpdateNotebook"), ThriftFieldType::T_BOOL, 8);
        w.writeBool(s.noUpdateNotebook.ref());
        w.writeFieldEnd();
    }
    if(s.noExpungeNotebook.isSet()) {
        w.writeFieldBegin(QStringLiteral("noExpungeNotebook"), ThriftFieldType::T_BOOL, 9);
        w.writeBool(s.noExpungeNotebook.ref());
        w.writeFieldEnd();
    }
    if(s.noSetDefaultNotebook.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSetDefaultNotebook"), ThriftFieldType::T_BOOL, 10);
        w.writeBool(s.noSetDefaultNotebook.ref());
        w.writeFieldEnd();
    }
    if(s.noSetNotebookStack.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSetNotebookStack"), ThriftFieldType::T_BOOL, 11);
        w.writeBool(s.noSetNotebookStack.ref());
        w.writeFieldEnd();
    }
    if(s.noPublishToPublic.isSet()) {
        w.writeFieldBegin(QStringLiteral("noPublishToPublic"), ThriftFieldType::T_BOOL, 12);
        w.writeBool(s.noPublishToPublic.ref());
        w.writeFieldEnd();
    }
    if(s.noPublishToBusinessLibrary.isSet()) {
        w.writeFieldBegin(QStringLiteral("noPublishToBusinessLibrary"), ThriftFieldType::T_BOOL, 13);
        w.writeBool(s.noPublishToBusinessLibrary.ref());
        w.writeFieldEnd();
    }
    if(s.noCreateTags.isSet()) {
        w.writeFieldBegin(QStringLiteral("noCreateTags"), ThriftFieldType::T_BOOL, 14);
        w.writeBool(s.noCreateTags.ref());
        w.writeFieldEnd();
    }
    if(s.noUpdateTags.isSet()) {
        w.writeFieldBegin(QStringLiteral("noUpdateTags"), ThriftFieldType::T_BOOL, 15);
        w.writeBool(s.noUpdateTags.ref());
        w.writeFieldEnd();
    }
    if(s.noExpungeTags.isSet()) {
        w.writeFieldBegin(QStringLiteral("noExpungeTags"), ThriftFieldType::T_BOOL, 16);
        w.writeBool(s.noExpungeTags.ref());
        w.writeFieldEnd();
    }
    if(s.noSetParentTag.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSetParentTag"), ThriftFieldType::T_BOOL, 17);
        w.writeBool(s.noSetParentTag.ref());
        w.writeFieldEnd();
    }
    if(s.noCreateSharedNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("noCreateSharedNotebooks"), ThriftFieldType::T_BOOL, 18);
        w.writeBool(s.noCreateSharedNotebooks.ref());
        w.writeFieldEnd();
    }
    if(s.updateWhichSharedNotebookRestrictions.isSet()) {
        w.writeFieldBegin(QStringLiteral("updateWhichSharedNotebookRestrictions"), ThriftFieldType::T_I32, 19);
        w.writeI32(static_cast<qint32>(s.updateWhichSharedNotebookRestrictions.ref()));
        w.writeFieldEnd();
    }
    if(s.expungeWhichSharedNotebookRestrictions.isSet()) {
        w.writeFieldBegin(QStringLiteral("expungeWhichSharedNotebookRestrictions"), ThriftFieldType::T_I32, 20);
        w.writeI32(static_cast<qint32>(s.expungeWhichSharedNotebookRestrictions.ref()));
        w.writeFieldEnd();
    }
    if(s.noShareNotesWithBusiness.isSet()) {
        w.writeFieldBegin(QStringLiteral("noShareNotesWithBusiness"), ThriftFieldType::T_BOOL, 21);
        w.writeBool(s.noShareNotesWithBusiness.ref());
        w.writeFieldEnd();
    }
    if(s.noRenameNotebook.isSet()) {
        w.writeFieldBegin(QStringLiteral("noRenameNotebook"), ThriftFieldType::T_BOOL, 22);
        w.writeBool(s.noRenameNotebook.ref());
        w.writeFieldEnd();
    }
    if(s.noSetInMyList.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSetInMyList"), ThriftFieldType::T_BOOL, 23);
        w.writeBool(s.noSetInMyList.ref());
        w.writeFieldEnd();
    }
    if(s.noChangeContact.isSet()) {
        w.writeFieldBegin(QStringLiteral("noChangeContact"), ThriftFieldType::T_BOOL, 24);
        w.writeBool(s.noChangeContact.ref());
        w.writeFieldEnd();
    }
    if(s.canMoveToContainerRestrictions.isSet()) {
        w.writeFieldBegin(QStringLiteral("canMoveToContainerRestrictions"), ThriftFieldType::T_STRUCT, 26);
        writeCanMoveToContainerRestrictions(w, s.canMoveToContainerRestrictions.ref());
        w.writeFieldEnd();
    }
    if(s.noSetReminderNotifyEmail.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSetReminderNotifyEmail"), ThriftFieldType::T_BOOL, 27);
        w.writeBool(s.noSetReminderNotifyEmail.ref());
        w.writeFieldEnd();
    }
    if(s.noSetReminderNotifyInApp.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSetReminderNotifyInApp"), ThriftFieldType::T_BOOL, 28);
        w.writeBool(s.noSetReminderNotifyInApp.ref());
        w.writeFieldEnd();
    }
    if(s.noSetRecipientSettingsStack.isSet()) {
        w.writeFieldBegin(QStringLiteral("noSetRecipientSettingsStack"), ThriftFieldType::T_BOOL, 29);
        w.writeBool(s.noSetRecipientSettingsStack.ref());
        w.writeFieldEnd();
    }
    if(s.noCanMoveNote.isSet()) {
        w.writeFieldBegin(QStringLiteral("noCanMoveNote"), ThriftFieldType::T_BOOL, 30);
        w.writeBool(s.noCanMoveNote.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNotebookRestrictions(ThriftBinaryBufferReader & r, NotebookRestrictions & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noReadNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noCreateNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noUpdateNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noExpungeNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noShareNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noEmailNotes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSendMessageToRecipients = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noUpdateNotebook = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noExpungeNotebook = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetDefaultNotebook = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetNotebookStack = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noPublishToPublic = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noPublishToBusinessLibrary = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noCreateTags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noUpdateTags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noExpungeTags = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetParentTag = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noCreateSharedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 19) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookInstanceRestrictions::type v;
                readEnumSharedNotebookInstanceRestrictions(r, v);
                s.updateWhichSharedNotebookRestrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 20) {
            if (fieldType == ThriftFieldType::T_I32) {
                SharedNotebookInstanceRestrictions::type v;
                readEnumSharedNotebookInstanceRestrictions(r, v);
                s.expungeWhichSharedNotebookRestrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 21) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noShareNotesWithBusiness = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 22) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noRenameNotebook = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 23) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetInMyList = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 24) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noChangeContact = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 26) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                CanMoveToContainerRestrictions v;
                readCanMoveToContainerRestrictions(r, v);
                s.canMoveToContainerRestrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 27) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetReminderNotifyEmail = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 28) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetReminderNotifyInApp = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 29) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noSetRecipientSettingsStack = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 30) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.noCanMoveNote = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNotebook(ThriftBinaryBufferWriter & w, const Notebook & s) {
    w.writeStructBegin(QStringLiteral("Notebook"));
    if(s.guid.isSet()) {
        w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if(s.name.isSet()) {
        w.writeFieldBegin(QStringLiteral("name"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.name.ref());
        w.writeFieldEnd();
    }
    if(s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(QStringLiteral("updateSequenceNum"), ThriftFieldType::T_I32, 5);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if(s.defaultNotebook.isSet()) {
        w.writeFieldBegin(QStringLiteral("defaultNotebook"), ThriftFieldType::T_BOOL, 6);
        w.writeBool(s.defaultNotebook.ref());
        w.writeFieldEnd();
    }
    if(s.serviceCreated.isSet()) {
        w.writeFieldBegin(QStringLiteral("serviceCreated"), ThriftFieldType::T_I64, 7);
        w.writeI64(s.serviceCreated.ref());
        w.writeFieldEnd();
    }
    if(s.serviceUpdated.isSet()) {
        w.writeFieldBegin(QStringLiteral("serviceUpdated"), ThriftFieldType::T_I64, 8);
        w.writeI64(s.serviceUpdated.ref());
        w.writeFieldEnd();
    }
    if(s.publishing.isSet()) {
        w.writeFieldBegin(QStringLiteral("publishing"), ThriftFieldType::T_STRUCT, 10);
        writePublishing(w, s.publishing.ref());
        w.writeFieldEnd();
    }
    if(s.published.isSet()) {
        w.writeFieldBegin(QStringLiteral("published"), ThriftFieldType::T_BOOL, 11);
        w.writeBool(s.published.ref());
        w.writeFieldEnd();
    }
    if(s.stack.isSet()) {
        w.writeFieldBegin(QStringLiteral("stack"), ThriftFieldType::T_STRING, 12);
        w.writeString(s.stack.ref());
        w.writeFieldEnd();
    }
    if(s.sharedNotebookIds.isSet()) {
        w.writeFieldBegin(QStringLiteral("sharedNotebookIds"), ThriftFieldType::T_LIST, 13);
        w.writeListBegin(ThriftFieldType::T_I64, s.sharedNotebookIds.ref().length());
        for(QList< qint64 >::const_iterator it = s.sharedNotebookIds.ref().constBegin(), end = s.sharedNotebookIds.ref().constEnd(); it != end; ++it) {
            w.writeI64(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.sharedNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("sharedNotebooks"), ThriftFieldType::T_LIST, 14);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.sharedNotebooks.ref().length());
        for(QList< SharedNotebook >::const_iterator it = s.sharedNotebooks.ref().constBegin(), end = s.sharedNotebooks.ref().constEnd(); it != end; ++it) {
            writeSharedNotebook(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.businessNotebook.isSet()) {
        w.writeFieldBegin(QStringLiteral("businessNotebook"), ThriftFieldType::T_STRUCT, 15);
        writeBusinessNotebook(w, s.businessNotebook.ref());
        w.writeFieldEnd();
    }
    if(s.contact.isSet()) {
        w.writeFieldBegin(QStringLiteral("contact"), ThriftFieldType::T_STRUCT, 16);
        writeUser(w, s.contact.ref());
        w.writeFieldEnd();
    }
    if(s.restrictions.isSet()) {
        w.writeFieldBegin(QStringLiteral("restrictions"), ThriftFieldType::T_STRUCT, 17);
        writeNotebookRestrictions(w, s.restrictions.ref());
        w.writeFieldEnd();
    }
    if(s.recipientSettings.isSet()) {
        w.writeFieldBegin(QStringLiteral("recipientSettings"), ThriftFieldType::T_STRUCT, 18);
        writeNotebookRecipientSettings(w, s.recipientSettings.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNotebook(ThriftBinaryBufferReader & r, Notebook & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.name = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.defaultNotebook = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceCreated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.serviceUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Publishing v;
                readPublishing(r, v);
                s.publishing = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.published = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.stack = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< qint64 > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_I64) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (Notebook.sharedNotebookIds)"));
                for(qint32 i = 0; i < size; i++) {
                    qint64 elem;
                    r.readI64(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.sharedNotebookIds = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< SharedNotebook > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (Notebook.sharedNotebooks)"));
                for(qint32 i = 0; i < size; i++) {
                    SharedNotebook elem;
                    readSharedNotebook(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.sharedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                BusinessNotebook v;
                readBusinessNotebook(r, v);
                s.businessNotebook = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                User v;
                readUser(r, v);
                s.contact = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 17) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NotebookRestrictions v;
                readNotebookRestrictions(r, v);
                s.restrictions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 18) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NotebookRecipientSettings v;
                readNotebookRecipientSettings(r, v);
                s.recipientSettings = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeLinkedNotebook(ThriftBinaryBufferWriter & w, const LinkedNotebook & s) {
    w.writeStructBegin(QStringLiteral("LinkedNotebook"));
    if(s.shareName.isSet()) {
        w.writeFieldBegin(QStringLiteral("shareName"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.shareName.ref());
        w.writeFieldEnd();
    }
    if(s.username.isSet()) {
        w.writeFieldBegin(QStringLiteral("username"), ThriftFieldType::T_STRING, 3);
        w.writeString(s.username.ref());
        w.writeFieldEnd();
    }
    if(s.shardId.isSet()) {
        w.writeFieldBegin(QStringLiteral("shardId"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.shardId.ref());
        w.writeFieldEnd();
    }
    if(s.sharedNotebookGlobalId.isSet()) {
        w.writeFieldBegin(QStringLiteral("sharedNotebookGlobalId"), ThriftFieldType::T_STRING, 5);
        w.writeString(s.sharedNotebookGlobalId.ref());
        w.writeFieldEnd();
    }
    if(s.uri.isSet()) {
        w.writeFieldBegin(QStringLiteral("uri"), ThriftFieldType::T_STRING, 6);
        w.writeString(s.uri.ref());
        w.writeFieldEnd();
    }
    if(s.guid.isSet()) {
        w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 7);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if(s.updateSequenceNum.isSet()) {
        w.writeFieldBegin(QStringLiteral("updateSequenceNum"), ThriftFieldType::T_I32, 8);
        w.writeI32(s.updateSequenceNum.ref());
        w.writeFieldEnd();
    }
    if(s.noteStoreUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("noteStoreUrl"), ThriftFieldType::T_STRING, 9);
        w.writeString(s.noteStoreUrl.ref());
        w.writeFieldEnd();
    }
    if(s.webApiUrlPrefix.isSet()) {
        w.writeFieldBegin(QStringLiteral("webApiUrlPrefix"), ThriftFieldType::T_STRING, 10);
        w.writeString(s.webApiUrlPrefix.ref());
        w.writeFieldEnd();
    }
    if(s.stack.isSet()) {
        w.writeFieldBegin(QStringLiteral("stack"), ThriftFieldType::T_STRING, 11);
        w.writeString(s.stack.ref());
        w.writeFieldEnd();
    }
    if(s.businessId.isSet()) {
        w.writeFieldBegin(QStringLiteral("businessId"), ThriftFieldType::T_I32, 12);
        w.writeI32(s.businessId.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readLinkedNotebook(ThriftBinaryBufferReader & r, LinkedNotebook & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.shareName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.username = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.shardId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sharedNotebookGlobalId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.uri = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.updateSequenceNum = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.noteStoreUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.webApiUrlPrefix = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.stack = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.businessId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeNotebookDescriptor(ThriftBinaryBufferWriter & w, const NotebookDescriptor & s) {
    w.writeStructBegin(QStringLiteral("NotebookDescriptor"));
    if(s.guid.isSet()) {
        w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.guid.ref());
        w.writeFieldEnd();
    }
    if(s.notebookDisplayName.isSet()) {
        w.writeFieldBegin(QStringLiteral("notebookDisplayName"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.notebookDisplayName.ref());
        w.writeFieldEnd();
    }
    if(s.contactName.isSet()) {
        w.writeFieldBegin(QStringLiteral("contactName"), ThriftFieldType::T_STRING, 3);
        w.writeString(s.contactName.ref());
        w.writeFieldEnd();
    }
    if(s.hasSharedNotebook.isSet()) {
        w.writeFieldBegin(QStringLiteral("hasSharedNotebook"), ThriftFieldType::T_BOOL, 4);
        w.writeBool(s.hasSharedNotebook.ref());
        w.writeFieldEnd();
    }
    if(s.joinedUserCount.isSet()) {
        w.writeFieldBegin(QStringLiteral("joinedUserCount"), ThriftFieldType::T_I32, 5);
        w.writeI32(s.joinedUserCount.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readNotebookDescriptor(ThriftBinaryBufferReader & r, NotebookDescriptor & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                r.readString(v);
                s.guid = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.notebookDisplayName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.contactName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.hasSharedNotebook = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.joinedUserCount = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeUserProfile(ThriftBinaryBufferWriter & w, const UserProfile & s) {
    w.writeStructBegin(QStringLiteral("UserProfile"));
    if(s.id.isSet()) {
        w.writeFieldBegin(QStringLiteral("id"), ThriftFieldType::T_I32, 1);
        w.writeI32(s.id.ref());
        w.writeFieldEnd();
    }
    if(s.name.isSet()) {
        w.writeFieldBegin(QStringLiteral("name"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.name.ref());
        w.writeFieldEnd();
    }
    if(s.email.isSet()) {
        w.writeFieldBegin(QStringLiteral("email"), ThriftFieldType::T_STRING, 3);
        w.writeString(s.email.ref());
        w.writeFieldEnd();
    }
    if(s.username.isSet()) {
        w.writeFieldBegin(QStringLiteral("username"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.username.ref());
        w.writeFieldEnd();
    }
    if(s.attributes.isSet()) {
        w.writeFieldBegin(QStringLiteral("attributes"), ThriftFieldType::T_STRUCT, 5);
        writeBusinessUserAttributes(w, s.attributes.ref());
        w.writeFieldEnd();
    }
    if(s.joined.isSet()) {
        w.writeFieldBegin(QStringLiteral("joined"), ThriftFieldType::T_I64, 6);
        w.writeI64(s.joined.ref());
        w.writeFieldEnd();
    }
    if(s.photoLastUpdated.isSet()) {
        w.writeFieldBegin(QStringLiteral("photoLastUpdated"), ThriftFieldType::T_I64, 7);
        w.writeI64(s.photoLastUpdated.ref());
        w.writeFieldEnd();
    }
    if(s.photoUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("photoUrl"), ThriftFieldType::T_STRING, 8);
        w.writeString(s.photoUrl.ref());
        w.writeFieldEnd();
    }
    if(s.role.isSet()) {
        w.writeFieldBegin(QStringLiteral("role"), ThriftFieldType::T_I32, 9);
        w.writeI32(static_cast<qint32>(s.role.ref()));
        w.writeFieldEnd();
    }
    if(s.status.isSet()) {
        w.writeFieldBegin(QStringLiteral("status"), ThriftFieldType::T_I32, 10);
        w.writeI32(static_cast<qint32>(s.status.ref()));
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readUserProfile(ThriftBinaryBufferReader & r, UserProfile & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.id = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.name = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.email = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.username = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                BusinessUserAttributes v;
                readBusinessUserAttributes(r, v);
                s.attributes = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.joined = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.photoLastUpdated = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.photoUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole::type v;
                readEnumBusinessUserRole(r, v);
                s.role = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserStatus::type v;
                readEnumBusinessUserStatus(r, v);
                s.status = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeRelatedContentImage(ThriftBinaryBufferWriter & w, const RelatedContentImage & s) {
    w.writeStructBegin(QStringLiteral("RelatedContentImage"));
    if(s.url.isSet()) {
        w.writeFieldBegin(QStringLiteral("url"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.url.ref());
        w.writeFieldEnd();
    }
    if(s.width.isSet()) {
        w.writeFieldBegin(QStringLiteral("width"), ThriftFieldType::T_I32, 2);
        w.writeI32(s.width.ref());
        w.writeFieldEnd();
    }
    if(s.height.isSet()) {
        w.writeFieldBegin(QStringLiteral("height"), ThriftFieldType::T_I32, 3);
        w.writeI32(s.height.ref());
        w.writeFieldEnd();
    }
    if(s.pixelRatio.isSet()) {
        w.writeFieldBegin(QStringLiteral("pixelRatio"), ThriftFieldType::T_DOUBLE, 4);
        w.writeDouble(s.pixelRatio.ref());
        w.writeFieldEnd();
    }
    if(s.fileSize.isSet()) {
        w.writeFieldBegin(QStringLiteral("fileSize"), ThriftFieldType::T_I32, 5);
        w.writeI32(s.fileSize.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readRelatedContentImage(ThriftBinaryBufferReader & r, RelatedContentImage & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.url = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.width = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.height = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_DOUBLE) {
                double v;
                r.readDouble(v);
                s.pixelRatio = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.fileSize = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeRelatedContent(ThriftBinaryBufferWriter & w, const RelatedContent & s) {
    w.writeStructBegin(QStringLiteral("RelatedContent"));
    if(s.contentId.isSet()) {
        w.writeFieldBegin(QStringLiteral("contentId"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.contentId.ref());
        w.writeFieldEnd();
    }
    if(s.title.isSet()) {
        w.writeFieldBegin(QStringLiteral("title"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.title.ref());
        w.writeFieldEnd();
    }
    if(s.url.isSet()) {
        w.writeFieldBegin(QStringLiteral("url"), ThriftFieldType::T_STRING, 3);
        w.writeString(s.url.ref());
        w.writeFieldEnd();
    }
    if(s.sourceId.isSet()) {
        w.writeFieldBegin(QStringLiteral("sourceId"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.sourceId.ref());
        w.writeFieldEnd();
    }
    if(s.sourceUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("sourceUrl"), ThriftFieldType::T_STRING, 5);
        w.writeString(s.sourceUrl.ref());
        w.writeFieldEnd();
    }
    if(s.sourceFaviconUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("sourceFaviconUrl"), ThriftFieldType::T_STRING, 6);
        w.writeString(s.sourceFaviconUrl.ref());
        w.writeFieldEnd();
    }
    if(s.sourceName.isSet()) {
        w.writeFieldBegin(QStringLiteral("sourceName"), ThriftFieldType::T_STRING, 7);
        w.writeString(s.sourceName.ref());
        w.writeFieldEnd();
    }
    if(s.date.isSet()) {
        w.writeFieldBegin(QStringLiteral("date"), ThriftFieldType::T_I64, 8);
        w.writeI64(s.date.ref());
        w.writeFieldEnd();
    }
    if(s.teaser.isSet()) {
        w.writeFieldBegin(QStringLiteral("teaser"), ThriftFieldType::T_STRING, 9);
        w.writeString(s.teaser.ref());
        w.writeFieldEnd();
    }
    if(s.thumbnails.isSet()) {
        w.writeFieldBegin(QStringLiteral("thumbnails"), ThriftFieldType::T_LIST, 10);
        w.writeListBegin(ThriftFieldType::T_STRUCT, s.thumbnails.ref().length());
        for(QList< RelatedContentImage >::const_iterator it = s.thumbnails.ref().constBegin(), end = s.thumbnails.ref().constEnd(); it != end; ++it) {
            writeRelatedContentImage(w, *it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    if(s.contentType.isSet()) {
        w.writeFieldBegin(QStringLiteral("contentType"), ThriftFieldType::T_I32, 11);
        w.writeI32(static_cast<qint32>(s.contentType.ref()));
        w.writeFieldEnd();
    }
    if(s.accessType.isSet()) {
        w.writeFieldBegin(QStringLiteral("accessType"), ThriftFieldType::T_I32, 12);
        w.writeI32(static_cast<qint32>(s.accessType.ref()));
        w.writeFieldEnd();
    }
    if(s.visibleUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("visibleUrl"), ThriftFieldType::T_STRING, 13);
        w.writeString(s.visibleUrl.ref());
        w.writeFieldEnd();
    }
    if(s.clipUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("clipUrl"), ThriftFieldType::T_STRING, 14);
        w.writeString(s.clipUrl.ref());
        w.writeFieldEnd();
    }
    if(s.contact.isSet()) {
        w.writeFieldBegin(QStringLiteral("contact"), ThriftFieldType::T_STRUCT, 15);
        writeContact(w, s.contact.ref());
        w.writeFieldEnd();
    }
    if(s.authors.isSet()) {
        w.writeFieldBegin(QStringLiteral("authors"), ThriftFieldType::T_LIST, 16);
        w.writeListBegin(ThriftFieldType::T_STRING, s.authors.ref().length());
        for(QStringList::const_iterator it = s.authors.ref().constBegin(), end = s.authors.ref().constEnd(); it != end; ++it) {
            w.writeString(*it);
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readRelatedContent(ThriftBinaryBufferReader & r, RelatedContent & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.contentId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.title = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.url = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sourceId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sourceUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sourceFaviconUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.sourceName = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.date = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.teaser = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< RelatedContentImage > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedContent.thumbnails)"));
                for(qint32 i = 0; i < size; i++) {
                    RelatedContentImage elem;
                    readRelatedContentImage(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.thumbnails = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_I32) {
                RelatedContentType::type v;
                readEnumRelatedContentType(r, v);
                s.contentType = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_I32) {
                RelatedContentAccess::type v;
                readEnumRelatedContentAccess(r, v);
                s.accessType = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.visibleUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 14) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.clipUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 15) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Contact v;
                readContact(r, v);
                s.contact = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (RelatedContent.authors)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.authors = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeBusinessInvitation(ThriftBinaryBufferWriter & w, const BusinessInvitation & s) {
    w.writeStructBegin(QStringLiteral("BusinessInvitation"));
    if(s.businessId.isSet()) {
        w.writeFieldBegin(QStringLiteral("businessId"), ThriftFieldType::T_I32, 1);
        w.writeI32(s.businessId.ref());
        w.writeFieldEnd();
    }
    if(s.email.isSet()) {
        w.writeFieldBegin(QStringLiteral("email"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.email.ref());
        w.writeFieldEnd();
    }
    if(s.role.isSet()) {
        w.writeFieldBegin(QStringLiteral("role"), ThriftFieldType::T_I32, 3);
        w.writeI32(static_cast<qint32>(s.role.ref()));
        w.writeFieldEnd();
    }
    if(s.status.isSet()) {
        w.writeFieldBegin(QStringLiteral("status"), ThriftFieldType::T_I32, 4);
        w.writeI32(static_cast<qint32>(s.status.ref()));
        w.writeFieldEnd();
    }
    if(s.requesterId.isSet()) {
        w.writeFieldBegin(QStringLiteral("requesterId"), ThriftFieldType::T_I32, 5);
        w.writeI32(s.requesterId.ref());
        w.writeFieldEnd();
    }
    if(s.fromWorkChat.isSet()) {
        w.writeFieldBegin(QStringLiteral("fromWorkChat"), ThriftFieldType::T_BOOL, 6);
        w.writeBool(s.fromWorkChat.ref());
        w.writeFieldEnd();
    }
    if(s.created.isSet()) {
        w.writeFieldBegin(QStringLiteral("created"), ThriftFieldType::T_I64, 7);
        w.writeI64(s.created.ref());
        w.writeFieldEnd();
    }
    if(s.mostRecentReminder.isSet()) {
        w.writeFieldBegin(QStringLiteral("mostRecentReminder"), ThriftFieldType::T_I64, 8);
        w.writeI64(s.mostRecentReminder.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readBusinessInvitation(ThriftBinaryBufferReader & r, BusinessInvitation & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.businessId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.email = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessUserRole::type v;
                readEnumBusinessUserRole(r, v);
                s.role = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_I32) {
                BusinessInvitationStatus::type v;
                readEnumBusinessInvitationStatus(r, v);
                s.status = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                r.readI32(v);
                s.requesterId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.fromWorkChat = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.created = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.mostRecentReminder = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeUserIdentity(ThriftBinaryBufferWriter & w, const UserIdentity & s) {
    w.writeStructBegin(QStringLiteral("UserIdentity"));
    if(s.type.isSet()) {
        w.writeFieldBegin(QStringLiteral("type"), ThriftFieldType::T_I32, 1);
        w.writeI32(static_cast<qint32>(s.type.ref()));
        w.writeFieldEnd();
    }
    if(s.stringIdentifier.isSet()) {
        w.writeFieldBegin(QStringLiteral("stringIdentifier"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.stringIdentifier.ref());
        w.writeFieldEnd();
    }
    if(s.longIdentifier.isSet()) {
        w.writeFieldBegin(QStringLiteral("longIdentifier"), ThriftFieldType::T_I64, 3);
        w.writeI64(s.longIdentifier.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readUserIdentity(ThriftBinaryBufferReader & r, UserIdentity & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                UserIdentityType::type v;
                readEnumUserIdentityType(r, v);
                s.type = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.stringIdentifier = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                qint64 v;
                r.readI64(v);
                s.longIdentifier = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writePublicUserInfo(ThriftBinaryBufferWriter & w, const PublicUserInfo & s) {
    w.writeStructBegin(QStringLiteral("PublicUserInfo"));
    w.writeFieldBegin(QStringLiteral("userId"), ThriftFieldType::T_I32, 1);
    w.writeI32(s.userId);
    w.writeFieldEnd();
    if(s.serviceLevel.isSet()) {
        w.writeFieldBegin(QStringLiteral("serviceLevel"), ThriftFieldType::T_I32, 7);
        w.writeI32(static_cast<qint32>(s.serviceLevel.ref()));
        w.writeFieldEnd();
    }
    if(s.username.isSet()) {
        w.writeFieldBegin(QStringLiteral("username"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.username.ref());
        w.writeFieldEnd();
    }
    if(s.noteStoreUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("noteStoreUrl"), ThriftFieldType::T_STRING, 5);
        w.writeString(s.noteStoreUrl.ref());
        w.writeFieldEnd();
    }
    if(s.webApiUrlPrefix.isSet()) {
        w.writeFieldBegin(QStringLiteral("webApiUrlPrefix"), ThriftFieldType::T_STRING, 6);
        w.writeString(s.webApiUrlPrefix.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readPublicUserInfo(ThriftBinaryBufferReader & r, PublicUserInfo & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool userId_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                userId_isset = true;
                UserID v;
                r.readI32(v);
                s.userId = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_I32) {
                ServiceLevel::type v;
                readEnumServiceLevel(r, v);
                s.serviceLevel = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.username = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.noteStoreUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.webApiUrlPrefix = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!userId_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("PublicUserInfo.userId has no value"));
}

void writeUserUrls(ThriftBinaryBufferWriter & w, const UserUrls & s) {
    w.writeStructBegin(QStringLiteral("UserUrls"));
    if(s.noteStoreUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("noteStoreUrl"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.noteStoreUrl.ref());
        w.writeFieldEnd();
    }
    if(s.webApiUrlPrefix.isSet()) {
        w.writeFieldBegin(QStringLiteral("webApiUrlPrefix"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.webApiUrlPrefix.ref());
        w.writeFieldEnd();
    }
    if(s.userStoreUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("userStoreUrl"), ThriftFieldType::T_STRING, 3);
        w.writeString(s.userStoreUrl.ref());
        w.writeFieldEnd();
    }
    if(s.utilityUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("utilityUrl"), ThriftFieldType::T_STRING, 4);
        w.writeString(s.utilityUrl.ref());
        w.writeFieldEnd();
    }
    if(s.messageStoreUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("messageStoreUrl"), ThriftFieldType::T_STRING, 5);
        w.writeString(s.messageStoreUrl.ref());
        w.writeFieldEnd();
    }
    if(s.userWebSocketUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("userWebSocketUrl"), ThriftFieldType::T_STRING, 6);
        w.writeString(s.userWebSocketUrl.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readUserUrls(ThriftBinaryBufferReader & r, UserUrls & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.noteStoreUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.webApiUrlPrefix = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.userStoreUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.utilityUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.messageStoreUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.userWebSocketUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

void writeAuthenticationResult(ThriftBinaryBufferWriter & w, const AuthenticationResult & s) {
    w.writeStructBegin(QStringLiteral("AuthenticationResult"));
    w.writeFieldBegin(QStringLiteral("currentTime"), ThriftFieldType::T_I64, 1);
    w.writeI64(s.currentTime);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 2);
    w.writeString(s.authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("expiration"), ThriftFieldType::T_I64, 3);
    w.writeI64(s.expiration);
    w.writeFieldEnd();
    if(s.user.isSet()) {
        w.writeFieldBegin(QStringLiteral("user"), ThriftFieldType::T_STRUCT, 4);
        writeUser(w, s.user.ref());
        w.writeFieldEnd();
    }
    if(s.publicUserInfo.isSet()) {
        w.writeFieldBegin(QStringLiteral("publicUserInfo"), ThriftFieldType::T_STRUCT, 5);
        writePublicUserInfo(w, s.publicUserInfo.ref());
        w.writeFieldEnd();
    }
    if(s.noteStoreUrl.isSet()) {
        w.writeFieldBegin(QStringLiteral("noteStoreUrl"), ThriftFieldType::T_STRING, 6);
        w.writeString(s.noteStoreUrl.ref());
        w.writeFieldEnd();
    }
    if(s.webApiUrlPrefix.isSet()) {
        w.writeFieldBegin(QStringLiteral("webApiUrlPrefix"), ThriftFieldType::T_STRING, 7);
        w.writeString(s.webApiUrlPrefix.ref());
        w.writeFieldEnd();
    }
    if(s.secondFactorRequired.isSet()) {
        w.writeFieldBegin(QStringLiteral("secondFactorRequired"), ThriftFieldType::T_BOOL, 8);
        w.writeBool(s.secondFactorRequired.ref());
        w.writeFieldEnd();
    }
    if(s.secondFactorDeliveryHint.isSet()) {
        w.writeFieldBegin(QStringLiteral("secondFactorDeliveryHint"), ThriftFieldType::T_STRING, 9);
        w.writeString(s.secondFactorDeliveryHint.ref());
        w.writeFieldEnd();
    }
    if(s.urls.isSet()) {
        w.writeFieldBegin(QStringLiteral("urls"), ThriftFieldType::T_STRUCT, 10);
        writeUserUrls(w, s.urls.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readAuthenticationResult(ThriftBinaryBufferReader & r, AuthenticationResult & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool currentTime_isset = false;
    bool authenticationToken_isset = false;
    bool expiration_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I64) {
                currentTime_isset = true;
                qint64 v;
                r.readI64(v);
                s.currentTime = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                authenticationToken_isset = true;
                QString v;
                r.readString(v);
                s.authenticationToken = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I64) {
                expiration_isset = true;
                qint64 v;
                r.readI64(v);
                s.expiration = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                User v;
                readUser(r, v);
                s.user = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                PublicUserInfo v;
                readPublicUserInfo(r, v);
                s.publicUserInfo = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.noteStoreUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.webApiUrlPrefix = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.secondFactorRequired = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.secondFactorDeliveryHint = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                UserUrls v;
                readUserUrls(r, v);
                s.urls = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!currentTime_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("AuthenticationResult.currentTime has no value"));
    if(!authenticationToken_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("AuthenticationResult.authenticationToken has no value"));
    if(!expiration_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("AuthenticationResult.expiration has no value"));
}

void writeBootstrapSettings(ThriftBinaryBufferWriter & w, const BootstrapSettings & s) {
    w.writeStructBegin(QStringLiteral("BootstrapSettings"));
    w.writeFieldBegin(QStringLiteral("serviceHost"), ThriftFieldType::T_STRING, 1);
    w.writeString(s.serviceHost);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("marketingUrl"), ThriftFieldType::T_STRING, 2);
    w.writeString(s.marketingUrl);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("supportUrl"), ThriftFieldType::T_STRING, 3);
    w.writeString(s.supportUrl);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("accountEmailDomain"), ThriftFieldType::T_STRING, 4);
    w.writeString(s.accountEmailDomain);
    w.writeFieldEnd();
    if(s.enableFacebookSharing.isSet()) {
        w.writeFieldBegin(QStringLiteral("enableFacebookSharing"), ThriftFieldType::T_BOOL, 5);
        w.writeBool(s.enableFacebookSharing.ref());
        w.writeFieldEnd();
    }
    if(s.enableGiftSubscriptions.isSet()) {
        w.writeFieldBegin(QStringLiteral("enableGiftSubscriptions"), ThriftFieldType::T_BOOL, 6);
        w.writeBool(s.enableGiftSubscriptions.ref());
        w.writeFieldEnd();
    }
    if(s.enableSupportTickets.isSet()) {
        w.writeFieldBegin(QStringLiteral("enableSupportTickets"), ThriftFieldType::T_BOOL, 7);
        w.writeBool(s.enableSupportTickets.ref());
        w.writeFieldEnd();
    }
    if(s.enableSharedNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("enableSharedNotebooks"), ThriftFieldType::T_BOOL, 8);
        w.writeBool(s.enableSharedNotebooks.ref());
        w.writeFieldEnd();
    }
    if(s.enableSingleNoteSharing.isSet()) {
        w.writeFieldBegin(QStringLiteral("enableSingleNoteSharing"), ThriftFieldType::T_BOOL, 9);
        w.writeBool(s.enableSingleNoteSharing.ref());
        w.writeFieldEnd();
    }
    if(s.enableSponsoredAccounts.isSet()) {
        w.writeFieldBegin(QStringLiteral("enableSponsoredAccounts"), ThriftFieldType::T_BOOL, 10);
        w.writeBool(s.enableSponsoredAccounts.ref());
        w.writeFieldEnd();
    }
    if(s.enableTwitterSharing.isSet()) {
        w.writeFieldBegin(QStringLiteral("enableTwitterSharing"), ThriftFieldType::T_BOOL, 11);
        w.writeBool(s.enableTwitterSharing.ref());
        w.writeFieldEnd();
    }
    if(s.enableLinkedInSharing.isSet()) {
        w.writeFieldBegin(QStringLiteral("enableLinkedInSharing"), ThriftFieldType::T_BOOL, 12);
        w.writeBool(s.enableLinkedInSharing.ref());
        w.writeFieldEnd();
    }
    if(s.enablePublicNotebooks.isSet()) {
        w.writeFieldBegin(QStringLiteral("enablePublicNotebooks"), ThriftFieldType::T_BOOL, 13);
        w.writeBool(s.enablePublicNotebooks.ref());
        w.writeFieldEnd();
    }
    if(s.enableGoogle.isSet()) {
        w.writeFieldBegin(QStringLiteral("enableGoogle"), ThriftFieldType::T_BOOL, 16);
        w.writeBool(s.enableGoogle.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readBootstrapSettings(ThriftBinaryBufferReader & r, BootstrapSettings & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool serviceHost_isset = false;
    bool marketingUrl_isset = false;
    bool supportUrl_isset = false;
    bool accountEmailDomain_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                serviceHost_isset = true;
                QString v;
                r.readString(v);
                s.serviceHost = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                marketingUrl_isset = true;
                QString v;
                r.readString(v);
                s.marketingUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRING) {
                supportUrl_isset = true;
                QString v;
                r.readString(v);
                s.supportUrl = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRING) {
                accountEmailDomain_isset = true;
                QString v;
                r.readString(v);
                s.accountEmailDomain = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 5) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableFacebookSharing = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 6) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableGiftSubscriptions = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 7) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableSupportTickets = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 8) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableSharedNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 9) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableSingleNoteSharing = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 10) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableSponsoredAccounts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 11) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableTwitterSharing = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 12) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableLinkedInSharing = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 13) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enablePublicNotebooks = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 16) {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                r.readBool(v);
                s.enableGoogle = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!serviceHost_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.serviceHost has no value"));
    if(!marketingUrl_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.marketingUrl has no value"));
    if(!supportUrl_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.supportUrl has no value"));
    if(!accountEmailDomain_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapSettings.accountEmailDomain has no value"));
}

void writeBootstrapProfile(ThriftBinaryBufferWriter & w, const BootstrapProfile & s) {
    w.writeStructBegin(QStringLiteral("BootstrapProfile"));
    w.writeFieldBegin(QStringLiteral("name"), ThriftFieldType::T_STRING, 1);
    w.writeString(s.name);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("settings"), ThriftFieldType::T_STRUCT, 2);
    writeBootstrapSettings(w, s.settings);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
}

void readBootstrapProfile(ThriftBinaryBufferReader & r, BootstrapProfile & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool name_isset = false;
    bool settings_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                name_isset = true;
                QString v;
                r.readString(v);
                s.name = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                settings_isset = true;
                BootstrapSettings v;
                readBootstrapSettings(r, v);
                s.settings = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!name_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapProfile.name has no value"));
    if(!settings_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapProfile.settings has no value"));
}

void writeBootstrapInfo(ThriftBinaryBufferWriter & w, const BootstrapInfo & s) {
    w.writeStructBegin(QStringLiteral("BootstrapInfo"));
    w.writeFieldBegin(QStringLiteral("profiles"), ThriftFieldType::T_LIST, 1);
    w.writeListBegin(ThriftFieldType::T_STRUCT, s.profiles.length());
    for(QList< BootstrapProfile >::const_iterator it = s.profiles.constBegin(), end = s.profiles.constEnd(); it != end; ++it) {
        writeBootstrapProfile(w, *it);
    }
    w.writeListEnd();
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
}

void readBootstrapInfo(ThriftBinaryBufferReader & r, BootstrapInfo & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool profiles_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                profiles_isset = true;
                QList< BootstrapProfile > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (BootstrapInfo.profiles)"));
                for(qint32 i = 0; i < size; i++) {
                    BootstrapProfile elem;
                    readBootstrapProfile(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.profiles = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!profiles_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("BootstrapInfo.profiles has no value"));
}

EDAMUserException::EDAMUserException() {}
EDAMUserException::~EDAMUserException() throw() {}
EDAMUserException::EDAMUserException(const EDAMUserException& other) : EvernoteException(other)
{
   errorCode = other.errorCode;
   parameter = other.parameter;
}
void writeEDAMUserException(ThriftBinaryBufferWriter & w, const EDAMUserException & s) {
    w.writeStructBegin(QStringLiteral("EDAMUserException"));
    w.writeFieldBegin(QStringLiteral("errorCode"), ThriftFieldType::T_I32, 1);
    w.writeI32(static_cast<qint32>(s.errorCode));
    w.writeFieldEnd();
    if(s.parameter.isSet()) {
        w.writeFieldBegin(QStringLiteral("parameter"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.parameter.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readEDAMUserException(ThriftBinaryBufferReader & r, EDAMUserException & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool errorCode_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                errorCode_isset = true;
                EDAMErrorCode::type v;
                readEnumEDAMErrorCode(r, v);
                s.errorCode = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.parameter = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!errorCode_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("EDAMUserException.errorCode has no value"));
}

EDAMSystemException::EDAMSystemException() {}
EDAMSystemException::~EDAMSystemException() throw() {}
EDAMSystemException::EDAMSystemException(const EDAMSystemException& other) : EvernoteException(other)
{
   errorCode = other.errorCode;
   message = other.message;
   rateLimitDuration = other.rateLimitDuration;
}
void writeEDAMSystemException(ThriftBinaryBufferWriter & w, const EDAMSystemException & s) {
    w.writeStructBegin(QStringLiteral("EDAMSystemException"));
    w.writeFieldBegin(QStringLiteral("errorCode"), ThriftFieldType::T_I32, 1);
    w.writeI32(static_cast<qint32>(s.errorCode));
    w.writeFieldEnd();
    if(s.message.isSet()) {
        w.writeFieldBegin(QStringLiteral("message"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.message.ref());
        w.writeFieldEnd();
    }
    if(s.rateLimitDuration.isSet()) {
        w.writeFieldBegin(QStringLiteral("rateLimitDuration"), ThriftFieldType::T_I32, 3);
        w.writeI32(s.rateLimitDuration.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readEDAMSystemException(ThriftBinaryBufferReader & r, EDAMSystemException & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool errorCode_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_I32) {
                errorCode_isset = true;
                EDAMErrorCode::type v;
                readEnumEDAMErrorCode(r, v);
                s.errorCode = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.message = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                r.readI32(v);
                s.rateLimitDuration = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!errorCode_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("EDAMSystemException.errorCode has no value"));
}

EDAMNotFoundException::EDAMNotFoundException() {}
EDAMNotFoundException::~EDAMNotFoundException() throw() {}
EDAMNotFoundException::EDAMNotFoundException(const EDAMNotFoundException& other) : EvernoteException(other)
{
   identifier = other.identifier;
   key = other.key;
}
void writeEDAMNotFoundException(ThriftBinaryBufferWriter & w, const EDAMNotFoundException & s) {
    w.writeStructBegin(QStringLiteral("EDAMNotFoundException"));
    if(s.identifier.isSet()) {
        w.writeFieldBegin(QStringLiteral("identifier"), ThriftFieldType::T_STRING, 1);
        w.writeString(s.identifier.ref());
        w.writeFieldEnd();
    }
    if(s.key.isSet()) {
        w.writeFieldBegin(QStringLiteral("key"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.key.ref());
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readEDAMNotFoundException(ThriftBinaryBufferReader & r, EDAMNotFoundException & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.identifier = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.key = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
}

EDAMInvalidContactsException::EDAMInvalidContactsException() {}
EDAMInvalidContactsException::~EDAMInvalidContactsException() throw() {}
EDAMInvalidContactsException::EDAMInvalidContactsException(const EDAMInvalidContactsException& other) : EvernoteException(other)
{
   contacts = other.contacts;
   parameter = other.parameter;
   reasons = other.reasons;
}
void writeEDAMInvalidContactsException(ThriftBinaryBufferWriter & w, const EDAMInvalidContactsException & s) {
    w.writeStructBegin(QStringLiteral("EDAMInvalidContactsException"));
    w.writeFieldBegin(QStringLiteral("contacts"), ThriftFieldType::T_LIST, 1);
    w.writeListBegin(ThriftFieldType::T_STRUCT, s.contacts.length());
    for(QList< Contact >::const_iterator it = s.contacts.constBegin(), end = s.contacts.constEnd(); it != end; ++it) {
        writeContact(w, *it);
    }
    w.writeListEnd();
    w.writeFieldEnd();
    if(s.parameter.isSet()) {
        w.writeFieldBegin(QStringLiteral("parameter"), ThriftFieldType::T_STRING, 2);
        w.writeString(s.parameter.ref());
        w.writeFieldEnd();
    }
    if(s.reasons.isSet()) {
        w.writeFieldBegin(QStringLiteral("reasons"), ThriftFieldType::T_LIST, 3);
        w.writeListBegin(ThriftFieldType::T_I32, s.reasons.ref().length());
        for(QList< EDAMInvalidContactReason::type >::const_iterator it = s.reasons.ref().constBegin(), end = s.reasons.ref().constEnd(); it != end; ++it) {
            w.writeI32(static_cast<qint32>(*it));
        }
        w.writeListEnd();
        w.writeFieldEnd();
    }
    w.writeFieldStop();
    w.writeStructEnd();
}

void readEDAMInvalidContactsException(ThriftBinaryBufferReader & r, EDAMInvalidContactsException & s) {
    QString fname;
    ThriftFieldType::type fieldType;
    qint16 fieldId;
    bool contacts_isset = false;
    r.readStructBegin(fname);
    while(true)
    {
        r.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_LIST) {
                contacts_isset = true;
                QList< Contact > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (EDAMInvalidContactsException.contacts)"));
                for(qint32 i = 0; i < size; i++) {
                    Contact elem;
                    readContact(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.contacts = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                r.readString(v);
                s.parameter = v;
            } else {
                r.skip(fieldType);
            }
        } else
        if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_LIST) {
                QList< EDAMInvalidContactReason::type > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_I32) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (EDAMInvalidContactsException.reasons)"));
                for(qint32 i = 0; i < size; i++) {
                    EDAMInvalidContactReason::type elem;
                    readEnumEDAMInvalidContactReason(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                s.reasons = v;
            } else {
                r.skip(fieldType);
            }
        } else
        {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    if(!contacts_isset) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("EDAMInvalidContactsException.contacts has no value"));
}


/** @endcond */



} // namespace qevercloud
