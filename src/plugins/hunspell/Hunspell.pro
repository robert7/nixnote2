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

# get g++ version
gcc {
    COMPILER_VERSION = $$system($$QMAKE_CXX " -dumpversion")
    COMPILER_MAJOR_VERSION1 = $$split(COMPILER_VERSION, ".")
    COMPILER_MAJOR_VERSION = $$first(COMPILER_MAJOR_VERSION1)
    message("$$TARGET: Compiler version $$COMPILER_MAJOR_VERSION")
    COMPILER_CONFIG = g++$$COMPILER_MAJOR_VERSION
    message("$$TARGET: Adding compiler config $$COMPILER_CONFIG")
    CONFIG += $$COMPILER_CONFIG
}

linux:QMAKE_CXXFLAGS += -std=c++11 -g -O2  -Wformat -Werror=format-security
linux:QMAKE_LFLAGS += -Wl,-Bsymbolic-functions -Wl,-z,relro

g++4 {
  # this is a guess, but "stack-protector-strong" may not be available yet
  QMAKE_CXXFLAGS += -fstack-protector
} else {
  QMAKE_CXXFLAGS += -fstack-protector-strong
}

SOURCES += hunspellplugin.cpp \
           spellchecker.cpp
HEADERS += hunspellplugin.h \
           hunspellinterface.h \
           spellchecker.h

PKGCONFIG += hunspell

unix:!mac:QMAKE_LFLAGS += -Wl,-soname,libhunspellplugin.so.1
