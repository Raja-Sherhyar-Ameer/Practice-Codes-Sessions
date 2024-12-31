#include<iostream>
using namespace std;

bool isSubstringfound(string sentence,string substring);
void replaceSubstring(string sentence,string substring, string replace);
int main(){

    
    string sentence = "I am Pakistani so I support Pakistani Cricket team in Pak-India match";
    string substring,replace_string;
    cout<<"Enter the substring: ";
    cin>>substring;
    cout<<"Enter the replacing string: ";
    cin>>replace_string;

    replaceSubstring(sentence,substring,replace_string);

    return 0;
}

bool isSubstringfound(string sentence,string substring){

    for(int k=0;k<sentence.length();k++){
        string temp="";
        for(int i=k;i<sentence.length();i++){
            temp+=sentence[i];
            if(temp==substring){
                return 1;
            }
        }
    }

    return 0;
}


void replaceSubstring(string sentence,string substring, string replace){
    string temp="";

    if(isSubstringfound(sentence,substring)){ 

        for(int i=0;i<sentence.length();){

            if(sentence[i]==substring[0]){

                for(int j=0;j<replace.length();j++){
                    temp+=replace[j];
                }
                i+=substring.length();
            }
            else{
                temp+=sentence[i];
                i++;
            }
        }
    }


    cout<<temp<<endl;
}