/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */


#include <generated/services.h>
#include "../impl.h"
#include "../impl.h"
#include "types_impl.h"
#include <qt4helpers.h>

namespace qevercloud {
QByteArray NoteStore_getSyncState_prepareParams(QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getSyncState"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getSyncState_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

SyncState NoteStore_getSyncState_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    SyncState result = SyncState();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getSyncState")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SyncState v;
                readSyncState(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getSyncState: missing result"));
    }
    return result;
}

QVariant NoteStore_getSyncState_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getSyncState_readReply(reply));
}

SyncState NoteStore::getSyncState(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getSyncState_prepareParams(authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getSyncState_readReply(reply);
}

AsyncResult* NoteStore::getSyncStateAsync(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getSyncState_prepareParams(authenticationToken);
    return new AsyncResult(m_url, params, NoteStore_getSyncState_readReplyAsync);
}

QByteArray NoteStore_getFilteredSyncChunk_prepareParams(QString authenticationToken, qint32 afterUSN, qint32 maxEntries, const SyncChunkFilter& filter)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getFilteredSyncChunk"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getFilteredSyncChunk_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("afterUSN"), ThriftFieldType::T_I32, 2);
    w.writeI32(afterUSN);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("maxEntries"), ThriftFieldType::T_I32, 3);
    w.writeI32(maxEntries);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("filter"), ThriftFieldType::T_STRUCT, 4);
    writeSyncChunkFilter(w, filter);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

SyncChunk NoteStore_getFilteredSyncChunk_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    SyncChunk result = SyncChunk();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getFilteredSyncChunk")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SyncChunk v;
                readSyncChunk(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getFilteredSyncChunk: missing result"));
    }
    return result;
}

QVariant NoteStore_getFilteredSyncChunk_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getFilteredSyncChunk_readReply(reply));
}

SyncChunk NoteStore::getFilteredSyncChunk(qint32 afterUSN, qint32 maxEntries, const SyncChunkFilter& filter, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getFilteredSyncChunk_prepareParams(authenticationToken, afterUSN, maxEntries, filter);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getFilteredSyncChunk_readReply(reply);
}

AsyncResult* NoteStore::getFilteredSyncChunkAsync(qint32 afterUSN, qint32 maxEntries, const SyncChunkFilter& filter, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getFilteredSyncChunk_prepareParams(authenticationToken, afterUSN, maxEntries, filter);
    return new AsyncResult(m_url, params, NoteStore_getFilteredSyncChunk_readReplyAsync);
}

QByteArray NoteStore_getLinkedNotebookSyncState_prepareParams(QString authenticationToken, const LinkedNotebook& linkedNotebook)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getLinkedNotebookSyncState"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getLinkedNotebookSyncState_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("linkedNotebook"), ThriftFieldType::T_STRUCT, 2);
    writeLinkedNotebook(w, linkedNotebook);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

SyncState NoteStore_getLinkedNotebookSyncState_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    SyncState result = SyncState();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getLinkedNotebookSyncState")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SyncState v;
                readSyncState(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getLinkedNotebookSyncState: missing result"));
    }
    return result;
}

QVariant NoteStore_getLinkedNotebookSyncState_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getLinkedNotebookSyncState_readReply(reply));
}

SyncState NoteStore::getLinkedNotebookSyncState(const LinkedNotebook& linkedNotebook, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getLinkedNotebookSyncState_prepareParams(authenticationToken, linkedNotebook);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getLinkedNotebookSyncState_readReply(reply);
}

AsyncResult* NoteStore::getLinkedNotebookSyncStateAsync(const LinkedNotebook& linkedNotebook, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getLinkedNotebookSyncState_prepareParams(authenticationToken, linkedNotebook);
    return new AsyncResult(m_url, params, NoteStore_getLinkedNotebookSyncState_readReplyAsync);
}

QByteArray NoteStore_getLinkedNotebookSyncChunk_prepareParams(QString authenticationToken, const LinkedNotebook& linkedNotebook, qint32 afterUSN, qint32 maxEntries, bool fullSyncOnly)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getLinkedNotebookSyncChunk"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getLinkedNotebookSyncChunk_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("linkedNotebook"), ThriftFieldType::T_STRUCT, 2);
    writeLinkedNotebook(w, linkedNotebook);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("afterUSN"), ThriftFieldType::T_I32, 3);
    w.writeI32(afterUSN);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("maxEntries"), ThriftFieldType::T_I32, 4);
    w.writeI32(maxEntries);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("fullSyncOnly"), ThriftFieldType::T_BOOL, 5);
    w.writeBool(fullSyncOnly);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

SyncChunk NoteStore_getLinkedNotebookSyncChunk_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    SyncChunk result = SyncChunk();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getLinkedNotebookSyncChunk")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SyncChunk v;
                readSyncChunk(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getLinkedNotebookSyncChunk: missing result"));
    }
    return result;
}

QVariant NoteStore_getLinkedNotebookSyncChunk_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getLinkedNotebookSyncChunk_readReply(reply));
}

SyncChunk NoteStore::getLinkedNotebookSyncChunk(const LinkedNotebook& linkedNotebook, qint32 afterUSN, qint32 maxEntries, bool fullSyncOnly, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getLinkedNotebookSyncChunk_prepareParams(authenticationToken, linkedNotebook, afterUSN, maxEntries, fullSyncOnly);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getLinkedNotebookSyncChunk_readReply(reply);
}

AsyncResult* NoteStore::getLinkedNotebookSyncChunkAsync(const LinkedNotebook& linkedNotebook, qint32 afterUSN, qint32 maxEntries, bool fullSyncOnly, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getLinkedNotebookSyncChunk_prepareParams(authenticationToken, linkedNotebook, afterUSN, maxEntries, fullSyncOnly);
    return new AsyncResult(m_url, params, NoteStore_getLinkedNotebookSyncChunk_readReplyAsync);
}

QByteArray NoteStore_listNotebooks_prepareParams(QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("listNotebooks"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_listNotebooks_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QList< Notebook > NoteStore_listNotebooks_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList< Notebook > result = QList< Notebook >();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listNotebooks")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList< Notebook > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (listNotebooks.result)"));
                for(qint32 i = 0; i < size; i++) {
                    Notebook elem;
                    readNotebook(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("listNotebooks: missing result"));
    }
    return result;
}

QVariant NoteStore_listNotebooks_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_listNotebooks_readReply(reply));
}

QList< Notebook > NoteStore::listNotebooks(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listNotebooks_prepareParams(authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_listNotebooks_readReply(reply);
}

AsyncResult* NoteStore::listNotebooksAsync(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listNotebooks_prepareParams(authenticationToken);
    return new AsyncResult(m_url, params, NoteStore_listNotebooks_readReplyAsync);
}

QByteArray NoteStore_listAccessibleBusinessNotebooks_prepareParams(QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("listAccessibleBusinessNotebooks"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_listAccessibleBusinessNotebooks_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QList< Notebook > NoteStore_listAccessibleBusinessNotebooks_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList< Notebook > result = QList< Notebook >();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listAccessibleBusinessNotebooks")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList< Notebook > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (listAccessibleBusinessNotebooks.result)"));
                for(qint32 i = 0; i < size; i++) {
                    Notebook elem;
                    readNotebook(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("listAccessibleBusinessNotebooks: missing result"));
    }
    return result;
}

QVariant NoteStore_listAccessibleBusinessNotebooks_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_listAccessibleBusinessNotebooks_readReply(reply));
}

QList< Notebook > NoteStore::listAccessibleBusinessNotebooks(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listAccessibleBusinessNotebooks_prepareParams(authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_listAccessibleBusinessNotebooks_readReply(reply);
}

AsyncResult* NoteStore::listAccessibleBusinessNotebooksAsync(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listAccessibleBusinessNotebooks_prepareParams(authenticationToken);
    return new AsyncResult(m_url, params, NoteStore_listAccessibleBusinessNotebooks_readReplyAsync);
}

QByteArray NoteStore_getNotebook_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getNotebook"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getNotebook_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Notebook NoteStore_getNotebook_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Notebook result = Notebook();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNotebook")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Notebook v;
                readNotebook(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getNotebook: missing result"));
    }
    return result;
}

QVariant NoteStore_getNotebook_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getNotebook_readReply(reply));
}

Notebook NoteStore::getNotebook(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNotebook_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getNotebook_readReply(reply);
}

AsyncResult* NoteStore::getNotebookAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNotebook_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_getNotebook_readReplyAsync);
}

QByteArray NoteStore_getDefaultNotebook_prepareParams(QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getDefaultNotebook"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getDefaultNotebook_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Notebook NoteStore_getDefaultNotebook_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Notebook result = Notebook();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getDefaultNotebook")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Notebook v;
                readNotebook(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getDefaultNotebook: missing result"));
    }
    return result;
}

QVariant NoteStore_getDefaultNotebook_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getDefaultNotebook_readReply(reply));
}

Notebook NoteStore::getDefaultNotebook(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getDefaultNotebook_prepareParams(authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getDefaultNotebook_readReply(reply);
}

AsyncResult* NoteStore::getDefaultNotebookAsync(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getDefaultNotebook_prepareParams(authenticationToken);
    return new AsyncResult(m_url, params, NoteStore_getDefaultNotebook_readReplyAsync);
}

QByteArray NoteStore_createNotebook_prepareParams(QString authenticationToken, const Notebook& notebook)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("createNotebook"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_createNotebook_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("notebook"), ThriftFieldType::T_STRUCT, 2);
    writeNotebook(w, notebook);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Notebook NoteStore_createNotebook_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Notebook result = Notebook();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("createNotebook")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Notebook v;
                readNotebook(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("createNotebook: missing result"));
    }
    return result;
}

QVariant NoteStore_createNotebook_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_createNotebook_readReply(reply));
}

Notebook NoteStore::createNotebook(const Notebook& notebook, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_createNotebook_prepareParams(authenticationToken, notebook);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_createNotebook_readReply(reply);
}

AsyncResult* NoteStore::createNotebookAsync(const Notebook& notebook, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_createNotebook_prepareParams(authenticationToken, notebook);
    return new AsyncResult(m_url, params, NoteStore_createNotebook_readReplyAsync);
}

QByteArray NoteStore_updateNotebook_prepareParams(QString authenticationToken, const Notebook& notebook)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("updateNotebook"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_updateNotebook_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("notebook"), ThriftFieldType::T_STRUCT, 2);
    writeNotebook(w, notebook);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_updateNotebook_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateNotebook")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("updateNotebook: missing result"));
    }
    return result;
}

QVariant NoteStore_updateNotebook_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_updateNotebook_readReply(reply));
}

qint32 NoteStore::updateNotebook(const Notebook& notebook, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateNotebook_prepareParams(authenticationToken, notebook);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_updateNotebook_readReply(reply);
}

AsyncResult* NoteStore::updateNotebookAsync(const Notebook& notebook, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateNotebook_prepareParams(authenticationToken, notebook);
    return new AsyncResult(m_url, params, NoteStore_updateNotebook_readReplyAsync);
}

QByteArray NoteStore_expungeNotebook_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("expungeNotebook"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_expungeNotebook_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_expungeNotebook_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("expungeNotebook")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("expungeNotebook: missing result"));
    }
    return result;
}

QVariant NoteStore_expungeNotebook_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_expungeNotebook_readReply(reply));
}

qint32 NoteStore::expungeNotebook(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_expungeNotebook_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_expungeNotebook_readReply(reply);
}

AsyncResult* NoteStore::expungeNotebookAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_expungeNotebook_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_expungeNotebook_readReplyAsync);
}

QByteArray NoteStore_listTags_prepareParams(QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("listTags"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_listTags_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QList< Tag > NoteStore_listTags_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList< Tag > result = QList< Tag >();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listTags")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList< Tag > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (listTags.result)"));
                for(qint32 i = 0; i < size; i++) {
                    Tag elem;
                    readTag(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("listTags: missing result"));
    }
    return result;
}

QVariant NoteStore_listTags_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_listTags_readReply(reply));
}

