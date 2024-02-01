#include<iostream>
#include<string>
using namespace std;
  
int main(){

    string  s;

    getline(cin,s,'#'); //it reads a paragraph until it incounters #

    //printing every character of ths string
    for(char ch: s){
        cout<<ch<<",";
    }

    cout<<s<<endl;
return 0;
}