/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_OAUTH_H
#define QEVERCLOUD_OAUTH_H

#include "Export.h"
#include "Helpers.h"
#include "Printable.h"

#include "generated/Types.h"

#include <QDialog>
#include <QList>
#include <QNetworkCookie>
#include <QString>

namespace qevercloud {

/**
 * @brief Sets the function to use for nonce generation for OAuth authentication.
 *
 * The default algorithm uses qrand() so do not forget to call qsrand() in your
 * application!
 *
 * qrand() is not guaranteed to be cryptographically strong. I try to amend
 * the fact by using QUuid::createUuid() which uses /dev/urandom if it's
 * available. But this is no guarantee either.
 * So if you want total control over nonce generation you can write you own
 * algorithm.
 *
 * setNonceGenerator is NOT thread safe.
 */
void setNonceGenerator(quint64 (*nonceGenerator)());

/** @cond HIDDEN_SYMBOLS  */
class EvernoteOAuthWebViewPrivate;
/** @endcond */

/**
 * @brief The class is tailored specifically for OAuth authorization with Evernote.
 *
 * While it is functional by itself you probably will prefer to use
 * EvernoteOAuthDialog.
 *
 * %Note that you have to include OAuth.h header.
 *
 * By default EvernoteOAuthWebView uses qrand() for generating nonce so do not
 * forget to call qsrand() in your application. See @link setNonceGenerator @endlink
 * If you want more control over nonce generation.
 */
class QEVERCLOUD_EXPORT EvernoteOAuthWebView: public QWidget
{
    Q_OBJECT
public:
    EvernoteOAuthWebView(QWidget * parent = Q_NULLPTR);

    /**
     * This function starts the OAuth sequence. In the end of the sequence will
     * be emitted one of the signals: authenticationSuceeded or authenticationFailed.
     *
     * Do not call the function while its call is in effect, i.e. one of
     * the signals is not emitted.
     *
     * @param host
     * Evernote host to authorize with. You need one of this:
     * <ul>
     * <li>"www.evernote.com" - the production service. It's the default value.</li>
     * <li>"sandox.evernote.com" - the developers "sandbox" service</li>
     * </ul>
     * @param consumerKey
     * get it <a href="http://dev.evernote.com/doc/">from the Evernote</a>
     * @param consumerSecret
     * along with this
     * @param timeoutMsec
     * Timeout for network requests in milliseconds
     */
    void authenticate(
        QString host, QString consumerKey, QString consumerSecret,
        const qint64 timeoutMsec = 30000);

    /**
      * @return true if the last call to authenticate resulted in a successful
      * authentication.
     */
    bool isSucceeded() const;

    /** @return error message resulted from the last call to authenticate */
    QString oauthError() const;

    /** Holds data that is returned by Evernote on a successful authentication */
    struct QEVERCLOUD_EXPORT OAuthResult: public Printable
    {
        QString noteStoreUrl; ///< note store url for the user; no need to
                              /// question UserStore::getNoteStoreUrl for it.
        Timestamp expires; ///< authenticationToken time of expiration.
        QString shardId; ///< usually is not used
        UserID userId; ///< same as PublicUserInfo::userId
        QString webApiUrlPrefix; ///< see PublicUserInfo::webApiUrlPrefix
        QString authenticationToken; ///< This is what this all was for!

        ///< Cookies set by Evernote during OAuth procedure. In April 2020 these
        /// cookies silently started to be required for UserStore API calls.
        /// Probably it was a bug on Evernote side which hopefully would be
        /// fixed at some point but nevertheless cookies set during OAuth
        /// procedure are now available as a part of OAuth result and can be
        /// used in subsequent calls to Evernote service. These cookies can
        /// be set when creating an instance of IRequestContext. Then this
        /// context can be used in QEverCloud calls. Cookies from context would
        /// propagate to HTTP requests performed by QEverCloud.
        /// See this thread on Evernote discussions for more details:
        /// https://discussion.evernote.com/topic/124257-calls-to-userstore-from-evernote-api-stopped-working
        QList<QNetworkCookie> cookies;

        virtual void print(QTextStream & strm) const override;
    };

    /** @returns the result of the last authentication, i.e. authenticate() call.*/
    OAuthResult oauthResult() const;

    /** The method is useful to specify default size for a EverOAuthWebView. */
    void setSizeHint(QSize sizeHint);

    QSize sizeHint() const override;

Q_SIGNALS:
    /** Emitted when the OAuth sequence started with authenticate() call is finished */
    void authenticationFinished(bool success);

    /**
     * Emitted when the OAuth sequence is successfully finished. Call
     * oauthResult() to get the data.
     */
    void authenticationSuceeded();

    /**
     * Emitted when the OAuth sequence is finished with a failure. Some error
     * info may be available with errorText().
     */
    void authenticationFailed();

private:
    EvernoteOAuthWebViewPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(EvernoteOAuthWebView)
};

/** @cond HIDDEN_SYMBOLS  */
class EvernoteOAuthDialogPrivate;
/** @endcond */

/**
 * @brief Authorizes your app with the Evernote service by means of OAuth
 * authentication.
 *
 * Intended usage:
 *
@code
#include <QEverCloudOAuth.h>

EvernoteOAuthDialog d(myConsumerKey, myConsumerSecret);
if(d.exec() == QDialog::Accepted) {
    EvernoteOAuthDialog::OAuthResult res = d.oauthResult();
    // Connect to Evernote
    ...
} else {
    QString errorText = d.oauthError();
    // handle an authentication error
    ...
}

@endcode
 *
 * %Note that you have to include QEverCloudOAuth.h header.
 *
 * By default EvernoteOAuthDialog uses qrand() for generating nonce so do not
 * forget to call qsrand() in your application.
 * See @link setNonceGenerator @endlink If you want more control over nonce
 * generation.
 */

class QEVERCLOUD_EXPORT EvernoteOAuthDialog: public QDialog
{
    Q_OBJECT
public:
    using OAuthResult = EvernoteOAuthWebView::OAuthResult;

    /** Constructs the dialog.
     *
     * @param host
     * Evernote host to authorize with. You need one of this:
     * <ul>
     * <li>"www.evernote.com" - the production service. It's the default value.</li>
     * <li>"sandox.evernote.com" - the developers "sandbox" service</li>
     * </ul>
     * @param consumerKey
     * get it <a href="http://dev.evernote.com/doc/">from the Evernote</a>
     * @param consumerSecret
     * along with this
    */
    EvernoteOAuthDialog(
        QString consumerKey, QString consumerSecret,
        QString host = QStringLiteral("www.evernote.com"),
        QWidget * parent = Q_NULLPTR);

    virtual ~EvernoteOAuthDialog() override;

    /**
     * The dialog adjusts its initial size automatically based on the contained
     * QWebView preffered size. Use this method to set the size.
     *
     * @param sizeHint will be used as the preffered size of the contained QWebView.
     */
    void setWebViewSizeHint(QSize sizeHint);

    /** @return true in case of a successful authentication.
     *          You probably better check exec() return value instead.
     */
    bool isSucceeded() const;

    /**
     * @return In case of an authentification error may return some information
     *         about the error.
     */
    QString oauthError() const;

    /**
     * @return the result of a successful authentication.
     */
    OAuthResult oauthResult() const;

    /**
     * @return
     *   QDialog::Accepted on a successful authentication.
     */
    virtual int exec() override;

    /** Shows the dialog as a window modal dialog, returning immediately.
     */
    virtual void open() override;

private:
    EvernoteOAuthDialogPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(EvernoteOAuthDialog)
};

} // namespace qevercloud

#endif // QEVERCLOUD_OAUTH_H
