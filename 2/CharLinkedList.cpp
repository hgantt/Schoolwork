// David Gantt
// comp15, hw2
// implementation of the CharLinkedList class


#include <iostream>
#include "CharLinkedList.h"

using namespace std;


CharLinkedList::CharLinkedList() {
	// create empty instance
	front = nullptr;
	numNodes = 0;
}

CharLinkedList::CharLinkedList(char c) {
	// creates instance of class with given char
	numNodes = 1;
	front = new Node;
	front->data = c;
	front->next = nullptr;
	front->previous = nullptr;
}

CharLinkedList::CharLinkedList(char carray[], int length) {
	// create instnace of class
	front = nullptr;
	numNodes = 0;
	int i = 0;
	// copy array chars
	while (i < length) {
		insertAt(carray[i], i);
		i++;
	}
}

CharLinkedList::CharLinkedList(CharLinkedList& list) {
	// initialize
	front = nullptr;
	numNodes = 0;
	// deep copy
	for (int i = 0; i < list.size(); i++) {
		insertAt(list.elementAt(i), i);
	}
}

// Thank you Mark Sheldon for the template code
CharLinkedList& CharLinkedList::operator= (CharLinkedList& rhs) {
	if (this != &rhs) {
		//recycle data
		clear();

		// deep copy
		for (int i = 0; i < rhs.size(); i++) {
			insertAt(rhs.elementAt(i), i);
		}
	}
	return *this;
}

CharLinkedList::~CharLinkedList() {
	// reycle data
	clear();
}


int CharLinkedList::size() {
	return numNodes;
}


bool CharLinkedList::isEmpty() {
	// check if list is empty
	if (front == nullptr and numNodes == 0) {
		return true;
	// if not, list must have at least one item
	} else {
		return false;
	}
}



// To Fix
void CharLinkedList::print() {

	Node * temp = front;

	cout << "CharLinkedList of size " << size() << " <<";

	// loop through, printing character by character
	while (temp != nullptr) {
		cout << temp->data;
		temp = temp->next;
	}

	cout << ">" << ">]" << endl;

}

char CharLinkedList::first() {
	// error message
	string error = "cannot get first of empty doubly-linked list";
	// check for error. if none, return first char
	if (isEmpty() == true) {
		throw runtime_error(error);
	} else {
		return front -> data;
	}
}

char CharLinkedList::last() {
	// error message
	string error = "cannot get last of empty doubly-linked list";
	// check for error. if none, return last char
	Node * temp = front;
	if (isEmpty()) {
		throw runtime_error(error);
	} else {
		while (temp-> next != nullptr) { // is this temp or temp -> next;
			temp = temp -> next;
		}
		return temp->data;
	}
}

void CharLinkedList::pushAtFront(char c) {
	// inserting into an empty list at pos 0
	if (front == nullptr) {
		Node * newNode = new Node;
		newNode -> data = c;
		newNode -> next = nullptr;
		newNode -> previous = nullptr;
		front = newNode;
		numNodes++;
	}
	// inserting into a nonempty list at pos 0
	else if (front != nullptr) {
		Node * newNode = new Node;
		newNode -> data = c;
		newNode -> next = front;
		newNode -> previous = nullptr;
		front = newNode;
		newNode = nullptr; 
		numNodes++;
	}
}

void CharLinkedList::pushAtBack(char c) {
	Node * temp = front;
	// inserting into "back" of an empty list
	if (front == nullptr and numNodes == 0) {
		pushAtFront(c); // pushAtFront and pushAtBack empty list are the same
	}

	else if (front != nullptr and numNodes > 0) {
		while (temp->next != nullptr){
			temp = temp -> next;
		}

		// manipulating pointers
		Node * newNode = new Node;
		newNode -> data = c;
		newNode -> next = nullptr;
		newNode -> previous = temp;
		temp -> next = newNode;
		temp = nullptr;
		newNode = nullptr;
		numNodes++;
	}
	
}

void CharLinkedList::insertAt(char c, int index) {
	// concatenate error string
	string error = "index (" + to_string(index) + ") not in range [0.." +
		to_string(numNodes) + "]";
	// check if error needs to be thrown	
	if (index < 0 or index > numNodes) {
		throw range_error(error);
	}
	// insert at 0 in empty or nonempty list
	if (index == 0) {
		pushAtFront(c);
	}
	// insert at back of empty or non-empty list
	else if (index == numNodes) {
		pushAtBack(c);
	}
	// insert at middle of non-empty list
	else {
		Node * temp = front;
		int counter = 0;
		while (counter < index) {
			temp = temp->next;
			counter++;
		}
		Node * newNode = new Node;
		newNode -> data = c;
		Node * storeNext = temp;
		temp = newNode;
		newNode -> previous = storeNext->previous;
		newNode -> next = storeNext;
		storeNext -> previous = newNode;
		temp = temp -> previous;
		temp -> next = newNode;
		numNodes++;
		newNode = nullptr;
		storeNext = nullptr;
	}
	
}


