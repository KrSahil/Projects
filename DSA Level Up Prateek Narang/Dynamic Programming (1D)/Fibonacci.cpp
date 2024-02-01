#include<iostream>
using namespace std;

int fib(int n){
    //base case
    if(n==1 || n==0){
        return n;
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}

int fibTopDownDP(int n, int dp[]){
    if(n==0 || n== 1){
        return n;
    }
    //check if the state is already computed
    if(dp[n]!=0){
        return dp[n];
    }
    return dp[n] = fib(n-1,dp) + fib(n-2,dp);
}

int fibBottomUpDP(int n){
    int dp[n+1] = {0};
    //base case
    dp[0] = 0;
    dp[1] = 1;

    //bottom up DP
    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
  
int main(){
 

 
return 0;
}