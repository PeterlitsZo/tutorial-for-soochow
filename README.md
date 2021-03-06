题解 For Soochow University
===============================================================================

基本信息
-------------------------------------------------------------------------------
目前的 IP：1.116.122.17，用户为 soochow

提交格式
-------------------------------------------------------------------------------
尽可能地保证提交信息有含义即可。不应该使用没有意义的提交信息。

组织格式
-------------------------------------------------------------------------------
题解应该存放在 `./<year>/<contest-name>/<title>.tex` 中，而参考代码应该放在
`./<year>/<contest-name>/<title>.cpp` 中。其中
`./<year>/<contest-name>/main.tex` 应该是特殊的：它表示了入口文档。

使用下列命令以编译文档：
``` shell
$ cd ./<year>/<contest-name>/
$ rm -f main.toc % beamer 和 paper 的 toc 格式不一样，需要删除重新生成。
$ lualatex main.tex % or xelatex main.tex
$ lualatex main.tex % run twice
```

或者如果有 makefile：
``` shell
$ cd ./<year>/<contest-name>/
$ make
```

查看 `./example/main.tex` 和 `./example/title.tex` 查看最新的模板。
