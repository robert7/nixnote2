# NixNote2
## Introduction

(Fork/clone of) nixnote2 - An unofficial client of Evernote for Linux.

This version contains the original code, selected changes merged from other forks and my changes. 
The aim is:
* mainly fixes to make the application more stable
* minor improvements (mainly focused on my personal needs)
* [TODO list..](docs/TODO.md)
* [CHANGELOG](docs/CHANGELOG.md)


## Installation

### Mac

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

### Building from source on other systems

This works much as described for Mac above. You'll need the same dependencies installed (including
libtidy on MS Windows). Then, run the same sequence of commands, followed by `sudo make install`.

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
