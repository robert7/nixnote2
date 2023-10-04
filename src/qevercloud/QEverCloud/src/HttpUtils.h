/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_HTTP_UTILS_H
#define QEVERCLOUD_HTTP_UTILS_H

#include "HttpRequestData.h"

QT_BEGIN_NAMESPACE

class QTcpSocket;

QT_END_NAMESPACE

namespace qevercloud {

[[nodiscard]] HttpRequestData readRequestDataFromSocket(QTcpSocket & socket);

[[nodiscard]] QByteArray readRequestBodyFromSocket(QTcpSocket & socket);

[[nodiscard]] bool writeBufferToSocket(
    const QByteArray & data, QTcpSocket & socket);

} // namespace qevercloud

#endif // QEVERCLOUD_HTTP_UTILS_H
