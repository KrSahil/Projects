#include<iostream>
using namespace std;

int ** create2DArray(int row,int column){

    int** arr = new int *[row];

    //allocate memory for each row
    for (int i=0;i<row;i++){
        arr[i] = new int[column];
    }

    //initialize array with increasing list of nos
    
    int value=0;

    for (int i=0; i<row;i++){
        for (int j =0;j<column;j++){
            arr[i][j] = value;
            value++;
        }
    }
    return arr;


}
  
int main(){
 
    //2d dynamic array

    int row, column;
    cin>>row>>column;

    int **arr = create2DArray(row,column);

        for (int i=0;i<row;i++){
            for (int j=0;j<column;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    
 
return 0;
}