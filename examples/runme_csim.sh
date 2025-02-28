#!/bin/bash

export BLOCK=$1 ; rm -rf ${BLOCK}.comp/ ${BLOCK}.tcl ; CSIM="--csim" make ${BLOCK}.comp
