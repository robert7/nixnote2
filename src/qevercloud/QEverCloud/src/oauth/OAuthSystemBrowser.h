/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_OAUTH_SYSTEM_BROWSER_H
#define QEVERCLOUD_OAUTH_SYSTEM_BROWSER_H

#include "AbstractOAuthEngine.h"

#include <QPointer>
#include <QWidget>

QT_BEGIN_NAMESPACE;

class QLabel;
class QTcpServer;
class QTcpSocket;

QT_END_NAMESPACE;

namespace qevercloud {

class EvernoteOAuthWebViewPrivate: public QWidget, public AbstractOAuthEngine
{
    Q_OBJECT
public:
    explicit EvernoteOAuthWebViewPrivate(QWidget * parent = nullptr);

Q_SIGNALS:
    void authenticationFinished(bool success);

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
    void respondWithAuthenticationIsCompletePage(
        const QPointer<QTcpSocket> & pWeakSocket);

    void respondWithAuthenticationFailedPage(
        const QPointer<QTcpSocket> & pWeakSocket);

    void respondImpl(
        const QString & text, const QPointer<QTcpSocket> & pWeakSocket);

    [[nodiscard]] QString authenticationIsCompleteResponseText() const;
    [[nodiscard]] QString authenticationFailedResponseText() const;

    void cleanupSocketAndServer(const QPointer<QTcpSocket> & pWeakSocket);

private:
    QTcpServer *    m_oauthCallbackServer = nullptr;
    QLabel *        m_oauthLinkLabel = nullptr;
};

} // namespace qevercloud

#endif // QEVERCLOUD_OAUTH_SYSTEM_BROWSER_H
