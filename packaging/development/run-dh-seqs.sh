#!/bin/bash

# this is approximation of test run for debian "rules"
# convenience helper only
# its not really exact, but may catch some mistakes
# it must be run *after* running recipe & any local changes must be copied manually

CDIR=`pwd`
echo Current dir: $CDIR
DEV_DIR=`dirname $0`
cd ${DEV_DIR}/..
PROJ_DIR=`pwd`
echo Project dir: $PROJ_DIR
. ${PROJ_DIR}/development/common-include.sh

RECIPE_NAME=$1
if [ -z "${RECIPE_NAME}" ] || [ ! -d "${RECIPE_NAME}" ]; then
  echo "1st param must me recipe name (directory)"
  exit 1
fi

DIR_WITH_RECIPE=build-${RECIPE_NAME}/launchpad-recipe
if [ ! -d ${DIR_WITH_RECIPE} ]; then
  echo "Directory with recipe content doesn't exist (you should run run-recipe.sh before)"
  exit 1
fi


cd ${DIR_WITH_RECIPE}

dh clean --without=build-stamp                        || error_exit "dh clean"

#dh build-arch --without=build-stamp                   || error_exit "dh build-arch"

fakeroot dh binary --without=build-stamp              || error_exit "dh binary"

cd $CDIR


