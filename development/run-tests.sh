#!/bin/bash
# compile and run tests - convenience shortcut only
set -xe

BUILD_TYPE=${1}
CLEAN=${2}
TIDY_LIB_DIR=${3}
CDIR=`pwd`
TEMP_DIR=`pwd`/tmp

function error_exit {
    echo "$0: ***********error_exit***********"
    echo "***********" 1>&2
    echo "*********** Failed: $1" 1>&2
    echo "***********" 1>&2
    cd ${CDIR}
    exit 1
}

if [ ! -f testsrc/tests.cpp ]; then
  echo "$0: You seem to be in wrong directory. script MUST be run from the project/testsrc directory."
  exit 1
fi

if [ -z "${BUILD_TYPE}" ]; then
    BUILD_TYPE=debug
fi
BUILD_DIR=qmake-build-${BUILD_TYPE}-t

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

if [ -d ${TEMP_DIR} ] ; then
  rm -rf ${TEMP_DIR}
fi
mkdir ${TEMP_DIR}


QMAKE_BINARY=qmake

if [ "${TIDY_LIB_DIR}" == "/usr/lib" ] ; then
  # at least on ubuntu pkgconfig for "libtidy-dev" is not installed - so we provide default
  # there could be better option
  # check: env PKG_CONFIG_PATH=./development/pkgconfig pkg-config --libs --cflags tidy
  CDIR=`pwd`
  echo export PKG_CONFIG_PATH=${CDIR}/../development/pkgconfig
  export PKG_CONFIG_PATH=${CDIR}/development/pkgconfig
elif [ -d ${TIDY_LIB_DIR}/pkgconfig ] ; then
  echo export PKG_CONFIG_PATH=${TIDY_LIB_DIR}/pkgconfig
  export PKG_CONFIG_PATH=${TIDY_LIB_DIR}/pkgconfig
fi

(${QMAKE_BINARY} testsrc/tests.pro CONFIG+=${BUILD_TYPE} QMAKE_RPATHDIR+=${TIDY_LIB_DIR} \
   && make \
   && ./${BUILD_DIR}/tests -platform offscreen \
) || error_exit "tests"

