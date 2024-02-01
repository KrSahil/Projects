#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int d){
        data = d;
        next = NULL;
    }

};
  
class List{
public:
    Node *head;
    Node *tail; //these two are going to store thee head and tail of the linked list

List(){  //Wehenever, we create   a new list we make head and tail as NULL
    head = NULL;
    tail = NULL;
}


void push_front(int data){
     if (head = NULL){   //that means tail will automatically be NULL
        Node * n = new Node(data); //creating new node whose data is data
            //dynamic memory allocation
        head = tail = n;
        return;
     }
     else{
        Node * n = new Node(data);
        (*n).next = head;
        head = n;
     }
}

void push_back(int data){
    if (head = NULL){
        Node *n = new Node(data);
        head = tail = n;
    }
    else{
        Node *n = new Node(data);
        (*tail).next=n;
        tail =n;
    }

}

};

int main(){
 
    List l;
    l.push_back(3);
    l.push_front(2);
    l.push_front(1);
    l.push_back(4);

    

 
return 0;
}