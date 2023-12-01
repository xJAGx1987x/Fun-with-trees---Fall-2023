# Fun-with-trees---Fall-2023
Tree based program from Data Structures (COMP 2270) Fall 2023. 

Overview:
You will need to write a program to count the frequency of words in a given text. You will
read the content of a text file and construct a binary search tree using the words in the file.
Each node of the tree will consist of a word (C++ string) and the frequency count of that
word. Make sure there is only one node for each word in the tree. The program should also
display some properties of the tree (number of nodes, height, fullness, and balance).
You will need to create a Tree class for this program. It will have member data for the root
pointer and the following member functions:

• A constructor that will create an empty tree.
• A destroy function that will repeatedly delete the root node.
• A recursive function that will insert a word into the tree. Note that this function will
create a new node only if the word does not already exist in the tree. If the word
already exists in the tree, only the count of the word should be increased in that
node.
• A recursive function that will delete a target node from the tree.
• A recursive function that will return the number of nodes in the tree.
• A recursive function that will display the words (along with the frequency count) in
alphabetical order (as shown in sample execution).
• A recursive function that will display the words (along with the frequency count) in
reverse alphabetical order (as shown in sample execution).
• A function that will determine if the tree is empty.
• A recursive function that will return the height of the tree.
• A recursive function that will determine if the tree is full.
• A recursive function that will determine if the tree is balanced.

You will need to write the tree code in tree.h and tree.cpp. The driver code should be
written in prog4.cpp and should display a menu to allow the user to perform different tree
operations repeatedly (sample execution). For option#1, you will read the content of a
text file and construct a binary search tree by repeatedly inserting each word read from the
file. For simplicity, you will disregard punctuation marks and ignore case sensitivity. You
MUST check if the tree is empty before constructing a new one. If the tree is not empty, you
will need to destroy the current one.
