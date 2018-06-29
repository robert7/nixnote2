# trivial cmake project file to enable debugging in clion
# currently far from perfect and can't really be used to build the project (use qmake to build)
# but it can be used as starting point for clion to recognise at least some parts of Qt
# I'll improve later

cmake_minimum_required (VERSION 2.8.12)
project (nixnote2)
find_package (Qt5Widgets)
find_package (Qt5Gui)
find_package (Qt5Sql)
find_package (Qt5Network)

#find_package(Qt5 REQUIR Widgets Gui Xml Webkit Sql Network Xml Script)


set (nixnote2_src
        ${PROJECT_SOURCE_DIR}/main.cpp
        ${PROJECT_SOURCE_DIR}/global.cpp
)
set (nixnote2_hdr
        ${PROJECT_SOURCE_DIR}/global.h
)

qt5_wrap_cpp(nixnote2_hdr_moc ${nixnote2_hdr})

include_directories (${PROJECT_SOURCE_DIR})
include_directories (${PROJECT_BINARY_DIR})

add_executable(nixnote2
        ${nixnote2_src}
        ${nixnote2_hdr_moc}
        )
target_link_libraries (nixnote2 Qt5::Widgets Qt5::Sql)
