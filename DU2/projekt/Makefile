CFLAGS=-std=c99 -pedantic -Wall -Wextra

all: tail

tail.o: tail.c tail.h error.h
	gcc $(CFLAGS) -c tail.c -o tail.o

error.o: error.c error.h
	gcc $(CFLAGS) -c error.c -o error.o

tail: tail.o error.o
	gcc $(CFLAGS) tail.o error.o -o tail