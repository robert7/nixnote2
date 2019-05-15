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
#include <QString>

#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))

#if __cplusplus >= 201103L

#ifndef Q_DECL_OVERRIDE
#define Q_DECL_OVERRIDE override
#endif

#ifndef Q_DECL_FINAL
#define Q_DECL_FINAL final
#endif

#ifndef Q_STATIC_ASSERT_X
#define Q_STATIC_ASSERT_X(x1,x2) static_assert(x1, x2)
#endif

#ifndef Q_DECL_EQ_DELETE
#define Q_DECL_EQ_DELETE = delete
#endif

#ifndef Q_NULLPTR
#define Q_NULLPTR nullptr
#endif

#else // __cplusplus

#ifndef Q_DECL_OVERRIDE
#define Q_DECL_OVERRIDE
#endif

#ifndef Q_DECL_FINAL
#define Q_DECL_FINAL
#endif

#ifndef Q_STATIC_ASSERT_X
#define Q_STATIC_ASSERT_X(x1,x2)
#endif

#ifndef Q_DECL_EQ_DELETE
#define Q_DECL_EQ_DELETE
#endif

#ifndef Q_NULLPTR
#define Q_NULLPTR NULL
#endif

#endif // __cplusplus

#ifndef QStringLiteral
#define QStringLiteral(x) QString::fromUtf8(x, sizeof(x) - 1)
#endif

#define QEC_SIGNAL(className, methodName, ...) SIGNAL(methodName(__VA_ARGS__))
#define QEC_SLOT(className, methodName, ...) SLOT(methodName(__VA_ARGS__))

#else // QT_VERSION

// VS2010 is supposed to be C++11 but does not fulfull the entire standard.
#if defined(_MSC_VER) && _MSC_VER <= 1600 // MSVC <= 2010

#ifdef Q_DECL_OVERRIDE
#undef Q_DECL_OVERRIDE
#endif
#define Q_DECL_OVERRIDE

#endif // VS2010

#define QEC_SIGNAL(className, methodName, ...) &className::methodName
#define QEC_SLOT(className, methodName, ...) &className::methodName

#endif // QT_VERSION

#endif // QEVERCLOUD_QT4_HELPERS_H
