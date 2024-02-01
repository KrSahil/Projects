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

    if(d==-1){
        return NULL;
    }

    Node *n = new Node(d);

    (*n).left = buildTree();
    (*n).right = buildTree();

    return n; //returning the root node
}

void printPreOrder(Node *root){
    if(root == NULL){
        return;
    }

    cout<<(*root).data<<" ";
    printPreOrder((*root).left);
    printPreOrder((*root).right);

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
    
    Node *root = buildTree();
   printPreOrder(root);
   cout<<endl;
   printInOrder(root);


 
return 0;
}