// David Gantt
// comp15
// project 1
// February 2020
// testRPNCalc.cpp. To test the RPNCalc class, I have a file of commands
// by the name testRPNCalc.cyl. PLEASE SEE README

// NOTE: I PROVIDED ALL OF MY .CYL FILES WHICH I USED FOR UNIT TESTING
// I DID NOT MAKE TESTING FUNCTIONS, BUT PIPED THE "testRPNCalc.cyl" 
// INTO BOTH THE REF IMPLEMENTATION AND MY IMPLEMENTATION AND DIFF TESTED.
// SEE THE README FOR DETAILS ON MY TESTING METHODS


#include "RPNCalc.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	RPNCalc calc;
	calc.run();
	return 0;
}

