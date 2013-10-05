
.PHONY : all clean

TARG := cheatsheet.pdf
DIRS := tmp

all: $(TARG)

clean:
	$(RM) -r $(TARG) $(DIRS)

%.pdf: %.tex
	mkdir -p tmp
	latexmk -silent -pdf -jobname=tmp/$(*F) $<
	mv tmp/$*.pdf $@

