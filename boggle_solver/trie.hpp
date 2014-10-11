#ifndef _TRIE_HPP_
#define _TRIE_HPP_

// The minimum and maximum character in the range.
extern const char minChar;
extern const char maxChar;

// Calculating the size of the character range.
int calcCharRange();

// Getting the index of a character within the range.
int calcCharIndex(char);

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
		bool stringIsPrefix(char*);

		// Checking if a string is a word.
		bool stringIsWord(char*);

		// Getting the size of the trie.
		int getSize();

		// Checking if a location in the trie is the end of a word.
		bool getIsWord();

		// Getting the children of the trie.
		Trie** getChildren();

	private:
		// Inserting a character into the trie and getting the next level of the
		// trie.
		Trie* insert_char(char);

		int size;
		bool isWord;
		Trie** children;

};

#endif
