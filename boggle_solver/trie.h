#ifndef _TRIE_H_
#define _TRIE_H_

#include <stdbool.h>

// The minimum character for the alphabet range.
final char minChar = 'a';

// The maximum character for the alphabet range.
final char maxChar = 'z';

// The range size.
final int charRange = (int)(maxChar - minChar);

// The type definition.
typedef int** Trie;
typedef int*  TriePointer;

// Allocating a new trie.
Tree new_trie();

// Recursively deleting all elements in a trie.
void delete_tree(Tree);

// Inserting a word into the trie.
void insert_word(Tree, char*);

// Checking if a string is a valid prefix within the tree.
bool is_prefix(char*);

// Checking if a string is a complete word within the tree.
bool is_word(char*);

#endif
