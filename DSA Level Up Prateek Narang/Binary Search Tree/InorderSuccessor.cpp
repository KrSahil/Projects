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

Node *inorderSuccessor(Node *root,Node *target){
    //2 cases
    //If right subtree exists
    if((*target).right!=NULL){
        Node *temp = (*target).right;
        while((*temp).left != NULL){
            temp = (*temp).left;
        }
        return temp;
    }
    //otherwise
    //we will traverse from root to leaf
    Node *temp = root;
    Node *succ = NULL;

    while(temp!=NULL){
        if(temp->key > target->key){
            succ = temp;
            temp = (*temp).left;
        }
        else if(temp->key < target->key){
            temp = temp->right;
        }
        else{
            //if the values are equal we are going to break the rule
            break;
        }
    }
    return succ;                           
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