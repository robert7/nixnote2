/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <Optional.h>
#include <generated/types.h>
#include <qt4helpers.h>
#include "generated/types_impl.h"
#include "impl.h"

namespace qevercloud {

ThriftException::ThriftException() :
    EverCloudException(),
    m_type(Type::UNKNOWN)
{}

ThriftException::ThriftException(ThriftException::Type::type type) :
    EverCloudException(),
    m_type(type)
{}

ThriftException::ThriftException(ThriftException::Type::type type, QString message) :
    EverCloudException(message),
    m_type(type)
{}

ThriftException::Type::type ThriftException::type() const
{
    return m_type;
}

QByteArray strEDAMErrorCode(EDAMErrorCode::type errorCode)
{
    switch(errorCode)
    {
    case EDAMErrorCode::UNKNOWN:
        return "UNKNOWN";
    case EDAMErrorCode::BAD_DATA_FORMAT:
        return "BAD_DATA_FORMAT";
    case EDAMErrorCode::PERMISSION_DENIED:
        return "PERMISSION_DENIED";
    case EDAMErrorCode::INTERNAL_ERROR:
        return "INTERNAL_ERROR";
    case EDAMErrorCode::DATA_REQUIRED:
        return "DATA_REQUIRED";
    case EDAMErrorCode::LIMIT_REACHED:
        return "LIMIT_REACHED";
    case EDAMErrorCode::QUOTA_REACHED:
        return "QUOTA_REACHED";
    case EDAMErrorCode::INVALID_AUTH:
        return "INVALID_AUTH";
    case EDAMErrorCode::AUTH_EXPIRED:
        return "AUTH_EXPIRED";
    case EDAMErrorCode::DATA_CONFLICT:
        return "DATA_CONFLICT";
    case EDAMErrorCode::ENML_VALIDATION:
        return "ENML_VALIDATION";
    case EDAMErrorCode::SHARD_UNAVAILABLE:
        return "SHARD_UNAVAILABLE";
    case EDAMErrorCode::LEN_TOO_SHORT:
        return "LEN_TOO_SHORT";
    case EDAMErrorCode::LEN_TOO_LONG:
        return "LEN_TOO_LONG";
    case EDAMErrorCode::TOO_FEW:
        return "TOO_FEW";
    case EDAMErrorCode::TOO_MANY:
        return "TOO_MANY";
    case EDAMErrorCode::UNSUPPORTED_OPERATION:
        return "UNSUPPORTED_OPERATION";
    case EDAMErrorCode::TAKEN_DOWN:
        return "TAKEN_DOWN";
    case EDAMErrorCode::RATE_LIMIT_REACHED:
        return "RATE_LIMIT_REACHED";
    default:
        return "UNRECOGNIZED_ERROR_CODE";
    }
}

const char * EDAMUserException::what() const throw()
{
    if (m_error.isEmpty())
    {
        m_error = "EDAMUserException: " + strEDAMErrorCode(errorCode);
        if (parameter.isSet()) {
            m_error += " parameter=" + parameter->toUtf8();
        }
    }

    return EvernoteException::what();
}

const char * EDAMSystemException::what() const throw()
{
    if (m_error.isEmpty())
    {
        m_error = "EDAMSystemException: " + strEDAMErrorCode(errorCode);

        if (message.isSet()) {
            m_error += " " + message->toUtf8();
        }

        if (rateLimitDuration.isSet()) {
            m_error += QStringLiteral(" rateLimitDuration= %1 sec.").arg(rateLimitDuration).toUtf8();
        }
    }

    return EvernoteException::what();
}

const char * EDAMNotFoundException::what() const throw()
{
    if (m_error.isEmpty())
    {
        m_error = "EDAMNotFoundException: ";

        if (identifier.isSet()) {
            m_error += " identifier=" + identifier->toUtf8();
        }

        if (key.isSet()) {
            m_error += " key=" + key->toUtf8();
        }
    }

    return EvernoteException::what();
}

ThriftException readThriftException(ThriftBinaryBufferReader & reader)
{
    QString name;
    ThriftFieldType::type fieldType;
    qint16 fieldId;

    reader.readStructBegin(name);
    QString error;
    ThriftException::Type::type type = ThriftException::Type::UNKNOWN;

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
                type = static_cast<ThriftException::Type::type>(t);
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

QSharedPointer<EverCloudExceptionData> EDAMInvalidContactsException::exceptionData() const
{
    return QSharedPointer<EverCloudExceptionData>(new EDAMInvalidContactsExceptionData(this->contacts, this->parameter, this->reasons));
}

EDAMInvalidContactsExceptionData::EDAMInvalidContactsExceptionData(QList<Contact> contacts, Optional<QString> parameter,
                                                                   Optional<QList<EDAMInvalidContactReason::type> > reasons) :
    EvernoteExceptionData(QStringLiteral("EDAMInvalidContactsExceptionData")),
    m_contacts(contacts),
    m_parameter(parameter),
    m_reasons(reasons)
{}

const char * EDAMInvalidContactsException::what() const throw()
{
    return "EDAMInvalidContactsException";
}

void EDAMInvalidContactsExceptionData::throwException() const
{
    EDAMInvalidContactsException exception;
    exception.contacts = m_contacts;
    exception.parameter = m_parameter;
    exception.reasons = m_reasons;
    throw exception;
}

QSharedPointer<EverCloudExceptionData> EDAMUserException::exceptionData() const
{
    return QSharedPointer<EverCloudExceptionData>(new EDAMUserExceptionData(QString::fromUtf8(what()), this->errorCode, this->parameter));
}

void EDAMUserExceptionData::throwException() const
{
    EDAMUserException exception;
    exception.errorCode = m_errorCode;
    exception.parameter = m_parameter;
    throw exception;
}

QSharedPointer<EverCloudExceptionData> EDAMSystemException::exceptionData() const
{
    return QSharedPointer<EverCloudExceptionData>(new EDAMSystemExceptionData(QString::fromUtf8(what()), this->errorCode, this->message,
                                                                              this->rateLimitDuration));
}

EDAMSystemExceptionData::EDAMSystemExceptionData(QString error, EDAMErrorCode::type errorCode, Optional<QString> message,
                                                 Optional<qint32> rateLimitDuration) :
    EvernoteExceptionData(error),
    m_errorCode(errorCode),
    m_message(message),
    m_rateLimitDuration(rateLimitDuration)
{}

void EDAMSystemExceptionData::throwException() const
{
    EDAMSystemException exception;
    exception.errorCode = m_errorCode;
    exception.message = m_message;
    exception.rateLimitDuration = m_rateLimitDuration;
    throw exception;
}

EDAMSystemExceptionRateLimitReachedData::EDAMSystemExceptionRateLimitReachedData(QString error, EDAMErrorCode::type errorCode,
                                                                                 Optional<QString> message,
                                                                                 Optional<qint32> rateLimitDuration) :
    EDAMSystemExceptionData(error, errorCode, message, rateLimitDuration)
{}

void EDAMSystemExceptionRateLimitReachedData::throwException() const
{
    EDAMSystemExceptionRateLimitReached exception;
    exception.errorCode = m_errorCode;
    exception.message = m_message;
    exception.rateLimitDuration = m_rateLimitDuration;
    throw exception;
}

QSharedPointer<EverCloudExceptionData> EDAMNotFoundException::exceptionData() const
{
    return QSharedPointer<EverCloudExceptionData>(new EDAMNotFoundExceptionData(QString::fromUtf8(what()), identifier, key));
}

EDAMNotFoundExceptionData::EDAMNotFoundExceptionData(QString error, Optional<QString> identifier, Optional<QString> key) :
    EvernoteExceptionData(error),
    m_identifier(identifier),
    m_key(key)
{}

void EDAMNotFoundExceptionData::throwException() const
{
    EDAMNotFoundException exception;
    exception.identifier = m_identifier;
    exception.key = m_key;
    throw exception;
}

const char * ThriftException::what() const throw()
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

void throwEDAMSystemException(const EDAMSystemException & baseException)
{
    if (baseException.errorCode == EDAMErrorCode::AUTH_EXPIRED) {
        EDAMSystemExceptionAuthExpired exception;
        exception.errorCode = exception.errorCode;
        exception.message = exception.message;
        exception.rateLimitDuration = exception.rateLimitDuration;
        throw exception;
    }

    if (baseException.errorCode == EDAMErrorCode::RATE_LIMIT_REACHED) {
        EDAMSystemExceptionRateLimitReached exception;
        exception.errorCode = exception.errorCode;
        exception.message = exception.message;
        exception.rateLimitDuration = exception.rateLimitDuration;
        throw exception;
    }

    throw baseException;
}

QSharedPointer<EverCloudExceptionData> EDAMSystemExceptionRateLimitReached::exceptionData() const
{
    return QSharedPointer<EverCloudExceptionData>(new EDAMSystemExceptionRateLimitReachedData(QString::fromUtf8(what()), this->errorCode,
                                                                                              this->message,
                                                                                              this->rateLimitDuration));
}

QSharedPointer<EverCloudExceptionData> EDAMSystemExceptionAuthExpired::exceptionData() const
{
    return QSharedPointer<EverCloudExceptionData>(new EDAMSystemExceptionAuthExpiredData(QString::fromUtf8(what()), this->errorCode,
                                                                                         this->message,
                                                                                         this->rateLimitDuration));
}

EDAMSystemExceptionAuthExpiredData::EDAMSystemExceptionAuthExpiredData(QString error, EDAMErrorCode::type errorCode,
                                                                       Optional<QString> message,
                                                                       Optional<qint32> rateLimitDuration) :
    EDAMSystemExceptionData(error, errorCode, message, rateLimitDuration)
{}

void EDAMSystemExceptionAuthExpiredData::throwException() const
{
    EDAMSystemExceptionAuthExpired exception;
    exception.errorCode = m_errorCode;
    exception.message = m_message;
    exception.rateLimitDuration = m_rateLimitDuration;
    throw exception;
}

ThriftExceptionData::ThriftExceptionData(QString error, ThriftException::Type::type type) :
    EverCloudExceptionData(error),
    m_type(type)
{}

void ThriftExceptionData::throwException() const
{
    throw ThriftException(m_type, errorMessage);
}

EDAMUserExceptionData::EDAMUserExceptionData(QString error, EDAMErrorCode::type errorCode, Optional<QString> parameter) :
    EvernoteExceptionData(error),
    m_errorCode(errorCode),
    m_parameter(parameter)
{}

} // namespace qevercloud
