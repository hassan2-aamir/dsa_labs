#include "task1to3.h"
#include <iostream>
using namespace std;

void PreOrderTraversal(BST_Node* root){
    if(root != nullptr){
        cout<<root->data<<endl;
        PreOrderTraversal(root->LeftChild);
        PreOrderTraversal(root->RightChild);
    }
}

void InOrderTraversal(BST_Node* root){
    if(root != nullptr){
        InOrderTraversal(root->LeftChild);
        cout<<root->data<<endl;
        InOrderTraversal(root->RightChild);
    }
}

void PostOrderTraversal(BST_Node* root){
    if(root != nullptr){
        PostOrderTraversal(root->LeftChild);
        PostOrderTraversal(root->RightChild);
        cout<<root->data<<endl;
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

    cout<<endl<<"In order traversal: "<<endl;
    InOrderTraversal(bst.root);

    cout<<endl<<"Pre order traversal: "<<endl;
    PreOrderTraversal(bst.root);

    cout<<endl<<"Post order traversal: "<<endl;
    PostOrderTraversal(bst.root);
    return 0;
}

