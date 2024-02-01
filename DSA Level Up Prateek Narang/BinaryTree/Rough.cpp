#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

Node(int d){
    data = d;
    Node*left = NULL;
    Node*right = NULL;
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

    return n;
}

void levelOrderPrint(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *temp = q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            //print the data we got
            cout<<temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;
}

Node *levelOrderBuild(){
    int d;
    cin>>d;

    Node *root = new Node(d);

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        Node *current = q.front();
        q.pop();
        int c1,c2;

        while(c1!=-1){
            (*current).left  = new Node(c1);
            q.push((*current).left);
        }
        while(c2!=-1){
            (*current).right = new Node(c2);
            q.push((*current).right);
        }
    }
    return root;

}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int h1 = height((*root).left);
    int h2 = height((*root).right);
    return 1+max(h1,h2);
}

int diameter(Node* root){
    if (root == NULL){
        return 0;
    }
    
    int D1 = height((*root).left)+height((*root).right);
    int D2 = height((*root).left);
    int D3 = height((*root).right);

    return max(D1,D2,D3);
}

class HDPair{
public:
    int height;
    int diameter;
};

int replaceWithSum(Node *root){
    //base case
    if(root == NULL){
        return 0;
    }
    if((*root).left == NULL && (*root).right == NULL){
        return (*root).data;
    }
    //Rec case
    int LS = replaceWithSum((*root).left);
    int RS = replaceWithSum((*root).right);

    int temp = (*root).data;
    (*root).data = LS + RS;

   // return LS + RS + temp;
    //or 
    return (*root).data + temp;
}

pair<int,bool> isHeightBalanced(Node*root){
    pair<int,bool> p, Left, Right;
    
    if(root == NULL){
        p.first = 0; //denotes height
        p.second = true; //is balanced
        return p;
    }

    Left = isHeightBalanced((*root).left);
    Right = isHeightBalanced((*root).right);

    int height = max(Left.first,Right.first)+1;

    if(abs(Left.first-Right.first)<= 1 && Left.second && Right.second){ //if both left and right are true
        return make_pair(height,true);

    }
    else{
        return make_pair(height,false);
    }
}


class Pair{
public:
    int inc;
    int exc;
};

Pair maxSubsetSun(Node *root){
    Pair p;
    //base case
    if(root == NULL){
        p.inc = p.exc = 0;
        return p;
    }

    //base case
    Pair Left = maxSubsetSun((*root).left);
    Pair Right = maxSubsetSun((*root).right);

    p.inc = (*root).data + Left.exc + Right.exc;
    p.exc = max(Left.inc,Left.exc) + max(Right.exc,Right.inc);

    return p;
}

void printAtLevelK(Node*root,int k){
    if(root == NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printAtLevelK((*root).left,k-1);
    printAtLevelK((*root).right,k-1);
    return;
}

int printNodesAtDistanceK(Node*root, Node *target, int k){
    if(root == NULL){
        return -1;
    }

    if(root == target){
        printAtLevelK(target,k);
        return 0;
    }

    int DL = printNodesAtDistanceK((*root).left,target,k);
}

//helper function
void traverseTree(Node*root, int d, map<int, vector<int> > &m){
    if(root == NULL){
        return;
    }
    m[d].push_back((*root).data);
    traverseTree((*root).left,d-1,m);
    traverseTree((*root).right,d+1,m);
}

void verticalOrderPrint(Node *root){
    map<int, vector<int> > m;
    int d = 0;

    traverseTree(root,d,m);

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
    Node *root = buildTree(); 
 
return 0;
}