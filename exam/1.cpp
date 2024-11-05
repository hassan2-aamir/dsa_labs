#include "../lab7/bst.h"
#include <iostream> 
using namespace std;

int calculateHeight(BST_Node* root){
    if (root==nullptr){
        return 0;
    }

    else{
        return 1+ max(calculateHeight(root->LeftChild),calculateHeight(root->RightChild));
    }
}

int checkBalance(BST_Node* root){
    return(calculateHeight(root->LeftChild)- calculateHeight(root->RightChild));
}

BST_Node* rotateLeft(BST_Node* root){
    BST_Node* x = root->RightChild;
    BST_Node* xLeft = x->LeftChild;
    
    x->LeftChild = root;
    root->RightChild = xLeft;

    return x;
}

BST_Node* rotateRight(BST_Node* root){
    BST_Node* x = root->LeftChild;
    BST_Node* xRight = x->RightChild;

    x->RightChild = root;
    root->LeftChild= xRight;

    return x;
}

void balanceNode(BST_Node* node){
    int balance = checkBalance(node);

    if(balance>1){
        if(node->LeftChild->LeftChild != nullptr){
            return rotateRight(node);
        }
        else{
            node->LeftChild=rotateLeft(node->LeftChild);
            return rotateRight(node);
        }
    } 

    if(balance<-1){
        if(node->RightChild->RightChild != nullptr){
            return rotateLeft(node);
        }
        else{
            node->RightChild = rotateRight(node->RightChild);
            return rotateLeft(node);
        }

    }
}