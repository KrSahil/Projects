#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

//Node to store the data (Linked List)
class Node{
public:
    string key;
    int value;

    Node(string key,int vaue){
        this->key = key;
        this->value = value;
    }
};

//LRU cache data structure
class LRUcache{
public:
    int maxSize;
    list<Node> l; //list of nodes
    //for a node we want a address of a praticular node, that address will be of type iterator; an iterator  to a node that is inside list

    unordered_map<string,list<Node>::iterator> m;
    //so this a address of a particular node that is inside of the list
    LRUcache(int maxSize){
        this->maxSize = maxSize > 1 ? maxSize : 1;
        //if the value is 0 then the min size is 1
    }

    void insertKeyValue(string key,int value){
        //2 cases
        //if it is present in the cache then it must  present inside the hash map also
        if(m.count(key)!=0){
            //key value pair exists insed the cache
            //replace the old value and update
             auto it = m[key]; //m of key gives us the address
             it->value = value; //and i go to that address and upadate the value with the new value
        }
        else{
            //if it is not present
            //check if cache is full or not
            //if it is full we reomve the least recently used item from the cache
            if(l.size()==maxSize){ //l.size = size of the list
                Node last = l.back();
                m.erase(last.key); //remove from the hashmap
                l.pop_back();   //reomves from the linked list
            }

            Node n(key,value); //once the memory is free we create the node with key and value as the data
            l.push_front(n); //we insert that node to front of the linked list
            m[key] = l.begin(); //update the entry in the hash map 
        }
    }

    /*

    int* getValue(string key){
    //int getValue(string key){ //because of return Null we cannot use int so we return a pointer;;;; but that causes a problem 
        //if that particular key is present or not
        if(m.count(key)!=0){
            //form the hash map first get the address where that node is present inside the linked list
            auto it = m[key];

            int value = it->value;
            //this node should also come to the top
            //so we create the copy of this node and insert it to the head of the linked list
            l.push_front(*it); //it gives me the address, and *it gives us that particular node 
            //we copied all the key value pairs (that is there in *it) and is pushed in the linked list

            //and the original one is erased
            l.erase(it);
            // now also we need to udate the address in the hash map to the top of the linked list item
            m[key] = l.begin();
            return value;
        }
        //what  if the value doesn't exists in the cache
        //what we are going to return
        return NULL; //but this doesn't matches the return type
    }

    */

   int* getValue(string key){
    //int getValue(string key){ //because of return Null we cannot use int so we return a pointer;;;; but that causes a problem 
        //if that particular key is present or not
        if(m.count(key)!=0){
            //form the hash map first get the address where that node is present inside the linked list
            auto it = m[key];

            int value = it->value;
            //this node should also come to the top
            //so we create the copy of this node and insert it to the head of the linked list
            l.push_front(*it); //it gives me the address, and *it gives us that particular node 
            //we copied all the key value pairs (that is there in *it) and is pushed in the linked list

            //and the original one is erased
            l.erase(it);
            // now also we need to udate the address in the hash map to the top of the linked list item
            m[key] = l.begin();
            //return value;
            //so insted we return the address of the value
            //return &value;
            //but this again causes a probelm
            // as it-value is already destoryed
            // |key|value| <- liked list top element
            //        ^    we shoul return address of this particular box
            // it is a dynamic memory so it will exist
            return &l.begin()->value;
        }
        //what  if the value doesn't exists in the cache
        //what we are going to return
        return NULL; //but this doesn't matches the return type
    }

    string mostRecentKey(){
        //simply return what is there at the head of the linked list
        return l.front().key;
    }
};
  
int main(){
    LRUcache lru(3);
    lru.insertKeyValue("mango",10);
    lru.insertKeyValue("apple",20);
    lru.insertKeyValue("guava",30);
    cout<<lru.mostRecentKey()<<endl;

    lru.insertKeyValue("mango",40);
    cout<<lru.mostRecentKey()<<endl;

    int *orders = lru.getValue("mango");
    if(orders!=NULL){
        cout<<"Orders of Mango "<<*orders<<endl;
    }

    lru.insertKeyValue("banana",20);

    if(lru.getValue("apple")==NULL){
        cout<<"apple doesn't exist";
    }

    if(lru.getValue("banana")==NULL){
        cout<<"banana doesn't exist";
    }

    if(lru.getValue("guava")==NULL){
        cout<<"guava doesn't exist";
    }

    if(lru.getValue("mango")==NULL){
        cout<<"mango doesn't exist";
    }
 
return 0;
}