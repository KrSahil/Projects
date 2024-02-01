#include<iostream>
#include<cstring>
using namespace std;
  
int main(){
    
    char a[100]= "apple";
    char b[100];

    // length 0f the array
    cout<<strlen(a)<<endl;

    //strcpy (destination , source)
    strcpy(b,a); 
    cout<<b<<endl;

    //compare
    cout<<strcmp(a,b)<<endl;

    //strcat
    char web[]="www";
    char domain[] = "codingminutes.com";

    cout<<strcat(web,domain); // we can also use it inside a comapare

    strcpy(b,strcat(web,domain));
    cout<<b;
 
return 0;
}   