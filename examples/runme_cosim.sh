#!/bin/bash

export BLOCK=$1 ; rm -rf ${BLOCK}.comp/ ${BLOCK}.tcl ; COSIM="--cosim" make ${BLOCK}.comp
