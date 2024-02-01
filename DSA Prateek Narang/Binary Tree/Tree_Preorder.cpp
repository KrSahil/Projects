#include<iostream>
using namespace std;
//Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1 

//Output : 1 2 4 5 7 3 6 
class Node{
public:
    int data;
    Node *left;  //because it is a adress of the next node;
    Node *right;
//public:
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
     //   left =right = NULL;
        
    }
};

/*
class Tree{
    Node *root;

};
*/  
//we are using functions because in many interview question will be based upon tree

Node *buildTree(){ //return type is Node * , so every node is going to return the adress of the sub tree

    int d;
    cin>>d;

    if (d == -1){
        return NULL;
    }
    //will form a new node
    Node *n = new Node(d); //Dynamic memory Allocation
    
    (*n).left = buildTree();
    (*n).right = buildTree();
    return n;

}

void printPreOrder(Node *root){
    //base case
    if (root == NULL){
        return;
    }
    cout<<(*root).data<<" ";
    printPreOrder((*root).left);
    printPreOrder((*root).right);
}
  
int main(){
    
    Node *root = buildTree();
    printPreOrder(root);
 
return 0;
}