void CharLinkedList::clear() {
	// clearing an empty list
	Node * temp = front;

	if (front == nullptr and numNodes == 0) {
		return;
	}
	// clearing a non empty list
	else if (front != nullptr and numNodes > 0) {
		
		while (temp != nullptr) {
			temp = front -> next;
			front -> previous = nullptr;
			front -> next = nullptr;
			front -> data = '\0'; 
			delete front;
			front = temp;
			numNodes--;
			
		}
	}
}

char CharLinkedList::elementAt(int index) {
	// concatenate error message and check for throw
	string error = "index (" + to_string(index) + ") not in range [0.." +
		to_string(numNodes) + ")";
	if (index < 0 or index >= numNodes) {
		throw range_error(error);
	}
	// iterate and return the element
	else {
		Node * temp = front;
		int count = 0;
		// non empty list case
		while (count < index) {
			count++;
			temp = temp -> next;
		}
		return temp->data;
	}
}

bool CharLinkedList::find(char c) {
	Node * temp = front;
	return findHelper(temp, c);
}

void CharLinkedList::replaceAt(char c, int index) {
	// error message
	string error = "index (" + to_string(index) + ") not in range [0.." +
		to_string(numNodes) + ")";
	if (index >= numNodes or index < 0) {
		throw range_error(error);
	}

	Node * temp = front;
	int count = 0;

	// iterate
	while (temp != nullptr and count < index) {
		temp = temp -> next;
		count++;
	}

	// replace
	temp -> data = c;

}


void CharLinkedList::popFromFront() {
	// error message
	string error = "cannot pop from empty doubly-linked list";
	if (isEmpty()) {
		throw runtime_error(error);
	}

	Node * temp = front;

	// one node case
	if (numNodes == 1) {
		front = nullptr;
		delete temp;
		numNodes--;
	} else {


	// greater than one element
	temp = temp->next;
	temp -> previous = nullptr;
	front -> next = nullptr;
	delete front;
	front = temp;
	numNodes--;
	}

}

void CharLinkedList::popFromBack() {
	// error
	string error = "cannot pop from empty doubly-linked list";
	if (isEmpty()) {
		throw runtime_error(error);
	}

	Node * temp = front;

	// one node case
	if (numNodes == 1) {
		popFromFront();

	} else {
	// with more than one element
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		if (numNodes == 1) {
			front = nullptr;
		}
		temp = temp->previous;
		delete temp -> next;
		temp -> next = nullptr; 
		numNodes--;
		temp = nullptr;

	}

}

void CharLinkedList::removeAt(int index) {
	// concatenate error message and check for throw
	string error = "index (" + to_string(index) + ") not in range [0.." +
		to_string(numNodes) + ")";
	if (index < 0 or index >= numNodes) {
		throw range_error(error);
	}

	// pop from front of list
	if (index == 0) {
		popFromFront();
	// pop from back of list
	} else if (index == (numNodes-1)) {
		popFromBack();
	// remove from middle of list
	} else {
		// we need two pointers!
		Node * temp = front;
		Node * afterRemove = front;
		int count = 0;

		while (count < (index + 1)) {
			afterRemove = afterRemove -> next;
			count++;
		}
		count = 0;

		while (count < (index-1)) {
			temp = temp->next;
			count++;
		}
		// remove and update pointers
		delete afterRemove->previous;
		temp->next = afterRemove;
		afterRemove->previous = temp;
		afterRemove = nullptr;
		temp = nullptr;
		numNodes--;
	}
}

void CharLinkedList::insertInOrder(char c) {
	Node * temp = front;
	// iterate and check for alphabetical order
	for (int i = 0; i < numNodes; i++) {
		if (c <= temp->data) {
			insertAt(c, i);
			return;
		} else {
			temp = temp->next;
		}
	}
	// insert
	insertAt(c, numNodes);
}

void CharLinkedList::concatenate(CharLinkedList * listTwo) {
	// iterate second list and add to back of first
	int numNodesTwo = listTwo->size();
	for (int i = 0; i < numNodesTwo; i++) {
		pushAtBack(listTwo->elementAt(i));
	}

}

void CharLinkedList::shrink() {
	return;
}
