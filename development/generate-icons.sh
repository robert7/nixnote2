#!/bin/bash
# convenience short cut

CD=`pwd`
cd resources/icons/hicolor

for S in 48 128 256 512; do
   echo "Creating ${S}px icon"
   inkscape -z -e ${S}x${S}/apps/nixnote2.png -w ${S} -h ${S} scalable/apps/nixnote2.svg
done

cd $CD

S=128
cp resources/icons/hicolor/${S}x${S}/apps/nixnote2.png resources/images/windowIcon.png
cp resources/icons/hicolor/${S}x${S}/apps/nixnote2.png resources/images/trayicon.png
cp resources/icons/hicolor/${S}x${S}/apps/nixnote2.png resources/images/splash_logo.png




