#include<iostream>
using namespace std;

void selection_sort(int a[], int n){

    for (int pos = 0; pos <= n-1-1; pos++){ //n-1 last index n-1-1 last second index maybe

        int current  = a[pos];
        int min_position = pos;

        //find the minimum positon 
        for(int j=pos; j<n; j++){

            if(a[j]<a[min_position]){
                min_position=j;
            }
            
        }
        //swap outside loop
        swap(a[min_position],a[pos]);

    }
}


int main(){
 
    int arr[] ={-2,3,4,-1,5,-12,6,1,3};
    int n = sizeof(arr)/sizeof(int);
    selection_sort(arr,  n);

    for(auto  x : arr){  //auto or int 
        cout<<x<<",";
    }
 
return 0;
}