// David Gantt
// comp15
// project 1
// February 2020
// This file is "RPNCalc.h". This is the header file for th eRPNCalc class
// in it all fo the functions for the class are declared, both public and
// private. All of the private functions are called in the RUN funciton,
// which takes commands and loops through user input. In main, I can simply
// call obj.run() to use the calculator. This is in an effort to make it very
// modular.

#ifndef RPNCALC_H
#define RPNCALC_H

#include "DatumStack.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>
#include <istream>

using namespace std;

class RPNCalc {

	public: 
	// PUBLIC METHODS

	// default constructor
	// takes nothing and returns nothing
	// initializes empty instance of the RPNCalc class
	RPNCalc();

	// destructor
	// takes nothing and returns nothing
	// frees up all memory associated with RPNCalc
	~RPNCalc();

	// rum
	// takes nothing and returns nothing
	// takes and processes commands from cin
	void run();

	private:

	// DATA MEMBERS
	// the one, glorious stack for our calculator
	DatumStack stack;

	// PRIVATE METHODS
	// gotInt
	// takes a string and an integer pointer and returns a bool
	// returns true if the string is an integer
	bool got_int(string s, int *resultp);

	// pushInt
	// takes an integer and returns void
	// pushes an integer onto the stack
	void pushInt(int i);

	// pushBool
	// takes a boolean value and returns void
	// pushes a bool onto the stack
	void pushBool(bool b);

	// notBool
	// takes nothing and returns nothing
	// pops the top element stack, a bool, and pushes its opposite
	void notBool();

	// print
	// takes nothing and returns nothing
	// prints the top of the stack
	void print();

	// clear
	// takes nothing and returns nothing
	// clears the stack
	void clear();

	// drop
	// takes nothing and returns nothing
	// pop top element off
	void drop();

	// dup
	// takes nothing and returns nothing
	// duplicates top element on stack
	void dup();

	// swap
	// takes nothing and returns nothing
	// swaps top two elements on stack
	void swap();

	// exec
	// takes nothing and returns nothing
	// pops an r string and executes its contents
	void exec();

	// add
	// takes nothing and returns nothing
	// adds top two elements on stack
	void add();

	// subtract
	// takes nothing and returns nothing
	// subtracts two elements on stack
	void subtract();

	// multiply
	// takes nothing and returns nothing
	// multiplies two elements on stack
	void multiply();

	// divide
	// takes nothing and returns nothing
	// divides two elements on stack
	void divide();

	// modulo
	// takes nothing and returns nothing
	// finds remainder of top two elts
	void modulo();

	// lessThan
	// takes nothing and returns nothing
	// checks the lessThan condition on top two elements
	void lessThan();

	// greaterThan
	// takes nothing and returns nothing
	// checks the greaterThan condition on top two elements
	void greaterThan();

	// lessOrEqual
	// takes nothing and returns nothing
	// checks the less or equal condition on top two elements
	void lessOrEqual();

	// greaterOrEqual
	// takes nothing and returns nothing
	// checks the greaterOrEqual condition on top two elements
	void greaterOrEqual();

	// equalTo
	// takes nothing and returns nothing
	// checks the equal-to condition on top two elements
	void equalTo();

	// parseRString
	// takes a reference to an istream and returns a string
	// reads from the input until all braces are matched,
	// and returns the string value of the RString
	string parseRString(istream& input);

	// pushRString
	// takes an RString (c++ string) and returns void
	// pushes an RString onto the stack
	void pushRString(string command);

	// file
	// takes a string fileName and returns void
	// opens the file and reads its contents into the calcyoulater
	void file(string fileName);

	// runWithCommands
	// takes a string of commands and returns void
	// runs the calcyoulater with a bunch of commands
	void runWithCommands(string manyCommands);

	// noBrackets
	// takes a string and return a string
	// removes the brackets from an rstring
	string noBrackets(string rString);

	// runIf
	// takes and returns nothing
	// executes the "if" command
	void runIf();

	// runExec
	// takes and returns nothing
	// executes the "exec command"
	void runExec();

	// runFile
	// takes and returns nothing
	// executes the "file" command
	void runFile();

	// arithmetic
	// takes a string and returns nothing
	// executes the +, -, *, /, and mod commands
	void arithmetic(string command);

	// logicalOps
	// takes a string and returns nothing
	// executes the >, <, <=, >=, ==
	void logicalOps(string command);

	// runEasierCommands
	// takes a string and returns nothing
	// executes the not, print, clear, drop, dup, swap commands
	void runEasierCommands(string command);

	// runHarderCommands
	// takes a string and returns nothing
	// executes the file, exec, and if commands
	void runHarderCommands(string command);

	// processCommand
	// takes a string, an instream by reference, and an int
	// processes a SINGLE command
	void processCommand(string command, istream &input, int intValue);
};

#endif