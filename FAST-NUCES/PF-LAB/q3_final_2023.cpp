#include<iostream>
#include<fstream>
using namespace std;
string name,password,user_name,email;
int age;
bool passwordChecker(string password);
void registerUser();
void loginUser();
int main(){

    int selected_option;

    // menu for users data handling
    while(true){

        cout<<"Please select any of the following option::"<<endl;
        cout<<"1. Register User\n2. Login User\n3. Exit the program"<<endl;
        cout<<"Your Selected Choice: ";
        cin>>selected_option;

        switch(selected_option){
            case 1:
            registerUser();
            cout<<endl;
            break;

            case 2:
            loginUser();
            cout<<endl;
            break;

            case 3:
            cout<<"Thanks for using the system"<<endl;
            return 0;

            default:
            cout<<"Invalid choice selcted"<<endl;
            cout<<endl;
        }
    }

    return 0;
}

// checking the password length as well as its validity
bool passwordChecker(string password){
    bool hasCapital=false,hasLower=false,hasSpecial=false,hasDigit=false;
    
    // iterating over all password length
    for(int i=0;i<password.length();i++){

        if(password[i]>='A' && password[i]<='Z'){
            hasCapital=true;
        }
        else if(password[i]>='a' && password[i]<='z'){
            hasLower=true;
        }
        else if(password[i]>='0' && password[i]<='9'){
            hasDigit=true;
        }
        else if( (password[i]>='!' && password[i]<='\'') || password[i]=='?' || password[i]=='@'){
            hasSpecial=true;
        } 
    }

    return hasCapital && hasDigit && hasLower && hasSpecial;
}

void registerUser(){

    // inputting the user data
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter your age: ";
    cin>>age;
    cout<<"Enter your user name: ";
    cin>>user_name;
    cout<<"Enter the email: ";
    cin>>email;
    cout<<"Enter the password: ";
    cin>>password;

    // checking the length of password
    if(password.length()<8){
        cout<<"Invalid Password length and it should be at least 8 characters"<<endl;
        return;
    }

    while(!passwordChecker(password)){
        cout<<"your password is very weak...So,"<<endl;
        cout<<"Enter the password again: ";
        cin>>password;
    }

    
    if(passwordChecker(password)){

        cout<<"User Registered Succcessfully"<<endl;

        // writing data of user to the file
        ofstream file(name+".txt");
        if(file.is_open()){
            file<<"Name: "<<name<<endl;
            file<<"Age: "<<age<<endl;
            file<<"Email: "<<email<<endl;
            file<<"User-name: "<<user_name<<endl;
            file<<"Password: "<<password<<endl;
        }
        else{
            cerr<<"Unable to open a file.... \nPlease try again...."<<endl;
        }
        file.close();

    }
    
}

void loginUser(){
    string t_name,t_user_name,t_password;
    cout<<"You are entering the credential for login"<<endl;
    
    // entering user data for login
    cout<<"Enter your name: ";
    cin>>t_name;
    cout<<"Enter your user name: ";
    cin>>t_user_name;
    cout<<"Enter the password: ";
    cin>>t_password;

    if(t_name==name && t_user_name==user_name && t_password==password){
        string line;

        // reading the file line by line
        ifstream inFile(name+".txt");
        if(inFile.is_open()){

            while(getline(inFile,line)){
                cout<<line<<endl;
            }
            inFile.close();

        }
        else{
            cerr<<"File does not exist... Try agian"<<endl;
        }
    }
    else{
        cout<<"Your credential does not match....\n\t\tLogin Unsuccessfull.....\nPlease try again to login"<<endl;
        return;
    }
}