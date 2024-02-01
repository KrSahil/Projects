#include<iostream>
using namespace std;
  
int main(){

   /* //correct way but not practical
    char number[][10]={
        {'a','b','c','\0'},
        {'h','e','l','\0'}

    }
    */
   //so we write each row as a string
    char number[][10]= {
        "one",
        "two",
        "three",
        "four",
        "hundred",
    };

    int i=3;

    cout<<number[i]<<endl; //prints entire row
    cout<<number[i][2]<<endl; //prints particular character

    //print everything
    for (int j=0;j<6;j++){
        cout<<number[j]<<endl;
        //here [j] pritns entire array
        // but this doesbt act same with string
    }
 
return 0;
}