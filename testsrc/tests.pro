message("Out path: $${OUT_PWD}")

QT += core widgets printsupport webkit webkitwidgets sql network xml dbus qml testlib

CONFIG += link_pkgconfig
PKGCONFIG += tidy

# -g flag needed for linker - https://stackoverflow.com/questions/5244509/no-debugging-symbols-found-when-using-gdb
LIBS += -g


TARGET = tests
TEMPLATE = app

SOURCES += tests.cpp \
           ../src/html/enmlformatter.cpp \
           ../src/logger/qslog.cpp \
           ../src/logger/qslogdest.cpp \
           ../src/logger/qsdebugoutput.cpp \
           ../src/utilities/NixnoteStringUtils.cpp \
           ../src/utilities/encrypt.cpp

HEADERS += tests.h \
           ../src/html/enmlformatter.h \
           ../src/logger/qslog.h \
           ../src/logger/qslogdest.h \
           ../src/logger/qsdebugoutput.h \
           ../src/utilities/NixnoteStringUtils.h \
           ../src/utilities/encrypt.h

CONFIG(debug, debug|release) {
    DESTDIR = qmake-build-debug-t
    message($$TARGET: Debug build!)
} else {
    DESTDIR = qmake-build-release-t
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


isEmpty(PREFIX) {
 PREFIX = /usr
}


# install
target.path = $${PREFIX}/abcd
INSTALLS += target
