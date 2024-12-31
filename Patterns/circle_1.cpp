#include<iostream>
using namespace std;
int main(){

    int radius;
    cout<<"Enter the radius: ";
    cin>>radius;

    int i=radius;
    for(int counter=1;counter<=radius; counter++, i++){
        for(int j=0;j<radius-counter;j++){
            cout<<"  ";
        }

        for(int k=1;k<=2*i-1;k++){
            if(i==radius){
                if(k==1 || k==2*i-1){
                    cout<<". ";
                }
                else{
                    cout<<"* ";
                }
            }
            else if(k==1 || k==2*i-1){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }

    i=i-2;
    for(int counter=radius-1;counter>=1; counter--, i--){
        for(int j=0;j<radius-counter;j++){
            cout<<"  ";
        }

        for(int k=1;k<=2*i-1;k++){
            if(i==radius){
                if(k==1 || k==2*i-1){
                    cout<<". ";
                }
                else{
                    cout<<"* ";
                }
            }
            else if(k==1 || k==2*i-1){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }



    return 0;
}