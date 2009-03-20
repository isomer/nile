CXXFLAGS=-I../lib -g -Wall -W -pedantic  -I.
LDFLAGS=-L../lib
CC=g++

all:  \
	nile_test1 \
	nile_test \
	fib \
	fib2 \
	fib3 \
	list \

#nile_test1.cc nile_test.cc 

%.cc: %.nile ../compiler/nile
	cat ../lib/system.nile $< | ../compiler/nile > $@

clean:
	rm -f nile_test1 nile_test fib fib2 fib3 list

.PHONY: nile_test1.out

.PRECIOUS: *.cc
