#ifndef LENSERESULTS_H
#define LENSERESULTS_H

#include <QObject>
#include "src/qevercloud/QEverCloud/headers/QEverCloud.h"

class LenseResults : public QObject
{
    Q_OBJECT
public:
    explicit LenseResults(QObject *parent = 0);
    Note note;

signals:

public slots:

};

#endif // LENSERESULTS_H
