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

#include <generated/EDAMErrorCode.h>
#include "../Impl.h"

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const EDAMErrorCode value)
{
    switch(value)
    {
    case EDAMErrorCode::UNKNOWN:
        out << "EDAMErrorCode::UNKNOWN";
        break;
    case EDAMErrorCode::BAD_DATA_FORMAT:
        out << "EDAMErrorCode::BAD_DATA_FORMAT";
        break;
    case EDAMErrorCode::PERMISSION_DENIED:
        out << "EDAMErrorCode::PERMISSION_DENIED";
        break;
    case EDAMErrorCode::INTERNAL_ERROR:
        out << "EDAMErrorCode::INTERNAL_ERROR";
        break;
    case EDAMErrorCode::DATA_REQUIRED:
        out << "EDAMErrorCode::DATA_REQUIRED";
        break;
    case EDAMErrorCode::LIMIT_REACHED:
        out << "EDAMErrorCode::LIMIT_REACHED";
        break;
    case EDAMErrorCode::QUOTA_REACHED:
        out << "EDAMErrorCode::QUOTA_REACHED";
        break;
    case EDAMErrorCode::INVALID_AUTH:
        out << "EDAMErrorCode::INVALID_AUTH";
        break;
    case EDAMErrorCode::AUTH_EXPIRED:
        out << "EDAMErrorCode::AUTH_EXPIRED";
        break;
    case EDAMErrorCode::DATA_CONFLICT:
        out << "EDAMErrorCode::DATA_CONFLICT";
        break;
    case EDAMErrorCode::ENML_VALIDATION:
        out << "EDAMErrorCode::ENML_VALIDATION";
        break;
    case EDAMErrorCode::SHARD_UNAVAILABLE:
        out << "EDAMErrorCode::SHARD_UNAVAILABLE";
        break;
    case EDAMErrorCode::LEN_TOO_SHORT:
        out << "EDAMErrorCode::LEN_TOO_SHORT";
        break;
    case EDAMErrorCode::LEN_TOO_LONG:
        out << "EDAMErrorCode::LEN_TOO_LONG";
        break;
    case EDAMErrorCode::TOO_FEW:
        out << "EDAMErrorCode::TOO_FEW";
        break;
    case EDAMErrorCode::TOO_MANY:
        out << "EDAMErrorCode::TOO_MANY";
        break;
    case EDAMErrorCode::UNSUPPORTED_OPERATION:
        out << "EDAMErrorCode::UNSUPPORTED_OPERATION";
        break;
    case EDAMErrorCode::TAKEN_DOWN:
        out << "EDAMErrorCode::TAKEN_DOWN";
        break;
    case EDAMErrorCode::RATE_LIMIT_REACHED:
        out << "EDAMErrorCode::RATE_LIMIT_REACHED";
        break;
    case EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED:
        out << "EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED";
        break;
    case EDAMErrorCode::DEVICE_LIMIT_REACHED:
        out << "EDAMErrorCode::DEVICE_LIMIT_REACHED";
        break;
    case EDAMErrorCode::OPENID_ALREADY_TAKEN:
        out << "EDAMErrorCode::OPENID_ALREADY_TAKEN";
        break;
    case EDAMErrorCode::INVALID_OPENID_TOKEN:
        out << "EDAMErrorCode::INVALID_OPENID_TOKEN";
        break;
    case EDAMErrorCode::USER_NOT_ASSOCIATED:
        out << "EDAMErrorCode::USER_NOT_ASSOCIATED";
        break;
    case EDAMErrorCode::USER_NOT_REGISTERED:
        out << "EDAMErrorCode::USER_NOT_REGISTERED";
        break;
    case EDAMErrorCode::USER_ALREADY_ASSOCIATED:
        out << "EDAMErrorCode::USER_ALREADY_ASSOCIATED";
        break;
    case EDAMErrorCode::ACCOUNT_CLEAR:
        out << "EDAMErrorCode::ACCOUNT_CLEAR";
        break;
    case EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED:
        out << "EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const EDAMErrorCode value)
{
    switch(value)
    {
    case EDAMErrorCode::UNKNOWN:
        out << "EDAMErrorCode::UNKNOWN";
        break;
    case EDAMErrorCode::BAD_DATA_FORMAT:
        out << "EDAMErrorCode::BAD_DATA_FORMAT";
        break;
    case EDAMErrorCode::PERMISSION_DENIED:
        out << "EDAMErrorCode::PERMISSION_DENIED";
        break;
    case EDAMErrorCode::INTERNAL_ERROR:
        out << "EDAMErrorCode::INTERNAL_ERROR";
        break;
    case EDAMErrorCode::DATA_REQUIRED:
        out << "EDAMErrorCode::DATA_REQUIRED";
        break;
    case EDAMErrorCode::LIMIT_REACHED:
        out << "EDAMErrorCode::LIMIT_REACHED";
        break;
    case EDAMErrorCode::QUOTA_REACHED:
        out << "EDAMErrorCode::QUOTA_REACHED";
        break;
    case EDAMErrorCode::INVALID_AUTH:
        out << "EDAMErrorCode::INVALID_AUTH";
        break;
    case EDAMErrorCode::AUTH_EXPIRED:
        out << "EDAMErrorCode::AUTH_EXPIRED";
        break;
    case EDAMErrorCode::DATA_CONFLICT:
        out << "EDAMErrorCode::DATA_CONFLICT";
        break;
    case EDAMErrorCode::ENML_VALIDATION:
        out << "EDAMErrorCode::ENML_VALIDATION";
        break;
    case EDAMErrorCode::SHARD_UNAVAILABLE:
        out << "EDAMErrorCode::SHARD_UNAVAILABLE";
        break;
    case EDAMErrorCode::LEN_TOO_SHORT:
        out << "EDAMErrorCode::LEN_TOO_SHORT";
        break;
    case EDAMErrorCode::LEN_TOO_LONG:
        out << "EDAMErrorCode::LEN_TOO_LONG";
        break;
    case EDAMErrorCode::TOO_FEW:
        out << "EDAMErrorCode::TOO_FEW";
        break;
    case EDAMErrorCode::TOO_MANY:
        out << "EDAMErrorCode::TOO_MANY";
        break;
    case EDAMErrorCode::UNSUPPORTED_OPERATION:
        out << "EDAMErrorCode::UNSUPPORTED_OPERATION";
        break;
    case EDAMErrorCode::TAKEN_DOWN:
        out << "EDAMErrorCode::TAKEN_DOWN";
        break;
    case EDAMErrorCode::RATE_LIMIT_REACHED:
        out << "EDAMErrorCode::RATE_LIMIT_REACHED";
        break;
    case EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED:
        out << "EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED";
        break;
    case EDAMErrorCode::DEVICE_LIMIT_REACHED:
        out << "EDAMErrorCode::DEVICE_LIMIT_REACHED";
        break;
    case EDAMErrorCode::OPENID_ALREADY_TAKEN:
        out << "EDAMErrorCode::OPENID_ALREADY_TAKEN";
        break;
    case EDAMErrorCode::INVALID_OPENID_TOKEN:
        out << "EDAMErrorCode::INVALID_OPENID_TOKEN";
        break;
    case EDAMErrorCode::USER_NOT_ASSOCIATED:
        out << "EDAMErrorCode::USER_NOT_ASSOCIATED";
        break;
    case EDAMErrorCode::USER_NOT_REGISTERED:
        out << "EDAMErrorCode::USER_NOT_REGISTERED";
        break;
    case EDAMErrorCode::USER_ALREADY_ASSOCIATED:
        out << "EDAMErrorCode::USER_ALREADY_ASSOCIATED";
        break;
    case EDAMErrorCode::ACCOUNT_CLEAR:
        out << "EDAMErrorCode::ACCOUNT_CLEAR";
        break;
    case EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED:
        out << "EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const EDAMInvalidContactReason value)
{
    switch(value)
    {
    case EDAMInvalidContactReason::BAD_ADDRESS:
        out << "EDAMInvalidContactReason::BAD_ADDRESS";
        break;
    case EDAMInvalidContactReason::DUPLICATE_CONTACT:
        out << "EDAMInvalidContactReason::DUPLICATE_CONTACT";
        break;
    case EDAMInvalidContactReason::NO_CONNECTION:
        out << "EDAMInvalidContactReason::NO_CONNECTION";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const EDAMInvalidContactReason value)
{
    switch(value)
    {
    case EDAMInvalidContactReason::BAD_ADDRESS:
        out << "EDAMInvalidContactReason::BAD_ADDRESS";
        break;
    case EDAMInvalidContactReason::DUPLICATE_CONTACT:
        out << "EDAMInvalidContactReason::DUPLICATE_CONTACT";
        break;
    case EDAMInvalidContactReason::NO_CONNECTION:
        out << "EDAMInvalidContactReason::NO_CONNECTION";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const ShareRelationshipPrivilegeLevel value)
{
    switch(value)
    {
    case ShareRelationshipPrivilegeLevel::READ_NOTEBOOK:
        out << "ShareRelationshipPrivilegeLevel::READ_NOTEBOOK";
        break;
    case ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY:
        out << "ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY";
        break;
    case ShareRelationshipPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY:
        out << "ShareRelationshipPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY";
        break;
    case ShareRelationshipPrivilegeLevel::FULL_ACCESS:
        out << "ShareRelationshipPrivilegeLevel::FULL_ACCESS";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const ShareRelationshipPrivilegeLevel value)
{
    switch(value)
    {
    case ShareRelationshipPrivilegeLevel::READ_NOTEBOOK:
        out << "ShareRelationshipPrivilegeLevel::READ_NOTEBOOK";
        break;
    case ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY:
        out << "ShareRelationshipPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY";
        break;
    case ShareRelationshipPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY:
        out << "ShareRelationshipPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY";
        break;
    case ShareRelationshipPrivilegeLevel::FULL_ACCESS:
        out << "ShareRelationshipPrivilegeLevel::FULL_ACCESS";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const PrivilegeLevel value)
{
    switch(value)
    {
    case PrivilegeLevel::NORMAL:
        out << "PrivilegeLevel::NORMAL";
        break;
    case PrivilegeLevel::PREMIUM:
        out << "PrivilegeLevel::PREMIUM";
        break;
    case PrivilegeLevel::VIP:
        out << "PrivilegeLevel::VIP";
        break;
    case PrivilegeLevel::MANAGER:
        out << "PrivilegeLevel::MANAGER";
        break;
    case PrivilegeLevel::SUPPORT:
        out << "PrivilegeLevel::SUPPORT";
        break;
    case PrivilegeLevel::ADMIN:
        out << "PrivilegeLevel::ADMIN";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const PrivilegeLevel value)
{
    switch(value)
    {
    case PrivilegeLevel::NORMAL:
        out << "PrivilegeLevel::NORMAL";
        break;
    case PrivilegeLevel::PREMIUM:
        out << "PrivilegeLevel::PREMIUM";
        break;
    case PrivilegeLevel::VIP:
        out << "PrivilegeLevel::VIP";
        break;
    case PrivilegeLevel::MANAGER:
        out << "PrivilegeLevel::MANAGER";
        break;
    case PrivilegeLevel::SUPPORT:
        out << "PrivilegeLevel::SUPPORT";
        break;
    case PrivilegeLevel::ADMIN:
        out << "PrivilegeLevel::ADMIN";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const ServiceLevel value)
{
    switch(value)
    {
    case ServiceLevel::BASIC:
        out << "ServiceLevel::BASIC";
        break;
    case ServiceLevel::PLUS:
        out << "ServiceLevel::PLUS";
        break;
    case ServiceLevel::PREMIUM:
        out << "ServiceLevel::PREMIUM";
        break;
    case ServiceLevel::BUSINESS:
        out << "ServiceLevel::BUSINESS";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const ServiceLevel value)
{
    switch(value)
    {
    case ServiceLevel::BASIC:
        out << "ServiceLevel::BASIC";
        break;
    case ServiceLevel::PLUS:
        out << "ServiceLevel::PLUS";
        break;
    case ServiceLevel::PREMIUM:
        out << "ServiceLevel::PREMIUM";
        break;
    case ServiceLevel::BUSINESS:
        out << "ServiceLevel::BUSINESS";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const QueryFormat value)
{
    switch(value)
    {
    case QueryFormat::USER:
        out << "QueryFormat::USER";
        break;
    case QueryFormat::SEXP:
        out << "QueryFormat::SEXP";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const QueryFormat value)
{
    switch(value)
    {
    case QueryFormat::USER:
        out << "QueryFormat::USER";
        break;
    case QueryFormat::SEXP:
        out << "QueryFormat::SEXP";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const NoteSortOrder value)
{
    switch(value)
    {
    case NoteSortOrder::CREATED:
        out << "NoteSortOrder::CREATED";
        break;
    case NoteSortOrder::UPDATED:
        out << "NoteSortOrder::UPDATED";
        break;
    case NoteSortOrder::RELEVANCE:
        out << "NoteSortOrder::RELEVANCE";
        break;
    case NoteSortOrder::UPDATE_SEQUENCE_NUMBER:
        out << "NoteSortOrder::UPDATE_SEQUENCE_NUMBER";
        break;
    case NoteSortOrder::TITLE:
        out << "NoteSortOrder::TITLE";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const NoteSortOrder value)
{
    switch(value)
    {
    case NoteSortOrder::CREATED:
        out << "NoteSortOrder::CREATED";
        break;
    case NoteSortOrder::UPDATED:
        out << "NoteSortOrder::UPDATED";
        break;
    case NoteSortOrder::RELEVANCE:
        out << "NoteSortOrder::RELEVANCE";
        break;
    case NoteSortOrder::UPDATE_SEQUENCE_NUMBER:
        out << "NoteSortOrder::UPDATE_SEQUENCE_NUMBER";
        break;
    case NoteSortOrder::TITLE:
        out << "NoteSortOrder::TITLE";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const PremiumOrderStatus value)
{
    switch(value)
    {
    case PremiumOrderStatus::NONE:
        out << "PremiumOrderStatus::NONE";
        break;
    case PremiumOrderStatus::PENDING:
        out << "PremiumOrderStatus::PENDING";
        break;
    case PremiumOrderStatus::ACTIVE:
        out << "PremiumOrderStatus::ACTIVE";
        break;
    case PremiumOrderStatus::FAILED:
        out << "PremiumOrderStatus::FAILED";
        break;
    case PremiumOrderStatus::CANCELLATION_PENDING:
        out << "PremiumOrderStatus::CANCELLATION_PENDING";
        break;
    case PremiumOrderStatus::CANCELED:
        out << "PremiumOrderStatus::CANCELED";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const PremiumOrderStatus value)
{
    switch(value)
    {
    case PremiumOrderStatus::NONE:
        out << "PremiumOrderStatus::NONE";
        break;
    case PremiumOrderStatus::PENDING:
        out << "PremiumOrderStatus::PENDING";
        break;
    case PremiumOrderStatus::ACTIVE:
        out << "PremiumOrderStatus::ACTIVE";
        break;
    case PremiumOrderStatus::FAILED:
        out << "PremiumOrderStatus::FAILED";
        break;
    case PremiumOrderStatus::CANCELLATION_PENDING:
        out << "PremiumOrderStatus::CANCELLATION_PENDING";
        break;
    case PremiumOrderStatus::CANCELED:
        out << "PremiumOrderStatus::CANCELED";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const SharedNotebookPrivilegeLevel value)
{
    switch(value)
    {
    case SharedNotebookPrivilegeLevel::READ_NOTEBOOK:
        out << "SharedNotebookPrivilegeLevel::READ_NOTEBOOK";
        break;
    case SharedNotebookPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY:
        out << "SharedNotebookPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY";
        break;
    case SharedNotebookPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY:
        out << "SharedNotebookPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY";
        break;
    case SharedNotebookPrivilegeLevel::GROUP:
        out << "SharedNotebookPrivilegeLevel::GROUP";
        break;
    case SharedNotebookPrivilegeLevel::FULL_ACCESS:
        out << "SharedNotebookPrivilegeLevel::FULL_ACCESS";
        break;
    case SharedNotebookPrivilegeLevel::BUSINESS_FULL_ACCESS:
        out << "SharedNotebookPrivilegeLevel::BUSINESS_FULL_ACCESS";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const SharedNotebookPrivilegeLevel value)
{
    switch(value)
    {
    case SharedNotebookPrivilegeLevel::READ_NOTEBOOK:
        out << "SharedNotebookPrivilegeLevel::READ_NOTEBOOK";
        break;
    case SharedNotebookPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY:
        out << "SharedNotebookPrivilegeLevel::MODIFY_NOTEBOOK_PLUS_ACTIVITY";
        break;
    case SharedNotebookPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY:
        out << "SharedNotebookPrivilegeLevel::READ_NOTEBOOK_PLUS_ACTIVITY";
        break;
    case SharedNotebookPrivilegeLevel::GROUP:
        out << "SharedNotebookPrivilegeLevel::GROUP";
        break;
    case SharedNotebookPrivilegeLevel::FULL_ACCESS:
        out << "SharedNotebookPrivilegeLevel::FULL_ACCESS";
        break;
    case SharedNotebookPrivilegeLevel::BUSINESS_FULL_ACCESS:
        out << "SharedNotebookPrivilegeLevel::BUSINESS_FULL_ACCESS";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const SharedNotePrivilegeLevel value)
{
    switch(value)
    {
    case SharedNotePrivilegeLevel::READ_NOTE:
        out << "SharedNotePrivilegeLevel::READ_NOTE";
        break;
    case SharedNotePrivilegeLevel::MODIFY_NOTE:
        out << "SharedNotePrivilegeLevel::MODIFY_NOTE";
        break;
    case SharedNotePrivilegeLevel::FULL_ACCESS:
        out << "SharedNotePrivilegeLevel::FULL_ACCESS";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const SharedNotePrivilegeLevel value)
{
    switch(value)
    {
    case SharedNotePrivilegeLevel::READ_NOTE:
        out << "SharedNotePrivilegeLevel::READ_NOTE";
        break;
    case SharedNotePrivilegeLevel::MODIFY_NOTE:
        out << "SharedNotePrivilegeLevel::MODIFY_NOTE";
        break;
    case SharedNotePrivilegeLevel::FULL_ACCESS:
        out << "SharedNotePrivilegeLevel::FULL_ACCESS";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const SponsoredGroupRole value)
{
    switch(value)
    {
    case SponsoredGroupRole::GROUP_MEMBER:
        out << "SponsoredGroupRole::GROUP_MEMBER";
        break;
    case SponsoredGroupRole::GROUP_ADMIN:
        out << "SponsoredGroupRole::GROUP_ADMIN";
        break;
    case SponsoredGroupRole::GROUP_OWNER:
        out << "SponsoredGroupRole::GROUP_OWNER";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const SponsoredGroupRole value)
{
    switch(value)
    {
    case SponsoredGroupRole::GROUP_MEMBER:
        out << "SponsoredGroupRole::GROUP_MEMBER";
        break;
    case SponsoredGroupRole::GROUP_ADMIN:
        out << "SponsoredGroupRole::GROUP_ADMIN";
        break;
    case SponsoredGroupRole::GROUP_OWNER:
        out << "SponsoredGroupRole::GROUP_OWNER";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const BusinessUserRole value)
{
    switch(value)
    {
    case BusinessUserRole::ADMIN:
        out << "BusinessUserRole::ADMIN";
        break;
    case BusinessUserRole::NORMAL:
        out << "BusinessUserRole::NORMAL";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const BusinessUserRole value)
{
    switch(value)
    {
    case BusinessUserRole::ADMIN:
        out << "BusinessUserRole::ADMIN";
        break;
    case BusinessUserRole::NORMAL:
        out << "BusinessUserRole::NORMAL";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const BusinessUserStatus value)
{
    switch(value)
    {
    case BusinessUserStatus::ACTIVE:
        out << "BusinessUserStatus::ACTIVE";
        break;
    case BusinessUserStatus::DEACTIVATED:
        out << "BusinessUserStatus::DEACTIVATED";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const BusinessUserStatus value)
{
    switch(value)
    {
    case BusinessUserStatus::ACTIVE:
        out << "BusinessUserStatus::ACTIVE";
        break;
    case BusinessUserStatus::DEACTIVATED:
        out << "BusinessUserStatus::DEACTIVATED";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const SharedNotebookInstanceRestrictions value)
{
    switch(value)
    {
    case SharedNotebookInstanceRestrictions::ASSIGNED:
        out << "SharedNotebookInstanceRestrictions::ASSIGNED";
        break;
    case SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS:
        out << "SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const SharedNotebookInstanceRestrictions value)
{
    switch(value)
    {
    case SharedNotebookInstanceRestrictions::ASSIGNED:
        out << "SharedNotebookInstanceRestrictions::ASSIGNED";
        break;
    case SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS:
        out << "SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const ReminderEmailConfig value)
{
    switch(value)
    {
    case ReminderEmailConfig::DO_NOT_SEND:
        out << "ReminderEmailConfig::DO_NOT_SEND";
        break;
    case ReminderEmailConfig::SEND_DAILY_EMAIL:
        out << "ReminderEmailConfig::SEND_DAILY_EMAIL";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const ReminderEmailConfig value)
{
    switch(value)
    {
    case ReminderEmailConfig::DO_NOT_SEND:
        out << "ReminderEmailConfig::DO_NOT_SEND";
        break;
    case ReminderEmailConfig::SEND_DAILY_EMAIL:
        out << "ReminderEmailConfig::SEND_DAILY_EMAIL";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const BusinessInvitationStatus value)
{
    switch(value)
    {
    case BusinessInvitationStatus::APPROVED:
        out << "BusinessInvitationStatus::APPROVED";
        break;
    case BusinessInvitationStatus::REQUESTED:
        out << "BusinessInvitationStatus::REQUESTED";
        break;
    case BusinessInvitationStatus::REDEEMED:
        out << "BusinessInvitationStatus::REDEEMED";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const BusinessInvitationStatus value)
{
    switch(value)
    {
    case BusinessInvitationStatus::APPROVED:
        out << "BusinessInvitationStatus::APPROVED";
        break;
    case BusinessInvitationStatus::REQUESTED:
        out << "BusinessInvitationStatus::REQUESTED";
        break;
    case BusinessInvitationStatus::REDEEMED:
        out << "BusinessInvitationStatus::REDEEMED";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const ContactType value)
{
    switch(value)
    {
    case ContactType::EVERNOTE:
        out << "ContactType::EVERNOTE";
        break;
    case ContactType::SMS:
        out << "ContactType::SMS";
        break;
    case ContactType::FACEBOOK:
        out << "ContactType::FACEBOOK";
        break;
    case ContactType::EMAIL:
        out << "ContactType::EMAIL";
        break;
    case ContactType::TWITTER:
        out << "ContactType::TWITTER";
        break;
    case ContactType::LINKEDIN:
        out << "ContactType::LINKEDIN";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const ContactType value)
{
    switch(value)
    {
    case ContactType::EVERNOTE:
        out << "ContactType::EVERNOTE";
        break;
    case ContactType::SMS:
        out << "ContactType::SMS";
        break;
    case ContactType::FACEBOOK:
        out << "ContactType::FACEBOOK";
        break;
    case ContactType::EMAIL:
        out << "ContactType::EMAIL";
        break;
    case ContactType::TWITTER:
        out << "ContactType::TWITTER";
        break;
    case ContactType::LINKEDIN:
        out << "ContactType::LINKEDIN";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const EntityType value)
{
    switch(value)
    {
    case EntityType::NOTE:
        out << "EntityType::NOTE";
        break;
    case EntityType::NOTEBOOK:
        out << "EntityType::NOTEBOOK";
        break;
    case EntityType::WORKSPACE:
        out << "EntityType::WORKSPACE";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const EntityType value)
{
    switch(value)
    {
    case EntityType::NOTE:
        out << "EntityType::NOTE";
        break;
    case EntityType::NOTEBOOK:
        out << "EntityType::NOTEBOOK";
        break;
    case EntityType::WORKSPACE:
        out << "EntityType::WORKSPACE";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const RecipientStatus value)
{
    switch(value)
    {
    case RecipientStatus::NOT_IN_MY_LIST:
        out << "RecipientStatus::NOT_IN_MY_LIST";
        break;
    case RecipientStatus::IN_MY_LIST:
        out << "RecipientStatus::IN_MY_LIST";
        break;
    case RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK:
        out << "RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const RecipientStatus value)
{
    switch(value)
    {
    case RecipientStatus::NOT_IN_MY_LIST:
        out << "RecipientStatus::NOT_IN_MY_LIST";
        break;
    case RecipientStatus::IN_MY_LIST:
        out << "RecipientStatus::IN_MY_LIST";
        break;
    case RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK:
        out << "RecipientStatus::IN_MY_LIST_AND_DEFAULT_NOTEBOOK";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const CanMoveToContainerStatus value)
{
    switch(value)
    {
    case CanMoveToContainerStatus::CAN_BE_MOVED:
        out << "CanMoveToContainerStatus::CAN_BE_MOVED";
        break;
    case CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE:
        out << "CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE";
        break;
    case CanMoveToContainerStatus::INSUFFICIENT_CONTAINER_PRIVILEGE:
        out << "CanMoveToContainerStatus::INSUFFICIENT_CONTAINER_PRIVILEGE";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const CanMoveToContainerStatus value)
{
    switch(value)
    {
    case CanMoveToContainerStatus::CAN_BE_MOVED:
        out << "CanMoveToContainerStatus::CAN_BE_MOVED";
        break;
    case CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE:
        out << "CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE";
        break;
    case CanMoveToContainerStatus::INSUFFICIENT_CONTAINER_PRIVILEGE:
        out << "CanMoveToContainerStatus::INSUFFICIENT_CONTAINER_PRIVILEGE";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const RelatedContentType value)
{
    switch(value)
    {
    case RelatedContentType::NEWS_ARTICLE:
        out << "RelatedContentType::NEWS_ARTICLE";
        break;
    case RelatedContentType::PROFILE_PERSON:
        out << "RelatedContentType::PROFILE_PERSON";
        break;
    case RelatedContentType::PROFILE_ORGANIZATION:
        out << "RelatedContentType::PROFILE_ORGANIZATION";
        break;
    case RelatedContentType::REFERENCE_MATERIAL:
        out << "RelatedContentType::REFERENCE_MATERIAL";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const RelatedContentType value)
{
    switch(value)
    {
    case RelatedContentType::NEWS_ARTICLE:
        out << "RelatedContentType::NEWS_ARTICLE";
        break;
    case RelatedContentType::PROFILE_PERSON:
        out << "RelatedContentType::PROFILE_PERSON";
        break;
    case RelatedContentType::PROFILE_ORGANIZATION:
        out << "RelatedContentType::PROFILE_ORGANIZATION";
        break;
    case RelatedContentType::REFERENCE_MATERIAL:
        out << "RelatedContentType::REFERENCE_MATERIAL";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const RelatedContentAccess value)
{
    switch(value)
    {
    case RelatedContentAccess::NOT_ACCESSIBLE:
        out << "RelatedContentAccess::NOT_ACCESSIBLE";
        break;
    case RelatedContentAccess::DIRECT_LINK_ACCESS_OK:
        out << "RelatedContentAccess::DIRECT_LINK_ACCESS_OK";
        break;
    case RelatedContentAccess::DIRECT_LINK_LOGIN_REQUIRED:
        out << "RelatedContentAccess::DIRECT_LINK_LOGIN_REQUIRED";
        break;
    case RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW:
        out << "RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const RelatedContentAccess value)
{
    switch(value)
    {
    case RelatedContentAccess::NOT_ACCESSIBLE:
        out << "RelatedContentAccess::NOT_ACCESSIBLE";
        break;
    case RelatedContentAccess::DIRECT_LINK_ACCESS_OK:
        out << "RelatedContentAccess::DIRECT_LINK_ACCESS_OK";
        break;
    case RelatedContentAccess::DIRECT_LINK_LOGIN_REQUIRED:
        out << "RelatedContentAccess::DIRECT_LINK_LOGIN_REQUIRED";
        break;
    case RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW:
        out << "RelatedContentAccess::DIRECT_LINK_EMBEDDED_VIEW";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QTextStream & operator<<(
    QTextStream & out, const UserIdentityType value)
{
    switch(value)
    {
    case UserIdentityType::EVERNOTE_USERID:
        out << "UserIdentityType::EVERNOTE_USERID";
        break;
    case UserIdentityType::EMAIL:
        out << "UserIdentityType::EMAIL";
        break;
    case UserIdentityType::IDENTITYID:
        out << "UserIdentityType::IDENTITYID";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

////////////////////////////////////////////////////////////////////////////////

QDebug & operator<<(
    QDebug & out, const UserIdentityType value)
{
    switch(value)
    {
    case UserIdentityType::EVERNOTE_USERID:
        out << "UserIdentityType::EVERNOTE_USERID";
        break;
    case UserIdentityType::EMAIL:
        out << "UserIdentityType::EMAIL";
        break;
    case UserIdentityType::IDENTITYID:
        out << "UserIdentityType::IDENTITYID";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(value) << ")";
        break;
    }
    return out;
}

} // namespace qevercloud
