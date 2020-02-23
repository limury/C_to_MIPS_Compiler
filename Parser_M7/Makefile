CPPFLAGS += -std=c++11 -W -Wall -s

all : bin/printTree

src/parser.tab.cpp src/parser.tab.hpp : src/parser.y
	bison -v -d src/parser.y -o src/parser.tab.cpp

src/lexer.yy.cpp : src/lexer.flex src/parser.tab.hpp
	flex -o src/lexer.yy.cpp src/lexer.flex

bin/printTree : src/printTree.o src/parser.tab.o src/lexer.yy.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/printTree $^

clean :
	rm src/parser.output
	rm bin/*
	rm src/*.tab.cpp
	rm src/*.tab.hpp
	rm src/*.yy.cpp
	rm src/parser.tab.cpp
	rm src/parser.tab.hpp
	rm src/*.o