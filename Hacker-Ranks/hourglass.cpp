#include<iostream>
#include<climits>
using namespace std;
int main(){
    int matrix[6][6];
    
    // inputting the matrix
    cout<<"Entering elements of array"<<endl;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cin>>matrix[i][j];
        }
    }
    
    int sum=INT_MIN;    // for better comparsion results

    // traversing till possible combinations
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            int x=i,y=j;
            int temp=0;

            // finding the sum of hourglass
            for(int moves=1;moves<=7;moves++){
                if(moves==3 || moves==4){
                    temp+=matrix[x][y];
                    x++;  y--;
                }
                else{
                    temp+=matrix[x][y];
                    y++;
                }

            }

            // comparing with each sum
            if(temp>sum){
                sum=temp;
            }
        }
    }
    
    
    cout<<"Maximu Hour-Glass sum is "<<sum<<endl;
    
    return 0;
}