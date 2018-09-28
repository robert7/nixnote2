#!/bin/bash

OF=$1
if [ -z "${OF}" ]; then
  echo "Missing param1 (output filename)"
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

echo "${BUILDVER}" >${OF}
