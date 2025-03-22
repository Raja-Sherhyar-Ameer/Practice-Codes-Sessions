#include<iostream>
using namespace std;

// Raja Shehryar Ameer    24I - 0544

int determinant_2D_finder(int**,int);
void coloumnSwap(int**,int**,int);

int main(){

    // Dyanmically Allocating the memory for 3x3 and 3x1 matrix
    int** mat = new int*[3];
    for(int i = 0; i < 3; ++i){
        mat[i] = new int[3];
    }

    cout<<"Enter the elements of the 3x3 matrix:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) {
            cin>>mat[i][j];
        }
    }

    int** B_mat=new int*[3];
    for(int i=0;i<3;i++) {
        B_mat[i]=new int[1];
    }

    cout << "Enter the elements of the 3x1 matrix:" << endl;
    for(int i = 0; i < 3; ++i) {
        cin >> B_mat[i][0];
    }
    
    // Finding of determinant of original matrix
    int det=0;
    for(int i=0;i<3;i++){

        if(i&1){
            det=det-(mat[0][i]* (determinant_2D_finder(mat,i)));
        }
        else{
            det=det+(mat[0][i]*(determinant_2D_finder(mat,i)));
        }
    }

    // Bounding Checkque
    if(det==0){
        cout<<"No solution exist"<<endl;

        // Avoiding memory leaks
        for(int i=0;i<3;i++){
            delete [] B_mat[i];
            delete[] mat[i];
        }
        delete[] B_mat, delete[] mat;
        B_mat=nullptr,mat=nullptr;

        return 0;
    }
    

    // Applying the cramer Rule
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

        // Printing the values
        cout<<"Ans 0"<<i+1<<" "<<ans<<endl;
        coloumnSwap(mat,B_mat,i);   // Used to recover the matrix
    }

    // Avoiding memory leaks
    for(int i=0;i<3;i++){
        delete [] B_mat[i];
        delete[] mat[i];
    }
    delete[] B_mat, delete[] mat;
    B_mat=nullptr,mat=nullptr;

    
    return 0;
}

int determinant_2D_finder(int** arr,int blocker){
    
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

void coloumnSwap(int** arr,int** swaper,int col){

    for(int i=0;i<3;i++){
        int temp=arr[i][col];
        arr[i][col]=swaper[i][0];
        swaper[i][0]=temp;
    }
}