# David Gantt
# Comp15 HW4
# March 8 2020
# Makefile for Binary Search Tree
# This file was provided.

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11 


hw4: hw4.o BinarySearchTree.o
	${CXX} -o $@ $^

%.o: %.cpp $(shell echo *.h)
	${CXX} ${CXXFLAGS} -c $<

clean:
	rm -rf hw4 *.o *.dSYM

provide:
	provide comp15 hw4 hw4.cpp BinarySearchTree.cpp BinarySearchTree.h \
	        README Makefile testingBST.cpp myCout.txt refCout.txt

