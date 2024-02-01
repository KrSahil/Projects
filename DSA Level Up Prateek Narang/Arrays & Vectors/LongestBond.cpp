#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int largestBand(vector<int> arr){
    int n = arr.size();
    unordered_set<int> s;
    //for lookup we need data inside the set
    //insertion inside the set
    for(int x:arr){
        s.insert(x);
    }
    //iterate over the array
    int largestLen = 1;
    for(auto element : s){//s-set
        int parent = element-1;
        //not igore it , parent element doesnt exist
        if (s.find(parent) == s.end()){ //parent doesnt exists
            //find entire band/chain starting from element
            int next_no = element + 1;
            int cnt = 1; //initialize the count with 1 because we already found it

            while(s.find(next_no)!=s.end()){
                next_no++;
                cnt++;
            }
            if(cnt>largestLen){
                largestLen = cnt;
            }
        }
    }
    return largestLen;
}
  
int main(){
    vector<int> arr{1,9,3,0,18,5,2,4,10,7,12,6};
    cout<<largestBand(arr);
 
return 0;
}