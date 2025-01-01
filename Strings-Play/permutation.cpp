#include<iostream>
using namespace std;
int main(){

    string word;
    cout<<"Enter the word: ";
    cin>>word;

    string temp="";
    for(int i=0;i<word.length();i++){
        int x=i+1;
        for(int j=0;j<word.length()-1;j++){
            temp=word[i];
            for(int k=0;k<=word.length()-1;k++){

                if(x>=word.length()){      // abc--acb, bca
                    x=0;                   // 1,2,3->0+1,--2,3->1,2 ::: 2,3->0
                }                          // 0,1,2            <=2

                if(word[i]==word[x]){
                    x++;
                    continue;
                }

                temp+=word[x];
                x++;

            }
            x=x+1;
            cout<<temp<<endl;
            temp="";
        }
    }




    return 0;
}