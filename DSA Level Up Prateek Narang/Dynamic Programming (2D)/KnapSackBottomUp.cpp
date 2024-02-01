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

//Bottom Up
int knapsackDP(int wt[],int price[],int N,int W){

    vector<vector<int>> dp(N+1,vector<int>(W+1,0)); 
    //this makes 0,i aand i,0   --- 0
    for(int n = 1; n<=N;n++){
        for(int w = 1; w<=W; w++){
            int inc = 0, exc = 0;
              
            //if we want to include nth item
            if(wt[n-1] <= w){ //it should be less than the capacity of the bag at current index. (weight varies at every increasing index)
                inc = price[n-1] + dp[n-1][w-wt[n-1]];
                //price of this item + profit i am getting from subProblem
                //SubProblem is already computed and stroed inside the DP array
            }
            exc = dp[n-1][w]; //we dont reduce tha capacity of the bag
            //Basically , we are calling the cell which is in same column but in previous row  


            dp[n][w] = max(inc,exc);
        }
    }


    return dp[N][W];
}
  
int main(){

    int wts[] = {2,7,3,4};
    int prices[] = {5,20,20,10};

    int N = 4;
    int W = 11;
    cout<<knapsack(wts,prices,N,W)<<endl;

    cout<<knapsackDP(wts,prices,N,W);

 
return 0;
}