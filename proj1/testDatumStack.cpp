// David Gantt
// comp15
// project 1
// February 2020
// This file is "testDatumStack.cpp". In it, I define a function to test
// each public method of the DatumStack class. There is one test fxn for
// each method. Each is called in main(), so as to test every function.

#include "DatumStack.h" 
#include <vector>
#include <iostream>

using namespace std;

// Testing Functions

// Name: All of these testing functions are named 
// after the public method they test
// Parameters: All of them, with the exception of 
// test_arrConstructor, takes a DatumStack
// object by reference.
// Returns: All return void.
// Purpose: to test the efficacy of the public member fxns in DatumStack
void test_defConstructor(DatumStack& stack);
void test_arrConstructor();
void test_isEmpty(DatumStack& stack);
void test_clear(DatumStack& stack);
void test_size(DatumStack& stack);
void test_top(DatumStack& stack);
void test_pop(DatumStack& stack);
void test_push(DatumStack& stack);

int main() {
	DatumStack stack;
	test_defConstructor(stack);
	test_arrConstructor();
	test_isEmpty(stack);
	test_clear(stack);
	test_size(stack);
	test_top(stack); // throws error
	test_pop(stack); // throws error
	test_push(stack); // throws error
	return 0;
}

void test_defConstructor(DatumStack& stack) {
	cout << "testing default constructor" << endl;
	// check if newly formed obj is empty (ie, has been created)
	if (stack.isEmpty()) {
		cout << "An empty DatumStack has been created. Success." << endl;
	} else {
		cout << "The test has failed." << endl;
	}
}

void test_arrConstructor() {
	cout << "testing paramaterized constructor" << endl;

	// init array
	Datum arrayD[2] = { Datum (5), Datum (true) };

	// construct
	DatumStack stack2(arrayD, 2);

	// test for size
	cout << "There are " << to_string(stack2.size()) << 
	"things on the stack" << endl;

}

void test_isEmpty(DatumStack& stack) {
	cout << "testing isEmpty" << endl;
	stack.clear();
	if (stack.isEmpty()) {
		cout << "The stack is empty" << endl;
	}

	// push datum on stack
	Datum d(1);
	stack.push(d);

	if (!stack.isEmpty()) {
		cout << "The stack is not empty. Test success." << endl;
	}
}

void test_clear(DatumStack& stack) {
	cout << "testing clear" << endl;
	// check size before and after clear call
	cout << "There are " << to_string(stack.size()) << 
	" things on the stack" << endl;
	stack.clear();
	cout << "There are " << to_string(stack.size()) <<
	 " things on the stack" << endl;
}

void test_size(DatumStack& stack) {
	cout << "testing size" << endl;
	stack.clear();
	cout << "There are " << to_string(stack.size()) << 
	" things on the stack" << endl;
	
	// push and check size
	Datum a(3);
	stack.push(a);
	cout << "There are " << to_string(stack.size()) <<
	 " things on the stack" << endl;

	// repeat
	Datum b(2);
	stack.push(b);
	cout << "There are " << to_string(stack.size()) << 
	" things on the stack" << endl;

	// repeat
	Datum c(1);
	stack.push(c);
	cout << "There are " << to_string(stack.size()) << 
	" things on the stack" << endl;
}

void test_top(DatumStack& stack) {
	cout << "testing top: " << endl;
	stack.clear();
	
	// first push
	Datum d(4);
	stack.push(d);
	cout << stack.top().toString() << endl;
	// second push
	Datum e(true);
	stack.push(e);
	cout << stack.top().toString() << endl;
	// third push
	Datum f("{ 4 + }");
	stack.push(f);
	cout << stack.top().toString() << endl;
	// throw the error exception. This will crash the program
	stack.clear();
	cout << stack.top().toString() << endl;
}

void test_pop(DatumStack& stack) {
	cout << "testing pop: " << endl;
	// load it up
	Datum d(4);
	stack.push(d);
	Datum e(true);
	stack.push(e);
	Datum f("{ 4 + }");
	stack.push(f);

	// pop elements while list isn't empty
	while (!stack.isEmpty()) {
		cout << stack.top().toString() << endl;
		stack.pop();
	}

	// error case
	stack.pop();
	cout << stack.top().toString() << endl; // WILL THROW ERROR

}

void test_push(DatumStack& stack) {
	cout << "testing push: " << endl;
	stack.clear();

	// first push
	Datum d(4);
	stack.push(d);
	cout << stack.top().toString() << endl;
	// second push
	Datum e(true);
	stack.push(e);
	cout << stack.top().toString() << endl;
	// third push
	Datum f("{ 4 + }");
	stack.push(f);
	cout << stack.top().toString() << endl;
}