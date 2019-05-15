/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <exceptions.h>
#include <globals.h>
#include "http.h"
#include <QEventLoop>
#include <QtNetwork>
#include <QSharedPointer>
#include <QUrl>

/** @cond HIDDEN_SYMBOLS  */

namespace qevercloud {

ReplyFetcher::ReplyFetcher() :
    m_success(false),
    m_httpStatusCode(0)
{
    m_ticker = new QTimer(this);
    QObject::connect(m_ticker, QEC_SIGNAL(QTimer,timeout), this, QEC_SLOT(ReplyFetcher,checkForTimeout));
}

void ReplyFetcher::start(QNetworkAccessManager * nam, QUrl url)
{
    QNetworkRequest request;
    request.setUrl(url);
    start(nam, request);
}

void ReplyFetcher::start(QNetworkAccessManager * nam, QNetworkRequest request, QByteArray postData)
{
    m_httpStatusCode= 0;
    m_errorText.clear();
    m_receivedData.clear();
    m_success = true; // not in finished() signal handler, it might not be called according to the docs
                      // besides, I've added timeout feature

    m_lastNetworkTime = QDateTime::currentMSecsSinceEpoch();
    m_ticker->start(1000);

    if (postData.isNull()) {
        m_reply = QSharedPointer<QNetworkReply>(nam->get(request), &QObject::deleteLater);
    }
    else {
        m_reply = QSharedPointer<QNetworkReply>(nam->post(request, postData), &QObject::deleteLater);
    }

    QObject::connect(m_reply.data(), QEC_SIGNAL(QNetworkReply,finished), this, QEC_SLOT(ReplyFetcher,onFinished));
    QObject::connect(m_reply.data(), SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
    QObject::connect(m_reply.data(), QEC_SIGNAL(QNetworkReply,sslErrors,QList<QSslError>), this, QEC_SLOT(ReplyFetcher,onSslErrors,QList<QSslError>));
    QObject::connect(m_reply.data(), QEC_SIGNAL(QNetworkReply,downloadProgress,qint64,qint64), this, QEC_SLOT(ReplyFetcher,onDownloadProgress,qint64,qint64));
}

void ReplyFetcher::onDownloadProgress(qint64, qint64)
{
    m_lastNetworkTime = QDateTime::currentMSecsSinceEpoch();
}

void ReplyFetcher::checkForTimeout()
{
    const int connectionTimeout = 30*1000;
    if ((m_lastNetworkTime - QDateTime::currentMSecsSinceEpoch()) > connectionTimeout) {
        setError(QStringLiteral("Connection timeout."));
    }
}

void ReplyFetcher::onFinished()
{
    m_ticker->stop();

    if (!m_success) {
        return;
    }

    m_receivedData = m_reply->readAll();
    m_httpStatusCode = m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    QObject::disconnect(m_reply.data());
    emit replyFetched(this);
}

void ReplyFetcher::onError(QNetworkReply::NetworkError error)
{
    Q_UNUSED(error)
    setError(m_reply->errorString());
}

void ReplyFetcher::onSslErrors(QList<QSslError> errors)
{
    QString errorText = QStringLiteral("SSL Errors:\n");

    for(int i = 0, numErrors = errors.size(); i < numErrors; ++i) {
        const QSslError & error = errors[i];
        errorText += error.errorString().append('\n');
    }

    setError(errorText);
}

void ReplyFetcher::setError(QString errorText)
{
    m_success = false;
    m_ticker->stop();
    m_errorText = errorText;
    QObject::disconnect(m_reply.data());
    emit replyFetched(this);
}

QByteArray simpleDownload(QNetworkAccessManager* nam, QNetworkRequest request,
                          QByteArray postData, int * httpStatusCode)
{
    ReplyFetcher fetcher;
    QEventLoop loop;
    QObject::connect(&fetcher, SIGNAL(replyFetched(QObject*)), &loop, SLOT(quit()));

    fetcher.start(nam, request, postData);
    loop.exec(QEventLoop::ExcludeUserInputEvents);

    if (httpStatusCode) {
        *httpStatusCode = fetcher.httpStatusCode();
    }

    if (fetcher.isError()) {
        throw EverCloudException(fetcher.errorText());
    }

    return fetcher.receivedData();
}

QNetworkRequest createEvernoteRequest(QString url)
{
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QStringLiteral("application/x-thrift"));

#if QT_VERSION < 0x050000
    request.setRawHeader("User-Agent", QString("QEverCloud %1.%2").arg(libraryVersion() / 10000).arg(libraryVersion() % 10000).toLatin1());
#else
    request.setHeader(QNetworkRequest::UserAgentHeader, QStringLiteral("QEverCloud %1.%2").arg(libraryVersion() / 10000).arg(libraryVersion() % 10000));
#endif

    request.setRawHeader("Accept", "application/x-thrift");
    return request;
}

QByteArray askEvernote(QString url, QByteArray postData)
{
    int httpStatusCode = 0;
    QByteArray reply = simpleDownload(evernoteNetworkAccessManager(), createEvernoteRequest(url), postData, &httpStatusCode);

    if (httpStatusCode != 200) {
        throw EverCloudException(QStringLiteral("HTTP Status Code = %1").arg(httpStatusCode));
    }

    return reply;
}

} // namespace qevercloud

/** @endcond */
