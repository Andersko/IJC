	/*
	* File: error.c
	* IJC-DU1, b)
	* Date: 18.3.2020
	* Author: Andrej Pavlovič
	* School: VUT FIT Brno
	* Compiled: gcc 7.5.0
	* Function: error functions
	*/

#include <stdarg.h>
#include <stdnoreturn.h>
#include <stdlib.h>
#include <stdio.h>

#include "error.h"

void warning_msg (const char *fmt, ...) {

	va_list ap;
	va_start(ap, fmt);

	fprintf(stderr, "CHYBA: ");
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");

	va_end(ap);
}

noreturn void error_exit (const char *fmt, ...) {

	va_list ap;
	va_start(ap, fmt);

	fprintf(stderr, "CHYBA: ");
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");

	va_end(ap);

	exit(1);
}