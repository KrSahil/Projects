#include<iostream>
using namespace std;

int largestSubarraySum(int arr[], int n){

    int largest_sum=0;
        
        for(int i=0;i<n;i++){
            for(int j=i; j<n;j++){

                int subarraySum=0;
               for (int k=i;k<=j;k++){
                   subarraySum += arr[k];
               }
               //put  a check if subarryaSum > largest_sum
               largest_sum = max(largest_sum,subarraySum);
            }
        }

    return largest_sum;
 //find out the largest sum of subarray  

 //brute force
 // 
}
  
int main(){
    int arr[] = {-2,3,4,-1,5,-12,6,1,3};
    int n= sizeof(arr)/sizeof(int);

    cout<<largestSubarraySum(arr,n)<<endl;


 
return 0;
}