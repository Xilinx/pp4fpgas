#include "block_mm.h"
//#include "hls_print.h"

void blockmatmul(hls::stream<blockvec> &Arows, hls::stream<blockvec> &Bcols,
        blockmat &ABpartial, int it) {
  #pragma HLS DATAFLOW
  int counter = it % (SIZE/BLOCK_SIZE);
  static DTYPE A[BLOCK_SIZE][SIZE] = { 0 };
  #pragma HLS STREAM variable=A type=shared depth=1
  if(counter == 0){ //only load the A rows when necessary
    loadA_i: for(int i = 0; i < SIZE; i++) {
      blockvec tempA = Arows.read();
      loadA_j: for(int j = 0; j < BLOCK_SIZE; j++) {
        #pragma HLS PIPELINE II=1
        A[j][i] = tempA.a[j];
      }
    }
  }
  DTYPE AB[BLOCK_SIZE][BLOCK_SIZE] = { 0 };
  partialsum_k: for(int k=0; k < SIZE; k++) {
    blockvec tempB = Bcols.read();
    partialsum_i: for(int i = 0; i < BLOCK_SIZE; i++) {
      partialsum_j: for(int j = 0; j < BLOCK_SIZE; j++) {
        AB[i][j] = AB[i][j] +  A[i][k] * tempB.a[j];
      }
    }
  }
  writeoutput_i: for(int i = 0; i < BLOCK_SIZE; i++) {
    writeoutput_j: for(int j = 0; j < BLOCK_SIZE; j++) {
      ABpartial.out[i][j] = AB[i][j];
    }
  }
}
