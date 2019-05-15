TARGET = QEverCloud

message("The use of qmake build system for QEverCloud is deprecated, the project file will be removed in the next release. Please use CMake build system instead")

win32 {
    TARGET = lib$$qtLibraryTarget($$TARGET)
}
else {
    TARGET = $$qtLibraryTarget($$TARGET)
}

TEMPLATE = lib

CONFIG += staticlib
DEFINES += QEVERCLOUD_STATIC_LIBRARY

QT += network widgets

use_qwebengine {
QT += webenginewidgets webengine
DEFINES += QEVERCLOUD_USE_QT_WEB_ENGINE
}
else {
QT += webkitwidgets webkit
}

CONFIG += silent
CONFIG -= debug_and_release debug_and_release_target

DESTDIR = bin
MOC_DIR = moc
OBJECTS_DIR = obj
UI_DIR = ui
RCC_DIR = rcc

INCLUDEPATH += headers

PUBLIC_HEADERS += \
    headers/QEverCloud.h \
    headers/QEverCloudOAuth.h

NON_GENERATED_PUBLIC_HEADERS += \
    headers/export.h \
    headers/oauth.h \
    headers/exceptions.h \
    headers/globals.h \
    headers/thumbnail.h \
    headers/AsyncResult.h \
    headers/Optional.h \
    headers/EverCloudException.h \
    headers/qt4helpers.h \
    headers/EventLoopFinisher.h

GENERATED_PUBLIC_HEADERS += \
    headers/generated/constants.h \
    headers/generated/services.h \
    headers/generated/types.h \
    headers/generated/EDAMErrorCode.h

PRIVATE_HEADERS += \
    src/thrift.h \
    src/http.h \
    src/impl.h \
    src/generated/types_impl.h

HEADERS += $$PUBLIC_HEADERS $$NON_GENERATED_PUBLIC_HEADERS $$GENERATED_PUBLIC_HEADERS
HEADERS += $$PRIVATE_HEADERS

SOURCES += \
    src/exceptions.cpp \
    src/globals.cpp \
    src/oauth.cpp \
    src/http.cpp \
    src/services_nongenerated.cpp \
    src/AsyncResult.cpp \
    src/EverCloudException.cpp \
    src/EventLoopFinisher.cpp \
    src/thumbnail.cpp \
    src/generated/constants.cpp \
    src/generated/services.cpp \
    src/generated/types.cpp

isEmpty(PREFIX) {
    PREFIX = /usr/local
}

greaterThan(QT_MAJOR_VERSION, 4) {
    INCLUDE_PREFIX=$$PREFIX/include/QEverCloud-qt5
}
else {
    INCLUDE_PREFIX=$$PREFIX/include/QEverCloud-qt4
}

target.path += $$PREFIX/lib

public_headers.path = $$INCLUDE_PREFIX
public_headers.files = $$PUBLIC_HEADERS

non_generated_public_headers.path = $$INCLUDE_PREFIX
non_generated_public_headers.files = $$NON_GENERATED_PUBLIC_HEADERS

generated_public_headers.path = $$INCLUDE_PREFIX/generated
generated_public_headers.files = $$GENERATED_PUBLIC_HEADERS

INSTALLS = target public_headers non_generated_public_headers generated_public_headers
