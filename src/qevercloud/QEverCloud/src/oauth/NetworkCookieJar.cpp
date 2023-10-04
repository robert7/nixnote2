/**
 * Copyright (c) 2020-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "NetworkCookieJar.h"

#include <QWebEngineCookieStore>
#include <QWebEngineProfile>

namespace qevercloud {

void NetworkCookieJar::loadStore()
{
    auto * pProfile = QWebEngineProfile::defaultProfile();
    auto * pCookieStore = pProfile->cookieStore();

    QObject::connect(
        pCookieStore,
        &QWebEngineCookieStore::cookieAdded,
        this,
        &NetworkCookieJar::handleCookieAdded,
        Qt::ConnectionType(Qt::UniqueConnection | Qt::DirectConnection));

    pCookieStore->loadAllCookies();
}

void NetworkCookieJar::handleCookieAdded(const QNetworkCookie & cookie)
{
    Q_UNUSED(QNetworkCookieJar::insertCookie(cookie))
}

} // namespace qevercloud
