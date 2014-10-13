#include "array.hpp"

#include <stdlib.h>

//////////
// Code //

// Creating an array with a specified initial size.
template <class T>
Array<T>::Array(int size) {
	this->size = size;
	this->length = 0;
	this->values = new T*[this->size];
}

// Creating an array with the default initial size (2);
template <class T>
Array<T>::Array() {
	this->size = 2;
	this->length = 0;
	this->values = new T*[this->size];
}

// Deleting an array.
template <class T>
Array<T>::~Array() {
	for (int i = 0; i < this->get_length(); i++)
		free(this->get_ptr(i));
	delete[] this->values;
}

// Inserting a value to the end.
template <class T>
void Array<T>::append(T val) {
	T* val_ptr = (T*)malloc(sizeof(T));
	*val_ptr = val;

	if (this->get_length() >= this->get_size())
		this->double_size();

	this->values[this->length] = val_ptr;
	this->length++;
}

// Seting an element in the array.
template <class T>
void Array<T>::set(int index, T val) {
	if (index >= this->get_length())
		return;
	*this->vaules[index] = val;
}

// Checking if the array contains a pointer.
template <class T>
bool Array<T>::contains_ptr(T* val_ptr) {
	for (int i = 0; i < this->get_length(); i++)
		if (this->get_ptr(i) == val_ptr)
			return true;
	return false;
}

// Checking if the array contains a value.
template <class T>
bool Array<T>::contains(T val) {
	for (int i = 0; i < this->get_length(); i++)
		if (this->get(i) == val)
			return true;
	return false;
}

// Getting a pointer to a single value from the array.
template <class T>
T* Array<T>::get_ptr(int index) {
	return this->values[index];
}

// Getting a single value from the array.
template <class T>
T Array<T>::get(int index) {
	return *this->get_ptr(index);
}

// Getting the current size of memory block in the array.
template <class T>
int Array<T>::get_size() {
	return this->size;
}

// Getting the current length of the array.
template <class T>
int Array<T>::get_length() {
	return this->length;
}

// Doubling the reserved memory of the array.
template <class T>
void Array<T>::double_size() {
	T** new_ts = new T*[this->get_size() * 2];
	for (int i = 0; i < this->get_size(); i++)
		new_ts[i] = this->get_ptr(i);

	for (int i = this->get_size(); i < this->get_size() * 2; i++)
		new_ts[i] = (T)0;

	this->size *= 2;

	delete[] this->values;
	this->values = new_ts;
}

// Halving the reserved memory of the array.
template <class T>
void Array<T>::halve_size() {
	this->size /= 2;

	T** new_ts = new T*[this->get_size()];
	for (int i = 0; i < this->get_size(); i++)
		new_ts[i] = this->get(i);

	delete[] this->values;
	this->values = new_ts;
}
