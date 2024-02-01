#include<iostream>
#include<vector>
using namespace std;

//Recursive code ~> Top Down
int knapsack(int wts[],int prices[],int N,int W){
    //base case
    if(N==0 || W == 0){
        return 0;
    }
    //rec case
    int inc = 0,exc = 0;

    //if we want to include and item, we need to check the weight of that item, that item is at the right most index
    if(wts[N-1]<=W){ //if weigth is less than the current capacity of the bag we include it
        inc = prices[N-1] + knapsack(wts,prices,N-1,W-wts[N-1]);
    }
    exc = knapsack(wts,prices,N-1,W);

    return max(inc,exc);
}
  
int main(){

    int wts[] = {2,7,3,4};
    int prices[] = {5,20,20,10};

    int N = 4;
    int W = 11;
    cout<<knapsack(wts,prices,N,W)<<endl;

   // cout<<knapsackDP(wts,prices,N,W);

 
return 0;
}