#!/bin/bash
QT_DIR=${1}
BUILD_TYPE=${2}
PROG=nixnote2

function error_exit {
    echo "***********error_exit***********"
    echo "***********" 1>&2
    echo "*********** Failed: $1" 1>&2
    echo "***********" 1>&2
    #cd ${CDIR}
    exit 1
}

if [ -z ${QT_DIR} ]; then
    echo "Missing argument(s).."
    echo "1st argument need to be the Qr root directory."
    echo "    Note: Qt root is where './bin/qmake' is.."
    echo "2nd argument is debug|release (defaults to debug)"
    echo "Example: $0 /d/dev/Qt/5.5/gcc_64 debug"
    exit 1
fi
if [ ! -f src/main.cpp ]; then
  echo "You seem to be in wrong directory. script MUST be run from the project directory."
  exit 1
fi



if [ -z "${BUILD_TYPE}" ]; then
    BUILD_TYPE=debug
fi
BUILD_DIR=qmake-build-${BUILD_TYPE}
if [ ! -d "${BUILD_DIR}" ]; then
  mkdir ${BUILD_DIR}
fi


# maybe later add with "clean" parameter
#if [ -d "${BUILD_DIR}" ]; then
#  rm -rf ${BUILD_DIR}
#fi

VERSION="$(cat version.txt)-$(git rev-parse --short HEAD)"
# for simplicity now create in both dirs
echo $VERSION >${BUILD_DIR}/build-version.txt
# this may not be needed, if we run from "appdir" during development
echo $VERSION >build-version.txt

echo $QT_DIR >${BUILD_DIR}/qt-dir.txt
echo "${BUILD_DIR}">_build_dir_.txt
echo Building version: ${VERSION}

APPDIR=appdir
if [ -d "${APPDIR}" ]; then
  rm -rf ${APPDIR}
  rm *.AppImage 2>/dev/null
fi


QMAKE_BINARY=${QT_DIR}/bin/qmake

if [ ! -f "${QMAKE_BINARY}" ]; then
    echo "qmake binary (${QMAKE_BINARY}) not found!"
    exit 1
fi


${QMAKE_BINARY} CONFIG+=${BUILD_TYPE} PREFIX=appdir/usr || error_exit "qmake"
make || error_exit "make"

# this is a bit hack: we rerun qmake, to generated "install" incl. created binary
${QMAKE_BINARY} CONFIG+=${BUILD_TYPE} PREFIX=appdir/usr || error_exit "qmake (2nd)"
make install || error_exit "make install"
