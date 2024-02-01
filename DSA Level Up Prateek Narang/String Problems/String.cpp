#include<iostream>
#include<string>
using namespace std;
  
int main(){

    //char s[100] ={'1','a','b','c','d','\0'};
    string s = "Hello World"; //Dynamic array, can be updated on runtime
    //or
    string m("Hello World");
    //get input
    string n;
    getline(cin,n); //get input from user and it will store it in n

    string o;
    
    getline(cin,o,'.'); //terminated by '.'
    for(char ch : s){
        cout<<ch<<" ";
    }

    //array of string



    cout<<s<<" "<<m<<" "<<n<<" "<<o<<endl;    

 
return 0;
}