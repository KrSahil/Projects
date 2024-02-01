#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
  
int main(){
    vector<int> arr ={10,11,12,13,2,4,6,4};

    int key = 11;

    vector<int>::iterator it = find( arr.begin(),arr.end(), key);
    
  //  cout<<it; 
    //it gives the address of the bucket
    //index= Address - BaseAddress
    //          it   - arr.begin();

    if(it!=arr.end()){//check if elemetn is present
        cout<<"present at index"<<it - arr.begin();
    }
    else{
        cout<<"Element not found";
    }
return 0;
}