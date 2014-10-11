#include "trie.hpp"

/////////////
// Imports //
#include <string.h>

//////////
// Code //

// The minimum and maximum character in the range.
const char minChar = 'a';
const char maxChar = 'z';

// Calculating the size of the character range.
int calcCharRange() {
	return 1 + (int)(maxChar - minChar);
}

// Getting the index of a character within the range.
int calcCharIndex(char c) {
	if (c < minChar || c > maxChar)
		return -1;
	return (int)(c - minChar);
}

// The constructor for a new trie with a specified child length.
Trie::Trie(int size) {
	this->size = size;
	this->isWord = false;
	this->children = new Trie*[size];
}

// The constructor for a new trie.
Trie::Trie() {
	this->size = calcCharRange();
	this->isWord = false;
	this->children = new Trie*[size];
}

// Deconstructing the trie.
Trie::~Trie() {
	for (int i = 0; i < this->size; i++)
		delete this->getChildren()[i];
	delete[] this->getChildren();
}

// Inserting a word into the trie.
void Trie::insert_word(char* word) {
	if (strlen(word) == 0)
		return;

	char c = word[0];
	int ci = calcCharIndex(c);
	if (ci == -1)
		return;

	Trie* next = insert_char(c);
	if (next == nullptr)
		return;

	next->insert_word(word + 1);
}

// Checking if a string is a prefix.
bool Trie::stringIsPrefix(char* word) {
	if (strlen(word) == 0)
		return true;

	int ci = calcCharIndex(word[0]);
	if (ci == -1)
		return false;

	if (this->getChildren()[ci] == nullptr)
		return false;

	return this->getChildren()[ci] -> stringIsPrefix(word + 1);
}

// Checking if a string is a word.
bool Trie::stringIsWord(char* word) {
	if (strlen(word) == 0)
		return this->getIsWord();

	int ci = calcCharIndex(word[0]);
	if (ci == -1)
		return false;

	if (this->getChildren()[ci] == nullptr)
		return false;

	return this->getChildren()[ci] -> stringIsWord(word + 1);
}

// Getting the size of the trie.
int Trie::getSize() {
	return this->size;
}

// Checking if a location in the trie is the end of a word.
bool Trie::getIsWord() {
	return this->isWord;
}

// Getting the children of the trie.
Trie** Trie::getChildren() {
	return this->children;
}

// Inserting a character into the trie and getting the next level of the trie.
Trie* Trie::insert_char(char c) {
	int ci = calcCharIndex(c);
	if (ci == -1)
		return nullptr;

	if (this->getChildren()[ci] == nullptr)
		this->getChildren()[ci] = new Trie(this->getSize());

	return this->getChildren()[ci];
}
