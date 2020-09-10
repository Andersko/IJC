	/*
	* File: error.h
	* IJC-DU1,  b)
	* Date: 18.3.2020
	* Author: Andrej Pavlovič
	* School: VUT FIT Brno
	* Compiled: gcc 7.5.0
	* HEADER FILE
	*/

#ifndef _ERROR_H_
#define _ERROR_H_

#include <stdnoreturn.h>

// warning message to stderr, program continues
void warning_msg (const char*, ...);

// error message to stderr, program exits
noreturn void error_exit (const char*, ...);

#endif // _ERROR_H_