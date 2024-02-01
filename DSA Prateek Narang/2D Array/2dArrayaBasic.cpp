#include<iostream>
using namespace std;


//passed by refrence
//any change we make here is reflected in main function
void print(int arr[][100],int n,int m){  //Rows may be optional but column is compulsary to mention
    //print
    for(int i=0; i<n ; i++){
        for (int j=0; j<m;j++){
            cout<<arr[i][j]<<" ";


        }
        cout<<endl;
    }
}


int main(){
    int n,m;
    //n - rows  ;  m  - column

    //constraints will be given in most of the question
    int arr[100][100];

    cin>>n>>m;

    //take input
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            cin>> arr[i][j];
        }

    }

    //calling print function
    print(arr,n,m);
 

 
return 0;
}