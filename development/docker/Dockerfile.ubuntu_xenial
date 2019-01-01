FROM ubuntu:xenial

ARG wdir="/opt"
WORKDIR $wdir

#ARG cmake_ver="cmake-3.8.0-Linux-x86_64"
#ENV PATH="${wdir}/${cmake_ver}/bin:${PATH}"

ARG make_core=4
ENV PATH="${wdir}/linuxdeployqt:${PATH}"

RUN apt-get update && apt-get install -y software-properties-common
RUN add-apt-repository ppa:nixnote/nixnote2-stable -y && apt-get update -qq
RUN apt-get update && apt-get install -y git-core qt5-default build-essential \
                              wget curl make pkg-config \
                              libboost-dev libboost-test-dev libboost-program-options-dev libevent-dev libcurl4-openssl-dev \
                              libpoppler-qt5-dev libqt5webkit5-dev qt5-qmake qttools5-dev-tools libhunspell-dev nixnote2-tidy


# now not needed anymore
# install cmake
#RUN wget -nv "https://cmake.org/files/v3.8/${cmake_ver}.tar.gz" && \
#        tar -xf "${cmake_ver}.tar.gz"

# install linuxdeployqt
RUN wget -nv "https://github.com/probonopd/linuxdeployqt/releases/download/continuous/linuxdeployqt-continuous-x86_64.AppImage" && \
        chmod a+x ./linuxdeployqt-continuous-x86_64.AppImage && \
        ./linuxdeployqt-continuous-x86_64.AppImage --appimage-extract && \
        mv squashfs-root linuxdeployqt && \
        mv linuxdeployqt/AppRun linuxdeployqt/linuxdeployqt

# now not needed anymore (installed as package)
# compile tidy
#ARG GIT_REV_TIDY="HEAD"
#ARG GIT_BRANCH_TIDY="master"
#RUN cd $wdir && git clone -b $GIT_BRANCH_TIDY "https://github.com/htacg/tidy-html5.git" && \
#        cd tidy-html5 && \
#        git checkout $GIT_REV_TIDY && \
#        cd build/cmake && \
#        cmake ../..  -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release && \
#        make -j $make_core && \
#        make install

RUN cd $wdir && git clone "https://github.com/robert7/nixnote2.git" && cd nixnote2 && git checkout master

CMD /bin/bash

