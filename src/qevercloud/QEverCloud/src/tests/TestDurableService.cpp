/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "TestDurableService.h"

#include <DurableService.h>
#include <Exceptions.h>

#include <QEventLoop>
#include <QtTest/QtTest>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

class ValueFetcher: public QObject
{
    Q_OBJECT
public:
    explicit ValueFetcher(QObject * parent = nullptr) :
        QObject(parent)
    {}

    QVariant m_value;
    EverCloudExceptionDataPtr m_exceptionData;

Q_SIGNALS:
    void finished();

public Q_SLOTS:
    void onFinished(
        QVariant value,
        EverCloudExceptionDataPtr data,
        IRequestContextPtr ctx)
    {
        Q_UNUSED(ctx)
        m_value = value;
        m_exceptionData = data;
        Q_EMIT finished();
    }
};

////////////////////////////////////////////////////////////////////////////////

DurableServiceTester::DurableServiceTester(QObject * parent) :
    QObject(parent)
{}

void DurableServiceTester::shouldExecuteSyncServiceCall()
{
    auto durableService = newDurableService();

    bool serviceCallDetected = false;
    QVariant value = QStringLiteral("value");

    IDurableService::SyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> IDurableService::SyncResult {
            Q_ASSERT(ctx);
            serviceCallDetected = true;
            return {value, {}};
        });

    auto result = durableService->executeSyncRequest(
        std::move(request),
        newRequestContext());

    QVERIFY(serviceCallDetected);
    QVERIFY(result.first == value);
    QVERIFY(!result.second);
}

void DurableServiceTester::shouldExecuteAsyncServiceCall()
{
    auto durableService = newDurableService();

    bool serviceCallDetected = false;
    QVariant value = QStringLiteral("value");

    IDurableService::AsyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> AsyncResult* {
            Q_ASSERT(ctx);
            serviceCallDetected = true;
            return new AsyncResult(value, {}, ctx);
        });

    AsyncResult * result = durableService->executeAsyncRequest(
        std::move(request),
        newRequestContext());

    ValueFetcher valueFetcher;
    QObject::connect(result, &AsyncResult::finished,
                     &valueFetcher, &ValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(&valueFetcher, &ValueFetcher::finished,
                     &loop, &QEventLoop::quit);
    loop.exec();

    QVERIFY(serviceCallDetected);
    QVERIFY(valueFetcher.m_value == value);
    QVERIFY(!valueFetcher.m_exceptionData);
}

void DurableServiceTester::shouldRetrySyncServiceCalls()
{
    auto durableService = newDurableService();

    int serviceCallCounter = 0;
    int maxServiceCallCounter = 3;

    auto ctx = newRequestContext(
        QString(),
        DEFAULT_REQUEST_TIMEOUT_MSEC,
        DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_INCREASE,
        DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
        maxServiceCallCounter);

    QVariant value = QStringLiteral("value");

    IDurableService::SyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> IDurableService::SyncResult {
            Q_ASSERT(ctx);
            Q_ASSERT(ctx->maxRequestRetryCount() == maxServiceCallCounter);

            ++serviceCallCounter;
            if (serviceCallCounter < maxServiceCallCounter)
            {
                EverCloudExceptionDataPtr data;
                try {
                    throw NetworkException(QNetworkReply::TimeoutError);
                }
                catch(const EverCloudException & e) {
                    data = e.exceptionData();
                }

                return {{}, data};
            }

            return {value, {}};
        });

    auto result = durableService->executeSyncRequest(std::move(request), ctx);

    QVERIFY(serviceCallCounter == maxServiceCallCounter);
    QVERIFY(result.first == value);
    QVERIFY(!result.second);
}

