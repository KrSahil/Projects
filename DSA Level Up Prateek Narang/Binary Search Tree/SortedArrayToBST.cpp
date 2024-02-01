#include<iostream>
#include<vector>
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

Node *sortedArrayToBST(vector<int> arr, int start, int end){
    //Return NULL if s>e , because no array element are there
    if(start>end){
        return NULL;
    }

    //get the middle element and make it root
    int mid = (start+end)/2;
    Node *root = new Node(arr[mid]);

    //create left and right subtree recursively 
    (*root).left = sortedArrayToBST(arr,start,mid-1);
    (*root).right = sortedArrayToBST(arr,mid+1, end);

    return root;
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

    cout<<sortedArrayToBST(arr,0,n-1);
 
return 0;
}