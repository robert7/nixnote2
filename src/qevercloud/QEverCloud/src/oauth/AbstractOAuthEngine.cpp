/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "AbstractOAuthEngine.h"
#include "NonceGenerator.h"

#include <Globals.h>
#include <Log.h>

namespace qevercloud {

EvernoteOAuthWebView::OAuthResult AbstractOAuthEngine::oauthResult() const
{
    return m_oauthResult;
}

void AbstractOAuthEngine::setSizeHint(QSize sizeHint)
{
    m_sizeHint = sizeHint;
}

QSize AbstractOAuthEngine::sizeHintValue() const noexcept
{
    return m_sizeHint;
}

void AbstractOAuthEngine::authenticate(
    QString host, QString consumerKey, QString consumerSecret,
    const qint64 timeoutMsec)
{
    m_host = host;
    m_isSucceeded = false;
    m_timeoutMsec = timeoutMsec;

    if (!onStartAuthentication()) {
        onAuthenticationFinished(false);
        return;
    }

    qint64 timestamp = QDateTime::currentMSecsSinceEpoch()/1000;
    quint64 nonce = nonceGenerator()();
    m_oauthUrlBase =
        QString::fromUtf8("https://%1/oauth?oauth_consumer_key=%2&"
                          "oauth_signature=%3&"
                          "oauth_signature_method=PLAINTEXT&"
                          "oauth_timestamp=%4&oauth_nonce=%5")
        .arg(host, consumerKey, consumerSecret).arg(timestamp).arg(nonce);

    // step 1: acquire temporary token
    ReplyFetcher * replyFetcher = new ReplyFetcher(context());
    QObject::connect(
        replyFetcher,
        &ReplyFetcher::replyFetched,
        context(),
        [this](ReplyFetcher * rf)
        {
            onTemporaryFinished(rf);
        });

    QUrl url(
        m_oauthUrlBase +
        QString::fromUtf8("&oauth_callback=%1").arg(oauthCallbackUrl()));

    auto * pNam = networkAccessManager(replyFetcher);
    Q_ASSERT(pNam);

    pNam->setProxy(evernoteNetworkProxy());
    replyFetcher->start(pNam, url, timeoutMsec);
}

bool AbstractOAuthEngine::onOAuthCallback(const QString & url)
{
    QEC_DEBUG("oauth[abstract]", "AbstractOAuthEngine::onOAuthCallback");

    // step 3: catch the redirect to our callback url
    bool result = false;
    const QString oauthMarker = QStringLiteral("?oauth_token=");
    if (url.contains(oauthMarker))
    {
        if (url.contains(QStringLiteral("&oauth_verifier=")))
        {
            QEC_DEBUG(
                "oauth[abstract]",
                "Received approval for permanent token receipt");

            result = true;
            QString token =
                url.mid(url.indexOf(oauthMarker) + oauthMarker.length());

            // step 4: acquire permanent token
            QEC_DEBUG(
                "oauth[abstract]",
                "Sending request to acquire permanent token");

            ReplyFetcher * replyFetcher = new ReplyFetcher(context());
            QObject::connect(
                replyFetcher,
                &ReplyFetcher::replyFetched,
                context(),
                [this](ReplyFetcher * rf)
                {
                    onPermanentFinished(rf);
                });

            QUrl url{
                m_oauthUrlBase +
                    QString::fromUtf8("&oauth_token=%1").arg(token)};

            auto * pNam = networkAccessManager(replyFetcher);
            pNam->setProxy(evernoteNetworkProxy());
            replyFetcher->start(pNam, url, m_timeoutMsec);
        }
        else
        {
            QEC_WARNING("oauth[abstract]", "Authentication failed");
            setError(QStringLiteral("Authentification failed."));
        }

        onOAuthResponseReceived();
    }

    return result;
}

void AbstractOAuthEngine::setError(QString error)
{
    m_isSucceeded = false;

    clear();

    m_errorText = error;
    onAuthenticationFinished(false);
}

void AbstractOAuthEngine::onTemporaryFinished(ReplyFetcher * rf)
{
    Q_ASSERT(rf);
    if (rf->isError())
    {
        QEC_WARNING("oauth[abstract]", "Failed to acquire temporary token: "
            << rf->errorText());
        setError(rf->errorText());
    }
    else
    {
        QEC_DEBUG("oauth[abstract]", "Successfully acquired temporary token");
        QString reply = QString::fromUtf8(rf->receivedData().constData());
        int index = reply.indexOf(QStringLiteral("&oauth_token_secret"));
        QString token = reply.left(index);

        // step 2: directing a user to the login page
        QUrl pageUrl{
            QString::fromUtf8("https://%1//OAuth.action?%2")
                .arg(m_host, std::move(token))};

        openOAuthPage(std::move(pageUrl));
    }

    rf->deleteLater();
}

void AbstractOAuthEngine::onPermanentFinished(ReplyFetcher * rf)
{
    Q_ASSERT(rf);
    if (rf->isError())
    {
        QEC_WARNING("oauth[abstract]", "Failed to acquire permanent token");
        setError(rf->errorText());
    }
    else
    {
        QEC_DEBUG("oauth[abstract]", "Successfully acquired permanent token");

        m_isSucceeded = true;

        QByteArray reply = rf->receivedData();
        QMap<QString, QString> params;
        QList<QByteArray> vals = reply.split('&');

        for(int i = 0, size = vals.length(); i < size; i++)  {
            QString decoded = QUrl::fromPercentEncoding(vals[i]);
            int pos = decoded.indexOf(QStringLiteral("="));
            params[decoded.left(pos).trimmed()] = decoded.mid(pos + 1);
        }

        m_oauthResult.noteStoreUrl = params[QStringLiteral("edam_noteStoreUrl")];
        m_oauthResult.expires =
            Timestamp(params[QStringLiteral("edam_expires")].toLongLong());
        m_oauthResult.shardId = params[QStringLiteral("edam_shard")];
        m_oauthResult.userId = params[QStringLiteral("edam_userId")].toInt();
        m_oauthResult.webApiUrlPrefix =
            params[QStringLiteral("edam_webApiUrlPrefix")];
        m_oauthResult.authenticationToken = params[QStringLiteral("oauth_token")];

        m_oauthResult.cookies = extractCookies(rf);
        onAuthenticationFinished(true);
    }

    rf->deleteLater();
}

} // namespace qevercloud
