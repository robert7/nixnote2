#!/bin/bash
QT_DIR=${1}
BUILD_TYPE=${2}
PROG=nixnote2

if [ -z ${QT_DIR} ]; then
    echo "Missing argument(s).."
    echo "1st argument need to be the Qr root directory."
    echo "    Note: Qt root is where './bin/qmake' is.."
    echo "2nd argument is debug|release (defaults to debug)"
    echo "Example: $0 /d/dev/Qt/5.5/gcc_64 debug"
    exit 1
fi
if [ -z "${BUILD_TYPE}" ]; then
    BUILD_TYPE=debug
fi
BUILD_DIR=qmake-build-${BUILD_TYPE}
VERSION="$(cat version.txt)-$(git rev-parse --short HEAD)"
echo $VERSION >${BUILD_DIR}/build-version.txt
echo $QT_DIR >${BUILD_DIR}/qt-dir.txt
echo "${BUILD_DIR}">_build_dir_.txt
echo Building version: ${VERSION}

APPDIR=appdir
QMAKE_BINARY=${QT_DIR}/bin/qmake

if [ ! -f "${QMAKE_BINARY}" ]; then
    echo "qmake binary (${QMAKE_BINARY}) not found!"
    exit 1
fi

# maybe later add with "clean" parameter
#if [ -d "${BUILD_DIR}" ]; then
#  rm -rf ${BUILD_DIR}
#fi

if [ -d "${APPDIR}" ]; then
  rm -rf ${APPDIR}
fi

if [ ! -d "${BUILD_DIR}" ]; then
  mkdir ${BUILD_DIR}
fi

${QMAKE_BINARY} CONFIG+=${BUILD_TYPE} PREFIX=appdir/usr
make

# this is a bit hack: we rerun qmake, to generated "install" incl. created binary
${QMAKE_BINARY} CONFIG+=${BUILD_TYPE} PREFIX=appdir/usr
make install
