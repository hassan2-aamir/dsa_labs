#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = -1;
        next = nullptr;
    }
};

Node* middle(Node* start, Node* last) {
    if (start == nullptr) return nullptr;
    
    Node* slow = start;
    Node* fast = start->next;

    while (fast != last && fast != nullptr && fast->next != last) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* binarySearch(int val, Node* start, Node* last) {
    // Base cases
    if (start == nullptr) return nullptr;
    if (start == last) {
        if (start->data == val) return start;
        return nullptr;
    }

    Node* mid = middle(start, last);
    if (mid == nullptr) return nullptr;

    if (mid->data == val) 
        return mid;
    
    if (mid->data > val)
        return binarySearch(val, start, mid);
    
    return binarySearch(val, mid->next, last);
}

int main() {
    Node *first = new Node(), *second = new Node(), *third = new Node(), 
         *fourth = new Node(), *fifth = new Node();

    first->data = 1; second->data = 2; third->data = 3; 
    fourth->data = 4; fifth->data = 5;

    first->next = second; second->next = third; 
    third->next = fourth; fourth->next = fifth;

    Node* result = binarySearch(4, first, nullptr);
    if (result)
        cout << result->data;
    else
        cout << "Value not found";

    // Clean up memory
    delete first;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}