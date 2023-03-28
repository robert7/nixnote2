/**
 * Copyright (c) 2019-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_ASYNC_RESULT_PRIVATE_H
#define QEVERCLOUD_ASYNC_RESULT_PRIVATE_H

#include <AsyncResult.h>

namespace qevercloud {

QT_FORWARD_DECLARE_CLASS(ReplyFetcher)

class AsyncResultPrivate: public QObject
{
    Q_OBJECT
public:
    explicit AsyncResultPrivate(
        QString url, QByteArray postData, IRequestContextPtr ctx,
        AsyncResult::ReadFunctionType readFunction, bool autoDelete,
        AsyncResult * q);

    explicit AsyncResultPrivate(
        QNetworkRequest request, QByteArray postData, IRequestContextPtr ctx,
        AsyncResult::ReadFunctionType readFunction, bool autoDelete,
        AsyncResult * q);

    explicit AsyncResultPrivate(
        QVariant result, EverCloudExceptionDataPtr error,
        IRequestContextPtr ctx, bool autoDelete, AsyncResult * q);

    virtual ~AsyncResultPrivate() override;

Q_SIGNALS:
    void finished(
        QVariant result, EverCloudExceptionDataPtr error,
        IRequestContextPtr ctx);

public Q_SLOTS:
    void start();

    void onReplyFetched(ReplyFetcher * pReplyFetcher);

    void setValue(QVariant result, EverCloudExceptionDataPtr error);

public:
    QNetworkRequest                 m_request;
    QByteArray                      m_postData;
    IRequestContextPtr              m_ctx;
    AsyncResult::ReadFunctionType   m_readFunction;
    bool                            m_autoDelete;

private:
    AsyncResult * const q_ptr;
    Q_DECLARE_PUBLIC(AsyncResult)
};

} // namespace qevercloud

#endif // QEVERCLOUD_ASYNC_RESULT_PRIVATE_H
