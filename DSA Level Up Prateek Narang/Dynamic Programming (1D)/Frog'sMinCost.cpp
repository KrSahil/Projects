#include<iostream>
#include<vector>
#include<cmath> //abs
using namespace std;

//bottom up approch
int getMinCost(vector<int> stones){
    
    int n = stones.size();
    vector<int> dp(n,0);

    //dp[0] = 0; // we already have assigned with zero
    dp[1] = abs(stones[1]- stones[0]);

    //and for all values which are stating from 2 
    for (int i = 2; i<n ; i++){
        //either we take jump from the previous step i.e the jump of 1
        int op1 = abs(stones[i] - stones[i-1]) + dp[i-1];
        //abs( current stone - height of the previous stone) + cost of reaching the previous stone that is already computed and stored in dp array

        int op2 = abs(stones[i] - stones[i-2]) + dp[i-2];

        dp[i] = min(op1,op2);
    }
    return dp[n-1]; //becuase we have n stones in the array
}
  
int main(){

    int n;
    cin>>n;
    vector<int> stones(n);

    for(int i = 0; i<n; i++){
        cin>>stones[i];
    } 

    cout<<getMinCost(stones)<<endl;

return 0;
}