# The original work is licensed under the Creative Commons Attribution 4.0 International License.
# See https://creativecommons.org/licenses/by/4.0/ or refer to the LICENSE file for details.
#
# Modifications Copyright (C) 2025 Advanced Micro Devices, Inc. All rights reserved.

base=main
all: main.pdf

# pdflatex is part of the Texlive distribution.
#
# See https://tug.org/texlive/ for TexLive installation instructions.
# Docker image available at https://hub.docker.com/r/texlive/texlive/

# Optional: path to a local texlive installation. If TEXLIVE_BINDIR points at a
# directory that actually contains pdflatex, it is used; otherwise pdflatex and
# bibtex are taken from PATH (the case inside the texlive container image).
# Override on the command line: make all TEXLIVE_BINDIR=/path/to/texlive/bin
TEXLIVE_BINDIR?=/wrk/xsjhdnobkup2/mpettigr/projects_nobkup/texlive/texlive/install-tl-20240625/./texlive/2024/bin/x86_64-linux

ifneq ($(wildcard $(TEXLIVE_BINDIR)/pdflatex),)
PDFLATEX=PATH=$(TEXLIVE_BINDIR):$$PATH $(TEXLIVE_BINDIR)/pdflatex
BIBTEX=PATH=$(TEXLIVE_BINDIR):$$PATH $(TEXLIVE_BINDIR)/bibtex
else
PDFLATEX=pdflatex
BIBTEX=bibtex
endif

main.aux: all.bib
	$(PDFLATEX) \\nonstopmode\\input main.tex
	$(BIBTEX) main

main.pdf: main.aux *.tex
	$(PDFLATEX) \\nonstopmode\\input main.tex
	$(PDFLATEX) \\nonstopmode\\input main.tex

clean:
	rm -rf main.pdf *.log *~ *.aux *.bbl *.blg *.out

# Build the book in the official Texlive container -- no local Texlive needed.
# Uses docker if present, otherwise podman. Pinned to the Texlive 2024 release
# so the container build matches a local Texlive 2024 install.
#
# Rootless podman already maps your user onto the container root, so --user is
# only needed under docker to keep main.pdf owned by you instead of by root.
TEXLIVE_IMAGE?=docker.io/texlive/texlive:TL2024-historic
CONTAINER_RUNTIME?=$(shell command -v docker 2>/dev/null || command -v podman 2>/dev/null)
CONTAINER_USER=$(if $(findstring podman,$(CONTAINER_RUNTIME)),,--user $(shell id -u):$(shell id -g))

docker-book:
	@test -n "$(CONTAINER_RUNTIME)" || { echo "No docker or podman found on PATH."; exit 1; }
	$(CONTAINER_RUNTIME) run --rm $(CONTAINER_USER) \
		-v ${PWD}:/src:z \
		-w /src \
		$(TEXLIVE_IMAGE) \
		make all TEXLIVE_BINDIR=

nwa:
	sudo docker run -it \
		--user $(shell id -u):$(shell id -g) \
		-v ${PWD}:/src \
		ghcr.io/b1nary-gr0up/nwa:main \
		config -c add