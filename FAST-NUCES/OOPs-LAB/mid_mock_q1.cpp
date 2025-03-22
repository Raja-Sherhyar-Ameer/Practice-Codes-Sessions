#include<iostream>
using namespace std;

// Raja Shehryar Ameer    24I - 0544

int determinant_2D_finder(int arr[][3],int blocker){
    
    int col_incrementer= blocker&1 ? 2:1,ops=0, det=0;
    
    // used to find the sub-matrix of 2x2 determinant
    for(int i=0;i<3;i++){
        
        // Avoiding the selected coloumn enteries
        if(i!=blocker){
            
            int x=i+col_incrementer;
            x=x<3 ? x:0;
            if(ops==1){
                x=i-col_incrementer;
                x=x>=0 ? x:0;
                det-=(arr[1][i]*arr[2][x]);
                break;
            }
            det+=(arr[1][i]*arr[2][x]);
            ops++;

        }
        
    }

    return det;
    
}

void coloumnSwap(int arr[][3],int swaper[][1],int col);

int main(){
    int mat[3][3]={
        {0, -2, 3},
        {4, -5, 0},
        {7, 0, -9}
    };  
    int B_mat[3][1]={
        {-1},
        {2},
        {3}
    };
    
    int det=0;
    for(int i=0;i<3;i++){

        if(i&1){
            det=det-(mat[0][i]* (determinant_2D_finder(mat,i)));
        }
        else{
            det=det+(mat[0][i]*(determinant_2D_finder(mat,i)));
        }
    }
    
    for(int i=0;i<3;i++){
        int t_det=0;
        coloumnSwap(mat,B_mat,i);    // Used to swap respective coloumn

        for(int i=0;i<3;i++){

            if(i&1){
                t_det=t_det-(mat[0][i]* (determinant_2D_finder(mat,i)));
            }
            else{
                t_det=t_det+(mat[0][i]*(determinant_2D_finder(mat,i)));
            }
        }
        double ans=(float)(t_det/det);
        cout<<"Ans 0"<<i+1<<" "<<ans<<"  det:"<<t_det<<endl;
        coloumnSwap(mat,B_mat,i);   // Used to recover the matrix
    }


    cout<<"Determinant: "<<det<<endl;
    
    return 0;
}

void coloumnSwap(int arr[][3],int swaper[][1],int col){

    for(int i=0;i<3;i++){
        int temp=arr[i][col];
        arr[i][col]=swaper[i][0];
        swaper[i][0]=temp;
    }
}