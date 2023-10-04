/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_GLOBALS_H
#define QEVERCLOUD_GLOBALS_H

#include "Export.h"

#include <QNetworkProxy>

/**
 * All the library lives in this namespace.
 */
namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

/**
 * Getter for network proxy settings used by QEverCloud. If none were set
 * explicitly, returns the same result as QNetworkProxy::applicationProxy.
 * Hence, QEverCloud uses the same proxy settings as the application which uses
 * QEverCloud by default.
 *
 * This function is thread-safe although internally it operates on a static
 * object containing proxy settings so it's not recommended to read and write
 * proxy settings concurrently to avoid contention for static object.
 *
 * WARNING: when QEverCloud is built with QtWebEngine and some proxy settings
 * different from QNetworkProxy::applicationProxy are set, the OAuth call
 * which loads the web page would not use them; instead it would use proxy
 * settings from QNetworkProxy::applicationProxy. This limitation is imposed
 * by Qt: https://doc.qt.io/qt-5/qtwebengine-overview.html#proxy-support
 */
QEVERCLOUD_EXPORT QNetworkProxy evernoteNetworkProxy();

/**
 * Setter for network proxy settings used by QEverCloud. If this function is
 * never called, QEverCloud would use proxy settings returned from
 * QNetworkProxy::applicationProxy static method.
 *
 * This function is thread-safe although internally it operates on a static
 * object containing proxy settings so it's not recommended to read and write
 * proxy settings concurrently to avoid contention for static object.
 *
 * WARNING: when QEverCloud is built with QtWebEngine and some proxy settings
 * different from QNetworkProxy::applicationProxy are set, the OAuth call
 * which loads the web page would not use them; instead it would use proxy
 * settings from QNetworkProxy::applicationProxy. This limitation is imposed
 * by Qt: https://doc.qt.io/qt-5/qtwebengine-overview.html#proxy-support
 */
QEVERCLOUD_EXPORT void setEvernoteNetworkProxy(QNetworkProxy proxy);

/**
 * Reset network proxy settings used by QEverCloud to those returned from
 * QNetworkProxy::applicationProxy static method.
 *
 * This function is thread-safe although internally it operates on a static
 * object containing proxy settings so it's not recommended to read and write
 * proxy settings concurrently to avoid contention for static object.
 */
QEVERCLOUD_EXPORT void resetEvernoteNetworkProxy();

////////////////////////////////////////////////////////////////////////////////

/**
 * QEverCloud library version.
 */
Q_DECL_DEPRECATED_X("libraryVersion is deprecated, use qevercloudVersionMajor/Minor/Patch instead")
QEVERCLOUD_EXPORT int libraryVersion();

////////////////////////////////////////////////////////////////////////////////

/**
 * Initialization function for QEverCloud, needs to be called once
 * before using the library. There is no harm if it is called multiple times
 */
QEVERCLOUD_EXPORT void initializeQEverCloud();

} // namespace qevercloud

#endif // QEVERCLOUD_GLOBALS_H
