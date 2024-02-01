#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;

class Node{
public:
    string name;
    list<string> nbrs;

    Node(string name){
        this->name = name;        
    }
};

class Graph{

    //what all nodes are there
    //refer the node by its name   ..hashmap(string,Node*)
    unordered_map<string,Node*> m;
public:
    Graph(vector<string> cities){
        for (auto city: cities){
            m[city] = new Node(city);
        }
    }
    void addEdge(string x, string y, bool undir = false){
        m[x] -> nbrs.push_back(y);

        if(undir){
            m[y]->nbrs.push_back(x);

        }
    }
    void printAdjList(){
        for(auto cityPair : m){ //city pair = name of the city and it's address
            auto city = cityPair.first;
            Node *node = cityPair.second;
            cout<<city<<"-->";

            for(auto nbr : (*node).nbrs){
                cout<<nbr<<",";
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