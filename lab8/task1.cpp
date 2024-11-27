#include <iostream>
#include "sorts.hpp" // Include header file for sorting algorithms
using namespace std;

int main() {
    // Define an array for testing sorting algorithms
    int A[] = {1, 3, 5, 7, 2, 4, 6};

    // Display the original array
    cout << "The array is: ";
    for (int i = 0; i < 7; i++) 
        cout << A[i] << " ";
    cout << "\n";

    // Apply Bubble Sort
    Sorting::bubbleSort(A, 7);
    cout << "The array after bubble sort is: ";
    for (int i = 0; i < 7; i++) 
        cout << A[i] << " ";
    cout << "\n";

    // Define another array to test Selection Sort
    int B[] = {1, 3, 5, 7, 2, 4, 6};

    // Apply Selection Sort
    Sorting::selectionSort(B, 7);
    cout << "The array after selection sort is: ";
    for (int i = 0; i < 7; i++) 
        cout << B[i] << " ";
    cout << "\n";

    // Define another array to test Insertion Sort
    int C[] = {1, 3, 5, 7, 2, 4, 6};

    // Apply Insertion Sort
    Sorting::insertionSort(C, 7);
    cout << "The array after insertion sort is: ";
    for (int i = 0; i < 7; i++) 
        cout << C[i] << " ";
    cout << "\n";

    // Define another array to test Merge Sort
    int D[] = {1, 3, 5, 7, 2, 4, 6};

    // Apply Merge Sort
    Sorting::mergeSort(D, 0, 6);
    cout << "The array after merge sort is: ";
    for (int i = 0; i < 7; i++) 
        cout << D[i] << " ";
    cout << "\n";

    return 0; // End of program
}
