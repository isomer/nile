CXXFLAGS=-Wall -W -pedantic -g
YFLAGS=-d

all:  nile 

nile: parse.tab.o lex.o nile.cc ast.o
#g++ $(LDFLAGS) $(CXXFLAGS) $^ -o $@

ast.cc: ast.h

%.tab.cpp %.tab.hpp: %.ypp ast.h
	bison $(YFLAGS) $< 

lex.cpp: lex.l
	flex  $(LFLAGS) -o $@ $< 

clean:
	rm -f nile *.tab.* lex.cpp *.o parse.output 

