
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

    //To destroy linked list we also need to destry node
    ~Node(){
        if (next!=NULL){
            delete next;
        }
        cout<<"Deleting node with Data"<<data<<endl;
    }
    friend class LinkedList;
    
};


class LinkedList{
    //this list must know the head of the linked list
    //sometimes tails also while insertion in tail
    Node * head;
    Node * tail;

     //u may skip
        //Search helper
        int searchHelper(Node *start, int key){
            //base case
            if (start == NULL){
                return -1;
            }
            //value matches
            if(start->data == key){
                return 0;
            }
            //remaining part of the linked list list we are going to make a recursive call
            int subIdx = searchHelper(start->next,key);
            if(subIdx == -1){
                return -1;
            }
            return subIdx+1;
        }


public:
    LinkedList(){
        //whenever we create a new linked list , we need to initialize head as null and tail as null
        head=NULL;
        tail=NULL;

       
    }

    Node* begin(){
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

    void insert (int data, int position){
        if (position==0){
            push_front(data);
            return;
        }
        Node *temp = head; //Start iterting from head
        for (int jump = 1; jump<= position-1;jump++){  
            temp = (*temp).next; //in every jump we are shifring the postition of template
            // we need do shift template to n-1 position
        }
        Node * n = new Node(data);
        (*n).next = (*temp).next;
        (*temp).next = n;
    }

    //linera seach is only applicable in linked list

    bool search(Node *head, int key){
        //array - direct access is available ; g a[i]
        //LinkedList - direct access is not supported

        Node *temp = head;
        while (temp!=NULL){
           if ((*head).data == key){
                return true;
           }
           head = (*head).next;
        }
        return false;
    }

    //Recursively
    bool searchRecursive(Node*head,int key){
        if (head == NULL){
            return false;
        }
        //recursive check at head, remaining linked list
        if((*head).data == key){
            return true;
        }
        else{
            return searchRecursive((*head).next,key);
        }
    }

    int recursiveSearch(int key){
        int idx  = searchHelper(head,key);
        return idx;
    }   

    void pop_fornt(){
        //moving head to index i+1 will work but that will creaate a memory leak
        /*
        1st step : copy head in temporary memory
        2nd : head =head-> next
        3rd : if we directly delete temp it will destroy the whol linked list
            so , we make next of the temp = null
        4th : delete temp
        */

       Node *temp = head;
       head = (*head).next;
       (*temp).next = NULL; 
        delete temp;
    }

    //Remove (position)
    /*
    1-2-3-4
    remove 3

    reach index 1

    index 1 = temp

    n =(*temp).next;
    temp->next = n-> next;
    n->next = NULL;
    delete n;
    */

    ~LinkedList() {
        if (head!=NULL){
        delete head;
        head = NULL;
    }
    }

    void reverseLinkedList(Node * head){  //we will import head 
        Node * C = head;
        Node * P = NULL;
        Node * N;

        while (C!=NULL){
            //save the next node
            N = (*C).next;
            //make the current node point to previous
            (*C).next = P;
            //upate P and C take them 1 steep forward
            P=C;
            C=N;
        }
        head = P;
    }




};