#include<iostream>
using namespace std;

void A(){
    cout<<"Hello";
}

void B(void (*ptr)()){  //function pointer as argument
    ptr();  //call-back funtion that "ptr" points to 
}
  
int main(){
 /*
    void(*p)() = A;

    B(p);

*/
//Instead of this two line we can write
    B(A);  //A is a call back function
 
return 0;
}