#include<iostream>
using namespace std;
string reverse_print(string name,int len){
    if(len<0){
        return "";
    }
    else{
        cout<<name[len--];
        return reverse_print(name,len);
    }
}

int main(){
    string word;
    cout<<"Enter the word: ";
    cin>>word;

    int length=word.length()-1;
    reverse_print(word,length);

    return 0;
}