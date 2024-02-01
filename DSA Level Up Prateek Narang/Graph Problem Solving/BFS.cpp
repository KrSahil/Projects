#include<iostream>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>*l;
public:
    Graph(int v){
        V=v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true){
        l[i].push_back(j);

        if(undir){
            l[j].push_back(i);
        }
    }
    void bfs(int source){
        queue<int> q;
        //we need to maintiain weather the node has been visited or not
        bool *visited = new bool[V]{0}; //intitalizing it with 0

        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            //do something work for every node
            int f = q.front();
            cout<<f<<endl;
            q.pop();

            //Push the nbrs of current node if they are not already
            for (auto nbr : l[f]){ //l[f] is the list that gives the nbrs of the current node
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]= true; //but we have not printed
                }
            }
        }
    }
};
  
int main(){
     Graph g(7);

     g.addEdge(0,1);
     g.addEdge(1,2);
     g.addEdge(3,5);
     g.addEdge(5,6);
     g.addEdge(4,5);
     g.addEdge(0,4);
     g.addEdge(3,4);

    g.bfs(1);
 
return 0;
}