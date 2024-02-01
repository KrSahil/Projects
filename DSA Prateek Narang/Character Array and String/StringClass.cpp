#include<iostream>
#include<string>
using namespace std;
  
int main(){
    //char s[1000]= {'1','a','b','c','\0'};
 
    //string s="Heloo World"; // Dynamic array
                        //we initialize it with some value

    //second way, making  a call to constructor to get inputt
    //string s("hello World");

    //third way , we take input from the user
    string s;
    getline(cin,s);
    cout<<s<<endl;
    
    string p;
    getline(cin,p,'#'); //it reads a paragraph until it incounters #
    cout<<p<<endl;
return 0;
}