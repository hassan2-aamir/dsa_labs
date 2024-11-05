#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> elements;  // Vector to store stack elements

public:
    // Method to push an element onto the stack
    void push(int value) {
        elements.push_back(value);  // Add element to the end of the vector
        cout << value << " pushed onto stack." << endl;
    }

    // Method to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        int poppedValue = elements.back();  // Get the last element
        elements.pop_back();  // Remove the last element
        cout << poppedValue << " popped from stack." << endl;
    }

    // Method to peek at the top element of the stack
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1;  // Return -1 or some error value
        }
        return elements.back();  // Return the last element
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return elements.empty();  // Return true if no elements are in the stack
    }

    // Method to get the size of the stack
    int size() {
        return elements.size();  // Return the number of elements in the stack
    }
};

class Node{
    int val;
    Node* left;
    Node* right
};

void inOIter(Node* root){
    Node* curr=root;
    
}