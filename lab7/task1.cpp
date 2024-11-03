// Include required header files
#include "bst.h"
#include <iostream>
using namespace std;

// Function to delete a node with given value from binary search tree
void deleteNode(int val, binarySearchTree &bst) {
   // Search for node to be deleted
   bst.Search(val);
   
   // If node not found, print error message and return
   if (bst.loc == nullptr) {
       cout << "Delete value does not exist in tree or tree is empty";
       return;
   }
   
   // Store pointers to node to be deleted and its parent
   BST_Node* nodeToDelete = bst.loc;
   BST_Node* parentNode = bst.ploc;
   
   // Case 1: If node to be deleted is a leaf node
   if (nodeToDelete->LeftChild == nullptr && nodeToDelete->RightChild == nullptr) {
       // If node is root
       if (parentNode == nullptr) {
           bst.root = nullptr;
       }
       // If node is not root
       else {
           // If node is right child of parent
           if (nodeToDelete->data > parentNode->data) {
               parentNode->RightChild = nullptr;
           }
           // If node is left child of parent 
           else {
               parentNode->LeftChild = nullptr;
           }
       }
       // Delete the node
       delete nodeToDelete;
   }
   
   // Case 2: If node to be deleted has exactly one child
   else if ((nodeToDelete->LeftChild == nullptr) || (nodeToDelete->RightChild == nullptr)) {
       // Get the child node (either left or right)
       BST_Node* child = (nodeToDelete->LeftChild != nullptr) ? 
                         nodeToDelete->LeftChild : nodeToDelete->RightChild;
       
       // If node to delete is root
       if (parentNode == nullptr) {
           bst.root = child;
       }
       // If node is not root
       else {
           // If node is right child of parent
           if (nodeToDelete->data > parentNode->data) {
               parentNode->RightChild = child;
           }
           // If node is left child of parent
           else {
               parentNode->LeftChild = child;
           }
       }
       // Delete the node
       delete nodeToDelete;
   }
   
   // Case 3: If node to be deleted has two children
   else {
       // Find the predecessor (largest value in left subtree)
       BST_Node* predecessorParent = nodeToDelete;
       BST_Node* predecessor = nodeToDelete->LeftChild;
       
       // Find the rightmost node in left subtree
       while (predecessor->RightChild != nullptr) {
           predecessorParent = predecessor;
           predecessor = predecessor->RightChild;
       }
       
       // Copy predecessor's data to node to be deleted
       nodeToDelete->data = predecessor->data;
       
       // Delete the predecessor node
       if (predecessorParent == nodeToDelete) {
           // If predecessor is direct left child
           predecessorParent->LeftChild = predecessor->LeftChild;
       }
       else {
           // If predecessor is not direct left child
           predecessorParent->RightChild = predecessor->LeftChild;
       }
       
       // Delete predecessor node
       delete predecessor;
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
   InOrderTraversal(bst.root);

   // Get value to delete from user
   int inp;
   cout<<"Enter value to delete: ";
   cin>>inp;
   
   // Delete the specified value
   deleteNode(inp,bst);

   // Display updated tree contents
   cout << endl << "Tree Contents after deletion: " << endl;
   InOrderTraversal(bst.root);

   return 0;  // End of the program
}