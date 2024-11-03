#include "bst.h"
#include <iostream>
using namespace std;

void destroyTree(binarySearchTree &bst,BST_Node* &root){
    BST_Node* curr = root;
    BST_Node* currl = curr->LeftChild;
    BST_Node* currr = curr->RightChild;

    curr->LeftChild=nullptr;
    curr->RightChild=nullptr;
    delete curr;
    root = nullptr;

    if(currl != nullptr){
        destroyTree(bst,currl);
    }

    if(currr != nullptr){
        destroyTree(bst,currr);
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
   
   
   // Delete the specified value
   destroyTree(bst,bst.root);

   // Display updated tree contents
   cout << endl << "Tree Contents after destruction: " << endl;
   InOrderTraversal(bst.root);

   return 0;  // End of the program
}
