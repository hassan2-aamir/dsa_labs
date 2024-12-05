#include <iostream>
#include <vector>
#include "heap.hpp"
using namespace std;

// Example Usage
int main() {
    MinHeap minHeap;

    // Insert nodes
    minHeap.push(new HuffmanNode('a', 5));
    minHeap.push(new HuffmanNode('b', 9));
    minHeap.push(new HuffmanNode('c', 12));
    minHeap.push(new HuffmanNode('d', 13));
    minHeap.push(new HuffmanNode('e', 16));
    minHeap.push(new HuffmanNode('f', 45));

    // Print heap
    cout << "Min Heap:" << endl;
    minHeap.print();

    // Extract elements
    while (!minHeap.isEmpty()) {
        HuffmanNode* node = minHeap.top();
        cout << "Extracted: (" << node->character << ", " << node->frequency << ")" << endl;
        minHeap.pop();
    }

    return 0;
}
