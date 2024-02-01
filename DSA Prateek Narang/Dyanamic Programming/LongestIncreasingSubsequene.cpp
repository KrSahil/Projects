#include<iostream>
#include<vector>
using namespace std;

//Bottom up Solution
//**it is just using the values of its previous highest subsequence, it is not making it's own
int lis(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n,1); //array will have n elements all intitialized with 1
    //we assume longest Increasin subsequence is 1
    int len = 1;
    for(int i = 1;  i<n; i++){ //we are starting from 1 because 0 will always be 1
        for(int j = 0;j<i;j++){ //we go to every elemnt that have less index than i
            if(arr[i]>arr[j]){
                dp[i]= max(dp[i],1+dp[j]);
                len = max(len,dp[i]);
            }
        }
    }
    return len;
}
  
int main(){
    vector<int> arr{50,4,10,8,30,100};
    cout<<lis(arr)<<endl;

 
return 0;
}