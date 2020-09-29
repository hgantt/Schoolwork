// David Gantt
// comp15
// project 1
// February 2020
// this file is main.cpp. it is very simple, and does only the following:
// initialize an object of the calculator class, and call its run function
// As such, the only necessary inclde is the header file of the RPNCalc
// class. When main is compiled, it links all of the included files in 
// RPNcalc class. I piped a .cylc file into this program to test it.

#include "RPNCalc.h"

int main() {

	RPNCalc calc; 
	calc.run();
	return 0;
}