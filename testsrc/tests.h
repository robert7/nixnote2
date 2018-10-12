#ifndef NIXNOTE2_TESTS_H
#define NIXNOTE2_TESTS_H

#include <QObject>

class Tests: public QObject
{
    Q_OBJECT

public:

    Q_INVOKABLE explicit Tests(QObject *parent=Q_NULLPTR);
    virtual ~Tests() {};

private slots:
    void toUpper();
};

#endif // NIXNOTE2_TESTS_H
