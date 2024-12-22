#include<iostream>
using namespace std;

int twoSum(int* ptr, int size, int target);

int main(){
    
    int arr[100];
    int n;
    cout<<"Enter the size of matrix: ";
    cin>>n;
    
    // inputting the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int* arr_ptr=arr;

    int index=twoSum(arr_ptr,n,6);
    if(index!=-1){
        cout<<"Targeted sum is found and formed by adding index at:: ";
        for(int i=0;i<=index;i++){
            cout<<i<<" ";
        }
    }
    else{
        cout<<"Targeted sum does not found";
    }

    return 0;
}
int twoSum(int* ptr, int size, int target){
    int sum=0;

    for(int i=0;i<size;i++){
        sum+=(*(ptr+i));

        if(target==sum){
            return i;
        }
    }

    return -1;
}