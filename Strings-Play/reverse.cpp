#include<iostream>
using namespace std;

/* this program is used to revsrse the words for a string 
   such as::: ---> Input : this is a game
              ---> Output: sith si a emag  */ 
int main(){
    string word;
    cout<<"Enter the word: ";
    getline(cin,word);

    string reverse_line="";
    string temp="";
    for(int i=0;i<word.length();){                      
        
        while(word[i]!=' ' && word[i]!='\0'){
            temp+=word[i];
            i++;
        }
        i++;
        
        for(int j=temp.length()-1;j>=0;j--){
            reverse_line+=temp[j];
        }

        temp="";
        reverse_line+=" ";

    }    

    cout<<"Reverse Order:: "<<reverse_line<<endl;


    return 0;
}