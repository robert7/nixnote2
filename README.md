# NixNote v2.1
## Introduction

Nixnote is Evernote desktop client for Linux.

* [Getting started](https://github.com/robert7/nixnote2/wiki/Getting-started)
* [New features in v2.1](https://github.com/robert7/nixnote2/wiki/New-features-in-v2.1)
* [CHANGELOG](https://github.com/robert7/nixnote2/blob/master/debian/changelog)
* [Howto install & binary downloads](https://github.com/robert7/nixnote2/releases)
  * For Ubuntu users its recommended to install native package from [NixNote PPA](https://github.com/robert7/nixnote2/wiki/NixNote-PPA) (although the AppImage version will also work).
  * For any linux distribution: [download AppImage, mark as executable & run](https://github.com/robert7/nixnote2/wiki/HowTo---Run-AppImage)

Travis CI [![Build Status](https://travis-ci.com/robert7/nixnote2.svg?branch=master)](https://travis-ci.com/robert7/nixnote2)

## Building from source

This app is mainly targeted at Linux, but it should compile quite easily on Windows and
also macOS config is already present (see more detailed info bellow). As lot of refactoring
has been made and I can't currently try anything else then linux, it is quite probable
that minor adjustments are needed for the all non linux builds.

### Linux - docker build
This should work out of the box, no fiddling with any dependencies
is needed. The created binary image should work on all ~recent distributions (at least
in theory).
Basic docker familiarity with docker is helpful.

More info in: [DOCKER README](docs/DOCKER-README.md)   

### Linux - manual build
* Install development dependencies - look in content of [this docker file](development/docker/Dockerfile.ubuntu_xenial)
  of [debian/control](https://github.com/robert7/nixnote2/blob/master/debian/control)
  to see example, what is needed for Ubuntu. If you use another distribution/version,
  you may need adjust packages.
* Qt: you can either get Qt packages for your distribution or as alternative you can download Qt 5 directly
  from [qt.io/download](https://www.qt.io/download). 
* Get latest source from github...
  * I recommend using `master` branch.
* Build
* Optional: create [AppImage package](https://appimage.org/) using [linuxdeployqt](https://github.com/probonopd/linuxdeployqt)

```bash
# replace path in 1st parameter with Qt root (`/usr` will use system Qt)
./development/build-with-qmake.sh /usr debug
```

`build-with-qmake.sh` is just kind of convenience script. You can also build without it like:
`qmake CONFIG+=debug PREFIX=appdir/usr`, then `make` & eventually `make install`.
This suppose, you installed libtidy in system default location (recommended version is 5.6.0).

If all got OK, you should have "qmake-build-debug/nixnote2" binary available now
(and also a deployment copy in appdir). 
I suggest running from "appdir" (e.g. `./appdir/usr/appdir/nixnote2`).


```bash
# Optional second step: if all got well you may try to create AppImage package
# may be a bit tricky - recommended for advanced users 
./development/create-AppImage.sh
```

Preparation steps
* You can either install the html-tidy56 package from my PPA or build yourself from source.
* Alternative 1: Install from PPA:
  * first [add PPA](https://github.com/robert7/nixnote2/wiki/NixNote-PPA)
  * then `sudo apt install tidy-html56` (note if you install nixnote2 from PPA, then tidy-html56 will be installed)
  * in this case libtidy will install in /opt/tidy56
* Alternative 2: Build tidy library from source:
  * clone [source code](https://github.com/htacg/tidy-html5) switch to master branch
  * follow [build instructions](https://github.com/htacg/tidy-html5/blob/next/README/BUILD.md)
    * short version:
    * cd build/cmake
    * cmake ../..  -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release
    * make                       
    * make DESTDIR=/opt/tidy56 install
    * library is now copied to /opt/tidy56/libs (if you use different directory, then pass it as 4th argument to
      "build-with-qmake.sh".

If it doesn't work: use docker build - or compare with docker recipe, what is different.

### macOS

Disclaimer: macOS build was added from [RJVB/nixnote2](https://github.com/RJVB/nixnote2). 
I can't currently test if it works. It is quite probable, that it will need minor adjustments mainly
in path handling. Pull request is welcome.

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

### Windows
Should work on Windows, but minor tweaks will be needed to make it run.
I currently have no time for it. Pull request is welcome. No sure its worth the effort, as there is
quite decent official Evernote client for Windows.
