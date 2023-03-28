/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_TEST_DURABLE_SERVICE_H
#define QEVERCLOUD_TEST_DURABLE_SERVICE_H

#include <QObject>

namespace qevercloud {

class DurableServiceTester: public QObject
{
    Q_OBJECT
public:
    explicit DurableServiceTester(QObject * parent = nullptr);

private Q_SLOTS:
    void shouldExecuteSyncServiceCall();
    void shouldExecuteAsyncServiceCall();
    void shouldRetrySyncServiceCalls();
    void shouldRetryAsyncServiceCalls();
    void shouldNotRetrySyncServiceCallMoreThanMaxTimes();
    void shouldNotRetryAsyncServiceCallMoreThanMaxTimes();
    void shouldNotRetrySyncServiceCallInCaseOfUnretriableError();
    void shouldNotRetryAsyncServiceCallInCaseOfUnretriableError();
};

} // namespace qevercloud

#endif // QEVERCLOUD_TEST_DURABLE_SERVICE_H