QList< Tag > NoteStore::listTags(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listTags_prepareParams(authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_listTags_readReply(reply);
}

AsyncResult* NoteStore::listTagsAsync(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listTags_prepareParams(authenticationToken);
    return new AsyncResult(m_url, params, NoteStore_listTags_readReplyAsync);
}

QByteArray NoteStore_listTagsByNotebook_prepareParams(QString authenticationToken, Guid notebookGuid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("listTagsByNotebook"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_listTagsByNotebook_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("notebookGuid"), ThriftFieldType::T_STRING, 2);
    w.writeString(notebookGuid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QList< Tag > NoteStore_listTagsByNotebook_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList< Tag > result = QList< Tag >();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listTagsByNotebook")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList< Tag > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (listTagsByNotebook.result)"));
                for(qint32 i = 0; i < size; i++) {
                    Tag elem;
                    readTag(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("listTagsByNotebook: missing result"));
    }
    return result;
}

QVariant NoteStore_listTagsByNotebook_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_listTagsByNotebook_readReply(reply));
}

QList< Tag > NoteStore::listTagsByNotebook(Guid notebookGuid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listTagsByNotebook_prepareParams(authenticationToken, notebookGuid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_listTagsByNotebook_readReply(reply);
}

AsyncResult* NoteStore::listTagsByNotebookAsync(Guid notebookGuid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listTagsByNotebook_prepareParams(authenticationToken, notebookGuid);
    return new AsyncResult(m_url, params, NoteStore_listTagsByNotebook_readReplyAsync);
}

QByteArray NoteStore_getTag_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getTag"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getTag_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Tag NoteStore_getTag_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Tag result = Tag();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getTag")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Tag v;
                readTag(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getTag: missing result"));
    }
    return result;
}

QVariant NoteStore_getTag_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getTag_readReply(reply));
}

Tag NoteStore::getTag(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getTag_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getTag_readReply(reply);
}

AsyncResult* NoteStore::getTagAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getTag_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_getTag_readReplyAsync);
}

QByteArray NoteStore_createTag_prepareParams(QString authenticationToken, const Tag& tag)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("createTag"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_createTag_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("tag"), ThriftFieldType::T_STRUCT, 2);
    writeTag(w, tag);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Tag NoteStore_createTag_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Tag result = Tag();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("createTag")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Tag v;
                readTag(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("createTag: missing result"));
    }
    return result;
}

QVariant NoteStore_createTag_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_createTag_readReply(reply));
}

Tag NoteStore::createTag(const Tag& tag, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_createTag_prepareParams(authenticationToken, tag);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_createTag_readReply(reply);
}

AsyncResult* NoteStore::createTagAsync(const Tag& tag, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_createTag_prepareParams(authenticationToken, tag);
    return new AsyncResult(m_url, params, NoteStore_createTag_readReplyAsync);
}

QByteArray NoteStore_updateTag_prepareParams(QString authenticationToken, const Tag& tag)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("updateTag"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_updateTag_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("tag"), ThriftFieldType::T_STRUCT, 2);
    writeTag(w, tag);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_updateTag_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateTag")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("updateTag: missing result"));
    }
    return result;
}

QVariant NoteStore_updateTag_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_updateTag_readReply(reply));
}

qint32 NoteStore::updateTag(const Tag& tag, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateTag_prepareParams(authenticationToken, tag);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_updateTag_readReply(reply);
}

AsyncResult* NoteStore::updateTagAsync(const Tag& tag, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateTag_prepareParams(authenticationToken, tag);
    return new AsyncResult(m_url, params, NoteStore_updateTag_readReplyAsync);
}

QByteArray NoteStore_untagAll_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("untagAll"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_untagAll_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

void NoteStore_untagAll_readReply(QByteArray reply)
{
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("untagAll")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
}

QVariant NoteStore_untagAll_readReplyAsync(QByteArray reply)
{
    NoteStore_untagAll_readReply(reply);
    return QVariant();
}

void NoteStore::untagAll(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_untagAll_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    NoteStore_untagAll_readReply(reply);
}

AsyncResult* NoteStore::untagAllAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_untagAll_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_untagAll_readReplyAsync);
}

QByteArray NoteStore_expungeTag_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("expungeTag"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_expungeTag_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_expungeTag_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("expungeTag")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("expungeTag: missing result"));
    }
    return result;
}

QVariant NoteStore_expungeTag_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_expungeTag_readReply(reply));
}

qint32 NoteStore::expungeTag(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_expungeTag_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_expungeTag_readReply(reply);
}

AsyncResult* NoteStore::expungeTagAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_expungeTag_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_expungeTag_readReplyAsync);
}

QByteArray NoteStore_listSearches_prepareParams(QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("listSearches"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_listSearches_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QList< SavedSearch > NoteStore_listSearches_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList< SavedSearch > result = QList< SavedSearch >();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listSearches")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList< SavedSearch > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (listSearches.result)"));
                for(qint32 i = 0; i < size; i++) {
                    SavedSearch elem;
                    readSavedSearch(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("listSearches: missing result"));
    }
    return result;
}

QVariant NoteStore_listSearches_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_listSearches_readReply(reply));
}

QList< SavedSearch > NoteStore::listSearches(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listSearches_prepareParams(authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_listSearches_readReply(reply);
}

AsyncResult* NoteStore::listSearchesAsync(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listSearches_prepareParams(authenticationToken);
    return new AsyncResult(m_url, params, NoteStore_listSearches_readReplyAsync);
}

QByteArray NoteStore_getSearch_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getSearch"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getSearch_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

SavedSearch NoteStore_getSearch_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    SavedSearch result = SavedSearch();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getSearch")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SavedSearch v;
                readSavedSearch(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getSearch: missing result"));
    }
    return result;
}

QVariant NoteStore_getSearch_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getSearch_readReply(reply));
}

SavedSearch NoteStore::getSearch(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getSearch_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getSearch_readReply(reply);
}

AsyncResult* NoteStore::getSearchAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getSearch_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_getSearch_readReplyAsync);
}

QByteArray NoteStore_createSearch_prepareParams(QString authenticationToken, const SavedSearch& search)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("createSearch"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_createSearch_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("search"), ThriftFieldType::T_STRUCT, 2);
    writeSavedSearch(w, search);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

SavedSearch NoteStore_createSearch_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    SavedSearch result = SavedSearch();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("createSearch")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SavedSearch v;
                readSavedSearch(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("createSearch: missing result"));
    }
    return result;
}

QVariant NoteStore_createSearch_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_createSearch_readReply(reply));
}

SavedSearch NoteStore::createSearch(const SavedSearch& search, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_createSearch_prepareParams(authenticationToken, search);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_createSearch_readReply(reply);
}

AsyncResult* NoteStore::createSearchAsync(const SavedSearch& search, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_createSearch_prepareParams(authenticationToken, search);
    return new AsyncResult(m_url, params, NoteStore_createSearch_readReplyAsync);
}

QByteArray NoteStore_updateSearch_prepareParams(QString authenticationToken, const SavedSearch& search)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("updateSearch"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_updateSearch_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("search"), ThriftFieldType::T_STRUCT, 2);
    writeSavedSearch(w, search);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_updateSearch_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateSearch")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("updateSearch: missing result"));
    }
    return result;
}

QVariant NoteStore_updateSearch_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_updateSearch_readReply(reply));
}

qint32 NoteStore::updateSearch(const SavedSearch& search, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateSearch_prepareParams(authenticationToken, search);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_updateSearch_readReply(reply);
}

AsyncResult* NoteStore::updateSearchAsync(const SavedSearch& search, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateSearch_prepareParams(authenticationToken, search);
    return new AsyncResult(m_url, params, NoteStore_updateSearch_readReplyAsync);
}

QByteArray NoteStore_expungeSearch_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("expungeSearch"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_expungeSearch_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_expungeSearch_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("expungeSearch")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("expungeSearch: missing result"));
    }
    return result;
}

QVariant NoteStore_expungeSearch_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_expungeSearch_readReply(reply));
}

qint32 NoteStore::expungeSearch(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_expungeSearch_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_expungeSearch_readReply(reply);
}

AsyncResult* NoteStore::expungeSearchAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_expungeSearch_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_expungeSearch_readReplyAsync);
}

QByteArray NoteStore_findNoteOffset_prepareParams(QString authenticationToken, const NoteFilter& filter, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("findNoteOffset"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_findNoteOffset_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("filter"), ThriftFieldType::T_STRUCT, 2);
    writeNoteFilter(w, filter);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 3);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_findNoteOffset_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("findNoteOffset")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("findNoteOffset: missing result"));
    }
    return result;
}

QVariant NoteStore_findNoteOffset_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_findNoteOffset_readReply(reply));
}

qint32 NoteStore::findNoteOffset(const NoteFilter& filter, Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_findNoteOffset_prepareParams(authenticationToken, filter, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_findNoteOffset_readReply(reply);
}

AsyncResult* NoteStore::findNoteOffsetAsync(const NoteFilter& filter, Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_findNoteOffset_prepareParams(authenticationToken, filter, guid);
    return new AsyncResult(m_url, params, NoteStore_findNoteOffset_readReplyAsync);
}

QByteArray NoteStore_findNotesMetadata_prepareParams(QString authenticationToken, const NoteFilter& filter, qint32 offset, qint32 maxNotes, const NotesMetadataResultSpec& resultSpec)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("findNotesMetadata"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_findNotesMetadata_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("filter"), ThriftFieldType::T_STRUCT, 2);
    writeNoteFilter(w, filter);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("offset"), ThriftFieldType::T_I32, 3);
    w.writeI32(offset);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("maxNotes"), ThriftFieldType::T_I32, 4);
    w.writeI32(maxNotes);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("resultSpec"), ThriftFieldType::T_STRUCT, 5);
    writeNotesMetadataResultSpec(w, resultSpec);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

NotesMetadataList NoteStore_findNotesMetadata_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    NotesMetadataList result = NotesMetadataList();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("findNotesMetadata")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                NotesMetadataList v;
                readNotesMetadataList(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("findNotesMetadata: missing result"));
    }
    return result;
}

QVariant NoteStore_findNotesMetadata_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_findNotesMetadata_readReply(reply));
}

NotesMetadataList NoteStore::findNotesMetadata(const NoteFilter& filter, qint32 offset, qint32 maxNotes, const NotesMetadataResultSpec& resultSpec, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_findNotesMetadata_prepareParams(authenticationToken, filter, offset, maxNotes, resultSpec);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_findNotesMetadata_readReply(reply);
}

AsyncResult* NoteStore::findNotesMetadataAsync(const NoteFilter& filter, qint32 offset, qint32 maxNotes, const NotesMetadataResultSpec& resultSpec, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_findNotesMetadata_prepareParams(authenticationToken, filter, offset, maxNotes, resultSpec);
    return new AsyncResult(m_url, params, NoteStore_findNotesMetadata_readReplyAsync);
}

QByteArray NoteStore_findNoteCounts_prepareParams(QString authenticationToken, const NoteFilter& filter, bool withTrash)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("findNoteCounts"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_findNoteCounts_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("filter"), ThriftFieldType::T_STRUCT, 2);
    writeNoteFilter(w, filter);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withTrash"), ThriftFieldType::T_BOOL, 3);
    w.writeBool(withTrash);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

NoteCollectionCounts NoteStore_findNoteCounts_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    NoteCollectionCounts result = NoteCollectionCounts();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("findNoteCounts")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                NoteCollectionCounts v;
                readNoteCollectionCounts(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("findNoteCounts: missing result"));
    }
    return result;
}

QVariant NoteStore_findNoteCounts_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_findNoteCounts_readReply(reply));
}

NoteCollectionCounts NoteStore::findNoteCounts(const NoteFilter& filter, bool withTrash, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_findNoteCounts_prepareParams(authenticationToken, filter, withTrash);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_findNoteCounts_readReply(reply);
}

AsyncResult* NoteStore::findNoteCountsAsync(const NoteFilter& filter, bool withTrash, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_findNoteCounts_prepareParams(authenticationToken, filter, withTrash);
    return new AsyncResult(m_url, params, NoteStore_findNoteCounts_readReplyAsync);
}

