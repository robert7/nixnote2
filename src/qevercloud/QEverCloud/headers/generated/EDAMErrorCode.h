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

#ifndef QEVERCLOUD_GENERATED_EDAMERRORCODE_H
#define QEVERCLOUD_GENERATED_EDAMERRORCODE_H

#include "../Export.h"

#include "../Helpers.h"
#include <QDebug>
#include <QMetaType>
#include <QTextStream>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_NAMESPACE
#endif
#endif

////////////////////////////////////////////////////////////////////////////////

/**
 * Numeric codes indicating the type of error that occurred on the
 * service.
 * <dl>
 *   <dt>UNKNOWN</dt>
 *     <dd>No information available about the error</dd>
 *   <dt>BAD_DATA_FORMAT</dt>
 *     <dd>The format of the request data was incorrect</dd>
 *   <dt>PERMISSION_DENIED</dt>
 *     <dd>Not permitted to perform action</dd>
 *   <dt>INTERNAL_ERROR</dt>
 *     <dd>Unexpected problem with the service</dd>
 *   <dt>DATA_REQUIRED</dt>
 *     <dd>A required parameter/field was absent</dd>
 *   <dt>LIMIT_REACHED</dt>
 *     <dd>Operation denied due to data model limit</dd>
 *   <dt>QUOTA_REACHED</dt>
 *     <dd>Operation denied due to user storage limit</dd>
 *   <dt>INVALID_AUTH</dt>
 *     <dd>Username and/or password incorrect</dd>
 *   <dt>AUTH_EXPIRED</dt>
 *     <dd>Authentication token expired</dd>
 *   <dt>DATA_CONFLICT</dt>
 *     <dd>Change denied due to data model conflict</dd>
 *   <dt>ENML_VALIDATION</dt>
 *     <dd>Content of submitted note was malformed</dd>
 *   <dt>SHARD_UNAVAILABLE</dt>
 *     <dd>Service shard with account data is temporarily down</dd>
 *   <dt>LEN_TOO_SHORT</dt>
 *     <dd>Operation denied due to data model limit, where something such
 *         as a string length was too short</dd>
 *   <dt>LEN_TOO_LONG</dt>
 *     <dd>Operation denied due to data model limit, where something such
 *         as a string length was too long</dd>
 *   <dt>TOO_FEW</dt>
 *     <dd>Operation denied due to data model limit, where there were
 *         too few of something.</dd>
 *   <dt>TOO_MANY</dt>
 *     <dd>Operation denied due to data model limit, where there were
 *         too many of something.</dd>
 *   <dt>UNSUPPORTED_OPERATION</dt>
 *     <dd>Operation denied because it is currently unsupported.</dd>
 *   <dt>TAKEN_DOWN</dt>
 *     <dd>Operation denied because access to the corresponding object is
 *         prohibited in response to a take-down notice.</dd>
 *   <dt>RATE_LIMIT_REACHED</dt>
 *     <dd>Operation denied because the calling application has reached
 *         its hourly API call limit for this user.</dd>
 *   <dt>BUSINESS_SECURITY_LOGIN_REQUIRED</dt>
 *     <dd>Access to a business account has been denied because the user must complete
 *        additional steps in order to comply with business security requirements.</dd>
 *   <dt>DEVICE_LIMIT_REACHED</dt>
 *     <dd>Operation denied because the user has exceeded their maximum allowed
 *        number of devices.</dd>
 *   <dt>OPENID_ALREADY_TAKEN</dt>
 *     <dd>Operation failed because the Open ID is already associated with another user.</dd>
 *   <dt>INVALID_OPENID_TOKEN</dt>
 *     <dd>Operation denied because the Open ID token is invalid. Please re-issue a valid
 *        token.</dd>
 *	 <dt>USER_NOT_REGISTERED</dt>
 *     <dd>There is no Evernote user associated with this OpenID account,
 *     	   and no Evernote user with a matching email</dd>
 *	 <dt>USER_NOT_ASSOCIATED</dt>
 *     <dd>There is no Evernote user associated with this OpenID account,
 *		   but Evernote user with matching email exists</dd>
 *	 <dt>USER_ALREADY_ASSOCIATED</dt>
 * 	   <dd>Evernote user is already associated with this provider
 *		   using a different email address.</dd>
 *	 <dt>ACCOUNT_CLEAR</dt>
 *     <dd>The user's account has been disabled. Clients should deal with this errorCode
 *         by logging the user out and purging all locally saved content, including local
 *         edits not yet pushed to the server.</dd>
 *	 <dt>SSO_AUTHENTICATION_REQUIRED</dt>
 *     <dd>SSO authentication is the only type of authentication allowed for the user's
 *         account. This error is thrown when the user attempts to authenticate by another
 *         method (password, OpenId, etc).</dd>
 * </dl>
 */
