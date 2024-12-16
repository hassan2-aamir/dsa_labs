#include <iostream>
#include <vector>

using namespace std;

class CuckooHash {
private:
    static const int TABLE_SIZE = 11;
    vector<int> table1;
    vector<int> table2;
    
    // Hash functions
    int hash1(int key) { return key % TABLE_SIZE; }
    int hash2(int key) { return (key / TABLE_SIZE) % TABLE_SIZE; }

public:
    CuckooHash() : table1(TABLE_SIZE, -1), table2(TABLE_SIZE, -1) {}

    bool addArea(int areaId) {
        if (exists(areaId)) return false;

        // Try to insert in table1 first
        for (int i = 0; i < TABLE_SIZE-1; i++) {
            int pos1 = hash1(areaId);
            if (table1[pos1] == -1) {
                table1[pos1] = areaId;
                return true;
            }

            // If collision occurs, move existing element to table2
            int temp = table1[pos1];
            table1[pos1] = areaId;
            areaId = temp;

            int pos2 = hash2(areaId);
            if (table2[pos2] == -1) {
                table2[pos2] = areaId;
                return true;
            }

            // If collision in table2, move back to table1
            temp = table2[pos2];
            table2[pos2] = areaId;
            areaId = temp;
        }
        
        // If we reach here, we need to rehash
        return false;
    }

    bool exists(int areaId) {
        int pos1 = hash1(areaId);
        int pos2 = hash2(areaId);
        return (table1[pos1] == areaId || table2[pos2] == areaId);
    }

    bool removeArea(int areaId) {
        int pos1 = hash1(areaId);
        int pos2 = hash2(areaId);
        
        if (table1[pos1] == areaId) {
            table1[pos1] = -1;
            return true;
        }
        if (table2[pos2] == areaId) {
            table2[pos2] = -1;
            return true;
        }
        return false;
    }
};

int main() {
    CuckooHash areaManager;
    
    // Test cases
    cout << "Adding area 301: " << (areaManager.addArea(301) ? "Success" : "Failed") << endl;
    cout << "Adding area 401: " << (areaManager.addArea(401) ? "Success" : "Failed") << endl;
    cout << "Area 301 exists: " << (areaManager.exists(301) ? "Yes" : "No") << endl;
    cout << "Area 501 exists: " << (areaManager.exists(501) ? "Yes" : "No") << endl;
    cout << "Removing area 301: " << (areaManager.removeArea(301) ? "Success" : "Failed") << endl;
    cout << "Area 301 exists: " << (areaManager.exists(301) ? "Yes" : "No") << endl;

    return 0;
}