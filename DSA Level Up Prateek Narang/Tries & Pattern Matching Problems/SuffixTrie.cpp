#include<iostream>
#include<unordered_map>
using namespace std;


//Build a Prefix Tree - Trie
class Node{
public:
	char data;
	unordered_map<char,Node*> m;
	bool isTerminal;

	Node(char d){
		data = d;
		isTerminal = false;
	}
};


class SuffixTrie{

	Node*root;
public:
	SuffixTrie(){
		root = new Node('\0');
	}

	//later
	void insert_helper(string word){

		Node* temp = root;

		for(char ch : word){

			if(temp->m.count(ch)==0){
				Node *n = new Node(ch);
				temp->m[ch] = n;
			}
			temp = temp->m[ch];
		}

		temp->isTerminal = true;

	}

	bool search(string word){

		Node*temp = root;

		for(char ch : word){

			if(temp->m.count(ch)==0){
				return false;
			}
			temp = temp->m[ch];


		}
		return temp->isTerminal;
	}

    void insert(string word){
        //pick all the substring from (i,eos) {eos:end of string} and call insert_helper
        for(int i = 0; word[i]!='\0' ; i++){
            insert_helper(word.substr(i)); //word of substring starting from index i
        }
    }
};


int main(){

		string input = "hello";

		string suffixes[] = {"lo","ell","hello"};

        SuffixTrie t;
        t.insert(input);

        for (auto sf: suffixes){
            if(t.search(sf)){
                cout<<"yes ";
            }
            else{
                cout<<"No ";
            }
        }

		return 0;
}