#include<iostream>
using namespace std;

void spiralPrint(int arr[][10],int n, int m){
    //4 variables
    int startRow=0;
    int endRow=n-1;  //no of rows-1
    int StartColumn=0;
    int endColumn=m-1; //no of column-1

    //outer loop (Traverse array boundry)
    while(StartColumn<= endColumn and startRow<=endRow){

        //traverse start row
        for (int col=StartColumn; col<=endColumn; col++){
            cout<<arr[startRow][col]<<" ";
        }

        //end column
        for  (int row=startRow+1; row<=endRow;row++){
            cout<<arr[row][endColumn]<<" ";
        }

        //end row    -> to print row we need to make changes in column
        for (int col=endColumn-1; col>=StartColumn;col-- ){
            //avoid dublicate printing of element
            if (startRow==endRow){
                break;
            }
            cout<<arr[endRow][col]<<" ";
        }

        //start column
        for (int row=endRow-1; row>= startRow+1; row--){
            //avoid dublicate printing of element
            if (StartColumn== endColumn){
                break;
            }
            cout<<arr[row][StartColumn]<<" ";
        }

        //update the variables to point inner spiral
        startRow++;
        endRow--;
        StartColumn++;
        endColumn--;
    }

}
  
int main(){
    
    
    //print in spiral form
    int arr[][10]= {
        {1,2,3,4},
        {12,13,14,5},
        {11,16,15,6},
        {10,9,8,7}
    };
    int n =4, m=4;

    

    spiralPrint(arr,n,m);
 
return 0;
}