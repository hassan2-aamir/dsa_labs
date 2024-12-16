#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
using namespace std;

/*
Driver class
*/
class DriverInfo {
    public:
        string name;
        string vehicleType;
        double rating;

    
        DriverInfo(string name, string vehicleType, double rating)
            : name(name), vehicleType(vehicleType), rating(rating) {}
};



/*
HashMap class to store and retrieve driver details. We have used linear probing for collision
 */
class DriverHashMap {
private:
    static const int TABLE_SIZE = 100; // Initial table size
    list<pair<int, DriverInfo>> table[TABLE_SIZE];

    /*
    Hash function to map driver ID to index.
     */
    int hashFunction(int driverID) const {
        return driverID % TABLE_SIZE;
    }

public:
    /*
    Add a new driver to the system.
     */
    void addDriver(int driverID, const DriverInfo& driverInfo) {
        int index = hashFunction(driverID);
        for (auto& pair : table[index]) {
            if (pair.first == driverID) {
                // Update existing driver info
                pair.second = driverInfo;
                return;
            }
        }
        // Insert new driver info
        table[index].emplace_back(driverID, driverInfo);
    }

    /*
    Retrieve driver details by ID.
     */
    DriverInfo getDriver(int driverID) {
        int index = hashFunction(driverID);
        for (const auto& pair : table[index]) {
            if (pair.first == driverID) {
                return pair.second;
            }
        }
        throw out_of_range("Driver not found");
    }

    /*
    Remove a driver from the system.
     */
    bool removeDriver(int driverID) {
        int index = hashFunction(driverID);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == driverID) {
                table[index].erase(it);
                return true;
            }
        }
        return false;
    }
};

int main() {
    DriverHashMap driverMap;

    // Add drivers
    driverMap.addDriver(101, DriverInfo("Alice", "Sedan", 4.5));
    driverMap.addDriver(102, DriverInfo("Bob", "SUV", 4.8));

    // Retrieve driver details
    try {
        DriverInfo driverInfo = driverMap.getDriver(101);
        cout << "Name: " << driverInfo.name << endl;
        cout << "Vehicle Type: " << driverInfo.vehicleType << endl;
        cout << "Rating: " << driverInfo.rating << endl;

        driverInfo = driverMap.getDriver(102);
        cout << endl << "Name: " << driverInfo.name << endl;
        cout << "Vehicle Type: " << driverInfo.vehicleType << endl;
        cout << "Rating: " << driverInfo.rating << endl<<endl;

    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    // Remove driver
    driverMap.removeDriver(101);

    // Attempt to retrieve removed driver
    try {
        driverMap.getDriver(101);
    } catch (const exception& e) {
        cout<<"When attempting to remove already removed driver"<<endl;
        cerr << e.what() << endl; // Output: Driver not found
    }

    return 0;
}
