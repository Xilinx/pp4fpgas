# pp4fpgas — AMD Vitis HLS edition

[![CI](https://github.com/Xilinx/pp4fpgas/actions/workflows/ci.yml/badge.svg?branch=2026.1)](https://github.com/Xilinx/pp4fpgas/actions/workflows/ci.yml)
[![read](https://img.shields.io/badge/Read-online-green.svg)](https://xilinx.github.io/pp4fpgas/)
[![download](https://img.shields.io/badge/Download-pdf-blue.svg)](https://xilinx.github.io/pp4fpgas/pp4fpgas.pdf)

**Read the book: <https://xilinx.github.io/pp4fpgas/>** — the PDF is rebuilt from
this repository on every change to the release branch.

An open-source high-level synthesis book by Ryan Kastner, Janarbek Matai, and
Stephen Neuendorffer — <http://hls.ucsd.edu/>

## Which version is this?

This is AMD's fork of [KastnerRG/pp4fpgas](https://github.com/KastnerRG/pp4fpgas),
maintained so that the book's examples keep working with current AMD tools. It
differs from the original in three ways:

- **The examples target Vitis HLS**, not the discontinued Vivado HLS, and are
  updated as the tool changes.
- **Every example is regression-tested** against the matching Vitis release (C
  simulation, synthesis, and co-simulation) before that release branch ships.
- **Each release has its own branch** named for the Vitis version — `2026.1` is
  the current one. The default branch is the most recent release.

The book text is the authors' work, used under CC-BY-4.0 and kept close to
upstream; AMD's changes are noted in [CHANGELOG.md](CHANGELOG.md). **If you want
the authors' original edition, use [KastnerRG/pp4fpgas](https://github.com/KastnerRG/pp4fpgas).**

# Background

Parallel Programming for FPGAs is an open-source book aimed at teaching hardware and software developers how to efficiently program FPGAs using high-level synthesis (HLS). The authors developed the book as we noticed a lack of material aimed at teaching people to effectively use HLS tools.

The book was developed over many years to serve as a primary reference for [UCSD 237C](http://kastner.ucsd.edu/ryan/cse237c/) — a hardware design class targeting first-year graduate students and advanced undergraduate students. We hope that you find it useful for learning more about HLS, FPGAs, and system-on-chip design.

The book is licensed under the [Creative Commons Attribution 4.0 International License](LICENSE). We encourage you to make edits, add material, and fix errors. Thanks to those who have made pull requests over the years. Please keep them coming!

Feel free to grab the source at the authors' github repo
https://github.com/KastnerRG/pp4fpgas, or for quicker access, [here is this
edition's pre-built pdf](https://xilinx.github.io/pp4fpgas/pp4fpgas.pdf).

Some fine people have translated this book into Mandarin - [pp4fpgas-ch](https://github.com/xupsh/pp4fpgas-cn)

If you want to cite this book, please use the arxiv submission:
```
@ARTICLE{2018arXiv180503648K,
author = {{Kastner}, R. and {Matai}, J. and {Neuendorffer}, S.},
title = "{Parallel Programming for FPGAs}",
journal = {ArXiv e-prints},
archivePrefix = "arXiv",
eprint = {1805.03648},
keywords = {Computer Science - Hardware Architecture},
year = 2018,
month = may
}
```
