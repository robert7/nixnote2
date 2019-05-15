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

## How to build

The project can be built and shipped as either static library or shared library. Dll export/import symbols necessary for Windows platform are supported.

Dependencies include the following Qt components:
 * For Qt4: QtCore, QtGui, QtNetwork, QtWebKit
 * For Qt5: Qt5Core, Qt5Widgets, Qt5Network and either:
   * Qt5WebKit and Qt5WebKitWidgets - for Qt < 5.4
   * Qt5WebEngine and Qt5WebEngineWidgets - for Qt < 5.6
   * Qt5WebEngineCore and Qt5WebEngineWidgets - for Qt >= 5.6

Since QEverCloud 3.0.2 it is also possible to choose Qt5WebKit over Qt5WebEngine using CMake option `USE_QT5_WEBKIT`.

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

## Compatibility

The previous versions the library used **qmake** build system and only allowed building as a static library. The latest version of the library uses **CMake** build system which allows building either shared or static library. For compatibility the project file for qmake build system was left within the project's source tree, however, it still only allows to build a static library. Plus, the deprecation warning is displayed when one tries to use the project file for qmake build system.

The library can be built with both Qt4 and Qt5 versions of the framework. By default Qt4 is used, if found. If you'd like to force finding the Qt5 version no matter whether Qt4 is found, pass `-DUSE_QT5=1` option to CMake.

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

### QtWebKit vs QWebEngine

The library uses Qt's web facilities for OAuth authentication. These can be based on either QtWebKit (for Qt4 and older versions of Qt5) or QWebEngine (for more recent versions of Qt5). With CMake build system the choice happens automatically during the pre-build configuration based on the used version of Qt. With qmake build system QtWebKit is used by default but that can be altered via qmake option `CONFIG+=use_qwebengine`.

### C++11/14/17 features

The library does not use any C++11/14/17 features directly but only through macros like `Q_DECL_OVERRIDE`, `Q_STATIC_ASSERT_X`, `QStringLiteral` and others. Some of these macros are also "backported" to Qt4 version of the library i.e. they are defined by the library itself for Qt4 version. So the library should be buildable even with not C++11/14/17-compliant compiler.

## Include files for applications using the library

Two "cumulative" headers - *QEverCloud.h* or *QEverCloudOAuth.h* - include everything needed for the general and OAuth functionality correspondingly. More "fine-grained" headers are available within the same subfolder if needed.

## Related projects

* [NotePoster](https://github.com/d1vanov/QEverCloud-example-NotePoster) is an example app using QEverCloud library to post notes to Evernote.
* [QEverCloud packaging](https://github.com/d1vanov/QEverCloud-packaging) repository contains various files and scripts required for building QEverCloud packages for various platforms and distributions.
* [QEverCloudGenerator](https://github.com/d1vanov/QEverCloudGenerator) repository contains the parser of [Evernote Thrift IDL files](https://github.com/evernote/evernote-thrift) generating headers and sources for QEverCloud library.
