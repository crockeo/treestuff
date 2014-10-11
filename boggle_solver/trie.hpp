#ifndef _TRIE_HPP_
#define _TRIE_HPP_

//////////
// Code //

// The minimum and maximum character in the range.
extern const char minChar;
extern const char maxChar;

// Calculating the size of the character range.
int calc_char_range();

// Getting the index of a character within the range.
int calc_char_index(char);

// The Trie datatype.
class Trie {
	public:
		// The constructor for a new trie with a specified child length.
		Trie(int);

		// The constructor for a new trie.
		Trie();

		// Deconstructing the trie.
		~Trie();

		// Inserting a word into the trie.
		void insert_word(char*);

		// Checking if a string is a prefix.
		bool string_is_prefix(char*);

		// Checking if a string is a word.
		bool string_is_word(char*);

		// Getting the size of the trie.
		int get_size();

		// Checking if a location in the trie is the end of a word.
		bool get_is_word();

		// Getting the children of the trie.
		Trie** get_children();

	private:
		// Inserting a character into the trie and getting the next level of the
		// trie.
		Trie* insert_char(char);

		int size;
		bool is_word;
		Trie** children;

};

#endif
