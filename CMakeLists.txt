# trivial cmake project file to enable debugging in clion
# currently far from perfect and can't really be used to build the project (use qmake to build)
# but it can be used as starting point for clion to recognise at least some parts of Qt
# I'll improve later

# additional options to be set before use:
# EXAMPLE:
# cmake flags:
# -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=/d/dev/Qt/5.5/gcc_64;/d/dev/libs
# environment:
# PKG_CONFIG_PATH=/d/dev/libs/lib/pkgconfig
# where in example "/d/dev/libs" is path where additional libs are installed (e.g. tidy)
# and "/d/dev/Qt/5.5/gcc_64" is example of QT root

cmake_minimum_required (VERSION 3.0.2)
project (nixnote2)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui REQUIRED)
find_package (Qt5Sql REQUIRED)
find_package (Qt5Network REQUIRED)
find_package (Qt5WebKit REQUIRED)
find_package (Qt5WebKitWidgets REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(TIDY REQUIRED tidy)

set (nixnote2_src
        src/main.cpp
        src/global.cpp
)
set (nixnote2_hdr
        src/global.h
)

qt5_wrap_cpp(nixnote2_hdr_moc ${nixnote2_hdr})

include_directories (${PROJECT_SOURCE_DIR})
include_directories (${PROJECT_BINARY_DIR})
#include_directories (${PROJECT_SOURCE_DIR}/../libs)
include_directories(${TIDY_INCLUDE_DIRS})

add_executable(nixnote2
        ${nixnote2_src}
        ${nixnote2_hdr_moc}
        )
target_link_libraries (nixnote2 Qt5::Widgets Qt5::Sql Qt5::Gui Qt5::Network Qt5:WebKit Qt5:WebKitWidgets)
