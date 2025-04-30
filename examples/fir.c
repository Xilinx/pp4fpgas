/*
 * The original work is licensed under the Creative Commons Attribution 4.0 International License.
 * See https://creativecommons.org/licenses/by/4.0/ or refer to the LICENSE file for details.
 *
 * Modifications Copyright (C) 2025 Advanced Micro Devices, Inc. All rights reserved.
 */

#include "fir.h"

void fir(int input, int *output, int taps[NUM_TAPS])
{
	static int delay_line[NUM_TAPS] = {};

	int result = 0;
	fir_loop_1: for (int i = NUM_TAPS - 1; i > 0; i--) {
		delay_line[i] = delay_line[i - 1];
	}
	delay_line[0] = input;
	
	fir_loop_2: for (int j = 0; j < NUM_TAPS; j++) {
		result += delay_line[j] * taps[j];
	}
	
	*output = result;
}
