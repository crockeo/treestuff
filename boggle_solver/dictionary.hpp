#ifndef _DICTIONARY_HPP_
#define _DICTIONARY_HPP_

/////////////
// Imports //
#include "trie.hpp"

//////////
// Code //

// The location of the dictionary.
extern const char* dictionary_location;

// Loading the dictionary trie into the program. If it already exists within
// memory then it'll just return that pointer.
Trie* load_dictionary_trie();

// Deleting a loaded dictionary trie if it exists.
void delete_dictionary_trie();

#endif
