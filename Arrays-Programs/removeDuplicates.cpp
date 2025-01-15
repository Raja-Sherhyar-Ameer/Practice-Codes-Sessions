#include<iostream>
using namespace std;

int main(){

    // inputting the array and its element
    int arr[30];
    int length;
    cout<<"Enter the number of elements of array: ";
    cin>>length;

    for(int i=0;i<length;i++){
        cin>>arr[i];
    }

    // sorting the array
    for(int i=0;i<length;i++){
        for(int j=i+1;j<length-i;j++){
            
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            
        }
    }


    
    
    return 0;
}