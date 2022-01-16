make:
	rm -f main.toc
	xelatex main.tex
	xelatex main.tex

byTineTex:
	rm -f main.toc
	R -e 'tinytex::xelatex("main.tex")'

clear:
	rm main.aux main.out main.log main.pdf main.toc
