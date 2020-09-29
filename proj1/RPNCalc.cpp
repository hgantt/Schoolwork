// David Gantt
// comp15
// project 1
// February 2020
// This file is "RPNCalc.cpp". It is the implementation for my calculator
// class. It contains definitions for all of the public and private member
// functions. In it there is one run() function which manages all of the user
// input, looping through and executing the correct private function depending
// on the given commoand. I make use of modular functions which are called in 
// run(). 

#include "RPNCalc.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

RPNCalc::RPNCalc() {
	// default constructor
}

RPNCalc::~RPNCalc() {
	// default destructor
}

void RPNCalc::run() {
	string command = " ";
	int value = 0;
	// process commands from cin separated by a space
	while (cin >> command) {
		processCommand(command, cin, value);
	}
	cout << "Thank you for using CalcYouLater." << endl;
}


void RPNCalc::runWithCommands(string manyCommands) {
	// initialize stringstream
	istringstream iss(manyCommands);
	string command;
	int value = 0;

	// take commands from iss
	while (iss >> command) {
		processCommand(command, iss, value);
	}
}

void RPNCalc::processCommand(string command, istream &input, int intValue) {
	// process a single command
	if (command == "quit") {
			cout << "Thank you for using CalcYouLater." << endl;
			exit(0);
		} else if (got_int(command, &intValue)) {
			pushInt(intValue);
		} else if (command[0] == '#' and command[1] == 't') {
			pushBool(true);
		} else if (command[0] == '#' and command[1] == 'f') {
			pushBool(false);
		} else if (command == "not" or command == "print" or 
			command == "clear" or command == "drop" or command == "dup"
			or command == "swap") {
			runEasierCommands(command);
		} else if (command == "+" or command == "-" or 
			command == "*" or command == "/" or command == "%") {
			arithmetic(command);
		} else if (command == "<" or command == ">" or command == "<="
			or command == ">=" or command == "==") {
			logicalOps(command);
		} else if (command == "{") {
			pushRString(parseRString(input));
		} else if (command == "exec" or command == "file" 
			or command == "if") {
			runHarderCommands(command);
		} else {
			cerr << command << ":  unimplemented\n";
		}
}

void RPNCalc::runEasierCommands(string command) {
	// check if command is any of these
	if (command == "not") {
		notBool();
	} else if (command == "print") {
		print();
	} else if (command == "clear") {
		clear();
	} else if (command == "drop") {
		drop();
	} else if (command == "dup") {
		dup();
	} else if (command == "swap") {
		swap();
	} else {
		return;
	}
}

void RPNCalc::runHarderCommands(string command) {
	// check if command is any of these
	if (command == "exec") {
		runExec();
	} else if (command == "file") {
		runFile();
	} else if (command == "if") {
		runIf();
	} else {
		return;
	}
}

void RPNCalc::logicalOps(string command) {
	// check if command is any of these
	if (command == "<") {
		lessThan();
	} else if (command == ">") {
		greaterThan();
	} else if (command == "<=") {
		lessOrEqual();
	} else if (command == ">=") {
		greaterOrEqual();
	} else if (command == "==") {
		equalTo();
	} else {
		return;
	}
}

void RPNCalc::arithmetic(string command) {
	// check if command is any of these
	if (command == "+") {
		add();
	} else if (command == "-") {
		subtract();
	} else if (command == "*") {
		multiply();
	} else if (command == "/") {
		divide();
	} else if (command == "mod") {
		modulo();
	} else {
		return;
	}
}

void RPNCalc::pushInt(int i) {
	// make and push a datum integer
	Datum d(i);
	stack.push(d);
}

void RPNCalc::pushBool(bool b) {
	// make and push a datum bool
	if (b == true) {
		Datum d(true);
		stack.push(d);
	} else if (b == false) {
		Datum d(false);
		stack.push(d);
	}
}

