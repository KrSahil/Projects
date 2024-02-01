#include<iostream>
#include<queue>
#include<algorithm>
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
  
int main(){
    node *root  = buildTree();
 

 
return 0;
}