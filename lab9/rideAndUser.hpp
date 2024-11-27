#include <iostream>
using namespace std;

// Ride structure representing a single ride
struct Ride {
    string startLocation;
    string endLocation;
    double fare;

    Ride(string start, string end, double fare)
        : startLocation(start), endLocation(end), fare(fare) {}
};

struct RideNode {
        Ride* ride;
        RideNode* prev;
        RideNode* next;

        RideNode(Ride* ride) : ride(ride), prev(nullptr), next(nullptr) {}
};
// RideHistory class responsible for managing the doubly linked list of rides
class RideHistory {
private:
    RideNode* head;
    RideNode* tail;

public:
    RideHistory() : head(nullptr), tail(nullptr) {}

    // Add a ride to the user's history
    void addRide(const string& startLocation, const string& endLocation, double fare) {
        Ride* newRide = new Ride(startLocation, endLocation, fare);
        RideNode* newNode = new RideNode(newRide);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Display the ride history for a user
    void displayRideHistory() {
        if (!head) {
            cout << "No ride history available.\n";
            return;
        }

        RideNode* currentRide = tail; // Start from the most recent ride (tail)
        char choice;
        do {
            cout << "\n--- Ride Details ---\n";
            cout << "Start Location: " << currentRide->ride->startLocation << endl;
            cout << "End Location: " << currentRide->ride->endLocation << endl;
            cout << "Fare: $" << currentRide->ride->fare << endl;

            cout << "\nOptions: ";
            if (currentRide->prev) {
                cout << "[P] Previous ";
            }
            if (currentRide->next) {
                cout << "[N] Next ";
            }
            cout << "[E] Exit\n";

            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 'P' || choice == 'p') {
                if (currentRide->prev) {
                    currentRide = currentRide->prev;
                } else {
                    cout << "No previous ride.\n";
                }
            } else if (choice == 'N' || choice == 'n') {
                if (currentRide->next) {
                    currentRide = currentRide->next;
                } else {
                    cout << "No next ride.\n";
                }
            } else if (choice != 'E' && choice != 'e') {
                cout << "Invalid option. Please try again.\n";
            }
        } while (choice != 'E' && choice != 'e');

        cout << "Exiting ride history view.\n";
    }

    RideNode* getRecentRideNode(){
        return head;
    }

    // Destructor to free memory
    ~RideHistory() {
        RideNode* current = head;
        while (current != nullptr) {
            RideNode* nextNode = current->next;
            delete current->ride; // Delete the Ride object
            delete current;
            current = nextNode;
        }
    }
};

// Node structure for user
struct User {
    string username;
    string password;
    RideHistory rideHistory; // Contains the ride history for each user
    User* next;

    User(string user, string pass)
        : username(user), password(pass), next(nullptr) {}
};

// UserList class to manage a list of users
class UserList {
protected:
    User* head;

    // Helper function to find a user (driver) node
    User* findUser(const string& username) {
        User* temp = head;
        while (temp != nullptr) {
            if (temp->username == username) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Protected helper method to load from a file, the filename is passed here
    void loadFromFileHelper(const string& filename) {
        ifstream infile(filename);
        if (!infile) {
            cout << "No existing user data found. Starting fresh.\n";
            return;
        }

        string username, password, startLocation, endLocation;
        double fare;
        while (infile >> username >> password) {
            User* newUser = new User(username, password);
            newUser->next = head;
            head = newUser;

            while (infile >> startLocation >> endLocation >> fare) {
                if (startLocation == "END_RIDES") break;
                addRide(newUser->username, startLocation, endLocation, fare, true); // Add rides for the user
            }
        }
        infile.close();
    }

    // Protected helper method to save to a file, the filename is passed here
    void saveToFileHelper(const string& filename) {
        ofstream outfile(filename);
        User* temp = head;
        while (temp != nullptr) {
            outfile << temp->username << " " << temp->password << endl;
            RideNode* rideTemp = temp->rideHistory.getRecentRideNode();
            while (rideTemp != nullptr) {
                outfile << rideTemp->ride->startLocation << " "
                        << rideTemp->ride->endLocation << " "
                        << rideTemp->ride->fare << endl;
                rideTemp = rideTemp->next;
            }
            outfile << "END_RIDES" << endl;
            temp = temp->next;
        }
        outfile.close();
    }

public:
    UserList() : head(nullptr) {}

    // Method to check if a user exists
    bool userExists(const string& username) {
        return findUser(username) != nullptr;
    }

    // Signup method
    bool signup(const string& username, const string& password) {
        if (findUser(username)) {
            cout << "Error: Username already exists.\n";
            return false;
        }

        User* newUser = new User(username, password);
        newUser->next = head;
        head = newUser;
        return true;
    }

    // Login method
    bool login(const string& username, const string& password) {
        User* userNode = findUser(username);
        if (userNode && userNode->password == password) {
            cout << "Login successful. Welcome, " << username << "!\n";
            return true;
        }
        cout << "Error: Invalid username or password.\n";
        return false;
    }

    // Add a ride to the user's history
    virtual void addRide(const string& username, const string& startLocation, const string& endLocation, double fare, bool calledFromLoadFile=false) {
    }



    // Display the ride history for a user
    void displayRideHistory(const string& username) {
        User* userNode = findUser(username);
        if (!userNode) {
            cout << "Error: User not found.\n";
            return;
        }

        userNode->rideHistory.displayRideHistory();
    }

    // Destructor to free memory
    virtual ~UserList() {
        User* current = head;
        while (current != nullptr) {
            User* nextUser = current->next;
            delete current;
            current = nextUser;
        }
    }
};