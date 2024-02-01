#include<iostream>
#include<vector>
using namespace std;

int trappedWater(vector<int> heights){
    //corner case
    //if two bars no water can be trapped
    int n = heights.size();
    if(n<=2){
        return 0;
    }

    //Left Max, Right Max
    vector<int> left(n,0); //n elements, all of the are 0 
    vector<int> right(n,0);
    left[0] = heights[0]; //initializing left of 0 with height of 0
    right[n-1] = heights[n-1];
 
    for(int i = 1; i<n; i++){ //here, we initialized i with 1
        left[i] = max(left[i-1],heights[i]);
        right[n-i-1] = max(right[n-i],heights[n-i-1]);

    } //this will compute left and right array for us
     
    //water
    int water = 0;
    for (int i=0; i<n;i++){
        water += min(left[i],right[i])- heights[i];
    }


    return water;
}
  
int main(){
 
    vector<int> water = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trappedWater(water)<<endl;
    return 0;

 
return 0;
}