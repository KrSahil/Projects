#include<iostream>
using namespace std;
  
/*
//pass by value
void applyTax(int income){

    float tax = 0.10;
    income = income-income*tax;
}
*/

//pass by refrence by using refrence variable
void applyTax(int &money){

    float tax = 0.10;
   money = money-money*tax;
}


int main(){
 
    int income;
    cin>>income;

    applyTax(income);

    cout<<income;
 
return 0;
}