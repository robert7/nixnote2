/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <OAuth.h>

#include <Log.h>

#if QEVERCLOUD_USE_QT_WEB_ENGINE
#include "OAuthWebEngine.h"
#elif QEVERCLOUD_USE_SYSTEM_BROWSER
#include "OAuthSystemBrowser.h"
#else
#include "OAuthWebKit.h"
#endif

#include <QVBoxLayout>

namespace qevercloud {

EvernoteOAuthWebView::EvernoteOAuthWebView(QWidget * parent) :
    QWidget(parent),
    d_ptr(new EvernoteOAuthWebViewPrivate(this))
{
    QObject::connect(
        d_ptr, &EvernoteOAuthWebViewPrivate::authenticationFinished,
        this,
        [this](const bool success)
        {
            Q_EMIT authenticationFinished(success);

            if (success) {
                Q_EMIT authenticationSuceeded();
            }
            else {
                Q_EMIT authenticationFailed();
            }
        });

    QVBoxLayout * pLayout = new QVBoxLayout(this);
    pLayout->addWidget(d_ptr);
    setLayout(pLayout);
}

void EvernoteOAuthWebView::authenticate(
    QString host, QString consumerKey, QString consumerSecret,
    const qint64 timeoutMsec)
{
    QEC_DEBUG("oauth", "Sending request to acquire temporary token");

    Q_D(EvernoteOAuthWebView);
    d->authenticate(
        std::move(host), std::move(consumerKey), std::move(consumerSecret),
        timeoutMsec);
}

bool EvernoteOAuthWebView::isSucceeded() const
{
    Q_D(const EvernoteOAuthWebView);
    return d->isSucceeded();
}

QString EvernoteOAuthWebView::oauthError() const
{
    Q_D(const EvernoteOAuthWebView);
    return d->oauthError();
}

EvernoteOAuthWebView::OAuthResult EvernoteOAuthWebView::oauthResult() const
{
    Q_D(const EvernoteOAuthWebView);
    return d->oauthResult();
}

void EvernoteOAuthWebView::setSizeHint(QSize sizeHint)
{
    Q_D(EvernoteOAuthWebView);
    d->setSizeHint(sizeHint);
    updateGeometry();
}

QSize EvernoteOAuthWebView::sizeHint() const
{
    Q_D(const EvernoteOAuthWebView);
    return d->sizeHintValue();
}

////////////////////////////////////////////////////////////////////////////////

void EvernoteOAuthWebView::OAuthResult::print(QTextStream & strm) const
{
    strm << "qevercloud::EvernoteOAuthWebView::OAuthResult {\n";

    strm << "  noteStoreUrl = " << noteStoreUrl << ";\n";
    strm << "  expires = " << expires << ";\n";
    strm << "  shardId = " << shardId << ";\n";
    strm << "  userId = " << QString::number(userId) << ";\n";
    strm << "  webApiUrlPrefix = " << webApiUrlPrefix << ";\n";
    strm << "  authenticationToken "
        << (authenticationToken.isEmpty()
            ? "is empty"
            : "is not empty") << ";\n";
    strm << "  cookies count: " << cookies.size() << ";\n";

    strm << "};\n";
}

////////////////////////////////////////////////////////////////////////////////

class EvernoteOAuthDialogPrivate
{
public:
    EvernoteOAuthDialogPrivate(
        const QString & host, const QString & consumerKey,
        const QString & consumerSecret) :
        m_pWebView(nullptr),
        m_host(host),
        m_consumerKey(consumerKey),
        m_consumerSecret(consumerSecret)
    {}

    EvernoteOAuthWebView *  m_pWebView;
    QString                 m_host;
    QString                 m_consumerKey;
    QString                 m_consumerSecret;
};

////////////////////////////////////////////////////////////////////////////////

EvernoteOAuthDialog::EvernoteOAuthDialog(
    QString consumerKey, QString consumerSecret, QString host,
    QWidget * parent) :
    QDialog(parent),
    d_ptr(new EvernoteOAuthDialogPrivate(host, consumerKey, consumerSecret))
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    d_ptr->m_pWebView = new EvernoteOAuthWebView(this);

    QObject::connect(
        d_ptr->m_pWebView, &EvernoteOAuthWebView::authenticationSuceeded,
        this, &EvernoteOAuthDialog::accept, Qt::QueuedConnection);

    QObject::connect(
        d_ptr->m_pWebView, &EvernoteOAuthWebView::authenticationFailed,
        this, &EvernoteOAuthDialog::reject, Qt::QueuedConnection);

    QVBoxLayout * pLayout = new QVBoxLayout(this);
    pLayout->addWidget(d_ptr->m_pWebView);
    setLayout(pLayout);

    d_ptr->m_pWebView->setSizeHint(QSize(768,576));
    adjustSize();
}

EvernoteOAuthDialog::~EvernoteOAuthDialog()
{
    delete d_ptr;
}

void EvernoteOAuthDialog::setWebViewSizeHint(QSize sizeHint)
{
    Q_D(EvernoteOAuthDialog);
    d->m_pWebView->setSizeHint(sizeHint);
}

bool EvernoteOAuthDialog::isSucceeded() const
{
    Q_D(const EvernoteOAuthDialog);
    return d->m_pWebView->isSucceeded();
}

QString EvernoteOAuthDialog::oauthError() const
{
    Q_D(const EvernoteOAuthDialog);
    return d->m_pWebView->oauthError();
}

EvernoteOAuthDialog::OAuthResult EvernoteOAuthDialog::oauthResult() const
{
    Q_D(const EvernoteOAuthDialog);
    return d->m_pWebView->oauthResult();
}

int EvernoteOAuthDialog::exec()
{
    Q_D(EvernoteOAuthDialog);
    d->m_pWebView->authenticate(d->m_host, d->m_consumerKey, d->m_consumerSecret);
    return QDialog::exec();
}

void EvernoteOAuthDialog::open()
{
    Q_D(EvernoteOAuthDialog);
    QDialog::open();
    d->m_pWebView->authenticate(d->m_host, d->m_consumerKey, d->m_consumerSecret);
}

} // namespace qevercloud

/** @endcond */
