#include <iostream>
using namespace std;

class Sorting {
public:
    // Bubble Sort
    static void bubbleSort(int* A, int N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - i - 1; j++) { // Fixed loop condition
                if (A[j] > A[j + 1]) {
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
        }
    }

    // Selection Sort
    static void selectionSort(int* A, int N) {
        for (int i = N - 1; i > 0; i--) {
            int max = i;
            for (int j = 0; j < i; j++) {
                if (A[j] > A[max])
                    max = j;
            }
            int temp = A[i];
            A[i] = A[max];
            A[max] = temp;
        }
    }

    // Insertion Sort
    static void insertionSort(int* A, int N) {
        for (int i = 1; i < N; i++) {
            int key = A[i];
            int j = i - 1;
            while (j >= 0 && A[j] > key) {
                A[j + 1] = A[j];
                j--;
            }
            A[j + 1] = key;
        }
    }

    // Merge function for Merge Sort
    static void merge(int* A, int start, int mid, int end) {
        int leftSize = mid - start + 1;
        int rightSize = end - mid;

        int* left = new int[leftSize];
        int* right = new int[rightSize];

        for (int i = 0; i < leftSize; i++)
            left[i] = A[start + i];
        for (int i = 0; i < rightSize; i++)
            right[i] = A[mid + 1 + i];

        int i = 0, j = 0, k = start;

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

        while (i < leftSize) {
            A[k] = left[i];
            i++;
            k++;
        }

        while (j < rightSize) {
            A[k] = right[j];
            j++;
            k++;
        }

        delete[] left;
        delete[] right;
    }

    // Merge Sort
    static void mergeSort(int* A, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            mergeSort(A, start, mid);
            mergeSort(A, mid + 1, end);
            merge(A, start, mid, end);
        }
    }
};

