#include<iostream>
using namespace std;

/* Problem:: Find max palindrome sub string in string */

int main(){

    string word;
    cout<<"Enter the word: ";
    getline(cin,word);
    
    if(word.empty()){
        cout<<"No string's palindrome found due to empty string"<<endl;
        return 0;
    }

    bool isPalindrome=true;
    string temp="", palindrome="";
    int c_length=0,p_length=0;
    
    // subset counter
    for(int k=1;k<=word.length();k++){
        for(int i=0;i<=word.length()-k;i++){
            
            // forming sub-string
            for(int j=i;j<i+k;j++){
                temp+=word[j];
            }
            
            c_length=temp.length()-1;

            // checking palindrome
            for(int x=0;x<(temp.length())/2;x++){
                if(temp[x]!=temp[c_length]){
                    isPalindrome=false;
                    break;
                }
                else{
                    isPalindrome=true;
                    c_length--;
                }
            }

            // cehcking largest subset palindrome
            if(isPalindrome &&  temp.length()>p_length){
                p_length=temp.length();
                palindrome=temp;
            }
            
            temp="";
        }
    }
    
    // printing the largest palindrome
    cout<<"Largest Sub-strings:: "<<palindrome<<endl;
    
    return 0;
}