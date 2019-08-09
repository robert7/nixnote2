/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_GLOBALS_H
#define QEVERCLOUD_GLOBALS_H

#include "export.h"
#include <QNetworkAccessManager>

/**
 * All the library lives in this namespace.
 */
namespace qevercloud {

/**
 * All network request made by QEverCloud - including OAuth - are
 * served by this NetworkAccessManager.
 *
 * Use this function to handle proxy authentication requests etc.
 */
QEVERCLOUD_EXPORT QNetworkAccessManager * evernoteNetworkAccessManager();

/**
 * Network request timeout in milliseconds
 */
QEVERCLOUD_EXPORT int connectionTimeout();

/**
 * Set network request timeout; negative values mean no timeout
 */
QEVERCLOUD_EXPORT void setConnectionTimeout(int timeout);

/**
 * qevercloud library version.
 */
QEVERCLOUD_EXPORT int libraryVersion();

} // namespace qevercloud

#endif // QEVERCLOUD_GLOBALS_H
