#include<iostream>
#include<algorithm>
using namespace std;
  
int main(){
    int arr[]={10,9,8,7,6,5,4,3,23,55,-4};
    int n = sizeof(arr)/sizeof(int);

    //Inbuilt Sort
    sort(arr,arr+n); // here, instead of going till n-1 we go till n becuse we need to go 1 out extra from the array

    //reverse the array
    reverse(arr,arr+n);

    //print the output
    for(int x :arr){
        cout<<x<<" ";
    }


 
return 0;
}