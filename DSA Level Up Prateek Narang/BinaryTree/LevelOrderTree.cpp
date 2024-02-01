#include<iostream>
#include<queue>
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

void levelOrderPrint(node*root){
    queue<node*> q; // eiher it should be node or node* 
                    //if we simply put an integer indide the queue there is no we can refer it's childern
                    //it is possible only if u store either copy of the node or pointer to the node
                    //node * is more efficient because we dont want to use extra memory space
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        if(temp == NULL){
            cout<<endl;
            q.pop();
            //insert a new null for the next level
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            //print the data we got 
            cout<<(*temp).data;
            if((*temp).left ){ //if temp->left exists
                q.push((*temp).left);
            }
            if((*temp).right){
                q.push((*temp).right);
            }
        }
    }
    return;
}


  
int main(){
    node *root  = buildTree();
 

 
return 0;
}