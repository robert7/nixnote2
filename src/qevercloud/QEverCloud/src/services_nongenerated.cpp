/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <generated/services.h>
#include <qt4helpers.h>
#include <QUrl>

namespace qevercloud {

/**
 * @brief Constructs UserStore object.
 * @param host
 *   www.evernote.com or sandbox.evernote.com
 * @param authenticationToken
 *   This token that will be used as the default token.
 */
UserStore::UserStore(QString host, QString authenticationToken, QObject * parent) :
    QObject(parent)
{
    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(host);
    url.setPath(QStringLiteral("/edam/user"));
    m_url = url.toString(QUrl::StripTrailingSlash);
    setAuthenticationToken(authenticationToken);
}

/**
 * Constructs NoteStore object.
 * @param noteStoreUrl
 * EDAM NoteStore service url. In general it's different for different users.
 * @param authenticationToken
 *  This token that will be used as the default token.
 *
 */
NoteStore::NoteStore(QString noteStoreUrl, QString authenticationToken, QObject * parent) :
    QObject(parent)
{
    setNoteStoreUrl(noteStoreUrl);
    setAuthenticationToken(authenticationToken);
}

/**
 * Constructs NoteStore object.
 *
 * noteStoreUrl and possibly authenticationToken are expected to be specified later.
 */
NoteStore::NoteStore(QObject * parent) :
    QObject(parent)
{}

/** @fn qevercloud::UserStore::setAuthenticationToken
 * Sets a value that will be used as the default token.
 * */

/** @fn qevercloud::UserStore::authenticationToken
 * @returns the default authentication token value.
 * */

/** @fn qevercloud::NoteStore::setAuthenticationToken
 * Sets a value that will be used as the default token.
 * */

/** @fn qevercloud::NoteStore::authenticationToken
 * @returns the default authentication token value.
 * */

/** @fn qevercloud::NoteStore::setNoteStoreUrl
 * Sets a value that will be used as EDAM NoteStore service url by this object.
 * */

/** @fn qevercloud::NoteStore::authenticationToken
 * @returns EDAM NoteStore service url that is used by this NoteStore object.
 * */

} // namespace qevercloud
