/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_EVER_CLOUD_EXCEPTION_H
#define QEVERCLOUD_EVER_CLOUD_EXCEPTION_H

#include "qt4helpers.h"
#include "export.h"
#include <QObject>
#include <QString>
#include <QSharedPointer>
#include <exception>

namespace qevercloud {

class QEVERCLOUD_EXPORT EverCloudExceptionData;

/**
 * All exceptions throws by the library are of this class or its descendants.
 */
class QEVERCLOUD_EXPORT EverCloudException: public std::exception
{
protected:
    mutable QByteArray m_error;

public:
    explicit EverCloudException();
    explicit EverCloudException(QString error);
    explicit EverCloudException(const std::string & error);
    explicit EverCloudException(const char * error);
    ~EverCloudException() throw();

    const char * what() const throw();

    virtual QSharedPointer<EverCloudExceptionData> exceptionData() const;
};

/**
 * @brief EverCloudException counterpart for asynchronous API.
 *
 * Asynchronous functions cannot throw exceptions so descendants of EverCloudExceptionData are retunded instead
 * in case of an error. Every exception class has its own counterpart.
 * The EverCloudExceptionData descendants hierarchy is a copy of the EverCloudException descendants hierarchy.
 *
 * The main reason not to use exception classes directly is that dynamic_cast does not work across module (exe, dll, etc) boundaries
 * in general, while `qobject_cast` do work as expected. That's why I decided to inherit my error classes from QObject.
 *
 * In general error checking in asynchronous API look like this:
 *
 * @code
NoteStore* ns;
...
QObject::connect(ns->getNotebook(notebookGuid), &AsyncResult::finished, [](QVariant result, QSharedPointer<EverCloudExceptionData> error) {
    if(!error.isNull()) {
        QSharedPointer<EDAMNotFoundExceptionData> errorNotFound = error.objectCast<EDAMNotFoundExceptionData>();
        QSharedPointer<EDAMUserExceptionData> errorUser = error.objectCast<EDAMUserExceptionData>();
        QSharedPointer<EDAMSystemExceptionData> errorSystem = error.objectCast<EDAMSystemExceptionData>();
        if(!errorNotFound.isNull()) {
            qDebug() << "notebook not found" << errorNotFound.identifier << errorNotFound.key;
        } else if(!errorUser.isNull()) {
            qDebug() << errorUser.errorMessage;
        } else if(!errorSystem.isNull()) {
            if(errorSystem.errorCode == EDAMErrorCode::RATE_LIMIT_REACHED) {
                qDebug() << "Evernote API rate limits are reached";
            } else if(errorSystem.errorCode == EDAMErrorCode::AUTH_EXPIRED) {
                qDebug() << "Authorization token is inspired";
            } else {
                // some other Evernote trouble
                qDebug() << errorSystem.errorMessage;
            }
        } else {
            // some unexpected error
            qDebug() << error.errorMessage;
        }
    } else {
      // success
    }
});

 @endcode
*/
class QEVERCLOUD_EXPORT EverCloudExceptionData: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(EverCloudExceptionData)
public:
    /**
     * Contains an error message. It's the std::exception::what() counterpart.
     */
    QString errorMessage;

    explicit EverCloudExceptionData(QString error);

    /**
     * If you want to throw an exception that corresponds to a recrived EverCloudExceptionData
     * descendant than call this function. Do not use `throw` statement, it's not polymorphic.
     */
    virtual void throwException() const;
};

/**
 * All exception sent by Evernote servers (as opposed to other error conditions, for example http errors) are
 * descendants of this class.
 */
class QEVERCLOUD_EXPORT EvernoteException: public EverCloudException
{
public:
    explicit EvernoteException();
    explicit EvernoteException(QString error);
    explicit EvernoteException(const std::string & error);
    explicit EvernoteException(const char * error);

    virtual QSharedPointer<EverCloudExceptionData> exceptionData() const Q_DECL_OVERRIDE;
};

/** Asynchronous API conterpart of EvernoteException. See EverCloudExceptionData for more details.*/
class QEVERCLOUD_EXPORT EvernoteExceptionData: public EverCloudExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EvernoteExceptionData)
public:
    explicit EvernoteExceptionData(QString error);
    virtual void throwException() const Q_DECL_OVERRIDE;
};

} // namespace qevercloud

#endif // QEVERCLOUD_EVER_CLOUD_EXCEPTION_H
