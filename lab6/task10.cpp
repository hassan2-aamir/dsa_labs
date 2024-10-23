#include "task1to3.h"
#include <iostream>
using namespace std;

int calculateDepth(BST_Node* root){
    if (root == nullptr){
        return -1;
    }
    else{
        return 1+max(calculateDepth(root->LeftChild),calculateDepth(root->RightChild));
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

    cout<<endl<<"Total Height: "<<calculateDepth(bst.root)<<endl;
    bst.Search(5);
    cout<<"Height at node with value 5: "<<calculateDepth(bst.loc)<<endl;
    bst.Search(18);
    cout<<"Height at node with value 18: "<<calculateDepth(bst.loc)<<endl;
    

    return 0;
}
