# HLS Book Examples Subdirectory README

Use Makefile to run tests and csynth_design compile all (compilable) examples

To run tests:

* cd examples
* make clean
* grep -iH ^\s*error *.log
**  to check if there are any errors

To run Vitis HLS (csynth) on all HLS components:

* cd examples
* make clean
* make hls
* find -wholename "*.comp/hls/hls.log" -exec grep -i 'error:' {} +
** This scans for "ERROR:" lines in all of the csynth compiled HLS components. This should return with no output.
p.s. To just get the warm fuzzy that this command works change 'error:' with 'warning:' and rerun.