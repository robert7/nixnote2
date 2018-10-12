#include <QtTest/QtTest>
#include <QObject>
#include <QString>

#include "tests.h"
#include "../src/html/enmlformatter.h"

Tests::Tests(QObject *parent) :
    QObject(parent)
{

}


void Tests::enmlFormat()
{
    //QString str = "Hello";
    //QCOMPARE(str.toUpper(), QString("HELLO"));

    bool guiAvailable = true;
    QHash<QString, QPair<QString, QString> > passwordSafe;
    QString cryptoJarPath;
    EnmlFormatter formatter("aa", guiAvailable, passwordSafe, cryptoJarPath);
    formatter.rebuildNoteEnml();
    formatter.getContent();
}

QTEST_MAIN(Tests)
