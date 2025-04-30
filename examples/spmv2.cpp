// The original work is licensed under the Creative Commons Attribution 4.0 International License.
// See https://creativecommons.org/licenses/by/4.0/ or refer to the LICENSE file for details.
//
// Modifications Copyright (C) 2025 Advanced Micro Devices, Inc. All rights reserved.

#include "spmv.h"

const static int S = 8;

void spmv(int rowPtr[NUM_ROWS+1], int columnIndex[NNZ],
       DTYPE values[NNZ], DTYPE y[SIZE], DTYPE x[SIZE])
{
#pragma HLS ARRAY_PARTITION variable=rowPtr cyclic factor=NUM_ROWS+1 dim=1

int i;
int cnt;
int LB;
int UB;
int flag;

//#pragma HLS ARRAY_PARTITION variable=cnt cyclic factor=4 dim=1
//#pragma HLS ARRAY_PARTITION variable=element_left cyclic factor=4 dim=1
//#pragma HLS ARRAY_PARTITION variable=LB cyclic factor=4 dim=1
//#pragma HLS ARRAY_PARTITION variable=UB cyclic factor=4 dim=1
//#pragma HLS ARRAY_PARTITION variable=element_done cyclic factor=4 dim=1

	LB = rowPtr[0];
	UB = rowPtr[1];

	int row = 0;
	int L, K;
	y[row] = 0;
 ACC:  for(i=0; i<NNZ + NUM_ROWS; i++ ) {
//#pragma HLS DEPENDENCE variable=y array inter false
#pragma HLS PIPELINE II=1
		if(LB == UB) {
			row++;
			if(row >= NUM_ROWS) break;	
			UB = rowPtr[row+1];
			y[row] = 0;
		} else {
			int k = LB;
			y[row] += values[k] * x[columnIndex[k]];
			LB++;
		}
	}
}
