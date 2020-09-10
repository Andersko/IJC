CFLAGS=-g -std=c11 -pedantic -Wall -Wextra -lm	

all: primes primes-i steg-decode



primes.o: primes.c eratosthenes.h bitset-inline-fce-def.h bitset.h error.h
	gcc $(CFLAGS) -c primes.c -o primes.o

eratosthenes.o: eratosthenes.c eratosthenes.h bitset.h error.h
	gcc $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

error.o: error.c error.h
	gcc $(CFLAGS) -c error.c -o error.o

ppm.o: ppm.c ppm.h error.h
	gcc $(CFLAGS) -c ppm.c -o ppm.o

steg-decode.o: steg-decode.c error.h ppm.h eratosthenes.h bitset.h bitset-inline-fce-def.h
	gcc $(CFLAGS) -c steg-decode.c -o steg-decode.o




primes: primes.o eratosthenes.o error.o
	gcc $(CFLAGS) primes.o eratosthenes.o error.o -o primes

primes-i: primes.c eratosthenes.c error.o
	gcc $(CFLAGS) -DUSE_INLINE primes.c eratosthenes.c error.o -o primes-i

steg-decode: steg-decode.o ppm.o error.o eratosthenes.o
	gcc $(CFLAGS) steg-decode.o ppm.o error.o eratosthenes.o -o steg-decode


run: primes primes-i
	ulimit -s 8388608 # toto mozno nebude mozne, no musime pouzit lokalne pole s funkciou create a s mensou pamatou mi to nefunguje, pri zmene na staticke pole alebo pri zmene funkci na alloc program prebehne bez problemov
	./primes
	./primes-i