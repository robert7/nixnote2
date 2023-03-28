cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/QEverCloud/cmake/modules")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/QEverCloud/cmake/modules/sanitizers")

include(QEverCloudCMakePolicies)
SET_POLICIES()

project(QEverCloud
  VERSION 6.2.0)

set(PROJECT_VENDOR "Dmitry Ivanov")
set(PROJECT_COPYRIGHT_YEAR "2015-2023")
set(PROJECT_DOMAIN_FIRST "qevercloud")
set(PROJECT_DOMAIN_SECOND "com")
set(PROJECT_DOMAIN "${PROJECT_DOMAIN_FIRST}.${PROJECT_DOMAIN_SECOND}")

include(QEverCloudDoxygen)

set(BUILD_DOCUMENTATION ON CACHE BOOL "Build documentation for QEverCloud")
set(BUILD_QCH_DOCUMENTATION OFF CACHE BOOL "Build documentation for QEverCloud in qch format")
set(BUILD_WITH_OAUTH_SUPPORT ON CACHE BOOL "Build QEverCloud with OAuth support")
set(BUILD_WITH_Q_NAMESPACE ON CACHE BOOL "Use Q_NAMESPACE and Q_ENUM_NS macros for introspection")
set(BUILD_TRANSLATIONS ON CACHE BOOL "Build translations")

if(BUILD_DOCUMENTATION)
  # set Doxygen documentation properties
  set(DOXY_INPUT "${PROJECT_SOURCE_DIR}/QEverCloud/headers ${PROJECT_SOURCE_DIR}/README.md")
  set(DOXY_USE_MDFILE_AS_MAINPAGE "${PROJECT_SOURCE_DIR}/README.md")
  set(DOXY_RECURSIVE "YES")
  set(DOXY_PROJECT_NAME ${PROJECT_NAME})
  set(DOXY_PROJECT_NUMBER "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
  set(DOXY_PROJECT_BRIEF "\"Unofficial Evernote Cloud API for Qt\"")
  set(DOXY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/doc")
  set(DOXY_WARN_IF_UNDOCUMENTED "NO")
  set(DOXY_EXTRACT_ALL "YES")
  if(BUILD_QCH_DOCUMENTATION)
    set(DOXY_GENERATE_QHP "YES")
  else()
    set(DOXY_GENERATE_QHP "NO")
  endif()
  ADD_DOCUMENTATION(doc Doxyfile)
endif()

include(QEverCloudCompilerSettings)
include(QEverCloudSetupQt)
include(QEverCloudUpdateTranslations)

set(QEVERCLOUD_QT_VERSION "qt5")

if(NOT CMAKE_INSTALL_LIBDIR)
  set(CMAKE_INSTALL_LIBDIR "lib")
endif()

if(NOT CMAKE_INSTALL_BINDIR)
  set(CMAKE_INSTALL_BINDIR "bin")
endif()

if(NOT CMAKE_INSTALL_INCLUDEDIR)
  set(CMAKE_INSTALL_INCLUDEDIR "include")
endif()

if(NOT CMAKE_INSTALL_TRANSLATIONSDIR)
  set(CMAKE_INSTALL_TRANSLATIONSDIR "share/${PROJECT_NAME}/translations")
endif()

if(NOT INSTALL_CMAKE_DIR)
  if(WIN32 AND NOT CYGWIN)
    set(INSTALL_CMAKE_DIR "CMake")
  else()
    set(INSTALL_CMAKE_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-${QEVERCLOUD_QT_VERSION}")
  endif()
endif()

set(BUILD_SHARED ON CACHE BOOL "Build shared library, otherwise static library")

if(MSVC)
  set(QEVERCLOUD_LIBNAME_PREFIX "lib")
else()
  set(QEVERCLOUD_LIBNAME_PREFIX "")
endif()

if(QEVERCLOUD_USE_QT_WEB_ENGINE)
  set(QEVERCLOUD_USES_QT_WEB_ENGINE "set(QEVERCLOUD_USE_QT_WEB_ENGINE TRUE)")
else()
  set(QEVERCLOUD_USES_QT_WEB_ENGINE "set(QEVERCLOUD_USE_QT_WEB_ENGINE FALSE)")
endif()

if(QEVERCLOUD_USE_SYSTEM_BROWSER)
  set(QEVERCLOUD_USES_SYSTEM_BROWSER "set(QEVERCLOUD_USE_SYSTEM_BROWSER TRUE)")
else()
  set(QEVERCLOUD_USES_SYSTEM_BROWSER "set(QEVERCLOUD_USE_SYSTEM_BROWSER FALSE)")
endif()

if(BUILD_WITH_OAUTH_SUPPORT)
  set(QEVERCLOUD_HAS_OAUTH "set(QEVERCLOUD_HAS_OAUTH TRUE)")
else()
  set(QEVERCLOUD_HAS_OAUTH "set(QEVERCLOUD_HAS_OAUTH FALSE)")
endif()

configure_file(QEverCloud/cmake/modules/QEverCloudBuildTreeSettings.cmake.in
  ${PROJECT_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}BuildTreeSettings.cmake @ONLY)
configure_file(QEverCloud/cmake/modules/QEverCloudConfig.cmake.in
  ${PROJECT_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}Config.cmake @ONLY)
configure_file(QEverCloud/cmake/modules/QEverCloudConfigVersion.cmake.in
  ${PROJECT_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}ConfigVersion.cmake @ONLY)

file(COPY QEverCloud/cmake/modules/QEverCloudFindQt5DependenciesCore.cmake DESTINATION ${PROJECT_BINARY_DIR})
file(RENAME ${PROJECT_BINARY_DIR}/QEverCloudFindQt5DependenciesCore.cmake ${PROJECT_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}FindQtDependencies.cmake)

if(BUILD_TRANSLATIONS)
  file(READ QEverCloud/cmake/modules/QEverCloudFindQt5DependenciesTranslations.cmake TRANSLATIONS_DEPS_FILE)
  file(APPEND ${PROJECT_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}FindQtDependencies.cmake "${TRANSLATIONS_DEPS_FILE}")
endif()

if(BUILD_WITH_OAUTH_SUPPORT)
  if(USE_QT5_WEBKIT OR Qt5Core_VERSION VERSION_LESS "5.6.0")
    file(READ QEverCloud/cmake/modules/QEverCloudFindQt5DependenciesWebKit.cmake WEBKIT_DEPS_FILE)
    file(APPEND ${PROJECT_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}FindQtDependencies.cmake "${WEBKIT_DEPS_FILE}")
  elseif(NOT QEVERCLOUD_USE_SYSTEM_BROWSER)
    file(READ QEverCloud/cmake/modules/QEverCloudFindQt5DependenciesWebEngineCore.cmake WEBENGINE_CORE_DEPS_FILE)
    file(APPEND ${PROJECT_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}FindQtDependencies.cmake "${WEBENGINE_CORE_DEPS_FILE}")
  endif()
endif()

find_package(Sanitizers)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

add_subdirectory(QEverCloud)

add_custom_target(check COMMAND "${CMAKE_CTEST_COMMAND}" "--verbose")
