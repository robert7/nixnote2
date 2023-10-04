/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "OAuthWebEngine.h"

#include "NetworkCookieJar.h"
#include "Utils.h"

#include <Log.h>

namespace qevercloud {

EvernoteOAuthWebViewPrivate::EvernoteOAuthWebViewPrivate(QWidget * parent) :
    QWebEngineView(parent),
    m_pCookieJar{new NetworkCookieJar(this)}
{
    m_pCookieJar->loadStore();

    page()->profile()->defaultProfile()->setHttpAcceptLanguage(
        httpAcceptLanguage());
}

void EvernoteOAuthWebViewPrivate::clearHtml()
{
    setHtml(QLatin1String(""));
}

void EvernoteOAuthWebViewPrivate::onUrlChanged(const QUrl & url)
{
    const auto urlString = url.toString();
    if (!urlString.contains(QString::fromUtf8("%1?").arg(oauthCallbackUrl()))) {
        return;
    }

    onOAuthCallback(urlString);
}

void EvernoteOAuthWebViewPrivate::onAuthenticationFinished(bool success)
{
    Q_EMIT authenticationFinished(success);
}

void EvernoteOAuthWebViewPrivate::openOAuthPage(QUrl pageUrl)
{
    QEC_DEBUG("oauth[webengine]", "EvernoteOAuthWebViewPrivate::openOAuthPage");

    QObject::connect(
        this, &EvernoteOAuthWebViewPrivate::urlChanged,
        this, &EvernoteOAuthWebViewPrivate::onUrlChanged);

    setUrl(std::move(pageUrl));
}

void EvernoteOAuthWebViewPrivate::onOAuthResponseReceived()
{
    QObject::disconnect(
        this, &EvernoteOAuthWebViewPrivate::urlChanged,
        this, &EvernoteOAuthWebViewPrivate::onUrlChanged);

    QMetaObject::invokeMethod(this, "clearHtml", Qt::QueuedConnection);
}

void EvernoteOAuthWebViewPrivate::clear()
{
    setHtml(QLatin1String(""));
    history()->clear();
}

QObject * EvernoteOAuthWebViewPrivate::context()
{
    return this;
}

bool EvernoteOAuthWebViewPrivate::onStartAuthentication()
{
    setHtml(QLatin1String(""));
    history()->clear();
    return true;
}

QString EvernoteOAuthWebViewPrivate::oauthCallbackUrl() const
{
    return QStringLiteral("nnoauth");
}

QNetworkAccessManager * EvernoteOAuthWebViewPrivate::networkAccessManager(
    QObject * rf)
{
    auto * pNam = new QNetworkAccessManager(rf);
    pNam->setCookieJar(new NetworkCookieJar);
    return pNam;
}

QList<QNetworkCookie> EvernoteOAuthWebViewPrivate::extractCookies(
    ReplyFetcher * rf)
{
    Q_UNUSED(rf)
    Q_ASSERT(m_pCookieJar);
    return m_pCookieJar->allCookies();
}

} // namespace qevercloud
