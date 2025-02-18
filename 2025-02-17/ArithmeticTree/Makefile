CC = g++     
OP = # -O2      # no optimizations for now
FLAGS = -g -Wall -Wextra -Wpedantic -Wno-unused-function -Wno-unused-parameter -std=c++20

all: calc

calc: calc.tab.o lex.yy.o arithtree.o 
	${CC} ${OP} ${FLAGS} -o calc calc.tab.o lex.yy.o arithtree.o


arithtree.o: arithtree.cpp
	${CC} ${OP} ${FLAGS} -c arithtree.cpp

calc.tab.o: calc.tab.cpp
	${CC} ${OP} ${FLAGS} -c calc.tab.cpp

#rustish.tab.cpp: rustish.tab.c
#	mv -f rustish.tab.c rustish.tab.cpp

calc.tab.cpp: calc.y 
	bison -Wcounterexamples -v -d -o calc.tab.cpp calc.y

lex.yy.o: lex.yy.cpp
	${CC} $(OP) $(FLAGS) -Wno-sign-compare -c lex.yy.cpp 

lex.yy.cpp: calc.l calc.tab.hpp
	flex -o lex.yy.cpp calc.l

clean:
	/bin/rm -f *.o *.yy.c *.yy.cpp *.tab.cpp *.tab.c *.tab.hpp \
	           core *.output *.temp *~ calc 

