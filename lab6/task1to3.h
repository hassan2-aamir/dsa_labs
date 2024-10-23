#include <iostream>
using namespace std;

// Class for a Binary Search Tree node
class BST_Node{ 
    public:
        int data;  // Data stored in the node
        BST_Node *LeftChild;  // Pointer to the left child
        BST_Node *RightChild;  // Pointer to the right child

        // Constructor to initialize the node with data, and set children as null
        BST_Node(int Data){
            data = Data;
            LeftChild = nullptr;
            RightChild = nullptr;
        }
};

// Class representing the binary search tree
class binarySearchTree{
    public:
        BST_Node *root;  // Pointer to the root node of the tree
        BST_Node *loc;   // Pointer to locate a node during search
        BST_Node *ploc;  // Pointer to locate the parent of a node during search

        // Constructor initializes an empty tree with all pointers set to null
        binarySearchTree(){
            root = nullptr;
            loc = nullptr;
            ploc = nullptr;
        }

        // Function to check if the tree is empty
        bool IsEmpty(){
            return root == nullptr;
        }

        // Search function to find a node with a specific value
        // 'loc' will store the node with the value if found, otherwise nullptr
        // 'ploc' will store the parent of the node being searched
        void Search(int value){
            loc = root;
            ploc = nullptr;
            // Traverse through the tree to find the node or reach a leaf
            while(loc != nullptr){
                if(loc->data == value){
                    return;  // Node with the value found
                }
                // Move to the right subtree if the value is greater
                else if(value > loc->data){
                    ploc = loc;  // Update the parent
                    loc = loc->RightChild;  // Move right
                }
                // Move to the left subtree if the value is smaller
                else{
                    ploc = loc;  // Update the parent
                    loc = loc->LeftChild;  // Move left
                }
            }
        }

        // Insert function that avoids duplicating nodes with the same value
        void InsertWithoutDuplication(int value){
            // Search for the value in the tree
            Search(value);

            // If the value already exists, do not insert
            if(loc != nullptr){
                cout << "Value already exists in the tree" << endl;
            }
            // If the tree is empty, create a new root node
            else if(ploc == nullptr){
                root = new BST_Node(value);
            }
            // Otherwise, insert the new node as a child of ploc
            else{
                loc = new BST_Node(value);  // Create a new node
                // Insert as right child if value is greater than the parent's data
                if(loc->data > ploc->data){
                    ploc->RightChild = loc;
                }
                // Insert as left child otherwise
                else{
                    ploc->LeftChild = loc;
                }
            }
        }
};

// Function to perform in-order traversal of the tree
// It prints the nodes in ascending order
void InOrderTraversal(BST_Node* root){
    if(root != nullptr){
        InOrderTraversal(root->LeftChild);  // Traverse left subtree
        cout << root->data << endl;  // Print the root's data
        InOrderTraversal(root->RightChild);  // Traverse right subtree
    }
}
