/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "Impl.h"
#include "generated/Types_io.h"

#include <Helpers.h>
#include <Optional.h>
#include <generated/Types.h>

#include <QTextStream>
#include <memory>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

NetworkException::NetworkException() :
    EverCloudException(),
    m_type(QNetworkReply::UnknownNetworkError)
{}

NetworkException::NetworkException(QNetworkReply::NetworkError type) :
    EverCloudException(),
    m_type(type)
{}

NetworkException::NetworkException(
        QNetworkReply::NetworkError type,
        QString message) :
    EverCloudException(message),
    m_type(type)
{}

NetworkException::~NetworkException() noexcept
{}

bool NetworkException::operator==(const NetworkException & other) const
{
    return m_type == other.m_type && m_error == other.m_error;
}

bool NetworkException::operator!=(const NetworkException & other) const
{
    return !operator==(other);
}

QNetworkReply::NetworkError NetworkException::type() const
{
    return m_type;
}

const char * NetworkException::what() const noexcept
{
    if (m_error.isEmpty())
    {
        switch (m_type)
        {
        case QNetworkReply::NoError:
            return "NetworkException: No error";
        case QNetworkReply::ConnectionRefusedError:
            return "NetworkException: Connection refused";
        case QNetworkReply::RemoteHostClosedError:
            return "NetworkException: Remote host closed";
        case QNetworkReply::HostNotFoundError:
            return "NetworkException: Host not found";
        case QNetworkReply::TimeoutError:
            return "NetworkException: The connection to remote host timed out";
        case QNetworkReply::OperationCanceledError:
            return "NetworkException: Operation canceled";
        case QNetworkReply::SslHandshakeFailedError:
            return "NetworkError: SSL handshake failed";
        case QNetworkReply::TemporaryNetworkFailureError:
            return "NetworkError: Temporary network failure";
        case QNetworkReply::NetworkSessionFailedError:
            return "NetworkError: Network session failed";
        case QNetworkReply::BackgroundRequestNotAllowedError:
            return "NetworkError: Background request not allowed";
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
        case QNetworkReply::TooManyRedirectsError:
            return "NetworkError: Too many redirects";
        case QNetworkReply::InsecureRedirectError:
            return "NetworkError: Insecure redirect";
#endif
        case QNetworkReply::ProxyConnectionRefusedError:
            return "NetworkError: Proxy connection refused";
        case QNetworkReply::ProxyConnectionClosedError:
            return "NetworkError: Proxy connection closed";
        case QNetworkReply::ProxyNotFoundError:
            return "NetworkError: Proxy not found";
        case QNetworkReply::ProxyTimeoutError:
            return "NetworkError: Proxy timeout";
        case QNetworkReply::ProxyAuthenticationRequiredError:
            return "NetworkError: Proxy authentication required";
        case QNetworkReply::ContentAccessDenied:
            return "NetworkError: Content access denied";
        case QNetworkReply::ContentOperationNotPermittedError:
            return "NetworkError: Content operation not permitted";
        case QNetworkReply::ContentNotFoundError:
            return "NetworkError: Content not found";
        case QNetworkReply::AuthenticationRequiredError:
            return "NetworkError: Authentication required";
        case QNetworkReply::ContentReSendError:
            return "NetworkError: Content resend failed";
        case QNetworkReply::ContentConflictError:
            return "NetworkError: Content conflict error";
        case QNetworkReply::ContentGoneError:
            return "NetworkError: Content gone";
        case QNetworkReply::InternalServerError:
            return "NetworkError: Internal server error";
        case QNetworkReply::OperationNotImplementedError:
            return "NetworkError: Operation not implemented error";
        case QNetworkReply::ServiceUnavailableError:
            return "NetworkError: Service unavailable";
        case QNetworkReply::ProtocolUnknownError:
            return "NetworkError: Protocol unknown";
        case QNetworkReply::ProtocolInvalidOperationError:
            return "NetworkError: Protocol invalid operation";
        case QNetworkReply::UnknownNetworkError:
            return "NetworkError: Unknown network";
        case QNetworkReply::UnknownProxyError:
            return "NetworkError: Unknown proxy";
        case QNetworkReply::UnknownContentError:
            return "NetworkError: Unknown content";
        case QNetworkReply::ProtocolFailure:
            return "NetworkError: Protocol failure";
        case QNetworkReply::UnknownServerError:
            return "NetworkError: Unknown server";
        default:
            return "NetworkError: (Invlaid exception type)";
        }
    }
    else
    {
        return m_error.constData();
    }
}

