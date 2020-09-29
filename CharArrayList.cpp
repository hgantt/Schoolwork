// David Gantt
// January 29th, 2020
// comp15: Data structures
// Implementation for the CharArrayList class. All of the member
// function are defined.

#include <iostream>
#include "CharArrayList.h"


using namespace std;

CharArrayList::CharArrayList() {
	// Initialize private data members
	numChars = capacity = 0;

	// Allocate memory on the heap for my array
	data = new char[capacity];
}

CharArrayList::CharArrayList(char c) {
	// Initialize private data members
	numChars = capacity = 1;

	// Allocate memory on the heap for my array
	data = new char[capacity];
	
	// Insert the given char at pos 0
	data[0] = c;
}

CharArrayList::CharArrayList(char array[], int length) {
	// Initialize private data members
	numChars = capacity = length;

	// Allocate memory on the heap for my array
	data = new char[length];

	// Copy the contents of the given array into the new array
	for (int i = 0; i < length; i++) {
		data[i] = array[i];
	}
}

CharArrayList::CharArrayList(const CharArrayList& list) {
	// Initialize private data members
	numChars = capacity = list.numChars;

	// Allocate memory on the heap for my new array
	data = new char[capacity];

	// Copy the contents from the array from the passed object's
	// array to the new object's array
	for (int i = 0; i < numChars; i++) {
		data[i] = list.data[i];
	}
}

CharArrayList& CharArrayList::operator= (const CharArrayList& rhs) {
	if (this != &rhs) {
		//recycle data
		delete [] data;

		numChars = rhs.numChars;
		capacity = numChars;
		data = new char[numChars];

		// make a deep copy
		for (int i = 0; i < numChars; i++) {
			data[i] = rhs.data[i];
		}
	}
	return *this;
}

CharArrayList::~CharArrayList() {
	// Delete the memory allocated for the array
	delete [] data;

	// Set the pointer to null
	data = nullptr;
	numChars = capacity = -1;
}

void CharArrayList::print() {
	// Print the array's contents by iterating through the array
	cout << "[CharArrayList of size " << numChars << " " << "<<";
	for (int i = 0; i < numChars; i++) {
			cout << data[i];
	}
	cout << ">" << ">]" << endl;
}

bool CharArrayList::isEmpty() {
	// Check to see if the array is empty by inspecting the number
	// of elements
	if (numChars == 0)
		return true;
	else
		return false;
}

int CharArrayList::size() {
	// return the number of elements in the array
	return numChars;
}

void CharArrayList::clear() {
	// set all of the elements to an empty char
	for (int i = 0; i < numChars; i++)
		data[i] = '\0';
	// set the number of elements to 0
	numChars = 0;
}

char CharArrayList::elementAt(int i) {
	// check for error
	string error = "index (" + to_string(i) + ") not in range [0.." +
		to_string(numChars) + ")";
	if ((i >= numChars) or (i < 0)) {
		throw range_error(error);
	// if no error, then return the element at the given index	
	} else
		return data[i];
}

void CharArrayList::removeAt(int i) {
	string error = "index (" + to_string(i) + ") not in range [0.." +
		to_string(numChars) + ")";
	if ((i >= numChars) or (i < 0)) {
		throw range_error(error);
	} 

	for (int count = i; count < numChars; count++) {
		data[count] = data[count+1];
	}
	data[numChars-1] = '\0';
	numChars--;
}

void CharArrayList::insertAt(char c, int i) {
	// check for error
	string error = "index (" + to_string(i) + ") not in range [0.." +
		to_string(numChars) + "]";
	if (i < 0 or i > numChars) {
		throw range_error(error);
	}
	// check for expansion
	if (numChars == capacity) {
			expand();
	// shift part of the array right to make space for the new element
	}
	for (int p = numChars; p > i; p--) {
		data[p] = data[p-1];
	}
	// insert the element and increment number of elements
	data[i] = c;
	numChars++;
}


void CharArrayList::pushAtBack(char c) {
	// insert a given char at the back
	insertAt(c, numChars);
}

void CharArrayList::pushAtFront(char c) {
	// insert a given char at the front
	insertAt(c, 0);
}

void CharArrayList::insertInOrder(char c) {
	// iterate through array, comparing chars to find correct insertion spot
	for (int i = 0; i < numChars; i++) {
		if (c <= data[i]) {
			insertAt(c, i);
			break;
		}
	}
}

void CharArrayList::shrink() {
	// allocate memory for new array
	char * newArray = new char [numChars];

	// copy data
	for (int i = 0; i < numChars; i++) {
		newArray[i] = data[i];
	}

	// delete old memory
	delete [] data;

	// update private data members
	data = newArray;
	capacity = numChars;
}

// PRIVATE MEMBER FUNCTION
void CharArrayList::expand() {
	// allocate memory for new array
	char * newArray = new char [(2 + (2*capacity))];
	// copy data contents
	for (int i = 0; i < numChars; i++) {
		newArray[i] = data[i];
	}
	// delete old array
	delete [] data;
	// update private data members
	data = newArray;
	capacity = (2 + (capacity * 2));
}

char CharArrayList::first() {
	// check for error
	if (numChars == 0) {
		throw runtime_error("cannot get first of empty ArrayList");
	// return first element
	} else {
		return data[0];
	}
}


char CharArrayList::last() {
	// check for error
	if (numChars == 0) {
		throw runtime_error("cannot get last of empty ArrayList");
	// return last element
	} else {
		return data[numChars-1];
	}
}

void CharArrayList::replaceAt(char c, int i) {
	// check for error messages
	string error = "index (" + to_string(i) + ") not in range [0.." +
		to_string(numChars) + ")";
	if (i >= numChars) {
		throw range_error(error); 
	// replace a given element w/ a given char
	} else {
		data[i] = c;
	}
}

void CharArrayList::popFromFront() {
	// check for error
	if (numChars == 0) {
		throw runtime_error("cannot pop from empty ArrayList");
	} else {
		// remove first element
		data[0] = '\0';
		// shift array left
		for (int i = 0; i < numChars; i++) {
			data[i] = data [i+1];
		}
		// decrement numchars
		numChars--;
	}
}

void CharArrayList::popFromBack() {
	// check for errors
	if (numChars == 0) {
		throw runtime_error("cannot pop from empty ArrayList");
	} else {
		// clear last element
		data[numChars-1] = '\0';
		numChars--;
	}
}

void CharArrayList::concatenate(CharArrayList * list) {
	// find size for second list
	int numCharsTwo = list->size();
	// iterate through second array to add those characters to
	// the end of the first array
	for (int i = 0; i < numCharsTwo; i++) {
		insertAt (list->elementAt(i), numChars);
	}
}

// I used this for testing
// int CharArrayList::getCap() {
//	return capacity;
// }