#ifndef _TRIE_H_
#define _TRIE_H_

/////////////
// Imports //
#include <stdbool.h>

//////////
// Code //

// The type definition.
typedef int** Trie;
typedef int*  TriePointer;

// The minimum character for the alphabet range.
extern const char minChar;

// The maximum character for the alphabet range.
extern const char maxChar;

// Calculating the range of the characters.
int calc_range();

// Allocating a new trie.
Trie new_trie();

// Recursively deleting all elements in a trie.
void delete_tree(Trie);

// Inserting a word into the trie.
void insert_word(Trie, char*);

// Checking if a string is a valid prefix within the tree.
bool is_prefix(char*);

// Checking if a string is a complete word within the tree.
bool is_word(char*);

#endif
