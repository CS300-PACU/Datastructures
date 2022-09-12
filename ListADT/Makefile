#############################################################################
# File name:  Makefile
# Author:     chadd williams
# Date:       Sept 1, 2021
# Class:      CS360
# Assignment: 
# Purpose:    
#############################################################################

CFLAGS=-g -Wall
VALGRIND_FLAGS=-v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all
all: bin bin/main


bin:
	mkdir -p bin

bin/main: bin bin/main.o
	gcc -o bin/main ${CFLAGS} bin/main.o

bin/main.o: src/main.c
	gcc -c -o bin/main.o ${CFLAGS} src/main.c

valgrind: bin/main
	valgrind ${VALGRIND_FLAGS} bin/main

printAll:
	enscript -C -T 2 -p - -M Letter -Ec --color -fCourier8 src/main.c  | ps2pdf - bin/main.pdf

clean:
	rm -f bin/main bin/*.o
