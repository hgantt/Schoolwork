/* David Gantt
 * Comp15 HW4
 * March 8 2020
 * BinarySearchTree.cpp
 * This is the testing file for the BinarySearchTree class.
 * It includes a unit test for every of the public member functions.
 */
#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

// Testing Functions

// Name: named with "test" and the public functions it tests
// Paramaters: A BinarySearchTree object, passed by reference
// Returns: void
// Purpose: unit test for the public member functions
void testCopyConstructor(BinarySearchTree &bst);
void testAssignment(BinarySearchTree &bst);
void testFindMin(BinarySearchTree &bst);
void testFindMax(BinarySearchTree &bst);
void testContains(BinarySearchTree &bst);
void testInsert(BinarySearchTree &bst);
void testRemove(BinarySearchTree &bst);
void testTreeHeight(BinarySearchTree &bst);
void testNodeCount(BinarySearchTree &bst);
void testCountTotal(BinarySearchTree &bst);
void testPrintTree(BinarySearchTree &bst);


int main() {
	// call default constructor
	BinarySearchTree bst;
	// initialize it w values
    int values[]  = {1, 4, 9, 16, 25, 64, 100, 225, 
    	14, 18, 18, 18, 60, -6, -99, 12, -6, -2, -3};
    int numValues = sizeof(values) / sizeof(int);
    for (int i = 0; i < numValues; i++) {
        bst.insert(values[i]);
    }

    // call all unit tests
	testCopyConstructor(bst);
	testAssignment(bst);
	testFindMin(bst);
	testFindMax(bst);
	testContains(bst);
	testInsert(bst);
	testRemove(bst);
	testTreeHeight(bst);
	testNodeCount(bst);
	testCountTotal(bst);
}

void testCopyConstructor(BinarySearchTree &bst) {
	cerr << "testing copyConstructor\n";
	// print the original tree
	bst.print_tree();
	// copy it
	BinarySearchTree copy(bst);
	// print the new tree, should be the same
	copy.print_tree();

	// empty tree
	BinarySearchTree emptyTree;
	emptyTree.print_tree();
	BinarySearchTree emptyCopy(emptyTree);
	emptyCopy.print_tree();
}

void testAssignment(BinarySearchTree &bst) {
	cerr << "testing assignment\n";
	// print the original tree
	bst.print_tree();
	// make a new tree, assignment
	BinarySearchTree newTree;
	newTree = bst;
	// print the new tree, should be the same
	newTree.print_tree();
}

void testFindMin(BinarySearchTree &bst) {
	cerr << "testing findMin\n";
	// print the min after removing many nodes
	cerr << bst.find_min() << endl;
	bst.remove(-99);
	cerr << bst.find_min() << endl;
	while (bst.contains(-6)) {
		bst.remove(-6);
	}
	cerr << bst.find_min() << endl;
}

void testFindMax(BinarySearchTree& bst) {
	cerr << "testing findMax\n";
	// print the max after removing many nodes
	cerr << bst.find_max() << endl;
	bst.remove(225);
	cerr << bst.find_max() << endl;
	bst.remove(100);
	cerr << bst.find_max() << endl;
	bst.remove(64);
	cerr << bst.find_max() << endl;
}

void testContains(BinarySearchTree& bst) {
	// 0 = false, 1 = true
	cerr << "testing contains\n";
	// test contains after removing some nodes
	cerr << bst.contains(22222) << endl;

	cerr << bst.contains(14) << endl;
	bst.remove(14);
	cerr << bst.contains(14) << endl;
}

void testInsert(BinarySearchTree &bst) {
	cerr << "testing insert\n";
	// insert and print many nodes on all
	// sides of trees in all configurations
	bst.print_tree();
	bst.insert(63);
	bst.print_tree();
	bst.insert(11);
	bst.print_tree();
	bst.insert(-111);
	bst.print_tree();
	bst.insert(2);
	bst.print_tree();
	bst.insert(12);
	bst.print_tree();
}

void testRemove(BinarySearchTree &bst) {
	cerr << "testing remove" << endl;
	// remove and print

	bst.print_tree();

	bst.remove(100000);
	bst.print_tree();

	bst.remove(bst.find_min());
	bst.print_tree();
	bst.remove(bst.find_max());
	bst.remove(1);
	bst.print_tree();
	bst.remove(16); 
	bst.print_tree();
	bst.remove(18); 
	bst.print_tree();
	bst.remove(18);
	bst.print_tree();
	bst.remove(18);
	bst.print_tree();
}

void testTreeHeight(BinarySearchTree &bst) {
	cerr << "testing tree_height\n";
	BinarySearchTree testTree;
	// empty
	cerr << testTree.tree_height() << endl;
	testTree.insert(5);
	// one
	cerr << testTree.tree_height() << endl;
	testTree.insert(1);
	// two
	cerr << testTree.tree_height() << endl;
	// manyu
	testTree = bst;
	cerr << testTree.tree_height() << endl;

}

void testNodeCount(BinarySearchTree &bst) {
	cerr << "testing node_count\n";
	BinarySearchTree testTree;
	// empty
	cerr << testTree.node_count() << endl;
	testTree.insert(4);
	// one
	cerr << testTree.node_count() << endl;
	// many by assignment
	testTree = bst;
	cerr << testTree.node_count() << endl;

}

void testCountTotal(BinarySearchTree &bst) {
	cerr << "testing count_total\n";
	BinarySearchTree testTree;
	//empty
	cerr << testTree.count_total() << endl;
	testTree.insert(5);
	// five
	cerr << testTree.count_total() << endl;
	testTree.insert(9);
	// fourteen
	cerr << testTree.count_total() << endl;
	// assignment
	cerr << bst.count_total() << endl;
	testTree = bst;
	cerr << testTree.count_total() << endl;
}