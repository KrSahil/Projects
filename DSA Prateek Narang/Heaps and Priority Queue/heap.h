#include<vector>
using namespace std;

class Heap{
    //we can create static array but that might not be useful
    vector<int> v;

    void heapify(int i){
        //left index 2i
        //reigh index 2i + 1
        int left = 2*i;
        int right = 2*i + 1;

        int minIdx = i;
        if (left < v.size() && v[left] < v[i]){      //we dont want to go outside of tree so we add exceotion (left < v.size())
            minIdx  = left;            
    }
        if (right < v.size() && v[right] < v[minIdx]){      //if right element lise  inside tree and righ telemnet is smaller than ith index
                                                            // here we dont compare the value with v[i] beause we already have replaced it value with min
            
            minIdx = right;
        }

        if (minIdx!=i){ //minimum index is not equal to original index
             swap(v[i],v[minIdx]);
             //recursively we will call heapify 
             heapify(minIdx);
        } //O(logN)
    }
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

        //return min element
        int top(){
            return v[1];
        }

        //remove min element
        void pop(){
            //1. swap first and last tuple_element
            int idx = v.size()-1;
            swap(v[1],v[idx]);
            v.pop_back();
            heapify(1);
        }

        bool empty(){
            return v.size() ==1;
        }


};
//insertion
//O(logN) - worst case
//because height of the tree is logN