cmake_minimum_required(VERSION 3.5.1)

include(QEverCloudCMakePolicies)
SET_POLICIES()

set(QEVERCLOUD_BINARY_DIR ${PROJECT_BINARY_DIR})

set(PUBLIC_HEADERS
    headers/QEverCloud.h)

if(BUILD_WITH_OAUTH_SUPPORT)
  list(APPEND PUBLIC_HEADERS
    headers/QEverCloudOAuth.h)
endif()

set(NON_GENERATED_HEADERS
    headers/AsyncResult.h
    headers/DurableService.h
    headers/EventLoopFinisher.h
    headers/EverCloudException.h
    headers/Export.h
    headers/Exceptions.h
    headers/Globals.h
    headers/Helpers.h
    headers/InkNoteImageDownloader.h
    headers/Log.h
    headers/Optional.h
    headers/Printable.h
    headers/RequestContext.h
    headers/Thumbnail.h)

if(BUILD_WITH_OAUTH_SUPPORT)
  list(APPEND NON_GENERATED_HEADERS
    headers/OAuth.h)
endif()

set(GENERATED_HEADERS
    headers/generated/Constants.h
    headers/generated/Services.h
    headers/generated/Servers.h
    headers/generated/Types.h
    headers/generated/EDAMErrorCode.h)

set(PRIVATE_HEADERS
    src/AsyncResult_p.h
    src/Http.h
    src/HttpRequestData.h
    src/HttpRequestParser.h
    src/HttpUtils.h
    src/Impl.h
    src/Thrift.h
    src/generated/Types_io.h
    src/oauth/NetworkCookieJar.h
    src/oauth/AbstractOAuthEngine.h
    src/oauth/NonceGenerator.h
    src/oauth/Utils.h)

set(SOURCES
    src/AsyncResult.cpp
    src/AsyncResult_p.cpp
    src/DurableService.cpp
    src/EventLoopFinisher.cpp
    src/EverCloudException.cpp
    src/Exceptions.cpp
    src/Globals.cpp
    src/Http.cpp
    src/HttpRequestParser.cpp
    src/HttpUtils.cpp
    src/InkNoteImageDownloader.cpp
    src/Log.cpp
    src/Printable.cpp
    src/RequestContext.cpp
    src/Thumbnail.cpp
    src/VersionInfo.cpp
    src/generated/Constants.cpp
    src/generated/EDAMErrorCode.cpp
    src/generated/Services.cpp
    src/generated/Servers.cpp
    src/generated/Types.cpp
    src/oauth/AbstractOAuthEngine.cpp
    src/oauth/NonceGenerator.cpp
    src/oauth/Utils.cpp)

set(${PROJECT_NAME}_TR_SOURCES
    ${PUBLIC_HEADERS}
    ${NON_GENERATED_HEADERS}
    ${GENERATED_HEADERS}
    ${PRIVATE_HEADERS}
    ${SOURCES}
    src/oauth/OAuthWebEngine.h
    src/oauth/OAuthWebEngine.cpp
    src/oauth/OAuthWebKit.h
    src/oauth/OAuthWebKit.cpp
    src/oauth/OAuthSystemBrowser.h
    src/oauth/OAuthSystemBrowser.cpp
    src/oauth/OAuth.cpp)

if(BUILD_WITH_OAUTH_SUPPORT)
  if(QEVERCLOUD_USE_QT_WEB_ENGINE)
    list(APPEND PRIVATE_HEADERS
      src/oauth/OAuthWebEngine.h)

    list(APPEND SOURCES
      src/oauth/NetworkCookieJar.cpp
      src/oauth/OAuthWebEngine.cpp)
  elseif(QEVERCLOUD_USE_SYSTEM_BROWSER)
    list(APPEND PRIVATE_HEADERS
      src/oauth/OAuthSystemBrowser.h)

    list(APPEND SOURCES
      src/oauth/OAuthSystemBrowser.cpp)
  else()
    list(APPEND PRIVATE_HEADERS
      src/oauth/OAuthWebKit.h)

    list(APPEND SOURCES
      src/oauth/OAuthWebKit.cpp)
  endif()

  list(APPEND SOURCES
    src/oauth/OAuth.cpp)
