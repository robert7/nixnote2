#ifndef NIXNOTE2_TESTS_H
#define NIXNOTE2_TESTS_H

#include <QObject>

class Tests: public QObject
{
    Q_OBJECT

private:
    QString formatToEnml(QString source);
    QString addEnmlEnvelope(QString source, QString resources = QString(), QString bodyAttrs = QString());
    QString readFile(QString file);
    QString getHtmlWithStrippedHtmlComments(QString source);

public:
    Q_INVOKABLE explicit Tests(QObject *parent=Q_NULLPTR);
    virtual ~Tests() {};

// comment out to debug the only the last test
private slots:
    void enmlBasicTest();
    void enmlNixnoteTodoTest();
    void enmlNixnoteImageTest();
    void enmlNixnoteObjectTest();
    void enmlNixnoteEncryptTest();
    void enmlNixnoteTableTest();
    void enmlHtml5TagsTest();
    void latexStringUtilTest();
    void enmlNixnoteLinkTest2();
    void enmlHtmlFileTest();
    void enmlBasicRecursiveTest();
    void enmlNixnoteLinkTest();
    void enmlTidyTest();
    void enmlHtmlCommentTest();
    void enmlHtmlMapTest();

private slots:
    void enmlHtmlSvgTest();
};

#endif // NIXNOTE2_TESTS_H
