#include<iostream>
#include<vector>

using namespace std;
  
int main(){
    //vector<int> arr = {1,2,3,4,5};
    //size of the vector

    //initializing array with random numbers
    //fill constructor
    vector<int> arr(10,7);
    cout<< arr.size()<<endl; //no of elements
    arr.push_back(4);
    //print all the elements in the array
    for(int i = 0; i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
    //capacity of the vector
    cout<<arr.capacity(); //all the capacity after doubling of array
    

 
return 0;
}