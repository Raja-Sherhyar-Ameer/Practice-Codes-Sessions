#include<iostream>
using namespace std;
int digit_counter(int val,int &count){
    if(val==0){
        return count; 
    }
    else{
        count+=1;
        return digit_counter(val/10,count);
    }

}
int main(){

int num,counter=0;
cout<<"Enter the number: ";
cin>>num;

cout<<digit_counter(num,counter);

    return 0;
}