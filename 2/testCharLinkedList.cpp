// David Gantt
// comp15, hw2
// testing file for the CharLinkedList class

#include "CharLinkedList.h"
#include <iostream>

using namespace std;

// ONE LARGE FUNCTION CONTRACT
// Testing Functions. 
// NAMES: named after the functions they test
// RETURNS: VOID
// PARAMATERS: A POINTER TO A CLASS OBJ (OR TWO), RARELY A CHAR
// PURPOSE: tests edge cases and normal cases for every funciton.
// NB: all constructors are either called in main or within the
// testing functions, so they do not have explicit tests themselves
void test_print(CharLinkedList& list);
void test_size(CharLinkedList& list); 
void test_isEmpty(CharLinkedList& list); 
void test_first(CharLinkedList& list);  
void test_last(CharLinkedList& list); 
void test_pushAtFront(CharLinkedList& list); 
void test_pushAtBack(CharLinkedList& list); 
void test_clear(CharLinkedList& list); 
void test_elementAt(CharLinkedList& list); 
void test_find(CharLinkedList& list, char c);
void test_replaceAt(CharLinkedList& list); 
void test_popFromFront(CharLinkedList& list); 
void test_popFromBack(CharLinkedList& list); 
void test_insertAt(CharLinkedList& list);
void test_removeAt(CharLinkedList& list);
void test_insertInOrder(CharLinkedList& list);
void test_concatenate(CharLinkedList& list, CharLinkedList& listTwo);
void test_copyConstructor(CharLinkedList& list);
void test_arrayConstructor();
void test_assignOperator(CharLinkedList& list);
void test_shrink(CharLinkedList& list);


// COMMENTED OUT CODE: ALL COMMENTED OUT CODE THROWS AN ERROR
// UNCOMMENT THIS CODE TO RUN ONE TEST AT A TIME. THERE IS NO
// OTHER COMMENTED OUT CODE. THIS WAS DONE INTENTIONALLY
int main()
{
	CharLinkedList list;
	test_print(list); 
	test_size(list); 
	test_isEmpty(list); 
	// test_first(list); 
	// test_last(list); 
	test_pushAtFront(list); 
	test_pushAtBack(list); 
	test_clear(list); 
	// test_elementAt(list); 
	test_find(list, 'c'); 
	// test_replaceAt(list); 
	// test_popFromFront(list); 
	// test_popFromBack(list);
	// test_insertAt(list);
	// test_removeAt(list);
	test_insertInOrder(list);
	CharLinkedList listTwo;
	test_concatenate(list, listTwo);
	test_copyConstructor(list);
	test_arrayConstructor();
	test_assignOperator(list);
	test_shrink(list);
}

void test_print(CharLinkedList& list) {
	cout << "print test: " << endl;
	// print empty list
	list.clear();
	list.print();
	// print nonempty list
	list.pushAtBack('a');
	list.print();
}

void test_size(CharLinkedList& list) {
	cout << "size test: " << endl;
	// size of empty list
	list.clear();
	cout << list.size() << endl;
	// size of nonempty list
	list.pushAtFront('a');
	cout << list.size() << endl;
}

void test_isEmpty(CharLinkedList& list) {
	cout << "isEmpty test: " << endl;
	
	// test non-empty case
	list.pushAtFront('a');
	if (list.isEmpty() == true) {
		cout << "The list is empty." << endl;
	}
	else {
		cout << "The list is not empty." << endl;
	}

	// test empty case
	list.clear();
	if (list.isEmpty() == true) {
		cout << "The list is empty." << endl;
	}
	else {
		cout << "The list is not empty." << endl;
	}
}

void test_first(CharLinkedList& list) {
	cout << "first test: " << endl;
	// 1 element test
	list.pushAtFront('a');
	cout << list.first() << endl;
	// >1 element test
	list.pushAtBack('b');
	cout << list.first() << endl;
	// empty test
	list.clear();
	cout << list.first() << endl;

}

