#include<iostream>
#include"list.h"

using namespace std;


  
int main(){
    LinkedList l;
    l.push_front(1);
    l.push_front(0);
    l.push_back(2);
    l.insert(9,2);
    l.insert(10,0);
    l.pop_fornt();

    //reverse
   /*
    Node *head;
    cin>>head;
    cout<<head;
    reverse(head);
    cout<<head;
*/

    Node* head = l.begin();

    while (head!=NULL){
        //cout<<head->data<<"->";
        //instead we can use getter to call data
       
       cout<<head->getData()<<"->";
       head = head->next;

    }

    //search 
 /*   int key;
    cin>>key;
   if (searchRecursive(head,key)){
        cout<<"Element found";
    }
    else{
        cout<<"Element not found";
    }
*/
    int key;
    cin>>key;
    cout<<l.recursiveSearch(key);
 
return 0;
}