#include<iostream>
#include<queue>
using namespace std;
  
int main(){

    priority_queue<int> leftHeap; //maxheap
    priority_queue<int, vector<int>, greater<int> >rightHeap; //min heap

    int d;
    cin>>d;
    //first elemnt always push in the left
    leftHeap.push(d);

    float med = d; //initialize median with the first element
    cout<<med<<" ";

    cin>>d;

    while(d!=-1){
        //3 cases
        //left or right equal
        if(leftHeap.size() > rightHeap.size()){
            //2 possibilities
            if(d<med){ //if current data is less than median then we push in left heap

                //befor pushing 
                rightHeap.push(leftHeap.top());
                leftHeap.pop();

                leftHeap.push(d); //but befor pushing one elemnt we need to remove root and that will go into the right heap

            }
            else{
                //insert in the right heap
                rightHeap.push(d);

            }
            med = (leftHeap.top() + rightHeap.top())/2.0; //2.0 for float value
        }
        else if(leftHeap.size()==rightHeap.size()){
            if(d<med){
                leftHeap.push(d);
                med = leftHeap.top();
            }
            else{
                rightHeap.push(d);
                med = rightHeap.top();
            }
        }
        else{
            //opposite of first case
            if(d<med){
                leftHeap.push(d);
            }
            else{
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(d);
            }
            med = (leftHeap.top() + rightHeap.top())/2;
        }
        cout<<med<<" ";
        cin>>d;
    }

 

 
return 0;
}