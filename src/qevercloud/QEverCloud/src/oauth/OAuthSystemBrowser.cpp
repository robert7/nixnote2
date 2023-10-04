/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "OAuthSystemBrowser.h"

#include "NetworkCookieJar.h"

#include "../HttpRequestParser.h"
#include "../HttpUtils.h"

#include <Log.h>

#include <QLabel>
#include <QTcpServer>
#include <QVBoxLayout>

namespace qevercloud {

EvernoteOAuthWebViewPrivate::EvernoteOAuthWebViewPrivate(QWidget * parent) :
    QWidget(parent)
{}

void EvernoteOAuthWebViewPrivate::onAuthenticationFinished(bool success)
{
    Q_EMIT authenticationFinished(success);
}

void EvernoteOAuthWebViewPrivate::openOAuthPage(QUrl pageUrl)
{
    auto * verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

    const auto titleText =
        QObject::tr(
            "Authentication",
            "qevercloud::EvernoteOAuthWebViewPrivate");

    auto * titleLabel = new QLabel(this);
    titleLabel->setText(
        QString::fromUtf8(
            "<html><head/><body><p align=\"center\">"
            "<span style=\"font-size:12pt; font-weight:600;\">%1"
            "</span></p></body></html>").arg(titleText));

    verticalLayout->addWidget(titleLabel);

    auto * descriptionLabel = new QLabel(this);
    descriptionLabel->setText(
        QObject::tr(
            "Open the link below in your browser and authenticate the "
            "application to access the data in your Evernote account",
            "qevercloud::EvernoteOAuthWebViewPrivate"));

    verticalLayout->addWidget(descriptionLabel);

    m_oauthLinkLabel = new QLabel(this);

    Q_ASSERT(m_oauthLinkLabel);
    m_oauthLinkLabel->setText(
        QString::fromUtf8("<a href=\"%1\">%1</a>").arg(pageUrl.toString()));
    m_oauthLinkLabel->setTextFormat(Qt::RichText);
    m_oauthLinkLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    m_oauthLinkLabel->setOpenExternalLinks(true);
    m_oauthLinkLabel->setWordWrap(true);

    verticalLayout->addWidget(m_oauthLinkLabel);
    setLayout(verticalLayout);
    adjustSize();
}

void EvernoteOAuthWebViewPrivate::onOAuthResponseReceived()
{
}

void EvernoteOAuthWebViewPrivate::clear()
{
}

QObject * EvernoteOAuthWebViewPrivate::context()
{
    return this;
}

bool EvernoteOAuthWebViewPrivate::onStartAuthentication()
{
    Q_ASSERT(!m_oauthCallbackServer);
    m_oauthCallbackServer = new QTcpServer(this);
    const bool listen = m_oauthCallbackServer->listen(QHostAddress::LocalHost);
    if (Q_UNLIKELY(!listen)) {
        QEC_ERROR(
            "oauth[browser]",
            "Failed to set up local TCP server to listen for OAuth callback: "
                << "(" << m_oauthCallbackServer->serverError() << ") "
                << m_oauthCallbackServer->errorString());
        return false;
    }

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        m_oauthCallbackServer,
        &QTcpServer::newConnection,
        this,
        [this] {
            QEC_DEBUG(
                "oauth[browser]",
                "New connection for OAuth callback server");

            if (Q_UNLIKELY(!m_oauthCallbackServer)) {
                QEC_INFO(
                    "oauth[browser]",
                    "OAuth callback server has already been shut down");
                return;
            }

            auto pSocket = m_oauthCallbackServer->nextPendingConnection();
            Q_ASSERT(pSocket);

            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QEC_ERROR(
                    "oauth[browser]",
                    "Local OAuth callback server failed to establish incoming "
                    "connection");
                m_errorText = QObject::tr(
                    "Failed to establish connection between browser and local "
                    "OAuth server",
                    "qevercloud::EvernoteOAuthWebViewPrivate");
                Q_EMIT authenticationFinished(false);
                return;
            }

            auto pWeakSocket = QPointer<QTcpSocket>{pSocket};

            auto * pHttpRequestParser = new HttpRequestParser(*pSocket, this);
            QObject::connect(
                pHttpRequestParser,
                &HttpRequestParser::finished,
                this,
                [this, pHttpRequestParser, pWeakSocket]
                {
                    QEC_DEBUG(
                        "oauth[browser]", "HttpRequestParser is finished");

                    auto httpRequestData = pHttpRequestParser->requestData();
                    pHttpRequestParser->deleteLater();

                    if (onOAuthCallback(QString::fromUtf8(httpRequestData.uri))) {
                        respondWithAuthenticationIsCompletePage(pWeakSocket);
                    }
                    else {
                        respondWithAuthenticationFailedPage(pWeakSocket);
                    }
                });

            QObject::connect(
                pHttpRequestParser,
                &HttpRequestParser::failed,
                this,
                [this, pHttpRequestParser, pWeakSocket]
                {
                    QEC_WARNING("oauth[browser]", "HttpRequestParser failed");

                    setError(QObject::tr(
                        "Authentification failed",
                        "qevercloud::EvernoteOAuthWebViewPrivate"));

                    pHttpRequestParser->deleteLater();
                    respondWithAuthenticationFailedPage(pWeakSocket);
                });
        });

    return true;
}

