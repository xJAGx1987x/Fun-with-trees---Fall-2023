// Name: Joshua George
// File Name: Tree.h
// Date: 10_27_2023
// Program Description:
// This C++ header file declares the structure of a binary search tree (BST) for word frequency analysis.
// The tree is designed to efficiently store words in alphabetical order, along with their frequencies.
// It provides a set of functions for tree manipulation, including creation, destruction, insertion,
// deletion, and various analysis functions such as counting nodes, calculating height, and checking
// for balance and fullness. The header file also includes the definition of the 'Tree' class and its
// associated 'Node' structure.

#ifndef TREE_H
#define TREE_H

#include <string>
#include <iostream> // Include for testing purposes
#include <algorithm>

using namespace std ; 


class Tree {
	private:
		struct Node {
			std::string word;
			int frequency;
			Node* left;
			Node* right;

			Node(const std::string& w) : word(w), frequency(1), left(nullptr), right(nullptr) {}
		};

		Node* root;

	public:
		Tree();
		~Tree();

		void destroyTree(Node*& node);
		void destroyTree();

		void insert(Node*& node, const std::string& word);
		void insert(const std::string& word);
		string toLower(const string& input) const ;  

		void deleteNode(Node*& node, const std::string& word);
		void deleteNode(const std::string& word);
		Node* findMin(Node* node) const;

		int countNodes(Node* node) const;
		int countNodes() const;

		void displayInOrder(Node* node, int& wordCount ) const;
		void displayInOrder() const;

		void displayReverseOrder(Node* node, int& wordCount) const;
		void displayReverseOrder() const;

		int height(Node* node) const;
		int height() const;

		bool isFull(Node* node) const;
		bool isFull() const;

		bool isBalanced(Node* node) const;
		bool isBalanced() const;

		bool isEmpty() const;
};

#endif
