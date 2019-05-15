/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This header provides the "backports" of several Qt5 macros into Qt4
 * so that one can use Qt5 candies with Qt4 as well
 */

#ifndef QEVERCLOUD_QT4_HELPERS_H
#define QEVERCLOUD_QT4_HELPERS_H

#include <QtGlobal>

#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))

#if __cplusplus >= 201103L
#define Q_DECL_OVERRIDE override
#define Q_DECL_FINAL final
#define Q_STATIC_ASSERT_X(x1,x2) static_assert(x1, x2)
#define Q_DECL_EQ_DELETE = delete
#define Q_NULLPTR nullptr
#else
#define Q_DECL_OVERRIDE
#define Q_DECL_FINAL
#define Q_STATIC_ASSERT_X(x1,x2)
#define Q_DECL_EQ_DELETE
#define Q_NULLPTR NULL
#endif

#define QStringLiteral(x) QString(QLatin1String(x))

#define QEC_SIGNAL(className, methodName, ...) SIGNAL(methodName(__VA_ARGS__))
#define QEC_SLOT(className, methodName, ...) SLOT(methodName(__VA_ARGS__))

#else // QT_VERSION

#define QEC_SIGNAL(className, methodName, ...) &className::methodName
#define QEC_SLOT(className, methodName, ...) &className::methodName

#endif // QT_VERSION

#endif // QEVERCLOUD_QT4_HELPERS_H
