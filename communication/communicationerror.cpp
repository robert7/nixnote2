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
        msg.append("[").append(code).append("]");
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

QString CommunicationError::communicationErrorTypeToString(CommunicationErrorType v) {
    switch (v) {
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
            return QString("enum:") + QString::number(v);
    }
}
