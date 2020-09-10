/*
 * File: tail.h
 * Project: IJC-DU2, part 1
 * Date of last change: 15.4.2020
 * Author: Andrej Pavlovič <xpavlo14@stud.fit.vutbr.cz>
 * School: VUT FIT Brno
 * Compiled with: gcc 7.5.0
*/

#ifndef TAIL_H
#define	TAIL_H

// primary function, prints lines from file
void tail (int n, char* source, bool reverse);

// main, handling arguments
int main (int argc, char* argv[]);

#endif // TAIL_H