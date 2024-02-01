#include<iostream>
using namespace std;

void printArray(int *arr, int n){
    //print array
    for (int i = 0; i<n ; i++){
        cout<<arr[i]<<" ";
    }

}

void fillArray(int *arr,int i,int n,int val){

    //base casae
    if(i==n){
        //print array

        printArray(arr,n);
        return;
    }


    //rec case
    arr[i] = val;
    fillArray(arr,i+1,n,val+1);

}
  
int main(){
   
    int arr[100]= {0};
    int n;
    cin>>n;

    fillArray(arr,0,n,1); //we want to start from 1
    cout<<endl;
    printArray(arr,n);


 

 
return 0;
}