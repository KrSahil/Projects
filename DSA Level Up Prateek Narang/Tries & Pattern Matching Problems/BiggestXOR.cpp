#include<iostream>
using namespace std;

class Node{
public:
    Node *left; //0 (if the left pointer is not null it contains 0)
    Node *right; //1 (if the right pointer is not null it contains 1)

};

class trie{
    Node *root;
public:
    trie(){
        root = new Node(); //root will point to a new
    }

    void insert(int n){
        Node *temp = root;
        //bits of the number in the trie
        //we are given a empty trie and we insert 5, we take 5 as 32 bit no
        for (int i = 31; i>=0;i--){
            int bit = (n>>i) &1; //bit  masking
            if(bit == 0){ //we will insert on the left side
                //it is also possible left is not NULL
                if(temp->left == NULL){
                    temp->left = new Node();
                }
                //if the bit is already insertded , just go to that index
                temp = temp->left;
                //we are not putting else because this statement alsways has to be executed
            }
            else{
                //if the current bit is 1
                if(temp->right == NULL){
                    temp->right = new Node();
                }
                temp = temp->right;
            }
        }

    }
    int max_xor_helper(int value){
        int current_ans = 0;
        Node* temp = root;

        //traverse the trie in complementary way
        //if we have 1 we will look for zero and vice versa
        for (int j = 31; j>=0; j--){
            int bit = (value>>j)&1;

            if(bit == 0){
                //find the opposite value
                if(temp->right!=NULL){
                    //that means opposite value is present
                    temp = temp->right;
                    current_ans += (1<<j);
                }
                else{ //we dont have other option
                    //if we dont have opposite value
                    temp = temp->left;
                }
            }
            else{
                //complemetary case, if we have 1 we will look for zero
                if(temp->left!=NULL){
                    //if we have zero go to that node
                    temp = temp->left;
                    current_ans += (1<<j);
                }
                else{
                    //if we don't have zero in the trie below the given node
                    //then we will have to go to that node and it will not contribute anything to our ans
                    temp = temp->right;  //10000
                                         //0
                                         //------
                                         //0
                    //so we dont cotribute anything to the answer (1<<j)
                }
            }
        }
        return current_ans;

    }
    int max_xor(int *input,int n){
        int max_xor = 0;
        for(int i=0;i<n;i++){
            int value = input[i];
            insert(value);
            int current_xor = max_xor_helper(value);
            max_xor = (max_xor,current_xor);
        }

        return max_xor;
    }
};
  
int main(){

    int input[] = {3,10,5,25,9,2};
    int n = sizeof(input)/sizeof(int);
    trie t;
    cout<<t.max_xor(input,n)<<endl; 

 
return 0;
}