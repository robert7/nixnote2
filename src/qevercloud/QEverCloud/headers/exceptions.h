/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_EXCEPTIONS_H
#define QEVERCLOUD_EXCEPTIONS_H

#include "Optional.h"
#include "export.h"
#include "EverCloudException.h"
#include "generated/EDAMErrorCode.h"
#include "generated/types.h"
#include <QString>
#include <QObject>
#include <QSharedPointer>

namespace qevercloud {

/**
 * Errors of the Thrift protocol level. It could be wrongly formatted parameters
 * or return values for example.
 */
class QEVERCLOUD_EXPORT ThriftException: public EverCloudException
{
public:
    struct Type {
        enum type {
            UNKNOWN = 0,
            UNKNOWN_METHOD = 1,
            INVALID_MESSAGE_TYPE = 2,
            WRONG_METHOD_NAME = 3,
            BAD_SEQUENCE_ID = 4,
            MISSING_RESULT = 5,
            INTERNAL_ERROR = 6,
            PROTOCOL_ERROR = 7,
            INVALID_DATA = 8
        };
    };

    ThriftException();
    ThriftException(Type::type type);
    ThriftException(Type::type type, QString message);

    Type::type type() const;

    const char * what() const throw() Q_DECL_OVERRIDE;

    virtual QSharedPointer<EverCloudExceptionData> exceptionData() const Q_DECL_OVERRIDE;

protected:
    Type::type m_type;
};

/** Asynchronous API conterpart of ThriftException. See EverCloudExceptionData for more details.*/
class QEVERCLOUD_EXPORT ThriftExceptionData: public EverCloudExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(ThriftExceptionData)
public:
    explicit ThriftExceptionData(QString error, ThriftException::Type::type type);
    virtual void throwException() const Q_DECL_OVERRIDE;

protected:
    ThriftException::Type::type m_type;
};

inline QSharedPointer<EverCloudExceptionData> ThriftException::exceptionData() const
{
    return QSharedPointer<EverCloudExceptionData>(new ThriftExceptionData(QString::fromUtf8(what()), type()));
}

/** Asynchronous API conterpart of EDAMUserException. See EverCloudExceptionData for more details.*/
class QEVERCLOUD_EXPORT EDAMUserExceptionData: public EvernoteExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EDAMUserExceptionData)
public:
    explicit EDAMUserExceptionData(QString error, EDAMErrorCode::type errorCode, Optional<QString> parameter);
    virtual void throwException() const Q_DECL_OVERRIDE;

protected:
    EDAMErrorCode::type     m_errorCode;
    Optional<QString>       m_parameter;
};

/** Asynchronous API conterpart of EDAMSystemException. See EverCloudExceptionData for more details.*/
class QEVERCLOUD_EXPORT EDAMSystemExceptionData: public EvernoteExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EDAMSystemExceptionData)
public:
    explicit EDAMSystemExceptionData(QString err, EDAMErrorCode::type errorCode, Optional<QString> message, Optional<qint32> rateLimitDuration);
    virtual void throwException() const Q_DECL_OVERRIDE;

protected:
    EDAMErrorCode::type     m_errorCode;
    Optional<QString>       m_message;
    Optional<qint32>        m_rateLimitDuration;
};

/** Asynchronous API conterpart of EDAMNotFoundException. See EverCloudExceptionData for more details.*/
class QEVERCLOUD_EXPORT EDAMNotFoundExceptionData: public EvernoteExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EDAMNotFoundExceptionData)
public:
    explicit EDAMNotFoundExceptionData(QString error, Optional<QString> identifier, Optional<QString> key);
    virtual void throwException() const Q_DECL_OVERRIDE;

protected:
    Optional<QString> m_identifier;
    Optional<QString> m_key;
};

/** Asynchronous API conterpart of EDAMInvalidContactsException. See EverCloudExceptionData for more details.*/
class QEVERCLOUD_EXPORT EDAMInvalidContactsExceptionData: public EvernoteExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EDAMInvalidContactsExceptionData)
public:
    explicit EDAMInvalidContactsExceptionData(QList<Contact> contacts, Optional<QString> parameter, Optional<QList<EDAMInvalidContactReason::type> > reasons);
    virtual void throwException() const Q_DECL_OVERRIDE;

protected:
    QList< Contact >                                    m_contacts;
    Optional< QString >                                 m_parameter;
    Optional< QList< EDAMInvalidContactReason::type > > m_reasons;
};

/**
 *  EDAMSystemException for `errorCode = RATE_LIMIT_REACHED`
 */
class QEVERCLOUD_EXPORT EDAMSystemExceptionRateLimitReached: public EDAMSystemException
{
public:
    virtual QSharedPointer<EverCloudExceptionData> exceptionData() const Q_DECL_OVERRIDE;
};

/** Asynchronous API conterpart of EDAMSystemExceptionRateLimitReached. See EverCloudExceptionData for more details.*/
class QEVERCLOUD_EXPORT EDAMSystemExceptionRateLimitReachedData: public EDAMSystemExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EDAMSystemExceptionRateLimitReachedData)
public:
    explicit EDAMSystemExceptionRateLimitReachedData(QString error, EDAMErrorCode::type errorCode, Optional<QString> message,
                                                     Optional<qint32> rateLimitDuration);
    virtual void throwException() const Q_DECL_OVERRIDE;
};

/**
 *  EDAMSystemException for `errorCode = AUTH_EXPIRED`
 */
class QEVERCLOUD_EXPORT EDAMSystemExceptionAuthExpired: public EDAMSystemException
{
public:
    virtual QSharedPointer<EverCloudExceptionData> exceptionData() const Q_DECL_OVERRIDE;
};

/** Asynchronous API conterpart of EDAMSystemExceptionAuthExpired. See EverCloudExceptionData for more details.*/
class QEVERCLOUD_EXPORT EDAMSystemExceptionAuthExpiredData: public EDAMSystemExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EDAMSystemExceptionAuthExpiredData)
public:
    explicit EDAMSystemExceptionAuthExpiredData(QString error, EDAMErrorCode::type errorCode, Optional<QString> message,
                                                Optional<qint32> rateLimitDuration);
    virtual void throwException() const Q_DECL_OVERRIDE;
};

} // namespace qevercloud

#endif // QEVERCLOUD_EXCEPTIONS_H