void DurableServiceTester::shouldRetryAsyncServiceCalls()
{
    auto durableService = newDurableService();

    int serviceCallCounter = 0;
    int maxServiceCallCounter = 3;

    auto ctx = newRequestContext(
        QString(),
        DEFAULT_REQUEST_TIMEOUT_MSEC,
        DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_INCREASE,
        DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
        maxServiceCallCounter);

    QVariant value = QStringLiteral("value");

    IDurableService::AsyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> AsyncResult* {
            Q_ASSERT(ctx);
            Q_ASSERT(ctx->maxRequestRetryCount() == maxServiceCallCounter);

            ++serviceCallCounter;
            if (serviceCallCounter < maxServiceCallCounter)
            {
                EverCloudExceptionDataPtr data;
                try {
                    throw NetworkException(QNetworkReply::TimeoutError);
                }
                catch(const EverCloudException & e) {
                    data = e.exceptionData();
                }

                return new AsyncResult(QVariant(), data, ctx);
            }

            return new AsyncResult(value, {}, ctx);
        });

    AsyncResult * result = durableService->executeAsyncRequest(
        std::move(request),
        ctx);

    ValueFetcher valueFetcher;
    QObject::connect(result, &AsyncResult::finished,
                     &valueFetcher, &ValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(&valueFetcher, &ValueFetcher::finished,
                     &loop, &QEventLoop::quit);
    loop.exec();

    QVERIFY(serviceCallCounter == maxServiceCallCounter);
    QVERIFY(valueFetcher.m_value == value);
    QVERIFY(!valueFetcher.m_exceptionData);
}

void DurableServiceTester::shouldNotRetrySyncServiceCallMoreThanMaxTimes()
{
    auto durableService = newDurableService();

    int serviceCallCounter = 0;
    int maxServiceCallCounter = 3;

    auto ctx = newRequestContext(
        QString(),
        DEFAULT_REQUEST_TIMEOUT_MSEC,
        DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_INCREASE,
        DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
        maxServiceCallCounter);

    IDurableService::SyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> IDurableService::SyncResult {
            Q_ASSERT(ctx);
            Q_ASSERT(ctx->maxRequestRetryCount() == maxServiceCallCounter);

            ++serviceCallCounter;
            EverCloudExceptionDataPtr data;
            try {
                throw NetworkException(QNetworkReply::TimeoutError);
            }
            catch(const EverCloudException & e) {
                data = e.exceptionData();
            }

            return {{}, data};
        });

    auto result = durableService->executeSyncRequest(std::move(request), ctx);

    QVERIFY(serviceCallCounter == maxServiceCallCounter);
    QVERIFY(!result.first.isValid());
    QVERIFY(result.second.get() != nullptr);

    bool exceptionCaught = false;
    try {
        result.second->throwException();
    }
    catch(const NetworkException & e) {
        exceptionCaught = true;
        QVERIFY(e.type() == QNetworkReply::TimeoutError);
    }
    QVERIFY(exceptionCaught);
}

void DurableServiceTester::shouldNotRetryAsyncServiceCallMoreThanMaxTimes()
{
    auto durableService = newDurableService();

    int serviceCallCounter = 0;
    int maxServiceCallCounter = 3;

    auto ctx = newRequestContext(
        QString(),
        DEFAULT_REQUEST_TIMEOUT_MSEC,
        DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_INCREASE,
        DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
        maxServiceCallCounter);

    IDurableService::AsyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> AsyncResult* {
            Q_ASSERT(ctx);
            Q_ASSERT(ctx->maxRequestRetryCount() == maxServiceCallCounter);

            ++serviceCallCounter;
            EverCloudExceptionDataPtr data;
            try {
                throw NetworkException(QNetworkReply::TimeoutError);
            }
            catch(const EverCloudException & e) {
                data = e.exceptionData();
            }

            return new AsyncResult(QVariant(), data, ctx);
        });

    AsyncResult * result = durableService->executeAsyncRequest(
        std::move(request),
        ctx);

    ValueFetcher valueFetcher;
    QObject::connect(result, &AsyncResult::finished,
                     &valueFetcher, &ValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(&valueFetcher, &ValueFetcher::finished,
                     &loop, &QEventLoop::quit);
    loop.exec();

    QVERIFY(serviceCallCounter == maxServiceCallCounter);
    QVERIFY(!valueFetcher.m_value.isValid());
    QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);

    bool exceptionCaught = false;
    try {
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const NetworkException & e) {
        exceptionCaught = true;
        QVERIFY(e.type() == QNetworkReply::TimeoutError);
    }
    QVERIFY(exceptionCaught);
}

