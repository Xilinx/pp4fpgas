#ifndef FIR_CSLOWED_H
#define FIR_CSLOWED_H

#define NUM_TAPS 16
#define K 4
#define SIZE 256

void block_fir(int input[256][K], int output[256][K], int taps[NUM_TAPS], int delay_line[NUM_TAPS][K]);

#endif // FIR_CSLOWED_H