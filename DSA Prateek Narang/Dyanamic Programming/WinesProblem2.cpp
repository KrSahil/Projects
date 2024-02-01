#include<iostream>
#include<vector>
using namespace std;

//top down code
int wines(int dp[][10],int prices[],int L,int R,int y){

    //base caase - array is finished
    if(L > R){
        return 0;
    }
    //store , check if state is already computed
    if(dp[L][R] != 0){
        return dp[L][R]; // the state is already computed
    }
    //rec case
    int pick_left = y*prices[L] + wines(dp,prices,L+1,R,y+1); //2nd function profit that will come by selling remaining item
    int pick_right = y*prices[R]  + wines(dp,prices,L,R-1,y+1);

    return dp[L][R] = max(pick_right,pick_left);

}
int wines_bottom_up(int prices[], int n){

    vector<vector<int> > dp(n+1, vector<int> (n+1,0));
    //start from the last row
    for (int i=n-1; i>=0;i--){
        for (int j=0; j<n; j++){

            //base case --only one bottle left
            if(i==j){
                dp[i][j]= n*prices[i];
            }
            else if(i<j){
                //dp[i][j] (i...j)
                int y= n-(j-i);
                int pick_left = prices[i]*y + dp[i+1][j];
                int pick_right = prices[j]*y + dp[i][j-1];

                dp[i][j] = max(pick_left,pick_right);

                
            }
            
        }
    }
    for (int i =0; i<n; i++){
        for (int j = 0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][n-1];
}
  
int main(){
 
    int a [] = {2,3,5,1,4};
    int n = 5;
    int dp[10][10] = {0};

    cout<<wines(dp,a,0,n-1,1)<<endl;

    for (int i =0; i<n; i++){
        for (int j = 0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------"<<endl;

    cout<<wines_bottom_up(a,n);
 
return 0;
}