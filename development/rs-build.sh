#!/bin/bash

QMAKE=/d/dev/Qt/5.5/gcc_64/bin/qmake

$QMAKE CONFIG+=debug && make && linuxdeployqt nixnote2 -qmake=$QMAKE -appimage
