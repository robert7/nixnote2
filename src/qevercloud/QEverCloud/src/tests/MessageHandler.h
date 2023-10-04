/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_TESTS_MESSAGE_HANDLER_H
#define QEVERCLOUD_TESTS_MESSAGE_HANDLER_H

#include <QtGlobal>

namespace qevercloud {

void testMessageOutput(
    QtMsgType type, const QMessageLogContext & context, const QString & msg);

} // namespace qevercloud

#endif // QEVERCLOUD_TESTS_MESSAGE_HANDLER_H
