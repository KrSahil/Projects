#include<iostream>
#include<algorithm>
using namespace std;


  
int main(){
    int arr[]={10,9,8,7,6,5,4,3,23,55,-4};
    int n = sizeof(arr)/sizeof(int);

    //ascending sort
    //sort(arr,arr+n);

    //Descending Sort 3 rd way,, we add greater<int>() in the end
    sort(arr,arr+n,greater<int>());


    //print the output
    for(int x :arr){
        cout<<x<<" ";
    }


 
return 0;
}