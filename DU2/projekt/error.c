/*
 * File: error.c
 * Project: IJC-DU2, part 1, part 2
 * Date of last change: 15.4.2020
 * Author: Andrej Pavlovič <xpavlo14@stud.fit.vutbr.cz>
 * School: VUT FIT Brno
 * Compiled with: gcc 7.5.0
 * Function: error handling
*/

#include <stdarg.h>
#include <stdnoreturn.h>
#include <stdlib.h>
#include <stdio.h>

#include "error.h"

void warning_msg (const char *fmt, ...) {

	va_list ap;
	va_start(ap, fmt);

	fprintf(stderr, "ERROR: ");
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");

	va_end(ap);
}

void error_exit (const char *fmt, ...) {

	va_list ap;
	va_start(ap, fmt);

	fprintf(stderr, "ERROR: ");
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");

	va_end(ap);

	exit(1);
}