#include<iostream>
using namespace std;

  
int main(){

   char paragraph[1000];

   //cin.getline(sentence,1000); // sentence, how  much it can hold 
    // stopping criteria for GetLine -> (sentence variable,length of sectence, stopping criteria)
    cin.getline(paragraph,1000,'.');  // by default value \n
    cout<<paragraph;
}