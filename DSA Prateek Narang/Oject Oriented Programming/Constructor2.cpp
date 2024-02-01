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
 
    //Product camera; //if we don't pass any parameter first constructor is called
    Product camera(101,"Sahil",2800,2600);

    


    cout<< "MRP " <<camera.getMrp()<<endl;
    cout<<"Selling Price "<<camera.getSellingPrice();
 
return 0;
}