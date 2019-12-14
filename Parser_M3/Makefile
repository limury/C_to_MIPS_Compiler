test: 	test.flex test.y
		bison -d test.y
		flex test.flex
		cc -o $@ test.tab.c lex.yy.c -lfl