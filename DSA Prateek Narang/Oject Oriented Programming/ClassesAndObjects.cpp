#include<iostream>
using namespace std;

class Product{
    int id;
    char name[100];
    int mrp;
    int selling_price;

};
  
int main(){
 
    Product Camera;  //object created  - camera is a object
    cout<<sizeof(Camera);

 
return 0;
}