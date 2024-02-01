#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> pairSum(vector<int> arr,int Sum){
    unordered_set<int> s;
    vector<int> result;

    for (int i = 0; i<arr.size(); i++){
        int x = Sum-arr[i];
        if(s.find(x) != s.end()){
            result.push_back(x);
            result.push_back(arr[i]);
        }
        s.insert(arr[i]);
    }
}
  
int main(){
 

 
return 0;
}