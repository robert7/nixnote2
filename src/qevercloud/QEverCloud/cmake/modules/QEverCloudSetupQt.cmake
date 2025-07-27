set(QEVERCLOUD_FIND_PACKAGE_ARG "VERBOSE")

find_package(Qt5Core 5.5 REQUIRED)
message(STATUS "Found Qt5 installation, version ${Qt5Core_VERSION}")

include(QEverCloudFindPackageWrapperMacro)
include(QEverCloudFindQt5DependenciesCore)

list(APPEND QT_INCLUDES
  ${Qt5Core_INCLUDE_DIRS}
  ${Qt5Network_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS})

list(APPEND QT_LIBRARIES
  ${Qt5Core_LIBRARIES}
  ${Qt5Network_LIBRARIES}
  ${Qt5Widgets_LIBRARIES})

list(APPEND QT_DEFINITIONS
  ${Qt5Core_DEFINITIONS}
  ${Qt5Network_DEFINITIONS}
  ${Qt5Widgets_DEFINITIONS})

if(BUILD_TRANSLATIONS)
  include(QEverCloudFindQt5DependenciesTranslations)

  list(APPEND QT_INCLUDES
    ${Qt5LinguistTools_INCLUDE_DIRS})

  list(APPEND QT_LIBRARIES
    ${Qt5LinguistTools_LIBRARIES})

  list(APPEND QT_DEFINITIONS
    ${Qt5LinguistTools_DEFINITIONS})
endif()

if(BUILD_WITH_OAUTH_SUPPORT AND NOT QEVERCLOUD_USE_SYSTEM_BROWSER)
  include(QEverCloudFindQt5DependenciesWebEngineCore)
  set(QEVERCLOUD_USE_QT_WEB_ENGINE TRUE)

  if(QEVERCLOUD_USE_QT_WEB_ENGINE)
    add_definitions(-DQEVERCLOUD_USE_QT_WEB_ENGINE)
  endif()

  list(APPEND QT_INCLUDES
    ${QT_INCLUDES}
    ${Qt5WebEngineCore_INCLUDE_DIRS}
    ${Qt5WebEngineWidgets_INCLUDE_DIRS})

  list(APPEND QT_LIBRARIES
    ${QT_LIBRARIES}
    ${Qt5WebEngineCore_LIBRARIES}
    ${Qt5WebEngineWidgets_LIBRARIES})

  list(APPEND QT_DEFINITIONS
    ${QT_DEFINITIONS}
    ${Qt5WebEngineCore_DEFINITIONS}
    ${Qt5WebEngineWidgets_DEFINITIONS})
endif()

list(REMOVE_DUPLICATES QT_INCLUDES)
list(REMOVE_DUPLICATES QT_LIBRARIES)
list(REMOVE_DUPLICATES QT_DEFINITIONS)

include_directories(SYSTEM "${QT_INCLUDES} ${SYSTEM}")
add_definitions(${QT_DEFINITIONS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR "ON")
