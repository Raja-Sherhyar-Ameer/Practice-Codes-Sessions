#include<iostream>
using namespace std;
int main(){
    int matrix[100][100];
    int size;
    cout<<"Enter the size\\order of square-matrix: ";
    cin>>size;

    // inputting the matrix
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cin>>matrix[i][j];
        }
    }

    


    return 0;
}