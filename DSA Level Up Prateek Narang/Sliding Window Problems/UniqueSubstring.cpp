#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

string unique_substring(string str){

    int i = 0;
    int j = 0;

    int window_len = 0; //tells the length of the current window
    int max_window_len = 0;
    int start_window = -1; //means we dont have any window 

    unordered_map<char,int> m;

    while(j<str.length()){

        while(j < str.length()){
            char ch = str[j];

            //if it is indside hash map and its idx >= startof the current window
            if(m.count(ch) && m[ch]>=i){
                //
                 i = m[ch] + 1; //reduces the lenght of the window
                 window_len = j-i; //updated remaining window len excluding current char

            }
            //update the last occuarance
            m[ch] = j;
            window_len++;
            j++;

            //update max window lenght in every step
            if(window_len > max_window_len){
                max_window_len= window_len;
                start_window = i; 
            }
        }
    }
    return str.substr(start_window,max_window_len);
}
  
int main(){
 
    string input;
    cin>>input;

    cout<<unique_substring(input);
 
return 0;
}