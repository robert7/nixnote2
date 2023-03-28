/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <RequestContext.h>

#include <Helpers.h>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

class Q_DECL_HIDDEN RequestContext final: public IRequestContext
{
public:
    RequestContext(QString authenticationToken, qint64 requestTimeout,
                   bool increaseRequestTimeoutExponentially,
                   qint64 maxRequestTimeout,
                   quint32 maxRequestRetryCount,
                   QList<QNetworkCookie> cookies) :
        m_requestId(QUuid::createUuid()),
        m_authenticationToken(std::move(authenticationToken)),
        m_requestTimeout(requestTimeout),
        m_increaseRequestTimeoutExponentially(increaseRequestTimeoutExponentially),
        m_maxRequestTimeout(maxRequestTimeout),
        m_maxRequestRetryCount(maxRequestRetryCount),
        m_cookies(std::move(cookies))
    {}

    virtual QUuid requestId() const override
    {
        return m_requestId;
    }

    virtual QString authenticationToken() const override
    {
        return m_authenticationToken;
    }

    virtual qint64 requestTimeout() const override
    {
        return m_requestTimeout;
    }

    virtual bool increaseRequestTimeoutExponentially() const override
    {
        return m_increaseRequestTimeoutExponentially;
    }

    virtual qint64 maxRequestTimeout() const override
    {
        return m_maxRequestTimeout;
    }

    virtual quint32 maxRequestRetryCount() const override
    {
        return m_maxRequestRetryCount;
    }

    virtual QList<QNetworkCookie> cookies() const override
    {
        return m_cookies;
    }

    virtual IRequestContext * clone() const override
    {
        return new RequestContext(
            m_authenticationToken,
            m_requestTimeout,
            m_increaseRequestTimeoutExponentially,
            m_maxRequestTimeout,
            m_maxRequestRetryCount,
            m_cookies);
    }

private:
    QUuid       m_requestId;
    QString     m_authenticationToken;
    qint64      m_requestTimeout;
    bool        m_increaseRequestTimeoutExponentially;
    qint64      m_maxRequestTimeout;
    quint32     m_maxRequestRetryCount;

    QList<QNetworkCookie>   m_cookies;
};

////////////////////////////////////////////////////////////////////////////////

template <typename T>
void printRequestContext(const IRequestContext & ctx, T & strm)
{
    strm << "RequestContext:\n"
        << "    authentication token = " << ctx.authenticationToken() << "\n"
        << "    request timeout = " << ctx.requestTimeout() << "\n"
        << "    increase request timeout exponentially = "
        << (ctx.increaseRequestTimeoutExponentially() ? "yes" : "no") << "\n"
        << "    max request timeout = " << ctx.maxRequestTimeout() << "\n"
        << "    max request retry count = " << ctx.maxRequestRetryCount()
        << "\n";

    const auto cookies = ctx.cookies();
    if (!cookies.isEmpty())
    {
        strm << "    cookies: " << "\n";

        for(const auto & cookie: qAsConst(cookies)) {
            strm << "        " << QString::fromUtf8(cookie.toRawForm()) << "\n";
        }
    }
}


QTextStream & operator<<(QTextStream & strm, const IRequestContext & ctx)
{
    printRequestContext(ctx, strm);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const IRequestContext & ctx)
{
    printRequestContext(ctx, dbg);
    return dbg;
}

////////////////////////////////////////////////////////////////////////////////

IRequestContextPtr newRequestContext(
    QString authenticationToken,
    qint64 requestTimeout,
    bool increaseRequestTimeoutExponentially,
    qint64 maxRequestTimeout,
    quint32 maxRequestRetryCount,
    QList<QNetworkCookie> cookies)
{
    return std::make_shared<RequestContext>(
        std::move(authenticationToken),
        requestTimeout,
        increaseRequestTimeoutExponentially,
        maxRequestTimeout,
        maxRequestRetryCount,
        std::move(cookies));
}

} // namespace qevercloud
