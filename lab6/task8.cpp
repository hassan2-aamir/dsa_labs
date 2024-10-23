#include "task1to3.h"
#include <iostream>
using namespace std;

int countInternalNodes(BST_Node* root){
    if (root==nullptr) return 0;
    else if(root->LeftChild == nullptr and root->RightChild == nullptr) return 1;    
    else return countInternalNodes(root->LeftChild)+countInternalNodes(root->RightChild);
    
}

int main() {
    binarySearchTree bst;

   
    // Insert values
    bst.InsertWithoutDuplication(10);
    bst.InsertWithoutDuplication(5);
    bst.InsertWithoutDuplication(15);
    bst.InsertWithoutDuplication(3);
    bst.InsertWithoutDuplication(7);
    bst.InsertWithoutDuplication(12);
    bst.InsertWithoutDuplication(18);

    cout<<endl<<"Tree Contents: "<<endl;
    InOrderTraversal(bst.root);

    cout<<endl<<"Leafs: "<<countInternalNodes(bst.root)<<endl;
    

    return 0;
}
