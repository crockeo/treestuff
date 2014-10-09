#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int char_index(char c) {
    return (int) (c - 'a');
}

// Makes a new tree
int** allocate_tree() {
    int** root = malloc(26 * sizeof(int*));
    memset(root, 0, 26 * sizeof(int*));
    return root;
}

// (Possibly) inserts a tree at c of the current root
int** insert_char(int** root, char c) {
    int loc = char_index(c);
    if (root[loc] == 0)
        root[loc] = (int*) allocate_tree();
    return (int**) root[loc];
}

int insert_word(int** root, char* word) {
    if (strlen(word) == 0) {
        return 0;
    }

    int** new_root = insert_char(root, word[0]);

    // Recurse down, making word one letter less
    insert_word(new_root, word + 1);

    return 0;
}

int search(int** root, char* word) {

    if (root == 0) {
        return 0;
    }

    if (strlen(word) == 0) {
        return 1;
    }
    char c = word[0];
    if (!(c >= 'a' && c <= 'z')) {
        return 0;
    }

    int loc = char_index(word[0]);
    int** new_root = (int**) root[loc];
    return search(new_root, word + 1);
}

void file_iterate_lines(char* file_name, int** root, int (*fn)(int**, char*)) {
       FILE * fp;
       char * line = NULL;
       size_t len = 0;
       ssize_t read;

       fp = fopen(file_name, "r");
       if (fp == NULL)
           exit(EXIT_FAILURE);

       while ((read = getline(&line, &len, fp)) != -1) {
           line[strlen(line) - 1] = '\0';
           (*fn)(root, line);
       }

       fclose(fp);
       if (line)
           free(line);
       return;
}

void free_tree(int** root) {
    int i;
    if (root == 0) {
        return;
    }

    for (i = 0; i < 26; i++) {
        free_tree((int**) root[i]);
    }
    free(*root);
    return;
}

int main()
{
    int** root = malloc(26 * sizeof(int*)); // heap
    char* file_name = "../dictionaries/dictionary.txt";

    file_iterate_lines(file_name, root, &insert_word);
    file_iterate_lines(file_name, root, &search);

    free_tree(root);
    return 0;
}
