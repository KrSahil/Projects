#include<iostream>
#include<vector>
using namespace std;

//Recursive
//exponential time
int countBST(int n){
    if(n==0 or n==1){
        return 1;
    }
    int ans = 0;
    for(int i = 1; i<=n ; i++){ //iterating over all the nodes (1 to N as root Node)
        int x = countBST(i-1); //no of possible ways for Left Sub Tree
        int y = countBST(n-i);

        ans += x*y;

    }
    return ans;
}

//Top Down - 0(n^2)
int countBSTtopDown(int n,int dp[]){
    if(n==0 or n==1){
        return 1;
    }
    //if dp[n] is not coumputed
    if(dp[n]!= 0){
        return dp[n];
    }

    int ans = 0;
    for(int i = 1; i<=n ; i++){ //iterating over all the nodes (1 to N as root Node)
        int x = countBSTtopDown(i-1,dp); //no of possible ways for Left Sub Tree
        int y = countBSTtopDown(n-i,dp);

        ans += x*y;

    }
    //if not couputed than we store it
    return dp[n] = ans;
}

int countBSTBottomUp(int N){
    vector<int> dp(N+1,0);

    dp[0] = dp[1] = 1;

    for(int n = 2; n<=N ; n++){ //i is behaving like n
        for(int i = 1; i<=n; i++){ // j is behaving like i
            dp[n] += (dp[i-1]*dp[n-i]); //dp[i] that is our current ans that will be increamented by the factor of 
        }
    }
    return dp[N]; 
}
  
int main(){

    int n = 5;   

    int dp[n+1] = {0};

    cout<<countBSTtopDown(n,dp)<<endl;
 
return 0;
}