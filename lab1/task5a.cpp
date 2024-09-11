#include <iostream>
using namespace std;

int main(){
    int a=5, b=10; 
	int *pa=&a; //pa and pb are pointer variables of type int. 
	int *pb=&b;
	
    //print the before 
    cout<<"before swap a = "<<*pa<<" and b = "<<*pb<<endl<<endl;

    //swap
    swap(pa,pb);

    //print the after 
    cout<<"after swap a = "<<*pa<<" and b = "<<*pb<<endl;
}

void swap(int *pa,int *pb){
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}