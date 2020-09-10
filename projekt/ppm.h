	/*
	* File: ppm.h
	* IJC-DU1,  b)
	* Date: 18.3.2020
	* Author: Andrej Pavlovič
	* School: VUT FIT Brno
	* Compiled: gcc 7.5.0
	* HEADER FILE
	*/

#ifndef _PPM_H_
#define _PPM_H_

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bytes (size is 3*xsize*ysize)
};

struct ppm * ppm_read(const char*);
void ppm_free(struct ppm*);

#endif // _PPM_H_