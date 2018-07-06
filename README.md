# NixNote2(+)
## Introduction

(Fork/clone of) nixnote2 - An unofficial client of Evernote for Linux.

This version contains the original code, selected changes merged from other forks and my changes. 
The aim is:
* Make the application more stable
* Improve status info (sync, error cases)
* Minor usability improvements (mainly focused on my personal needs)
* [TODO list](docs/TODO.md)
* [CHANGELOG](docs/CHANGELOG.md)


## Building from source

Tha app is mainly targeted at Linux, but it should compile quite easily on Windows and 
also macOS config is already present (see more detailed info bellow). It could be,
that minor adjustments are needed for the non linux builds.

### Linux

* Install development dependencies
  * Install basic dependencies (recipe for Ubuntu, use similar for other distros)
    * ```sudo apt-get install -y git-core qt5-default build-essential```
    * ```sudo apt-get install -y libboost-dev libboost-test-dev libboost-program-options-dev libevent-dev``` 
  * Install qt5 and poppler
    * ```sudo apt-get install -y libpoppler-qt5-dev```
    * ```sudo apt-get install -y libqt5webkit5-dev```
    * ```sudo apt install -y qt5-qmake```
  * ~Optional
    * ```sudo apt-get install -y libopencv-dev libhunspell-dev``` 
  * As alternative you can download qt5 directly from [qt.io/download](https://www.qt.io/download). 
    Currently Qt supported version is 5.5. Building against 5.6+ needs source changes 
    (this is on TODO list).
* Get latest source from github... 
  * I recommend using `master` branch. There maybe feature/* or release/* available, but this may 
    not be stable. Anyway there isn't any guarantee for `master` branch either :-)
* Build
* Optional: create [AppImage package](https://appimage.org/) using [linuxdeployqt](https://github.com/probonopd/linuxdeployqt)

```bash
# replace path in 1st parameter with Qt root 
./development/build-with-qmake.sh /d/dev/Qt/5.5/gcc_64 debug
```
If all got OK, you should have "qmake-build-debug/nixnote2" binary available now 
(and also a deployment copy in appdir). 
I suggest running from "appdir" (./appdir/usr/appdir/nixnote2).

```bash
# Optional second step: if all got well you may try to create AppImage package
# may be a bit tricky - recommended for advanced users 
./development/create-AppImage.sh
```

Preparation steps
* Build tidy library
  * clone [source code](https://github.com/htacg/tidy-html5) switch to master branch
  * follow [build instructions](https://github.com/htacg/tidy-html5/blob/next/README/BUILD.md)
    * short version:
    * cd build/cmake
    * edit "build-me.sh" change line with TMPINST to: TMPINST="../../../libs"
    * ./build-me.sh DEBUG SHARED                      
    * make install
    * library is now copied to ../../../libs                                                                                         

### macOS

Disclaimer: macOS build was added from [RJVB/nixnote2](https://github.com/RJVB/nixnote2). 
I can't currently test if it works. It is quite probable, that it will need minor adjustments.

```bash
mkdir build
cd build
qmake ../nixnote2/NixNote2.pro
make
```

Upon successful completion you will have the NixNote2.app bundle in the build directory.

Here, qmake is the one from Qt5. You will need to have Qt5 installed (qtbase, qtdeclarative and qtwebkit),
as well as pkgconfig, poppler-qt5, hunspell and curl; dependencies can come from MacPorts, Fink or HomeBrew (I use MacPorts).
It should be possible to use official Qt5 packages too but I haven't tested that.

The resulting application still depends MacPorts (or Fink or HomeBrew). To turn this into a standalone app bundle that can be
deployed anywhere:

```bash
> cd build
> macdeployqt NixNote2.app [-no-strip]
```

As far as I can tell this will find and copy all required dependencies into the app bundle and modify them so they
can be loaded from inside that bundle (wherever it ends up).

## Binaries
Upcomming..


