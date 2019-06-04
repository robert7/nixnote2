#include <QString>
#include <QtTest>
#include <QDebug>

#ifdef QEVERCLOUD_SHARED_LIBRARY
#undef QEVERCLOUD_SHARED_LIBRARY
#endif

#ifdef QEVERCLOUD_STATIC_LIBRARY
#undef QEVERCLOUD_STATIC_LIBRARY
#endif

#include <QEverCloud.h>
#include <utility>

class TestEverCloudTest: public QObject
{
    Q_OBJECT
public:
    TestEverCloudTest();

private Q_SLOTS:
    void testOptional();
};

TestEverCloudTest::TestEverCloudTest()
{}

using namespace qevercloud;

void TestEverCloudTest::testOptional()
{
    Optional<int> i;
    QVERIFY(!i.isSet());

    i = 10;
    QVERIFY(i.isSet());
    QVERIFY(i == 10);
    i.clear();
    QVERIFY(!i.isSet());

    i.init().ref() = 11;
    QVERIFY(i == 11);
    static_cast<int&>(i) = 12;
    QVERIFY(i == 12);

    const Optional<int> ic = ' ';
    QVERIFY(ic == 32);

    i.clear();
    i.init();
    QVERIFY2(i.isSet() && i == int(), "i.isSet() && i == int()");

    i.clear();
    bool exception = false;
    try {
        qDebug() << i;
    }
    catch(const EverCloudException &) {
        exception = true;
    }
    QVERIFY(exception);

    Optional<int> y, k = 10;
    y = k;
    QVERIFY(y == 10);
    Optional<double> d;
    d = y;
    QVERIFY(d == 10);
    d = ' ';
    QVERIFY(d == 32);

    Optional<double> d2(y), d3(' '), d4(d);
    QVERIFY(d2 == 10);
    QVERIFY(d3 == 32);
    QVERIFY(d4 == d);

    Optional<int> oi;
    Optional<double> od;
    QVERIFY(oi.isEqual(od)); oi = 1;
    QVERIFY(!oi.isEqual(od));
    od = 1;
    QVERIFY(oi.isEqual(od));
    oi = 2;
    QVERIFY(!oi.isEqual(od));

    Note n1, n2;
    QVERIFY(n1 == n2);
    n1.guid = QStringLiteral("12345");
    QVERIFY(n1 != n2);
    n2.guid = n1.guid;
    QVERIFY(n1 == n2);

#if defined(Q_COMPILER_RVALUE_REFS) && !defined(_MSC_VER)
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
#endif

    Optional<Timestamp> t;
    t = 0;
    t = Timestamp(0);
    QVERIFY(t.ref() == Timestamp(0));
}

#if QT_VERSION < QT_VERSION_CHECK(5, 6, 0)
#ifdef QT_GUI_LIB
#undef QT_GUI_LIB
QTEST_MAIN(TestEverCloudTest)
#define QT_GUI_LIB
#endif // QT_GUI_LIB
#else
QTEST_GUILESS_MAIN(TestEverCloudTest)
#endif

#include "TestQEverCloud.moc"
