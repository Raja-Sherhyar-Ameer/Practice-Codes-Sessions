#include<iostream>
using namespace std;

/*

Problem: This is leetCode problem number 2379 in which string s given a representation of colouring 
block such that 'W' means White and 'B' means Black. However, your task is to find minimum operation
that you will be performing on the string to make it equal to k consecutive Black blocks. 

Input: 
s = "WBBWWBBWBW", k = 7
Output:
The minimum operations are 3

*/

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