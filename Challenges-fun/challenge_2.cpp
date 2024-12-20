#include<iostream>
using namespace std;
int main(){

    int matrix[100][100];
    int n;
    cout<<"Enter the order of square-matrix: ";
    cin>>n;

    // inputting the elements
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    cout<<"Diagonal elements:: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<matrix[i][j]<<" ";
            }
        }
    }

    int j=n-1;
    cout<<"\nAnti-diagonal elements:: ";
    for(int i=0;i<n;i++){
        cout<<matrix[i][j--]<<" ";
    }
    cout<<endl;
    int k=0;
    j=0;
    while(true){

        if(k!=n && j!=n){
            cout<<matrix[k][j++]<<" ";
        }
        else if(k!=n && j==n){
            cout<<matrix[++k][j-1]<<" ";
        }
        else if(k==n && j==n){
            cout<<matrix[k-1][--j]<<" ";
        }
        else if(k!=n && j==0){
            cout<<matrix[--k][j]<<" ";
        }

        if(k==1 && j==0)
        return 0;
    }


    return 0;
}