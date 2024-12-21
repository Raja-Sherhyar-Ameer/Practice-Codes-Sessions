#include <iostream>
using namespace std;
int equilibrium_index(int arr[],int n){
    for(int i=0;i<n;i++){
        int left_sum=0,right_sum=0;
        for(int j=0;j<n;j++){
            
            if(j<i){
                left_sum+=arr[j];
            }
            else if(j>i){
                right_sum+=arr[j];
            }
        }

        // checking the equilibrium index
        if(left_sum==right_sum){
            return i; 
        }
    }
    return -1; // if no equilibrium index found
} 
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int array[100];
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    cout<<equilibrium_index(array,size);
    return 0;
}