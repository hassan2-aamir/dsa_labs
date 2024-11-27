#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm> // For std::sort
#include "sorts.hpp"
using namespace std;

// Generate a random array
int* generateArray(int size) {
    int* array = new int[size]; // Allocate memory for the array
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100 + 1; // Generate random numbers between 1 and 100
    }
    return array;
}

// Measure execution time
template <typename Func>
double measureExecutionTime(Func sortingFunction, int* array, int size) {
    int* tempArray = new int[size]; // Create a temporary copy of the array
    copy(array, array + size, tempArray); // Copy the array contents

    auto start = chrono::high_resolution_clock::now(); // Start timer
    sortingFunction(tempArray, size); // Execute the sorting function
    auto end = chrono::high_resolution_clock::now(); // Stop timer

    delete[] tempArray; // Free the memory used for the temporary copy

    chrono::duration<double> elapsed = end - start; // Calculate elapsed time
    return elapsed.count(); // Return time in seconds
}

int main() {
    srand(time(0)); // Seed random number generator

    int sizes[] = {100}; // Array sizes to test
    for (int size : sizes) {
        cout << "Array size: " << size << endl;

        int* array = generateArray(size); // Generate a random array of given size

        // Sort using STL::sort in ascending order
        int* sortedAsc = new int[size];
        copy(array, array + size, sortedAsc); // Copy the array
        sort(sortedAsc, sortedAsc + size);   // Sort in ascending order

        // Sort using STL::sort in descending order
        int* sortedDesc = new int[size];
        copy(array, array + size, sortedDesc); // Copy the array
        sort(sortedDesc, sortedDesc + size, greater<int>()); // Sort in descending order

        // Test sorting algorithms on ascending order
        cout << "Sorted (Ascending):" << endl;
        cout << "Bubble Sort: " << measureExecutionTime(Sorting::bubbleSort, sortedAsc, size) << " seconds" << endl;
        cout << "Selection Sort: " << measureExecutionTime(Sorting::selectionSort, sortedAsc, size) << " seconds" << endl;
        cout << "Insertion Sort: " << measureExecutionTime(Sorting::insertionSort, sortedAsc, size) << " seconds" << endl;
        cout << "Merge Sort: " << measureExecutionTime([](int* A, int N) { Sorting::mergeSort(A, 0, N - 1); }, sortedAsc, size) << " seconds" << endl;

        // Test sorting algorithms on descending order
        cout << "Sorted (Descending):" << endl;
        cout << "Bubble Sort: " << measureExecutionTime(Sorting::bubbleSort, sortedDesc, size) << " seconds" << endl;
        cout << "Selection Sort: " << measureExecutionTime(Sorting::selectionSort, sortedDesc, size) << " seconds" << endl;
        cout << "Insertion Sort: " << measureExecutionTime(Sorting::insertionSort, sortedDesc, size) << " seconds" << endl;
        cout << "Merge Sort: " << measureExecutionTime([](int* A, int N) { Sorting::mergeSort(A, 0, N - 1); }, sortedDesc, size) << " seconds" << endl;

        // Free the allocated memory
        delete[] array;
        delete[] sortedAsc;
        delete[] sortedDesc;

        cout << endl;
    }

    return 0; // End of program
}
