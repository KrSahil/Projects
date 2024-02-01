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


class LinkedList{
    public:
        Node *head;
        Node *tail;
};

LinkedList tree2LL(Node *root){
    
    LinkedList l;
    //Base case
    if(root == NULL){
        l.head = l.tail = NULL;
        return l;
    }

    //4 cases
    if((*root).left == NULL && (*root).right == NULL){
        //case of leaf node
        l.head = l.tail = root;
        //this will form a linked list of one node
        
    }
    else if((*root).left != NULL  && (*root).right == NULL){
        LinkedList leftLL = tree2LL((*root).left);
        //(*(leftLL.tail)).right = root;
        leftLL.tail -> right = root;

        l.head = leftLL.head;
        l.tail =root;
    }
    else if(root->left == NULL && root -> right != NULL){
        LinkedList rightLL = tree2LL((*root).right);
        (*root).right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
    }
    else{
        LinkedList leftLL = tree2LL((*root).left);
        LinkedList rightLL = tree2LL((*root).right);
        leftLL.tail = root;
        (*root).right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }
    return l;
}

int main(){

    Node *root = NULL;
    int arr[] =  {8,3,10,1,6,14,4,7,13};
    
    for(int x : arr){
        root = insert(root,x);
    }

    LinkedList l = tree2LL(root);

    Node*temp = l.head;
    while(temp!=NULL){
        cout<<temp->key;
        temp = temp->right;
    }

 
return 0;
}