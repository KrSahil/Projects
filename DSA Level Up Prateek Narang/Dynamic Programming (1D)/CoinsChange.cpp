#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Bottom Up approch
int minNumberOfCoinsForChange(int m, vector<int> denoms){
    vector<int> dp(m+1,0);
    dp[0] = 0;

    for (int i = 1; i<= m; i++){
        dp[i] = INT_MAX;

        for(int c : denoms){
            //can we go back to this index
            
            //if(i-c>=0){ //handling corner case
            if(i-c >= 0 && dp[i-c]!= INT_MAX){ //only than we should update our answer
                dp[i] = min(dp[i],dp[i-c]+1);
            }
        }
    }
    return dp[m] == INT_MAX ? -1 : dp[m];
    //corener case if we have coins of 5 7 and 10 then there is no way of making change for {1,2,3,4}
    //similarly we cannot make change for 6 as we reqire 1

}
  
int main(){
    vector<int> denoms = {1,5,7,10};
    int m = 16;
    cout<<minNumberOfCoinsForChange(m,denoms);
 

 
return 0;
}