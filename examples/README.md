# HLS Book Examples Subdirectory README

Use Makefile to run tests and various HLS stages for all examples.

## Software Tests

* cd examples
* make clean
* make test
* make test_verify
  * This checks for errors in all test logs automatically

NOTE: make test runs with g++ rather than csim_design.

## Vitis HLS Synthesis

* cd examples
* make clean
* make csynth
* make csynth_verify
  * This checks for errors in all of the HLS csynth logs automatically

## C Simulation

* cd examples
* make clean
* make csim
* make csim_verify
  * This checks for errors in C simulation logs automatically

## Co-Simulation

* cd examples
* make clean
* make cosim
* make cosim_verify
  * This checks for errors in co-simulation logs automatically

## Complete Workflow Example

```bash
cd examples
make clean
make test
make test_verify
make clean
make csim
make csim_verify
make clean
make csynth
make csynth_verify
make clean
make cosim
make cosim_verify
```

## Verification Commands

Each *_verify target runs specific checks:

* test_verify: Finds and reports errors in software test logs
* csynth_verify: Finds and reports errors in HLS synthesis logs
* csim_verify: Finds and reports errors in C simulation logs
* cosim_verify: Finds and reports errors in co-simulation logs

If no errors are found, these commands will report "No errors found in [type] logs".

## Manual Verification

You can also manually check logs:

* Software test logs: `grep -q "ERROR" *.log`
* HLS synthesis logs: `find -wholename "*.comp/hls/hls.log" -exec grep -i 'error:' {} +`
* C simulation logs: `find . -path "*/csim/*/hls*.log" -o -path "*/csim/*.log" -exec grep -i '^\s*error:' {} +`
* Co-simulation logs: `find . -path "*.comp/hls/sim/verilog/xsim.log" -exec grep -i '^\s*error:' {} +`

To verify these commands work, try replacing 'error:' with 'warning:' and rerun to see typical output.