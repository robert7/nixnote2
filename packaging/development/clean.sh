#!/bin/bash

DEV_DIR=`dirname $0`
. ${DEV_DIR}/common-include.sh

for i in build* ; do
  if [ -d $i ] ; then
     echo Clean: removing directory $i
     rm -rf $i || error_exit "rm directory \"$i\""
  fi
  if [ -f $i ] ; then
     echo Removing file $i || error_exit "rm file \"$i\""
     rm -f $i
  fi
done

echo Clean: OK
