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
    //because 
    if(head==NULL){
        head = new node(data);
        return;
    }
    //otherwise
    node *n = new node (data);
    (*n).next = head;
    head = n;
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

 
return 0;
}