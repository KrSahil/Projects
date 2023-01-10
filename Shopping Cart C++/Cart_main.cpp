#include<iostream>
#include<vector>
#include"DataModel.h"
using namespace std;

vector<Product> allProdcts = {
    Product(1,"apple",26),
    Product(2,"mango",16),
    Product(3,"guava",36),
    Product(4,"banana",56),
    Product(5,"strawberry",29),
    Product(6,"pineapple",20),


};

//Product chooseProduct(){ //because we also have to return NULL se instead we return address
Product* chooseProduct(){
    //Display the list of products
    string productList;
    cout<<"Available Products "<<endl;

    for (auto product: allProdcts){
        productList.append(product.getDisplayName());
    }
    cout<<productList<<endl;
    //ask the user
    cout<<"-------------------"<<endl;
    string choice;
    cin>>choice;

    for(int i=0; i<allProdcts.size(); i++){
        if(allProdcts[i].getShortName()==choice){
           // return allProdcts[i]; - as the return type is poinnter so we rturn the address
           return &allProdcts[i];
        }
    }
    //item was not found
    cout<<"Prduct Not Found"<<endl;
    return NULL;
}

bool checkOut(Cart &cart){ //i dont want to make the copy of the cart so I'll pass it by refrence
    if(cart.isEmpty()){
        return false;
    }
    int total = cart.getTotal();
    cout<<"Pay in Cash ";

    int paid;
    cin>>paid;

    if(paid>=total){
        cout<<"Change" <<paid - total<<endl;
        cout<<"ThankYou for shoppin With us";
        return true;
    }
    else{
        cout<<"Not enough cash";
        return false;
    }

}

  
int main(){
    char action;
    Cart cart;
    while(true){
        cout<<"Select an action - (a)dd item, (v)iew cart, (c)heck out"<<endl;
        cin>>action;

        if(action == 'a'){
            //to do: add to cart
            //View the items + choose product + add to the cart
            Product * product = chooseProduct();
            if(product!=NULL){
                cout<<"Added to the cart"<<product->getDisplayName()<<endl;
                cart.addProduct(*product); //product is a pointer. so inorder to give a object we need to derefrence it
            }
        }
        else if(action == 'v'){
            //View the cart
            cout<<"-----------------"<<endl;
            cout<< cart.viewCart();
             cout<<"-----------------"<<endl;
        }
        else{
            //checkout
            cart.viewCart();
            if(checkOut(cart)){
                break;
            }

        }
    }   

 
return 0;
}