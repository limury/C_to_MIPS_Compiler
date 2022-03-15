CPPFLAGS += -W -Wall -g 

# This avoids error: ‘fileno’ was not declared in this scope
CPPFLAGS += -std=c++0x

# Avoid warnings about yyunput not used
CPPFLAGS += -Wno-unused-function -Wno-tautological-constant-out-of-range-compare

all : bin/prog

lexer.yy.cpp : lexer.flex
	flex -o lexer.yy.cpp  lexer.flex

bin/prog : clean lexer.yy.o lex_test.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/prog lexer.yy.o lex_test.o

clean :
	@rm -rf bin
	@rm -f *.yy.cpp
	@rm -f *.yy.o
	@rm -f *.o
	@echo "all clean."