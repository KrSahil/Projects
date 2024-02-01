#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(){
    int d;
    cin>>d;

    if (d==-1){
        return NULL;
    }
    Node *n  = new Node(d);

    (*n).left=buildTree();
    (*n).right=buildTree();


    return n;
}

void printPostOrder(Node *root){
    if (root == NULL){
        return;
    }

    
    printPostOrder((*root).left);
    printPostOrder((*root).right);
    
    cout<<(*root).data<<" ";


}

  
int main(){
    Node *root = buildTree();
    printPostOrder(root);

 
return 0;
}