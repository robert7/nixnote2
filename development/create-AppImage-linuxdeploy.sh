#!/bin/bash

PROG=nixnote2
DESKTOP_FILE=appdir/usr/share/applications/${PROG}.desktop

BUILD_DIR=$(cat _build_dir_.txt)
echo Build dir: ${BUILD_DIR}

if [ ! -f "$DESKTOP_FILE" ]; then
    echo "$DESKTOP_FILE not found!"
    exit 1
fi

export VERSIONX=$(cat appdir/usr/share/nixnote2/version.txt)
echo Version: ${VERSIONX}

# First, create appdir with bundled binaries
CMD="linuxdeploy --desktop-file=$DESKTOP_FILE --appdir=appdir --plugin qt"
echo About to run: $CMD
$CMD

# Then remove nss libs from the AppDir as they are known to cause troubles, see
# https://github.com/probonopd/linuxdeployqt/issues/35
rm -f appdir/usr/lib/libnss3.so
rm -f appdir/usr/lib/libnssutil3.so

# Now create the actual appimage
echo "Creating AppImage"
appimagetool -n appdir
