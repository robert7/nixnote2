message("Out path: $${OUT_PWD}")

QT += core gui widgets sql testlib

TARGET = tests
TEMPLATE = app

SOURCES += tests.cpp 
HEADERS += tests.h 

CONFIG(debug, debug|release) {
    DESTDIR = qmake-build-debug
    message(Debug build!)
} else {
    DESTDIR = qmake-build-release
    message(Release build!)
}
OBJECTS_DIR = $${DESTDIR}
MOC_DIR = $${DESTDIR}

isEmpty(PREFIX) {
 PREFIX = /usr
}


# install
target.path = $${PREFIX}/abcd
INSTALLS += target
