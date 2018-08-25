# NixNote2
## Introduction

Fork of [baumgarr/nixnote2](https://github.com/baumgarr/nixnote2) - An unofficial client of Evernote for Linux.

This version contains the original code, selected changes merged from other forks and my changes. 

* Wiki
  * [Getting started](https://github.com/robert7/nixnote2/wiki/Getting-started)
  * [New features in v2.1](https://github.com/robert7/nixnote2/wiki/New-features-in-v2.1)
* [CHANGELOG](docs/CHANGELOG.md)
* [Binary releases](https://github.com/robert7/nixnote2/releases)

## Building from source

Tha app is mainly targeted at Linux, but it should compile quite easily on Windows and 
also macOS config is already present (see more detailed info bellow). As lot of refactoring
has been made and I can't currently try anything else then linux, it is quite probable
that minor adjustments are needed for the all non linux builds.

### Linux - docker build
**Recommended build** for all but advanced users is using docker. 
This should work out of the box, no fiddling with any dependencies
is needed. The created binary image should work on all ~recent distributions (at least
in theory).
Basic docker familiarity with docker is helpful.

More info in: [DOCKER README](docs/DOCKER-README.md)   

### Linux - manual build
* Install development dependencies - look in content of [this docker file](development/docker/Dockerfile.ubuntu_xenial)
  to see example what is needed for Ubuntu 16.04. If you use another distribution/version, 
  you need to find the right packages.
* Qt: you can either get Qt packages for your distribution or as alternative you can download qt5 directly 
  from [qt.io/download](https://www.qt.io/download). 
  Currently **only supported version is Qt 5.5**. Building against 5.6+ needs source changes 
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
    * cmake ../..  -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release
    * make                       
    * make DESTDIR=../../../libs install
    * library is now copied to ../../../libs                                                                                         

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
Should work Windows, but minor tweaks will be needed to make it run. 
I currently have no time for it. Pull request is welcome.
