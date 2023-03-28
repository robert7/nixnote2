/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "OAuthWebKit.h"

#include "NetworkCookieJar.h"
#include "Utils.h"

#include <Globals.h>
#include <Log.h>

namespace qevercloud {

EvernoteOAuthWebViewPrivate::EvernoteOAuthWebViewPrivate(QWidget * parent) :
    QWebView(parent)
{
    auto * pNam = page()->networkAccessManager();
    pNam->setProxy(evernoteNetworkProxy());
    pNam->setCookieJar(new NetworkCookieJar);
}

EvernoteOAuthWebViewPrivate::~EvernoteOAuthWebViewPrivate()
{
    QWebSettings::clearMemoryCaches();
}

void EvernoteOAuthWebViewPrivate::clearHtml()
{
    setHtml(QLatin1String(""));
}

void EvernoteOAuthWebViewPrivate::onUrlChanged(const QUrl & url)
{
    const auto urlString = url.toString();
    if (!urlString.contains(QString::fromUtf8("%1?").arg(oauthCallbackUrl()))) {
        // Hack which appears to solve the problem of login page freezing on
        // analytics pitstop
        back();
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
    QEC_DEBUG("oauth[webkit]", "EvernoteOAuthWebViewPrivate::openOAuthPage");

    QObject::connect(
        this, &EvernoteOAuthWebViewPrivate::urlChanged,
        this, &EvernoteOAuthWebViewPrivate::onUrlChanged);

    QNetworkRequest request;
    request.setUrl(pageUrl);
    request.setRawHeader(
        QByteArray("Accept-Language"), httpAcceptLanguage().toUtf8());

    load(request);
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
    return page()->networkAccessManager();
}

QList<QNetworkCookie> EvernoteOAuthWebViewPrivate::extractCookies(
    ReplyFetcher * rf)
{
    Q_ASSERT(rf);

    auto * pNam = rf->networkAccessManager();
    if (Q_UNLIKELY(!pNam)) {
        QEC_WARNING("oauth[webkit]", "Failed to extract cookies after OAuth: "
            << "network access manager instance expired");
        return {};
    }

    auto * pCookieJar = qobject_cast<NetworkCookieJar*>(pNam->cookieJar());
    if (Q_UNLIKELY(!pCookieJar)) {
        QEC_WARNING("oauth[webkit]", "Failed to extract cookies after OAuth: "
            << "unexpected instance of cookie jar");
        return {};
    }

    return pCookieJar->allCookies();
}

} // namespace qevercloud
