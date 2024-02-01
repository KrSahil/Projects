#include<iostream>
#include<queue>
using namespace std;
  
int main(){

  int arr[] = {10,15,20,13,6,90};
  int n = sizeof(arr)/sizeof(int); 

  //priority_queue<int> heap;
  //By default max heap

  //for making it mean heap
  priority_queue<int,vector<int> , greater<int> > heap;
  //instead of greater<int> we can also create our own custom compare function

  for(int x:arr){
    heap.push(x);
  }

  while(!heap.empty()){
    cout<<heap.top()<<endl;
    heap.pop();
  }

 
return 0;
}