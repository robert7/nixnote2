#include <QtTest/QtTest>
#include <QObject>
#include <QString>

#include "tests.h"

Tests::Tests(QObject *parent) :
    QObject(parent)
{

}


void Tests::toUpper()
{
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

QTEST_MAIN(Tests)
