#include<iostream> 
#include<vector>

using namespace std;
  
int main(){

    vector<int> arr={1,2,3,4,5};
    //push_back o(1)
    arr.push_back(16);

    


    cout<<arr.size()<<endl<<endl;

    //capacity = acutal memory allocated to particualar vector
     cout<<arr.capacity()<<endl;

     //here size is 6 but capacity is 10 as the vector doubled its capacity
     // when new element was inserted
 
return 0;
}