# NixNote2

## Project Status

> **NixNote2 is currently unmaintained.**
>
> I no longer use Evernote or NixNote2 and cannot provide regular support, bug triage, packaging help, or feature development. The repository remains available for existing users and for anyone who wants to fork or continue the project.
>
> Critical fixes or well-scoped community pull requests may still be considered, but please do not assume maintainer availability.

## Introduction

Nixnote is Evernote desktop client for Linux (can be also build on macOS and Windows).

* [Getting started](https://github.com/robert7/nixnote2/wiki/Getting-started)
* [Features](https://github.com/robert7/nixnote2/wiki/Features)
* [CHANGELOG](https://github.com/robert7/nixnote2/blob/master/debian/changelog)
* [Contributing](CONTRIBUTING.md)
* [Releases](https://github.com/robert7/nixnote2/releases)

![Github Actions](https://github.com/robert7/nixnote2/actions/workflows/cicd.yaml/badge.svg)

## Packages

### AppImage (recommended)
The AppImage is the recommended way to run NixNote2. It works on recent x86_64 Linux distributions
(verified on Ubuntu 26.04) and does not depend on distribution packages.

* Download `NixNote2-x86_64.AppImage` from the [continuous build](https://github.com/robert7/nixnote2/releases/tag/continuous)
  release - it reflects the tip of the `master` branch.
* Mark it as executable and run it:

``` bash
chmod +x NixNote2-x86_64.AppImage
./NixNote2-x86_64.AppImage
```

The AppImage uses the static AppImage runtime and does not need the FUSE 2 library (`libfuse2`).
Mounting the image uses `fusermount3` from the `fuse3` package, which is usually installed by default on desktop
systems (otherwise: `sudo apt install fuse3`). Without FUSE, run `./NixNote2-x86_64.AppImage --appimage-extract-and-run`.

AppImages of v2.1.10 and older still need `libfuse2t64` (Ubuntu 24.04+, Debian 13+) or `libfuse2` (older releases).

More information can be found on the [NixNote AppImage wiki page](https://github.com/robert7/nixnote2/wiki/HowTo---Run-AppImage).

### Debian and Ubuntu official repositories
NixNote2 depends on QtWebKit (Qt 5), which was removed from newer distribution releases. As a result,
the `nixnote2` package is **no longer available in Ubuntu 25.04 or newer and Debian 13 (Trixie) or newer** -
use the AppImage there.

Older releases still ship it, with older versions:

| Distribution | Version |
|---|---|
| Ubuntu 24.04 (Noble) | 2.1.10 |
| Ubuntu 22.04 (Jammy) | 2.1.6 |
| Ubuntu 20.04 (Focal) | 2.1.5 |
| Debian 12 (Bookworm) | 2.1.7 |
| Debian 11 (Bullseye) | 2.1.6 |

``` bash
sudo apt update
sudo apt install nixnote2 -y
```

### Ubuntu PPA (legacy)
The [NixNote PPA](https://github.com/robert7/nixnote2/wiki/NixNote-PPA) provides the latest stable release
(2.1.11) for **Ubuntu 20.04 (Focal) and 22.04 (Jammy) only**. No builds are planned for newer Ubuntu releases.

``` bash
sudo add-apt-repository ppa:nixnote/nixnote2-stable -y
sudo apt update
sudo apt install nixnote2 -y
```

### Community builds
The following packages are maintained by the community. They are not verified by this project
and may be outdated or no longer maintained.

#### Windows
Windows binaries can be found at a fork https://github.com/boo-yee/nixnote2 under [Releases](https://github.com/boo-yee/nixnote2/releases).

#### Arch Linux
AUR package [nixnote2-git](https://aur.archlinux.org/packages/nixnote2-git/)
builds the latest [stable release](https://github.com/robert7/nixnote2/wiki/Releases---versions%2C-build-pipeline%2C-branches%2C-tags#stable-releases).

#### Gentoo Linux
NixNote is available via a custom portage [overlay]. It can be installed by running the following commands:
``` bash
layman -o https://raw.githubusercontent.com/bbugyi200/portage-overlay/master/repository.xml -f -a bbugyi200
emerge nixnote:2
```

Another option: [AppImage ebuild in Guru](https://github.com/gentoo/guru/tree/master/app-office/nixnote-bin), with only single dependency: fuse.

[overlay]: https://github.com/bbugyi200/portage-overlay/blob/master/app-misc/nixnote/nixnote-9999.ebuild

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
* Install development dependencies - look in content of [this docker file](development/docker/Dockerfile.ubuntu_focal)
  or [debian/control](https://github.com/robert7/nixnote2/blob/master/debian/control)
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
I suggest running from "appdir" (e.g. `./appdir/usr/bin/nixnote2`).


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
Build with MinGW32 for a 32-bit Nixnote2 (if you want a 64-bit one, you need to use MinGW-w64 or MSVC):

Unlike Unix-like systems, Windows is not shipped with a bash environment, so you need to install one first.

#### Download development dependencies:

##### Download the third-party libraries:
If you want to download binary third-party library files compatible with Qt 5.5.0, you can get them from [winlib](https://github.com/boo-yee/winlib). Inside it, Hunspell and tidy are built with MinGW 32 4.9.2(shipped with Qt 5.5.0), and poppler is downloaded from sourceforge as binary. If you want to build by yourself, you can download them from the following links:

[poppler](https://sourceforge.net/projects/poppler-qt5-mingw32/)

[tidy](https://github.com/htacg/tidy-html5/)

[hunspell](https://github.com/hunspell/hunspell/)

##### Download Qt:
[Qt](https://download.qt.io/)(with MinGW32)

Qt 5.5.0 is enough. But if you want to build with a newer version, you need to download QtWebKit separately and copy the files under QtWebKit include folder to /your_path_to_qt/[version]/mingw[version]/include.

[QtWebKit](https://github.com/qtwebkit/qtwebkit/releases)

(Advice: You may want to add the path to qmake.exe and ming32-make.exe to the PATH environment, so that you do not have to type the full path when building the application and libraries later. You can do this by hand or running qtenv2.bat.)

#### Build third-party libraries:
If you need to build tidy-html5 by yourself, its README file may help. The poppler link points to the binary files, you can use it directly.

About hunspell, as its README instructs us to use MSYS2 and Cygwin, which may be in x64, so to get compatible libraries, you have to set gcc and g++ as the one you used previously for tidy under MSYS2 or Cygwin(by alias or export command) and build like this:
```bash
MSYS2/Cygwin # autoreconf -vfi
MSYS2/Cygwin # ./configure --build=i686-pc-mingw32 --host=i686-pc-mingw32 --target=i686-pc-mingw32
MSYS2/Cygwin # mingw32-make.exe
```
Then you will get the hunspell dll file.

Then, create folders as winlib/includes in this repository folder and copy the files under poppler, tidy and hunspell include folders to winlib/includes. The structure is:

```bash
nixnote2
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

#### Build the application:

(This part can be going under any bash environment, not definitely MSYS or Cygwin.)

```bash
git clone nixnote2
cd nixnote2
qmake.exe -set HUNSPELL_VERSION 1.7-0(you can change the version as needed)
qmake.exe CONFIG+=debug[/release] nixnote2.pro
qmake.exe -unset HUNSPELL_VERSION
mingw32-make.exe
strip.exe qmake-build-debug/[release]/nixnote2.exe
```

Finally, you will get qmake-build-debug[/release]/nixnote2.exe.

#### Deployment:

First, copy the nixnote2.exe to the deployment_folder, then execute the following commands:

```bash
windeployqt.exe --compiler-runtime --libdir [deployment_folder] [deployment_folder]
bash development/deploy-on-windows.sh [deployment_folder]
```

If you need spell check, you have to download the dictionary files and copy the .aff and .dic file to the deployment folder. You may want to download them [here](https://github.com/wooorm/dictionaries).


## Donations
If you would like to support the project, you can send me some little amount via paypal: https://paypal.me/nixnote2
