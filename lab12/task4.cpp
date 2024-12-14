#include <iostream>
#include "task4.hpp"
using namespace std;

int main() {
    DirectAddressingWithDoubleHashing hashTable;

    int choice, value;

    while (true) {
        cout << "\n--- Direct Addressing Hash Table with Double Hashing Menu ---" << endl;
        cout << "1. Insert Value" << endl;
        cout << "2. Search Value" << endl;
        cout << "3. Delete Value" << endl;
        cout << "4. Display Hash Table" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Insert
                cout << "Enter value to insert: ";
                cin >> value;
                hashTable.insertKeyValuePair(value);
                break;

            case 2: // Search
                cout << "Enter value to search: ";
                cin >> value;
                hashTable.searchValue(value);
                break;

            case 3: // Delete
                cout << "Enter value to delete: ";
                cin >> value;
                hashTable.deleteValue(value);
                break;

            case 4: // Display
                hashTable.displayHashTable();
                break;

            case 5: // Exit
                cout << "Exiting program. Goodbye!" << endl;
                return 0;

            default: // Invalid choice
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
