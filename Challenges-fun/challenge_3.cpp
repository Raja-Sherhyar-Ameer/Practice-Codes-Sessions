#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter the number of rows: ";
    cin>>m;
    cout<<"Enter the number of coloumns: ";
    cin>>n;

    int data[100][100];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>data[i][j];
        }
    }






    return 0;
}