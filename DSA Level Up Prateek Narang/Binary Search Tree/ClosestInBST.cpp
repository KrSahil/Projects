#include<iostream>
#include<climits>
using namespace std;

class Node{
    public:
        int key;
        Node *left;
        Node *right;

    Node(int key){
        this-> key = key;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int key){
    
    //base case
    if(root == NULL){
        return new Node(key);
    }
    //REc case
    if(key<(*root).key){
        (*root).left = insert((*root).left,key); //should point to a new sub tree that is returned by the insert function

    }
    else{
        //same thing can be done for the right sub tree
        (*root).right  = insert((*root).right,key);
    }
    return root;

}

void printInOrder(Node* root){

    if(root == NULL){
        return;
    }
    //left,root, right
    printInOrder((*root).left);
    cout<<(*root).key<<" ,";
    printInOrder((*root).right);

}

int findClosestInBST(Node *root, int target){

    int closest; //what we need to find
    int diff = INT_MAX;

    Node *temp = root; //temporary pointer at the root of the tree
    
    while (temp!=NULL){ //while the temporary pointer is not NULL we are going to travers the tree from root to leaf
        int current_diff = abs((*temp).key - target);

        if(current_diff == 0){
            //we exactly found the target node
            return temp->key;
        }

        if(current_diff<diff){
            diff = current_diff;
            closest = (*temp).key;
        }
        //right or left
        if((*temp).key < target){
            temp = (*temp).right;
        }
        else{
            temp = (*temp).left;
        }
    }
    return closest;
}

int main(){

    Node *root = NULL;
    int arr[] =  {8,3,10,1,6,14,4,7,13};
    
    for(int x : arr){
        root = insert(root,x);
    }

    //print
    printInOrder(root);
    cout<<endl;
    cout<<findClosestInBST(root,17);
 
return 0;
}