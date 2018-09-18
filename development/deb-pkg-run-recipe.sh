#!/bin/bash


CDIR=`pwd`
echo Current dir: $CDIR
DEV_DIR=`dirname $0`
cd ${DEV_DIR}/..
PROJ_DIR=`pwd`
echo Project dir: $PROJ_DIR
. ${PROJ_DIR}/development/common-include.sh

RECIPE_NAME=$1
RECIPE_FILE=./packaging/launchpad-recipe-${RECIPE_NAME}
if [ -z "${RECIPE_NAME}" ] || [ ! -f "${RECIPE_FILE}" ]; then
  echo "1st param must me recipe name - expected recipe file: ${RECIPE_FILE}"
  exit 1
fi
USE_DISTRIBUTION=$2
if [ -z "${USE_DISTRIBUTION}" ]; then
  USE_DISTRIBUTION=bionic
fi

./development/deb-pkg-clean.sh

git-build-recipe --allow-fallback-to-native --distribution ${USE_DISTRIBUTION} ${RECIPE_FILE} build-pkg-${RECIPE_NAME}

cd $CDIR

