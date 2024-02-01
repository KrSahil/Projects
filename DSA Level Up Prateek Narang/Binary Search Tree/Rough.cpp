#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node *insert(Node* root, int key){
    if(root == NULL){
        return new Node(key);
    }
    //rec case
    if(key < (*root).data){
        (*root).left = insert((*root).left,key);
    }
    else{
        (*root).right = insert((*root).right,key);
    }
    return root;
    //this overwrites the data all the times
}

void printInOrder(Node *root){
    if(root == NULL){
        return;
    }
    printInOrder((*root).left);
    cout<<(*root).data<<" ";
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