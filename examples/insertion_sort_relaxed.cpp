// The original work is licensed under the Creative Commons Attribution 4.0 International License.
// See https://creativecommons.org/licenses/by/4.0/ or refer to the LICENSE file for details.
//
// Modifications Copyright (C) 2025 Advanced Micro Devices, Inc. All rights reserved.

#include "insertion_sort.h"
void insertion_sort(DTYPE A[SIZE]) {
 L1:
    int i, j;
    for(i = 1; i < SIZE; i++) {
        DTYPE item = A[i];
        j = i;
        DTYPE t = A[j-1];
    L2:
        while(j > 0 && t > item) {
#pragma HLS pipeline II=1
            A[j] = t;
            if (j > 1)
                t = A[j-2];
            j--;
        }
        A[j] = item;
    }
}
