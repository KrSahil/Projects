#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> mergeKArrays(vector<vector<int> > arrays){
    //logic
    int k = arrays.size();
    cout<<"Array size: "<<k<<endl;
    //triplet priority queue - element, array index, element index
    priority_queue< vector<int>, vector<vector<int> >, greater<vector<int> > > q;
    //each element will be of type vector int
    //and they will have vector of vector int
    //greater<vector<int>> comperator function- that is going to compare on the basic of 0th element of the vector

    //next step, create a output vector
    vector<int> output;

    //initialize the heap
    for(int i = 0; i<k; i++){
        int element = arrays[i][0]; //pick 0th element of each row
        q.push({element,i,0}); //(1,0) (2,0) (3,0) may be
    } //we extract 0th element from all the k arrays

    //start poping element  &  pushing more elements
    while(!q.empty()){
        auto top = q.top();
        q.pop(); //removing the top most element
    
        //we are going to print it or push it to output vector
        //top is triplet and it is going to contain 3 elements
        //so we extract them
        int element = top[0];
        int a_idx = top[1];
        int e_idx = top[2]; //element index

        output.push_back(element);

        //check if next index exists or not in the array
        //did not understand---
        if (e_idx + 1 < arrays[a_idx].size()){
            int next_element = arrays[a_idx][e_idx+1];
            q.push({next_element,a_idx,e_idx+1});

        }
    }
    return output;
}
  
int main(){

    vector<vector<int> > arr = {{10,15,20,30},
                                {2,5,8,14,24},
                                {0,11,60,90}
                                };

    //various approaches
    vector<int>result = mergeKArrays(arr);
    //final result in a single vector

    //output
    for(auto x:result){
        cout<<x <<" ";
    }

 
return 0;
}