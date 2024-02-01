#include<iostream>
using namespace std;

int wines(int dp[][10], int prices[], int L,int R, int y){
    //base case
    //array will be finished
    if (L>R){
        return 0;
    }
    //chechk if state is already computed
    if(dp[L][R] != 0){
        return dp[L][R];
    }

    //rec case
    int pick_left = y*prices[L] + wines(dp,prices,L+1,R,y+1);
    int pick_right = y*prices[R] + wines(dp,prices,L,R-1,y+1);

    return dp[L][R] = max(pick_right,pick_left);
    
}
  
int main(){
    int a[] = {2,3,5,1,4};
    int n = 5;
    int dp[10][10] = {0};

    cout<<wines(dp,a,0,n-1,1)<<endl;


    //dp table
    for(int i = 0; i<n; i++){
        for (int j =0; j<n; j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
 
return 0;
}