QByteArray NoteStore_getNoteWithResultSpec_prepareParams(QString authenticationToken, Guid guid, const NoteResultSpec& resultSpec)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getNoteWithResultSpec"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getNoteWithResultSpec_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("resultSpec"), ThriftFieldType::T_STRUCT, 3);
    writeNoteResultSpec(w, resultSpec);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Note NoteStore_getNoteWithResultSpec_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Note result = Note();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNoteWithResultSpec")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Note v;
                readNote(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getNoteWithResultSpec: missing result"));
    }
    return result;
}

QVariant NoteStore_getNoteWithResultSpec_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getNoteWithResultSpec_readReply(reply));
}

Note NoteStore::getNoteWithResultSpec(Guid guid, const NoteResultSpec& resultSpec, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNoteWithResultSpec_prepareParams(authenticationToken, guid, resultSpec);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getNoteWithResultSpec_readReply(reply);
}

AsyncResult* NoteStore::getNoteWithResultSpecAsync(Guid guid, const NoteResultSpec& resultSpec, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNoteWithResultSpec_prepareParams(authenticationToken, guid, resultSpec);
    return new AsyncResult(m_url, params, NoteStore_getNoteWithResultSpec_readReplyAsync);
}

QByteArray NoteStore_getNote_prepareParams(QString authenticationToken, Guid guid, bool withContent, bool withResourcesData, bool withResourcesRecognition, bool withResourcesAlternateData)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getNote"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getNote_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withContent"), ThriftFieldType::T_BOOL, 3);
    w.writeBool(withContent);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withResourcesData"), ThriftFieldType::T_BOOL, 4);
    w.writeBool(withResourcesData);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withResourcesRecognition"), ThriftFieldType::T_BOOL, 5);
    w.writeBool(withResourcesRecognition);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withResourcesAlternateData"), ThriftFieldType::T_BOOL, 6);
    w.writeBool(withResourcesAlternateData);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Note NoteStore_getNote_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Note result = Note();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNote")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Note v;
                readNote(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getNote: missing result"));
    }
    return result;
}

QVariant NoteStore_getNote_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getNote_readReply(reply));
}

Note NoteStore::getNote(Guid guid, bool withContent, bool withResourcesData, bool withResourcesRecognition, bool withResourcesAlternateData, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNote_prepareParams(authenticationToken, guid, withContent, withResourcesData, withResourcesRecognition, withResourcesAlternateData);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getNote_readReply(reply);
}

AsyncResult* NoteStore::getNoteAsync(Guid guid, bool withContent, bool withResourcesData, bool withResourcesRecognition, bool withResourcesAlternateData, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNote_prepareParams(authenticationToken, guid, withContent, withResourcesData, withResourcesRecognition, withResourcesAlternateData);
    return new AsyncResult(m_url, params, NoteStore_getNote_readReplyAsync);
}

QByteArray NoteStore_getNoteApplicationData_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getNoteApplicationData"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getNoteApplicationData_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

LazyMap NoteStore_getNoteApplicationData_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    LazyMap result = LazyMap();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNoteApplicationData")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                LazyMap v;
                readLazyMap(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getNoteApplicationData: missing result"));
    }
    return result;
}

QVariant NoteStore_getNoteApplicationData_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getNoteApplicationData_readReply(reply));
}

LazyMap NoteStore::getNoteApplicationData(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNoteApplicationData_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getNoteApplicationData_readReply(reply);
}

AsyncResult* NoteStore::getNoteApplicationDataAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNoteApplicationData_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_getNoteApplicationData_readReplyAsync);
}

QByteArray NoteStore_getNoteApplicationDataEntry_prepareParams(QString authenticationToken, Guid guid, QString key)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getNoteApplicationDataEntry"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getNoteApplicationDataEntry_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("key"), ThriftFieldType::T_STRING, 3);
    w.writeString(key);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QString NoteStore_getNoteApplicationDataEntry_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QString result = QString();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNoteApplicationDataEntry")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QString v;
                r.readString(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getNoteApplicationDataEntry: missing result"));
    }
    return result;
}

QVariant NoteStore_getNoteApplicationDataEntry_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getNoteApplicationDataEntry_readReply(reply));
}

QString NoteStore::getNoteApplicationDataEntry(Guid guid, QString key, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNoteApplicationDataEntry_prepareParams(authenticationToken, guid, key);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getNoteApplicationDataEntry_readReply(reply);
}

AsyncResult* NoteStore::getNoteApplicationDataEntryAsync(Guid guid, QString key, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNoteApplicationDataEntry_prepareParams(authenticationToken, guid, key);
    return new AsyncResult(m_url, params, NoteStore_getNoteApplicationDataEntry_readReplyAsync);
}

QByteArray NoteStore_setNoteApplicationDataEntry_prepareParams(QString authenticationToken, Guid guid, QString key, QString value)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("setNoteApplicationDataEntry"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_setNoteApplicationDataEntry_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("key"), ThriftFieldType::T_STRING, 3);
    w.writeString(key);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("value"), ThriftFieldType::T_STRING, 4);
    w.writeString(value);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_setNoteApplicationDataEntry_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("setNoteApplicationDataEntry")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("setNoteApplicationDataEntry: missing result"));
    }
    return result;
}

QVariant NoteStore_setNoteApplicationDataEntry_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_setNoteApplicationDataEntry_readReply(reply));
}

qint32 NoteStore::setNoteApplicationDataEntry(Guid guid, QString key, QString value, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_setNoteApplicationDataEntry_prepareParams(authenticationToken, guid, key, value);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_setNoteApplicationDataEntry_readReply(reply);
}

AsyncResult* NoteStore::setNoteApplicationDataEntryAsync(Guid guid, QString key, QString value, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_setNoteApplicationDataEntry_prepareParams(authenticationToken, guid, key, value);
    return new AsyncResult(m_url, params, NoteStore_setNoteApplicationDataEntry_readReplyAsync);
}

QByteArray NoteStore_unsetNoteApplicationDataEntry_prepareParams(QString authenticationToken, Guid guid, QString key)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("unsetNoteApplicationDataEntry"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_unsetNoteApplicationDataEntry_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("key"), ThriftFieldType::T_STRING, 3);
    w.writeString(key);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_unsetNoteApplicationDataEntry_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("unsetNoteApplicationDataEntry")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("unsetNoteApplicationDataEntry: missing result"));
    }
    return result;
}

QVariant NoteStore_unsetNoteApplicationDataEntry_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_unsetNoteApplicationDataEntry_readReply(reply));
}

qint32 NoteStore::unsetNoteApplicationDataEntry(Guid guid, QString key, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_unsetNoteApplicationDataEntry_prepareParams(authenticationToken, guid, key);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_unsetNoteApplicationDataEntry_readReply(reply);
}

AsyncResult* NoteStore::unsetNoteApplicationDataEntryAsync(Guid guid, QString key, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_unsetNoteApplicationDataEntry_prepareParams(authenticationToken, guid, key);
    return new AsyncResult(m_url, params, NoteStore_unsetNoteApplicationDataEntry_readReplyAsync);
}

QByteArray NoteStore_getNoteContent_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getNoteContent"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getNoteContent_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QString NoteStore_getNoteContent_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QString result = QString();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNoteContent")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QString v;
                r.readString(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getNoteContent: missing result"));
    }
    return result;
}

QVariant NoteStore_getNoteContent_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getNoteContent_readReply(reply));
}

QString NoteStore::getNoteContent(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNoteContent_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getNoteContent_readReply(reply);
}

AsyncResult* NoteStore::getNoteContentAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNoteContent_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_getNoteContent_readReplyAsync);
}

QByteArray NoteStore_getNoteSearchText_prepareParams(QString authenticationToken, Guid guid, bool noteOnly, bool tokenizeForIndexing)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getNoteSearchText"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getNoteSearchText_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("noteOnly"), ThriftFieldType::T_BOOL, 3);
    w.writeBool(noteOnly);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("tokenizeForIndexing"), ThriftFieldType::T_BOOL, 4);
    w.writeBool(tokenizeForIndexing);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QString NoteStore_getNoteSearchText_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QString result = QString();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNoteSearchText")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QString v;
                r.readString(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getNoteSearchText: missing result"));
    }
    return result;
}

QVariant NoteStore_getNoteSearchText_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getNoteSearchText_readReply(reply));
}

QString NoteStore::getNoteSearchText(Guid guid, bool noteOnly, bool tokenizeForIndexing, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNoteSearchText_prepareParams(authenticationToken, guid, noteOnly, tokenizeForIndexing);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getNoteSearchText_readReply(reply);
}

AsyncResult* NoteStore::getNoteSearchTextAsync(Guid guid, bool noteOnly, bool tokenizeForIndexing, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNoteSearchText_prepareParams(authenticationToken, guid, noteOnly, tokenizeForIndexing);
    return new AsyncResult(m_url, params, NoteStore_getNoteSearchText_readReplyAsync);
}

QByteArray NoteStore_getResourceSearchText_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getResourceSearchText"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getResourceSearchText_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QString NoteStore_getResourceSearchText_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QString result = QString();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceSearchText")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QString v;
                r.readString(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getResourceSearchText: missing result"));
    }
    return result;
}

QVariant NoteStore_getResourceSearchText_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getResourceSearchText_readReply(reply));
}

QString NoteStore::getResourceSearchText(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceSearchText_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getResourceSearchText_readReply(reply);
}

AsyncResult* NoteStore::getResourceSearchTextAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceSearchText_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_getResourceSearchText_readReplyAsync);
}

QByteArray NoteStore_getNoteTagNames_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getNoteTagNames"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getNoteTagNames_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QStringList NoteStore_getNoteTagNames_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QStringList result = QStringList();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNoteTagNames")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QStringList v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRING) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (getNoteTagNames.result)"));
                for(qint32 i = 0; i < size; i++) {
                    QString elem;
                    r.readString(elem);
                    v.append(elem);
                }
                r.readListEnd();
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getNoteTagNames: missing result"));
    }
    return result;
}

QVariant NoteStore_getNoteTagNames_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getNoteTagNames_readReply(reply));
}

QStringList NoteStore::getNoteTagNames(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNoteTagNames_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getNoteTagNames_readReply(reply);
}

AsyncResult* NoteStore::getNoteTagNamesAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNoteTagNames_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_getNoteTagNames_readReplyAsync);
}

QByteArray NoteStore_createNote_prepareParams(QString authenticationToken, const Note& note)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("createNote"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_createNote_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("note"), ThriftFieldType::T_STRUCT, 2);
    writeNote(w, note);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Note NoteStore_createNote_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Note result = Note();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("createNote")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Note v;
                readNote(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("createNote: missing result"));
    }
    return result;
}

QVariant NoteStore_createNote_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_createNote_readReply(reply));
}

Note NoteStore::createNote(const Note& note, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_createNote_prepareParams(authenticationToken, note);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_createNote_readReply(reply);
}

AsyncResult* NoteStore::createNoteAsync(const Note& note, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_createNote_prepareParams(authenticationToken, note);
    return new AsyncResult(m_url, params, NoteStore_createNote_readReplyAsync);
}

QByteArray NoteStore_updateNote_prepareParams(QString authenticationToken, const Note& note)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("updateNote"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_updateNote_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("note"), ThriftFieldType::T_STRUCT, 2);
    writeNote(w, note);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Note NoteStore_updateNote_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Note result = Note();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateNote")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Note v;
                readNote(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("updateNote: missing result"));
    }
    return result;
}

QVariant NoteStore_updateNote_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_updateNote_readReply(reply));
}

Note NoteStore::updateNote(const Note& note, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateNote_prepareParams(authenticationToken, note);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_updateNote_readReply(reply);
}

AsyncResult* NoteStore::updateNoteAsync(const Note& note, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateNote_prepareParams(authenticationToken, note);
    return new AsyncResult(m_url, params, NoteStore_updateNote_readReplyAsync);
}

QByteArray NoteStore_deleteNote_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("deleteNote"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_deleteNote_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_deleteNote_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("deleteNote")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("deleteNote: missing result"));
    }
    return result;
}

