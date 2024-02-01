#include<iostream>
using namespace std;

bool isSoreted(int arr[], int n){
    // base case
    if (n==1 || n ==1){  // if base has only one elemnt then return true
        return true;
    }

    //recursive case
    if (arr[0]<arr[1] and isSoreted(arr+1,n-1)){ // check figure in notebook
    
    return true;
    }
    return false;
}

bool isSorted2ndWay (int arr[], int i , int n){
    if ( i == n-1){
        return true;
    }
    if (arr[i]<arr[i+1] && isSorted2ndWay(arr,i+1,n)){
        return true;
    }
    return false;

}

  
int main(){
    int arr[] = {1,2,3,9,5,6};
    int n = sizeof(arr)/sizeof(int);
 
    cout<<isSoreted(arr,n)<<endl;
    cout<<isSorted2ndWay(arr,0,n);

return 0;
}