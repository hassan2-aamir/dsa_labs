#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev = nullptr;
        Node* next = nullptr;
};

Node* reverseDoubly(Node* root){
    Node* curr =root, *temp;
    while(curr!= nullptr){
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev=temp;

        if(temp==nullptr) root=curr;
        curr=temp;
    }
    

    return root;

}

void displayList(Node* root){   
    Node* curr=root;
    while (curr!=nullptr){
        cout<<curr->data<<endl;
        curr=curr->next;
    }
}



int main() {
    // Create nodes
    Node* head = new Node();
    head->data = 1;

    Node* second = new Node();
    second->data = 2;

    Node* third = new Node();
    third->data = 3;

    // Link nodes to form the list: 1 <-> 2 <-> 3
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // Display original list
    cout << "Original List: ";
    displayList(head);

    // Reverse the list
    head = reverseDoubly(head);

    // Display reversed list
    cout << "Reversed List: ";
    displayList(head);

    // Free allocated memory
    delete first;
    delete second;
    delete head;

    return 0;
}