	/*
	* File: steg-decode.c
	* IJC-DU1,  b)
	* Date: 18.3.2020
	* Author: Andrej Pavlovič
	* School: VUT FIT Brno
	* Compiled: gcc 7.5.0
	* Function: decode message from picture of ppm format
	*/

#include <string.h>
#include <ctype.h>

#include "error.h"
#include "ppm.h"
#include "eratosthenes.h"
#include "bitset.h"
#include "bitset-inline-fce-def.h"

int main (int argc, char* argv[]) {

	// correct arguments count check
	if ( argc != 2 ) {
		error_exit("wrong (%d) arguments count. 1 is required", argc - 1);
	}

	// correct file format check
	if ( strlen(argv[1]) < 4 || strcmp(&argv[1][strlen(argv[1])-4], ".ppm") ) {
		error_exit("wrong file format - '.ppm' is required");
	}

	struct ppm* pic = ppm_read(argv[1]);
	if ( !pic ) {
		exit(1);
	}

	unsigned data_size = 3 * pic->xsize * pic->ysize;
	bitset_alloc(primes, data_size);
	unsigned char message[data_size/8];
	Eratosthenes(primes);

	unsigned long k = 0;
	unsigned long j = 23;

	do {

		message[k] = 0;

		// every for loop is readed one character aka 8 bites
		for (int i = 0; i < 8; j++) {
			
			// data limit control
			if ( j > (data_size-1) ) {
				bitset_free(primes);
				ppm_free(pic);
				error_exit("message is not ending correctly with '\\0' symobl");
			}

			// prime index was found
			if ( !bitset_getbit(primes, j) ) {
				message[k] |= (pic->data[j] & 1) << i; // saving last bit of this prime index
				i++;
			}
		}
	} while ( message[k++] != '\0' ); // ends while if '\0' was readed

	// stdout messege
	printf("%s\n", message);

	bitset_free(primes);
	ppm_free(pic);
	return 0;
}