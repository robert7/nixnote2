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

#include "aboutdialog.h"
#include <QWebEngineView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "src/global.h"

extern Global global;

AboutDialog::AboutDialog(QDialog *parent) :
    QDialog(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout();
    this->setLayout(mainLayout);
    QWebEngineView *page = new QWebEngineView();
    QPushButton *okButton = new QPushButton();
    okButton->setText(tr("OK"));
    mainLayout->addWidget(page);
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QSpacerItem *spacer1 = new QSpacerItem(100000, 1, QSizePolicy::Maximum);
    QSpacerItem *spacer2 = new QSpacerItem(100000, 1, QSizePolicy::Maximum);
    buttonLayout->addSpacerItem(spacer1);
    buttonLayout->addWidget(okButton);
    buttonLayout->addSpacerItem(spacer2);
    mainLayout->addLayout(buttonLayout);
    this->setLayout(mainLayout);
    const QString programDataDir = global.fileManager.getProgramDataDir();
    QString versionStr = tr("Version: ") + global.fileManager.getProgramVersionPrintable();

    QString aboutFileName = programDataDir + "help/about.html";
    QString data = global.fileManager.readFile(aboutFileName);

    QString translationInformation = tr("Note to translators: For translation credit, change this message to your name & contact information and it will appear in the About dialog box. HTML Formatting is available.");
    QString translationStaticInformation = "Note to translators: For translation credit, change this message to your name & contact information and it will appear in the About dialog box. HTML Formatting is available.";
    if (translationInformation == translationStaticInformation) {
        data.replace("__TRANSLATION__", "");
    } else {
        data = data.replace("__TRANSLATION__", translationInformation);
    }

    data.replace("__VERSION__", versionStr);
#ifndef _WIN32
    data = data.replace("__LOGO__", "file://" + global.fileManager.getImageDirPath("") + "splash_logo.png");
#else
    data = data.replace("__LOGO__", "file:///" + global.fileManager.getImageDirPath("") + "splash_logo.png");
#endif

    page->setHtml(data);

    connect(okButton, SIGNAL(clicked()), this, SLOT(close()));
    this->resize(600, 500);
    this->setFont(global.getGuiFont(font()));
}

