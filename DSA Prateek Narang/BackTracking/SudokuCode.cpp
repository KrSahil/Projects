#include<iostream>
#include<cmath>
using namespace std;

bool solveSudoku(int mat[][9],int i,int j,int n){

}
  
int main(){
    int n = 9;
    int mat[4][4]={
        {5,3,0,0},
        {6,0,0,1},
        {0,2,3,3},
        {9,5,0,0}
    };

    if(!solveSudoku(mat,0,0,n)){
        cout<<"No solution exists";
    }
 

 
return 0;
}