EverCloudExceptionDataPtr NetworkException::exceptionData() const
{
    return std::make_shared<NetworkExceptionData>(
        QString::fromUtf8(what()), type());
}

NetworkExceptionData::NetworkExceptionData(
        QString error,
        QNetworkReply::NetworkError type) :
    EverCloudExceptionData(error),
    m_type(type)
{}

void NetworkExceptionData::throwException() const
{
    throw NetworkException(m_type, errorMessage);
}

////////////////////////////////////////////////////////////////////////////////

ThriftException::ThriftException() :
    EverCloudException(),
    m_type(Type::UNKNOWN)
{}

ThriftException::ThriftException(ThriftException::Type type) :
    EverCloudException(),
    m_type(type)
{}

ThriftException::ThriftException(ThriftException::Type type, QString message) :
    EverCloudException(message),
    m_type(type)
{}

ThriftException::~ThriftException() noexcept
{}

QTextStream & operator<<(QTextStream & strm, const ThriftException::Type type)
{
    switch(type)
    {
    case ThriftException::Type::UNKNOWN:
        strm << "Unknown application exception";
        break;
    case ThriftException::Type::UNKNOWN_METHOD:
        strm << "Unknown method";
        break;
    case ThriftException::Type::INVALID_MESSAGE_TYPE:
        strm << "Invalid message type";
        break;
    case ThriftException::Type::WRONG_METHOD_NAME:
        strm << "Wrong method name";
        break;
    case ThriftException::Type::BAD_SEQUENCE_ID:
        strm << "Bad sequence identifier";
        break;
    case ThriftException::Type::MISSING_RESULT:
        strm << "Missing result";
        break;
    case ThriftException::Type::INTERNAL_ERROR:
        strm << "Internal error";
        break;
    case ThriftException::Type::PROTOCOL_ERROR:
        strm << "Protocol error";
        break;
    case ThriftException::Type::INVALID_DATA:
        strm << "Invalid data";
        break;
    default:
        strm << "Invalid exception type: " << static_cast<int>(type);
        break;
    }

    return strm;
}

bool ThriftException::operator==(const ThriftException & other) const
{
    return m_type == other.m_type && m_error == other.m_error;
}

bool ThriftException::operator!=(const ThriftException & other) const
{
    return !operator==(other);
}

ThriftException::Type ThriftException::type() const
{
    return m_type;
}

const char * ThriftException::what() const noexcept
{
    if (m_error.isEmpty())
    {
        switch (m_type)
        {
        case Type::UNKNOWN:
            return "ThriftException: Unknown application exception";
        case Type::UNKNOWN_METHOD:
            return "ThriftException: Unknown method";
        case Type::INVALID_MESSAGE_TYPE:
            return "ThriftException: Invalid message type";
        case Type::WRONG_METHOD_NAME:
            return "ThriftException: Wrong method name";
        case Type::BAD_SEQUENCE_ID:
            return "ThriftException: Bad sequence identifier";
        case Type::MISSING_RESULT:
            return "ThriftException: Missing result";
        case Type::INTERNAL_ERROR:
            return "ThriftException: Internal error";
        case Type::PROTOCOL_ERROR:
            return "ThriftException: Protocol error";
        case Type::INVALID_DATA:
            return "ThriftException: Invalid data";
        default:
            return "ThriftException: (Invalid exception type)";
        };
    }
    else
    {
        return m_error.constData();
    }
}

EverCloudExceptionDataPtr ThriftException::exceptionData() const
{
    return std::make_shared<ThriftExceptionData>(
        QString::fromUtf8(what()), type());
}

ThriftExceptionData::ThriftExceptionData(
        QString error,
        ThriftException::Type type) :
    EverCloudExceptionData(error),
    m_type(type)
{}

