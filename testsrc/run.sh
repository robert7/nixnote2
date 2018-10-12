#!/bin/bash

TYPE=debug
qmake CONFIG+=${TYPE} && make && ./qmake-build-${TYPE}/tests

