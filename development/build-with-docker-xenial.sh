#!/bin/bash
PROJECTBRANCH=${1}
PROJECTDIR=`pwd`

if [ ! -f src/main.cpp ]; then
  echo "You seem to be in wrong directory. script MUST be run from the project directory."
  exit 1
fi

if [ -z "${PROJECTBRANCH}" ]; then
    PROJECTBRANCH=master
fi


cd $PROJECTDIR
# create "builder" image
docker build -t nixnote2/xenial -f ./development/docker/Dockerfile.ubuntu_xenial ./development/docker

# delete appdir content
rm -rf appdir
mkdir appdir

if [ -d docker-build-debug ]; then
  mkdir docker-build-debug
fi

# start container (note: each call creates new container)
time docker run \
   --rm \
   -v $PROJECTDIR/appdir:/opt/nixnote2/appdir \
   -v $PROJECTDIR/docker-build-debug:/opt/nixnote2/qmake-build-debug \
   -it nixnote2/xenial \
   /bin/bash -c "cd nixnote2 && git fetch && git checkout $PROJECTBRANCH && git pull && ./development/build-with-qmake.sh /usr debug && ./development/create-AppImage.sh && mv *.AppImage appdir && chmod -R a+rwx appdir"

ls appdir/*.AppImage
echo "If all got well then AppImage file in appdir is your binary"

cd $PROJECTDIR
