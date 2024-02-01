#include<iostream>
#include<vector>>
using namespace std;

class Node{
public:
    int key;
    Node *left;
    Node *right;

    Node(int key){
        this-> key = key;
        left = right = NULL;
    }
};

Node * insert(Node *root,int key){

    if (root == NULL){
        return new Node(key);
    }

    //rec case
    if (key < (*root).key){
        (*root).left =insert ((*root).left,key);
    }
    else{
        (*root).right= insert ((*root).right,key);
    }
    return root;

}

bool search(Node *root,int key){
    if(root == NULL){
        return false;
    }

    if((*root).key == key){
        return true;
    }
    if(key < (*root).key){

        return search((*root).left,key);

    }   //this will traverse right direction
        return search((*root).right,key);
}

void PrintInOrder(Node *root){
    if(root == NULL){
        return;
    }

    PrintInOrder((*root).left);

    cout<< (*root).key<<",";

    PrintInOrder((*root).right);
}

Node *findMin(Node *root){
    while ((*root).left != NULL){
        root = (*root).left;
    }
    return root;
}

Node *remove(Node *root , int key){ //it reurns address of the updated tree
    //1st we seacrch

    if (root == NULL){
        return NULL;
    }
    else if(key < (*root).key){
        (*root).left = remove((*root).left,key);
    }
    else if(key > (*root).key){
        (*root).right = remove((*root).right,key);
    }

    // till now only searching is done

    //now deletion code
    else{
        //when current node matches the key
        //three cases
        //-------1 = No child
        if((*root).left==NULL && (*root).right==NULL){
            delete root;
            root = NULL;    //we return null value
           // return root;   //we can return root in the end because it will be true for all the cases
        }
        //--------2 = 1 child
        else if  ((*root).left == NULL){
            Node *temp = root;
            root = (*root).right;
            delete temp;
        }
        else if((*root).right == NULL){
            Node *temp = root;
            root = (*root).left;
            delete temp;
        }
        //------3 = 2 child
        else{
            Node *temp = findMin((*root).right);

            //we are only going to copy the data, we are not swapping
            (*root).key = (*temp).key;
            (*root).right = remove((*root).right,(*temp).key);
        }
    }
    return root;
}

void printInRange(Node *root, int k1, int k2){

    if (root == NULL){
        return;
    }

    if ((*root).key >= k1 && (*root).key <= k2){
        //call on both the sides
        printInRange((*root).left,k1,k2);
        cout<<(*root).key<<" ";
        printInRange((*root).right,k1,k2);
    }
    else if ((*root).key > k2){
        printInRange((*root).left,k1,k2);
    }
    else{
        // (*root).key < k1
        printInRange((*root).right,k1,k2);
    }
}

void printRoot2leaf(Node *root, vector<int> &path){

    //2 BASE CASES
    if (root == NULL){
        return;
    }

    if ((*root).left == NULL && (*root).right == NULL){
        //print the vector
        for (int Node:path){
            cout<<Node<<"->";
        }
        
        cout<<(*root).data<<" ";
        cout<<endl;
        return;
    }

    //rec case

    path.push_back((*root).data);
    printRoot2leaf((*root).left,path);
    printRoot2leaf((*root).right,path);

    //back tracking
    path.pop_back();
    return;
}


int main(){
    Node *root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for (int x :arr){
        root = insert(root,x);
    }

    PrintInOrder(root);
    cout<<endl;

  //  int key;
   // cin>>key;

   // root = remove(root,key);


   // PrintInOrder(root);

   // cout<<search(root,key)<<endl;
   cout<<endl;
    printInRange(root,5,12);

    vector<int> path;
    printRoot2leaf(root,path);


 
return 0;
}