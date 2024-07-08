## [1.0.3](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/compare/v1.0.2...v1.0.3) (2024-07-08)


### Bug Fixes

* add more robust support for pdflatex ([cc42632](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/cc426329d0d4cba3ba3b052e9c6d99901c4fbf26))
* add python requirements.txt for venv setup ([db839ba](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/db839ba3ebcade2a2b0bab48f821cd96db8d1b04))
* update venv requirements.txt ([7346e7a](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/7346e7a35e608b94c401de1943197bb84a962e29))

## [1.0.2](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/compare/v1.0.1...v1.0.2) (2024-06-14)


### Bug Fixes

* incorrect factor value ([410e644](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/410e64406de1b4398d8f2effc4653d962979388b))
* remove spurious commitlint cfg file ([451ca97](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/451ca971628a8fe7ede4a65ee09b39f721bc5b31))
* same named variables - vivado_hls ([876016a](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/876016aebc15d4589192cb06fc66b53d1c113498))

## [1.0.1](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/compare/v1.0.0...v1.0.1) (2024-06-13)


### Bug Fixes

* disable body-max-line-length during release ([3f31e15](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/3f31e1591fae85f747db10d368b473de5e4d1185))

# 1.0.0 (2024-06-13)


### Bug Fixes

* add M-1 stage butterflies in FFT calc ([c372981](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/c372981da21b96bf0cfc17f203846f26767775ac))
* broken delay line input var access ([ae66946](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/ae66946e007550ab8af36274debc298d9b3c5edb))
* correct delay line init with in vals for block FIR ([a20fa8a](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/a20fa8a9ca439be37bec06c75f6c9935085e0755))
* fix Makefile HLS compiler flows ([790d01b](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/790d01b842b2a6bcf1d164ae40be6c125521186a))
* fix missing call to fir ([cce6a75](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/cce6a75b303cde96a9c26bc5645055e7ea602edc))
* gitignore auto-gen'ed .dat and .bmp files ([38a11a8](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/38a11a88141434efd4d9dff2ffc1c1f8cbc995a4))
* incorrect include file name ([4ba2adc](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/4ba2adc488338b345d54124b9e91f9167290151d))
* incorrect NUM_TAPS - should be 16 ([5771214](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/5771214b9ef93fa24757a66cfe10fc393e08c399))
* incorrect S define and LB & UB declares ([3791562](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/3791562e0b6dda8664ed52cd970b54ae760f4a46))
* incorrect S definition ([0b8cbdd](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/0b8cbdd3eaa30a95b09baad33da0d9173eb761c9))
* incorrect var / wrong pragma defines ([2c017e4](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/2c017e48bd24a15b2b97eb4e3c228aec4505a670))
* incorrect window var access for printf ([67fb24e](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/67fb24e3b9bab719dce0f0b9d6a2e0d1db24d024))
* missing hls_stream.h inc & var defines ([79b7e6d](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/79b7e6d83f7578de1944fd15e761d87720c3dbae))
* missing include histogram.h ([ef3335e](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/ef3335e96452b1caf5d83fffd5c35407ba549e55))
* missing variables i and j declaration ([0362328](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/036232889663dd6dd23e7bb39331d3018dba3d93))
* remove examples/tcl script auto-gen'ed now ([a96623a](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/a96623aa4adfc3bba50bd8765cbde4fcf198cff3))
* remove leading dot from commitlint.config.js ([11a4071](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/11a4071ca44a9d600b14d387043d258d8e0893cd))
* remove spurious ap_int.h include ([a183982](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/a183982ebaa1477557d55166268af4b98922dda9))
* rename .commitlintrc.js to .commitlint.config.js ([8890542](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/88905424e0be06842df0f8d48977ed8802ed754e))
* rename gen_hls_csynth_script.py ([d55fc63](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/d55fc63b2ce88f860cfdc955ad8dbf4510208ea3))
* resolve semantic-release changelog config ([d040b9c](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/d040b9c200e8cafbb0c3b3850978799e34a2e687))
* update .gitignore ([a67dc13](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/a67dc132a08b96bcd76b39d82d1f2a9568915f2a))
* use more generic rule with broader application ([fe1656e](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/fe1656e4ed74469741b1af872cce7d41fd24b8bb))


### Features

* add gen_template_report.py ([5c7ba32](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/5c7ba321fdc50288e5b0b86982e35a22f3acf4f3))
* add generate HLS csynth script ([e08baf6](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/e08baf615ab4d0901563cece5f2425a6e0e8ff87))
* add hls component csynth log extract script ([5657582](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/5657582ed3d2f4dd2c7a2756fd3d2d332f0d0022))
* add semantic-release support ([e91efca](https://gitenterprise.xilinx.com/mpettigr/pp4fpgas/commit/e91efca86caeb18718713012dec2e6df718caa90))
