#include "fileio.h"

/////////////
// Imports //
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//////////
// Code //

// Doubling the length of a word.
char* double_length(char* str, int length) {
	char* new_str = (char*)malloc(length * 2 * sizeof(char));
	memset(new_str, '\0', length * 2 * sizeof(char));
	strcpy(new_str, str);
	free(str);
	return new_str;
}

// Changing the size of a char* to its exact size.
char* exact_size(char* str) {
	char* new_str = (char*)malloc(strlen(str) * sizeof(char));
	strcpy(new_str, str);
	free(str);
	return new_str;
}

// Reading a single line out of a file.
char* read_line(FILE* f) {
	int ic = fgetc(f);
	if (ic == EOF)
		return NULL;

	int wordlen = 1;
	int pos = 0;
	char* word = (char*)malloc(wordlen * sizeof(char));

	char c;
	while (true) {
		c = (char)ic;

		if (c == '\n') {
			word[pos] = '\0';
			break;
		}

		word[pos] = c;
		pos++;
		if (pos >= wordlen) {
			word = double_length(word, wordlen);
			wordlen *= 2;
		}

		ic = fgetc(f);
	}

	return exact_size(word);
}
