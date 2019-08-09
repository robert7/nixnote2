QEverCloud
==========

**Unofficial Evernote Cloud API for Qt**

Travis CI (Linux, OS X): [![Build Status](https://travis-ci.org/d1vanov/QEverCloud.svg?branch=master)](https://travis-ci.org/d1vanov/QEverCloud)

AppVeyor CI (Windows): [![Build status](https://ci.appveyor.com/api/projects/status/75vtxm2o18u4atw0/branch/master?svg=true)](https://ci.appveyor.com/project/d1vanov/qevercloud/branch/master)

## What's this

This library presents the complete Evernote SDK for Qt.
All the functionality that is described on [Evernote site](http://dev.evernote.com/doc/)
is implemented and ready to use. In particular OAuth authentication is implemented.

Read doxygen generated [documentation](http://d1vanov.github.io/QEverCloud) for detailed info.

The documentation can also be generated in the form of a .qch file which you can register with
your copy of Qt Creator to have context-sensitive help. See below for more details.

## How to contribute

Please see the [contribution guide](CONTRIBUTING.md) for detailed info. 

## Downloads

Prebuilt versions of the library can be downloaded from the following locations:

 * Stable version:
   * Windows binaries:
     * [MSVC 2015 32 bit Qt 5.10](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud-windows-qt510-VS2015_x86.zip)
     * [MSVC 2017 64 bit Qt 5.10](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud-windows-qt510-VS2017_x64.zip)
     * [MinGW 32 bit Qt 5.5](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud-windows-qt55-MinGW_x86.zip)
   * [Mac binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud_mac_x86_64.zip) (built with latest Qt from Homebrew)
   * [Linux binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud_linux_qt_592_x86_64.zip) built on Ubuntu 14.04 with Qt 5.9.2
 * Unstable version:
   * Windows binaries:
     * [MSVC 2015 32 bit Qt 5.10](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud-windows-qt510-VS2015_x86.zip)
     * [MSVC 2017 64 bit Qt 5.10](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud-windows-qt510-VS2017_x64.zip)
     * [MinGW 32 bit Qt 5.5](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud-windows-qt55-MinGW_x86.zip)
   * [Mac binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud_mac_x86_64.zip) (built with latest Qt from Homebrew)
   * [Linux binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud_linux_qt_592_x86_64.zip) built on Ubuntu 14.04 with Qt 5.9.2

## How to build

The project can be built and shipped as either static library or shared library. Dll export/import symbols necessary for Windows platform are supported.

Dependencies include the following Qt components:
 * For Qt4: QtCore, QtGui, QtNetwork and, if the library is built with OAuth support, QtWebKit
 * For Qt5: Qt5Core, Qt5Widgets, Qt5Network and, if the library is built with OAuth support, either:
   * Qt5WebKit and Qt5WebKitWidgets - for Qt < 5.4
   * Qt5WebEngine and Qt5WebEngineWidgets - for Qt < 5.6
   * Qt5WebEngineCore and Qt5WebEngineWidgets - for Qt >= 5.6

Since QEverCloud 3.0.2 it is possible to choose Qt5WebKit over Qt5WebEngine using CMake option `USE_QT5_WEBKIT`.

Since QEverCloud 4.0.0 it is possible to build the library without OAuth support and thus without QtWebKit or QtWebEngine dependencies, for this use CMake option `BUILD_WITH_OAUTH_SUPPORT=NO`.

Also, if Qt4's QtTest or Qt5's Qt5Test modules are found during the pre-build configuration, the unit tests are enabled and can be run with `make test` command.

The project uses CMake build system which can be used as simply as follows (on Unix platforms):
```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=<...> ../
make
make install
```

Please note that installing the library somewhere is mandatory because it puts the library's headers into the subfolder dependent on used Qt version: either *qt4qevercloud* or *qt5qevercloud*. The intended use of library's headers is something like this:
```
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#include <qt4qevercloud/QEverCloud.h>
#else
#include <qt5qevercloud/QEverCloud.h>
#endif
```

If you just need to use the only one Qt version, you can skip the check and just include the header file you need.

More CMake configurations options available:

*BUILD_DOCUMENTATION* - when *ON*, attempts to find Doxygen and in case of success adds *doc* target so the documentation can be built using `make doc` command after the `cmake ../` step. By default this option is on.

*BUILD_QCH_DOCUMENTATION* - when *ON*, passes instructions on to Doxygen to build the documentation in *qch* format. This option only has any meaning if *BUILD_DOCUMENTATION* option is on. By default this option is off.

*BUILD_SHARED* - when *ON*, CMake configures the build for the shared library. By default this option is on.

If *BUILD_SHARED* is *ON*, `make install` would install the CMake module necessary for applications using CMake's `find_package` command to find the installation of the library.

If *MAJOR_VERSION_LIB_NAME_SUFFIX* is on, `make install` would add the major version as a suffix to the library's name.

If *MAJOR_VERSION_DEV_HEADERS_FOLDER_NAME_SUFFIX* is on, `make install` would install the development headers into the folder which name would end with the major version of QEverCloud.

The two latter options are intended to allow for easier installation of multiple major versions of QEverCloud.

## Compatibility

The library can be built with both Qt4 and Qt5 versions of the framework. Since QEverCloud 4.1.0 the default one is Qt5. In order to force building with Qt4 version pass `-DBUILD_WITH_QT4=ON` option to CMake. Prior to QEverCloud 4.1.0 version of Qt used by default was Qt4. For those old versions in order to force building with Qt5 one needs to pass `-DUSE_QT5=1` option to CMake.

### API breaks from 2.x to 3.0

The API breaks only include the relocation of header files required in order to use the library: in 2.x one could simply do
```
#include <QEverCloud.h>
```
while since 3.0 the intended way to use the installed shared library is the following:
```
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#include <qt4qevercloud/QEverCloud.h>
#else
#include <qt5qevercloud/QEverCloud.h>
#endif
```

### API breaks from 3.x to 4.0

Tha API breaks in 4.0 inlcude a few changes caused by migration from Evernote API 1.25 to Evernote API 1.28. The breaks are listed in a [separate document](API_breaks_3_to_4.md).

### QtWebKit vs QWebEngine

The library uses Qt's web facilities for OAuth authentication. These can be based on either QtWebKit (for Qt4 and older versions of Qt5) or QWebEngine (for more recent versions of Qt5). With CMake build system the choice happens automatically during the pre-build configuration based on the used version of Qt. One can also choose to use QtWebKit even with newer versions of Qt via CMake option `USE_QT5_WEBKIT`.

### C++11/14/17 features

The library does not use any C++11/14/17 features directly but only through macros like `Q_DECL_OVERRIDE`, `Q_STATIC_ASSERT_X`, `QStringLiteral` and others. Some of these macros are also "backported" to Qt4 version of the library i.e. they are defined by the library itself for Qt4 version. So the library should be buildable even with not C++11/14/17-compliant compiler.

## Include files for applications using the library

Two "cumulative" headers - *QEverCloud.h* or *QEverCloudOAuth.h* - include everything needed for the general and OAuth functionality correspondingly. More "fine-grained" headers are available within the same subfolder if needed.

## Related projects

* [NotePoster](https://github.com/d1vanov/QEverCloud-example-NotePoster) is an example app using QEverCloud library to post notes to Evernote.
* [QEverCloud packaging](https://github.com/d1vanov/QEverCloud-packaging) repository contains various files and scripts required for building QEverCloud packages for various platforms and distributions.
* [QEverCloudGenerator](https://github.com/d1vanov/QEverCloudGenerator) repository contains the parser of [Evernote Thrift IDL files](https://github.com/evernote/evernote-thrift) generating headers and sources for QEverCloud library.
* [libquentier](https://github.com/d1vanov/libquentier) is a library for creating of feature rich full sync Evernote clients built on top of QEverCloud
* [Quentier](https://github.com/d1vanov/quentier) is an open source desktop note taking app capable of working as Evernote client built on top of libquentier and QEverCloud
