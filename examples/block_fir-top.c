/*
 * The original work is licensed under the Creative Commons Attribution 4.0 International License.
 * See https://creativecommons.org/licenses/by/4.0/ or refer to the LICENSE file for details.
 *
 * Modifications Copyright (C) 2025 Advanced Micro Devices, Inc. All rights reserved.
 */


#include "stdio.h"
#include "block_fir.h"

const int SIZE = 256;

int main() {
  int taps[] = {1,2,0,-3,0,4,-5,0,1,-2,0,-3,0,4,-5,0};
  int delay_line[NUM_TAPS] = {0};
  int input[256] = {0}, output[256] = {0};
  for(int i = 0; i < SIZE; i++) {
    input[i] = i;
    printf("input[%d] = %d output %d \n", i, input[i], output[i]);
  }

  block_fir(input, output, taps, delay_line);
  
  for(int i = 0; i < SIZE; i++) {
    printf("input[%d] = %d output %d \n", i, input[i], output[i]);
  }
  
  printf("result = %d\n", output[SIZE-1]);
  if(output[SIZE-1] == -1452) {
    return 0;
  } else {
    return 1;
  }
}

