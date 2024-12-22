#include<iostream>
using namespace std;

/* Problem:: Printing of elements in different manner as:
   a. Diagonal Element
   b. Anti Diagonal Element
   c. Bordered Element in clockwise starting from 00 index
*/

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

    // printing the primary diagonal element
    cout<<"Diagonal elements:: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<matrix[i][j]<<" ";
            }
        }
    }

    int j=n-1;
    // printing the secondary diagonal element
    cout<<"\nAnti-diagonal elements:: ";
    for(int i=0;i<n;i++){
        cout<<matrix[i][j--]<<" ";
    }
    cout<<endl;

    // printing the border element in clockwise order
    cout<<"Bordered linear clockwise printing is as:: ";  
    int counter=0; j=0;
    int i=0;
    while(counter<n*n){

        if(i==0 && j!=n-1 && j+1<n){              // move right
            cout<<matrix[i][j++]<<" ";
        }
        else if(j==n-1 && i+1<n){                // move down
            cout<<matrix[i++][j]<<" ";
        }
        else if(i==n-1 && j-1>=0){               // move left
            cout<<matrix[i][j--]<<" ";
        }
        else if(j!=n-1 && i-1>=0){              // move up
            cout<<matrix[i--][j]<<" ";
        }

        if(i==0 && j==0){
            break;
        }
        else{
            counter++;
        }   
    }

    return 0;
}