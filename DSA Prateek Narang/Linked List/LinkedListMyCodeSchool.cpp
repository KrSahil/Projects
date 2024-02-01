#include<iostream>
using namespace std;

struct Node
{
   int data;
  // struct Node* next;  //C languae
  Node * next; //c++
  };

  //struct Node *head;
  Node *head;


  void Insert(int x){
    Node * temp;
    temp = new Node();

    (*temp).data = x;
    (*temp).next = NULL;
    head = temp;
  }


  void Print();

  
int main(){
 
    head = NULL;  //empty list

    int n, x;
    cout<<"How many numbers";
    cin>>n;
    for(int i = 0; i<n;i++){
        cout<<"Enter the "<<i<<" number : ";
        cin>>x;
        Insert(x);
        Print();
    }

 
return 0;
}