#!/bin/bash

function error_exit {
    echo "***********error_exit***********"
    echo "***********" 1>&2
    echo "*********** Failed: $1" 1>&2
    echo "***********" 1>&2
    cd ${CDIR}
    exit 1
}

DESTDIR=$1
echo $0: DESTDIR=${DESTDIR}

if [ -z "${DESTDIR}" ]; then
  echo "Missing param1 (DESTDIR)"
  exit 1
fi

VERSION=$(head ./debian/changelog --lines=1|sed -E 's/^[^(]*\(([^)]*).*/\1/g')
GITHASH=$(git rev-parse --short HEAD)
if [ -z "${GITHASH}" ] ; then
  echo "Seems getting git version failed.."
  BUILDVER="${VERSION}"
else 
  BUILDVER="${VERSION}-${GITHASH}"
fi


echo Version: ${VERSION}
echo Git hash: ${GITHASH}

ODIR=${DESTDIR}/version

mkdir -p ${ODIR} || error_exit "mkdir"
echo "${BUILDVER}" >${ODIR}/build-version.txt || error_exit "echo build-version"
echo "${VERSION}" >${ODIR}/version.txt || error_exit "echo version"
