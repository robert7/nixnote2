#!/bin/bash
# here we expected that the particular version of qmake, you want to use, is found on PATH
# so if you want to use something different then default, make sure you adjust path before calling this script
set -xe

BUILD_TYPE=${1}
CLEAN=${2}
TIDY_LIB_DIR=${3}
CDIR=`pwd`

function error_exit {
    echo "$0: ***********error_exit***********"
    echo "***********" 1>&2
    echo "*********** Failed: $1" 1>&2
    echo "***********" 1>&2
    cd ${CDIR}
    exit 1
}

if [ ! -f src/main.cpp ]; then
  echo "$0: You seem to be in wrong directory. script MUST be run from the project directory."
  exit 1
fi

if [ -z "${BUILD_TYPE}" ]; then
    BUILD_TYPE=debug
fi
BUILD_DIR=qmake-build-${BUILD_TYPE}

if [ "${CLEAN}" == "clean" ]; then
  echo "Clean build: ${BUILD_DIR}"
  if [ -d "${BUILD_DIR}" ]; then
    rm -rf ${BUILD_DIR}
  fi
fi

if [ -z "${TIDY_LIB_DIR}" ]; then
   # system default
   TIDY_LIB_DIR=/usr/lib
fi
if [ ! -d "${TIDY_LIB_DIR}" ]; then
   echo "TIDY_LIB_DIR (${TIDY_LIB_DIR}) is not a directory"
   exit 1
fi
echo "$0: libtidy is expected in: ${TIDY_LIB_DIR}"

if [ ! -d "${BUILD_DIR}" ]; then
  mkdir ${BUILD_DIR}
fi

echo "${BUILD_DIR}">_build_dir_.txt

APPDIR=appdir
if [ -d "${APPDIR}" ]; then
  rm -rf ${APPDIR}/* || echo "failed to remove"
  rm *.AppImage 2>/dev/null || echo "failed to remove"
fi


QMAKE_BINARY=qmake

if [ "${TIDY_LIB_DIR}" == "/usr/lib" ] ; then
  # at least on ubuntu pkgconfig for "libtidy-dev" is not installed - so we provide default
  # there could be better option
  # check: env PKG_CONFIG_PATH=./development/pkgconfig pkg-config --libs --cflags tidy
  CDIR=`pwd`
  echo export PKG_CONFIG_PATH=${CDIR}/development/pkgconfig
  export PKG_CONFIG_PATH=${CDIR}/development/pkgconfig
elif [ -d ${TIDY_LIB_DIR}/pkgconfig ] ; then
  echo export PKG_CONFIG_PATH=${TIDY_LIB_DIR}/pkgconfig
  export PKG_CONFIG_PATH=${TIDY_LIB_DIR}/pkgconfig
fi


echo ${QMAKE_BINARY} CONFIG+=${BUILD_TYPE} PREFIX=appdir/usr QMAKE_RPATHDIR+=${TIDY_LIB_DIR} || error_exit "$0: qmake"
${QMAKE_BINARY} CONFIG+=${BUILD_TYPE} PREFIX=appdir/usr QMAKE_RPATHDIR+=${TIDY_LIB_DIR} || error_exit "$0: qmake"

make -j$(nproc) || error_exit "$0: make"
make -j$(nproc) install || error_exit "$0: make install"

cp changelog.txt debian/changelog
