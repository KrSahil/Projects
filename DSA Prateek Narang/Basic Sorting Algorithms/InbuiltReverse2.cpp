#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
    return a>b;
}
  
int main(){
    int arr[]={10,9,8,7,6,5,4,3,23,55,-4};
    int n = sizeof(arr)/sizeof(int);

    //Inbuilt Sort  reverse
    sort(arr,arr+n,compare); // here, we pass the function as a parameter to another function
    //it is not a function parameter


    //print the output
    for(int x :arr){
        cout<<x<<" ";
    }


 
return 0;
}