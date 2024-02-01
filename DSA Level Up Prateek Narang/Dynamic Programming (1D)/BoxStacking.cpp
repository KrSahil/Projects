#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compareBoxes(vector<int> b1,vector<int>b2){
    return b1[2]>b2[2]; //if hight of box b1 is smaller than b2
}

//either u use less than in both the function, or use greater than in both of the function

bool canPlace(vector<int> b1,vector<int>b2){
    //it is possible u have 2 same height. so when u are stacking we must ensreu top box has lesser height
    if(b1[0]>b2[0] && b1[1]>b2[1] && b1[2]>b2[2]){
        return true;
    }
    return false; //we will not do the stacking
}

int boxStacking(vector<vector<int>> boxes){

    //1. Sorting 
    sort(boxes.begin(),boxes.end(),compareBoxes);

    int n = boxes.size();
    //2. DP
    //in the begining each box will be stored independently , it will not be stacked
    vector<int> dp(n+1,0);

    for(int i = 0;i<n; i++){
        dp[i] = boxes[i][2]; //height of ith box
    }
    /*
    we created a dp array extracting height
    1
    2
    3
    4
    5
    8
    */

   //
    for(int i = 1; i<n; i++){
        //cheeck for all boxes whose index is less than i
        for(int j = 0; j<i; j++ ){
            if(canPlace(boxes[j],boxes[i])){ //can i place jth box top of ith box
                int current_height = boxes[i][2];

                //we are adding the height of entire stack(if all condition satisfied) , instead of just one box
                if(dp[j] + current_height > dp[i]) { //current hight is greated than any of the ans u have formed so far
                    dp[i] = dp[j] + current_height;
                }
            }
        }
    }
    //u can use a loop to find max height in dp array
    int max_height = 0;
    for (int i = 0; i<n; i++){
        max_height = max(max_height,dp[i]);
    }
    return max_height;
}
  
int main(){

    vector<vector<int>> boxes = {
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,3,4},
        {2,2,1},
        {4,4,5},
    };

    int height = boxStacking(boxes);

    cout<<"Max heighth " <<height<<endl;

    return 0;
}