#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
  
int main(){
    unordered_set<int> uset = {1,2,3,4,8,9,9,2};
    auto search = uset.find(2);
    if(search!=uset.end()){
        cout<<"found "<<(*search)<<endl;
    }
    else{
        cout<<"Not found";
    }
    for (auto &elm:uset){
        cout<<elm<<" ";
    }
 
 return 0;
}