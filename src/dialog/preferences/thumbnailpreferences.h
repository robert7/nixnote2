#ifndef THUMBNAILPREFERENCES_H
#define THUMBNAILPREFERENCES_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QCheckBox>


class ThumbnailPreferences : public QWidget
{
    Q_OBJECT
private:
    QGridLayout *mainLayout;
    QLabel *disableLabel;
    QCheckBox *disableThumbnail;

public:
    explicit ThumbnailPreferences(QWidget *parent = 0);
    void saveValues();

signals:

public slots:
};

#endif // THUMBNAILPREFERENCES_H
