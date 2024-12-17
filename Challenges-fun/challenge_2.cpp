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
    for(int i=0;i<n*n;i++){
        if(i!=n && j!=n){
            cout<<matrix[i][j++]<<" ";
        }
        else if(i!=n && j==n){
            cout<<matrix[i++][j]<<" ";
        }
        else if(i==n && j==n){
            cout<<matrix[i][j--]<<" ";
        }
        else if(i!=n && j==0){
            cout<<matrix[i--][j]<<" ";
        }
    }


    return 0;
}