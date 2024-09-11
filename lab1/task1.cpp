#include <iostream>
using namespace std;

int main(){
    int an_int;
    int* a; 
    long a_long;
    double a_double;
    float a_float;
    char a_char;

    cout<<"size of int: "<<sizeof(a)<<" bytes"<<endl;
    cout<<"size of long: "<<sizeof(a_long)<<" bytes"<<endl;
    cout<<"size of double: "<<sizeof(a_double)<<" bytes"<<endl;
    cout<<"size of float: "<<sizeof(a_float)<<" bytes"<<endl;
    cout<<"size of char: "<<sizeof(a_char)<<" bytes"<<endl;

    return 0;
}