/*
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int lcsBottomUp(string s1, string s2){
    //bottom up approch to LCS
    int n1 = s1.length();
    int n2 = s2.length();
    //now we are going to fill the grid in bottom up manner

    //2D dp array
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

    //iterate from 1,1 to n1,n2
    for(int i = 1; i <= n1; i++){
        for ( int j = 1; j<=n2; j++){
            if(s1[i-1]==s2[j-1]){ //check if 
            //indexing is 1 based but in the string array it is 0 based  so we need to subtract 1
            //if the last character we are consedering in the current string is same as last character in the second string
            //than we can include that particular character
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                int op1 = dp[i-1][j];
                int op2 = dp[i][j-1];
                dp[i][j] = max(op1,op2);
            }
        }
    }

    /*
    //print the matrix
    for (int i = 0; i<=n1; i++){
        for(int j = 0; j<=n2; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    // * /

    vector<char> result;
    int i = n1, j = n2;
    
    while(i!=0 && j!=0){
        if(dp[i][j] = dp[i][j-1]){
            j--;
        }
        else if(dp[i][j] == dp[i-1][j]){
            i--;
        }
        else{
            //.if the value is not same as left or not same as right , that means we came by a diagonal
            //we  include the current character in the ans
            result.push_back(s1[i-1]); //either we pick it from s1 or s2 , that doesn't matter
            //we include the current character in the reuslt and we say go to the diagonl element
            i--;
            j--;
        }
    }
    //reverse the result
    reverse(result.begin(),result.end());
    for(char x: result){
        cout<<x<<",";
    }


    return dp[n1][n2];
}
  
int main(){

    string s1 = "ABCD"; 
    string s2 = "ABEDG";

    cout<<lcsBottomUp(s2,s1)<<endl;

return 0;
}

*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;


int lcs(string s1,string s2){
	//bottom up approach to lcs
	int n1 = s1.length();
	int n2 = s2.length();

	//2d dp array
	vector<vector<int > > dp(n1 + 1, vector<int>(n2+1,0));

	//1,1 ... n1,n2
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){

			if(s1[i-1]==s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				int op1 = dp[i-1][j];
				int op2 = dp[i][j-1];
				dp[i][j] = max(op1,op2);
			}
		}
	}

	//print
	/*
	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	*/

	vector<char> result;
	int i=n1,j=n2;
	while(i!=0 and j!=0){
		if(dp[i][j]==dp[i][j-1]){
			j--;
		}
		else if(dp[i][j]==dp[i-1][j]){
			i--;
		}
		else{
			result.push_back(s1[i-1]);
			i--;
			j--;
		}
	}
	reverse(result.begin(),result.end());
	for(char x:result){
		cout<<x <<",";
	}

	return dp[n1][n2];

}

int main(){

	string s1 = "ABCD";
	string s2 = "ABEDG";

	cout<<endl;
	cout <<lcs(s2,s1) <<endl;


	

	return 0;
}

