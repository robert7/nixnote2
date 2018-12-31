#!/bin/bash
PROJECTBRANCH=${1}
PROJECTDIR=`pwd`
set -xe

# note: all with DOCKERMODIFIER != "" is highly experimental and needs "someway" to include webkit binaries
# so without it will fail
#DOCKERMODIFIER=_qt562

DOCKERTAG=nixnote2/xenial${DOCKERMODIFIER}
DOCKERFILE=./development/docker/Dockerfile.ubuntu_xenial${DOCKERMODIFIER}

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
if [ ! -z ${DOCKERMODIFIER} ] ; then
  echo "Docker image ${DOCKERTAG} created.. "
  echo "DOCKERMODIFIER set to $DOCKERMODIFIER .. you need to provide webkit manually.."
  exit 1
fi

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



# to try manually:
#   DOCKERTAG=..
#   docker run --rm  -it ${DOCKERTAG} /bin/bash
#    then
#      PROJECTBRANCH=feature/rc1
#      BUILD_TYPE=release
#      ...copy command from bellow & paste..
# --------------------

# **TEMPORARY** for beineri PPA recompile #################
# PROJECTBRANCH=feature/rc1;BUILD_TYPE=release
# source /opt/qt*/bin/qt*-env.sh
# git fetch && git checkout $PROJECTBRANCH && git pull  && ./development/build-with-qmake.sh ${BUILD_TYPE} noclean /usr/lib/nixnote2/tidy
# unset QTDIR; unset QT_PLUGIN_PATH ; unset LD_LIBRARY_PATH
# ./development/create-AppImage.sh
# mv *.AppImage appdir2 && chmod -R a+rwx appdir/*.AppImage

time docker run \
   --rm \
   -v $PROJECTDIR/appdir:/opt/nixnote2/appdir \
   -v $PROJECTDIR/docker-build-${BUILD_TYPE}:/opt/nixnote2/qmake-build-${BUILD_TYPE} \
   -v $PROJECTDIR/docker-build-${BUILD_TYPE}-t:/opt/nixnote2/qmake-build-${BUILD_TYPE}-t \
   -it ${DOCKERTAG} \
      /bin/bash -c "cd nixnote2 && git fetch && git checkout $PROJECTBRANCH && git pull  && ./development/build-with-qmake.sh ${BUILD_TYPE} noclean /usr/lib/nixnote2/tidy && ./development/run-tests.sh ${BUILD_TYPE} noclean /usr/lib/nixnote2/tidy && ./development/create-AppImage.sh && mv *.AppImage appdir && chmod -R a+rwx appdir/*.AppImage"

ls appdir/*.AppImage
echo "If all got well then AppImage file in appdir is your binary"

cd $PROJECTDIR
