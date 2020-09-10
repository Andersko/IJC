	/*
	* File: primes.c
	* IJC-DU1,  a)
	* Date: 18.3.2020
	* Author: Andrej Pavlovič
	* School: VUT FIT Brno
	* Compiled: gcc 7.5.0
	* Function: test for eratosthenes.c file
	* Note:	library <math.h> is not used but was required in assignment
	*/

#include <time.h>
#include <math.h>

#include "eratosthenes.h"
#include "bitset-inline-fce-def.h"

#define N 500000000 // 500 millions
#define QUANTITY 10

int main(void) {

	clock_t start_t = clock();

	bitset_create(primes, N);
	Eratosthenes(primes);
	bitset_index_t index = bitset_size(primes) + 1;

	// find index of 10th highest prime
	for (int i = 0; i < QUANTITY; i++)
		do index--; while( bitset_getbit(primes, index) );

	// print last 10 primes
	for (; index <= N; index++)
		if ( !bitset_getbit(primes, index) )
			printf("%lu\n", index);

	fprintf(stderr, "Time=%.3g\n", (double)(clock()-start_t)/CLOCKS_PER_SEC);

	return 0;
}