endif()

set(ALL_HEADERS_AND_SOURCES ${PUBLIC_HEADERS})
list(APPEND ALL_HEADERS_AND_SOURCES ${NON_GENERATED_HEADERS})
list(APPEND ALL_HEADERS_AND_SOURCES ${GENERATED_HEADERS})
list(APPEND ALL_HEADERS_AND_SOURCES ${PRIVATE_HEADERS})
list(APPEND ALL_HEADERS_AND_SOURCES ${SOURCES})

set(${PROJECT_NAME}_TR_FILES
    QEverCloud/translations/QEverCloud_ru_RU.ts)

set(${PROJECT_NAME}_QM_FILES "")
update_translation("${${PROJECT_NAME}_TR_SOURCES}" "${${PROJECT_NAME}_TR_FILES}")

if(BUILD_WITH_OAUTH_SUPPORT)
  set(QEVERCLOUD_HAS_OAUTH "#define QEVERCLOUD_HAS_OAUTH 1")
else()
  set(QEVERCLOUD_HAS_OAUTH "#define QEVERCLOUD_HAS_OAUTH 0")
endif()

if(QEVERCLOUD_USE_QT_WEB_ENGINE EQUAL QEVERCLOUD_USE_SYSTEM_BROWSER)
  message(FATAL_ERROR "QEverCloud can be built either with QtWebKit or QtWebEngine or system browser backend for OAuth")
endif()

if(QEVERCLOUD_USE_QT_WEB_ENGINE)
  set(QEVERCLOUD_USES_QT_WEB_ENGINE "#define QEVERCLOUD_USE_QT_WEB_ENGINE 1")
else()
  set(QEVERCLOUD_USES_QT_WEB_ENGINE "#define QEVERCLOUD_USE_QT_WEB_ENGINE 0")
endif()

if(QEVERCLOUD_USE_SYSTEM_BROWSER)
  set(QEVERCLOUD_USES_SYSTEM_BROWSER "#define QEVERCLOUD_USE_SYSTEM_BROWSER 1")
else()
  set(QEVERCLOUD_USES_SYSTEM_BROWSER "#define QEVERCLOUD_USE_SYSTEM_BROWSER 0")
endif()

if(BUILD_WITH_Q_NAMESPACE)
  set(QEVERCLOUD_USES_Q_NAMESPACE "#define QEVERCLOUD_USES_Q_NAMESPACE 1")
else()
  set(QEVERCLOUD_USES_Q_NAMESPACE "#define QEVERCLOUD_USES_Q_NAMESPACE 0")
endif()

set(QEVERCLOUD_VERSION_MAJOR_DEFINE "#define QEVERCLOUD_VERSION_MAJOR ${PROJECT_VERSION_MAJOR}")
set(QEVERCLOUD_VERSION_MINOR_DEFINE "#define QEVERCLOUD_VERSION_MINOR ${PROJECT_VERSION_MINOR}")
set(QEVERCLOUD_VERSION_PATCH_DEFINE "#define QEVERCLOUD_VERSION_PATCH ${PROJECT_VERSION_PATCH}")

