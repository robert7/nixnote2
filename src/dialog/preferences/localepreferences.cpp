/*********************************************************************************
NixNote - An open-source client for the Evernote service.
Copyright (C) 2015 Randy Baumgarte

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
***********************************************************************************/


#include "localepreferences.h"
#include "src/global.h"

#include <QDate>

extern Global global;

LocalePreferences::LocalePreferences(QWidget *parent) :
    QWidget(parent)
{
    mainLayout = new QGridLayout(this);
    mainLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    setLayout(mainLayout);
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    translationLabel = new QLabel("Language *");
    translationLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    translationCombo = new QComboBox(this);
    translationCombo->addItem(tr("<System Default>"), QLocale::system().name());
    translationCombo->addItem(tr("Catalan"), "ca");
    translationCombo->addItem(tr("Czech"), "cs_CZ");
    translationCombo->addItem(tr("Danish"), "da");
    translationCombo->addItem(tr("German"), "de");
    translationCombo->addItem(tr("English (US)"), "en_US");
    translationCombo->addItem(tr("English (UK)"), "en_GB");
    translationCombo->addItem(tr("Spanish"), "es");
    translationCombo->addItem(tr("French"), "fr");
    translationCombo->addItem(tr("Japanese"), "ja");
    translationCombo->addItem(tr("Polish"), "pl");
    translationCombo->addItem(tr("Portugese"), "pt");
    translationCombo->addItem(tr("Russian"), "ru");
    translationCombo->addItem(tr("Slovak"), "sk");
    translationCombo->addItem(tr("Chinese"), "zh_CN");
    translationCombo->addItem(tr("Chinese (Taiwan)"), "zh_TW");
    QLabel *restartLabel = new QLabel(tr("*Note: Restart required"),this);


    dateFormatLabel = new QLabel(tr("Date Format"), this);
    dateFormatLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    dateFormatCombo = new QComboBox(this);
    const QStringList dateFormats = global.getDateFormats();
    for (int i = 0; i < dateFormats.size(); i++) {
        const QString fmt = dateFormats.at(i);
        dateFormatCombo->addItem(fmt + QStringLiteral(" - ") + date.toString(fmt), i + 1);
    }


    timeFormatLabel = new QLabel(tr("Time Format"), this);
    timeFormatLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    timeFormatCombo = new QComboBox(this);
    const QStringList timeFormats = global.getTimeFormats();
    for (int i = 0; i < timeFormats.size(); i++) {
        const QString fmt = timeFormats.at(i);
        timeFormatCombo->addItem(fmt + QStringLiteral(" - ") + time.toString(fmt), i + 1);
    }

    mainLayout->addWidget(translationLabel,0,0);
    mainLayout->addWidget(translationCombo,0,1);
    mainLayout->addWidget(dateFormatLabel,1,0);
    mainLayout->addWidget(dateFormatCombo,1,1);
    mainLayout->addWidget(timeFormatLabel,2,0);
    mainLayout->addWidget(timeFormatCombo,2,1);
    mainLayout->addWidget(restartLabel,3,0);

    global.settings->beginGroup(INI_GROUP_LOCALE);
    QString translationi = global.settings->value("translation", "").toString();
    int datei = global.settings->value("dateFormat", 1).toInt();
    int timei = global.settings->value("timeFormat", 1).toInt();
    global.settings->endGroup();

    int index = dateFormatCombo->findData(datei);
    dateFormatCombo->setCurrentIndex(index);

    index = timeFormatCombo->findData(timei);
    timeFormatCombo->setCurrentIndex(index);

    index = translationCombo->findData(translationi);
    translationCombo->setCurrentIndex(index);
    this->setFont(global.getGuiFont(font()));
}


LocalePreferences::~LocalePreferences() {
}



void LocalePreferences::saveValues() {
    int dateFormat = getDateFormatNo();
    int timeFormat = getTimeFormatNo();
    QString translation = getTranslation();

    global.settings->beginGroup(INI_GROUP_LOCALE);
    global.settings->setValue("translation", translation);
    global.settings->setValue("dateFormat", dateFormat);
    global.settings->setValue("timeFormat", timeFormat);
    global.settings->endGroup();


    global.setDateFormat(dateFormat);
    global.setTimeFormat(timeFormat);
}




QString LocalePreferences::getTranslation() {
    int index = translationCombo->currentIndex();
    return translationCombo->itemData(index).toString();
}


int LocalePreferences::getDateFormatNo() {
    int index = dateFormatCombo->currentIndex();
    return dateFormatCombo->itemData(index).toInt();
}



int LocalePreferences::getTimeFormatNo() {
    int index = timeFormatCombo->currentIndex();
    return timeFormatCombo->itemData(index).toInt();
}
