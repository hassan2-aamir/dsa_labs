#include <iostream>
using namespace std;

class DirectAddressingWithDoubleHashing {
public:
    int hashTable[100];

    DirectAddressingWithDoubleHashing() {
        fill_n(hashTable, 100, -1); // Initialize all slots to -1
    }

    // Primary hash function
    int primaryHash(int value) {
        return value % 100;
    }

    // Secondary hash function for double hashing
    int secondaryHash(int value) {
        return 1 + (value % (100 - 1)); // Must not return 0
    }

    void insertKeyValuePair(int value) {
        int key = primaryHash(value);

        if (hashTable[key] == -1) {
            hashTable[key] = value;
            cout << "Value inserted successfully at index: " << key << endl;
        } else {
            // Collision resolution using double hashing
            cout << "Collision detected. Resolving using double hashing..." << endl;
            int stepSize = secondaryHash(value);
            int originalKey = key;

            while (hashTable[key] != -1) {
                key = (key + stepSize) % 100;
                if (key == originalKey) {
                    cout << "Hash table is full. Cannot insert value." << endl;
                    return;
                }
            }

            hashTable[key] = value;
            cout << "Value inserted successfully at index: " << key << endl;
        }
    }

    void searchValue(int value) {
        int key = primaryHash(value);
        int stepSize = secondaryHash(value);
        int originalKey = key;

        while (hashTable[key] != -1) {
            if (hashTable[key] == value) {
                cout << "Value found at index: " << key << endl;
                return;
            }
            key = (key + stepSize) % 100;
            if (key == originalKey) break; // If we loop back to the start, stop
        }

        cout << "Value does not exist" << endl;
    }

    void deleteValue(int value) {
        int key = primaryHash(value);
        int stepSize = secondaryHash(value);
        int originalKey = key;

        while (hashTable[key] != -1) {
            if (hashTable[key] == value) {
                hashTable[key] = -1;
                cout << "Value deleted successfully from index: " << key << endl;
                return;
            }
            key = (key + stepSize) % 100;
            if (key == originalKey) break; // If we loop back to the start, stop
        }

        cout << "No such value exists to delete" << endl;
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
