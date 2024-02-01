#include<iostream>
#include<cstring>
using namespace std;
  
int main(){
    
    char a[] ="abcdef"; // here, we dont require null character
    //some inbuilt functions
    cout<<a<<endl;
    

    //read a character array
    //we dont need for loop
    //hwllo world will cause error because of space
    char b[100];
    cin>>b;
    cout<<b<<endl;





    cout<<strlen(a)<<endl;  //number of visible character
    cout<<sizeof(a);        //+1 because of null character
 
return 0;
}