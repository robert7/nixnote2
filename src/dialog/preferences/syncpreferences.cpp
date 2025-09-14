/*********************************************************************************
NixNote - An open-source client for the Evernote service.
Copyright (C) 2013 Randy Baumgarte

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

#include "syncpreferences.h"
#include "src/global.h"

#include <QGroupBox>

extern Global global;

SyncPreferences::SyncPreferences(QWidget *parent) :
    QWidget(parent)
{
    this->setFont(global.getGuiFont(font()));
    QGridLayout *mainLayout = new QGridLayout(this);
    setLayout(mainLayout);

    syncAutomatically = new QCheckBox(tr("Sync automatically"), this);
    syncAutomatically->setChecked(true);

    syncInterval = new QComboBox(this);
    syncInterval->addItem(tr("Every 15 minutes"), 15);
    syncInterval->addItem(tr("Every 30 minutes"), 30);
    syncInterval->addItem(tr("Every hour"), 60);
    syncInterval->addItem(tr("Every day"), 1440);

    syncOnStartup = new QCheckBox(tr("Sync on startup"), this);
    //syncOnStartup->setEnabled(false);
    syncOnShutdown = new QCheckBox(tr("Sync on shutdown"),this);
    //syncOnShutdown->setEnabled(false);
    enableSyncNotifications = new QCheckBox(tr("Enable sync notifications"), this);
    showGoodSyncMessagesInTray = new QCheckBox(tr("Show successful syncs"), this);
    apiRateRestart = new QCheckBox(tr("Restart sync on API limit (experimental)"), this);
    connectionClosedRestart = new QCheckBox(tr("Restart sync on connection closed (experimental)"), this);
    QLabel *threadNumberLabel = new QLabel(tr("The number of downloading threads(1~50)"), this);
    threadNumber = new QSpinBox(this);
    threadNumber->setMinimum(1);
    threadNumber->setMaximum(50);

    enableProxy = new QCheckBox(tr("Enable Proxy*"), this);
    enableSocks5 = new QCheckBox(tr("Enable Socks5"),this);
    QLabel *hostLabel = new QLabel(tr("Proxy Hostname"), this);
    QLabel *portLabel = new QLabel(tr("Proxy Port"), this);
    QLabel *userLabel = new QLabel(tr("Proxy Username"), this);
    QLabel *passwordLabel = new QLabel(tr("Proxy Password"),this);
    QLabel *restartLabel = new QLabel(tr("*Note: Restart required"),this);

    host = new QLineEdit(this);
    port = new QLineEdit(this);
    userId = new QLineEdit(this);
    password = new QLineEdit(this);

    enableProxy->setChecked(global.isProxyEnabled());
    enableSocks5->setChecked(global.isSocks5Enabled());
    host->setText(global.getProxyHost());
    port->setText(QString::number(global.getProxyPort()));
    port->setInputMask("00000");
    userId->setText(global.getProxyUserid());
    password->setText(global.getProxyPassword());
    password->setEchoMode(QLineEdit::Password);

    popupOnSyncError = new QCheckBox(tr("Popup message on sync errors."),0);
    popupOnSyncError->setChecked(global.popupOnSyncError());

    mainLayout->addWidget(enableSyncNotifications,0,0);
    mainLayout->addWidget(showGoodSyncMessagesInTray, 0,1);
    mainLayout->addWidget(syncOnStartup,1,0);
    mainLayout->addWidget(popupOnSyncError, 1,1);
    mainLayout->addWidget(syncOnShutdown,2,0);
    mainLayout->addWidget(syncAutomatically,3,0);
    mainLayout->addWidget(syncInterval, 3,1);
    mainLayout->addWidget(apiRateRestart, 4,0);
    mainLayout->addWidget(connectionClosedRestart, 4,1);

    mainLayout->addWidget(enableProxy,5,0);
    mainLayout->addWidget(enableSocks5,5,1);
    mainLayout->addWidget(hostLabel,6,0);
    mainLayout->addWidget(host, 6,1);
    mainLayout->addWidget(portLabel,7,0);
    mainLayout->addWidget(port,7,1);
    mainLayout->addWidget(userLabel, 8,0);
    mainLayout->addWidget(userId,8,1);
    mainLayout->addWidget(passwordLabel,9,0);
    mainLayout->addWidget(password,9,1);
    mainLayout->addWidget(restartLabel,10,0);
    mainLayout->addWidget(threadNumberLabel, 11,0);
    mainLayout->addWidget(threadNumber, 11,1);
    mainLayout->setAlignment(Qt::AlignTop);

    global.settings->beginGroup(INI_GROUP_SYNC);
    int interval = global.settings->value("syncInterval", 15).toInt();
    int index = syncInterval->findData(interval);
    syncInterval->setCurrentIndex(index);
    syncAutomatically->setChecked(global.settings->value("syncAutomatically", true).toBool());
    syncOnShutdown->setChecked(global.settings->value("syncOnShutdown", false).toBool());
    syncOnStartup->setChecked(global.settings->value("syncOnStartup", true).toBool());
    enableSyncNotifications->setChecked(global.settings->value("enableNotification", true).toBool());
    showGoodSyncMessagesInTray->setChecked(global.showGoodSyncMessagesInTray);
    apiRateRestart->setChecked(global.settings->value("apiRateLimitAutoRestart", true).toBool());
    connectionClosedRestart->setChecked(global.settings->value("connectionClosedAutoRestart", false).toBool());
    threadNumber->setValue(global.settings->value("threadNumber", 5).toInt());

    global.settings->endGroup();
    global.showGoodSyncMessagesInTray = showGoodSyncMessagesInTray->isChecked();

    if (enableSyncNotifications->isChecked())
        showGoodSyncMessagesInTray->setEnabled(true);
    else
        showGoodSyncMessagesInTray->setEnabled(false);

    connect(syncAutomatically, SIGNAL(stateChanged(int)), this, SLOT(enableSyncStateChange()));
    connect(enableSyncNotifications, SIGNAL(toggled(bool)), this, SLOT(enableSuccessfulSyncMessagesInTray()));
    connect(enableProxy, SIGNAL(stateChanged(int)), this, SLOT(proxyCheckboxAltered(int)));
    if (!global.isProxyEnabled()) {
        proxyCheckboxAltered(Qt::Unchecked);
    }
}


SyncPreferences::~SyncPreferences() {
    delete syncInterval;
    delete syncOnShutdown;
    delete syncOnStartup;
    delete syncAutomatically;
}


void SyncPreferences::enableSyncStateChange() {
    if (syncAutomatically->isChecked())
        syncInterval->setEnabled(true);
    else
        syncInterval->setEnabled(false);
}

void SyncPreferences::enableSuccessfulSyncMessagesInTray() {
    if (this->enableSyncNotifications->isChecked())
        this->showGoodSyncMessagesInTray->setEnabled(true);
    else
        this->showGoodSyncMessagesInTray->setEnabled(false);
}

int SyncPreferences::getSyncInterval() {
    int index = syncInterval->currentIndex();
    return syncInterval->itemData(index).toInt();
}


void SyncPreferences::saveValues() {
    global.settings->beginGroup(INI_GROUP_SYNC);
    global.settings->setValue("syncAutomatically", syncAutomatically->isChecked());
    global.settings->setValue("syncOnShutdown", syncOnShutdown->isChecked());
    global.settings->setValue("syncOnStartup", syncOnStartup->isChecked());
    global.settings->setValue("enableNotification", enableSyncNotifications->isChecked());
    global.settings->setValue("syncInterval", getSyncInterval());
    global.settings->setValue("showGoodSyncMessagesInTray", showGoodSyncMessagesInTray ->isChecked());
    global.settings->setValue("apiRateLimitAutoRestart", apiRateRestart ->isChecked());
    global.settings->setValue("connectionClosedAutoRestart", connectionClosedRestart->isChecked());
    global.settings->setValue("threadNumber", threadNumber->value());
    global.settings->endGroup();

    global.showGoodSyncMessagesInTray = showGoodSyncMessagesInTray->isChecked();

    global.setProxyEnabled(enableProxy->isChecked());
    global.setSocks5Enabled(enableSocks5->isChecked());
    global.setProxyHost(host->text().trimmed());
    global.setProxyPort(port->text().toInt());
    global.setProxyUserid(userId->text().trimmed());
    global.setProxyPassword(password->text().trimmed());
    global.setPopupOnSyncError(this->popupOnSyncError->isChecked());
}



void SyncPreferences::proxyCheckboxAltered(int state) {
    bool value = false;
    if (state == Qt::Checked)
        value = true;
    enableSocks5->setEnabled(value);
    host->setEnabled(value);
    port->setEnabled(value);
    userId->setEnabled(value);
    password->setEnabled(value);
}
