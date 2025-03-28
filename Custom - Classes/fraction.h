#pragma once
#include<iostream>
using namespace std;

// Raja Shehryar Ameer     24I-0544

class Fraction{
private:
    int numerator,denominator;
    
public:

// Constructor Implementation
Fraction(){
    numerator=0,denominator=1;
} 
Fraction(int n,int d){
    numerator=n,denominator= (d!=0) ? d:1;
} 
Fraction(Fraction& num):numerator(num.numerator),denominator(num.denominator){}

// Setter and Getter
void setNumerator(int n){
    numerator=n;
}
void setDenominator(int d){
    denominator=d!=0 ? d:1;
}


int getNumerator()const{
    return numerator;
}
int getDenominator()const{
    return denominator;
}

int getNumerator(){
    return numerator;
}
int getDenominator(){
    return denominator;
}

// Overloading the operators

// Comparing the Fraction
bool operator==(Fraction& other){

    if(numerator== other.getNumerator() && denominator==other.getDenominator())
    return true;

    return false;
}

// Greater Fraction 
bool operator>(Fraction& other){
    int x=numerator*other.getDenominator(),y=other.getNumerator()*denominator;
    if(x>y)
    return true;

    return false;
}

// Lesser Fraction 
bool operator<(Fraction& other){

    int x=numerator*other.getDenominator(),y=other.getNumerator()*denominator;
    if(x<y)
    return true;

    return false;
}

// Adding the fractions
Fraction operator+(const Fraction& other){
    int n=numerator*other.getDenominator() + denominator*other.getNumerator();
    int d=denominator*other.getDenominator();

    for(int i=1;i*i<=d;i++){
        if(n%i==0 && d%i==0){
            n/=i;
            d/=i;
        }
    }

    return Fraction(n,d);
}

// Subtracting the fraction
Fraction operator-(const Fraction& other){
    int n=numerator*other.getDenominator() - denominator*other.getNumerator();
    int d=denominator*other.getDenominator();

    for(int i=1;i*i<=d;i++){
        if(n%i==0 && d%i==0){
            n/=i;
            d/=i;
        }
    }

    return Fraction(n,d);
}

// Printing the result
friend ostream& operator<<(ostream& OUT,const Fraction& num);
friend istream& operator>>(istream& IN,Fraction& num);

~Fraction(){
    cout<<"Bye bye"<<endl;
}
};

ostream& operator<<(ostream& OUT,const Fraction& num){
    OUT<<num.numerator<<"/"<<num.denominator<<endl;

    return OUT;
}

istream& operator>>(istream& IN,Fraction& num){

    cout<<"Enter numerator: ";
    IN>>num.numerator;
    cout<<"Enter denominator: ";
    IN>>num.denominator;

    return IN;
}
