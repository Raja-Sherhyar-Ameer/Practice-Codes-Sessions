#include<iostream>
#include<iomanip> // for setfill
using namespace std;

/*
   Problem:: Create a Sparse matrix from another matrix...
   This matrix is defined as a matrix that is used to track non-zero 
   elements of another matrix as well as its position and the value.
*/

int main(){

    // inputting the rows and cols for a matrix
    int rows,cols;
    cout<<"Enter the rows: ";
    cin>>rows;
    cout<<"Enter the coloumn: ";
    cin>>cols;

    // dynamically created matrix
    int** matrix=new int*[rows];
    for(int i=0;i<rows;i++){
        *(matrix+i)=new int[cols]{};
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>matrix[i][j];
        }
    }

    int sparse_mat[100][3],x=0;  // sparse matrix defined and its row-index
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]!=0){
                sparse_mat[x][0]=i;
                sparse_mat[x][1]=j;
                sparse_mat[x][2]=matrix[i][j];
                x++;
            }
        }
    }

    // printing element in form of chart
    cout<<setw(6)<<"Rows"<<setw(10)<<"Coloumns"<<setw(7)<<"Value"<<endl;
    for(int i=0;i<x;i++){
        for(int j=0;j<3;){
            cout<<setw(5)<<sparse_mat[i][j]<<setw(8)<<sparse_mat[i][++j]<<setw(8)<<sparse_mat[i][++j];
            j++;
        }
        cout<<endl;
    }


    // deallocating the memory
    for(int i=0;i<rows;i++){
        delete[] *(matrix+i);
    }

    delete[] matrix;
    matrix=nullptr;

    return 0;
}