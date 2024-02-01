#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isBalanced(string input){
    stack<char> s;

    for(auto ch : input){
        switch(ch){
            case '(':
            case '{':
            case '[': s.push(ch);
                break;

            case ')': if(!s.empty() && s.top() == '('){
                        s.pop();
                      }
                      else{
                        return false;
                      }
                      break;

            case '}': if(!s.empty() && s.top() == '{'){
                        s.pop();
                      }
                      else{
                        return false;
                      }
                      break;

            case ']': if(!s.empty() && s.top() == '['){
                        s.pop();
                      }
                      else{
                        return false;
                      }
                      break;
                      
            default : continue;            

        }
    }

    if(s.empty()){
        return true;
    }
    return false;
}
  
int main(){
    string s = "((aa+b+c)+[d])";

    if(isBalanced(s)){
        cout<<"Balanced";
    }
    else{
        cout<<"Not Balanced";
    }

return 0;
}