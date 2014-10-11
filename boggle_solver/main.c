#include <stdio.h>

#include "dictionary.h"
#include "trie.h"

int main() {
	Trie* dict = construct_dictionary_trie();
	delete_trie(dict);
	printf("Nothing here yet.\n");
	return 0;
}