void test_last(CharLinkedList& list) {
	cout << "last test: " << endl;
	// 1 element test
	list.pushAtBack('a');
	cout << list.last() << endl;
	// >1 element test
	list.pushAtFront('b');
	cout << list.last() << endl;
	// empty test
	list.clear();
	cout << list.last() << endl;
}

void test_pushAtFront(CharLinkedList& list) {
	cout << "pushAtFront test: " << endl;
	// pushAtFront in empty list
	list.clear();
	list.pushAtFront('a');
	list.print();
	// pushAtFront in nonempty list
	list.pushAtFront('b');
	list.print();
}

void test_pushAtBack(CharLinkedList& list) {
	cout << "pushAtBack test: " << endl;
	// pushAtBack in empty list
	list.clear();
	list.pushAtBack('a');
	list.print();
	// pushAtBack in nonempty list
	list.pushAtBack('b');
	list.print();
	list.pushAtBack('c');
	list.print();
}

void test_clear(CharLinkedList& list) {
	cout << "clear test: " << endl;
	// test empty list
	list.clear();
	if (list.isEmpty()) {
		cout << "the list is empty. clear worked on the empty list." << endl;
	}
	else if (not list.isEmpty()) {
		cout << "the list is not empty. clear did not work" 
		<< " on the empty list" << endl;
	}
	// test 1 element list
	list.pushAtFront('a');
	list.clear();
	if (list.isEmpty()) {
		cout << "the list is empty. clear worked on the 1 element list." << endl;
	}
	else if (not list.isEmpty()) {
		cout << "the list is not empty. clear did not work" 
		<< " on the empty list" << endl;
	}
	// test >1 element list
	list.pushAtBack('b');
	list.clear();
	if (list.isEmpty()) {
		cout << "the list is empty. clear worked on the many element list." << endl;
	}
	else if (not list.isEmpty()) {
		cout << "the list is not empty. clear did not work" 
		<< " on the empty list" << endl;
	}
}


void test_elementAt(CharLinkedList& list) {
	cout << "elementAt test: " << endl;
	// iterative loop, print every element
	for (int i = 0; i < list.size(); i++) {
		cout << "The " << i << "th element is: " << list.elementAt(i) << endl;
	}
	// in empty list
	list.clear();
	cout << list.elementAt(0) << endl;
}

void test_find(CharLinkedList& list, char c) {
	// in empty list
	cout << "find test: " << endl;
	list.clear();
	if (list.find(c)) {
		cout << "the char is in the list" << endl;
	} else {
		cout << "the char is not in the list" << endl;
	}
	// non empty test
	list.pushAtBack(c);
	if (list.find(c)) {
		cout << "the char is in the list" << endl;
	} else {
		cout << "the char is not in the list" << endl;
	}
}

void test_replaceAt(CharLinkedList& list) {
	// in nonempty list
	cout << "replaceAt test: " << endl;
	list.clear();
	list.pushAtBack('c');
	list.print();
	list.replaceAt('d', 0);
	list.print();

	// in empty list
	list.clear();
	list.print();
	list.replaceAt('a', 0); // should throw error

}

// THIS ISN NOT POPPING 
void test_popFromFront(CharLinkedList& list) {
	// in nonempty list
	cout << "popFromFront test: " << endl;
	
	// for list w 2 elements
	list.clear();
	list.pushAtBack('a');
	list.pushAtFront('z');
	list.pushAtFront('r');
	list.print();
	list.popFromFront(); // now there are 2 elements
	list.print();
	list.popFromFront(); // now 1 element
	list.print();
	list.popFromFront(); // now 0 elements
	list.print();

	// in empty list
	list.clear();
	list.print();
	list.popFromFront(); // should throw error
}

