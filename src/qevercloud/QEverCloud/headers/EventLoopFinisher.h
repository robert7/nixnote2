/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_EVENT_LOOP_FINISHER_H
#define QEVERCLOUD_EVENT_LOOP_FINISHER_H

#include "Export.h"
#include "Helpers.h"

#include <QEventLoop>
#include <QObject>

namespace qevercloud {

QT_FORWARD_DECLARE_CLASS(EventLoopFinisherPrivate)

class QEVERCLOUD_EXPORT EventLoopFinisher: public QObject
{
    Q_OBJECT
public:
    explicit EventLoopFinisher(
        QEventLoop * loop, int exitCode, QObject * parent = Q_NULLPTR);

    ~EventLoopFinisher();

public Q_SLOTS:
    void stopEventLoop();

private:
    EventLoopFinisherPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(EventLoopFinisher)
};

} // namespace qevercloud

#endif // QEVERCLOUD_EVENT_LOOP_FINISHER_H