QVariant NoteStore_deleteNote_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_deleteNote_readReply(reply));
}

qint32 NoteStore::deleteNote(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_deleteNote_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_deleteNote_readReply(reply);
}

AsyncResult* NoteStore::deleteNoteAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_deleteNote_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_deleteNote_readReplyAsync);
}

QByteArray NoteStore_expungeNote_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("expungeNote"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_expungeNote_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_expungeNote_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("expungeNote")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("expungeNote: missing result"));
    }
    return result;
}

QVariant NoteStore_expungeNote_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_expungeNote_readReply(reply));
}

qint32 NoteStore::expungeNote(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_expungeNote_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_expungeNote_readReply(reply);
}

AsyncResult* NoteStore::expungeNoteAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_expungeNote_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_expungeNote_readReplyAsync);
}

QByteArray NoteStore_copyNote_prepareParams(QString authenticationToken, Guid noteGuid, Guid toNotebookGuid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("copyNote"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_copyNote_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("noteGuid"), ThriftFieldType::T_STRING, 2);
    w.writeString(noteGuid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("toNotebookGuid"), ThriftFieldType::T_STRING, 3);
    w.writeString(toNotebookGuid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Note NoteStore_copyNote_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Note result = Note();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("copyNote")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Note v;
                readNote(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("copyNote: missing result"));
    }
    return result;
}

QVariant NoteStore_copyNote_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_copyNote_readReply(reply));
}

Note NoteStore::copyNote(Guid noteGuid, Guid toNotebookGuid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_copyNote_prepareParams(authenticationToken, noteGuid, toNotebookGuid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_copyNote_readReply(reply);
}

AsyncResult* NoteStore::copyNoteAsync(Guid noteGuid, Guid toNotebookGuid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_copyNote_prepareParams(authenticationToken, noteGuid, toNotebookGuid);
    return new AsyncResult(m_url, params, NoteStore_copyNote_readReplyAsync);
}

QByteArray NoteStore_listNoteVersions_prepareParams(QString authenticationToken, Guid noteGuid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("listNoteVersions"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_listNoteVersions_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("noteGuid"), ThriftFieldType::T_STRING, 2);
    w.writeString(noteGuid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QList< NoteVersionId > NoteStore_listNoteVersions_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList< NoteVersionId > result = QList< NoteVersionId >();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listNoteVersions")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList< NoteVersionId > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (listNoteVersions.result)"));
                for(qint32 i = 0; i < size; i++) {
                    NoteVersionId elem;
                    readNoteVersionId(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("listNoteVersions: missing result"));
    }
    return result;
}

QVariant NoteStore_listNoteVersions_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_listNoteVersions_readReply(reply));
}

QList< NoteVersionId > NoteStore::listNoteVersions(Guid noteGuid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listNoteVersions_prepareParams(authenticationToken, noteGuid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_listNoteVersions_readReply(reply);
}

AsyncResult* NoteStore::listNoteVersionsAsync(Guid noteGuid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listNoteVersions_prepareParams(authenticationToken, noteGuid);
    return new AsyncResult(m_url, params, NoteStore_listNoteVersions_readReplyAsync);
}

QByteArray NoteStore_getNoteVersion_prepareParams(QString authenticationToken, Guid noteGuid, qint32 updateSequenceNum, bool withResourcesData, bool withResourcesRecognition, bool withResourcesAlternateData)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getNoteVersion"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getNoteVersion_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("noteGuid"), ThriftFieldType::T_STRING, 2);
    w.writeString(noteGuid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("updateSequenceNum"), ThriftFieldType::T_I32, 3);
    w.writeI32(updateSequenceNum);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withResourcesData"), ThriftFieldType::T_BOOL, 4);
    w.writeBool(withResourcesData);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withResourcesRecognition"), ThriftFieldType::T_BOOL, 5);
    w.writeBool(withResourcesRecognition);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withResourcesAlternateData"), ThriftFieldType::T_BOOL, 6);
    w.writeBool(withResourcesAlternateData);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Note NoteStore_getNoteVersion_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Note result = Note();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNoteVersion")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Note v;
                readNote(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getNoteVersion: missing result"));
    }
    return result;
}

QVariant NoteStore_getNoteVersion_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getNoteVersion_readReply(reply));
}

Note NoteStore::getNoteVersion(Guid noteGuid, qint32 updateSequenceNum, bool withResourcesData, bool withResourcesRecognition, bool withResourcesAlternateData, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNoteVersion_prepareParams(authenticationToken, noteGuid, updateSequenceNum, withResourcesData, withResourcesRecognition, withResourcesAlternateData);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getNoteVersion_readReply(reply);
}

AsyncResult* NoteStore::getNoteVersionAsync(Guid noteGuid, qint32 updateSequenceNum, bool withResourcesData, bool withResourcesRecognition, bool withResourcesAlternateData, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNoteVersion_prepareParams(authenticationToken, noteGuid, updateSequenceNum, withResourcesData, withResourcesRecognition, withResourcesAlternateData);
    return new AsyncResult(m_url, params, NoteStore_getNoteVersion_readReplyAsync);
}

QByteArray NoteStore_getResource_prepareParams(QString authenticationToken, Guid guid, bool withData, bool withRecognition, bool withAttributes, bool withAlternateData)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getResource"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getResource_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withData"), ThriftFieldType::T_BOOL, 3);
    w.writeBool(withData);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withRecognition"), ThriftFieldType::T_BOOL, 4);
    w.writeBool(withRecognition);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withAttributes"), ThriftFieldType::T_BOOL, 5);
    w.writeBool(withAttributes);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withAlternateData"), ThriftFieldType::T_BOOL, 6);
    w.writeBool(withAlternateData);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Resource NoteStore_getResource_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Resource result = Resource();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResource")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Resource v;
                readResource(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getResource: missing result"));
    }
    return result;
}

QVariant NoteStore_getResource_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getResource_readReply(reply));
}

Resource NoteStore::getResource(Guid guid, bool withData, bool withRecognition, bool withAttributes, bool withAlternateData, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResource_prepareParams(authenticationToken, guid, withData, withRecognition, withAttributes, withAlternateData);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getResource_readReply(reply);
}

AsyncResult* NoteStore::getResourceAsync(Guid guid, bool withData, bool withRecognition, bool withAttributes, bool withAlternateData, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResource_prepareParams(authenticationToken, guid, withData, withRecognition, withAttributes, withAlternateData);
    return new AsyncResult(m_url, params, NoteStore_getResource_readReplyAsync);
}

QByteArray NoteStore_getResourceApplicationData_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getResourceApplicationData"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getResourceApplicationData_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

LazyMap NoteStore_getResourceApplicationData_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    LazyMap result = LazyMap();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceApplicationData")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                LazyMap v;
                readLazyMap(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getResourceApplicationData: missing result"));
    }
    return result;
}

QVariant NoteStore_getResourceApplicationData_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getResourceApplicationData_readReply(reply));
}

LazyMap NoteStore::getResourceApplicationData(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceApplicationData_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getResourceApplicationData_readReply(reply);
}

AsyncResult* NoteStore::getResourceApplicationDataAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceApplicationData_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_getResourceApplicationData_readReplyAsync);
}

QByteArray NoteStore_getResourceApplicationDataEntry_prepareParams(QString authenticationToken, Guid guid, QString key)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getResourceApplicationDataEntry"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getResourceApplicationDataEntry_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("key"), ThriftFieldType::T_STRING, 3);
    w.writeString(key);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QString NoteStore_getResourceApplicationDataEntry_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QString result = QString();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceApplicationDataEntry")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QString v;
                r.readString(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getResourceApplicationDataEntry: missing result"));
    }
    return result;
}

QVariant NoteStore_getResourceApplicationDataEntry_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getResourceApplicationDataEntry_readReply(reply));
}

QString NoteStore::getResourceApplicationDataEntry(Guid guid, QString key, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceApplicationDataEntry_prepareParams(authenticationToken, guid, key);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getResourceApplicationDataEntry_readReply(reply);
}

AsyncResult* NoteStore::getResourceApplicationDataEntryAsync(Guid guid, QString key, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceApplicationDataEntry_prepareParams(authenticationToken, guid, key);
    return new AsyncResult(m_url, params, NoteStore_getResourceApplicationDataEntry_readReplyAsync);
}

QByteArray NoteStore_setResourceApplicationDataEntry_prepareParams(QString authenticationToken, Guid guid, QString key, QString value)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("setResourceApplicationDataEntry"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_setResourceApplicationDataEntry_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("key"), ThriftFieldType::T_STRING, 3);
    w.writeString(key);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("value"), ThriftFieldType::T_STRING, 4);
    w.writeString(value);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_setResourceApplicationDataEntry_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("setResourceApplicationDataEntry")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("setResourceApplicationDataEntry: missing result"));
    }
    return result;
}

QVariant NoteStore_setResourceApplicationDataEntry_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_setResourceApplicationDataEntry_readReply(reply));
}

qint32 NoteStore::setResourceApplicationDataEntry(Guid guid, QString key, QString value, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_setResourceApplicationDataEntry_prepareParams(authenticationToken, guid, key, value);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_setResourceApplicationDataEntry_readReply(reply);
}

AsyncResult* NoteStore::setResourceApplicationDataEntryAsync(Guid guid, QString key, QString value, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_setResourceApplicationDataEntry_prepareParams(authenticationToken, guid, key, value);
    return new AsyncResult(m_url, params, NoteStore_setResourceApplicationDataEntry_readReplyAsync);
}

QByteArray NoteStore_unsetResourceApplicationDataEntry_prepareParams(QString authenticationToken, Guid guid, QString key)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("unsetResourceApplicationDataEntry"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_unsetResourceApplicationDataEntry_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("key"), ThriftFieldType::T_STRING, 3);
    w.writeString(key);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_unsetResourceApplicationDataEntry_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("unsetResourceApplicationDataEntry")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("unsetResourceApplicationDataEntry: missing result"));
    }
    return result;
}

QVariant NoteStore_unsetResourceApplicationDataEntry_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_unsetResourceApplicationDataEntry_readReply(reply));
}

qint32 NoteStore::unsetResourceApplicationDataEntry(Guid guid, QString key, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_unsetResourceApplicationDataEntry_prepareParams(authenticationToken, guid, key);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_unsetResourceApplicationDataEntry_readReply(reply);
}

AsyncResult* NoteStore::unsetResourceApplicationDataEntryAsync(Guid guid, QString key, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_unsetResourceApplicationDataEntry_prepareParams(authenticationToken, guid, key);
    return new AsyncResult(m_url, params, NoteStore_unsetResourceApplicationDataEntry_readReplyAsync);
}

QByteArray NoteStore_updateResource_prepareParams(QString authenticationToken, const Resource& resource)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("updateResource"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_updateResource_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("resource"), ThriftFieldType::T_STRUCT, 2);
    writeResource(w, resource);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_updateResource_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateResource")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("updateResource: missing result"));
    }
    return result;
}

QVariant NoteStore_updateResource_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_updateResource_readReply(reply));
}

qint32 NoteStore::updateResource(const Resource& resource, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateResource_prepareParams(authenticationToken, resource);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_updateResource_readReply(reply);
}

AsyncResult* NoteStore::updateResourceAsync(const Resource& resource, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateResource_prepareParams(authenticationToken, resource);
    return new AsyncResult(m_url, params, NoteStore_updateResource_readReplyAsync);
}

QByteArray NoteStore_getResourceData_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getResourceData"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getResourceData_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QByteArray NoteStore_getResourceData_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QByteArray result = QByteArray();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceData")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QByteArray v;
                r.readBinary(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getResourceData: missing result"));
    }
    return result;
}

QVariant NoteStore_getResourceData_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getResourceData_readReply(reply));
}

QByteArray NoteStore::getResourceData(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceData_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getResourceData_readReply(reply);
}

AsyncResult* NoteStore::getResourceDataAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceData_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_getResourceData_readReplyAsync);
}

