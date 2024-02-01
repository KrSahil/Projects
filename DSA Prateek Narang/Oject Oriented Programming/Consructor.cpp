#include<iostream>
using namespace std;

class Product{
    int id;
    char name[100];
    int mrp;   
    int selling_price;

public:

    //constructor - it exists by default even if we dont make them; it will be hidden
     Product(){
         cout<<"Inside Constructor"<<endl;
     }
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
 
    Product camera; //as soon as we make object of class default constrcutor is called by default

    camera.setMrp(100);
    camera.setSellingPrice(200);




    cout<<sizeof(camera)<<endl;
    cout<< "MRP " <<camera.getMrp()<<endl;
    cout<<"Selling Price "<<camera.getSellingPrice();
 
return 0;
}