#include <iostream>
#include<vector>
#include<deque>
using namespace std;

void maxSubArrayK(vector<int> a,int k){
    
    //the idea is that deque will store only useful element
    //two types of data that are not useful
    //after isnertion of evey new element go back and pop elements if they are not useful
    //also we remove the element if they are out of bound (size of K)


    //Algorithm
    int n = a.size();

    deque<int> Q(k);
    //1. Process only the first K elements
    int i;

    for(i=0;i<k;i++){
        //Logic here ...

        while(!Q.empty() && a[i] > a[Q.back()]){
            Q.pop_back();
        }

        Q.push_back(i);

    }

    //2. Remaining the elements of the array
    for( ;i<n;i++){
        cout << a[Q.front()]<<" ";
        //Remove element from the left (contraction when an index lies outside the current window)
        while(!Q.empty() and Q.front() <=i-k){
            Q.pop_front();
        }
        while(!Q.empty() && a[i] >= a[Q.back()]){
            Q.pop_back();
        }

        //always
        Q.push_back(i);
    }


    cout<< a[Q.front()];

}

int main() {
    
    vector<int> arr{1,2,3,1,4,5,2,3,5};
    int k = 3;

    maxSubArrayK(arr,k);


    
    
    return 0;
}

