#include<iostream>
using namespace std;
int sum(int num){

    // base case:: call till num bacomes 1
    if(num==1){
        return 1;
    }
    else
    return num+sum(num-1);

}
int fact(int num){

    //since the factorial exist only for whole numbers that are positive
    if(num>=0){
        /*base case:: call till num bacomes 1 and why 0 if user enters
        to get the the factorial for both the number 1 and 0 is 1*/    
        if(num==1 || num==0){
            return 1;
        }
        else
            return num*fact(num-1);
    }
    else{
        cout<<"Inavlid number entered by user and it should be positive"<<endl;
        return 0;
    }
    
}
int main(){

    // calling the sum
    cout<<"The sum of first 6 natural numbers are "<<sum(6)<<endl;
    // calling the factorials
    cout<<"The factorial of number 5 is "<<fact(5)<<endl;

    return 0;
}