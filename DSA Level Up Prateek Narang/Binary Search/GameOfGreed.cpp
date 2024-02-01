#include<iostream>
using namespace std;

bool divideAmongK(int arr[], int n, int k, int min_coisn){
    int partitions = 0;
    int current_friend = 0;

    for (int i = 0; i<n; i++){
        if(current_friend + arr[i] >= min_coisn){
            partitions +=1;
            current_friend = 0;

        }
        else{
            current_friend += arr[i];
        }
    }

    return partitions >= k;

}

int k_partition(int *arr, int n, int k){
    int s = 0;
    int e = 0;
    for(int i = 0; i<n; i++){
        e += arr[i];
    }
    
    int mid;
    int ans;

    while (s<=e){
        mid = (s+e)/2;
        bool isPossible = divideAmongK(arr,n,k,mid);

        if(isPossible){
            s = mid + 1;
            ans = mid;
        }
        else {
            e = mid -1;

        }
    }
    return ans;
}
  
int main(){

    //your code goes here
    int a[] = {1,2,3,4};
    int n = sizeof(a)/sizeof(int);
    int k = 3;

    cout<<k_partition(a,n,k)<<endl;
 

 
return 0;
}