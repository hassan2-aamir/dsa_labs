#include "../lab7/bst.h"
#include <iostream> 
using namespace std;

int calculateHeight(BST_Node* root){
    if (root==nullptr){
        return -1;
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

BST_Node* balanceNode(BST_Node* node){
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

    return node;
}

void insertNodeAVLTree(int val, BST_Node* &root){
    if(val>root->data){
        if(root->RightChild == nullptr){
            root->RightChild=new BST_Node(val);
        }
        else{
            insertNodeAVLTree(val,root->RightChild);
        }
    }

    else if(val<root->data){
        if(root->LeftChild==nullptr){
            root->LeftChild = new BST_Node(val) ;
        }
        else{
            insertNodeAVLTree(val,root->LeftChild);
        }

    }

    root=balanceNode(root);
}

// Function for In-Order Traversal
void inOrderTraversal(BST_Node* root) {
    if (root == nullptr) return;
    
    inOrderTraversal(root->LeftChild);          // Traverse left subtree
    cout << root->data << " ";              // Print node value
    inOrderTraversal(root->RightChild);         // Traverse right subtree
}

int main(){
    BST_Node* root = new BST_Node(10);
    insertNodeAVLTree(11,root);
    insertNodeAVLTree(12,root);

    cout <<endl<< "In-Order Traversal of the binary tree: ";
    inOrderTraversal(root);  // Display tree contents in In-Order Traversal
    cout << endl;

    cout<<root->LeftChild->data<<endl;


}