TARGET = hunspellplugin
CONFIG += plugin link_pkgconfig
TEMPLATE = lib

SOURCES += hunspellplugin.cpp \
           ../../utilities/spellchecker.cpp


HEADERS += hunspellplugin.h \
           hunspellinterface.h \
           ../../utilities/spellchecker.h

PKGCONFIG += hunspell

unix:!mac:QMAKE_LFLAGS += -Wl,-soname,libhunspellplugin.so.1
