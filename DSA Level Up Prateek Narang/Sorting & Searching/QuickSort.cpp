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

void quickSort(vector<int> &a, int s, int e){
    //Base case
    if(s>=e){ //1 or 0 element
        return;
    }
    //Rec case
    int p = partition(a,s,e); //places pivot element in its correct position
    quickSort(a,s,p-1); // left part
    quickSort(a,p+1,e); // right part     

}
  
int main(){
    vector<int> arr{10,5,2,0,7,6,4};
    cout<<arr.size()<<endl;
    int n = arr.size();

    quickSort(arr,0,n-1);

    for(int x :arr){
        cout<<x<<",";
    }

 
return 0;
}