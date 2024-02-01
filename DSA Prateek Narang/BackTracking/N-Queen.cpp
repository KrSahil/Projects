#include<iostream>
using namespace std;

bool canPlace(int board [][20], int n, int x, int y){
    //column
    for(int k=0; k<x; k++){
        if (board[k][y]==1){
            return false;
        }
    }
    //left diagonal
    int i = x;
    int j = y;
    while (i>=0 && j>=0){
        if (board[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }

    //right diagonal
    i=x;
    j=y;
    while(i>=0 && j<n){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void printBoard(int n,int board[][20] ){

    for (int i=0;i<n;i++){  //rows
        for (int j = 0 ; j<n ; j++){  //columns
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solveNQueen(int n, int board[][20],int i){

    //base case
    //if we reach row that is equal to N
    if(i==n){
        //print the board
        printBoard(n,board);
        return true;
    }

    //rec case
    //try to place a queen in every row
    for (int j=0; j<n; j++){
        //weather the current i,j is safe or not
        if(canPlace(board,n,i,j)){
            board[i][j]=1;
            bool success = solveNQueen(n,board,i+1); //next row: successful in solving next row or not?
                                                    //if it is true, it will return true and the position will freeze
                                                    //if it is false we try out next postion for queen  
            if(success){
                return true;
            }
            //if not true we need do back track and chane thhe postion of Q
            //backtrack
            board[i][j] = 0;
            //this will change the value of q to 0 and it will backtrack to for loop and j+1 will be executed
        }
    }
    //even after change is one row above doesnt solve the problem
    return false; //after all columns have been checked
    //we return back to parent function
}
  
int main(){
 
    int board[20][20] = {0};
    int n;
    cin>>n;

    solveNQueen(n,board,0);

 
return 0;
}