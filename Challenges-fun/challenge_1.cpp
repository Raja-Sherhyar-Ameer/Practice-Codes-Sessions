#include<iostream>
using namespace std;

/* this program ensures that user enter correctly enters the password and
   is of correct of order as well */

int main(){
    string pasword;
    cout<<"Enter the password: ";
    cin>>pasword;

    int counter=0;
    int i=0;
    while(pasword[i]!='\0'){
        counter++;
        i++;
    }
    

    if(counter<12 || counter>12){
        cout<<"Invalid pasword length"<<endl;
        return 0;
    }

    int digit_counter=0, upper_counter=0,lower_counter=0,special_counter=0;
    for(int i=0;i<12;i++){
        if(pasword[i]>=48 && pasword[i]<=57)
        digit_counter++;
        else if(pasword[i]>=65 && pasword[i]<=90)
        upper_counter++;
        else if(pasword[i]>=97 && pasword[i]<=122)
        lower_counter++;
        else if(pasword[i]==33 || (pasword[i]>=35 && pasword[i]<=38) || pasword[i]==42 || pasword[i]==64 || pasword[i]==94)
        special_counter++;
    }

    if(digit_counter>=2 && upper_counter>=1 && lower_counter>=1 && special_counter>=2){
        cout<<"correct pasword written"<<endl;
    }
    else{
        cout<<"Invalid pasword written"<<endl;
        return 0;
    }

    return 0;
}