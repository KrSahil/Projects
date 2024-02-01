#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &a, int s, int e){
    int pivot = a[e];
    int i = s-1;

    for(int j = s; j<e; j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    //bring pivot to its correct index
    swap(a[i+1],a[e]);
    return i + 1;
}

int quickSelect(vector<int> &a, int s, int e, int k){
    int p = partition(a,s,e);
    if(p==k){
        return a[p];
    }
    else if(k<p){
        return quickSelect(a,s,p-1,k);
    }
    else{
        return quickSelect(a,p+1,e,k);
    }
}


  
int main(){
    vector<int> arr{10,5,2,0,7,6,4};
    //cout<<arr.size()<<endl;
    int n = arr.size();

    int k;
    cin>>k;

    cout<<quickSelect(arr,0,n-1,k);
 
return 0;
}