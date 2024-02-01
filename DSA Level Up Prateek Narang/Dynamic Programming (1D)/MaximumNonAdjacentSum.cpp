#include<iostream>
#include<vector>
using namespace std;

//Bottom Up Approach
int maxSubsetSumNoAdjacent(vector<int> array){

    int n = array.size();
    vector<int> dp(n+1,0);

    //Corner case
    if(n==1){ //or array.size()==1
        return max(array[0],0); //or 0 if elemtn is negative
    }

    //if we have 2 elements
    else if(n==2){ //or array.size() == 2
        return max(0,max(array[0],array[1])); // if both of them are nagative we can return 0 also 
    }

    //other wise we will have our normal bottom up logic
    dp[0] = max(array[0],0);
    dp[1] = max(0,max(array[0],array[1]));

    for (int i =2 ; i<n ;i++){
        //either we inclued the current element 
        int inc = array[i] + dp[i-2]; //+ sum that we have formed till before the previous element
        //or exclude
        int exc = dp[i-1]; //just the sum that we have fromed till previous element

        dp[i] = max(inc,exc);
    }
    return dp[n-1];        
}
  
int main(){

    vector<int> arr({6,10,12,7,9,14});
    cout<<maxSubsetSumNoAdjacent(arr);
 
return 0;
}