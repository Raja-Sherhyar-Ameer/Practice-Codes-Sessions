#include<iostream>
using namespace std;

// used to find the whether the given array passed is mountain array or not
bool isMountainArray(int arr[], int n);
int main(){
    
    int arr[30];
    int n;
    cout<<"Enter the length of the array: ";
    cin>>n;
    
    // inputting the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    // calling and checking the array for mountain
    if( isMountainArray(arr, n) ){
        cout<<"Given array is mounatin array"<<endl;
    }
    else{
        cout<<"Given array is not a mounatin array"<<endl;
    }
    
    
    return 0;
}

bool isMountainArray(int arr[], int n){
    
    bool start=false,ismountain=true,mid=true;
    int counter=0;
    //traversing the each element
    for(int i=0;i<n-1;i++){

        if(arr[i]>arr[i+1] && i==0){
            return false;
        }

        if(arr[i]<arr[i+1] && !start){
            ismountain=true;
            start=false;
        }
        else if(arr[i]>arr[i+1] && mid){
            ismountain=true;
            start=true;
        }
        else{ 
            ismountain=false;
            return ismountain;
        }

    }

    return ismountain;
}