void RPNCalc::pushRString(string command) {
	// make and push a datum RString
	Datum d(command);
	stack.push(d);
}

void RPNCalc::notBool() {
	// drop and re-push opposite
	try {
		bool b = stack.top().getBool();
		drop();
		pushBool(not b);
	} catch (exception &e) {
		cerr << "Error: " << e.what() << endl;
	}
}

void RPNCalc::print() {
	// print top of stack
	try {
		cout << stack.top().toString() << endl;
	} catch (runtime_error) {
		cerr << "Error: empty_stack\n";
	}
}

void RPNCalc::clear() {
	// use built-in fxn
	stack.clear();
}

void RPNCalc::drop() {
	// use built-in fxn
	try {
		stack.pop();
	} catch (runtime_error) {
		cerr << "Error: empty_stack\n";
	}
}

void RPNCalc::dup() {
	// push whatever is on top
	try {
		Datum d(stack.top());
		stack.push(d);
	} catch (runtime_error) {
		cerr << "Error: empty_stack\n";
	}
}

void RPNCalc::swap() {
	// store and pop both top, push in opposite order
	try {
		Datum ogTop(stack.top());
		stack.pop();
		Datum ogBottom(stack.top());
		stack.pop();
		stack.push(ogTop);
		stack.push(ogBottom);
	} catch (runtime_error) {
		cerr << "Error: empty_stack\n";
	}
}

void RPNCalc::add() {
	// store and drop top two elements, push sum
	try {
		Datum a = stack.top();
		drop();
		Datum b = stack.top();
		drop();
		pushInt(a.getInt() + b.getInt());
	} catch (exception &e) {
		cerr << "Error: " << e.what() << endl;
	}
}

void RPNCalc::subtract() {
	// store and drop top two elements, push difference
	try {
		Datum a = stack.top();
		drop();
		Datum b = stack.top();
		drop();
		pushInt(b.getInt() - a.getInt());
	} catch (exception &e) {
		cerr << "Error: " << e.what() << endl;
	}
}

void RPNCalc::multiply() {
	// store and drop top two elements, push product
	try {
		Datum a = stack.top();
		drop();
		Datum b = stack.top();
		drop();
		pushInt(a.getInt() * b.getInt());
	} catch (exception &e) {
		cerr << "Error: " << e.what() << endl;
	}
}

void RPNCalc::divide() {
	// store and drop top two elements, push quotient
	try {
		Datum a = stack.top();
		drop();
		Datum b = stack.top();
		drop();
		pushInt(b.getInt() / a.getInt());
	} catch (exception &e) {
		cerr << "Error: " << e.what() << endl;
	}
}

void RPNCalc::modulo() {
	// store and drop top two elements, push remainder
	try {
		Datum a = stack.top();
		drop();
		Datum b = stack.top();
		drop();
		pushInt(b.getInt() % a.getInt());
	} catch (exception &e) {
		cerr << "Error: " << e.what() << endl;
	}
}

void RPNCalc::lessThan() {
	// push boolean value of less-than operator
	try {
		Datum a = stack.top();
		drop();
		Datum b = stack.top();
		drop();
		// check condition
		if (b < a) {
			pushBool(true);
		} else {
			pushBool(false);
		}
	} catch (exception &e) {
		cerr << "Error: " << e.what() << endl;
	}
}

void RPNCalc::greaterThan() {
	// push boolean value of greater-than operator
	try {
		Datum a = stack.top();
		drop();
		Datum b = stack.top();
		drop();
		// check condition
		if ((not (b < a)) and (not (b == a))) {
			pushBool(true);
		} else {
			pushBool(false);
		}
	} catch (exception &e) {
		cerr << "Error: " << e.what() << endl;
	}
}

