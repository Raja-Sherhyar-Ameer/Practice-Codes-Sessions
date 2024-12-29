#include<iostream>
using namespace std;

/* This function is used to generate the magic square matrix of odd numbers
   using lumbere's algorithms. However, Magic Square matrix is defined is
   the matrix whose row sum or column sum or diagonal sum are equal
*/
void generateMagic_matrix(int matrix[][7],int size);

int main(){
    int matrix[7][7]={0};
    
    // calling the magic matrix generation function
    generateMagic_matrix(matrix,7);
    cout<<"The magic square matrix:: "<<endl;

    // printing the matrix
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
void generateMagic_matrix(int matrix[][7],int size){

    int i=0,j=size/2;
    matrix[i][j]=1;
    int limit=size-1;

    // following the loubere's Algorithms
    for(int val=2;val<=size*size;){
        
        if(i-1>=0 && j+1<size && matrix[i-1][j+1]==0){
            i--;   j++;
            matrix[i][j]=val;
        }
        else if(i-1>=0 && j+1<size && matrix[i-1][j+1]!=0){
            i++;
            matrix[i][j]=val;
        }
        else if(i-1<0 && j+1<size && matrix[i+limit][j+1]==0){
            i+=limit;  j++;
            matrix[i][j]=val;
        }
        else if(j+1>=size && i-1>=0 && matrix[i-1][j-limit]==0){
            j-=limit;  i--;
            matrix[i][j]=val;
        }
        else if(i-1<0 && j+1>=size && matrix[i+limit][j-limit]==0){
            i+=limit; j-=limit;
            matrix[i][j]=val;
        }
        else if(i-1<0 && j+1>=size && matrix[i+limit][j-limit]!=0){
            i+=1; 
            matrix[i][j]=val;
        }
        val++;
    }
    
}