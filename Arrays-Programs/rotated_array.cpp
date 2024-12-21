#include<iostream>
using namespace std;
/* Problem:: To Rotate the matrix clockwise 90 degree , with some restrictions are
 a. Donot use extra array  
 b. Changes in array only be done by pointers
*/

int main(){
    int n;
    cout<<"Enter the size of square matrix: ";
    cin>>n;
    int x=n-1;
    int matrix[n][n]={0};
    int* ptr[n];
    
    // inputting the matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){    
            cin>>matrix[i][j];    
        }                       
    }

    // element accessing through pointer
    for(int i=0;i<n;i++){
        ptr[i]=matrix[i];
    }

    // rotating the matrix by 90 degree clockwise
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i-1;j++){
            int temp=*(*(ptr+i)+j); 
            *(*(ptr+i)+j)=*(*(ptr+x-j)+i);         // Error in code fixed by GPT by replacing *(*(ptr+x-i)+j) =*(*(ptr+x-j)+i)
            *(*(ptr+x-j)+i)=*(*(ptr+x-i)+x-j);
            *(*(ptr+x-i)+x-j)=*(*(ptr+j)+x-i);
            *(*(ptr+j)+x-i)=temp;
        }
    }

    cout<<"The rotated matrix is: "<<endl;
    // printing the rotated matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    

    return 0;
}