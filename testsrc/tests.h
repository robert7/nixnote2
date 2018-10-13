#ifndef NIXNOTE2_TESTS_H
#define NIXNOTE2_TESTS_H

#include <QObject>

class Tests: public QObject
{
    Q_OBJECT

private:
    QString formatToEnml(QString source);
    QString addEnmlEnvelope(QString source);

public:
    Q_INVOKABLE explicit Tests(QObject *parent=Q_NULLPTR);
    virtual ~Tests() {};

private slots:
    void enmlBasicTest();
    void enmlTidyTest();
    void enmlNixnoteSpecialsTest();
};

#endif // NIXNOTE2_TESTS_H
