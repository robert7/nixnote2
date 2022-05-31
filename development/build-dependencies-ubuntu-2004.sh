#!/bin/bash
sudo add-apt-repository ppa:nixnote/nixnote2-stable -y
sudo apt-get update -qq

sudo apt-get -y install git-core qt5-default build-essential \
                            wget curl make pkg-config \
                            libboost-dev libboost-test-dev libboost-program-options-dev libevent-dev libcurl4-openssl-dev \
                            libpoppler-qt5-dev libqt5webkit5-dev qt5-qmake qttools5-dev-tools libqt5sql5-sqlite \
                            libhunspell-dev \
                            nixnote2-tidy

# now build with e.g.
# ./development/build-with-qmake.sh debug noclean /usr/lib/nixnote2/tidy
# then binary: ./qmake-build-debug/nixnote2
# run with: ./appdir/usr/appdir/nixnote2