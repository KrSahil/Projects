//Product , Item , Price
#include<string>
#include<unordered_map>
using namespace std;

//Forward declaration
class Item;
class Cart;

class Product{
    int id;
    string name;
    int price;
public:
    Product(){}

    Product(int u_id, string name , int price){
        id = u_id;
        this->name =name; 
        this-> price = price; 

    }
    string getDisplayName(){
        return name + " : Rs" + to_string(price) + "\n";
    }
    string getShortName(){
        return name.substr(0,1);
    }

    
    friend class Item;
    friend class Cart;
};

class Item{
    Product product; 
    int qunatity;
public:
    //dummy construcor for -- unordered_map<int,Item> items; we are creating hashmap of itmes
    Item(){

    }

    //constructor using Initialization list
    Item(Product p,int q):product(p),qunatity(q){}

    int getItemPrice(){
        return qunatity * product.price; //but price is a private data member of the Product class
    }
    string getItemInfo(){
        return to_string (qunatity) + " x " + product.name + "Rs. " + to_string(qunatity * product.price) + "\n";
    }
    friend class Cart;
};

class Cart{
    unordered_map<int,Item> items;
    
public:
    void addProduct(Product product){
        //if count == 0 means this item is added for the first time
        if(items.count(product.id)==0){
            Item newItem(product,1); //whose product is product and item is 1
            items[product.id] = newItem;
            //      key             value

        }
        else{ //item was alreay present
            items[product.id].qunatity += 1;
        }
    }
    int getTotal(){
        int total = 0;
        for(auto itemPair: items){
            auto item = itemPair.second;
            total += item.getItemPrice();
        }
        return total;
    }

    string viewCart(){
        if(items.empty()){
             return "Cart is empty";
        }
        string itemizedList;
        //iterate over the hash map and put all the infromation inside the single string
        int cart_total = getTotal();

        for(auto itemPair : items){
            auto item = itemPair.second;
            itemizedList.append(item.getItemInfo());

        }
        return itemizedList + "\n Total Amount : Rs. " + to_string(cart_total) + '\n';

    }

    bool isEmpty(){
        return items.empty();
    }

    

};