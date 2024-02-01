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


class Trie{
	//since it is a tree and it will start from a root
	//so, first we make pointer to the root
	Node*root; //Root node will point NULL in the begining 
public:
	Trie(){
		root = new Node('\0');  
	}

	//later
	void insert(string word){

		Node* temp = root; //temporary pointer that points to root of the trie
		//we will iterater over all the characters taht are there in words  
		for(char ch : word){

			if(temp->m.count(ch)==0){ //refer notebook- " temp->m " refering to hash map
									  //count is a function of hash map, which tells if the key is present or not
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
		//Do u want to return true or false
		//it depends on the node u are treminating
		return temp->isTerminal; //if temp->isTerminal it returns true
		
	}
};


int main(){

		string input = "this is a suffix trie";

		string queries[] = {"fix"};


		return 0;
}