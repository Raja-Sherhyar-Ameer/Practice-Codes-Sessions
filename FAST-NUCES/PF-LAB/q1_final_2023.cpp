#include<iostream>
using namespace std;

/* This function is used to print "X" pattern in series according to user 
   inputs as height and how many series in a line.
*/

void pattern(int wavelength,int waveheight);

int main(){

    // loop for patterns iterators
    for(int i=3,j=3;i<=8;i++,j+=2){
        cout<<"Length = "<<i<<"\tHeight = "<<j<<endl;
        pattern(i,j);
    }

    return 0;
}

void pattern(int wavelength, int waveheight){
    int mid;
    if(waveheight%2==0){
        mid=waveheight/2;
    }
    else{
        mid=waveheight/2+1;
    }

    // upper "X" part
    for(int i=mid;i>1;i--){
        
        // for printing repeatition in a single row
        for(int l=0;l<wavelength;l++){
            
            for(int j=0;j<mid-i;j++){
                cout<<" ";
            }

            for(int k=1;k<=2*i-1;k++){
                if(k==1 || k==2*i-1){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }

            for(int m=0;m<mid-i;m++){
                cout<<" ";
            }
        }
        cout<<endl;
    }

    // lower "X" part
    for(int i=1;i<=mid;i++){

        // for printing repeatition in a single row
        for(int l=0;l<wavelength;l++){

            for(int j=0;j<mid-i;j++){
                cout<<" ";
            }

            for(int k=1;k<=2*i-1;k++){
                if(k==1 || k==2*i-1){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }

            for(int m=0;m<mid-i;m++){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
}