#!/bin/bash

# If VITIS_HLS_ARGS is set then add to the make call below
export BLOCK=$1
rm -rf ${BLOCK}.comp/ ${BLOCK}.tcl
VITIS_HLS_ARGS=${VITIS_HLS_ARGS:+$VITIS_HLS_ARGS} CSIM="--csim" COSIM="--cosim" CSYNTH="--csynth" make ${BLOCK}.comp
