#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int countSubsets(vector<int> arr,int n,int i, int X){
    //base case
        if(i == n){ //if i =n the entire arry is finished
            //check if target sum is also zero
            if(X==0){
                return 1;
            }
            return 0;
        }

    //rec case
    int inc = countSubsets(arr,n,i+1,X-arr[i]);
    int exc = countSubsets(arr,n,i+1,X);
    return inc + exc;
}
  
int main(){
    vector<int> arr{1,2,3,4,5};
    int X = 6; // here , X is the target sum

    cout<<countSubsets(arr, arr.size(),0,X);

 
return 0;
}