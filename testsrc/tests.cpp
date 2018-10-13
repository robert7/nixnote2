#include <QtTest/QtTest>
#include <QObject>
#include <QString>

#include "tests.h"
#include "../src/html/enmlformatter.h"

Tests::Tests(QObject *parent) :
        QObject(parent) {

}


QString Tests::formatToEnml(QString source) {
    bool guiAvailable = true;
    QHash<QString, QPair<QString, QString> > passwordSafe;
    QString cryptoJarPath;
    EnmlFormatter formatter(source, guiAvailable, passwordSafe, cryptoJarPath);
    formatter.rebuildNoteEnml();
    return formatter.getContent().replace("\n", "");
}

QString Tests::addEnmlEnvelope(QString source) {
    return QStringLiteral(
                   "<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE en-note SYSTEM 'http://xml.evernote.com/pub/enml2.dtd'><en-note>")
           + source
           + QStringLiteral("</en-note>");
}

void Tests::enmlBasicTest() {
    QString src1("aa");
    QCOMPARE(formatToEnml(src1), addEnmlEnvelope(src1));

    QString src2("<div>aa</div>");
    QCOMPARE(formatToEnml(src2), addEnmlEnvelope(src2));

    QString src3("<html><head><title>xx</title></head><body><div>aa</div></body></html>");
    QString src3r("<div>aa</div>");
    QCOMPARE(formatToEnml(src3), addEnmlEnvelope(src3r));
}

void Tests::enmlTidyTest() {
    {
        QString src("<div>aa1</xdiv>");
        QString result("<div>aa1</div>");
        QCOMPARE(formatToEnml(src), addEnmlEnvelope(result));
    }
    {
        QString src("aa2</div>");
        QString result("aa2");
        QCOMPARE(formatToEnml(src), addEnmlEnvelope(result));
    }
    {
        QString src("<html>aa3</div>");
        QString result("aa3");
        QCOMPARE(formatToEnml(src), addEnmlEnvelope(result));
    }
    {
        QString src("<table <tr>aa4</td>");
        QString result("aa4");
        QCOMPARE(formatToEnml(src), addEnmlEnvelope(result));
    }
    {
        // defined attribute is NOT deleted
        QString src(R"(<div style="something: 1">aa5</div>)");
        QString result(R"(<div style="something: 1">aa5</div>)");
        QCOMPARE(formatToEnml(src), addEnmlEnvelope(result));
    }
    {
        // undefined attribute is deleted
        QString src(R"(<div style="something: 1" abcd="something: 1">aa6</div>)");
        QString result(R"(<div style="something: 1">aa6</div>)");
        QCOMPARE(formatToEnml(src), addEnmlEnvelope(result));
    }
}

QTEST_MAIN(Tests)
