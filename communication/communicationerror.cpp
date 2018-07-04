/*********************************************************************************
NixNote - An open-source client for the Evernote service.
Copyright (C) 2013 Randy Baumgarte

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
***********************************************************************************/


#include "communicationerror.h"
#include "logger/qslog.h"
#include "qevercloud/generated/EDAMErrorCode.h"

// Default constructor
CommunicationError::CommunicationError(QObject *parent) :
    QObject(parent) {
    this->reset();
}


// Reset all values
void CommunicationError::reset() {
    retryCount = 0;
    maxRetryCount = 3;
    code = 0;
    message = QString();
    internalMessage = QString();
    type = None;
}


// Retry after the last error
bool CommunicationError::retry() {
    return retryCount < maxRetryCount;
}

// reset class to given exception/error info
void CommunicationError::resetTo(CommunicationErrorType type, int code, QString message, QString internalMessage) {
    reset();
    this->type = type;
    this->code = code;
    this->internalMessage = internalMessage;

    // render exception name
    QString msg(communicationErrorTypeToString(type));
    // followed by code
    if (code != 0) {
        msg.append("[").append(code);
        // for some type we have text table for codes
        if (type == CommunicationError::EDAMUserException) {
            msg.append("-");
            msg.append(edamErrorCodeToString(code));
        }

        msg.append("]");
    }
    // then by message
    msg.append(": ");
    msg.append(message);
    // save like this
    this->message = msg;
    // then append internal message
    if (!internalMessage.isEmpty()) {
        msg.append(" ## " + internalMessage);
    }

    // check if this is the right point to print, or we hant to have dedicated method
    QLOG_ERROR() << msg;
}


QString CommunicationError::edamErrorCodeToString(int code) {
    switch (code) {
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
            // #6
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

            // #11
        case EDAMErrorCode::ENML_VALIDATION:
            return "ENML_VALIDATION";
        case EDAMErrorCode::SHARD_UNAVAILABLE:
            return "SHARD_UNAVAILABLE";
        case EDAMErrorCode::LEN_TOO_SHORT:
            return "LEN_TOO_SHORT";
        case EDAMErrorCode::LEN_TOO_LONG:
            return "LEN_TOO_LONG";
        case EDAMErrorCode::LEN_TOO_FEW:
            return "TOO_FEW";
            // #16
        case EDAMErrorCode::TOO_MANY:
            return "TOO_MANY";
        case EDAMErrorCode::UNSUPPORTED_OPERATION:
            return "UNSUPPORTED_OPERATION";
        case EDAMErrorCode::TAKEN_DOWN:
            return "TAKEN_DOWN";
        case EDAMErrorCode::RATE_LIMIT_REACHED:
            return "RATE_LIMIT_REACHED";

        default:
            return QString("UNKNOWN(").append(QString::number(code)).append(")");
    }
}


QString CommunicationError::communicationErrorTypeToString(CommunicationErrorType type) {
    switch (type) {
        case None:
            return "None";
        case Unknown:
            return "Unknown";
        case EDAMSystemException:
            return "EDAMSystemException";
        case EDAMUserException:
            return "EDAMUserException";
        case TTransportException:
            return "TTransportException";
        case EDAMNotFoundException:
            return "EDAMNotFoundException";
        case StdException:
            return "StdException";
        case TSSLException:
            return "TSSLException";
        case TException:
            return "TException";
        case RateLimitExceeded:
            return "RateLimitExceeded";
        case ThriftException:
            return "ThriftException";

        default:
            return QString("UNKNOWN(").append(QString::number(type)).append(")");
    }
}