QByteArray NoteStore_getResourceByHash_prepareParams(QString authenticationToken, Guid noteGuid, QByteArray contentHash, bool withData, bool withRecognition, bool withAlternateData)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getResourceByHash"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getResourceByHash_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("noteGuid"), ThriftFieldType::T_STRING, 2);
    w.writeString(noteGuid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("contentHash"), ThriftFieldType::T_STRING, 3);
    w.writeBinary(contentHash);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withData"), ThriftFieldType::T_BOOL, 4);
    w.writeBool(withData);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withRecognition"), ThriftFieldType::T_BOOL, 5);
    w.writeBool(withRecognition);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("withAlternateData"), ThriftFieldType::T_BOOL, 6);
    w.writeBool(withAlternateData);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Resource NoteStore_getResourceByHash_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Resource result = Resource();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceByHash")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Resource v;
                readResource(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getResourceByHash: missing result"));
    }
    return result;
}

QVariant NoteStore_getResourceByHash_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getResourceByHash_readReply(reply));
}

Resource NoteStore::getResourceByHash(Guid noteGuid, QByteArray contentHash, bool withData, bool withRecognition, bool withAlternateData, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceByHash_prepareParams(authenticationToken, noteGuid, contentHash, withData, withRecognition, withAlternateData);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getResourceByHash_readReply(reply);
}

AsyncResult* NoteStore::getResourceByHashAsync(Guid noteGuid, QByteArray contentHash, bool withData, bool withRecognition, bool withAlternateData, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceByHash_prepareParams(authenticationToken, noteGuid, contentHash, withData, withRecognition, withAlternateData);
    return new AsyncResult(m_url, params, NoteStore_getResourceByHash_readReplyAsync);
}

QByteArray NoteStore_getResourceRecognition_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getResourceRecognition"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getResourceRecognition_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QByteArray NoteStore_getResourceRecognition_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QByteArray result = QByteArray();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceRecognition")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QByteArray v;
                r.readBinary(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getResourceRecognition: missing result"));
    }
    return result;
}

QVariant NoteStore_getResourceRecognition_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getResourceRecognition_readReply(reply));
}

QByteArray NoteStore::getResourceRecognition(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceRecognition_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getResourceRecognition_readReply(reply);
}

AsyncResult* NoteStore::getResourceRecognitionAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceRecognition_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_getResourceRecognition_readReplyAsync);
}

QByteArray NoteStore_getResourceAlternateData_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getResourceAlternateData"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getResourceAlternateData_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QByteArray NoteStore_getResourceAlternateData_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QByteArray result = QByteArray();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceAlternateData")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QByteArray v;
                r.readBinary(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getResourceAlternateData: missing result"));
    }
    return result;
}

QVariant NoteStore_getResourceAlternateData_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getResourceAlternateData_readReply(reply));
}

QByteArray NoteStore::getResourceAlternateData(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceAlternateData_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getResourceAlternateData_readReply(reply);
}

AsyncResult* NoteStore::getResourceAlternateDataAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceAlternateData_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_getResourceAlternateData_readReplyAsync);
}

QByteArray NoteStore_getResourceAttributes_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getResourceAttributes"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getResourceAttributes_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

ResourceAttributes NoteStore_getResourceAttributes_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    ResourceAttributes result = ResourceAttributes();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getResourceAttributes")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                ResourceAttributes v;
                readResourceAttributes(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getResourceAttributes: missing result"));
    }
    return result;
}

QVariant NoteStore_getResourceAttributes_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getResourceAttributes_readReply(reply));
}

ResourceAttributes NoteStore::getResourceAttributes(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceAttributes_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getResourceAttributes_readReply(reply);
}

AsyncResult* NoteStore::getResourceAttributesAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getResourceAttributes_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_getResourceAttributes_readReplyAsync);
}

QByteArray NoteStore_getPublicNotebook_prepareParams(UserID userId, QString publicUri)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getPublicNotebook"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getPublicNotebook_pargs"));
    w.writeFieldBegin(QStringLiteral("userId"), ThriftFieldType::T_I32, 1);
    w.writeI32(userId);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("publicUri"), ThriftFieldType::T_STRING, 2);
    w.writeString(publicUri);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Notebook NoteStore_getPublicNotebook_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Notebook result = Notebook();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getPublicNotebook")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Notebook v;
                readNotebook(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getPublicNotebook: missing result"));
    }
    return result;
}

QVariant NoteStore_getPublicNotebook_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getPublicNotebook_readReply(reply));
}

Notebook NoteStore::getPublicNotebook(UserID userId, QString publicUri)
{
    QByteArray params = NoteStore_getPublicNotebook_prepareParams(userId, publicUri);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getPublicNotebook_readReply(reply);
}

AsyncResult* NoteStore::getPublicNotebookAsync(UserID userId, QString publicUri)
{
    QByteArray params = NoteStore_getPublicNotebook_prepareParams(userId, publicUri);
    return new AsyncResult(m_url, params, NoteStore_getPublicNotebook_readReplyAsync);
}

QByteArray NoteStore_shareNotebook_prepareParams(QString authenticationToken, const SharedNotebook& sharedNotebook, QString message)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("shareNotebook"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_shareNotebook_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("sharedNotebook"), ThriftFieldType::T_STRUCT, 2);
    writeSharedNotebook(w, sharedNotebook);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("message"), ThriftFieldType::T_STRING, 3);
    w.writeString(message);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

SharedNotebook NoteStore_shareNotebook_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    SharedNotebook result = SharedNotebook();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("shareNotebook")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SharedNotebook v;
                readSharedNotebook(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("shareNotebook: missing result"));
    }
    return result;
}

QVariant NoteStore_shareNotebook_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_shareNotebook_readReply(reply));
}

SharedNotebook NoteStore::shareNotebook(const SharedNotebook& sharedNotebook, QString message, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_shareNotebook_prepareParams(authenticationToken, sharedNotebook, message);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_shareNotebook_readReply(reply);
}

AsyncResult* NoteStore::shareNotebookAsync(const SharedNotebook& sharedNotebook, QString message, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_shareNotebook_prepareParams(authenticationToken, sharedNotebook, message);
    return new AsyncResult(m_url, params, NoteStore_shareNotebook_readReplyAsync);
}

QByteArray NoteStore_createOrUpdateNotebookShares_prepareParams(QString authenticationToken, const NotebookShareTemplate& shareTemplate)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("createOrUpdateNotebookShares"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_createOrUpdateNotebookShares_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("shareTemplate"), ThriftFieldType::T_STRUCT, 2);
    writeNotebookShareTemplate(w, shareTemplate);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

CreateOrUpdateNotebookSharesResult NoteStore_createOrUpdateNotebookShares_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    CreateOrUpdateNotebookSharesResult result = CreateOrUpdateNotebookSharesResult();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("createOrUpdateNotebookShares")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                CreateOrUpdateNotebookSharesResult v;
                readCreateOrUpdateNotebookSharesResult(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 4) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMInvalidContactsException e;
                readEDAMInvalidContactsException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("createOrUpdateNotebookShares: missing result"));
    }
    return result;
}

QVariant NoteStore_createOrUpdateNotebookShares_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_createOrUpdateNotebookShares_readReply(reply));
}

CreateOrUpdateNotebookSharesResult NoteStore::createOrUpdateNotebookShares(const NotebookShareTemplate& shareTemplate, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_createOrUpdateNotebookShares_prepareParams(authenticationToken, shareTemplate);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_createOrUpdateNotebookShares_readReply(reply);
}

AsyncResult* NoteStore::createOrUpdateNotebookSharesAsync(const NotebookShareTemplate& shareTemplate, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_createOrUpdateNotebookShares_prepareParams(authenticationToken, shareTemplate);
    return new AsyncResult(m_url, params, NoteStore_createOrUpdateNotebookShares_readReplyAsync);
}

QByteArray NoteStore_updateSharedNotebook_prepareParams(QString authenticationToken, const SharedNotebook& sharedNotebook)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("updateSharedNotebook"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_updateSharedNotebook_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("sharedNotebook"), ThriftFieldType::T_STRUCT, 2);
    writeSharedNotebook(w, sharedNotebook);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_updateSharedNotebook_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateSharedNotebook")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("updateSharedNotebook: missing result"));
    }
    return result;
}

QVariant NoteStore_updateSharedNotebook_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_updateSharedNotebook_readReply(reply));
}

qint32 NoteStore::updateSharedNotebook(const SharedNotebook& sharedNotebook, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateSharedNotebook_prepareParams(authenticationToken, sharedNotebook);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_updateSharedNotebook_readReply(reply);
}

AsyncResult* NoteStore::updateSharedNotebookAsync(const SharedNotebook& sharedNotebook, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateSharedNotebook_prepareParams(authenticationToken, sharedNotebook);
    return new AsyncResult(m_url, params, NoteStore_updateSharedNotebook_readReplyAsync);
}

QByteArray NoteStore_setNotebookRecipientSettings_prepareParams(QString authenticationToken, QString notebookGuid, const NotebookRecipientSettings& recipientSettings)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("setNotebookRecipientSettings"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_setNotebookRecipientSettings_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("notebookGuid"), ThriftFieldType::T_STRING, 2);
    w.writeString(notebookGuid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("recipientSettings"), ThriftFieldType::T_STRUCT, 3);
    writeNotebookRecipientSettings(w, recipientSettings);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

Notebook NoteStore_setNotebookRecipientSettings_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    Notebook result = Notebook();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("setNotebookRecipientSettings")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                Notebook v;
                readNotebook(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("setNotebookRecipientSettings: missing result"));
    }
    return result;
}

QVariant NoteStore_setNotebookRecipientSettings_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_setNotebookRecipientSettings_readReply(reply));
}

Notebook NoteStore::setNotebookRecipientSettings(QString notebookGuid, const NotebookRecipientSettings& recipientSettings, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_setNotebookRecipientSettings_prepareParams(authenticationToken, notebookGuid, recipientSettings);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_setNotebookRecipientSettings_readReply(reply);
}

AsyncResult* NoteStore::setNotebookRecipientSettingsAsync(QString notebookGuid, const NotebookRecipientSettings& recipientSettings, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_setNotebookRecipientSettings_prepareParams(authenticationToken, notebookGuid, recipientSettings);
    return new AsyncResult(m_url, params, NoteStore_setNotebookRecipientSettings_readReplyAsync);
}

QByteArray NoteStore_listSharedNotebooks_prepareParams(QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("listSharedNotebooks"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_listSharedNotebooks_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QList< SharedNotebook > NoteStore_listSharedNotebooks_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList< SharedNotebook > result = QList< SharedNotebook >();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listSharedNotebooks")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList< SharedNotebook > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (listSharedNotebooks.result)"));
                for(qint32 i = 0; i < size; i++) {
                    SharedNotebook elem;
                    readSharedNotebook(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("listSharedNotebooks: missing result"));
    }
    return result;
}

QVariant NoteStore_listSharedNotebooks_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_listSharedNotebooks_readReply(reply));
}

QList< SharedNotebook > NoteStore::listSharedNotebooks(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listSharedNotebooks_prepareParams(authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_listSharedNotebooks_readReply(reply);
}

AsyncResult* NoteStore::listSharedNotebooksAsync(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listSharedNotebooks_prepareParams(authenticationToken);
    return new AsyncResult(m_url, params, NoteStore_listSharedNotebooks_readReplyAsync);
}

QByteArray NoteStore_createLinkedNotebook_prepareParams(QString authenticationToken, const LinkedNotebook& linkedNotebook)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("createLinkedNotebook"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_createLinkedNotebook_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("linkedNotebook"), ThriftFieldType::T_STRUCT, 2);
    writeLinkedNotebook(w, linkedNotebook);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

LinkedNotebook NoteStore_createLinkedNotebook_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    LinkedNotebook result = LinkedNotebook();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("createLinkedNotebook")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                LinkedNotebook v;
                readLinkedNotebook(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("createLinkedNotebook: missing result"));
    }
    return result;
}

QVariant NoteStore_createLinkedNotebook_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_createLinkedNotebook_readReply(reply));
}

