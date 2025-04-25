#!/bin/bash

export BLOCK=$1
rm -rf ${BLOCK}.comp/ ${BLOCK}.tcl
VITIS_HLS_ARGS=${VITIS_HLS_ARGS:+$VITIS_HLS_ARGS}  CSIM="--csim" make ${BLOCK}.comp
