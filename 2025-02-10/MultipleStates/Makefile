#
#   Richard Halterman
#
#   Makefile for a simple flex project
#


CC = g++     
OP = # -O2      # no optimizations for now
FLAGS = -g -Wall -Wextra -Wpedantic -Wno-unused-function -Wno-unused-parameter -std=c++20

all: count_words

count_words: lex.yy.o 
	${CC} ${OP} ${FLAGS} -o count_words lex.yy.o 

lex.yy.o: lex.yy.cpp
	${CC} ${OP} ${FLAGS} -Wno-sign-compare -c lex.yy.cpp 

lex.yy.cpp: count_words.l 
	flex -o lex.yy.cpp count_words.l

run: count_words
	./count_words

clean:
	/bin/rm -f *.o *.yy.c *.yy.cpp *.tab.cpp *.tab.c *.tab.hpp \
	           core *.output *.temp *~ count_words a.s vg.out

