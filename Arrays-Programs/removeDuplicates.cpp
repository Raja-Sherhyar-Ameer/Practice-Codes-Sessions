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
        for(int j=0;j<length-i-1;j++){
            
            // comparing the element and finding max, placing at right position
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }
    }

   
    return 0;
}