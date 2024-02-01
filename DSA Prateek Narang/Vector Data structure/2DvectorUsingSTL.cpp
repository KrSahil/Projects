#include<iostream>
#include<vector>
using namespace std;

//2d vector
//2d vector is a replacement for 2d Array

  
int main(){
    vector< vector<int> > arr = {
                                  {1,2,3},
                                  {4,5,6,7},
                                  {7,8,9,10,11},
                                  {11,12}
                                };
         //unlike 2d array each row can have different element
    
    //arr.size() -> no of rows
    for(int i=0;i<arr.size();i++){
        for (int number:arr[i]){
            cout<<number<<" ";
        }
        cout<<endl;
    }
return 0;
}