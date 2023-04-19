/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_HTTP_REQUEST_DATA_H
#define QEVERCLOUD_HTTP_REQUEST_DATA_H

#include <QByteArray>

/** @cond HIDDEN_SYMBOLS  */

namespace qevercloud {

// (Incomplete) data from HTTP request parsed from data read from QTcpSocket
struct HttpRequestData
{
    enum class Method
    {
        GET,
        POST
    };

    Method method = Method::POST;
    QByteArray uri;
    QByteArray body;
};

} // namespace qevercloud

/** @endcond */

#endif // QEVERCLOUD_HTTP_REQUEST_DATA_H
