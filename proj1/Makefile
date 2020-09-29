###
### Makefile for CalcYouLater Project
### CalcYouLater is an RPN calculator
###
### Author: DAVID GANTT
## there are three executables: CalcYouLater (for the RPNCalc),
## testDatumStack, and testRPNCalc. the client may make any of
## these programs. Note, again, that the testRPNCalc was not used
## for testing

##
## Here is a rule for compiling .cyl files for use in your testing
##

%.cylc:  %.cyl
	./cylc $^

CXX = clang++
CXXFLAGS = -g3  -std=c++11 -Wall -Wextra  -Wpedantic -Wshadow
LDFLAGS = -g3


INCLUDES = $(shell echo *.h)
EXECS = CalcYouLater

CalcYouLater: RPNCalc.o Datum.o DatumStack.o main.o
	${CXX} ${LDFLAGS} $^ -o $@


testRPNCalc: testRPNCalc.o RPNCalc.o DatumStack.o Datum.o
	${CXX} ${LDFLAGS} $^ -o $@

testDatumStack: testDatumStack.o DatumStack.o Datum.o
	${CXX} ${LDFLAGS} $^ -o $@


main.o: main.cpp
RPNCalc.o: RPNCalc.cpp RPNCalc.h
DatumStack.o: DatumStack.h DatumStack.cpp
testRPNCalc.o: testRPNCalc.cpp RPNCalc.cpp
testDatumStack.o: testDatumStack.cpp DatumStack.cpp Datum.o




.PHONY: clean
clean:
	rm -f ${EXECS} *.o *.dSYM./


