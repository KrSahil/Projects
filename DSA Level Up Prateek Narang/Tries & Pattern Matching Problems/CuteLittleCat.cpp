#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Node{
public:
    char data;
    unordered_map<char,Node*> children;
    bool isTerminal;

    Node(char d){
        data = d;
        isTerminal = false;
    }
};

class Trie{
    
public:
    Node*root;
    Trie(){
        root = new Node('\0');
    }

    void insert(string word){
        Node *temp = root;

        for(char ch: word){
            if(temp->children.count(ch)==0){
                Node *n = new Node(ch);
                temp->children[ch] = n;
            }
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
    }
};

void searchHelper(Trie t,string doucment, int i, unordered_map<string,bool> &m){
    //start form the given index and see if there is word starting from the given index and it can be found in the trie or not
    Node*temp = t.root;  //starting from the root of the trie node
    for(int j = i; j<doucment.length(); j++){
        char ch = doucment[j]; //curent character
        if(temp->children.count(ch)==0){
            //if inside the root node (particular letter Eg.L) is not present we simply return 
            return;
        }
        //if it is present we traverse the branch
        temp = temp->children[ch];
        //if temp is terminal
        if(temp->isTerminal){
            //history part
            //if temp is present we create a substring
            string out = doucment.substr(i,j-i+1); //we have j-i+1 characters
            //inserting to hash map
            m[out] = true;
        }
    }
    return; 
}

void documentSearch(string document, vector<string> words){
    //1. Create a trie of words
    Trie t;
    for(auto w: words){
        t.insert(w); //all the words are inserted into the trie
    }
    //2. Searching  (Helper function)
    unordered_map<string,bool>m; //creating undoredered map to mark the words i have found
    for (int i = 0; i<document.length(); i++){ //creating all sufixes
        searchHelper(t,document,i,m);
    }

    //3. You can check which words are marked as True inside HashMap
    for(auto w:words){ //iterating over all the words
        if(m[w]){ //if it is true
            cout<<w<<" : True"<<endl;
        }
        else{
            cout<<w<<" : False"<<endl;
        }
    }
    return;

}
  
int main(){
    string document = "little cute cat loves to code in c++, java & python";
    vector<string> words = {"cute cat", "ttle", "cat","quick","big"};   //step 1 - insert this in trie
 
    documentSearch(document,words);
 
return 0;
}