#include<iostream>
#include<climits>
#include<vector>
using namespace std;


//Top Down
int min_jumps(vector<int> arr, int n, vector<int> dp, int i ){
    //last index is n-1 : this should return 0 steps needed
    //base case
    if(i==n-1){
        return 0;
    }

    if(i>=n){
        return INT_MAX;
    }

    //Rec case
    if(dp[i]!=0){ //it is already computed
        return dp[i];
    }

    //assume steps needed is INT_MAX
    int steps = INT_MAX;
    int max_jump = arr[i];

    for(int jump = 1; jump<=max_jump; jump++){ ///we will try all possible jump
        //the idex to which i can go is 
        int next_cell = i + jump; //where I am standing + the jump I am taking 
        int subProb = min_jumps(arr,n,dp,next_cell);
        //next_ cell : if it is out of bounds it will return INT_MAX, if it is last cell it will return 0, if it is inside the array it will make another recursive call
        if(subProb!=INT_MAX){
            steps = min(steps,subProb+1); // min of whatever steps i have  covered so far , or ans that I am getting from subproblem + 1, because we are also making jump
        }
    }
    return dp[i] = steps; 
}
  
int main(){

    vector<int> arr{3,4,2,1,2,3,7,1,1,3};
    int n = arr.size();

    //create a array for dp
    vector<int> dp(n,0);

    cout<<min_jumps(arr,n,dp,0)<<endl;
 
return 0;
}