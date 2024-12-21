#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of square matrix: ";
    cin>>n;
    int matrix[n][n]={
        {1,2,3},
        {4,5,6},
        {7,8,9}};
    int* ptr[n];
    
    // inputting the matrix
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){    00-02:: 01-12 :: 02-22
    //         cin>>matrix[i][j];    10-01:: 11-11 :: 12-21
    //     }                         20-00:: 21-01 :: 22-02
    // }

    // element accessing through pointer
    for(int i=0;i<n;i++){
        ptr[i]=matrix[i];
    }

    int x=n-1;
    for(int i=0;i<n;i++){
        for(int j=n-1-i;j>=0;j--){
            int temp = *(*(ptr+i)+j);
            *(*(ptr+i)+j) = *(*(ptr+j)+x);
            *(*(ptr+j)+x) = temp;

        }
        x--;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=n-1;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    

    return 0;
}