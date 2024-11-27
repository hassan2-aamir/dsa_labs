#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

// Sorting class with static methods
class Sorting {
public:
    // Bubble Sort
    static void bubbleSort(int* A, int N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - i - 1; j++) {
                if (A[j] > A[j + 1]) {
                    swap(A[j], A[j + 1]); // Swap adjacent elements if out of order
                }
            }
        }
    }

    // Selection Sort
    static void selectionSort(int* A, int N) {
        for (int i = N - 1; i > 0; i--) {
            int maxIndex = i; // Assume the last element is the largest
            for (int j = 0; j < i; j++) {
                if (A[j] > A[maxIndex])
                    maxIndex = j; // Update index of the largest element
            }
            swap(A[i], A[maxIndex]); // Move the largest element to its correct position
        }
    }

    // Insertion Sort
    static void insertionSort(int* A, int N) {
        for (int i = 1; i < N; i++) {
            int key = A[i]; // Element to be inserted
            int j = i - 1;
            while (j >= 0 && A[j] > key) {
                A[j + 1] = A[j]; // Shift larger elements one position to the right
                j--;
            }
            A[j + 1] = key; // Insert the key at the correct position
        }
    }

    // Merge Sort
    static void merge(int* A, int start, int mid, int end) {
        int leftSize = mid - start + 1; // Size of the left sub-array
        int rightSize = end - mid;     // Size of the right sub-array

        int* left = new int[leftSize]; // Allocate memory for the left sub-array
        int* right = new int[rightSize]; // Allocate memory for the right sub-array

        // Copy data into the left and right sub-arrays
        for (int i = 0; i < leftSize; i++)
            left[i] = A[start + i];
        for (int i = 0; i < rightSize; i++)
            right[i] = A[mid + 1 + i];

        int i = 0, j = 0, k = start; // Initialize pointers for merging

        // Merge the two sub-arrays back into the original array
        while (i < leftSize && j < rightSize) {
            if (left[i] <= right[j]) {
                A[k] = left[i];
                i++;
            } else {
                A[k] = right[j];
                j++;
            }
            k++;
        }

        // Copy any remaining elements of the left sub-array
        while (i < leftSize) {
            A[k] = left[i];
            i++;
            k++;
        }

        // Copy any remaining elements of the right sub-array
        while (j < rightSize) {
            A[k] = right[j];
            j++;
            k++;
        }

        // Free allocated memory for temporary sub-arrays
        delete[] left;
        delete[] right;
    }

    static void mergeSort(int* A, int start, int end) {
        if (start < end) { // Check if the array can be divided further
            int mid = start + (end - start) / 2; // Calculate the midpoint
            mergeSort(A, start, mid);           // Recursively sort the left half
            mergeSort(A, mid + 1, end);         // Recursively sort the right half
            merge(A, start, mid, end);          // Merge the two sorted halves
        }
    }
};

// Function to generate an array with random numbers
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
    // Create a copy of the array to sort
    int* tempArray = new int[size];
    copy(array, array + size, tempArray); // Copy the array contents

    auto start = chrono::high_resolution_clock::now(); // Start timer
    sortingFunction(tempArray, size); // Execute the sorting function
    auto end = chrono::high_resolution_clock::now(); // Stop timer

    delete[] tempArray; // Free memory used for the copy

    chrono::duration<double> elapsed = end - start; // Calculate elapsed time
    return elapsed.count(); // Return time in seconds
}

int main() {
    srand(time(0)); // Seed random number generator

    int sizes[] = {100, 1000, 10000, 100000, 1000000}; // Array sizes to test
    for (int size : sizes) {
        cout << "Array size: " << size << endl;

        int* array = generateArray(size); // Generate random array of given size

        // Bubble Sort
        if (size <= 100000) { // Bubble Sort is too slow for larger arrays
            cout << "Bubble Sort: "
                 << measureExecutionTime(Sorting::bubbleSort, array, size) << " seconds" << endl;
        } else {
            cout << "Bubble Sort: Skipped (too slow)" << endl;
        }

        // Selection Sort
        if (size <= 100000) { // Selection Sort is too slow for larger arrays
            cout << "Selection Sort: "
                 << measureExecutionTime(Sorting::selectionSort, array, size) << " seconds" << endl;
        } else {
            cout << "Selection Sort: Skipped (too slow)" << endl;
        }

        // Insertion Sort
        if (size <= 100000) { // Insertion Sort is too slow for larger arrays
            cout << "Insertion Sort: "
                 << measureExecutionTime(Sorting::insertionSort, array, size) << " seconds" << endl;
        } else {
            cout << "Insertion Sort: Skipped (too slow)" << endl;
        }

        // Merge Sort
        cout << "Merge Sort: "
             << measureExecutionTime([](int* A, int N) { Sorting::mergeSort(A, 0, N - 1); }, array, size)
             << " seconds" << endl;

        delete[] array; // Free the allocated memory
        cout << endl;
    }

    return 0; // End of program
}
