#include<iostream>
using namespace std;


//o(n)   time o(1)

int largestSubarraySum3(int arr[], int n){
    int current_sum=0;
    int largest_sum=0;

    for(int i=0;i<n; i++){
        current_sum=current_sum+arr[i];
        if (current_sum< 0){
            current_sum=0;
        }
        largest_sum=max(largest_sum,current_sum);
    }
    return largest_sum;
}

int main(){
    int arr[] = {-2,3,4,-1,5,-12,6,1,3};
    int n= sizeof(arr)/sizeof(int);

    cout<<largestSubarraySum3(arr,n)<<endl;


 
return 0;
}