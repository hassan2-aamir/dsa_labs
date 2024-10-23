#include "task1to3.h"  // Include the header file containing the class definitions for BST_Node and binarySearchTree
#include <iostream>    // Include for input/output operations
using namespace std;

// Function for Pre-Order Traversal
// Root -> Left -> Right
void PreOrderTraversal(BST_Node* root){
    if(root != nullptr){
        cout << root->data << endl;  // Visit the root node
        PreOrderTraversal(root->LeftChild);  // Traverse the left subtree
        PreOrderTraversal(root->RightChild);  // Traverse the right subtree
    }
}

// Function for In-Order Traversal
// Left -> Root -> Right (prints nodes in ascending order for a BST)
void inOrderTraversal(BST_Node* root){
    if(root != nullptr){
        InOrderTraversal(root->LeftChild);  // Traverse the left subtree
        cout << root->data << endl;  // Visit the root node
        InOrderTraversal(root->RightChild);  // Traverse the right subtree
    }
}

// Function for Post-Order Traversal
// Left -> Right -> Root
void PostOrderTraversal(BST_Node* root){
    if(root != nullptr){
        PostOrderTraversal(root->LeftChild);  // Traverse the left subtree
        PostOrderTraversal(root->RightChild);  // Traverse the right subtree
        cout << root->data << endl;  // Visit the root node
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

    // Perform and display In-Order Traversal
    cout << endl << "In order traversal: " << endl;
    inOrderTraversal(bst.root);

    // Perform and display Pre-Order Traversal
    cout << endl << "Pre order traversal: " << endl;
    PreOrderTraversal(bst.root);

    // Perform and display Post-Order Traversal
    cout << endl << "Post order traversal: " << endl;
    PostOrderTraversal(bst.root);

    return 0;  // End of the program
}
