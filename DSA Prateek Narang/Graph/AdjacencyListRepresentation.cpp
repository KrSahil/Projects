#include<iostream>
#include<list>
using namespace std;

class Graph{
    //Pointer to an array of list
    //Dyanamic Alloacation because size of array is not known
    int V; //vertices graph will have
    list<int> *l;  //Declaration
public:
    Graph(int v){
        V=v;  //how many verticse graph is going to have
        l = new list<int>[v];  //arra of linked list
                        // l = new list<int>   ; this will create single linked list
                        // and pointer will be of type -  list<int>*l
                        //list<int> * l = new<list> [v];   we have initalize pointer to linked list in private


    }
    //how do we add edge
    void addEdge(int i, int j,bool undir = true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void printAdjList(){
        //Iterate over all the rows
        for (int i = 0;i<V;i++){
            cout<<i<<"-->";
            //Iterate over all the elements in each row
            for(int node:l[i]){
                cout<<node<<",";
            }
            cout<<endl; //after every row
        }
    }

}; 
  
int main(){
 
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(3,5);

    g.printAdjList();

    
 
return 0;
}