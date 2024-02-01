#include<iostream>
#include<vector>
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

int wines_bottom_up(int prices[], int N){
    //creating DP array
    vector<vector<int>> dp(N+1,vector<int>(N+1,0));

    //we start from the last row
    for(int i = N-1; i>=0; i--){
        //iterating from bottom row to top row
        for(int j = 0; j<N; j++ ){



            /*
            if we leave the code this way it will give us error
                    <- [  ]    ]
                    but we dont have any element at left at 0,0
                    so, //we make base case
                                */
            //base case
            if(i==j){
                dp[i][j] = N*prices[i];
                //N = no of bottles I have because that will be year
            }


            //we only fill cells if i<=j
            else if(i<=j){
                //dp(i..j)
                //if i ...j bottle are remaining then current year is 
                int y = N - (j-i);
                //this will give us multiplicative factor for calculating the price
                
                //now, we have 2 options
                int pick_left = prices[i]*y + dp[i+1][j];
                //price of left i.e. i
                int pick_right = prices[j]*y + dp[i][j-1];

                dp[i][j] = max(pick_left,pick_right);

                

            }
        }
    }

    //dp table
    for(int i = 0; i<N; i++){
        for (int j =0; j<N; j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }

    return dp[0][N-1];
}
  
int main(){
    int a[] = {2,3,5,1,4};
    int n = 5;
    int dp[10][10] = {0};

    cout<<"Top Down"<<endl;

    cout<<wines(dp,a,0,n-1,1)<<endl<<endl;


    //dp table
    for(int i = 0; i<n; i++){
        for (int j =0; j<n; j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Bottom Up"<<endl;

    cout<<wines_bottom_up(a,n)<<endl;
 
return 0;
}