void DurableServiceTester::shouldNotRetrySyncServiceCallInCaseOfUnretriableError()
{
    auto durableService = newDurableService();

    int serviceCallCounter = 0;
    int maxServiceCallCounter = 3;

    auto ctx = newRequestContext(
        QString(),
        DEFAULT_REQUEST_TIMEOUT_MSEC,
        DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_INCREASE,
        DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
        maxServiceCallCounter);

    IDurableService::SyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> IDurableService::SyncResult {
            Q_ASSERT(ctx);
            Q_ASSERT(ctx->maxRequestRetryCount() == maxServiceCallCounter);

            ++serviceCallCounter;
            EverCloudExceptionDataPtr data;
            try {
                EDAMUserException e;
                e.errorCode = EDAMErrorCode::AUTH_EXPIRED;
                throw e;
            }
            catch(const EverCloudException & e) {
                data = e.exceptionData();
            }

            return {{}, data};
        });

    auto result = durableService->executeSyncRequest(std::move(request), ctx);

    QVERIFY(serviceCallCounter == 1);
    QVERIFY(!result.first.isValid());
    QVERIFY(result.second.get() != nullptr);

    bool exceptionCaught = false;
    try {
        result.second->throwException();
    }
    catch(const EDAMUserException & e) {
        exceptionCaught = true;
        QVERIFY(e.errorCode == EDAMErrorCode::AUTH_EXPIRED);
    }
    QVERIFY(exceptionCaught);
}

void DurableServiceTester::shouldNotRetryAsyncServiceCallInCaseOfUnretriableError()
{
    auto durableService = newDurableService();

    int serviceCallCounter = 0;
    int maxServiceCallCounter = 3;

    auto ctx = newRequestContext(
        QString(),
        DEFAULT_REQUEST_TIMEOUT_MSEC,
        DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_INCREASE,
        DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
        maxServiceCallCounter);

    IDurableService::AsyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> AsyncResult* {
            Q_ASSERT(ctx);
            Q_ASSERT(ctx->maxRequestRetryCount() == maxServiceCallCounter);

            ++serviceCallCounter;
            EverCloudExceptionDataPtr data;
            try {
                EDAMUserException e;
                e.errorCode = EDAMErrorCode::AUTH_EXPIRED;
                throw e;
            }
            catch(const EverCloudException & e) {
                data = e.exceptionData();
            }

            return new AsyncResult(QVariant(), data, ctx);
        });

    AsyncResult * result = durableService->executeAsyncRequest(
        std::move(request),
        ctx);

    ValueFetcher valueFetcher;
    QObject::connect(result, &AsyncResult::finished,
                     &valueFetcher, &ValueFetcher::onFinished);

    QEventLoop loop;
    QObject::connect(&valueFetcher, &ValueFetcher::finished,
                     &loop, &QEventLoop::quit);
    loop.exec();

    QVERIFY(serviceCallCounter == 1);
    QVERIFY(!valueFetcher.m_value.isValid());
    QVERIFY(valueFetcher.m_exceptionData.get() != nullptr);

    bool exceptionCaught = false;
    try {
        valueFetcher.m_exceptionData->throwException();
    }
    catch(const EDAMUserException & e) {
        exceptionCaught = true;
        QVERIFY(e.errorCode == EDAMErrorCode::AUTH_EXPIRED);
    }
    QVERIFY(exceptionCaught);
}

} // namespace qevercloud

#include <TestDurableService.moc>
