#include<iostream>
#include<vector>
using namespace std;
  
int main(){
    vector < vector <int> > arr = { //vector in which each element is a vector
        {1,2,3},
        {3,4,5,8,9}, //unlike array each row can have different number of elements
        {7,8,9}
    };
    //update a element
    arr[0][0] = 12;
    
 for (int i = 0; i<arr.size(); i++){
    for(int number: arr[i]){
        cout<<number<<" ";
    }
    cout<<endl;
 }

 
return 0;
}