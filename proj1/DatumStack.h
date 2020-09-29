// David Gantt
// comp15
// project 1
// February 2020
// This file is "DatumStack.h", the definition of the DatumStack class
// Here, I define all of its public member fxns, which manipulate a privately
// stored vector (stack) of Datum objects. This class will be included in my
// RPNCalc class


#ifndef DATUMSTACK_H
#define DATUMSTACK_H

#include "Datum.h"
#include <vector>

using namespace std;

class DatumStack {
	public:
		// Default constructor
		// Takes nothing and returns nothing
		// initializes an empty instance of the DatumStack class
		DatumStack();

		// Paramaterized constructor
		// takes an array of datum and its integer length and returns nothing
		// initializes an instance of the class from the array
		DatumStack(Datum * arr, int length);

		// isEmpty
		// takes nothing and returns a boolean value
		// checks if the list is empty, returns true if it is, false if not
		bool isEmpty();

		// clear
		// takes nothing and returns nothing
		// clears dStack into an empty list
		void clear();

		// size
		// takes nothing and returns an int
		// returns the size of the stack (ie num of elements)
		int size();

		// top
		// takes nothing and returns a Datum
		// retuns the Datum at the top of the stack
		// Datum top();
		Datum top();

		// pop
		// takes nothing and has a void return type
		// removes the element from the top of the list
		void pop();

		// push
		// takes a Datum and returns nothing
		// pushes the Datum on top of the stack
		void push(Datum d);


	private:
		// vector stack containing Datum
		// the highest element in the vector is the TOP of the stack
		vector <Datum> dStack;

		// size of the stack
		int numData;
};

#endif