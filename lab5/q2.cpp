#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int* queue;
    
public:
    Queue(int c) {
        capacity = c;
        front = rear = -1;
        queue = new int[capacity];
    }
    
    ~Queue() {
        delete[] queue;
    }
    
    void Enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full, cannot enqueue.\n";
            return;
        }
        if (front == -1) 
            front = 0;

        rear = (rear + 1) % capacity;
        queue[rear] = element;
        cout << "Patient registered id: " << element << endl;
    }
    
    int Dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue.\n";
            return -1;
        }
        
        int element = queue[front];
        
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        
        return element;
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
    
    void Clear() {
        front = rear = -1;
        cout << "Queue cleared.\n";
    }
    
    int getFront() const {
        return front;
    }
    
    int getRear() const {
        return rear;
    }
    
    int* getQueue() const {
        return queue;
    }
    
    int getCapacity() const {
        return capacity;
    }
};

class WaitingRoom {
    int id;
    Queue waitingLine;

public:
    WaitingRoom(): id(0) ,waitingLine(7){        
    }
    void RegisterPatient() {
        int patientId = ++id;
        waitingLine.Enqueue(patientId);
    }

    void ServePatient() {
        int patientID = waitingLine.Dequeue();
        if (patientID != -1) 
            cout << "Patient number " << patientID << ", it's finally your turn :)" << endl;
    }

    void CancelAll() {
        waitingLine.Clear();
    }

    bool CanDoctorGoHome() {
        return waitingLine.isEmpty();
    }

    void ShowAllPatient() {
        if (!waitingLine.isEmpty()) {
            cout << "Patients are: ";
            int curr = waitingLine.getFront();
            int rear = waitingLine.getRear();
            int* queueArray = waitingLine.getQueue();
            int capacity = waitingLine.getCapacity();

            do {
                cout << queueArray[curr] << " ";
                curr = (curr + 1) % capacity;
            } while (curr != (rear + 1) % capacity);

            cout << endl;
        } else {
            cout << "Line is empty!" << endl;
        }
    }
};


// Test function
void testWaitingRoom() {
    WaitingRoom wr1;

    cout << "Registering patients...\n";
    wr1.RegisterPatient();  // Should register patient 1
    wr1.RegisterPatient();  // Should register patient 2
    wr1.RegisterPatient();  // Should register patient 3

    cout << "\nShowing all patients...\n";
    wr1.ShowAllPatient();  // Should show patients 1, 2, and 3

    cout << "\nServing patients...\n";
    wr1.ServePatient();  // Should serve patient 1
    wr1.ServePatient();  // Should serve patient 2

    cout << "\nShowing remaining patients...\n";
    wr1.ShowAllPatient();  // Should show patient 3

    cout << "\nChecking if the doctor can go home...\n";
    if (wr1.CanDoctorGoHome()) {
        cout << "Doctor can go home.\n";
    } else {
        cout << "Doctor cannot go home yet.\n";
    }

    cout << "\nCanceling all patients...\n";
    wr1.CancelAll();

    cout << "\nChecking if the doctor can go home after canceling...\n";
    if (wr1.CanDoctorGoHome()) {
        cout << "Doctor can go home.\n";
    } else {
        cout << "Doctor cannot go home yet.\n";
    }
}

int main() {
    testWaitingRoom();
    return 0;
}
