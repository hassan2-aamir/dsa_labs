#include <iostream>      // Include for input/output operations
#include "task1to3.h"   // Include the header file containing the class definitions for BST_Node and binarySearchTree
using namespace std;

int main() {
    binarySearchTree bst;  // Create a binary search tree object

    // Test if the tree is empty and display the result
    cout << "Is the tree empty? " << (bst.IsEmpty() ? "Yes" : "No") << endl << endl;

    // Insert values into the binary search tree
    bst.InsertWithoutDuplication(10);  // Insert root node
    bst.InsertWithoutDuplication(5);   // Insert left child of root
    bst.InsertWithoutDuplication(15);  // Insert right child of root
    bst.InsertWithoutDuplication(3);   // Insert left child of node 5
    bst.InsertWithoutDuplication(7);   // Insert right child of node 5
    bst.InsertWithoutDuplication(12);  // Insert left child of node 15
    bst.InsertWithoutDuplication(18);  // Insert right child of node 15
    cout << "Values inserted successfully" << endl << endl; // Confirm insertion

    // Try to insert a duplicate value (10)
    cout << "Trying to insert a duplicate value" << endl;
    bst.InsertWithoutDuplication(10); // Attempt to insert 10 again

    return 0; // End of the program
}
