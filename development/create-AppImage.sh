#!/bin/bash

PROG=nixnote2
DESKTOP_FILE=appdir/usr/share/applications/${PROG}.desktop

BUILD_DIR=$(cat _build_dir_.txt)
echo Build dir: ${BUILD_DIR}

QT_DIR=$(cat ${BUILD_DIR}/qt-dir.txt)
QMAKE_BINARY=${QT_DIR}/bin/qmake

echo QT_DIR=${QT_DIR}, QMAKE_BINARY=${QMAKE_BINARY}


if [ ! -f "$DESKTOP_FILE" ]; then
    echo "$DESKTOP_FILE not found!"
    exit 1
fi

export VERSION=$(cat version.txt)
echo Version: ${VERSION}

CMD="linuxdeployqt $DESKTOP_FILE -qmake=${QMAKE_BINARY} -bundle-non-qt-libs"
echo About to run: $CMD
$CMD

CMD="linuxdeployqt $DESKTOP_FILE -qmake=${QMAKE_BINARY} -appimage"
echo About to run: $CMD
$CMD
