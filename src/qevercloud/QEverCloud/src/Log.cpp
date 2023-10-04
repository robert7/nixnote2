/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <Log.h>

#include <QGlobalStatic>

#include <atomic>
#include <cstdio>
#include <ctime>
#include <memory>

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

Q_GLOBAL_STATIC(ILoggerPtr, globalLogger)

////////////////////////////////////////////////////////////////////////////////

template <typename T>
void printLogLevel(T & out, const LogLevel level)
{
    switch(level)
    {
    case LogLevel::Trace:
        out << "Trace";
        break;
    case LogLevel::Debug:
        out << "Debug";
        break;
    case LogLevel::Info:
        out << "Info";
        break;
    case LogLevel::Warn:
        out << "Warn";
        break;
    case LogLevel::Error:
        out << "Error";
        break;
    default:
        out << "Unknown (" << static_cast<qint64>(level) << ")";
        break;
    }
}

////////////////////////////////////////////////////////////////////////////////

class NullLogger final: public ILogger
{
public:
    virtual bool shouldLog(
        const LogLevel level, const char * component) const override
    {
        Q_UNUSED(level)
        Q_UNUSED(component)
        return false;
    }

    virtual void log(
        const LogLevel level, const char * component, const char * fileName,
        const quint32 lineNumber, const qint64 timestamp,
        const QString & message) override
    {
        Q_UNUSED(level)
        Q_UNUSED(component)
        Q_UNUSED(fileName)
        Q_UNUSED(lineNumber)
        Q_UNUSED(timestamp)
        Q_UNUSED(message)
    }

    virtual void setLevel(const LogLevel level) override
    {
        m_level.store(static_cast<int>(level));
    }

    virtual LogLevel level() const override
    {
        return static_cast<LogLevel>(m_level.load());
    }

private:
    std::atomic<int> m_level;
};

////////////////////////////////////////////////////////////////////////////////

class StdErrLogger final: public ILogger
{
public:
    StdErrLogger(LogLevel level) :
        m_cerr(stderr),
        m_level(static_cast<int>(level))
    {}

    virtual bool shouldLog(
        const LogLevel level, const char * component) const override
    {
        Q_UNUSED(component)
        return (static_cast<int>(level) >= m_level);
    }

    virtual void log(
        const LogLevel level, const char * component, const char * fileName,
        const quint32 lineNumber, const qint64 timestamp,
        const QString & message) override
    {
        if (!shouldLog(level, component)) {
            return;
        }

        printTimestamp(timestamp);

        m_cerr << "\t" << static_cast<LogLevel>(m_level.load())
            << "\t[" << component << "] "
            << fileName << ":" << lineNumber << " "
            << message << "\n";
        m_cerr.flush();
    }

    virtual void setLevel(const LogLevel level) override
    {
        m_level.store(static_cast<int>(level));
    }

    virtual LogLevel level() const override
    {
        return static_cast<LogLevel>(m_level.load());
    }

private:
    void printTimestamp(const qint64 timestamp)
    {
        std::time_t t(timestamp / 1000);
        std::tm localTm;
        Q_UNUSED(localTm)
        std::tm * tm = Q_NULLPTR;

#ifdef _MSC_VER
        // MSVC's localtime is thread-safe since MSVC 2005
        tm = std::localtime(&t);
#else // ifdef _MSC_VER
#ifdef __MINGW32__
        // MinGW lacks localtime_r but uses MS's localtime instead which is told to
        // be thread-safe but it's still not re-entrant.
        // So, can at best hope it won't cause problems too often
        tm = localtime(&t);
#else // POSIX
        tm = &localTm;
        Q_UNUSED(localtime_r(&t, tm))
#endif
#endif // ifdef _MSC_VER

        const size_t maxBufSize = 100;
        char buffer[maxBufSize];
        const char * format = "%Y-%m-%d %H:%M:%S";
        size_t size = strftime(buffer, maxBufSize, format, tm);

        m_cerr << QString::fromLocal8Bit(buffer, static_cast<int>(size));

        qint64 msecPart = timestamp - t * 1000;
        m_cerr << ".";
        m_cerr << QString::fromUtf8("%1").arg(msecPart, 3, 10, QChar::fromLatin1('0'));

#if !defined(_MSC_VER) && !defined(__MINGW32__)
        const char * timezone = tm->tm_zone;
        if (timezone) {
            m_cerr << " ";
            m_cerr << QString::fromLocal8Bit(timezone);
        }
#endif
    }

private:
    QTextStream m_cerr;
    std::atomic<int> m_level;
};

} // namespace

////////////////////////////////////////////////////////////////////////////////

ILoggerPtr logger()
{
    if (globalLogger.exists() &&
        !globalLogger.isDestroyed() &&
        (globalLogger->get() != nullptr))
    {
        return *globalLogger;
    }

    return nullLogger();
}

void setLogger(ILoggerPtr logger)
{
    if (!globalLogger.isDestroyed()) {
        *globalLogger = logger;
    }
}

ILoggerPtr nullLogger()
{
    return std::make_shared<NullLogger>();
}

ILoggerPtr newStdErrLogger(LogLevel level)
{
    return std::make_shared<StdErrLogger>(level);
}

QTextStream & operator<<(QTextStream & out, const LogLevel level)
{
    printLogLevel<QTextStream>(out, level);
    return out;
}

QDebug & operator<<(QDebug & out, const LogLevel level)
{
    printLogLevel<QDebug>(out, level);
    return out;
}

} // namespace qevercloud