void ThriftExceptionData::throwException() const
{
    throw ThriftException(m_type, errorMessage);
}

////////////////////////////////////////////////////////////////////////////////

const char * EDAMUserException::what() const noexcept
{
    if (m_error.isEmpty())
    {
        QTextStream strm(&m_error);
        strm << "EDAMUserException: " << errorCode;
        if (parameter.isSet()) {
            strm << " parameter=" << parameter->toUtf8();
        }
    }

    return EvernoteException::what();
}

const char * EDAMSystemException::what() const noexcept
{
    if (m_error.isEmpty())
    {
        QTextStream strm(&m_error);
        strm << "EDAMSystemException: " << errorCode;

        if (message.isSet()) {
            strm << " " << message->toUtf8();
        }

        if (rateLimitDuration.isSet()) {
            strm << " rateLimitDuration= " << rateLimitDuration << " sec.";
        }
    }

    return EvernoteException::what();
}

const char * EDAMNotFoundException::what() const noexcept
{
    if (m_error.isEmpty())
    {
        QTextStream strm(&m_error);
        strm << "EDAMNotFoundException: ";

        if (identifier.isSet()) {
            strm << " identifier=" << identifier;
        }

        if (key.isSet()) {
            strm << " key=" << key;
        }
    }

    return EvernoteException::what();
}

