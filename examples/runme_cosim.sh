#!/bin/bash

export BLOCK=$1 ; rm -rf ${BLOCK}.comp/ ${BLOCK}.tcl ; COSIM="--cosim" CSYNTH="--csynth" make ${BLOCK}.comp
