#include<iostream> 
#include<vector>

using namespace std;
  
int main(){

    vector<int> arr={1,2,3,4,5};
    

    
    //delete last element
    arr.pop_back();
    //insert new element
    arr.push_back(16);

    //print all the element of the vector
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }

return 0;
}