#include<string>
#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
    string key;
    T value;
    Node *next;

    Node(String key, T value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

template<typename T>
class HashTable{

    //this will mantain the ds and aslo maintain addition and deletion of node
    Node<T> ** table;
    int cs; //total entreis that have been inserted
    int ts; // size of the table

    //method that will compute hash value
    int hashFn(string key){
        //we are going to compute index by suming over all the values that are there in the key

        int idx = 0;
        int power = 1;


        //in each iteration power is going to be multiplied by 29
        //29^0  29^1  29^2 ...

        for(auto ch : key){ 
            //take a mod of avoid table size overflow
            idx = (idx + ch*power)%ts;
            power = (power * 29)%ts;
        }
        return idx;

        }

        //rehash
        void rehash(){
            // Save the pointer to the old tabel and we will do insertion in the new table
            Node<T> **oldTable = table; //table we had earlier
         //   table = new Node<T>* [2*ts + 1]; //Ideally we should maeke table size prime, for now we are doubling it and making it odd
            int oldTs = ts; //old table size = table size

            //incrase the table size
            cs =0;
            ts = 2*ts + 1;
            table = new Node<T>* [ts]; //ts = 2*ts + 1

            //copy the data to new table
            //initialize new table with null Values
            for (int i = 0; i<ts; i++){
                table[i] = NULL;
            }

            //copying elements from old table to new table
            for (int i = 0; i<oldTs; i++){
                //we are going to create a temporary vaiable that is going to point the head of the Ith linked list in the old table
                Node<T> *temp = oldTable[i];

                while(temp!=NULL){
                    string key = (*temp).key;
                    T value = (*temp).value;
                    //Insertion will happen in new table
                    insert(key,value);
                    temp = (*temp).next; //after completin one copying we move to next node 0->0
                }
                //Destroy the Ith linkedist
                if(oldTable[i]!=NULL){
                    delete oldTable[i]; //this is going to deestroy 1st node
                }
            }
            delete [] oldTable; //[] -> symbolizes that it is array
    }
public:
    HashTable(int default_size = 7){
        cs = 0;
        ts = default_size;

        table = new Node<T>*[ts];

        //if LL doesnt exists NULL to avoid garbage value
        for (int i = 0; i<ts; i++){
            table[i] = NULL;
        }
    }

    void insert(string key, T val){
        //next
        int idx = hashFn(key); //we need a function that converts has function to index
        //index at table = hash funcctioon of the key we received

        //insertion
        Node<T>* n = new Node<T>(key,val);

        //Insertion at head of the linked list
        (*n).next = table[idx];
        table[idx] = n;

        cs++;

        //rehashing
        //if objects cross Thresshold frequency

        //load factor
        float load_factor = cs/float(ts);
        if(load_factor > 0.7){
            //rehash
            rehash();

        }
    }

    //T search(strirng key)
    //what to return if no item was found
    // so we return T* -> if object is present it will return address or else it will return NULL
    T* search(string key){
        int idx = hashFn(key);

        Node<T> *temp = table[idx];
        while(temp!=NULL){
            if((*temp).key == key){
                return &temp->value; //returning address

            }
            temp = (*temp).next;

        }
        return NULL;

    }

    void erase(string key){
        //find the bucket id
        //iterate over the linked list
        //
    }


    T& operator[] (string key){
        //return the valie
        //if key is not found than create a new node and return
        //return the existing node
        T * valueFound = search(key);
        if (keyFound==NULL){
            T object;
            insert(key,object); //we dont know where it is created
            // so we search for it
            valueFound = search(key); //we are going to get pointer to the value
        }
        return *valueFound; //derefrencing key found
    }

        //testing
        void print(){
    //iterate over buckets
        for (int i=0; i<ts; i++){
            cout<<"Bucket "<<i<<"->";
            Node<T> *temp = table[i];
            while (temp!=NULL){
                cout<<(*temp).key<<"->";
                temp = (*temp).next;
            }
            cout<<endl;
        }

        }
    
};