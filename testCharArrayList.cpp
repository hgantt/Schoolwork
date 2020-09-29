// David Gantt
// January 29th, 2020
// comp15: Data Structures
// Testing file/client for the CharArrayList class. Includes
// many functions for testing the public members of the class
// CharArrayList


#include "CharArrayList.h"

using namespace std;

// Testing Functions. Each is named with with "test_"
// followed by the member function which it tests.
// The functions which are not tested in the
// functions below are tested in main().
void test_constructor(CharArrayList& list);
void test_IsEmpty(CharArrayList& list);
void test_size(CharArrayList& list); 
void test_elementAt(CharArrayList& list); 
void test_clear(CharArrayList& list); 
void test_insert(CharArrayList& list); 
void test_shrink(CharArrayList& list);
void test_first(CharArrayList& list);
void test_last(CharArrayList& list);
void test_replaceAt(CharArrayList& list);
void test_popFromBack(CharArrayList& list);
void test_popFromFront(CharArrayList& list);
void test_concatenation(CharArrayList& list, CharArrayList& listTwo);
void test_expand(CharArrayList& list);
void test_removeAt(CharArrayList& list);

// this main is longer than 30 lines
int main() 
{
	CharArrayList list('b'); 
	test_constructor(list); // test default constructor
	test_IsEmpty(list); // test IsEmpty
	test_size(list); // test size
	test_clear(list); // test clear
	test_IsEmpty(list);
	// tests insertAt(), pushAtBack(), pushAtFront(), and insertInOrder()
	test_insert(list); 
	test_removeAt(list); // test removeAt
	test_first(list); // test first
	test_last(list); // test last
	test_replaceAt(list); // test replaceAt
	test_popFromBack(list); // test popFromBack
	test_popFromFront(list); // test popFromFront
	test_elementAt(list); // test elementAt
	CharArrayList listTwo('p'); // test paramaterized constructor
	test_concatenation(list, listTwo); // test concatenation
	CharArrayList listThree(list); // test copy constructor
	listThree.print();
	test_concatenation(list, listThree);
	//test_shrink(list); // test shrink, this cannot be done without getCap
	list.print(); // test print
	test_replaceAt(list); // test replaceAt
	CharArrayList listFour;
	listThree.print();
	listFour = listThree; // test assignment operator
	listFour.insertAt('d', 4); 
	listFour.print(); 
	char array [5];
	for (int i = 0; i < 5; i++) {
		array [i] = 'a';
	}
	CharArrayList listFive(array, 4); // test other paramaterized constructor
	listFive.print();
	return 0;
}

void test_constructor(CharArrayList& list) {
	cout << "test constructor: " << endl;
	list.print();
}

void test_IsEmpty(CharArrayList& list) {
		bool empty = list.isEmpty();
		if (empty == true) {
				cout << "IsEmpty Test: The list is empty" << endl;;
		} else if (empty == false) {
				cout << "IsEmpty Test: There is at" <<
				" least one element in the list" << endl;
		}
}

void test_size(CharArrayList& list) {
	int size = list.size();
	cout << "Size Test: The size is " << size << endl;
}

void test_elementAt(CharArrayList& list) {
	cout << "element at test: the element is: ";
	char c = list.elementAt(1);
	cout << c << endl;
}

void test_clear(CharArrayList& list){
	list.clear();
	bool empty = list.isEmpty();
	if (empty == true) {
			cout << "Clear Test: The list is empty." << endl;
	} else if (empty == false)
			cout << "Clear Test: The list is not empty." << endl;
}

void test_insert(CharArrayList& list) {
	cout << "insert test: " << endl;
	list.insertAt('a', 0);
	list.print();
	list.pushAtBack('z');
	list.print();
	list.pushAtFront('c');
	list.print();
	list.insertAt('d', 1);
	list.print();
	list.pushAtBack('f');
	list.print();
	list.insertInOrder('q');
	list.print();
	list.insertInOrder('l');
	list.print();

	//expected output cdalqzf
}

// Uses getCap() function to test the shrink function
//void test_shrink(CharArrayList& list) {
//	cout << "shrink test: " << endl;
//	int capacity = list.getCap();
//	cout << capacity << endl;
//	list.shrink();
//	capacity = list.getCap();
//	cout << capacity << endl;
//}


void test_first(CharArrayList& list) {
	cout << "first test: " << endl;
	char c = list.first();
	cout << c << endl;
}

void test_last(CharArrayList& list) {
	cout << "last test: " << endl;
	char c = list.last();
	cout << c << endl;
}

void test_replaceAt(CharArrayList& list) {
	cout << "replaceAt Test: " << endl;
	list.print();
	list.replaceAt('e', 4);
	list.print();
}

void test_popFromBack(CharArrayList& list) {
	cout << "popFromBack Test:" << endl;
	list.print();
	list.popFromBack();
	list.print();
}

void test_popFromFront(CharArrayList& list) {
	cout << "popFromFront Test:" << endl;
	list.print();
	list.popFromFront();
	list.print();
}

void test_concatenation(CharArrayList& ogList, CharArrayList& list) {
	cout << "concatenation test: " << endl;
	ogList.print();
	ogList.concatenate(&list);
	ogList.print();
}

void test_removeAt(CharArrayList& list) {
	cout << "Testing removeAt: " << endl;
	list.print();
	list.removeAt(6);
	list.print();
}

// Used to test the private expand function
//void test_expand(CharArrayList& list) {
//	cout << "expansion test: " << endl;
//	int cap = list.getCap();
//	cout << cap << endl;
//	list.expand();
//	cap = list.getCap();
//	cout << cap << endl;
//
//}