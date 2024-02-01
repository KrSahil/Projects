#include<vector>
using namespace std;

class Heap{
    //we can create static array but that might not be useful
    vector<int> v;
public:
     Heap(int default_size=10){
        v.reserve(default_size+1);  //reserve the space // we added because we are not going to use 0th position
        v.push_back(-1); //0th index is reserved with -1 , we will start storing from st index     
     }

        void push(int data){
            //add data to end of the heap
            v.push_back(data);

            int idx = v.size()-1;
            int parent = idx/2;

            while(idx>1 && v[idx] < v[parent]){
                swap( v[idx] , v[parent]);
                idx = parent;
                parent = parent/2;
            }
        }
};

//insertion
//O(logN) - worst case
//because height of the tree is logN