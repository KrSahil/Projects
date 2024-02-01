#include<iostream>
using namespace std;

class Product{
    int id;
    char name[100];
    int mrp;   
    int selling_price;

public:
//setter
    void setMrp(int price){
        if (price>0){
        mrp = price;
        }
    }
    void setSellingPrice(int price){
        //additional checks
        if(price>mrp){
            selling_price= mrp;
        } 
        else{
            selling_price= price;
        }
        
    }
//getter
    int getMrp(){
        return mrp;
    }
    int getSellingPrice(){
        return selling_price;
    }

};
  
int main(){
 
    Product camera; 

    camera.setMrp(100);
    camera.setSellingPrice(200);




    cout<<sizeof(camera)<<endl;

    // cout<< "MRP " <<camera.mrp;  - this code is not going to work because 
    // mrp is a private member
    // so here, comes the use of getter

    cout<< "MRP " <<camera.getMrp()<<endl;
    cout<<"Selling Price "<<camera.getSellingPrice();
 
return 0;
}