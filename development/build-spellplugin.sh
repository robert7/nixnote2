#!/bin/bash
CDIR=`pwd`
BUILD_TYPE=$1
DESTDIR=$2
echo $0: BUILD_TYPE=$1, DESTDIR=$2
if [ -z "${DESTDIR}" ] || [ ! -d "${DESTDIR}" ] ; then
  echo "$0: wrong params: 1st param: config (debug/release), 2nd param: destination directory for build"
  exit 1
fi


function error_exit {
    echo "***********error_exit***********"
    echo "***********" 1>&2
    echo "*********** Failed: $1" 1>&2
    echo "***********" 1>&2
    cd ${CDIR}
    exit 1
}

cd src/plugins/hunspell || error_exit "cd"
qmake CONFIG+=${BUILD_TYPE} || error_exit "qmake"
make || error_exit "make"

cd $CDIR

