#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

//pre order bild of the binary tree

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

//Input : 1 2 4 2 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node *buildTree(){
    int d;
    cin>>d;


    if(d==-1){
        return NULL;
    }
    node *n = new node(d);
    (*n).left = buildTree();
    (*n).right = buildTree();
}

int height(node *root){
    if(root == NULL){
        return 0;
    }
    int h1 = height((*root).left);
    int h2 = height((*root).right);
    return 1 + max(h1,h2);
}



// Diameter
//time complexity - O(N^2)
int diameter(node*root){
    //base case
    if(root == NULL){
        return 0;
    }
    //rec case
    //option d1
    int D1 = height((*root).left) + height((*root).right);
    //option d2
    int D2 = height((*root).left);
    int D3 = height((*root).right);

    return max(D1,D2,D3);

}

class HDPair{
public:
    int height;
    int diameter;
};

HDPair optDiameter(node*root){
    HDPair p;
    if(root == NULL){
        p.height = p.diameter = 0;
        return p;
    }
    //othrewise
    HDPair Left = optDiameter((*root).left);
    HDPair Right = optDiameter((*root).right);

    p.height = max(Left.height,Right.height)+1;

    int D1 = Left.height + Right.height;
    int D2 = Left.diameter;
    int D3 = Right.diameter;

    p.diameter = max(D1,max(D2,D3));
    return p;
}

int replaceWithSum(node *root){
    //base case
    //2 corner cases if We have NULL or leaf nodes
    if(root == NULL){
        return 0;
    }
    if((*root).left==NULL && (*root).right == NULL){
        return (*root).data;
    }
    //rec case
    int LS = replaceWithSum((*root).left);
    int RS = replaceWithSum((*root).right);

    int temp = (*root).data;
    (*root).data = LS + RS;
    
    return (*root).data + temp;

}

//o(N)
pair<int,bool> isHeightBalanced(node *root){ //return type is of pair and bull
    //both left and right should be balaced
    pair<int,bool> p , Left, Right; //both left sub tree and right sub tree are going to return a pair

    if(root == NULL){
        p.first = 0;  //p.first denotes height
        p.second = true; //denotes boolean value ---- balanced
        return p;         
    }
    //rec case
    Left = isHeightBalanced((*root).left);
    Right = isHeightBalanced((*root).right);
    //this is a bottom up approch and we need answers from both left sub tree and right sub tree
    
    //p.first = max(Left.first, Right.first) + 1;
    int height = max(Left.first, Right.first) + 1;
    //              H1          H2
    //for p.second we need to check three conditions
    //abs = absolute value
    if(abs(Left.first - Right.first) <= 1 && Left.second && Right.second){      // left.second & right.second are true
        //if all of these conditions is satisfied then our tree is balanced
        return make_pair(height,true);
        //we are returning 
    }
    //height remains the same but balancedTree is fasle
    return make_pair(height,false);
     
}
  
int main(){
    node *root  = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);

    pair<int,bool> p = isHeightBalanced(root);
    if(p.second){
        cout<<"yes the tree is balanced";
    }
    else{
        cout<<"No it's not a heght balaned tree";
    }

 

 
return 0;
}