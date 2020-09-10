	/*
	* File: bitset.h
	* IJC-DU1,  a)
	* Date: 18.3.2020
	* Author: Andrej Pavlovič
	* School: VUT FIT Brno
	* Compiled: gcc 7.5.0
	* HEADER FILE
	* Function: define macros and inline function for bit array data type
	*/

#ifndef _BITSET_H_
#define _BITSET_H_

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

#include "error.h"

typedef unsigned long bitset_t;
typedef unsigned long bitset_index_t;

#define bitset_create(name, size) \
	bitset_t name[1 + (size/(sizeof(bitset_t)*CHAR_BIT)) + ((size%(sizeof(bitset_t)*CHAR_BIT)) ? 1 : 0)] = {size,}; \
	static_assert (size <= 500000000 && size > 0, "bitset_create: size of array is out of 1-80000000");

#define bitset_alloc(name, size) \
	assert(size <= 500000000 && size > 0); \
	bitset_t* name = (bitset_t*) calloc(size/(sizeof(bitset_t)*CHAR_BIT) + (size%(sizeof(bitset_t)*CHAR_BIT ? 1 : 0)), sizeof(bitset_t)); \
	if ( !name ) { \
		error_exit("bitset_alloc: error in memory allocation"); \
	} \
	*name = size;


#ifndef USE_INLINE


#define bitset_free(name) \
	free(name)

#define bitset_size(name) \
	*name

#define bitset_setbit(name, index, expression) \
	expression ? \
	(*(name + 1 + (index/(sizeof(bitset_t)*CHAR_BIT))) |= ((bitset_t) 1) << (index%(sizeof(bitset_t)*CHAR_BIT))) : \
	(*(name + 1 + (index/(sizeof(bitset_t)*CHAR_BIT))) &= ~(((bitset_t) 1) << (index%(sizeof(bitset_t)*CHAR_BIT)))); \

#define bitset_getbit(name, index) \
	(*(name + 1 + (index/(sizeof(bitset_t)*CHAR_BIT))) & ((bitset_t) 1) << (index%(sizeof(bitset_t)*CHAR_BIT))) ? 1 : 0


#else


inline void bitset_free (bitset_t* name) {
	free(name);
}

inline bitset_t bitset_size (bitset_t* name) {
	return *name;
}

inline void bitset_setbit (bitset_t* name, bitset_index_t index, int expression) {
	expression ?
	(*(name + 1 + (index/(sizeof(bitset_t)*CHAR_BIT))) |= ((bitset_t) 1) << (index%(sizeof(bitset_t)*CHAR_BIT))) :
	(*(name + 1 + (index/(sizeof(bitset_t)*CHAR_BIT))) &= ~(((bitset_t) 1) << (index%(sizeof(bitset_t)*CHAR_BIT))));
}

inline int bitset_getbit (bitset_t* name, bitset_index_t index) {
	return (*(name + 1 + (index/(sizeof(bitset_t)*CHAR_BIT))) & ((bitset_t) 1) << (index%(sizeof(bitset_t)*CHAR_BIT))) ? 1 : 0;
}

#endif // USE_INLINE
#endif // _BITSET_H_