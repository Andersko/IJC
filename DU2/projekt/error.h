/*
 * File: error.h
 * Project: IJC-DU2, part 1, part 2
 * Date of last change: 15.4.2020
 * Author: Andrej Pavlovič <xpavlo14@stud.fit.vutbr.cz>
 * School: VUT FIT Brno
 * Compiled with: gcc 7.5.0
*/

#ifndef _ERROR_H_
#define _ERROR_H_

// warning message to stderr, program continues
void warning_msg (const char*, ...);

// error message to stderr, program exits
void error_exit (const char*, ...);

#endif // _ERROR_H_