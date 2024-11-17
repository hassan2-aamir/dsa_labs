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
                    swap(A[j], A[j + 1]);
                }
            }
        }
    }

    // Selection Sort
    static void selectionSort(int* A, int N) {
        for (int i = N - 1; i > 0; i--) {
            int maxIndex = i;
            for (int j = 0; j < i; j++) {
                if (A[j] > A[maxIndex])
                    maxIndex = j;
            }
            swap(A[i], A[maxIndex]);
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

    // Merge Sort
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

    static void mergeSort(int* A, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            mergeSort(A, start, mid);
            mergeSort(A, mid + 1, end);
            merge(A, start, mid, end);
        }
    }
};

// Function to generate an array with random numbers
int* generateArray(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100 + 1; // Random numbers between 1 and 100
    }
    return array;
}

// Measure execution time
template <typename Func>
double measureExecutionTime(Func sortingFunction, int* array, int size) {
    // Create a copy of the array to sort
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

    int sizes[] = {100, 1000, 10000, 100000, 1000000};
    for (int size : sizes) {
        cout << "Array size: " << size << endl;

        int* array = generateArray(size);

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

    return 0;
}
