/*
 * The original work is licensed under the Creative Commons Attribution 4.0 International License.
 * See https://creativecommons.org/licenses/by/4.0/ or refer to the LICENSE file for details.
 *
 * Modifications Copyright (C) 2025 Advanced Micro Devices, Inc. All rights reserved.
 */


#include "stdio.h"

typedef int coef_t;
typedef int data_t;
typedef int acc_t;

const int SIZE = 256;

void fir(data_t *y, data_t x);

int main() {
	int out = 0;
	for (int i = 0; i < SIZE; i++) {
		fir(&out, i);
	}
	printf("result = %d\n", out);
	if (out == 262500) {
		return 0;
	} else {
		return 1;
	}
}
