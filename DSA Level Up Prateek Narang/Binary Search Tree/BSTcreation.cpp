#include<iostream>
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

int main(){

    Node *root = NULL;
    int arr[] =  {8,3,10,1,6,14,4,7,13};
    
    for(int x : arr){
        root = insert(root,x);
    }

    //print
    printInOrder(root);
 
return 0;
}