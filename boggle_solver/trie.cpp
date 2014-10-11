#include "trie.hpp"

/////////////
// Imports //
#include <iostream>
#include <string.h>

//////////
// Code //

// The minimum and maximum character in the range.
const char minChar = 'a';
const char maxChar = 'z';

// Calculating the size of the character range.
int calc_char_range() {
	return 1 + (int)(maxChar - minChar);
}

// Getting the index of a character within the range.
int calc_char_index(char c) {
	if (c < minChar || c > maxChar)
		return -1;
	return (int)(c - minChar);
}

// The constructor for a new trie with a specified child length.
Trie::Trie(int size) {
	this->size = size;
	this->is_word = false;

	this->children = new Trie*[size];
	for (int i = 0; i < size; i++)
		this->children[i] = nullptr;
}

// The constructor for a new trie.
Trie::Trie() {
	this->size = calc_char_range();
	this->is_word = false;

	this->children = new Trie*[size];
	for (int i = 0; i < size; i++)
		this->children[i] = nullptr;
}

// Deconstructing the trie.
Trie::~Trie() {
	for (int i = 0; i < this->size; i++)
		delete this->get_children()[i];
	delete[] this->get_children();
}

// Inserting a word into the trie.
void Trie::insert_word(char* word) {
	if (strlen(word) == 0) {
		this->is_word = true;
		return;
	}

	char c = word[0];
	int ci = calc_char_index(c);
	if (ci == -1)
		return;

	Trie* next = insert_char(c);
	if (next == nullptr)
		return;

	next->insert_word(word + 1);
}

// Checking if a string is a prefix.
bool Trie::string_is_prefix(char* word) {
	if (strlen(word) == 0)
		return true;

	int ci = calc_char_index(word[0]);
	if (ci == -1)
		return false;

	if (this->get_children()[ci] == nullptr)
		return false;

	return this->get_children()[ci] -> string_is_prefix(word + 1);
}

// Checking if a string is a word.
bool Trie::string_is_word(char* word) {
	if (strlen(word) == 0)
		return this->get_is_word();

	int ci = calc_char_index(word[0]);
	if (ci == -1)
		return false;

	if (this->get_children()[ci] == nullptr)
		return false;

	return this->get_children()[ci] -> string_is_word(word + 1);
}

// Getting the size of the trie.
int Trie::get_size() {
	return this->size;
}

// Checking if a location in the trie is the end of a word.
bool Trie::get_is_word() {
	return this->is_word;
}

// Getting the children of the trie.
Trie** Trie::get_children() {
	return this->children;
}

// Inserting a character into the trie and getting the next level of the trie.
Trie* Trie::insert_char(char c) {
	int ci = calc_char_index(c);
	if (ci == -1)
		return nullptr;

	if (this->get_children()[ci] == nullptr)
		this->get_children()[ci] = new Trie(this->get_size());

	return this->get_children()[ci];
}
