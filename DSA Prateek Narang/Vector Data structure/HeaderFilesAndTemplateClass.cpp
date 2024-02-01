#include<iostream>
#include"vector.h"  //to use your own library
//how to make our header file generic so that it can accpt more data type
//so we use template
using namespace std;



  
int main(){
    Vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout<<v.front()<<endl;
    cout<<v.back()<<endl;

    cout<<v.at(3)<<endl;

    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl<<endl;

    //print all the element of the vector
    for (int i=0; i<v.size();i++){
       // cout<<v.at(i)<<",";
       cout<<v[i]<<","; //because of lien 68
    }

 
return 0;
}