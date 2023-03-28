/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "HttpUtils.h"

#include "HttpRequestParser.h"

#include <QEventLoop>
#include <QTcpSocket>

namespace qevercloud {

HttpRequestData readRequestDataFromSocket(QTcpSocket & socket)
{
    if (!socket.waitForConnected()) {
        return {};
    }

    QEventLoop loop;
    HttpRequestParser extractor(socket);

    QObject::connect(
        &extractor,
        &HttpRequestParser::finished,
        &loop,
        &QEventLoop::quit);

    QObject::connect(
        &extractor,
        &HttpRequestParser::failed,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    if (!extractor.status()) {
        return {};
    }

    return extractor.requestData();
}

QByteArray readRequestBodyFromSocket(QTcpSocket & socket)
{
    return readRequestDataFromSocket(socket).body;
}

bool writeBufferToSocket(const QByteArray & data, QTcpSocket & socket)
{
    int remaining = data.size();
    const char * pData = data.constData();
    while(socket.isOpen() && remaining>0)
    {
        // If the output buffer has become large, then wait until it has been sent.
        if (socket.bytesToWrite() > 16384)
        {
            socket.waitForBytesWritten(-1);
        }

        qint64 written = socket.write(pData, remaining);
        if (written < 0) {
            return false;
        }

        pData += written;
        remaining -= written;
    }
    return true;
}

} // namespace qevercloud
