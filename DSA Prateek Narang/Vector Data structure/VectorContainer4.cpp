#include<iostream> 
#include<vector>

using namespace std;
  
int main(){

    //fill constructor
    //inintialize vector (no of outputs, output digit)
    vector<int> arr (10,7);
    

/*
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
*/

    //alternative loop
    for(int x : arr){
        cout<<x<<endl;
    }
return 0;
}