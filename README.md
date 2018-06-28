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

You'll need the same dependencies installed (including libtidy on MS Windows).

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
    Highest currently supported version is 5.5. Building against 5.6+ needs some 
    source changes (and will probably break qt4 compatibility).
* It should be possible to build against qt4 but its **deprecated** - will be removed soon
* Get latest source from github... 
  * I recommend using `master` branch. There maybe feature/* or release/* available, but this may 
    not be stable. Anyway there isn't any guarantee for `master` branch either :-)
* Build

```bash
> mkdir build
> # although `release`, for now I recommend `debug` config

> # important: make sure you are using qt5 qmake 
> # version check: `qmake --version`
> qmake --version
> # check you get something like `Using Qt version 5.5.1` and NOT `Using Qt version 4.x.x'
> # on Ubuntu 16.04 I need to use /usr/lib/x86_64-linux-gnu/qt5/bin/qmake as just default qmake is 4.x

> # generate Makefile 
> qmake CONFIG+=debug

> # compile binaries
> make
```
If all got OK, you should have "nixnote2" binary available now.. if not... 
Go! install the missing dependency! :-)

### macOS

```bash
> mkdir build
> cd build
> qmake ../nixnote2/NixNote2.pro
> make
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

## Binary distribution -- **this will take older version build from source from upstream repository**

### Debian and Ubuntu

#### Install from distribution repository

For users of Debian Stretch (Debian 9) or later, Debian unstable and Ubuntu 17.04+, you may install
from the official repositories. This will become the stable release we will encourage users to install.

```bash
sudo apt update
sudo apt install nixnote2
```

For users of Debian Stretch (Debian 9), you may also install the
**latest upstream stable release** from `stretch-backports` repository:

```bash
# !! NOTE: You need to enable stretch-backports repository first
# See https://backports.debian.org for instructions
# After you enabled backports repository, type the following commands:
sudo apt update
sudo apt install nixnote2 -t stretch-backports
```

You may find the package information on [Debian PTS](https://tracker.debian.org/pkg/nixnote2).

#### Install via daily PPA

For testing the very latest functionality, there is an unstable Daily-build PPA for Debian/Ubuntu (provided by [artmg](https://github.com/artmg/nixnote2-packaging/wiki)). This is _only_ recommended for Advanced users.

```bash
sudo add-apt-repository ppa:nixnote/nixnote2-daily
sudo apt update
sudo apt install nixnote2
```

### Arch Linux

NixNote2 is available via AUR: [nixnote-beta](https://aur.archlinux.org/packages/nixnote-beta/),
[nixnote](https://aur.archlinux.org/packages/nixnote/).

These packages are also available in [[archlinuxcn]](https://www.archlinuxcn.org/archlinux-cn-repo-and-mirror/)
unofficial repository.

### Gentoo Linux

NixNote is available via gentoo-zh overlay, you can install by:

```bash
# run with root privileges
layman -a gentoo-zh
emerge nixnote:1 # to install nixnote-1.6
# or
emerge nixnote:2 # to install nixnote-2.0
```

### RPM package on Copr

The NixNote2 package for Fedora and other distros using RPM packages is now on Copr, provided by [Nuno Dias](http://copr-dist-git.fedorainfracloud.org/cgit/nunodias/nixnote2/).

```bash
dnf copr enable nunodias/nixnote2
dnf install nixnote2

# OR for OLDER Distros using yum
yum copr enable nunodias/nixnote2
yum install nixnote2
```

![Nixnote](screenshot.png)
