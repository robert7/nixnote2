#!/bin/bash
PROJECTBRANCH=${1}
PROJECTDIR=`pwd`
set -xe

DOCKERTAG=nixnote2/focal
DOCKERFILE=./development/docker/Dockerfile.ubuntu_focal

function error_exit {
    echo "$0: ***********error_exit***********"
    echo "***********" 1>&2
    echo "*********** Failed: $1" 1>&2
    echo "***********" 1>&2
    cd ${CDIR}
    exit 1
}

if [ ! -f src/main.cpp ]; then
  echo "You seem to be in wrong directory. script MUST be run from the project directory."
  exit 1
fi

if [ -z "${PROJECTBRANCH}" ]; then
    PROJECTBRANCH=master
fi

cd $PROJECTDIR
# create "builder" image
docker build -t ${DOCKERTAG} -f ${DOCKERFILE} ./development/docker

# stop after creating the image (e.g. you want to do the build manually)
if [ ! -d appdir ] ; then
  mkdir appdir || error_exit "mkdir appdir"
fi

# delete appdir content
rm -rf appdir/* || error_exit "rm appdir"

BUILD_TYPE=release

if [ ! -d docker-build-${BUILD_TYPE} ]; then
  mkdir docker-build-${BUILD_TYPE}
fi

# start container (note: each call creates new container)
time docker run \
   --rm \
   -v $PROJECTDIR/appdir:/opt/nixnote2/appdir \
   -v $PROJECTDIR/docker-build-${BUILD_TYPE}:/opt/nixnote2/qmake-build-${BUILD_TYPE} \
   -v $PROJECTDIR/docker-build-${BUILD_TYPE}-t:/opt/nixnote2/qmake-build-${BUILD_TYPE}-t \
   -it ${DOCKERTAG} \
      /bin/bash -c "cd nixnote2 && git fetch && git checkout --track origin/$PROJECTBRANCH && git reset --hard origin/$PROJECTBRANCH && ./development/build-with-qmake.sh ${BUILD_TYPE} noclean /usr/lib browser && ./development/run-tests.sh ${BUILD_TYPE} noclean /usr/lib && ./development/create-AppImage-linuxdeploy.sh && mv *.AppImage appdir && chmod -R a+rwx appdir/*.AppImage"

ls appdir/*.AppImage
echo "If all got well then AppImage file in appdir is your binary"

cd $PROJECTDIR
