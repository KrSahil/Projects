#include<iostream>
#include<vector>
using namespace std;

int lcs(string s1, string s2, int i , int j){
    //base case
    if(i == s1.length() || j == s2.length()){
        return 0; //that means one of the string is finished , we won't find anything common. So, we return 0
    }

    //rec case
    //if current charachter matches we add 1 to the answer
    if(s1[i] == s2[i]){
        return 1 + lcs(s1,s2,i+1,j+1); //we return and make a call on remaining sub problem
    }
    //if the current incides don't match , than we include one of them

    int op1 = lcs(s1,s2,i+1,j);
    int op2 = lcs(s1,s2,i,j+1);

    //whatever bracnh returns the max ans , we return it
    return max(op1,op2);

}

int lcsTopDown(string s1, string s2, int i , int j, vector<vector<int>> &dp){
    //base case
    if(i == s1.length() || j == s2.length()){
        return 0; //that means one of the string is finished , we won't find anything common. So, we return 0
    }
    //check if a state is already computed
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    //rec case
    //if current charachter matches we add 1 to the answer
    if(s1[i] == s2[i]){
        return dp[i][j] = 1 + lcsTopDown(s1,s2,i+1,j+1,dp); //we return and make a call on remaining sub problem
        //when we are computing a particular state, before returning we store it,
    }
    //if the current incides don't match , than we include one of them

    int op1 = lcsTopDown(s1,s2,i+1,j,dp);
    int op2 = lcsTopDown(s1,s2,i,j+1,dp);

    //whatever bracnh returns the max ans , we return it
    return dp[i][j] = max(op1,op2);
    //similarly we are computing the state here

}
  
int main(){

    string s1 = "ABCD"; 
    string s2 = "ABEDG";

    cout<<lcs(s1,s2,0,0)<<endl;

    //Top Down
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1,vector<int>(n2,-1));  //we will initialize n1 no of rows(no of elements), and ecah row would
    // be a vector of integers( And ecah row contains n2 no of cells)
    // and we initialized it with -1 because 0 can be a valid ans
    //n1 X n2

    cout<<lcsTopDown(s1,s2,0,0,dp)<<endl;

    //printing the vector
    for(int i = 0; i<n1; i++){
        for(int j = 0; j<n2; j++){
            cout<<dp[i][j]<<"    ";
        }
        cout<<endl;
    }
 
return 0;
}