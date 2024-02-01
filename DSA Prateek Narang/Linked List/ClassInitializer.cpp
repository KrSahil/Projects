#include<iostream>
using namespace std;
/*
Syntax for initialization list in constructor
constructor(argument-list) : initialization- section 

{
    assignment + other code;
}

class Test{
    int a;
    int b;
    public:
        Test(int i, int j) : a(i),b(j)  {constructor body} // if i  do this- in place of i comes a and in pleace of j comes b;
}

};

*/


/*
class Test{
    int a;
    int b;
    public:
        Test(int i, int j)  {  //if i  do this- in place of i comes a and in pleace of j comes b;
         a=i;
         b=j;
            cout<<"constructor body"<<endl;
            cout<<"Value of a is "<<a<<endl;
            cout<<"Value of b is "<<b<<endl;
            } 
};
*/

/*
class Test{
    int a;
    int b;
    public:
        Test(int i, int j) : a(i),b(j)  {  //if i  do this- in place of i comes a and in pleace of j comes b;
            cout<<"constructor body"<<endl;
            cout<<"Value of a is "<<a<<endl;
            cout<<"Value of b is "<<b<<endl;
            } 
};
*/

class Test{
    int a;
    int b;
    public:
       // Test(int i, int j) : a(i),b(i+j)  {    //this works
       // Test(int i, int j) : a(i),b(2*j)  {    //this works
       // Test(int i, int j) : a(i),b(a+j)  {    //this also works - > here we 1 st assisgned the value of a and later used it with j

      // Test(int i, int j) : b(j),a(i+b)  {    //garbage value printed because we have ... int a than int b; 1st a is declared so a is inintalized 1st
    //a will be initialized first
   
   
   /*
    Test(int i, int j) : b(j),a(i+b)  { 
            cout<<"constructor body"<<endl;
            cout<<"Value of a is "<<a<<endl;
            cout<<"Value of b is "<<b<<endl;
            } 
            */

/*
            Test(int i, int j) : a(i)  { 
                b=j;    //we can also declare remaining file inside the constructor body
            cout<<"constructor body"<<endl;
            cout<<"Value of a is "<<a<<endl;
            cout<<"Value of b is "<<b<<endl;
            } 
            */

            Test(int i, int j)  {
                a=i;
                b=j; 
            cout<<"constructor body"<<endl;
            cout<<"Value of a is "<<a<<endl;
            cout<<"Value of b is "<<b<<endl;
            } 
};
  
int main(){
 
    Test t(4,6);
 
return 0;
}