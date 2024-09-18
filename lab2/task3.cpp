#include <iostream>
using namespace std;

int main() {
    int* ptr = nullptr;  // Pointer initialized to nullptr
    
    //modified check
    if (ptr != nullptr){
        // Try to dereference the pointer
        cout << "Value pointed by ptr: " << *ptr << endl;  // This will cause a crash
    }
    else{
        cout<<"Error Segmentation fault"<<endl;
    }
    return 0;
}
