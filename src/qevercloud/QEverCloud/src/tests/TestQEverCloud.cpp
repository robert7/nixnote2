/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "MessageHandler.h"
#include "TestDurableService.h"
#include "TestOptional.h"
#include "generated/TestNoteStore.h"
#include "generated/TestUserStore.h"

#include <QEverCloud.h>

#include <QCoreApplication>
#include <QtTest/QtTest>

#include <cstdlib>

using namespace qevercloud;

int main(int argc, char *argv[])
{
    // Fixed seed for rand() calls
    std::srand(1575003691);

    qInstallMessageHandler(testMessageOutput);
    QCoreApplication app(argc, argv);

    initializeQEverCloud();

    int res = 0;
#define RUN_TESTS(tester)                                                      \
    res = QTest::qExec(new tester);                                            \
    if (res != 0) {                                                            \
        return res;                                                            \
    }                                                                          \
// RUN_TESTS

    RUN_TESTS(DurableServiceTester)
    RUN_TESTS(OptionalTester)
    RUN_TESTS(NoteStoreTester)
    RUN_TESTS(UserStoreTester)

    return 0;
}
