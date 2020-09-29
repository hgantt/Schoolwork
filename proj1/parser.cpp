// David Gantt
// comp15
// project 1
// February 2020
// This file is parser.cpp. It contains the declaration and definition
// and testing of a parseRString function which parses RStrings. See
// function contract below. It is defined then tested in main().

#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// parseRString
// takes an input stream passed by reference and returns a string
// parses an RString and returns it as a standard c++ string. It is called
// after the input stream reads in a '{'.
string parseRString(istream &input);


int main() {

	// test parseRString
	ifstream inFile;
	inFile.open("text.txt");

	cout << parseRString(inFile) << endl;

	return 0;
}


string parseRString(istream &input) {
	// initialize string to return
	string parsed = "{";

	// when braces is 0 (ie, when its closed), break out
	int braces = 1;

	char c;

	while (input.get(c)) {

		// increment or decrement if finds string
		if (c == '{') {
			braces++;
		} else if (c == '}') {
			braces--;
		}

		// append string to return
		parsed = parsed + c;

		// break if rstring is closed
		if (braces == 0) {
			break;
		}
	}
		// return value
		return parsed;
}