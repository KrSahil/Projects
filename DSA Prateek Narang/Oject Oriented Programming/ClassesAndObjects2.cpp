#include<iostream>
using namespace std;

class Product{
    int id;
    char name[100];
public:
    int mrp;   //if not initialized may give garbage value
    int selling_price;

};
  
int main(){
 
    Product camera;  //object created  - camera is a object

    camera.mrp= 100;
    camera.selling_price = 200;




    cout<<sizeof(camera)<<endl;

  //  cout<< Camera.mrp;  // wwe cannot use mrp until it's public
  cout<< "MRP " <<camera.mrp; 

 
return 0;
}