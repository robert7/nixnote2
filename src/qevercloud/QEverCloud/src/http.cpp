/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <exceptions.h>
#include <globals.h>
#include <qt4helpers.h>
#include "http.h"
#include <QEventLoop>
#include <QtNetwork>
#include <QSharedPointer>
#include <QUrl>

// TEMP!! nixnote addition to allow logger calls
#include "src/logger/qslog.h"
////////////////////////////////////////////////

/** @cond HIDDEN_SYMBOLS  */

namespace qevercloud {

ReplyFetcher::ReplyFetcher(QObject * parent) :
    QObject(parent),
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
    const int timeout = connectionTimeout();
    if (timeout < 0) {
        return;
    }

    if ((QDateTime::currentMSecsSinceEpoch() - m_lastNetworkTime) > timeout) {
        setError(QStringLiteral("Request timeout."));
    }
}

void ReplyFetcher::onFinished()
{
    QLOG_DEBUG() << "QEverCloud.http.ReplyFetcher.onFinished m_success=" << m_success;
    m_ticker->stop();

    if (!m_success) {
        return;
    }

    m_receivedData = m_reply->readAll();
    m_httpStatusCode = m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QLOG_DEBUG() << "QEverCloud.http.ReplyFetcher.onFinished m_httpStatusCode=" << m_httpStatusCode
                 << " datalen=" << m_receivedData.size();

    QObject::disconnect(m_reply.data());
    emit replyFetched(this);
}

void ReplyFetcher::onError(QNetworkReply::NetworkError error)
{
    auto errorText = m_reply->errorString();
    QLOG_DEBUG() << "QEverCloud.http.ReplyFetcher.onError: code=" << error
                << " (" << ((int) error) << ") "
                << ", text=" << errorText
                << ", m_success=" << m_success;

    // // applied patch from https://github.com/d1vanov/QEverCloud/commit/012425c98e52406fc5f3aa69750eba84b931a5a3
    // // Workaround for Evernote server problems
    // if ((error == QNetworkReply::UnknownContentError) &&
    //     errorText.endsWith(QStringLiteral("server replied: OK"))) {
    //     // ignore this, it's actually ok
    //     QLOG_WARN() << "QEverCloud.http.ReplyFetcher.onError: error is ignored "
    //                 << "(it's actually ok)";
    //     return;
    // }
    setError(errorText);
}

void ReplyFetcher::onSslErrors(QList<QSslError> errors)
{
    QString errorText = QStringLiteral("SSL Errors:\n");

    for(int i = 0, numErrors = errors.size(); i < numErrors; ++i) {
        const QSslError & error = errors[i];
        errorText += error.errorString().append(QStringLiteral("\n"));
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
    ReplyFetcher * fetcher = new ReplyFetcher;
    QEventLoop loop;
    QObject::connect(fetcher, SIGNAL(replyFetched(QObject * )), &loop, SLOT(quit()));

    ReplyFetcherLauncher *fetcherLauncher = new ReplyFetcherLauncher(fetcher, nam, request, postData);
    QTimer::singleShot(0, fetcherLauncher, SLOT(start()));

    qint64 time1 = QDateTime::currentMSecsSinceEpoch();
    QString url = request.url().toString();
    QLOG_DEBUG() << "QEverCloud.http.simpleDownload: sending http request url=" << url;
    QLOG_TRACE() << "postData=" << postData;
    loop.exec(QEventLoop::ExcludeUserInputEvents);

    fetcherLauncher->deleteLater();

    qint64 time2 = QDateTime::currentMSecsSinceEpoch();
    int httpCodeLocal = fetcher->httpStatusCode();
    bool isError = fetcher->isError();
    *httpStatusCode = httpCodeLocal;

    QByteArray receivedData = fetcher->receivedData();


    QLOG_DEBUG() << "QEverCloud.http.simpleDownload: got reply for url=" << url << ", http code " << httpCodeLocal
                 << ", isError=" << isError
                 << ", " << (time2 - time1) << " ms";
    QLOG_DEBUG() << "QEverCloud.http.simpleDownload: got reply for url=" << url;
    QLOG_TRACE() << "data=" << receivedData;

    if (isError) {
        QString errorText = fetcher->errorText();
        QLOG_WARN() << "QEverCloud.http.simpleDownload: reply for url=" << url
                    << " is error: " << errorText << " => EverCloudException " << errorText;
        fetcher->deleteLater();
        throw EverCloudException(errorText);
    }

    fetcher->deleteLater();
    return receivedData;
}

QNetworkRequest createEvernoteRequest(QString url)
{
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QStringLiteral("application/x-thrift"));

#if QT_VERSION < 0x050000
    request.setRawHeader("User-Agent", QString::fromUtf8("QEverCloud %1.%2").arg(libraryVersion() / 10000).arg(libraryVersion() % 10000).toLatin1());
#else
    request.setHeader(QNetworkRequest::UserAgentHeader, QStringLiteral("QEverCloud %1.%2").arg(libraryVersion() / 10000).arg(libraryVersion() % 10000));
#endif

    request.setRawHeader("Accept", "application/x-thrift");
    return request;
}

QByteArray askEvernote(QString url, QByteArray postData)
{
    QLOG_DEBUG() << "QEverCloud.http.askEvernote: sending http request url=" << url;
    int httpStatusCode = 0;
    QByteArray reply = simpleDownload(evernoteNetworkAccessManager(), createEvernoteRequest(url), postData, &httpStatusCode);

    if (httpStatusCode != 200) {
        QLOG_WARN() << "QEverCloud.askEvernote: http code=" << httpStatusCode << " => EverCloudException";

        throw EverCloudException(QStringLiteral("HTTP Status Code = %1").arg(httpStatusCode));
    }

    return reply;
}

ReplyFetcherLauncher::ReplyFetcherLauncher(ReplyFetcher * fetcher, QNetworkAccessManager * nam,
                                           const QNetworkRequest & request, const QByteArray & postData) :
    QObject(nam),
    m_fetcher(fetcher),
    m_nam(nam),
    m_request(request),
    m_postData(postData)
{}

void ReplyFetcherLauncher::start()
{
    m_fetcher->start(m_nam, m_request, m_postData);
}

} // namespace qevercloud

/** @endcond */
