// Name: Joshua George
// File Name: Tree.cpp
// Date: 10_27_2023
// Program Description:
// This C++ file implements the functions declared in the 'tree.h' header file.
// It defines the behavior of a binary search tree (BST) designed for word frequency analysis.
// The tree structure is used to efficiently store words in alphabetical order, along with their
// frequencies. The implementation includes operations such as tree creation, destruction,
// insertion, deletion, and various analysis functions like counting nodes, calculating height,
// and checking for balance and fullness.
#include "tree.h"
#include <iostream>
#include <string> 
#include <algorithm>

using namespace std ; 

// Constructor that will create an empty tree
Tree::Tree() {
    root = nullptr;
}

// Destructor to destroy the tree
Tree::~Tree() {
    destroyTree(root);
}

// Function to destroy the tree
void Tree::destroyTree(Node*& node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
        node = nullptr;
    }
}

// Wrapper function for destroying the tree
void Tree::destroyTree() {
	if (isEmpty() ) {
		cout << "\n Tree is empty!" << endl ;
	} else {
		destroyTree(root) ;
		cout << endl << "Tree destroyed!" << endl << endl ; 
	}
}

// Recursive function to insert a word into the tree
void Tree::insert(Node*& node, const string& word) {
    if (node == nullptr) {
        // Create a new node if the current node is null
        node = new Node(toLower(word));
    } else {
        // Convert the word in the node to lowercase
        string currentWordLower = toLower(node->word);
        // Convert the incoming word to lowercase for comparison
        string newWordLower = toLower(word);

        if (newWordLower < currentWordLower) {
            // Recursively insert into the left subtree
            insert(node->left, word);
        } else if (newWordLower > currentWordLower) {
            // Recursively insert into the right subtree
            insert(node->right, word);
        } else {
            // Word already exists, increment frequency
            node->frequency++;
        }
    }
}

// Wrapper function for inserting into the tree
void Tree::insert(const string& word) {
    insert(root, word);
}


// Helper function to convert a string to lowercase
string Tree::toLower(const string& input) const {
    string result = input;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to delete a target node from the tree
void Tree::deleteNode(Node*& node, const string& word) {
    // Implementation for deleting a node goes here
	if (node == nullptr) {
        // Node not found
        return;
    } else if (word < node->word) {
        // Word is in the left subtree
        deleteNode(node->left, word);
    } else if (word > node->word) {
        // Word is in the right subtree
        deleteNode(node->right, word);
    } else {
        // Node with the word to be deleted found

        // Case 1: Node has no children or only one child
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            node = temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            node = temp;
        } else {
            // Case 3: Node has two children
            // Find the in-order successor (or predecessor)
            Node* temp = findMin(node->right); // Example: using in-order successor (findMin)

            // Copy the in-order successor's data to this node
            node->word = temp->word;
            node->frequency = temp->frequency;

            // Recursively delete the in-order successor
            deleteNode(node->right, temp->word);
        }
    }
}

// Wrapper function for deleting a node from the tree
void Tree::deleteNode(const string& word) {
    deleteNode(root, word);
}

// Recursive function to count the number of nodes in the tree
int Tree::countNodes(Node* node) const { 
    if (node == nullptr) {
        return 0;  // An empty subtree has 0 nodes
    }

    // Count the current node and recursively count nodes in the left and right subtrees
    return 1 + countNodes(node->left) + countNodes(node->right);
}


// Function to return the number of nodes in the tree
int Tree::countNodes() const {
    return countNodes(root);
}


// Test function to display the tree (in-order traversal)
void Tree::displayInOrder(Node* node, int& wordCount) const {
    if (node != nullptr) {
        displayInOrder(node->left, wordCount) ;
        cout << node->word << " (" << node->frequency << ")  " ;
		wordCount++ ; 
		if (wordCount % 5 == 0) {
            cout << endl;
        }
        displayInOrder(node->right, wordCount);
    }
}

// Wrapper Function to display words in alphabetical order
void Tree::displayInOrder() const {
    if (isEmpty()) {
        cout << "Tree is empty!" << endl;
    } else {
		int wordCount = 0;
        displayInOrder(root, wordCount) ;
        cout << endl << endl ; // Ensure a new line after the last word
    }
}

// Recursive function to display the tree in reverse alphabetical order
void Tree::displayReverseOrder(Node* node, int& wordCount) const {
    if (node != nullptr) {
        displayReverseOrder(node->right, wordCount);

        cout << node->word << " (" << node->frequency << ") ";

        wordCount++;

        if (wordCount % 5 == 0) {
            cout << endl;
        }

        displayReverseOrder(node->left, wordCount);
    }
}

// Function to display the tree in reverse alphabetical order
void Tree::displayReverseOrder() const {
    if (isEmpty()) {
        cout << " Tree is empty!" << endl;
    } else {
        int wordCount = 0;
        displayReverseOrder(root, wordCount);
        cout << endl << endl; // Ensure a new line after the last word
    }
}


// Recursive function to calculate the height of the tree
int Tree::height(Node* node) const {
    if (node == nullptr) {
        return 0;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Return the height of the current node plus one (counting the current level)
        return 1 + max(leftHeight, rightHeight);
    }
}

// Function to return the height of the tree
int Tree::height() const {
    return height(root);
}

// Recursive function to check if the tree is full
bool Tree::isFull(Node* node) const {
       // An empty tree is considered full
    if (node == nullptr) {
        return true;
    }

    // If a node has no children, it's full by definition
    if (node->left == nullptr && node->right == nullptr) {
        return true;
    }

    // If a node has one child or two children, check its subtrees
    if (node->left != nullptr && node->right != nullptr) {
        return isFull(node->left) && isFull(node->right);
    }

    // If a node has only one child, the tree is not full
    return false;
}

// Function to check if the tree is full
bool Tree::isFull() const {
    return isFull(root);
}

// Recursive function to check if the tree is balanced
bool Tree::isBalanced(Node* node) const {
    if (node == nullptr) {
        return true; // An empty tree is balanced
    }

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    // Check if the subtree is balanced
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right)) {
        return true;
    }
    return false;
}


// Function to check if the tree is balanced
bool Tree::isBalanced() const {
    return isBalanced(root);
}

// Function to check if the tree is empty
bool Tree::isEmpty() const {
    return root == nullptr;
}

Tree::Node* Tree::findMin(Node* node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}