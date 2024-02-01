#include<iostream>
using namespace std;
  
//0(k^n) - exponential time complexity
//Recursive
int countWays(int n, int k){
    if(n==0){ //we are standing at the ground
        return 1;
    }
    if(n<0){ //we cannot come from negative index
        return 0;
    }
    //recursive case
    int ans = 0;
    for(int jump = 1; jump <= k; jump++){
        ans += countWays(n-jump,k); //n = 3, k = 5 , then n-k can be negative; so we made a condition above as (n<0)
    }
    return ans;
}

//Top Down Code (O(n,k))
int countWaysTD(int n, int k, int *dp){
    if(n==0){ //we are standing at the ground
        return 1;
    }
    if(n<0){ //we cannot come from negative index
        return 0;
    }

    //check if state is already computed
    if(dp[n]!=0){
        return dp[n];
    }
    //recursive case
    int ans = 0;
    for(int jump = 1; jump <= k; jump++){
        ans += countWaysTD(n-jump,k,dp); //n = 3, k = 5 , then n-k can be negative; so we made a condition above as (n<0)
    }
    return dp[n] = ans;
}

int main(){
    int n,k;
    cin>>n>>k;

    int dp[100] = {0};

    cout<<countWays(n,k)<<endl;
    cout<<countWaysTD(n,k,dp)<<endl;
    
return 0;
}