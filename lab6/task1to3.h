#include <iostream>
using namespace std;

class BST_Node{ 
	public:
		int data;
		BST_Node *LeftChild;
		BST_Node *RightChild;

		BST_Node(int Data){
			data = Data;
			LeftChild=nullptr;
			RightChild=nullptr;
		}
};

class binarySearchTree{
	public:
		BST_Node *root;
		BST_Node *loc;
		BST_Node *ploc;

		binarySearchTree(){
			root=nullptr;
			loc=nullptr;
			ploc=nullptr;
		}
		bool IsEmpty(){
			return root == nullptr;
		}
		void Search(int value){
			loc=root;
			ploc=nullptr;
			while(loc!= nullptr){
				if(loc->data==value){
					return;
				}
				else if(value>loc->data){
					ploc=loc;
					loc=loc->RightChild	;
				}
				else{
					ploc = loc;
					loc=loc->LeftChild;
				}
			}
		}
		void InsertWithoutDuplication(int value){
			Search(value);
			if(loc!=nullptr){
				cout<<"Value already exists in the tree"<<endl;
			}
			else if(ploc==nullptr){
				root = new BST_Node(value);
			}
			else{
				loc=new BST_Node(value);
				if(loc->data >ploc->data){
					ploc->RightChild=loc;

				}
				else{
					ploc->LeftChild=loc;
				}
			}
		}
};

void InOrderTraversal(BST_Node* root){
    if(root != nullptr){
        InOrderTraversal(root->LeftChild);
        cout<<root->data<<endl;
        InOrderTraversal(root->RightChild);
    }
}