QEverCloud
==========

**Unofficial Evernote Cloud API for Qt**

![master](https://github.com/d1vanov/QEverCloud/workflows/Build/badge.svg?branch=master)

## What's this

This library presents the complete Evernote SDK for Qt.
All the functionality that is described on [Evernote site](http://dev.evernote.com/doc/)
is implemented and ready to use. In particular OAuth authentication is implemented.

Read doxygen generated [documentation](http://d1vanov.github.io/QEverCloud) for detailed info.

The documentation can also be generated in the form of a .qch file which you can register with
your copy of Qt Creator to have context-sensitive help. See below for more details.

## How to contribute

See [contribution guide](CONTRIBUTING.md) for detailed info.

## Downloads

Prebuilt versions of the library can be downloaded from the following locations:

 * Stable version:
   * Windows binaries:
     * [MSVC 2019 32 bit Qt 5.15.2](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/QEverCloud_windows_x86.zip)
     * [MSVC 2019 64 bit Qt 5.15.2](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/QEverCloud_windows_x64.zip)
   * [Mac binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/QEverCloud_macos_x86_64.zip) (built with Qt 5.15.2)
   * [Linux binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/QEverCloud_linux_x86_64.zip) built on Ubuntu 20.04 with Qt 5.12.8
 * Unstable version:
   * Windows binaries:
     * [MSVC 2019 32 bit Qt 5.15.2](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/QEverCloud_windows_x86.zip)
     * [MSVC 2019 64 bit Qt 5.15.2](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/QEverCloud_windows_x64.zip)
   * [Mac binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/QEverCloud_macos_x86_64.zip) (built with Qt 5.15.2)
   * [Linux binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/QEverCloud_linux_x86_64.zip) built on Ubuntu 20.04 with Qt 5.12.8

## How to build

QEverCloud uses CMake build system which can be used as simply as follows (on Unix platforms):
```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=<...> ../
make
make install
```

The library can be built and shipped either as a static library or a shared library. Dll export/import symbols necessary for Windows platform are supported.

QEverCloud uses C++14 standard. CMake automatically checks whether the compiler is capable enough of building QEverCloud so if the pre-build configuration step was successful, the build step should be successful as well. Known capable compilers are g++ 9 or later and Visual Studio 2019 or later.

The recommended version of Qt5 for building the library is the latest Qt 5.15. However, it is also known to build and work with Qt 5.12.

QEverCloud depends on the following Qt components:
 * Qt5Core
 * Qt5Widgets
 * Qt5Network
 * (Optional) Qt5WebKit an Qt5WebKitWidgets
 * (Optional) Qt5WebEngine and Qt5WebEngineWidgets

The dependencies on Qt5WebKit or Qt5WebEngine are only actual if the library is built with OAuth support. But even then there is an option to build the library with OAuth support but without the dependency on either of these components. More on this below.

By default the library is built with OAuth support and uses Qt5WebEngine for it. The following cmake parameters are available to alter this behaviour:
 * `-DBUILD_WITH_OAUTH_SUPPORT=NO` would disable building with OAuth support entirely.
 * `-DUSE_QT5_WEBKIT=ON` would build the library with OAuth using Qt5WebKit for web page rendering.
 * `-DQEVERCLOUD_USE_SYSTEM_BROWSER=ON` would build the library with OAuth not using either Qt5WebKit or Qt5WebEngine but instead delegating some portion of OAuth procedure to the system browser.

If Qt5's Qt5Test module is found during the pre-build configuration step, the unit tests are enabled and can be run with `make test` and more verbose `make check` commands.

Other available CMake configurations options:

*BUILD_DOCUMENTATION* - when *ON*, attempts to find Doxygen and in case of success adds *doc* target so the documentation can be built using `make doc` command after the pre-build configuration step. By default this option is on.

*BUILD_QCH_DOCUMENTATION* - when *ON*, passes instructions on to Doxygen to build the documentation in *qch* format. This option only has any meaning if *BUILD_DOCUMENTATION* option is on. By default this option is off.

*BUILD_SHARED* - when *ON*, CMake configures the build for the shared library. By default this option is on.

*BUILD_WITH_Q_NAMESPACE* - when *ON*, `Q_NAMESPACE` and `Q_ENUM_NS` macros are used to add introspection capabilities to enumerations within `qevercloud` namespace. Qt >= 5.8 is required to enable this option. By default this option is enabled.

*BUILD_TRANSLATIONS* - when *ON*, builds and installs translation files for translatable strings from QEverCloud.

If *BUILD_SHARED* is *ON*, `make install` installs CMake module necessary for applications using CMake's `find_package` command to find the installation of QEverCloud.

It is possible to build the library with enabled sanitizers using additional CMake options:
 * `-DSANITIZE_ADDRESS=ON` to enable address sanitizer
 * `-DSANITIZE_MEMORY=ON` to enable memory sanitizer
 * `-DSANITIZE_THREAD=ON` to enable thread sanitizer
 * `-DSANITIZE_UNDEFINED=ON` to enable undefined behaviour sanitizer

## Include files for applications using the library

Two "cumulative" headers - *QEverCloud.h* or *QEverCloudOAuth.h* - include everything needed for the general and OAuth functionality correspondingly. More "fine-grained" headers can also be used if needed.

## Seeding random numbers generator for Qt < 5.10

QEverCloud requires random numbers generator for OAuth procedure. When QEverCloud is built against Qt >= 5.10, it uses `QRandomGenerator` which is cryptographically secure on supported platforms and is seeded by Qt internals. With Qt < 5.10 QEverCloud uses `qrand`. It requires the client application to call `qsrand` with seed value before using OAuth calls of QEverCloud. So if you are using QEverCloud built with Qt < 5.10, make sure to call `qsrand` before using QEverCloud's OAuth.

## Related projects

* [QEverCloudGenerator](https://github.com/d1vanov/QEverCloudGenerator) repository hosts code generating parser of [Evernote Thrift IDL files](https://github.com/evernote/evernote-thrift). This parser is used to autogenerate a portion of QEverCloud's headers and sources.
* [libquentier](https://github.com/d1vanov/libquentier) is a library for creating feature rich full sync Evernote clients built on top of QEverCloud
* [Quentier](https://github.com/d1vanov/quentier) is an open source desktop note taking app capable of working as Evernote client built on top of libquentier and QEverCloud
