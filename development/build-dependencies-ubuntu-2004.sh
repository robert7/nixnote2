#!/bin/bash

## 2023.04: this file is not updated see docker/Dockerfile.ubuntu_focal


# preparation
# sudo apt update
# sudo apt upgrade

sudo add-apt-repository ppa:nixnote/nixnote2-stable -y
sudo apt-get update -qq

sudo apt-get -y install git-core qt5-default build-essential \
                            wget curl make pkg-config \
                            libboost-dev libboost-test-dev libboost-program-options-dev libevent-dev libcurl4-openssl-dev \
                            libpoppler-qt5-dev libqt5webkit5-dev qt5-qmake qttools5-dev-tools libqt5sql5-sqlite \
                            libhunspell-dev \
                            nixnote2-tidy

# sudo apt install git
# cd $HOME
# git clone https://github.com/robert7/nixnote2.git
# cd nixnote2

# now build with e.g.
# ./development/build-with-qmake.sh debug noclean /usr/lib/nixnote2/tidy
# then binary is in: ./qmake-build-debug/nixnote2
# cd appdir
# ./usr/appdir/nixnote2
