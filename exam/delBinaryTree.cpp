#include <iostream>
using namespace std;

class Node {
public:
    int val;        // Value of the node
    Node* left;     // Pointer to left child
    Node* right;    // Pointer to right child

    // Constructor to initialize a node with a value
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

Node* predecessor(Node* node){
    if(node->left==nullptr) return nullptr;
    else{
        Node* curr=node->left;
        while(curr->right != nullptr){
            curr=curr->right;
        }
        return curr;
    }
}
Node* delNode(Node* node){
    if (node == nullptr) return nullptr;

    if(node->left ==nullptr and node->right ==nullptr){
        delete node;
        return nullptr;
    }

    if (node->left == nullptr and node->right!= nullptr){
        Node* temp = node->right;
        delete node;
        return temp;
    }

    if (node->left != nullptr and node->right == nullptr){
        Node* temp = node->left;
        delete node;
        return temp;
    }

    if(node->left != nullptr && node->right != nullptr){
        Node* pred = predecessor(node);  // Find the predecessor

        // Find the parent of predecessor to update its child after deletion
        Node* parent = node->left;
        if (parent->right == nullptr) {  // If the predecessor is node->left itself
            node->val = pred->val;
            node->left = delNode(node->left);  // Update node's left pointer after deletion
        } else {
            while (parent->right != pred) {
                parent = parent->right;
            }
            node->val = pred->val;
            parent->right = delNode(pred);  // Update parent's right pointer after deletion
        }
        return node;
    }
    return node;
}

// Function to create a sample binary tree
Node* createSampleTree() {
    // Create root node
    Node* root = new Node(10);
    
    // Manually create other nodes
    root->left = new Node(5);
    root->right = new Node(15);
    
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    
    root->right->left = new Node(13);
    root->right->right = new Node(17);

    return root;
}

// Function for In-Order Traversal
void inOrderTraversal(Node* root) {
    if (root == nullptr) return;
    
    inOrderTraversal(root->left);          // Traverse left subtree
    cout << root->val << " ";              // Print node value
    inOrderTraversal(root->right);         // Traverse right subtree
}

int main() {
    Node* root = createSampleTree();  // Create the binary tree

    cout <<endl<< "In-Order Traversal of the binary tree: ";
    inOrderTraversal(root);  // Display tree contents in In-Order Traversal
    cout << endl;

    delNode(root->left);

    cout <<endl<< "In-Order Traversal of the binary tree: ";
    inOrderTraversal(root);  // Display tree contents in In-Order Traversal
    cout << endl;


    return 0;  // End of the program
}



