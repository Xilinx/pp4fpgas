// The original work is licensed under the Creative Commons Attribution 4.0 International License.
// See https://creativecommons.org/licenses/by/4.0/ or refer to the LICENSE file for details.
//
// Modifications Copyright (C) 2025 Advanced Micro Devices, Inc. All rights reserved.

#include "histogram.h"

void histogram(int in[INPUT_SIZE], int hist[VALUE_SIZE]) {
  int val;
  histogram_loop_1: for(int i = 0; i < INPUT_SIZE; i++) {
    #pragma HLS PIPELINE
    val = in[i];
    hist[val] = hist[val] + 1;
  }
}
