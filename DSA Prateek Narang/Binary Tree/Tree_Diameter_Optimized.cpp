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

int height(Node *root){
    if(root == 0){
        return 0;
    }
    int h1 = height((*root).left);
    int h2 = height((*root).right);
    return 1 + max(h1,h2);
}

//Diameter of the tree
int diameter(Node *root){
    //base case
    if (root == 0){
        return 0;
    }

    //rec case
    int D1 = height((*root).left) + height((*root).right);
    int D2 = diameter((*root).left);
    int D3 = diameter((*root).right); 

    return max(D1,max(D2,D3));

}

//Diameter Optimised
class HDPair{
public:
    int height;
    int diameter;
};

HDPair optDimater(Node *root){
    HDPair p;

    if(root == NULL){
        p.height = p.diameter = 0;
    }

    //other wise
    HDPair Left = optDimater((*root).left);
    HDPair Right = optDimater((*root).right);

    p.height = max(Left.height,Right.height) + 1;

    int D1 = Left.height + Right.height;
    int D2 = Left.diameter;
    int D3 = Right.diameter;

    p.diameter = max (D1,max(D2,D3));
    return p;

}


  
int main(){
    Node *root = levelOrderBuild();
    levelOrderPrint(root);
    cout<<endl<<endl;
    cout<<diameter(root)<<endl;
 

 
return 0;
}