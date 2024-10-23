#include "task1to3.h"
#include <iostream>
using namespace std;

int calculateDepth(BST_Node *node, int value, int depth){
    if ( node == nullptr){
        return -1;
    }
    
    if(node->data==value) return depth;
    
    if(value>node->data) return calculateDepth(node->RightChild,value,depth+1);
    else return calculateDepth(node->LeftChild,value,depth+1);
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

    cout<<endl<<"Height at root: "<<calculateDepth(bst.root,10,0)<<endl;
    cout<<"Height at node with value 5: "<<calculateDepth(bst.root,5,0)<<endl;
    cout<<"Height at node with value 18: "<<calculateDepth(bst.root,18,0)<<endl;
    

    return 0;
}
