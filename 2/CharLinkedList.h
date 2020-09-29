// David Gantt
// Comp15, hw2, header file
// defines the CharLinkedList class,
// including all of its public and private member functions and data members
// February 5th, 2020


#ifndef CHARLINKEDLIST_H
#define CHARLINKEDLIST_H

#include <iostream>

class CharLinkedList {
	
	public:
		// Name: Default or nullary constructor. 
		// Returns and Paramaters: Takes nothing and returns nothing.
		// Purpose: Initializes an empty instance of the list.
		CharLinkedList();

		// Name: Paramaterized constructor. 
		// returns and Paramaters: Takes a char. Returns nothing. 
		// Purpose: Initializes an instance of the class with one node.
		CharLinkedList(char c);

		// Name: Paramaterized constructor. 
		// Takes an array of chars and the arrays length as an integer.
		// Purpose: Initializes an instance of the class with length nodes
		CharLinkedList(char carray[], int length);

		// Name: assignment operator. 
		// returns and paramaters: Takes a pointer to another
		// instance of the class. 
		// Purpose: Creates a deep copy of the
		// right hand side into the left hand side of the "=" symbol
		CharLinkedList& operator=(CharLinkedList& rhs);

		// Name: copy constructor. 
		// returns and paramaters: takes a pointer to another instance of
		// the class. 
		// purpose: initializes a new instance of the class exactly
		// like the other.
		CharLinkedList(CharLinkedList& list);

		// name: destructor. 
		// purpose: recycles all data. 
		// paramaters: takes nothing and returns nothing
		~CharLinkedList();

		// name: print. 
		// paramaters and returns: takes nothing and returns nothing. 
		// purpose: prints the linked list
		void print(); 

		// name: size function. 
		// returns: takes nothing and returns an int
		// purpose: returns the size of the linked list
		int size();

		// name: isEmpty function. 
		// param/returns: takes nothing and returns a bool value.
		// purpose: returns true if the function is empty, false if not
		bool isEmpty(); 

		// name: pushAtFront function. 
		// param/returns: takes a char and returns nothing.
		// purpose: creates a node with the given char at the front of the 
		// list
		void pushAtFront(char c); 

		// name: pushAtBack function. 
		// paramaters/returns: takes a char and returns nothing
		// purpose: creates a node with the given char at the back of the list
		void pushAtBack(char c);

		// name: insertAt. 
		// param/returns: takes a char and an index and returns nothing.
		// purpose: inserts the a new node with the given char at the given
		// index
		void insertAt(char c, int index);

		// name: first. 
		// param/returns: takes nothing and returns the 
		// first char in the linked list
		// purpose: return the first char in the linked list
		char first();


		// name: last. 
		// param/returns: takes nothing and returns the 
		// last char in the linked list
		// purpose: return the last char in the linked list
		char last(); 

		// name: shrink. 
		// param/returns: takes nothing and returns nothing. 
		// purpose: guarantees the linked list is not using excess memory
		void shrink();

		// name: clear function. 
		// param/returns: takes nothing and returns nothing. 
		// purpose: clears the list and recycles memory
		void clear(); 

		// name: elementAt function. 
		// param/returns: takes an index and returns the char at that 
		// index
		// purpose: listed above in the return section
		char elementAt(int index);

		// name: find function. 
		// param/return: takes a char and returns a bool value. 
		// purpose: return  true if the given char is
		// in the list, false if not
		bool find(char c); 

		// name: replaceAt function. 
		// param/returns: takes a char and an index, no return
		// purpose: replaces the data at that index w the given char
		void replaceAt(char c, int index);

		// insertInOrder function. 
		// takes a char and returns nothing.
		// inserts the given char in alphabetical order
		void insertInOrder(char c);

		// popFromFront function. 
		// takes nothing and returns nothing.
		// removes the first node
		void popFromFront(); 

		// popFromBack function.
		// takes nothing and returns nothing.
		// removes the back node
		void popFromBack();

		// removeAt function. 
		// takes an integer index and returns nothing
		// removes the node at that index
		void removeAt(int index);
		
		// concatenate function. 
		// takes a CharLinkedList pointer and returns void
		// concatenates the two lists.
		void concatenate(CharLinkedList * listTwo);

	private:
		// Data Members
		struct Node {
			char data;
			Node * next;
			Node * previous;
		};

		Node * front;
		int numNodes;

		// Private Functions

		// findHelper
		// takes a pointer to a node and returns a bool value true or false
		// called in public function find, uses recursion
		bool findHelper(Node * nptr, char c) {
			while (nptr != nullptr) { 
				if (nptr -> data == c) {
					return true;
				} else {
					return findHelper(nptr->next, c);
				}
			} return false;

		}
};

#endif