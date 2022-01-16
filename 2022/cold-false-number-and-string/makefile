make:
	rm -f main.toc
	lualatex main.tex
	lualatex main.tex

byTineTex:
	rm -f main.toc
	R -e 'tinytex::xelatex("main.tex")'

clear:
	rm main.aux main.out main.log main.pdf main.toc
