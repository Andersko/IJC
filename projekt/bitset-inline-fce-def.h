	/*
	* File: bitset-inline-fce-def.h
	* IJC-DU1,  a)
	* Date: 18.3.2020
	* Author: Andrej Pavlovič
	* School: VUT FIT Brno
	* Compiled: gcc 7.5.0
	* Functions: extern definitions of inline functions in file "bitset.h"
	*/

#ifdef USE_INLINE

extern void bitset_free (bitset_t*);
extern bitset_t bitset_size (bitset_t*);
extern void bitset_setbit (bitset_t*, bitset_index_t, int);
extern int bitset_getbit (bitset_t*, bitset_index_t);

#endif // USE_INLINE

typedef int make_iso_compilers_happy; // in case this file would be compiled with ISO compilers using '-pedantic' or so..