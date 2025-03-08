#include <iostream>
#include <climits>
using namespace std;

/*

Program: It is a C category program known as Shuffled Sequences in which you have to print out
two type of sequence such that first is monotonically increasing and other is monotically decresing such
that sum of both monotonic sequence must be equals to original shuffled sequence. 

Sample Input::
7              --- size of shuffled sequence
7 2 7 3 3 1 4  --- elements of sequence

Output::
YES         --- if both monotonic exist
2           --- Ascending sequence size
3 7 
5           --- Descending sequence size
7 4 3 2 1 

Note: For more details about the problem, you can search for CodeForces 1144C

*/

int partition(int* arr, int s, int e){
    int idx=s;
    for(int j=s;j<e;j++){
        if(arr[j]<=arr[e]){
            swap(arr[idx],arr[j]);
            idx++;
        }
    }
    
    swap(arr[e],arr[idx]);
    
    return idx;
}

void Quicksort(int* arr,int st, int end){
    if(st<end){
        int pivotIndex = partition(arr, st, end);
        
        Quicksort(arr, st, pivotIndex - 1);
        Quicksort(arr, pivotIndex + 1, end);
    }
    
}
int main() {
    int size;
    //cout<<"Enter the size: ";
    cin>>size;
    int* arr=new int[size];
    bool* dp=new bool[size]{false};
    //cout<<"\t\tEntering the element\n";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    
    Quicksort(arr, 0, size-1);
    int left=0,right=1,freq=1,max=INT_MIN,des_size=0;
    while(right<size){
        
        if(max>=3){
            cout<<"NO"<<endl;
            delete [] dp;
            delete [] arr;
            dp=nullptr;
            arr=nullptr;
            return 0;
        }
        
        if(arr[left]==arr[right]){
            freq++;
            
            max=max>freq?max:freq;
            if(freq==2){
                dp[left]=true;
                des_size++;
            }
        }
        else{
            freq=1;
        }
        
        left++,right++;
    }
    
    cout<<"Yes\n"<<size-des_size<<endl;
    for(int i=0;i<size;i++){
        if(dp[i])
        continue;
        cout<<arr[i]<<" ";
    }
    
    cout<<"\n"<<des_size<<endl;
    for(int i=size-1;i>=0;i--){
        if(!dp[i])
        continue;
        cout<<arr[i]<<" ";
    }
    
    
    
    delete [] dp;
    delete [] arr;
    dp=nullptr;
    arr=nullptr;

    return 0;
}