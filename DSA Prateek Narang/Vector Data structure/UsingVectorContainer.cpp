#include<iostream> 
#include<vector>

using namespace std;
  
int main(){
    //Demo vector
    vector<int> arr;   // vector datatype arrayName


    cout<<arr.size()<<endl;
    //only declared vector size is always zero


    //size = no of elements
    vector<int> arr2={1,2,3,4,5};
    cout<<arr2.size()<<endl<<endl;

    //capacity = acutal memory allocated to particualar vector

    cout<<arr2.capacity()<<endl;
 
return 0;
}