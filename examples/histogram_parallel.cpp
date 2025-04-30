// The original work is licensed under the Creative Commons Attribution 4.0 International License.
// See https://creativecommons.org/licenses/by/4.0/ or refer to the LICENSE file for details.
//
// Modifications Copyright (C) 2025 Advanced Micro Devices, Inc. All rights reserved.

#include "histogram_parallel.h"
void histogram_map(int in[INPUT_SIZE/2], int hist[VALUE_SIZE]) {
  histogram_map_loop_1: for(int i = 0; i < VALUE_SIZE; i++) {
#pragma HLS PIPELINE II=1
    hist[i] = 0;
  }
  int old = in[0];
  int acc = 0;
  histogram_map_loop_2: for(int i = 0; i < INPUT_SIZE/2; i++) {
#pragma HLS PIPELINE II=1
#pragma HLS DEPENDENCE variable=hist intra RAW false
    int val = in[i];
    if(old == val) {
      acc = acc + 1;
    } else {
      hist[old] = acc;
      acc = hist[val] + 1;
    }
    old = val;
  }
  hist[old] = acc;
}

void histogram_reduce(int hist1[VALUE_SIZE], int hist2[VALUE_SIZE], int output[VALUE_SIZE]) {
  histogram_reduce_loop_1: for(int i = 0; i < VALUE_SIZE; i++) {
#pragma HLS PIPELINE II=1
    output[i] = hist1[i] + hist2[i];
  }
}

//Top level function
void histogram(int inputA[INPUT_SIZE/2], int inputB[INPUT_SIZE/2], int hist[VALUE_SIZE]){
  #pragma HLS DATAFLOW
  int hist1[VALUE_SIZE];
  int hist2[VALUE_SIZE];

  histogram_map(inputA, hist1);
  histogram_map(inputB, hist2);
  histogram_reduce(hist1, hist2, hist);
}
