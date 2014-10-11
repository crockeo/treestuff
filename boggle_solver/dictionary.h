#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

/////////////
// Imports //
#include "trie.h"

//////////
// Code //

// The location of the dictionary.
extern const char* dictionary_location;

// Constructing a Trie from the dictionary.
Trie* construct_dictionary_trie();

#endif
