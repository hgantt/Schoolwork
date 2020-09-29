/* David Gantt
 * Comp15 HW4
 * March 8 2020
 * BinarySearchTree.cpp
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure. It includes the definition of all
 * public and private member functions.
 * Acknowledgements: I'd like to thank the TAs for helping me.
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
        root = nullptr;  // not really necessary, since the tree is going
                         // away, but might want to guard against someone
                         // using a pointer after deleting
}

void BinarySearchTree::post_order_delete(Node *node)
{
    if (node == nullptr)
        return;

    post_order_delete(node->left);
    post_order_delete(node->right);
    delete node;
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        // use pre-order traversal to copy the tree
        root = pre_order_copy(source.root); // ASK ABOUT .ROOT
}

// assignment overload
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
        // TODO: Students write code here
        // check for self-assignment
    if (this == &source)
        return *this;
        // delete current tree if it exists
    post_order_delete(root);
        // use pre-order traversal to copy the tree
    root = pre_order_copy(source.root);
    // BinarySearchTree newTree(source);
        // don't forget to "return *this"
    return *this;
}

// returns the root of the copied tree
BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{
    if (node == nullptr)
        return nullptr;

    Node * temp = new Node;
    temp->data = node->data;
    temp->count = node->count;
    temp->left = pre_order_copy(node->left);
    temp->right = pre_order_copy(node->right);
    return temp;
}

int BinarySearchTree::find_min() const
{
        if (root == nullptr)
                return numeric_limits<int>::max(); // INT_MAX
        return find_min(root)->data;
}

BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{
    if (node->left == nullptr)
        return node;
    else
        return find_min(node->left);
}

int BinarySearchTree::find_max() const
{
    if (root == nullptr)
        return numeric_limits<int>::min();

    return find_max(root)->data;
}

BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
    if (node->right == nullptr) {
        return node;
    } else {
        return find_max(node->right);
    }
}

bool BinarySearchTree::contains(int value) const
{
    return contains(root, value);
}

bool BinarySearchTree::contains(Node *node, int value) const
{
        // return false if the tree is empty
    if (node == nullptr)
        return false;
        // return true if found
    else if (node->data == value)
        return true;
        // search for it
    else if (node->data > value)
        return contains(node->left, value);
    else
        return contains(node->right, value);
}
 
void BinarySearchTree::insert(int value)
{
        insert(root, nullptr, value);
}

// the node in this is the root of the tree
void BinarySearchTree::insert(Node *node, Node *parent, int value)
{
        if (parent == nullptr and node == nullptr) {
            root = newNode(value);
            return;
        } else if (node == nullptr) {
            Node * temp = newNode(value);

            if (value > parent->data) {
                parent->right = temp;
            } else {
                parent->left = temp;
            }
        // nonempty tree, not in the tree
        } else if (node->data == value) {
            node->count++;
        // nonempty tree, already in the tree
        } else {
            if (value > node->data) {
                insert(node->right, node, value);
            } else {
                insert(node->left, node, value);
            }
        }
}

bool BinarySearchTree::remove(int value)
{
    return remove(root, nullptr, value);
}

bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
    if (node != nullptr) {
        if (node->data == value) {
            node->count--;
            if (node->count == 0) { // if its no longer in the tree, remove it
                // if its a leaf (has 0 children)
                if (isLeaf(node)) {
                    removeLeaf(parent, node);
                    return true;
                // 2 children
                } if (node->left != nullptr and node->right != nullptr) {
                    Node * temp = find_min(node->right);
                    node->count = temp->count;
                    node->data = temp->data;
                    temp->count = 1;
                    return remove(node->right, node, node->data);
                // node has one child
                } else {
                    removeWithOneChild(parent, node);
                    delete node;
                }
                return true;
            } 
        } else if (node->data > value) // recursive call
            return remove(node->left, node, value);
        else if (node->data < value)
            return remove(node->right, node, value);
    } return false;
}

int BinarySearchTree::tree_height() const
{
    if (root == NULL)
        return -1; 
    
    return tree_height(root);
}

int BinarySearchTree::tree_height(Node *node) const
{
    if (node == nullptr) {
        return 0;
    } else if (isLeaf(node)) {
        return 0;
    } else {
        int heightLeft = tree_height(node->left);
        int heightRight = tree_height(node->right);
        return 1 + max(heightLeft, heightRight);

    }
}

// returns the total number of nodes
int BinarySearchTree::node_count() const
{
    if (root == nullptr)
        return 0;
    return node_count(root);
}

int BinarySearchTree::node_count(Node *node) const
{
    if (node == nullptr)
        return 0;
    
    return 1 + node_count(node->left) + node_count(node->right);
}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() const
{
    if (root == nullptr) {
        return 0;
    }

    return count_total(root);
}

int BinarySearchTree::count_total(Node *node) const
{
        if (node == nullptr)
            return 0;
        // duplicates
        if (node->count > 1) {
            return (node->count * node->data) + count_total(node->left) +
             count_total(node->right);
        }
        // non duplicates
        return node->data + count_total(node->left) +
             count_total(node->right);
}

BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const
{
        if (node == nullptr)
                return nullptr;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        size_t      numLayers  = tree_height() + 1;
        size_t      levelWidth = 4;
        const char *rootPrefix = "-> ";

        // Need numLayers * levelWidth characters for each layer of tree.
        // Add an extra levelWidth characters at front to avoid if statement
        // 1 extra char for nul character at end
        char *start = new char[(numLayers + 1) * levelWidth + 1];

        print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
        delete[] start;
}

// Logic and Output Reference: 
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const
{
        if (node == nullptr)
                return;

        // 4 characters + 1 for nul terminator
        using TreeLevel                    = char[5];
        static const int       levelLength = sizeof(TreeLevel) - 1;
        static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                               CONNECT = "   |";
        // Copies prev into dest and advances dest by strlen(prev)
        auto set = [](char *dest, const char *prev) {
                size_t p = strlen(prev);
                return (char *)memcpy(dest, prev, p) + p;
        };

        print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

        // Clear any characters that would immediate precede the "branch"
        // Don't need to check for root (i.e start of array),fullLine is padded
        set(currPos - levelLength, EMPTY);

        // Terminate fullLine at current level
        *currPos = '\0';

        std::cerr << fullLine << branch << node->data
                  << (node->count > 1 ? "*" : "") << endl;

        // Connect upper branch to parent
        if (branch == UP)
                set(currPos - levelLength, CONNECT);

        // Connect lower branch to parent
        print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}

bool BinarySearchTree::isLeaf(Node * np) const {
    if (np == nullptr)
        return false;
    if (np->right == nullptr and np->left == nullptr)
        return true;
    else
        return false;
}

BinarySearchTree::Node * BinarySearchTree::newNode(int value) const {
    Node * newNode = new Node;
    newNode->right = nullptr;
    newNode->left = nullptr;
    newNode->data = value;
    newNode->count = 1;
    return newNode;
}

void BinarySearchTree::removeWithOneChild(Node * parent, Node * node) const {
    if (parent->right == node and node->left == nullptr) 
        parent->right = node->right;
    else if (parent->right == node and node->right == nullptr) 
        parent->right = node->left;
    else if (parent->left == node and node->right == nullptr) 
        parent->left = node->left;
    else if (parent->left == node and node->left == nullptr) 
        parent->left = node->right;
}

void BinarySearchTree::removeLeaf(Node * parent, Node * node) const {
    if (node->count > 1) 
        node->count--;
    // left of parent
    else if (node->data < parent->data)
        parent->left = nullptr;
    // its to the right of the parent
    else if (node->data > parent->data)
        parent->right = nullptr;
    delete node;
}


