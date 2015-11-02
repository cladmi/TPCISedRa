.PHONY: all clean realclean

PDF = TPCI_SEDRAInria.pdf
PDFLATEX_FLAGS = -halt-on-error -file-line-error


all: $(PDF)

%.pdf: %.tex
	pdflatex $(PDFLATEX_FLAGS) $<
	pdflatex $(PDFLATEX_FLAGS) $<
	pdflatex $(PDFLATEX_FLAGS) $<

realclean: clean
	$(RM) $(PDF)

clean:
	$(RM) *.log *.aux *.toc *.out
