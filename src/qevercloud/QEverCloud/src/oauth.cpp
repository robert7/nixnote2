/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <oauth.h>
#include <qt4helpers.h>
#include "http.h"
#include <QVBoxLayout>
#include <QNetworkReply>

#ifdef QEVERCLOUD_USE_QT_WEB_ENGINE
#include <QWebEngineView>
#include <QWebEngineHistory>
#else
#include <QWebView>
#include <QWebSettings>
#include <QWebHistory>
#endif

#include <QUuid>
#include <cstring>

/** @cond HIDDEN_SYMBOLS  */

namespace {

    quint64 random64()
    {
        quint64 res = 0;
        for(int i = 0; i < 8; i++) {
            res += static_cast<quint64>(qrand() % 256) << i*8;
        }

        QByteArray randomData = QUuid::createUuid().toRfc4122();
        quint64 random;
        std::memcpy(&random, &randomData.constData()[0], sizeof(random));
        res ^= random;
        std::memcpy(&random, &randomData.constData()[sizeof(random)], sizeof(random));
        res ^= random;

        return res;
    }

    typedef quint64 (*NonceGenerator)();
    NonceGenerator nonceGenerator_ = random64;

    NonceGenerator nonceGenerator() {return nonceGenerator_;}
}

void setNonceGenerator(quint64 (*nonceGenerator)())
{
    nonceGenerator_ = nonceGenerator;
}

