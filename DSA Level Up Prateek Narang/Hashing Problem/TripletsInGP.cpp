/*
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int count_triplets(vector<int> arr, int r){
    int n = arr.size();
    //crate 2 unordered map, one for left and one for right
    unordered_map<long,long> right,left;//long inorder to avoid overflow because of ar^2

    //Initnalize the Right map woth freq and left map = 0
    for(auto x:arr){ //we pick every elment from the array
        right[x]++;
        left[x] = 0;
    }

    //compute answer by iterating from left to right
    int ans = 0;
    for (int i=0; i<n; i++){
        //1st step we remove the a[i] element
        right[arr[i]]--;
        //checking a/r and ar and their frequencies
        if(arr[i]%r==0){
            long b = arr[i];
            long a = arr[i]/r;
            long c = arr[i]*r;

            ans += left[a] * right[c];
        }

        left [arr[i]]++;
    }
    return ans;
}
  
int main(){

    int n,r;
    cin>>n>>r;
    vector<int> arr(n,0);

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<count_triplets(arr,n);

 
return 0;
}

*/

#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int count_triplets(vector<int> arr,int r){

    int n = arr.size();
    unordered_map<long,long> right,left;

    //Init the Right Map with freq, Left map = 0
    for(auto x : arr){
        right[x]++;
        left[x] = 0;
    }

    //compute by iterating left to right
    int ans = 0;
    for(int i = 0; i < n; i++){

        right[arr[i]]--;

        if(arr[i]%r==0){
            long b = arr[i];
            long a = arr[i]/r;
            long c = arr[i]*r;

            ans += left[a] * right[c];
        }

        left[arr[i]]++;

    }    
    return ans;

}

int main() {
    
    int n,r;
    cin>>n>>r;
    vector<int> arr(n,0);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<count_triplets(arr,r);

    return 0;
}