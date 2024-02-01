#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data = d;
        left = right = NULL;
    }
};

Node *buildTree(){
    int d;
    cin>> d;

    if(d==-1){
        return NULL;

    }
    Node *n = new Node(d);

    (*n).left=buildTree();
    (*n).right= buildTree();

    return n;
}

Node* levelOrderBuild(){
    int d;
    cin>>d;

    Node *root = new Node(d);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        Node *current = q.front();
        q.pop();

        int c1,c2; //child 1 and child 2
        cin>>c1>>c2;

        if(c1!=-1){
            (*current).left = new Node(c1);
            q.push((*current).left);
        }
        if(c2!=-1){
           (*current).right = new Node(c2);
            q.push((*current).right); 
        }
    }
    return root;
}

void levelOrderPrint(Node *root){
    queue<Node*> q; //we can either store copy of the node or pointer to the node
                    //pointer is memory efficient
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        Node* temp = q.front();
        
        if(temp == NULL){
            cout<<endl;
            q.pop();

            //insert the new NULL for the next level
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            
            //q.pop();
            cout<<(*temp).data<<" ";
           q.pop();

            if ((*temp).left){
                q.push((*temp).left);
            }
            if ((*temp).right){
                q.push((*temp).right);
            }
        }

    }
    return;
}

//helper Function : Height of the tree
int height(Node *root){
    if(root == 0){
        return 0;
    }
    int h1 = height((*root).left);
    int h2 = height((*root).right);
    return 1 + max(h1,h2);
}


  
int main(){
    Node *root = levelOrderBuild();
    levelOrderPrint(root);
 

 
return 0;
}