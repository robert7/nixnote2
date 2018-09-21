#!/bin/bash

OF=$1
if [ -z "${OF}" ]; then
  echo "Missing param1 (output filename)"
  exit 1
fi

VERSION=$(cat version.txt)
GITHASH=$(xgit rev-parse --short HEAD)
if [ -z "${GITHASH}" ] ; then
  echo "Seems getting git version failed.."
  echo "--"  
  ls -la
  echo "--"  
  BUILDVER="${VERSION}"
else 
  BUILDVER="${VERSION}-${GITHASH}"
fi


echo Version: ${VERSION}
echo Git hash: ${GITHASH}

echo "${BUILDVER}" >${OF}
