/**
 * Copyright (c) 2019-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_LOG_H
#define QEVERCLOUD_LOG_H

#include "Export.h"
#include "Helpers.h"

#include <QDateTime>
#include <QDebug>
#include <QObject>
#include <QTextStream>

#include <memory>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

enum class LogLevel
{
    Trace = 0,
    Debug,
    Info,
    Warn,
    Error
};

QEVERCLOUD_EXPORT QTextStream & operator<<(
    QTextStream & out, const LogLevel level);

QEVERCLOUD_EXPORT QDebug & operator<<(
    QDebug & out, const LogLevel level);

////////////////////////////////////////////////////////////////////////////////

class QEVERCLOUD_EXPORT ILogger
{
public:
    virtual bool shouldLog(
        const LogLevel level, const char * component) const = 0;

    virtual void log(
        const LogLevel level, const char * component, const char * fileName,
        const quint32 lineNumber, const qint64 timestamp,
        const QString & message) = 0;

    virtual void setLevel(const LogLevel level) = 0;

    virtual LogLevel level() const = 0;
};

using ILoggerPtr = std::shared_ptr<ILogger>;

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT ILoggerPtr logger();

QEVERCLOUD_EXPORT void setLogger(ILoggerPtr logger);

QEVERCLOUD_EXPORT ILoggerPtr nullLogger();

QEVERCLOUD_EXPORT ILoggerPtr newStdErrLogger(LogLevel level = LogLevel::Warn);

////////////////////////////////////////////////////////////////////////////////

#define __QEVERCLOUD_LOG_BASE(component, level, message)                       \
    {                                                                          \
        auto __qevercloudLogger = ::qevercloud::logger();                      \
        if (__qevercloudLogger->shouldLog(level, component))                   \
        {                                                                      \
            QString msg;                                                       \
            QDebug dbg(&msg);                                                  \
            dbg.nospace();                                                     \
            dbg.noquote();                                                     \
            dbg << message;                                                    \
            __qevercloudLogger->log(                                           \
                level,                                                         \
                component,                                                     \
                __FILE__,                                                      \
                __LINE__,                                                      \
                QDateTime::currentMSecsSinceEpoch(),                           \
                msg);                                                          \
        }                                                                      \
    }                                                                          \
// __QEVERCLOUD_LOG_BASE

#define QEC_TRACE(component, message)                                          \
    __QEVERCLOUD_LOG_BASE(component, LogLevel::Trace, message)                 \
// QEC_TRACE

#define QEC_DEBUG(component, message)                                          \
    __QEVERCLOUD_LOG_BASE(component, LogLevel::Debug, message)                 \
// QEC_DEBUG

#define QEC_INFO(component, message)                                           \
    __QEVERCLOUD_LOG_BASE(component, LogLevel::Info, message)                  \
// QEC_INFO

#define QEC_WARNING(component, message)                                        \
    __QEVERCLOUD_LOG_BASE(component, LogLevel::Warn, message)                  \
// QEC_WARNING

#define QEC_ERROR(component, message)                                          \
    __QEVERCLOUD_LOG_BASE(component, LogLevel::Error, message)                 \
// QEC_ERROR

} // namespace qevercloud

#endif // QEVERCLOUD_LOG_H
