#include<iostream>
using namespace std;


//prefix sum approach O(N^2)

int largestSubarraySum2(int arr[], int n){
    //prefix Sums
   // int prefix[n]={0};  -> error, we need to take a constant array
   int prefix[100]={0};
    prefix[0] = arr[0];

    for (int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
        // we used i=1 in loop because i-1 = 0(if i=1) we cannot take -1 incex
    }

    //largest sum logic
    int largest_sum=0;
        
        for(int i=0;i<n;i++){
            for(int j=i; j<n;j++){

               // int subarraySum=prefix[j]-prefix[i-1]; // but here a error can occur becuse loop stats from 0 so we can get -1 index
                int subarraySum=i>0 ? prefix[j]-prefix[i-1]:prefix[j];


               //put  a check if subarryaSum > largest_sum
               largest_sum = max(largest_sum,subarraySum);
            }
        }

    return largest_sum;

}

int main(){
    int arr[] = {-2,3,4,-1,5,-12,6,1,3};
    int n= sizeof(arr)/sizeof(int);

    cout<<largestSubarraySum2(arr,n)<<endl;


 
return 0;
}