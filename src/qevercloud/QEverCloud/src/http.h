/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_HTTP_H
#define QEVERCLOUD_HTTP_H

#include <qt4helpers.h>
#include <QString>
#include <QByteArray>
#include <QtEndian>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>
#include <QSharedPointer>
#include <QTypeInfo>
#include <QSslError>

/** @cond HIDDEN_SYMBOLS  */

namespace qevercloud {

QNetworkAccessManager * evernoteNetworkAccessManager();

// the class greatly simplifies QNetworkReply handling
class ReplyFetcher: public QObject
{
    Q_OBJECT
public:
    ReplyFetcher(QObject * parent = Q_NULLPTR);

    void start(QNetworkAccessManager * nam, QUrl url);
    // if !postData.isNull() then POST will be issued instead of GET
    void start(QNetworkAccessManager * nam, QNetworkRequest request, QByteArray postData = QByteArray());
    bool isError() { return !m_success; }
    QString errorText() { return m_errorText; }
    QByteArray receivedData() { return m_receivedData; }
    int httpStatusCode() { return m_httpStatusCode; }

Q_SIGNALS:
    void replyFetched(QObject*); // sends itself

private Q_SLOTS:
    void onFinished();
    void onError(QNetworkReply::NetworkError);
    void onSslErrors(QList<QSslError> l);
    void onDownloadProgress(qint64, qint64);
    void checkForTimeout();

private:
    void setError(QString errorText);

private:
    QSharedPointer<QNetworkReply>   m_reply;
    bool                            m_success;
    QString                         m_errorText;
    QByteArray                      m_receivedData;
    int                             m_httpStatusCode;
    QTimer*                         m_ticker;
    qint64                          m_lastNetworkTime;
};

QNetworkRequest createEvernoteRequest(QString url);

QByteArray askEvernote(QString url, QByteArray postData);

QByteArray simpleDownload(QNetworkAccessManager * nam, QNetworkRequest request,
                          QByteArray postData = QByteArray(), int * httpStatusCode = Q_NULLPTR);

class ReplyFetcherLauncher: public QObject
{
    Q_OBJECT
public:
    explicit ReplyFetcherLauncher(ReplyFetcher * fetcher, QNetworkAccessManager * nam,
                                  const QNetworkRequest & request, const QByteArray & postData);

public Q_SLOTS:
    void start();

private:
    ReplyFetcher *          m_fetcher;
    QNetworkAccessManager * m_nam;
    QNetworkRequest         m_request;
    QByteArray              m_postData;
};

} // namespace qevercloud

/** @endcond */

#endif // QEVERCLOUD_HTTP_H
