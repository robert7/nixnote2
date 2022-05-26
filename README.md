# NixNote v2.1
## Introduction

Nixnote is Evernote desktop client for Linux (can be also build on macOS and Windows).

* [Getting started](https://github.com/robert7/nixnote2/wiki/Getting-started)
* [Features](https://github.com/robert7/nixnote2/wiki/Features)
* [CHANGELOG](https://github.com/robert7/nixnote2/blob/master/debian/changelog)
* [Contributing](CONTRIBUTING.md)
* [Releases](https://github.com/robert7/nixnote2/releases)


Travis CI [![Build Status](https://travis-ci.com/robert7/nixnote2.svg?branch=master)](https://app.travis-ci.com/github/robert7/nixnote2)

## Project Status
Unfortunately, I as a "maintainer" don't have time for the project anymore.

Anyone who is interested, can fork & continue…

So far I know Nixnote works quite fine for many people... in case there would be some breaks in Evernote API, I'm willing to investigate and fix if I can. Otherwise, I do some "must have" maintenance.

## Packages
### Debian, Ubuntu and derivatives official repositories
In case you distribution is based on **Debian 10 (Buster) or Ubuntu 19.04 (Disco) or later distribution 
versions**, you can install Nixnote 2.1 from official repositories using:

``` bash
sudo apt update
sudo apt install nixnote2 -y
```
But there maybe newer version in the PPA (see bellow).
Note: on older distributions the "nixnote2" may also be available, but you may get the older [2.0 version](https://github.com/baumgarr/nixnote2).

### Ubuntu
NixNote PPA - reflects the latest [stable release](https://github.com/robert7/nixnote2/wiki/Releases---versions%2C-build-pipeline%2C-branches%2C-tags#stable-releases). More information can be found on [NixNote PPA wiki page](https://github.com/robert7/nixnote2/wiki/NixNote-PPA). Installation commands:

``` bash
sudo add-apt-repository ppa:nixnote/nixnote2-stable -y
sudo apt update
sudo apt install nixnote2 -y
```
PPA packages are available for Ubuntu 16.04 (Xenial) and newer.

Additionally there is a "[development branch PPA](https://code.launchpad.net/~nixnote/+archive/ubuntu/nixnote2-develop)" available.
The usage is same as for "stable PPA", just replace the name "nixnote2-stable" with "nixnote2-develop".
Just please take care, that you don't enable both stable and development PPA.
At most times, the "[development release](https://github.com/robert7/nixnote2/wiki/Releases---versions%2C-build-pipeline%2C-branches%2C-tags#development-releases)"
should be OK for daily use.

### AppImage
This is suitable to **any ~recent linux distribution**.
Installation is trivial - download AppImage file, mark as executable & run.
More information can be found on [NixNote AppImage wiki page](https://github.com/robert7/nixnote2/wiki/HowTo---Run-AppImage).

Two builds are available:
* [Stable build](https://github.com/robert7/nixnote2/releases/tag/continuous) - it reflects the latest [stable release](https://github.com/robert7/nixnote2/wiki/Releases---versions%2C-build-pipeline%2C-branches%2C-tags#stable-releases) - tip of the `master` branch - same as the PPA or AUR version.
* [Development build](https://github.com/robert7/nixnote2/releases/tag/continuous-develop) - it reflects the latest [development release](https://github.com/robert7/nixnote2/wiki/Releases---versions%2C-build-pipeline%2C-branches%2C-tags#development-releases) - tip of the `develop` branch..

### Other
I can't provide support for packaging for other distributions that Ubuntu PPA and the AppImage
but here are links to further community builds:

#### Arch Linux
AUR package [nixnote2-git](https://aur.archlinux.org/packages/nixnote2-git/)
builds the latest [stable release](https://github.com/robert7/nixnote2/wiki/Releases---versions%2C-build-pipeline%2C-branches%2C-tags#stable-releases).

#### Gentoo Linux
NixNote is available via a custom portage overlay (that lives [here][overlay]). It can be installed by running the following commands:
``` bash
layman -o https://raw.githubusercontent.com/bbugyi200/portage-overlay/master/repository.xml -f -a bbugyi200
emerge nixnote:2
```

[overlay]: https://github.com/bbugyi200/portage-overlay

#### Fedora
https://copr.fedorainfracloud.org/coprs/nunodias/nixnote2/

#### OpenSUSE
https://software.opensuse.org/package/nixnote2

## Building from source

This app is mainly targeted at Linux, but it should compile quite easily on Windows and
also macOS config is already present (see more detailed info bellow). As lot of refactoring
has been made and I can't currently try anything else then linux, it is quite probable
that minor adjustments are needed for the all non linux builds.

Application is developed using [Clion](https://www.jetbrains.com/clion/) IDE
using open source licence from [JetBrains](https://www.jetbrains.com/?from=nixnote2).

### Linux - docker build
This should work out of the box, no fiddling with any dependencies
is needed. The created binary image should work on all ~recent distributions (at least
in theory).
Basic familiarity with docker is helpful.

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
./development/build-with-qmake.sh
```
`build-with-qmake.sh` is just kind of convenience script. You can also build without it like:
`qmake CONFIG+=debug PREFIX=appdir/usr`, then `make && make install`.

This suppose, you installed libtidy in system default location (recommended version is 5.6.0).

In case you installed tidy from nixnote (e.g. using package `nixnote2-tidy` from Nixnote PPA), then
the could command could be `./development/build-with-qmake.sh debug noclean /usr/lib/nixnote2/tidy`.

If all got OK, you should have "qmake-build-debug/nixnote2" binary available now
(and also a deployment copy in appdir). 
I suggest running from "appdir" (e.g. `./appdir/usr/appdir/nixnote2`).


```bash
# Optional second step: if all got well you may try to create AppImage package
./development/create-AppImage.sh
```

Preparation steps
* You can either install the `nixnote2-tidy` package from NixNote PPA or build yourself from source.
* Alternative 1: Install nixnote from [PPA](https://github.com/robert7/nixnote2/wiki/NixNote-PPA):
  * ..this includes nixnote2-tidy package
  * in this case libtidy is installed in /usr/lib/nixnote2/tidy
* Alternative 2: Build tidy library from source:
  * clone [source code](https://github.com/htacg/tidy-html5) switch to master branch
  * follow [build instructions](https://github.com/htacg/tidy-html5/blob/next/README/BUILD.md)
    * short version:
    * cd build/cmake
    * cmake ../..  -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release
    * make                       
    * make DESTDIR=/some/directory install
    * library is now copied to /some/directory/lib (/some/directory/lib should be then passed as 3rd argument to
      build-with-qmake.sh)

If it doesn't work: use docker build - or compare with docker recipe, what is different - e.g. missing dependency package.

### macOS
Build from source. Basically same as for linux:

```bash
./development/build-with-qmake.sh
```
`build-with-qmake.sh` is just kind of convenience script. You can also build without it like:
`qmake CONFIG+=debug PREFIX=appdir/usr`, then `make && make install`.

Upon successful completion you will have the NixNote2.app bundle in the build directory (e.g. qmake-build-debug/NixNote2.app).

Dependencies can come from MacPorts, Fink or HomeBrew (I use MacPorts).
It should be possible to use official Qt5 packages too but I haven't tested that.
Tested with following macPorts packages: qt5, qt5-qtwebkit, poppler-qt5, hunspell, boost, tidy.

The resulting application still depends MacPorts (or Fink or HomeBrew). To turn this into a standalone app bundle that can be
deployed anywhere:

```bash
> cd build
> macdeployqt NixNote2.app [-no-strip]
```

As far as I can tell this will find and copy all required dependencies into the app bundle and modify them so they
can be loaded from inside that bundle (wherever it ends up).

### Windows
Build with MinGW32(MinGW-w64 and MSVC should work too):

Unlike Unix-like systems, Windows is not shipped with a bash environment, so you need to have one.

Download development dependencies:

[poppler](https://sourceforge.net/projects/poppler-qt5-mingw32/)

[tidy](https://github.com/htacg/tidy-html5/)

[hunspell](https://github.com/hunspell/hunspell/)

[Qt](https://download.qt.io/)(with MinGW32)

(Advice: You may want to add the path to qmake.exe and ming32-make.exe to the PATH environment, so that you do not have to type the full path when building the application and libraries later. You can do this by hand or running qtenv2.bat.)

If your Qt version is 5.5 or higher, you need to download QtWebKit separately, because it is deprecated.

[QtWebKit](https://github.com/qtwebkit/qtwebkit/releases/download/qtwebkit-tp5/qtwebkit-tp5-qt58-mingw530-x86.zip)

You need to build tidy-html5 by yourself to get the dll files, its README file may help. The poppler link points to the binary files, of an old version. If you want to use the latest version, you can download the code [here](https://github.com/freedesktop/poppler) and build it.

About hunspell, as its README instructs us to use MSYS2 and Cygwin, which may be in x64, so you had better pay attention to the host type when executing its configure script. To get compatible libraries, you have to set gcc and g++ as the one you used previously for tidy(by alias or export command) and run the configure script like this:
```bash
./configure --build=i686-pc-mingw32 --host=i686-pc-mingw32 --target=i686-pc-mingw32
```
And then, execute 'mingw32-make.exe', and you will get the dll file.

If your qt version is 5.5 or higher, you need to copy the files under QtWebKit include folder to /your_path_to_qt/[version]/mingw[version]/include. Then, create folders as winlib/includes in this repository folder and copy the files under poppler, tidy and hunspell include folders to winlib/includes. The structure is:

```bash
nixnote_repo
|
`--winlib
   |
   includes
   |
   `--poppler
   |  |
   |  `--qt5
   |  |  |
   |  |  `...
   |  `--cpp
   |     |
   |     `...
   `--tidy
   |  |
   |  `--tidyplatform.h
   |  |
   |  `--tidyenum.h
   |  |
   |  ...
   |
   `--hunspell
      |
      `--affentry.hxx
      |
      ...
```
And also copy the dll files libtidy.dll, libpoppler.dll, libpoppler-qt5.dll, libhunspell-1.7-0.dll to winlib.

Then, build the application.

```bash
qmake.exe -set HUNSPELL_VERSION 1.7-0(you can change the version as needed)
qmake.exe CONFIG+=debug[/release] nixnote2.pro
qmake.exe -unset HUNSPELL_VERSION
mingw32-make.exe -f Makefile.Release
(As qmake.exe do not add the version of hunspell in the generated makefiles, so we have to set/unset it by hand.
If error occurs when executing the command of strip, you can ignore it.)
```

Finally, you will get qmake-build-build[/release]/nixnote2.exe. Run deploy-on-windows.sh under the development folder to finish the deploy, and copy the nixnote2.exe to the deploy folder. If you need spell check, you have to download the dictionary files and copy the .aff and .dic file to the deploy folder, you may want to download them [here](https://github.com/wooorm/dictionaries).


## Donations
If you would like to support the project, you can send me some little amount via paypal: https://paypal.me/nixnote2