LinkedNotebook NoteStore::createLinkedNotebook(const LinkedNotebook& linkedNotebook, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_createLinkedNotebook_prepareParams(authenticationToken, linkedNotebook);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_createLinkedNotebook_readReply(reply);
}

AsyncResult* NoteStore::createLinkedNotebookAsync(const LinkedNotebook& linkedNotebook, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_createLinkedNotebook_prepareParams(authenticationToken, linkedNotebook);
    return new AsyncResult(m_url, params, NoteStore_createLinkedNotebook_readReplyAsync);
}

QByteArray NoteStore_updateLinkedNotebook_prepareParams(QString authenticationToken, const LinkedNotebook& linkedNotebook)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("updateLinkedNotebook"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_updateLinkedNotebook_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("linkedNotebook"), ThriftFieldType::T_STRUCT, 2);
    writeLinkedNotebook(w, linkedNotebook);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_updateLinkedNotebook_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateLinkedNotebook")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("updateLinkedNotebook: missing result"));
    }
    return result;
}

QVariant NoteStore_updateLinkedNotebook_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_updateLinkedNotebook_readReply(reply));
}

qint32 NoteStore::updateLinkedNotebook(const LinkedNotebook& linkedNotebook, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateLinkedNotebook_prepareParams(authenticationToken, linkedNotebook);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_updateLinkedNotebook_readReply(reply);
}

AsyncResult* NoteStore::updateLinkedNotebookAsync(const LinkedNotebook& linkedNotebook, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateLinkedNotebook_prepareParams(authenticationToken, linkedNotebook);
    return new AsyncResult(m_url, params, NoteStore_updateLinkedNotebook_readReplyAsync);
}

QByteArray NoteStore_listLinkedNotebooks_prepareParams(QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("listLinkedNotebooks"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_listLinkedNotebooks_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QList< LinkedNotebook > NoteStore_listLinkedNotebooks_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList< LinkedNotebook > result = QList< LinkedNotebook >();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listLinkedNotebooks")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList< LinkedNotebook > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (listLinkedNotebooks.result)"));
                for(qint32 i = 0; i < size; i++) {
                    LinkedNotebook elem;
                    readLinkedNotebook(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("listLinkedNotebooks: missing result"));
    }
    return result;
}

QVariant NoteStore_listLinkedNotebooks_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_listLinkedNotebooks_readReply(reply));
}

QList< LinkedNotebook > NoteStore::listLinkedNotebooks(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listLinkedNotebooks_prepareParams(authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_listLinkedNotebooks_readReply(reply);
}

AsyncResult* NoteStore::listLinkedNotebooksAsync(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_listLinkedNotebooks_prepareParams(authenticationToken);
    return new AsyncResult(m_url, params, NoteStore_listLinkedNotebooks_readReplyAsync);
}

QByteArray NoteStore_expungeLinkedNotebook_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("expungeLinkedNotebook"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_expungeLinkedNotebook_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

qint32 NoteStore_expungeLinkedNotebook_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    qint32 result = qint32();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("expungeLinkedNotebook")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_I32) {
                resultIsSet = true;
                qint32 v;
                r.readI32(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("expungeLinkedNotebook: missing result"));
    }
    return result;
}

QVariant NoteStore_expungeLinkedNotebook_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_expungeLinkedNotebook_readReply(reply));
}

qint32 NoteStore::expungeLinkedNotebook(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_expungeLinkedNotebook_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_expungeLinkedNotebook_readReply(reply);
}

AsyncResult* NoteStore::expungeLinkedNotebookAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_expungeLinkedNotebook_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_expungeLinkedNotebook_readReplyAsync);
}

QByteArray NoteStore_authenticateToSharedNotebook_prepareParams(QString shareKeyOrGlobalId, QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("authenticateToSharedNotebook"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_authenticateToSharedNotebook_pargs"));
    w.writeFieldBegin(QStringLiteral("shareKeyOrGlobalId"), ThriftFieldType::T_STRING, 1);
    w.writeString(shareKeyOrGlobalId);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 2);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

AuthenticationResult NoteStore_authenticateToSharedNotebook_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    AuthenticationResult result = AuthenticationResult();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("authenticateToSharedNotebook")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                AuthenticationResult v;
                readAuthenticationResult(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("authenticateToSharedNotebook: missing result"));
    }
    return result;
}

QVariant NoteStore_authenticateToSharedNotebook_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_authenticateToSharedNotebook_readReply(reply));
}

AuthenticationResult NoteStore::authenticateToSharedNotebook(QString shareKeyOrGlobalId, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_authenticateToSharedNotebook_prepareParams(shareKeyOrGlobalId, authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_authenticateToSharedNotebook_readReply(reply);
}

AsyncResult* NoteStore::authenticateToSharedNotebookAsync(QString shareKeyOrGlobalId, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_authenticateToSharedNotebook_prepareParams(shareKeyOrGlobalId, authenticationToken);
    return new AsyncResult(m_url, params, NoteStore_authenticateToSharedNotebook_readReplyAsync);
}

QByteArray NoteStore_getSharedNotebookByAuth_prepareParams(QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getSharedNotebookByAuth"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getSharedNotebookByAuth_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

SharedNotebook NoteStore_getSharedNotebookByAuth_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    SharedNotebook result = SharedNotebook();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getSharedNotebookByAuth")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                SharedNotebook v;
                readSharedNotebook(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getSharedNotebookByAuth: missing result"));
    }
    return result;
}

QVariant NoteStore_getSharedNotebookByAuth_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getSharedNotebookByAuth_readReply(reply));
}

SharedNotebook NoteStore::getSharedNotebookByAuth(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getSharedNotebookByAuth_prepareParams(authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getSharedNotebookByAuth_readReply(reply);
}

AsyncResult* NoteStore::getSharedNotebookByAuthAsync(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getSharedNotebookByAuth_prepareParams(authenticationToken);
    return new AsyncResult(m_url, params, NoteStore_getSharedNotebookByAuth_readReplyAsync);
}

QByteArray NoteStore_emailNote_prepareParams(QString authenticationToken, const NoteEmailParameters& parameters)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("emailNote"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_emailNote_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("parameters"), ThriftFieldType::T_STRUCT, 2);
    writeNoteEmailParameters(w, parameters);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

void NoteStore_emailNote_readReply(QByteArray reply)
{
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("emailNote")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
}

QVariant NoteStore_emailNote_readReplyAsync(QByteArray reply)
{
    NoteStore_emailNote_readReply(reply);
    return QVariant();
}

void NoteStore::emailNote(const NoteEmailParameters& parameters, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_emailNote_prepareParams(authenticationToken, parameters);
    QByteArray reply = askEvernote(m_url, params);
    NoteStore_emailNote_readReply(reply);
}

AsyncResult* NoteStore::emailNoteAsync(const NoteEmailParameters& parameters, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_emailNote_prepareParams(authenticationToken, parameters);
    return new AsyncResult(m_url, params, NoteStore_emailNote_readReplyAsync);
}

QByteArray NoteStore_shareNote_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("shareNote"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_shareNote_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QString NoteStore_shareNote_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QString result = QString();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("shareNote")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRING) {
                resultIsSet = true;
                QString v;
                r.readString(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("shareNote: missing result"));
    }
    return result;
}

QVariant NoteStore_shareNote_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_shareNote_readReply(reply));
}

QString NoteStore::shareNote(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_shareNote_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_shareNote_readReply(reply);
}

AsyncResult* NoteStore::shareNoteAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_shareNote_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_shareNote_readReplyAsync);
}

QByteArray NoteStore_stopSharingNote_prepareParams(QString authenticationToken, Guid guid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("stopSharingNote"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_stopSharingNote_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 2);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

void NoteStore_stopSharingNote_readReply(QByteArray reply)
{
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("stopSharingNote")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
}

QVariant NoteStore_stopSharingNote_readReplyAsync(QByteArray reply)
{
    NoteStore_stopSharingNote_readReply(reply);
    return QVariant();
}

void NoteStore::stopSharingNote(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_stopSharingNote_prepareParams(authenticationToken, guid);
    QByteArray reply = askEvernote(m_url, params);
    NoteStore_stopSharingNote_readReply(reply);
}

AsyncResult* NoteStore::stopSharingNoteAsync(Guid guid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_stopSharingNote_prepareParams(authenticationToken, guid);
    return new AsyncResult(m_url, params, NoteStore_stopSharingNote_readReplyAsync);
}

QByteArray NoteStore_authenticateToSharedNote_prepareParams(QString guid, QString noteKey, QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("authenticateToSharedNote"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_authenticateToSharedNote_pargs"));
    w.writeFieldBegin(QStringLiteral("guid"), ThriftFieldType::T_STRING, 1);
    w.writeString(guid);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("noteKey"), ThriftFieldType::T_STRING, 2);
    w.writeString(noteKey);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 3);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

AuthenticationResult NoteStore_authenticateToSharedNote_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    AuthenticationResult result = AuthenticationResult();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("authenticateToSharedNote")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                AuthenticationResult v;
                readAuthenticationResult(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("authenticateToSharedNote: missing result"));
    }
    return result;
}

QVariant NoteStore_authenticateToSharedNote_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_authenticateToSharedNote_readReply(reply));
}

AuthenticationResult NoteStore::authenticateToSharedNote(QString guid, QString noteKey, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_authenticateToSharedNote_prepareParams(guid, noteKey, authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_authenticateToSharedNote_readReply(reply);
}

AsyncResult* NoteStore::authenticateToSharedNoteAsync(QString guid, QString noteKey, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_authenticateToSharedNote_prepareParams(guid, noteKey, authenticationToken);
    return new AsyncResult(m_url, params, NoteStore_authenticateToSharedNote_readReplyAsync);
}

QByteArray NoteStore_findRelated_prepareParams(QString authenticationToken, const RelatedQuery& query, const RelatedResultSpec& resultSpec)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("findRelated"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_findRelated_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("query"), ThriftFieldType::T_STRUCT, 2);
    writeRelatedQuery(w, query);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("resultSpec"), ThriftFieldType::T_STRUCT, 3);
    writeRelatedResultSpec(w, resultSpec);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

RelatedResult NoteStore_findRelated_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    RelatedResult result = RelatedResult();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("findRelated")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                RelatedResult v;
                readRelatedResult(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("findRelated: missing result"));
    }
    return result;
}

QVariant NoteStore_findRelated_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_findRelated_readReply(reply));
}

RelatedResult NoteStore::findRelated(const RelatedQuery& query, const RelatedResultSpec& resultSpec, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_findRelated_prepareParams(authenticationToken, query, resultSpec);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_findRelated_readReply(reply);
}

AsyncResult* NoteStore::findRelatedAsync(const RelatedQuery& query, const RelatedResultSpec& resultSpec, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_findRelated_prepareParams(authenticationToken, query, resultSpec);
    return new AsyncResult(m_url, params, NoteStore_findRelated_readReplyAsync);
}

QByteArray NoteStore_updateNoteIfUsnMatches_prepareParams(QString authenticationToken, const Note& note)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("updateNoteIfUsnMatches"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_updateNoteIfUsnMatches_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("note"), ThriftFieldType::T_STRUCT, 2);
    writeNote(w, note);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

UpdateNoteIfUsnMatchesResult NoteStore_updateNoteIfUsnMatches_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    UpdateNoteIfUsnMatchesResult result = UpdateNoteIfUsnMatchesResult();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateNoteIfUsnMatches")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                UpdateNoteIfUsnMatchesResult v;
                readUpdateNoteIfUsnMatchesResult(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("updateNoteIfUsnMatches: missing result"));
    }
    return result;
}

QVariant NoteStore_updateNoteIfUsnMatches_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_updateNoteIfUsnMatches_readReply(reply));
}

UpdateNoteIfUsnMatchesResult NoteStore::updateNoteIfUsnMatches(const Note& note, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateNoteIfUsnMatches_prepareParams(authenticationToken, note);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_updateNoteIfUsnMatches_readReply(reply);
}

