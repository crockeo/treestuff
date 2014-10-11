#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

//////////
// Code //

// The path to the dictionary.
extern char* dictionary_path;

// Getting the number of currently loaded words. -1 stands for no words loaded.
int get_loaded_words();

// Getting the array of words.
char** get_words();

// Freeing the list of words.
void free_words();

// Freeing and then reloading the list of words.
char** reload_words();

#endif
