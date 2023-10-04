/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_EXCEPTIONS_H
#define QEVERCLOUD_EXCEPTIONS_H

#include "EverCloudException.h"
#include "Export.h"
#include "Optional.h"
#include "generated/EDAMErrorCode.h"
#include "generated/Types.h"

#include <QNetworkReply>
#include <QObject>
#include <QString>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief The NetworkException class represents QNetworkReply level errors.
 */
class QEVERCLOUD_EXPORT NetworkException: public EverCloudException
{
public:
    NetworkException();
    NetworkException(QNetworkReply::NetworkError error);
    NetworkException(QNetworkReply::NetworkError error, QString message);
    virtual ~NetworkException() noexcept override;

    bool operator==(const NetworkException & other) const;
    bool operator!=(const NetworkException & other) const;

    QNetworkReply::NetworkError type() const;

    const char * what() const noexcept override;

    virtual EverCloudExceptionDataPtr exceptionData() const override;

protected:
    QNetworkReply::NetworkError m_type;
};

/**
 * Asynchronous API counterpart of NetworkException. See EverCloudExceptionData
 * for more details.
 */
class QEVERCLOUD_EXPORT NetworkExceptionData: public EverCloudExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(NetworkExceptionData)
public:
    explicit NetworkExceptionData(QString error, QNetworkReply::NetworkError type);
    virtual void throwException() const override;

protected:
    QNetworkReply::NetworkError m_type;
};

////////////////////////////////////////////////////////////////////////////////

/**
 * Errors of the Thrift protocol level. It could be wrongly formatted parameters
 * or return values for example.
 */
class QEVERCLOUD_EXPORT ThriftException: public EverCloudException
{
public:
    enum class Type {
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

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const Type type);

    ThriftException();
    ThriftException(Type type);
    ThriftException(Type type, QString message);
    virtual ~ThriftException() noexcept override;

    bool operator==(const ThriftException & other) const;
    bool operator!=(const ThriftException & other) const;

    Type type() const;

    const char * what() const noexcept override;

    virtual EverCloudExceptionDataPtr exceptionData() const override;

protected:
    Type m_type;
};

/**
 * Asynchronous API counterpart of ThriftException. See EverCloudExceptionData
 * for more details.
 */
class QEVERCLOUD_EXPORT ThriftExceptionData: public EverCloudExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(ThriftExceptionData)
public:
    explicit ThriftExceptionData(QString error, ThriftException::Type type);
    virtual void throwException() const override;

protected:
    ThriftException::Type m_type;
};

////////////////////////////////////////////////////////////////////////////////

/**
 * Asynchronous API counterpart of EDAMUserException. See EverCloudExceptionData
 * for more details.
 */
class QEVERCLOUD_EXPORT EDAMUserExceptionData: public EvernoteExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EDAMUserExceptionData)
public:
    explicit EDAMUserExceptionData(
        QString error, EDAMErrorCode errorCode, Optional<QString> parameter);

    virtual void throwException() const override;

protected:
    EDAMErrorCode       m_errorCode;
    Optional<QString>   m_parameter;
};

////////////////////////////////////////////////////////////////////////////////

/**
 * Asynchronous API counterpart of EDAMSystemException.
 * See EverCloudExceptionData for more details.
 */
class QEVERCLOUD_EXPORT EDAMSystemExceptionData: public EvernoteExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EDAMSystemExceptionData)
public:
    explicit EDAMSystemExceptionData(
        QString err, EDAMErrorCode errorCode, Optional<QString> message,
        Optional<qint32> rateLimitDuration);

    virtual void throwException() const override;

protected:
    EDAMErrorCode       m_errorCode;
    Optional<QString>   m_message;
    Optional<qint32>    m_rateLimitDuration;
};

////////////////////////////////////////////////////////////////////////////////

/**
 * Asynchronous API counterpart of EDAMNotFoundException.
 * See EverCloudExceptionData for more details.
 */
class QEVERCLOUD_EXPORT EDAMNotFoundExceptionData: public EvernoteExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EDAMNotFoundExceptionData)
public:
    explicit EDAMNotFoundExceptionData(
        QString error, Optional<QString> identifier, Optional<QString> key);

    virtual void throwException() const override;

protected:
    Optional<QString> m_identifier;
    Optional<QString> m_key;
};

////////////////////////////////////////////////////////////////////////////////

/**
 * Asynchronous API counterpart of EDAMInvalidContactsException.
 * See EverCloudExceptionData for more details.
 */
class QEVERCLOUD_EXPORT EDAMInvalidContactsExceptionData:
    public EvernoteExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EDAMInvalidContactsExceptionData)
public:
    explicit EDAMInvalidContactsExceptionData(
        QList<Contact> contacts, Optional<QString> parameter,
        Optional<QList<EDAMInvalidContactReason> > reasons);

    virtual void throwException() const override;

protected:
    QList<Contact>      m_contacts;
    Optional<QString>   m_parameter;
    Optional<QList<EDAMInvalidContactReason>> m_reasons;
};

////////////////////////////////////////////////////////////////////////////////

/**
 *  EDAMSystemException for `errorCode = RATE_LIMIT_REACHED`
 */
class QEVERCLOUD_EXPORT EDAMSystemExceptionRateLimitReached:
    public EDAMSystemException
{
public:
    virtual EverCloudExceptionDataPtr exceptionData() const override;
};

////////////////////////////////////////////////////////////////////////////////

/**
 * Asynchronous API counterpart of EDAMSystemExceptionRateLimitReached.
 * See EverCloudExceptionData for more details.
 */
class QEVERCLOUD_EXPORT EDAMSystemExceptionRateLimitReachedData:
    public EDAMSystemExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EDAMSystemExceptionRateLimitReachedData)
public:
    explicit EDAMSystemExceptionRateLimitReachedData(
        QString error, EDAMErrorCode errorCode, Optional<QString> message,
        Optional<qint32> rateLimitDuration);

    virtual void throwException() const override;
};

////////////////////////////////////////////////////////////////////////////////

/**
 *  EDAMSystemException for `errorCode = AUTH_EXPIRED`
 */
class QEVERCLOUD_EXPORT EDAMSystemExceptionAuthExpired: public EDAMSystemException
{
public:
    virtual EverCloudExceptionDataPtr exceptionData() const override;
};

////////////////////////////////////////////////////////////////////////////////

/**
 * Asynchronous API counterpart of EDAMSystemExceptionAuthExpired.
 * See EverCloudExceptionData for more details.
 */
class QEVERCLOUD_EXPORT EDAMSystemExceptionAuthExpiredData:
    public EDAMSystemExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EDAMSystemExceptionAuthExpiredData)
public:
    explicit EDAMSystemExceptionAuthExpiredData(
        QString error, EDAMErrorCode errorCode, Optional<QString> message,
        Optional<qint32> rateLimitDuration);

    virtual void throwException() const override;
};

} // namespace qevercloud

#endif // QEVERCLOUD_EXCEPTIONS_H
