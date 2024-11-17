#include <iostream>
#include "sorts.hpp"
using namespace std;

int main(){

    int A[] ={1,3,5,7,2,4,6};

    cout<<"The array is: ";
    for(int i=0;i<7;i++) cout<<A[i]<<" ";
    cout<<"\n";

    Sorting::bubbleSort(A,7);
    cout<<"The array after bubble sort is: ";
    for(int i=0;i<7;i++) cout<<A[i]<<" ";
    cout<<"\n";

    int B[] ={1,3,5,7,2,4,6};

    Sorting::selectionSort(B,7);
    cout<<"The array after selection sort is: ";
    for(int i=0;i<7;i++) cout<<A[i]<<" ";
    cout<<"\n";


    int C[] ={1,3,5,7,2,4,6};

    Sorting::insertionSort(C,7);
    cout<<"The array after insertion sort is: ";
    for(int i=0;i<7;i++) cout<<A[i]<<" ";
    cout<<"\n";

    int D[] ={1,3,5,7,2,4,6};

    Sorting::mergeSort(D,0,6);
    cout<<"The array after insertion sort is: ";
    for(int i=0;i<7;i++) cout<<A[i]<<" ";
    cout<<"\n";
}