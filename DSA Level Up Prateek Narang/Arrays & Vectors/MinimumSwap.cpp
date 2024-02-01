#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countMinSwaps(vector<int> arr){
    //know the acutual positions (sortng)
    //store the current indices
    pair<int,int> ap[n];
    for(int i = 0; i<n; i++){
        ap[i].first = arr[i];
        ap[i].second = i;
    }

    //sorting
    sort(ap,ap+n);

    //see notebook - now we are focused on old indicies of ap - 4,3,2,1,0
    //new indices                                               0,1,2,3,4
    //build the logic
    vector<bool> visited(n,false);  
    
    for(int i = 0; i<n; i++){
        //if element is visited || is at the right position
        int old_position = ap[i].second;
        if(visited[i]==true || old_position == i){
            continue;
        }
        //visiing the element(index) for the first time
         int node = i;
         int cycle = 0;
         

         while(visited[node]==false){
            visited[node] = true;
            int next_node= ap[node].second;
            node = next_node;
            cycle+=1;
         }
        ans += (cycle-1);
    }                                  

    return ans;
}
  
int main(){
    vector<int> arr{5,4,3,2,1};
    cout<<countMinSwaps(arr); 
    return 0;
}