#include<iostream>
#include<stack>
using namespace std;

//Stock Span Problem
void stockSpan(int prices[] , int n, int span[]){
    stack<int> s; //indices of the day
    s.push(0);

    span[0]=1; //span at 1st day is always 1;

    //loop the rest of the days
    for (int i=1; i<=n-1;i++){
        int currentPrice = prices[i];
        //top most elemetn that is higher than the cureent price
        while (!s.empty() && prices[s.top()]<=currentPrice){
            s.pop();
        }

        if(!s.empty()){
        int prev_highest = s.top();
        span[i]=i -prev_highest;
        }
        else{
            span[i]= i+1;
        }

        //push this element into the stack
      s.push(i);
    }

}
  
int main(){

    int prices[] = {100,80,60,70,60,75,85};
    int n = sizeof(prices)/sizeof(int);
    int span [100]={0};
 
    stockSpan(prices,n,span);
    for (int i =0;i<n;i++){
        cout<<span[i]<<" ";
    }
 
return 0;
}

//O(N) -> push and pop element only once
