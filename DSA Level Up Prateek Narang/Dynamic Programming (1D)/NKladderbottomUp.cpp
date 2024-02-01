#include<iostream>
#include<vector>
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

//Bottom approch (O(n*k))
int countWaysBU(int n,int k){
    //iterative approch

    vector<int> dp(n+1,0);

    //similar as base case
    dp[0] = 1;

    //and for all other values 
    for(int i=1; i<=n ; i++){
        //sum up previous k values ... with base case index >=0
        for (int jump = 1; jump <= k; jump++){
            if(i-jump>=0){
                dp[i] += dp[i-jump]; //we add the anwer of previous state in the current state
            } 
        }

    }
    return dp[n];
    
}

//Bottom Up - Optimised (O(n+k))
int countWaysOpt(int n, int k){
    vector<int> dp(n+1,0);

    dp[0] = dp[1] = 1;

    for(int i = 2; i<=k ; i++){
        dp[i] = 2*dp[i-1];
        /*
        dp[i] = 2dp[i-1] - dp[i-k-1]
        dp[i-k-1] will not exists if i<= k
        eg. k = 3; we cannot go to index 3-3-1
        1 1 2
        here we can see, 3rd term is double of previous term (or summesion of previous two terms)
        after 4 values are found we continue with the main approch
        so, that is why we break the code into two parts // one part (i<=k)  and other part (i>k)
        */
    }
    for(int i=k+1; i<=n; i++){
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }
    return dp[n];
}

int main(){
    int n,k;
    cin>>n>>k;

    int dp[100] = {0};

    cout<<countWays(n,k)<<endl;
    cout<<countWaysBU(n,k)<<endl;
    cout<<countWaysOpt(n,k)<<endl;
    
return 0;
}