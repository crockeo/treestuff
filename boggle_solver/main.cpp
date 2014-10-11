#include <iostream>

#include "dictionary.hpp"
#include "trie.hpp"

int main() {
	Trie* t = load_dictionary_trie();
	delete t;
}
