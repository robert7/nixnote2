/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_OAUTH_WEBENGINE_H
#define QEVERCLOUD_OAUTH_WEBENGINE_H

#include "AbstractOAuthEngine.h"

#include <QWebEngineProfile>
#include <QWebEngineView>
#include <QWebEngineHistory>

namespace qevercloud {

class NetworkCookieJar;

class EvernoteOAuthWebViewPrivate:
    public QWebEngineView, public AbstractOAuthEngine
{
    Q_OBJECT
public:
    explicit EvernoteOAuthWebViewPrivate(QWidget * parent = nullptr);

Q_SIGNALS:
    void authenticationFinished(bool success);

public Q_SLOTS:
    void clearHtml();

private Q_SLOTS:
    void onUrlChanged(const QUrl & url);

private: // AbstractOAuthEngine
    void onAuthenticationFinished(bool success) override;
    void openOAuthPage(QUrl pageUrl) override;
    void onOAuthResponseReceived() override;
    void clear() override;
    [[nodiscard]] QObject * context() override;
    [[nodiscard]] bool onStartAuthentication() override;
    [[nodiscard]] QString oauthCallbackUrl() const override;

    [[nodiscard]] QNetworkAccessManager * networkAccessManager(
        QObject * rf) override;

    [[nodiscard]] QList<QNetworkCookie> extractCookies(
        ReplyFetcher * pReplyFetcher) override;

private:
    NetworkCookieJar * m_pCookieJar = nullptr;
};

} // namespace qevercloud

#endif // QEVERCLOUD_OAUTH_WEBENGINE_H
