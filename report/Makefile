
NAME = Report

all:
	echo $(NAME)
	pdflatex $(NAME).tex
	bibtex $(NAME)
	pdflatex $(NAME).tex
	pdflatex $(NAME).tex
	make clean

clean:
	rm $(NAME).aux $(NAME).bbl $(NAME).blg $(NAME).log $(NAME).out
