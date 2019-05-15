/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <AsyncResult.h>
#include <EventLoopFinisher.h>
#include "http.h"
#include <QEventLoop>
#include <QSignalMapper>
#include <typeinfo>

namespace qevercloud {

class AsyncResultPrivate
{
public:
    explicit AsyncResultPrivate(QString url, QByteArray postData, AsyncResult::ReadFunctionType readFunction,
                                bool autoDelete, AsyncResult * q);

    explicit AsyncResultPrivate(QNetworkRequest request, QByteArray postData, AsyncResult::ReadFunctionType readFunction,
                                bool autoDelete, AsyncResult * q);

    virtual ~AsyncResultPrivate();

    QNetworkRequest                 m_request;
    QByteArray                      m_postData;
    AsyncResult::ReadFunctionType   m_readFunction;
    bool                            m_autoDelete;

private:
    AsyncResult * const q_ptr;
    Q_DECLARE_PUBLIC(AsyncResult)
};

AsyncResultPrivate::AsyncResultPrivate(QString url, QByteArray postData, AsyncResult::ReadFunctionType readFunction,
                                       bool autoDelete, AsyncResult * q) :
    m_request(createEvernoteRequest(url)),
    m_postData(postData),
    m_readFunction(readFunction),
    m_autoDelete(autoDelete),
    q_ptr(q)
{}

AsyncResultPrivate::AsyncResultPrivate(QNetworkRequest request, QByteArray postData, AsyncResult::ReadFunctionType readFunction,
                                       bool autoDelete, AsyncResult * q) :
    m_request(request),
    m_postData(postData),
    m_readFunction(readFunction),
    m_autoDelete(autoDelete),
    q_ptr(q)
{}


AsyncResultPrivate::~AsyncResultPrivate()
{}

QVariant AsyncResult::asIs(QByteArray replyData)
{
    return replyData;
}

AsyncResult::AsyncResult(QString url, QByteArray postData, AsyncResult::ReadFunctionType readFunction,
                         bool autoDelete, QObject * parent) :
    QObject(parent),
    d_ptr(new AsyncResultPrivate(url, postData, readFunction, autoDelete, this))
{
    QMetaObject::invokeMethod(this, "start", Qt::QueuedConnection);
}

AsyncResult::AsyncResult(QNetworkRequest request, QByteArray postData, qevercloud::AsyncResult::ReadFunctionType readFunction,
                         bool autoDelete, QObject * parent) :
    QObject(parent),
    d_ptr(new AsyncResultPrivate(request, postData, readFunction, autoDelete, this))
{
    QMetaObject::invokeMethod(this, "start", Qt::QueuedConnection);
}

AsyncResult::~AsyncResult()
{
    delete d_ptr;
}

bool AsyncResult::waitForFinished(int timeout)
{
    QEventLoop loop;
    QObject::connect(this, SIGNAL(finished(QVariant,QSharedPointer<EverCloudExceptionData>)), &loop, SLOT(quit()));

    if(timeout >= 0) {
        QTimer timer;
        EventLoopFinisher finisher(&loop, 1);
        connect(&timer, SIGNAL(timeout()), &finisher, SLOT(stopEventLoop()));
        timer.setSingleShot(true);
        timer.setInterval(timeout);
        timer.start();
    }

    bool res = (loop.exec(QEventLoop::ExcludeUserInputEvents) == 0);
    return res;
}

void AsyncResult::start()
{
    Q_D(AsyncResult);
    ReplyFetcher * replyFetcher = new ReplyFetcher;
    QObject::connect(replyFetcher, QEC_SIGNAL(ReplyFetcher,replyFetched,QObject*),
                     this, QEC_SLOT(AsyncResult,onReplyFetched,QObject*));
    replyFetcher->start(evernoteNetworkAccessManager(), d->m_request, d->m_postData);
}

void AsyncResult::onReplyFetched(QObject * rp)
{
    Q_D(AsyncResult);

    ReplyFetcher * reply = qobject_cast<ReplyFetcher*>(rp);
    QSharedPointer<EverCloudExceptionData> error;
    QVariant result;

    try
    {
        if (reply->isError()) {
            error = QSharedPointer<EverCloudExceptionData>(new EverCloudExceptionData(reply->errorText()));
        }
        else if(reply->httpStatusCode() != 200) {
            error = QSharedPointer<EverCloudExceptionData>(new EverCloudExceptionData(QStringLiteral("HTTP Status Code = %1").arg(reply->httpStatusCode())));
        }
        else {
            result = d->m_readFunction(reply->receivedData());
        }
    }
    catch(const EverCloudException & e) {
        error = e.exceptionData();
    }
    catch(const std::exception & e) {
        error = QSharedPointer<EverCloudExceptionData>(new EverCloudExceptionData(QStringLiteral("Exception of type \"%1\" with the message: %2")
                                                                                  .arg(QString::fromUtf8(typeid(e).name()), QString::fromUtf8(e.what()))));
    }
    catch(...) {
        error = QSharedPointer<EverCloudExceptionData>(new EverCloudExceptionData(QStringLiteral("Unknown exception")));
    }

    emit finished(result, error);
    reply->deleteLater();

    if (d->m_autoDelete) {
        this->deleteLater();
    }
}

} // namespace qevercloud
