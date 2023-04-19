/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "TestOptional.h"

#include <Optional.h>
#include <generated/Types.h>

#include <QtTest/QtTest>

namespace qevercloud {

OptionalTester::OptionalTester(QObject * parent) :
    QObject(parent)
{}

void OptionalTester::shouldDetectValueNotSet()
{
    Optional<int> i;
    QVERIFY(!i.isSet());
}

void OptionalTester::shouldClearValue()
{
    Optional<int> i;
    i = 10;
    QVERIFY(i.isSet());
    QVERIFY(i == 10);
    i.clear();
    QVERIFY(!i.isSet());
}

void OptionalTester::shouldDetectExternalValueChange()
{
    Optional<int> i;
    i.init().ref() = 11;
    QVERIFY(i == 11);
    static_cast<int&>(i) = 12;
    QVERIFY(i == 12);
}

void OptionalTester::shouldCastToIntFromAscii()
{
    const Optional<int> ic = ' ';
    QVERIFY(ic == 32);
}

void OptionalTester::shouldInitValue()
{
    Optional<int> i;
    i.init();
    QVERIFY2(i.isSet() && i == int(), "i.isSet() && i == int()");
}

void OptionalTester::shouldThrowExceptionOnAttemptToReferenceUnsetValue()
{
    Optional<int> i;
    bool exceptionThrown = false;
    try {
        int a = i;
    }
    catch(const EverCloudException &) {
        exceptionThrown = true;
    }
    QVERIFY(exceptionThrown);
}

void OptionalTester::shouldAssignFromOtherOptionals()
{
    Optional<int> y, k = 10;
    y = k;
    QVERIFY(y == 10);
    Optional<double> d;
    d = y;
    QVERIFY(d == 10.0);
    d = ' ';
    QVERIFY(d == 32.0);
}

void OptionalTester::shouldProcessEqualityChecks()
{
    Optional<int> y = 10;
    Optional<int> d = 32;

    Optional<double> d2(y), d3(' '), d4(d);
    QVERIFY(d2 == 10.0);
    QVERIFY(d3 == 32.0);
    QVERIFY(d4.ref() == d.ref());

    Optional<int> oi;
    Optional<double> od;
    QVERIFY(oi.isEqual(od)); oi = 1;
    QVERIFY(!oi.isEqual(od));
    od = 1;
    QVERIFY(oi.isEqual(od));
    oi = 2;
    QVERIFY(!oi.isEqual(od));
}

void OptionalTester::shouldProcessStructEqualityChecks()
{
    Note n1, n2;
    QVERIFY(n1 == n2);
    n1.guid = QStringLiteral("12345");
    QVERIFY(n1 != n2);
    n2.guid = n1.guid;
    QVERIFY(n1 == n2);
}

void OptionalTester::shouldProcessValueMoves()
{
    Optional<int> oi1, oi2;
    oi1 = 10;
    oi2 = std::move(oi1);
    QVERIFY(oi2 == 10);
    QVERIFY(!oi1.isSet());

    Note note1, note2;
    note1.guid = QStringLiteral("12345");
    QVERIFY(note1.guid.isSet());
    QVERIFY(!note2.guid.isSet());
    note2 = std::move(note1);
    QVERIFY(note2.guid.isSet());
    QVERIFY(!note1.guid.isSet());
}

void OptionalTester::shouldHandleZeroTimestamp()
{
    Optional<Timestamp> t;
    t = Timestamp(0);
    QVERIFY(t.ref() == Timestamp(0));
}

} // namespace qevercloud
