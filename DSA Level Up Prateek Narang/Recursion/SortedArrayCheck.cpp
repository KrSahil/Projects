#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){
    //base case
    if(n==0 || n==1){
        return true;
    }
    //rec case
    if(arr[0]<arr[1] && isSorted(arr+1,n-1)){
        return true;
    }
    return false;
}

bool isSorted2ndWay(int arr[],int i,int n){
    if(i==n-1){
        return true; //we are at last index
    }
    if(arr[i]<arr[i+1] && isSorted2ndWay(arr,i+1,n)){
        return true;
    }
    return false;
}
  
int main(){ 
    int arr[] = {1,2,3,5,4,6};
    int n = sizeof(arr)/sizeof(int);

    cout<<isSorted(arr,n);
 
return 0;
}