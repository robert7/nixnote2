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


#include "crossmemorymapper.h"
#include <iostream>
#include "src/logger/qslog.h"

CrossMemoryMapper::CrossMemoryMapper(QObject *parent) :
    QObject(parent) {
}

CrossMemoryMapper::CrossMemoryMapper(QString &key, QObject *parent) :
    QObject(parent) {
    this->setKey(key);
    buffer = nullptr;
}


void CrossMemoryMapper::setKey(QString &key) {
    this->key = key;
    sharedMemory = new QSharedMemory(key, this);
}


CrossMemoryMapper::~CrossMemoryMapper() {
    if (buffer != nullptr)
        free(buffer);
    if (key != "" && sharedMemory->isAttached())
        sharedMemory->detach();
}

QSharedMemory::SharedMemoryError CrossMemoryMapper::allocate(int size) {
    QLOG_DEBUG() << "Shared memory segment is about to be allocaed; size=" << size;
    if (key == "") {
        QLOG_ERROR() << "Shared memory segment can't be created: no key!";
        return QSharedMemory::SharedMemoryError::UnknownError;
    }
    if (!sharedMemory->create(size, QSharedMemory::ReadWrite)) {
        QSharedMemory::SharedMemoryError error = sharedMemory->error();
        QLOG_WARN() << "Shared memory segment failed to allocate, instance key=" << key << "; error=" << error
            << ", " << sharedMemory->errorString();
        return error;
    }
    buffer = (char *) malloc(static_cast<size_t>(getSharedMemorySize()));
    QLOG_INFO() << "Shared memory segment allocated, instance key: " << key;
    return QSharedMemory::SharedMemoryError::NoError;
}


void CrossMemoryMapper::clearMemory() {
    lock();
    memset(sharedMemory->data(), 0, static_cast<size_t>(getSharedMemorySize()));
    unlock();
}


bool CrossMemoryMapper::lock() {
    if (sharedMemory == nullptr)
        return false;
    return sharedMemory->lock();
}


bool CrossMemoryMapper::unlock() {
    if (sharedMemory == nullptr)
        return false;
    return sharedMemory->unlock();
}


bool CrossMemoryMapper::attach() {
    if (key == "") {
        QLOG_ERROR() << "Shared memory segment can't be attached: no key!";
        return false;
    }
    if (sharedMemory == nullptr) {
        QLOG_ERROR() << "Shared memory segment can't be attached: nullptr!";
        return false;
    }
    if (buffer == nullptr) {
        buffer = (char *) malloc(getSharedMemorySize());
    }
    bool ret = sharedMemory->attach();
    QLOG_DEBUG() << "Shared memory segment attach, instance key: " << key << ", result: " << ret;
    return ret;
}


bool CrossMemoryMapper::detach() {
    sharedMemory->unlock();
    bool ret = sharedMemory->detach();
    QLOG_DEBUG() << "Shared memory segment detach, instance key: " << key << ", result: " << ret;
    return ret;
}


QByteArray CrossMemoryMapper::read() {
    if (!isAttached())
        attach();
    if (sharedMemory == nullptr || !sharedMemory->isAttached() || buffer == nullptr)
        return QByteArray();

    if (buffer != nullptr)
        free(buffer);
    buffer = (char *) malloc(getSharedMemorySize());

    memcpy(buffer, sharedMemory->data(), getSharedMemorySize());
    this->unlock();
    clearMemory();
    QByteArray data = QByteArray(QByteArray::fromRawData(buffer, (int)getSharedMemorySize()));
    return data;
}

size_t CrossMemoryMapper::getSharedMemorySize() const {
    return (size_t) sharedMemory->size();
}

void CrossMemoryMapper::write(QString value) {
    write(value.toAscii());
}

void CrossMemoryMapper::write(QByteArray data) {
    QString svalue(data);
    this->lock();
    void *memptr = sharedMemory->data();
    memcpy(memptr, svalue.toStdString().c_str(), static_cast<size_t>(data.size()));
    this->unlock();
}


bool CrossMemoryMapper::isAttached() {
    if (sharedMemory == nullptr)
        return false;
    return sharedMemory->isAttached();
}

const QString &CrossMemoryMapper::getKey() const {
    return key;
}
