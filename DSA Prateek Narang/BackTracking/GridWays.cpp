#include<iostream>
using namespace std;

int gridWay(int i, int j , int m, int n){ //i,j starting cell ,, m,n traget cell
    if(i==m-1 && j==n-1){ //we have reached the target cell
        return 1;

    }
    //corner case -> if we are at the end of the row we must not go down
    if(j>=n || i>=m){
        return 0;
    }



    int ans = gridWay(i+1,j,m,n) + gridWay(i,j+1,m,n);
//              right               bottom
    return ans;
}
  
int main(){
    int m,n;
    cin>>m>>n;

    cout<< gridWay(0,0,m,n);

 
return 0;
}