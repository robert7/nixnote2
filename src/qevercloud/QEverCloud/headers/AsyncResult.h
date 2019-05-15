/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2016 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_ASYNC_RESULT_H
#define QEVERCLOUD_ASYNC_RESULT_H

#include "qt4helpers.h"
#include "export.h"
#include "EverCloudException.h"
#include <QObject>
#include <QNetworkRequest>

namespace qevercloud {

QT_FORWARD_DECLARE_CLASS(AsyncResultPrivate)

/**
 * @brief Returned by asynchonous versions of functions.
 *
 * Wait for AsyncResult::finished signal.
 *
 * Intended usage is something like this:
 *
 * @code
NoteStore* ns;
Note note;
...
QObject::connect(ns->createNoteAsync(note), &AsyncResult::finished, [ns](QVariant result, QSharedPointer<EverCloudExceptionData> error) {
    if(!error.isNull()) {
        // do something in case of an error
    } else {
        Note note = result.value<Note>();
        // process returned result
    }
});
 @endcode
 */
class QEVERCLOUD_EXPORT AsyncResult: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(AsyncResult)
private:
    static QVariant asIs(QByteArray replyData);

public:
    typedef QVariant (*ReadFunctionType)(QByteArray replyData);

    AsyncResult(QString url, QByteArray postData, ReadFunctionType readFunction = AsyncResult::asIs,
                bool autoDelete = true, QObject * parent = Q_NULLPTR);

    AsyncResult(QNetworkRequest request, QByteArray postData, ReadFunctionType readFunction = AsyncResult::asIs,
                bool autoDelete = true, QObject * parent = Q_NULLPTR);

    ~AsyncResult();

    /**
     * @brief Wait for asyncronous operation to complete.
     * @param timeout
     * Maximum time to wait in milliseconds. Forever if < 0.
     * @return true if finished successfully, false in case of the timeout
     */
    bool waitForFinished(int timeout = -1);

Q_SIGNALS:
    /**
     * @brief Emitted upon asyncronous call completition.
     * @param result
     * @param error
     * error.isNull() != true in case of an error. See EverCloudExceptionData for more details.
     *
     * AsyncResult deletes itself after emitting this signal. You don't have to manage it's lifetime explicitly.
     */
    void finished(QVariant result, QSharedPointer<EverCloudExceptionData> error);

private Q_SLOTS:
    void onReplyFetched(QObject * rp);
    void start();

private:
    AsyncResultPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(AsyncResult)
};

} // namespace qevercloud

#endif // QEVERCLOUD_ASYNC_RESULT_H
