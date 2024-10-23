#include "task1to3.h"  // Include the header file containing the class definitions for BST_Node and binarySearchTree
#include <iostream>    // Include for input/output operations
using namespace std;

// Function to find and print the largest value in the BST
// It works by traversing to the rightmost node, which holds the largest value in a BST
void largestBST(BST_Node* root){
    // If there is no right child, we have found the largest node
    if(root->RightChild == nullptr){
        cout << "Largest Node value is: " << root->data << endl << endl;  // Output the largest node's value
    }
    else{
        largestBST(root->RightChild);  // Continue moving to the right to find the largest node
    }
}

int main() {
    binarySearchTree bst;  // Create a binary search tree object

    // Insert values into the binary search tree
    bst.InsertWithoutDuplication(10);  // Insert the root node
    bst.InsertWithoutDuplication(5);   // Insert left child of root
    bst.InsertWithoutDuplication(15);  // Insert right child of root
    bst.InsertWithoutDuplication(3);   // Insert left child of node 5
    bst.InsertWithoutDuplication(7);   // Insert right child of node 5
    bst.InsertWithoutDuplication(12);  // Insert left child of node 15
    bst.InsertWithoutDuplication(18);  // Insert right child of node 15

    // Display the contents of the tree using In-Order Traversal
    cout << endl << "Tree Contents: " << endl;
    InOrderTraversal(bst.root);

    // Call the function to find and display the largest node in the tree
    largestBST(bst.root);

    return 0;  // End of the program
}
