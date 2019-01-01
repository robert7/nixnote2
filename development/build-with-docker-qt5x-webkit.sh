#!/bin/bash

# ############
# !! EXPERIMENTAL build with qt >5.5 and community version of Qt WebKit https://github.com/annulen/webkit
# ############

PROJECTBRANCH=${1}
PROJECTDIR=`pwd`
set -xe

NNQTVER=qt511
DOCKERMODIFIER=_$NNQTVER
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

if [ ! -d appdir ] ; then
  mkdir appdir
fi

# cleanup
BUILD_TYPE=release
rm -rf appdir || error_exit "rm appdir"
rm -rf docker-build-${BUILD_TYPE} || error_exit "rm docker-build-${BUILD_TYPE}"


if [ ! -d docker-build-${BUILD_TYPE} ]; then
  mkdir docker-build-${BUILD_TYPE}
fi


echo "EXPERIMENTAL build with qt >5.5 and community version of webkit https://github.com/annulen/webkit"
echo "(for now) rest of the commands should be entered manually in docker container console"

PROG=nixnote2
DESKTOP_FILE=appdir/usr/share/applications/${PROG}.desktop

time docker run \
   --rm \
   -v $PROJECTDIR/appdir:/opt/nixnote2/appdir \
   -v $PROJECTDIR/docker-build-${BUILD_TYPE}:/opt/nixnote2/qmake-build-${BUILD_TYPE} \
   -v $PROJECTDIR/docker-build-${BUILD_TYPE}-t:/opt/nixnote2/qmake-build-${BUILD_TYPE}-t \
   -it ${DOCKERTAG} \
      /bin/bash -c "cd /opt && wget https://github.com/robert7/nixnote2-packaging/releases/download/v2.1.2/qtwebkit-$NNQTVER-binaries.tgz && cd /opt/$NNQTVER && tar -xf /opt/qtwebkit-$NNQTVER-binaries.tgz && cd /opt/nixnote2 && git fetch && git checkout $PROJECTBRANCH && git pull && source /opt/qt5*/bin/qt*-env.sh && ./development/build-with-qmake.sh ${BUILD_TYPE} noclean /usr/lib/nixnote2/tidy && cd /opt/nixnote2 && unset QTDIR && unset QT_PLUGIN_PATH && unset QT_BASE_DIR && unset LD_LIBRARY_PATH && linuxdeployqt $DESKTOP_FILE -appimage && mv *.AppImage appdir && chmod -R a+rwx appdir"

###################################################################################################################################
# manually run following commands in docker container console:

#### install and compile webkit
## cd /opt && git clone git://code.qt.io/qt/qtwebkit.git; source /opt/qt5*/bin/qt*-env.sh && cd qtwebkit && mkdir -p WebKitBuild/Release && cd WebKitBuild/Release && cmake -DPORT=Qt -DCMAKE_BUILD_TYPE=Release ../.. && make -j$(nproc) && make install

#### OPTIONAL: create tarball with webkit binaries
## cd /opt/qtwebkit/WebKitBuild/Release && make DESTDIR=/opt/qtwebkit-$NNQTVER-binaries install && cd /opt/qtwebkit-$NNQTVER-binaries/opt/$NNQTVER && tar -zcf /opt/nixnote2/appdir/qtwebkit-$NNQTVER-binaries.tgz * && cd /opt
####

#### ALTERNATIVE to webkit "compile from source" (as it takes ages): use prebuild webkit binaries
## cd /opt && wget https://github.com/robert7/nixnote2-packaging/releases/download/v2.1.2/qtwebkit-$NNQTVER-binaries.tgz && cd /opt/$NNQTVER && tar -xf /opt/qtwebkit-$NNQTVER-binaries.tgz

#### compile nixnote and create AppImage - at the end resulting binary is copied to "appdir" which is mapped from host machine
## PROJECTBRANCH=master && BUILD_TYPE=release && cd /opt/nixnote2 && git fetch && git checkout $PROJECTBRANCH && git pull && source /opt/qt5*/bin/qt*-env.sh && ./development/build-with-qmake.sh ${BUILD_TYPE} noclean /usr/lib/nixnote2/tidy && cd /opt/nixnote2 && unset QTDIR && unset QT_PLUGIN_PATH && unset QT_BASE_DIR && unset LD_LIBRARY_PATH && PROG=nixnote2 && DESKTOP_FILE=appdir/usr/share/applications/${PROG}.desktop && linuxdeployqt $DESKTOP_FILE -appimage && mv *.AppImage appdir && chmod -R a+rwx appdir


