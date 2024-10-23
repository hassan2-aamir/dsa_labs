#include "task1to3.h"  // Include the header file containing the class definitions for BST_Node and binarySearchTree
#include <iostream>    // Include for input/output operations
using namespace std;

// Function to count the internal nodes in the BST
// Internal nodes are nodes that have at least one child (non-leaf nodes)
int countInternalNodes(BST_Node* root){
    // Base case: if the node is null, return 0 (no internal nodes)
    if (root == nullptr) return 0;

    // If the node has at least one child (either left or right)
    else if(root->LeftChild != nullptr || root->RightChild != nullptr) {
        // Count this node as an internal node and recursively count the internal nodes in both subtrees
        return 1 + countInternalNodes(root->LeftChild) + countInternalNodes(root->RightChild);    
    }
    // If the node is a leaf (no children), return 0
    else return 0;
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

    // Output the count of internal nodes
    cout << endl << "Number of Internal Nodes: " << countInternalNodes(bst.root) << endl;

    return 0;  // End of the program
}
