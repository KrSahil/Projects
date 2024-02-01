#include<iostream>
using namespace std;

class Node{
public:
    int key;
    Node *left;
    Node *right;

    Node (int key){
        this->key = key;
        left = right = NULL;
    }
};

Node * insert(Node *root, int key){  //it is taking root pointer to node and key as argument

    if (root == NULL){  //Tree doesnt exists
        return new Node(key);
    }

    //rec case
    if (key < (*root).key){
        (*root).left = insert((*root).left,key);
    }
    else{
        (*root).right = insert ((*root).right,key);
    }


    return root; //returns address

}

//O(H)
bool search(Node *root,int key){
    if (root == NULL){
        return false;
    }
    if((*root).key==key){
        return true;

    }
    if(key < (*root).key){

        return search((*root).left,key);

    }
        return search((*root).right,key);
}

void printInOreder(Node *root){
    if (root == NULL){
        return;
    }
    //left, root, right
    printInOreder((*root).left);
    cout<< (*root).key <<",";
    printInOreder((*root).right);
}
  
int main(){
    Node *root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for (int x :arr){
        root = insert(root,x);
    }

    printInOreder(root);

    int key;
    cin>>key;

    cout<<search(root,key)<<endl;
    
 
return 0;
}