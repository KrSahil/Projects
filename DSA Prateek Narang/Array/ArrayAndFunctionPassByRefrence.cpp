#include<iostream>
using namespace std;
  
void printArray(int arr[]){
    cout<<"In function "<<sizeof(arr) <<endl;
    //only address of array

    
}


int main(){
    int arr[]={1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    
    cout<<"In main "<<sizeof(arr)<<endl;
    //here we get output -> 24 because we have array here
    printArray(arr);

    for (int i = 0; i < n; i++)
    {
       cout<<arr[i]<<endl;
    }
    
 
return 0;
}