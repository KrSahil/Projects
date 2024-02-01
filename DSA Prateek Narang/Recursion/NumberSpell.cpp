#include<iostream>
using namespace std;


//global array 
string spell[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void printSpell (int n){
    if (n==0){
        return;
    }

    int last_digit = n%10;
    //extract last digit
    //but we dont want to print last digit now
    printSpell(n/10);

    cout<<spell[last_digit]<<" ";

}

int main(){
 
    int n;
    cin>>n;
    printSpell(n);
 
return 0;
}
