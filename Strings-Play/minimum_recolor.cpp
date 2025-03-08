#include<iostream>
using namespace std;

int main(){

    string s; 
    cout<<"Enter the colouring blocks: ";
    cin>>s;
    int k;
    cout<<"Enter the number for consecutive blacks: ";
    cin>>k;

    int left=0, right=0, curr_oper=0,min_operation=INT_MAX;
    while(right<s.length()){
        
        if(s[right]=='W'){
            curr_oper++;
        }

        if((right+1-left)==k){
            min_operation=curr_oper<=min_operation ? curr_oper:min_operation;

            if(s[left]=='W'){
                curr_oper--;
            }
            left++;
        }
        right++;
    }

    cout<<min_operation<<endl;

    return 0;
}