if(NOT QEVERCLOUD_BUILD_INFO)
  find_package(Git)
  if(GIT_FOUND)
    message(STATUS "Git found: ${GIT_EXECUTABLE}")

    # Get git branch
    execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
      OUTPUT_VARIABLE QEVERCLOUD_GIT_BRANCH
      RESULT_VARIABLE QEVERCLOUD_GIT_BRANCH_RETURN_CODE
      OUTPUT_STRIP_TRAILING_WHITESPACE)
    if(NOT "${QEVERCLOUD_GIT_BRANCH_RETURN_CODE}" STREQUAL "0")
      message(AUTHOR_WARNING "Failed to determine the current git branch, return code ${QEVERCLOUD_GIT_BRANCH_RETURN_CODE}")
      set(QEVERCLOUD_GIT_BRANCH "unknown branch")
    else()
      if(${QEVERCLOUD_GIT_BRANCH} STREQUAL "HEAD")
        # Can happen if running on detached HEAD, can happen in CI jobs; workaround: try to get the current branch from environment variables
        set(APPVEYOR_REPO_BRANCH "$ENV{APPVEYOR_REPO_BRANCH}")
        set(TRAVIS_BRANCH "$ENV{TRAVIS_BRANCH}")
        if(NOT "${APPVEYOR_REPO_BRANCH}" STREQUAL "")
          set(QEVERCLOUD_GIT_BRANCH "${APPVEYOR_REPO_BRANCH}")
        elseif(NOT "${TRAVIS_BRANCH}" STREQUAL "")
          set(QEVERCLOUD_GIT_BRANCH "${TRAVIS_BRANCH}")
        endif()
      endif()
      message(STATUS "Git branch: ${QEVERCLOUD_GIT_BRANCH}")
    endif()

    # Get last commit short hash
    execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
      OUTPUT_VARIABLE QEVERCLOUD_GIT_REVISION
      RESULT_VARIABLE QEVERCLOUD_GIT_REVISION_RETURN_CODE
      OUTPUT_STRIP_TRAILING_WHITESPACE)
    if(NOT "${QEVERCLOUD_GIT_REVISION_RETURN_CODE}" STREQUAL "0")
      message(AUTHOR_WARNING "Failed to determine the current git revision")
      set(QEVERCLOUD_GIT_REVISION "unknown revision")
    else()
      message(STATUS "Last commit short hash: ${QEVERCLOUD_GIT_REVISION}")
    endif()

    # Check for uncommitted changes
    execute_process(COMMAND ${GIT_EXECUTABLE} diff-index --quiet HEAD --
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
      RESULT_VARIABLE QEVERCLOUD_GIT_DIRTY_STATE)
    if(NOT "${QEVERCLOUD_GIT_DIRTY_STATE}" STREQUAL "0")
      set(QEVERCLOUD_GIT_REVISION "${QEVERCLOUD_GIT_REVISION}, with uncommitted changes")
    endif()

    set(QEVERCLOUD_BUILD_INFO "#define QEVERCLOUD_BUILD_INFO \"${QEVERCLOUD_GIT_BRANCH}, ${QEVERCLOUD_GIT_REVISION}\"")
  else()
    set(QEVERCLOUD_BUILD_INFO "#define QEVERCLOUD_BUILD_INFO \"unknown\"")
  endif()
else()
  set(QEVERCLOUD_BUILD_INFO "#define QEVERCLOUD_BUILD_INFO \"${QEVERCLOUD_BUILD_INFO}\"")
endif()

configure_file(headers/VersionInfo.h.in
  ${PROJECT_BINARY_DIR}/VersionInfo.h @ONLY)
list(APPEND ALL_HEADERS_AND_SOURCES ${PROJECT_BINARY_DIR}/VersionInfo.h)
include_directories(${PROJECT_BINARY_DIR})

set(LIBNAME "${QEVERCLOUD_LIBNAME_PREFIX}${QEVERCLOUD_QT_VERSION}qevercloud")

if(BUILD_SHARED)
  add_library(${LIBNAME} SHARED ${ALL_HEADERS_AND_SOURCES})
  target_compile_definitions(${LIBNAME} PRIVATE "-DQEVERCLOUD_SHARED_LIBRARY")
else()
  add_library(${LIBNAME} STATIC ${ALL_HEADERS_AND_SOURCES})
  target_compile_definitions(${LIBNAME} PRIVATE "-DQEVERCLOUD_STATIC_LIBRARY")
endif()

add_sanitizers(${LIBNAME})

set_target_properties(${LIBNAME} PROPERTIES
  VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}"
  SOVERSION ${PROJECT_VERSION_MAJOR}
  CXX_STANDARD 14
  CXX_EXTENSIONS OFF
  MACOSX_RPATH 1)

target_compile_features(${LIBNAME} INTERFACE
  cxx_auto_type
  cxx_defaulted_functions
  cxx_defaulted_move_initializers
  cxx_deleted_functions
  cxx_noexcept
  cxx_nullptr
  cxx_override
  cxx_right_angle_brackets
  cxx_rvalue_references
  cxx_strong_enums)

target_compile_features(${LIBNAME} PRIVATE
  cxx_final
  cxx_lambdas
  cxx_range_for)

