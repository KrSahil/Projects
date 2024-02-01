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

void printAtLevelK(node*root, int k){
    if(root == NULL){
        return;
    }
    if(k==0){
        cout<<(*root).data<<" ";
        return;
    }
    //other wise we make a call at left sub tree
    printAtLevelK((*root).left,k-1);
    //make a call at right sub tree and reduce the value of k
    printAtLevelK((*root).right,k-1);
    return;
}

int printNodesAtDistanceK(node *root, node *target,int k){
    //base case
    if(root == NULL){ //if particular node is not present
        return -1;
    }

    //reached the target node
    //we are not comparing data rather we are comparing pointers
    if(root == target){
        printAtLevelK(target,k);
        return 0;
    }

    //other case -- target node is present either at the left or at right
    //find the distance of target node in the left sub tree
    int DL = printNodesAtDistanceK((*root).left,target,k);
    if(DL!=-1){
        //2 cases
        //print the current node or make a call at right

        //print the current node
        if(DL + 1 == k){
            cout<<(*root).data;
        }
        //or print some nodes in the right subtree
        else{
            //go in the some other part of the tree
            printAtLevelK((*root).right,k-2-DL);
        }
        //we can return to the parent node
        return 1 + DL;
    }

    //Exact complementary case for the right
    int DR = printNodesAtDistanceK((*root).right, target, k);
    if(DR!=-1){
        //2 cases
        //print the current node
        if(DR + 1 == k){   //maybe - weather the currennt root node should be printed or not
            cout<<(*root).data;

        }
        else{
            printAtLevelK((*root).left,k-2-DR);
        }
        return 1 + DR;
    }
    return -1; //target node is not present
}


  
int main(){
    node *root  = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);

    node *target = root->left->left;

    int k = 2;

 
return 0;
}