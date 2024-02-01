#include<iostream>
#include<vector>
using namespace std;

//Top Down
int countSub(string a,string b,int m,int n){

    //base case
    //if all the letter have been mathced or all the letters have been finished
    //Or 2nd case all the string of B has mathced with A
    if((m==-1 && n==-1) || n==-1){
        return 1;
    }
    if(m==-1){
        //the first string is finished but something is still left in string B
        return 0;
    }

    //rec case
    if(a[m] == b[n]){ //if last character match
        //we have 2 options
        //either to take last letter from a or not
        return countSub(a,b,m-1,n-1) + countSub(a,b,m-1,n); 
    }
    return countSub(a,b,m-1,n);

}

//count subsequecne bottom up
int countBU(string a,string b){
    int m = a.length();
    int n = b.length();

    vector<vector<int>>dp (m+1, vector<int>(n+1,0)); //part of the base case is initalized already 

    //fill the table in bottom up manner
    //first col as 1
    for (int i = 0; i<=m; i++){
        dp[i][0] = 1;
    }

    //1,1 ... m,n
    for (int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){ //fill the table
        //2 options 
        //1st - if current char from A matches current char from B 

            if(a[i-1] == b[j-1]){ //for dp table indexing is 1 based and for string it is 1 based 
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; //either we match the characters + no wf ways if we dont match
            }
            else{
                //we will copy the ansers form previous row and the same column
                dp[i][j] = dp[i-1][j];
            }
            //dp table
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }



    return dp[m][n];
}
  
int main(){
    string a = "ABCECDG";
    string b = "ABC";

    cout<< countSub(a,b,a.size()-1,b.size()-1)<<endl;
    cout<<countBU(a,b);
 
return 0;
}