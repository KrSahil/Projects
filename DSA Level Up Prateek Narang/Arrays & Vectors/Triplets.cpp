#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > triplets(vector<int> arr,int targetSum){
    //logic
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> result;

    //pick every a[i] and, solve pair sum for remaining part
    for (int i =0;i<n-3;i++){

        int j = i + 1;
        int k = n-1; //last element

        //two pointer approach
        //j is going to move forward and k  is going to move backward
        while(j<k){
            int current_sum = arr[i];
            current_sum += arr[j];
            current_sum += arr[k];

            if(current_sum == targetSum){//I already found one of my result
                result.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
            }
            else if(current_sum > targetSum){
                k--;
            }
            else{
                j++;
            }
        }

    }
    return result;
}
  
int main(){
 
    vector<int> arr{1,2,3,4,5,6,7,8,9,15};
    int S = 18;

    auto result = triplets(arr,S);

    for(auto v : result){
        for (auto no : v){
            cout<<no<<",";
        }
        cout<<endl;
    }
 
return 0;
}