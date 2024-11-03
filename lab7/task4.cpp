#include "bst.h"     // Include the binary search tree header file
#include <iostream>  // Include input-output stream library
using namespace std;

// Function to count the types of nodes in a binary search tree
void countNodes(BST_Node* root, int* counts) {
    if (root == nullptr) {           // Base case: if root is null, return
        return;
    } 

    // Check if the node is a leaf node (no children)
    if (root->LeftChild == nullptr and root->RightChild == nullptr) {
        counts[0]++;                // Increment leaf node count
    }
    // Check if the node has only a left child
    else if (root->RightChild == nullptr) {
        counts[1]++;                // Increment count for nodes with only left child
    }
    // Check if the node has only a right child
    else if (root->LeftChild == nullptr) {
        counts[2]++;                // Increment count for nodes with only right child
    }
    // Node has both left and right children
    else {
        counts[3]++;                // Increment count for nodes with two children
    }

    // Recursive calls to count nodes in left and right subtrees
    countNodes(root->LeftChild, counts);
    countNodes(root->RightChild, counts);
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
    bst.InsertWithoutDuplication(20);  // Insert right child of node 18

    // Display the contents of the tree using In-Order Traversal
    cout << endl << "Tree Contents: " << endl;
    InOrderTraversal(bst.root);   // Print tree contents before counting

    int counts[] = {0, 0, 0, 0};  // Initialize counts array to hold node types
    countNodes(bst.root, counts); // Count different node types in the tree
    
    // Display counts of each node type
    cout << endl << "Counts: " << endl;
    cout << "Leaf Count: " << counts[0] << endl;          // Display count of leaf nodes
    cout << "Left only Count: " << counts[1] << endl;     // Display count of nodes with only left child
    cout << "Right Only Count: " << counts[2] << endl;    // Display count of nodes with only right child
    cout << "2 child Count: " << counts[3] << endl;       // Display count of nodes with two children

    return 0;  // End of the program
}
