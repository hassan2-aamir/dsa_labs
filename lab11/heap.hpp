#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class HuffmanNode {
public:
    char character;       // The character
    int frequency;        // Frequency of the character
    HuffmanNode* left;    // Pointer to the left child
    HuffmanNode* right;   // Pointer to the right child

    // Constructor
    HuffmanNode(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}
};

class MinHeap {
private:
    vector<HuffmanNode*> heap;

    // Helper functions
    int parent(int i) { 
        return (i - 1) / 2; 
    }
    int leftChild(int i) { 
        return 2 * i + 1; 
    }
    int rightChild(int i) { 
        return 2 * i + 2; 
    }

    // Heapify down
    void heapifyDown(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int smallest = i;

        if (left < heap.size() && heap[left]->frequency < heap[smallest]->frequency)
            smallest = left;
        if (right < heap.size() && heap[right]->frequency < heap[smallest]->frequency)
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // Heapify up
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)]->frequency > heap[i]->frequency) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // Get the root node (minimum element)
    HuffmanNode* top() {
        if (isEmpty()) {
            cout << "Heap is empty" << endl;
            return nullptr;
        }
        return heap[0];
    }

    // Remove the root node
    void pop() {
        if (isEmpty()) {
            cout << "Heap is empty" << endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Insert a new node
    void push(HuffmanNode* node) {
        heap.push_back(node);
        heapifyUp(heap.size() - 1);
    }

    // Check if the heap is empty
    bool isEmpty() {
        return heap.empty();
    }

    // Get the size of the heap
    int size() {
        return heap.size();
    }

    // Print the heap as a tree
    void print() {
        for (HuffmanNode* node : heap) {
            cout << "(" << node->character << ", " << node->frequency << ") ";
        }
        cout << endl;
    }
};

