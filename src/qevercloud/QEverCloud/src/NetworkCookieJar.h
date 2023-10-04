/**
 * Copyright (c) 2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <QNetworkCookie>
#include <QNetworkCookieJar>

namespace qevercloud {

/**
 * @brief The NetworkCookieJar class is a small class subclassing from
 * QNetworkCookieJar and exposing its protected members.
 *
 * When QEverCloud uses QtWebEngine, this class is also capable of collecting
 * cookies from QtWebEngine's default profile
 */
class NetworkCookieJar: public QNetworkCookieJar
{
    Q_OBJECT
public:
    explicit NetworkCookieJar(QObject * parent = nullptr) :
        QNetworkCookieJar(parent)
    {}

    QList<QNetworkCookie> allCookies()
    {
        return QNetworkCookieJar::allCookies();
    }

    void setAllCookies(QList<QNetworkCookie> cookies)
    {
        QNetworkCookieJar::setAllCookies(std::move(cookies));
    }

#if QEVERCLOUD_USE_QT_WEB_ENGINE
    void loadStore();

private Q_SLOTS:
    void handleCookieAdded(const QNetworkCookie & cookie);
#endif
};

} // namespace qevercloud
