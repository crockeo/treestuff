#include <iostream>

#include "trie.hpp"

int main() {
	Trie* t = new Trie;

	std::cout << "Inserting...\n";
	t->insert_word("hello");

	std::cout << "Searching (prefix)...\n";
	std::cout << t->string_is_prefix("hell") << "\n";
	std::cout << t->string_is_prefix("hellooo") << "\n";

	std::cout << "Searching (word)...\n";
	std::cout << t->string_is_word("hello") << "\n";

	delete t;
}
