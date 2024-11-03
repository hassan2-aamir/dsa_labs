#include "bst.h"  // Include the header file containing the class definitions for BST_Node and binarySearchTree
#include <iostream>    // Include for input/output operations
using namespace std;

// Function to display the leaf nodes in the BST
// A leaf node is a node that has no children (both left and right child are null)
void displayLeafNodes(BST_Node* root){
    // If the node is a leaf (both left and right children are null)
    if(root->LeftChild == nullptr && root->RightChild == nullptr){
        cout << root->data << endl;  // Output the leaf node's value
    }
    else{
        // Recursively check the left subtree if it exists
        if(root->LeftChild != nullptr) displayLeafNodes(root->LeftChild);
        // Recursively check the right subtree if it exists
        if(root->RightChild != nullptr) displayLeafNodes(root->RightChild);
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

    // Display all the leaf nodes of the tree
    cout << endl << "Leaf Nodes: " << endl;
    displayLeafNodes(bst.root);

    return 0;  // End of the program
}
