#include "bst.h"    // Include the binary search tree header file
#include <iostream> // Include input-output stream library
using namespace std;

// Function to recursively destroy all nodes in the binary search tree
void destroyTree(binarySearchTree &bst, BST_Node* &root) {
    BST_Node* curr = root;          // Set curr to the root of the tree
    BST_Node* currl = curr->LeftChild; // Pointer to the left child of current node
    BST_Node* currr = curr->RightChild; // Pointer to the right child of current node

    // Disconnect current node's children
    curr->LeftChild = nullptr;
    curr->RightChild = nullptr;
    delete curr;                    // Delete the current node
    root = nullptr;                 // Set root to nullptr, effectively deleting the tree

    // Recursively destroy left and right subtrees
    if(currl != nullptr) {
        destroyTree(bst, currl);    // Destroy left subtree
    }

    if(currr != nullptr) {
        destroyTree(bst, currr);    // Destroy right subtree
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
   bst.InsertWithoutDuplication(20);  // Insert right child of node 18

   // Display the contents of the tree using In-Order Traversal
   cout << endl << "Tree Contents: " << endl;
   InOrderTraversal(bst.root);  // Print tree contents before deletion

   // Delete the entire tree
   destroyTree(bst, bst.root); // Call destroyTree to delete all nodes in the tree

   // Display updated tree contents after deletion
   cout << endl << "Tree Contents after destruction: " << endl;
   InOrderTraversal(bst.root); // Print tree contents after deletion

   return 0;  // End of the program
}
