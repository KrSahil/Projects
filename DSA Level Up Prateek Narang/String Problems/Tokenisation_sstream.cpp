#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
  
int main(){

    string input;
    getline(cin,input);

    //create a string stream object
    stringstream ss(input);

    // >> and << operators
    string token;
    vector<string> tokens;
    while(getline(ss,token,' ')){ //get ss and store it in token
        tokens.push_back(token);
    
    }

    //print all the tokens'
    for(auto token:tokens){
        cout<<token<<",";
    }
 
return 0;
}