#include<iostream>
#include<queue>
using namespace std;
  
int main(){
    queue<int> myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);

    while(!myQueue.empty()){
        cout<<myQueue.front()<<" ";
        myQueue.pop();
    }
 
return 0;
}