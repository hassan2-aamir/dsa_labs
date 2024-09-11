#include <iostream>
using namespace std;
    
int main(){   
    int list[5]={3,6,9,12,15};
	int *pArr= list;

    //loop through array
    for (int i =0 ;i<=4;i++){
        cout<<*(pArr+i)<<" ";
    }

    //endl for readabality
    cout<<endl;
}