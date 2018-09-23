#!/bin/bash
# workaround helper script example for Import Folders
#
# actually this not needed anymore, see end of the https://github.com/robert7/nixnote2/issues/14


if [ ! -f "$1" ]; then echo 1st param needs to be existing file!; exit 1; fi
if [ ! -d "$2" ]; then echo 2nd param needs to be existing directory!; exit 1; fi


# copy file with ".tmp" file extension to targed directory
cp $1 $2/$1.tmp

# rename file to original name
mv $2/$1.tmp $2/$1
