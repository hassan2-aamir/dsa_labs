#include <iostream>
using namespace std;

class Sorting {
public:
    // Bubble Sort
    static void bubbleSort(int* A, int N) {
        // Iterate over the array
        for (int i = 0; i < N; i++) {
            // Traverse the unsorted part of the array
            for (int j = 0; j < N - i - 1; j++) { // Exclude already sorted elements
                if (A[j] > A[j + 1]) { // Swap if elements are out of order
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
        }
    }

    // Selection Sort
    static void selectionSort(int* A, int N) {
        // Iterate backwards over the array
        for (int i = N - 1; i > 0; i--) {
            int max = i; // Assume the last element is the largest
            // Find the largest element in the unsorted portion
            for (int j = 0; j < i; j++) {
                if (A[j] > A[max]) // Update index of the largest element
                    max = j;
            }
            // Swap the largest element to its correct position
            int temp = A[i];
            A[i] = A[max];
            A[max] = temp;
        }
    }

    // Insertion Sort
    static void insertionSort(int* A, int N) {
        // Iterate over the array starting from the second element
        for (int i = 1; i < N; i++) {
            int key = A[i]; // Element to be inserted
            int j = i - 1;
            // Shift larger elements one position to the right
            while (j >= 0 && A[j] > key) {
                A[j + 1] = A[j];
                j--;
            }
            A[j + 1] = key; // Insert the key at the correct position
        }
    }

    // Merge function for Merge Sort
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

    // Merge Sort
    static void mergeSort(int* A, int start, int end) {
        if (start < end) { // Check if the array can be divided further
            int mid = start + (end - start) / 2; // Calculate the midpoint
            mergeSort(A, start, mid);           // Recursively sort the left half
            mergeSort(A, mid + 1, end);         // Recursively sort the right half
            merge(A, start, mid, end);          // Merge the two sorted halves
        }
    }
};
