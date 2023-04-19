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

#include "TestUserStore.h"
#include "../../Impl.h"
#include "../../HttpUtils.h"
#include "RandomDataGenerators.h"
#include <generated/Servers.h>
#include <generated/Services.h>
#include <QTcpServer>
#include <QtTest/QtTest>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

UserStoreTester::UserStoreTester(QObject * parent) :
    QObject(parent)
{}

////////////////////////////////////////////////////////////////////////////////

class UserStoreCheckVersionTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        bool(
            QString,
            qint16,
            qint16,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreCheckVersionTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void checkVersionRequestReady(
        bool value,
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onCheckVersionRequestReceived(
        QString clientName,
        qint16 edamVersionMajor,
        qint16 edamVersionMinor,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                clientName,
                edamVersionMajor,
                edamVersionMinor,
                ctx);

            Q_EMIT checkVersionRequestReady(
                v,
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT checkVersionRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetBootstrapInfoTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        BootstrapInfo(
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreGetBootstrapInfoTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getBootstrapInfoRequestReady(
        BootstrapInfo value,
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onGetBootstrapInfoRequestReceived(
        QString locale,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                locale,
                ctx);

            Q_EMIT getBootstrapInfoRequestReady(
                v,
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getBootstrapInfoRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreAuthenticateLongSessionTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        AuthenticationResult(
            QString,
            QString,
            QString,
            QString,
            QString,
            QString,
            bool,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreAuthenticateLongSessionTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void authenticateLongSessionRequestReady(
        AuthenticationResult value,
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onAuthenticateLongSessionRequestReceived(
        QString username,
        QString password,
        QString consumerKey,
        QString consumerSecret,
        QString deviceIdentifier,
        QString deviceDescription,
        bool supportsTwoFactor,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                username,
                password,
                consumerKey,
                consumerSecret,
                deviceIdentifier,
                deviceDescription,
                supportsTwoFactor,
                ctx);

            Q_EMIT authenticateLongSessionRequestReady(
                v,
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT authenticateLongSessionRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreCompleteTwoFactorAuthenticationTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        AuthenticationResult(
            QString,
            QString,
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreCompleteTwoFactorAuthenticationTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void completeTwoFactorAuthenticationRequestReady(
        AuthenticationResult value,
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onCompleteTwoFactorAuthenticationRequestReceived(
        QString oneTimeCode,
        QString deviceIdentifier,
        QString deviceDescription,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                oneTimeCode,
                deviceIdentifier,
                deviceDescription,
                ctx);

            Q_EMIT completeTwoFactorAuthenticationRequestReady(
                v,
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT completeTwoFactorAuthenticationRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreRevokeLongSessionTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        void(
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreRevokeLongSessionTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void revokeLongSessionRequestReady(
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onRevokeLongSessionRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            m_executor(
                ctx);

            Q_EMIT revokeLongSessionRequestReady(
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT revokeLongSessionRequestReady(
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreAuthenticateToBusinessTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        AuthenticationResult(
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreAuthenticateToBusinessTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void authenticateToBusinessRequestReady(
        AuthenticationResult value,
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onAuthenticateToBusinessRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT authenticateToBusinessRequestReady(
                v,
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT authenticateToBusinessRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetUserTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        User(
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreGetUserTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getUserRequestReady(
        User value,
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onGetUserRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT getUserRequestReady(
                v,
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getUserRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetPublicUserInfoTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        PublicUserInfo(
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreGetPublicUserInfoTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getPublicUserInfoRequestReady(
        PublicUserInfo value,
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onGetPublicUserInfoRequestReceived(
        QString username,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                username,
                ctx);

            Q_EMIT getPublicUserInfoRequestReady(
                v,
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getPublicUserInfoRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetUserUrlsTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        UserUrls(
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreGetUserUrlsTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getUserUrlsRequestReady(
        UserUrls value,
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onGetUserUrlsRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT getUserUrlsRequestReady(
                v,
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getUserUrlsRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreInviteToBusinessTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        void(
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreInviteToBusinessTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void inviteToBusinessRequestReady(
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onInviteToBusinessRequestReceived(
        QString emailAddress,
        IRequestContextPtr ctx)
    {
        try
        {
            m_executor(
                emailAddress,
                ctx);

            Q_EMIT inviteToBusinessRequestReady(
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT inviteToBusinessRequestReady(
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreRemoveFromBusinessTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        void(
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreRemoveFromBusinessTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void removeFromBusinessRequestReady(
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onRemoveFromBusinessRequestReceived(
        QString emailAddress,
        IRequestContextPtr ctx)
    {
        try
        {
            m_executor(
                emailAddress,
                ctx);

            Q_EMIT removeFromBusinessRequestReady(
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT removeFromBusinessRequestReady(
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreUpdateBusinessUserIdentifierTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        void(
            QString,
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreUpdateBusinessUserIdentifierTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void updateBusinessUserIdentifierRequestReady(
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onUpdateBusinessUserIdentifierRequestReceived(
        QString oldEmailAddress,
        QString newEmailAddress,
        IRequestContextPtr ctx)
    {
        try
        {
            m_executor(
                oldEmailAddress,
                newEmailAddress,
                ctx);

            Q_EMIT updateBusinessUserIdentifierRequestReady(
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT updateBusinessUserIdentifierRequestReady(
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreListBusinessUsersTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QList<UserProfile>(
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreListBusinessUsersTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void listBusinessUsersRequestReady(
        QList<UserProfile> value,
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onListBusinessUsersRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT listBusinessUsersRequestReady(
                v,
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT listBusinessUsersRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreListBusinessInvitationsTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QList<BusinessInvitation>(
            bool,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreListBusinessInvitationsTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void listBusinessInvitationsRequestReady(
        QList<BusinessInvitation> value,
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onListBusinessInvitationsRequestReceived(
        bool includeRequestedInvitations,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                includeRequestedInvitations,
                ctx);

            Q_EMIT listBusinessInvitationsRequestReady(
                v,
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT listBusinessInvitationsRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetAccountLimitsTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        AccountLimits(
            ServiceLevel,
            IRequestContextPtr ctx)>;

public:
    explicit UserStoreGetAccountLimitsTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getAccountLimitsRequestReady(
        AccountLimits value,
        EverCloudExceptionDataPtr exceptionData);

public Q_SLOTS:
    void onGetAccountLimitsRequestReceived(
        ServiceLevel serviceLevel,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                serviceLevel,
                ctx);

            Q_EMIT getAccountLimitsRequestReady(
                v,
                EverCloudExceptionDataPtr());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getAccountLimitsRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreCheckVersionAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreCheckVersionAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    bool m_value;
    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        m_value = qvariant_cast<bool>(value);
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetBootstrapInfoAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreGetBootstrapInfoAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    BootstrapInfo m_value;
    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        m_value = qvariant_cast<BootstrapInfo>(value);
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreAuthenticateLongSessionAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreAuthenticateLongSessionAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    AuthenticationResult m_value;
    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        m_value = qvariant_cast<AuthenticationResult>(value);
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreCompleteTwoFactorAuthenticationAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreCompleteTwoFactorAuthenticationAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    AuthenticationResult m_value;
    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        m_value = qvariant_cast<AuthenticationResult>(value);
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreRevokeLongSessionAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreRevokeLongSessionAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        Q_UNUSED(value)
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreAuthenticateToBusinessAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreAuthenticateToBusinessAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    AuthenticationResult m_value;
    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        m_value = qvariant_cast<AuthenticationResult>(value);
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetUserAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreGetUserAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    User m_value;
    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        m_value = qvariant_cast<User>(value);
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetPublicUserInfoAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreGetPublicUserInfoAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    PublicUserInfo m_value;
    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        m_value = qvariant_cast<PublicUserInfo>(value);
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetUserUrlsAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreGetUserUrlsAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    UserUrls m_value;
    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        m_value = qvariant_cast<UserUrls>(value);
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreInviteToBusinessAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreInviteToBusinessAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        Q_UNUSED(value)
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreRemoveFromBusinessAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreRemoveFromBusinessAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        Q_UNUSED(value)
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        Q_UNUSED(value)
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreListBusinessUsersAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreListBusinessUsersAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    QList<UserProfile> m_value;
    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        m_value = qvariant_cast<QList<UserProfile>>(value);
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreListBusinessInvitationsAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreListBusinessInvitationsAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    QList<BusinessInvitation> m_value;
    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        m_value = qvariant_cast<QList<BusinessInvitation>>(value);
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

class UserStoreGetAccountLimitsAsyncValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreGetAccountLimitsAsyncValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    AccountLimits m_value;
    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        m_value = qvariant_cast<AccountLimits>(value);
        Q_UNUSED(ctx)
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteCheckVersion()
{
    QString clientName = generateRandomString();
    qint16 edamVersionMajor = generateRandomInt16();
    qint16 edamVersionMinor = generateRandomInt16();
    IRequestContextPtr ctx = newRequestContext();

    bool response = generateRandomBool();

    UserStoreCheckVersionTesterHelper helper(
        [&] (const QString & clientNameParam,
             qint16 edamVersionMajorParam,
             qint16 edamVersionMinorParam,
             IRequestContextPtr ctxParam) -> bool
        {
            Q_ASSERT(clientName == clientNameParam);
            Q_ASSERT(edamVersionMajor == edamVersionMajorParam);
            Q_ASSERT(edamVersionMinor == edamVersionMinorParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::checkVersionRequest,
        &helper,
        &UserStoreCheckVersionTesterHelper::onCheckVersionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreCheckVersionTesterHelper::checkVersionRequestReady,
        &server,
        &UserStoreServer::onCheckVersionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::checkVersionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool res = userStore->checkVersion(
        clientName,
        edamVersionMajor,
        edamVersionMinor,
        ctx);
    QVERIFY(res == response);
}

void UserStoreTester::shouldDeliverThriftExceptionInCheckVersion()
{
    QString clientName = generateRandomString();
    qint16 edamVersionMajor = generateRandomInt16();
    qint16 edamVersionMinor = generateRandomInt16();
    IRequestContextPtr ctx = newRequestContext();

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreCheckVersionTesterHelper helper(
        [&] (const QString & clientNameParam,
             qint16 edamVersionMajorParam,
             qint16 edamVersionMinorParam,
             IRequestContextPtr ctxParam) -> bool
        {
            Q_ASSERT(clientName == clientNameParam);
            Q_ASSERT(edamVersionMajor == edamVersionMajorParam);
            Q_ASSERT(edamVersionMinor == edamVersionMinorParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::checkVersionRequest,
        &helper,
        &UserStoreCheckVersionTesterHelper::onCheckVersionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreCheckVersionTesterHelper::checkVersionRequestReady,
        &server,
        &UserStoreServer::onCheckVersionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::checkVersionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        bool res = userStore->checkVersion(
            clientName,
            edamVersionMajor,
            edamVersionMinor,
            ctx);
        Q_UNUSED(res)
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteCheckVersionAsync()
{
    QString clientName = generateRandomString();
    qint16 edamVersionMajor = generateRandomInt16();
    qint16 edamVersionMinor = generateRandomInt16();
    IRequestContextPtr ctx = newRequestContext();

    bool response = generateRandomBool();

    UserStoreCheckVersionTesterHelper helper(
        [&] (const QString & clientNameParam,
             qint16 edamVersionMajorParam,
             qint16 edamVersionMinorParam,
             IRequestContextPtr ctxParam) -> bool
        {
            Q_ASSERT(clientName == clientNameParam);
            Q_ASSERT(edamVersionMajor == edamVersionMajorParam);
            Q_ASSERT(edamVersionMinor == edamVersionMinorParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::checkVersionRequest,
        &helper,
        &UserStoreCheckVersionTesterHelper::onCheckVersionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreCheckVersionTesterHelper::checkVersionRequestReady,
        &server,
        &UserStoreServer::onCheckVersionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::checkVersionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->checkVersionAsync(
        clientName,
        edamVersionMajor,
        edamVersionMinor,
        ctx);

    UserStoreCheckVersionAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreCheckVersionAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreCheckVersionAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_value == response);
    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverThriftExceptionInCheckVersionAsync()
{
    QString clientName = generateRandomString();
    qint16 edamVersionMajor = generateRandomInt16();
    qint16 edamVersionMinor = generateRandomInt16();
    IRequestContextPtr ctx = newRequestContext();

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreCheckVersionTesterHelper helper(
        [&] (const QString & clientNameParam,
             qint16 edamVersionMajorParam,
             qint16 edamVersionMinorParam,
             IRequestContextPtr ctxParam) -> bool
        {
            Q_ASSERT(clientName == clientNameParam);
            Q_ASSERT(edamVersionMajor == edamVersionMajorParam);
            Q_ASSERT(edamVersionMinor == edamVersionMinorParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::checkVersionRequest,
        &helper,
        &UserStoreCheckVersionTesterHelper::onCheckVersionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreCheckVersionTesterHelper::checkVersionRequestReady,
        &server,
        &UserStoreServer::onCheckVersionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::checkVersionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->checkVersionAsync(
            clientName,
            edamVersionMajor,
            edamVersionMinor,
            ctx);

        UserStoreCheckVersionAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreCheckVersionAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreCheckVersionAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetBootstrapInfo()
{
    QString locale = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    BootstrapInfo response = generateRandomBootstrapInfo();

    UserStoreGetBootstrapInfoTesterHelper helper(
        [&] (const QString & localeParam,
             IRequestContextPtr ctxParam) -> BootstrapInfo
        {
            Q_ASSERT(locale == localeParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getBootstrapInfoRequest,
        &helper,
        &UserStoreGetBootstrapInfoTesterHelper::onGetBootstrapInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetBootstrapInfoTesterHelper::getBootstrapInfoRequestReady,
        &server,
        &UserStoreServer::onGetBootstrapInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getBootstrapInfoRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    BootstrapInfo res = userStore->getBootstrapInfo(
        locale,
        ctx);
    QVERIFY(res == response);
}

void UserStoreTester::shouldDeliverThriftExceptionInGetBootstrapInfo()
{
    QString locale = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreGetBootstrapInfoTesterHelper helper(
        [&] (const QString & localeParam,
             IRequestContextPtr ctxParam) -> BootstrapInfo
        {
            Q_ASSERT(locale == localeParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getBootstrapInfoRequest,
        &helper,
        &UserStoreGetBootstrapInfoTesterHelper::onGetBootstrapInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetBootstrapInfoTesterHelper::getBootstrapInfoRequestReady,
        &server,
        &UserStoreServer::onGetBootstrapInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getBootstrapInfoRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        BootstrapInfo res = userStore->getBootstrapInfo(
            locale,
            ctx);
        Q_UNUSED(res)
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteGetBootstrapInfoAsync()
{
    QString locale = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    BootstrapInfo response = generateRandomBootstrapInfo();

    UserStoreGetBootstrapInfoTesterHelper helper(
        [&] (const QString & localeParam,
             IRequestContextPtr ctxParam) -> BootstrapInfo
        {
            Q_ASSERT(locale == localeParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getBootstrapInfoRequest,
        &helper,
        &UserStoreGetBootstrapInfoTesterHelper::onGetBootstrapInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetBootstrapInfoTesterHelper::getBootstrapInfoRequestReady,
        &server,
        &UserStoreServer::onGetBootstrapInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getBootstrapInfoRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->getBootstrapInfoAsync(
        locale,
        ctx);

    UserStoreGetBootstrapInfoAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreGetBootstrapInfoAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreGetBootstrapInfoAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_value == response);
    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverThriftExceptionInGetBootstrapInfoAsync()
{
    QString locale = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreGetBootstrapInfoTesterHelper helper(
        [&] (const QString & localeParam,
             IRequestContextPtr ctxParam) -> BootstrapInfo
        {
            Q_ASSERT(locale == localeParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getBootstrapInfoRequest,
        &helper,
        &UserStoreGetBootstrapInfoTesterHelper::onGetBootstrapInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetBootstrapInfoTesterHelper::getBootstrapInfoRequestReady,
        &server,
        &UserStoreServer::onGetBootstrapInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getBootstrapInfoRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->getBootstrapInfoAsync(
            locale,
            ctx);

        UserStoreGetBootstrapInfoAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreGetBootstrapInfoAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreGetBootstrapInfoAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteAuthenticateLongSession()
{
    QString username = generateRandomString();
    QString password = generateRandomString();
    QString consumerKey = generateRandomString();
    QString consumerSecret = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    bool supportsTwoFactor = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext();

    AuthenticationResult response = generateRandomAuthenticationResult();

    UserStoreAuthenticateLongSessionTesterHelper helper(
        [&] (const QString & usernameParam,
             const QString & passwordParam,
             const QString & consumerKeyParam,
             const QString & consumerSecretParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             bool supportsTwoFactorParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(username == usernameParam);
            Q_ASSERT(password == passwordParam);
            Q_ASSERT(consumerKey == consumerKeyParam);
            Q_ASSERT(consumerSecret == consumerSecretParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            Q_ASSERT(supportsTwoFactor == supportsTwoFactorParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequest,
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::onAuthenticateLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::authenticateLongSessionRequestReady,
        &server,
        &UserStoreServer::onAuthenticateLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AuthenticationResult res = userStore->authenticateLongSession(
        username,
        password,
        consumerKey,
        consumerSecret,
        deviceIdentifier,
        deviceDescription,
        supportsTwoFactor,
        ctx);
    QVERIFY(res == response);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInAuthenticateLongSession()
{
    QString username = generateRandomString();
    QString password = generateRandomString();
    QString consumerKey = generateRandomString();
    QString consumerSecret = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    bool supportsTwoFactor = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext();

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::UNSUPPORTED_OPERATION;
    userException.parameter = generateRandomString();

    UserStoreAuthenticateLongSessionTesterHelper helper(
        [&] (const QString & usernameParam,
             const QString & passwordParam,
             const QString & consumerKeyParam,
             const QString & consumerSecretParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             bool supportsTwoFactorParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(username == usernameParam);
            Q_ASSERT(password == passwordParam);
            Q_ASSERT(consumerKey == consumerKeyParam);
            Q_ASSERT(consumerSecret == consumerSecretParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            Q_ASSERT(supportsTwoFactor == supportsTwoFactorParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequest,
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::onAuthenticateLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::authenticateLongSessionRequestReady,
        &server,
        &UserStoreServer::onAuthenticateLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = userStore->authenticateLongSession(
            username,
            password,
            consumerKey,
            consumerSecret,
            deviceIdentifier,
            deviceDescription,
            supportsTwoFactor,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInAuthenticateLongSession()
{
    QString username = generateRandomString();
    QString password = generateRandomString();
    QString consumerKey = generateRandomString();
    QString consumerSecret = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    bool supportsTwoFactor = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext();

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::LEN_TOO_LONG;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreAuthenticateLongSessionTesterHelper helper(
        [&] (const QString & usernameParam,
             const QString & passwordParam,
             const QString & consumerKeyParam,
             const QString & consumerSecretParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             bool supportsTwoFactorParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(username == usernameParam);
            Q_ASSERT(password == passwordParam);
            Q_ASSERT(consumerKey == consumerKeyParam);
            Q_ASSERT(consumerSecret == consumerSecretParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            Q_ASSERT(supportsTwoFactor == supportsTwoFactorParam);
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequest,
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::onAuthenticateLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::authenticateLongSessionRequestReady,
        &server,
        &UserStoreServer::onAuthenticateLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = userStore->authenticateLongSession(
            username,
            password,
            consumerKey,
            consumerSecret,
            deviceIdentifier,
            deviceDescription,
            supportsTwoFactor,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInAuthenticateLongSession()
{
    QString username = generateRandomString();
    QString password = generateRandomString();
    QString consumerKey = generateRandomString();
    QString consumerSecret = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    bool supportsTwoFactor = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext();

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreAuthenticateLongSessionTesterHelper helper(
        [&] (const QString & usernameParam,
             const QString & passwordParam,
             const QString & consumerKeyParam,
             const QString & consumerSecretParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             bool supportsTwoFactorParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(username == usernameParam);
            Q_ASSERT(password == passwordParam);
            Q_ASSERT(consumerKey == consumerKeyParam);
            Q_ASSERT(consumerSecret == consumerSecretParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            Q_ASSERT(supportsTwoFactor == supportsTwoFactorParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequest,
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::onAuthenticateLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::authenticateLongSessionRequestReady,
        &server,
        &UserStoreServer::onAuthenticateLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = userStore->authenticateLongSession(
            username,
            password,
            consumerKey,
            consumerSecret,
            deviceIdentifier,
            deviceDescription,
            supportsTwoFactor,
            ctx);
        Q_UNUSED(res)
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteAuthenticateLongSessionAsync()
{
    QString username = generateRandomString();
    QString password = generateRandomString();
    QString consumerKey = generateRandomString();
    QString consumerSecret = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    bool supportsTwoFactor = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext();

    AuthenticationResult response = generateRandomAuthenticationResult();

    UserStoreAuthenticateLongSessionTesterHelper helper(
        [&] (const QString & usernameParam,
             const QString & passwordParam,
             const QString & consumerKeyParam,
             const QString & consumerSecretParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             bool supportsTwoFactorParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(username == usernameParam);
            Q_ASSERT(password == passwordParam);
            Q_ASSERT(consumerKey == consumerKeyParam);
            Q_ASSERT(consumerSecret == consumerSecretParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            Q_ASSERT(supportsTwoFactor == supportsTwoFactorParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequest,
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::onAuthenticateLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::authenticateLongSessionRequestReady,
        &server,
        &UserStoreServer::onAuthenticateLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->authenticateLongSessionAsync(
        username,
        password,
        consumerKey,
        consumerSecret,
        deviceIdentifier,
        deviceDescription,
        supportsTwoFactor,
        ctx);

    UserStoreAuthenticateLongSessionAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreAuthenticateLongSessionAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreAuthenticateLongSessionAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_value == response);
    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInAuthenticateLongSessionAsync()
{
    QString username = generateRandomString();
    QString password = generateRandomString();
    QString consumerKey = generateRandomString();
    QString consumerSecret = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    bool supportsTwoFactor = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext();

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::ENML_VALIDATION;
    userException.parameter = generateRandomString();

    UserStoreAuthenticateLongSessionTesterHelper helper(
        [&] (const QString & usernameParam,
             const QString & passwordParam,
             const QString & consumerKeyParam,
             const QString & consumerSecretParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             bool supportsTwoFactorParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(username == usernameParam);
            Q_ASSERT(password == passwordParam);
            Q_ASSERT(consumerKey == consumerKeyParam);
            Q_ASSERT(consumerSecret == consumerSecretParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            Q_ASSERT(supportsTwoFactor == supportsTwoFactorParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequest,
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::onAuthenticateLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::authenticateLongSessionRequestReady,
        &server,
        &UserStoreServer::onAuthenticateLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->authenticateLongSessionAsync(
            username,
            password,
            consumerKey,
            consumerSecret,
            deviceIdentifier,
            deviceDescription,
            supportsTwoFactor,
            ctx);

        UserStoreAuthenticateLongSessionAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreAuthenticateLongSessionAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreAuthenticateLongSessionAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInAuthenticateLongSessionAsync()
{
    QString username = generateRandomString();
    QString password = generateRandomString();
    QString consumerKey = generateRandomString();
    QString consumerSecret = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    bool supportsTwoFactor = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext();

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreAuthenticateLongSessionTesterHelper helper(
        [&] (const QString & usernameParam,
             const QString & passwordParam,
             const QString & consumerKeyParam,
             const QString & consumerSecretParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             bool supportsTwoFactorParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(username == usernameParam);
            Q_ASSERT(password == passwordParam);
            Q_ASSERT(consumerKey == consumerKeyParam);
            Q_ASSERT(consumerSecret == consumerSecretParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            Q_ASSERT(supportsTwoFactor == supportsTwoFactorParam);
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequest,
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::onAuthenticateLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::authenticateLongSessionRequestReady,
        &server,
        &UserStoreServer::onAuthenticateLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->authenticateLongSessionAsync(
            username,
            password,
            consumerKey,
            consumerSecret,
            deviceIdentifier,
            deviceDescription,
            supportsTwoFactor,
            ctx);

        UserStoreAuthenticateLongSessionAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreAuthenticateLongSessionAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreAuthenticateLongSessionAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInAuthenticateLongSessionAsync()
{
    QString username = generateRandomString();
    QString password = generateRandomString();
    QString consumerKey = generateRandomString();
    QString consumerSecret = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    bool supportsTwoFactor = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext();

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreAuthenticateLongSessionTesterHelper helper(
        [&] (const QString & usernameParam,
             const QString & passwordParam,
             const QString & consumerKeyParam,
             const QString & consumerSecretParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             bool supportsTwoFactorParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(username == usernameParam);
            Q_ASSERT(password == passwordParam);
            Q_ASSERT(consumerKey == consumerKeyParam);
            Q_ASSERT(consumerSecret == consumerSecretParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            Q_ASSERT(supportsTwoFactor == supportsTwoFactorParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequest,
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::onAuthenticateLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateLongSessionTesterHelper::authenticateLongSessionRequestReady,
        &server,
        &UserStoreServer::onAuthenticateLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->authenticateLongSessionAsync(
            username,
            password,
            consumerKey,
            consumerSecret,
            deviceIdentifier,
            deviceDescription,
            supportsTwoFactor,
            ctx);

        UserStoreAuthenticateLongSessionAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreAuthenticateLongSessionAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreAuthenticateLongSessionAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteCompleteTwoFactorAuthentication()
{
    QString oneTimeCode = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    AuthenticationResult response = generateRandomAuthenticationResult();

    UserStoreCompleteTwoFactorAuthenticationTesterHelper helper(
        [&] (const QString & oneTimeCodeParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oneTimeCode == oneTimeCodeParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequest,
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::onCompleteTwoFactorAuthenticationRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::completeTwoFactorAuthenticationRequestReady,
        &server,
        &UserStoreServer::onCompleteTwoFactorAuthenticationRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AuthenticationResult res = userStore->completeTwoFactorAuthentication(
        oneTimeCode,
        deviceIdentifier,
        deviceDescription,
        ctx);
    QVERIFY(res == response);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInCompleteTwoFactorAuthentication()
{
    QString oneTimeCode = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::UNKNOWN;
    userException.parameter = generateRandomString();

    UserStoreCompleteTwoFactorAuthenticationTesterHelper helper(
        [&] (const QString & oneTimeCodeParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oneTimeCode == oneTimeCodeParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequest,
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::onCompleteTwoFactorAuthenticationRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::completeTwoFactorAuthenticationRequestReady,
        &server,
        &UserStoreServer::onCompleteTwoFactorAuthenticationRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = userStore->completeTwoFactorAuthentication(
            oneTimeCode,
            deviceIdentifier,
            deviceDescription,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInCompleteTwoFactorAuthentication()
{
    QString oneTimeCode = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::TOO_MANY;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreCompleteTwoFactorAuthenticationTesterHelper helper(
        [&] (const QString & oneTimeCodeParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oneTimeCode == oneTimeCodeParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequest,
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::onCompleteTwoFactorAuthenticationRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::completeTwoFactorAuthenticationRequestReady,
        &server,
        &UserStoreServer::onCompleteTwoFactorAuthenticationRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = userStore->completeTwoFactorAuthentication(
            oneTimeCode,
            deviceIdentifier,
            deviceDescription,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInCompleteTwoFactorAuthentication()
{
    QString oneTimeCode = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreCompleteTwoFactorAuthenticationTesterHelper helper(
        [&] (const QString & oneTimeCodeParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oneTimeCode == oneTimeCodeParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequest,
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::onCompleteTwoFactorAuthenticationRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::completeTwoFactorAuthenticationRequestReady,
        &server,
        &UserStoreServer::onCompleteTwoFactorAuthenticationRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = userStore->completeTwoFactorAuthentication(
            oneTimeCode,
            deviceIdentifier,
            deviceDescription,
            ctx);
        Q_UNUSED(res)
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteCompleteTwoFactorAuthenticationAsync()
{
    QString oneTimeCode = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    AuthenticationResult response = generateRandomAuthenticationResult();

    UserStoreCompleteTwoFactorAuthenticationTesterHelper helper(
        [&] (const QString & oneTimeCodeParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oneTimeCode == oneTimeCodeParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequest,
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::onCompleteTwoFactorAuthenticationRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::completeTwoFactorAuthenticationRequestReady,
        &server,
        &UserStoreServer::onCompleteTwoFactorAuthenticationRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->completeTwoFactorAuthenticationAsync(
        oneTimeCode,
        deviceIdentifier,
        deviceDescription,
        ctx);

    UserStoreCompleteTwoFactorAuthenticationAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreCompleteTwoFactorAuthenticationAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreCompleteTwoFactorAuthenticationAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_value == response);
    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInCompleteTwoFactorAuthenticationAsync()
{
    QString oneTimeCode = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::LEN_TOO_LONG;
    userException.parameter = generateRandomString();

    UserStoreCompleteTwoFactorAuthenticationTesterHelper helper(
        [&] (const QString & oneTimeCodeParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oneTimeCode == oneTimeCodeParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequest,
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::onCompleteTwoFactorAuthenticationRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::completeTwoFactorAuthenticationRequestReady,
        &server,
        &UserStoreServer::onCompleteTwoFactorAuthenticationRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->completeTwoFactorAuthenticationAsync(
            oneTimeCode,
            deviceIdentifier,
            deviceDescription,
            ctx);

        UserStoreCompleteTwoFactorAuthenticationAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreCompleteTwoFactorAuthenticationAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreCompleteTwoFactorAuthenticationAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInCompleteTwoFactorAuthenticationAsync()
{
    QString oneTimeCode = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::PERMISSION_DENIED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreCompleteTwoFactorAuthenticationTesterHelper helper(
        [&] (const QString & oneTimeCodeParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oneTimeCode == oneTimeCodeParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequest,
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::onCompleteTwoFactorAuthenticationRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::completeTwoFactorAuthenticationRequestReady,
        &server,
        &UserStoreServer::onCompleteTwoFactorAuthenticationRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->completeTwoFactorAuthenticationAsync(
            oneTimeCode,
            deviceIdentifier,
            deviceDescription,
            ctx);

        UserStoreCompleteTwoFactorAuthenticationAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreCompleteTwoFactorAuthenticationAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreCompleteTwoFactorAuthenticationAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInCompleteTwoFactorAuthenticationAsync()
{
    QString oneTimeCode = generateRandomString();
    QString deviceIdentifier = generateRandomString();
    QString deviceDescription = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreCompleteTwoFactorAuthenticationTesterHelper helper(
        [&] (const QString & oneTimeCodeParam,
             const QString & deviceIdentifierParam,
             const QString & deviceDescriptionParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oneTimeCode == oneTimeCodeParam);
            Q_ASSERT(deviceIdentifier == deviceIdentifierParam);
            Q_ASSERT(deviceDescription == deviceDescriptionParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequest,
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::onCompleteTwoFactorAuthenticationRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreCompleteTwoFactorAuthenticationTesterHelper::completeTwoFactorAuthenticationRequestReady,
        &server,
        &UserStoreServer::onCompleteTwoFactorAuthenticationRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::completeTwoFactorAuthenticationRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->completeTwoFactorAuthenticationAsync(
            oneTimeCode,
            deviceIdentifier,
            deviceDescription,
            ctx);

        UserStoreCompleteTwoFactorAuthenticationAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreCompleteTwoFactorAuthenticationAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreCompleteTwoFactorAuthenticationAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteRevokeLongSession()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserStoreRevokeLongSessionTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequest,
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::onRevokeLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::revokeLongSessionRequestReady,
        &server,
        &UserStoreServer::onRevokeLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    userStore->revokeLongSession(
        ctx);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInRevokeLongSession()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::DATA_REQUIRED;
    userException.parameter = generateRandomString();

    UserStoreRevokeLongSessionTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequest,
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::onRevokeLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::revokeLongSessionRequestReady,
        &server,
        &UserStoreServer::onRevokeLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        userStore->revokeLongSession(
            ctx);
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInRevokeLongSession()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::TOO_MANY;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreRevokeLongSessionTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequest,
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::onRevokeLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::revokeLongSessionRequestReady,
        &server,
        &UserStoreServer::onRevokeLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        userStore->revokeLongSession(
            ctx);
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInRevokeLongSession()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreRevokeLongSessionTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequest,
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::onRevokeLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::revokeLongSessionRequestReady,
        &server,
        &UserStoreServer::onRevokeLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        userStore->revokeLongSession(
            ctx);
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteRevokeLongSessionAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserStoreRevokeLongSessionTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequest,
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::onRevokeLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::revokeLongSessionRequestReady,
        &server,
        &UserStoreServer::onRevokeLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->revokeLongSessionAsync(
        ctx);

    UserStoreRevokeLongSessionAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreRevokeLongSessionAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreRevokeLongSessionAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInRevokeLongSessionAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::ENML_VALIDATION;
    userException.parameter = generateRandomString();

    UserStoreRevokeLongSessionTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequest,
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::onRevokeLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::revokeLongSessionRequestReady,
        &server,
        &UserStoreServer::onRevokeLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->revokeLongSessionAsync(
            ctx);

        UserStoreRevokeLongSessionAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreRevokeLongSessionAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreRevokeLongSessionAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInRevokeLongSessionAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::INTERNAL_ERROR;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreRevokeLongSessionTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequest,
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::onRevokeLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::revokeLongSessionRequestReady,
        &server,
        &UserStoreServer::onRevokeLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->revokeLongSessionAsync(
            ctx);

        UserStoreRevokeLongSessionAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreRevokeLongSessionAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreRevokeLongSessionAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInRevokeLongSessionAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreRevokeLongSessionTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequest,
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::onRevokeLongSessionRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRevokeLongSessionTesterHelper::revokeLongSessionRequestReady,
        &server,
        &UserStoreServer::onRevokeLongSessionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::revokeLongSessionRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->revokeLongSessionAsync(
            ctx);

        UserStoreRevokeLongSessionAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreRevokeLongSessionAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreRevokeLongSessionAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteAuthenticateToBusiness()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    AuthenticationResult response = generateRandomAuthenticationResult();

    UserStoreAuthenticateToBusinessTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequest,
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::onAuthenticateToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::authenticateToBusinessRequestReady,
        &server,
        &UserStoreServer::onAuthenticateToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AuthenticationResult res = userStore->authenticateToBusiness(
        ctx);
    QVERIFY(res == response);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInAuthenticateToBusiness()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::LIMIT_REACHED;
    userException.parameter = generateRandomString();

    UserStoreAuthenticateToBusinessTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequest,
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::onAuthenticateToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::authenticateToBusinessRequestReady,
        &server,
        &UserStoreServer::onAuthenticateToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = userStore->authenticateToBusiness(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInAuthenticateToBusiness()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::UNKNOWN;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreAuthenticateToBusinessTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequest,
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::onAuthenticateToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::authenticateToBusinessRequestReady,
        &server,
        &UserStoreServer::onAuthenticateToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = userStore->authenticateToBusiness(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInAuthenticateToBusiness()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreAuthenticateToBusinessTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequest,
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::onAuthenticateToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::authenticateToBusinessRequestReady,
        &server,
        &UserStoreServer::onAuthenticateToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = userStore->authenticateToBusiness(
            ctx);
        Q_UNUSED(res)
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteAuthenticateToBusinessAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    AuthenticationResult response = generateRandomAuthenticationResult();

    UserStoreAuthenticateToBusinessTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequest,
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::onAuthenticateToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::authenticateToBusinessRequestReady,
        &server,
        &UserStoreServer::onAuthenticateToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->authenticateToBusinessAsync(
        ctx);

    UserStoreAuthenticateToBusinessAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreAuthenticateToBusinessAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreAuthenticateToBusinessAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_value == response);
    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInAuthenticateToBusinessAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::TOO_MANY;
    userException.parameter = generateRandomString();

    UserStoreAuthenticateToBusinessTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequest,
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::onAuthenticateToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::authenticateToBusinessRequestReady,
        &server,
        &UserStoreServer::onAuthenticateToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->authenticateToBusinessAsync(
            ctx);

        UserStoreAuthenticateToBusinessAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreAuthenticateToBusinessAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreAuthenticateToBusinessAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInAuthenticateToBusinessAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DEVICE_LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreAuthenticateToBusinessTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequest,
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::onAuthenticateToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::authenticateToBusinessRequestReady,
        &server,
        &UserStoreServer::onAuthenticateToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->authenticateToBusinessAsync(
            ctx);

        UserStoreAuthenticateToBusinessAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreAuthenticateToBusinessAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreAuthenticateToBusinessAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInAuthenticateToBusinessAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreAuthenticateToBusinessTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequest,
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::onAuthenticateToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreAuthenticateToBusinessTesterHelper::authenticateToBusinessRequestReady,
        &server,
        &UserStoreServer::onAuthenticateToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::authenticateToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->authenticateToBusinessAsync(
            ctx);

        UserStoreAuthenticateToBusinessAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreAuthenticateToBusinessAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreAuthenticateToBusinessAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetUser()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    User response = generateRandomUser();

    UserStoreGetUserTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> User
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserRequest,
        &helper,
        &UserStoreGetUserTesterHelper::onGetUserRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserTesterHelper::getUserRequestReady,
        &server,
        &UserStoreServer::onGetUserRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    User res = userStore->getUser(
        ctx);
    QVERIFY(res == response);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInGetUser()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::USER_ALREADY_ASSOCIATED;
    userException.parameter = generateRandomString();

    UserStoreGetUserTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> User
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserRequest,
        &helper,
        &UserStoreGetUserTesterHelper::onGetUserRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserTesterHelper::getUserRequestReady,
        &server,
        &UserStoreServer::onGetUserRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        User res = userStore->getUser(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInGetUser()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DATA_CONFLICT;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreGetUserTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> User
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserRequest,
        &helper,
        &UserStoreGetUserTesterHelper::onGetUserRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserTesterHelper::getUserRequestReady,
        &server,
        &UserStoreServer::onGetUserRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        User res = userStore->getUser(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInGetUser()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreGetUserTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> User
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserRequest,
        &helper,
        &UserStoreGetUserTesterHelper::onGetUserRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserTesterHelper::getUserRequestReady,
        &server,
        &UserStoreServer::onGetUserRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        User res = userStore->getUser(
            ctx);
        Q_UNUSED(res)
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteGetUserAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    User response = generateRandomUser();

    UserStoreGetUserTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> User
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserRequest,
        &helper,
        &UserStoreGetUserTesterHelper::onGetUserRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserTesterHelper::getUserRequestReady,
        &server,
        &UserStoreServer::onGetUserRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->getUserAsync(
        ctx);

    UserStoreGetUserAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreGetUserAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreGetUserAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_value == response);
    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInGetUserAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::RATE_LIMIT_REACHED;
    userException.parameter = generateRandomString();

    UserStoreGetUserTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> User
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserRequest,
        &helper,
        &UserStoreGetUserTesterHelper::onGetUserRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserTesterHelper::getUserRequestReady,
        &server,
        &UserStoreServer::onGetUserRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->getUserAsync(
            ctx);

        UserStoreGetUserAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreGetUserAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreGetUserAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInGetUserAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DATA_REQUIRED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreGetUserTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> User
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserRequest,
        &helper,
        &UserStoreGetUserTesterHelper::onGetUserRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserTesterHelper::getUserRequestReady,
        &server,
        &UserStoreServer::onGetUserRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->getUserAsync(
            ctx);

        UserStoreGetUserAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreGetUserAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreGetUserAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInGetUserAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreGetUserTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> User
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserRequest,
        &helper,
        &UserStoreGetUserTesterHelper::onGetUserRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserTesterHelper::getUserRequestReady,
        &server,
        &UserStoreServer::onGetUserRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->getUserAsync(
            ctx);

        UserStoreGetUserAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreGetUserAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreGetUserAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetPublicUserInfo()
{
    QString username = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    PublicUserInfo response = generateRandomPublicUserInfo();

    UserStoreGetPublicUserInfoTesterHelper helper(
        [&] (const QString & usernameParam,
             IRequestContextPtr ctxParam) -> PublicUserInfo
        {
            Q_ASSERT(username == usernameParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequest,
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::onGetPublicUserInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::getPublicUserInfoRequestReady,
        &server,
        &UserStoreServer::onGetPublicUserInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    PublicUserInfo res = userStore->getPublicUserInfo(
        username,
        ctx);
    QVERIFY(res == response);
}

void UserStoreTester::shouldDeliverEDAMNotFoundExceptionInGetPublicUserInfo()
{
    QString username = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    UserStoreGetPublicUserInfoTesterHelper helper(
        [&] (const QString & usernameParam,
             IRequestContextPtr ctxParam) -> PublicUserInfo
        {
            Q_ASSERT(username == usernameParam);
            throw notFoundException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequest,
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::onGetPublicUserInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::getPublicUserInfoRequestReady,
        &server,
        &UserStoreServer::onGetPublicUserInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        PublicUserInfo res = userStore->getPublicUserInfo(
            username,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInGetPublicUserInfo()
{
    QString username = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DEVICE_LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreGetPublicUserInfoTesterHelper helper(
        [&] (const QString & usernameParam,
             IRequestContextPtr ctxParam) -> PublicUserInfo
        {
            Q_ASSERT(username == usernameParam);
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequest,
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::onGetPublicUserInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::getPublicUserInfoRequestReady,
        &server,
        &UserStoreServer::onGetPublicUserInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        PublicUserInfo res = userStore->getPublicUserInfo(
            username,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInGetPublicUserInfo()
{
    QString username = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::RATE_LIMIT_REACHED;
    userException.parameter = generateRandomString();

    UserStoreGetPublicUserInfoTesterHelper helper(
        [&] (const QString & usernameParam,
             IRequestContextPtr ctxParam) -> PublicUserInfo
        {
            Q_ASSERT(username == usernameParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequest,
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::onGetPublicUserInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::getPublicUserInfoRequestReady,
        &server,
        &UserStoreServer::onGetPublicUserInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        PublicUserInfo res = userStore->getPublicUserInfo(
            username,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInGetPublicUserInfo()
{
    QString username = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreGetPublicUserInfoTesterHelper helper(
        [&] (const QString & usernameParam,
             IRequestContextPtr ctxParam) -> PublicUserInfo
        {
            Q_ASSERT(username == usernameParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequest,
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::onGetPublicUserInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::getPublicUserInfoRequestReady,
        &server,
        &UserStoreServer::onGetPublicUserInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        PublicUserInfo res = userStore->getPublicUserInfo(
            username,
            ctx);
        Q_UNUSED(res)
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteGetPublicUserInfoAsync()
{
    QString username = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    PublicUserInfo response = generateRandomPublicUserInfo();

    UserStoreGetPublicUserInfoTesterHelper helper(
        [&] (const QString & usernameParam,
             IRequestContextPtr ctxParam) -> PublicUserInfo
        {
            Q_ASSERT(username == usernameParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequest,
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::onGetPublicUserInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::getPublicUserInfoRequestReady,
        &server,
        &UserStoreServer::onGetPublicUserInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->getPublicUserInfoAsync(
        username,
        ctx);

    UserStoreGetPublicUserInfoAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreGetPublicUserInfoAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreGetPublicUserInfoAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_value == response);
    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverEDAMNotFoundExceptionInGetPublicUserInfoAsync()
{
    QString username = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    UserStoreGetPublicUserInfoTesterHelper helper(
        [&] (const QString & usernameParam,
             IRequestContextPtr ctxParam) -> PublicUserInfo
        {
            Q_ASSERT(username == usernameParam);
            throw notFoundException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequest,
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::onGetPublicUserInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::getPublicUserInfoRequestReady,
        &server,
        &UserStoreServer::onGetPublicUserInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->getPublicUserInfoAsync(
            username,
            ctx);

        UserStoreGetPublicUserInfoAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreGetPublicUserInfoAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreGetPublicUserInfoAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInGetPublicUserInfoAsync()
{
    QString username = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::RATE_LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreGetPublicUserInfoTesterHelper helper(
        [&] (const QString & usernameParam,
             IRequestContextPtr ctxParam) -> PublicUserInfo
        {
            Q_ASSERT(username == usernameParam);
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequest,
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::onGetPublicUserInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::getPublicUserInfoRequestReady,
        &server,
        &UserStoreServer::onGetPublicUserInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->getPublicUserInfoAsync(
            username,
            ctx);

        UserStoreGetPublicUserInfoAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreGetPublicUserInfoAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreGetPublicUserInfoAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInGetPublicUserInfoAsync()
{
    QString username = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::SHARD_UNAVAILABLE;
    userException.parameter = generateRandomString();

    UserStoreGetPublicUserInfoTesterHelper helper(
        [&] (const QString & usernameParam,
             IRequestContextPtr ctxParam) -> PublicUserInfo
        {
            Q_ASSERT(username == usernameParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequest,
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::onGetPublicUserInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::getPublicUserInfoRequestReady,
        &server,
        &UserStoreServer::onGetPublicUserInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->getPublicUserInfoAsync(
            username,
            ctx);

        UserStoreGetPublicUserInfoAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreGetPublicUserInfoAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreGetPublicUserInfoAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInGetPublicUserInfoAsync()
{
    QString username = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreGetPublicUserInfoTesterHelper helper(
        [&] (const QString & usernameParam,
             IRequestContextPtr ctxParam) -> PublicUserInfo
        {
            Q_ASSERT(username == usernameParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequest,
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::onGetPublicUserInfoRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetPublicUserInfoTesterHelper::getPublicUserInfoRequestReady,
        &server,
        &UserStoreServer::onGetPublicUserInfoRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getPublicUserInfoRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->getPublicUserInfoAsync(
            username,
            ctx);

        UserStoreGetPublicUserInfoAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreGetPublicUserInfoAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreGetPublicUserInfoAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetUserUrls()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserUrls response = generateRandomUserUrls();

    UserStoreGetUserUrlsTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> UserUrls
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequest,
        &helper,
        &UserStoreGetUserUrlsTesterHelper::onGetUserUrlsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserUrlsTesterHelper::getUserUrlsRequestReady,
        &server,
        &UserStoreServer::onGetUserUrlsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    UserUrls res = userStore->getUserUrls(
        ctx);
    QVERIFY(res == response);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInGetUserUrls()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::UNKNOWN;
    userException.parameter = generateRandomString();

    UserStoreGetUserUrlsTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> UserUrls
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequest,
        &helper,
        &UserStoreGetUserUrlsTesterHelper::onGetUserUrlsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserUrlsTesterHelper::getUserUrlsRequestReady,
        &server,
        &UserStoreServer::onGetUserUrlsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        UserUrls res = userStore->getUserUrls(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInGetUserUrls()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::LEN_TOO_LONG;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreGetUserUrlsTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> UserUrls
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequest,
        &helper,
        &UserStoreGetUserUrlsTesterHelper::onGetUserUrlsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserUrlsTesterHelper::getUserUrlsRequestReady,
        &server,
        &UserStoreServer::onGetUserUrlsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        UserUrls res = userStore->getUserUrls(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInGetUserUrls()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreGetUserUrlsTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> UserUrls
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequest,
        &helper,
        &UserStoreGetUserUrlsTesterHelper::onGetUserUrlsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserUrlsTesterHelper::getUserUrlsRequestReady,
        &server,
        &UserStoreServer::onGetUserUrlsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        UserUrls res = userStore->getUserUrls(
            ctx);
        Q_UNUSED(res)
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteGetUserUrlsAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserUrls response = generateRandomUserUrls();

    UserStoreGetUserUrlsTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> UserUrls
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequest,
        &helper,
        &UserStoreGetUserUrlsTesterHelper::onGetUserUrlsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserUrlsTesterHelper::getUserUrlsRequestReady,
        &server,
        &UserStoreServer::onGetUserUrlsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->getUserUrlsAsync(
        ctx);

    UserStoreGetUserUrlsAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreGetUserUrlsAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreGetUserUrlsAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_value == response);
    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInGetUserUrlsAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::UNSUPPORTED_OPERATION;
    userException.parameter = generateRandomString();

    UserStoreGetUserUrlsTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> UserUrls
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequest,
        &helper,
        &UserStoreGetUserUrlsTesterHelper::onGetUserUrlsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserUrlsTesterHelper::getUserUrlsRequestReady,
        &server,
        &UserStoreServer::onGetUserUrlsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->getUserUrlsAsync(
            ctx);

        UserStoreGetUserUrlsAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreGetUserUrlsAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreGetUserUrlsAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInGetUserUrlsAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreGetUserUrlsTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> UserUrls
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequest,
        &helper,
        &UserStoreGetUserUrlsTesterHelper::onGetUserUrlsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserUrlsTesterHelper::getUserUrlsRequestReady,
        &server,
        &UserStoreServer::onGetUserUrlsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->getUserUrlsAsync(
            ctx);

        UserStoreGetUserUrlsAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreGetUserUrlsAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreGetUserUrlsAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInGetUserUrlsAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreGetUserUrlsTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> UserUrls
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequest,
        &helper,
        &UserStoreGetUserUrlsTesterHelper::onGetUserUrlsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetUserUrlsTesterHelper::getUserUrlsRequestReady,
        &server,
        &UserStoreServer::onGetUserUrlsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getUserUrlsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->getUserUrlsAsync(
            ctx);

        UserStoreGetUserUrlsAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreGetUserUrlsAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreGetUserUrlsAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteInviteToBusiness()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserStoreInviteToBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            return;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequest,
        &helper,
        &UserStoreInviteToBusinessTesterHelper::onInviteToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreInviteToBusinessTesterHelper::inviteToBusinessRequestReady,
        &server,
        &UserStoreServer::onInviteToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    userStore->inviteToBusiness(
        emailAddress,
        ctx);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInInviteToBusiness()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::TAKEN_DOWN;
    userException.parameter = generateRandomString();

    UserStoreInviteToBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequest,
        &helper,
        &UserStoreInviteToBusinessTesterHelper::onInviteToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreInviteToBusinessTesterHelper::inviteToBusinessRequestReady,
        &server,
        &UserStoreServer::onInviteToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        userStore->inviteToBusiness(
            emailAddress,
            ctx);
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInInviteToBusiness()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DEVICE_LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreInviteToBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequest,
        &helper,
        &UserStoreInviteToBusinessTesterHelper::onInviteToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreInviteToBusinessTesterHelper::inviteToBusinessRequestReady,
        &server,
        &UserStoreServer::onInviteToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        userStore->inviteToBusiness(
            emailAddress,
            ctx);
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInInviteToBusiness()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreInviteToBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequest,
        &helper,
        &UserStoreInviteToBusinessTesterHelper::onInviteToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreInviteToBusinessTesterHelper::inviteToBusinessRequestReady,
        &server,
        &UserStoreServer::onInviteToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        userStore->inviteToBusiness(
            emailAddress,
            ctx);
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteInviteToBusinessAsync()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserStoreInviteToBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            return;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequest,
        &helper,
        &UserStoreInviteToBusinessTesterHelper::onInviteToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreInviteToBusinessTesterHelper::inviteToBusinessRequestReady,
        &server,
        &UserStoreServer::onInviteToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->inviteToBusinessAsync(
        emailAddress,
        ctx);

    UserStoreInviteToBusinessAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreInviteToBusinessAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreInviteToBusinessAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInInviteToBusinessAsync()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::TOO_FEW;
    userException.parameter = generateRandomString();

    UserStoreInviteToBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequest,
        &helper,
        &UserStoreInviteToBusinessTesterHelper::onInviteToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreInviteToBusinessTesterHelper::inviteToBusinessRequestReady,
        &server,
        &UserStoreServer::onInviteToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->inviteToBusinessAsync(
            emailAddress,
            ctx);

        UserStoreInviteToBusinessAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreInviteToBusinessAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreInviteToBusinessAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInInviteToBusinessAsync()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreInviteToBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequest,
        &helper,
        &UserStoreInviteToBusinessTesterHelper::onInviteToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreInviteToBusinessTesterHelper::inviteToBusinessRequestReady,
        &server,
        &UserStoreServer::onInviteToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->inviteToBusinessAsync(
            emailAddress,
            ctx);

        UserStoreInviteToBusinessAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreInviteToBusinessAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreInviteToBusinessAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInInviteToBusinessAsync()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreInviteToBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequest,
        &helper,
        &UserStoreInviteToBusinessTesterHelper::onInviteToBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreInviteToBusinessTesterHelper::inviteToBusinessRequestReady,
        &server,
        &UserStoreServer::onInviteToBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::inviteToBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->inviteToBusinessAsync(
            emailAddress,
            ctx);

        UserStoreInviteToBusinessAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreInviteToBusinessAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreInviteToBusinessAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteRemoveFromBusiness()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserStoreRemoveFromBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            return;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequest,
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::onRemoveFromBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::removeFromBusinessRequestReady,
        &server,
        &UserStoreServer::onRemoveFromBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    userStore->removeFromBusiness(
        emailAddress,
        ctx);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInRemoveFromBusiness()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::LIMIT_REACHED;
    userException.parameter = generateRandomString();

    UserStoreRemoveFromBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequest,
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::onRemoveFromBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::removeFromBusinessRequestReady,
        &server,
        &UserStoreServer::onRemoveFromBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        userStore->removeFromBusiness(
            emailAddress,
            ctx);
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInRemoveFromBusiness()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::USER_ALREADY_ASSOCIATED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreRemoveFromBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequest,
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::onRemoveFromBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::removeFromBusinessRequestReady,
        &server,
        &UserStoreServer::onRemoveFromBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        userStore->removeFromBusiness(
            emailAddress,
            ctx);
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMNotFoundExceptionInRemoveFromBusiness()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    UserStoreRemoveFromBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            throw notFoundException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequest,
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::onRemoveFromBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::removeFromBusinessRequestReady,
        &server,
        &UserStoreServer::onRemoveFromBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        userStore->removeFromBusiness(
            emailAddress,
            ctx);
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInRemoveFromBusiness()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreRemoveFromBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequest,
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::onRemoveFromBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::removeFromBusinessRequestReady,
        &server,
        &UserStoreServer::onRemoveFromBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        userStore->removeFromBusiness(
            emailAddress,
            ctx);
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteRemoveFromBusinessAsync()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserStoreRemoveFromBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            return;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequest,
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::onRemoveFromBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::removeFromBusinessRequestReady,
        &server,
        &UserStoreServer::onRemoveFromBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->removeFromBusinessAsync(
        emailAddress,
        ctx);

    UserStoreRemoveFromBusinessAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreRemoveFromBusinessAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreRemoveFromBusinessAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInRemoveFromBusinessAsync()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::ENML_VALIDATION;
    userException.parameter = generateRandomString();

    UserStoreRemoveFromBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequest,
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::onRemoveFromBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::removeFromBusinessRequestReady,
        &server,
        &UserStoreServer::onRemoveFromBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->removeFromBusinessAsync(
            emailAddress,
            ctx);

        UserStoreRemoveFromBusinessAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreRemoveFromBusinessAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreRemoveFromBusinessAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInRemoveFromBusinessAsync()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreRemoveFromBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequest,
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::onRemoveFromBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::removeFromBusinessRequestReady,
        &server,
        &UserStoreServer::onRemoveFromBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->removeFromBusinessAsync(
            emailAddress,
            ctx);

        UserStoreRemoveFromBusinessAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreRemoveFromBusinessAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreRemoveFromBusinessAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMNotFoundExceptionInRemoveFromBusinessAsync()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    UserStoreRemoveFromBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            throw notFoundException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequest,
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::onRemoveFromBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::removeFromBusinessRequestReady,
        &server,
        &UserStoreServer::onRemoveFromBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->removeFromBusinessAsync(
            emailAddress,
            ctx);

        UserStoreRemoveFromBusinessAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreRemoveFromBusinessAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreRemoveFromBusinessAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInRemoveFromBusinessAsync()
{
    QString emailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreRemoveFromBusinessTesterHelper helper(
        [&] (const QString & emailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(emailAddress == emailAddressParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequest,
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::onRemoveFromBusinessRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreRemoveFromBusinessTesterHelper::removeFromBusinessRequestReady,
        &server,
        &UserStoreServer::onRemoveFromBusinessRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::removeFromBusinessRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->removeFromBusinessAsync(
            emailAddress,
            ctx);

        UserStoreRemoveFromBusinessAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreRemoveFromBusinessAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreRemoveFromBusinessAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteUpdateBusinessUserIdentifier()
{
    QString oldEmailAddress = generateRandomString();
    QString newEmailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserStoreUpdateBusinessUserIdentifierTesterHelper helper(
        [&] (const QString & oldEmailAddressParam,
             const QString & newEmailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oldEmailAddress == oldEmailAddressParam);
            Q_ASSERT(newEmailAddress == newEmailAddressParam);
            return;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequest,
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::onUpdateBusinessUserIdentifierRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::updateBusinessUserIdentifierRequestReady,
        &server,
        &UserStoreServer::onUpdateBusinessUserIdentifierRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    userStore->updateBusinessUserIdentifier(
        oldEmailAddress,
        newEmailAddress,
        ctx);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInUpdateBusinessUserIdentifier()
{
    QString oldEmailAddress = generateRandomString();
    QString newEmailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::LEN_TOO_SHORT;
    userException.parameter = generateRandomString();

    UserStoreUpdateBusinessUserIdentifierTesterHelper helper(
        [&] (const QString & oldEmailAddressParam,
             const QString & newEmailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oldEmailAddress == oldEmailAddressParam);
            Q_ASSERT(newEmailAddress == newEmailAddressParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequest,
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::onUpdateBusinessUserIdentifierRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::updateBusinessUserIdentifierRequestReady,
        &server,
        &UserStoreServer::onUpdateBusinessUserIdentifierRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        userStore->updateBusinessUserIdentifier(
            oldEmailAddress,
            newEmailAddress,
            ctx);
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInUpdateBusinessUserIdentifier()
{
    QString oldEmailAddress = generateRandomString();
    QString newEmailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::INVALID_AUTH;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreUpdateBusinessUserIdentifierTesterHelper helper(
        [&] (const QString & oldEmailAddressParam,
             const QString & newEmailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oldEmailAddress == oldEmailAddressParam);
            Q_ASSERT(newEmailAddress == newEmailAddressParam);
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequest,
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::onUpdateBusinessUserIdentifierRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::updateBusinessUserIdentifierRequestReady,
        &server,
        &UserStoreServer::onUpdateBusinessUserIdentifierRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        userStore->updateBusinessUserIdentifier(
            oldEmailAddress,
            newEmailAddress,
            ctx);
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMNotFoundExceptionInUpdateBusinessUserIdentifier()
{
    QString oldEmailAddress = generateRandomString();
    QString newEmailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    UserStoreUpdateBusinessUserIdentifierTesterHelper helper(
        [&] (const QString & oldEmailAddressParam,
             const QString & newEmailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oldEmailAddress == oldEmailAddressParam);
            Q_ASSERT(newEmailAddress == newEmailAddressParam);
            throw notFoundException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequest,
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::onUpdateBusinessUserIdentifierRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::updateBusinessUserIdentifierRequestReady,
        &server,
        &UserStoreServer::onUpdateBusinessUserIdentifierRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        userStore->updateBusinessUserIdentifier(
            oldEmailAddress,
            newEmailAddress,
            ctx);
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInUpdateBusinessUserIdentifier()
{
    QString oldEmailAddress = generateRandomString();
    QString newEmailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreUpdateBusinessUserIdentifierTesterHelper helper(
        [&] (const QString & oldEmailAddressParam,
             const QString & newEmailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oldEmailAddress == oldEmailAddressParam);
            Q_ASSERT(newEmailAddress == newEmailAddressParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequest,
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::onUpdateBusinessUserIdentifierRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::updateBusinessUserIdentifierRequestReady,
        &server,
        &UserStoreServer::onUpdateBusinessUserIdentifierRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        userStore->updateBusinessUserIdentifier(
            oldEmailAddress,
            newEmailAddress,
            ctx);
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteUpdateBusinessUserIdentifierAsync()
{
    QString oldEmailAddress = generateRandomString();
    QString newEmailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UserStoreUpdateBusinessUserIdentifierTesterHelper helper(
        [&] (const QString & oldEmailAddressParam,
             const QString & newEmailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oldEmailAddress == oldEmailAddressParam);
            Q_ASSERT(newEmailAddress == newEmailAddressParam);
            return;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequest,
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::onUpdateBusinessUserIdentifierRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::updateBusinessUserIdentifierRequestReady,
        &server,
        &UserStoreServer::onUpdateBusinessUserIdentifierRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->updateBusinessUserIdentifierAsync(
        oldEmailAddress,
        newEmailAddress,
        ctx);

    UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInUpdateBusinessUserIdentifierAsync()
{
    QString oldEmailAddress = generateRandomString();
    QString newEmailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::DEVICE_LIMIT_REACHED;
    userException.parameter = generateRandomString();

    UserStoreUpdateBusinessUserIdentifierTesterHelper helper(
        [&] (const QString & oldEmailAddressParam,
             const QString & newEmailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oldEmailAddress == oldEmailAddressParam);
            Q_ASSERT(newEmailAddress == newEmailAddressParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequest,
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::onUpdateBusinessUserIdentifierRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::updateBusinessUserIdentifierRequestReady,
        &server,
        &UserStoreServer::onUpdateBusinessUserIdentifierRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->updateBusinessUserIdentifierAsync(
            oldEmailAddress,
            newEmailAddress,
            ctx);

        UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInUpdateBusinessUserIdentifierAsync()
{
    QString oldEmailAddress = generateRandomString();
    QString newEmailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::UNKNOWN;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreUpdateBusinessUserIdentifierTesterHelper helper(
        [&] (const QString & oldEmailAddressParam,
             const QString & newEmailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oldEmailAddress == oldEmailAddressParam);
            Q_ASSERT(newEmailAddress == newEmailAddressParam);
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequest,
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::onUpdateBusinessUserIdentifierRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::updateBusinessUserIdentifierRequestReady,
        &server,
        &UserStoreServer::onUpdateBusinessUserIdentifierRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->updateBusinessUserIdentifierAsync(
            oldEmailAddress,
            newEmailAddress,
            ctx);

        UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMNotFoundExceptionInUpdateBusinessUserIdentifierAsync()
{
    QString oldEmailAddress = generateRandomString();
    QString newEmailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    UserStoreUpdateBusinessUserIdentifierTesterHelper helper(
        [&] (const QString & oldEmailAddressParam,
             const QString & newEmailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oldEmailAddress == oldEmailAddressParam);
            Q_ASSERT(newEmailAddress == newEmailAddressParam);
            throw notFoundException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequest,
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::onUpdateBusinessUserIdentifierRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::updateBusinessUserIdentifierRequestReady,
        &server,
        &UserStoreServer::onUpdateBusinessUserIdentifierRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->updateBusinessUserIdentifierAsync(
            oldEmailAddress,
            newEmailAddress,
            ctx);

        UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInUpdateBusinessUserIdentifierAsync()
{
    QString oldEmailAddress = generateRandomString();
    QString newEmailAddress = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreUpdateBusinessUserIdentifierTesterHelper helper(
        [&] (const QString & oldEmailAddressParam,
             const QString & newEmailAddressParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(oldEmailAddress == oldEmailAddressParam);
            Q_ASSERT(newEmailAddress == newEmailAddressParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequest,
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::onUpdateBusinessUserIdentifierRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreUpdateBusinessUserIdentifierTesterHelper::updateBusinessUserIdentifierRequestReady,
        &server,
        &UserStoreServer::onUpdateBusinessUserIdentifierRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::updateBusinessUserIdentifierRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->updateBusinessUserIdentifierAsync(
            oldEmailAddress,
            newEmailAddress,
            ctx);

        UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreUpdateBusinessUserIdentifierAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteListBusinessUsers()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QList<UserProfile> response;
    response << generateRandomUserProfile();
    response << generateRandomUserProfile();
    response << generateRandomUserProfile();

    UserStoreListBusinessUsersTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<UserProfile>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequest,
        &helper,
        &UserStoreListBusinessUsersTesterHelper::onListBusinessUsersRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessUsersTesterHelper::listBusinessUsersRequestReady,
        &server,
        &UserStoreServer::onListBusinessUsersRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    QList<UserProfile> res = userStore->listBusinessUsers(
        ctx);
    QVERIFY(res == response);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInListBusinessUsers()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::INVALID_OPENID_TOKEN;
    userException.parameter = generateRandomString();

    UserStoreListBusinessUsersTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<UserProfile>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequest,
        &helper,
        &UserStoreListBusinessUsersTesterHelper::onListBusinessUsersRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessUsersTesterHelper::listBusinessUsersRequestReady,
        &server,
        &UserStoreServer::onListBusinessUsersRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        QList<UserProfile> res = userStore->listBusinessUsers(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInListBusinessUsers()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::PERMISSION_DENIED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreListBusinessUsersTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<UserProfile>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequest,
        &helper,
        &UserStoreListBusinessUsersTesterHelper::onListBusinessUsersRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessUsersTesterHelper::listBusinessUsersRequestReady,
        &server,
        &UserStoreServer::onListBusinessUsersRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        QList<UserProfile> res = userStore->listBusinessUsers(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInListBusinessUsers()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreListBusinessUsersTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<UserProfile>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequest,
        &helper,
        &UserStoreListBusinessUsersTesterHelper::onListBusinessUsersRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessUsersTesterHelper::listBusinessUsersRequestReady,
        &server,
        &UserStoreServer::onListBusinessUsersRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        QList<UserProfile> res = userStore->listBusinessUsers(
            ctx);
        Q_UNUSED(res)
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteListBusinessUsersAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QList<UserProfile> response;
    response << generateRandomUserProfile();
    response << generateRandomUserProfile();
    response << generateRandomUserProfile();

    UserStoreListBusinessUsersTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<UserProfile>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequest,
        &helper,
        &UserStoreListBusinessUsersTesterHelper::onListBusinessUsersRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessUsersTesterHelper::listBusinessUsersRequestReady,
        &server,
        &UserStoreServer::onListBusinessUsersRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->listBusinessUsersAsync(
        ctx);

    UserStoreListBusinessUsersAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreListBusinessUsersAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreListBusinessUsersAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_value == response);
    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInListBusinessUsersAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::INTERNAL_ERROR;
    userException.parameter = generateRandomString();

    UserStoreListBusinessUsersTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<UserProfile>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequest,
        &helper,
        &UserStoreListBusinessUsersTesterHelper::onListBusinessUsersRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessUsersTesterHelper::listBusinessUsersRequestReady,
        &server,
        &UserStoreServer::onListBusinessUsersRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->listBusinessUsersAsync(
            ctx);

        UserStoreListBusinessUsersAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreListBusinessUsersAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreListBusinessUsersAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInListBusinessUsersAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreListBusinessUsersTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<UserProfile>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequest,
        &helper,
        &UserStoreListBusinessUsersTesterHelper::onListBusinessUsersRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessUsersTesterHelper::listBusinessUsersRequestReady,
        &server,
        &UserStoreServer::onListBusinessUsersRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->listBusinessUsersAsync(
            ctx);

        UserStoreListBusinessUsersAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreListBusinessUsersAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreListBusinessUsersAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInListBusinessUsersAsync()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreListBusinessUsersTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<UserProfile>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequest,
        &helper,
        &UserStoreListBusinessUsersTesterHelper::onListBusinessUsersRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessUsersTesterHelper::listBusinessUsersRequestReady,
        &server,
        &UserStoreServer::onListBusinessUsersRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessUsersRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->listBusinessUsersAsync(
            ctx);

        UserStoreListBusinessUsersAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreListBusinessUsersAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreListBusinessUsersAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteListBusinessInvitations()
{
    bool includeRequestedInvitations = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QList<BusinessInvitation> response;
    response << generateRandomBusinessInvitation();
    response << generateRandomBusinessInvitation();
    response << generateRandomBusinessInvitation();

    UserStoreListBusinessInvitationsTesterHelper helper(
        [&] (bool includeRequestedInvitationsParam,
             IRequestContextPtr ctxParam) -> QList<BusinessInvitation>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(includeRequestedInvitations == includeRequestedInvitationsParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequest,
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::onListBusinessInvitationsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::listBusinessInvitationsRequestReady,
        &server,
        &UserStoreServer::onListBusinessInvitationsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    QList<BusinessInvitation> res = userStore->listBusinessInvitations(
        includeRequestedInvitations,
        ctx);
    QVERIFY(res == response);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInListBusinessInvitations()
{
    bool includeRequestedInvitations = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::TOO_FEW;
    userException.parameter = generateRandomString();

    UserStoreListBusinessInvitationsTesterHelper helper(
        [&] (bool includeRequestedInvitationsParam,
             IRequestContextPtr ctxParam) -> QList<BusinessInvitation>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(includeRequestedInvitations == includeRequestedInvitationsParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequest,
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::onListBusinessInvitationsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::listBusinessInvitationsRequestReady,
        &server,
        &UserStoreServer::onListBusinessInvitationsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        QList<BusinessInvitation> res = userStore->listBusinessInvitations(
            includeRequestedInvitations,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInListBusinessInvitations()
{
    bool includeRequestedInvitations = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreListBusinessInvitationsTesterHelper helper(
        [&] (bool includeRequestedInvitationsParam,
             IRequestContextPtr ctxParam) -> QList<BusinessInvitation>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(includeRequestedInvitations == includeRequestedInvitationsParam);
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequest,
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::onListBusinessInvitationsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::listBusinessInvitationsRequestReady,
        &server,
        &UserStoreServer::onListBusinessInvitationsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        QList<BusinessInvitation> res = userStore->listBusinessInvitations(
            includeRequestedInvitations,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInListBusinessInvitations()
{
    bool includeRequestedInvitations = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreListBusinessInvitationsTesterHelper helper(
        [&] (bool includeRequestedInvitationsParam,
             IRequestContextPtr ctxParam) -> QList<BusinessInvitation>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(includeRequestedInvitations == includeRequestedInvitationsParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequest,
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::onListBusinessInvitationsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::listBusinessInvitationsRequestReady,
        &server,
        &UserStoreServer::onListBusinessInvitationsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        QList<BusinessInvitation> res = userStore->listBusinessInvitations(
            includeRequestedInvitations,
            ctx);
        Q_UNUSED(res)
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteListBusinessInvitationsAsync()
{
    bool includeRequestedInvitations = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QList<BusinessInvitation> response;
    response << generateRandomBusinessInvitation();
    response << generateRandomBusinessInvitation();
    response << generateRandomBusinessInvitation();

    UserStoreListBusinessInvitationsTesterHelper helper(
        [&] (bool includeRequestedInvitationsParam,
             IRequestContextPtr ctxParam) -> QList<BusinessInvitation>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(includeRequestedInvitations == includeRequestedInvitationsParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequest,
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::onListBusinessInvitationsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::listBusinessInvitationsRequestReady,
        &server,
        &UserStoreServer::onListBusinessInvitationsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->listBusinessInvitationsAsync(
        includeRequestedInvitations,
        ctx);

    UserStoreListBusinessInvitationsAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreListBusinessInvitationsAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreListBusinessInvitationsAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_value == response);
    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInListBusinessInvitationsAsync()
{
    bool includeRequestedInvitations = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED;
    userException.parameter = generateRandomString();

    UserStoreListBusinessInvitationsTesterHelper helper(
        [&] (bool includeRequestedInvitationsParam,
             IRequestContextPtr ctxParam) -> QList<BusinessInvitation>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(includeRequestedInvitations == includeRequestedInvitationsParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequest,
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::onListBusinessInvitationsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::listBusinessInvitationsRequestReady,
        &server,
        &UserStoreServer::onListBusinessInvitationsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->listBusinessInvitationsAsync(
            includeRequestedInvitations,
            ctx);

        UserStoreListBusinessInvitationsAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreListBusinessInvitationsAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreListBusinessInvitationsAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverEDAMSystemExceptionInListBusinessInvitationsAsync()
{
    bool includeRequestedInvitations = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::LEN_TOO_SHORT;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    UserStoreListBusinessInvitationsTesterHelper helper(
        [&] (bool includeRequestedInvitationsParam,
             IRequestContextPtr ctxParam) -> QList<BusinessInvitation>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(includeRequestedInvitations == includeRequestedInvitationsParam);
            throw systemException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequest,
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::onListBusinessInvitationsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::listBusinessInvitationsRequestReady,
        &server,
        &UserStoreServer::onListBusinessInvitationsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->listBusinessInvitationsAsync(
            includeRequestedInvitations,
            ctx);

        UserStoreListBusinessInvitationsAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreListBusinessInvitationsAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreListBusinessInvitationsAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInListBusinessInvitationsAsync()
{
    bool includeRequestedInvitations = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreListBusinessInvitationsTesterHelper helper(
        [&] (bool includeRequestedInvitationsParam,
             IRequestContextPtr ctxParam) -> QList<BusinessInvitation>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(includeRequestedInvitations == includeRequestedInvitationsParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequest,
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::onListBusinessInvitationsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreListBusinessInvitationsTesterHelper::listBusinessInvitationsRequestReady,
        &server,
        &UserStoreServer::onListBusinessInvitationsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::listBusinessInvitationsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->listBusinessInvitationsAsync(
            includeRequestedInvitations,
            ctx);

        UserStoreListBusinessInvitationsAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreListBusinessInvitationsAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreListBusinessInvitationsAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void UserStoreTester::shouldExecuteGetAccountLimits()
{
    ServiceLevel serviceLevel = ServiceLevel::BASIC;
    IRequestContextPtr ctx = newRequestContext();

    AccountLimits response = generateRandomAccountLimits();

    UserStoreGetAccountLimitsTesterHelper helper(
        [&] (const ServiceLevel & serviceLevelParam,
             IRequestContextPtr ctxParam) -> AccountLimits
        {
            Q_ASSERT(serviceLevel == serviceLevelParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getAccountLimitsRequest,
        &helper,
        &UserStoreGetAccountLimitsTesterHelper::onGetAccountLimitsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetAccountLimitsTesterHelper::getAccountLimitsRequestReady,
        &server,
        &UserStoreServer::onGetAccountLimitsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getAccountLimitsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AccountLimits res = userStore->getAccountLimits(
        serviceLevel,
        ctx);
    QVERIFY(res == response);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInGetAccountLimits()
{
    ServiceLevel serviceLevel = ServiceLevel::PREMIUM;
    IRequestContextPtr ctx = newRequestContext();

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::UNKNOWN;
    userException.parameter = generateRandomString();

    UserStoreGetAccountLimitsTesterHelper helper(
        [&] (const ServiceLevel & serviceLevelParam,
             IRequestContextPtr ctxParam) -> AccountLimits
        {
            Q_ASSERT(serviceLevel == serviceLevelParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getAccountLimitsRequest,
        &helper,
        &UserStoreGetAccountLimitsTesterHelper::onGetAccountLimitsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetAccountLimitsTesterHelper::getAccountLimitsRequestReady,
        &server,
        &UserStoreServer::onGetAccountLimitsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getAccountLimitsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AccountLimits res = userStore->getAccountLimits(
            serviceLevel,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInGetAccountLimits()
{
    ServiceLevel serviceLevel = ServiceLevel::BASIC;
    IRequestContextPtr ctx = newRequestContext();

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreGetAccountLimitsTesterHelper helper(
        [&] (const ServiceLevel & serviceLevelParam,
             IRequestContextPtr ctxParam) -> AccountLimits
        {
            Q_ASSERT(serviceLevel == serviceLevelParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getAccountLimitsRequest,
        &helper,
        &UserStoreGetAccountLimitsTesterHelper::onGetAccountLimitsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetAccountLimitsTesterHelper::getAccountLimitsRequestReady,
        &server,
        &UserStoreServer::onGetAccountLimitsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getAccountLimitsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AccountLimits res = userStore->getAccountLimits(
            serviceLevel,
            ctx);
        Q_UNUSED(res)
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldExecuteGetAccountLimitsAsync()
{
    ServiceLevel serviceLevel = ServiceLevel::BASIC;
    IRequestContextPtr ctx = newRequestContext();

    AccountLimits response = generateRandomAccountLimits();

    UserStoreGetAccountLimitsTesterHelper helper(
        [&] (const ServiceLevel & serviceLevelParam,
             IRequestContextPtr ctxParam) -> AccountLimits
        {
            Q_ASSERT(serviceLevel == serviceLevelParam);
            return response;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getAccountLimitsRequest,
        &helper,
        &UserStoreGetAccountLimitsTesterHelper::onGetAccountLimitsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetAccountLimitsTesterHelper::getAccountLimitsRequestReady,
        &server,
        &UserStoreServer::onGetAccountLimitsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getAccountLimitsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    AsyncResult * result = userStore->getAccountLimitsAsync(
        serviceLevel,
        ctx);

    UserStoreGetAccountLimitsAsyncValueFetcher valueFetcher;
    QObject::connect(
        result,
        &AsyncResult::finished,
        &valueFetcher,
        &UserStoreGetAccountLimitsAsyncValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(
        &valueFetcher,
        &UserStoreGetAccountLimitsAsyncValueFetcher::finished,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    QVERIFY(valueFetcher.m_value == response);
    QVERIFY(valueFetcher.m_exceptionData.get() == nullptr);
}

void UserStoreTester::shouldDeliverEDAMUserExceptionInGetAccountLimitsAsync()
{
    ServiceLevel serviceLevel = ServiceLevel::PREMIUM;
    IRequestContextPtr ctx = newRequestContext();

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::UNSUPPORTED_OPERATION;
    userException.parameter = generateRandomString();

    UserStoreGetAccountLimitsTesterHelper helper(
        [&] (const ServiceLevel & serviceLevelParam,
             IRequestContextPtr ctxParam) -> AccountLimits
        {
            Q_ASSERT(serviceLevel == serviceLevelParam);
            throw userException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getAccountLimitsRequest,
        &helper,
        &UserStoreGetAccountLimitsTesterHelper::onGetAccountLimitsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetAccountLimitsTesterHelper::getAccountLimitsRequestReady,
        &server,
        &UserStoreServer::onGetAccountLimitsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getAccountLimitsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->getAccountLimitsAsync(
            serviceLevel,
            ctx);

        UserStoreGetAccountLimitsAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreGetAccountLimitsAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreGetAccountLimitsAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void UserStoreTester::shouldDeliverThriftExceptionInGetAccountLimitsAsync()
{
    ServiceLevel serviceLevel = ServiceLevel::BASIC;
    IRequestContextPtr ctx = newRequestContext();

    auto thriftException = ThriftException(
        ThriftException::Type::INTERNAL_ERROR,
        QStringLiteral("Internal error"));

    UserStoreGetAccountLimitsTesterHelper helper(
        [&] (const ServiceLevel & serviceLevelParam,
             IRequestContextPtr ctxParam) -> AccountLimits
        {
            Q_ASSERT(serviceLevel == serviceLevelParam);
            throw thriftException;
        });

    UserStoreServer server;
    QObject::connect(
        &server,
        &UserStoreServer::getAccountLimitsRequest,
        &helper,
        &UserStoreGetAccountLimitsTesterHelper::onGetAccountLimitsRequestReceived);
    QObject::connect(
        &helper,
        &UserStoreGetAccountLimitsTesterHelper::getAccountLimitsRequestReady,
        &server,
        &UserStoreServer::onGetAccountLimitsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        &tcpServer,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readRequestBodyFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &UserStoreServer::getAccountLimitsRequestReady,
        &server,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    std::unique_ptr<IUserStore> userStore(
        newUserStore(
            QStringLiteral("http://127.0.0.1:") + QString::number(port),
            nullptr,
            nullptr,
            nullRetryPolicy()));
    bool caughtException = false;
    try
    {
        AsyncResult * result = userStore->getAccountLimitsAsync(
            serviceLevel,
            ctx);

        UserStoreGetAccountLimitsAsyncValueFetcher valueFetcher;
        QObject::connect(
            result,
            &AsyncResult::finished,
            &valueFetcher,
            &UserStoreGetAccountLimitsAsyncValueFetcher::onFinished);

        QEventLoop loop;
        QObject::connect(
            &valueFetcher,
            &UserStoreGetAccountLimitsAsyncValueFetcher::finished,
            &loop,
            &QEventLoop::quit);

        loop.exec();

        QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const ThriftException & e)
    {
        caughtException = true;
        QVERIFY(e == thriftException);
    }

    QVERIFY(caughtException);
}

} // namespace qevercloud

#include <TestUserStore.moc>
