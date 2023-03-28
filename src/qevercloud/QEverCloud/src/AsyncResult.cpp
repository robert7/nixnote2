/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "AsyncResult_p.h"
#include "Http.h"

#include <AsyncResult.h>
#include <EventLoopFinisher.h>

#include <QEventLoop>
#include <QSignalMapper>

#include <typeinfo>

namespace qevercloud {

QVariant AsyncResult::asIs(QByteArray replyData)
{
    return replyData;
}

AsyncResult::AsyncResult(
        QString url, QByteArray postData, IRequestContextPtr ctx,
        AsyncResult::ReadFunctionType readFunction, bool autoDelete,
        QObject * parent) :
    QObject(parent),
    d_ptr(new AsyncResultPrivate(
        url,
        std::move(postData),
        std::move(ctx),
        std::move(readFunction),
        autoDelete,
        this))
{
    if (!url.isEmpty()) {
        QMetaObject::invokeMethod(d_ptr, "start", Qt::QueuedConnection);
    }
}

AsyncResult::AsyncResult(
        QNetworkRequest request, QByteArray postData, IRequestContextPtr ctx,
        qevercloud::AsyncResult::ReadFunctionType readFunction,
        bool autoDelete, QObject * parent) :
    QObject(parent),
    d_ptr(new AsyncResultPrivate(
        std::move(request),
        std::move(postData),
        std::move(ctx),
        std::move(readFunction),
        autoDelete,
        this))
{
    QMetaObject::invokeMethod(d_ptr, "start", Qt::QueuedConnection);
}

AsyncResult::AsyncResult(
        QVariant result, EverCloudExceptionDataPtr error,
        IRequestContextPtr ctx, bool autoDelete, QObject * parent) :
    QObject(parent),
    d_ptr(new AsyncResultPrivate(
        std::move(result),
        std::move(error),
        std::move(ctx),
        autoDelete,
        this))
{}

AsyncResult::~AsyncResult()
{
    delete d_ptr;
}

bool AsyncResult::waitForFinished(int timeout)
{
    QEventLoop loop;
    QObject::connect(
        this,
        &AsyncResult::finished,
        &loop,
        [&loop](const QVariant & result,
                const EverCloudExceptionDataPtr & error,
                const IRequestContextPtr & ctx)
        {
            Q_UNUSED(result)
            Q_UNUSED(error)
            Q_UNUSED(ctx)
            loop.quit();
        });

    if (timeout >= 0)
    {
        QTimer timer;
        EventLoopFinisher finisher(&loop, 1);
        QObject::connect(
            &timer,
            &QTimer::timeout,
            &finisher,
            &EventLoopFinisher::stopEventLoop);

        timer.setSingleShot(true);
        timer.setInterval(timeout);
        timer.start();
    }

    bool res = (loop.exec(QEventLoop::ExcludeUserInputEvents) == 0);
    return res;
}

} // namespace qevercloud
