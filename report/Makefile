
NAME = Report

all:
	pdflatex $(NAME).tex
	bibtex $(NAME)
	pdflatex $(NAME).tex
	pdflatex $(NAME).tex
	make clean

clean:
	rm $(NAME).aux $(NAME).bbl $(NAME).blg $(NAME).log $(NAME).out ../texput.log
