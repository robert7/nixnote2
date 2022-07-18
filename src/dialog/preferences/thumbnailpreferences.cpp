#include "thumbnailpreferences.h"
#include "src/global.h"

extern Global global;


ThumbnailPreferences::ThumbnailPreferences(QWidget *parent) : QWidget(parent)
{
    disableThumbnail = new QCheckBox();
    disableLabel = new QLabel(tr("Disable thumbnail generation"));

    mainLayout = new QGridLayout(this);
    mainLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    setLayout(mainLayout);

    mainLayout->addWidget(disableLabel, 0,0);
    mainLayout->addWidget(disableThumbnail, 0,1);

    disableThumbnail->setChecked(global.disableThumbnails);
}



void ThumbnailPreferences::saveValues() {

    global.settings->beginGroup(INI_GROUP_THUMBNAIL);
    global.settings->setValue("disabled", disableThumbnail->isChecked());
    global.settings->endGroup();

    global.disableThumbnails = disableThumbnail->isChecked();
}
