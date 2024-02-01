#include<iostream>
#include<climits>
using namespace std;

//Recursive solution
int max_profit(int prices[],int n){
    //base case
    if(n<=0){
        return 0;
    }

    //rec case
    int ans = INT_MIN;

    for(int i = 0; i<n; i++){
        //i = 0, we are making a cut of length 1
        //i = 1, we are making a cut of length 2
        int cut = i+1;

        int current_ans = prices[i] + max_profit(prices,n-cut);
        //price of the current cut + max profit of remaining rod i.e. n-cut

        //update our global ans 
        ans = max(ans,current_ans);
    }
    return ans; 

}

//Bottom up solution
int max_profit_dp(int *prices, int n){

    int dp[n+1];
    dp[0] = 0;

    int ans = INT_MIN;
    for (int len = 1; len <= n ; len++){
        for(int i = 0; i<len ; i++){  
            int cut = i + 1;
            int current_ans = prices[i] + dp[len-cut]; 
            ans = max(current_ans,ans);
        }
        //computed the asn for dp[len]
        dp[len] = ans;
    }
    return dp[n];
}
  
int main(){
    
    int prices[] = {1,5,8,9,10,17,17,20};
    int n = sizeof(prices)/sizeof(int);

    cout<<max_profit_dp(prices,n)<<endl;
 
return 0;
}