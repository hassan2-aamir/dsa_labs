#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "rideAndUser.hpp"
using namespace std;



class DriverList : public UserList {
private:
    // Override load and save with driver-specific filenames
    void loadFromFile(){
        UserList::loadFromFileHelper("drivers.txt");  // Load data specific to drivers
    }

    void saveToFile() {
        UserList::saveToFileHelper("drivers.txt");  // Save data specific to drivers
    }



public:
    DriverList() {
        loadFromFile();
    }

    // Now just use the inherited methods from UserList
    bool driverExists(const string& username) {
        return userExists(username); // Access the method from UserList
    }

    // Add a ride to the user's history
    void addRide(const string& username, const string& startLocation, const string& endLocation, double fare, bool calledFromLoadFile=false) override {
        User* userNode = findUser(username);
        if (!userNode) {
            cout << "Error: User not found.\n";
            return;
        }

        userNode->rideHistory.addRide(startLocation, endLocation, fare);
        saveToFile();
        if(!calledFromLoadFile){
            cout << "Ride added successfully!\n";
        }
    }

    // Destructor to free memory
    ~DriverList() {
        // Cleanup handled by the UserList destructor
    }
};



int main() {
    DriverList driverList;
    bool loggedIn = false; // Tracks if a driver is logged in
    string currentDriver; // Stores the username of the logged-in driver
    int choice;

    do {
        if (!loggedIn) {
            // Main menu for signup/login
            cout << "\n1. Signup Driver\n2. Login Driver\n3. Exit\nEnter your choice: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

            if (choice == 1) {
                string username, password;
                cout << "Enter username: ";
                getline(cin, username);
                cout << "Enter password: ";
                getline(cin, password);
                driverList.signup(username, password);
            } else if (choice == 2) {
                string username, password;
                cout << "Enter username: ";
                getline(cin, username);
                cout << "Enter password: ";
                getline(cin, password);
                if (driverList.login(username, password)) {
                    loggedIn = true;
                    currentDriver = username; // Store the logged-in driver's username
                }
            } else if (choice == 3) {
                cout << "Exiting program. Goodbye!\n";
                break; // Exit the loop and program
            } else {
                cout << "Invalid choice. Try again.\n";
            }
        } else {
            // Menu for logged-in driver
            cout << "\n1. Add Ride\n2. Display Ride History\n3. Logout\nEnter your choice: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

            if (choice == 1) {
                string startLocation, endLocation;
                double fare;
                cout << "Enter start location: ";
                getline(cin, startLocation);
                cout << "Enter end location: ";
                getline(cin, endLocation);
                cout << "Enter fare: ";
                cin >> fare;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                driverList.addRide(currentDriver, startLocation, endLocation, fare);
            } else if (choice == 2) {
                driverList.displayRideHistory(currentDriver);
            } else if (choice == 3) {
                loggedIn = false; // Log out the driver
                currentDriver = ""; // Clear the current driver
                cout << "You have been logged out. Returning to the main menu...\n";
            } else {
                cout << "Invalid choice. Try again.\n";
            }
        }
    } while (true); // Keep running until "Exit" is explicitly chosen

    return 0;
}


