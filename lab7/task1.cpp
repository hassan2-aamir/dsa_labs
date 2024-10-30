#include "bst.h"
#include <iostream>
using namespace std;

BST_Node* predecessor(BST_Node* curr,int start=1){
    if (start ==1)curr = curr->LeftChild;
    // If there is no right child, we have found the smallest node
    if(curr->RightChild == nullptr){
        return curr;  // Output the largest node's value
    }
    else{
        predecessor(curr->RightChild,0);  // Continue moving to the right to find the largest node
    }
}
void deleteNode(int val,binarySearchTree bst){
    bst.Search(val);
    if(bst.loc==nullptr){
        cout<<"Delete value does not exist in tree or tree is empty";
    }
    else{
        //leaf node
        if (bst.loc->LeftChild == nullptr && bst.loc->RightChild == nullptr){
            if(bst.loc->data>bst.ploc->data) bst.ploc->RightChild=nullptr;
            else bst.ploc->LeftChild=nullptr;
            BST_Node* temp = bst.loc;
            delete temp;
        }
        //one subtree
        else if((bst.loc->LeftChild==nullptr && bst.loc->RightChild!= nullptr)||(bst.loc->LeftChild!= nullptr && bst.loc->RightChild== nullptr)){
            if(bst.loc->data>bst.ploc->data) bst.ploc->RightChild=nullptr;
            else bst.ploc->LeftChild=nullptr;

            if (bst.loc->LeftChild!= nullptr){
                if(bst.ploc->data<bst.loc->LeftChild->data) bst.ploc->RightChild=bst.loc->LeftChild;
                else bst.ploc->LeftChild=bst.loc->LeftChild;
            }

            if (bst.loc->RightChild!= nullptr){
                if(bst.ploc->data<bst.loc->RightChild->data) bst.ploc->RightChild=bst.loc->RightChild;
                else bst.ploc->LeftChild=bst.loc->RightChild;
            }

            BST_Node* temp = bst.loc;
            delete temp;
        }

        //two subtrees
        else{
            BST_Node* pred = predecessor(bst.loc);
            if(bst.loc->data>bst.ploc->data) bst.ploc->RightChild=nullptr;
            else bst.ploc->LeftChild=nullptr;

            bst.loc->LeftChild=nullptr;
            bst.ploc->RightChild

        }

    }
}