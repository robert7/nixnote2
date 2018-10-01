TARGET = hunspellplugin
CONFIG += plugin link_pkgconfig
TEMPLATE = lib

CONFIG(debug, debug|release) {
    DESTDIR = ../../../qmake-build-debug/hunspellplugin
    BUILD_TYPE = debug
    message($$TARGET: Debug build!)
} else {
    DESTDIR = ../../../qmake-build-release/hunspellplugin
    BUILD_TYPE = release
    message($$TARGET: Release build!)
}
OBJECTS_DIR = $${DESTDIR}
MOC_DIR = $${DESTDIR}


SOURCES += hunspellplugin.cpp \
           spellchecker.cpp
HEADERS += hunspellplugin.h \
           hunspellinterface.h \
           spellchecker.h

PKGCONFIG += hunspell

unix:!mac:QMAKE_LFLAGS += -Wl,-soname,libhunspellplugin.so.1
