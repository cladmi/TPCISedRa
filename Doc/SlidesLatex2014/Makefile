DOCUMENT_ENG    = presentation_ci_eng
THEME_FOLDER = inria-doc-style
OBJS_FOLDER  = bin

###

TEX2PDF		=pdflatex
TEX2PDF_OPTS	=-halt-on-error

###

all : $(DOCUMENT_ENG).pdf
.PHONY: FORCE

%.pdf : %.tex  $(OBJS_FOLDER) FORCE
	TEXINPUTS=".:$(THEME_FOLDER):" $(TEX2PDF) $(TEX2PDF_OPTS) --output-directory=$(OBJS_FOLDER) $< && \
	  TEXINPUTS=".:$(THEME_FOLDER):" $(TEX2PDF) --output-directory=$(OBJS_FOLDER) $< && \
	  TEXINPUTS=".:$(THEME_FOLDER):" $(TEX2PDF) --output-directory=$(OBJS_FOLDER) $<
	cp $(OBJS_FOLDER)/$@ $@


$(OBJS_FOLDER):
	mkdir $(OBJS_FOLDER)
clean:
	$(RM) *.pdf
	$(RM) -r $(OBJS_FOLDER)


