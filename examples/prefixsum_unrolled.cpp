// The original work is licensed under the Creative Commons Attribution 4.0 International License.
// See https://creativecommons.org/licenses/by/4.0/ or refer to the LICENSE file for details.
//
// Modifications Copyright (C) 2025 Advanced Micro Devices, Inc. All rights reserved.

#define SIZE 128

void prefixsum(int in[SIZE], int out[SIZE]) {
  #pragma HLS ARRAY_PARTITION variable=out cyclic factor=4 dim=1
  #pragma HLS ARRAY_PARTITION variable=in cyclic factor=4 dim=1
  out[0] = in[0];
  
  prefixsum_loop_1: for(int i=1; i < SIZE; i++) {
    #pragma HLS UNROLL factor=4
    #pragma HLS PIPELINE II=1
    out[i] = out[i-1] + in[i];
  }
}
