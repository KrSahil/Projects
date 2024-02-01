#include<iostream>
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

   // printLinkedList(head);
    
    recReverse(head);
    printLinkedList(head);

 
return 0;
}