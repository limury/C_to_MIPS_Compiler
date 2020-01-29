c_compiler: ast.o gen_asm.o top.o
	gcc -o c_compiler ast.o gen_asm.o top.o

ast.o: ast.c
	gcc -c -g -o ast.o ast.c_compiler

gen_asm.o: gen_asm.c ast.h
	gcc -c -g -o gen_asm.o gen_asm.c

top.o: top.c ast.h gen_asm.g lex.yy.c
	gcc -c -g -o top.o top.c

lex.yy.c: lexel.l y.tab.c
	lex lexer.l

y.tab.c: parser.y
	tacc -v parser.y