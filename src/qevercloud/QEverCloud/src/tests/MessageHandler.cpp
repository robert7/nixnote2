/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "MessageHandler.h"

#include <QByteArray>
#include <QString>

#include <cstdio>
#include <cstdlib>

namespace qevercloud {

void testMessageOutput(
    const QtMsgType type, const QMessageLogContext & context,
    const QString & msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";
    switch (type) {
    case QtDebugMsg:
        fprintf(
            stderr,
            "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line,
            function);
        break;
    case QtInfoMsg:
        fprintf(
            stderr,
            "Info: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line,
            function);
        break;
    case QtWarningMsg:
        fprintf(
            stderr,
            "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file,
            context.line, function);
        break;
    case QtCriticalMsg:
        fprintf(
            stderr,
            "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file,
            context.line, function);
        break;
    case QtFatalMsg:
        fprintf(
            stderr,
            "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line,
            function);
        break;
    }
}

} // namespace qevercloud
