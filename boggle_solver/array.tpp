#include "array.hpp"

//////////
// Code //

// Creating an array with a specified initial size.
template <class T>
Array<T>::Array(int size) {
	this->size = size;
	this->length = 0;
	this->values = new T[this->size];
}

// Creating an array with the default initial size (2);
template <class T>
Array<T>::Array() {
	this->size = 2;
	this->length = 0;
	this->values = new T[this->size];
}

// Deleting an array.
template <class T>
Array<T>::~Array() {
	delete[] this->values;
}

// Inserting a value to the end.
template <class T>
void Array<T>::append(T val) {
	if (this->get_length() >= this->get_size())
		this->double_size();

	this->values[this->length] = val;
	this->length++;
}

// Seting an element in the array.
template <class T>
void Array<T>::set(int index, T val) {
	if (index >= this->get_length())
		return;
	this->vaules[index] = val;
}

// Checking if the array contains a value.
template <class T>
bool Array<T>::contains(T val) {
	for (int i = 0; i < this->get_length(); i++)
		if (this->values[i] == val)
			return true;
	return false;
}

// Popping the first value off of the array.
template <class T>
T Array<T>::pop_first() {
	T val = this->get(0);
	for (int i = 1; i < this->get_length(); i++)
		this->values[i - 1] = this->values[i];
	length--;

	if (this->get_length() < this->get_size() / 2)
		this->halve_size();

	return val;
};

// Peeking at the first value in the array.
template <class T>
T Array<T>::peek_first() {
	return this->get(0);
}

// Popping the last value off of the array.
template <class T>
T Array<T>::pop_last() {
	T val = this->get(this->get_length() - 1);
	this->length -= 1;

	if (this->get_length() < this->get_size() / 2)
		this->halve_size();

	return val;
};

// Peeking at the last value in the array.
template <class T>
T Array<T>::peek_last() {
	return this->get(this->get_length() - 1);
}

// Getting a single value from the array.
template <class T>
T Array<T>::get(int index) {
	return this->values[index];
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
	T* new_ts = new T[this->get_size() * 2];
	for (int i = 0; i < this->get_size(); i++)
		new_ts[i] = this->get(i);

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

	T* new_ts = new T[this->get_size()];
	for (int i = 0; i < this->get_size(); i++)
		new_ts[i] = this->get(i);

	delete[] this->values;
	this->values = new_ts;
}