AsyncResult* NoteStore::updateNoteIfUsnMatchesAsync(const Note& note, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_updateNoteIfUsnMatches_prepareParams(authenticationToken, note);
    return new AsyncResult(m_url, params, NoteStore_updateNoteIfUsnMatches_readReplyAsync);
}

QByteArray NoteStore_manageNotebookShares_prepareParams(QString authenticationToken, const ManageNotebookSharesParameters& parameters)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("manageNotebookShares"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_manageNotebookShares_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("parameters"), ThriftFieldType::T_STRUCT, 2);
    writeManageNotebookSharesParameters(w, parameters);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

ManageNotebookSharesResult NoteStore_manageNotebookShares_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    ManageNotebookSharesResult result = ManageNotebookSharesResult();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("manageNotebookShares")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                ManageNotebookSharesResult v;
                readManageNotebookSharesResult(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("manageNotebookShares: missing result"));
    }
    return result;
}

QVariant NoteStore_manageNotebookShares_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_manageNotebookShares_readReply(reply));
}

ManageNotebookSharesResult NoteStore::manageNotebookShares(const ManageNotebookSharesParameters& parameters, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_manageNotebookShares_prepareParams(authenticationToken, parameters);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_manageNotebookShares_readReply(reply);
}

AsyncResult* NoteStore::manageNotebookSharesAsync(const ManageNotebookSharesParameters& parameters, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_manageNotebookShares_prepareParams(authenticationToken, parameters);
    return new AsyncResult(m_url, params, NoteStore_manageNotebookShares_readReplyAsync);
}

QByteArray NoteStore_getNotebookShares_prepareParams(QString authenticationToken, QString notebookGuid)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getNotebookShares"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("NoteStore_getNotebookShares_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("notebookGuid"), ThriftFieldType::T_STRING, 2);
    w.writeString(notebookGuid);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

ShareRelationships NoteStore_getNotebookShares_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    ShareRelationships result = ShareRelationships();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getNotebookShares")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                ShareRelationships v;
                readShareRelationships(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getNotebookShares: missing result"));
    }
    return result;
}

QVariant NoteStore_getNotebookShares_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(NoteStore_getNotebookShares_readReply(reply));
}

ShareRelationships NoteStore::getNotebookShares(QString notebookGuid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNotebookShares_prepareParams(authenticationToken, notebookGuid);
    QByteArray reply = askEvernote(m_url, params);
    return NoteStore_getNotebookShares_readReply(reply);
}

AsyncResult* NoteStore::getNotebookSharesAsync(QString notebookGuid, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = NoteStore_getNotebookShares_prepareParams(authenticationToken, notebookGuid);
    return new AsyncResult(m_url, params, NoteStore_getNotebookShares_readReplyAsync);
}

QByteArray UserStore_checkVersion_prepareParams(QString clientName, qint16 edamVersionMajor, qint16 edamVersionMinor)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("checkVersion"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_checkVersion_pargs"));
    w.writeFieldBegin(QStringLiteral("clientName"), ThriftFieldType::T_STRING, 1);
    w.writeString(clientName);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("edamVersionMajor"), ThriftFieldType::T_I16, 2);
    w.writeI16(edamVersionMajor);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("edamVersionMinor"), ThriftFieldType::T_I16, 3);
    w.writeI16(edamVersionMinor);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

bool UserStore_checkVersion_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    bool result = bool();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("checkVersion")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_BOOL) {
                resultIsSet = true;
                bool v;
                r.readBool(v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("checkVersion: missing result"));
    }
    return result;
}

QVariant UserStore_checkVersion_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStore_checkVersion_readReply(reply));
}

bool UserStore::checkVersion(QString clientName, qint16 edamVersionMajor, qint16 edamVersionMinor)
{
    QByteArray params = UserStore_checkVersion_prepareParams(clientName, edamVersionMajor, edamVersionMinor);
    QByteArray reply = askEvernote(m_url, params);
    return UserStore_checkVersion_readReply(reply);
}

AsyncResult* UserStore::checkVersionAsync(QString clientName, qint16 edamVersionMajor, qint16 edamVersionMinor)
{
    QByteArray params = UserStore_checkVersion_prepareParams(clientName, edamVersionMajor, edamVersionMinor);
    return new AsyncResult(m_url, params, UserStore_checkVersion_readReplyAsync);
}

QByteArray UserStore_getBootstrapInfo_prepareParams(QString locale)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getBootstrapInfo"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_getBootstrapInfo_pargs"));
    w.writeFieldBegin(QStringLiteral("locale"), ThriftFieldType::T_STRING, 1);
    w.writeString(locale);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

BootstrapInfo UserStore_getBootstrapInfo_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    BootstrapInfo result = BootstrapInfo();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getBootstrapInfo")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                BootstrapInfo v;
                readBootstrapInfo(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getBootstrapInfo: missing result"));
    }
    return result;
}

QVariant UserStore_getBootstrapInfo_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStore_getBootstrapInfo_readReply(reply));
}

BootstrapInfo UserStore::getBootstrapInfo(QString locale)
{
    QByteArray params = UserStore_getBootstrapInfo_prepareParams(locale);
    QByteArray reply = askEvernote(m_url, params);
    return UserStore_getBootstrapInfo_readReply(reply);
}

AsyncResult* UserStore::getBootstrapInfoAsync(QString locale)
{
    QByteArray params = UserStore_getBootstrapInfo_prepareParams(locale);
    return new AsyncResult(m_url, params, UserStore_getBootstrapInfo_readReplyAsync);
}

QByteArray UserStore_authenticateLongSession_prepareParams(QString username, QString password, QString consumerKey, QString consumerSecret, QString deviceIdentifier, QString deviceDescription, bool supportsTwoFactor)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("authenticateLongSession"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_authenticateLongSession_pargs"));
    w.writeFieldBegin(QStringLiteral("username"), ThriftFieldType::T_STRING, 1);
    w.writeString(username);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("password"), ThriftFieldType::T_STRING, 2);
    w.writeString(password);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("consumerKey"), ThriftFieldType::T_STRING, 3);
    w.writeString(consumerKey);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("consumerSecret"), ThriftFieldType::T_STRING, 4);
    w.writeString(consumerSecret);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("deviceIdentifier"), ThriftFieldType::T_STRING, 5);
    w.writeString(deviceIdentifier);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("deviceDescription"), ThriftFieldType::T_STRING, 6);
    w.writeString(deviceDescription);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("supportsTwoFactor"), ThriftFieldType::T_BOOL, 7);
    w.writeBool(supportsTwoFactor);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

AuthenticationResult UserStore_authenticateLongSession_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    AuthenticationResult result = AuthenticationResult();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("authenticateLongSession")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                AuthenticationResult v;
                readAuthenticationResult(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("authenticateLongSession: missing result"));
    }
    return result;
}

QVariant UserStore_authenticateLongSession_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStore_authenticateLongSession_readReply(reply));
}

AuthenticationResult UserStore::authenticateLongSession(QString username, QString password, QString consumerKey, QString consumerSecret, QString deviceIdentifier, QString deviceDescription, bool supportsTwoFactor)
{
    QByteArray params = UserStore_authenticateLongSession_prepareParams(username, password, consumerKey, consumerSecret, deviceIdentifier, deviceDescription, supportsTwoFactor);
    QByteArray reply = askEvernote(m_url, params);
    return UserStore_authenticateLongSession_readReply(reply);
}

AsyncResult* UserStore::authenticateLongSessionAsync(QString username, QString password, QString consumerKey, QString consumerSecret, QString deviceIdentifier, QString deviceDescription, bool supportsTwoFactor)
{
    QByteArray params = UserStore_authenticateLongSession_prepareParams(username, password, consumerKey, consumerSecret, deviceIdentifier, deviceDescription, supportsTwoFactor);
    return new AsyncResult(m_url, params, UserStore_authenticateLongSession_readReplyAsync);
}

QByteArray UserStore_completeTwoFactorAuthentication_prepareParams(QString authenticationToken, QString oneTimeCode, QString deviceIdentifier, QString deviceDescription)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("completeTwoFactorAuthentication"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_completeTwoFactorAuthentication_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("oneTimeCode"), ThriftFieldType::T_STRING, 2);
    w.writeString(oneTimeCode);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("deviceIdentifier"), ThriftFieldType::T_STRING, 3);
    w.writeString(deviceIdentifier);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("deviceDescription"), ThriftFieldType::T_STRING, 4);
    w.writeString(deviceDescription);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

AuthenticationResult UserStore_completeTwoFactorAuthentication_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    AuthenticationResult result = AuthenticationResult();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("completeTwoFactorAuthentication")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                AuthenticationResult v;
                readAuthenticationResult(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("completeTwoFactorAuthentication: missing result"));
    }
    return result;
}

QVariant UserStore_completeTwoFactorAuthentication_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStore_completeTwoFactorAuthentication_readReply(reply));
}

AuthenticationResult UserStore::completeTwoFactorAuthentication(QString oneTimeCode, QString deviceIdentifier, QString deviceDescription, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_completeTwoFactorAuthentication_prepareParams(authenticationToken, oneTimeCode, deviceIdentifier, deviceDescription);
    QByteArray reply = askEvernote(m_url, params);
    return UserStore_completeTwoFactorAuthentication_readReply(reply);
}

AsyncResult* UserStore::completeTwoFactorAuthenticationAsync(QString oneTimeCode, QString deviceIdentifier, QString deviceDescription, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_completeTwoFactorAuthentication_prepareParams(authenticationToken, oneTimeCode, deviceIdentifier, deviceDescription);
    return new AsyncResult(m_url, params, UserStore_completeTwoFactorAuthentication_readReplyAsync);
}

QByteArray UserStore_revokeLongSession_prepareParams(QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("revokeLongSession"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_revokeLongSession_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

void UserStore_revokeLongSession_readReply(QByteArray reply)
{
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("revokeLongSession")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
}

QVariant UserStore_revokeLongSession_readReplyAsync(QByteArray reply)
{
    UserStore_revokeLongSession_readReply(reply);
    return QVariant();
}

void UserStore::revokeLongSession(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_revokeLongSession_prepareParams(authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    UserStore_revokeLongSession_readReply(reply);
}

AsyncResult* UserStore::revokeLongSessionAsync(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_revokeLongSession_prepareParams(authenticationToken);
    return new AsyncResult(m_url, params, UserStore_revokeLongSession_readReplyAsync);
}

QByteArray UserStore_authenticateToBusiness_prepareParams(QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("authenticateToBusiness"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_authenticateToBusiness_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

AuthenticationResult UserStore_authenticateToBusiness_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    AuthenticationResult result = AuthenticationResult();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("authenticateToBusiness")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                AuthenticationResult v;
                readAuthenticationResult(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("authenticateToBusiness: missing result"));
    }
    return result;
}

QVariant UserStore_authenticateToBusiness_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStore_authenticateToBusiness_readReply(reply));
}

AuthenticationResult UserStore::authenticateToBusiness(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_authenticateToBusiness_prepareParams(authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return UserStore_authenticateToBusiness_readReply(reply);
}

AsyncResult* UserStore::authenticateToBusinessAsync(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_authenticateToBusiness_prepareParams(authenticationToken);
    return new AsyncResult(m_url, params, UserStore_authenticateToBusiness_readReplyAsync);
}

QByteArray UserStore_getUser_prepareParams(QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getUser"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_getUser_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

User UserStore_getUser_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    User result = User();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getUser")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                User v;
                readUser(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getUser: missing result"));
    }
    return result;
}

QVariant UserStore_getUser_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStore_getUser_readReply(reply));
}

User UserStore::getUser(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_getUser_prepareParams(authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return UserStore_getUser_readReply(reply);
}

AsyncResult* UserStore::getUserAsync(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_getUser_prepareParams(authenticationToken);
    return new AsyncResult(m_url, params, UserStore_getUser_readReplyAsync);
}

QByteArray UserStore_getPublicUserInfo_prepareParams(QString username)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getPublicUserInfo"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_getPublicUserInfo_pargs"));
    w.writeFieldBegin(QStringLiteral("username"), ThriftFieldType::T_STRING, 1);
    w.writeString(username);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

