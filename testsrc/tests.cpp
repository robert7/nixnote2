#include <QtTest/QtTest>
#include <QObject>
#include <QString>

#include "tests.h"
#include "../src/html/enmlformatter.h"
#include "../src/logger/qslog.h"
#include "../src/logger/qslogdest.h"

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
    // raw string literals: https://en.cppreference.com/w/cpp/language/string_literal
    {
        // defined attribute is NOT deleted
        QString src(R"R(<div style="something: 1">aa5</div>)R");
        QString result(R"R(<div style="something: 1">aa5</div>)R");
        QCOMPARE(formatToEnml(src), addEnmlEnvelope(result));
    }
    {
        // undefined attributes are deleted
        QString src(R"R(<div style="something: 1" abcd="something: 1" lid="12" onclick="alert('hey'\)">aa6</div>)R");
        QString result(R"R(<div style="something: 1">aa6</div>)R");
        QCOMPARE(formatToEnml(src), addEnmlEnvelope(result));
    }
}

QT_BEGIN_NAMESPACE
QTEST_ADD_GPU_BLACKLIST_SUPPORT_DEFS

QT_END_NAMESPACE
int main(int argc, char *argv[]) {
    // Setup the QLOG functions for debugging & messages
    // we need to do it at very beginning, else we lose the startup messages
    QsLogging::Logger &logger = QsLogging::Logger::instance();
    // at very beginning we starting with info level to get basic startup info
    // log level is later adjusted by settings

    logger.setLoggingLevel(QsLogging::DebugLevel);

    QsLogging::DestinationPtr debugDestination(
            QsLogging::DestinationFactory::MakeDebugOutputDestination());
    logger.addDestination(debugDestination.get());

    QApplication app(argc, argv);
    app.setAttribute(Qt::AA_Use96Dpi, true);

    QTEST_DISABLE_KEYPAD_NAVIGATION
    QTEST_ADD_GPU_BLACKLIST_SUPPORT

    Tests tc;

    QTEST_SET_MAIN_SOURCE_PATH
    return QTest::qExec(&tc, argc, argv);
}
