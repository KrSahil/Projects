#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int> &array, int s, int e){
    int i = s;
    int m = (s+e)/2;
    int j = m+1;

    //temporary array
    vector<int> temp;

    while(i<=m && j<=e){
        if(array[i]<array[j]){
            temp.push_back(array[i]);
            i++;
        }
        else{
            temp.push_back(array[j]);
            j++;
        }
    }

    //this loop breaks when one of array is exhausted     

    //copy rem elements from left arrayy
    while (i<=m){
        temp.push_back(array[i++]);
    }

    //or copy rem elements from second (right) array
    while (j<=e){
        temp.push_back(array[j++]);
    }

    //copy back the elements from temp to original
    int k = 0;
    for (int idx = s; idx <= e; idx++){
        array[idx] = temp[k++];
    }
    return;


}

void mergeSort(vector<int> &array,int s, int e){
    //base case
    if(s>=e){  //array containig one element is already sorted
        return;
    }

    //rec case
    int mid = (s+e)/2;
    mergeSort(array,s,mid);    // left part
    mergeSort(array,mid+1,e);  //right part

    //after right and left are combiened we merge them
    return merge(array,s,e);



}
  
int main(){
    
    vector<int> arr = {10,5,2,0,7,6,4};

    int s = 0;
    int e = arr.size()-1;
    mergeSort(arr,s,e);

    for (int x: arr){
        cout<<x<<" ";
    }
 

 
return 0;
}