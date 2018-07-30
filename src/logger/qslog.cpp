// Copyright (c) 2010, Razvan Petru
// All rights reserved.

// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:

// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice, this
//   list of conditions and the following disclaimer in the documentation and/or other
//   materials provided with the distribution.
// * The name of the contributors may not be used to endorse or promote products
//   derived from this software without specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.

#include "qslog.h"
#include "qslogdest.h"
#include <QMutex>
#include <QList>
#include <QDateTime>
#include <QtGlobal>
#include <QFile>
#include <QDir>


#include <cassert>
#include <cstdlib>
#include <stdexcept>

namespace QsLogging {
    typedef QList<Destination *> DestinationList;

    static const char TraceString[] = "TRACE";
    static const char DebugString[] = "DEBUG";
    static const char InfoString[] = "INFO";
    static const char WarnString[] = "WARN";
    static const char ErrorString[] = "ERROR";
    static const char FatalString[] = "FATAL";

    // not using Qt::ISODate because we need the milliseconds too
    static const QString fmtDateTime("yyyy-MM-dd hh:mm:ss.zzz");

    static const char *LevelToText(Level theLevel) {
        switch (theLevel) {
            case TraceLevel:
                return TraceString;
            case DebugLevel:
                return DebugString;
            case InfoLevel:
                return InfoString;
            case WarnLevel:
                return WarnString;
            case ErrorLevel:
                return ErrorString;
            case FatalLevel:
                return FatalString;
            default: {
                assert(!"bad log level");
                return InfoString;
            }
        }
    }

    class LoggerImpl {
    public:
        LoggerImpl() :
            level(InfoLevel) {

        }

        QMutex logMutex;
        Level level;
        DestinationList destList;
    };

    Logger::Logger() :
        d(new LoggerImpl) {
        this->filenameCounter = 0;
        this->displayTimestamp = true;
    }

    Logger::~Logger() {
        delete d;
    }

    void Logger::addDestination(Destination *destination) {
        assert(destination);
        d->destList.push_back(destination);
    }

    void Logger::setLoggingLevel(Level newLevel) {
        d->level = newLevel;
    }

    Level Logger::loggingLevel() const {
        return d->level;
    }

    // creates the complete log message and passes it to the logger
    void Logger::Helper::writeToLog() {
        const char *const levelName = LevelToText(level);
        Logger &logger = Logger::instance();
        QString completeMessage(QString(levelName).leftJustified(5).append(" "));
        if (logger.isDisplayTimestamp()) {
            completeMessage.append(QDateTime::currentDateTime().toString(fmtDateTime)).append(" ");
        }
        completeMessage.append(buffer);

        QMutexLocker lock(&logger.d->logMutex);
        logger.write(completeMessage);
    }

    Logger::Helper::~Helper() {
        try {
            writeToLog();
        }
        catch (std::exception &e) {
            // you shouldn't throw exceptions from a sink
            Q_UNUSED(e);
            assert(!"exception in logger helper destructor");
            //throw;
        }
    }

    // sends the message to all the destinations
    void Logger::write(const QString &message) {
        for (DestinationList::iterator it = d->destList.begin(),
                 endIt = d->destList.end(); it != endIt; ++it) {
            if (!(*it)) {
                assert(!"null log destination");
                continue;
            }
            (*it)->write(message);
        }
    }

#define QLOGINFO QsLogging::Logger::Helper(QsLogging::InfoLevel).stream

    /**
     * Write a string to log file - one file per call (to be used for logging of long strings e.g. note html)
     *
     * @param logid - some short string for easy identification
     *                we will construct filename with seq.number and use this as part of filename
     * @param message - obviously the content to write
     */
    void Logger::writeToFile(const QString &logid, const QString &message) {

        if (fileLoggingPath.isEmpty()) {
            QLOGINFO() << "fileLoggingPath not set writeToFile not disabled";
        }

        if (!fileLoggingPath.endsWith(QDir::separator())) {
            fileLoggingPath.append(QDir::separator());
        }

        // not multi-thread safe, but should not be needed
        filenameCounter++;
        // format with 4 leading zeros; 10 is radix
        QString filename = QString("%1").arg(filenameCounter, 4, 10, QChar('0'));
        if (!logid.isEmpty()) {
            filename.append("-").append(logid);
        }
        if (!filename.contains(".")) {
            filename.append(".log");
        }

        QFile file(fileLoggingPath + filename);

        if (file.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream stream(&file);
            stream << message;
        }
        //QLOGINFO() << "Writing attachment data to " << filename;
    }

    /**
     * Can be used to turn of timestamp display.
     * May be useful while debugging (e.g. in IDE).
     */
    void Logger::setDisplayTimestamp(bool displayTimestamp) {
        Logger::displayTimestamp = displayTimestamp;
    }

    bool Logger::isDisplayTimestamp() const {
        return displayTimestamp;
    }

    int Logger::getFilenameCounter() const {
        return filenameCounter;
    }

} // end namespace