namespace qevercloud {

#ifdef QEVERCLOUD_USE_QT_WEB_ENGINE
class EvernoteOAuthWebViewPrivate: public QWebEngineView
#else
class EvernoteOAuthWebViewPrivate: public QWebView
#endif
{
    Q_OBJECT
public:
    EvernoteOAuthWebViewPrivate(QWidget * parent = Q_NULLPTR);

Q_SIGNALS:
    void authenticationFinished(bool success);
    void authenticationSuceeded();
    void authenticationFailed();

public Q_SLOTS:
    void temporaryFinished(QObject * rf);
    void permanentFinished(QObject * rf);
    void onUrlChanged(const QUrl & url);
    void clearHtml();

public:
    void setError(QString error);

    bool        m_isSucceeded;
    QSize       m_sizeHint;
    QString     m_errorText;
    QString     m_oauthUrlBase;
    QString     m_host;
    EvernoteOAuthWebView::OAuthResult   m_oauthResult;
};

EvernoteOAuthWebViewPrivate::EvernoteOAuthWebViewPrivate(QWidget * parent)
#ifdef QEVERCLOUD_USE_QT_WEB_ENGINE
    : QWebEngineView(parent), m_isSucceeded(false)
#else
    : QWebView(parent), m_isSucceeded(false)
#endif
{
#ifndef QEVERCLOUD_USE_QT_WEB_ENGINE
    page()->setNetworkAccessManager(evernoteNetworkAccessManager());
#endif
}

void EvernoteOAuthWebViewPrivate::setError(QString errorText)
{
    m_isSucceeded = false;
    this->setHtml(QLatin1String(""));
    this->history()->clear();
    m_errorText = errorText;
    emit authenticationFinished(false);
    emit authenticationFailed();
}

EvernoteOAuthWebView::EvernoteOAuthWebView(QWidget * parent) :
    QWidget(parent),
    d_ptr(new EvernoteOAuthWebViewPrivate(this))
{
    QObject::connect(d_ptr, QEC_SIGNAL(EvernoteOAuthWebViewPrivate,authenticationFinished,bool),
                     this, QEC_SIGNAL(EvernoteOAuthWebView,authenticationFinished,bool));
    QObject::connect(d_ptr, QEC_SIGNAL(EvernoteOAuthWebViewPrivate,authenticationSuceeded),
                     this, QEC_SIGNAL(EvernoteOAuthWebView,authenticationSuceeded));
    QObject::connect(d_ptr, QEC_SIGNAL(EvernoteOAuthWebViewPrivate,authenticationFailed),
                     this, QEC_SIGNAL(EvernoteOAuthWebView,authenticationFailed));

    QVBoxLayout * pLayout = new QVBoxLayout(this);
    pLayout->addWidget(d_ptr);
    setLayout(pLayout);
}

void EvernoteOAuthWebView::authenticate(QString host, QString consumerKey, QString consumerSecret)
{
    Q_D(EvernoteOAuthWebView);
    d->m_host = host;
    d->m_isSucceeded = false;
    d->setHtml(QLatin1String(""));
    d->history()->clear();

    qint64 timestamp = QDateTime::currentMSecsSinceEpoch()/1000;
    quint64 nonce = nonceGenerator()();
    d->m_oauthUrlBase = QStringLiteral("https://%1/oauth?oauth_consumer_key=%2&oauth_signature=%3&oauth_signature_method=PLAINTEXT&oauth_timestamp=%4&oauth_nonce=%5")
            .arg(host, consumerKey, consumerSecret).arg(timestamp).arg(nonce);

    // step 1: acquire temporary token
    ReplyFetcher * replyFetcher = new ReplyFetcher();
    QObject::connect(replyFetcher, QEC_SIGNAL(ReplyFetcher,replyFetched,QObject*),
                     d, QEC_SLOT(EvernoteOAuthWebViewPrivate,temporaryFinished,QObject*));
    QUrl url(d->m_oauthUrlBase + QStringLiteral("&oauth_callback=nnoauth"));
#ifdef QEVERCLOUD_USE_QT_WEB_ENGINE
    replyFetcher->start(evernoteNetworkAccessManager(), url);
#else
    replyFetcher->start(d->page()->networkAccessManager(), url);
#endif
}

bool EvernoteOAuthWebView::isSucceeded() const
{
    Q_D(const EvernoteOAuthWebView);
    return d->m_isSucceeded;
}

QString EvernoteOAuthWebView::oauthError() const
{
    Q_D(const EvernoteOAuthWebView);
    return d->m_errorText;
}

EvernoteOAuthWebView::OAuthResult EvernoteOAuthWebView::oauthResult() const
{
    Q_D(const EvernoteOAuthWebView);
    return d->m_oauthResult;
}

void EvernoteOAuthWebView::setSizeHint(QSize sizeHint)
{
    Q_D(EvernoteOAuthWebView);
    d->m_sizeHint = sizeHint;
    updateGeometry();
}

QSize EvernoteOAuthWebView::sizeHint() const
{
    Q_D(const EvernoteOAuthWebView);
    return d->m_sizeHint;
}

void EvernoteOAuthWebViewPrivate::temporaryFinished(QObject * rf)
{
    ReplyFetcher * replyFetcher = qobject_cast<ReplyFetcher*>(rf);
    if (replyFetcher->isError())
    {
        setError(replyFetcher->errorText());
    }
    else
    {
        QString reply = QString::fromUtf8(replyFetcher->receivedData().constData());
        int index = reply.indexOf(QStringLiteral("&oauth_token_secret"));
        QString token = reply.left(index);

        // step 2: directing a user to the login page
        QObject::connect(this, QEC_SIGNAL(EvernoteOAuthWebViewPrivate,urlChanged,QUrl),
                         this, QEC_SLOT(EvernoteOAuthWebViewPrivate,onUrlChanged,QUrl));
        QUrl loginUrl(QStringLiteral("https://%1//OAuth.action?%2").arg(m_host, token));
        setUrl(loginUrl);
    }

    replyFetcher->deleteLater();
}

void EvernoteOAuthWebViewPrivate::onUrlChanged(const QUrl & url)
{
    // step 3: catch the redirect to our callback url (nnoauth)
    QString s = url.toString();
    QString oauthMarker = QStringLiteral("?oauth_token=");
    if (s.contains(QStringLiteral("nnoauth?")) && s.contains(oauthMarker))
    {
        if (s.contains(QStringLiteral("&oauth_verifier=")))
        { // success
            QString token = s.mid(s.indexOf(oauthMarker) + oauthMarker.length());

            // step 4: acquire permanent token
            ReplyFetcher * replyFetcher = new ReplyFetcher();
            QObject::connect(replyFetcher, QEC_SIGNAL(ReplyFetcher,replyFetched,QObject*),
                             this, QEC_SLOT(EvernoteOAuthWebViewPrivate,permanentFinished,QObject*));
            QUrl url(m_oauthUrlBase + QStringLiteral("&oauth_token=%1").arg(token));
#ifdef QEVERCLOUD_USE_QT_WEB_ENGINE
            replyFetcher->start(evernoteNetworkAccessManager(), url);
#else
            replyFetcher->start(page()->networkAccessManager(), url);
#endif
        }
        else
        {
            setError(QStringLiteral("Authentification failed."));
        }

        QObject::disconnect(this, QEC_SIGNAL(EvernoteOAuthWebViewPrivate,urlChanged,QUrl),
                            this, QEC_SLOT(EvernoteOAuthWebViewPrivate,onUrlChanged,QUrl));
        QMetaObject::invokeMethod(this, "clearHtml", Qt::QueuedConnection);
    }
}

void EvernoteOAuthWebViewPrivate::permanentFinished(QObject * rf)
{
    ReplyFetcher * replyFetcher = qobject_cast<ReplyFetcher*>(rf);
    if (replyFetcher->isError())
    {
        setError(replyFetcher->errorText());
    }
    else
    {
        m_isSucceeded = true;

        QByteArray reply = replyFetcher->receivedData();
        QMap<QString, QString> params;
        QList<QByteArray> vals = reply.split('&');

        for(int i = 0, size = vals.length(); i < size; i++)  {
            QString decoded = QUrl::fromPercentEncoding(vals[i]);
            int pos = decoded.indexOf(QStringLiteral("="));
            params[decoded.left(pos).trimmed()] = decoded.mid(pos + 1);
        }

        m_oauthResult.noteStoreUrl = params[QStringLiteral("edam_noteStoreUrl")];
        m_oauthResult.expires = Timestamp(params[QStringLiteral("edam_expires")].toLongLong());
        m_oauthResult.shardId = params[QStringLiteral("edam_shard")];
        m_oauthResult.userId = params[QStringLiteral("edam_userId")].toInt();
        m_oauthResult.webApiUrlPrefix = params[QStringLiteral("edam_webApiUrlPrefix")];
        m_oauthResult.authenticationToken = params[QStringLiteral("oauth_token")];

        emit authenticationFinished(true);
        emit authenticationSuceeded();
    }

    replyFetcher->deleteLater();
}

void EvernoteOAuthWebViewPrivate::clearHtml()
{
    setHtml(QLatin1String(""));
}

class EvernoteOAuthDialogPrivate
{
public:
    EvernoteOAuthDialogPrivate(const QString & host, const QString & consumerKey, const QString & consumerSecret) :
        m_pWebView(Q_NULLPTR),
        m_host(host),
        m_consumerKey(consumerKey),
        m_consumerSecret(consumerSecret)
    {}

