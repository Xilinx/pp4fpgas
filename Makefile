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

# NOTE: You *must* put the path to your texlive installation here.
#
# TODO: Refactor to use Texlive docker image instead.
TEXLIVE_BINDIR=/wrk/xsjhdnobkup2/mpettigr/projects_nobkup/texlive/texlive/install-tl-20240625/./texlive/2024/bin/x86_64-linux
PDFLATEX=PATH=$(TEXLIVE_BINDIR):$$PATH $(TEXLIVE_BINDIR)/pdflatex
BIBTEX=PATH=$(TEXLIVE_BINDIR):$$PATH $(TEXLIVE_BINDIR)/bibtex

main.aux: all.bib
	$(PDFLATEX) \\nonstopmode\\input main.tex
	$(BIBTEX) main

main.pdf: main.aux *.tex
	$(PDFLATEX) \\nonstopmode\\input main.tex
	$(PDFLATEX) \\nonstopmode\\input main.tex

clean:
	rm -rf main.pdf *.log *~ *.aux *.bbl *.blg *.out

# Manually trigger semantic-release.
# Warning: This will push to the remote repository.
#
# If you want to test the release process without pushing to the remote
# repository, use `npx semantic-release -d`.
#
# NOTE: If you don't have any local modules installed, run 'npm install'.
semantic-release:
	npx semantic-release --no-ci

# Create a release branch. This is the release branch that will be 
# published to github.com/Xilinx/pp4fpgas.
#
create-release-branch:
	./scripts/create-release-branch.sh

nwa:
	sudo docker run -it \
		--user $(shell id -u):$(shell id -g) \
		-v ${PWD}:/src \
		ghcr.io/b1nary-gr0up/nwa:main \
		config -c add