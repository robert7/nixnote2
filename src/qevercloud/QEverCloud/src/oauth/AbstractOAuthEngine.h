/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_ABSTRACT_OAUTH_ENGINE_H
#define QEVERCLOUD_ABSTRACT_OAUTH_ENGINE_H

#include "../Http.h"

#include <OAuth.h>

#include <QSize>
#include <QUrl>

namespace qevercloud {

class AbstractOAuthEngine
{
public:
    [[nodiscard]] bool isSucceeded() const noexcept { return m_isSucceeded; }
    [[nodiscard]] QString oauthError() const { return m_errorText; }
    [[nodiscard]] EvernoteOAuthWebView::OAuthResult oauthResult() const;

    void setSizeHint(QSize sizeHint);
    [[nodiscard]] QSize sizeHintValue() const noexcept;

    void authenticate(
        QString host, QString consumerKey, QString consumerSecret,
        const qint64 timeoutMsec);

protected: // Methods that subclassed need to call when appropriate
    bool onOAuthCallback(const QString & url);
    void setError(QString error);

protected: // Interface for subclasses to implement
    virtual void onAuthenticationFinished(bool success) = 0;
    virtual void openOAuthPage(QUrl pageUrl) = 0;
    virtual void onOAuthResponseReceived() = 0;
    virtual void clear() = 0;
    [[nodiscard]] virtual QObject * context() = 0;
    [[nodiscard]] virtual bool onStartAuthentication() = 0;
    [[nodiscard]] virtual QString oauthCallbackUrl() const = 0;

    [[nodiscard]] virtual QNetworkAccessManager * networkAccessManager(
        QObject * rf) = 0;

    [[nodiscard]] virtual QList<QNetworkCookie> extractCookies(
        ReplyFetcher * pReplyFetcher) = 0;

private:
    void onTemporaryFinished(ReplyFetcher * rf);
    void onPermanentFinished(ReplyFetcher * rf);

protected:
    bool        m_isSucceeded = false;
    QSize       m_sizeHint;
    QString     m_errorText;
    QString     m_oauthUrlBase;
    QString     m_host;
    qint64      m_timeoutMsec = 0;
    EvernoteOAuthWebView::OAuthResult   m_oauthResult;
};

} // namespace qevercloud

#endif // QEVERCLOUD_ABSTRACT_OAUTH_ENGINE_H
