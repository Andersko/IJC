    /*
    * File: eratosthenes.c
    * IJC-DU1,  a)
    * Date: 18.3.2020
    * Author: Andrej Pavlovič
    * School: VUT FIT Brno
    * Compiled: gcc 7.5.0
    * Function: calculate primes via sieve of eratosthenes
    */

#include "eratosthenes.h"

void Eratosthenes(bitset_t* bitArray) {

	long unsigned n = bitset_size(bitArray);

	// main algorithm
    for (long unsigned j = 2; j*j <= n; j++)
        if ( !bitset_getbit(bitArray,j) )
            for (long unsigned i = j*j; i <= n; i += j)
                bitset_setbit(bitArray,i,1);

    // correcting first 2 numbers
    bitset_setbit(bitArray, 0, 1);
    if ( n > 1 )
	    bitset_setbit(bitArray, 1, 1);    
}