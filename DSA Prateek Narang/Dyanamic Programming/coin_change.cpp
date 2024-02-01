#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Bottom Up Approach 
//first we create a array
int minNumberOfCoinsForChange(int m, vector<int> denoms){
    //we will crate a m+1 array to make change of m rupees, so that last index is at m
    vector<int> dp(m+1,0); //initiaize every thing with 0
    dp[0] = 0;

    for (int i = 1; i<=m ; i++){
        // do not know what is the min
        dp[i]= INT_MAX;

           for (int c : denoms ){
                if(i-c >=0 && dp[i-c] != INT_MAX){// becase it is not possible to get chanege all the time
                    dp[i] = min(dp[i],dp[i-c]+1);
                }
            }
    }
    return dp[m]==INT_MAX? -1 : dp[m];
}
  
int main(){
    vector<int> denoms = {1,5,7,10}; //types of coins
    int m = 8;
    cout<<minNumberOfCoinsForChange(m,denoms);
 
return 0;
}