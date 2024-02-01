#include<iostream>
using namespace std;

bool compare(int a, int b){
    return a>b;
}

void bubble_sort_rec2(int arr[], int n,int j){
    // base case 
    if (n==1){
        return;
    }
    if ( j == n-1){
        //reduce the problem size and reduce j to 0
         bubble_sort_rec2(arr,n-1,0);
         return;

    }

    
        if (arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    
    bubble_sort_rec2(arr,n,j+1);
}
  
int main(){

    int arr[] = {4,-12,2,8,1,0,2};
    int n = sizeof(arr)/sizeof(int);


    bubble_sort_rec2(arr,n,0);

    for (int i = 0;i<n; i++){
        cout<<arr[i]<<",";
    }
 

 
return 0;
}