ThriftException readThriftException(ThriftBinaryBufferReader & reader)
{
    QString name;
    ThriftFieldType fieldType;
    qint16 fieldId;

    reader.readStructBegin(name);
    QString error;
    ThriftException::Type type = ThriftException::Type::UNKNOWN;

    while(true)
    {
        reader.readFieldBegin(name, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        switch(fieldId)
        {
        case 1:
            if (fieldType == ThriftFieldType::T_STRING) {
                QString str;
                reader.readString(str);
                error = str;
            }
            else {
                reader.skip(fieldType);
            }
            break;
        case 2:
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 t;
                reader.readI32(t);
                type = static_cast<ThriftException::Type>(t);
            }
            else {
                reader.skip(fieldType);
            }
            break;
        default:
            reader.skip(fieldType);
            break;
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();

    return ThriftException(type, error);
}

void writeThriftException(
    ThriftBinaryBufferWriter & writer, const ThriftException & exception)
{
    writer.writeStructBegin(QStringLiteral("ThriftException"));

    writer.writeFieldBegin(QStringLiteral("error"), ThriftFieldType::T_STRING, 1);
    writer.writeString(QString::fromUtf8(exception.what()));
    writer.writeFieldEnd();

    writer.writeFieldBegin(QStringLiteral("type"), ThriftFieldType::T_I32, 2);
    writer.writeI32(static_cast<qint32>(exception.type()));
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
}

EverCloudExceptionDataPtr EDAMInvalidContactsException::exceptionData() const
{
    return std::make_shared<EDAMInvalidContactsExceptionData>(
        contacts, parameter, reasons);
}

EDAMInvalidContactsExceptionData::EDAMInvalidContactsExceptionData(
        QList<Contact> contacts,
        Optional<QString> parameter,
        Optional<QList<EDAMInvalidContactReason> > reasons) :
    EvernoteExceptionData(QStringLiteral("EDAMInvalidContactsExceptionData")),
    m_contacts(contacts),
    m_parameter(parameter),
    m_reasons(reasons)
{}

const char * EDAMInvalidContactsException::what() const noexcept
{
    return "EDAMInvalidContactsException";
}

void EDAMInvalidContactsExceptionData::throwException() const
{
    EDAMInvalidContactsException e;
    e.contacts = m_contacts;
    e.parameter = m_parameter;
    e.reasons = m_reasons;
    throw e;
}

EverCloudExceptionDataPtr EDAMUserException::exceptionData() const
{
    return std::make_shared<EDAMUserExceptionData>(
        QString::fromUtf8(what()), errorCode, parameter);
}

void EDAMUserExceptionData::throwException() const
{
    EDAMUserException e;
    e.errorCode = m_errorCode;
    e.parameter = m_parameter;
    throw e;
}

EverCloudExceptionDataPtr EDAMSystemException::exceptionData() const
{
    return std::make_shared<EDAMSystemExceptionData>(
        QString::fromUtf8(what()), errorCode, message, rateLimitDuration);
}

EDAMSystemExceptionData::EDAMSystemExceptionData(
        QString error,
        EDAMErrorCode errorCode,
        Optional<QString> message,
        Optional<qint32> rateLimitDuration) :
    EvernoteExceptionData(error),
    m_errorCode(errorCode),
    m_message(message),
    m_rateLimitDuration(rateLimitDuration)
{}

void EDAMSystemExceptionData::throwException() const
{
    EDAMSystemException e;
    e.errorCode = m_errorCode;
    e.message = m_message;
    e.rateLimitDuration = m_rateLimitDuration;
    throw e;
}

EDAMSystemExceptionRateLimitReachedData::EDAMSystemExceptionRateLimitReachedData(
        QString error, EDAMErrorCode errorCode,
        Optional<QString> message,
        Optional<qint32> rateLimitDuration) :
    EDAMSystemExceptionData(error, errorCode, message, rateLimitDuration)
{}

void EDAMSystemExceptionRateLimitReachedData::throwException() const
{
    EDAMSystemExceptionRateLimitReached e;
    e.errorCode = m_errorCode;
    e.message = m_message;
    e.rateLimitDuration = m_rateLimitDuration;
    throw e;
}

EverCloudExceptionDataPtr EDAMNotFoundException::exceptionData() const
{
    return std::make_shared<EDAMNotFoundExceptionData>(
        QString::fromUtf8(what()), identifier, key);
}

EDAMNotFoundExceptionData::EDAMNotFoundExceptionData(
        QString error,
        Optional<QString> identifier,
        Optional<QString> key) :
    EvernoteExceptionData(error),
    m_identifier(identifier),
    m_key(key)
{}

void EDAMNotFoundExceptionData::throwException() const
{
    EDAMNotFoundException e;
    e.identifier = m_identifier;
    e.key = m_key;
    throw e;
}

void throwEDAMSystemException(const EDAMSystemException & baseException)
{
    if (baseException.errorCode == EDAMErrorCode::AUTH_EXPIRED) {
        EDAMSystemExceptionAuthExpired e;
        e.errorCode = baseException.errorCode;
        e.message = baseException.message;
        e.rateLimitDuration = baseException.rateLimitDuration;
        throw e;
    }

    if (baseException.errorCode == EDAMErrorCode::RATE_LIMIT_REACHED) {
        EDAMSystemExceptionRateLimitReached e;
        e.errorCode = baseException.errorCode;
        e.message = baseException.message;
        e.rateLimitDuration = baseException.rateLimitDuration;
        throw e;
    }

    throw baseException;
}

EverCloudExceptionDataPtr EDAMSystemExceptionRateLimitReached::exceptionData() const
{
    return std::make_shared<EDAMSystemExceptionRateLimitReachedData>(
        QString::fromUtf8(what()),
        errorCode,
        message,
        rateLimitDuration);
}

EverCloudExceptionDataPtr EDAMSystemExceptionAuthExpired::exceptionData() const
{
    return std::make_shared<EDAMSystemExceptionAuthExpiredData>(
        QString::fromUtf8(what()),
        errorCode,
        message,
        rateLimitDuration);
}

EDAMSystemExceptionAuthExpiredData::EDAMSystemExceptionAuthExpiredData(
        QString error,
        EDAMErrorCode errorCode,
        Optional<QString> message,
        Optional<qint32> rateLimitDuration) :
    EDAMSystemExceptionData(error, errorCode, message, rateLimitDuration)
{}

void EDAMSystemExceptionAuthExpiredData::throwException() const
{
    EDAMSystemExceptionAuthExpired e;
    e.errorCode = m_errorCode;
    e.message = m_message;
    e.rateLimitDuration = m_rateLimitDuration;
    throw e;
}

EDAMUserExceptionData::EDAMUserExceptionData(
        QString error,
        EDAMErrorCode errorCode,
        Optional<QString> parameter) :
    EvernoteExceptionData(error),
    m_errorCode(errorCode),
    m_parameter(parameter)
{}

} // namespace qevercloud