QString EvernoteOAuthWebViewPrivate::oauthCallbackUrl() const
{
    Q_ASSERT(m_oauthCallbackServer);
    return QString::fromUtf8(QUrl(
        QString::fromUtf8("http://127.0.0.1:%1")
        .arg(m_oauthCallbackServer->serverPort())).toEncoded());
}

QNetworkAccessManager * EvernoteOAuthWebViewPrivate::networkAccessManager(
    QObject * rf)
{
    auto * pNam = new QNetworkAccessManager(rf);
    pNam->setCookieJar(new NetworkCookieJar);
    return pNam;
}

QList<QNetworkCookie> EvernoteOAuthWebViewPrivate::extractCookies(
    ReplyFetcher * pReplyFetcher)
{
    Q_ASSERT(pReplyFetcher);

    auto * pNam = pReplyFetcher->networkAccessManager();
    if (Q_UNLIKELY(!pNam)) {
        QEC_WARNING("oauth[browser]", "Failed to extract cookies after OAuth: "
            << "network access manager instance expired");
        return {};
    }

    auto * pCookieJar = qobject_cast<NetworkCookieJar*>(pNam->cookieJar());
    if (Q_UNLIKELY(!pCookieJar)) {
        QEC_WARNING("oauth[browser]", "Failed to extract cookies after OAuth: "
            << "unexpected instance of cookie jar");
        return {};
    }

    return pCookieJar->allCookies();
}

void EvernoteOAuthWebViewPrivate::respondWithAuthenticationIsCompletePage(
    const QPointer<QTcpSocket> & pWeakSocket)
{
    QEC_DEBUG(
        "oauth[browser]",
        "Responding with authentication is complete HTML page on OAuth "
            << "callback request");

    respondImpl(
        authenticationIsCompleteResponseText(), pWeakSocket);
}

void EvernoteOAuthWebViewPrivate::respondWithAuthenticationFailedPage(
    const QPointer<QTcpSocket> & pWeakSocket)
{
    QEC_DEBUG(
        "oauth[browser]",
        "Responding with authentication failed HTML page on OAuth callback "
            << "request");

    respondImpl(
        authenticationFailedResponseText(), pWeakSocket);
}

void EvernoteOAuthWebViewPrivate::respondImpl(
    const QString & text, const QPointer<QTcpSocket> & pWeakSocket)
{
    if (pWeakSocket.isNull()) {
        QEC_WARNING(
            "oauth[browser]",
            "Cannot respond on OAuth callback request: socket is dead");
        return;
    }

    auto * pSocket = pWeakSocket.data();

    QByteArray responseHtml = QString::fromUtf8(
        "<html><head/><body><p align=\"center\">"
        "<span style=\"font-size:12pt; font-weight:600;\">%1"
        "</span></p></body></html>").arg(text).toUtf8();

    QByteArray buffer;
    buffer.append("HTTP/1.1 200 OK\r\n");
    buffer.append("Content-Length: ");
    buffer.append(responseHtml.size());
    buffer.append("\r\n");
    buffer.append("Content-Type: text/html\r\n\r\n");
    buffer.append(responseHtml);

    if (!writeBufferToSocket(buffer, *pSocket)) {
        QEC_WARNING(
            "oauth[browser]",
            "Failed to write response to socket for OAuth callback");
        cleanupSocketAndServer(pWeakSocket);
        return;
    }

    QEC_DEBUG("oauth[browser]", "Responded on OAuth callback request");

    // Need to cleanup the resources but not immediately: the browser needs the
    // socket still open until it is able to receive the entire response
    auto timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(5000); // 5 seconds should be enough
    QObject::connect(
        timer,
        &QTimer::timeout,
        this,
        [this, timer, pWeakSocket]
        {
            timer->deleteLater();
            cleanupSocketAndServer(pWeakSocket);
        });

    timer->start();
}

QString EvernoteOAuthWebViewPrivate::authenticationIsCompleteResponseText() const
{
    return QObject::tr(
        "Authentication is complete! You can now close "
        "this page and return to the app",
        "qevercloud::EvernoteOAuthWebViewPrivate");
}

QString EvernoteOAuthWebViewPrivate::authenticationFailedResponseText() const
{
    return QObject::tr(
        "Authentication failed!",
        "qevercloud::EvernoteOAuthWebViewPrivate");
}

void EvernoteOAuthWebViewPrivate::cleanupSocketAndServer(
    const QPointer<QTcpSocket> & pWeakSocket)
{
    if (!pWeakSocket.isNull()) {
        auto * pSocket = pWeakSocket.data();
        pSocket->close();
        pSocket->deleteLater();
    }

    if (m_oauthCallbackServer) {
        m_oauthCallbackServer->close();
        m_oauthCallbackServer->deleteLater();
        m_oauthCallbackServer = nullptr;
    }
}

} // namespace qevercloud
