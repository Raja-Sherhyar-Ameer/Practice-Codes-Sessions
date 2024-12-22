#include<iostream>
using namespace std;

int max_sum_1(int arr[], int size);
int max_sum_2(int arr[], int size);

int main(){
    int arr[100];
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    // inputting the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The maximum sub array sum through 1st approach is " <<max_sum_1(arr,n)<<endl;
    cout<<"The maximum sub array sum through 2nd approach is " <<max_sum_2(arr,n)<<endl;

}

int max_sum_1(int arr[], int size){
    int sum=0,max_sum=INT_MIN;

    for(int sub=1;sub<size;sub++){  // sub-array counter

        // possible sub-array combination
        for(int i=0;i<=size-sub;i++){
            for(int j=i;j<i+sub;j++){
                sum+=arr[j];
            }

            if(sum>max_sum){
                max_sum=sum;
            }
            sum=0;
        }
    }

    return max_sum;
}

int max_sum_2(int arr[], int size){
    int sum=0,temp=INT_MIN;
    
    // traversing through all elements
    for(int i=0;i<size;i++){

        // all possible subset of element by element and their sum
        for(int j=i;j<size;j++){
            sum+=arr[j];
            if(sum>temp){
                temp=sum;
            }
        }
        sum=0;
    }

    return temp;
}