/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2017 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_EXPORT_H
#define QEVERCLOUD_EXPORT_H

#include <QtCore/QtGlobal>

#if defined(QEVERCLOUD_SHARED_LIBRARY)
#  define QEVERCLOUD_EXPORT Q_DECL_EXPORT
#elif defined(QEVERCLOUD_STATIC_LIBRARY)
#  define QEVERCLOUD_EXPORT Q_DECL_EXPORT
#else
#  define QEVERCLOUD_EXPORT Q_DECL_IMPORT
#endif

#endif // QEVERCLOUD_EXPORT_H
