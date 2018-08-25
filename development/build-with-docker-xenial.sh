#!/bin/bash
PROJECTBRANCH=${1}
PROJECTDIR=`pwd`

function error_exit {
    echo "***********error_exit***********"
    echo "***********" 1>&2
    echo "*********** Failed: $1" 1>&2
    echo "***********" 1>&2
    #cd ${CDIR}
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
docker build -t nixnote2/xenial -f ./development/docker/Dockerfile.ubuntu_xenial ./development/docker
# delete appdir content
rm -rf appdir; mkdir appdir

# start container (note: each call creates new container)
docker run -v $PROJECTDIR/appdir:/opt/nixnote2/appdir -it nixnote2/xenial \
   /bin/bash -c "cd nixnote2 && git fetch && git checkout $PROJECTBRANCH && git pull && ./development/build-with-qmake.sh /usr debug && ./development/create-AppImage.sh && mv *.AppImage appdir && chmod -R a+rwx appdir"

ls appdir/*.AppImage
echo "If all got well then AppImage file in appdir is your binary"

cd $PROJECTDIR