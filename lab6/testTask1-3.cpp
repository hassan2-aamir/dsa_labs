#include <iostream>
#include "task1to3.h"
using namespace std;

int main() {
    binarySearchTree bst;

    // Test if the tree is empty
    cout << "Is the tree empty? " << (bst.IsEmpty() ? "Yes" : "No") << endl<<endl;

    // Insert values
    bst.InsertWithoutDuplication(10);
    bst.InsertWithoutDuplication(5);
    bst.InsertWithoutDuplication(15);
    bst.InsertWithoutDuplication(3);
    bst.InsertWithoutDuplication(7);
    bst.InsertWithoutDuplication(12);
    bst.InsertWithoutDuplication(18);
    cout<<"Values inserted successfully"<<endl<<endl;

    // Try to insert a duplicate value
    cout<<"Trying to insert a duplicate value"<<endl;
    bst.InsertWithoutDuplication(10);


    return 0;
}