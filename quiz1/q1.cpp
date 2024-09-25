#include <iostream>
using namespace std;

int main(){
    int matrix[3][3];
    int vector[3];

    for(int i=0;i<3;i++){
        for (int j=0; j<3;j++){
            cout<<"Enter matrix row "<<i+1<<" column "<<j+1<<": ";
            cin>>matrix[i][j];
        }
    }

    for(int i=0;i<3;i++){
        cout<<"Enter vector value "<< i+1<<" : ";
        cin>>vector[i];
    }
    int ans[] ={0,0,0};
    for (int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum+=matrix[i][j]*vector[j];
        }
        ans[i]=sum;
    }
    cout<<"["<<ans[0]<<" "<<ans[1]<<" "<<ans[1]<<"]";
}