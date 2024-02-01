#include<iostream>
using namespace std;

/* METHODS OF CREATING CHAR ARRAY
char a[100]= {'a','b','c'};  -> wrong  o/p-> a b c garbage because it will print garbag values unitil it finds 0 
char a[100]= {'a','b','c','\0'}; ->correct  -> terminatin it with null character
char a[100]= "abc";  -> it automatically adds null character at the end
*/
  
int main(){
  /*  char a[] ={'a','b','d','c'};
 
    // we can also print it with using for loop or
    cout<<a;

    if we print above code we may get garbage values as we have not terminated the program
*/ 
    char a[] ={'a','b','d','c','\0'};
 
    cout<<a;
 
return 0;
}