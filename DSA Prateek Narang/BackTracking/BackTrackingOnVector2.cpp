//Array are passed by refrecne
//vector are passed by value

#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr, int n){
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void fillArray(vector<int> &arr,int i, int n, int val){

    if(i==n){
        printArray(arr,n);
        return;
    }

    //rec case
    arr[i] = val;
    fillArray(arr, i+1 , n , val+1);

    //backteacing step
    arr[i] = -1 * arr[i];

}
  
int main(){

    vector<int> arr (100,0); //100 elements initialized to 0
    int n;
    cin>>n;

    fillArray(arr,0,n,1);
    cout<<endl;
    printArray(arr,n);
 

 
return 0;
}