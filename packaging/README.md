# Debian packaging for nixnote21 

..work in progress :) as I try to figure out the magic behind debian packages

Test run packaging (aproximate local simulation):
```bash
# ppa is used for tidy-html56
sudo add-apt-repository ppa:robert7/nixnote21
sudo apt-get update

sudo apt -y install dh-make git git-build-recipe javahelper default-jdk \
   libboost-dev libcurl4-openssl-dev libhunspell-dev libpoppler-qt5-dev \
   libqt5webkit5-dev libswscale-dev tidy-html56 qml qt5-qmake qtbase5-dev \
   qttools5-dev-tools build-essential pkg-config

git clone https://github.com/robert7/nixnote2-packaging.git
cd nixnote2-packaging

# test run part #1
./development/run-recipe.sh nixnote21 bionic

# if OK, then part #2:
./development/run-dh-seqs.sh nixnote21
```