void RPNCalc::lessOrEqual() {
	// push boolean value of less-or-equal operator
	try {
		Datum a = stack.top();
		drop();
		Datum b = stack.top();
		drop();
	// check condition
		if (b < a or b == a) {
			pushBool(true);
		} else {
			pushBool(false);
		}
	} catch (exception &e) {
		cerr << "Error: " << e.what() << endl;
	}
}

void RPNCalc::greaterOrEqual() {
	// push boolean value of greater-or-equal operator
	try {
		Datum a = stack.top();
		drop();
		Datum b = stack.top();
		drop();
	// check condition
		if (not (b < a)) {
			pushBool(true);
		} else {
			pushBool(false);
		}
	} catch (exception &e) {
		cerr << "Error: " << e.what() << endl;
	}
}

void RPNCalc::equalTo() {
	// push boolean value of equal-to operator
	try {
		Datum a = stack.top();
		drop();
		Datum b = stack.top();
		drop();

	 	if (b == a) {
	 		pushBool(true);
	 	} else {
	 		pushBool(false);
	 	}
	
	} catch (exception &e) {
		cerr << "Error: " << e.what() << endl;
	}
}

string RPNCalc::parseRString(istream& input) {
	// initialize string to return
	string parsed = "{";
	// when braces is 0 (ie, when its closed), break out
	int braces = 1;
	string c;
	while (braces != 0) {
		input >> c;
		// increment or decrement if finds string
		if (c == "{") {
			braces++;
		} else if (c == "}") {
			braces--;
		}
		// append string to return
		parsed = parsed + " " + c;
	}
		// return value
		return parsed;
}


void RPNCalc::file(string fileName) {
		// open file passed in by rstring
	ifstream inFile;
	inFile.open(fileName);
	if (not inFile.is_open()) {
		cerr << "Unable to read " << fileName << endl;
		return;
	}
	// runWithCommands takes a string, but i just have an open file
	string commandLine;
	while (!inFile.eof()) {
		getline(inFile, commandLine);
		runWithCommands(commandLine);
	}
	inFile.close();
}


string RPNCalc::noBrackets(string rString) {
	// init string to return
	string newString;
	// pop back curly and the space
	rString.pop_back();
	rString.pop_back();
	// pop front curly and the space
	rString.erase(rString.begin());
	rString.erase(rString.begin());
	newString = rString;
	return newString; 
}

void RPNCalc::runIf() {
	Datum doFalse = stack.top();
	stack.pop();
	Datum doTrue = stack.top();
	stack.pop();
	Datum condition = stack.top();
	stack.pop();
	// condition error
	if (not condition.isBool()) {
		cerr << "Error: expected boolean in if test\n";
		return;
	}
	// true case
	if (not doTrue.isRString()) {
		cerr << "Error: expected rstring in if branch\n";
		return;
	}
	// false case
	if (not doFalse.isRString()) {
		cerr << "Error: expected rstring in if branch\n";
		return;
	}
	// execute conditional
	if (condition.getBool()) {
		runWithCommands(noBrackets(doTrue.getRString()));
	} else {
		runWithCommands(noBrackets(doFalse.getRString()));
	}
}

bool RPNCalc::got_int(string s, int *resultp)
{
        return sscanf(s.c_str(), "%d", resultp) == 1;
}

void RPNCalc::runExec() {
	// runs the exec command
	try {
		Datum d = stack.top();
		// check if s is an rString
		if (not d.isRString()) {
			throw runtime_error("cannot execute non rstring");
		}
		stack.pop();
		string rString = noBrackets(d.toString());
		runWithCommands(rString);
	} catch (exception &e) {
			cerr << "Error: " << e.what() << endl;
		}
}

void RPNCalc::runFile() {
	// runs the file command
	try {
		Datum d = stack.top();
		if (not d.isRString()) {
			throw runtime_error("file operand not rstring");
		}
		string s = stack.top().toString();
		stack.pop();
		string fileName = noBrackets(s);
		file(fileName);
	} catch (exception &e) {
		cerr << "Error: " << e.what() << endl;
	}
}