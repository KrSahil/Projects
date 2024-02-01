#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

//sorted subsequences
void subsequences(string s, string o,vector<string> &v){

    //base case
    if(s.size() == 0){ //we are at  leaf node
        v.push_back(o);
        return;
    }

    //rec case
    char ch = s[0];
    string reduced_input = s.substr(1);
    subsequences(reduced_input, o + ch, v); //includes current letter
    subsequences(reduced_input,o,v); //excludes current letter

}

bool compare(string s1, string s2){
    if(s1.length()==s2.length()){
        return s1<s2; //lexographic sorting
    }
    return s1.length() < s2.length();
}
  
int main(){
    string s;
    cin>>s;
    vector<string> v;
    string output = "";
    subsequences(s,output,v); 

    sort(v.begin(),v.end(),compare);

    for (auto s: v){
        cout<<s<<" ";
    }


 
return 0;
}