PublicUserInfo UserStore_getPublicUserInfo_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    PublicUserInfo result = PublicUserInfo();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getPublicUserInfo")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                PublicUserInfo v;
                readPublicUserInfo(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getPublicUserInfo: missing result"));
    }
    return result;
}

QVariant UserStore_getPublicUserInfo_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStore_getPublicUserInfo_readReply(reply));
}

PublicUserInfo UserStore::getPublicUserInfo(QString username)
{
    QByteArray params = UserStore_getPublicUserInfo_prepareParams(username);
    QByteArray reply = askEvernote(m_url, params);
    return UserStore_getPublicUserInfo_readReply(reply);
}

AsyncResult* UserStore::getPublicUserInfoAsync(QString username)
{
    QByteArray params = UserStore_getPublicUserInfo_prepareParams(username);
    return new AsyncResult(m_url, params, UserStore_getPublicUserInfo_readReplyAsync);
}

QByteArray UserStore_getUserUrls_prepareParams(QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getUserUrls"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_getUserUrls_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

UserUrls UserStore_getUserUrls_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    UserUrls result = UserUrls();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getUserUrls")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                UserUrls v;
                readUserUrls(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getUserUrls: missing result"));
    }
    return result;
}

QVariant UserStore_getUserUrls_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStore_getUserUrls_readReply(reply));
}

UserUrls UserStore::getUserUrls(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_getUserUrls_prepareParams(authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return UserStore_getUserUrls_readReply(reply);
}

AsyncResult* UserStore::getUserUrlsAsync(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_getUserUrls_prepareParams(authenticationToken);
    return new AsyncResult(m_url, params, UserStore_getUserUrls_readReplyAsync);
}

QByteArray UserStore_inviteToBusiness_prepareParams(QString authenticationToken, QString emailAddress)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("inviteToBusiness"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_inviteToBusiness_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("emailAddress"), ThriftFieldType::T_STRING, 2);
    w.writeString(emailAddress);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

void UserStore_inviteToBusiness_readReply(QByteArray reply)
{
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("inviteToBusiness")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
}

QVariant UserStore_inviteToBusiness_readReplyAsync(QByteArray reply)
{
    UserStore_inviteToBusiness_readReply(reply);
    return QVariant();
}

void UserStore::inviteToBusiness(QString emailAddress, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_inviteToBusiness_prepareParams(authenticationToken, emailAddress);
    QByteArray reply = askEvernote(m_url, params);
    UserStore_inviteToBusiness_readReply(reply);
}

AsyncResult* UserStore::inviteToBusinessAsync(QString emailAddress, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_inviteToBusiness_prepareParams(authenticationToken, emailAddress);
    return new AsyncResult(m_url, params, UserStore_inviteToBusiness_readReplyAsync);
}

QByteArray UserStore_removeFromBusiness_prepareParams(QString authenticationToken, QString emailAddress)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("removeFromBusiness"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_removeFromBusiness_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("emailAddress"), ThriftFieldType::T_STRING, 2);
    w.writeString(emailAddress);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

void UserStore_removeFromBusiness_readReply(QByteArray reply)
{
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("removeFromBusiness")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
}

QVariant UserStore_removeFromBusiness_readReplyAsync(QByteArray reply)
{
    UserStore_removeFromBusiness_readReply(reply);
    return QVariant();
}

void UserStore::removeFromBusiness(QString emailAddress, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_removeFromBusiness_prepareParams(authenticationToken, emailAddress);
    QByteArray reply = askEvernote(m_url, params);
    UserStore_removeFromBusiness_readReply(reply);
}

AsyncResult* UserStore::removeFromBusinessAsync(QString emailAddress, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_removeFromBusiness_prepareParams(authenticationToken, emailAddress);
    return new AsyncResult(m_url, params, UserStore_removeFromBusiness_readReplyAsync);
}

QByteArray UserStore_updateBusinessUserIdentifier_prepareParams(QString authenticationToken, QString oldEmailAddress, QString newEmailAddress)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("updateBusinessUserIdentifier"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_updateBusinessUserIdentifier_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("oldEmailAddress"), ThriftFieldType::T_STRING, 2);
    w.writeString(oldEmailAddress);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("newEmailAddress"), ThriftFieldType::T_STRING, 3);
    w.writeString(newEmailAddress);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

void UserStore_updateBusinessUserIdentifier_readReply(QByteArray reply)
{
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("updateBusinessUserIdentifier")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 3) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMNotFoundException e;
                readEDAMNotFoundException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
}

QVariant UserStore_updateBusinessUserIdentifier_readReplyAsync(QByteArray reply)
{
    UserStore_updateBusinessUserIdentifier_readReply(reply);
    return QVariant();
}

void UserStore::updateBusinessUserIdentifier(QString oldEmailAddress, QString newEmailAddress, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_updateBusinessUserIdentifier_prepareParams(authenticationToken, oldEmailAddress, newEmailAddress);
    QByteArray reply = askEvernote(m_url, params);
    UserStore_updateBusinessUserIdentifier_readReply(reply);
}

AsyncResult* UserStore::updateBusinessUserIdentifierAsync(QString oldEmailAddress, QString newEmailAddress, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_updateBusinessUserIdentifier_prepareParams(authenticationToken, oldEmailAddress, newEmailAddress);
    return new AsyncResult(m_url, params, UserStore_updateBusinessUserIdentifier_readReplyAsync);
}

QByteArray UserStore_listBusinessUsers_prepareParams(QString authenticationToken)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("listBusinessUsers"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_listBusinessUsers_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QList< UserProfile > UserStore_listBusinessUsers_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList< UserProfile > result = QList< UserProfile >();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listBusinessUsers")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList< UserProfile > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (listBusinessUsers.result)"));
                for(qint32 i = 0; i < size; i++) {
                    UserProfile elem;
                    readUserProfile(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("listBusinessUsers: missing result"));
    }
    return result;
}

QVariant UserStore_listBusinessUsers_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStore_listBusinessUsers_readReply(reply));
}

QList< UserProfile > UserStore::listBusinessUsers(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_listBusinessUsers_prepareParams(authenticationToken);
    QByteArray reply = askEvernote(m_url, params);
    return UserStore_listBusinessUsers_readReply(reply);
}

AsyncResult* UserStore::listBusinessUsersAsync(QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_listBusinessUsers_prepareParams(authenticationToken);
    return new AsyncResult(m_url, params, UserStore_listBusinessUsers_readReplyAsync);
}

QByteArray UserStore_listBusinessInvitations_prepareParams(QString authenticationToken, bool includeRequestedInvitations)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("listBusinessInvitations"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_listBusinessInvitations_pargs"));
    w.writeFieldBegin(QStringLiteral("authenticationToken"), ThriftFieldType::T_STRING, 1);
    w.writeString(authenticationToken);
    w.writeFieldEnd();
    w.writeFieldBegin(QStringLiteral("includeRequestedInvitations"), ThriftFieldType::T_BOOL, 2);
    w.writeBool(includeRequestedInvitations);
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

QList< BusinessInvitation > UserStore_listBusinessInvitations_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    QList< BusinessInvitation > result = QList< BusinessInvitation >();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("listBusinessInvitations")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_LIST) {
                resultIsSet = true;
                QList< BusinessInvitation > v;
                qint32 size;
                ThriftFieldType::type elemType;
                r.readListBegin(elemType, size);
                v.reserve(size);
                if(elemType != ThriftFieldType::T_STRUCT) throw ThriftException(ThriftException::Type::INVALID_DATA, QStringLiteral("Incorrect list type (listBusinessInvitations.result)"));
                for(qint32 i = 0; i < size; i++) {
                    BusinessInvitation elem;
                    readBusinessInvitation(r, elem);
                    v.append(elem);
                }
                r.readListEnd();
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 2) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMSystemException e;
                readEDAMSystemException(r, e);
                throwEDAMSystemException(e);
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("listBusinessInvitations: missing result"));
    }
    return result;
}

QVariant UserStore_listBusinessInvitations_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStore_listBusinessInvitations_readReply(reply));
}

QList< BusinessInvitation > UserStore::listBusinessInvitations(bool includeRequestedInvitations, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_listBusinessInvitations_prepareParams(authenticationToken, includeRequestedInvitations);
    QByteArray reply = askEvernote(m_url, params);
    return UserStore_listBusinessInvitations_readReply(reply);
}

AsyncResult* UserStore::listBusinessInvitationsAsync(bool includeRequestedInvitations, QString authenticationToken)
{
    if (authenticationToken.isEmpty()) {
        authenticationToken = m_authenticationToken;
    }
    QByteArray params = UserStore_listBusinessInvitations_prepareParams(authenticationToken, includeRequestedInvitations);
    return new AsyncResult(m_url, params, UserStore_listBusinessInvitations_readReplyAsync);
}

QByteArray UserStore_getAccountLimits_prepareParams(ServiceLevel::type serviceLevel)
{
    ThriftBinaryBufferWriter w;
    qint32 cseqid = 0;
    w.writeMessageBegin(QStringLiteral("getAccountLimits"), ThriftMessageType::T_CALL, cseqid);
    w.writeStructBegin(QStringLiteral("UserStore_getAccountLimits_pargs"));
    w.writeFieldBegin(QStringLiteral("serviceLevel"), ThriftFieldType::T_I32, 1);
    w.writeI32(static_cast<qint32>(serviceLevel));
    w.writeFieldEnd();
    w.writeFieldStop();
    w.writeStructEnd();
    w.writeMessageEnd();
    return w.buffer();
}

AccountLimits UserStore_getAccountLimits_readReply(QByteArray reply)
{
    bool resultIsSet = false;
    AccountLimits result = AccountLimits();
    ThriftBinaryBufferReader r(reply);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType::type mtype;
    r.readMessageBegin(fname, mtype, rseqid);
    if (mtype == ThriftMessageType::T_EXCEPTION) {
      ThriftException e = readThriftException(r);
      r.readMessageEnd();
      throw e;
    }
    if (mtype != ThriftMessageType::T_REPLY) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }
    if (fname.compare(QStringLiteral("getAccountLimits")) != 0) {
      r.skip(ThriftFieldType::T_STRUCT);
      r.readMessageEnd();
      throw ThriftException(ThriftException::Type::WRONG_METHOD_NAME);
    }

    ThriftFieldType::type fieldType;
    qint16 fieldId;
    r.readStructBegin(fname);
    while(true) {
        r.readFieldBegin(fname, fieldType, fieldId);
        if(fieldType == ThriftFieldType::T_STOP) break;
        if(fieldId == 0) {
            if(fieldType == ThriftFieldType::T_STRUCT) {
                resultIsSet = true;
                AccountLimits v;
                readAccountLimits(r, v);
                result = v;
            } else {
                r.skip(fieldType);
            }
        }
       else if (fieldId == 1) {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                EDAMUserException e;
                readEDAMUserException(r, e);
                throw e;
            }
            else {
                r.skip(fieldType);
            }
        }
        else {
            r.skip(fieldType);
        }
        r.readFieldEnd();
    }
    r.readStructEnd();
    r.readMessageEnd();
    if (!resultIsSet) {
        throw ThriftException(ThriftException::Type::MISSING_RESULT, QStringLiteral("getAccountLimits: missing result"));
    }
    return result;
}

QVariant UserStore_getAccountLimits_readReplyAsync(QByteArray reply)
{
    return QVariant::fromValue(UserStore_getAccountLimits_readReply(reply));
}

AccountLimits UserStore::getAccountLimits(ServiceLevel::type serviceLevel)
{
    QByteArray params = UserStore_getAccountLimits_prepareParams(serviceLevel);
    QByteArray reply = askEvernote(m_url, params);
    return UserStore_getAccountLimits_readReply(reply);
}

AsyncResult* UserStore::getAccountLimitsAsync(ServiceLevel::type serviceLevel)
{
    QByteArray params = UserStore_getAccountLimits_prepareParams(serviceLevel);
    return new AsyncResult(m_url, params, UserStore_getAccountLimits_readReplyAsync);
}


} // namespace qevercloud
