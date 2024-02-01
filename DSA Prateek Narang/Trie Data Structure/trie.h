#include<unordered_map>
#include<string>
using namespace std;

class Trie; 

class Node{
    char data;
    unordered_map<char,Node*> m; //m stores childrean of every node
    bool isTerminal;

public: 
    Node(char d){
        data = d;
        isTerminal = false;
    }
    friend class Trie;
};

class Trie{
    //trie is going to store address of the root node
    Node*root;    
    
public:
    Trie(){
        root = new Node('\0'); //root node will always be null
    }
    //insertion
    void insert(string word){
        Node *temp = root; // we will have to start from the root node
        //iterate over all the words
        for(char ch :word){
            //count = current letter is present or not
            // m    = hash map
            if((*temp).m.count(ch)==0){//node doesnt exist
            Node *n = new Node(ch);
            //store the address of the node in hash map
            temp->m[ch]=n; //conection betwwen root and new node is establlished
            //now we want to do the same thing with upcoming node
            //so we move the temp to recently created node

            }
        temp = temp->m[ch];
        }
        //mark as terminal node after insertion is complete
        temp->isTerminal = true;
    }

    //searching
    bool search(string word){
        //---he hello apple---
        //do u have h? y
        //do you have e? y
        //is y terminal? y (search findished)
        Node *temp = root;
        for(char ch:word){
            if(temp->m.count(ch)==0){
                return false; //address for search item is not there
            }
            temp = temp->m[ch]; //it is present
        }
        //is it terminal node
        return temp->isTerminal;

    }
};