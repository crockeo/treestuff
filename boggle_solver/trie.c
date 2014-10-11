#include "trie.h"

////////////////////
// Global Imports //
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//////////
// Code //

// The minimum character for the alphabet range.
const char minChar = 'a';

// The maximum character for the alphabet range.
const char maxChar = 'z';

// Calculating the range of the characters.
int calc_range() {
	return 1 + (int)(maxChar - minChar);
}

// Calculating the index a character represents.
int calc_index(char c) {
	if (c < minChar || c > maxChar)
		return -1;

	return (int)(c - minChar);
}

// Allocating a new trie.
Trie* new_trie() {
	Trie* t = (Trie*)malloc(sizeof(Trie));

	t->is_word = false;
	t->children = (Trie**)malloc(calc_range() * sizeof(Trie*));
	memset(t->children, 0, calc_range() * sizeof(Trie*));

	return t;
}

// Recursively deleting all elements in a trie.
void delete_trie(Trie* t) {
	for (int i = 0; i < calc_range(); i++)
		if (t->children[i] == NULL)
			delete_trie(t->children[i]);
	free(t);
}

// Inserting a char into the trie.
Trie* insert_char(Trie* t, char c) {
	int char_index = calc_index(c);
	if (char_index == -1)
		return NULL;

	if (t->children[char_index] == NULL)
		t->children[char_index] = new_trie();

	return t->children[char_index];
}

// Inserting a word into the trie.
void insert_word(Trie* t, char* word) {
	if (strlen(word) == 0) {
		t->is_word = true;
		return;
	}

	printf("%s\n", word);

	Trie* nt = insert_char(t, word[0]);
	if (nt == NULL)
		return;
	
	insert_word(nt, word + 1);
}

// Checking if a string is a valid prefix within the tree.
bool is_prefix(Trie* t, char* word) {
	if (strlen(word) == 0)
		return true;

	if (t == NULL)
		return false;

	printf("%s\n", word);

	int char_index = calc_index(word[0]);
	if (char_index == -1)
		return false;

	return is_prefix(t->children[char_index], word + 1);
}

// Checking if a string is a valid word within the tree.
bool is_word(Trie* t, char* word) {
	if (strlen(word) == 0)
		return t->is_word;

	if (t == NULL)
		return false;

	printf("%s\n", word);

	int char_index = calc_index(word[0]);
	if (char_index == -1)
		return false;

	return is_word(t->children[char_index], word + 1);
}
