#include <iostream>
using namespace std;

void array_function(){
    //get user input
    int num;
    cout<<"Enter number of elements in array: ";
    cin>>num;
    //create and populate array
    int* arr = new int[num];
    for (int i =0;i<num;i++){
        *(arr+i)=i+1;
    }
    //display array contents
    cout<<"array:"<<endl;
    for (int i =0;i<num;i++){
        cout<<*(arr+i)<<" ";
    }
    //deallocate memory
    delete[] arr;
}

int main(){
    
    array_function();
    
    return 0;
}