/*
 * The original work is licensed under the Creative Commons Attribution 4.0 International License.
 * See https://creativecommons.org/licenses/by/4.0/ or refer to the LICENSE file for details.
 *
 * Modifications Copyright (C) 2025 Advanced Micro Devices, Inc. All rights reserved.
 */


#include "block_fir.h"

void block_fir(int input[256], int output[256], int taps[NUM_TAPS],
							 int delay_line[NUM_TAPS]) {	
	int i, j;
	block_fir_loop_1: for (j = 0; j < 256; j++) {
		int result = 0;
		for (i = NUM_TAPS - 1; i > 0; i--) {
#pragma HLS unroll
			delay_line[i] = delay_line[i - 1];
		}
		delay_line[0] = input[j];

		for (i = 0; i < NUM_TAPS; i++) {
#pragma HLS pipeline
			result += delay_line[i] * taps[i];
		}
		output[j] = result;
	}
}
