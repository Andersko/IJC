	/*
	* File: ppm.c
	* IJC-DU1,  b)
	* Date: 18.3.2020
	* Author: Andrej Pavlovič
	* School: VUT FIT Brno
	* Compiled: gcc 7.5.0
	* Function: load data of ppm file to structure
	*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "ppm.h"
#include "error.h"

struct ppm * ppm_read(const char * filename) {

	FILE *file = fopen(filename,"rb");

	// file opening failed
	if ( !file ) {
		error_exit("ppm_read: file \"%s\" does not exist", filename);
	}

	unsigned long xsize, ysize, maxval;

	// scanning and checikng file header
	if ( fgetc(file) != 'P' || fgetc(file) != '6' || fscanf(file, " %lu %lu %lu", &xsize, &ysize, &maxval) != 3 || maxval != 255 || !isspace(fgetc(file)) || isspace(fgetc(file)) ) {
		warning_msg("ppm_read: file \"%s\" has invalid format", filename);
		return NULL;
	}

	// control if file contain any data
	if ( xsize < 1 || ysize < 1 ) {
		warning_msg("ppm_read: file has no visual data");
		return NULL;
	}

	// one step back in file
	fseek(file, -1, SEEK_CUR);

	struct ppm* pic = (struct ppm*) malloc(sizeof(struct ppm) + (3 * xsize * ysize));

	// memory alloc cotrol
	if ( !pic ) {
		warning_msg("ppm_read: memory allocation error");
		return NULL;
	}

	// load binary data
	if ( fread(pic->data, 1, 3 * xsize * ysize, file) != 3 * xsize * ysize || fgetc(file) != EOF ) {
		warning_msg("ppm_read: file \"%s\" probably has invalid format (header data information is incorrect)", filename);
		free(pic);
		fclose(file);
		return NULL;
	}

	// saving information to struct
	pic->xsize = xsize;
	pic->ysize = ysize;

	fclose(file);
	return pic;
}

void ppm_free(struct ppm *p) {
	free(p);
}