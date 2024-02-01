#include<iostream>
#include<queue>
#include<map>
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

//helper
void traverseTree(node*root, int d, map<int, vector<int> > &m ){ //key is the disatance and value is vector of inteers
                                                        //and we can pass this object by refrence because we don't want to create copies of map in every call
    if(root == NULL){
        return;
    }
    //otherwise, at current node we are at distance 'd'
    m[d].push_back((*root).data);
    traverseTree((*root).left, d-1,m);
    traverseTree((*root).right,d+1,m);


}

void verticalOrderPrint(node * root){
    map<int, vector<int> > m;
    int d = 0; //current distance from the root node is 0

    traverseTree(root,d, m);

    // - 1  -> (....) 0-> (....)
    //key is mapped with list on nodes
    //we will try to traverse this key value pair

    //Keys are sorted {-2,-1,0,1,2,3,....}
    for(auto p:m){
        int key = p.first;
        vector<int> line = p.second;

        for(auto data:line){
            cout<<data<<" ";
        }

        cout<<endl;
    }
    return;

}
  
int main(){
    node *root  = buildTree();
 

 
return 0;
}