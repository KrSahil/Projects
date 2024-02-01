#include<iostream>
using namespace std;
  
int main(){
 
    int x = 10;

    cout<<&x<<endl; 


    int *xptr =&x; // both of them will have same value
    cout<<xptr<<endl<<endl;

    //address of a Pointer variable
    cout<<&xptr<<endl;

    //pointer to a pointer
    int ** xxptr=&xptr;
    cout<<xxptr;

return 0;
}