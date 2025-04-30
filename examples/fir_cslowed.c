/*
 * The original work is licensed under the Creative Commons Attribution 4.0 International License.
 * See https://creativecommons.org/licenses/by/4.0/ or refer to the LICENSE file for details.
 *
 * Modifications Copyright (C) 2025 Advanced Micro Devices, Inc. All rights reserved.
 */


#include "fir_cslowed.h"


void block_fir(int input[SIZE][K], int output[SIZE][K], int taps[NUM_TAPS],
							 int delay_line[NUM_TAPS][K]) {
	int i, j, k; 
	for (j = 0; j < SIZE; j++) {
		for (k = 0; k < K; k++) {
			int result[K] = {0};
			for (i = NUM_TAPS - 1; i > 0; i--) {
#pragma HLS unroll
				delay_line[i][k] = delay_line[i - 1][k];
			}
			delay_line[0][k] = input[j][k];

			for (i = 0; i < NUM_TAPS; i++) {
#pragma HLS pipeline
				result[k] += delay_line[i][k] * taps[i];
			}
			output[j][k] = result[k];
		}
	}
}
