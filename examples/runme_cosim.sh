#!/bin/bash

export BLOCK=$1 ; rm -rf ${BLOCK}.comp/ ${BLOCK}.tcl ; CSIM="--csim" COSIM="--cosim" CSYNTH="--csynth" make ${BLOCK}.comp
