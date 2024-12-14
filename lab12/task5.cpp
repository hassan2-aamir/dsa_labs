#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include "task4.hpp"
using namespace std;
using namespace chrono;

// Include the hashing class definitions here (Direct Addressing, Linear Probing, Quadratic Probing, Double Hashing)

// Function to generate random keys
vector<int> generateRandomKeys(int count, int maxValue) {
    vector<int> keys;
    for (int i = 0; i < count; ++i) {
        keys.push_back(rand() % maxValue);
    }
    return keys;
}

// Function to measure lookup time
template <typename HashingClass>
long long measureLookupTime(HashingClass& hashTable, vector<int>& keys) {
    auto start = high_resolution_clock::now();
    for (int key : keys) {
        hashTable.searchValue(key); // Perform lookup
    }
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

int main() {
    srand(time(0)); // Seed random number generator

    // Generate 50 random keys for insertion
    vector<int> insertKeys = generateRandomKeys(50, 1000);

    // Initialize hash tables
    directAddressing directHashTable;
    directAddressing_withLinearProbing linearHashTable;
    directAddressing_withQuadraticProbing quadraticHashTable;
    DirectAddressingWithDoubleHashing doubleHashTable;

    // Insert keys into each hash table
    for (int key : insertKeys) {
        directHashTable.insertKeyValuePair(key);
        linearHashTable.insertKeyValuePair(key);
        quadraticHashTable.insertKeyValuePair(key);
        doubleHashTable.insertKeyValuePair(key);
    }

    // Measure lookup times
    long long directTime = measureLookupTime(directHashTable, insertKeys);
    long long linearTime = measureLookupTime(linearHashTable, insertKeys);
    long long quadraticTime = measureLookupTime(quadraticHashTable,insertKeys);
    long long doubleTime = measureLookupTime(doubleHashTable, insertKeys);

    // Print results
    cout << "Lookup Time for 50 keys(in microseconds):" << endl;
    cout << "Direct Addressing: " << directTime << " µs" << endl;
    cout << "Linear Probing: " << linearTime << " µs" << endl;
    cout << "Quadratic Probing: " << quadraticTime << " µs" << endl;
    cout << "Double Hashing: " << doubleTime << " µs" << endl;

    return 0;
}
