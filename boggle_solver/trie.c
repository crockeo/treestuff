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
	return (int)(maxChar - minChar);
}

// Allocating a new trie.
Trie new_trie() {
	return NULL;
}

// Recursively deleting all elements in a trie.
void delete_tree(Trie t) {

}

// Inserting a word into the trie.
void insert_word(Trie t, char* word) {

}

// Checking if a string is a valid prefix within the tree.
bool is_prefix(char* word) {
	return false;
}

// Checking if a string is a complete word within the tree.
bool is_word(char* word) {
	return false;
}

/*#include <stdio.h>*/
/*#include <string.h>*/
/*#include <stdlib.h>*/

/*// A synonym for the Tree type (to make the code more self-documenting).*/
/*typedef int** Tree;*/

/*// Finding the equivalent index for a character.*/
/*int char_index(char c) {*/
    /*return (int) (c - 'a');*/
/*}*/

/*// Makes a new tree*/
/*Tree allocate_tree() {*/
    /*Tree root = malloc(26 * sizeof(int*));*/
    /*memset(root, 0, 26 * sizeof(int*));*/
    /*return root;*/
/*}*/

/*// (Possibly) inserts a tree at c of the current root*/
/*Tree insert_char(Tree root, char c) {*/
    /*int loc = char_index(c);*/
    /*if (root[loc] == 0)*/
        /*root[loc] = (int*) allocate_tree();*/
    /*return (Tree) root[loc];*/
/*}*/

/*int insert_word(Tree root, char* word) {*/
    /*if (strlen(word) == 0) {*/
        /*return 0;*/
    /*}*/

    /*Tree new_root = insert_char(root, word[0]);*/

    /*// Recurse down, making word one letter less*/
    /*insert_word(new_root, word + 1);*/

    /*return 0;*/
/*}*/

/*int search(Tree root, char* word) {*/

    /*if (root == 0) {*/
        /*return 0;*/
    /*}*/

    /*if (strlen(word) == 0) {*/
        /*return 1;*/
    /*}*/
    /*char c = word[0];*/
    /*if (!(c >= 'a' && c <= 'z')) {*/
        /*return 0;*/
    /*}*/

    /*int loc = char_index(word[0]);*/
    /*Tree new_root = (Tree) root[loc];*/
    /*return search(new_root, word + 1);*/
/*}*/

/*void file_iterate_lines(char* file_name, Tree root, int (*fn)(Tree, char*)) {*/
       /*FILE * fp;*/
       /*char * line = NULL;*/
       /*size_t len = 0;*/
       /*ssize_t read;*/

       /*fp = fopen(file_name, "r");*/
       /*if (fp == NULL)*/
           /*exit(EXIT_FAILURE);*/

       /*while ((read = getline(&line, &len, fp)) != -1) {*/
           /*line[strlen(line) - 1] = '\0';*/
           /*(*fn)(root, line);*/
       /*}*/

       /*fclose(fp);*/
       /*if (line)*/
           /*free(line);*/
       /*return;*/
/*}*/

/*void free_tree(Tree root) {*/
    /*int i;*/
    /*if (root == 0) {*/
        /*return;*/
    /*}*/

    /*for (i = 0; i < 26; i++) {*/
        /*free_tree((Tree) root[i]);*/
    /*}*/
    /*free(*root);*/
    /*return;*/
/*}*/

/*int main()*/
/*{*/
    /*Tree root = malloc(26 * sizeof(int*)); // heap*/
    /*char* file_name = "../dictionaries/dictionary.txt";*/

    /*file_iterate_lines(file_name, root, &insert_word);*/
    /*file_iterate_lines(file_name, root, &search);*/

    /*free_tree(root);*/
    /*return 0;*/
/*}*/
