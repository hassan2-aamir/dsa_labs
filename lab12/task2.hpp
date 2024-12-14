#include <iostream>
using namespace std;

class directAddressing_withLinearProbing {
    public:
        int hashTable[100];

        directAddressing_withLinearProbing() {
            // Initialize hashTable to -1
            fill_n(hashTable, 100, -1);
        }

        void insertKeyValuePair(int value) {
            int key = value % 100; // Primary hash
            int originalKey = key; // Keep track of starting point for circular probing
            while (hashTable[key] != -1) { // Find the next available slot
                if (hashTable[key] == value) {
                    cout << "Value already exists at index " << key << endl;
                    return;
                }
                key = (key + 1) % 100; // Move to the next slot (circular probing)
                if (key == originalKey) {
                    cout << "Hash table is full, cannot insert value" << endl;
                    return;
                }
            }
            hashTable[key] = value;
            cout << "Value inserted successfully at index " << key << endl;
        }

        void searchValue(int value) {
            int key = value % 100; // Primary hash
            int originalKey = key; // Keep track of starting point for circular probing
            while (hashTable[key] != -1) { // Stop if an empty slot is encountered
                if (hashTable[key] == value) {
                    cout << "Value found at index: " << key << endl;
                    return;
                }
                key = (key + 1) % 100; // Move to the next slot
                if (key == originalKey) {
                    break; // We've come full circle
                }
            }
            cout << "Value does not exist" << endl;
        }

        void deleteValue(int value) {
            int key = value % 100; // Primary hash
            int originalKey = key; // Keep track of starting point for circular probing
            while (hashTable[key] != -1) { // Stop if an empty slot is encountered
                if (hashTable[key] == value) {
                    hashTable[key] = -1;
                    cout << "Value deleted successfully from index " << key << endl;
                    return;
                }
                key = (key + 1) % 100; // Move to the next slot
                if (key == originalKey) {
                    break; // We've come full circle
                }
            }
            cout << "No such value" << endl;
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