target_link_libraries(${LIBNAME} ${QT_LIBRARIES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)

add_definitions("-DQT_NO_CAST_FROM_ASCII -DQT_NO_CAST_TO_ASCII -DQT_NO_CAST_FROM_BYTEARRAY -DQT_NO_NARROWING_CONVERSIONS_IN_CONNECT")

# Tests
find_package(Qt5Test QUIET)
if(Qt5Test_FOUND)
  set(TEST_HEADERS
      src/HttpRequestData.h
      src/HttpRequestParser.h
      src/HttpUtils.h
      src/tests/MessageHandler.h
      src/tests/TestDurableService.h
      src/tests/TestOptional.h
      src/tests/generated/RandomDataGenerators.h
      src/tests/generated/TestNoteStore.h
      src/tests/generated/TestUserStore.h)
  set(TEST_SOURCES
      src/HttpRequestParser.cpp
      src/HttpUtils.cpp
      src/tests/MessageHandler.cpp
      src/tests/TestDurableService.cpp
      src/tests/TestOptional.cpp
      src/tests/TestQEverCloud.cpp
      src/tests/generated/RandomDataGenerators.cpp
      src/tests/generated/TestNoteStore.cpp
      src/tests/generated/TestUserStore.cpp)
  add_executable(test_${PROJECT_NAME} ${TEST_HEADERS} ${TEST_SOURCES})
  add_sanitizers(test_${PROJECT_NAME})
  add_test(test_${PROJECT_NAME} test_${PROJECT_NAME})
  set_target_properties(test_${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF)
  target_link_libraries(test_${PROJECT_NAME} ${LIBNAME} ${QT_LIBRARIES} Qt5::Test)
else()
  message(STATUS "Haven't found Qt components required for building and running the unit tests")
endif()

# install shared library
install(TARGETS ${LIBNAME}
  EXPORT QEverCloud-${QEVERCLOUD_QT_VERSION}LibraryDepends
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

set(DEV_HEADERS_FOLDER_NAME ${QEVERCLOUD_QT_VERSION}qevercloud)

# install public headers
foreach(ITEM ${PUBLIC_HEADERS})
  install(FILES ${ITEM} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${DEV_HEADERS_FOLDER_NAME})
endforeach()

foreach(ITEM ${NON_GENERATED_HEADERS})
  install(FILES ${ITEM} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${DEV_HEADERS_FOLDER_NAME})
endforeach()

foreach(ITEM ${GENERATED_HEADERS})
  install(FILES ${ITEM} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${DEV_HEADERS_FOLDER_NAME}/generated)
endforeach()

# install VersionInfo.h header
install(FILES ${PROJECT_BINARY_DIR}/VersionInfo.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${DEV_HEADERS_FOLDER_NAME})

# install translations
foreach(QM_FILE ${${PROJECT_NAME}_QM_FILES})
  install(CODE "
          set(QM_FILE \"${QM_FILE})\")
          if(EXISTS \"${QM_FILE}\")
            get_filename_component(QM_FILE_BASE_NAME \"${QM_FILE}\" NAME)
            message(STATUS \"Installing: \$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_TRANSLATIONSDIR}/\${QM_FILE_BASE_NAME}\")
            file(COPY \"${QM_FILE}\" DESTINATION \"\$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_TRANSLATIONSDIR}\")
          endif()
          " COMPONENT Runtime)
endforeach()

# install cmake module
if(BUILD_SHARED)
  install(EXPORT QEverCloud-${QEVERCLOUD_QT_VERSION}LibraryDepends DESTINATION ${INSTALL_CMAKE_DIR})
  install(FILES ${PROJECT_SOURCE_DIR}/QEverCloud/cmake/modules/QEverCloudFindPackageWrapperMacro.cmake DESTINATION ${INSTALL_CMAKE_DIR})
  install(FILES ${QEVERCLOUD_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}FindQtDependencies.cmake DESTINATION ${INSTALL_CMAKE_DIR})
  install(FILES ${QEVERCLOUD_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}Config.cmake DESTINATION ${INSTALL_CMAKE_DIR})
  install(FILES ${QEVERCLOUD_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}ConfigVersion.cmake DESTINATION ${INSTALL_CMAKE_DIR})
endif()
