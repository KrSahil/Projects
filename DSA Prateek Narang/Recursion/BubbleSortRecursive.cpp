#include<iostream>
using namespace std;

bool compare(int a, int b){
    return a>b;
}

//sort the element in increasing order
void bubble_sort_rec(int arr[], int n){
    // base case 
    if (n==1){
        return;
    }

    for ( int j=0; j<n-1;j++){
        if (arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
    bubble_sort_rec(arr,n-1);
}
  
int main(){

    int arr[] = {4,-12,2,8,1,0,2};
    int n = sizeof(arr)/sizeof(int);


    bubble_sort_rec(arr,n);

    for (int i = 0;i<n; i++){
        cout<<arr[i]<<",";
    }
 

 
return 0;
}