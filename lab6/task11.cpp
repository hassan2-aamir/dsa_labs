#include "task1to3.h"  // Include the header file containing the class definitions for BST_Node and binarySearchTree
#include <iostream>    // Include for input/output operations
using namespace std;

// Function to calculate the depth of a node with a specific value in the BST
// The depth is defined as the number of edges from the root to the node with the given value
int calculateDepth(BST_Node *node, int value, int depth) {
    // Base case: if the node is null, return -1 (indicating the value does not exist)
    if (node == nullptr) {
        return -1;
    }
    
    // If the current node's data matches the target value, return the current depth
    if (node->data == value) return depth;
    
    // If the target value is greater than the current node's data, search the right subtree
    // Increment the depth by 1 for the next recursive call
    if (value > node->data) return calculateDepth(node->RightChild, value, depth + 1);
    
    // If the target value is less than the current node's data, search the left subtree
    // Increment the depth by 1 for the next recursive call
    else return calculateDepth(node->LeftChild, value, depth + 1);
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

    // Calculate and output the depth of the node with value 10 (the root)
    cout << endl << "Height at root: " << calculateDepth(bst.root, 10, 0) << endl;

    // Calculate and output the depth of the node with value 5
    cout << "Height at node with value 5: " << calculateDepth(bst.root, 5, 0) << endl;

    // Calculate and output the depth of the node with value 18
    cout << "Height at node with value 18: " << calculateDepth(bst.root, 18, 0) << endl;

    return 0;  // End of the program
}
