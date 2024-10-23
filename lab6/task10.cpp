#include "task1to3.h"  // Include the header file containing the class definitions for BST_Node and binarySearchTree
#include <iostream>    // Include for input/output operations
using namespace std;

// Function to calculate the height of the BST
// Height is defined as the number of edges on the longest path from the node to a leaf
int calculateHeight(BST_Node* root){
    // Base case: if the node is null, return -1 (indicating no height)
    if (root == nullptr){
        return -1;
    }
    else{
        // Calculate the height of the left and right subtrees
        // Return 1 plus the maximum height of either subtree
        return 1 + max(calculateHeight(root->LeftChild), calculateHeight(root->RightChild));
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

    // Calculate and output the total height of the entire tree
    cout << endl << "Total Height of tree: " << calculateHeight(bst.root) << endl;

    // Search for the node with value 5 and calculate its height
    bst.Search(5);
    cout << "Height at node with value 5: " << calculateHeight(bst.loc) << endl;

    // Search for the node with value 18 and calculate its height
    bst.Search(18);
    cout << "Height at node with value 18: " << calculateHeight(bst.loc) << endl;

    return 0;  // End of the program
}
