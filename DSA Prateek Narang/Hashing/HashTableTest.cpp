#include<iostream>
#include"hashTable.h"
using namespace std;
  
int main(){

    HashTable<int> h;
    h.insert("Mango",20);
    h.insert("apple",120);
    h.insert("guava",220);
    h.insert("pumpkin",320);

    h.print();

    string fruit;
    cin>>fruit;

    int *price = h.search(fruit);
    if(price!=NULL){
        cout<<"price of fruit is"<< *price;
    }
    else{
        cout<<"Fruit not found";
    }

    //super cool functionality
    h["newFruit"]=200;
    cout<<"new fruit cost is"<<h["newFruit"]<<endl;
    h["newFruit"]+=20;

    cout<<"new fruit updated cost: "<<h["newFruit"]<<endl;

 

 
return 0;
}