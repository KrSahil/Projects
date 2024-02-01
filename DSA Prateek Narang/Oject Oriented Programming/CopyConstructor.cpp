#include<iostream>
#include<cstring>
using namespace std;

class Product{
private:
    int id;
    char name[100];
    int mrp;   
    int selling_price;

public:

    //constructor - it exists by default even if we dont make them; it will be hidden
     Product(){
         cout<<"Inside Constructor"<<endl;
     }

    //parameterised constructor
     Product(int id,char *n,int mrp,int selling_price){  //constructor overloading
         /*
         id = id;
         mrp = mrp;
         selling_price = selling_price;
         */

        //  this makes us confused so here comes, THIS operator
        this->id = id;
        this->mrp = mrp;
        this->selling_price= selling_price;

        //we don't need "this->"  for char *n 
        
        //name = n;      // this will be wrong because we dont want to copy the address we want to copy the array
        strcpy(name,n);  // from n copy all the array into name

        
     }

    Product(Product &X){
        //create the copy
        id = X.id;
      //  name = X.name;  //array
        strcpy(name,X.name);
    //we cannot copy the name of the array
    // we cannot assign something to the array name because array name is read only constant
    //so we copy them
        mrp = X.mrp;
        selling_price= X.selling_price;
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

    void showDetails(){
        cout<<"Name "<<name<<endl;
        cout<<"Id "<<id<<endl;
        cout<<"Selling Price "<<selling_price<<endl;
        cout<<"MRP "<<mrp<<endl;
    }

};
  
int main(){
 
    //Product camera; //if we don't pass any parameter first constructor is called
    Product camera(101,"GoPro ",2800,2600);
    camera.showDetails();

    //copy is made using special  constructor -> copy constructor
    Product webcam(camera);   
    webcam.showDetails();

    Product handyCam = camera;  // this also makes the call to copy coonstructor  
    handyCam.showDetails();

   
return 0;
}