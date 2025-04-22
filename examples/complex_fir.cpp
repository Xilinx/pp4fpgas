// The original work is licensed under the Creative Commons Attribution 4.0 International License.
// See https://creativecommons.org/licenses/by/4.0/ or refer to the LICENSE file for details.
//
// Modifications Copyright (C) 2025 Advanced Micro Devices, Inc. All rights reserved.

#include "complex_fir.h"

void complexFIR(data_t Iin, data_t Qin, data_t *Iout, data_t *Qout, coef_t Itaps[NUM_TAPS], coef_t Qtaps[NUM_TAPS]) {

  data_t IinIfir, QinQfir, QinIfir, IinQfir;

  fir(Iin, &IinIfir, Itaps); // firI1
  fir(Qin, &QinQfir, Qtaps); // firQ1
  fir(Qin, &QinIfir, Itaps); // firI2
  fir(Iin, &IinQfir, Qtaps); // firQ2

  *Iout = IinIfir + QinQfir;
  *Qout = QinIfir - IinQfir;
}
