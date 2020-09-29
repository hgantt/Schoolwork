// David Gantt
// comp15
// project 1
// February 2020
// This file is "DatumStack.cpp". This is the implementation of my DatumStack
// class. I implement all of the public methods defined in DatumStack.h.
// Below is commented code describing what each function does. This code is
// tested in another file, testDatumStack.cpp. Below are many functions 
// common to a stack class, like isEmpty, pop, top, etc.


#include "DatumStack.h"
#include <vector>
#include <iostream>

using namespace std;

DatumStack::DatumStack() {
	// init data members
	numData = 0;
}

DatumStack::DatumStack(Datum * arr, int length) {
	// iterate through array, push on stack
	for (int i = 0; i < length; i++) {
		push(arr[i]);
	}
	numData = length;
}

bool DatumStack::isEmpty() {
	// simple if else statement to check size
	if (numData == 0) {
		return true;
	} else {
		return false;
	}
}

void DatumStack::clear() {
	// use built in, update
	dStack.clear();
	numData = 0;
}

int DatumStack::size() {
	return numData;
}

Datum DatumStack::top() {
	if (isEmpty()) {
		throw runtime_error("empty_stack");
	} else {
		return dStack.back();
	}
	// in RPNCalc, you will try to pop and then catch the runtime error
}

void DatumStack::pop() {
	// throw error or pop
	if (isEmpty()) {
		throw runtime_error("empty_stack");
	} else {
		dStack.pop_back();
		numData--;
	}
}

void DatumStack::push(Datum d) {
	// use built in fxn, then increment data
	dStack.push_back(d);
	numData++;
}