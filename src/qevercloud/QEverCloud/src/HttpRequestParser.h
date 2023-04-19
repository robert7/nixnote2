/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_HTTP_REQUEST_PARSER_H
#define QEVERCLOUD_HTTP_REQUEST_PARSER_H

#include "HttpRequestData.h"

#include <QObject>

QT_BEGIN_NAMESPACE

class QTcpSocket;

QT_END_NAMESPACE

namespace qevercloud {

// Simplistic parser of HTTP request data from QTcpSocket
class HttpRequestParser: public QObject
{
    Q_OBJECT
public:
    explicit HttpRequestParser(QTcpSocket & socket, QObject * parent = nullptr);

    [[nodiscard]] bool status() const noexcept;

    [[nodiscard]] const QByteArray & data() const noexcept;

    [[nodiscard]] HttpRequestData requestData() const;

Q_SIGNALS:
    void finished();
    void failed();

private Q_SLOTS:
    void onSocketReadyRead();

private:
    void tryParseData();

private:
    bool            m_status = false;
    HttpRequestData m_requestData;
    QByteArray      m_data;
};

} // namespace qevercloud

#endif // QEVERCLOUD_HTTP_REQUEST_PARSER_H
