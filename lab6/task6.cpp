#include "task1to3.h"
#include <iostream>
using namespace std;

void largestBST(BST_Node* root){
    if(root->RightChild == nullptr){
        cout<<"Largest Node value is: "<<root->data<<endl<<endl;    
    }
    else{
        largestBST(root->RightChild);
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

    largestBST(bst.root);

    return 0;
}
