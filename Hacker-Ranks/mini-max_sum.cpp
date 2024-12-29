#include<iostream>
using namespace std;
int main(){
    const int size=5;
    int arr[size];

    // inputting the array
    for(int i=0;i<size;i++){
        cout<<"Enter the element "<<i+1<<": ";
        cin>>arr[i];
    }

    // for better comparisons
    long long int max=LLONG_MIN,min=LLONG_MAX;

    // traversing through each elements subset
    for(int i=0;i<size;i++){
        int temp=0;

        // 4-element sub array counter
        for(int counter=0,j=i;counter<4;counter++){
            if(j>=size){
                j=0;
            }

            temp+=arr[j];
            j++;
        }

        if(temp>max){
            max=temp;
        }
        if(temp<min){
            min=temp;
        }
    }

    // printing the sum
    cout<<"MINIMUM SUM:: "<<min<<endl;
    cout<<"MAXIMUM SUM:: "<<max<<endl;

    return 0;
}