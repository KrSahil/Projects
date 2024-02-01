#include<iostream>
#include<vector>
using namespace std;

//Recursive case -->Top Down
int knacpsack(int  wts[],int prices[],int N,int W){
    //base case
    if(N==0 || W==0){
        return 0;
    }
    //rec case
    int inc = 0 , exc = 0;
    if(wts[N-1]<=W){
        inc = prices[N-1] + knacpsack(wts,prices,N-1, W-wts[N-1]);
    }
    exc = knacpsack(wts,prices,N-1,W);
    return max(inc,exc);
}

//Bottom Up Dp
int knapsackDP(int wt[],int price[],int N,int W){
    vector<vector<int> > dp(N+1,vector<int>(W+1,0)); //initialize with N+1 row and each row will be a vector of W+1 columns and default value will be 0 in all the cells
    
    for (int n=1;n<=N;n++){
        for (int w=1;w<=W;w++){
            //we are solving a problem for a dp of N,W
            //we want to find the value
            int inc = 0, exc =0;

            if (wt[n-1] <= w){
                inc = price[n-1] + dp[n-1][w-wt[n-1]];
            }
            exc = dp[n-1][w]; //we dont reduce the capacity of the bag

            dp[n][w]  = max(inc,exc);
        }
    }
    return dp[N][W];
}
  
int main(){
    int wts[] = {2,7,3,4};
    int prices[] = {5,20,20,10};

    int N = 4;
    int W = 11;

     cout<<knacpsack(wts,prices,N,W)<<endl;
    cout<<knapsackDP(wts,prices,N,W);
 

 
return 0;
}