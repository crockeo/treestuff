#include "dictionary.hpp"

/////////////
// Imports //
#include <fstream>

#include "trie.hpp"

//////////
// Code //

// The buffered reference to the dictionary trie.
Trie* dictionary_trie = nullptr;

// The location of the dictionary.
const char* dictionary_location = "../dictionaries/dictionary.txt";

// Loading the dictionary trie into the program. If it already exists within
// memory then it'll just return that pointer.
Trie* load_dictionary_trie() {
	if (dictionary_trie == nullptr) {
		dictionary_trie = new Trie;

		std::ifstream ifs;
		ifs.open(dictionary_location, std::ifstream::in);

		char* word = new char[256];
		while (ifs.good()) {
			ifs.getline(word, 256);
			dictionary_trie->insert_word(word);
		}

		delete[] word;
	}

	return dictionary_trie;
}

// Deleting a loaded dictionary trie if it exists.
void delete_dictionary_trie() {
	if (dictionary_trie != nullptr) {
		delete dictionary_trie;
		dictionary_trie = nullptr;
	}
}
