#ifndef _TRIE_H_
#define _TRIE_H_

/////////////
// Imports //
#include <stdbool.h>

//////////
// Code //

// The data structure of the Trie.
typedef struct Trie {
	bool is_word;
	struct Trie** children;
} Trie;

// The minimum character for the alphabet range.
extern const char minChar;

// The maximum character for the alphabet range.
extern const char maxChar;

// Calculating the range of the characters.
int calc_range();

// Calculating the index a character represents.
int calc_index(char);

// Allocating a new trie.
Trie* new_trie();

// Recursively deleting all elements in a trie.
void delete_trie(Trie*);

// Inserting a char into the trie.
Trie* insert_char(Trie*, char);

// Inserting a word into the trie.
void insert_word(Trie*, char*);

// Checking if a string is a valid prefix within the tree.
bool is_prefix(Trie*, char*);

// Checking if a string is a valid prefix within the tree.
bool is_word(Trie*, char*);

#endif
