#include <iostream>
#include <vector>
using namespace std;

class CuckooHash {
private:
    static const int TABLE_SIZE = 101;  // Prime number for better distribution
    vector<int> table1;
    vector<int> table2;
    static const int MAX_LOOP = 100;    // Prevent infinite loops

    // Hash functions
    int hash1(int key) const {
        return key % TABLE_SIZE;
    }

    int hash2(int key) const {
        return (key / TABLE_SIZE) % TABLE_SIZE;
    }

public:
    CuckooHash() : table1(TABLE_SIZE, -1), table2(TABLE_SIZE, -1) {}

    /*
    Function to insert value in hash table
    */
    bool insert(int key) {
        if (exists(key)) return false;

        for (int i = 0; i < MAX_LOOP; i++) {
            // Try to insert in table1
            int pos1 = hash1(key);
            if (table1[pos1] == -1) {
                table1[pos1] = key;
                return true;
            }

            // Swap with table1 and try table2
            int temp = table1[pos1];
            table1[pos1] = key;
            key = temp;

            int pos2 = hash2(key);
            if (table2[pos2] == -1) {
                table2[pos2] = key;
                return true;
            }

            // Swap with table2 and continue
            temp = table1[pos2];
            table1[pos2] = key;
            key = temp;
        }
        // If we reach here, we need to rehash
        return false;
    }

    /* 
    function to check if key exists in tables
    */
    bool exists(int key) const {
        int pos1 = hash1(key);
        int pos2 = hash2(key);
        return (table1[pos1] == key || table2[pos2] == key);
    }

    /*
    Fnction to remove value from hash table
    */
    bool remove(int key) {
        int pos1 = hash1(key);
        int pos2 = hash2(key);
        
        if (table1[pos1] == key) {
            table1[pos1] = -1;
            return true;
        }
        if (table2[pos2] == key) {
            table2[pos2] = -1;
            return true;
        }
        return false;
    }
};

int main() {
    CuckooHash hash;
    
    // Test cases
    hash.insert(20101);
    hash.insert(20202);
    
    cout << "20101 exists: " << (hash.exists(20101) ? "true" : "false") << endl;
    cout << "20303 exists: " << (hash.exists(20303) ? "true" : "false") << endl;
    
    hash.remove(20101);
    cout << "After removing 20101, exists: " << (hash.exists(20101) ? "true" : "false") << endl;

    return 0;
}