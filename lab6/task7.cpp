#include "task1to3.h"
#include <iostream>
using namespace std;

void contLeafNodes(BST_Node* root){
    if(root->LeftChild == nullptr and root->RightChild == nullptr){
        cout<<root->data<<endl;    
    }
    else{
        if(root->LeftChild != nullptr) contLeafNodes(root->LeftChild);
        if(root->RightChild != nullptr) contLeafNodes(root->RightChild);
    }
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

    cout<<endl<<"Leafs: "<<endl;
    contLeafNodes(bst.root);

    return 0;
}
