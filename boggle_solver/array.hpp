#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

template <class T>
class Array {
	public:
		// Creating an array with a specified initial size.
		Array(int);
		
		// Creating an array with the default initial size (2);
		Array();

		// Deleting an array.
		~Array();

		// Inserting a value to the end.
		void append(T);

		// Concatenating an array with this array.
		void concatenate(Array<T>*);

		// Seting an element in the array.
		void set(int, T);

		// Checking if the array contains a pointer.
		bool contains_ptr(T*);

		// Checking if the array contains a value.
		bool contains(T);

		// Getting a pointer to a single value from the array.
		T* get_ptr(int);

		// Getting a single value from the array.
		T get(int);

		// Getting the current size of memory block in the array.
		int get_size();

		// Getting the current length of the array.
		int get_length();

	private:
		// The size the array takes up in memory.
		int size;

		// The current number of indices filled in the array.
		int length;

		// The raw list of values in the array.
		T** values;

		// Doubling the reserved memory of the array.
		void double_size();

		// Halving the reserved memory of the array.
		void halve_size();
};

#include "array.tpp"

#endif
