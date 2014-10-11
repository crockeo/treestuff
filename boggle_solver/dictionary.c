#include "dictionary.h"

/////////////
// Imports //
#include <stdlib.h>

//////////
// Code //

// The internal buffer of words.
char** words = NULL;

// The number of currently loaded words.
int loaded_words = -1;

// The path to the dictionary.
char* dictionary_path = "../dictionaries/dictionary.txt";

// Getting the number of currently loaded words. -1 stands for no words loaded.
int get_loaded_words() {
	return loaded_words;
}

// Getting the array of words.
char** get_words() {
	if (words == NULL) {
		FILE* f = fopen(dictionary_path, "r");
		if (f == NULL)
			return NULL;

		// TODO: Implement the rest of get_words()
	}

	return words;
}

// Freeing the list of words.
void free_words() {
	for (int i = 0; i < get_loaded_words(); i++)
		if (words[i] != NULL)
			free(words[i]);
	free(words);
}

// Freeing and then reloading the list of words.
char** reload_words() {
	free_words();
	return get_words();
}
