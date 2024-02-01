#include<iostream>
#include<stack>
using namespace std;


void insertAtBottom(stack<int> &s, int data){
 //we pass container by refrence because , we want to modify the original stack'
 //by defalt it is passed by value 
    //recursively empty the stack unitl it reaches base case
    if(s.empty()){
        s.push(data);
        return;
    }
    //recursive case
    //we will remove one element and store it in temp
    int temp = s.top();  //How is temp storing series of data?????
    s.pop();

    insertAtBottom(s,data);  //this will lead us to the base case
    //while coming back
    //we are going to store back the values
    s.push(temp);

}
  
int main(){
 
stack<int> s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
    
   insertAtBottom(s,5);

while (!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
}
 

 
return 0;
}