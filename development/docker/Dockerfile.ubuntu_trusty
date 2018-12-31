FROM ubuntu:trusty

#
# unfortunately this doesn't work
# ..but, as "trusty" is reaching "end of life" I never bothered to fix the build
# so I only leave it for reference
# currently the AppImage build with "xenial"
#

ARG wdir="/opt"
WORKDIR $wdir

ARG cmake_ver="cmake-3.8.0-Linux-x86_64"
ARG make_core=4
ENV PATH="${wdir}/${cmake_ver}/bin:${PATH}"
ENV PATH="${wdir}/linuxdeployqt:${PATH}"

RUN apt-get update && apt-get install -y software-properties-common

# install Qt 5.5 from PPA - https://launchpad.net/~beineri/+archive/ubuntu/opt-qt551-trusty
# note: trusty would have 5.3 per default
ENV PATH="/opt/qt55/bin:${PATH}"
RUN add-apt-repository ppa:beineri/opt-qt551-trusty -y
RUN add-apt-repository ppa:beineri/opt-qt551-trusty -y && apt-get update

RUN apt-get update && apt-get install -y git-core build-essential \
                              wget curl make \
                              libboost-dev libboost-test-dev libboost-program-options-dev libevent-dev libcurl4-openssl-dev \
                              qt55base \
                              libpoppler-qt5-dev \
                              qttools5-dev-tools \
                              qt55tools qt55script qt55quick1 qt55webengine qt55webkit-examples qt55quickcontrols qt553d

# install cmake
RUN wget -nv "https://cmake.org/files/v3.8/${cmake_ver}.tar.gz" && \
        tar -xf "${cmake_ver}.tar.gz"

# install linuxdeployqt
RUN wget -nv "https://github.com/probonopd/linuxdeployqt/releases/download/continuous/linuxdeployqt-continuous-x86_64.AppImage" && \
        chmod a+x ./linuxdeployqt-continuous-x86_64.AppImage && \
        ./linuxdeployqt-continuous-x86_64.AppImage --appimage-extract && \
        mv squashfs-root linuxdeployqt && \
        mv linuxdeployqt/AppRun linuxdeployqt/linuxdeployqt

# compile tidy
ARG git_rev_tidy="HEAD"
ARG git_branch_tidy="master"
RUN cd $wdir && git clone -b $git_branch_tidy "https://github.com/htacg/tidy-html5.git" && \
        cd tidy-html5 && \
        git checkout $git_rev_tidy && \
        cd build/cmake && \
        cmake ../..  -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release && \
        make -j $make_core && \
        make install

# use git_rev to make sure the last layers are run again, if there are new commits
ARG git_rev1="HEAD"
ARG git_rev="HEAD"
ARG git_branch="feature/rs-9-alfa"
RUN cd $wdir && git clone -b $git_branch "https://github.com/robert7/nixnote2.git" && \
        cd nixnote2 && \
        git checkout $git_rev

# TODO: fix compile...

CMD /bin/bash

