#include <iostream>
#include <vector>
#include "heap.hpp"
using namespace std;

int main() {
    MinHeap heap;

    // Test push
    heap.push(10);
    heap.push(15);
    heap.push(20);
    heap.push(17);
    heap.push(8);

    cout << "Heap after pushes:" << endl;
    heap.print();

    // Test top
    cout << "Top element: " << heap.top() << endl;

    // Test pop
    heap.pop();
    cout << "Heap after pop:" << endl;
    heap.print();

    // Test size
    cout << "Heap size: " << heap.size() << endl;

    // Test height
    cout << "Heap height: " << heap.height() << endl;

    // Test buildHeap
    vector<int> arr = {3, 9, 2, 1, 4, 5};
    heap.buildHeap(arr);
    cout << "Heap after buildHeap:" << endl;
    heap.print();

    // Test isEmpty
    cout << "Is heap empty? " << (heap.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
