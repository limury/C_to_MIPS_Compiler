CPPFLAGS += -std=c++11 -W -Wall -s

all : bin/printTree

obj/parser.tab.cpp obj/parser.tab.hpp : src/parser.y
	bison -v -d src/parser.y -o obj/parser.tab.cpp

obj/lexer.yy.cpp : src/lexer.flex obj/parser.tab.hpp
	flex -o obj/lexer.yy.cpp src/lexer.flex

obj/printTree.o : src/printTree.cpp include/Node.hpp include/includes.hpp
	mkdir -p obj
	g++ $(CPPFLAGS) -c src/printTree.cpp -o obj/printTree.o

bin/printTree : obj/printTree.o obj/parser.tab.o obj/lexer.yy.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/printTree $^

obj/includes.o : src/includes.hpp
obj/Node.o : src/Node.hpp src/includes.hpp

clean :
	rm bin/*
	rm obj/*