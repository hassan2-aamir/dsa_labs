#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // Helper functions
    int parent(int i) { 
        return (int) i  / 2; 
    }
    int leftChild(int i) { 
        return 2 * i + 1; 
    }
    int rightChild(int i) { 
        return 2 * i + 2; 
        }

    // Heapify down to maintain min-heap property when 
    void heapifyDown(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int smallest = i;

        if (left < heap.size() and heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() and heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // Heapify up to maintain min-heap property
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // Returns the minimum element without removing it
    int top() {
        if (isEmpty()) {
            cout<< "Heap is empty";
        }
        return heap[0];
    }

    // Removes the minimum element
    void pop() {
        if (isEmpty()) {
            cout<<"Heap is empty"<<endl;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Inserts a new element into the heap
    void push(int num) {
        heap.push_back(num);
        heapifyUp(heap.size() - 1);
    }

    // Checks if the heap is empty
    bool isEmpty() {
        return heap.empty();
    }

    // Returns the number of elements in the heap
    int size() {
        return heap.size();
    }

    // Returns the height of the heap
    int height() {
        return isEmpty() ? 0 : ceil(log2(heap.size() + 1)) - 1;
    }

    // Builds a heap from an array
    void buildHeap( vector<int>& array) {
        heap = array;
        for (int i = parent(heap.size() - 1); i >= 0; i--) {
            heapifyDown(i);
        }
    }

    // Prints the heap as a tree
    void print() {
        int level = 0, count = 0, levelSize = 1;
        for (int i = 0; i < heap.size(); ++i) {
            if (count == 0) {
                cout << "Level " << level++ << ": ";
                levelSize *= 2;
                count = levelSize / 2;
            }
            cout << heap[i] << " ";
            count--;
            if (count == 0) cout << endl;
        }
        cout << endl;
    }
};

