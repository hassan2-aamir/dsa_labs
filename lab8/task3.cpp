#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm> // For std::sort
#include "sorts.hpp"
using namespace std;


// Generate a random array
int* generateArray(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100 + 1;
    }
    return array;
}

// Measure execution time
template <typename Func>
double measureExecutionTime(Func sortingFunction, int* array, int size) {
    int* tempArray = new int[size];
    copy(array, array + size, tempArray);

    auto start = chrono::high_resolution_clock::now();
    sortingFunction(tempArray, size);
    auto end = chrono::high_resolution_clock::now();

    delete[] tempArray;

    chrono::duration<double> elapsed = end - start;
    return elapsed.count();
}

int main() {
    srand(time(0)); // Seed random number generator

    int sizes[] = {100};
    for (int size : sizes) {
        cout << "Array size: " << size << endl;

        int* array = generateArray(size);

        // Sort using STL::sort in ascending order
        int* sortedAsc = new int[size];
        copy(array, array + size, sortedAsc);
        sort(sortedAsc, sortedAsc + size);

        // Sort using STL::sort in descending order
        int* sortedDesc = new int[size];
        copy(array, array + size, sortedDesc);
        sort(sortedDesc, sortedDesc + size, greater<int>());

        cout << "Sorted (Ascending):" << endl;
        cout << "Bubble Sort: " << measureExecutionTime(Sorting::bubbleSort, sortedAsc, size) << " seconds" << endl;
        cout << "Selection Sort: " << measureExecutionTime(Sorting::selectionSort, sortedAsc, size) << " seconds" << endl;
        cout << "Insertion Sort: " << measureExecutionTime(Sorting::insertionSort, sortedAsc, size) << " seconds" << endl;
        cout << "Merge Sort: " << measureExecutionTime([](int* A, int N) { Sorting::mergeSort(A, 0, N - 1); }, sortedAsc, size) << " seconds" << endl;

        cout << "Sorted (Descending):" << endl;
        cout << "Bubble Sort: " << measureExecutionTime(Sorting::bubbleSort, sortedDesc, size) << " seconds" << endl;
        cout << "Selection Sort: " << measureExecutionTime(Sorting::selectionSort, sortedDesc, size) << " seconds" << endl;
        cout << "Insertion Sort: " << measureExecutionTime(Sorting::insertionSort, sortedDesc, size) << " seconds" << endl;
        cout << "Merge Sort: " << measureExecutionTime([](int* A, int N) { Sorting::mergeSort(A, 0, N - 1); }, sortedDesc, size) << " seconds" << endl;

        delete[] array;
        delete[] sortedAsc;
        delete[] sortedDesc;

        cout << endl;
    }

    return 0;
}
