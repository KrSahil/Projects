#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool checkRedundant(string str){

    stack<char> s;
    for(char ch: str){
        if(ch != ')'){
            s.push(ch); // a,b, + , - , ( .....
        }
        else{
            // '('
            bool operator_found = false;
            while (!s.empty() && s.top()!='('){
                char top = s.top();
                if(top == '+' || top == '-' || top == '/' || top == '*'){
                    operator_found = true;
                }
                s.pop();
            }
            //we are still left with the opening bracket
            s.pop(); //pop the opening breacket after the loop is over

            if(operator_found == false){
                return true;
            }
        }
    }
    return false;  //it's not redunant 
}
  
int main(){
    string str = "((a+b)+c)";
    if (checkRedundant(str)){
        cout<<"Contains Redundant Paranthesis";
    }
    else{
        cout<<"Doesn't contain Redundant Paranthesis";
    }
     
return 0;
}