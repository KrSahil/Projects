#include<iostream>
#include<cstring>
using namespace std;

class Product{
private:
    int id;
    char *name;
    int mrp;   
    int selling_price;

public:

    Product(){
         cout<<"Inside Constructor"<<endl;
     }

    Product(int id,char *n,int mrp,int selling_price){  

        this->id = id;
        this->mrp = mrp;
        this->selling_price= selling_price;

        name = new char[strlen(n)+1];   //allocating the memory
        strcpy(name,n); 

        
     }

    Product(Product &X){
        id = X.id;
        //handling char array
        name = new char[strlen(X.name)+1];  //here, we created new array
        //now , we copy what is there in originanl array
        strcpy(name,X.name);
       mrp = X.mrp;
        selling_price= X.selling_price;
    }

    void operator = (Product &X){
        //deep copy inside Copy Assignment
        id = X.id;
        //handling char array
        name = new char[strlen(X.name)+1];  //here, we created new array
        //now , we copy what is there in originanl array
        strcpy(name,X.name);
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
//setter for name
    void setName(char *name){
        strcpy(this->name,name);
    }

};
  
int main(){
 
    Product camera(101,"GoPro",2800,2600);
    //Product old_camera(camera);
    Product old_camera; // constructor has already been called

    old_camera = camera; //copy assignment operator
    old_camera.setName("GoPro8Old");
    //name is changing for both the camera

    old_camera.showDetails();    
    camera.showDetails();
    /*
    old_camera.setName("GoPro8");
    old_camera.setSellingPrice(200);
    

*/
   
return 0;
}