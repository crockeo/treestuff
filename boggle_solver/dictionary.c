#include "dictionary.h"

/////////////
// Imports //
#include <stdlib.h>
#include <stdio.h>

#include "fileio.h"
#include "trie.h"

//////////
// Code //

// The location of the dictionary.
const char* dictionary_location = "../dictionaries/dictionary.txt";

// Constructing a Trie from the dictionary.
Trie* construct_dictionary_trie() {
	FILE* f = fopen(dictionary_location, "r");
	if (f == NULL)
		return NULL;

	Trie* t = new_trie();
	
	for (char* word = read_line(f); word != NULL; word = read_line(f)) {
		insert_word(t, word);
		free(word);
	}

	return t;
}
