#!/bin/bash

PROG=myprog
DESKTOP_FILE=appdir/usr/share/applications/${PROG}.desktop

QT_DIR=${1}
QMAKE_BINARY=${QT_DIR}/bin/qmake

if [ -z ${QT_DIR} ]; then
    echo "1st argument need to be the Qr root directory. Example: $0: /d/dev/Qt/5.5/gcc_64"
    echo "Note: Qt root is where './bin/qmake' is.."
    exit 1
fi


if [ ! -f "$DESKTOP_FILE" ]; then
    echo "$DESKTOP_FILE not found!"
    exit 1
fi

export VERSION=$(git rev-parse --short HEAD)

CMD="linuxdeployqt $DESKTOP_FILE -qmake=${QMAKE_BINARY} -bundle-non-qt-libs"
echo About to run: $CMD
$CMD

CMD="linuxdeployqt $DESKTOP_FILE -qmake=${QMAKE_BINARY} -appimage"
echo About to run: $CMD
$CMD
