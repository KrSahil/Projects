#include<iostream>
#include<algorithm>
using namespace std;

class node{
    
public:
    int data;
    node* next;

        node(int data){
            this->data = data;
            next = NULL;
        }
};

//-------------------------linked list------------//

void insertAtHead(node * &head,int data){
    //              pass by refrence 
    if(head==NULL){
        head = new node(data);
        return;
    }
    //otherwise
    node *n = new node (data);
    (*n).next = head;
    head = n;
}

void insertInMiddle(node * &head,int data,int position){
    if(position == 0){
        insertAtHead(head,data);
    }
    else{
        node * temp = head; //temporary pointer that points to head
        for (int jump = 1; jump<=position-1; jump++ ){
            temp = (*temp).next;
        }
        node *n = new node(data);
        (*n).next = (*temp).next;
        (*temp).next = n;
    }
}

node *recReverse(node * head){
    //base case
    if(head==NULL || (*head).next == NULL){  // if head is null or we are at  last node 
        return head;
    }
    //otherwise
    node* smallHead = recReverse((*head).next);
    (*(*head).next).next = head;
    (*head).next = NULL;
    return smallHead;
}

void iterativeReverse(node *&head){
    node *prev = NULL;
    node *current = head;
    node *temp;

    while (current!= NULL){
        //store next
        temp = (*current).next;
        //update the current
        (*current).next = prev;

       //prev and current
        prev = current;
        current = temp;
    }
    head = prev;
    return;
}

node* KReverse(node *head, int k){
    //base case
    if(head == NULL){
        return NULL;
    }

    //reverse the first K nodes
    node *prev = NULL;
    node *current = head;
    node *temp;
    int cnt =  1;

     while (current!= NULL && cnt<= k){
        //store next
        temp = (*current).next;
        //update the current
        (*current).next = prev;

       //prev and current
        prev = current;
        current = temp;
        cnt++;
    }
    //we know temp is one step ahead here
    if(temp!=NULL){
        (*head).next = KReverse(temp,k);
    }
    return prev;
}

void* merge(node* a, node *b){
    //base case
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }

    //rec case
    node *c; //temporary head call, will be created in every reursive call

    if((*a).data < (*b).data){
        c = a;
        //next of c will make connect itself with the recursive function
        (*c).next = merge((*a).next,b);
    }
    else{
        c = b;
        c->next = merge(a,b->next);
    }
    return c; 
}

void printLinkedList(node *head){
    while(head!=NULL){
        cout<<(*head).data<<"-->";
        head = (*head).next;
    }
    cout<<endl;
}



int main(){
    node* head = NULL;
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);

    printLinkedList(head);
    
    //KReverse(head,3);   //this will  give us the error
    //we also need to update our head
    head = KReverse(head,3);
    printLinkedList(head);

 
return 0;
}