void test_popFromBack(CharLinkedList& list) {
	cout << "popFromBack test: " << endl;
	// in nonempty list
	list.clear();
	list.pushAtBack('a');
	list.pushAtFront('z'); // 2 elements
	list.print();
	list.popFromBack(); // now one element
	list.print();
	list.popFromBack(); // now 0 elements
	list.print();

	// in empty list
	list.clear();
	list.print();
	list.popFromBack();
}

void test_insertAt(CharLinkedList& list) {
	cout << "insertAt test: " << endl;
	// in empty list, GOOD
	list.clear();
	list.insertAt('a', 0);
	list.print();

	// in nonempty list
	list.insertAt('b', 1);
	list.print();
	list.insertAt('c', 1);
	list.print();
	list.insertAt('d', 3);
	list.print();
	list.insertAt('r', 0);
	list.print();

	// throw error
	list.insertAt('x', 44);

}

void test_removeAt(CharLinkedList& list) {
	cout << "removeAt test: " << endl;

	// load up list
	list.clear();
	list.pushAtFront('a');
	list.insertAt('c', 1);
	list.insertAt('b', 1);
	list.insertAt('d', 3);
	list.pushAtBack('e');
	list.print();

	//removing
	list.removeAt(0);
	list.print();
	list.removeAt(3);
	list.print();
	list.removeAt(1);
	list.print();
	list.removeAt(44); // should throw error
}

void test_insertInOrder(CharLinkedList& list) {
	cout << "insertInOrder test: " << endl;

	// load up the list
	list.clear();
	list.pushAtFront('a');
	list.insertAt('b', 1);
	list.insertAt('d', 2);
	list.pushAtBack('e');
	list.print();

	// test insert
	list.insertInOrder('c');
	list.print();
	list.insertInOrder('b');
	list.print();
	list.insertInOrder('f');
	list.print();

	// spec test
	list.clear();
	list.pushAtFront('z');
	list.pushAtBack('d');
	list.insertAt('e', 1);
	list.print();
	list.insertInOrder('a');
	list.print();
}

void test_concatenate(CharLinkedList& list, CharLinkedList& listTwo) {
	cout << "concatenate test: " << endl;
	// load up list one
	list.clear();
	list.pushAtFront('a');
	list.insertAt('b', 1);
	list.insertAt('d', 2);
	list.pushAtBack('e');
	list.print();

	// load up list two
	listTwo.pushAtBack('a');
	listTwo.insertAt('r', 1);
	listTwo.insertAt('b', 1);
	listTwo.insertAt('d', 2);
	listTwo.pushAtBack('e');
	listTwo.print();

	// test concatenate
	list.concatenate(&listTwo);
	list.print();
	list.concatenate(&list);
	list.print();
	listTwo.clear();
	list.concatenate(&listTwo);
	list.print();
}

void test_copyConstructor(CharLinkedList& list) {
	cout << "copy constructor test: " << endl;
	// nonempty case
	list.print();
	CharLinkedList listTwo(list);
	listTwo.print();

	// empty case
	list.clear();
	list.print();
	CharLinkedList listThree(list);
	listThree.print();
}

void test_arrayConstructor() {
	cout << "testing array constructor: " << endl;
	char carray[5];
	for (int i = 0; i < 5; i++) {
		carray[i] = 'a';
	}
	CharLinkedList list(carray, 5);
	list.print();

}


void test_assignOperator(CharLinkedList& list) {
	cout << "testing assingment operator: " << endl;
	CharLinkedList listTwo;
	listTwo.print();

	// load up list
	list.pushAtBack('a');
	list.insertAt('r', 1);
	list.insertAt('b', 1);
	list.insertAt('d', 2);
	list.pushAtBack('e');
	cout << "original list is: " << endl;
	list.print();

	listTwo = list;

	cout << "new list is: " << endl;
	listTwo.print();

	list.clear();
	listTwo = list;
	cout << "now, the cleared list: " << endl;
	listTwo.print();
}

void test_shrink(CharLinkedList& list) {
	cout << "testing shrink" << endl;
	list.shrink();
}
