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
  if(USE_QT5_WEBKIT OR Qt5Core_VERSION VERSION_LESS "5.6.0")
    include(QEverCloudFindQt5DependenciesWebKit)
  else()
    include(QEverCloudFindQt5DependenciesWebEngineCore)
    set(QEVERCLOUD_USE_QT_WEB_ENGINE TRUE)
  endif()

  if(QEVERCLOUD_USE_QT_WEB_ENGINE)
    add_definitions(-DQEVERCLOUD_USE_QT_WEB_ENGINE)
  endif()

  if(USE_QT5_WEBKIT)
    list(APPEND QT_INCLUDES
      ${QT_INCLUDES}
      ${Qt5WebKit_INCLUDE_DIRS}
      ${Qt5WebKitWidgets_INCLUDE_DIRS})

    list(APPEND QT_LIBRARIES
      ${QT_LIBRARIES}
      ${Qt5WebKit_LIBRARIES}
      ${Qt5WebKitWidgets_LIBRARIES})

    list(APPEND QT_DEFINITIONS
      ${QT_DEFINITIONS}
      ${Qt5WebKit_DEFINITIONS}
      ${Qt5WebKitWidgets_DEFINITIONS})
  else()
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
endif()

list(REMOVE_DUPLICATES QT_INCLUDES)
list(REMOVE_DUPLICATES QT_LIBRARIES)
list(REMOVE_DUPLICATES QT_DEFINITIONS)

include_directories(SYSTEM "${QT_INCLUDES} ${SYSTEM}")
add_definitions(${QT_DEFINITIONS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR "ON")
