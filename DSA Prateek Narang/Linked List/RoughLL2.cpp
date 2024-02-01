#include<iostream>
using namespace std;

//forward declaration
class LinkedList;  //becaues we are using Lineked List in line no 17 but linked list is defined in line no 25

class Node{
    int data; //private member
    

    //data and next poinetr of Node class are private
    //so to access them in Linked List we need friend function


public:
    Node* next;
    Node(int d) {
        data=d;
        next=NULL;       
    }

    //getter for data (private member)
    int getData(){
        return data;
    }
    friend class LinkedList;
    
};


class LinkedList{
    //this list must know the head of the linked list
    //sometimes tails also while insertion in tail
    Node * head;
    Node * tail;

public:
    LinkedList(){
        //whenever we create a new linked list , we need to initialize head as null and tail as null
        head=NULL;
        tail=NULL;
    }


//I need to access the Node *head, so we do it
    Node* begin(){     //int * begin()
        return head;
    }               

//METHOD -> push front

    void push_front(int data){  //both head and tail are null,so both of them will point to the first node
         if(head == NULL){ //if head is null than taail is automatically null so we dont check
             Node * n = new Node (data); //here , we are using "new" operator because we want
                                         // Node to persist(exist) even after the fuctiona call is over

                        //new operator denotes a request for memory alocation on the free store
                        //Dynamic Memory Allocation

                        //if us use "Static allocation" than this node will get deleted after function call is over
             head = tail = n;
         }
         else{
             //in this case, tail will not change
             Node * n = new Node(data);
                //n is a local variable which will get destroyed after function call 
             (*n).next = head;
             head = n;
         }
    }


    void push_back (int data){
        //if someone calls empty (new) linked list,
        if (head == NULL){
            Node * n;
            n = new Node(data);
           //n = (Node*)malloc(sizeof(Node));
            head = tail = n;
        }
        else{  //Linked list already exists
            Node * n;
            n = new Node(data);
            (*tail).next = n;
            tail = n;
        }
    } 
    void insert(int data, int postition){
        if (postition == 0){
            push_front(data);
            return;
        }
        Node *temp = head; 
        for (int jump = 1;jump<=postition-1;jump++){
            temp = (*temp).next;
        }
        Node *n = new Node(data);
        (*n).next = (*temp).next;
        (*temp).next = n;
    

    }

};

int main(){
 
    LinkedList l;
    l.push_back(3);
    l.push_front(2);
    l.push_front(1);
    l.push_back(4);

    // we need the access of NOde*head -> so we create a function to return head

    Node *head = l.begin();

    while(head!=NULL){
        cout<<(*head).getData()<<"->";
        head = (*head).next;
    }

 
return 0;
}