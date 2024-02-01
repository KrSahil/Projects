#include<iostream>
#include<queue>
using namespace std;

int join_ropes(int ropes[] , int n){
    //min heap
    //put all the ropes inside the min heap
    priority_queue<int,vector<int>, greater<int> > pq(ropes,ropes+n); //greater<int> is a inbuitl comperator
                                                    //initialize it with all the ropes we have


    //logic
    int cost = 0;

    while(pq.size() > 1){ //we will try to extract ropes from the heap
        int A = pq.top();
        pq.pop();

        int B = pq.top();
        pq.pop();

        int new_rope = (A+B);
        cost += new_rope;
        pq.push(new_rope); //we push new rope because we need to sum again it with the remaining elements  -- but in mean heap way
    }
    return cost;

}
  
int main(){
    int ropes[] = {4,3,2,6};
    int n = 4;

    cout<<join_ropes(ropes,n)<<endl; 

 
return 0;
}