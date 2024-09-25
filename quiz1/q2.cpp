#include <iostream>
using namespace std;

int main(){
    int matrow,matcol,vecrow;

    cout<<"Enter num of row in matrix: ";
    cin>>matrow;

    cout<<"enter num of columns in matrix: ";
    cin>>matcol;

    vecrow=matcol;

    int *matrix = new int[matrow*matcol];
    int *vector = new int[vecrow];

    for(int i=0;i<matrow;i++){
        for (int j=0; j<matcol;j++){
            cout<<"Enter matrix row "<<i+1<<" column "<<j+1<<": ";
            cin>>*(matrix+i*3+j);
        }
    }

    for(int i=0;i<vecrow;i++){
        cout<<"Enter vector value "<< i+1<<" : ";
        cin>>*(vector+i);
    }
    int *ans = new int[matrow];
    for (int i=0;i<matcol;i++){
        int sum=0;
        for(int j=0;j<vecrow;j++){
            sum+=*(matrix+i*3+j)**(vector+j);
        }
        *(ans+i)=sum;
    }
    cout<<"[";
    for(int i=0;i<matrow;i++){
        cout<<*(ans+i)<<" ";
    }
    cout<<"]";
}