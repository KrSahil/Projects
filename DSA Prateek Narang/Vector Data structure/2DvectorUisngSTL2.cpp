#include<iostream>
#include<vector>
using namespace std;
 
int main(){
    vector< vector<int> > arr = {
                                  {1,2,3},
                                  {4,5,6,7},
                                  {7,8,9,10,11},
                                  {11,12}
                                };

        //updating the values of a vector
        arr[0][0]+=10;
         
    for(int i=0;i<arr.size();i++){
        for (int number:arr[i]){
            cout<<number<<" ";
        }
        cout<<endl;
    }
return 0;
}