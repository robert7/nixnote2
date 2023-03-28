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

#ifndef QEVERCLOUD_GENERATED_TESTUSERSTORE_H
#define QEVERCLOUD_GENERATED_TESTUSERSTORE_H

#include <QObject>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

class UserStoreTester: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreTester(QObject * parent = nullptr);

private Q_SLOTS:
    void shouldExecuteCheckVersion();
    void shouldDeliverThriftExceptionInCheckVersion();
    void shouldExecuteCheckVersionAsync();
    void shouldDeliverThriftExceptionInCheckVersionAsync();
    void shouldExecuteGetBootstrapInfo();
    void shouldDeliverThriftExceptionInGetBootstrapInfo();
    void shouldExecuteGetBootstrapInfoAsync();
    void shouldDeliverThriftExceptionInGetBootstrapInfoAsync();
    void shouldExecuteAuthenticateLongSession();
    void shouldDeliverEDAMUserExceptionInAuthenticateLongSession();
    void shouldDeliverEDAMSystemExceptionInAuthenticateLongSession();
    void shouldDeliverThriftExceptionInAuthenticateLongSession();
    void shouldExecuteAuthenticateLongSessionAsync();
    void shouldDeliverEDAMUserExceptionInAuthenticateLongSessionAsync();
    void shouldDeliverEDAMSystemExceptionInAuthenticateLongSessionAsync();
    void shouldDeliverThriftExceptionInAuthenticateLongSessionAsync();
    void shouldExecuteCompleteTwoFactorAuthentication();
    void shouldDeliverEDAMUserExceptionInCompleteTwoFactorAuthentication();
    void shouldDeliverEDAMSystemExceptionInCompleteTwoFactorAuthentication();
    void shouldDeliverThriftExceptionInCompleteTwoFactorAuthentication();
    void shouldExecuteCompleteTwoFactorAuthenticationAsync();
    void shouldDeliverEDAMUserExceptionInCompleteTwoFactorAuthenticationAsync();
    void shouldDeliverEDAMSystemExceptionInCompleteTwoFactorAuthenticationAsync();
    void shouldDeliverThriftExceptionInCompleteTwoFactorAuthenticationAsync();
    void shouldExecuteRevokeLongSession();
    void shouldDeliverEDAMUserExceptionInRevokeLongSession();
    void shouldDeliverEDAMSystemExceptionInRevokeLongSession();
    void shouldDeliverThriftExceptionInRevokeLongSession();
    void shouldExecuteRevokeLongSessionAsync();
    void shouldDeliverEDAMUserExceptionInRevokeLongSessionAsync();
    void shouldDeliverEDAMSystemExceptionInRevokeLongSessionAsync();
    void shouldDeliverThriftExceptionInRevokeLongSessionAsync();
    void shouldExecuteAuthenticateToBusiness();
    void shouldDeliverEDAMUserExceptionInAuthenticateToBusiness();
    void shouldDeliverEDAMSystemExceptionInAuthenticateToBusiness();
    void shouldDeliverThriftExceptionInAuthenticateToBusiness();
    void shouldExecuteAuthenticateToBusinessAsync();
    void shouldDeliverEDAMUserExceptionInAuthenticateToBusinessAsync();
    void shouldDeliverEDAMSystemExceptionInAuthenticateToBusinessAsync();
    void shouldDeliverThriftExceptionInAuthenticateToBusinessAsync();
    void shouldExecuteGetUser();
    void shouldDeliverEDAMUserExceptionInGetUser();
    void shouldDeliverEDAMSystemExceptionInGetUser();
    void shouldDeliverThriftExceptionInGetUser();
    void shouldExecuteGetUserAsync();
    void shouldDeliverEDAMUserExceptionInGetUserAsync();
    void shouldDeliverEDAMSystemExceptionInGetUserAsync();
    void shouldDeliverThriftExceptionInGetUserAsync();
    void shouldExecuteGetPublicUserInfo();
    void shouldDeliverEDAMNotFoundExceptionInGetPublicUserInfo();
    void shouldDeliverEDAMSystemExceptionInGetPublicUserInfo();
    void shouldDeliverEDAMUserExceptionInGetPublicUserInfo();
    void shouldDeliverThriftExceptionInGetPublicUserInfo();
    void shouldExecuteGetPublicUserInfoAsync();
    void shouldDeliverEDAMNotFoundExceptionInGetPublicUserInfoAsync();
    void shouldDeliverEDAMSystemExceptionInGetPublicUserInfoAsync();
    void shouldDeliverEDAMUserExceptionInGetPublicUserInfoAsync();
    void shouldDeliverThriftExceptionInGetPublicUserInfoAsync();
    void shouldExecuteGetUserUrls();
    void shouldDeliverEDAMUserExceptionInGetUserUrls();
    void shouldDeliverEDAMSystemExceptionInGetUserUrls();
    void shouldDeliverThriftExceptionInGetUserUrls();
    void shouldExecuteGetUserUrlsAsync();
    void shouldDeliverEDAMUserExceptionInGetUserUrlsAsync();
    void shouldDeliverEDAMSystemExceptionInGetUserUrlsAsync();
    void shouldDeliverThriftExceptionInGetUserUrlsAsync();
    void shouldExecuteInviteToBusiness();
    void shouldDeliverEDAMUserExceptionInInviteToBusiness();
    void shouldDeliverEDAMSystemExceptionInInviteToBusiness();
    void shouldDeliverThriftExceptionInInviteToBusiness();
    void shouldExecuteInviteToBusinessAsync();
    void shouldDeliverEDAMUserExceptionInInviteToBusinessAsync();
    void shouldDeliverEDAMSystemExceptionInInviteToBusinessAsync();
    void shouldDeliverThriftExceptionInInviteToBusinessAsync();
    void shouldExecuteRemoveFromBusiness();
    void shouldDeliverEDAMUserExceptionInRemoveFromBusiness();
    void shouldDeliverEDAMSystemExceptionInRemoveFromBusiness();
    void shouldDeliverEDAMNotFoundExceptionInRemoveFromBusiness();
    void shouldDeliverThriftExceptionInRemoveFromBusiness();
    void shouldExecuteRemoveFromBusinessAsync();
    void shouldDeliverEDAMUserExceptionInRemoveFromBusinessAsync();
    void shouldDeliverEDAMSystemExceptionInRemoveFromBusinessAsync();
    void shouldDeliverEDAMNotFoundExceptionInRemoveFromBusinessAsync();
    void shouldDeliverThriftExceptionInRemoveFromBusinessAsync();
    void shouldExecuteUpdateBusinessUserIdentifier();
    void shouldDeliverEDAMUserExceptionInUpdateBusinessUserIdentifier();
    void shouldDeliverEDAMSystemExceptionInUpdateBusinessUserIdentifier();
    void shouldDeliverEDAMNotFoundExceptionInUpdateBusinessUserIdentifier();
    void shouldDeliverThriftExceptionInUpdateBusinessUserIdentifier();
    void shouldExecuteUpdateBusinessUserIdentifierAsync();
    void shouldDeliverEDAMUserExceptionInUpdateBusinessUserIdentifierAsync();
    void shouldDeliverEDAMSystemExceptionInUpdateBusinessUserIdentifierAsync();
    void shouldDeliverEDAMNotFoundExceptionInUpdateBusinessUserIdentifierAsync();
    void shouldDeliverThriftExceptionInUpdateBusinessUserIdentifierAsync();
    void shouldExecuteListBusinessUsers();
    void shouldDeliverEDAMUserExceptionInListBusinessUsers();
    void shouldDeliverEDAMSystemExceptionInListBusinessUsers();
    void shouldDeliverThriftExceptionInListBusinessUsers();
    void shouldExecuteListBusinessUsersAsync();
    void shouldDeliverEDAMUserExceptionInListBusinessUsersAsync();
    void shouldDeliverEDAMSystemExceptionInListBusinessUsersAsync();
    void shouldDeliverThriftExceptionInListBusinessUsersAsync();
    void shouldExecuteListBusinessInvitations();
    void shouldDeliverEDAMUserExceptionInListBusinessInvitations();
    void shouldDeliverEDAMSystemExceptionInListBusinessInvitations();
    void shouldDeliverThriftExceptionInListBusinessInvitations();
    void shouldExecuteListBusinessInvitationsAsync();
    void shouldDeliverEDAMUserExceptionInListBusinessInvitationsAsync();
    void shouldDeliverEDAMSystemExceptionInListBusinessInvitationsAsync();
    void shouldDeliverThriftExceptionInListBusinessInvitationsAsync();
    void shouldExecuteGetAccountLimits();
    void shouldDeliverEDAMUserExceptionInGetAccountLimits();
    void shouldDeliverThriftExceptionInGetAccountLimits();
    void shouldExecuteGetAccountLimitsAsync();
    void shouldDeliverEDAMUserExceptionInGetAccountLimitsAsync();
    void shouldDeliverThriftExceptionInGetAccountLimitsAsync();
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_TESTUSERSTORE_H
