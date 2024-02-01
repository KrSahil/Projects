#include<iostream>
using namespace std;

struct student {
    int rollno;
    char sex;
};
  
int main(){
 
    student anil;  //variable name
    student *anilPtr; //to use pointer first eew must declare it

    anilPtr = &anil;  //pointing to address of anil using anilPtr;
      
    anil.rollno=32;   //to access the member of the structure uisng variable
   // anilPtr->sex='M'; //to access the member of the structure using pointer
    (*anilPtr).sex='F';
    cout<< anilPtr->rollno<<endl;
    cout<< anil.sex;
 
return 0;
}