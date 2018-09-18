#!/bin/bash

OF=$1
if [ -z "${OF}" ]; then
  echo missing param1
  exit 1
fi

VERSION=$(cat version.txt)
GITHASH=$(git rev-parse --short HEAD)
echo Version: ${VERSION}
echo Git hash: ${GITHASH}


echo "${VERSION}-${GITHASH}" >${OF}