    EvernoteOAuthWebView*   m_pWebView;
    QString                 m_host;
    QString                 m_consumerKey;
    QString                 m_consumerSecret;
};

EvernoteOAuthDialog::EvernoteOAuthDialog(QString consumerKey, QString consumerSecret, QString host, QWidget  *parent) :
    QDialog(parent),
    d_ptr(new EvernoteOAuthDialogPrivate(host, consumerKey, consumerSecret))
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    d_ptr->m_pWebView = new EvernoteOAuthWebView(this);

    QObject::connect(d_ptr->m_pWebView, QEC_SIGNAL(EvernoteOAuthWebView,authenticationSuceeded),
                     this, QEC_SLOT(EvernoteOAuthDialog,accept), Qt::QueuedConnection);
    QObject::connect(d_ptr->m_pWebView, QEC_SIGNAL(EvernoteOAuthWebView,authenticationFailed),
                     this, QEC_SLOT(EvernoteOAuthDialog,reject), Qt::QueuedConnection);

    QVBoxLayout * pLayout = new QVBoxLayout(this);
    pLayout->addWidget(d_ptr->m_pWebView);
    setLayout(pLayout);

    d_ptr->m_pWebView->setSizeHint(QSize(768,576));
    adjustSize();
}

EvernoteOAuthDialog::~EvernoteOAuthDialog()
{
#ifndef QEVERCLOUD_USE_QT_WEB_ENGINE
    QWebSettings::clearMemoryCaches();
#endif

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

#include "oauth.moc"
