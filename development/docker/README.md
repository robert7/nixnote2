# docker build helper

WORK IN PROGRESS

docker build -t nixnote2/trusty -f Dockerfile.ubuntu_trusty .
docker run -it nixnote2/trusty /bin/bash

HOW TO USE

?????????????
run docker container interactively and allow access to fuse device
docker run -it --cap-add SYS_ADMIN --device /dev/fuse trustylab
enter labpowerqt build directory and run linuxdeployqt


source /opt/qt5*/bin/qt5*-env.sh
./linuxdeployqt appdir/usr/share/applications/*.desktop -bundle-non-qt-libs && \
./linuxdeployqt appdir/usr/share/applications/*.desktop -appimage

use docker cp to copy the generated appimage. the appimage has the same
architecture than the host system.

