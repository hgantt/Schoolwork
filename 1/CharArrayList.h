// David Gantt
// January 29th, 2020
// comp15: Data Structures
// Header file for the CharArrayList class. Includes the
// definition for the CharArrayList class and the declarations of
// its many members.

#ifndef CHARARRAYLIST_H
#define CHARARRAYLIST_H

#include <iostream>

using namespace std;

// The CharArrayList class stores a dynamically allocated array of chars
// and several member functions which performs various operations
// on said array. 
class CharArrayList {
	public:
		// The default/nullary constructor. Takes no parameters,
		// has no return value. Creates an empty instance
		// of the class CharArrayList
		CharArrayList(); // default or nullary constructor

		// A paramaterized constructor. Takes one char, 
		// and has no return value. Creates an instance of
		// the class CharArrayList with one element, char c.
		CharArrayList(char c); // paramaterized constructor


		// Another paramaterized constructor. This takes 
		// an array of chars and an integer representing the length
		// of that array. It creates a new instance of the CharArrayList
		// class with the contents of the given array.
		CharArrayList(char array[], int length);

		// Copy constructor for the CharArrayList class. It takes a 
		// pointer to another class object and makes a deep copy of the
		// class.
		CharArrayList(const CharArrayList &list);

		// Assignment operator. Takes a pointer to another class object
		// and returns nothing. 
		CharArrayList& operator=(const CharArrayList& rhs);

		// Destructor. Takes no paramaters, and has no return value.
		// Frees up allocated memory on the heap.
		~CharArrayList(); // destructor

		// "print" function. Takes no paramaters, returns nothing.
		// Prints out the array list in the manner described
		// in the assignment specification.
		void print(); // print function

		// "isEmpty" function. Takes no paramaters, 
		// returns a boolean value. If the array list is empty,
		// it returns true. Otherwise, it returns false.
		bool isEmpty(); 

		// "size" function. Takes no paramaters, returns an integer
		// (the number of elements in the array)
		int size();

		// "clear" function. Takes no paramaters, returns nothing.
		// Clears the array, setting the number of elements to zero.
		void clear();

		// "elementAt" function. Takes an integer (index)
		// and returns a char (the data at the specified index). 
		char elementAt(int i);

		// "insertAt" function. Takes a char and an integer, 
		// and returns nothing.
		// Inserts the specified char "c" at the 
		// given index "i" and adjusts the array list accordingly.
		void insertAt(char c, int i);


		// "removeAt" function. Takes an integer index and returns nothing.
		// Removes the data at the given index. 
		void removeAt(int i);

		// "pushAtBack" function. Takes a char, and returns nothing.
		// Inserts the given char at the back of the array.
		void pushAtBack(char c);

		// "pushAtFront" function. Takes a char, and returns nothing.
		// Inserts the given char at the front of the array.
		void pushAtFront(char c);

		// "insertInOrder" function. Takes a char, and returns nothing.
		// Inserts the given char in alphabetical order, 
		// assuming ascending order.
		void insertInOrder(char c);

		// "shrink" function. Takes nothing and returns nothing.
		// Shrinkwraps the array, such that the capacity
		// is equivalent to the number of elements.
		void shrink();

		// '"first' function. Takes nothing and returns 
		// a char (the first element in the array)
		char first();

		// "last" function. Takes nothing and returns a char 
		// (the last element in the array)
		char last();

		// "replaceAt" function. Takes a char and an index integer, 
		// and returns nothing. Replaces the current element 
		// at the given index with the given char.
		void replaceAt(char c, int i);

		// "popFromFront" function. Takes nothing and returns nothing. 
		// Removes the first element in the array and adjusts accordingly.
		void popFromFront();

		// "popFromBack" function. Takes nothing and returns nothing.
		// Removes the first elements in the array and adjusts accordingly.
		void popFromBack();

		// "concatenate" function. Takes a pointer to a second instance
		// of the class CharArrayList. It concatenates the two arrays,
		// such that the second instance of the class follows directly
		// after the first.
		void concatenate(CharArrayList * list);


		// TO DO: testing functions
		// MAKE SURE I HAVE A TEST FUNCTION FOR EVERY SINGLE FUNCTION
		// Then: MAKE SURE EVERYTHING MATCHES THE SPEC
		// Then: JFFE's
		// QUESTIONS: DO I NEED CONTRACTS FOR TESTING FUNCTIONS.

		// This getCap() function I used for testing
		// int getCap();

	private:

		// Private data members

		// Including, in order: the number of elements in the array,
		// the capacity of the array, and a pointer to an array
		// on the heap.
		int numChars;
		int capacity;
		char * data;


		// Private helper functions

		// "expand" function. Takes nothing and returns nothing.
		// Expands the capacity of the array to twice the current
		// capacity plus two. 
		void expand();

};



#endif
