#include <iostream>
using namespace std;

void array_function(){
    //get user input
    int num;
    cout<<"Enter number of elements in array: ";
    cin>>num;
    //initialise sum
    int sum=0;
    //create and populate array
    int* arr = new int[num];
    for (int i =0;i<num;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>*(arr+i);
        //calculate sum within loop
        sum+=*(arr+i);
    }
    //deallocate memory
    delete[] arr;
    //calculate average
    double avg=(double)sum/(double)num;
    //print results
    cout<<endl<<endl<<"sum of array: "<<sum<<endl;
    cout<<"average of array: "<<avg<<endl;
}

int main(){
    
    array_function();
    
    return 0;
}