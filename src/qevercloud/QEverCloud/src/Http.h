/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_HTTP_H
#define QEVERCLOUD_HTTP_H

#include <Helpers.h>

#include <QByteArray>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkCookie>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPointer>
#include <QSslError>
#include <QString>
#include <QtEndian>
#include <QTimer>
#include <QTypeInfo>

#include <memory>

/** @cond HIDDEN_SYMBOLS  */

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief The ReplyFetcher class simplifies handling of QNetworkReply
 */
class ReplyFetcher: public QObject
{
    Q_OBJECT
public:
    ReplyFetcher(QObject * parent = nullptr);

    void start(QNetworkAccessManager * nam, QUrl url, qint64 timeoutMsec);

    // if !postData.isNull() then POST will be issued instead of GET
    void start(
        QNetworkAccessManager * nam, QNetworkRequest request,
        qint64 timeoutMsec, QByteArray postData = QByteArray());

    bool isError() const
    {
        return m_errorType != QNetworkReply::NoError;
    }

    QNetworkReply::NetworkError errorType() const
    {
        return m_errorType;
    }

    QString errorText() const
    {
        return m_errorText;
    }

    QByteArray receivedData() const
    {
        return m_receivedData;
    }

    int httpStatusCode() const
    {
        return m_httpStatusCode;
    }

    QNetworkAccessManager * networkAccessManager()
    {
        if (!m_pNam.isNull()) {
            return m_pNam.data();
        }
        else {
            return nullptr;
        }
    }

Q_SIGNALS:
    void replyFetched(ReplyFetcher * pSelf); // sends itself

private Q_SLOTS:
    void onFinished();
    void onError(QNetworkReply::NetworkError);
    void onSslErrors(QList<QSslError> list);
    void onDownloadProgress(qint64 downloaded, qint64 total);
    void checkForTimeout();

private:
    void setError(QNetworkReply::NetworkError errorType, QString errorText);

private:
    struct QNetworkReplyDeleter
    {
        void operator()(QNetworkReply * pReply)
        {
            pReply->deleteLater();
        }
    };

    using QNetworkReplyPtr = std::unique_ptr<QNetworkReply, QNetworkReplyDeleter>;

private:
    QPointer<QNetworkAccessManager>     m_pNam;

    QNetworkReplyPtr    m_pReply;

    QNetworkReply::NetworkError m_errorType = QNetworkReply::NoError;
    QString     m_errorText;
    QByteArray  m_receivedData;
    int         m_httpStatusCode = 0;

    QTimer *    m_pTicker = nullptr;
    qint64      m_lastNetworkTime = 0;
    qint64      m_timeoutMsec = 0;
};

////////////////////////////////////////////////////////////////////////////////

QNetworkRequest createEvernoteRequest(
    QString url, QList<QNetworkCookie> cookies);

QByteArray askEvernote(
    QString url, QByteArray postData, const qint64 timeoutMsec,
    QList<QNetworkCookie> cookies = {});

QByteArray simpleDownload(
    QNetworkRequest request, const qint64 timeoutMsec,
    QByteArray postData = {}, int * pHttpStatusCode = nullptr);

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief The ReplyFetcherLauncher class simplifies ReplyFetcher starting
 */
class ReplyFetcherLauncher: public QObject
{
    Q_OBJECT
public:
    explicit ReplyFetcherLauncher(
        ReplyFetcher * pFetcher, QNetworkAccessManager * pNam,
        const QNetworkRequest & request, const qint64 timeoutMsec,
        const QByteArray & postData);

public Q_SLOTS:
    void start();

private:
    ReplyFetcher *          m_pFetcher = nullptr;
    QNetworkAccessManager * m_pNam = nullptr;
    QNetworkRequest         m_request;
    qint64                  m_timeoutMsec = 0;
    QByteArray              m_postData;
};

} // namespace qevercloud

/** @endcond */

#endif // QEVERCLOUD_HTTP_H
