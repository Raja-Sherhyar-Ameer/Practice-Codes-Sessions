#include<iostream>
using namespace std;
/* Problem:: Find Maximum Dense Sub-matrix in a Binary Matrix
    Given a binary matrix data of size 𝑚×𝑛 (containing only 0s and 1s), 
    you are tasked with finding the maximum-sized square sub-matrix where
    the number of 1s is at least 75% of the total elements in that sub-matrix
*/

int main(){
    int m,n;
    cout<<"Enter the number of rows: ";
    cin>>m;
    cout<<"Enter the number of coloumns: ";
    cin>>n;

    // inputting the array
    int data[100][100];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>data[i][j];
        }
    }

    int k=2; // sub-matrix order indexes
    int max_count,count=0;
    int temp=0;
    int x_position,y_position;

    // sub-matrix traversal
    for(;k<m;k++){ 
        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                max_count=0;
                int least=0.75*k*k;
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                        if(data[x][y]==1){
                            max_count++;
                        }
                    }
                }
                if(max_count>=least && max_count>temp){
                    temp=max_count;
                    x_position=i,y_position=j;
                    count=k;
                }
            }
        }
    }

        // outputting the matrix with startig position and largest sub-matrix
        cout<<"The starting position is "<<x_position<<y_position<<endl;
        cout<<"The largest sub-matrix is "<<count<<"x"<<count<<" "<<endl;




    return 0;
}