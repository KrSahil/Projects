#include<iostream>
#include<vector>
using namespace std;

//Bottom Up Solution

int lis(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n,1);

    int len = 1; //this varible will store the max of all the values 

    for(int i = 1;i<n; i++ ){  //we are starting from 1 because for 0 ans will always be 1
        for(int j = 0; j<i; j++){
            //check if can ith index as the end of the sequence wich ends at jth element
            if(arr[i]>arr[j]){ //that means i can be attached to the end of that particular sequence
                dp[i] = max(dp[i], 1+dp[j]); //max ( whatever ans we have computed so far, what this new length is going to be)
                len = max(len, dp[i]); //max (whatever is the length we have so far , what is the new length that is computed in dp[i])
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