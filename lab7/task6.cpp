// Include required header files
#include "bst.h"         // Include the binary search tree header file
#include <iostream>      // Include input-output stream library
using namespace std;

// Function to delete a node with a given value from the binary search tree
void deleteNode(int val, binarySearchTree &bst) {
   // Search for the node to be deleted
   bst.Search(val);
   
   // If node is not found, print error message and return
   if (bst.loc == nullptr) {
       cout << "Delete value does not exist in tree or tree is empty";
       return;
   }
   
   // Store pointers to the node to be deleted and its parent
   BST_Node* nodeToDelete = bst.loc;
   BST_Node* parentNode = bst.ploc;
   
   // Case 1: Node to be deleted is a leaf node
   if (nodeToDelete->LeftChild == nullptr && nodeToDelete->RightChild == nullptr) {
       // If node is the root
       if (parentNode == nullptr) {
           bst.root = nullptr;  // Set tree root to null
       }
       // If node is not the root
       else {
           // If node is a right child of its parent
           if (nodeToDelete->data > parentNode->data) {
               parentNode->RightChild = nullptr;
           }
           // If node is a left child of its parent
           else {
               parentNode->LeftChild = nullptr;
           }
       }
       // Delete the node
       delete nodeToDelete;
   }
   
   // Case 2: Node to be deleted has exactly one child
   else if ((nodeToDelete->LeftChild == nullptr) || (nodeToDelete->RightChild == nullptr)) {
       // Get the child node (either left or right)
       BST_Node* child = (nodeToDelete->LeftChild != nullptr) ? 
                         nodeToDelete->LeftChild : nodeToDelete->RightChild;
       
       // If node to delete is the root
       if (parentNode == nullptr) {
           bst.root = child;  // Replace root with the child
       }
       // If node is not the root
       else {
           // If node is a right child of its parent
           if (nodeToDelete->data > parentNode->data) {
               parentNode->RightChild = child;
           }
           // If node is a left child of its parent
           else {
               parentNode->LeftChild = child;
           }
       }
       // Delete the node
       delete nodeToDelete;
   }
   
   // Case 3: Node to be deleted has two children
   else {
       // Find the predecessor (largest value in left subtree)
       BST_Node* predecessorParent = nodeToDelete;
       BST_Node* predecessor = nodeToDelete->LeftChild;
       
       // Traverse to the rightmost node in the left subtree
       while (predecessor->RightChild != nullptr) {
           predecessorParent = predecessor;
           predecessor = predecessor->RightChild;
       }
       
       // Copy predecessor's data to the node to be deleted
       nodeToDelete->data = predecessor->data;
       
       // Delete the predecessor node
       if (predecessorParent == nodeToDelete) {
           // If predecessor is a direct left child
           predecessorParent->LeftChild = predecessor->LeftChild;
       }
       else {
           // If predecessor is not a direct left child
           predecessorParent->RightChild = predecessor->LeftChild;
       }
       
       // Delete predecessor node
       delete predecessor;
   }
}

// Function to delete nodes that have only one subtree in the binary search tree
void delete1sub(BST_Node* root, binarySearchTree &bst) {
    if (root == nullptr) return;  // Base case: if root is null, return

    // Recursively delete nodes with only one subtree in left and right subtrees
    delete1sub(root->LeftChild, bst);
    delete1sub(root->RightChild, bst);

    // If the node has only a left child, delete the node
    if (root->LeftChild != nullptr && root->RightChild == nullptr) {
        deleteNode(root->data, bst);
    }
    
    
    
}

int main() {
    binarySearchTree bst;  // Create a binary search tree object

    // Insert values into the binary search tree
    bst.InsertWithoutDuplication(10);  // Insert the root node
    bst.InsertWithoutDuplication(5);   // Insert left child of root
    bst.InsertWithoutDuplication(15);  // Insert right child of root
    bst.InsertWithoutDuplication(3);   // Insert left child of node 5
    bst.InsertWithoutDuplication(12);  // Insert left child of node 15
    bst.InsertWithoutDuplication(18);  // Insert right child of node 15
    bst.InsertWithoutDuplication(20);  // Insert right child of node 18
    
    
    

    // Display the contents of the tree using In-Order Traversal before deletion
    cout << endl << "Tree Contents: " << endl;
    InOrderTraversal(bst.root);   // Print tree contents before deleting nodes

    // Delete nodes with only one subtree
    delete1sub(bst.root, bst);
    
    // Display tree contents after deleting nodes with only one subtree
    cout << endl << "Tree Contents after deleting nodes with only 1 subtree: " << endl;
    InOrderTraversal(bst.root);

    return 0;  // End of the program
}
