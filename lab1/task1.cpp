#include <iostream>
using namespace std;

int main(){
    //declare different datatype variables
    int an_int;
    long a_long;
    double a_double;
    float a_float;
    char a_char;

    //use sizeof to return bytes of different variables
    cout<<"size of int: "<<sizeof(an_int)<<" bytes"<<endl;
    cout<<"size of long: "<<sizeof(a_long)<<" bytes"<<endl;
    cout<<"size of double: "<<sizeof(a_double)<<" bytes"<<endl;
    cout<<"size of float: "<<sizeof(a_float)<<" bytes"<<endl;
    cout<<"size of char: "<<sizeof(a_char)<<" bytes"<<endl;

    return 0;
}