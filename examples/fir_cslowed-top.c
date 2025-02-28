#include "stdio.h"
#include "fir_cslowed.h"

//const int SIZE = 256;
//const int K = 4;

int main() {
    int taps[NUM_TAPS] = {1, 2, 0, -3, 0, 4, -5, 0, 1, -2, 0, -3, 0, 4, -5, 0};
    int delay_line[NUM_TAPS][K] = {0};
    int input[SIZE][K] = {0}, output[SIZE][K] = {0};

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < K; j++) {
            input[i][j] = i + j;
        }
    }

    block_fir(input, output, taps, delay_line);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < K; j++) {
            printf("input[%d][%d] = %d output[%d][%d] = %d\n", i, j, input[i][j], i, j, output[i][j]);
        }
    }

    printf("result = %d\n", output[SIZE-1][0]);
	// only channel 0 is checked and mirrors the fir-top.c test check since the input is the same
	// the fir.c fir() function is the same as the fir_cslowed.c block_fir() function channel 0.
    if (output[SIZE-1][0] == -1452) {
        return 0;
    } else {
        return 1;
    }
}