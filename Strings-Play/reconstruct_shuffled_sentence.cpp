#include<iostream>
using namespace std;

int main(){
    string shuffled_sentence,correct_senetence="";
    cout<<"Enter the shuffled sentence: ";
    getline(cin,shuffled_sentence);

    int word_counter=1;
    for(int i=0;i<shuffled_sentence.length();i++){

        if(shuffled_sentence[i]==' ' && shuffled_sentence[i+1]!=' '){
            word_counter++;
        }
    }

    
    string word="",t_word="";
    for(int i=0;i<=word_counter;i++){

        string temp=""; int order=INT_MAX,x=0;

        for(int j=0;j<shuffled_sentence.length();j++){

            if(shuffled_sentence[j]==word[0]){
                for(int k=0;k<word.length()-1;k++){
                    correct_senetence+=word[k];
                }
                correct_senetence+=" ";
                t_word=word;
                word="";
            }

            if(shuffled_sentence[j]==t_word[x]){
                shuffled_sentence[j]='a';
                x++;
            }
            else{ 

                if(shuffled_sentence[j]!=' '){
                    temp+=shuffled_sentence[j];
                }
                else{
                    temp="";
                }

                if(shuffled_sentence[j]>='0' && shuffled_sentence[j]<='9'){
                    int t_order=shuffled_sentence[j]-'0';
                    
                    if(t_order<order){
                        word=temp;
                        order=t_order;
                        cout<<word<<endl;
                        t_word="";
                    }
                }
            }


        }
    }

    cout<<correct_senetence<<endl;
    return 0;
}