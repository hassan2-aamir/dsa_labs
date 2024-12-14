#include <iostream>
#include <cmath>
using namespace std;

class directAddressing_withQuadraticProbing {
    public:
        int hashTable[100];

        directAddressing_withQuadraticProbing() {
            // Initialize hashTable with -1 values
            fill_n(hashTable, 100, -1);
        }

        void insertKeyValuePair(int value) {
            int key = value % 100;
            int i = 0;

            while (i < 100) { // Quadratic probing loop
                int newKey = (key + i * i) % 100; // Quadratic probing formula
                if (hashTable[newKey] == -1) {
                    hashTable[newKey] = value;
                    cout << "Value inserted successfully at index " << newKey << endl;
                    return;
                }
                i++;
            }
            cout << "Hash table is full. Cannot insert value." << endl;
        }

        void searchValue(int value) {
            int key = value % 100;
            int i = 0;

            while (i < 100) { // Quadratic probing loop
                int newKey = (key + i * i) % 100;
                if (hashTable[newKey] == value) {
                    cout << "Value found at index: " << newKey << endl;
                    return;
                } else if (hashTable[newKey] == -1) {
                    break; // Stop searching if an empty slot is encountered
                }
                i++;
            }
            cout << "Value does not exist" << endl;
        }

        void deleteValue(int value) {
            int key = value % 100;
            int i = 0;

            while (i < 100) { // Quadratic probing loop
                int newKey = (key + i * i) % 100;
                if (hashTable[newKey] == value) {
                    hashTable[newKey] = -1;
                    cout << "Value deleted successfully from index " << newKey << endl;
                    return;
                } else if (hashTable[newKey] == -1) {
                    break; // Stop searching if an empty slot is encountered
                }
                i++;
            }
            cout << "No such value exists to delete." << endl;
        }

        void displayHashTable() {
            cout << "Hash Table Contents: " << endl;
            for (int i = 0; i < 100; ++i) {
                if (hashTable[i] != -1) {
                    cout << "Key: " << i << " -> Value: " << hashTable[i] << endl;
                }
            }
        }
};
