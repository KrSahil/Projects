#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class Node{
public:
    string name;
    list<string> nbrs; //storing list of neighbours

    Node(string name){
        this->name = name;

    }
};

class Graph{
    //All nodes
    //Hash map where string is the key and Node* is is pointer (String, Node*)
    unordered_map<string,Node*> m;
public:
    Graph(vector<string> citites){
        for(auto city: citites){
            m[city] = new Node(city);
        }
    }

    void addEdge(string x, string y, bool undir= false){
        m[x]->nbrs.push_back(y);

        if(undir){ //if undirected then, reverse will alos be true
            m[y]->nbrs.push_back(x);      
            
        }  

    }

    void printAdjList(){
        for(auto cityPair : m){ //City pair = name and it's address(Node*)
            auto city = cityPair.first;
            Node *node = cityPair.second;

            cout<<city<<"-->";

            //we can find the neihbour by node->nbrs
            for(auto nbr: node->nbrs){
                cout<<nbr<<" ,";
            }
            cout<<endl;
        }
    }
};
  
int main(){
    vector<string> cities = {"Delhi","London","Paris","New York"};
    Graph g(cities);
    g.addEdge("Delhi","London");
    g.addEdge("New York","London");
    g.addEdge("Delhi","Paris");
    g.addEdge("Paris","New York");

    g.printAdjList();
 
 
 
return 0;
}