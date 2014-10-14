#include "mystring.hpp"

/////////////
// Imports //
#include <iostream>
#include <string.h>

#include "array.hpp"

//////////
// Code //

// Constructing a string from a c string.
String::String(char* word) : Array<char>() {
	int l = strlen(word);
	for (int i = 0; i < l; i++)
		this->append(word[i]);
}

// Constructing a string with a given capacity.
String::String(int size) : Array<char>(size) { }

// Constructing a string with a default capacity.
String::String() : Array<char>() { }

// Printing out the strng.
void String::print() {
	for (int i = 0; i < this->get_length(); i++)
		std::cout << this->get(i);
}

// Printing out the string with a newline after.
void String::println() {
	this->print();
	std::cout << "\n";
}
