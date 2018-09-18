#!/bin/bash

if [ ! -f ./development/common-include.sh ]; then
  echo "You seem to be in wrong directory. script MUST be run from the project directory."
  exit 1
fi

function error_exit {
    echo "***********error_exit***********"
    echo "***********" 1>&2
    echo "*********** Failed: $1" 1>&2
    echo "***********" 1>&2
    exit 1
}

# common settings/directories etc
# ..

