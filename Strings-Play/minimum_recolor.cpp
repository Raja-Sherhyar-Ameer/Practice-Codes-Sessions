#include<iostream>
using namespace std;

int main(){

    // Inputting the parameter
    string s; 
    cout<<"Enter the colouring blocks: ";
    cin>>s;
    int k;
    cout<<"Enter the number for consecutive blacks: ";
    cin>>k;

    int left=0, right=0, curr_oper=0,min_operation=INT_MAX;

    // Iterate through whole length
    while(right<s.length()){
        
        // Recolor the block to black
        if(s[right]=='W'){
            curr_oper++;
        }

        // Checking for Desired consecutive black box size
        if((right+1-left)==k){
            min_operation=curr_oper<=min_operation ? curr_oper:min_operation;

            // Avoiding repeatitve checking 
            if(min_operation==0){
                cout<<"The minimun operations are "<<min_operation<<endl;
                return 0;
            }

            // Adjustment for next Block
            if(s[left]=='W'){
                curr_oper--;
            }
            left++;
        }
        right++;
    }

    // Printing the results
    cout<<"The minimun operations are "<<min_operation<<endl;

    return 0;
}