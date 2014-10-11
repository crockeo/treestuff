#include <stdio.h>

#include "trie.h"

int main() {
	Trie* t = new_trie();

	printf("Inserting...\n");
	insert_word(t, "testing");
	insert_word(t, "word");
	insert_word(t, "hahaha");

	printf("Is Prefix...\n");
	printf("%i\n", is_prefix(t, "test"));

	printf("Is Word...\n");
	printf("%i\n", is_word(t, "test"));

	return 0;
}
