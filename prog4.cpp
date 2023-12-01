// Name: Joshua George
// File Name: prog4.cpp 
// Date: 10_27_2023
// Program Description:
// This C++ program serves as the main driver file for a word frequency analysis application.
// It utilizes a tree data structure to efficiently store and manage words, along with their
// frequencies, read from a user-specified text file. The program allows users to create, modify,
// and analyze word frequency trees, providing insights into the structure of the text and supporting
// operations such as tree destruction, insertion, and display. The user is guided through a menu
// interface to interact with the application's functionality.

#include <iostream>
#include <fstream>
#include <string>
#include "tree.h"

using namespace std;

string removePunctuation(const string& input) ; 

int main() {
    Tree tree;

    int choice;
    string filename;  // Move variable declaration outside the switch
    ifstream inputFile;  // Move variable declaration outside the switch
    string word;  // Move variable declaration outside the switch

    do {
        cout << endl <<  "1. Build the tree\n"
             << "2. Display words (A-Z)\n"
             << "3. Display words (Z-A)\n"
             << "4. Destroy the tree\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
              case 1:
        if (!tree.isEmpty()) {
            // If it does, delete the existing tree
            tree.destroyTree();
        }

        while (true) {
            cout << "Enter the filename (or type 'menu' to go back): ";
            cin >> filename;

            if (filename == "menu") {
                // User wants to go back to the menu
                break;
            }

            inputFile.open(filename);
            if (inputFile) {
                // File opened successfully
                while (inputFile >> word) {
                    string cleanedWord = removePunctuation(word);
                    if (!cleanedWord.empty()) {
                        tree.insert(cleanedWord);
                    }
                }

                // Close the file when done
                inputFile.close();
				cout << endl << "The tree has " << tree.countNodes() << " words and a height of " << tree.height() << ".\n" ;
				cout << "The tree is " << (tree.isFull() ? "full" : "not full") << ".\n";
				cout << "The tree is " << (tree.isBalanced() ? "balanced" : "not balanced") << ".\n";
                break; // Exit the loop as the file is successfully processed
            } else {
                cerr << "Error: Unable to open file '" << filename << "'\n";
            }
        }
		break ;

            case 2:
				cout << endl ; 
                tree.displayInOrder();
                break;
            case 3:
				cout << endl ; 
                tree.displayReverseOrder();
                break;
            case 4:
                tree.destroyTree();
                break;
            case 5:
                cout << "Good-Bye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

// Helper function to remove punctuation from a string
string removePunctuation(const string& input) {
    string result;
    for (char ch : input) {
        if (isalpha(ch) || isdigit(ch) || ch == '\'') {
            // Keep letters, digits, and single quotes
            result += ch;
        }
    }
    return result;
}