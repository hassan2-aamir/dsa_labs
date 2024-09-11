#include <iostream>
using namespace std;

int main(){
    int a=5, b=10; 
	int *pa=&a; //pa and pb are pointer variables of type int. 
	int *pb=&b;
	
	int **ppa=&pa; //ppa and ppb are called double pointers or pointers-to-pointers.
	int **ppb=&pb;

     //print the before 
    cout<<"before swap a = "<<**ppa<<" and b = "<<**ppb<<endl<<endl;

     //swap
    swap(ppa,ppb);

    //print the after 
    cout<<"after swap a = "<<**ppa<<" and b = "<<**ppb<<endl;
}

void swap(int **ppa,int **ppb){
    int temp = **ppa;
    **ppa = **ppb;
    **ppb = temp;
}