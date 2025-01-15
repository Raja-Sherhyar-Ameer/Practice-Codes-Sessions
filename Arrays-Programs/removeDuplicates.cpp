#include<iostream>
using namespace std;

/* Problem:: Your task is to print the unique elements in the array and
   remove the duplicates from it.

    Input  :: [1, 3, 5, 9, 8, 3, 1]
    Output :: [1, 3, 5, 8, 9]

   Constraint::  Removing logic must be executed only single loop
   It should be generic and work for both sorted and non-sorted array
*/

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

    int x=1;  // counter for tracking unique elements
    for(int i=0;i<length;i++){

        if(i!=0 && ((arr[i]^arr[i-1])!=0) ){
            arr[x++]=arr[i];
        }

    }
    
    cout<<"The unique elements are "<<x<<endl;

    // printing the unique elements
    for(int i=0;i<x;i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}