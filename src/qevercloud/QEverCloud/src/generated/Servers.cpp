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

#include <generated/Servers.h>
#include "../Impl.h"
#include "../Thrift.h"
#include "Types_io.h"
#include <Log.h>

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetSyncStateParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getSyncState_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetFilteredSyncChunkParams(
    ThriftBinaryBufferReader & reader,
    qint32 & afterUSN,
    qint32 & maxEntries,
    SyncChunkFilter & filter,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getFilteredSyncChunk_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                afterUSN = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                maxEntries = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SyncChunkFilter v;
                readSyncChunkFilter(reader, v);
                filter = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetLinkedNotebookSyncStateParams(
    ThriftBinaryBufferReader & reader,
    LinkedNotebook & linkedNotebook,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getLinkedNotebookSyncState_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LinkedNotebook v;
                readLinkedNotebook(reader, v);
                linkedNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetLinkedNotebookSyncChunkParams(
    ThriftBinaryBufferReader & reader,
    LinkedNotebook & linkedNotebook,
    qint32 & afterUSN,
    qint32 & maxEntries,
    bool & fullSyncOnly,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getLinkedNotebookSyncChunk_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LinkedNotebook v;
                readLinkedNotebook(reader, v);
                linkedNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                afterUSN = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                maxEntries = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                fullSyncOnly = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListNotebooksParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listNotebooks_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListAccessibleBusinessNotebooksParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listAccessibleBusinessNotebooks_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNotebookParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetDefaultNotebookParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getDefaultNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateNotebookParams(
    ThriftBinaryBufferReader & reader,
    Notebook & notebook,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_createNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Notebook v;
                readNotebook(reader, v);
                notebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateNotebookParams(
    ThriftBinaryBufferReader & reader,
    Notebook & notebook,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Notebook v;
                readNotebook(reader, v);
                notebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeNotebookParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_expungeNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListTagsParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listTags_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListTagsByNotebookParams(
    ThriftBinaryBufferReader & reader,
    Guid & notebookGuid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listTagsByNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                notebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetTagParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getTag_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateTagParams(
    ThriftBinaryBufferReader & reader,
    Tag & tag,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_createTag_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Tag v;
                readTag(reader, v);
                tag = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateTagParams(
    ThriftBinaryBufferReader & reader,
    Tag & tag,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateTag_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Tag v;
                readTag(reader, v);
                tag = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUntagAllParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_untagAll_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeTagParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_expungeTag_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListSearchesParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listSearches_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetSearchParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getSearch_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateSearchParams(
    ThriftBinaryBufferReader & reader,
    SavedSearch & search,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_createSearch_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SavedSearch v;
                readSavedSearch(reader, v);
                search = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateSearchParams(
    ThriftBinaryBufferReader & reader,
    SavedSearch & search,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateSearch_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SavedSearch v;
                readSavedSearch(reader, v);
                search = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeSearchParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_expungeSearch_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindNoteOffsetParams(
    ThriftBinaryBufferReader & reader,
    NoteFilter & filter,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_findNoteOffset_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteFilter v;
                readNoteFilter(reader, v);
                filter = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindNotesMetadataParams(
    ThriftBinaryBufferReader & reader,
    NoteFilter & filter,
    qint32 & offset,
    qint32 & maxNotes,
    NotesMetadataResultSpec & resultSpec,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_findNotesMetadata_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteFilter v;
                readNoteFilter(reader, v);
                filter = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                offset = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                maxNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NotesMetadataResultSpec v;
                readNotesMetadataResultSpec(reader, v);
                resultSpec = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindNoteCountsParams(
    ThriftBinaryBufferReader & reader,
    NoteFilter & filter,
    bool & withTrash,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_findNoteCounts_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteFilter v;
                readNoteFilter(reader, v);
                filter = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withTrash = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteWithResultSpecParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    NoteResultSpec & resultSpec,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNoteWithResultSpec_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteResultSpec v;
                readNoteResultSpec(reader, v);
                resultSpec = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    bool & withContent,
    bool & withResourcesData,
    bool & withResourcesRecognition,
    bool & withResourcesAlternateData,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withContent = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withResourcesData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withResourcesRecognition = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 6)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withResourcesAlternateData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteApplicationDataParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNoteApplicationData_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNoteApplicationDataEntry_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                key = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreSetNoteApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
    QString & value,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_setNoteApplicationDataEntry_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                key = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                value = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUnsetNoteApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_unsetNoteApplicationDataEntry_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                key = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteContentParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNoteContent_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteSearchTextParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    bool & noteOnly,
    bool & tokenizeForIndexing,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNoteSearchText_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                noteOnly = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                tokenizeForIndexing = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceSearchTextParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceSearchText_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteTagNamesParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNoteTagNames_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateNoteParams(
    ThriftBinaryBufferReader & reader,
    Note & note,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_createNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Note v;
                readNote(reader, v);
                note = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateNoteParams(
    ThriftBinaryBufferReader & reader,
    Note & note,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Note v;
                readNote(reader, v);
                note = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreDeleteNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_deleteNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_expungeNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCopyNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & noteGuid,
    Guid & toNotebookGuid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_copyNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                noteGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                toNotebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListNoteVersionsParams(
    ThriftBinaryBufferReader & reader,
    Guid & noteGuid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listNoteVersions_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                noteGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteVersionParams(
    ThriftBinaryBufferReader & reader,
    Guid & noteGuid,
    qint32 & updateSequenceNum,
    bool & withResourcesData,
    bool & withResourcesRecognition,
    bool & withResourcesAlternateData,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNoteVersion_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                noteGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                updateSequenceNum = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withResourcesData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withResourcesRecognition = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 6)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withResourcesAlternateData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    bool & withData,
    bool & withRecognition,
    bool & withAttributes,
    bool & withAlternateData,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResource_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withRecognition = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withAttributes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 6)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withAlternateData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceApplicationDataParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceApplicationData_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceApplicationDataEntry_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                key = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreSetResourceApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
    QString & value,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_setResourceApplicationDataEntry_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                key = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                value = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUnsetResourceApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_unsetResourceApplicationDataEntry_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                key = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateResourceParams(
    ThriftBinaryBufferReader & reader,
    Resource & resource,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateResource_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Resource v;
                readResource(reader, v);
                resource = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceDataParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceData_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceByHashParams(
    ThriftBinaryBufferReader & reader,
    Guid & noteGuid,
    QByteArray & contentHash,
    bool & withData,
    bool & withRecognition,
    bool & withAlternateData,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceByHash_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                noteGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                contentHash = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withRecognition = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 6)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withAlternateData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceRecognitionParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceRecognition_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceAlternateDataParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceAlternateData_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceAttributesParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceAttributes_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetPublicNotebookParams(
    ThriftBinaryBufferReader & reader,
    UserID & userId,
    QString & publicUri,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname =
        QStringLiteral("NoteStore_getPublicNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                userId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                publicUri = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreShareNotebookParams(
    ThriftBinaryBufferReader & reader,
    SharedNotebook & sharedNotebook,
    QString & message,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_shareNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SharedNotebook v;
                readSharedNotebook(reader, v);
                sharedNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                message = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateOrUpdateNotebookSharesParams(
    ThriftBinaryBufferReader & reader,
    NotebookShareTemplate & shareTemplate,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_createOrUpdateNotebookShares_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NotebookShareTemplate v;
                readNotebookShareTemplate(reader, v);
                shareTemplate = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateSharedNotebookParams(
    ThriftBinaryBufferReader & reader,
    SharedNotebook & sharedNotebook,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateSharedNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SharedNotebook v;
                readSharedNotebook(reader, v);
                sharedNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreSetNotebookRecipientSettingsParams(
    ThriftBinaryBufferReader & reader,
    QString & notebookGuid,
    NotebookRecipientSettings & recipientSettings,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_setNotebookRecipientSettings_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                notebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NotebookRecipientSettings v;
                readNotebookRecipientSettings(reader, v);
                recipientSettings = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListSharedNotebooksParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listSharedNotebooks_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateLinkedNotebookParams(
    ThriftBinaryBufferReader & reader,
    LinkedNotebook & linkedNotebook,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_createLinkedNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LinkedNotebook v;
                readLinkedNotebook(reader, v);
                linkedNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateLinkedNotebookParams(
    ThriftBinaryBufferReader & reader,
    LinkedNotebook & linkedNotebook,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateLinkedNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LinkedNotebook v;
                readLinkedNotebook(reader, v);
                linkedNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListLinkedNotebooksParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listLinkedNotebooks_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeLinkedNotebookParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_expungeLinkedNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreAuthenticateToSharedNotebookParams(
    ThriftBinaryBufferReader & reader,
    QString & shareKeyOrGlobalId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_authenticateToSharedNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                shareKeyOrGlobalId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetSharedNotebookByAuthParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getSharedNotebookByAuth_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreEmailNoteParams(
    ThriftBinaryBufferReader & reader,
    NoteEmailParameters & parameters,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_emailNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteEmailParameters v;
                readNoteEmailParameters(reader, v);
                parameters = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreShareNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_shareNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreStopSharingNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_stopSharingNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreAuthenticateToSharedNoteParams(
    ThriftBinaryBufferReader & reader,
    QString & guid,
    QString & noteKey,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_authenticateToSharedNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                noteKey = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindRelatedParams(
    ThriftBinaryBufferReader & reader,
    RelatedQuery & query,
    RelatedResultSpec & resultSpec,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_findRelated_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                RelatedQuery v;
                readRelatedQuery(reader, v);
                query = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                RelatedResultSpec v;
                readRelatedResultSpec(reader, v);
                resultSpec = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateNoteIfUsnMatchesParams(
    ThriftBinaryBufferReader & reader,
    Note & note,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateNoteIfUsnMatches_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Note v;
                readNote(reader, v);
                note = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreManageNotebookSharesParams(
    ThriftBinaryBufferReader & reader,
    ManageNotebookSharesParameters & parameters,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_manageNotebookShares_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                ManageNotebookSharesParameters v;
                readManageNotebookSharesParameters(reader, v);
                parameters = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNotebookSharesParams(
    ThriftBinaryBufferReader & reader,
    QString & notebookGuid,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNotebookShares_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                notebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreCheckVersionParams(
    ThriftBinaryBufferReader & reader,
    QString & clientName,
    qint16 & edamVersionMajor,
    qint16 & edamVersionMinor,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname =
        QStringLiteral("UserStore_checkVersion_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                clientName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                reader.readI16(v);
                edamVersionMajor = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                reader.readI16(v);
                edamVersionMinor = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetBootstrapInfoParams(
    ThriftBinaryBufferReader & reader,
    QString & locale,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname =
        QStringLiteral("UserStore_getBootstrapInfo_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                locale = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreAuthenticateLongSessionParams(
    ThriftBinaryBufferReader & reader,
    QString & username,
    QString & password,
    QString & consumerKey,
    QString & consumerSecret,
    QString & deviceIdentifier,
    QString & deviceDescription,
    bool & supportsTwoFactor,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname =
        QStringLiteral("UserStore_authenticateLongSession_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                username = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                password = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                consumerKey = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                consumerSecret = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                deviceIdentifier = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 6)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                deviceDescription = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 7)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                supportsTwoFactor = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreCompleteTwoFactorAuthenticationParams(
    ThriftBinaryBufferReader & reader,
    QString & oneTimeCode,
    QString & deviceIdentifier,
    QString & deviceDescription,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_completeTwoFactorAuthentication_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                oneTimeCode = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                deviceIdentifier = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                deviceDescription = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreRevokeLongSessionParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_revokeLongSession_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreAuthenticateToBusinessParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_authenticateToBusiness_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetUserParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_getUser_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetPublicUserInfoParams(
    ThriftBinaryBufferReader & reader,
    QString & username,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname =
        QStringLiteral("UserStore_getPublicUserInfo_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                username = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetUserUrlsParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_getUserUrls_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreInviteToBusinessParams(
    ThriftBinaryBufferReader & reader,
    QString & emailAddress,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_inviteToBusiness_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                emailAddress = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreRemoveFromBusinessParams(
    ThriftBinaryBufferReader & reader,
    QString & emailAddress,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_removeFromBusiness_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                emailAddress = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreUpdateBusinessUserIdentifierParams(
    ThriftBinaryBufferReader & reader,
    QString & oldEmailAddress,
    QString & newEmailAddress,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_updateBusinessUserIdentifier_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                oldEmailAddress = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                newEmailAddress = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreListBusinessUsersParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_listBusinessUsers_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreListBusinessInvitationsParams(
    ThriftBinaryBufferReader & reader,
    bool & includeRequestedInvitations,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("UserStore_listBusinessInvitations_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                includeRequestedInvitations = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetAccountLimitsParams(
    ThriftBinaryBufferReader & reader,
    ServiceLevel & serviceLevel,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname =
        QStringLiteral("UserStore_getAccountLimits_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                ServiceLevel v;
                readEnumServiceLevel(reader, v);
                serviceLevel = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = newRequestContext();
}

} // namespace

////////////////////////////////////////////////////////////////////////////////

NoteStoreServer::NoteStoreServer(QObject * parent) :
    QObject(parent)
{}

void NoteStoreServer::onRequest(QByteArray data)
{
    ThriftBinaryBufferReader reader(data);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);

    if (mtype != ThriftMessageType::T_CALL) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }

    if (fname == QStringLiteral("getSyncState"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreGetSyncStateParams(
            reader,
            ctx);

        Q_EMIT getSyncStateRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getFilteredSyncChunk"))
    {
        qint32 afterUSN = 0;
        qint32 maxEntries = 0;
        SyncChunkFilter filter;
        IRequestContextPtr ctx;

        parseNoteStoreGetFilteredSyncChunkParams(
            reader,
            afterUSN,
            maxEntries,
            filter,
            ctx);

        Q_EMIT getFilteredSyncChunkRequest(
            afterUSN,
            maxEntries,
            filter,
            ctx);
    }
    else if (fname == QStringLiteral("getLinkedNotebookSyncState"))
    {
        LinkedNotebook linkedNotebook;
        IRequestContextPtr ctx;

        parseNoteStoreGetLinkedNotebookSyncStateParams(
            reader,
            linkedNotebook,
            ctx);

        Q_EMIT getLinkedNotebookSyncStateRequest(
            linkedNotebook,
            ctx);
    }
    else if (fname == QStringLiteral("getLinkedNotebookSyncChunk"))
    {
        LinkedNotebook linkedNotebook;
        qint32 afterUSN = 0;
        qint32 maxEntries = 0;
        bool fullSyncOnly = false;
        IRequestContextPtr ctx;

        parseNoteStoreGetLinkedNotebookSyncChunkParams(
            reader,
            linkedNotebook,
            afterUSN,
            maxEntries,
            fullSyncOnly,
            ctx);

        Q_EMIT getLinkedNotebookSyncChunkRequest(
            linkedNotebook,
            afterUSN,
            maxEntries,
            fullSyncOnly,
            ctx);
    }
    else if (fname == QStringLiteral("listNotebooks"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreListNotebooksParams(
            reader,
            ctx);

        Q_EMIT listNotebooksRequest(
            ctx);
    }
    else if (fname == QStringLiteral("listAccessibleBusinessNotebooks"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreListAccessibleBusinessNotebooksParams(
            reader,
            ctx);

        Q_EMIT listAccessibleBusinessNotebooksRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getNotebook"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetNotebookParams(
            reader,
            guid,
            ctx);

        Q_EMIT getNotebookRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getDefaultNotebook"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreGetDefaultNotebookParams(
            reader,
            ctx);

        Q_EMIT getDefaultNotebookRequest(
            ctx);
    }
    else if (fname == QStringLiteral("createNotebook"))
    {
        Notebook notebook;
        IRequestContextPtr ctx;

        parseNoteStoreCreateNotebookParams(
            reader,
            notebook,
            ctx);

        Q_EMIT createNotebookRequest(
            notebook,
            ctx);
    }
    else if (fname == QStringLiteral("updateNotebook"))
    {
        Notebook notebook;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateNotebookParams(
            reader,
            notebook,
            ctx);

        Q_EMIT updateNotebookRequest(
            notebook,
            ctx);
    }
    else if (fname == QStringLiteral("expungeNotebook"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreExpungeNotebookParams(
            reader,
            guid,
            ctx);

        Q_EMIT expungeNotebookRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("listTags"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreListTagsParams(
            reader,
            ctx);

        Q_EMIT listTagsRequest(
            ctx);
    }
    else if (fname == QStringLiteral("listTagsByNotebook"))
    {
        Guid notebookGuid;
        IRequestContextPtr ctx;

        parseNoteStoreListTagsByNotebookParams(
            reader,
            notebookGuid,
            ctx);

        Q_EMIT listTagsByNotebookRequest(
            notebookGuid,
            ctx);
    }
    else if (fname == QStringLiteral("getTag"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetTagParams(
            reader,
            guid,
            ctx);

        Q_EMIT getTagRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("createTag"))
    {
        Tag tag;
        IRequestContextPtr ctx;

        parseNoteStoreCreateTagParams(
            reader,
            tag,
            ctx);

        Q_EMIT createTagRequest(
            tag,
            ctx);
    }
    else if (fname == QStringLiteral("updateTag"))
    {
        Tag tag;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateTagParams(
            reader,
            tag,
            ctx);

        Q_EMIT updateTagRequest(
            tag,
            ctx);
    }
    else if (fname == QStringLiteral("untagAll"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreUntagAllParams(
            reader,
            guid,
            ctx);

        Q_EMIT untagAllRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("expungeTag"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreExpungeTagParams(
            reader,
            guid,
            ctx);

        Q_EMIT expungeTagRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("listSearches"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreListSearchesParams(
            reader,
            ctx);

        Q_EMIT listSearchesRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getSearch"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetSearchParams(
            reader,
            guid,
            ctx);

        Q_EMIT getSearchRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("createSearch"))
    {
        SavedSearch search;
        IRequestContextPtr ctx;

        parseNoteStoreCreateSearchParams(
            reader,
            search,
            ctx);

        Q_EMIT createSearchRequest(
            search,
            ctx);
    }
    else if (fname == QStringLiteral("updateSearch"))
    {
        SavedSearch search;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateSearchParams(
            reader,
            search,
            ctx);

        Q_EMIT updateSearchRequest(
            search,
            ctx);
    }
    else if (fname == QStringLiteral("expungeSearch"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreExpungeSearchParams(
            reader,
            guid,
            ctx);

        Q_EMIT expungeSearchRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("findNoteOffset"))
    {
        NoteFilter filter;
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreFindNoteOffsetParams(
            reader,
            filter,
            guid,
            ctx);

        Q_EMIT findNoteOffsetRequest(
            filter,
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("findNotesMetadata"))
    {
        NoteFilter filter;
        qint32 offset = 0;
        qint32 maxNotes = 0;
        NotesMetadataResultSpec resultSpec;
        IRequestContextPtr ctx;

        parseNoteStoreFindNotesMetadataParams(
            reader,
            filter,
            offset,
            maxNotes,
            resultSpec,
            ctx);

        Q_EMIT findNotesMetadataRequest(
            filter,
            offset,
            maxNotes,
            resultSpec,
            ctx);
    }
    else if (fname == QStringLiteral("findNoteCounts"))
    {
        NoteFilter filter;
        bool withTrash = false;
        IRequestContextPtr ctx;

        parseNoteStoreFindNoteCountsParams(
            reader,
            filter,
            withTrash,
            ctx);

        Q_EMIT findNoteCountsRequest(
            filter,
            withTrash,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteWithResultSpec"))
    {
        Guid guid;
        NoteResultSpec resultSpec;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteWithResultSpecParams(
            reader,
            guid,
            resultSpec,
            ctx);

        Q_EMIT getNoteWithResultSpecRequest(
            guid,
            resultSpec,
            ctx);
    }
    else if (fname == QStringLiteral("getNote"))
    {
        Guid guid;
        bool withContent = false;
        bool withResourcesData = false;
        bool withResourcesRecognition = false;
        bool withResourcesAlternateData = false;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteParams(
            reader,
            guid,
            withContent,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);

        Q_EMIT getNoteRequest(
            guid,
            withContent,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteApplicationData"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteApplicationDataParams(
            reader,
            guid,
            ctx);

        Q_EMIT getNoteApplicationDataRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteApplicationDataEntryParams(
            reader,
            guid,
            key,
            ctx);

        Q_EMIT getNoteApplicationDataEntryRequest(
            guid,
            key,
            ctx);
    }
    else if (fname == QStringLiteral("setNoteApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        QString value;
        IRequestContextPtr ctx;

        parseNoteStoreSetNoteApplicationDataEntryParams(
            reader,
            guid,
            key,
            value,
            ctx);

        Q_EMIT setNoteApplicationDataEntryRequest(
            guid,
            key,
            value,
            ctx);
    }
    else if (fname == QStringLiteral("unsetNoteApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        IRequestContextPtr ctx;

        parseNoteStoreUnsetNoteApplicationDataEntryParams(
            reader,
            guid,
            key,
            ctx);

        Q_EMIT unsetNoteApplicationDataEntryRequest(
            guid,
            key,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteContent"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteContentParams(
            reader,
            guid,
            ctx);

        Q_EMIT getNoteContentRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteSearchText"))
    {
        Guid guid;
        bool noteOnly = false;
        bool tokenizeForIndexing = false;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteSearchTextParams(
            reader,
            guid,
            noteOnly,
            tokenizeForIndexing,
            ctx);

        Q_EMIT getNoteSearchTextRequest(
            guid,
            noteOnly,
            tokenizeForIndexing,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceSearchText"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceSearchTextParams(
            reader,
            guid,
            ctx);

        Q_EMIT getResourceSearchTextRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteTagNames"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteTagNamesParams(
            reader,
            guid,
            ctx);

        Q_EMIT getNoteTagNamesRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("createNote"))
    {
        Note note;
        IRequestContextPtr ctx;

        parseNoteStoreCreateNoteParams(
            reader,
            note,
            ctx);

        Q_EMIT createNoteRequest(
            note,
            ctx);
    }
    else if (fname == QStringLiteral("updateNote"))
    {
        Note note;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateNoteParams(
            reader,
            note,
            ctx);

        Q_EMIT updateNoteRequest(
            note,
            ctx);
    }
    else if (fname == QStringLiteral("deleteNote"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreDeleteNoteParams(
            reader,
            guid,
            ctx);

        Q_EMIT deleteNoteRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("expungeNote"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreExpungeNoteParams(
            reader,
            guid,
            ctx);

        Q_EMIT expungeNoteRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("copyNote"))
    {
        Guid noteGuid;
        Guid toNotebookGuid;
        IRequestContextPtr ctx;

        parseNoteStoreCopyNoteParams(
            reader,
            noteGuid,
            toNotebookGuid,
            ctx);

        Q_EMIT copyNoteRequest(
            noteGuid,
            toNotebookGuid,
            ctx);
    }
    else if (fname == QStringLiteral("listNoteVersions"))
    {
        Guid noteGuid;
        IRequestContextPtr ctx;

        parseNoteStoreListNoteVersionsParams(
            reader,
            noteGuid,
            ctx);

        Q_EMIT listNoteVersionsRequest(
            noteGuid,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteVersion"))
    {
        Guid noteGuid;
        qint32 updateSequenceNum = 0;
        bool withResourcesData = false;
        bool withResourcesRecognition = false;
        bool withResourcesAlternateData = false;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteVersionParams(
            reader,
            noteGuid,
            updateSequenceNum,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);

        Q_EMIT getNoteVersionRequest(
            noteGuid,
            updateSequenceNum,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);
    }
    else if (fname == QStringLiteral("getResource"))
    {
        Guid guid;
        bool withData = false;
        bool withRecognition = false;
        bool withAttributes = false;
        bool withAlternateData = false;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceParams(
            reader,
            guid,
            withData,
            withRecognition,
            withAttributes,
            withAlternateData,
            ctx);

        Q_EMIT getResourceRequest(
            guid,
            withData,
            withRecognition,
            withAttributes,
            withAlternateData,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceApplicationData"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceApplicationDataParams(
            reader,
            guid,
            ctx);

        Q_EMIT getResourceApplicationDataRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceApplicationDataEntryParams(
            reader,
            guid,
            key,
            ctx);

        Q_EMIT getResourceApplicationDataEntryRequest(
            guid,
            key,
            ctx);
    }
    else if (fname == QStringLiteral("setResourceApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        QString value;
        IRequestContextPtr ctx;

        parseNoteStoreSetResourceApplicationDataEntryParams(
            reader,
            guid,
            key,
            value,
            ctx);

        Q_EMIT setResourceApplicationDataEntryRequest(
            guid,
            key,
            value,
            ctx);
    }
    else if (fname == QStringLiteral("unsetResourceApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        IRequestContextPtr ctx;

        parseNoteStoreUnsetResourceApplicationDataEntryParams(
            reader,
            guid,
            key,
            ctx);

        Q_EMIT unsetResourceApplicationDataEntryRequest(
            guid,
            key,
            ctx);
    }
    else if (fname == QStringLiteral("updateResource"))
    {
        Resource resource;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateResourceParams(
            reader,
            resource,
            ctx);

        Q_EMIT updateResourceRequest(
            resource,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceData"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceDataParams(
            reader,
            guid,
            ctx);

        Q_EMIT getResourceDataRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceByHash"))
    {
        Guid noteGuid;
        QByteArray contentHash;
        bool withData = false;
        bool withRecognition = false;
        bool withAlternateData = false;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceByHashParams(
            reader,
            noteGuid,
            contentHash,
            withData,
            withRecognition,
            withAlternateData,
            ctx);

        Q_EMIT getResourceByHashRequest(
            noteGuid,
            contentHash,
            withData,
            withRecognition,
            withAlternateData,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceRecognition"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceRecognitionParams(
            reader,
            guid,
            ctx);

        Q_EMIT getResourceRecognitionRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceAlternateData"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceAlternateDataParams(
            reader,
            guid,
            ctx);

        Q_EMIT getResourceAlternateDataRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceAttributes"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceAttributesParams(
            reader,
            guid,
            ctx);

        Q_EMIT getResourceAttributesRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getPublicNotebook"))
    {
        UserID userId;
        QString publicUri;
        IRequestContextPtr ctx;

        parseNoteStoreGetPublicNotebookParams(
            reader,
            userId,
            publicUri,
            ctx);

        Q_EMIT getPublicNotebookRequest(
            userId,
            publicUri,
            ctx);
    }
    else if (fname == QStringLiteral("shareNotebook"))
    {
        SharedNotebook sharedNotebook;
        QString message;
        IRequestContextPtr ctx;

        parseNoteStoreShareNotebookParams(
            reader,
            sharedNotebook,
            message,
            ctx);

        Q_EMIT shareNotebookRequest(
            sharedNotebook,
            message,
            ctx);
    }
    else if (fname == QStringLiteral("createOrUpdateNotebookShares"))
    {
        NotebookShareTemplate shareTemplate;
        IRequestContextPtr ctx;

        parseNoteStoreCreateOrUpdateNotebookSharesParams(
            reader,
            shareTemplate,
            ctx);

        Q_EMIT createOrUpdateNotebookSharesRequest(
            shareTemplate,
            ctx);
    }
    else if (fname == QStringLiteral("updateSharedNotebook"))
    {
        SharedNotebook sharedNotebook;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateSharedNotebookParams(
            reader,
            sharedNotebook,
            ctx);

        Q_EMIT updateSharedNotebookRequest(
            sharedNotebook,
            ctx);
    }
    else if (fname == QStringLiteral("setNotebookRecipientSettings"))
    {
        QString notebookGuid;
        NotebookRecipientSettings recipientSettings;
        IRequestContextPtr ctx;

        parseNoteStoreSetNotebookRecipientSettingsParams(
            reader,
            notebookGuid,
            recipientSettings,
            ctx);

        Q_EMIT setNotebookRecipientSettingsRequest(
            notebookGuid,
            recipientSettings,
            ctx);
    }
    else if (fname == QStringLiteral("listSharedNotebooks"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreListSharedNotebooksParams(
            reader,
            ctx);

        Q_EMIT listSharedNotebooksRequest(
            ctx);
    }
    else if (fname == QStringLiteral("createLinkedNotebook"))
    {
        LinkedNotebook linkedNotebook;
        IRequestContextPtr ctx;

        parseNoteStoreCreateLinkedNotebookParams(
            reader,
            linkedNotebook,
            ctx);

        Q_EMIT createLinkedNotebookRequest(
            linkedNotebook,
            ctx);
    }
    else if (fname == QStringLiteral("updateLinkedNotebook"))
    {
        LinkedNotebook linkedNotebook;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateLinkedNotebookParams(
            reader,
            linkedNotebook,
            ctx);

        Q_EMIT updateLinkedNotebookRequest(
            linkedNotebook,
            ctx);
    }
    else if (fname == QStringLiteral("listLinkedNotebooks"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreListLinkedNotebooksParams(
            reader,
            ctx);

        Q_EMIT listLinkedNotebooksRequest(
            ctx);
    }
    else if (fname == QStringLiteral("expungeLinkedNotebook"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreExpungeLinkedNotebookParams(
            reader,
            guid,
            ctx);

        Q_EMIT expungeLinkedNotebookRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("authenticateToSharedNotebook"))
    {
        QString shareKeyOrGlobalId;
        IRequestContextPtr ctx;

        parseNoteStoreAuthenticateToSharedNotebookParams(
            reader,
            shareKeyOrGlobalId,
            ctx);

        Q_EMIT authenticateToSharedNotebookRequest(
            shareKeyOrGlobalId,
            ctx);
    }
    else if (fname == QStringLiteral("getSharedNotebookByAuth"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreGetSharedNotebookByAuthParams(
            reader,
            ctx);

        Q_EMIT getSharedNotebookByAuthRequest(
            ctx);
    }
    else if (fname == QStringLiteral("emailNote"))
    {
        NoteEmailParameters parameters;
        IRequestContextPtr ctx;

        parseNoteStoreEmailNoteParams(
            reader,
            parameters,
            ctx);

        Q_EMIT emailNoteRequest(
            parameters,
            ctx);
    }
    else if (fname == QStringLiteral("shareNote"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreShareNoteParams(
            reader,
            guid,
            ctx);

        Q_EMIT shareNoteRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("stopSharingNote"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreStopSharingNoteParams(
            reader,
            guid,
            ctx);

        Q_EMIT stopSharingNoteRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("authenticateToSharedNote"))
    {
        QString guid;
        QString noteKey;
        IRequestContextPtr ctx;

        parseNoteStoreAuthenticateToSharedNoteParams(
            reader,
            guid,
            noteKey,
            ctx);

        Q_EMIT authenticateToSharedNoteRequest(
            guid,
            noteKey,
            ctx);
    }
    else if (fname == QStringLiteral("findRelated"))
    {
        RelatedQuery query;
        RelatedResultSpec resultSpec;
        IRequestContextPtr ctx;

        parseNoteStoreFindRelatedParams(
            reader,
            query,
            resultSpec,
            ctx);

        Q_EMIT findRelatedRequest(
            query,
            resultSpec,
            ctx);
    }
    else if (fname == QStringLiteral("updateNoteIfUsnMatches"))
    {
        Note note;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateNoteIfUsnMatchesParams(
            reader,
            note,
            ctx);

        Q_EMIT updateNoteIfUsnMatchesRequest(
            note,
            ctx);
    }
    else if (fname == QStringLiteral("manageNotebookShares"))
    {
        ManageNotebookSharesParameters parameters;
        IRequestContextPtr ctx;

        parseNoteStoreManageNotebookSharesParams(
            reader,
            parameters,
            ctx);

        Q_EMIT manageNotebookSharesRequest(
            parameters,
            ctx);
    }
    else if (fname == QStringLiteral("getNotebookShares"))
    {
        QString notebookGuid;
        IRequestContextPtr ctx;

        parseNoteStoreGetNotebookSharesParams(
            reader,
            notebookGuid,
            ctx);

        Q_EMIT getNotebookSharesRequest(
            notebookGuid,
            ctx);
    }
}

void NoteStoreServer::onGetSyncStateRequestReady(
    SyncState value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getSyncState"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getSyncStateRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getSyncState"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getSyncState"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSyncStateRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSyncStateRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getSyncState"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSyncState(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getSyncStateRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetFilteredSyncChunkRequestReady(
    SyncChunk value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getFilteredSyncChunk"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getFilteredSyncChunkRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getFilteredSyncChunk"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getFilteredSyncChunk"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getFilteredSyncChunkRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getFilteredSyncChunkRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getFilteredSyncChunk"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSyncChunk(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getFilteredSyncChunkRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetLinkedNotebookSyncStateRequestReady(
    SyncState value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getLinkedNotebookSyncState"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncStateRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getLinkedNotebookSyncState"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getLinkedNotebookSyncState"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncStateRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncStateRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncStateRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getLinkedNotebookSyncState"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSyncState(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getLinkedNotebookSyncStateRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetLinkedNotebookSyncChunkRequestReady(
    SyncChunk value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getLinkedNotebookSyncChunk"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncChunkRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getLinkedNotebookSyncChunk"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getLinkedNotebookSyncChunk"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncChunkRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncChunkRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncChunkRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getLinkedNotebookSyncChunk"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSyncChunk(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getLinkedNotebookSyncChunkRequestReady(
        writer.buffer());
}

void NoteStoreServer::onListNotebooksRequestReady(
    QList<Notebook> value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listNotebooks"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listNotebooksRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listNotebooks"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listNotebooks"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listNotebooksRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listNotebooksRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("listNotebooks"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: qAsConst(value)) {
        writeNotebook(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listNotebooksRequestReady(
        writer.buffer());
}

void NoteStoreServer::onListAccessibleBusinessNotebooksRequestReady(
    QList<Notebook> value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listAccessibleBusinessNotebooks"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listAccessibleBusinessNotebooksRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listAccessibleBusinessNotebooks"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listAccessibleBusinessNotebooks"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listAccessibleBusinessNotebooksRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listAccessibleBusinessNotebooksRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("listAccessibleBusinessNotebooks"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: qAsConst(value)) {
        writeNotebook(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listAccessibleBusinessNotebooksRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetNotebookRequestReady(
    Notebook value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNotebook"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getNotebook"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNotebookRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetDefaultNotebookRequestReady(
    Notebook value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getDefaultNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getDefaultNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getDefaultNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getDefaultNotebook"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getDefaultNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getDefaultNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getDefaultNotebook"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getDefaultNotebookRequestReady(
        writer.buffer());
}

void NoteStoreServer::onCreateNotebookRequestReady(
    Notebook value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("createNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT createNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("createNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("createNotebook"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("createNotebook"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT createNotebookRequestReady(
        writer.buffer());
}

void NoteStoreServer::onUpdateNotebookRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateNotebook"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("updateNotebook"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateNotebookRequestReady(
        writer.buffer());
}

void NoteStoreServer::onExpungeNotebookRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("expungeNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT expungeNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("expungeNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("expungeNotebook"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("expungeNotebook"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT expungeNotebookRequestReady(
        writer.buffer());
}

void NoteStoreServer::onListTagsRequestReady(
    QList<Tag> value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listTags"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listTagsRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listTags"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listTags"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listTagsRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listTagsRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("listTags"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: qAsConst(value)) {
        writeTag(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listTagsRequestReady(
        writer.buffer());
}

void NoteStoreServer::onListTagsByNotebookRequestReady(
    QList<Tag> value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listTagsByNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listTagsByNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listTagsByNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listTagsByNotebook"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listTagsByNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listTagsByNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listTagsByNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("listTagsByNotebook"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: qAsConst(value)) {
        writeTag(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listTagsByNotebookRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetTagRequestReady(
    Tag value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getTag"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getTagRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getTag"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getTag"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getTagRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getTagRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getTagRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getTag"),
        ThriftFieldType::T_STRUCT,
        0);
    writeTag(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getTagRequestReady(
        writer.buffer());
}

void NoteStoreServer::onCreateTagRequestReady(
    Tag value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("createTag"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT createTagRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("createTag"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("createTag"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createTagRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createTagRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createTagRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("createTag"),
        ThriftFieldType::T_STRUCT,
        0);
    writeTag(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT createTagRequestReady(
        writer.buffer());
}

void NoteStoreServer::onUpdateTagRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateTag"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateTagRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateTag"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateTag"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateTagRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateTagRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateTagRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("updateTag"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateTagRequestReady(
        writer.buffer());
}

void NoteStoreServer::onUntagAllRequestReady(
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("untagAll"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT untagAllRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("untagAll"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("untagAll"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT untagAllRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT untagAllRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT untagAllRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("untagAll"),
        ThriftFieldType::T_VOID,
        0);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT untagAllRequestReady(
        writer.buffer());
}

void NoteStoreServer::onExpungeTagRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("expungeTag"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT expungeTagRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("expungeTag"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("expungeTag"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeTagRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeTagRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeTagRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("expungeTag"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT expungeTagRequestReady(
        writer.buffer());
}

void NoteStoreServer::onListSearchesRequestReady(
    QList<SavedSearch> value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listSearches"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listSearchesRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listSearches"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listSearches"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listSearchesRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listSearchesRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("listSearches"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: qAsConst(value)) {
        writeSavedSearch(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listSearchesRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetSearchRequestReady(
    SavedSearch value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getSearch"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getSearch"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getSearch"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getSearch"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSavedSearch(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getSearchRequestReady(
        writer.buffer());
}

void NoteStoreServer::onCreateSearchRequestReady(
    SavedSearch value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("createSearch"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT createSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("createSearch"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("createSearch"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("createSearch"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSavedSearch(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT createSearchRequestReady(
        writer.buffer());
}

void NoteStoreServer::onUpdateSearchRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateSearch"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateSearch"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateSearch"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("updateSearch"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateSearchRequestReady(
        writer.buffer());
}

void NoteStoreServer::onExpungeSearchRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("expungeSearch"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT expungeSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("expungeSearch"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("expungeSearch"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeSearchRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("expungeSearch"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT expungeSearchRequestReady(
        writer.buffer());
}

void NoteStoreServer::onFindNoteOffsetRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("findNoteOffset"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT findNoteOffsetRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("findNoteOffset"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("findNoteOffset"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNoteOffsetRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNoteOffsetRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNoteOffsetRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("findNoteOffset"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT findNoteOffsetRequestReady(
        writer.buffer());
}

void NoteStoreServer::onFindNotesMetadataRequestReady(
    NotesMetadataList value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("findNotesMetadata"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT findNotesMetadataRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("findNotesMetadata"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("findNotesMetadata"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNotesMetadataRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNotesMetadataRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNotesMetadataRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("findNotesMetadata"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNotesMetadataList(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT findNotesMetadataRequestReady(
        writer.buffer());
}

void NoteStoreServer::onFindNoteCountsRequestReady(
    NoteCollectionCounts value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("findNoteCounts"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT findNoteCountsRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("findNoteCounts"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("findNoteCounts"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNoteCountsRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNoteCountsRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNoteCountsRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("findNoteCounts"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNoteCollectionCounts(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT findNoteCountsRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetNoteWithResultSpecRequestReady(
    Note value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNoteWithResultSpec"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteWithResultSpecRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNoteWithResultSpec"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNoteWithResultSpec"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteWithResultSpecRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteWithResultSpecRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteWithResultSpecRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getNoteWithResultSpec"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNote(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteWithResultSpecRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetNoteRequestReady(
    Note value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNote"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getNote"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNote(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetNoteApplicationDataRequestReady(
    LazyMap value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNoteApplicationData"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNoteApplicationData"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNoteApplicationData"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getNoteApplicationData"),
        ThriftFieldType::T_STRUCT,
        0);
    writeLazyMap(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteApplicationDataRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetNoteApplicationDataEntryRequestReady(
    QString value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNoteApplicationDataEntry"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNoteApplicationDataEntry"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNoteApplicationDataEntry"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getNoteApplicationDataEntry"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeString(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteApplicationDataEntryRequestReady(
        writer.buffer());
}

void NoteStoreServer::onSetNoteApplicationDataEntryRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("setNoteApplicationDataEntry"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT setNoteApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("setNoteApplicationDataEntry"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("setNoteApplicationDataEntry"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setNoteApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setNoteApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setNoteApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("setNoteApplicationDataEntry"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT setNoteApplicationDataEntryRequestReady(
        writer.buffer());
}

void NoteStoreServer::onUnsetNoteApplicationDataEntryRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("unsetNoteApplicationDataEntry"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT unsetNoteApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("unsetNoteApplicationDataEntry"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("unsetNoteApplicationDataEntry"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT unsetNoteApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT unsetNoteApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT unsetNoteApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("unsetNoteApplicationDataEntry"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT unsetNoteApplicationDataEntryRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetNoteContentRequestReady(
    QString value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNoteContent"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteContentRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNoteContent"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNoteContent"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteContentRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteContentRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteContentRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getNoteContent"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeString(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteContentRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetNoteSearchTextRequestReady(
    QString value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNoteSearchText"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteSearchTextRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNoteSearchText"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNoteSearchText"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteSearchTextRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteSearchTextRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteSearchTextRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getNoteSearchText"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeString(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteSearchTextRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetResourceSearchTextRequestReady(
    QString value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceSearchText"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceSearchTextRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceSearchText"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceSearchText"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceSearchTextRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceSearchTextRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceSearchTextRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceSearchText"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeString(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceSearchTextRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetNoteTagNamesRequestReady(
    QStringList value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNoteTagNames"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteTagNamesRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNoteTagNames"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNoteTagNames"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteTagNamesRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteTagNamesRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteTagNamesRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getNoteTagNames"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRING, value.size());
    for(const auto & v: qAsConst(value)) {
        writer.writeString(v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteTagNamesRequestReady(
        writer.buffer());
}

void NoteStoreServer::onCreateNoteRequestReady(
    Note value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("createNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT createNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("createNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("createNote"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("createNote"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNote(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT createNoteRequestReady(
        writer.buffer());
}

void NoteStoreServer::onUpdateNoteRequestReady(
    Note value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateNote"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("updateNote"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNote(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateNoteRequestReady(
        writer.buffer());
}

void NoteStoreServer::onDeleteNoteRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("deleteNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT deleteNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("deleteNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("deleteNote"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT deleteNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT deleteNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT deleteNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("deleteNote"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT deleteNoteRequestReady(
        writer.buffer());
}

void NoteStoreServer::onExpungeNoteRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("expungeNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT expungeNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("expungeNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("expungeNote"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("expungeNote"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT expungeNoteRequestReady(
        writer.buffer());
}

void NoteStoreServer::onCopyNoteRequestReady(
    Note value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("copyNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT copyNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("copyNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("copyNote"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT copyNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT copyNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT copyNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("copyNote"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNote(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT copyNoteRequestReady(
        writer.buffer());
}

void NoteStoreServer::onListNoteVersionsRequestReady(
    QList<NoteVersionId> value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listNoteVersions"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listNoteVersionsRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listNoteVersions"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listNoteVersions"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listNoteVersionsRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listNoteVersionsRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listNoteVersionsRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("listNoteVersions"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: qAsConst(value)) {
        writeNoteVersionId(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listNoteVersionsRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetNoteVersionRequestReady(
    Note value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNoteVersion"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteVersionRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNoteVersion"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNoteVersion"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteVersionRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteVersionRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteVersionRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getNoteVersion"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNote(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteVersionRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetResourceRequestReady(
    Resource value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResource"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResource"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResource"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getResource"),
        ThriftFieldType::T_STRUCT,
        0);
    writeResource(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetResourceApplicationDataRequestReady(
    LazyMap value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceApplicationData"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceApplicationData"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceApplicationData"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceApplicationData"),
        ThriftFieldType::T_STRUCT,
        0);
    writeLazyMap(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceApplicationDataRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetResourceApplicationDataEntryRequestReady(
    QString value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceApplicationDataEntry"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceApplicationDataEntry"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceApplicationDataEntry"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceApplicationDataEntry"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeString(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceApplicationDataEntryRequestReady(
        writer.buffer());
}

void NoteStoreServer::onSetResourceApplicationDataEntryRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("setResourceApplicationDataEntry"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT setResourceApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("setResourceApplicationDataEntry"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("setResourceApplicationDataEntry"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setResourceApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setResourceApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setResourceApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("setResourceApplicationDataEntry"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT setResourceApplicationDataEntryRequestReady(
        writer.buffer());
}

void NoteStoreServer::onUnsetResourceApplicationDataEntryRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("unsetResourceApplicationDataEntry"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT unsetResourceApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("unsetResourceApplicationDataEntry"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("unsetResourceApplicationDataEntry"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT unsetResourceApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT unsetResourceApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT unsetResourceApplicationDataEntryRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("unsetResourceApplicationDataEntry"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT unsetResourceApplicationDataEntryRequestReady(
        writer.buffer());
}

void NoteStoreServer::onUpdateResourceRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateResource"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateResourceRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateResource"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateResource"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateResourceRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateResourceRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateResourceRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("updateResource"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateResourceRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetResourceDataRequestReady(
    QByteArray value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceData"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceDataRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceData"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceData"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceDataRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceDataRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceDataRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceData"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeBinary(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceDataRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetResourceByHashRequestReady(
    Resource value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceByHash"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceByHashRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceByHash"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceByHash"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceByHashRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceByHashRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceByHashRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceByHash"),
        ThriftFieldType::T_STRUCT,
        0);
    writeResource(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceByHashRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetResourceRecognitionRequestReady(
    QByteArray value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceRecognition"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceRecognitionRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceRecognition"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceRecognition"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceRecognitionRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceRecognitionRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceRecognitionRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceRecognition"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeBinary(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceRecognitionRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetResourceAlternateDataRequestReady(
    QByteArray value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceAlternateData"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceAlternateDataRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceAlternateData"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceAlternateData"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceAlternateDataRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceAlternateDataRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceAlternateDataRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceAlternateData"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeBinary(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceAlternateDataRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetResourceAttributesRequestReady(
    ResourceAttributes value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceAttributes"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceAttributesRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceAttributes"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceAttributes"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceAttributesRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceAttributesRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceAttributesRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceAttributes"),
        ThriftFieldType::T_STRUCT,
        0);
    writeResourceAttributes(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceAttributesRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetPublicNotebookRequestReady(
    Notebook value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getPublicNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getPublicNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getPublicNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getPublicNotebook"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getPublicNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getPublicNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getPublicNotebook"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getPublicNotebookRequestReady(
        writer.buffer());
}

void NoteStoreServer::onShareNotebookRequestReady(
    SharedNotebook value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("shareNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT shareNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("shareNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("shareNotebook"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT shareNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT shareNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT shareNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("shareNotebook"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSharedNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT shareNotebookRequestReady(
        writer.buffer());
}

void NoteStoreServer::onCreateOrUpdateNotebookSharesRequestReady(
    CreateOrUpdateNotebookSharesResult value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("createOrUpdateNotebookShares"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT createOrUpdateNotebookSharesRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("createOrUpdateNotebookShares"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("createOrUpdateNotebookShares"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createOrUpdateNotebookSharesRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createOrUpdateNotebookSharesRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createOrUpdateNotebookSharesRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMInvalidContactsException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMInvalidContactsException"),
                ThriftFieldType::T_STRUCT,
                4);

            writeEDAMInvalidContactsException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createOrUpdateNotebookSharesRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("createOrUpdateNotebookShares"),
        ThriftFieldType::T_STRUCT,
        0);
    writeCreateOrUpdateNotebookSharesResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT createOrUpdateNotebookSharesRequestReady(
        writer.buffer());
}

void NoteStoreServer::onUpdateSharedNotebookRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateSharedNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateSharedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateSharedNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateSharedNotebook"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateSharedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateSharedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateSharedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("updateSharedNotebook"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateSharedNotebookRequestReady(
        writer.buffer());
}

void NoteStoreServer::onSetNotebookRecipientSettingsRequestReady(
    Notebook value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("setNotebookRecipientSettings"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT setNotebookRecipientSettingsRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("setNotebookRecipientSettings"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("setNotebookRecipientSettings"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setNotebookRecipientSettingsRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setNotebookRecipientSettingsRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setNotebookRecipientSettingsRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("setNotebookRecipientSettings"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT setNotebookRecipientSettingsRequestReady(
        writer.buffer());
}

void NoteStoreServer::onListSharedNotebooksRequestReady(
    QList<SharedNotebook> value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listSharedNotebooks"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listSharedNotebooksRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listSharedNotebooks"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listSharedNotebooks"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listSharedNotebooksRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listSharedNotebooksRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listSharedNotebooksRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("listSharedNotebooks"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: qAsConst(value)) {
        writeSharedNotebook(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listSharedNotebooksRequestReady(
        writer.buffer());
}

void NoteStoreServer::onCreateLinkedNotebookRequestReady(
    LinkedNotebook value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("createLinkedNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT createLinkedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("createLinkedNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("createLinkedNotebook"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createLinkedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createLinkedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createLinkedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("createLinkedNotebook"),
        ThriftFieldType::T_STRUCT,
        0);
    writeLinkedNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT createLinkedNotebookRequestReady(
        writer.buffer());
}

void NoteStoreServer::onUpdateLinkedNotebookRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateLinkedNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateLinkedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateLinkedNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateLinkedNotebook"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateLinkedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateLinkedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateLinkedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("updateLinkedNotebook"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateLinkedNotebookRequestReady(
        writer.buffer());
}

void NoteStoreServer::onListLinkedNotebooksRequestReady(
    QList<LinkedNotebook> value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listLinkedNotebooks"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listLinkedNotebooksRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listLinkedNotebooks"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listLinkedNotebooks"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listLinkedNotebooksRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listLinkedNotebooksRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listLinkedNotebooksRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("listLinkedNotebooks"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: qAsConst(value)) {
        writeLinkedNotebook(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listLinkedNotebooksRequestReady(
        writer.buffer());
}

void NoteStoreServer::onExpungeLinkedNotebookRequestReady(
    qint32 value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("expungeLinkedNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT expungeLinkedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("expungeLinkedNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("expungeLinkedNotebook"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeLinkedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeLinkedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeLinkedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("expungeLinkedNotebook"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT expungeLinkedNotebookRequestReady(
        writer.buffer());
}

void NoteStoreServer::onAuthenticateToSharedNotebookRequestReady(
    AuthenticationResult value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("authenticateToSharedNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("authenticateToSharedNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("authenticateToSharedNotebook"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNotebookRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("authenticateToSharedNotebook"),
        ThriftFieldType::T_STRUCT,
        0);
    writeAuthenticationResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT authenticateToSharedNotebookRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetSharedNotebookByAuthRequestReady(
    SharedNotebook value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getSharedNotebookByAuth"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getSharedNotebookByAuthRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getSharedNotebookByAuth"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getSharedNotebookByAuth"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSharedNotebookByAuthRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSharedNotebookByAuthRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSharedNotebookByAuthRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getSharedNotebookByAuth"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSharedNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getSharedNotebookByAuthRequestReady(
        writer.buffer());
}

void NoteStoreServer::onEmailNoteRequestReady(
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("emailNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT emailNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("emailNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("emailNote"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT emailNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT emailNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT emailNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("emailNote"),
        ThriftFieldType::T_VOID,
        0);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT emailNoteRequestReady(
        writer.buffer());
}

void NoteStoreServer::onShareNoteRequestReady(
    QString value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("shareNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT shareNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("shareNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("shareNote"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT shareNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT shareNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT shareNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("shareNote"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeString(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT shareNoteRequestReady(
        writer.buffer());
}

void NoteStoreServer::onStopSharingNoteRequestReady(
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("stopSharingNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT stopSharingNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("stopSharingNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("stopSharingNote"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT stopSharingNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT stopSharingNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT stopSharingNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("stopSharingNote"),
        ThriftFieldType::T_VOID,
        0);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT stopSharingNoteRequestReady(
        writer.buffer());
}

void NoteStoreServer::onAuthenticateToSharedNoteRequestReady(
    AuthenticationResult value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("authenticateToSharedNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("authenticateToSharedNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("authenticateToSharedNote"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNoteRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("authenticateToSharedNote"),
        ThriftFieldType::T_STRUCT,
        0);
    writeAuthenticationResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT authenticateToSharedNoteRequestReady(
        writer.buffer());
}

void NoteStoreServer::onFindRelatedRequestReady(
    RelatedResult value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("findRelated"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT findRelatedRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("findRelated"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("findRelated"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findRelatedRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findRelatedRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findRelatedRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("findRelated"),
        ThriftFieldType::T_STRUCT,
        0);
    writeRelatedResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT findRelatedRequestReady(
        writer.buffer());
}

void NoteStoreServer::onUpdateNoteIfUsnMatchesRequestReady(
    UpdateNoteIfUsnMatchesResult value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateNoteIfUsnMatches"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateNoteIfUsnMatchesRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateNoteIfUsnMatches"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateNoteIfUsnMatches"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNoteIfUsnMatchesRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNoteIfUsnMatchesRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNoteIfUsnMatchesRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("updateNoteIfUsnMatches"),
        ThriftFieldType::T_STRUCT,
        0);
    writeUpdateNoteIfUsnMatchesResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateNoteIfUsnMatchesRequestReady(
        writer.buffer());
}

void NoteStoreServer::onManageNotebookSharesRequestReady(
    ManageNotebookSharesResult value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("manageNotebookShares"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT manageNotebookSharesRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("manageNotebookShares"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("manageNotebookShares"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT manageNotebookSharesRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT manageNotebookSharesRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT manageNotebookSharesRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("manageNotebookShares"),
        ThriftFieldType::T_STRUCT,
        0);
    writeManageNotebookSharesResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT manageNotebookSharesRequestReady(
        writer.buffer());
}

void NoteStoreServer::onGetNotebookSharesRequestReady(
    ShareRelationships value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNotebookShares"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNotebookSharesRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNotebookShares"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNotebookShares"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNotebookSharesRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNotebookSharesRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNotebookSharesRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getNotebookShares"),
        ThriftFieldType::T_STRUCT,
        0);
    writeShareRelationships(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNotebookSharesRequestReady(
        writer.buffer());
}

////////////////////////////////////////////////////////////////////////////////

UserStoreServer::UserStoreServer(QObject * parent) :
    QObject(parent)
{}

void UserStoreServer::onRequest(QByteArray data)
{
    ThriftBinaryBufferReader reader(data);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);

    if (mtype != ThriftMessageType::T_CALL) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }

    if (fname == QStringLiteral("checkVersion"))
    {
        QString clientName;
        qint16 edamVersionMajor = 0;
        qint16 edamVersionMinor = 0;
        IRequestContextPtr ctx;

        parseUserStoreCheckVersionParams(
            reader,
            clientName,
            edamVersionMajor,
            edamVersionMinor,
            ctx);

        Q_EMIT checkVersionRequest(
            clientName,
            edamVersionMajor,
            edamVersionMinor,
            ctx);
    }
    else if (fname == QStringLiteral("getBootstrapInfo"))
    {
        QString locale;
        IRequestContextPtr ctx;

        parseUserStoreGetBootstrapInfoParams(
            reader,
            locale,
            ctx);

        Q_EMIT getBootstrapInfoRequest(
            locale,
            ctx);
    }
    else if (fname == QStringLiteral("authenticateLongSession"))
    {
        QString username;
        QString password;
        QString consumerKey;
        QString consumerSecret;
        QString deviceIdentifier;
        QString deviceDescription;
        bool supportsTwoFactor = false;
        IRequestContextPtr ctx;

        parseUserStoreAuthenticateLongSessionParams(
            reader,
            username,
            password,
            consumerKey,
            consumerSecret,
            deviceIdentifier,
            deviceDescription,
            supportsTwoFactor,
            ctx);

        Q_EMIT authenticateLongSessionRequest(
            username,
            password,
            consumerKey,
            consumerSecret,
            deviceIdentifier,
            deviceDescription,
            supportsTwoFactor,
            ctx);
    }
    else if (fname == QStringLiteral("completeTwoFactorAuthentication"))
    {
        QString oneTimeCode;
        QString deviceIdentifier;
        QString deviceDescription;
        IRequestContextPtr ctx;

        parseUserStoreCompleteTwoFactorAuthenticationParams(
            reader,
            oneTimeCode,
            deviceIdentifier,
            deviceDescription,
            ctx);

        Q_EMIT completeTwoFactorAuthenticationRequest(
            oneTimeCode,
            deviceIdentifier,
            deviceDescription,
            ctx);
    }
    else if (fname == QStringLiteral("revokeLongSession"))
    {
        IRequestContextPtr ctx;

        parseUserStoreRevokeLongSessionParams(
            reader,
            ctx);

        Q_EMIT revokeLongSessionRequest(
            ctx);
    }
    else if (fname == QStringLiteral("authenticateToBusiness"))
    {
        IRequestContextPtr ctx;

        parseUserStoreAuthenticateToBusinessParams(
            reader,
            ctx);

        Q_EMIT authenticateToBusinessRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getUser"))
    {
        IRequestContextPtr ctx;

        parseUserStoreGetUserParams(
            reader,
            ctx);

        Q_EMIT getUserRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getPublicUserInfo"))
    {
        QString username;
        IRequestContextPtr ctx;

        parseUserStoreGetPublicUserInfoParams(
            reader,
            username,
            ctx);

        Q_EMIT getPublicUserInfoRequest(
            username,
            ctx);
    }
    else if (fname == QStringLiteral("getUserUrls"))
    {
        IRequestContextPtr ctx;

        parseUserStoreGetUserUrlsParams(
            reader,
            ctx);

        Q_EMIT getUserUrlsRequest(
            ctx);
    }
    else if (fname == QStringLiteral("inviteToBusiness"))
    {
        QString emailAddress;
        IRequestContextPtr ctx;

        parseUserStoreInviteToBusinessParams(
            reader,
            emailAddress,
            ctx);

        Q_EMIT inviteToBusinessRequest(
            emailAddress,
            ctx);
    }
    else if (fname == QStringLiteral("removeFromBusiness"))
    {
        QString emailAddress;
        IRequestContextPtr ctx;

        parseUserStoreRemoveFromBusinessParams(
            reader,
            emailAddress,
            ctx);

        Q_EMIT removeFromBusinessRequest(
            emailAddress,
            ctx);
    }
    else if (fname == QStringLiteral("updateBusinessUserIdentifier"))
    {
        QString oldEmailAddress;
        QString newEmailAddress;
        IRequestContextPtr ctx;

        parseUserStoreUpdateBusinessUserIdentifierParams(
            reader,
            oldEmailAddress,
            newEmailAddress,
            ctx);

        Q_EMIT updateBusinessUserIdentifierRequest(
            oldEmailAddress,
            newEmailAddress,
            ctx);
    }
    else if (fname == QStringLiteral("listBusinessUsers"))
    {
        IRequestContextPtr ctx;

        parseUserStoreListBusinessUsersParams(
            reader,
            ctx);

        Q_EMIT listBusinessUsersRequest(
            ctx);
    }
    else if (fname == QStringLiteral("listBusinessInvitations"))
    {
        bool includeRequestedInvitations = false;
        IRequestContextPtr ctx;

        parseUserStoreListBusinessInvitationsParams(
            reader,
            includeRequestedInvitations,
            ctx);

        Q_EMIT listBusinessInvitationsRequest(
            includeRequestedInvitations,
            ctx);
    }
    else if (fname == QStringLiteral("getAccountLimits"))
    {
        ServiceLevel serviceLevel;
        IRequestContextPtr ctx;

        parseUserStoreGetAccountLimitsParams(
            reader,
            serviceLevel,
            ctx);

        Q_EMIT getAccountLimitsRequest(
            serviceLevel,
            ctx);
    }
}

void UserStoreServer::onCheckVersionRequestReady(
    bool value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("checkVersion"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT checkVersionRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("checkVersion"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("checkVersion"));

    writer.writeFieldBegin(
        QStringLiteral("checkVersion"),
        ThriftFieldType::T_BOOL,
        0);
    writer.writeBool(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT checkVersionRequestReady(
        writer.buffer());
}

void UserStoreServer::onGetBootstrapInfoRequestReady(
    BootstrapInfo value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getBootstrapInfo"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getBootstrapInfoRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getBootstrapInfo"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getBootstrapInfo"));

    writer.writeFieldBegin(
        QStringLiteral("getBootstrapInfo"),
        ThriftFieldType::T_STRUCT,
        0);
    writeBootstrapInfo(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getBootstrapInfoRequestReady(
        writer.buffer());
}

void UserStoreServer::onAuthenticateLongSessionRequestReady(
    AuthenticationResult value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("authenticateLongSession"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT authenticateLongSessionRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("authenticateLongSession"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("authenticateLongSession"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateLongSessionRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateLongSessionRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("authenticateLongSession"),
        ThriftFieldType::T_STRUCT,
        0);
    writeAuthenticationResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT authenticateLongSessionRequestReady(
        writer.buffer());
}

void UserStoreServer::onCompleteTwoFactorAuthenticationRequestReady(
    AuthenticationResult value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("completeTwoFactorAuthentication"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT completeTwoFactorAuthenticationRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("completeTwoFactorAuthentication"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("completeTwoFactorAuthentication"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT completeTwoFactorAuthenticationRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT completeTwoFactorAuthenticationRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("completeTwoFactorAuthentication"),
        ThriftFieldType::T_STRUCT,
        0);
    writeAuthenticationResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT completeTwoFactorAuthenticationRequestReady(
        writer.buffer());
}

void UserStoreServer::onRevokeLongSessionRequestReady(
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("revokeLongSession"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT revokeLongSessionRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("revokeLongSession"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("revokeLongSession"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT revokeLongSessionRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT revokeLongSessionRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("revokeLongSession"),
        ThriftFieldType::T_VOID,
        0);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT revokeLongSessionRequestReady(
        writer.buffer());
}

void UserStoreServer::onAuthenticateToBusinessRequestReady(
    AuthenticationResult value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("authenticateToBusiness"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT authenticateToBusinessRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("authenticateToBusiness"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("authenticateToBusiness"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToBusinessRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToBusinessRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("authenticateToBusiness"),
        ThriftFieldType::T_STRUCT,
        0);
    writeAuthenticationResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT authenticateToBusinessRequestReady(
        writer.buffer());
}

void UserStoreServer::onGetUserRequestReady(
    User value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getUser"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getUserRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getUser"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getUser"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getUserRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getUserRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getUser"),
        ThriftFieldType::T_STRUCT,
        0);
    writeUser(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getUserRequestReady(
        writer.buffer());
}

void UserStoreServer::onGetPublicUserInfoRequestReady(
    PublicUserInfo value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getPublicUserInfo"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getPublicUserInfoRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getPublicUserInfo"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getPublicUserInfo"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getPublicUserInfoRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getPublicUserInfoRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getPublicUserInfoRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getPublicUserInfo"),
        ThriftFieldType::T_STRUCT,
        0);
    writePublicUserInfo(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getPublicUserInfoRequestReady(
        writer.buffer());
}

void UserStoreServer::onGetUserUrlsRequestReady(
    UserUrls value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getUserUrls"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getUserUrlsRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getUserUrls"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getUserUrls"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getUserUrlsRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getUserUrlsRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getUserUrls"),
        ThriftFieldType::T_STRUCT,
        0);
    writeUserUrls(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getUserUrlsRequestReady(
        writer.buffer());
}

void UserStoreServer::onInviteToBusinessRequestReady(
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("inviteToBusiness"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT inviteToBusinessRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("inviteToBusiness"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("inviteToBusiness"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT inviteToBusinessRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT inviteToBusinessRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("inviteToBusiness"),
        ThriftFieldType::T_VOID,
        0);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT inviteToBusinessRequestReady(
        writer.buffer());
}

void UserStoreServer::onRemoveFromBusinessRequestReady(
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("removeFromBusiness"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT removeFromBusinessRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("removeFromBusiness"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("removeFromBusiness"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT removeFromBusinessRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT removeFromBusinessRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT removeFromBusinessRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("removeFromBusiness"),
        ThriftFieldType::T_VOID,
        0);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT removeFromBusinessRequestReady(
        writer.buffer());
}

void UserStoreServer::onUpdateBusinessUserIdentifierRequestReady(
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateBusinessUserIdentifier"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateBusinessUserIdentifierRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateBusinessUserIdentifier"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateBusinessUserIdentifier"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateBusinessUserIdentifierRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateBusinessUserIdentifierRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateBusinessUserIdentifierRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("updateBusinessUserIdentifier"),
        ThriftFieldType::T_VOID,
        0);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateBusinessUserIdentifierRequestReady(
        writer.buffer());
}

void UserStoreServer::onListBusinessUsersRequestReady(
    QList<UserProfile> value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listBusinessUsers"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listBusinessUsersRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listBusinessUsers"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listBusinessUsers"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listBusinessUsersRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listBusinessUsersRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("listBusinessUsers"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: qAsConst(value)) {
        writeUserProfile(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listBusinessUsersRequestReady(
        writer.buffer());
}

void UserStoreServer::onListBusinessInvitationsRequestReady(
    QList<BusinessInvitation> value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listBusinessInvitations"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listBusinessInvitationsRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listBusinessInvitations"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listBusinessInvitations"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listBusinessInvitationsRequestReady(
                writer.buffer());
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listBusinessInvitationsRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("listBusinessInvitations"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: qAsConst(value)) {
        writeBusinessInvitation(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listBusinessInvitationsRequestReady(
        writer.buffer());
}

void UserStoreServer::onGetAccountLimitsRequestReady(
    AccountLimits value,
    EverCloudExceptionDataPtr exceptionData)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getAccountLimits"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getAccountLimitsRequestReady(
                writer.buffer());
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getAccountLimits"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getAccountLimits"));

    if (exceptionData)
    {
        try
        {
            exceptionData->throwException();
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getAccountLimitsRequestReady(
                writer.buffer());
            return;
        }
        catch(const std::exception & e)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception: " << e.what());
        }
        catch(...)
        {
            // TODO: more proper error handling
            QEC_ERROR("server", "Unknown exception");
        }
    }

    writer.writeFieldBegin(
        QStringLiteral("getAccountLimits"),
        ThriftFieldType::T_STRUCT,
        0);
    writeAccountLimits(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getAccountLimitsRequestReady(
        writer.buffer());
}

} // namespace qevercloud
