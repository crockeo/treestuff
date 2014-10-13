#ifndef _MYSTRING_HPP_
#define _MYSTRING_HPP_

/////////////
// Imports //
#include "array.hpp"

//////////
// Code //

// My string datatype.
class String : public Array<char> {
	public:
		// Constructing a string from a c string.
		String(char*);

		// Constructing a string with a given capacity.
		String(int);

		// Constructing a string with a default capacity.
		String();

		// Printing out the strng.
		void print();

		// Printing out the string with a newline after.
		void println();
};

#endif