enum class EDAMErrorCode
{
    UNKNOWN = 1,
    BAD_DATA_FORMAT = 2,
    PERMISSION_DENIED = 3,
    INTERNAL_ERROR = 4,
    DATA_REQUIRED = 5,
    LIMIT_REACHED = 6,
    QUOTA_REACHED = 7,
    INVALID_AUTH = 8,
    AUTH_EXPIRED = 9,
    DATA_CONFLICT = 10,
    ENML_VALIDATION = 11,
    SHARD_UNAVAILABLE = 12,
    LEN_TOO_SHORT = 13,
    LEN_TOO_LONG = 14,
    TOO_FEW = 15,
    TOO_MANY = 16,
    UNSUPPORTED_OPERATION = 17,
    TAKEN_DOWN = 18,
    RATE_LIMIT_REACHED = 19,
    BUSINESS_SECURITY_LOGIN_REQUIRED = 20,
    DEVICE_LIMIT_REACHED = 21,
    OPENID_ALREADY_TAKEN = 22,
    INVALID_OPENID_TOKEN = 23,
    USER_NOT_ASSOCIATED = 24,
    USER_NOT_REGISTERED = 25,
    USER_ALREADY_ASSOCIATED = 26,
    ACCOUNT_CLEAR = 27,
    SSO_AUTHENTICATION_REQUIRED = 28
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(EDAMErrorCode)
#endif
#endif

inline uint qHash(EDAMErrorCode value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const EDAMErrorCode value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const EDAMErrorCode value);

////////////////////////////////////////////////////////////////////////////////

/**
 * An enumeration that provides a reason for why a given contact was invalid, for example,
 * as thrown via an EDAMInvalidContactsException.
 *
 * <dl>
 *   <dt>BAD_ADDRESS</dt>
 *     <dd>The contact information does not represent a valid address for a recipient.
 *         Clients should be validating and normalizing contacts, so receiving this
 *         error code commonly represents a client error.
 *         </dd>
 *   <dt>DUPLICATE_CONTACT</dt>
 *     <dd>If the method throwing this exception accepts a list of contacts, this error
 *         code indicates that the given contact is a duplicate of another contact in
 *         the list.  Note that the server may clean up contacts, and that this cleanup
 *         occurs before checking for duplication.  Receiving this error is commonly
 *         an indication of a client issue, since client should be normalizing contacts
 *         and removing duplicates. All instances that are duplicates are returned.  For
 *         example, if a list of 5 contacts has the same e-mail address twice, the two
 *         conflicting e-mail address contacts will be returned.
 *         </dd>
 *   <dt>NO_CONNECTION</dt>
 *     <dd>Indicates that the given contact, an Evernote type contact, is not connected
 *         to the user for which the call is being made. It is possible that clients are
 *         out of sync with the server and should re-synchronize their identities and
 *         business user state. See Identity.userConnected for more information on user
 *         connections.
 *         </dd>
 * </dl>
 *
 * Note that if multiple reasons may apply, only one is returned. The precedence order
 * is BAD_ADDRESS, DUPLICATE_CONTACT, NO_CONNECTION, meaning that if a contact has a bad
 * address and is also duplicated, it will be returned as a BAD_ADDRESS.
 */
enum class EDAMInvalidContactReason
{
    BAD_ADDRESS,
    DUPLICATE_CONTACT,
    NO_CONNECTION
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(EDAMInvalidContactReason)
#endif
#endif

inline uint qHash(EDAMInvalidContactReason value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const EDAMInvalidContactReason value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const EDAMInvalidContactReason value);

////////////////////////////////////////////////////////////////////////////////

/**
 * Privilege levels for accessing shared notebooks.
 *
 * READ_NOTEBOOK: Recipient is able to read the contents of the shared notebook
 *   but does not have access to information about other recipients of the
 *   notebook or the activity stream information.
 *
 * READ_NOTEBOOK_PLUS_ACTIVITY: Recipient has READ_NOTEBOOK rights and can also
 *   access information about other recipients and the activity stream.
 *
 * MODIFY_NOTEBOOK_PLUS_ACTIVITY: Recipient has rights to read and modify the contents
 *   of the shared notebook, including the right to move notes to the trash and to create
 *   notes in the notebook.  The recipient can also access information about other
 *   recipients and the activity stream.
 *
 * FULL_ACCESS: Recipient has full rights to the shared notebook and recipient lists,
 *   including privilege to revoke and create invitations and to change privilege
 *   levels on invitations for individuals. If the user is a member of the same group,
 *   (e.g. the same business) as the shared notebook, they will additionally be granted
 *   permissions to update the publishing status of the notebook.
 */
enum class ShareRelationshipPrivilegeLevel
{
    READ_NOTEBOOK = 0,
    READ_NOTEBOOK_PLUS_ACTIVITY = 10,
    MODIFY_NOTEBOOK_PLUS_ACTIVITY = 20,
    FULL_ACCESS = 30
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(ShareRelationshipPrivilegeLevel)
#endif
#endif

inline uint qHash(ShareRelationshipPrivilegeLevel value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const ShareRelationshipPrivilegeLevel value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const ShareRelationshipPrivilegeLevel value);

////////////////////////////////////////////////////////////////////////////////

/**
 * This enumeration defines the possible permission levels for a user.
 * Free accounts will have a level of NORMAL and paid Premium accounts
 * will have a level of PREMIUM.
 */
enum class PrivilegeLevel
{
    NORMAL = 1,
    PREMIUM = 3,
    VIP = 5,
    MANAGER = 7,
    SUPPORT = 8,
    ADMIN = 9
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(PrivilegeLevel)
#endif
#endif

inline uint qHash(PrivilegeLevel value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const PrivilegeLevel value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const PrivilegeLevel value);

////////////////////////////////////////////////////////////////////////////////

/**
 * This enumeration defines the possible tiers of service that a user may have. A
 * ServiceLevel of BUSINESS signifies a business-only account, which can never be any
 * other ServiceLevel.
 */
enum class ServiceLevel
{
    BASIC = 1,
    PLUS = 2,
    PREMIUM = 3,
    BUSINESS = 4
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(ServiceLevel)
#endif
#endif

inline uint qHash(ServiceLevel value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const ServiceLevel value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const ServiceLevel value);

////////////////////////////////////////////////////////////////////////////////

/**
 * Every search query is specified as a sequence of characters.
 * Currently, only the USER query format is supported.
 */
enum class QueryFormat
{
    USER = 1,
    SEXP = 2
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(QueryFormat)
#endif
#endif

inline uint qHash(QueryFormat value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const QueryFormat value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const QueryFormat value);

////////////////////////////////////////////////////////////////////////////////

/**
 * This enumeration defines the possible sort ordering for notes when
 * they are returned from a search result.
 */
enum class NoteSortOrder
{
    CREATED = 1,
    UPDATED = 2,
    RELEVANCE = 3,
    UPDATE_SEQUENCE_NUMBER = 4,
    TITLE = 5
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(NoteSortOrder)
#endif
#endif

inline uint qHash(NoteSortOrder value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const NoteSortOrder value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const NoteSortOrder value);

////////////////////////////////////////////////////////////////////////////////

/**
 * This enumeration defines the possible states of a premium account
 *
 * NONE:    the user has never attempted to become a premium subscriber
 *
 * PENDING: the user has requested a premium account but their charge has not
 *   been confirmed
 *
 * ACTIVE:  the user has been charged and their premium account is in good
 *  standing
 *
 * FAILED:  the system attempted to charge the was denied. We will periodically attempt to
 *  re-validate their order.
 *
 * CANCELLATION_PENDING: the user has requested that no further charges be made
 *   but the current account is still active.
 *
 * CANCELED: the premium account was canceled either because of failure to pay
 *   or user cancelation. No more attempts will be made to activate the account.
 */
enum class PremiumOrderStatus
{
    NONE = 0,
    PENDING = 1,
    ACTIVE = 2,
    FAILED = 3,
    CANCELLATION_PENDING = 4,
    CANCELED = 5
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(PremiumOrderStatus)
#endif
#endif

inline uint qHash(PremiumOrderStatus value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const PremiumOrderStatus value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const PremiumOrderStatus value);

////////////////////////////////////////////////////////////////////////////////

/**
 * Privilege levels for accessing shared notebooks.
 *
 * Note that as of 2014-04, FULL_ACCESS is synonymous with BUSINESS_FULL_ACCESS.  If a
 * user is a member of a business and has FULL_ACCESS privileges, then they will
 * automatically be granted BUSINESS_FULL_ACCESS for notebooks in their business.  This
 * will happen implicitly when they attempt to access the corresponding notebooks of
 * the business.  BUSINESS_FULL_ACCESS is therefore deprecated.
 *
 * READ_NOTEBOOK: Recipient is able to read the contents of the shared notebook
 *   but does not have access to information about other recipients of the
 *   notebook or the activity stream information.
 *
 * MODIFY_NOTEBOOK_PLUS_ACTIVITY: Recipient has rights to read and modify the contents
 *   of the shared notebook, including the right to move notes to the trash and to create
 *   notes in the notebook.  The recipient can also access information about other
 *   recipients and the activity stream.
 *
 * READ_NOTEBOOK_PLUS_ACTIVITY: Recipient has READ_NOTEBOOK rights and can also
 *   access information about other recipients and the activity stream.
 *
 * GROUP: If the user belongs to a group, such as a Business, that has a defined
 *   privilege level, use the privilege level of the group as the privilege for
 *   the individual.
 *
 * FULL_ACCESS: Recipient has full rights to the shared notebook and recipient lists,
 *   including privilege to revoke and create invitations and to change privilege
 *   levels on invitations for individuals.  For members of a business, FULL_ACCESS
 *   privilege on business notebooks also grants the ability to change how the notebook
 *   will appear when shared with the business, including the rights to share and
 *   unshare the notebook with the business.
 *
 * BUSINESS_FULL_ACCESS: Deprecated.  See the note above about BUSINESS_FULL_ACCESS and
 *   FULL_ACCESS being synonymous.
 */
enum class SharedNotebookPrivilegeLevel
{
    READ_NOTEBOOK = 0,
    MODIFY_NOTEBOOK_PLUS_ACTIVITY = 1,
    READ_NOTEBOOK_PLUS_ACTIVITY = 2,
    GROUP = 3,
    FULL_ACCESS = 4,
    BUSINESS_FULL_ACCESS = 5
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(SharedNotebookPrivilegeLevel)
#endif
#endif

inline uint qHash(SharedNotebookPrivilegeLevel value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const SharedNotebookPrivilegeLevel value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const SharedNotebookPrivilegeLevel value);

////////////////////////////////////////////////////////////////////////////////

/**
 * Privilege levels for accessing a shared note. All privilege levels convey "activity feed" access,
 * which allows the recipient to access information about other recipients and the activity stream.
 *
 * READ_NOTE: Recipient has rights to read the shared note.
 *
 * MODIFY_NOTE: Recipient has all of the rights of READ_NOTE, plus rights to modify the shared
 *   note's content, title and resources. Other fields, including the notebook, tags and metadata,
 *   may not be modified.
 *
 * FULL_ACCESS: Recipient has all of the rights of MODIFY_NOTE, plus rights to share the note with
 *   other users via email, public note links, and note sharing. Recipient may also update and
 *   remove other recipient's note sharing rights.
 */
enum class SharedNotePrivilegeLevel
{
    READ_NOTE = 0,
    MODIFY_NOTE = 1,
    FULL_ACCESS = 2
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(SharedNotePrivilegeLevel)
#endif
#endif

inline uint qHash(SharedNotePrivilegeLevel value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const SharedNotePrivilegeLevel value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const SharedNotePrivilegeLevel value);

////////////////////////////////////////////////////////////////////////////////

/**
 * Enumeration of the roles that a User can have within a sponsored group.
 *
 * GROUP_MEMBER: The user is a member of the group with no special privileges.
 *
 * GROUP_ADMIN: The user is an administrator within the group.
 *
 * GROUP_OWNER: The user is the owner of the group.
 */
enum class SponsoredGroupRole
{
    GROUP_MEMBER = 1,
    GROUP_ADMIN = 2,
    GROUP_OWNER = 3
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(SponsoredGroupRole)
#endif
#endif

inline uint qHash(SponsoredGroupRole value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const SponsoredGroupRole value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const SponsoredGroupRole value);

////////////////////////////////////////////////////////////////////////////////

/**
 * Enumeration of the roles that a User can have within an Evernote Business account.
 *
 * ADMIN: The user is an administrator of the Evernote Business account.
 *
 * NORMAL: The user is a regular user within the Evernote Business account.
 */
enum class BusinessUserRole
{
    ADMIN = 1,
    NORMAL = 2
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(BusinessUserRole)
#endif
#endif

inline uint qHash(BusinessUserRole value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const BusinessUserRole value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const BusinessUserRole value);

////////////////////////////////////////////////////////////////////////////////

/**
 * The BusinessUserStatus indicates the status of the user in the business.
 *
 * A BusinessUser will typically start as ACTIVE.
 * Only ACTIVE users can authenticate to the Business.
 *
 * <dl>
 * <dt>ACTIVE<dt>
 * <dd>The business user can authenticate to and access the business.</dd>
 * <dt>DEACTIVATED<dt>
 * <dd>The business user has been deactivated and cannot access the business</dd>
 * </dl>
 */
enum class BusinessUserStatus
{
    ACTIVE = 1,
    DEACTIVATED = 2
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(BusinessUserStatus)
#endif
#endif

inline uint qHash(BusinessUserStatus value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const BusinessUserStatus value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const BusinessUserStatus value);

////////////////////////////////////////////////////////////////////////////////

/**
 * An enumeration describing restrictions on the domain of shared notebook
 * instances that are valid for a given operation, as used, for example, in
 * NotebookRestrictions.
 *
 * ASSIGNED: The domain consists of shared notebooks that belong, or are assigned,
 * to the recipient.
 *
 * NO_SHARED_NOTEBOOKS: No shared notebooks are applicable to the operation.
 */
enum class SharedNotebookInstanceRestrictions
{
    ASSIGNED = 1,
    NO_SHARED_NOTEBOOKS = 2
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(SharedNotebookInstanceRestrictions)
#endif
#endif

inline uint qHash(SharedNotebookInstanceRestrictions value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const SharedNotebookInstanceRestrictions value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const SharedNotebookInstanceRestrictions value);

////////////////////////////////////////////////////////////////////////////////

/**
 * An enumeration describing the configuration state related to receiving
 * reminder e-mails from the service.  Reminder e-mails summarize notes
 * based on their Note.attributes.reminderTime values.
 *
 * DO_NOT_SEND: The user has selected to not receive reminder e-mail.
 *
 * SEND_DAILY_EMAIL: The user has selected to receive reminder e-mail for those
 *   days when there is a reminder.
 */
enum class ReminderEmailConfig
{
    DO_NOT_SEND = 1,
    SEND_DAILY_EMAIL = 2
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(ReminderEmailConfig)
#endif
#endif

inline uint qHash(ReminderEmailConfig value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const ReminderEmailConfig value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const ReminderEmailConfig value);

////////////////////////////////////////////////////////////////////////////////

/**
 * An enumeration defining the possible states of a BusinessInvitation.
 *
 * APPROVED: The invitation was created or approved by a business admin and may be redeemed by the
 *   invited email.
 *
 * REQUESTED: The invitation was requested by a non-admin member of the business and must be
 *   approved by an admin before it may be redeemed. Invitations in this state do not count
 *   against a business' seat limit.
 *
 * REDEEMED: The invitation has already been redeemed. Invitations in this state do not count
 *   against a business' seat limit.
 */
enum class BusinessInvitationStatus
{
    APPROVED = 0,
    REQUESTED = 1,
    REDEEMED = 2
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(BusinessInvitationStatus)
#endif
#endif

inline uint qHash(BusinessInvitationStatus value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const BusinessInvitationStatus value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const BusinessInvitationStatus value);

////////////////////////////////////////////////////////////////////////////////

/**
 * What kinds of Contacts does the Evernote service know about?
 */
enum class ContactType
{
    EVERNOTE = 1,
    SMS = 2,
    FACEBOOK = 3,
    EMAIL = 4,
    TWITTER = 5,
    LINKEDIN = 6
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(ContactType)
#endif
#endif

inline uint qHash(ContactType value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const ContactType value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const ContactType value);

////////////////////////////////////////////////////////////////////////////////

/**
 * Entity types
 */
enum class EntityType
{
    NOTE = 1,
    NOTEBOOK = 2,
    WORKSPACE = 3
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(EntityType)
#endif
#endif

inline uint qHash(EntityType value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const EntityType value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const EntityType value);

////////////////////////////////////////////////////////////////////////////////

/**
 * This enumeration defines the possible states that a notebook can be in for a recipient.
 * It encompasses the "inMyList" boolean and default notebook status.
 *
 * <dl>
 * <dt>NOT_IN_MY_LIST</dt>
 * <dd>The notebook is not in the recipient's list (not "joined").</dd>
 * <dt>IN_MY_LIST</dt>
 * <dd>The notebook is in the recipient's notebook list (formerly, we would say
 *     that the recipient has "joined" the notebook)</dd>
 * <dt>IN_MY_LIST_AND_DEFAULT_NOTEBOOK</dt>
 * <dd>The same as IN_MY_LIST and this notebook is the user's default notebook.</dd>
 * </dl>
 */
enum class RecipientStatus
{
    NOT_IN_MY_LIST = 1,
    IN_MY_LIST = 2,
    IN_MY_LIST_AND_DEFAULT_NOTEBOOK = 3
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(RecipientStatus)
#endif
#endif

inline uint qHash(RecipientStatus value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const RecipientStatus value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const RecipientStatus value);

////////////////////////////////////////////////////////////////////////////////

/**
 * This enumeration defines the possible types of canMoveToContainer outcomes.
 * <p />
 * An outdated client is expected to signal a "Cannot Move, Please Upgrade To Learn Why"
 * like response to the user if an unknown enumeration value is received.
 * <dl>
 * <dt>CAN_BE_MOVED</dt>
 * <dd>Can move Notebook to Workspace.</dd>
 * <dt>INSUFFICIENT_ENTITY_PRIVILEGE</dt>
 * <dd>Can not move Notebook to Workspace, because either:
 *  a) Notebook not in Workspace and insufficient privilege on Notebook
 *  or b) Notebook in Workspace and membership on Workspace with insufficient privilege
 *  for move</dd>
 * <dt>INSUFFICIENT_CONTAINER_PRIVILEGE</dt>
 * <dd>Notebook in Workspace and no membership on Workspace.
 * </dd>
 * </dl>
 */
enum class CanMoveToContainerStatus
{
    CAN_BE_MOVED = 1,
    INSUFFICIENT_ENTITY_PRIVILEGE = 2,
    INSUFFICIENT_CONTAINER_PRIVILEGE = 3
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(CanMoveToContainerStatus)
#endif
#endif

inline uint qHash(CanMoveToContainerStatus value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const CanMoveToContainerStatus value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const CanMoveToContainerStatus value);

////////////////////////////////////////////////////////////////////////////////

/**
 * This enumeration defines the possible types of related content.
 *
 * NEWS_ARTICLE: This related content is a news article
 * PROFILE_PERSON: This match refers to the profile of an individual person
 * PROFILE_ORGANIZATION: This match refers to the profile of an organization
 * REFERENCE_MATERIAL: This related content is material from reference works
 */
enum class RelatedContentType
{
    NEWS_ARTICLE = 1,
    PROFILE_PERSON = 2,
    PROFILE_ORGANIZATION = 3,
    REFERENCE_MATERIAL = 4
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(RelatedContentType)
#endif
#endif

inline uint qHash(RelatedContentType value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const RelatedContentType value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const RelatedContentType value);

////////////////////////////////////////////////////////////////////////////////

/**
 * This enumeration defines the possible ways to access related content.
 *
 * NOT_ACCESSIBLE: The content is not accessible given the user's privilege level, but
 *     still worth showing as a snippet. The content url may point to a webpage that
 *     explains why not, or explains how to access that content.
 *
 * DIRECT_LINK_ACCESS_OK: The content is accessible directly, and no additional login is
 *     required.
 *
 * DIRECT_LINK_LOGIN_REQUIRED: The content is accessible directly, but an additional login
 *     is required.
 *
 * DIRECT_LINK_EMBEDDED_VIEW: The content is accessible directly, and should be shown in
 *     an embedded web view.
 *     If the URL refers to a secured location under our control (for example,
 *     https://www.evernote.com/<smth>), the client may include user-specific authentication
 *     credentials with the request.
 */
enum class RelatedContentAccess
{
    NOT_ACCESSIBLE = 0,
    DIRECT_LINK_ACCESS_OK = 1,
    DIRECT_LINK_LOGIN_REQUIRED = 2,
    DIRECT_LINK_EMBEDDED_VIEW = 3
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(RelatedContentAccess)
#endif
#endif

inline uint qHash(RelatedContentAccess value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const RelatedContentAccess value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const RelatedContentAccess value);

////////////////////////////////////////////////////////////////////////////////

/**
 *
 */
enum class UserIdentityType
{
    EVERNOTE_USERID = 1,
    EMAIL = 2,
    IDENTITYID = 3
};

#if QT_VERSION >= QT_VERSION_CHECK(5, 8, 0)
#if QEVERCLOUD_USES_Q_NAMESPACE
Q_ENUM_NS(UserIdentityType)
#endif
#endif

inline uint qHash(UserIdentityType value)
{
    return static_cast<uint>(value);
}

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const UserIdentityType value);

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const UserIdentityType value);

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::EDAMErrorCode)
Q_DECLARE_METATYPE(qevercloud::EDAMInvalidContactReason)
Q_DECLARE_METATYPE(qevercloud::ShareRelationshipPrivilegeLevel)
Q_DECLARE_METATYPE(qevercloud::PrivilegeLevel)
Q_DECLARE_METATYPE(qevercloud::ServiceLevel)
Q_DECLARE_METATYPE(qevercloud::QueryFormat)
Q_DECLARE_METATYPE(qevercloud::NoteSortOrder)
Q_DECLARE_METATYPE(qevercloud::PremiumOrderStatus)
Q_DECLARE_METATYPE(qevercloud::SharedNotebookPrivilegeLevel)
Q_DECLARE_METATYPE(qevercloud::SharedNotePrivilegeLevel)
Q_DECLARE_METATYPE(qevercloud::SponsoredGroupRole)
Q_DECLARE_METATYPE(qevercloud::BusinessUserRole)
Q_DECLARE_METATYPE(qevercloud::BusinessUserStatus)
Q_DECLARE_METATYPE(qevercloud::SharedNotebookInstanceRestrictions)
Q_DECLARE_METATYPE(qevercloud::ReminderEmailConfig)
Q_DECLARE_METATYPE(qevercloud::BusinessInvitationStatus)
Q_DECLARE_METATYPE(qevercloud::ContactType)
Q_DECLARE_METATYPE(qevercloud::EntityType)
Q_DECLARE_METATYPE(qevercloud::RecipientStatus)
Q_DECLARE_METATYPE(qevercloud::CanMoveToContainerStatus)
Q_DECLARE_METATYPE(qevercloud::RelatedContentType)
Q_DECLARE_METATYPE(qevercloud::RelatedContentAccess)
Q_DECLARE_METATYPE(qevercloud::UserIdentityType)

#endif // QEVERCLOUD_GENERATED_EDAMERRORCODE_H
