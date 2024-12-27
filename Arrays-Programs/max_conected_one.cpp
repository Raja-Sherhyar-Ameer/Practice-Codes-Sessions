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

    int temp=INT_MIN;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            int counter=0,sum=0;
            while(counter<size*size){
                int x=i,y=j;

                if(x+1<size && matrix[x][y]==1){       // move down
                    sum+=matrix[x++][y];
                }
                else if(y-1>=0 && matrix[x][y]==1){       // move left
                    sum+=matrix[x][y--];
                }
                else if(y+1<size && matrix[x][y]==1){       // move right
                    sum+=matrix[x][y++];
                }
                else if(x-1>=0 && matrix[x][y]==1){       // move left
                    sum+=matrix[x--][y];
                }
                counter++;
            }
            if(sum>temp){
                temp=sum;
            }
        }
    }

    cout<<temp<<endl;


    return 0;
}