/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */


#ifndef QEVERCLOUD_GENERATED_EDAMERRORCODE_H
#define QEVERCLOUD_GENERATED_EDAMERRORCODE_H

#include "../export.h"

namespace qevercloud {

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
 *       by logging the user out and purging all locally saved content, including local
 *       edits not yet pushed to the server.</dd>
 *	 <dt>SSO_AUTHENTICATION_REQUIRED</dt>
  *     <dd>SSO authentication is the only type of authentication allowed for the user's
  *     account. This error is thrown when the user attempts to authenticate by another
   *     method (password, OpenId, etc).</dd>
  * </dl>
 */
struct QEVERCLOUD_EXPORT EDAMErrorCode
{
    enum type
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
};


} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMERRORCODE_H
