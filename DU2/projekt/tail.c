/*
 * File: tail.c
 * Project: IJC-DU2, part 1
 * Date of last change: 15.4.2020
 * Author: Andrej Pavlovič <xpavlo14@stud.fit.vutbr.cz>
 * School: VUT FIT Brno
 * Compiled with: gcc 7.5.0
 * Function: print last n lines of file on stdout or jump over n lines and print rest on stdout
 * Arguments: 	[-n number]	-> number of lines to print, if set with '+' sign it's number of lines to jump over (default n = 10)
 *				[file]		-> file destination (if not set, reads from stdin)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tail.h"
#include "error.h"


#define ERROR \
	"error occured while parsing arguments, usage:\n\n  [-n number]\tn>0, number of lines " \
	"to print, if set with '+' sign\n\t\tit's number of lines to jump over (default n = 10)\n\n  " \
	"[file]\tfile destination (if not set, reads from stdin)\n"


void tail (int n, char* source, bool reverse) {

	FILE* file;

	// set source file
	if ( strcmp(source, "stdin") ) {
		file = fopen(source, "r");

		if ( !file ) {
			error_exit("%s: no such file or directory", source);
		}
	}
	else {
		file = stdin;
	}

	int offset = 0;
	char c;

	if ( reverse ) {
		offset = n - 1;
	}

	else {

		// count newlines
		while ( (c = fgetc(file)) != EOF ) {
			if ( c == '\n' ) {
				offset++;
			}
		}

		// counts one less line because last character is EOF
		offset++;

		// count offset from start of file
		if ( ! ((offset = n - offset) < 1) ) {
			offset = 0;
		}
		else {
			offset = abs(offset);
		}

		// set file pointer to start
		fseek(file, 0, SEEK_SET);
	}

	// set file pointer to offset position
	for ( int i = 0; i < offset; ) {
		while ( (c = fgetc(file)) ) {
			if ( c == '\n' || c == EOF ) {
				i++;
				break;
			}
		}
	}

	// print lines
	while ( (c = fgetc(file)) != EOF ) {
		printf("%c", c);
	}

	fclose(file);
}


int main (int argc, char* argv[]) {

	int n = 10;
	char* source;
	bool reverse = false;

	// arguments handling
	if ( argc == 1 ) {
		source = "stdin";
	}
	else if ( argc == 2 && argv[1][0] != '-' ) {
		source = argv[1];
	}
	else if ( argc == 3 ) {
		
		if ( strcmp(argv[1], "-n") ) {
			error_exit(ERROR);
		}

		for ( unsigned i = 0; i < strlen(argv[2]); i++ ) {
			if ( (!(argv[2][i] >= 48 && argv[2][i] <= 57)) && argv[2][i] != 43 ) {
				error_exit(ERROR);
			}
		}

		if ( argv[2][0] == 43 ) {
			reverse = true;
		}

		n = atoi(argv[2]);
		source = "stdin";
	}
	else if ( argc == 4 ) {

		int n_pos;

		if ( ! strcmp(argv[1], "-n") ) {
			n_pos = 2;
			source = argv[3];
		}
		else if( ! strcmp(argv[2], "-n") ) {
			n_pos = 3;
			source = argv[1];
		}
		else {
			error_exit(ERROR);
		}

		for ( unsigned i = 0; i < strlen(argv[n_pos]); i++ ) {
			if ( (!(argv[n_pos][i] >= 48 && argv[n_pos][i] <= 57)) && argv[n_pos][i] != 43 ) {
				printf("\n");
				error_exit(ERROR);
			}
		}

		if ( argv[n_pos][0] == 43 ) {
			reverse = true;
		}

		n = atoi(argv[n_pos]);
	}
	else {
		error_exit(ERROR);
	}

	if ( n <= 0 ) {
		error_exit(ERROR);
	}
	
	// tail function
	tail(n, source, reverse);

	return 0;
}